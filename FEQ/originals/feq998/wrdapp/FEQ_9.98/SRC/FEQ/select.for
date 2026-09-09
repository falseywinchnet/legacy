C
C
C
      SUBROUTINE FORCE_SLASHES(
     M                       NAME)

C     Force all backslashes to be slashes: Linux rules!
      IMPLICIT NONE
      CHARACTER*(*) NAME

C     Local 
      INTEGER I, N
C***********************************************************************
      N = LEN_TRIM(NAME)
      DO 100 I=1,N
        IF(NAME(I:I).EQ.'\') THEN
          NAME(I:I) = '/'
        ENDIF
100   CONTINUE
      RETURN
      END

C
C
C
      SUBROUTINE TO_LOWER(
     M            STRING)
C
C     Convert all uppercase alpha characters to lower case
C     Modified from  a USGS routine.
      CHARACTER*(*) STRING

C     + + + ARGUMENT DEFINITIONS + + +
C     STRING - character string to be made lower case

C     + + + LOCAL VARIABLES + + +
      INTEGER   I, ICH, IEND

C     + + + INTRINSICS + + +
      INTRINSIC  ICHAR, LEN_TRIM, CHAR
C***********************************************************************
      IEND = LEN_TRIM(STRING)
      DO 10 I = 1, IEND
        ICH = ICHAR(STRING(I:I))
        IF(ICH.GE.65 .AND. ICH.LE.90) THEN
C         Character is lower case.
          STRING(I:I)= CHAR(ICH+32)
        ENDIF
 10   CONTINUE

      RETURN
      END
C     Contains routines used in processing selectors used to 
C     extract those parts of a master input file to use in 
C     a given run.


      SUBROUTINE SELECTOR_SYMBOL_INIT()

C     Initialize the selector-symbol table facility. 

      IMPLICIT NONE

      INCLUDE 'selector.cmn'

C***********************************************************************
      LAST_SYMBOL = 0
      RETURN
      END



C     ***********
C     *         *
C     * LSA_SELECT
C     *         *
C     ***********

      SUBROUTINE   LSA_SELECTOR
     I                         (STDOUT, KEY, 
     M                         CLASS, VALUE, 
     O                         INDEX, FLAG)
 
C     + + + PURPOSE + + +
C     Do a linear search for KEY in the entries in the selector
C     symbol table and add to the table if KEY is not found.
C     Otherwise, return the index to KEY and the value of
C     CLASS and VALUE found for the symbol in KEY. 
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER FLAG, INDEX, STDOUT, CLASS, VALUE
      CHARACTER KEY*16
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT - standard output unit for user messages
C     KEY    - search value
C     CLASS  - Class code for the symbol.
C     VALUE  - numeric value for the symbol.
C     INDEX  - index into the table at the match point
C     FLAG  -  0: KEY not in the table; 1: Key in the table;
C              2: error encountered.

      INCLUDE 'selector.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *ERR:414* Too many entries in selector-symbol table.',
     A         ' Number=',I5)
C***********************************************************************
      DO 100 I=1,LAST_SYMBOL
        IF(KEY.EQ.SYMBOL(I)) THEN
C         FOUND MATCH
          INDEX = I
          CLASS = SYMBOL_CLASS(I)
          VALUE = SYMBOL_VALUE(I)
          FLAG = 1
          RETURN
        ENDIF
 100  CONTINUE
C     MATCH NOT FOUND
      LAST_SYMBOL = LAST_SYMBOL + 1

      IF(LAST_SYMBOL.GT.MAX_SYMBOL) THEN
        WRITE(STDOUT,50) LAST_SYMBOL
        FLAG = 2
        LAST_SYMBOL = MAX_SYMBOL
      ENDIF
      FLAG = 0
      SYMBOL(LAST_SYMBOL) = KEY
      SYMBOL_CLASS(LAST_SYMBOL) = CLASS
      SYMBOL_VALUE(LAST_SYMBOL) = VALUE
      INDEX = LAST_SYMBOL
      RETURN
      END
C     ***********
C     *         *
C     * LS_SELECT
C     *         *
C     ***********

      SUBROUTINE   LS_SELECTOR
     I                        (KEY, 
     O                         CLASS, VALUE, INDEX)
 
C     + + + PURPOSE + + +
C     Do a linear search for KEY in the entries in the selector
C     symbol table and return its class, value, and index
C     if it is found.  Otherwise return a zero value for
C     index.  
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER INDEX, CLASS, VALUE
      CHARACTER KEY*16
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     KEY    - search value
C     CLASS  - Class code for the symbol.
C     VALUE  - numeric value for the symbol.
C     INDEX  - index into the table at the match point

      INCLUDE 'selector.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I
 
C***********************************************************************
      DO 100 I=1,LAST_SYMBOL
        IF(KEY.EQ.SYMBOL(I)) THEN
C         Found match
          INDEX = I
          CLASS = SYMBOL_CLASS(I)
          VALUE = SYMBOL_VALUE(I)
          RETURN
        ENDIF
 100  CONTINUE
C     Match not found.
      INDEX = 0
      RETURN
      END

C
C
C
      SUBROUTINE MAKE_SB_HOME_NAME(STDOUT,
     M                             SB_HOME)

C     Make a home name from the true values in the selector table. 

      IMPLICIT NONE
      INTEGER STDOUT
      CHARACTER*(*) SB_HOME

      INCLUDE 'selector.cmn'

C     Local
      INTEGER I, J, K, TRUE

      CHARACTER WORK*128

      DATA TRUE/1/ 
C     **************************FORMATS*********************************
50    FORMAT
     A(/,' *WRN:60* No selector variable was true.  It is then easy to',
     B/,5X,'create a scenario directory that matches the current',
     C/,5X,'working directory.  If that is done FEQ cannot detect',
     D/,5X,'equality of the file names for the primary and secondary',
     E/,5X,'master-input files.  Make sure that the scenario home',
     F/,5X,'directory that you are creating is not the same as any',
     G/,5X,'directory from which you will be invoking FEQ using the',
     H/,5X,'primary master-input file as its first command-line',
     I/,5X,'argument.  Otherwise it is possible to destroy your primary',
     J/,5X,'master-input file.  That is not good but Fortran has no',
     K/,5X,'portable means for reporting the name of the current',
     L/,5X,'working directory so that FEQ can check for that outcome.')
C************************************************************************
C     Method:  Scan through the selector table and extract the keys 
C     that are true.  These are then appended in the order found
C     to the existing string in SB_HOME.  We use an underscore
C     character as the delimiter between adjacent keys.  It is the 
C     user's responsibility to present the keys in the proper order
C     and of the proper number and length so that the result is
C     the desired one!

C     Initialize the character pointers. J points to the last 
C     character inserted into work.  
      J = 0

      WORK = '/'
      J = J + 1
      DO 100 I=1,LAST_SYMBOL
        IF(SYMBOL_VALUE(I).EQ.TRUE) THEN
C         We have a hit!
          K = LEN_TRIM(SYMBOL(I))
          WORK(J+1:J+K) = SYMBOL(I)(1:K)
          J = J + K
          WORK(J+1:J+1) = '_'
          J = J + 1
        ENDIF
100   CONTINUE

C     We have added one too many underscores.  Trim off the trailing
C     underscore and add to the end of SB_HOME.  Note: SB_HOME should
C     not be blank nor empty.  Otherwise an error has occurred 
C     earlier. 
      IF(J.GT.0) THEN
        J = J - 1
        K = LEN_TRIM(SB_HOME)
        SB_HOME = SB_HOME(1:K)//WORK(1:J)
      ENDIF

C     If J is 0 then no selector value was true.  It is then possible to 
C     create a home name that matches the current working directory.  It is
C     then possible that the secondary master-file name is the same as the 
C     primary master-file name and we will not be able to tell.  Fortran has
C     no portable means for getting us the current working directory!

      IF(J.EQ.0) THEN
        WRITE(STDOUT,50)
      ENDIF
      RETURN
      END



C
C
C
      SUBROUTINE GET_SELECTORS(STDIN, STDOUT,
     O                         FILE_NAME, SB_HOME) 

C     Get the selector values from the Set-selectors block. 

      IMPLICIT NONE

      INTEGER STDIN, STDOUT

      CHARACTER FILE_NAME*128, SB_HOME*64

C     Local 

      INTEGER IT, NXT, VALUE, CLASS, FORCE_LC 

      CHARACTER LINE*196, RESULT*128, KEY*16

C     ****************************Formats*******************************
50    FORMAT(/,' *ERR:415* No = found after a selector name.') 
52    FORMAT(/,' *ERR:416* Selector name=',A,' has more than 16',
     A ' characters.')
54    FORMAT(/,' *ERR:417* No selector name found.')
56    FORMAT(/,' *ERR:418* No selector value found.')
58    FORMAT(/,' *ERR:419* ' A,' is an invalid selector value.  ',
     A  'Must be TRUE, true, FALSE, or false.')
60    FORMAT(/,' Home directory for output files is: ',A)
C***********************************************************************
C     Set the default file name should the user not give one. Note:
C     the leading blank IS important.  Operating system will ignore
C     leading blanks in file names and we need the space to possibly 
C     insert a slash later.  If this default name is changed be
C     sure to chaNge the test for the default name about 30 lines
C     below!
      FILE_NAME = ' f_e_q_i_n_temp.default'
C     Set the default select-block home name to blank
      SB_HOME = ' '
C     Clear the lower-case flag
      FORCE_LC = 0
100   CONTINUE
        CALL  INL196
     I             (STDIN, STDOUT,
     O              LINE)
        IT = LEN_TRIM(LINE)
        WRITE(STDOUT,'(A)') LINE(1:IT)

        IF(LINE(1:5).EQ.'END S') THEN
C         Check for making a home name.  
          IF(SB_HOME.NE.' ') THEN
C           Make a home name. 
            CALL MAKE_SB_HOME_NAME(STDOUT,
     M                             SB_HOME)
            IF(FORCE_LC.EQ.1) THEN
              CALL TO_LOWER(
     M                      SB_HOME)
            ENDIF
            WRITE(STDOUT,60) SB_HOME 
C           Adjust default file name if it still applies.  Note:
C           the code that gets the user-given file name does not
C           leave any leading blanks.  Thus we can tell if the 
C           default name has been changed.
            IF(FILE_NAME.EQ.' f_') THEN
C             Default still applies and we have a home directory 
C             given.  Add prefix of slash
              FILE_NAME(1:1) = '/'
            ENDIF      
          ENDIF
                
          
          RETURN
        ENDIF

        NXT = INDEX(LINE, '=')
        IF(NXT.EQ.0) THEN
          WRITE(STDOUT,50) 
          STOP 'Abnormal stop. Error(s) found.'
        ENDIF
        NXT = NXT - 1
C       Extract the selector name
        RESULT = LINE(1:NXT)
        CALL STRIP_L_BLANKS(
     M                      RESULT)
        IT = LEN_TRIM(RESULT)
        IF(IT.GT.16) THEN
          WRITE(STDOUT,52) RESULT(1:IT)
          STOP 'Abnormal stop. Error(s) found.'
        ELSEIF(IT.EQ.0) THEN
          WRITE(STDOUT,54)
          STOP 'Abnormal stop. Error(s) found.'
        ENDIF

        KEY = RESULT(1:IT)

C       Look for the selector value.  Move beyond the equal sign in line.
        NXT = NXT + 2
        CALL NXTTOK
     I             (LINE,
     M              NXT,
     O              RESULT)
        IF(NXT.EQ.0) THEN
          WRITE(STDOUT,56)
          STOP 'Abnormal stop. Error(s) found.'
        ENDIF
        IF(KEY.EQ.'FILE') THEN
          FILE_NAME = RESULT
        ELSEIF(KEY.EQ.'MAKEHOMENAME') THEN
          SB_HOME = RESULT
          FORCE_LC = 0
        ELSEIF(KEY.EQ.'makehomename') THEN
          SB_HOME = RESULT
          FORCE_LC = 1
        ELSE
          IT = LEN_TRIM(RESULT)
          IF(RESULT(1:4).EQ.'TRUE'.OR.RESULT(1:4).EQ.'true') THEN
            VALUE = 1
          ELSEIF(RESULT(1:5).EQ.'FALSE'.OR.RESULT(1:5).EQ.'false') THEN
            VALUE = 0
          ELSE
            WRITE(STDOUT,58) RESULT(1:IT)
            STOP 'Abnormal stop. Error(s) found.'
          ENDIF

C         The value of class is not used but is retained for possible future use. 

          CLASS = 1024

          CALL LSA_SELECTOR
     I                     (STDOUT, KEY, 
     M                      CLASS, VALUE, 
     O                      NXT, IT)
        ENDIF
        GOTO 100
      
      END  
        
C
C
C
      SUBROUTINE PUSH_TOKEN(TOKEN, STATE, LEVEL,
     O                      PNT)

C     Put token set on the token stack

      IMPLICIT NONE
      INTEGER TOKEN, STATE, LEVEL, PNT

      INCLUDE 'selectstack.cmn'

C***********************************************************************
      TOP = TOP + 1
      IF(TOP.GT.MAX_TOP) THEN
        PNT = -1
      ELSE
        SELECT_STACK(1,TOP) = TOKEN
        SELECT_STACK(2,TOP) = STATE
        SELECT_STACK(3,TOP) = LEVEL
        PNT = TOP
      ENDIF
      RETURN
      END
C
C
C
      SUBROUTINE POP_TOKEN(
     O                     TOKEN, STATE, LEVEL, PNT)

C     Get last token set from stack and drop top of stack.

      IMPLICIT NONE
      INTEGER TOKEN, STATE, LEVEL, PNT

      INCLUDE 'selectstack.cmn'

C***********************************************************************
      IF(TOP.EQ.0) THEN
        PNT = -1
      ELSE
        TOKEN = SELECT_STACK(1,TOP)
        STATE = SELECT_STACK(2,TOP)
        LEVEL = SELECT_STACK(3,TOP)
   
        TOP = TOP - 1
        PNT = TOP
      ENDIF
      RETURN
      END
C
C
C

      SUBROUTINE GET_TOP_OF_STACK(
     O                     TOKEN, STATE, LEVEL, PNT)

C     Get last token set from stack

      IMPLICIT NONE
      INTEGER TOKEN, STATE, LEVEL, PNT

      INCLUDE 'selectstack.cmn'

C***********************************************************************
      IF(TOP.EQ.0) THEN
        PNT = -1
      ELSE
        TOKEN = SELECT_STACK(1,TOP)
        STATE = SELECT_STACK(2,TOP)
        LEVEL = SELECT_STACK(3,TOP)
        PNT = TOP
      ENDIF
      RETURN
      END

C
C
C
      SUBROUTINE CLEAR_SELECT_STACK()

C     Clear the selection-block processing stack

      INCLUDE 'selectstack.cmn'
C*******************************************************************************
      TOP = 0
      RETURN
      END
      
C
C
C
      SUBROUTINE CLASSIFY_LINE(STDOUT, LINE,
     M                         OLD_LEVEL, OLD_TOKEN,
     O                         TOKEN, STATE, TOKEN_LEVEL)

C     Given a line, seek selection keywords, define the token values, 
C     determine the value for the STATE of the keyword if it has one,
C     and adjust the level as required.  If the keywork has no STATE
C     return STATE as true. 

      IMPLICIT NONE
      INTEGER OLD_LEVEL, TOKEN_LEVEL, STATE, TOKEN, STDOUT, OLD_TOKEN

      CHARACTER*196 LINE

C     Local

      INTEGER CLASS, INDX, IT,  NXT, TRUE, FALSE, SELECTOR_VALUE,
     A        NOT, DELTA_LEVEL(0:4,0:4), I, J, DLEV

      CHARACTER RESULT*64, WORK*196, SELECTOR*16, NOT_SYMBOL*1


      INTEGER NONE_TOKEN, IF_TOKEN, ELSE_TOKEN, ELSEIF_TOKEN,
     A  ENDIF_TOKEN, ENDFILE_TOKEN
      PARAMETER (NONE_TOKEN=0, IF_TOKEN=1,  ELSE_TOKEN=2, 
     A           ELSEIF_TOKEN=3, ENDIF_TOKEN=4, ENDFILE_TOKEN=5)
      DATA TRUE/1/, FALSE/0/, NOT_SYMBOL/'~'/
      DATA ((DELTA_LEVEL(I,J),J=0,4),I=0,4)/
     A 0, 0,-1,-1,-1,
     B 1, 1, 0, 0, 0,
     C 1, 1, 0, 0, 0,
     D 1, 1, 0, 0, 0,
     E 0, 0,-1,-1,-1/
      
C     **********************Formats*************************************
50    FORMAT(/,' *ERR:420* Selector name=',A,' has unknown value.')
C*******************************************************************************
      WORK = LINE
      NXT = 1
      CALL STRIP_L_BLANKS(
     M                    WORK)

      CALL NXTTOK
     I           (WORK,
     M            NXT,
     O            RESULT)
      IF(NXT.EQ.0) THEN
C       Line was blank
        TOKEN = NONE_TOKEN 
        STATE = TRUE
      ELSEIF(RESULT(1:3).EQ.'IF ') THEN
C       Found the if statement
        TOKEN = IF_TOKEN
C       Seek the selector 
        CALL NXTTOK
     I             (WORK,
     M              NXT,
     O              RESULT)
        IF(RESULT(1:1).EQ.NOT_SYMBOL) THEN
          NOT = TRUE
          SELECTOR = RESULT(2:17)
        ELSE
          NOT = FALSE
          SELECTOR = RESULT(1:16)
        ENDIF
        CALL  LS_SELECTOR
     I                   (SELECTOR, 
     O                    CLASS, SELECTOR_VALUE, INDX)
        
        IF(INDX.EQ.0) THEN
          IT = LEN_TRIM(SELECTOR)
          WRITE(STDOUT,50) SELECTOR(1:IT)
          STOP 'Abnormal stop. Error(s) found.'
        ENDIF
        IF(NOT.EQ.TRUE) THEN
          IF(SELECTOR_VALUE.EQ.TRUE) THEN
            SELECTOR_VALUE = FALSE
          ELSE
            SELECTOR_VALUE = TRUE
          ENDIF
        ENDIF
        STATE = SELECTOR_VALUE
      ELSEIF(RESULT(1:6).EQ.'ELSEIF') THEN
C       Found the elseif statement
        TOKEN = ELSEIF_TOKEN
C       Seek the selector 
        CALL NXTTOK
     I             (WORK,
     M              NXT,
     O              RESULT)
        IF(RESULT(1:1).EQ.NOT_SYMBOL) THEN
          NOT = TRUE
          SELECTOR = RESULT(2:17)
        ELSE
          NOT = FALSE
          SELECTOR = RESULT(1:16)
        ENDIF
        CALL  LS_SELECTOR
     I                   (SELECTOR, 
     O                    CLASS, SELECTOR_VALUE, INDX)
        
        IF(INDX.EQ.0) THEN
          IT = LEN_TRIM(SELECTOR)
          WRITE(STDOUT,50) SELECTOR(1:IT)
          STOP 'Abnormal stop. Error(s) found.'
        ENDIF
        IF(NOT.EQ.TRUE) THEN
          IF(SELECTOR_VALUE.EQ.TRUE) THEN
            SELECTOR_VALUE = FALSE
          ELSE
            SELECTOR_VALUE = TRUE
          ENDIF
        ENDIF
        STATE = SELECTOR_VALUE
      ELSEIF(RESULT(1:4).EQ.'ELSE') THEN
C       Found the else statement
        TOKEN = ELSE_TOKEN
C       Set state here but value will be replaced by calling unit.
        STATE = TRUE
      ELSEIF(RESULT(1:5).EQ.'ENDIF') THEN
C       Found the endif statement
        TOKEN = ENDIF_TOKEN
C       Set state here but value will be replaced by calling unit.
        STATE = TRUE
      ELSEIF(RESULT(1:7).EQ.'ENDFILE') THEN
C       Found the endfile statement
        TOKEN = ENDFILE_TOKEN
C       Set state here but value will be replaced by calling unit.
        STATE = TRUE
      ELSE
        TOKEN = NONE_TOKEN
        STATE = TRUE
      ENDIF

C     Set the level and adjust OLD_TOKEN
      IF(TOKEN.EQ.ENDFILE_TOKEN) THEN
        TOKEN_LEVEL = OLD_LEVEL
      ELSE
C       Define the change in level 
        DLEV = DELTA_LEVEL(OLD_TOKEN,TOKEN)
C        WRITE(STDOUT,*) ' '
C        WRITE(STDOUT,*) ' OLD_TOKEN=',OLD_TOKEN,' TOKEN=',TOKEN
C        WRITE(STDOUT,*) ' LEVEL_CHANGE=',DLEV,' NEW_LEVEL=',TOKEN_LEVEL
C        WRITE(STDOUT,'(A)') LINE
        TOKEN_LEVEL = OLD_LEVEL + DLEV
        OLD_LEVEL = TOKEN_LEVEL
      ENDIF

      OLD_TOKEN = TOKEN
          
      RETURN
      END
C
C
C     
      SUBROUTINE DISCARD_LINES(STDIN, STDOUT, TARGET_LEVEL,
     M                         OLD_LEVEL, OLD_TOKEN,
     O                         TOKEN, STATE, TOKEN_LEVEL)

C     Read and discard lines until the level of a keyword matches
C     the target level.  Return the keyword description.

      IMPLICIT NONE

      INTEGER STDIN, STDOUT, TARGET_LEVEL, OLD_LEVEL, TOKEN, STATE, 
     A        TOKEN_LEVEL, OLD_TOKEN

C     Local

      CHARACTER LINE*196
C     **************************Formats*********************************
50    FORMAT(/,' *ERR:421* End of master-input file reached when not',
     A' expected.  Possible missing ENDIF statement.')      
C*******************************************************************************
C      WRITE(STDOUT,*) 'Entering Discard lines'
100   CONTINUE
        CALL  INL196_ALL
     I                  (STDIN,
     O                   LINE)
        IF(LINE(1:7).EQ.'ENDFILE') THEN
          WRITE(STDOUT,50)
          STOP 'Abnormal stop.  Error(s) found.'
        ENDIF

        CALL CLASSIFY_LINE(STDOUT, LINE,
     M                     OLD_LEVEL, OLD_TOKEN,
     O                     TOKEN, STATE, TOKEN_LEVEL)

        IF(TOKEN_LEVEL.EQ.TARGET_LEVEL) THEN
C      WRITE(STDOUT,*) 'Leaving Discard lines'

          RETURN
        ENDIF
        GOTO 100
      END

C
C
C     
      SUBROUTINE DISCARD_LINES_TO_ENDIF(STDIN, STDOUT, TARGET_LEVEL,
     M                         OLD_LEVEL, OLD_TOKEN,
     O                         TOKEN, STATE, TOKEN_LEVEL)

C     Read and discard lines until an ENDIF token is found at the 
C     the target level.  Return the keyword description.

      IMPLICIT NONE

      INTEGER STDIN, STDOUT, TARGET_LEVEL, OLD_LEVEL, TOKEN, STATE, 
     A        TOKEN_LEVEL, OLD_TOKEN

C     Local
      INTEGER  ENDIF_TOKEN
      PARAMETER (ENDIF_TOKEN=4)

      CHARACTER LINE*196
C     **************************Formats*********************************
50    FORMAT(/,' *ERR:421* End of master-input file reached when not',
     A' expected.  Possible missing ENDIF statement.')      
C*******************************************************************************
C      WRITE(STDOUT,*) 'Entering Discard lines to endif'

100   CONTINUE
        CALL  INL196_ALL
     I                  (STDIN,
     O                   LINE)
        IF(LINE(1:7).EQ.'ENDFILE') THEN
          WRITE(STDOUT,50)
          STOP 'Abnormal stop.  Error(s) found.'
        ENDIF

        CALL CLASSIFY_LINE(STDOUT, LINE,
     M                     OLD_LEVEL, OLD_TOKEN,
     O                     TOKEN, STATE, TOKEN_LEVEL)

        IF(TOKEN_LEVEL.EQ.TARGET_LEVEL.AND.
     A         TOKEN.EQ.ENDIF_TOKEN) THEN
C      WRITE(STDOUT,*) 'Leaving Discard lines to endif'

          RETURN
        ENDIF
        GOTO 100
      END
C
C
C
      SUBROUTINE SCAN_MASTER_INPUT(STDIN, STDOUT, FILE_NAME, SB_HOME,
     I                             FNAME1,
     O                             EFLAG)

C     Scan the master input file and select the input to use. 

      IMPLICIT NONE

      INTEGER STDIN, STDOUT, EFLAG

      CHARACTER FILE_NAME*128, SB_HOME*64, FNAME1*64


C     Called program units
      INTEGER GET_UNIT
      EXTERNAL GET_UNIT

C     Local

      INTEGER STDTMP, IT, TRUE, FALSE,
     A        STACK_TOKEN, STACK_STATE, STACK_LEVEL, 
     B        INHAND_TOKEN, INHAND_STATE, INHAND_LEVEL,
     C        TOP_PNT, INHAND, OLD_LEVEL, ACT, I, J,
     D        IOFLAG, OLD_TOKEN, DISCARD_TOKEN, DISCARD_LEVEL,
     E        DISCARD_STATE


      CHARACTER LINE*196, WORK*196

      INTEGER NONE_TOKEN, IF_TOKEN, ELSE_TOKEN, ELSEIF_TOKEN,
     A  ENDIF_TOKEN, ENDFILE_TOKEN
      PARAMETER (NONE_TOKEN=0, IF_TOKEN=1,  ELSE_TOKEN=2, 
     A           ELSEIF_TOKEN=3, ENDIF_TOKEN=4, ENDFILE_TOKEN=5)
      DATA TRUE/1/, FALSE/0/


C     Outline of process:

C       We read lines from STDIN and check each line for a keyword,
C       IF, ELSE, ELSEIF, ENDIF, or ENDFILE.  Each occurrence of a keyword
C       is assigned a level.  The level starts at 0.  When an IF is found,
C       it is given the current level and then the current level is incremented.
C       When a ENDIF is found the current level is decremented and the 
C       value is then given to the ENDIF.  An ELSE or an ELSEIF gets
C       current level less 1.   Each keyword gets a token values, 
C       that is, a numeric code that we assign for our convenience.

C       We maintain a pushdown stack, or just a stack, that is a last-in
C       first-out structure.  We can put sets of values on this stack and
C       we can pop off the top of the stack.  We also maintain a pointer that
C       points to the top of the stack. 

C       A line that does not contain a keyword is given a token as 
C       well and has values just like a line with a keyword.  These values
C       are carefully chosen so that the algorithm will work.  The token
C       is the NONE_TOKEN for a line not containing a keyword. 

C       We keep track of the the current truth STATE of each token. 
C       It can be true or false.  In some cases the value we assign is
C       for our convenience, e. g. for a line not containing a keyword
C       as well as the ENDFILE line.  Otherwise the truth state is 
C       based on the context.  Thus we keep track of three values: 
C       TOKEN, STATE, and LEVEL.  We do this for two sets of values:
C       1. the top-of-stack, and 2. the in-hand.  The in-hand values
C       are the ones we get as we process the information.  

C       It is then possible using the current top-of-stack set and the 
C       current in-hand set, to define a set of actions that depends on these
C       two sets of values.  It is then possible to process any valid nested 
C       set of keywords to select those parts of the input from the master input
C       file that we will retain for processing with FEQ. 

C       We initialize the top of stack to the NONE_TOKEN, STATE:false, and level 0.
C       At some points the next line that we need has already been processed in the 
C       actions.  At other times we must read a new line to get the in-hand information. 
C       Thuse we must set a control value for reading a new line: INHAND.  INHAND
C       must start out as false. 

C       Here is the contents of the action matrix:

C  Token on                        Token in 
C  Stack                           Hand
C ----------  -------------------------------------------------------------------------------------------
C     -       NONE           IF             ELSE*          ELSEIF*        ENDIF*         ENDFILE
C     -      |--------------|--------------|--------------|--------------|--------------|---------------|
C NONE       |Transfer line |Put on stack  |Error         |Error         |Error         |Close workfile.|
C            |              |              |    5         |   8          |              |Close master   |
C            |              |     3        |              |              |     11       | file.     13  |
C            |     1        |              |              |              |              |Open workfile  |
C            |              |              |              |              |              | as input file.|
C            ____________________________________________________________________________________________
C            |top stack:F   |top stack:F   |Pop stack. If |Pop stack. If |Pop stack.    |Error.         |
C IF         | Discard lines| Discard lines|T,dscrd lns to|T,dscrd lns to|              |               |
C            | until level  | until level  |ENDIF@crrntlvl|ENDIF@crrntlvl|    12        |       14      |
C            | matches stck | mtchs stcklvl|If F,psh ELSE |If F,psh      |              |               |
C            | level        |else          |as T          |ELSEIF        |              |               |
C            |else      2   | Put on stck  |          .   |              |              |               |
C            | transfer line|     4        |      6       |        9     |              |               |
C            ____________________________________________________________________________________________
C ELSE       |Same as above |Same as above |Error         |Error         |Pop stack.    |Error.         |
C            |              |     4        |     7        |       10     |    12        |       15      |
C            |     2        |              |              |              |              |               |
C            ____________________________________________________________________________________________
C ELSEIF     |Same as above |Same as above |Same as for IF|Same as for IF|Pop stack.    |Error          |
C            |     2        |      4       |     6        |     9        |    12        |        16     |
C            ____________________________________________________________________________________________
C            * Levels for these tokens should match the level for the token on the top of stack.

      INTEGER ACTION(0:3,0:5)
      
      DATA ((ACTION(I,J),J=0,5),I=0,3)/
     A               1, 3, 5, 8,11,13,
     B               2, 4, 6, 9,12,14,
     C               2, 4, 7,10,12,15,
     D               2, 4, 6, 9,12,16/


C     *****************************Formats******************************
50    FORMAT(/,' *ERR:420* Selector name=',A,' has unknown value.')
52    FORMAT(/,' *ERR:422* Found misplaced IF or ELSE in a selection',
     A' block.')
54    FORMAT(/,' *ERR:423* The following file could not be opened:',
     A       /,5X, A,/,' Make sure the pathname exists and that you',
     B       ' have permission to write to the file.')
56    FORMAT(/,' *WRN:59* The selector-block home directory is:',
     A       /,5X,A,/,' and the file name: ',A,
     B       /,' does not have a leading slash.  A slash has been',
     C         ' added.')
58    FORMAT(/,' *BUG* STACK_TOKEN=',I5,' invalid on stack!')
60    FORMAT(/,' *ERR:433* Secondary master-input file name=',/,
     A  5X,A,/,' is same as primary master-input filename=',/,
     B  5X,A)
505   FORMAT
     A(/,' *ERR:424* ELSE found but no matching IF/ELSEIF exists.')
506   FORMAT(/,' *ERR:425* Possible missing ENDIF.')
507   FORMAT(/,' *ERR:426* ELSE found after an ELSE.')
508   FORMAT
     A (/,' *ERR:427* ELSEIF found but no matching IF/ELSEIF exists.')
510   FORMAT(/,' *ERR:428* ELSEIF found after matching ELSE.')
511   FORMAT
     A(/,' *ERR:429* ENDIF found with no matching IF, ELSE, or ENDIF.')
514   FORMAT(/,' *ERR:430* At end of master-input file and no ENDIF',
     A' for IF found.')
515   FORMAT(/,' *ERR:431* At end of master-input file and no ENDIF',
     A' for ELSE found.')
516   FORMAT(/,' *ERR:432* At end of master-input file and no ENDIF',
     A' for ELSEIF found.')
C***********************************************************************
C     Open a file for holding the new input sequence. 

      STDTMP = GET_UNIT(0)

      IF(SB_HOME.NE.' ') THEN
        WORK = SB_HOME
        IT = LEN_TRIM(WORK)
        IF(FILE_NAME(1:1).NE.'/') THEN
          WRITE(STDOUT,56) SB_HOME, FILE_NAME
          WORK = WORK(1:IT)//'/'//FILE_NAME
        ELSE
          WORK = WORK(1:IT)//FILE_NAME
        ENDIF
        FILE_NAME = WORK
      ENDIF

C     Try to prevent a disaster-overwriting the primary master-input file!
C     We assume that the user will be running FEQ in the directory that 
C     contains this file.  Thus if the selector-block home name is 
C     non-blank the fully qualified name will disagree with the value
C     of the command-line argument giving an unqualified primary master-input
C     file name.  This is not fool-proof but it should prevent most 
C     accidents.  The means used to construct the scenario directory names
C     should essentially prevent a disaster. 


      IF(FILE_NAME.EQ.FNAME1) THEN
C       Will write over the primary master-input file!
        WRITE(STDOUT,60) FILE_NAME, FNAME1
        STOP 'Abnormal stop. Error(s) found.'
      ENDIF        
      OPEN(UNIT=STDTMP, FILE=FILE_NAME, STATUS='UNKNOWN',IOSTAT=IOFLAG)
      IF(IOFLAG.NE.0) THEN
        IT = LEN_TRIM(FILE_NAME)
        WRITE(STDOUT,54) FILE_NAME(1:IT)
C        WRITE(STDOUT,*) ' IOFLAG=',IOFLAG
        STOP 'Abnormal stop. Error(s) found.'
      ENDIF

C     Initialize the selection-processing values
      OLD_LEVEL = 0
      OLD_TOKEN = NONE_TOKEN
      CALL CLEAR_SELECT_STACK()

      INHAND_TOKEN = NONE_TOKEN
      INHAND_STATE = TRUE
      INHAND_LEVEL = OLD_LEVEL
      CALL PUSH_TOKEN(INHAND_TOKEN, INHAND_STATE, INHAND_LEVEL,
     O                      TOP_PNT)

C     Enable reading input lines to start the process. We have nothing
C     in hand!
      INHAND = FALSE

C     Read the STDIN transfering to STDTMP and search for IF statements and END
C     statements. 


9000  CONTINUE
        
        IF(INHAND.EQ.FALSE) THEN
C         Get next line from master input file and define the 
C         inhand values.
          CALL  INL196_ALL
     I                    (STDIN,
     O                     LINE)

          CALL CLASSIFY_LINE(STDOUT, LINE,
     M                       OLD_LEVEL, OLD_TOKEN,
     O                       INHAND_TOKEN, INHAND_STATE, INHAND_LEVEL)
        ENDIF

C       Get the top of stack values. This does not pop the stack!
        CALL GET_TOP_OF_STACK(
     O       STACK_TOKEN, STACK_STATE, STACK_LEVEL, TOP_PNT)
       
C        WRITE(STDOUT,*) ' STACK_TOKEN=',STACK_TOKEN,
C     A                  ' INHAND_TOKEN=',INHAND_TOKEN
        IF(STACK_TOKEN.GT.3) THEN
          WRITE(STDOUT,58) STACK_TOKEN
          STOP 'Abnormal stop.  Bug found.'
        ENDIF
        ACT = ACTION(STACK_TOKEN,INHAND_TOKEN)
        GOTO(100, 200, 300, 400, 500, 600, 700, 800, 900, 1000,
     A       1100, 1200, 1300, 1400, 1500, 1600),ACT 

          WRITE(STDOUT,*) ' BUG: INVALID INDEX FOR COMP. GOTO.'
          WRITE(STDOUT,*) ' IN SUB. SCAN_MASTER_INPUT. INDEX=',ACT
          STOP 'Abnormal stop: errors found.'


100     CONTINUE
C         Transfer LINE 
          IT = LEN_TRIM(LINE)

          IF(IT.EQ.0) THEN
C           Line is blank
            WRITE(STDTMP,'(A)') ' '
          ELSE
C           Line is not blank
            WRITE(STDTMP,'(A)') LINE(1:IT)
          ENDIF
          INHAND = FALSE
          GOTO 9999

200     CONTINUE
          IF(STACK_STATE.EQ.FALSE) THEN
C           Discard lines until we find a keyword whose level 
C           matches the level of the token on the top of stack.
            CALL DISCARD_LINES(STDIN, STDOUT, STACK_LEVEL,
     M                       OLD_LEVEL, OLD_TOKEN,
     O                       INHAND_TOKEN, INHAND_STATE, INHAND_LEVEL)

            INHAND = TRUE
          ELSE
C           Transfer LINE 
            IT = LEN_TRIM(LINE)

            IF(IT.EQ.0) THEN
C             Line is blank
              WRITE(STDTMP,'(A)') ' '
            ELSE
C             Line is not blank
              WRITE(STDTMP,'(A)') LINE(1:IT)
            ENDIF
            INHAND = FALSE
          ENDIF
          GOTO 9999

300     CONTINUE
C         Push in-hand values onto the stack.
          CALL PUSH_TOKEN(INHAND_TOKEN, INHAND_STATE, INHAND_LEVEL,
     O                    TOP_PNT)
          INHAND = FALSE
          GOTO 9999

400     CONTINUE
          IF(STACK_STATE.EQ.FALSE) THEN
C           Discard lines until we find a keyword whose level 
C           matches the level of the token on the top of stack.
            CALL DISCARD_LINES(STDIN, STDOUT, STACK_LEVEL,
     M                       OLD_LEVEL, OLD_TOKEN,
     O                       INHAND_TOKEN, INHAND_STATE, INHAND_LEVEL)

            INHAND = TRUE
          ELSE
C           Push in-hand values onto the stack.
            CALL PUSH_TOKEN(INHAND_TOKEN, INHAND_STATE, INHAND_LEVEL,
     O                      TOP_PNT)
            INHAND = FALSE
          ENDIF
          GOTO 9999

500     CONTINUE
C         Error- ELSE found but matching IF or ELSEIF
          WRITE(STDOUT,505) 
          STOP 'Abnormal stop.  Error(s) found.'

600     CONTINUE
C         process an in-hand ELSE with a matching IF or ELSEIF
          CALL POP_TOKEN(
     O                   STACK_TOKEN, STACK_STATE, STACK_LEVEL, TOP_PNT)
          IF(STACK_LEVEL.NE.INHAND_LEVEL) THEN
C           Possible user error.
            WRITE(STDOUT,506)
            STOP 'Abnormal stop.  Error(s) found.'
          ENDIF

C         If the just popped token was true, then we need to discard lines
C         until we find an ENDIF whose level matches the just popped value.
          IF(STACK_STATE.EQ.TRUE) THEN
            CALL DISCARD_LINES_TO_ENDIF(STDIN, STDOUT, STACK_LEVEL,
     M                    OLD_LEVEL, OLD_TOKEN,
     O                    DISCARD_TOKEN, DISCARD_STATE, DISCARD_LEVEL)
           
          ELSE
            INHAND_STATE = TRUE
            CALL PUSH_TOKEN(INHAND_TOKEN, INHAND_STATE, INHAND_LEVEL,
     O                      TOP_PNT)
          ENDIF
          INHAND = FALSE
          GOTO 9999

700     CONTINUE
C         Error- ELSE found  after a matching ELSE
          WRITE(STDOUT,507)
          STOP 'Abnormal stop.  Error(s) found.'

800     CONTINUE
C         Error- ELSEIF found with no preceding IF or ELSEIF
          WRITE(STDOUT,508)
          STOP 'Abnormal stop.  Error(s) found.'
             
900     CONTINUE
C         Process an ELSEIF with a matching IF or ELSEIF
          CALL POP_TOKEN(
     O                   STACK_TOKEN, STACK_STATE, STACK_LEVEL, TOP_PNT)
          IF(STACK_LEVEL.NE.INHAND_LEVEL) THEN
C           Possible user error.
            WRITE(STDOUT,506)
            STOP 'Abnormal stop.  Error(s) found.'
          ENDIF
C         If the stack state is true, discard lines until we find
C         an ENDIF at the stack level.
          IF(STACK_STATE.EQ.TRUE) THEN
            CALL DISCARD_LINES_TO_ENDIF(STDIN, STDOUT, STACK_LEVEL,
     M                  OLD_LEVEL, OLD_TOKEN,
     O                  DISCARD_TOKEN, DISCARD_STATE, DISCARD_LEVEL)
          
          ELSE
            CALL PUSH_TOKEN(INHAND_TOKEN, INHAND_STATE, INHAND_LEVEL,
     O                      TOP_PNT)
          ENDIF
          INHAND = FALSE
          GOTO 9999

1000    CONTINUE
C         Error- ELSEIF after matching ELSE
          WRITE(STDOUT,510)
          STOP 'Abnormal stop.  Error(s) found.'


1100    CONTINUE
C         Error-ENDIF found but no matching statement exists
          WRITE(STDOUT,511)
          WRITE(STDOUT,'(A)') LINE
          STOP 'Abnormal stop.  Error(s) found.'

1200    CONTINUE
C         Process an ENDIF with a matching IF, ELSE, or ELSEIF
          CALL POP_TOKEN(
     O                   STACK_TOKEN, STACK_STATE, STACK_LEVEL, TOP_PNT)
          IF(STACK_LEVEL.NE.INHAND_LEVEL) THEN
C           Possible user error.
            WRITE(STDOUT,506)
            STOP 'Abnormal stop.  Error(s) found.'
          ENDIF
          INHAND = FALSE
          GOTO 9999

1300    CONTINUE
C         Process the ENDFILE.
C         Master file has been processed. 
          CLOSE(STDTMP)
          CLOSE(STDIN)
          OPEN(UNIT=STDIN, FILE=FILE_NAME,STATUS='OLD')
          
          GOTO 10000

1400    CONTINUE
C         Error-End of Master input file found before ENDIF for 
C               IF was found.
          WRITE(STDOUT,514)
          STOP 'Abnormal stop.  Error(s) found.'

1500    CONTINUE
C         Error-End of Master input file found before ENDIF for 
C               ELSE was found.
          WRITE(STDOUT,515)
          STOP 'Abnormal stop.  Error(s) found.'

1600    CONTINUE
C         Error-End of Master input file found before ENDIF for 
C               ELSEIF was found.
          WRITE(STDOUT,516)
          STOP 'Abnormal stop.  Error(s) found.'

9999    CONTINUE
          GOTO 9000

10000 CONTINUE
      RETURN
      END


