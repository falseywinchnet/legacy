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

