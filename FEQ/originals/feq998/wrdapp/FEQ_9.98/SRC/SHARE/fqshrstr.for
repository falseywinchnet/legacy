C     ***********
C     *         *
C     * CHAR_TO_DP
C     *         *
C     ***********

      REAL*8 FUNCTION CHAR_TO_DP(CHAR_ARGUMENT)

C     Transfer a character string that is 8 characters long
C     into a 8-byte floating point variable WITHOUT any 
C     data conversion. 

      IMPLICIT NONE
      CHARACTER*8 CHAR_ARGUMENT

C     Local

      REAL*8 TP
C***********************************************************************
      READ(CHAR_ARGUMENT,'(A8)')  TP
      CHAR_TO_DP = TP
      RETURN
      END
C     ***********
C     *         *
C     * DP_TO_CHAR
C     *         *
C     ***********

      CHARACTER*8 FUNCTION DP_TO_CHAR(DP_ARGUMENT)

C     Transfer the characters placed in the DP_ARGUMENT
C     by the function CHAR_TO_DP to a character string.

      IMPLICIT NONE

      REAL*8 DP_ARGUMENT

C     Local

      CHARACTER*8 TP
C***********************************************************************
      WRITE(TP,'(A8)')  DP_ARGUMENT
      DP_TO_CHAR = TP
      RETURN
      END
      

C     ***********
C     *         *
C     * VAR_DECIMAL
C     *         *
C     ***********

      SUBROUTINE VAR_DECIMAL(VALUE,
     O                       RESULT)

C     Convert VALUE to a number and output it in RESULT so as 
C     to get a good use of the columns for precision of output. 

      IMPLICIT NONE
      CHARACTER*(*) RESULT

      REAL VALUE

C     Local

      INTEGER FIELD_WIDTH, NUMBER_OF_DECIMAL_PLACES, D,
     A        IT

      REAL Y

      CHARACTER ROUT_FORMAT*7,  IOUT_FORMAT*5, CHAR2*2

      INTRINSIC LOG10, ABS
      
      DATA ROUT_FORMAT/'(F  . )'/, IOUT_FORMAT/'(I  )'/
      
C***********************************************************************
      FIELD_WIDTH = LEN(RESULT)
      IF(FIELD_WIDTH.GT.20) FIELD_WIDTH = 20
      WRITE(CHAR2,'(I2)') FIELD_WIDTH
      ROUT_FORMAT(3:4) = CHAR2
      IOUT_FORMAT(3:4) = CHAR2
      IF(VALUE.NE.0.0) THEN
        Y = LOG10(ABS(VALUE))
        IF(Y.LT.0.0) Y = 0.0
      ELSE
        Y = 0.0
      ENDIF
      
      D = INT(Y) + 3
      IF(D.LT.FIELD_WIDTH) THEN

        NUMBER_OF_DECIMAL_PLACES = FIELD_WIDTH - D
        IF(NUMBER_OF_DECIMAL_PLACES.GT.7) NUMBER_OF_DECIMAL_PLACES = 7
        WRITE(ROUT_FORMAT(6:6),'(I1)') NUMBER_OF_DECIMAL_PLACES

        WRITE(RESULT, ROUT_FORMAT) VALUE
      ELSE
        IT = ABS(VALUE) + 0.5
        IF(VALUE.LT.0.0) IT = -IT
        WRITE(RESULT,IOUT_FORMAT) IT
      ENDIF

      RETURN
      END
C     ***********
C     *         *
C     * VAR_DECIMALD
C     *         *
C     ***********

      SUBROUTINE VAR_DECIMALD(VALUE,
     O                       RESULT)

C     Convert VALUE to a number and output it in RESULT so as 
C     to get a good use of the columns for precision of output. 

      IMPLICIT NONE
      CHARACTER*(*) RESULT

      REAL*8 VALUE

C     Local

      INTEGER FIELD_WIDTH, NUMBER_OF_DECIMAL_PLACES, D,
     A        IT

      REAL*8 Y

      CHARACTER ROUT_FORMAT*7,  IOUT_FORMAT*5, CHAR2*2

      INTRINSIC LOG10, ABS
      
      DATA ROUT_FORMAT/'(F  . )'/, IOUT_FORMAT/'(I  )'/
      
C***********************************************************************
      FIELD_WIDTH = LEN(RESULT)
      IF(FIELD_WIDTH.GT.20) FIELD_WIDTH = 20
      WRITE(CHAR2,'(I2)') FIELD_WIDTH
      ROUT_FORMAT(3:4) = CHAR2
      IOUT_FORMAT(3:4) = CHAR2
      IF(VALUE.NE.0.0) THEN
        Y = LOG10(ABS(VALUE))
        IF(Y.LT.0.D0) Y = 0.0
      ELSE
        Y = 0.D0
      ENDIF
      
      D = INT(Y) + 3
      IF(D.LT.FIELD_WIDTH) THEN

        NUMBER_OF_DECIMAL_PLACES = FIELD_WIDTH - D
        IF(NUMBER_OF_DECIMAL_PLACES.GT.7) NUMBER_OF_DECIMAL_PLACES = 7
        WRITE(ROUT_FORMAT(6:6),'(I1)') NUMBER_OF_DECIMAL_PLACES

        WRITE(RESULT, ROUT_FORMAT) VALUE
      ELSE
        IT = ABS(VALUE) + 0.5
        IF(VALUE.LT.0.0) IT = -IT
        WRITE(RESULT,IOUT_FORMAT) IT
      ENDIF

      RETURN
      END
C
C
C
      SUBROUTINE   GETNXT
     I                   (NAME, IS,
     O                    IE, NXTSTR)
 
C     + + + PURPOSE + + +
C     Get the next consecutive sequence of non-blank characters from
C     NAME, starting at character position IS, and return the
C     substring together with the index of the next character in
C     NAME at which to start the next search.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IE, IS
      CHARACTER NAME*(*), NXTSTR*(*)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NAME   - string being scanned
C     IS     - character position for starting scan
C     IE     - next character position after current scan
C     NXTSTR - the next string found
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, IEND, ISTART, ISTOP
 
C     + + + INTRINSICS + + +
      INTRINSIC LEN
C***********************************************************************
      I = IS
      IEND = LEN(NAME)
 
 100  CONTINUE
        IF(NAME(I:I).EQ.' ') THEN
          I = I + 1
          IF(I.LE.IEND) THEN
            GOTO 100
          ELSE
C           RETURN A BLANK IF NO NON-BLANK FOUND
            NXTSTR = ' '
            IE = IEND
            RETURN
          ENDIF
        ELSE
          ISTART = I
 110      CONTINUE
            IF(NAME(I:I).NE.' ') THEN
              I = I + 1
              IF(I.LE.IEND) THEN
                GOTO 110
              ELSE
                ISTOP = IEND
              ENDIF
            ELSE
              ISTOP = I - 1
            ENDIF
        ENDIF
 
      NXTSTR = NAME(ISTART:ISTOP)
      IE = ISTOP + 1
      RETURN
      END
C     ***********
C     *         *
C     * STRIP_L_BLANKS
C     *         *
C     ***********

      SUBROUTINE STRIP_L_BLANKS(
     M                          NAME)

C     Strip leading blanks from the string NAME and return.

      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      CHARACTER NAME*(*)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NAME   - string being scanned
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, IEND, ISTART
 
C     + + + INTRINSICS + + +
      INTRINSIC LEN
C***********************************************************************
      I = 1
      IEND = LEN(NAME)
 
 100  CONTINUE
        IF(NAME(I:I).EQ.' ') THEN
          I = I + 1
          IF(I.LE.IEND) THEN
            GOTO 100
          ELSE
C           RETURN A BLANK IF NO NON-BLANK FOUND
            NAME = ' '
            RETURN
          ENDIF
        ELSE
          ISTART = I
        ENDIF
 
      NAME = NAME(ISTART:IEND)
      IF(ISTART.GT.1) THEN
        NAME(IEND-ISTART+2:IEND) = ' '
      ENDIF
      RETURN
      END
C     ***********
C     *         *
C     * STRIP_BLANKS_AND_ZEROS
C     *         *
C     ***********

      SUBROUTINE STRIP_BLANKS_AND_ZEROS(
     M                                  NAME)

C     Strip trailing and leading blanks and leading zeros
C     from the string NAME and return.

      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      CHARACTER NAME*(*)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NAME   - string being scanned
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, IEND, ISTART
 
C     Called program units
C***********************************************************************
      I = 1
      IEND = LEN_TRIM(NAME)
 
 100  CONTINUE
        IF(NAME(I:I).EQ.' ') THEN
          I = I + 1
          IF(I.LE.IEND) THEN
            GOTO 100
          ELSE
C           RETURN A BLANK IF NO NON-BLANK FOUND
            NAME = ' '
            RETURN
          ENDIF
        ELSE
          IF(NAME(I:I).EQ.'0') THEN
            IF(I.EQ.IEND) THEN
              ISTART = I
            ELSE
              IF(NAME(I+1:I+1).EQ.'.') THEN
                ISTART = I
              ELSE
                I = I + 1 
                GOTO 100
              ENDIF
            ENDIF
          ELSE
            ISTART = I
          ENDIF
        ENDIF
 
      NAME = NAME(ISTART:IEND)
      IF(ISTART.GT.1) THEN
        NAME(IEND-ISTART+2:IEND) = ' '
      ENDIF
      RETURN
      END
C
C
C
      CHARACTER*(*) FUNCTION   GETTOK
     I                               (NAME)
 
C     + + + PURPOSE + + +
C     Get the first consecutive sequence of non-blank characters from
C     NAME
      IMPLICIT NONE
 
C     + + + DUMMY ARGUMENTS + + +
      CHARACTER NAME*(*)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NAME   - string being scanned
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, IEND, ISTART, ISTOP
 
C     + + + INTRINSICS + + +
      INTRINSIC LEN
C***********************************************************************
      I = 1
      IEND = LEN(NAME)
 
 100  CONTINUE
        IF(NAME(I:I).EQ.' ') THEN
          I = I + 1
          IF(I.LE.IEND) THEN
            GOTO 100
          ELSE
C           RETURN A BLANK IF NO NON-BLANK FOUND
            GETTOK = ' '
            RETURN
          ENDIF
        ELSE
          ISTART = I
 110      CONTINUE
            IF(NAME(I:I).NE.' ') THEN
              I = I + 1
              IF(I.LE.IEND) THEN
                GOTO 110
              ELSE
                ISTOP = I-1
              ENDIF
            ELSE
              ISTOP = I
            ENDIF
        ENDIF
 
      GETTOK = NAME(ISTART:ISTOP)
      RETURN
      END
C     ***********
C     *         *
C     * LENSTR  *
C     *         *
C     ***********

      INTEGER   FUNCTION   LENSTR
     I                           (STR)


C     Invoke the F95 intrinsic LEN_TRIM

C     Return the actual length of the character string,
C     excluding trailing blanks.  Modified from USGS.


      IMPLICIT NONE
      CHARACTER*(*) STR

C     + + + ARGUMENT DEFINITIONS + + +
C     STR    - character string

C     + + + LOCAL VARIALBES + + +
C      INTEGER LENT, DONE, LEN

C     Program units
      INTRINSIC LEN_TRIM
C***********************************************************************

      LENSTR = LEN_TRIM(STR)
      RETURN
      END
C      DONE = 0
C      LENT = LEN(STR)
C  10  CONTINUE
C        IF (STR(LENT:LENT).EQ.' ') THEN
C          LENT = LENT - 1
C        ELSE
C          DONE = 1
C        END IF
C      IF (LENT.GT.0.AND.DONE.EQ.0) GO TO 10
CC
C      LENSTR= LENT
CC
C      RETURN
C      END


C     ***********
C     *         *
C     * GET_HECDSS_PATH
C     *         *
C     ***********

      SUBROUTINE GET_HECDSS_PATH(STRING,
     M                           NEXT,
     O                           RESULT, EFLAG)

C     Get a HECDSS path name from STRING starting at position NEXT and
C     returning it in RESULT if one is found.  Otherwise return a blank
C     in RESULT.  NEXT should point to the position in the string after
C     the last character of the path if that position exists.  If the
C     position does not exist, return 0.

      IMPLICIT NONE
      INTEGER EFLAG, NEXT
      
      CHARACTER*(*) STRING, RESULT

C     Local

      INTEGER I, J, STRING_LENGTH, FIRST_SLASH, MAX_LENGTH_RESULT,
     A        KNT

C     Called routines

      INTEGER LENSTR

      EXTERNAL LENSTR
      INTRINSIC  LEN
C***********************************************************************
      EFLAG = 0
      RESULT = ' '
      STRING_LENGTH = LENSTR(STRING)
      MAX_LENGTH_RESULT = LEN(RESULT)
C     Find the first /
      DO 90 I=NEXT, STRING_LENGTH
        IF(STRING(I:I).EQ.'/') THEN
          FIRST_SLASH = I
          GOTO 95
        ENDIF
90    CONTINUE
      RESULT = ' '
      NEXT = -1
      RETURN
95    CONTINUE

C     Starting at the first slash, transfer characters to 
C     RESULT, counting slashes until the 7th slash is transferred
C     or some string limit is exhausted.

      KNT = 0
      J = 0
      DO 100 I=FIRST_SLASH, STRING_LENGTH
        J = J + 1
        IF(J.GT.MAX_LENGTH_RESULT) THEN
          EFLAG = 1
          NEXT = -2
          RETURN
        ENDIF
        RESULT(J:J) = STRING(I:I)        
        IF(STRING(I:I).EQ.'/') THEN
          KNT = KNT + 1
          IF(KNT.EQ.7) GOTO 110
        ENDIF
100   CONTINUE
C     A pathname was not found.  We hit the end of string
C     before finding 7 slashes.  
      RESULT = ' '
      NEXT = -3
      RETURN

110   CONTINUE
C     Here we have a path name.  Set the value of NEXT
      IF(I.EQ.STRING_LENGTH) THEN
        NEXT = 0
      ELSE
        NEXT = I + 1
      ENDIF

      RETURN
      END
C     ***********
C     *         *
C     * NXTTOK  *
C     *         *
C     ***********
 
      SUBROUTINE   NXTTOK
     I                   (STRING,
     M                    NXT,
     O                    RESULT)
 
C     + + + PURPOSE + + +
C     Get the next consecutive sequence of non-blank characters from
C     STRING, return the sequence in RESULT, and the next character
C     offset in NXT.

      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER NXT
      CHARACTER RESULT*(*), STRING*(*)

C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STRING - string to scan
C     NXT    - character offset for next scan
C     RESULT - item found

C     + + + LOCAL VARIABLES + + +
      INTEGER I, IEND, ISTART, ISTOP

C     + + + INTRINSICS + + +
      INTRINSIC LEN
C***********************************************************************
      I = NXT
      IEND = LEN(STRING)

 100  CONTINUE
        IF(STRING(I:I).EQ.' ') THEN
          I = I + 1
          IF(I.LE.IEND) THEN
            GOTO 100
          ELSE
C           RETURN A BLANK IF NO NON-BLANK FOUND
            RESULT = ' '
            NXT = -1
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
                ISTOP = I - 1
              ENDIF
            ELSE
              ISTOP = I - 1
            ENDIF
        ENDIF

      RESULT = STRING(ISTART:ISTOP)
      NXT = ISTOP + 1
C      WRITE(*,*) ' NXTTOK: RESULT=',RESULT,' NXT=',NXT
C      WRITE(*,*) ' ISTART=',ISTART,' ISTOP=',ISTOP
      RETURN
      END
      
C
C
C
      CHARACTER*8 FUNCTION   PUT8
     I                           (X)
 
C     + + + PURPOSE + + +
C     Function to convert a real number into a special compact
C     form of output to retain 4 significant figures for
C     numbers in the range -1e10 < x < 1e10.  This range includes
C     all reasonable flows for any river on earth!
C     The smallest non-zero flow is 1e-9, again smaller than any
C     flow of interest in a stream.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      REAL X
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     X      - value to format
 
C     + + + LOCAL VARIABLES + + +
      CHARACTER RESULT*8, WORK*10
C***********************************************************************
      WRITE(WORK,'(1PE10.3)') X
      IF(WORK(8:8).EQ.'+'.AND.WORK(9:9).NE.'0') THEN
C       OVERFLOW
        RESULT = ' *******'
      ELSEIF(WORK(8:8).EQ.'-'.AND.WORK(9:9).NE.'0') THEN
C       UNDERFLOW
        RESULT = ' 0.000+0'
      ELSE
        RESULT(1:6) = WORK(1:6)
        RESULT(7:7) = WORK(8:8)
        RESULT(8:8) = WORK(10:10)
      ENDIF
      PUT8 = RESULT
      RETURN
      END
C
C
C
      SUBROUTINE   RDUP
     I                 (N,
     M                  A,
     O                  NEWN)
 
C     + + + PURPOSE + + +
C     Remove duplicates from the sorted vector A(*) of
C     length N returning the new value of N, NEWN.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER N, NEWN
      REAL A(N)

C      INCLUDE 'stdun.cmn'

C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     N      - Number of items in list
C     A      - Vector of sorted values possibly having duplicates
C     NEWN   - New number of items in list free of duplicates
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, J, J1
      REAL DIV
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
C***********************************************************************
C     Select a value near the middle of the list for scale. 
      DIV = 0.5*(ABS(A(1)) + ABS(A(N)))
C      IF(DIV.EQ.0.0) THEN
C        WRITE(STD6,*) ' N=',N
C        WRITE(STD6,*) ' DIV=',DIV
C        WRITE(STD6,*) (A(I),I=1,N)
C        STOP 'Bug found in RDUP'
C      ENDIF
      J=1
      IF(J+1.GT.N) GOTO 100
        J1=J+1
          DO 90 I=J1,N
          IF(ABS((A(J)-A(1))-(A(I)-A(1)))/DIV.LE.1.E-5) GOTO 90
            J=J+1
            IF(J.NE.I) A(J)=A(I)
 90       CONTINUE
 100  CONTINUE
      NEWN=J
      RETURN
      END
