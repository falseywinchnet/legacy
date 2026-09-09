C Routines used to create and sovle the network matrix, check convergence,      
C update varible sets, etc                                                      
C                                                                               
 
C
C
C
      SUBROUTINE   BDYFLW
     I                   (BDYNUM, DT, EXNODT, NEX, QE1, QE2, 
     I                    WT, BDYVEC,
     M                    BNI, BNQ, TAI, TAQ, TAQBN, WSI, WSQ)
 
C     + + + PURPOSE + + +
C     Compute the cumulative flow into(BNI) and out of(BNQ)
C     the system.  Note that change in direction of flow is
C     included so that flow reversal will be handled reasonably.
C     That is, as the run progresses both BNI and BNQ can only
C     become larger or stay the same.

      IMPLICIT NONE

      INCLUDE 'arsize.prm'
      INCLUDE 'tam.cmn' 
      INCLUDE 'stdun.cmn'

C     + + + DUMMY ARGUMENTS + + +
      INTEGER BDYNUM, NEX
      INTEGER BDYVEC(NEX), EXNODT(9,NEX)
      REAL QE1(NEX), QE2(NEX), WT
      REAL*8 DT, BNI, BNQ, TAI, TAQ, TAQBN, WSI, WSQ
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     BDYNUM - number of boundary nodes in the model
C     DT     - time step in seconds
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
C     NEX    - number of exterior nodes in the model
C     QE1    - flow at exterior nodes at start of time step
C     QE2    - flow at exterior nodes at end of time step
C     TUNIT_KNT - number of trib-area units
C     TAM_GROSS_INFLOW - inflow to each trib-area unit
C     WT     - weight factor for approximating time integrals
C     BDYVEC - node numbers for the boundary nodes in the model
C     BNI  - total volume of inflow to the model to current time
C     BNQ - total volume of outflow from the model to current time
C     TAI - total inflow to tributary area 
C     TAQ - total outflow from tributary area into branches
C           and LPR's exclusive of boundary nodes
C     TAQBN - total outflow to boundary nodes.
C     WSI   -total of inflow to water surface from rainfall
C     WSQ   -total of outflow from water surface from evaporation 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, IT
      REAL TEMP
      REAL*8 SUMNEG, SUMPOS
 
C     + + + INTRINSICS + + +
      INTRINSIC FLOAT
C***********************************************************************
C     APPROXIMATE THE INFLOW AND OUTFLOW INTEGRAL ACCOUNTING
C     FOR ANY FLOW REVERSALS AT THE BOUNDARIES.
 
      SUMPOS = 0.D0 
      SUMNEG = 0.D0
 
      DO 206 I=1,BDYNUM
        IT = BDYVEC(I)
        TEMP = (QE1(IT) + WT*(QE2(IT) - QE1(IT)))
 
C       TEMP*(SIGN OF THE NODE) < 0 INDICATES INFLOW TO THE
C       SYSTEM.  THEREFORE SWITCH SIGNS TO BE THE SAME AS THE
C       SIGN FOR THE LATERAL INFLOW SIGN CONVENTION.
 
        TEMP = -FLOAT(EXNODT(1,IT))*TEMP
        IF(TEMP.GT.0.0) THEN
          SUMPOS = SUMPOS + TEMP
        ELSE
          SUMNEG = SUMNEG + TEMP
        ENDIF
 206  CONTINUE
 
C     BNI AND BNQ MUST BE > 0. CHANGE SIGN OF SUMNEG
 
      BNI = BNI + DT*SUMPOS 
      BNQ = BNQ - DT*SUMNEG
      TAI = TAI + DT*L_TAI
      TAQ = TAQ + DT*L_TAQ
      TAQBN = TAQBN + DT*L_TAQBN
      WSI = WSI + DT*L_WSI
      WSQ = WSQ + DT*L_WSQ
      
      RETURN
      END
C
C
C
      SUBROUTINE   CMPCOR
     I                   (NBRA, NEX, BRPT, EXNODT, QEPS, EPSSYS, EPSSY2,
     I                    ABSTOL,
     O                    MXRE, BMXRE, NMXRE, IVAR_MXRE, KNT, 
     O                    KNTA, BNODE_MAX)
 
C     + + + PURPOSE + + +
C     Compute corrections to current estimate
 
      IMPLICIT NONE

C     + + + DUMMY ARGUMENTS + + +
      INTEGER BMXRE, KNT, KNTA, NBRA, NEX, NMXRE, BNODE_MAX,
     A        IVAR_MXRE
      INTEGER BRPT(8,NBRA), EXNODT(9,NEX)
      REAL ABSTOL, EPSSY2, EPSSYS, MXRE, QEPS
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NBRA   - number of branches in the model
C     NEX    - number of exterior nodes in the model
C     BRPT   - branch pointer table.  Values for each branch are:
C              ROW       Meaning
C              1         upstream user node number
C              2         downstream user node number
C              3         pointer into branch vector for upstream node
C              4         pointer into branch vector for downstream node
C              5         upstream exterior node number
C              6         downstream exterior node number
C              7         pointer to address in EMC for the branch
C              8         number of unknowns at a node for the branch
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
C     QEPS   - value of flow to prevent zero divide when computing
C               relative correction
C     EPSSYS - primary convergence limit 
C     EPSSY2 - secondary convergence limit
C     ABSTOL - Absolute tolerance in depth that overrides relative
C               change in declaring convergence.
C     MXRE   - maximum relative correction value for any variable
C     BMXRE  - branch number for maximum relative correction
C     NMXRE  - node number at which maximum relative correction occurs
C     IVAR_MXRE -internal variable number at point of max relative error (correction)
C     KNT    - number of variables that violate the primary convergence
C               tolerance
C     KNTA   - number of variables that violate the secondary
C               convergence tolerance
C     BNODE_MAX - internal branch node number of maximum relative 
C                 correction.
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'misccon.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'enothr.cmn'
      INCLUDE 'matcom.cmn'
      INCLUDE 'stdun.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER FNA, I, IDUM, IKNT, IKNTA, IVAR, LNA, NAD, NB, NDBAS,
     A        NINC, SNODE
      REAL B, DIV, DQ, DY, RDUM, T, TEMP
 
C     + + + EQUIVALENCES + + +
      EQUIVALENCE(IDUM, RDUM)
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS, MAX
 
C     + + + EXTERNAL FUNCTIONS + + +
      CHARACTER GETUSN*5
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETUSN
C***********************************************************************
      IKNT = 0
      IKNTA = 0
C     RHS NOW CONTAINS CHANGES AT ALL NODES
 
      MXRE = 0.0
      BMXRE = 0
      NMXRE = 0
 
      DO 50 I=1,NEX
        IF(EXNODT(3,I).GT.0) THEN
C         EXTERIOR NODES ON BRANCHES NEED NOT BE DONE
        ELSE
          IVAR = EXNODT(5,I) + 1
          TEMP = RHS(IVAR)
          IF(EXNODT(3,I).LT.0) THEN
C           RESERVOIR HERE. TE2(I) CONTAINS THE CURRENT SURFACE
C           AREA OF THE RESERVOIR. AE2(I) CONTAINS NEGATIVE OF CURRENT
C           VOLUME.
 
            IF(ABS(TEMP).LT.RESEPS) THEN
              B = 0.0
            ELSE
              RDUM = TE2(I)
              DIV = MAX(ABS(AE2(I)), LPRDY*RDUM, LPRMIN)
              B  = 3.*ABS(TEMP*RDUM/DIV)
            ENDIF
          ELSE
            IF(YE2(I).LE.0.0) THEN
      WRITE(STD6,*) ' *WRN:51* YE2(I) <= 0.0 in CMPCOR at EXNODE=',
     A               GETUSN(I)
 
              IF(ABS(TEMP).LT.0.01) THEN
                B = 0.0
              ELSE
                B = 1.0
              ENDIF
            ELSE
              B = ABS(TEMP)/YE2(I)
c          if(ivar.eq.3062) then
c            write(std6,54) b, ye2(i), temp
c54    format(' Debug: b=',1pe12.5,' ye22(i)=',1pe12.5,' temp=',1pe12.5)
c          endif 

            ENDIF
          ENDIF
          IF(B.GE.MXRE) THEN
            MXRE = B
            BMXRE = 0
            NMXRE = -I
            IVAR_MXRE = IVAR
          ENDIF
          IF(B.GT.EPSSYS) THEN
            IKNT = IKNT + 1
            IF(B.GT.EPSSY2) THEN
              IKNTA = IKNTA + 1
            ENDIF
            HI_IQ_NS_STATE(IVAR) = 0
          ELSE
            HI_IQ_NS_STATE(IVAR) = 1
          ENDIF
          ENCORY(I) = HI_IQ_NS_FAC(IVAR)*TEMP
 
 
          TEMP = RHS(IVAR-1)
 
          B = ABS(TEMP/(ABS(QE2(I)) + QEPS))
 
c          if(ivar-1.eq.3061) then
c            write(std6,52) b, qe2(i), temp
c52    format(' Debug: b=',1pe12.5,' qe2(i)=',1pe12.5,' temp=',1pe12.5)
c          endif 
          IF(B.GE.MXRE) THEN
            MXRE = B
            BMXRE = 0
            NMXRE = I
            IVAR_MXRE = IVAR - 1
          ENDIF
          IF(B.GT.EPSSYS) THEN
            IKNT = IKNT + 1
            IF(B.GT.EPSSY2) THEN
              IKNTA = IKNTA + 1
            ENDIF
            HI_IQ_NS_STATE(IVAR-1) = 0
          ELSE
            HI_IQ_NS_STATE(IVAR-1) = 1
          ENDIF
 
          ENCORQ(I) = HI_IQ_NS_FAC(IVAR-1)*TEMP
        ENDIF
 50   CONTINUE
 
C     DO THE NODES ON BRANCHES
 
      DO 100 NB=1,NBRA
        IVAR = BRPT(7,NB)
        SNODE = BRPT(1,NB)
        IF(IVAR.GT.0) THEN
          NINC = 1
          FNA = BRPT(3,NB)
          LNA = BRPT(4,NB)
          NDBAS = FNA
        ELSE
          NINC = -1
          FNA = BRPT(4,NB)
          LNA = BRPT(3,NB)
          NDBAS = LNA
          IVAR = -IVAR
        ENDIF
 
C       DO THE NODES
 
        DO 90 NAD=FNA,LNA,NINC
          DY = RHS(IVAR+1)
          BNCORY(NAD) = HI_IQ_NS_FAC(IVAR+1)*DY
          IF(ABS(DY).LT.ABSTOL) THEN
            B = 0.0
          ELSE
            T = T2(NAD)
            B = ABS(DY*T/A2(NAD))
          ENDIF
          IF(B.GE.MXRE) THEN
            MXRE = B
            BMXRE = NB
            IVAR_MXRE = IVAR + 1
            BNODE_MAX = NAD
            NMXRE = -(SNODE + NAD - NDBAS)
          ENDIF
 
          IF(B.GT.EPSSYS) THEN
            IKNT = IKNT + 1
            IF(B.GT.EPSSY2) THEN
              IKNTA = IKNTA + 1
            ENDIF
            HI_IQ_NS_STATE(IVAR+1) = 0
          ELSE
            HI_IQ_NS_STATE(IVAR+1) = 1
          ENDIF
 
          DQ = RHS(IVAR)
          BNCORQ(NAD) = HI_IQ_NS_FAC(IVAR)*DQ
 
          B = ABS(DQ/(ABS(Q2(NAD)) + QEPS))
          IF(B.GE.MXRE) THEN
            MXRE = B
            BMXRE = NB
            IVAR_MXRE = IVAR 
            BNODE_MAX = NAD
            NMXRE = SNODE + NAD - NDBAS
          ENDIF
          IF(B.GT.EPSSYS) THEN
            IKNT = IKNT + 1
            IF(B.GT.EPSSY2) THEN
              IKNTA = IKNTA + 1
            ENDIF
            HI_IQ_NS_STATE(IVAR) = 0
          ELSE
            HI_IQ_NS_STATE(IVAR) = 1
          ENDIF
          IVAR = IVAR + 2
 90     CONTINUE
 100  CONTINUE
 
      KNT = IKNT
      KNTA = IKNTA
      RETURN
      END
C
C
C
      SUBROUTINE   CRSET2
     I                   (NBRA, NEX, BRPT,
     M                    EXNODT)
 
C     + + + PURPOSE + + +
C     Establish remainder of set 2 given the values of Y2(*),
C     Ye2(*), and Q2(*).  On convergence Qe2(*) has not yet been
C     set so it must be done here also.
 
      IMPLICIT NONE

C     + + + DUMMY ARGUMENTS + + +
      INTEGER NBRA, NEX
      INTEGER BRPT(8, NBRA), EXNODT(9,NEX)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NBRA   - number of branches in the model
C     NEX    - number of exterior nodes in the model
C     BRPT   - branch pointer table.  Values for each branch are:
C              ROW       Meaning
C              1         upstream user node number
C              2         downstream user node number
C              3         pointer into branch vector for upstream node
C              4         pointer into branch vector for downstream node
C              5         upstream exterior node number
C              6         downstream exterior node number
C              7         pointer to address in EMC for the branch
C              8         number of unknowns at a node for the branch
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
      INCLUDE 'arsize.prm'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'stdun.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADRS, FN, GEQ, IDUM, II, JJ, LN, NTAB
      REAL A, ARG, B, DB, DK, DMA, DMQ, DT, K, MA, MQT, PDV, RDUM, T,
     A     VOL, Y
 
C     + + + EQUIVALENCES + + +
      EQUIVALENCE (IDUM,RDUM)
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LKTAB, XLKT20, XLKT23
C***********************************************************************
      DO 200 II=1,NBRA
        FN = BRPT(3,II)
        LN = BRPT(4,II)
        GEQ = GEQVEC(II)
        DO 100 JJ=FN,LN
          Y = Y2(JJ)
          ADRS = NSEC(JJ)
 
          GOTO(1, 1, 2, 2), GEQ
            WRITE(STD6,*) ' *BUG:XXX* INVALID GEQOPT IN CRSET2'
            STOP 'Abnormal stop: errors found.'
 
 1        CONTINUE
            CALL XLKT20
     I                 (ADRS,
     M                  Y,
     O                  A, T, DT, K, DK, B, DB)
            A2(JJ) = A
            T2(JJ) = T
            K2(JJ) = K
            B2(JJ) = B
            GOTO 9
 
 2        CONTINUE
            CALL XLKT23
     I                 (ADRS,
     M                  Y,
     O                  A, T, DT, K, DK, B, DB, MA, DMA, MQT, DMQ)
            A2(JJ) = A
            T2(JJ) = T
            K2(JJ) = K
            B2(JJ) = B
            MA2(JJ) = MA
            MQ2(JJ) = MQT
            GOTO 9
 
 9        CONTINUE
 
 100    CONTINUE
 
C       MAKE EXTERIOR NODE VALUES ON BRANCHES SAME AS THE INTERIOR
C       NODE SYSTEM VALUES
 
        YE2(BRPT(5,II)) = Y2(FN)
        TE2(BRPT(5,II)) = T2(FN)
        AE2(BRPT(5,II)) = A2(FN)
        QE2(BRPT(5,II)) = Q2(FN)
 
        YE2(BRPT(6,II)) = Y2(LN)
        TE2(BRPT(6,II)) = T2(LN)
        AE2(BRPT(6,II)) = A2(LN)
        QE2(BRPT(6,II)) = Q2(LN)
 
 200  CONTINUE
 
C     FIND VOLUMES IN RESERVOIRS
 
      DO 300 II=1,NEX
        IF(EXNODT(3,II).EQ.-1) THEN
 
          ADRS = EXNODT(4,II)
          ARG = YE2(II)
          CALL LKTAB
     I              (ADRS, ARG, 0,
     O               VOL, NTAB, PDV)
          TE2(II) = PDV
          AE2(II) = -VOL
        ENDIF
 
 300  CONTINUE
 
      RETURN
      END
C
C
C
      SUBROUTINE   CSMAT
     I                  (DT, DTDY, WT, NBN, NBRA, NEX, BRPT, HSLOT, EPT,
     I                   DTMIN_OUT, START_EQ, END_EQ, JTIME, PRTIME,
     I                   KOUNT, QEPS,
     M                   EMC, EXNODT,
     O                   RNORM, MXRES, LMXRES, ERRP, ERRQ, BERRQ, NERRQ,
     O                   NERRP, BERRP)
 
C     + + + PURPOSE + + +
C     Compute and solve the network matrix.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 

C     + + + DUMMY ARGUMENTS + + +
      INTEGER BERRP, BERRQ, LMXRES, NBN, NBRA, NERRP, NERRQ, NEX, EPT,
     A        START_EQ, END_EQ, KOUNT
      INTEGER BRPT(8,NBRA), EMC(MREMC), EXNODT(9,NEX)
      REAL ERRP, ERRQ, HSLOT, MXRES, RNORM, WT, DTMIN_OUT, QEPS
      REAL*8 DT, DTDY, JTIME, PRTIME
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     DT     - time step in seconds
C     WT     - weight factor for approximating time integrals
C     NBN    - total number on nodes on branches in the model
C     NBRA   - number of branches in the model
C     NEX    - number of exterior nodes in the model
C     BRPT   - branch pointer table.  Values for each branch are:
C              ROW       Meaning
C              1         upstream user node number
C              2         downstream user node number
C              3         pointer into branch vector for upstream node
C              4         pointer into branch vector for downstream node
C              5         upstream exterior node number
C              6         downstream exterior node number
C              7         pointer to address in EMC for the branch
C              8         number of unknowns at a node for the branch
C     HSLOT  - height of bottom slot.  Currently 0.0 always
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
C     RNORM  - sum of squares of the residuals
C     MXRES  - maximum value of the residuals in the matrix
C     LMXRES - location of the maximum residual
C     ERRP   - current maximum relative change in surcharge storage
C     ERRQ   - maximum value of the ratio of lateral inflow to the
C               average flow in the element
C     BERRQ  - records the branch number(internal) that has the
C               greatest value of the ratio of lateral inflow
C               to average flow in an element
C     NERRQ  - node at which maximum relative lateral inflow occurs
C     NERRP  - node at which maximum correction to surcharge storage
C               occurs
C     BERRP  - records the branch number(internal) that has the
C               greatest absolute value of the change in surcharge
C               storage relative to the storage in the storm sewer
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'matcom.cmn'
      INCLUDE 'xscom.cmn'
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL PROFAC, PROSLV, SETEXT
C***********************************************************************
      CALL SETEXT
     I     (DT, DTDY, WT, NBN, NBRA, NEX, BRPT, HSLOT, EPT, QEPS, jtime,
     M            EMC, EXNODT,
     O            RNORM, MXRES, LMXRES, ERRP, ERRQ, BERRQ, NERRQ, NERRP,
     O            BERRP)
 
 
C     Save copy of matrix and rhs for later dumping
      IF(START_EQ.LE.END_EQ) then
        if(JTIME.GE.PRTIME) THEN
          CALL SAVEMAT(NUMEQ, C(NUMEQ), PDAVEC, RHS, 
     O               PDAVEC2, RHS2)
        endif
      ENDIF

 
C      WRITE(STDOUT,*) ' PROFILE MATRIX AND RHS BEFORE SOLUTION'
C       CALL OUTPRO(STDOUT)
 
C      WRITE(STDOUT,*) ' DIAGONAL ELEMENTS IN MATRIX'
C      DO 100 I=1,NUMEQ
C        WRITE(STDOUT,'(I5,F10.3)') I,PDAVEC(C(I))
C100   CONTINUE
C      WRITE(STDOUT,*) ' '
 
C     SOLVE  MATRIX
 
 
      CALL PROFAC
     I           (STDOUT)
 
      CALL PROSLV
     I           (NUMEQ, PDAVEC, C, R,
     M            RHS)
 

      IF(START_EQ.LE.END_EQ) then
        if( JTIME.GE.PRTIME) THEN
          CALL DMPEQS(STDOUT, START_EQ, END_EQ, KOUNT, JTIME)
        endif
      ENDIF

C      WRITE(STDOUT,*) ' SOLUTION VECTOR'
C      DO 100 I=1,NUMEQ
C        WRITE(STDOUT,'(1X,1PE11.3)') RHS(I)
C100   CONTINUE
 
C      WRITE(STDOUT,*) ' PROFILE MATRIX AND RHS AFTER SOLUTION'
C      CALL OUTPRO(STDOUT)
 
      RETURN
      END
C
C
C
      SUBROUTINE SAVEMAT(N, M, PDAVEC, RHS, 
     O             PDAVEC2, RHS2)

C     Save copies of matrix and rhs before solution to use in a 
C     common printout.

      IMPLICIT NONE
      INTEGER N, M
      REAL*8 PDAVEC(M), PDAVEC2(M), RHS(N), RHS2(N)
C***********************************************************************
      RHS2 = RHS
      PDAVEC2 = PDAVEC
      RETURN
      END

C
C
C
      SUBROUTINE   ESTBN
     I                  (DT, NBN, MRE)
 
C     + + + PURPOSE + + +
C     Estimate values of the dependent variables for the first
C     iteration of each time step for nodes on branches.

      IMPLICIT NONE
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER NBN
      REAL MRE
      REAL*8 DT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     DT     - time step in seconds
C     NBN    - total number on nodes on branches in the model
C     MRE    - maximum relative change permitted when estimating values
C               for branch nodes
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I
      REAL DELY, MXDELY, Y
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS, SIGN
C***********************************************************************
      DO 300 I=1,NBN
        Q2(I) = Q1(I) + MQ(I)*DT
 
        Y = Y1(I)
        MXDELY = MRE*Y
        DELY = MY(I)*DT
        IF(ABS(DELY).GT.MXDELY) DELY = SIGN(MXDELY,DELY)
        Y2(I) = Y + DELY
        IF(Y2(I).GT.BNMAXY(I)) THEN
          Y2(I) = 0.5*(Y + BNMAXY(I))
        ENDIF
 300  CONTINUE
 
      RETURN
      END
C
C
C
      SUBROUTINE   ESTEN
     I                  (DT, NEX, MRE, EXNODT)
 
C     + + + PURPOSE + + +
C     Estimate values of the dependent variables for the first
C     iteration of each time step for exterior nodes.
      IMPLICIT NONE
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER NEX
      INTEGER EXNODT(9,NEX)
      REAL MRE
      REAL*8 DT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     DT     - time step in seconds
C     NEX    - number of exterior nodes in the model
C     MRE    - maximum relative change permitted when estimating values
C               for branch nodes
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
      INCLUDE 'arsize.prm'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'enothr.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, J
      REAL DELY, MXDELY, Y
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS, SIGN
C***********************************************************************
      DO 450 I=1,NEX
        IF(EXNODT(3,I).LE.0) GOTO 410
          J = EXNODT(2,I)
C         NODE ON A BRANCH
          QE2(I) = Q2(J)
          YE2(I) = Y2(J)
          TE2(I) = T2(J)
          GOTO 420
 410    CONTINUE
 
C         FREE NODE-DEFINE ONLY DEPTH AND FLOW
 
          Y = YE1(I)
          MXDELY = MRE*Y
          DELY = MYE(I)*DT
          IF(ABS(DELY).GT.MXDELY) DELY = SIGN(MXDELY,DELY)
          YE2(I) = Y +DELY
          IF(YE2(I).GT.ENMAXY(I)) THEN
            YE2(I) = 0.5*(Y + ENMAXY(I))
          ENDIF
          QE2(I) = QE1(I) +MQE(I)*DT
 420    CONTINUE
 450  CONTINUE
 
      RETURN
      END
C
C
C
      SUBROUTINE   FMXMN
     I                  (NBN, NEX, NBRA, EXNODT, BRPT, JTIME)
 
C     + + + PURPOSE + + +
C     Find maximum and minimum flows and elevations. At this point
C     the set 1 variables have been reset to values of set 2 with
C     small flow clipping.  Use set 1 in the flow tests.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER NBN, NBRA, NEX
      INTEGER BRPT(8,NBRA), EXNODT(9,NEX)
      REAL*8 JTIME
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NBN    - total number on nodes on branches in the model
C     NEX    - number of exterior nodes in the model
C     NBRA   - number of branches in the model
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
C     BRPT   - branch pointer table.  Values for each branch are:
C              ROW       Meaning
C              1         upstream user node number
C              2         downstream user node number
C              3         pointer into branch vector for upstream node
C              4         pointer into branch vector for downstream node
C              5         upstream exterior node number
C              6         downstream exterior node number
C              7         pointer to address in EMC for the branch
C              8         number of unknowns at a node for the branch
C     JTIME  - current modified julian time in the model
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'misccon.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnrslt.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'enrslt.cmn'
      INCLUDE 'bnpond.cmn'
      INCLUDE 'stdun.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER DNN, I, IBRA, IE, IS, J, UNN
      REAL SUM, TEMP, V
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS, MAX
C***********************************************************************
      DO 242 IBRA=1,NBRA
        IS = BRPT(3,IBRA)
        IE = BRPT(4,IBRA)
        UNN = BRPT(5,IBRA)
        DNN = BRPT(6,IBRA)

C       Do upstream exterior node
C       Find maximum flow
        IF(Q1(IS).GT.QMAX(IS)) THEN
          QMAX(IS) = Q1(IS)
          TQMAX(IS) = JTIME
        ENDIF
 
C       Find maximum absolute value of velocity
        V = ABS(Q1(IS)/A2(IS))
        VMAX(IS) = MAX(V, VMAX(IS))
 
C     Find minimum flow
        IF(Q1(IS).LT.QMIN(IS)) THEN
          QMIN(IS) = Q1(IS)
          TQMIN(IS) = JTIME
        ENDIF
 
C       Find maximum elevation
        TEMP = Y1(IS) + ZVEC(IS)
        IF(TEMP.GT.ZMAX(IS)) THEN
          ZMAX(IS) = TEMP
          TZMAX(IS) = JTIME
C         Check  for associated values
          IF(TOSTORE(UNN).GT.0) THEN
C           They exist!  Store values
            ZSTORE(TOSTORE(UNN)) = ZE(OTHERNODE(UNN)) 
     A                               + YE1(OTHERNODE(UNN))
            QSTORE(TOSTORE(UNN)) = QE1(FLOWNODE(UNN))
          ENDIF
        ENDIF

C       Do downstream exterior node
C       Find maximum flow
        IF(Q1(IE).GT.QMAX(IE)) THEN
          QMAX(IE) = Q1(IE)
          TQMAX(IE) = JTIME
        ENDIF
 
C       Find maximum absolute value of velocity
        V = ABS(Q1(IE)/A2(IE))
        VMAX(IE) = MAX(V, VMAX(IE))
 
C     Find minimum flow
        IF(Q1(IE).LT.QMIN(IE)) THEN
          QMIN(IE) = Q1(IE)
          TQMIN(IE) = JTIME
        ENDIF
 
C       Find maximum elevation
        TEMP = Y1(IE) + ZVEC(IE)
        IF(TEMP.GT.ZMAX(IE)) THEN
          ZMAX(IE) = TEMP
          TZMAX(IE) = JTIME
C         Check node for associated values

          IF(TOSTORE(DNN).GT.0) THEN
C           They exist!  Store values
            ZSTORE(TOSTORE(DNN)) = ZE(OTHERNODE(DNN)) 
     A                               + YE1(OTHERNODE(DNN))
            QSTORE(TOSTORE(DNN)) = QE1(FLOWNODE(DNN))
          ENDIF
        ENDIF


        DO 240 I=IS+1,IE-1
C         Find maximum flow                       
          IF(Q1(I).GT.QMAX(I)) THEN               
            QMAX(I) = Q1(I)                       
            TQMAX(I) = JTIME                      
          ENDIF                                   
                                                  
C         Find maximum absolute value of velocity 
          V = ABS(Q1(I)/A2(I))                    
          VMAX(I) = MAX(V, VMAX(I))               
                                                  
C         Find minimum flow
          IF(Q1(I).LT.QMIN(I)) THEN               
            QMIN(I) = Q1(I)                       
            TQMIN(I) = JTIME                      
          ENDIF                                   
                                                  
C         Find maximum elevation
          TEMP = Y1(I) + ZVEC(I)                  
          IF(TEMP.GT.ZMAX(I)) THEN                
            ZMAX(I) = TEMP                        
            TZMAX(I) = JTIME                      
          ENDIF                                   
 240    CONTINUE                                  
 242  CONTINUE                                                  

C     Find maxima for free nodes
                                              
      DO 245 I=1,NEX                          
        IF(EXNODT(3,I).LE.0) THEN            
          IF(QE1(I).GT.FNQMAX(I)) THEN      
            FNQMAX(I) = QE1(I)              
            FTQMAX(I) = JTIME               
          ENDIF                             
          IF(QE1(I).LT.FNQMIN(I)) THEN      
            FNQMIN(I) = QE1(I)              
            FTQMIN(I) = JTIME               
          ENDIF                             
                                            
          TEMP = YE2(I)+ZE(I)               
          IF(TEMP.GT.FNZMAX(I)) THEN        
            FNZMAX(I) = TEMP                
            FTZMAX(I) = JTIME 
C           Check  for associated values
            IF(TOSTORE(I).GT.0) THEN
C             They exist!  Store values
              ZSTORE(TOSTORE(I)) = ZE(OTHERNODE(I)) + YE1(OTHERNODE(I))
              QSTORE(TOSTORE(I)) = QE1(FLOWNODE(I))
          ENDIF

              
           ENDIF                             
        ENDIF
 245  CONTINUE                                
 
C     Find the branch ponding volume and its maximum if ponding is
C     possible
 
      IF(PNDFLG.EQ.1) THEN
 
        DO 500 I=1,NBRA
          SUM = 0.0
          DO 400 J=BRPT(3,I),BRPT(4,I)
            SUM = SUM + POND2(J)
 400      CONTINUE
          BPOND(I) = SUM
          IF(SUM.GT.BPMAX(I)) BPMAX(I) = SUM
 500    CONTINUE
      ENDIF
 
      RETURN
      END
C
C
C
      SUBROUTINE   MAKCOR
     I                   (NEX, NBRA, NBN, STDOUT, EXNODT, BRPT, LAMBDA,
     I                    QCHOP)
 
C     + + + PURPOSE + + +
C     Make corrections such that no area or depth will be negative.
C     Decrease in depth is limited so that negative depth
C     does not result.
      IMPLICIT NONE
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, NBN, NBRA, NEX
      INTEGER BRPT(8,NBRA), EXNODT(9,NEX)
      REAL LAMBDA, QCHOP
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NEX    - number of exterior nodes in the model
C     NBRA   - number of branches in the model
C     NBN    - total number on nodes on branches in the model
C     STDOUT   - Fortran unit number for user output and messages
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
C     BRPT   - branch pointer table.  Values for each branch are:
C              ROW       Meaning
C              1         upstream user node number
C              2         downstream user node number
C              3         pointer into branch vector for upstream node
C              4         pointer into branch vector for downstream node
C              5         upstream exterior node number
C              6         downstream exterior node number
C              7         pointer to address in EMC for the branch
C              8         number of unknowns at a node for the branch
C     LAMBDA - factor that defines the partial Newton correction
C     QCHOP  - chopping value for output of flow
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'enelem.cmn'
      INCLUDE 'enothr.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
 
C     + + + SAVED VALUES + + +
      REAL MRD
      SAVE MRD
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, IBRA, NODE
      REAL DY, DYT, FRAC
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER GETUSB
      CHARACTER GETUSN*5
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL FBRND, GETUSB, GETUSN
 
C     + + + DATA INITIALIZATIONS + + +
      DATA MRD/0.5/
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(' VALUE BELOW MINIMUM AT EXT. NODE=',A5,' VALUE=',F10.4,
     A       ' MINIMUM=',F10.4)
 52   FORMAT(' NEGATIVE DEPTH AT:',I4,':',I6,' DEPTH=',F10.4)
 56   FORMAT(' *WRN:37* TABLE OVERFLOW AT EXT. NODE=',A5,' ARGUMENT=',
     A        F10.4)
 58   FORMAT(' *WRN:38* TABLE OVERFLOW AT:',I4,':',I6,' ARGUMENT=',
     A        F10.2)
C***********************************************************************
      FRAC = LAMBDA
 
      DO 200 I=1,NEX
C       DO ONLY FREE NODES
        IF(EXNODT(3,I).LE.0) THEN
          DY = ENCORY(I)
          DYT = MRD*YE3(I)
          IF(ABS(DY).GT.DYT) THEN
            DY = SIGN(DYT, DY)
          ENDIF
          YE2(I) = YE3(I) + FRAC*DY
          IF(YE2(I).LT.ENMINY(I)) THEN
            WRITE(STDOUT,50) GETUSN(I), YE2(I), ENMINY(I)
            YE2(I) = 0.5*(YE3(I) + ENMINY(I))
          ELSEIF(YE2(I).GT.ENMAXY(I)) THEN
            WRITE(STDOUT,56) GETUSN(I), YE2(I)
            YE2(I) = 0.5*(YE3(I) + ENMAXY(I))
          ENDIF
 
          QE2(I) = QE3(I) + FRAC*ENCORQ(I)
          IF(ABS(QE2(I)).LE.QCHOP) QE2(I) = 0.0
        ENDIF
 200  CONTINUE
 
      DO 300 I=1,NBN
 
        DY = BNCORY(I)
C       Limit the relative change in depth
        DYT = MRD*Y3(I)
        IF(ABS(DY).GT.DYT) THEN
          DY = SIGN(DYT, DY)
        ENDIF
 
 
        Y2(I) = Y3(I) + FRAC*DY
 
        IF(Y2(I).LE.0.0) THEN
          Y2(I) = 0.95*Y3(I)
          CALL FBRND
     I              (I, NBRA, BRPT, STDOUT,
     O               IBRA, NODE)
          WRITE(STDOUT,52) GETUSB(IBRA), NODE, Y3(I)
        ELSEIF(Y2(I).GT.BNMAXY(I)) THEN
          CALL FBRND
     I              (I, NBRA, BRPT, STDOUT,
     O               IBRA, NODE)
          WRITE(STDOUT,58) GETUSB(IBRA), NODE, Y2(I)
          Y2(I) = 0.5*(Y3(I) + BNMAXY(I))
        ENDIF
        Q2(I) = Q3(I) + FRAC*BNCORQ(I)
 
 300  CONTINUE
 
      RETURN
      END
C
C
C
      SUBROUTINE   RPLSET
     I                   (DT, FAC, NBN, NEX)
 
C     + + + PURPOSE + + +
C     Replace set 1 with set 2 values for next time step. Also
C     compute the slopes for estimation at the same time.
      IMPLICIT NONE
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER NBN, NEX
      REAL FAC
      REAL*8 DT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     DT     - time step in seconds
C     FAC    - factor controlling the extrapolation vectors
C     NBN    - total number on nodes on branches in the model
C     NEX    - number of exterior nodes in the model
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'bnpond.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I
C***********************************************************************
C     I) INTERIOR NODES
 
      DO 210 I=1,NBN
        MY(I) = FAC*(Y2(I)-Y1(I))/DT
        A1(I) = A2(I)
        MQ(I) = FAC*(Q2(I)-Q1(I))/DT
        Q1(I) = Q2(I)
        T1(I) = T2(I)
        Y1(I) = Y2(I)
        K1(I) = K2(I)
        B1(I) = B2(I)
        POND1(I) = POND2(I)
        MA1(I) = MA2(I)
        MQ1(I) = MQ2(I)
 210  CONTINUE
 
C     II) EXTERIOR NODES
 
      DO 220 I=1,NEX
        MQE(I) = FAC*(QE2(I)-QE1(I))/DT
        QE1(I) = QE2(I)
        MYE(I) = FAC*(YE2(I)-YE1(I))/DT
        YE1(I) = YE2(I)
        TE1(I) = TE2(I)
        AE1(I) = AE2(I)
 220  CONTINUE
 
      RETURN
      END
C
C
C
      SUBROUTINE   RSTNZD
     I                   (NBRA, BRPT)
 
C     + + + PURPOSE + + +
C     Reset the weight for the integrals along the channel. The value is
C     set by the current depth.   The weight as computed assumes that
C     the flow is downstream.  The weights are set at the start of
C     the time step and held constant throughout the time step.
C     The weight applies to the new time point.
      IMPLICIT NONE
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER NBRA
      INTEGER BRPT(8,NBRA)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NBRA   - number of branches in the model
C     BRPT   - branch pointer table.  Values for each branch are:
C              ROW       Meaning
C              1         upstream user node number
C              2         downstream user node number
C              3         pointer into branch vector for upstream node
C              4         pointer into branch vector for downstream node
C              5         upstream exterior node number
C              6         downstream exterior node number
C              7         pointer to address in EMC for the branch
C              8         number of unknowns at a node for the branch
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'nzdcom.cmn'
      INCLUDE 'bnothr.cmn'
 
C     + + + LOCAL PARAMETERS + + +
      REAL WMAX
      PARAMETER(WMAX=0.99)
 
C     + + + LOCAL VARIABLES + + +
      INTEGER FN, I, J, LN
      REAL P, YHAF, YM, YONE
 
C     + + + INTRINSICS + + +
      INTRINSIC MIN
C***********************************************************************
      DO 110 I=1,NBRA
        IF(GEQVEC(I).EQ.2.OR.GEQVEC(I).EQ.4) THEN
          FN = BRPT(3,I) + 1
          LN = BRPT(4,I)
          YONE = YATONE(I)
          YHAF = YATHAF(I)
          DO 100 J=FN,LN
 
C           RESET THE WEIGHT FOR THE INITIAL TIME LINE.
            WXVEC1(J) = WXVEC2(J)
 
C           DEFINE THE WEIGHT FACTOR FOR EACH ELEMENT AT THE NEW TIME
C           LINE.  THE WEIGHT IS SET AT THE START OF A TIME STEP AND
C           HELD CONSTANT THROUGH ALL ITERATIONS OF THE TIME STEP.
C           USE MINIMUM DEPTH IN THE ELEMENT TO DEFINE THE WEIGHT
C           BECAUSE THE WEIGHT IS FOR THE ELEMENT AND NOT FOR A NODE.
 
            YM = MIN(Y1(J-1), Y1(J))
            IF(YM.GE.YHAF) THEN
              WXVEC2(J) = .5
            ELSEIF(YM.LE.YONE) THEN
              WXVEC2(J) = WMAX
            ELSE
C             INTERPOLATION REQUIRED
              P = (YM - YONE)/(YHAF - YONE)
              IF(NZDTYP(I).EQ.0) THEN
C               LINEAR
                WXVEC2(J) = WMAX +(.5 - WMAX)*P
              ELSE
C               CUBIC HERMITE WITH ZERO DERIVATIVES AT END POINTS
                WXVEC2(J) = WMAX + (WMAX - .5)*(P*P*(2*P - 3))
              ENDIF
            ENDIF
 100      CONTINUE
        ENDIF
 110  CONTINUE
 
      RETURN
      END
C
C
C
      SUBROUTINE   RSTSTA
     I                   (MODE, STDOUT,
     M                    EMC)
 
C     + + + PURPOSE + + +
C     Reset the state variables in emc for code 5 & 6 based on MODE:
C       MODE = 1     current  <-- previous
C       MODE <> 1    previous <-- current
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, MODE
      INTEGER EMC(MREMC)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     MODE   - mode selection for resetting state
C     STDOUT   - Fortran unit number for user output and messages
C     EMC    - vector containing coded form of the Matrix Control Input
 
C     + + + LOCAL VARIABLES + + +
      INTEGER CODE, J
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
C***********************************************************************
C     SEARCH EMC FOR THE PROPER CODES
 
      J = EMC(1)
 10   CONTINUE
      CODE = EMC(J)
      IF(CODE.EQ.-1) RETURN
      GOTO(2000,2,2000,2000,5,6,2000,2000,2000,2000, 2000, 2000,
     A     2000, 2000, 2000),CODE
        WRITE(STDOUT,*) ' *BUG:25* INVALID EMC CODE IN RSTSTA. CODE='
     A                ,CODE
        STOP 'Abnormal stop: errors found.'
 
 2    CONTINUE
      J = J+EMC(J+1)
      GOTO 2000
 5    CONTINUE
 
 
        GOTO(100, 200, 300, 400, 500, 600, 700, 800, 900), EMC(J+1)
 
          WRITE(STDOUT,*) ' *BUG:38* INVALID CODE 5 TYPE IN RSTSTA.',
     A                  ' TYPE=',EMC(J+1)
          STOP 'Abnormal stop: errors found.'
 
 100    CONTINUE
 
C         EXPANSION-CONTRACTION
          IF(MODE.EQ.1) THEN
             EMC(J+8) = EMC(J+12)
          ELSE
             EMC(J+12) = EMC(J+8)
          ENDIF
          J = J + CD5TY1
          GOTO 2000
 200    CONTINUE
          J = J + CD5TY2
          GOTO 2000
 300    CONTINUE
          J = J + CD5TY3
          GOTO 2000
 400    CONTINUE
          J = J + CD5TY4
          GOTO 2000
 500    CONTINUE
C         ABRUPT EXPANSION
          IF(MODE.EQ.1) THEN
            EMC(J+6) = EMC(J+7)
          ELSE
            EMC(J+7) = EMC(J+6)
          ENDIF
          J = J + CD5TY5
          GOTO 2000
 600    CONTINUE
          J = J + 1 + ABS(EMC(J+6))*CD5TY6
          GOTO 2000
 700    CONTINUE
          J = J + CD5TY7
          GOTO 2000
 800    CONTINUE
          J = J + CD5TY8
          GOTO 2000
 900    CONTINUE
          J = J + CD5TY9
          GOTO 2000
 
 6    CONTINUE
         IF(EMC(J+1).EQ.2) THEN
 
C           FORCED ELEVATION WITH POSSIBLE CRITICAL DEPTH
            IF(MODE.EQ.1) THEN
               EMC(J+5) = EMC(J+7)
            ELSE
               EMC(J+7) = EMC(J+5)
            ENDIF
         ENDIF
         GOTO 2000
 2000    CONTINUE
         J = J + EMC(CODE+1)
         GOTO 10
      END
C
C
C
      SUBROUTINE   SETSTA
     I                   (STDOUT, NEX, GRAV, EXNODT, EPT,
     M                    EMC)
 
C     + + + PURPOSE + + +
C     Set state values in network-matrix control(EMC) for
C     code 5 type 1; code 5 type 5; and code 6, type 2 entries
C     based on state given by the steady flow analysis.
 
      IMPLICIT NONE

C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EPT, STDOUT, NEX
      INTEGER EMC(EPT), EXNODT(9,NEX)
      REAL GRAV
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     NEX    - number of exterior nodes in the model
C     GRAV   - value of acceleration due to gravity
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
C     EMC    - vector containing coded form of the Matrix Control Input
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'bnelem.cmn'
      INCLUDE 'enelem.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADRS, CODE, DNN, FNODE, IDUM, J, NODE, NTAB, SYSGN, TYPE,
     A        UNN
      REAL AC, BC, CON, DBC, DCON, DTC, PCV, QC, QCSQR, R, RDUM, TC, Y
 
C     + + + EQUIVALENCES + + +
      EQUIVALENCE (RDUM,IDUM)
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LKTAB, XLKT20
C***********************************************************************
C     SEARCH THROUGH EMC FOR THE PROPER CODES
 
      J = EMC(1)
 10     CONTINUE
        CODE = EMC(J)
        IF(CODE.EQ.-1) RETURN
        GOTO(2000,2,2000,2000,5,6,2000,2000,2000,2000, 2000, 2000,
     A        2000, 2000, 2000),CODE
          WRITE(STDOUT,*) ' *BUG:18* INVALID EMC CODE IN SETSTA. CODE=',
     A               CODE
          STOP 'Abnormal stop: errors found.'
 
 2        CONTINUE
            J = J+EMC(J+1)
            GOTO 2000
 
 5        CONTINUE
            TYPE = EMC(J+1)
            GOTO(100, 200, 300, 400, 500, 600, 700, 800, 900), TYPE
 
             WRITE(STDOUT,*) ' *BUG:37* INVALID CODE 5 TYPE IN SETSTA.',
     A           ' TYPE=',TYPE
             STOP 'Abnormal stop: errors found.'
 
 100        CONTINUE
              ADRS = EMC(J+7)
              SYSGN = EMC(J+5)
              FNODE = EMC(J+4)
              UNN = EMC(J+2)
              DNN = EMC(J+3)
              IDUM = EMC(J+11)
              Y = YE2(UNN) + ZE(UNN)
              IF(QE2(FNODE)*SYSGN.LT.0) Y = YE2(DNN) + ZE(DNN)
              Y = Y-RDUM
              IF(Y.GT.0.0) THEN
                CALL XLKT20
     I                     (ADRS,
     M                      Y,
     O                      AC, TC, DTC, CON, DCON, BC, DBC)
                QCSQR = GRAV*AC**3/TC
                R = QE2(FNODE)**2/QCSQR
                EMC(J+8) = -1
                IF(R.GT.0.98.AND.R.LT.1.02) EMC(J+8) = 1
              ELSE
                EMC(J+8) = -1
              ENDIF
C             SET PREVIOUS STATE
              EMC(J+12) = EMC(J+8)
 
              J = J + CD5TY1
              GOTO 2000
 200        CONTINUE
              J = J + CD5TY2
              GOTO 2000
 300        CONTINUE
              J = J + CD5TY3
              GOTO 2000
 400        CONTINUE
              J = J + CD5TY4
              GOTO 2000
 500        CONTINUE
C             LOOKUP CRITICAL FLOW AT THE UPSTREAM DEPTH
              CALL LKTAB
     I                  (EMC(J+8), YE2(EMC(J+2)), 1,
     O                   QC, NTAB, PCV)
              IF(QE2(EMC(J+2)).GE.QC) THEN
                EMC(J+6) = 1
              ELSE
                EMC(J+6) = -1
              ENDIF
              EMC(J+7) = EMC(J+6)
              J = J + CD5TY5
              GOTO 2000
 600        CONTINUE
              J = J + 1 + ABS(EMC(J+6))*CD5TY6
              GOTO 2000
 700        CONTINUE
              J = J + CD5TY7
              GOTO 2000
 800        CONTINUE
              J = J + CD5TY8
              GOTO 2000
 900        CONTINUE
              J = J + CD5TY9
              GOTO 2000
 
 6        CONTINUE
            IF(EMC(J+1).NE.2) GOTO 2000
              NODE = EMC(J+2)
              IF(EXNODT(2,NODE).GT.0) THEN
                QCSQR = GRAV*AE2(NODE)**3/T2(EXNODT(2,NODE))
                R = QE2(NODE)**2/QCSQR
                EMC(J+5) = -1
                IF(R.GT.0.98.AND.R.LT.1.02) EMC(J+5) = 1
C               SET PREVIOUS STATE
                EMC(J+7) = EMC(J+5)
              ELSE
C               Free node so that critical flow cannot exist.  Set the 
C               state values.
                EMC(J+5) = 1
                EMC(J+7) = 1
              ENDIF
              GOTO 2000
 
 2000     CONTINUE
            J = J+EMC(CODE+1)
            GOTO 10
      END
