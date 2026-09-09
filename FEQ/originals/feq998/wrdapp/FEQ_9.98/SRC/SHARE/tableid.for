C
C
C
      SUBROUTINE FIND_INTERNAL_TAB_NUMBER
     I                                  (TABID,
     O                                   INTERNAL_TAB_NUMBER)

C     Given an id, try to find its internal table nubmer, if none is found,
C     return 0
      IMPLICIT NONE
      INTEGER  INTERNAL_TAB_NUMBER
      CHARACTER*16 TABID

      INCLUDE 'arsize.prm'
      INCLUDE 'tabid.cmn'

C******************************************************************************

      CALL LSTAB
     I           (TABID, TABID_TABLE, NUM_TABID,
     O            INTERNAL_TAB_NUMBER)

      RETURN
      END
C
C
C
      SUBROUTINE GET_INTERNAL_TAB_NUMBER
     I                                  (STDOUT, TABID,
     M                                   EFLAG,
     O                                   INTERNAL_TAB_NUMBER)

C     Given a table id, find its internal table number and if none
C     is known, assign one. 
      IMPLICIT NONE
      INTEGER EFLAG, INTERNAL_TAB_NUMBER, STDOUT
      CHARACTER*16 TABID

      INCLUDE 'arsize.prm'
      INCLUDE 'tabid.cmn'

C******************************************************************************

      CALL LSATAB
     I           (STDOUT, TABID, MFTNUM,
     M            TABID_TABLE, NUM_TABID,
     O            INTERNAL_TAB_NUMBER, EFLAG)

      RETURN
      END
C
C
C
      CHARACTER*16 FUNCTION GET_TABID(ITABNUM)

C     Get the table id from the symbol table given the internal table
C     number.

      IMPLICIT NONE
      INTEGER ITABNUM

      INCLUDE 'arsize.prm'
      INCLUDE 'tabid.cmn'

C*******************************************************************************
      IF(ITABNUM.GT.0.AND.ITABNUM.LE.NUM_TABID) THEN
        GET_TABID = TABID_TABLE(ITABNUM)
      ELSE
        GET_TABID = ' '
      ENDIF
      RETURN
      END
C
C
C
      INTEGER FUNCTION NONBLANK_NONZERO(CHAR16)

C     Signal if the argument string is non-blank and if an 
C     integer if it is non-zero as well.  The function value is 
C     zero if the string contains all blanks or is  an
C     integer zero. 

      IMPLICIT NONE
      CHARACTER*16 CHAR16

C     Local
      INTEGER I

C*******************************************************************************
      NONBLANK_NONZERO = 0
      IF(CHAR16.NE.' ') THEN
C       Attempt to read as an integer
        READ(CHAR16,'(I16)',ERR=100) I
        IF(I.NE.0) THEN
          NONBLANK_NONZERO = 1
        ENDIF
        GOTO 110
100     CONTINUE
          NONBLANK_NONZERO = 1
110     CONTINUE
      ENDIF
      RETURN
      END
