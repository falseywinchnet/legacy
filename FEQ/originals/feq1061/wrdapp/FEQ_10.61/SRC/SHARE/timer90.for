C
C
C
      SUBROUTINE TIMERL
     O                 ( ITICK )
C
C     + + + PURPOSE + + +
C     Determine the elapsed time in 100-th seconds since first call to this
C     routine.
C
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ITICK
C
C     + + + ARGUMENT DEFINITIONS + + +
C     ITICK  - Number of seconds elapsed since first call.
C
C     + + + LOCAL VARIABLES + + +
      INTEGER COUNT, COUNT_RATE, COUNT_MAX
      real*8 time
C
C     + + + SAVE VARIABLES + + +
      INTEGER first, base, seconds
      SAVE first, base, seconds
C
C     + + + DATA INITIALIZATIONS + + +
      DATA first/0/
C
C     + + + END SPECIFICATIONS + + +
C
      CALL SYSTEM_CLOCK(COUNT, COUNT_RATE, COUNT_MAX)

      seconds = INT(DBLE(COUNT)*100.D0/DBLE(COUNT_RATE) + 0.5D0)
c      call cpu_time(time)
c      write(*,*) ' cpu time=',time

c      seconds = time*100.d0 + 0.5d0
      IF (first.EQ.0) THEN
        first = 1
        base = seconds
        ITICK = 0
      ELSE
        ITICK = seconds - base
      ENDIF
      END
