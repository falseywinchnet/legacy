C     Misc routines

C
C
C
      SUBROUTINE CLEAR_HOME()

C     Clear the Local HOME part of file names. 

      IMPLICIT NONE

      INCLUDE 'home.cmn'
C***********************************************************************
      HOME = ' '
      RETURN
      END
C
C
C
      SUBROUTINE SET_HOME(LHOME)

C     Set the Local HOME part of file names. 

      IMPLICIT NONE
      CHARACTER*(*) LHOME

      INCLUDE 'home.cmn'
C***********************************************************************
      HOME = LHOME
      RETURN
      END

