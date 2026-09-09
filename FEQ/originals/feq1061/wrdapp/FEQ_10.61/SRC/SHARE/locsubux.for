C
C
C
      SUBROUTINE TIMERL
     O                 ( ITICK )

C     + + + PURPOSE + + +
C     Determine the elapsed time in  0.01 seconds since first call to this
C     routine.

      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ITICK

C     + + + ARGUMENT DEFINITIONS + + +
C     ITICK  - Number of seconds elapsed since first call.

C     + + + LOCAL VARIABLES + + +
      REAL  TIME_VEC(2)
      INTEGER SECONDS
      REAL CTIME, TIME

      REAL DTIME
      
C     DATE_AND_TIME IS A LAHEY FORTRAN 90 SYSTEM SUBROUTINE

C     + + + SAVE VARIABLES + + +
      INTEGER first, base
      SAVE first, base, CTIME

C     + + + DATA INITIALIZATIONS + + +
      DATA first/0/, CTIME/0.0/

C***********************************************************************

      TIME = DTIME(TIME_VEC)
      CTIME = CTIME + TIME
      
      SECONDS = INT(CTIME*100.D0 + 0.5D0)
      IF (first.EQ.0) THEN
        first = 1
        base = SECONDS
        ITICK = 0
      ELSE
        ITICK = SECONDS - base
      ENDIF
C
      RETURN
      END
