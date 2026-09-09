C     ***********
C     *         *
C     * PROCESS_OLD_IOUNITS
C     *         *
C     ***********

      SUBROUTINE PROCESS_OLD_IOUNITS(STDOUT, UNIT_STRING, 
     O                               UNIT, NAME_STRING)

C     Process old I/O unit specifications so that the old format will
C     be read properly and the new one also 

      INTEGER STDOUT, UNIT

      CHARACTER UNIT_STRING*(*), NAME_STRING*(*)

C     Local

      INTEGER IT

      EXTERNAL STRIP_L_BLANKS
C     ****************************Formats*******************************
C***********************************************************************
C     We assume that the unit string contains everything following
C     the = in the old specification.  We always used I5 for the
C     input of the unit number.  Thus we seek a unit number in the
C     first 5 characters.  If we find one, then we assume that we
C     have the old format. 

      READ(UNIT_STRING(1:5),'(I5)',ERR=100) IT
C       Ok here.  We found an integer.
        IF(IT.GT.0) THEN 
          NAME_STRING = UNIT_STRING(6:)
          UNIT = IT
        ELSE
C         If the unit number, IT, is zero, we assume that the name is
C         to be ignored!
          UNIT = 0
          NAME_STRING = ' '
        ENDIF
        GOTO 110
100   CONTINUE
C       Read for an integer failed.  Assume that unit was not
C       given and the name string begins at first character
        NAME_STRING = UNIT_STRING
C       Return positive unit number to force checking for length of
C       NAME_STRING in calling program unit. 
        UNIT = 1
110   CONTINUE
      CALL STRIP_L_BLANKS(
     M                  NAME_STRING)
      RETURN
      END
