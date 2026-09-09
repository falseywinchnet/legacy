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
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ITICK
C
C     + + + ARGUMENT DEFINITIONS + + +
C     ITICK  - Number of seconds elapsed since first call.
C
C     + + + LOCAL VARIABLES + + +
      CHARACTER cdate*8, ctime*10, czone*5
      INTEGER ivalues(8), ihr, imn, isec, seconds, imilli
C
C     DATE_AND_TIME IS A LAHEY FORTRAN 90 SYSTEM SUBROUTINE
C
C     + + + SAVE VARIABLES + + +
      INTEGER first, base
      SAVE first, base
C
C     + + + DATA INITIALIZATIONS + + +
      DATA first/0/
C
C     + + + END SPECIFICATIONS + + +
C
      CALL DATE_AND_TIME(cdate,ctime,czone,ivalues)
      ihr = ivalues(5)
      imn = ivalues(6)
      isec = ivalues(7)
      imilli = ivalues(8)
      
      seconds = (ihr*3600 + imn*60 + isec )*100 + imilli/10
C      secnds = (ihr*3600 + imn*60 + isec )*100 
      IF (first.EQ.0) THEN
        first = 1
        base = seconds
        ITICK = 0
      ELSE
        ITICK = seconds - base
      ENDIF
C
      RETURN
      END
