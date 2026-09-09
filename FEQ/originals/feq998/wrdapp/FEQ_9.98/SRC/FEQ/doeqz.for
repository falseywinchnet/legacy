C
C
C
       SUBROUTINE DOEQZ(STDOUT, NBRA, NBN, NEX, EXNODT, EMC, EPT,
     M             YE1KNOWN,
     O             EFLAG)
 
C     + + + PURPOSE + + +
C     Make assignment of EqZ instructions if one of the pair of nodes
C     has an unknown value.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, EPT, NBN, NBRA, NEX, STDOUT
      INTEGER YE1KNOWN(NEX)
      INTEGER EMC(EPT), EXNODT(9,NEX)

C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     NEX    - number of exterior nodes in the model
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     EMC    - vector containing coded form of the Matrix Control Input
C     EXNODT - exterior node table.  Contains the following items
C              for each exterior node.
C              Row   Content
C               1    sign of the node
C               2    pointer into vectors for nodes on a branch
C               3    descriptive code: if -1 then a reservoir;
C                    if  0 then not on a branch and not a reservoir;
C                    if > 0 then a branch number
C               4    pointer to a cross section table if on a branch, 
C                    to storage table if a reservoir, to other node if
C                    a dummy branch
C               5    gives the variable number(in the system matrix) for
C                    the flow at the exterior node. Also a junction
C                    pointer in initial processing of input
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'enelem.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'matcom.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER  CODE, DNN, IPNT, UPN, IENTRY, KNT, OLDKNT,
     A         OTHER_END, MAXPASS, PASS, MID, IDUM 
 
      REAL RDUM, ZMID

      EQUIVALENCE (IDUM, RDUM)

C     + + + EXTERNAL FUNCTIONS + + +
      CHARACTER*5 GETUSN
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETUSN 
C     + + + OUTPUT FORMATS + + +
50    FORMAT(/,
     A'*BUG:XXX* Branch node:',A5,' has unknown elev. in DOEQZ.')
52    FORMAT(/,'*BUG*  Too many passes in DOEQZ. Runaway loop.')
60    FORMAT(' Both unknown: ',A5,' ',A5,'  KNT=',I5)
62    FORMAT(' ',A5,' known. ',A5,' unknown')
64    FORMAT(' Other end=',A5)
65    FORMAT(//,
     A ' Initializing EqZ connections to free nodes on dummy branches')
66    FORMAT(/,' PASS=',I5)
68    FORMAT(' Source nodes for Code 12 unknown:',A5,' ',A5,' ',A5)
70    FORMAT(' ',A5,' Unknown in code 12')
72    FORMAT(/,
     A ' EqZ connections to free nodes on dummy branches completed')
C***********************************************************************
C     The only unknown exterior nodes here should be free nodes.  All
C     nodes on a branch should be known here--if not, we have a bug.

C     Approach:  1. Set KNT to zero and then scan for EqZ instructions. 
C      2.For each one found check for an unknown values of elevation/depth.
C      3. If only one value is unknown, then assign the known value to
C         it if the unknown value is at a free node.  If it is a 
C         branch node, then write bug message and stop. 
C      4. If the unknown value being assigned is on a dummy branch or 
C         on a LPR, 
C         then assign the same value to the other node.
C      5. If two values are unknown, then increment KNT.

C     We need to have an old value of KNT because there may be some values
C     that do not get assigned.  Output a warning message for each exterior
C     node with an unknown value.


      KNT = 0
      OLDKNT = 0
      MAXPASS = NEX
      PASS = 0
      WRITE(STDOUT,65)
100   CONTINUE
        PASS = PASS + 1
        WRITE(STDOUT,66) PASS
        IF(PASS.GT.MAXPASS) THEN
          WRITE(STDOUT,52)
          STOP 'Abnormal stop.  Bug found.'
        ENDIF          
C       Start loop seaching for EqZ:  CODE=3
        IENTRY = 0
 
 200    CONTINUE
          IENTRY = IENTRY + 1
          IPNT = ADD(IENTRY)
          CODE = EMC(IPNT)
          IF(CODE.EQ.3) THEN
C           Get the node numbers
            UPN = EMC(IPNT+1)
            DNN = EMC(IPNT+2)
            IF(YE1KNOWN(UPN).EQ.0) THEN
C             The upstream node is unknown.  Is it on a branch?
              IF(EXNODT(3,UPN).GT.0) THEN
                WRITE(STDOUT,50) GETUSN(UPN)
                STOP 'Abnormal stop.  Bug found.'
              ENDIF
              IF(YE1KNOWN(DNN).EQ.0) THEN
C               Both nodes are unknown.  Count the occurrence.
                KNT = KNT + 1
                WRITE(STDOUT,60) GETUSN(UPN), GETUSN(DNN), KNT
              ELSE
C               DNN node has known elevation.  Assign its value
C               to UPN node and update the known flag.
                WRITE(STDOUT,62) GETUSN(DNN), GETUSN(UPN)
                YE1(UPN) = YE1(DNN) + ZE(DNN) - ZE(UPN)
                YE1KNOWN(UPN) = 1
C               Now propagate the value to the other end of the 
C               dummy branch.
                IF(EXNODT(3,UPN).EQ.0) THEN
C                 Node on dummy branch or inflow node to LPR
                  IF(EXNODT(4,UPN).GT.0) THEN
C                   Node on a dummy branch
                    OTHER_END = EXNODT(4,UPN)
                    WRITE(STDOUT,64) GETUSN(OTHER_END)
                    YE1(OTHER_END) = YE1(DNN) + ZE(DNN) - ZE(OTHER_END)
                    YE1KNOWN(OTHER_END) = 1
                  ENDIF
                ENDIF
              ENDIF
            ELSE
C             UPN node is known
              IF(YE1KNOWN(DNN).EQ.0) THEN
                WRITE(STDOUT,62) GETUSN(UPN), GETUSN(DNN)

C               DNN node is unknown.  Is it on a branch?
                IF(EXNODT(3,DNN).GT.0) THEN
                  WRITE(STDOUT,50) GETUSN(DNN)
                  STOP 'Abnormal stop.  Bug found.'
                ENDIF
C               Assign the value to the unknown node.
                YE1(DNN) = YE1(UPN) + ZE(UPN) - ZE(DNN)
                YE1KNOWN(DNN) = 1
C               Now propagate the value to the other end of the 
C               dummy branch. 
                IF(EXNODT(3,DNN).EQ.0) THEN
C                 Node on dummy branch or inflow node to LPR
                  IF(EXNODT(4,DNN).GT.0) THEN
C                   Node on a dummy branch
                    OTHER_END = EXNODT(4,DNN)
                    WRITE(STDOUT,64) GETUSN(OTHER_END)
                    YE1(OTHER_END) = YE1(UPN) + ZE(UPN) - ZE(OTHER_END)
                    YE1KNOWN(OTHER_END) = 1
                  ENDIF
                ENDIF
              ENDIF
            ENDIF
          ELSEIF(CODE.EQ.12) THEN
C           Get the node numbers
            UPN = EMC(IPNT+1)
            DNN = EMC(IPNT+2)
            MID = EMC(IPNT+3)
            IF(YE1KNOWN(MID).EQ.0) THEN
              WRITE(STDOUT,70) GETUSN(MID)
              
              IF(YE1KNOWN(UPN).EQ.0.OR.YE1KNOWN(DNN).EQ.0) THEN
C               Count as an unknown.
                KNT = KNT + 1
                WRITE(STDOUT,68) GETUSN(UPN), GETUSN(DNN), GETUSN(MID)
              ELSE
C               Both source nodes are known.   Get the factor
                IDUM = EMC(IPNT+4)
                ZMID = RDUM*(YE1(UPN) + ZE(UPN)) + 
     A                  (1. - RDUM)*(YE1(DNN) + ZE(DNN))
                YE1(MID) = ZMID - ZE(MID)
                YE1KNOWN(MID) = 1
C               Now set the other end. 
                IF(EXNODT(3,MID).EQ.0) THEN
C                 Node on dummy branch or inflow node to LPR
                  IF(EXNODT(4,MID).GT.0) THEN
C                   Node on dummy branch
                    OTHER_END = EXNODT(4,MID)
                    WRITE(STDOUT,64) GETUSN(OTHER_END)
                    YE1(OTHER_END) = ZMID - ZE(OTHER_END)
                    YE1KNOWN(OTHER_END) = 1
                  ENDIF
                ENDIF
              ENDIF
            ENDIF
          ENDIF
          IF(CODE.GT.0) THEN
C           Continue the search.
            GOTO 200
          ENDIF
      
C       If KNT is zero at this point, then all unknown values
C       of depth/elevation have been assign and we are done.
C       If KNT is positive, then place its value in OLDKNT, 
C       clear KNT, and go back for another pass.  If KNT is the
C       same as OLDKNT, then we are done but with some undefined
C       depths/elevations. 

        IF(KNT.GT.0) THEN
          IF(KNT.EQ.OLDKNT) THEN
C           We are done but there are still some undefined values. 
C           Do a scan again but print all nodes with an undefined value. 
 
            WRITE(STDOUT,*) ' In DOEQZ: KNT=',KNT,' OLDKNT=',OLDKNT

          ELSE
C           There has been a change in the count of cases where both 
C           values are unknown.  Continue the scanning to possibly 
C           spread the change to the next set of unknowns.
            OLDKNT = KNT
            KNT = 0
            GOTO 100
          ENDIF
        ENDIF
 
      WRITE(STDOUT,72)
      RETURN
      END
C
C
C
      SUBROUTINE FIND_CODE7(STDOUT, NODE, MR, EMC,
     O                    INODE)

C     Search EMC, the network-matrix control vector for a code 7 with
C     a reservoir node of NODE and return with the inflow node value, INODE.

      IMPLICIT NONE
      INTEGER NODE, MR, INODE, STDOUT
      INTEGER EMC(MR)

C     Common blocks
      INCLUDE 'arsize.prm'
      INCLUDE 'matcom.cmn'

C     External routines
      CHARACTER*5 GETUSN
      EXTERNAL GETUSN
C     Local variables
      INTEGER CODE, IENTRY, IPNT

C***********************************************************************
      IENTRY = 0
 
 200  CONTINUE
        IENTRY = IENTRY + 1
        IPNT = ADD(IENTRY)
        CODE = EMC(IPNT)
        IF(CODE.EQ.7) THEN
          IF(EMC(IPNT+1).EQ.NODE) THEN
C           We have a hit.
            INODE = EMC(IPNT+5)
            RETURN
          ENDIF
        ENDIF
        IF(CODE.GT.0) THEN
C         Continue the search.
          GOTO 200
        ENDIF

C     If we fall through, then we have a bug.  We were seeking a code
C     7 with NODE and it had better exist in EMC or there are major problems
C     afoot elsewhere.

      WRITE(STDOUT,50) GETUSN(NODE)
50    FORMAT(/,'*BUG* Exterior node=',A5,' expected as a LPR',
     A   ' node but code 7 with this node not found in EMC!')

      STOP 'Abnormal stop.  Bug found.'
      END