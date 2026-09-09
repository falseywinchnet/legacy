C     Other i/o unit handling routines are in directory SHARE
C     ***********
C     *         *
C     * GET_HECDSS_UNIT
C     *         *
C     ***********

      INTEGER FUNCTION GET_HECDSS_UNIT (STDOUT)

C     Get a unit number for HECDSS I/O.

      INTEGER STDOUT

      INCLUDE 'forunit.cmn'

C     Local

      INTEGER I
C     *********************************FORMATS**************************
50    FORMAT(/,' *ERR:319* I/O unit numbers exhausted.')
C***********************************************************************
      DO 100 I=1,DIM_UNIT
        IF(UNIT_STATUS(I).EQ.0) THEN
C         Found one!
          GET_HECDSS_UNIT = I
          UNIT_KNT = UNIT_KNT + 1
C         Mark unit as in use for HECDSS I/O
          UNIT_STATUS(I) = HECDSS_IO
          GOTO 110
        ENDIF
100   CONTINUE
C     If we get here then there are no unit numbers left.  This is
C     a fatal error. 
      WRITE(STDOUT,50) 
      STOP 'Abnormal stop: errors found.'

110   CONTINUE
      RETURN
      END      

C     ***********
C     *         *
C     * RELEASE_HECDSS_UNIT
C     *         *
C     ***********

      SUBROUTINE RELEASE_HECDSS_UNIT(STDOUT, UNIT)

C     Free a HECDSS file I/O unit number.  The file is closed elsewhere.

      IMPLICIT NONE
      INTEGER STDOUT, UNIT

      INCLUDE 'forunit.cmn'

C     *****************************Formats******************************
50    FORMAT(/,' *BUG:XXX* Unit=',I5,' out of range in',
     A         ' RELEASE_HECDSS_UNIT.')
52    FORMAT(/,' *BUG:XXX* Unit=',I5,' was not in use in',
     A         ' RELEASE_HECDSS_UNIT.')
54    FORMAT(/,' *BUG:XXX* Unit=',I5,' was not assigned to HECDSS in',
     A         ' RELEASE_HECDSS_UNIT.')
C***********************************************************************
      IF(UNIT.LE.0.OR.UNIT.GT.DIM_UNIT) THEN
        WRITE(STDOUT,50) UNIT
      ELSEIF(UNIT_STATUS(UNIT).LE.0) THEN
        WRITE(STDOUT,52) UNIT
      ELSE
        IF(UNIT_STATUS(UNIT).EQ.HECDSS_IO) THEN
C         Free for use later.
          UNIT_STATUS(UNIT) = 0
          RETURN
        ELSE
          WRITE(STDOUT,54) UNIT
        ENDIF
      ENDIF
      STOP 'Abnormal stop: bug found.'
      END        
