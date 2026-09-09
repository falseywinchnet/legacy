C     ***********
C     *         *
C     * REPLACE_IDENTIFIERS
C     *         *
C     ***********

      SUBROUTINE REPLACE_IDENTIFIERS(STDOUT, MAX_NVAL, MODE, NVAL,
     M                   CVAL, CLEN, ITEM_TYPE, 
     O                   EFLAG)

C     Scan the list of items and replace any unknown identifiers
C     with their value from the symbol table. 

      IMPLICIT NONE
      INTEGER STDOUT, NVAL, MAX_NVAL, MODE, CLEN(MAX_NVAL),
     A        ITEM_TYPE(MAX_NVAL), EFLAG

      CHARACTER CVAL(MAX_NVAL)*(*)

C     Local

      INTEGER IS, INTVAL, CHRVAL, I, CLASS, INDX,
     A        VALUE, LOOKUP
      PARAMETER(INTVAL=1, CHRVAL=4)

      CHARACTER WORK*16, KEY*16

      INTEGER LENSTR
      EXTERNAL LENSTR, LS_GLOBAL, STRIP_L_BLANKS, 
     A         FIND_INTERNAL_TAB_NUMBER
C     ******************************FORMATS*****************************
50    FORMAT(/,' *WRN:52* Name= ',A,' is unknown in an instruction.',
     A       '  May cause later errors.')
C***********************************************************************
      IF(MODE.EQ.0) THEN
C       Skip the first item in the list-it is the instruction name or
C       the macro name. 
        IS = 2
      ELSE
C       This is a continuation line.  Start at the first item.
        IS = 1
      ENDIF

C     Find all items of type character value, skip any that are 
C     predefined, and lookup the rest in the symbol table. 

      DO 200 I=IS,NVAL
C       Clear the lookup flag
        LOOKUP = 0        

        IF(ITEM_TYPE(I).EQ.CHRVAL) THEN
C         Eliminate predefined values.  
          IF(CLEN(I).EQ.1) THEN
            IF(CVAL(I).NE.'U'.AND.CVAL(I).NE.'D'.AND.
     A         CVAL(I).NE.'F') THEN
C             Unknown identifier of length 1.
              LOOKUP = 1
            ENDIF
          ELSE
C           Identifier is longer than 1 character.
            IF(CVAL(I)(1:1).NE.'U'.AND.CVAL(I)(1:1).NE.'D'.AND.
     A         CVAL(I)(1:1).NE.'F') THEN
C             Unknown identifier of length greater than 1
C             which cannot be predefined.  
   
              LOOKUP = 1
            ELSE
C             Identifer begins with U, D, or F, is more
C             than 1 character long.  May be predefined
C             if it references an exterior node. 
              READ(CVAL(I)(2:CLEN(I)),*,ERR=110) VALUE
C               Characters after first char are an integer.
                IF(VALUE.GT.9999) THEN
                  LOOKUP = 1
                ENDIF
                GOTO 120
110           CONTINUE
C               Character after first char not an integer.
C               The identifier is unknown.

                LOOKUP = 1
120           CONTINUE
            ENDIF
          ENDIF
          IF(LOOKUP.EQ.1) THEN
C           We found an unknown identifier.  Look it up.
            KEY = CVAL(I)
            CALL LS_GLOBAL
     I                     (KEY,
     O                      CLASS, VALUE, INDX)
            IF(INDX.EQ.0) THEN
C             See if it is a table id. 
              CALL  FIND_INTERNAL_TAB_NUMBER
     I                                      (KEY,
     O                                       INDX)
              IF(INDX.EQ.0) THEN
                IF(CVAL(I)(1:3).NE.'TAB'.AND.CVAL(I)(1:3).NE.'tab') THEN
                  WRITE(STDOUT,50) CVAL(I)(1:CLEN(I))
                ENDIF
              ENDIF
            ELSE
              WRITE(WORK,'(I10)') VALUE
              CALL STRIP_L_BLANKS(
     M                        WORK)
              CLEN(I) = LENSTR(WORK)
              ITEM_TYPE(I) = INTVAL
              CVAL(I) = WORK
            ENDIF
          ENDIF
        ENDIF
200   CONTINUE
      RETURN
      END

C     ***********
C     *         *
C     * PRESCAN
C     *         *
C     ***********

      SUBROUTINE PRESCAN(STDOUT, MAX_NVAL, MODE,
     M                   NVAL, CVAL, CLEN, ITEM_TYPE, TERM,
     M                   TERML, TERMCLS, IVAL,
     O                    EFLAG)

C     Do several scans of the list of items processing the
C     incrementation, decrementation, concatenation, and
C     replication operators that appear, if any.  

      IMPLICIT NONE
      INTEGER STDOUT, NVAL, MAX_NVAL, MODE, CLEN(MAX_NVAL),
     A        ITEM_TYPE(MAX_NVAL), TERML(MAX_NVAL), 
     B        TERMCLS(MAX_NVAL), IVAL(MAX_NVAL), EFLAG

      CHARACTER CVAL(MAX_NVAL)*(*), TERM(MAX_NVAL)*1

C     Local

      INTEGER IGET, IS, LEFT, RIGHT, ASTERISK, PLUS_OR_MINUS,
     A        VERTICAL_BAR, INTVAL, CHRVAL, IDFLAG,
     B        N, N_ADD, REPLICATE, IPUT, I, REAVAL, DPRVAL

      PARAMETER (ASTERISK=2, PLUS_OR_MINUS=3, VERTICAL_BAR=17)
      PARAMETER(INTVAL=1, REAVAL=2, DPRVAL=3, CHRVAL=4)

      CHARACTER CHR*1, WORK*128, increment*15

      INTEGER len_trim
C     ***********************FORMATS************************************
50    FORMAT(/,' *ERR:288* Argument: ',A,' before a + or - is not a',
     A        ' valid exterior-node label.')
52    FORMAT(/,' *ERR:289* Argument: ',A,' following a + or - is',
     A         ' not an integer.')
54    FORMAT(/,' *ERR:290* Decrementing ',I8,' by ',I8,' yields a',
     A         ' negative result.')
56    FORMAT(/,' *ERR:291* A replication factor ',A,' is not an',
     A         ' integer.')
58    FORMAT(/,' *ERR:292* Replication factor=',I5,' is < 2')
C***********************************************************************
      IF(MODE.EQ.0) THEN
C       Skip the first item in the list-it is the instruction name or
C       the macro name. 
        IS = 2
        IGET = 2
      ELSE
C       This is a continuation line.  Start at the first item.
        IS = 1
        IGET = 1
      ENDIF

C     Do a scan of the arguments to lookup any identifiers. 

      CALL REPLACE_IDENTIFIERS(STDOUT, MAX_NVAL, MODE, NVAL,
     M                         CVAL, CLEN, ITEM_TYPE, 
     O                         EFLAG)

C     Now move items in the list and check for the plus/minus operator.
100   CONTINUE
        IF(TERMCLS(IGET).EQ.PLUS_OR_MINUS) THEN
C         Do the operation.  Convert the first operand.
          IF(ITEM_TYPE(IGET).EQ.INTVAL) THEN
            IDFLAG = 0
            READ(CVAL(IGET),*) LEFT
          ELSEIF(ITEM_TYPE(IGET).EQ.CHRVAL) THEN
C           Item must be a exterior node label.
c           Maybe a TAB or tab-trying to get this implemented
            IDFLAG = 1
            CHR = CVAL(IGET)(1:1)
            IF(CHR.EQ.'F'.OR.CHR.EQ.'D'.OR.CHR.EQ.'U') THEN
C             First character is ok.  Try to convert the integer part.
              READ(CVAL(IGET)(2:),*, ERR=110) LEFT
              GOTO 120
110           CONTINUE
                WRITE(STDOUT,50) CVAL(IGET)(1:CLEN(IGET))
                STOP 'Abnormal stop: errors found.'
120           CONTINUE
            ELSEIF(cval(iget)(1:3) == 'TAB'.or.
     a             cval(iget)(1:3) == 'tab') then
c             Process adjustment to a datum not yet known. 
c             We will combine into a single string and pass
c             it on to the next level for processing.
              idflag = 2
            else         
              WRITE(STDOUT,50) CVAL(IGET)(1:CLEN(IGET))
              STOP 'Abnormal stop: errors found.'
            ENDIF
          ELSE
            WRITE(STDOUT,50) CVAL(IGET)(1:CLEN(IGET))
            STOP 'Abnormal stop: errors found.'
          ENDIF

C         Convert the second operand.  Could be integer, real, or double
          IF(ITEM_TYPE(IGET+1).EQ.INTVAL) THEN
            READ(CVAL(IGET+1),*) RIGHT
          elseif(ITEM_TYPE(IGET+1).EQ.REAVAL.or.
     a           ITEM_TYPE(IGET+1).EQ.DPRVAL) then
c           Extract the string 
            increment =  CVAL(IGET+1)
          ELSE
            WRITE(STDOUT,52) CVAL(IGET+1)(1:CLEN(IGET+1))
            STOP 'Abnormal stop: errors found.'
          ENDIF

C         Now do the operation.
          if(idflag /= 2) then
            IF(TERM(IGET).EQ.'+') THEN
              LEFT = LEFT + RIGHT
            ELSE
              LEFT = LEFT - RIGHT
              IF(LEFT.LE.0) THEN
                WRITE(STDOUT,54) LEFT, RIGHT
                STOP 'Abnormal stop: errors found.'
              ENDIF
            ENDIF
          

C           Now create the character-string form of the result.
            WRITE(WORK,'(I10)') LEFT
            CALL STRIP_L_BLANKS(
     M                        WORK)
            IF(IDFLAG.EQ.0) THEN
              CVAL(IS) = WORK
            ELSE
              CVAL(IS)(1:1) = CHR
              CVAL(IS)(2:) = WORK
            ENDIF
          else
c           concatenate the increment back onto the 
c           TAB or tab so that it is passed to the next level
            
            cval(is) = 'TAB'//term(iget)//increment
          endif
          CLEN(IS) = len_trim(CVAL(IS))
          ITEM_TYPE(IS) = ITEM_TYPE(IGET)
          TERM(IS) = TERM(IGET+1)
          TERMCLS(IS) = TERMCLS(IGET+1)
          TERML(IS) = TERML(IGET+1)

          IS = IS + 1
C         Skip over the operand just processed.
          IGET = IGET + 2
          IF(IGET.LE.NVAL) GOTO  100
        ELSE
          CVAL(IS) = CVAL(IGET)
          CLEN(IS) = CLEN(IGET)
          ITEM_TYPE(IS) = ITEM_TYPE(IGET)
          TERM(IS) = TERM(IGET)
          TERMCLS(IS) = TERMCLS(IGET)
          TERML(IS) = TERML(IGET)
          IS = IS + 1
          IGET = IGET + 1
          IF(IGET.LE.NVAL) GOTO 100
        ENDIF              
      NVAL = IS - 1

C      WRITE(STDOUT,*) ' After first scan: NVAL=',NVAL
C      WRITE(STDOUT,97)
C97    FORMAT(1X,12X,'ITEM','   LEN  TYPE T  TCLS')
C      DO 9213 I=1,NVAL
C        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I),
C     A                  TERMCLS(I)
C99    FORMAT(' ',A16,' ',I5,' ',I5,' ',A1,' ',I5)
C9213  CONTINUE

      
C     Now move items in the list and check for the concatenation operator.
      IF(MODE.EQ.0) THEN
C       Skip the first item in the list-it is the instruction name or
C       the macro name. 
        IS = 2
        IGET = 2
      ELSE
C       This is a continuation line.  Start at the first item.
        IS = 1
        IGET = 1
      ENDIF
200   CONTINUE
        IF(TERMCLS(IGET).EQ.VERTICAL_BAR) THEN
C         Do the operation. 
          CVAL(IS) = CVAL(IGET)
          CVAL(IS)(CLEN(IGET)+1:) = CVAL(IGET+1)
          CLEN(IS) = len_trim(CVAL(IS))
          ITEM_TYPE(IS) = ITEM_TYPE(IGET)
          TERM(IS) = TERM(IGET+1)
          TERMCLS(IS) = TERMCLS(IGET+1)
          TERML(IS) = TERML(IGET+1)

          IS = IS + 1
C         Skip over the operand just processed.
          IGET = IGET + 2
          IF(IGET.LE.NVAL) GOTO  200
        ELSE
          CVAL(IS) = CVAL(IGET)
          CLEN(IS) = CLEN(IGET)
          ITEM_TYPE(IS) = ITEM_TYPE(IGET)
          TERM(IS) = TERM(IGET)
          TERMCLS(IS) = TERMCLS(IGET)
          TERML(IS) = TERML(IGET)
          IS = IS + 1
          IGET = IGET + 1
          IF(IGET.LE.NVAL) GOTO 200
        ENDIF              
      NVAL = IS - 1


C     Now do the replication operations.  Need two passes.
C     The first computes the increased numbers of items. 
C     The second does the transfer. 

      IF(MODE.EQ.0) THEN
C       Skip the first item in the list-it is the instruction name or
C       the macro name. 
        IS = 1
        IGET = 2
      ELSE
C       This is a continuation line.  Start at the first item.
        IS = 0
        IGET = 1
      ENDIF
      N_ADD = 0
      REPLICATE = 0
300   CONTINUE
        IF(TERMCLS(IGET).EQ.ASTERISK) THEN
C         Convert the replication factor.
          REPLICATE = 1
          IF(ITEM_TYPE(IGET).EQ.INTVAL) THEN
            READ(CVAL(IGET),*) N
            IF(N.LE.1) THEN
              WRITE(STDOUT,58) N
              STOP 'Abnormal stop: errors found.'
            ENDIF
            IVAL(IGET) = N
          ELSE
            WRITE(STDOUT,56) CVAL(IGET)(1:CLEN(IGET))
            STOP 'Abnormal stop: errors found.'
          ENDIF
C         Compute the number of added items.  A replication
C         factor of 1 is invalid.  The replication factor itself
C         will be removed from the list.  Therefore, a factor
C         of 2 leaves the list length unchanged.  
          N_ADD = N_ADD + N - 2
          IGET = IGET + 2
        ELSE
          IGET = IGET + 1
        ENDIF
        IF(IGET.LE.NVAL) GOTO 300

        IF(REPLICATE.EQ.1) THEN
C         We have to do a replicate operation.  Scan the list
C         in reverse and transfer the values to the new locations
C         replicating arguments as required. 

          IPUT = NVAL + N_ADD
          IGET = NVAL

400       CONTINUE
            IF(TERMCLS(IGET).EQ.ASTERISK) THEN
C             One instance of the item being replicated has
C             already been transfered. Transfer it to 
C             subsequent locations. 
              N = IVAL(IGET) - 1
              DO 410 I=IPUT,IPUT - N + 1, -1
                CVAL(I) = CVAL(IPUT+1)
                CLEN(I) = CLEN(IPUT+1)
                ITEM_TYPE(I) = ITEM_TYPE(IPUT+1)
                TERM(I) = TERM(IPUT+1)
                TERMCLS(I) = TERMCLS(IPUT+1)
                TERML(I) = TERML(IPUT+1)
410           CONTINUE                
              IPUT = IPUT - N
              IGET = IGET - 1
            ELSE
C             Transfer the item.
              CVAL(IPUT) = CVAL(IGET)
              CLEN(IPUT) = CLEN(IGET)
              ITEM_TYPE(IPUT) = ITEM_TYPE(IGET)
              TERM(IPUT) = TERM(IGET)
              TERMCLS(IPUT) = TERMCLS(IGET)
              TERML(IPUT) = TERML(IGET)
              IPUT = IPUT - 1
              IGET = IGET -1
            ENDIF
            IF(IGET.GT.IS) GOTO 400
        ENDIF
      RETURN
      END      

C         
C
C
C
      SUBROUTINE TO_UPPER(
     M            STRING)
C
C     Convert a character string from lower case to upper case
C     Modified from USGS routine.

      IMPLICIT NONE
      CHARACTER*(*) STRING

C     + + + ARGUMENT DEFINITIONS + + +
C     STRING - character string to be made upper case

C     + + + LOCAL VARIABLES + + +
      INTEGER   I, ICH, IEND

C     + + + INTRINSICS + + +
      INTRINSIC  ICHAR, LEN, CHAR
C***********************************************************************
      IEND = LEN(STRING)
      DO 10 I = 1, IEND
        ICH = ICHAR(STRING(I:I))
        IF(ICH.GE.97 .AND. ICH.LE.122) THEN
C         Character is lower case.
          STRING(I:I)= CHAR(ICH-32)
        ENDIF
 10   CONTINUE

      RETURN
      END
C     ***********
C     *         *
C     * GET_CODE_NC_F
C     *         *
C     ***********


      SUBROUTINE GET_CODE_NC_F(STDOUT, MODE, LONG_LINE,
     O                     CODE, NC, NC_LONG, F, FC, EFLAG)

C     Process the items in LONG_LINE and create values
C     for CODE, NC, and F.

C     Dummy Arguments

      IMPLICIT NONE
      INTEGER  CODE, EFLAG, MODE, STDOUT
      REAL F(5)
      CHARACTER NC(10)*5, LONG_LINE*196,
     A          NC_LONG(10)*16, FC(5)*4

C     Local variables

      CHARACTER LINE*200

      INTEGER MAX_NVAL

      PARAMETER (MAX_NVAL=40)

      INTEGER  CHRVAL, CONTINUATION_VALUE, INTVAL, REAVAL, DPRVAL,
     A         PLACE_HOLDER
      PARAMETER(INTVAL=1, REAVAL=2, DPRVAL=3, CHRVAL=4,
     A          CONTINUATION_VALUE=5, PLACE_HOLDER=6)

      INTEGER MACRO_CLASS, INSTRUCTION_CLASS, VARIABLE_ARGUMENTS_CLASS
      PARAMETER (MACRO_CLASS=1, INSTRUCTION_CLASS=2,
     A           VARIABLE_ARGUMENTS_CLASS=3)

      INTEGER SEMICOLON
      PARAMETER (SEMICOLON = 20)

      INTEGER  FKNT, INIT_IKNT, IKNT, NVAL, OPT, I, NON_INT_ID,
     A         CLASS, VALUE, INDX, IT, ISTART, ILIMIT
      
      INTEGER CLEN(MAX_NVAL), IVAL(MAX_NVAL), ITEM_TYPE(MAX_NVAL),
     A        TERML(MAX_NVAL), TERMCLS(MAX_NVAL)
      REAL RVAL(MAX_NVAL)
      REAL*8 DPVAL(MAX_NVAL)
      CHARACTER CVAL(MAX_NVAL)*256, TERM(MAX_NVAL)*1, INSTRUCTION*16


      INTEGER LENSTR
      EXTERNAL TO_UPPER, LS_GLOBAL, LENSTR

C     *********************************FORMATS**************************
50    FORMAT(/,' *BUG* in GET_CODE_NC_F: No values found in line.')
52    FORMAT(/,' *ERR:293* First value on line:',A8,' not valid for',
     A         ' CODE.')
54    FORMAT(/,' *ERR:294* Too many values. Float values MUST have',
     A          ' a decimal point present.')
56    FORMAT(/,' *ERR:295* Wrong type. Make sure float values have a',
     A          ' decimal point present.')
58    FORMAT(/,' *ERR:296 Too many float values.')
60    FORMAT(/,' *ERR:297* Instruction named: ',A,' not known.  Check',
     A        ' spelling here',/,5X,'and in DEFINE MACROS block.')
62    FORMAT(/,' Found macro instruction: ',A)
64    FORMAT(/,' Found instruction: ',A)
C***********************************************************************
C     Clear the target variables.
      DO 95 I=1,10
        NC(I) = ' '
        NC_LONG(I) = ' '
95    CONTINUE
      DO 96 I=1,5
        F(I) = 0.0
C       Set information to check for missing float values
C       so they do not get set to zero as a default.
        FC(I) = 'NONE'
96    CONTINUE

      LINE = LONG_LINE
      IT = LENSTR(LINE)
C     Search for user given quote.
      I = INDEX(LINE(1:IT),'''')
      IF(I.EQ.0) THEN
        LINE(IT+1:IT+1) = ''''
C      ELSE
C       Revise user quote to  ,quote
C        LINE(I:I+2) = ' ,'''
C        IT = I
      ENDIF

      WRITE(STDOUT,98) LINE(1:IT)
98    FORMAT(/,' Current instruction line:',/,1x,A)


C     Select the option to return what is found with no
C     expectations being enforced.
      OPT = 1
      CALL GETVAL(STDOUT, LINE, MAX_NVAL, OPT,
     O             ITEM_TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O             TERM, TERML, TERMCLS, NVAL)

C      WRITE(STDOUT,*) ' Return from GETVAL in GET_CODE_NC_F: NVAL=',NVAL
C      WRITE(STDOUT,97)
C97    FORMAT(1X,12X,'ITEM','   LEN  TYPE T  TCLS')
C      DO 9213 I=1,NVAL
C        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I),
C     A                  TERMCLS(I)
C99    FORMAT(' ',A16,' ',I5,' ',I5,' ',A1,' ',I5)
C9213  CONTINUE

C     Trim off the end of line item.
C      NVAL = NVAL - 1


C     Put the prescan manipulations here.

      IF(NVAL.GT.1) THEN
        CALL PRESCAN(STDOUT, MAX_NVAL, MODE,
     M                NVAL, CVAL, CLEN, ITEM_TYPE, TERM,
     M                TERML, TERMCLS, IVAL,
     O                EFLAG)

      ENDIF

C      WRITE(STDOUT,*) ' Return from PRESCAN: NVAL=',NVAL
C      WRITE(STDOUT,97)
C      DO 9214 I=1,NVAL
C        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I),
C     A                  TERMCLS(I)
C9214  CONTINUE

C     At this point we should have at least one item in the list.
C     The all integer or identifier items should appear first
C     followed in some cases by floating point numbers and 
C     once in a while there will be a continuation flag.  If a 
C     continuation flag is present it is the last item in the
C     list.   MODE will signal if the line we are to process 
C     is a continuation line.  The format of the continuation line
C     may depend on the CODE and the TYPE.  

      IF(EFLAG.NE.0) RETURN

C     Process a line of information.

      IF(NVAL.LE.0) THEN
        WRITE(STDOUT,50)
        EFLAG = 1
      ELSE
        IF(MODE.EQ.0) THEN
C         Transfer the code value.
          IF(ITEM_TYPE(1).EQ.INTVAL) THEN
            READ(CVAL(1),*) CODE
          ELSEIF(ITEM_TYPE(1).EQ.CHRVAL) THEN
C           We have an identifier first in the line.  Could
C           be a macro instruction or an instruction. 
            INSTRUCTION = CVAL(1)
            CALL LS_GLOBAL
     I                     (INSTRUCTION, 
     O                      CLASS, VALUE, INDX)
            IF(INDX.EQ.0) THEN
              WRITE(STDOUT,60) INSTRUCTION
              STOP 'Abnormal stop: errors found.'
            ELSE
              IF(CLASS.EQ.INSTRUCTION_CLASS) THEN
C               Not a macro instruction.  Return value 
C               as the CODE.
                WRITE(STDOUT,64) LONG_LINE(1:LENSTR(LONG_LINE))
                CODE = VALUE
              ELSEIF(CLASS.EQ.MACRO_CLASS) THEN
C               Macro instruction.  Go expand it.
                WRITE(STDOUT,62) LONG_LINE(1:LENSTR(LONG_LINE))
                CALL EXPAND_MACRO(STDOUT, VALUE, NVAL ,CVAL, CLEN,
     O                            EFLAG)
C               Return to process the next line of input.  This
C               line may come from the macro stack or it may come from
C               the user input file.  Signal macro expansion return
C               by setting CODE to 999
                CODE = 999              
                GOTO 120
              ELSEIF(CLASS.EQ.VARIABLE_ARGUMENTS_CLASS) THEN
C               Special case for sum of flows = 0.  The number
C               of nodes is a variable.  This instruction class
C               will have one or more arguments and the number
C               of arguments is inserted into the list.  Thus
C               the user need not supply the number of arguments.

                CODE = VALUE

C               Insert the number of arguments into the lists adjusting
C               only those items needed below. 

                WRITE(STDOUT,64) LONG_LINE(1:LENSTR(LONG_LINE))
                CALL INSERT_ARGUMENT_KNT(MAX_NVAL,
     M                               NVAL, CVAL, CLEN, ITEM_TYPE,
     M                               TERM, TERML, TERMCLS)
C      WRITE(STDOUT,*) ' Return from INSERT_ARG...: NVAL=',NVAL
C      WRITE(STDOUT,97)
C      DO 9215 I=1,NVAL
C        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I),
C     A                  TERMCLS(I)
C9215  CONTINUE
              ENDIF
            ENDIF
          ELSE
            WRITE(STDOUT,52) CVAL(1)
            EFLAG = 1
          ENDIF
C         Set the key values.
          ISTART = 2
          INIT_IKNT = 0
        ELSEIF(MODE.EQ.1) THEN
C         Continuation line for Code 5 Type 6.
          ISTART = 1
          INIT_IKNT = 4
        ENDIF
      ENDIF


C     Check to see if a continuation signal is present.
      IF(ITEM_TYPE(NVAL).EQ.CONTINUATION_VALUE) THEN
C       Continuation signal found.
        ILIMIT = 9
        NC(10) = '    1'
        NC_LONG(10) = '1'
        NVAL = NVAL - 1
      ELSE
C       No continuation signal present.
        ILIMIT = 10
      ENDIF



C     Now transfer integers or identifiers until NVAL is reached, or
C     a non-integer and non-identifier type is found.

      NON_INT_ID = 0
      IKNT = INIT_IKNT
      FKNT = 0
C      WRITE(STDOUT,*) ' ISTART=',ISTART,' NVAL=',NVAL
      DO 110 I=ISTART,NVAL
        IF(NON_INT_ID.EQ.0) THEN
C         Check for type
          IF(ITEM_TYPE(I).NE.INTVAL.AND.ITEM_TYPE(I).NE.CHRVAL.AND.
     A       ITEM_TYPE(I).NE.PLACE_HOLDER ) THEN
            NON_INT_ID = 1
          ELSE
            IKNT = IKNT + 1
            IF(IKNT.LE.ILIMIT) THEN
              IF(ITEM_TYPE(I).EQ.PLACE_HOLDER) THEN
                NC(IKNT) = ' '
                NC_LONG(IKNT) = ' '
              ELSE
                NC(IKNT) = ' '
                IT = CLEN(I)
                IF(IT.GT.5) THEN
                  IT = 5
                ENDIF
                NC(IKNT)(6-IT:5) = CVAL(I)
                NC_LONG(IKNT) = CVAL(I)
              ENDIF
            ELSE
              WRITE(STDOUT,54)
              EFLAG = 1
            ENDIF
            IF(TERMCLS(I).EQ.SEMICOLON) THEN
              NON_INT_ID = 1
C             This is the terminator for the last item in the set of
C             integer/identifier.  Thus skip to end of loop so that the
C             next item is processed as the first in the floating 
C             point values set. 
              GOTO 110
            ENDIF
          ENDIF
        ENDIF
        IF(NON_INT_ID.EQ.1) THEN
C         We expect type to be real or double precision or place holder or
C         the special identifier TAB or tab.
          IF(ITEM_TYPE(I).NE.REAVAL.AND.ITEM_TYPE(I).NE.DPRVAL.AND.
     A       ITEM_TYPE(I).NE.PLACE_HOLDER.AND.CVAL(I)(1:3).NE.'TAB'
     B       .AND.CVAL(I)(1:3).NE.'tab') THEN
            WRITE(STDOUT,56)
            EFLAG = 1
          ELSE
            FKNT = FKNT + 1
            IF(FKNT.LE.5) THEN
              IF(ITEM_TYPE(I).EQ.PLACE_HOLDER) THEN
                F(FKNT) = 0.0
                FC(FKNT) = ' '
              ELSEIF(CVAL(I)(1:3).EQ.'TAB'.or.
     a               CVAL(I)(1:3).EQ.'tab') THEN
                FC(FKNT) = 'LKUP'
                if(clen(i) > 3) then
c                 An increment to the eventual datum is present. 
                  read(cval(i)(4:clen(i)),*) f(fknt)
                else
                  F(FKNT) = 0.0
                endif
              ELSE
                READ(CVAL(I),*) F(FKNT)
                FC(FKNT) = ' '
              ENDIF
            ELSE
              WRITE(STDOUT,58)
              EFLAG = 1
            ENDIF
          ENDIF
        ENDIF
110   CONTINUE
120   CONTINUE
      RETURN
      END

C     ***********
C     *         *
C     * GET_ITEMS
C     *         *
C     ***********

      SUBROUTINE GET_ITEMS(STDOUT, LINE_IN, MAX_KNT,
     O                     ITEM_KNT, ITEMS, ITEM_LENGTH, 
     O                     ITEM_TYPE, TERM_CLASS, EFLAG)

C     Get a sequence of items from a line of user input. 
C     That is, break a line of input into its parts.  An item
C     can be: an identifier(by our definition), an integer,
C     a single precision floating point value, or a double precision
C     floating point value.

      IMPLICIT NONE
      INTEGER STDOUT, ITEM_KNT, MAX_KNT, EFLAG,
     A        ITEM_LENGTH(MAX_KNT), ITEM_TYPE(MAX_KNT),
     B        TERM_CLASS(MAX_KNT)

      CHARACTER ITEMS(MAX_KNT)*(*), LINE_IN*(*)

C     Local variables

      CHARACTER LINE*256

      INTEGER MAX_NVAL

      PARAMETER (MAX_NVAL=20)

      INTEGER  OPT, I, IT, NVAL
      
      INTEGER CLEN(MAX_NVAL), IVAL(MAX_NVAL), ITYPE(MAX_NVAL),
     A        TERML(MAX_NVAL), TERMCLS(MAX_NVAL)
      REAL RVAL(MAX_NVAL)
      REAL*8 DPVAL(MAX_NVAL)
      CHARACTER CVAL(MAX_NVAL)*256, TERM(MAX_NVAL)*1

      INTEGER LENSTR
      EXTERNAL GETVAL, LENSTR

      INTRINSIC INDEX
C     *********************************FORMATS**************************
50    FORMAT(/,' *ERR:298* Found ',I3,' items when no more than ',I3,
     A       ' were expected.'/)
C***********************************************************************

      LINE = LINE_IN
      I = INDEX(LINE,'''')
      IF(I.EQ.0) THEN
        IT = LENSTR(LINE)
        LINE(IT+1:IT+1) = ''''
      ELSE
C       Revise user quote to  ,quote
C        LINE(I:I+2) = ' ,'''
      ENDIF

C     Select the option to return what is found with no
C     expectations being enforced.
      OPT = 1
      CALL GETVAL(STDOUT, LINE, MAX_NVAL, OPT,
     O            ITYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O             TERM, TERML, TERMCLS, NVAL)
C      WRITE(STDOUT,*) ' Return from GETVAL in GET_ITEMS: NVAL=',NVAL
C      DO 9213 I=1,NVAL
C        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I)
C99    FORMAT(' ',A12,' ',I5,' ',I5,' ',A1)
C9213  CONTINUE

C     Transfer to arguments.  Trim off last item since it is the 
C     special end of line item.
C      IF(NVAL-1.GT.MAX_KNT) THEN
      IF(NVAL.GT.MAX_KNT) THEN
        WRITE(STDOUT,50) NVAL, MAX_KNT
        EFLAG = 1
        NVAL = MAX_KNT
      ENDIF
C      ITEM_KNT = NVAL - 1
      ITEM_KNT = NVAL 
C      DO 100 I=1,NVAL-1
      DO 100 I=1,NVAL
        ITEMS(I) = CVAL(I)
        ITEM_LENGTH(I) = CLEN(I)
        ITEM_TYPE(I) = ITYPE(I)
        TERM_CLASS(I) = TERMCLS(I)
100   CONTINUE
      RETURN
      END
