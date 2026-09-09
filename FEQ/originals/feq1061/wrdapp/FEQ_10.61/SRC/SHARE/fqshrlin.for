C     ***********
C     *         *
C     * CHK_AND_CONVERT_RESPONSE
C     *         *
C     ***********

      SUBROUTINE CHK_AND_CONVERT_RESPONSE(STDOUT,
     I           N_SYMBOL, SYMBOL_TABLE, RESPONSE_TYPE,
     I           CONVERT_RULE, ITEM_KNT, ITEM_TYPE, CVAL, CLEN,
     M           EFLAG,
     O           IVAL, RVAL, DPVAL)

C     Check that items that require a response have a valid response.
C     Also convert the numeric arguments following the rule 
C     for the particular input variable. 
C     Used for cases in which the user gives the variable name followed
C     by an equal sign followed by the response.  There may be responses
C     that do not fit this pattern.  If so, the response type for that 
C     symbol in the symbol table is 0.

      IMPLICIT NONE
      INTEGER EFLAG, N_SYMBOL, ITEM_KNT, STDOUT
      INTEGER  RESPONSE_TYPE(N_SYMBOL),
     A        CONVERT_RULE(N_SYMBOL), ITEM_TYPE(ITEM_KNT), 
     B        CLEN(ITEM_KNT), IVAL(ITEM_KNT)
      REAL RVAL(ITEM_KNT)
      REAL*8 DPVAL(ITEM_KNT)
      CHARACTER SYMBOL_TABLE(N_SYMBOL)*16, CVAL(ITEM_KNT)*(*)

C     Local

C     Parameters
      INTEGER CHRVAL, EXACT_TYPE, DATETIME, DPRVAL, INTVAL, MULTR,
     A        REAVAL
      PARAMETER (INTVAL=1, DPRVAL=3, CHRVAL=4, EXACT_TYPE=0, DATETIME=7,
     A           MULTR=8, REAVAL=2)

      INTEGER I, IP, IR, J
      CHARACTER KEY*16, RESPONSE*16
C     *********************************FORMATS**************************
50    FORMAT(/,' *ERR:368* Name=',A16,' is unknown as an input value.')
52    FORMAT(/,' *ERR:369* ',A,' is invalid value for ',A)
54    FORMAT(/,' *ERR:370* Response for ',A,' is missing or in error.')
56    FORMAT(/,' *BUG:XXX* Invalid RESPONSE_TYPE=',I5,' at index=',I5,
     A   ' in CHK_AND_CONVERT_RESPONSE.')
58    FORMAT(/,' *BUG:XXX* Conversion error in string:',A,/,5X,
     A  'in CHK_AND_CONVERT_RESPONSE.')
60    FORMAT(/,' *ERR:384* ',A,' is an invalid year response.')
62    FORMAT(/,' *ERR:385* ',A,' is an invalid month response.')
64    FORMAT(/,' *ERR:386* ',A,' is an invalid day response.')
66    FORMAT(/,' *ERR:387* ',A,' is an invalid hour response.')
68    FORMAT(/,' *ERR:388* ', A,' invalid for: ',A)
C***********************************************************************
C     Construct a loop over the items found on the line of input. 
C     We will be incrementing the loop variable depending on the
C     nature of the item so that the typical loop structures cannot
C     be used. 

      I = 1
100   CONTINUE
        KEY = CVAL(I)(1:CLEN(I))
        CALL LSTAB
     I            (KEY, SYMBOL_TABLE, N_SYMBOL,
     O             IP)
        IF(IP.EQ.0) THEN
          WRITE(STDOUT,50) KEY
          STOP 'Abnormal stop. Errors found.'
        ELSE
          IF(RESPONSE_TYPE(IP).EQ.0) THEN
            I = I + 1
          ELSEIF(RESPONSE_TYPE(IP).EQ.-1) THEN
C           Get out now!  Checking cannot continue on this
C           line.  Errors were detected in parsing the 
C           line.  
            RETURN
          ELSEIF(RESPONSE_TYPE(IP).EQ.DATETIME) THEN
C           Special processing for a date-time string.  The pattern is
C           <id>=year/mn/dy:hour.  year, mn, dy are integers and hour is
C           double precision.  Currently, all values must appear.
C           Process for the year response.
            IF(I+1.GT.ITEM_KNT) THEN
              WRITE(STDOUT,54) KEY
              STOP 'Abnormal stop. Errors found.'
            ENDIF
            IF(ITEM_TYPE(I+1).EQ.INTVAL) THEN
              READ(CVAL(I+1)(1:CLEN(I+1)), *,ERR=10000) IVAL(I+1)
            ELSE
              WRITE(STDOUT,60) CVAL(I+1)(1:CLEN(I+1))
            ENDIF
            I = I + 1
C           Process the month response.
            IF(I+1.GT.ITEM_KNT) THEN
              WRITE(STDOUT,54) KEY
              STOP 'Abnormal stop. Errors found.'
            ENDIF
            IF(ITEM_TYPE(I+1).EQ.INTVAL) THEN
              READ(CVAL(I+1)(1:CLEN(I+1)), *,ERR=10000) IVAL(I+1)
            ELSE
              WRITE(STDOUT,62) CVAL(I+1)(1:CLEN(I+1))
            ENDIF
            I = I + 1
C           Process the day response.
            IF(I+1.GT.ITEM_KNT) THEN
              WRITE(STDOUT,54) KEY
              STOP 'Abnormal stop. Errors found.'
            ENDIF
            IF(ITEM_TYPE(I+1).EQ.INTVAL) THEN
              READ(CVAL(I+1)(1:CLEN(I+1)), *,ERR=10000) IVAL(I+1)
            ELSE
              WRITE(STDOUT,64) CVAL(I+1)(1:CLEN(I+1))
            ENDIF
            I = I + 1
C           Process the hour response
            IF(I+1.GT.ITEM_KNT) THEN
              WRITE(STDOUT,54) KEY
              STOP 'Abnormal stop. Errors found.'
            ENDIF
            IF(ITEM_TYPE(I+1).LE.DPRVAL) THEN
              READ(CVAL(I+1)(1:CLEN(I+1)), *,ERR=10000) DPVAL(I+1)
            ELSE
              WRITE(STDOUT,66) CVAL(I+1)(1:CLEN(I+1))
            ENDIF
            I = I + 2
          ELSEIF(RESPONSE_TYPE(IP).EQ.MULTR) THEN
C           We have one or more values with the first one possibly 
C           an integer if there is more than one value.  All values
C           must be on the current line.  
            IF(I+1.GT.ITEM_KNT) THEN
              WRITE(STDOUT,54) KEY
              STOP 'Abnormal stop. Errors found.'
            ENDIF
            IF(ITEM_TYPE(I+1).EQ.INTVAL) THEN
              READ(CVAL(I+1)(1:CLEN(I+1)), *,ERR=10000) IVAL(I+1)
            ELSEIF(ITEM_TYPE(I+1).EQ.REAVAL) THEN
              READ(CVAL(I+1)(1:CLEN(I+1)), *,ERR=10000) RVAL(I+1)
            ELSE
              WRITE(STDOUT,68) CVAL(I+1)(1:CLEN(I+1)), KEY
              STOP 'Abnormal stop. Errors found.'
            ENDIF              

            J = 2
200         CONTINUE
              IF(I+J.GT.ITEM_KNT) THEN
C               We are done processing the multiple response item.
                GOTO 210
              ELSEIF(ITEM_TYPE(I+J).LE.REAVAL) THEN
C               Convert the item.
                READ(CVAL(I+J)(1:CLEN(I+J)), *,ERR=10000) RVAL(I+J)
              ELSEIF(ITEM_TYPE(I+J).EQ.CHRVAL) THEN
C               We have encountered a string- take to be end of multiple item
C               input.
                GOTO 210
              ENDIF
              J = J + 1
              GOTO 200
210         CONTINUE
            I = I + J

          ELSE
C           Check the response that follows.
            IF(I+1.GT.ITEM_KNT) THEN
              WRITE(STDOUT,54) KEY
              STOP 'Abnormal stop. Errors found.'
            ENDIF
C           Check for valid TYPE.
            IF(CONVERT_RULE(IP).EQ.EXACT_TYPE) THEN
              IF(ITEM_TYPE(I+1).NE.RESPONSE_TYPE(IP)) THEN
                WRITE(STDOUT,52)  CVAL(I+1)(1:CLEN(I+1)), KEY
                EFLAG = 1
              ELSE
C               Make sure that any character response is not
C               in the symbol table. 
                IF(RESPONSE_TYPE(IP).EQ.CHRVAL) THEN
                  RESPONSE = CVAL(I+1)(1:CLEN(I+1))
                  CALL LSTAB
     I                     (RESPONSE, SYMBOL_TABLE, N_SYMBOL,
     O                      IR)
                  IF(IR.NE.0) THEN
                    WRITE(STDOUT,52) RESPONSE, KEY 
                    EFLAG = 1
                  ENDIF
                ENDIF
              ENDIF
            ELSE
C             Conversion rule is to accept a lower type.  Only 
C             numeric responses should appear here. 
              IF(ITEM_TYPE(I+1).GT.RESPONSE_TYPE(IP)) THEN
                WRITE(STDOUT,52)  CVAL(I+1)(1:CLEN(I+1)), KEY
                EFLAG = 1
              ENDIF
            ENDIF
            
C           Convert using RESPONSE_TYPE(IP) as the type.

            GOTO (1000, 2000, 3000, 4000), RESPONSE_TYPE(IP)
              WRITE(STDOUT,56) RESPONSE_TYPE(IP), IP
              STOP 'Abnormal stop. Bug found.'

1000          CONTINUE
                READ(CVAL(I+1)(1:CLEN(I+1)), *,ERR=10000) IVAL(I+1)
                GOTO 9000
2000          CONTINUE
                READ(CVAL(I+1)(1:CLEN(I+1)), *,ERR=10000) RVAL(I+1)
                GOTO 9000
3000          CONTINUE
                READ(CVAL(I+1)(1:CLEN(I+1)), *,ERR=10000) DPVAL(I+1)
                GOTO 9000
4000          CONTINUE
                GOTO 9000
9000        CONTINUE

            I = I + 2
          ENDIF                            
        ENDIF
        IF(I.LE.ITEM_KNT) GOTO 100
      RETURN
10000 CONTINUE
      WRITE(STDOUT,58) CVAL(I+1)(1:CLEN(I+1))
      STOP 'Abnormal stop. Bug found.'

      END
C
C
C
      SUBROUTINE   STAINT
     I                   (CLASS,
     O                    STATE)
 
C     + + + PURPOSE + + +
C     Initialize the STATE from the CLASS of the first character
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER CLASS, STATE
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     CLASS  - Class for the character being processed
C     STATE  - Status for the scanner
 
      INTEGER IDENTIFIER, INTEGER, FIXED, 
     D        ASTERISKP, COMMAP, SLASHI, BACKSLASHI, COLONI,
     E        EQUALI, SIGN, STRING

      PARAMETER (IDENTIFIER=1, INTEGER=2, FIXED=3, ASTERISKP=10,
     F          COMMAP=11,SLASHI=12, BACKSLASHI=13, COLONI=14, 
     G          EQUALI=15,
     H          SIGN=16, STRING=17)

      INTEGER CLASS_TO_STATE(18)

      DATA CLASS_TO_STATE/FIXED,      ASTERISKP,   SIGN,   COMMAP,
     A                    SLASHI,     -1,          COLONI,    EQUALI,
     B                    IDENTIFIER, BACKSLASHI,  -1,        INTEGER,
     C                    4*IDENTIFIER, -1, STRING/              
     
C     + + + COMMON BLOCKS + + +
      INCLUDE 'stdun.cmn'
C***********************************************************************
C     State initialization rules:

C     Char Class     State value assigned 
C       period          fixed
C      asterisk         asteriskp
C      plus/minus       sign
C      comma            commap
C      slash            slashi
C      blank            should not appear 
C      colon            coloni
C      equal            equali
C      underline        identifier
C      backslash        backslashi
C      quote(single)    should not appear here
C      digit            integer
C      a:c              identifier
C       d               identifier
C       e               identifier
C      f:z              identifier
C      vertical bar     should not appear but nothing makes sure it does not.
C      dquote           string

      STATE = CLASS_TO_STATE(CLASS)
      IF(STATE.LE.0) THEN
        WRITE(STD6,*) ' *BUG:XXX* Invalid CLASS=', CLASS,' in STAINT.'
        STATE = -1
      ENDIF
      RETURN
      END
C
C
C
      SUBROUTINE   GITEM
     I                  (LINE,
     M                   FIRST,
     O                   ITEM, ITML, ITMSTA,  TERM, TERML, TERMCLS, EOS)
 
C     + + + PURPOSE + + +
C     Get an item from a LINE of input.  GITEM keeps track of the
C     call sequence and signals EOS=1 if the string has been exhausted
C     by the item returned.
C     
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EOS, ITMSTA, ITML, TERML, TERMCLS
      CHARACTER ITEM*(*), LINE*(*), TERM*(*)
      LOGICAL FIRST
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     LINE   - Character string to be processed
C     FIRST  - Flag for first call to GITEM
C     ITEM   - Value of the next item in the search string
C     ITML   - Number of characters in the item found
C     ITMSTA   - State for the item found
C     EOS    - End of string flag
C     TERM   - string value of terminating entity
C     TERML  - number of characters in the terminating entity
C     TERMCLS - character-class number for the terminator
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'stdun.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER ACTION(17,20), CHRCLS(0:255), L, NEXT, SLEN, STATE
      CHARACTER VALUE*256
      SAVE ACTION, CHRCLS, L, NEXT, SLEN, STATE, VALUE
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ACT, CLASS, I,J
      CHARACTER CHR*1
 
C     + + + INTRINSICS + + +
      INTRINSIC ICHAR, LEN
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL STAINT

 
C     This is the action matrix in two forms: labeled for a human reader
C     and in data input form for a computer reader. 

C                 Class of the next character:                                                            
C                    1        2       3      4     5      6     7     8    9     10    11    12   13  14  15   16  17   18    19   20
C    Current       period asterisk  plus  comma  slash blank colon equal under back  sngle digit a:c   d   e  f:z vert dble  misc semi
C     State                         minus                                line  slash quote                        bar  quote char coln
C  --------        ------ -------- ------ ----- ------ ----- ----- ----- ----- ----- ----- ----- --- --- --- ---- ---- ----- ---- ----
C  1  identifier      1      2        3     3      1    11     1     3     1     1     9     1    1    1   1   1   3     2    17    3
C  2  integer         4      3        3     3      3    11     3     2     2     2     9     1   12   13   5  12   2     2    17    3
C  3  fixed           2      2       10     3      2    11     2     2     2     2     9     1    2   13   5   2   2     2    17    2
C  4  single1         2      2       10     2      2     2     2     2     2     2     2    15   12   12  12  12   2     2    17    2
C  5  single2         2      2        2     2      2     2     2     2     2     2     2    15    2    2   2   2   2     2    17    2
C  6  single3         2      2        2     3      2    11     2     2     2     2     9     1    2    2   2   2   2     2    17    2
C  7  double1         2      2       14     2      2     2     2     2     2     2     2    16   12   12  12  12   2     2    17    2
C  8  double2         2      2        2     2      2     2     2     2     2     2     2    16    2    2   2   2   2     2    17    2
C  9  double3         2      2        2     3      2    11     2     2     2     2     9     1    2    2   2   2   2     2    17    2
C 10  asteriskp       2      2        2     3      2    11     2     2     2     2     9     2    2    2   2   2   2     2    17    2
C 11  commap          7      7        7     7      7     7     2     2     7     7     8     7    7    7   7   7   2     2    17    2
C 12  slashi          2      2        2     2      2    11     2     2    12     2     9    12   12   12  12  12   2     2    17    2
C 13  backslashi      2      2        2     2      2     2     2     2    12     2     2    12   12   12  12  12   2     2    17    2
C 14  coloni          2      2        2     2      2     2     2     2     2     2     2     2    2    2   2   2   2     2    17    2
C 15  equali          2      2        2     2      2     2     2     2     2     2     2     2    2    2   2   2   2     2    17    2
C 16  sign            4      2        2     2      2    17     2     2    12     2     2     6   12   12  12  12   2     2    17    2
C 17  string          1      1        1     1      1     1     1     1     1     1     9     1    1    1   1   1   1     3     1    1

C     Summary statement of each action. 
C     Action#   Description
C        1      add a character to the current item
C        2      error condition-invalid sequence of characters
C        3      Terminate and return the current item. 
C        4      Add character to the current item and change state to a fixed point number.
C        5      Add char to current item and change state to single1 item.
C        6      Add char to current item and change state to integer
C        7      Terminate and return an asteriskp with comma as terminater
C        8      Terminate and return an asteriskp with quote as terminater- end of line
C        9      End of input line.  Return the item and set the end of string flag.
C       10      Add char to item and change the state to single2.
C       11      Find next non-blank, reset terminator as needed, and return. 
C       12      Add to current item and change state to identifier
C       13      Add char to current item and change state to double1 item.
C       14      Add char to current item and change state to double2
C       15      Add char to current item and change state to single3
C       16      Add char to current item and change state to double3
C       17      Ignore char and look for next char.


C     State initialization rules:

C     Char Class     State value assigned 
C       period          fixed
C      asterisk         asteriskp          asterisk as a place holder
C      plus/minus       integer
C      comma            commap             comma as a place holder
C      slash            slashi
C      blank            skip to non-blank and try again
C      colon            coloni
C      equal            error
C      underline        identifier
C      backslash        backslashi
C      quote            end of line
C      digit            integer
C      a:c              identifier
C       d               identifier
C       e               identifier
C      f:z              identifier
C      dquote           string
C      
C      Note: comma and asterisk can be terminators but in that role they
C            will never be the first item.  An asterisk is taken as a 
C            terminator whenever it appears at the end of another item
C            with no intervening spaces.  A comma is a place holder if
C            it is found as the first character after another item has
C            been completed.  Also a detected comma place holder is
C            returned as an asterisk place holder with a terminating 
C            comma.  Thus COMMAP will not be seen as an item state 
C            outside GITEM and STAINT. 


      INTEGER PERIOD, ASTERISK, PLUS_OR_MINUS, COMMA, SLASH, SPACE,
     A        COLON, EQUAL, UNDERLINE, BACKSLASH, QUOTE, DIGIT, A_TO_C,
     B        D, E, F_TO_Z, IDENTIFIER, INTEGER, FIXED, SINGLE1, 
     C        SINGLE2, SINGLE3, DOUBLE1, DOUBLE2, DOUBLE3,
     D        ASTERISKP, VERTICAL_BAR, DQUOTE, MISC, SEMICOLON

      PARAMETER (PERIOD=1, ASTERISK=2, PLUS_OR_MINUS=3, COMMA=4,
     A           SLASH=5, SPACE=6, COLON=7, EQUAL=8, UNDERLINE=9,
     B           BACKSLASH=10, QUOTE=11, DIGIT=12, A_TO_C=13, D=14,
     C           E=15, F_TO_Z=16, VERTICAL_BAR=17, DQUOTE=18,
     D           MISC=19, SEMICOLON=20)

      PARAMETER (IDENTIFIER=1, INTEGER=2, FIXED=3,
     D           SINGLE1=4, SINGLE2=5, SINGLE3=6, DOUBLE1=7,         
     E           DOUBLE2=8, DOUBLE3=9, ASTERISKP=10)


C     Set the class for each of the 256 characters that might be seen in
C     a string.  Assumes the ASCII sequence!  This will not work with
C     EBCIDC.  Characters that are skipped(ignored) are given the class
C     of zero.  

      DATA CHRCLS/32*0,SPACE,MISC,DQUOTE,4*MISC,QUOTE,2*MISC, ASTERISK, 
     A  PLUS_OR_MINUS, COMMA, PLUS_OR_MINUS, PERIOD, SLASH, 10*DIGIT, 
     B  COLON, SEMICOLON, MISC, EQUAL,3*MISC, 3*A_TO_C, D, E, 21*F_TO_Z,
     C  MISC, BACKSLASH, 2*MISC, UNDERLINE, 0, 3*A_TO_C, D, E, 
     D  21*F_TO_Z, MISC, VERTICAL_BAR, 2*MISC, 129*0/


      DATA ((ACTION(I,J),J=1,20),I=1,17)/
     A       1, 2, 3, 3, 1,11, 1, 3, 1, 1, 9, 1, 1, 1, 1, 1, 3, 2,17, 3, 
     B       4, 3, 3, 3, 3,11, 3, 2, 2, 2, 9, 1,12,13, 5,12, 2, 2,17, 3, 
     C       2, 2,10, 3, 2,11, 2, 2, 2, 2, 9, 1, 2,13, 5, 2, 2, 2,17, 2, 
     D       2, 2,10, 2, 2, 2, 2, 2, 2, 2, 2,15,12,12,12,12, 2, 2,17, 2, 
     E       2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,15, 2, 2, 2, 2, 2, 2,17, 2, 
     F       2, 2, 2, 3, 2,11, 2, 2, 2, 2, 9, 1, 2, 2, 2, 2, 2, 2,17, 2, 
     G       2, 2,14, 2, 2, 2, 2, 2, 2, 2, 2,16,12,12,12,12, 2, 2,17, 2, 
     H       2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,16, 2, 2, 2, 2, 2, 2,17, 2, 
     I       2, 2, 2, 3, 2,11, 2, 2, 2, 2, 9, 1, 2, 2, 2, 2, 2, 2,17, 2, 
     J       2, 2, 2, 3, 2,11, 2, 2, 2, 2, 9, 2, 2, 2, 2, 2, 2, 2,17, 2, 
     K       7, 7, 7, 7, 7, 7, 2, 2, 7, 7, 8, 7, 7, 7, 7, 7, 2, 2,17, 2, 
     L       2, 2, 2, 2, 2,11, 2, 2,12, 2, 9,12,12,12,12,12, 2, 2,17, 2, 
     M       2, 2, 2, 2, 2, 2, 2, 2,12, 2, 2,12,12,12,12,12, 2, 2,17, 2, 
     N       2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,17, 2, 
     O       2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,17, 2, 
     P       4, 2, 2, 2, 2,17, 2, 2,12, 2, 2, 6,12,12,12,12, 2, 2,17, 2, 
     Q       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 3, 1, 1/ 
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' Found in following line:',/,1X,A)
 52   FORMAT(/,' Invalid item or invalid sequence:',A)
C***********************************************************************
      IF(FIRST) THEN
C       THIS IS THE FIRST CALL FOR LINE
        FIRST = .FALSE.
 
C       CLEAR THE LOCAL ITEM LENGTH
        L = 0
C       CLEAR THE END OF STRING FLAG
        EOS = 0
C       GET THE LENGTH OF THE CURRENT STRING
        SLEN = LEN(LINE)
        NEXT = 1
      ENDIF

6000  CONTINUE
        CHR = LINE(NEXT:NEXT)
        CLASS = CHRCLS(ICHAR(CHR))
C       Skip spaces and any non-printing characaters as well as 
C       characters ignored. Characters of class MISC are skipped
C       until a double quote starts a string. 

        IF(CLASS.EQ.0.OR.CLASS.EQ.SPACE.OR.CLASS.EQ.MISC) THEN
          NEXT = NEXT + 1
          GOTO 6000
        ENDIF
      L = 1
      VALUE(L:L) = CHR

      IF(CLASS.NE.QUOTE) THEN
        CALL STAINT (CLASS,
     O               STATE)
        IF(STATE.LT.0) THEN
          WRITE(STD6,52) CHR
          WRITE(STD6,50) LINE
 
          EOS = 1
          ITEM = ' '
          ITML = 0
          ITMSTA = STATE
          TERM = ' '
          TERML = 0
          TERMCLS = -1
          FIRST = .TRUE.
          RETURN
        ENDIF
        NEXT = NEXT + 1 
      ELSE
C       The quote was found as the first character.
C       Signal end of string with no item to process.
        ITML = 0
        EOS = 1
        FIRST = .TRUE.
        TERMCLS = QUOTE
        TERML = 1
        RETURN           
      ENDIF
      
C     GET THE NEXT CHARACTER AND PROCESS.
 
 9000 CONTINUE
        CHR = LINE(NEXT:NEXT)
        CLASS = CHRCLS(ICHAR(CHR))
        IF(CLASS.EQ.0) THEN
          NEXT = NEXT + 1
          GOTO 9000
        ENDIF

C        WRITE(STD6,*) ' CHR=',CHR,' ICHAR=',ICHAR(CHR)
 
C       NOW SELECT THE NEXT ACTION USING THE MATRIX, STATE, AND
C       CLASS
 
        ACT = ACTION(STATE,CLASS)
C        WRITE(STD6,*) ' STATE=',STATE,' CLASS=',CLASS,' ACT=',ACT
 
        GOTO(100, 200, 300, 400, 500, 600, 700, 800, 900, 1000,
     A       1100, 1200, 1300, 1400, 1500, 1600, 1700), ACT
 
          WRITE(STD6,*) ' BUG: INVALID INDEX FOR COMP. GOTO.'
          WRITE(STD6,*) ' IN SUB. GITEM. INDEX=',ACT
          STOP 'Abnormal stop: errors found.'
 
 100      CONTINUE
C           Add a character to the current item
            L = L + 1
            VALUE(L:L) = CHR
            GOTO 8900
 
 200      CONTINUE
C           Error condition
 
            WRITE(STD6,52) VALUE(1:L)//CHR
            WRITE(STD6,50) LINE
 
            EOS = 1
            ITEM = ' '
            ITML = 0
            ITMSTA = STATE
            TERM = ' '
            TERML = 0
            TERMCLS = -1
            FIRST = .TRUE.
            RETURN
 
 300      CONTINUE
C           Terminate and return the current item 

            ITEM = VALUE(1:L)
            ITML = L
            ITMSTA = STATE

            TERM = CHR
            TERML = 1
            TERMCLS = CLASS
 
            NEXT = NEXT + 1
            RETURN
 
 400      CONTINUE
C           Add character to the current item and change state to
C           a fixed point number
            L = L + 1
            VALUE(L:L) = CHR
            STATE = FIXED
            GOTO 8900
 
 500      CONTINUE
C           Add char to current item and change state to SINGLE1
            L = L + 1
            VALUE(L:L) = CHR
            STATE = SINGLE1
            GOTO 8900
 
 600      CONTINUE
C           Add char to current item and change state to INTEGER
            L = L + 1
            VALUE(L:L) = CHR
            STATE = INTEGER
            GOTO 8900
 
 
 700      CONTINUE
C           Terminate and return an asteriskp with comma as terminater
            ITEM = '*'
            ITML = 1
            ITMSTA = ASTERISKP

            TERM = ','
            TERML = 1
            TERMCLS = COMMA
 
C           Do not increment NEXT because the char at NEXT must be 
C           used for the next item.
C            NEXT = NEXT + 1
            RETURN
 
 800      CONTINUE
C           Terminate and return an asteriskp with quote as terminater-
C           end of line
            ITEM = '*'
            ITML = 1
            ITMSTA = ASTERISKP

            TERM = ''''
            TERML = 1
            TERMCLS = QUOTE

            EOS = 1 
            FIRST = .TRUE.
            RETURN
 
 900      CONTINUE
C           End of input line.  Return the item and set the end of 
C           string flag.
            ITEM = VALUE(1:L)
            ITML = L
            ITMSTA = STATE
            TERM = ''''
            TERML = 1
            TERMCLS = QUOTE
            EOS = 1
            FIRST = .TRUE.
            RETURN
 
 1000     CONTINUE
C           Add char to item and change the state to single2.
            L = L + 1
            VALUE(L:L) = CHR
            STATE = SINGLE2
            GOTO 8900
 
 1100     CONTINUE
C           Find next non-blank and reset terminator as needed. 
C           Must set terminater to the correct value.  May not be
C           a blank.  The following values could be the terminater
C           with one or more blanks between it and the current value:
C            comma, equal, quote, semi-colon
 
            ITEM = VALUE(1:L)
            ITML = L
            ITMSTA = STATE

 
C           Chr contains a blank.  NEXT points at its location.
C           Search ahead for the next non-blank or end of string.
 
            DO 1101 J=NEXT+1,SLEN
              CHR = LINE(J:J)
              CLASS = CHRCLS(ICHAR(CHR))
              IF(CLASS.NE.SPACE) THEN
                IF(CLASS.EQ.COMMA) THEN
C                 Found a comma. Adjust the pointer to use
C                 it as the terminater instead of the space.
                  TERM = ','
                  TERMCLS = COMMA
                  NEXT = J+1
                ELSEIF(CLASS.EQ.SEMICOLON) THEN
                  TERM = ';'
                  TERMCLS = SEMICOLON
                  NEXT = J+1
                ELSEIF(CLASS.EQ.EQUAL) THEN
                  TERM = '='
                  TERMCLS = EQUAL
                  NEXT = J+1
                ELSEIF(CLASS.EQ.QUOTE) THEN
C                 This is the end of the line.  The quote has 
C                 terminated the last item and also signaled the
C                 end of line.
                  TERM = ''''
                  TERMCLS = QUOTE
                  NEXT = J + 1
                  EOS = 1 
                  FIRST = .TRUE.
                ELSE
C                 The blank is the terminater.
                  TERM = ' '
                  TERMCLS = SPACE
                  NEXT = J 
                ENDIF
                TERML = 1
                RETURN
              ELSE
               
              ENDIF
 1101       CONTINUE
C           DROP THROUGH MEANS NO NON-SPACE FOUND UNTIL END OF LINE
C           SIMULATE WITH A COMMA ALSO
            NEXT = SLEN + 1
            TERM = ' '
            TERML = 1
            TERMCLS = SPACE
            EOS = 1
            RETURN


1200      CONTINUE
C           Add to current item and change state to identifier
            L = L + 1
            VALUE(L:L) = CHR
            STATE = IDENTIFIER
            GOTO 8900

1300      CONTINUE
C           Add char to current item and change state to double1.
            L = L + 1
            VALUE(L:L) = CHR
            STATE = DOUBLE1
            GOTO 8900

1400      CONTINUE
C           Add char to current item and change state to double2
            L = L + 1
            VALUE(L:L) = CHR
            STATE = DOUBLE2
            GOTO 8900

1500      CONTINUE
C           Add char to current item and change state to single3
            L = L + 1
            VALUE(L:L) = CHR
            STATE = SINGLE3
            GOTO 8900
 
1600      CONTINUE
C           Add char to current item and change state to double3
            L = L + 1
            VALUE(L:L) = CHR
            STATE = DOUBLE3

            GOTO 8900

1700      CONTINUE
C           Ignore char and return for the next one
            GOTO 8900

 8900   CONTINUE
 
        NEXT = NEXT + 1
        GOTO 9000
 
      END
C
C
C
      SUBROUTINE   GETVAL
     I                   (STDERR, LINE, NVAL, OPT,
     O                    ITEM_TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, 
     O                    EFLAG, TERM, TERML, TERMCLS,
     O                    MVAL)
      IMPLICIT NONE 
C     + + + PURPOSE + + +
C     Get values from LINE and store them in the appropriate element
C     of the vector(IVAL, RVAL, DPVAL, or CVAL) of the proper type.
C     Report errors in type that prevent proper conversions.  Report
C     excess values.
 
C     STDERR- unit number for output of errors and messages.
C     LINE- the character string to scan.
C     NVAL- the maximum number of values to expect.  It is an error if
C           this number is exceeded.
C     OPT-  if 0 then
C       ITEM_TYPE- vector giving the type of value expected for each value in
C              LINE
C       IVAL, RVAL, DPVAL, CVAL- vectors of the correct type for storing
C           the values found in LINE.  
C       CLEN- vector giving the length of the character string if the
C             value is of type CHARACTER.
C       EFLAG- set to 1 if an error was found in LINE.
C     else if 1
C       ITEM_TYPE- vector giving the type of value found in LINE
C       CVAL- gives the value returned
C       CLEN- give the length of the value

C     else if 2
C       like 0 but ITEM_TYPE gives the type as found in LINE and
C       CVAL and CLEN also contain the string form of argument.

C     In either case:

C        TERM- gives the single character value for the terminator
C        TERML- gives the terminator length in case we want to 
C               make it more than one character.
C        TERMCLS- gives the class number of the terminator.  
C        MVAL- the number of values actually found. A value may be null or
C             defaulted and it is still counted.


C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, MVAL, NVAL, OPT, STDERR
      INTEGER CLEN(NVAL), IVAL(NVAL), ITEM_TYPE(NVAL), TERML(NVAL),
     A        TERMCLS(NVAL)
      REAL RVAL(NVAL)
      REAL*8 DPVAL(NVAL)
      CHARACTER CVAL(NVAL)*(*), LINE*(*), TERM(NVAL)*1
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDERR - Fortran unit number for output of error messages
C     LINE   - Character string to be processed
C     NVAL   - Number of items expected in the string
C     OPT    - If OPT=0 then number and type of items are known else
C               if OPT=1 then number and type are unknown
C     ITEM_TYPE   - Type of item: real, integer, char, double precision
C     IVAL   - Contains integer value for an integer item
C     RVAL   - Return value for a real item
C     DPVAL  - Return for a double precision value
C     CVAL   - Contains character string returned for a string value
C     CLEN   - Vector giving the length of the character string if the
C               value is of type CHARACTER
C     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors
C     MVAL   - Number of item found in the string
 
C     + + + LOCAL PARAMETERS + + +
      INTEGER  CHRVAL, CONTINUATION_VALUE, INTVAL, REAVAL, DPRVAL,
     A         PLACE_HOLDER
      PARAMETER(INTVAL=1, REAVAL=2, DPRVAL=3, CHRVAL=4,
     A          CONTINUATION_VALUE=5, PLACE_HOLDER=6)
 
      INTEGER IDENTIFIER, INTEGER, FIXED, SINGLE3, DOUBLE3,
     A        ASTERISKP, SLASHI, STRING

      PARAMETER (IDENTIFIER=1, INTEGER=2, FIXED=3,
     D           SINGLE3=6, DOUBLE3=9, ASTERISKP=10,
     E           SLASHI=12, STRING=17)

C     + + + SAVED VALUES + + +
      INTEGER DEFTYP(17)
      SAVE DEFTYP
 
C     + + + LOCAL VARIABLES + + +
      INTEGER EOS, ITMSTA, ITML, TRML, TRMCLS
      CHARACTER ITEM*256, TRM*1
      LOGICAL FIRST
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GITEM
 
C     + + + DATA INITIALIZATIONS + + +
C      1  identifier
C      2  integer         Gives the offset number for the state 
C      3  fixed           number of the item. 
C      4  single1   
C      5  single2   
C      6  single3   
C      7  double1         Negative values in DEFTYP denote items
C      8  double2         that should not be seen. -1: never to be
C      9  double3         seen; -2:might be some reason to see them
C     10  asteriskp       in the future.
C     11  commap    
C     12  slashi    
C     13  backslashi
C     14  coloni    
C     15  equali    
C     16  sign
C     17  string
      DATA DEFTYP/CHRVAL, INTVAL, REAVAL,-1,-1,REAVAL,-1,-1,
     A            DPRVAL,PLACE_HOLDER,-2,CONTINUATION_VALUE,-2,-2,-2,
     B            -1,CHRVAL/
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,'*ERR:552* Found at least',I5,' items. Expected no more',
     A       ' than',I5)
 51   FORMAT(/,'*BUG:XXX* Invalid type=',I5,' found in GETVAL.')
 52   FORMAT(/,'*ERR:553* Expected an integer number but found ',A20,
     A         ' instead.')
 53   FORMAT(/,'*ERR:554* Expected a number but found ',A20,' instead.')
 54   FORMAT(/,'*WRN:555* Expected an identifier but found ',A20,
     A       ' instead.')
 56   FORMAT(/,' Offending line:',A)
58    FORMAT(/,'*BUG:XXX* Invalid numeric field in GETVAL:',A)
C***********************************************************************
C     CLEAR THE COUNTER FOR VALUES FOUND
 
      MVAL = 0
 
C     SET THE FIRST CALL TO TRUE
 
      FIRST = .TRUE.
 
C     SEEK SUCCESSIVE ITEMS FROM LINE AND TAKE THE REQUIRED ACTION.
 
99999 CONTINUE
        CALL GITEM
     I            (LINE,
     M             FIRST,
     O             ITEM, ITML, ITMSTA, 
     O             TRM, TRML, TRMCLS, EOS)
        IF(TRMCLS.EQ.-1) EFLAG = 1
        IF(EOS.EQ.1.AND.ITML.EQ.0) THEN
C         END OF LINE FOUND.
            
          RETURN
        ELSE
C         PROCESS A VALUE.
          MVAL = MVAL + 1
          IF(MVAL.GT.NVAL) THEN
            WRITE(STDERR,50) MVAL, NVAL
            MVAL = MVAL - 1
            EFLAG = 1
            RETURN
          ENDIF
          IF(OPT.EQ.1.OR.OPT.EQ.2) THEN
            ITEM_TYPE(MVAL) = DEFTYP(ITMSTA)
            CVAL(MVAL) = ITEM
            CLEN(MVAL) = ITML
            TERM(MVAL) = TRM
            TERML(MVAL) = TRML
            TERMCLS(MVAL) = TRMCLS
          ENDIF
 
          IF(OPT.EQ.1) GOTO 70000
 
C         If the item type is ASTERISKP, then we do not
C         attempt to compute its value. Note that comma
C         place holders have been replaced by ASTERISKP.  
C         Also do not try to convert a continuation signal.
C         

          IF(ITMSTA.EQ.ASTERISKP.OR.ITMSTA.EQ.SLASHI) GOTO 70000

C         BRANCH ON THE TYPE EXPECTED/FOUND.
 
          GOTO(10000, 20000, 30000, 40000), ITEM_TYPE(MVAL)
 
            WRITE(STDERR,51) ITEM_TYPE(MVAL)
            STOP 'Abnormal stop: errors found.'
 
10000       CONTINUE
C             EXPECTING AN INTEGER VALUE
              IF(ITMSTA.NE.INTEGER) THEN
                WRITE(STDERR,52) ITEM(1:ITML)
                EFLAG = 1
                WRITE(STDERR,56) LINE
                WRITE(STDERR,*) ' '
              ELSE
                READ(ITEM(1:ITML),'(I10)',ERR=90000) IVAL(MVAL)
              ENDIF
              GOTO 70000
 
20000       CONTINUE
C             Expecting a real value.  Accept INTEGER, FIXED, and SINGLE3

              IF(ITMSTA.EQ.INTEGER.OR.ITMSTA.EQ.SINGLE3.OR.
     A           ITMSTA.EQ.FIXED) THEN
                READ(ITEM(1:ITML),'(F20.0)',ERR=90000) RVAL(MVAL)
              ELSE
                WRITE(STDERR,53) ITEM(1:ITML)
                EFLAG = 1
                WRITE(STDERR,56) LINE
                WRITE(STDERR,*) ' '
              ENDIF
              GOTO 70000
 
30000       CONTINUE
C             EXPECTING A DOUBLE PRECISION VALUE. 
C             Accept INTEGER, FIXED, SINGLE3, AND DOUBLE3
              IF(ITMSTA.EQ.INTEGER.OR.ITMSTA.EQ.FIXED.OR.
     A           ITMSTA.EQ.SINGLE3.OR.ITMSTA.EQ.DOUBLE3) THEN
                READ(ITEM(1:ITML),'(D20.0)',ERR=90000) DPVAL(MVAL)
              ELSE
                WRITE(STDERR,53) ITEM(1:ITML)
                EFLAG = 1
                WRITE(STDERR,56) LINE
                WRITE(STDERR,*) ' '
              ENDIF
              GOTO 70000
 
40000       CONTINUE
C             Expecting a character value.  This could be an identifier
C             or a generic string.  Accept anything else that gets
C             through but issue a warning.  Primarily useful in
C             debugging changes in the code.  Normally nothing
C             else should appear here. 
C            
              IF(ITMSTA.NE.IDENTIFIER.AND.ITMSTA.NE.STRING) THEN
                WRITE(STDERR,54) ITEM(1:ITML)
                WRITE(STDERR,56) LINE
                WRITE(STDERR,*) ' '
              ENDIF
              CVAL(MVAL) = ITEM
              CLEN(MVAL) = ITML
              GOTO 70000
 
70000     CONTINUE
        ENDIF
        IF(EOS.EQ.1) RETURN
        GOTO 99999

90000 CONTINUE
        WRITE(STDERR,58) ITEM(1:ITML)
      STOP 'Abnormal stop. Bug found.'

      END
C     ***********
C     *         *
C     * GET_NAMED_ITEMS
C     *         *
C     ***********

      SUBROUTINE GET_NAMED_ITEMS(
     I                           STDIN, STDOUT,  MAX_LINE, N_NAME,
     I  GROUP, RESPONSE_TYPE, CONVERT_RULE, GROUP_INDEX, NAME_TABLE,
     I  N_INTEGER, N_DP,  N_CHAR, BLOCK_NAME,
     O  INTEGER_RESPONSE, REAL_RESPONSE, DP_RESPONSE, CHAR_RESPONSE,
     O  EFLAG)

C     Get one or more named items from one or more lines of user input.
C     A named item is a name known to the routine that called us
C     followed by an equal sign which is followed by one or more 
C     responses on a single line.  No response can carry over to 
C     a following line.  A response can be more than one value 
C     of a type that depends on the response type of the name.
C     Some names will not have a response.  They represent a value
C     in themselves. 

C     STDIN- unit number for input of lines of user information.
C     STDOUT- unit number for communication with the user via output
C     MAX_LINE- maximum number of lines to process.  Used to enable processing
C               a single line.  Otherwise MAX_LINE should be large. 
C     N_NAME- number of names that might appear.  There can be aliases,
C             that is, different names that have the same meaning.
C     The following values are all vectors that have the extent: N_NAME
C     GROUP- gives the code defining the response group: numeric data, 
C            character data, end signal, or next block.  
C            Numeric data are integer, real, or double
C            precision.  Character data are character strings.
C            End signal and next block are used to terminate the processing
C            of lines. 
C     RESPONSE_TYPE- gives the type of the response: integer value,
C                real value, double precision value, multiple real
C                value, date-time, or none.
C     CONVERT_RULE-  exact: the numeric value must exactly match the
C                   numeric type or types.  Thus if the response type
C                   is integer, the response MUST be an integer.  That
C                   is 123 is valid but 123. is not valid.  lower: the
C                   numeric response will take a lower type where 
C                   the ranking from high to low is: double precision,
C                   real, integer.  Thus if the response type is real,
C                   a response of 123 is valid even though it is an 
C                   integer. 
C     GROUP_INDEX- index into the vector of the type that matches the
C                  GROUP-numeric or character.  The numeric responses
C                  are considered to be in an overlay.  That is
C                  real, integer, and double precision are overlaid
C                  on the same space.  We assume that integer and real
C                  values are the same size in the target processor
C                  and the double precision is double the size of 
C                  a real.  The index for a double precision value is
C                  the index in the real vector to its first real
C                  element.  For example:

C Name          Name       Group    Response   Group
C count                             type      index          Notes
C -----   ----------    --------  ----------  ------  ------------------------------------------------------------
C   1     NBRA           NUMERIC  INTVAL        1
C   2     NEX            NUMERIC  INTVAL        2
C   3     SFAC           NUMERIC  REAVAL        3     This is the first real value but it gets index 3
C                                               4     We need this space  so that 
C                                                     the following double precision value will have the correct
C                                                     index value.  The index value must alwasy be the first
C                                                     of two real elements
C   4     FACTOR         NUMERIC  DPRVAL        5     This one takes two slots
C                                               6     Needed for the double precision value
C                                               7     Needed so that following date-time value has proper index. 
C                                                     This can be avoided in most cases but I put it here as 
C                                                     an example of how the data-time value must be placed.
C   5     STIME          NUMERIC  DATETIME      8     Contains the year
C                                               9     Contains the month number 
C                                              10     contains the day number
C                                              11     contains double 
C                                              12      precision hour of the day           
C   6     SOPER          CHAR     CHRVAL        1     Note that character values have their own index.  Each 
C                                                     character value can be 64 characters long.
C   7     BRANCH         NXTBLK   NONE          0     Group index is not used.  This example would apply to 
C                                                     processing the run-control block because the heading
C                                                     for the branch-description block could follow it.
C                                                     The line containing BRANCH must be put back on the input.
C   8     END            ENDSIG   NONE          0     An explicit end signal for the current block.  

C     NAME_TABLE-  contains the names for the possible responses.  In the example just above, 
C                  there would be 8 names in the table of names. 
C     N_INTEGER-  number of elements in the numeric-response table for integers and reals.  
C                 Should be even number   because the double precision vector will get one-half this 
C                 number of elements. 
C     N_DP-       number of elements in the numeric-response table for double precision values. 
C                 Should be one-half N_INTEGER.
C     N_CHAR-     number of elements in the character-response table
C     BLOCK_NAME- name of the block or command being processed.  Needed in error messages.
C     INTEGER_RESPONSE - vector for integer responses
C     REAL_RESPONSE - vector for the real responses
C     DP_RESPONSE- vector for double precision responses
C     CHAR_RESPONSE- vector for character responses
C     EFLAG- error flag.  If > 0 an error has been found. 

      IMPLICIT NONE

      INTEGER STDIN, STDOUT, MAX_LINE, N_NAME, EFLAG, N_INTEGER,
     A        N_DP, N_CHAR
      INTEGER GROUP(N_NAME), RESPONSE_TYPE(N_NAME), 
     A        CONVERT_RULE(N_NAME), GROUP_INDEX(N_NAME),
     B        INTEGER_RESPONSE(N_INTEGER)

      REAL REAL_RESPONSE(N_INTEGER)

      REAL*8 DP_RESPONSE(N_DP)

      CHARACTER CHAR_RESPONSE(N_CHAR)*(*), NAME_TABLE(N_NAME)*16,
     A          BLOCK_NAME*(*)

C     Local

C     + + + LOCAL PARAMETERS + + +
      INTEGER  NVAL, INTVAL, REAVAL, CONTINUATION_VALUE,
     A         CHRVAL, DPRVAL, EXACT, LOWER,
     B         DATETIME, MULTR, NUMERIC, CHAR, NXTBLK, ENDSIG,
     C         NONE
      PARAMETER( NVAL=40, INTVAL=1, REAVAL=2,
     A          DPRVAL=3, CHRVAL=4, CONTINUATION_VALUE=5,
     B          EXACT=0,LOWER=1,DATETIME=7, MULTR=8, NONE=0, 
     C          NUMERIC=0, CHAR=1, NXTBLK=2, ENDSIG=3)

      INTEGER EFLAG2, I, IE, IT, J, JS, K, KNT, OPT, IP, GROUP_CODE,
     A        ITEM_KNT, TYPE, MAXKNT, NMULT_GIVEN, NMULT_COUNTED,
     B        LINE_KNT
      INTEGER CLEN(NVAL), IVAL(NVAL), TERML(NVAL), TERMCLS(NVAL),
     A        ITEM_TYPE(NVAL)
      REAL RVAL(NVAL)
      REAL*8 DPVAL(NVAL)
      CHARACTER CVAL(NVAL)*256, TERM(NVAL)*1, LINE*196,
     A          KEY*16


      EXTERNAL  GETVAL, inline

C     *****************************FORMATS******************************
54    FORMAT(/,' *ERR:389* Name=',A,' is unknown in: ',A)
56    FORMAT(/,' Unable to continue due to previous errors in: ',A)
60    FORMAT(/,' Processing:',A)
62    FORMAT(/,' *ERR:390* Count=',I5,' is too large for: ',A)
64    FORMAT(/,' *WRN:391* ',I4,' items requested ',
     A          'but only ',I4,' found.')
C***********************************************************************
C     Clear the local error flag for subroutine GETVAL 
      EFLAG2 = 0
C     Read lines of input and process each one until the expected number
C     of lines or an end of block signal is found.  

C     Default values must be set for all possible responses before we 
C     get here. 
 
C     Select option for GETVAL to return BOTH the string value
C     and the converted value for numeric responses.  
C     In some cases the value will be recomputed. 
      OPT = 2
C     Start a loop over input lines
      LINE_KNT = 0
100   CONTINUE

        IF(LINE_KNT.GE.MAX_LINE) RETURN

        CALL inline
     I            (STDIN, STDOUT,
     O             LINE)

        LINE_KNT = LINE_KNT + 1


        IT = LEN_TRIM(LINE)
        WRITE(STDOUT,60) LINE(1:IT)

        LINE(IT+1:IT+1) = ''''

        CALL GETVAL
     I             (STDOUT, LINE, NVAL, OPT,
     O              ITEM_TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, 
     O              EFLAG2, TERM, TERML, TERMCLS,
     O              ITEM_KNT)
C      WRITE(STDOUT,*) 
C     A  ' Return from GETVAL in GET_NAMED_ITEMS: ITEM_KNT=',ITEM_KNT
C      WRITE(STDOUT,97)
C97    FORMAT(1X,12X,'ITEM','   LEN  TYPE T  TCLS')
C      DO 9213 I=1,ITEM_KNT
C        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I),
C     A                  TERMCLS(I)
C99    FORMAT(' ',A16,' ',I5,' ',I5,' ',A1,' ',I5)
C9213  CONTINUE


        IF(EFLAG2.NE.0) THEN
C         Error in parsing the line of input.
          
          WRITE(STDOUT,56) BLOCK_NAME(1:LEN_TRIM(BLOCK_NAME))
          STOP 'Abnormal stop.  Errors found.'
        ELSE
C         No errors reported.  Process the items found on the current
C         line. 

C         Check if this is already something from a following input block
C         or the end of block signal.  CHK_AND_CONVERT_RESPONSE does
C         not know anything about what might follow this signal value.

          I = 1
C         Find the value for the next item from the 
C         symbol table. 
          KEY = CVAL(I)(1:CLEN(I))
          CALL LSTAB
     I              (KEY, NAME_TABLE, N_NAME,
     O               IP)
          IF(IP.EQ.0) THEN
C           error-symbol not found
            WRITE(STDOUT,54) KEY, BLOCK_NAME(1:LEN_TRIM(BLOCK_NAME))
            EFLAG = 1
            STOP 'Abnormal stop.  Errors found.'
          ELSE
            GROUP_CODE = GROUP(IP)
            IF(GROUP_CODE.EQ.NXTBLK) THEN
              BACKSPACE(STDIN)
              RETURN
            ELSEIF(GROUP_CODE.EQ.ENDSIG) THEN
              RETURN
            ENDIF
          ENDIF


          CALL CHK_AND_CONVERT_RESPONSE(STDOUT,
     I           N_NAME, NAME_TABLE, RESPONSE_TYPE,
     I           CONVERT_RULE, ITEM_KNT, ITEM_TYPE, CVAL, CLEN,
     M           EFLAG,
     O           IVAL, RVAL, DPVAL)

          I = 1
110       CONTINUE          
C           Find the value for the next item from the 
C           symbol table. 
            KEY = CVAL(I)(1:CLEN(I))
            CALL LSTAB
     I                (KEY, NAME_TABLE, N_NAME,
     O                 IP)
            IF(IP.EQ.0) THEN
C             error-symbol not found
              WRITE(STDOUT,54) KEY, BLOCK_NAME(1:LEN_TRIM(BLOCK_NAME))
              EFLAG = 1
              STOP 'Abnormal stop.  Errors found.'
            ELSE
              GROUP_CODE = GROUP(IP)
              IT = GROUP_INDEX(IP)            
              TYPE = RESPONSE_TYPE(IP)
            ENDIF


            IF(GROUP_CODE.EQ.NUMERIC) THEN
C             Responses are a numeric value.
              IF(TYPE.EQ.INTVAL) THEN
                INTEGER_RESPONSE(IT) = IVAL(I+1)
              ELSEIF(TYPE.EQ.REAVAL) THEN
                REAL_RESPONSE(IT) = RVAL(I+1)
              ELSEIF(TYPE.EQ.DPRVAL) THEN
                DP_RESPONSE((IT+1)/2) = DPVAL(I+1)
              ELSEIF(TYPE.EQ.DATETIME) THEN
C               IT points to the year location.  Month and day are
C               at unit increments away.  The hour is double precision
C               and is stored as a conceptual overlay on the real and 
C               integer vectors.  E. G. IT -> year, IT+1->month
C               IT+2-> day and (IT+4)/2-> hour.
                INTEGER_RESPONSE(IT) = IVAL(I+1)
                INTEGER_RESPONSE(IT+1) = IVAL(I+2)
                INTEGER_RESPONSE(IT+2) = IVAL(I+3)
                DP_RESPONSE((IT+4)/2) = DPVAL(I+4)
                I = I + 3
              ELSEIF(TYPE.EQ.MULTR) THEN
C               Compute the maximum number of real items.  Note: the 
C               multiple real repsonses cannot be the last in the 
C               vectors.  There must be another input item following
C               so that IP + 1 is valid. 
                MAXKNT = GROUP_INDEX(IP+1) - IT - 1
                JS = 1
                NMULT_GIVEN = -1
                NMULT_COUNTED = 0
                IF(ITEM_TYPE(I+1).EQ.INTVAL.AND.
     A             IVAL(I+1).LE.MAXKNT) THEN
C                 Treat as count of the number of real values.
                  NMULT_GIVEN = IVAL(I+1)
                  JS = 2
                ENDIF
C               Determine the number of items for error checking
                J = JS
150             CONTINUE
                  IF(I+J.GT.ITEM_KNT) GOTO 160
                  IF(ITEM_TYPE(I+J).EQ.CHRVAL) GOTO 160
                  J = J + 1
                  GOTO 150
160             CONTINUE
                NMULT_COUNTED = J - JS
                
C                WRITE(STDOUT,*) ' NMULT_GIVEN=',NMULT_GIVEN,
C     A                       ' NMULT_COUNTED=',NMULT_COUNTED
                IF(NMULT_GIVEN.GT.NMULT_COUNTED) THEN
                  WRITE(STDOUT,64) NMULT_GIVEN, NMULT_COUNTED
                  NMULT_GIVEN = NMULT_COUNTED
                ENDIF
                IF(NMULT_GIVEN.GE.0) THEN
                  INTEGER_RESPONSE(IT) = NMULT_GIVEN
                ELSE
                  INTEGER_RESPONSE(IT) = NMULT_COUNTED
                ENDIF
                
                IF(INTEGER_RESPONSE(IT).GT.MAXKNT) THEN 
                  WRITE(STDOUT,62) INTEGER_RESPONSE(IT), KEY
                  STOP 'Abnormal stop.  Errors found.'
                ENDIF

                IF(INTEGER_RESPONSE(IT).GT.0) THEN
                  DO 165 J=1, INTEGER_RESPONSE(IT)
                    K = J + JS - 1
                    REAL_RESPONSE(IT+J) = RVAL(I+K)
165               CONTINUE
                ENDIF
                  I = I + NMULT_COUNTED + JS - 1
              ENDIF
            ELSEIF(GROUP_CODE.EQ.CHAR) THEN
C             The responses are character values.
              CHAR_RESPONSE(IT) = CVAL(I+1)(1:CLEN(I+1))
            ENDIF
C           Do the increment for single response items.  Multiple response 
C           items must increment such that the correct result occurs with this
C           final increment!
            I = I + 2
            IF(I.GT.ITEM_KNT) THEN
C             Get the next line from the input
              GOTO 100
            ELSE
C             Get the next item from the current line
              GOTO 110
            ENDIF            
        ENDIF

200   CONTINUE
      RETURN
      END

C     ***********
C     *         *
C     * GET_HEAD_LIMTS
C     *         *
C     ***********
 
      SUBROUTINE  GET_HEAD_LIMITS
     I                           (STDOUT, STRING, MAXN,
     O                            N, HEAD_START, HEAD_END)
 
C     + + + PURPOSE + + +
C     Get the starting and stopping column numbers for each
C     heading in the string. 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER MAXN, N, HEAD_START(MAXN), HEAD_END(MAXN), STDOUT
      CHARACTER  STRING*(*)

C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT - standard output
C     STRING - string to scan
C     MAXN - maximum extent for vectors in arg list
C     N - number of headings found
C     HEAD_START - column number of start of each heading
C     HEAD_END - column number of end of each heading.

C     + + + LOCAL VARIABLES + + +
      INTEGER DONE, I, IEND, ISTART, ISTOP, IT

C     + + + INTRINSICS + + +
      INTRINSIC LEN_TRIM
C     **************************FORMATS*********************************
50    FORMAT(/,' *ERR:392* Found ',I3,' headings > ',I3,' allowed.')
C***********************************************************************
      I = 1
      DONE = 0
      IEND = LEN_TRIM(STRING)
C     Seek a single quote marking beginning of a comment
      IT = INDEX(STRING(1:IEND),'''')
      IF(IT.GT.0) THEN
C       Single quote found.  Character before it becomes the end
        IEND = IT - 1
      ENDIF
      

C      WRITE(STDOUT,*) ' IEND=',IEND
      N = 0

 100  CONTINUE
        IF(STRING(I:I).EQ.' ') THEN
          I = I + 1
          IF(I.LE.IEND) THEN
            GOTO 100
          ELSE
C           RETURN if no non-blank found
            RETURN
          ENDIF
        ELSE
          ISTART = I
 110      CONTINUE
            IF(STRING(I:I).NE.' ') THEN
              I = I + 1
              IF(I.LE.IEND) THEN
                GOTO 110
              ELSE
                ISTOP = I-1
                DONE = 1
              ENDIF
            ELSE
              ISTOP = I-1
            ENDIF
        ENDIF

      N = N + 1
      IF(N.GT.MAXN) THEN
        WRITE(STDOUT,50) N, MAXN
        STOP 'Abnormal stop.  Errors found.'
      ENDIF
      HEAD_START(N) = ISTART
      HEAD_END(N) = ISTOP

      IF(DONE.EQ.1) RETURN

      GOTO 100
      END
C
C
C
      SUBROUTINE GET_ITEM_LIMITS(
     I                           STDOUT, STRING, MAXN, JUST,
     O                           N, ITEM_START, ITEM_END)

C     Find the column limits for the items on an input line as defined
C     by the justification rule and the limits for the headings supplied
C     by the user.
 
      IMPLICIT NONE
      CHARACTER JUST*5, STRING*(*)
      INTEGER N, MAXN, STDOUT, ITEM_START(MAXN),ITEM_END(MAXN)

C     Called program units

      EXTERNAL GET_HEAD_LIMITS

C     Local

      INTEGER I
      INTEGER HEAD_START(MAXN), HEAD_END(MAXN)
C***********************************************************************
      CALL  GET_HEAD_LIMITS
     I                     (STDOUT, STRING, MAXN,
     O                      N, HEAD_START, HEAD_END)
      IF(JUST.EQ.'LEFT') THEN
C       Use left justification to set the limits
        DO 100 I=1,N-1
          ITEM_START(I) = HEAD_START(I)
          ITEM_END(I) = HEAD_START(I+1) - 1
100     CONTINUE
C       Assume a max of 10 columns for the last column of input.
        ITEM_START(N) = HEAD_START(N)
        ITEM_END(N) = ITEM_START(N) + 10 - 1
      ELSE
C       Use right justification to set the limits
C       Do the first item.  Always starts in column 1.
        ITEM_START(1) = 1
        ITEM_END(1) = HEAD_END(1)
        DO 110 I=2,N
          ITEM_START(I) = HEAD_END(I-1) + 1
          ITEM_END(I) = HEAD_END(I)
110     CONTINUE
      ENDIF
      RETURN
      END
