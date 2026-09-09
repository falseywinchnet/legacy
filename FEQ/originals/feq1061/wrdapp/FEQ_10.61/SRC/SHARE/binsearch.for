C
C
C
      SUBROUTINE   BINSER
     I                   (ITEM, N, TAB,
     O                    MID)
 
C     + + + PURPOSE + + +
C     Binary search in a sorted list of N items stored
C     in TAB(*). MID=0 if element is not found, else
C     MID gives the location in TAB at which a match
C     was found.
 
      IMPLICIT NONE

C     + + + DUMMY ARGUMENTS + + +
      INTEGER MID, N
      CHARACTER ITEM*(*), TAB(N)*(*)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ITEM   - Search value
C     N      - Number of items to search
C     TAB    - Vector of items to be searched for a match
C     MID    - Index of value found and 0 if value not found
 
C     + + + LOCAL VARIABLES + + +
      INTEGER IL, IR
C***********************************************************************
      IL = 1
      IR = N
 100  CONTINUE
        IF(IL.GT.IR) GOTO 140
          MID = (IL + IR)/2
          IF(ITEM.GE.TAB(MID)) GOTO 110
            IR = MID - 1
            GOTO 130
 110      CONTINUE
            IF(ITEM.EQ.TAB(MID)) GOTO 120
              IL = MID + 1
              GOTO 130
 120        CONTINUE
            RETURN
 130      CONTINUE
            GOTO 100
 140    CONTINUE
        MID=0
        RETURN
        END

