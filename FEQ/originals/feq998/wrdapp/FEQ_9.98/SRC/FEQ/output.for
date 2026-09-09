C Routines used in creating and checking output files of various kinds        

C
C
C
      SUBROUTINE   NON_CONV_SUMMARY(STDOUT, NEX, NBN, NBRA, BRPT)

C     Output a summary of the final location appearing when
C     convergence fails. 

      IMPLICIT NONE
      INTEGER NBRA, NEX, NBN, STDOUT
      INTEGER BRPT(8,NBRA)


C     Common blocks

      INCLUDE 'arsize.prm'
      INCLUDE 'enothr.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'inusnb.cmn'

C     Local 

      INTEGER I, J, KNT, COUNT, FNODE, LNODE, SNODE, USER_NODE

      REAL FKNT, FRACTION
C     ******************************FORMATS*****************************
50    FORMAT(/,' Analysis of Non-Convergence Events',/,'  Exterior',
     A  ' nodes appearing as last location of maximum relative',
     B  ' correction.',/,'   Node Count Fraction')
52    FORMAT(' ',1X,A5,I6,F9.2)      
54    FORMAT(/,'  Branch',
     A  ' nodes appearing as last location of maximum relative',
     B  ' correction.',/,'  Branch   Node Count Fraction')
56    FORMAT('  ',I6,I7,I6,F9.2)      
C***********************************************************************
      KNT = 0
      DO 100 I=1,NEX
        KNT = KNT + NON_CONV_ENODE(I)
100   CONTINUE

      DO 105 I=1,NBN
        KNT = KNT + NON_CONV_BNODE(I)
105   CONTINUE

      FKNT = REAL(KNT)

      IF(KNT.GT.0) THEN
        WRITE(STDOUT,50)
        DO 110 I=1,NEX
          COUNT = NON_CONV_ENODE(I)
          IF(COUNT.GT.0) THEN
            FRACTION = REAL(COUNT)/FKNT
            IF(FRACTION.GT.0.00) THEN
              WRITE(STDOUT,52) INENUS(I), COUNT, FRACTION
            ENDIF
          ENDIF
110     CONTINUE

        WRITE(STDOUT,54) 

        DO 120 I=1,NBRA
          FNODE = BRPT(3,I)
          LNODE = BRPT(4,I)
          SNODE = BRPT(1,I)
          DO 115 J=FNODE,LNODE
            COUNT = NON_CONV_BNODE(J)
            IF(COUNT.GT.0) THEN
              FRACTION = REAL(COUNT)/FKNT
              IF(FRACTION.GT.0.00) THEN
                USER_NODE = SNODE + J - FNODE
                WRITE(STDOUT,56) INBRUS(I), USER_NODE, COUNT, FRACTION
              ENDIF
            ENDIF
115       CONTINUE
120     CONTINUE
      ENDIF

      
      RETURN
      END


C
C
C
      SUBROUTINE   BWPUT
     I                  (BWFDSN, WT, NBRA, NBN, NEX, NBLK, OPBLK)
 
C     + + + PURPOSE + + +
C     Put current state of system into dataset given by BWFDSN.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER BWFDSN, NBLK, NBN, NBRA, NEX
      INTEGER OPBLK(MNBLK)
      REAL WT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     BWFDSN - unit number for the initial conditions file
C     WT     - weight factor for approximating time integrals
C     NBRA   - number of branches in the model
C     NBN    - total number on nodes on branches in the model
C     NEX    - number of exterior nodes in the model
C     NBLK   - number of operation blocks
C     OPBLK  - pointer into the function table storage(FTAB/ITAB) for
C               each operation block.
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnpond.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'ftable.cmn'
      INCLUDE 'tam.cmn'

C     + + + LOCAL VARIABLES + + +
      INTEGER I, IT
C***********************************************************************
C      SHIFT TO UNFORMATED I/O FOR PRODUCTION VERSION.
 
      WRITE(BWFDSN)  WT
      DO 100 I=1,NBN
        WRITE(BWFDSN) Q1(I), Y1(I), T1(I), A1(I), K1(I),B1(I), WXVEC(I),
     A    POND1(I), DXVEC(I), DZVEC(I), MY(I), MQ(I)
 100  CONTINUE
 
      DO 200 I=1,NEX
        WRITE(BWFDSN) QE1(I), YE1(I), AE1(I), MYE(I), MQE(I)
 200  CONTINUE
 
C     PROBLEM IN FORECASTING WITH WRITING EMC.  TRY TO GET BY WITHOUT
C     DOING SO.  RESETTING STATE SHOULD WORK
C      WRITE(BWFDSN) EMC
 
      DO 300 I=1,NBLK
        IT = OPBLK(I) + 1
        WRITE(BWFDSN) FTAB(IT), FTAB(IT+1)
 300  CONTINUE
 
      WRITE(BWFDSN) (BPOND(I), I=1,NBRA)
      
      IF(DLAY_KNT.GT.0) WRITE(BWFDSN) (DLAY_Q1(I),I=1,DLAY_KNT)

      DO 400  I=1,DTEN_KNT
        WRITE(BWFDSN) DTEN_S1(I), DTEN_Q1(I), DTEN_Q1P(I)
400   CONTINUE

      RETURN
      END
C
C
C
      SUBROUTINE   GET14
     I                  (NEX, EXNODT, ADR, NODE, ZTAB,
     O                   HDATUM, HEAD, TABN, QMX, HMAX, TABTYP)
 
      IMPLICIT NONE
C     + + + PURPOSE + + +
C     Get data items for checking extremes for 2-D tables of type 14.
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADR, NEX, NODE, TABN, TABTYP, ZTAB
      INTEGER EXNODT(9,NEX)
      REAL HDATUM, HEAD, HMAX, QMX
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NEX    - number of exterior nodes in the model
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
C     ADR    - address of the function table in FTAB/ITAB
C     NODE   - node number
C     ZTAB   - address of table giving variable datum level
C     HDATUM - datum for heads
C     HEAD   - maximum simulated head for this table
C     TABN   - table number
C     QMX    - maximum tabulated free flow in the table
C     HMAX   - maximum head tabulated in the table
C     TABTYP -  table type
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'bnrslt.cmn'
      INCLUDE 'enrslt.cmn'
      INCLUDE 'julian.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER IT, NTAB
      REAL PDV, TI
      REAL*8 JT
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LKTAB
C***********************************************************************
      TABN = ITAB(ADR+1)
      TABTYP = ITAB(ADR+2)
      QMX = FTAB(ADR+9)
      HMAX = FTAB(ADR+5)
      IT = EXNODT(3,NODE)
      IF(IT.LE.0) THEN
        HEAD = FNZMAX(NODE)
        JT = FTZMAX(NODE)
      ELSE
        IT = EXNODT(2,NODE)
        HEAD = ZMAX(IT)
        JT = TZMAX(IT)
      ENDIF
      IF(ZTAB.GT.0) THEN
        TI = 86400.*(JT - SJTIME)
        CALL LKTAB
     I            (ZTAB, TI, 1,
     O             HDATUM, NTAB, PDV)
      ENDIF
 
      HEAD = HEAD - HDATUM
 
      RETURN
      END
C
C
C
      SUBROUTINE   GET613
     I                   (NEX, EXNODT, ADR, NODE, ZTAB,
     O                    HDATUM, HEAD, TABN, HMAX, TABTYP)
 
C     + + + PURPOSE + + +
C     Get data items for checking extremes for 2-D tables of type 6
C     and 13.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADR, NEX, NODE, TABN, TABTYP, ZTAB
      INTEGER EXNODT(9,NEX)
      REAL HDATUM, HEAD, HMAX
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NEX    - number of exterior nodes in the model
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
C     ADR    - address of the function table in FTAB/ITAB
C     NODE   - node number
C     ZTAB   - address of table giving variable datum level
C     HDATUM - datum for heads
C     HEAD   - maximum simulated head for this table
C     TABN   - table number
C     HMAX   - maximum head tabulated in the table
C     TABTYP -  table type
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'bnrslt.cmn'
      INCLUDE 'enrslt.cmn'
      INCLUDE 'julian.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER IT, NTAB
      REAL PDV, TI
      REAL*8 JT
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LKTAB
C***********************************************************************
      TABN = ITAB(ADR+1)
      TABTYP = ITAB(ADR+2)
      HMAX = FTAB(ADR+9)
      IT = EXNODT(3,NODE)
      IF(IT.LE.0) THEN
        HEAD = FNZMAX(NODE)
        JT = FTZMAX(NODE)
      ELSE
        IT = EXNODT(2,NODE)
        HEAD = ZMAX(IT)
        JT = TZMAX(IT)
      ENDIF
      IF(ZTAB.GT.0) THEN
        TI = 86400.*(JT - SJTIME)
        CALL LKTAB
     I            (ZTAB, TI, 1,
     O             HDATUM, NTAB, PDV)
      ENDIF
 
      HEAD = HEAD - HDATUM
 
      RETURN
      END
C
C
C
      SUBROUTINE   MARSUM
     I                   (NROW, NCOL, MAXROW,
     M                    TABLE)
 
C     + + + PURPOSE + + +
C     Compute marginal sums for TABLE.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER MAXROW, NCOL, NROW
      REAL TABLE(MAXROW,*)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NROW   - number of rows in table
C     NCOL   - number of columns
C     MAXROW - declared number of rows in the table
C     TABLE  - table for which marginal sum is computed
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, J
      REAL SUM, SUM2
C***********************************************************************
C     FIND THE ROW SUMS
 
      DO 110 I=1,NROW
        SUM = 0.0
        DO 100 J=1,NCOL
          IF(TABLE(I,J).GT.0.0) THEN
C           Negative values NOT included in row sums. 
            SUM = SUM + TABLE(I,J)
          ENDIF
 100    CONTINUE
        TABLE(I,NCOL+1) = SUM
 110  CONTINUE
 
      SUM2 = 0.0
C     FIND COLUMN SUMS
 
      DO 130 J=1,NCOL
        SUM = 0.0
        DO 120 I=1,NROW
          SUM = SUM + TABLE(I,J)
 120    CONTINUE
        TABLE(NROW+1,J) = SUM
        IF(SUM.GT.0.0) THEN
          SUM2 = SUM2 + SUM
        ENDIF
 130  CONTINUE
 
      TABLE(NROW+1,NCOL+1) = SUM2
 
      RETURN
      END
C
C
C
      SUBROUTINE   OUTSP
     I                  (EXNODT, NEX, YR, MN, DY, HR, NOUT, UNIT, POUT,
     M                   QOUT, ZOUT, LKOUNT)
 
C     + + + PURPOSE + + +
C     Writes elevation and discharge at up to MNSOUT nodes.
C     Also writes selected gate settings.  Includes optional
C     output lines.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER DY, LKOUNT, NEX, MN, NOUT, UNIT, YR
      INTEGER EXNODT(9,NEX), POUT(NOUT)
      REAL HR
      CHARACTER QOUT(NOUT)*8, ZOUT(NOUT)*8
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     YR     - calendar year
C     MN     - number of month(1-12)
C     DY     - day in the month
C     HR     - hour of the day
C     NOUT   - number of special outputs
C     UNIT   - unit number
C     POUT   - pointer to the value to output
C     QOUT   - flow values to output in special output
C     ZOUT   - values of elevation to output
C     LKOUNT - number of lines on the current output page
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'misccon.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'namcom.cmn'
      INCLUDE 'gatcom.cmn'
      INCLUDE 'mhenry.cmn'
      INCLUDE 'spout.cmn'
 
C     + + + SAVED VALUES + + +
      CHARACTER SLGTYP(0:4)*8
      SAVE SLGTYP
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADR, I, J, OPTION, TABADR, LOOKUP_DONE
      CHARACTER CHR9*9
      REAL AMAIN, KMAIN, TMAIN, DTU, DCON, BU, DBU, 
     A     AFLOOD, QMAIN, QFLOOD, ATOTAL, TTOTAL, 
     B     KTOTAL, QTOTAL
 

C     + + + INTRINSICS + + +
      INTRINSIC ABS, IABS
 
 
      CHARACTER PUT8*8, ITEMS*16
C     + + + DATA INITIALIZATIONS + + +
      DATA SLGTYP/'    ZERO','      FO','      SO','      FW',
     A   '      SW'/, ITEMS/'  Flow    Elev  '/
 
C     + + + OUTPUT FORMATS + + +
 10   FORMAT(F8.1)
 11   FORMAT(' ',F10.6,45A8)
 12   FORMAT(' ',I4,'/',I2,'/',I2,45A8)
 13   FORMAT(F9.0)
15    FORMAT(' ',A10,45A8)
 20   FORMAT(F8.3)
 50   FORMAT(11X,45(1X,A7))
52    FORMAT(18X, 40(2X,2A7))
54    FORMAT('YEAR MN DY    HOUR',40A16)
56    FORMAT(I4,I3,I3,F8.4,40(A8,A8))
C***********************************************************************
C     WRITE THE HEADINGS IF NEEDED
 
      IF(LKOUNT.EQ.0) THEN
        IF(SPOUT_STYLE.EQ.2) THEN
          WRITE(UNIT,50) (SPHEAD(I,1), I=1,NOUT)
          WRITE(UNIT,50) (SPHEAD(I,2), I=1,NOUT)
          LKOUNT = 2
        ELSE
C         Single line style.
          WRITE(UNIT,52) (SPHEAD(I,1), SPHEAD(I,2), I=1,NOUT)
          WRITE(UNIT,54) (ITEMS, I=1,NOUT)
          LKOUNT = 2
        ENDIF
      ENDIF
 
C     SELECT THE VALUES
 
       DO 100 I=1,NOUT
         ADR = POUT(I)
         IF(ADR.GT.0) GOTO 90
C           EXTERIOR NODE
            ADR = IABS(ADR)
            IF(ADR.LT.10000) THEN
              IF(ABS(QE1(ADR)).LE.100000.0) THEN
                WRITE(QOUT(I),10) QE1(ADR)
              ELSE
                WRITE(CHR9,13) QE1(ADR)
                QOUT(I) = CHR9
              ENDIF
              WRITE(ZOUT(I),20) YE1(ADR) + ZE(ADR)
            ELSEIF(ADR.LT.20000) THEN
              ADR = ADR - 10000
             CALL VAR_DECIMAL(QPVEC(ADR),
     O                       QOUT(I))
C              WRITE(QOUT(I),10) QPVEC(ADR)
              ZOUT(I) = ' TBAFLW '
            ELSEIF(ADR.EQ.20000) THEN
C             MCHENRY SLUICE GATE
C             REPORT FLOW TYPE AND GATE OPENING.
              QOUT(I) = SLGTYP(TYPMCH)
              WRITE(ZOUT(I),20) HGMCH
            ELSE
C             Gates other than McHenry.   Get items from standard
C             locations set by subroutines called in SETEXT.
              ADR = ADR - 20000
              QOUT(I) = FCLASS(ADR)
              WRITE(ZOUT(I),20) GOPEN(ADR)
            ENDIF
            GOTO 100
 90      CONTINUE
         IF(ADR.LT.10000) THEN
            IF(ABS(Q1(ADR)).LT.100000.0) THEN
              WRITE(QOUT(I),10) Q1(ADR)
            ELSE
              WRITE(CHR9,13) Q1(ADR)
              QOUT(I) = CHR9
            ENDIF
            WRITE(ZOUT(I),20) Y1(ADR) + ZVEC(ADR)
         ELSE
           ADR = ADR - 10000
           CALL VAR_DECIMAL(QPVEC(ADR),
     O                    QOUT(I))
C           WRITE(QOUT(I),10) QPVEC(ADR)
           ZOUT(I) = ' TBAFLW '
         ENDIF
 100   CONTINUE

      IF(SPOUT_STYLE.EQ.2) THEN 
        WRITE(UNIT,12) YR, MN, DY, ZOUT
        WRITE(UNIT,11) HR, QOUT
      ELSEIF(SPOUT_STYLE.EQ.1) THEN
        WRITE(UNIT,56) YR, MN, DY, HR, (QOUT(I), ZOUT(I), I=1,NOUT)
      ENDIF

 
 
C     Process the optional lines of output.
      IF(SPOUT_KNT.GT.0) THEN
        DO 500 I=1,NOUT
          ADR = POUT(I)
          IF(ADR.GT.-10000.AND.ADR.LT.10000) THEN
C           This could be a node on a branch.
            IF(ADR.LT.0) THEN
C             This is an exterior node.  Check if it is on
C             a branch.
              ADR = ABS(ADR)
              IF(EXNODT(3,ADR).GT.0) THEN
C               Yes it is on a branch.  Get its branch-vector
C               address.
                ADR = EXNODT(2,ADR)
              ELSE
C               It is not on a branch or it is a special request.
C               Skip it.
                GOTO 500
              ENDIF
            ENDIF
 
            TABADR = SPOUT_MAIN_CHANNEL_TABLE(I)
            LOOKUP_DONE = 0
            IF(TABADR.GT.0) THEN
              IF(NEED_LOOKUP.EQ.1) THEN
                LOOKUP_DONE = 1
                CALL XLKT20
     I                (TABADR,
     M                 Y1(ADR),
     O                 AMAIN, TMAIN, DTU, KMAIN, DCON, BU, DBU)
                ATOTAL = A1(ADR)
                TTOTAL = T1(ADR)
                KTOTAL = K1(ADR)
                QTOTAL = Q1(ADR)
                IF(AMAIN.GT.ATOTAL) AMAIN = ATOTAL
                IF(TMAIN.GT.TTOTAL) TMAIN = TTOTAL
                IF(KMAIN.GT.KTOTAL) KMAIN = KTOTAL
              ENDIF
            ENDIF
 
            DO 300 J=1,SPOUT_KNT
              OPTION = SPOUT_ITEM_VALUE(SPOUT_ITEM(J))
C              SELECT CASE(OPTION)
 
C              CASE (TOTAL_AREA)
              IF(OPTION.EQ.TOTAL_AREA) THEN
                EXTRA_BUFFER(I,J) = PUT8(A1(ADR))
 
C              CASE (MAIN_CHANNEL_AREA)
              ELSEIF(OPTION.EQ.MAIN_CHANNEL_AREA) THEN

                IF(LOOKUP_DONE.EQ.1) THEN
                  EXTRA_BUFFER(I,J) = PUT8(AMAIN)
                ELSE
                  EXTRA_BUFFER(I,J) = ' '
                ENDIF
 
C              CASE (FLOOD_PLAIN_AREA)
              ELSEIF(OPTION.EQ.FLOOD_PLAIN_AREA) THEN
                IF(LOOKUP_DONE.EQ.1) THEN
                  EXTRA_BUFFER(I,J) = PUT8(ATOTAL - AMAIN)
                ELSE
                  EXTRA_BUFFER(I,J) = ' '
                ENDIF
 
C              CASE (MEAN_VELOCITY)
              ELSEIF(OPTION.EQ.MEAN_VELOCITY) THEN
                WRITE(EXTRA_BUFFER(I,J),'(F8.3)') Q1(ADR)/A1(ADR)
 
C              CASE (MAIN_CHANNEL_VELOCITY)
              ELSEIF(OPTION.EQ.MAIN_CHANNEL_VELOCITY) THEN
                IF(LOOKUP_DONE.EQ.1) THEN
                  QMAIN = QTOTAL*KMAIN/KTOTAL
                  WRITE(EXTRA_BUFFER(I,J),'(F8.3)') QMAIN/AMAIN
                ELSE
                  EXTRA_BUFFER(I,J) = ' '
                ENDIF
 
C              CASE (FLOOD_PLAIN_VELOCITY)
              ELSEIF(OPTION.EQ.FLOOD_PLAIN_VELOCITY) THEN
                IF(LOOKUP_DONE.EQ.1) THEN
                  AFLOOD = ATOTAL - AMAIN
                  QFLOOD = QTOTAL*(1.0 - KMAIN/KTOTAL)
                  IF(AFLOOD.GT.0.0) THEN
                    WRITE(EXTRA_BUFFER(I,J),'(F8.3)') QFLOOD/AFLOOD
                  ELSE
                    EXTRA_BUFFER(I,J) = ' '
                  ENDIF
                ELSE
                  EXTRA_BUFFER(I,J) = ' '
                ENDIF
 
C              CASE (FLOOD_PLAIN_FLOW)
              ELSEIF(OPTION.EQ.FLOOD_PLAIN_FLOW) THEN
                IF(LOOKUP_DONE.EQ.1) THEN
                  QFLOOD = QTOTAL*(1.0 - KMAIN/KTOTAL)
                  EXTRA_BUFFER(I,J) = PUT8(QFLOOD)
                ELSE
                  EXTRA_BUFFER(I,J) = ' '
                ENDIF
 
C              CASE (MAIN_CHANNEL_FLOW)
              ELSEIF(OPTION.EQ.MAIN_CHANNEL_FLOW) THEN
                IF(LOOKUP_DONE.EQ.1) THEN
                  QMAIN = QTOTAL*KMAIN/KTOTAL
                  EXTRA_BUFFER(I,J) = PUT8(QMAIN)
                ELSE
                  EXTRA_BUFFER(I,J) = ' '
                ENDIF
 
C              END SELECT
              ENDIF
 
300         CONTINUE
          ENDIF
500     CONTINUE
 
C       Output the extra lines.  All are complete.
        DO 600 J=1,SPOUT_KNT
          WRITE(UNIT,15) SPOUT_ITEM_LABEL(SPOUT_ITEM(J)),
     A                        (EXTRA_BUFFER(I,J), I=1,NOUT)
600     CONTINUE
      ENDIF
      LKOUNT = LKOUNT + LINE_KNT
 
      IF(LKOUNT.EQ.PAGESP) LKOUNT = 0
 
      RETURN
      END
C
C
C
      SUBROUTINE   PRTLOG
     I                   (STDOUT, KOUNT, MXREV, BMXREV, NMXREV, MXRV,
     I                    LMXRV, MXSSRV, KNTVEC)
 
C     + + + PURPOSE + + +
C     Print a summary of the various error statistics.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER KOUNT, STDOUT
      INTEGER BMXREV(KOUNT), KNTVEC(KOUNT), LMXRV(KOUNT), NMXREV(KOUNT)
      REAL MXREV(KOUNT), MXRV(KOUNT), MXSSRV(KOUNT)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     KOUNT  - number of iterations to convergence or the maximum
C               number allowed
C     MXREV  - maximum relative correction value for each iteration
C     BMXREV - branch numbers for maximum relative corrections
C     NMXREV - maximum relative correction node for each iteration
C     MXRV   - maximum residual in the matrix for each iteration
C     LMXRV  - locations of the maximum residuals
C     MXSSRV - sum of squares of the residuals for each iteration
C     KNTVEC - number of variables that violate the primary convergence
C               tolerance for each iteration
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'inusnb.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER BRA, I, NODE
      CHARACTER NODOUT*7
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(' ITER RCORECT  BRA   NODE   MXRES  LOC  SUMSQR NUMGT')
 52   FORMAT(I5,1PE8.1,I5,A7,1PE8.1,I5,1PE8.1,I6)
C***********************************************************************
      WRITE(STDOUT,50)
      DO 100 I=1,KOUNT
        BRA = BMXREV(I)
        NODE = NMXREV(I)
        IF(BRA.EQ.0) THEN
C         EXTERIOR NODE
          IF(NODE.LT.0) THEN
            NODOUT = '-'//INENUS(-NODE)
          ELSE
            NODOUT = ' '//INENUS(NODE)
         ENDIF
        ELSE
C         NODE ON A BRANCH
          WRITE(NODOUT,'(I7)') NODE
          BRA = INBRUS(BRA)
        ENDIF
 
        WRITE(STDOUT,52) I, MXREV(I), BRA, NODOUT,
     A                 MXRV(I), LMXRV(I), MXSSRV(I), KNTVEC(I)
 100  CONTINUE
 
      RETURN
      END
C
C
C
      SUBROUTINE   PUTFC
     I                  (STDOUT, PUTDSN, NAME, WT, NBRA, NBN, NEX,
     I                   JTIME, NBLK, OPBLK, SITER, DT, BNODE, EXNODT)
 
C     + + + PURPOSE + + +
C     Put current state of system into dataset given by PUTDSN.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER BNODE, NBLK, NBN, NBRA, NEX, PUTDSN, STDOUT
      INTEGER EXNODT(9,NEX), OPBLK(MNBLK)
      REAL SITER, WT
      REAL*8 DT, JTIME
      CHARACTER NAME*32
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT - standard output unit for user messages
C     PUTDSN - unit number for storing final conditions
C     NAME   - name of the file for storing the final conditions
C     WT     - weight factor for approximating time integrals
C     NBRA   - number of branches in the model
C     NBN    - total number on nodes on branches in the model
C     NEX    - number of exterior nodes in the model
C     JTIME  - current modified julian time in the model
C     NBLK   - number of operation blocks
C     OPBLK  - pointer into the function table storage(FTAB/ITAB) for
C               each operation block.
C     SITER  - weighted sum of iterations to convergence
C     DT     - time step in seconds
C     BNODE  - boundary node number at which to start defining the
C               coefficient matrix
C
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'stdun.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER IOFLAG
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL BWPUT, FREE_UNIT
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' Final conditions saved at JTIME=',F20.10)
C***********************************************************************
C     OPEN THE FILE
      IF(NAME.EQ.' ') THEN
        OPEN(PUTDSN, FILE='PUTD', FORM='UNFORMATTED', STATUS='NEW')
      ELSE
        OPEN(PUTDSN, FILE=NAME, FORM='UNFORMATTED',
     A          STATUS='UNKNOWN', IOSTAT=IOFLAG)
        IF(IOFLAG.NE.0) THEN
          WRITE(STD6,*) ' PROBLEM IN OPENING FILE: ',NAME
          WRITE(STD6,*) ' CHECK PATH FOR FINAL CONDITIONS FILE.'
          STOP 'Abnormal stop: errors found.'
        ENDIF
      ENDIF
 
C     WRITE SIZE INFORMATION SO THAT WE CAN CHECK FOR AGREEMENT
C     AND CATCH MANY MISTAKES IN SPECIFYING A FILE.
 
      WRITE(PUTDSN) NBRA, NBN, NEX, JTIME, SITER, DT, BNODE
 
      CALL BWPUT
     I          (PUTDSN, WT, NBRA, NBN, NEX, NBLK, OPBLK)
 
      CALL FREE_UNIT(STD6, PUTDSN)
      WRITE(STDOUT,50)  JTIME
      RETURN
      END
C     ***********
C     *         *
C     * RDQUIT  *
C     *         *
C     ***********
 
      SUBROUTINE RDQUIT(STDOUT)
 
C     Close any files used for input of flow or elevation.
 
      IMPLICIT NONE
      INTEGER STDOUT

      INCLUDE 'arsize.prm'
      INCLUDE 'rdcom.cmn'
 
C     Local
 
      INTEGER I

C     External names

      EXTERNAL FREE_UNIT
C***********************************************************************
      DO 100 I=1,NUM_TS_F
        IF(DSS_INDEX_IN(I).EQ.0) THEN
C         This is a file and not a path in a HECDSS
          CALL FREE_UNIT(STDOUT, UNIN(I))
        ENDIF
100   CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE   RESOUT
     I                   (GRAV, VUNIT, STDOUT, NBRA, NODEID, NEX, TIME,
     I                    SFAC, BRPT, EXNODT, QCHOP)
 
C     + + + PURPOSE + + +
C     Output results.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, NBRA, NEX
      INTEGER BRPT(8,NBRA), EXNODT(9,NEX)
      REAL GRAV, QCHOP, SFAC, VUNIT
      REAL*8 TIME
      CHARACTER NODEID*4
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     GRAV   - value of acceleration due to gravity
C     VUNIT  - conversion factor for volumes on output
C     STDOUT   - Fortran unit number for user output and messages
C     NBRA   - number of branches in the model
C     NODEID - user node identification string
C     NEX    - number of exterior nodes in the model
C     TIME   - elapsed time in seconds from start of run
C     SFAC   - conversion factor from user stations to internal stations
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
C     QCHOP  - chopping value for output of flow
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'bnpond.cmn'
      INCLUDE 'julian.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'enothr.cmn'
      INCLUDE 'inusnb.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADDFLG, FA, FN, II, KNT, LA, NAD, NB
      REAL BRASUM, ELEV, FR, QPUT, ST, SUM, TEMP, YTEMP, Z
      CHARACTER AREAC*8, FLOWC*8, LATC*8, TOPC*8
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + EXTERNAL FUNCTIONS + + +
      REAL FROUDE
      CHARACTER PUT8*8
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL FROUDE, PUT8
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT(/,' RESULTS at time ',F15.0,' JTIME = ',F20.10)
 2010 FORMAT(/,' BRANCH NUMBER = ',I5)
 2020 FORMAT(' NODE STATION  DISCHARGE',6X,'AREA VELOC  DEPTH',
     A       '    ELEV',5X,'TOP   FR LAT INF')
 2022 FORMAT('  Node  Node Identifier     Stat    Flow    Area   Vel',
     A       '  Depth    Elev     Top  Fr Lat Inf')
 2030 FORMAT(I5,F8.3,1PE11.3,1PE10.3,0PF6.2,F7.2,F8.2,F8.1,F5.1,1PE8.1)
 2040 FORMAT(/,' EXTERIOR NODES')
 2050 FORMAT(' NODE',8X,'QE1',5X,'YE1',4X,'ELEV    STORAGE    STORAGE')
 2052 FORMAT('  Node  Node Identifier',8X,'QE1',5X,'YE1',4X,
     A       'Elev    Storage    Storage')
 2060 FORMAT(1X,A4,1PE11.3,2(0PF8.2))
 2062 FORMAT(1X,A5,1X,A16,1PE11.3,2(0PF8.3))
 2070 FORMAT(/,'       Branch ponding volume = ',1PE12.4,A6,
     A       0PF10.1,A6)
 2080 FORMAT(/,'     Network ponding volume = ',1PE12.4,A6,
     A       0PF10.1,A6)
 2090 FORMAT(1X,A5,1PE11.3,2(0PF8.2),2(1PE11.3))
 2092 FORMAT(1X,A5,1X,A16,1PE11.3,2(0PF8.3),2(1PE11.3))
C     Formats for US standard unit set.
18000 FORMAT(I6,1X,A16,F9.0,A8,A8,F6.2,F7.2,F8.2,A8,F4.1,A8)
18100 FORMAT(I6,1X,A16,F9.1,A8,A8,F6.2,F7.2,F8.2,A8,F4.1,A8)
18200 FORMAT(I6,1X,A16,F9.2,A8,A8,F6.2,F7.2,F8.2,A8,F4.1,A8)
18300 FORMAT(I6,1X,A16,F9.3,A8,A8,F6.2,F7.2,F8.2,A8,F4.1,A8)
18400 FORMAT(I6,1X,A16,F9.4,A8,A8,F6.2,F7.2,F8.2,A8,F4.1,A8)
C     Formats for metric unit set.
19000 FORMAT(I6,1X,A16,F9.1,A8,A8,F6.3,F7.3,F8.3,A8,F4.1,A8)
19100 FORMAT(I6,1X,A16,F9.2,A8,A8,F6.3,F7.3,F8.3,A8,F4.1,A8)
19200 FORMAT(I6,1X,A16,F9.3,A8,A8,F6.3,F7.3,F8.3,A8,F4.1,A8)
19300 FORMAT(I6,1X,A16,F9.4,A8,A8,F6.3,F7.3,F8.3,A8,F4.1,A8)
19400 FORMAT(I6,1X,A16,F9.5,A8,A8,F6.3,F7.3,F8.3,A8,F4.1,A8)
C***********************************************************************
 
C     TITLE
 
      WRITE(STDOUT,2000) TIME, JTIME
 
C     WRITE OUT RESULTS ETC FOR INTERIOR NODES
 
      SUM = 0.0
 
C     I) BRANCH LOOP
 
      DO 100 NB=1,NBRA
        FN = BRPT(1,NB) - 1
C        LN = BRPT(2,NB)
        FA = BRPT(3,NB)
        LA = BRPT(4,NB)
        WRITE(STDOUT,2010) INBRUS(NB)
C        IF(NODEID.EQ.'NO') THEN
C          WRITE(STDOUT,2020)
C        ELSE
          WRITE(STDOUT,2022)
C        ENDIF
 
        IF(ADDVEC(NB).LT.0) THEN
C         DO NOT OUTPUT ADDED NODES.
          ADDFLG = ABS(ADDVEC(NB))
        ELSE
          ADDFLG = 0
        ENDIF
C       II) NODE LOOP
C       ALWAYS OUTPUT THE FIRST NODE ON THE BRANCH
        NAD = FA
        FN = FN + 1
        FR = FROUDE(NSEC(NAD), Y1(NAD), Q1(NAD), A1(NAD),
     A              T1(NAD), GRAV)
        Z  = Y1(NAD) +ZVEC(NAD)
        ST = XVEC(NAD)/SFAC
          TEMP = 0.0
        QPUT = Q1(NAD)
        IF(ABS(QPUT).LE.QCHOP) THEN
          QPUT = 0.0
        ENDIF
C        IF(NODEID.EQ.'NO') THEN
C          WRITE(STDOUT,2030) FN, ST, QPUT, A1(NAD), QPUT/A1(NAD),
C     A              Y1(NAD), Z, T1(NAD), FR, TEMP
C        ELSE
          FLOWC = PUT8(QPUT)
          AREAC = PUT8(A1(NAD))
          TOPC = PUT8(T1(NAD))
          LATC = PUT8(TEMP)
          YTEMP = Y1(NAD) + SDVEC(NAD)
          GOTO (60, 61, 62, 63, 64, 70, 71, 72, 73, 74), FTID
60        CONTINUE
          WRITE(STDOUT,18000) FN, BNODID(NAD), ST, FLOWC, AREAC,
     A              QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC
          GOTO 99
61        CONTINUE
          WRITE(STDOUT,18100) FN, BNODID(NAD), ST, FLOWC, AREAC,
     A              QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC
          GOTO 99
62        CONTINUE
          WRITE(STDOUT,18200) FN, BNODID(NAD), ST, FLOWC, AREAC,
     A              QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC
          GOTO 99
63        CONTINUE
          WRITE(STDOUT,18300) FN, BNODID(NAD), ST, FLOWC, AREAC,
     A              QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC
          GOTO 99
64        CONTINUE
          WRITE(STDOUT,18400) FN, BNODID(NAD), ST, FLOWC, AREAC,
     A              QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC
          GOTO 99
70        CONTINUE
          WRITE(STDOUT,19000) FN, BNODID(NAD), ST, FLOWC, AREAC,
     A              QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC
          GOTO 99
71        CONTINUE
          WRITE(STDOUT,19100) FN, BNODID(NAD), ST, FLOWC, AREAC,
     A              QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC
          GOTO 99
72        CONTINUE
          WRITE(STDOUT,19200) FN, BNODID(NAD), ST, FLOWC, AREAC,
     A              QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC
          GOTO 99
73        CONTINUE
          WRITE(STDOUT,19300) FN, BNODID(NAD), ST, FLOWC, AREAC,
     A              QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC
          GOTO 99
74        CONTINUE
          WRITE(STDOUT,19400) FN, BNODID(NAD), ST, FLOWC, AREAC,
     A              QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC
99        CONTINUE
C        ENDIF
 
        KNT = ADDFLG
        DO 50 NAD=FA+1,LA
          IF(HLTAB(NAD).EQ.0.AND.KNT.GT.0) THEN
C           SKIP THE ADDED NODES
            KNT = KNT -1
          ELSE
C           OUTPUT THE NODE. RESET THE KNT AGAIN
            KNT = ADDFLG
            FN = FN + 1
            FR = FROUDE(NSEC(NAD), Y1(NAD), Q1(NAD), A1(NAD),
     A                  T1(NAD), GRAV)
            Z  = Y1(NAD) +ZVEC(NAD)
            ST = XVEC(NAD)/SFAC
            TEMP = QPVEC(NAD)
            QPUT = Q1(NAD)
            IF(ABS(QPUT).LE.QCHOP) THEN
              QPUT = 0.0
            ENDIF
C            IF(NODEID.EQ.'NO') THEN
C              WRITE(STDOUT,2030) FN, ST, QPUT, A1(NAD), QPUT/A1(NAD),
C     A                  Y1(NAD), Z, T1(NAD), FR, TEMP
C            ELSE
              FLOWC = PUT8(QPUT)
              AREAC = PUT8(A1(NAD))
              TOPC = PUT8(T1(NAD))
              LATC = PUT8(TEMP)
              YTEMP = Y1(NAD) + SDVEC(NAD)
              GOTO (160, 161, 162, 163, 164, 170, 171, 172, 173, 174),
     A                                                           FTID    
160           CONTINUE                                                         
              WRITE(STDOUT,18000) FN, BNODID(NAD), ST, FLOWC, AREAC,           
     A                  QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC               
              GOTO 199                                                         
161           CONTINUE                                                         
              WRITE(STDOUT,18100) FN, BNODID(NAD), ST, FLOWC, AREAC,           
     A                  QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC               
              GOTO 199                                                         
162           CONTINUE                                                         
              WRITE(STDOUT,18200) FN, BNODID(NAD), ST, FLOWC, AREAC,           
     A                  QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC               
              GOTO 199                                                         
163           CONTINUE                                                         
              WRITE(STDOUT,18300) FN, BNODID(NAD), ST, FLOWC, AREAC,           
     A                  QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC               
              GOTO 199                                                         
164           CONTINUE                                                         
              WRITE(STDOUT,18400) FN, BNODID(NAD), ST, FLOWC, AREAC,           
     A                  QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC               
              GOTO 199                                                         
170           CONTINUE                                                         
              WRITE(STDOUT,19000) FN, BNODID(NAD), ST, FLOWC, AREAC,           
     A                  QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC               
              GOTO 199                                                         
171           CONTINUE                                                         
              WRITE(STDOUT,19100) FN, BNODID(NAD), ST, FLOWC, AREAC,           
     A                  QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC               
              GOTO 199                                                         
172           CONTINUE                                                         
              WRITE(STDOUT,19200) FN, BNODID(NAD), ST, FLOWC, AREAC,           
     A                  QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC               
              GOTO 199                                                         
173           CONTINUE                                                         
              WRITE(STDOUT,19300) FN, BNODID(NAD), ST, FLOWC, AREAC,           
     A                  QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC               
              GOTO 199                                                         
174           CONTINUE                                                         
              WRITE(STDOUT,19400) FN, BNODID(NAD), ST, FLOWC, AREAC,           
     A                  QPUT/A1(NAD), YTEMP, Z, TOPC, FR, LATC               
199           CONTINUE                                                         
C            ENDIF
          ENDIF
 50     CONTINUE
        BRASUM = BPOND(NB)
        IF(BRASUM.GT.0.0) THEN
          IF(GRAV.GT.20.0) THEN
            WRITE(STDOUT,2070) BRASUM, ' ft^3 ', BRASUM/VUNIT,' Ac-ft'
          ELSE
            WRITE(STDOUT,2070) BRASUM, ' m^3  ', BRASUM/VUNIT,' K m^3'
          ENDIF
        ENDIF
 
        SUM = SUM + BRASUM
 100  CONTINUE
      IF(SUM.GT.0.0) THEN
        IF(GRAV.GT.20.0) THEN
          WRITE(STDOUT,2080) SUM, ' ft^3 ', SUM/VUNIT,' Ac-ft'
        ELSE
          WRITE(STDOUT,2080) SUM, ' m^3  ', SUM/VUNIT,' K m^3'
        ENDIF
      ENDIF
 
C     WRITE OUT RESULTS FOR EXTERIOR NODES
 
      WRITE(STDOUT,2040)
      WRITE(STDOUT,2052)
 
      DO 200 II=1,NEX
        NAD = USNSRT(II)
        ELEV = ZE(NAD) + YE1(NAD)
        QPUT = QE1(NAD)
        IF(ABS(QPUT).LE.QCHOP) THEN
          QPUT = 0.0
        ENDIF
        IF(EXNODT(3,NAD).EQ.-1) THEN
          WRITE(STDOUT,2092) INENUS(NAD), ENODID(NAD), QPUT,
     A                     YE1(NAD), ELEV, ABS(AE1(NAD)),
     B                     ABS(AE1(NAD))/VUNIT
 
        ELSE
          IF(EXNODT(3,NAD).GT.0) THEN
            YTEMP = YE1(NAD) + SDVEC(EXNODT(2,NAD))
          ELSE
            YTEMP = YE1(NAD)
          ENDIF
          IF(QPUT.NE.0.0) THEN
            WRITE(STDOUT,2062) INENUS(NAD), ENODID(NAD), QPUT, YTEMP,
     A                       ELEV
          ENDIF
        ENDIF
 200  CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE   TDTCHK
     I                   (STDOUT, EXNODT, NEX, EMC)
 
C     + + + PURPOSE + + +
C     Check two-D tables to see if the maximum results for elevation
C     or flow exceeded the limit of the table.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, NEX
      INTEGER EMC(MREMC), EXNODT(9,NEX)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
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
C     EMC    - vector containing coded form of the Matrix Control Input
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'bnrslt.cmn'
      INCLUDE 'enrslt.cmn'
      INCLUDE 'ftable.cmn'
      INCLUDE 'matcom.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADR, CODE, DNN, DUADR, HOUT, I, IENTRY, IOFF, IPNT, IT,
     A        MDN, NPAIR, QNN, SYSGN, TABN, TABTYP, TYPE, UDADR, UNN,
     B        ZTAB
      REAL H, HD, HDATUM, HMAX, HU, QMX, QNEG, QPOS, W, WC
 
C     + + + EXTERNAL NAMES + + +
      CHARACTER GET_TABID*16
      EXTERNAL GET14, GET613, GET_TABID
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *WRN:49* Two-D table overflows have occurred:',/,
     A' Table            Type  Maximum  Overflow  Maximum  Overflow',/,
     B' Id                     head in  amount    flow in  amount',/,
     C'                        table              table           ',/,
     D' ---------------- ----  -------  --------  -------  -------')
 52   FORMAT(1X,A16,I5,F10.2,F10.2)
 54   FORMAT(1X,A16,I5,20X,F10.2,F10.2)
C***********************************************************************
C     Clear the heading flag.
      HOUT = 0
C     START SEARCH
      IENTRY = 0
      TYPE = 6
 100  CONTINUE
        IENTRY = IENTRY + 1
        IPNT = ADD(IENTRY)
        CODE = EMC(IPNT)
        IF(CODE.EQ.5) THEN
C         CODE = 5.  Check for type.
          IF(TYPE.EQ.EMC(IPNT+1)) THEN
C           Found type 6.  Get the node numbers and the system sign.
            UNN = EMC(IPNT+2)
            DNN = EMC(IPNT+3)
            QNN = EMC(IPNT+4)
            SYSGN = EMC(IPNT+5)
C           Get the flows at the flow node.
            IT = EXNODT(3,QNN)
            IF(IT.LE.0) THEN
C             Node not on a branch.
              QPOS = FNQMAX(QNN)
              QNEG = FNQMIN(QNN)
            ELSE
              IT = EXNODT(2,QNN)
              QPOS = QMAX(IT)
              QNEG = QMIN(IT)
            ENDIF
            IF(QNEG.GT.0.0) THEN
C             No need to check.  Only check minimum flow when it is
C             negative.
              QNEG = 0.0
            ENDIF
 
C           If the number of flow paths is negative
C           then  tables of type 14 are involved.
            NPAIR = EMC(IPNT+6)
            IF(NPAIR.LT.0) THEN
C             Tables are type 14.  At most two tables appear.
              UDADR = EMC(IPNT+7)
              DUADR = EMC(IPNT+8)
              ZTAB = EMC(IPNT+10)
              ITMP = EMC(IPNT+11)
              HDATUM = RTMP
C             Flows of zero are not checked.
              IF(QPOS*SYSGN.GT.0) THEN
C               Maximum flow was from U to D.
                CALL GET14
     I                    (NEX, EXNODT, UDADR, DNN, ZTAB,
     O                     HDATUM, H, TABN, QMX, HMAX, TABTYP)
              ELSEIF(QPOS*SYSGN.LT.0) THEN
C               Maximum flow was from D to U.
                CALL GET14
     I                    (NEX, EXNODT, DUADR, UNN, ZTAB,
     O                     HDATUM, H, TABN, QMX, HMAX, TABTYP)
              ENDIF
              IF(QPOS.GT.0.0) THEN
                IF(H.GT.HMAX) THEN
                  IF(HOUT.EQ.0) THEN
                    WRITE(STDOUT,50)
                    HOUT = 1
                  ENDIF
C                 Final result  is above maximum  head.
                  WRITE(STDOUT,52) GET_TABID(TABN), TABTYP, HMAX, H-HMAX
                ENDIF
                IF(QPOS.GT.QMX) THEN
                  IF(HOUT.EQ.0) THEN
                    WRITE(STDOUT,50)
                    HOUT = 1
                  ENDIF
C                 Final flow result is above the table
                  WRITE(STDOUT,54) GET_TABID(TABN), TABTYP, QMX, 
     A                               QPOS-QMX
                ENDIF
              ENDIF
 
              IF(QNEG*SYSGN.GT.0) THEN
C               Minimum flow was from U to D.
                CALL GET14
     I                    (NEX, EXNODT, UDADR, DNN, ZTAB,
     O                     HDATUM, H, TABN, QMX, HMAX, TABTYP)
              ELSEIF(QNEG*SYSGN.LT.0) THEN
C               Minimum flow was from D to U.
                CALL GET14
     I                    (NEX, EXNODT, DUADR, UNN, ZTAB,
     O                     HDATUM, H, TABN, QMX, HMAX, TABTYP)
              ENDIF
              IF(-QNEG.GT.0.0) THEN
                IF(H.GT.HMAX) THEN
                  IF(HOUT.EQ.0) THEN
                    WRITE(STDOUT,50)
                    HOUT = 1
                  ENDIF
C                 Final result  is above maximum  head.
                  WRITE(STDOUT,52) GET_TABID(TABN), TABTYP, HMAX, H-HMAX
                ENDIF
                IF(-QNEG.GT.QMX) THEN
                  IF(HOUT.EQ.0) THEN
                    WRITE(STDOUT,50)
                    HOUT = 1
                  ENDIF
C                 Final flow result is above the table
                  WRITE(STDOUT,54) GET_TABID(TABN), TABTYP, QMX, 
     A                      -QNEG-QMX
                ENDIF
              ENDIF
 
            ELSE
C             Tables of type 6 or 13 may appear and there may be
C             multiple pairs.
              IOFF = 0
              DO 200 I=1,NPAIR
                UDADR = EMC(IPNT+IOFF+7)
                DUADR = EMC(IPNT+IOFF+8)
                ZTAB = EMC(IPNT+IOFF+10)
 
                ITMP = EMC(IPNT+IOFF+11)
                HDATUM = RTMP
 
                IF(QPOS*SYSGN.GT.0) THEN
C                 Maximum flow was from U to D.
                  CALL GET613
     I                       (NEX, EXNODT, UDADR, UNN, ZTAB,
     O                        HDATUM, H, TABN, HMAX, TABTYP)
                ELSEIF(QPOS*SYSGN.LT.0) THEN
C                 Maximum flow was from D to U.
                  CALL GET613
     I                       (NEX, EXNODT, DUADR, DNN, ZTAB,
     O                        HDATUM, H, TABN, HMAX, TABTYP)
                ENDIF
                IF(QPOS.GT.0.0) THEN
                  IF(H.GT.HMAX) THEN
                    IF(HOUT.EQ.0) THEN
                      WRITE(STDOUT,50)
                      HOUT = 1
                    ENDIF
C                   Final result  is above maximum head.
                    WRITE(STDOUT,52) GET_TABID(TABN), TABTYP, HMAX,
     A                                H-HMAX
                  ENDIF
                ENDIF
 
                IF(QNEG*SYSGN.GT.0) THEN
C                 Minimum flow was from U to D.
                  CALL GET613
     I                       (NEX, EXNODT, UDADR, UNN, ZTAB,
     O                        HDATUM, H, TABN, HMAX, TABTYP)
                ELSEIF(QNEG*SYSGN.LT.0) THEN
C                 Minimum flow was from D to U.
                  CALL GET613
     I                       (NEX, EXNODT, DUADR, DNN, ZTAB,
     O                        HDATUM, H, TABN, HMAX, TABTYP)
                ENDIF
                IF(-QNEG.GT.0.0) THEN
                  IF(H.GT.HMAX) THEN
                    IF(HOUT.EQ.0) THEN
                      WRITE(STDOUT,50)
                      HOUT = 1
                    ENDIF
C                   Final result  is above maximum head.
                    WRITE(STDOUT,52) GET_TABID(TABN), TABTYP, HMAX, 
     A                                  H-HMAX
                  ENDIF
                ENDIF
                IOFF = IOFF + CD5TY6
 200          CONTINUE
            ENDIF
          ENDIF
        ELSEIF(CODE.EQ.14) THEN
C         Side-weir option.  Dual tables of type 6 or 13.
          UNN = EMC(IPNT+1)
          DNN = EMC(IPNT+2)
C         THE MIDDLE NODE(MDN) IS ALWAYS THE FLOW NODE FOR A SIDE WEIR
          MDN = EMC(IPNT+3)
C         Set the system sign. If the sign of the flow node is < 0 then
C         a flow > 0 indicates that flow was into the flow path having
C         the flow node.  This means that SYSGN is of opposite sign to 
C         the sign of the flow node. 
          SYSGN = -EXNODT(1,MDN)

C         Get the addresses of the two 2-D tables.
          UDADR = EMC(IPNT+4)
          DUADR = EMC(IPNT+5)

C         Set the weight factor for computing head. 
          ITMP= EMC(IPNT+8)
          W = RTMP
          WC = 1.0 - W
          ITMP = EMC(IPNT+9)
          HDATUM = RTMP
C         Get the flows at the flow node.
          IT = EXNODT(3,MDN)
          IF(IT.LE.0) THEN
C           Node not on a branch.
            QPOS = FNQMAX(MDN)
            QNEG = FNQMIN(MDN)
          ELSE
            QPOS = QMAX(IT)
            QNEG = QMIN(IT)
          ENDIF
          IF(QNEG.GT.0.0) THEN
C           No need to check.  Only check minimum flow when it is
C           negative.
            QNEG = 0.0
          ENDIF
          IF(QPOS*SYSGN.GT.0) THEN
C           Maximum flow was from U to D.
            ADR = UDADR
            TABN = ITAB(ADR+1)
            TABTYP = ITAB(ADR+2)
            HMAX = FTAB(ADR+9)
            IT = EXNODT(3,UNN)
            IF(IT.LE.0) THEN
              HU = FNZMAX(UNN)
            ELSE
              IT = EXNODT(2,UNN)
              HU = ZMAX(IT)
            ENDIF
            IT = EXNODT(3,DNN)
            IF(IT.LE.0) THEN
              HD = FNZMAX(DNN)
            ELSE
              IT = EXNODT(2,DNN)
              HD = ZMAX(IT)
            ENDIF
            H = W*HU + WC*HD - HDATUM
          ELSEIF(QPOS*SYSGN.LT.0) THEN
C           Maximum flow was from D to U.
            CALL GET613
     I                 (NEX, EXNODT, DUADR, MDN, 0,
     O                  HDATUM, H, TABN, HMAX, TABTYP)
          ENDIF
          IF(QPOS.GT.0.0) THEN
            IF(H.GT.HMAX) THEN
              IF(HOUT.EQ.0) THEN
                WRITE(STDOUT,50)
                 HOUT = 1
              ENDIF
C             Final result  is above maximum ups head.
              WRITE(STDOUT,52) GET_TABID(TABN), TABTYP, HMAX, H-HMAX
            ENDIF
          ENDIF
 
          IF(QNEG*SYSGN.GT.0) THEN
C           Minimum flow was from U to D.
            ADR = UDADR
            TABN = ITAB(ADR+1)
            TABTYP = ITAB(ADR+2)
            HMAX = FTAB(ADR+9)
            IT = EXNODT(3,UNN)
            IF(IT.LE.0) THEN
              HU = FNZMAX(UNN)
            ELSE
              HU = ZMAX(IT)
            ENDIF
            IT = EXNODT(3,DNN)
            IF(IT.LE.0) THEN
              HD = FNZMAX(DNN)
            ELSE
              HD = ZMAX(IT)
            ENDIF
            H = W*HU + WC*HD - HDATUM
          ELSEIF(QNEG*SYSGN.LT.0) THEN
C           Minimum flow was from D to U.
            CALL GET613
     I                 (NEX, EXNODT, DUADR, MDN, 0,
     O                  HDATUM, H, TABN, HMAX, TABTYP)
          ENDIF
          IF(-QNEG.GT.0.0) THEN
            IF(H.GT.HMAX) THEN
              IF(HOUT.EQ.0) THEN
                WRITE(STDOUT,50)
                HOUT = 1
              ENDIF
C             Final result  is above maximum head.
              WRITE(STDOUT,52) GET_TABID(TABN), TABTYP, HMAX, H-HMAX
            ENDIF
          ENDIF
 
 
        ENDIF
 
        IF(CODE.GT.0) THEN
C         Continue the search.
          GOTO 100
        ENDIF
      RETURN
      END
C
C
C
      SUBROUTINE WRITE_DLAY_DTEN(STDOUT, DLAY_PNT, DTEN_PNT)

C     Write the presence of delay, detention or both

      IMPLICIT NONE
      INTEGER STDOUT, DLAY_PNT, DTEN_PNT

C     *******************************FORMATS****************************
81    FORMAT(5X,'Flows subject to delay and detention.')
82    FORMAT(5X,' Flows subject to detention.')
83    FORMAT(5X,'Flows subject to delay')
C***********************************************************************
      IF(DTEN_PNT.GT.0) THEN
        IF(DLAY_PNT.GT.0) THEN
          WRITE(STDOUT,81)
        ELSE
          WRITE(STDOUT,82)
        ENDIF
      ELSE
        IF(DLAY_PNT.GT.0) THEN
          WRITE(STDOUT,83) 
        ENDIF
      ENDIF
      RETURN
      END
C
C
C
      SUBROUTINE OUTPUT_DLAY_DTEN_PARAMETERS(STDOUT, GRAV,
     I                                       DLAY_PNT, DTEN_PNT)

C     Output a summary of the delay and detention parameters for 
C     a tributary-area unit. 

      IMPLICIT NONE
      INTEGER STDOUT, DLAY_PNT, DTEN_PNT
      REAL GRAV


      INCLUDE 'arsize.prm'
      INCLUDE 'tam.cmn'
      INCLUDE 'dtendef.cmn'

C     External names
      CHARACTER GET_TABID*16
      EXTERNAL GET_TABID
C     ******************************FORMATS*****************************
50    FORMAT(/,5X,' The linear reservoir delay time is:',F7.2,' hours.')
52    FORMAT(/,5X,' The detention parameters are:',/,7X,
     A            ' Design depth=',F7.2,' feet.',/,7X,
     B            ' Unit area flow=',F7.3,' cfs/acre.',/,7X,
     C            ' Pond side slope=',F7.2,' horizontal/vertical',/,7X,
     D            ' Average drainage area=',F8.2,' acres.',/,7X,
     E         ' Overflow weir slope=',F8.2,' horizontal/vertical',/,7X,
     F            ' Dimensionless weir coefficient=',F7.3,/,7X,
     G            ' Impervious area land-use index=',I3,/,7X,
     H            ' Table Id for detention volumes=',A,/,7X,
     I            ' Table Id for orifice flow=',A)
62    FORMAT(/,5X,' The detention parameters are:',/,7X,
     A            ' Design depth=',F7.2,' meters.',/,7X,
     B            ' Unit area flow=',F7.3,' cms/km^2.',/,7X,
     C            ' Pond side slope=',F7.2,' horizontal/vertical',/,7X,
     D            ' Average drainage area=',F10.5,' km^2.',/,7X,
     E         ' Overflow weir slope=',F8.2,' horizontal/vertical',/,7X, 
     F            ' Dimensionless weir coefficient=',F7.3,/,7X,
     G            ' Impervious area land-use index=',I3,/,7X,
     H            ' Table Id for detention volumes=',A,/,7X,
     I            ' Table Id for orifice flow=',A)
64    FORMAT(/,5X,' Linear-reservoir delay computed below.')
C***********************************************************************
      IF(DLAY_PNT.GT.0) THEN
C       We have some delay. 
        IF(DLAY_K(DLAY_PNT).GT.0.0) THEN
          WRITE(STDOUT,50)  DLAY_K(DLAY_PNT)/3600.
        ELSE
          WRITE(STDOUT,64)
        ENDIF
      ENDIF

      IF(DTEN_PNT.GT.0) THEN
C       We have detention.
        IF(GRAV.GT.15.0) THEN
          WRITE(STDOUT,52) DTEN_YD(DTEN_PNT), DTEN_UAQ(DTEN_PNT)*43560., 
     A                    DTEN_BZ(DTEN_PNT), DTEN_AVDA(DTEN_PNT)/43560., 
     B                    DTEN_WZ(DTEN_PNT), DTEN_WC(DTEN_PNT),
     C                    DEF_DTEN_LUI, 
     D                    GET_TABID(DTEN_UADV_TAB(DTEN_PNT)),                      
     E                    GET_TABID(DTEN_ORF_TAB(DTEN_PNT))                                
        ELSE
          WRITE(STDOUT,62) DTEN_YD(DTEN_PNT), DTEN_UAQ(DTEN_PNT)*1.E6, 
     A                    DTEN_BZ(DTEN_PNT), DTEN_AVDA(DTEN_PNT)/1.E6, 
     B                    DTEN_WZ(DTEN_PNT), DTEN_WC(DTEN_PNT),
     C                    DEF_DTEN_LUI, 
     D                    GET_TABID(DTEN_UADV_TAB(DTEN_PNT)),
     E                    GET_TABID(DTEN_ORF_TAB(DTEN_PNT))
        ENDIF
      ENDIF
      RETURN
      END                 
C
C
C
      SUBROUTINE   TRBOUT
     I                   (SFAC, SFAC2, STDOUT, NBRA, BRPT, TRIBA, NRWTA,
     I                    RTAP, RWTA, GSTART, GEND, NGAGE, GLU,
     I                    RTAFAC, TAFAC, XVEC, GRAV)
 
C     + + + PURPOSE + + +
C     Output the tributary areas as they exist at the end of TRIBIN
C     to verify that TRIBIN has processed them correctly.  
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER GLU, STDOUT, NBRA, NGAGE, NRWTA
      INTEGER BRPT(8,NBRA), GEND(0:MXGAGE), GSTART(0:MXGAGE),
     A        RTAP(MNFREE), RWTA(MNFREE)
      REAL GRAV, RTAFAC(MNFREE), SFAC, SFAC2, TAFAC(MNBRA),
     A     TRIBA(MXR_TRIBA,MXN_LU_G), XVEC(MNBN)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     SFAC   - conversion factor from user stations to internal stations
C     SFAC2  - conversion factor for tributary area
C     STDOUT   - Fortran unit number for user output and messages
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
C     TRIBA  - tributary areas for the model
C     NRWTA  - number of reservoirs with tributary area
C     RTAP   - reservoir tributary area pointer
C     RWTA   - reservoirs with tributary area
C     GSTART - starting address for storing land uses for each gage
C     GEND   - ending address for storing land uses for each gage
C     NGAGE  - number of gages
C     GLU    - number of gaged land uses in the model
C     RTAFAC - reservoir tributary area factor
C     TAFAC  - factor to adjust tributary areas
C     XVEC   - station values for each node on a branch

      INCLUDE 'tam.cmn'
 
C     + + + SAVED VALUES + + +
      CHARACTER LABELT(12)*8, TOTAL*8
      SAVE LABELT, TOTAL
 
C     + + + LOCAL VARIABLES + + +
      INTEGER FNODE, I, IBRA, J, JE, JS, LNODE,
     A        GAGE, N, UNIT_PNT, LPR_KNT, CAT_CODE,
     B        ITEM, TRIBA_PNT, NODE_CONVERT, FRACTION_PNT,
     C        DTEN_PNT, DLAY_PNT

      REAL AFAC, NETSUM(MXGAGE+1,MXN_LU_G+1), SUM,  TP,
     B    TEMP(MXN_LU_G+1), SUM2, FRAC, OLD_FRAC,
     C    FRAC_EPS, STANDARD_AFAC, TPP
 
      CHARACTER CHAR8(MXN_LU_G+1)*8, SUM_STRING*8, 
     A          LABEL(MXN_LU_G)*8

C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER GETUSB
      CHARACTER GETUSN*5
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETUSB, GETUSN, MARSUM, VAR_DECIMAL,
     A         FILL_VAR_DECIMAL_VECTOR
 
C     + + + DATA INITIALIZATIONS + + +
      DATA LABELT/'   AREA1','   AREA2','   AREA3','   AREA4',
     A           '   AREA5','   AREA6','   AREA7','   AREA8',
     B           '   AREA9','  AREA10','  AREA11','  AREA12'/,
     C     TOTAL/'   TOTAL'/
 
      DATA FRAC_EPS/2.E-3/
C     + + + OUTPUT FORMATS + + +
50    FORMAT(/,' *BUG:XXX* Invalid CAT_CODE=',I5,' in sub. TRBOUT.')
 60   FORMAT(' FNODE GAGE', 14A8)
 64   FORMAT(/,' Tributary Area Unit flowing into Branch:',I5)
 66   FORMAT(/,' Tributary Area Unit flowing into LPR/BN:',A5)
 68   FORMAT(' ',2I5,12A8)
 70   FORMAT('  GAGE',13A8)
 72   FORMAT(' ',I5,13A8)
 74   FORMAT(' ',A5,13A8)
78    FORMAT('  Node Fraction')
80    FORMAT(I6,F9.5)
81    FORMAT(' Sum of runoff allocation fractions=',F10.4)
C***********************************************************************
C      WRITE(STDOUT,*) ' At entry to TRBOUT: GLU=',GLU
C     Set the labels
      DO 101 I=1,GLU
        LABEL(I) = LABELT(I)
101   CONTINUE

C     Set the standard factor to convert internal tributary area
C     to square miles for English and square kilometers for Metric.
C     Used only for the Network summary of tributary area. 

      IF(GRAV.GT.15.0) THEN
C       English 
        STANDARD_AFAC = 5280.**2
      ELSE
        STANDARD_AFAC = 1000.**2
      ENDIF

C     CLEAR THE NETWORK SUMMARY ARRAY
 
      DO 110 I=1,NGAGE
        DO 100 J=1,GLU
          NETSUM(I,J) = 0.0
 100    CONTINUE
 110  CONTINUE
      
      WRITE(STDOUT,*) ' '
      WRITE(STDOUT,*) ' DISPLAY AND SUMMARY OF TRIBUTARY AREA'

C     Scan through the tributary management vector, TAM_ITAB, and 
C     print values in the order of input. 

      UNIT_PNT =  1 
      LPR_KNT = 0

9000  CONTINUE
        
        ITEM = TAM_ITAB(UNIT_PNT)
        CAT_CODE =TAM_ITAB(UNIT_PNT+1)
        DTEN_PNT = TAM_ITAB(UNIT_PNT+5)
        DLAY_PNT = TAM_ITAB(UNIT_PNT+6)

        GOTO (1000, 2000, 3000), CAT_CODE

          WRITE(STDOUT,50) CAT_CODE
          STOP 'Abnormal stop. Bug found.'


1000    CONTINUE
C         Output summary for a tributary unit on a branch. 

          IBRA = ITEM
          WRITE(STDOUT,64) GETUSB(IBRA)
          CALL WRITE_DLAY_DTEN(STDOUT, DLAY_PNT, DTEN_PNT)

          WRITE(STDOUT,70) (LABEL(J), J=1,GLU), TOTAL
        
          IF(TAFAC(IBRA).LT.0.0) THEN
            AFAC = SFAC2
          ELSE
            AFAC = SFAC2*TAFAC(IBRA)
          ENDIF
          GAGE = TAM_ITAB(UNIT_PNT+4)
          JE = GEND(GAGE)
          JS = GSTART(GAGE)
          TRIBA_PNT = TAM_ITAB(UNIT_PNT+3)
          N = JE - JS + 1
          SUM = 0.0
          DO 1010 J=1,N
            TP = TRIBA(TRIBA_PNT,J)/AFAC
            TPP = TRIBA(TRIBA_PNT,J)/STANDARD_AFAC
            TEMP(J) = TP
            NETSUM(GAGE,J) = NETSUM(GAGE,J) + TPP
            IF(TP.GT.0.0) THEN
              SUM = SUM + TP
            ENDIF
1010      CONTINUE
          CALL FILL_VAR_DECIMAL_VECTOR(N, TEMP,
     O                                CHAR8)
          CALL VAR_DECIMAL(SUM,
     O                    SUM_STRING)
          WRITE(STDOUT,72) GAGE, (CHAR8(J), J=1,N), SUM_STRING

          IF(SUM.NE.0.0) THEN
C           Print the flow distribution fractions for the 
C           computational elements on the branch. 
            FNODE = TAM_ITAB(UNIT_PNT+7)
            LNODE = TAM_ITAB(UNIT_PNT+8)
C           Get offset to convert from internal node number to 
C           the user node number. 
            NODE_CONVERT = BRPT(1,IBRA) - BRPT(3,IBRA)
            FRACTION_PNT = TAM_ITAB(UNIT_PNT+9)
            WRITE(STDOUT,78) 
C            WRITE(STDOUT,*) ' FRACTION_PNT=',FRACTION_PNT
C            WRITE(STDOUT,*) ' FNODE=',FNODE,' LNODE=',LNODE
            SUM2 = 0.0
            OLD_FRAC = 0.0
            DO 1020 J=FNODE, LNODE
              FRAC = TAM_FTAB(FRACTION_PNT + J - FNODE)
              IF(ABS(FRAC - OLD_FRAC)/(FRAC + 0.01).GT.FRAC_EPS) THEN
C               The fraction has changed.  Print the changed value
                WRITE(STDOUT,80) J + NODE_CONVERT, FRAC
                OLD_FRAC = FRAC
              ENDIF
              SUM2 = SUM2 + TAM_FTAB(FRACTION_PNT + J - FNODE)
1020        CONTINUE
            WRITE(STDOUT,81) SUM2 
          ENDIF
 
          CALL OUTPUT_DLAY_DTEN_PARAMETERS(STDOUT, GRAV,
     I                                     DLAY_PNT, DTEN_PNT)

          GOTO 9999

2000    CONTINUE
C         Output summary for tributary unit on a level-pool reservoir or a
C         boundary node.  At this point in input processing we cannot 
C         tell the difference.  
          LPR_KNT = TAM_ITAB(UNIT_PNT+8)
          WRITE(STDOUT,66) GETUSN(RWTA(LPR_KNT))
          CALL WRITE_DLAY_DTEN(STDOUT, DLAY_PNT, DTEN_PNT)
          WRITE(STDOUT,70) (LABEL(J), J=1,GLU), TOTAL
          TRIBA_PNT = TAM_ITAB(UNIT_PNT+3)
          GAGE = TAM_ITAB(UNIT_PNT+4)
          IF(RTAFAC(LPR_KNT).LT.0.0) THEN
            AFAC = SFAC2
          ELSE
            AFAC = SFAC2*RTAFAC(LPR_KNT)
          ENDIF

          JE = GEND(GAGE)
          JS = GSTART(GAGE)
          SUM = 0.0
          N = JE - JS + 1
          DO 2010 J=1,N
            TP = TRIBA(TRIBA_PNT,J)/AFAC
            TPP = TRIBA(TRIBA_PNT,J)/STANDARD_AFAC
            TEMP(J) = TP
            NETSUM(GAGE,J) = NETSUM(GAGE,J) + TPP
            IF(TP.GT.0.0) THEN
              SUM = SUM + TP
            ENDIF
2010      CONTINUE 
          CALL FILL_VAR_DECIMAL_VECTOR(N, TEMP,
     O                                CHAR8)
           CALL VAR_DECIMAL(SUM,
     O                     SUM_STRING)
          WRITE(STDOUT,72)  GAGE, 
     A        (CHAR8(J), J=1,N), SUM_STRING

          CALL OUTPUT_DLAY_DTEN_PARAMETERS(STDOUT, GRAV,
     I                                     DLAY_PNT, DTEN_PNT)

          GOTO 9999

3000    CONTINUE
          WRITE(STDOUT,*) ' Should not reach here.  BN not known yet.'
          STOP 'Abnormal stop: TRBOUT. Bug found.'

9999    CONTINUE
C       Point to the next unit.
        UNIT_PNT = TAM_ITAB(UNIT_PNT + 2)
        IF(UNIT_PNT.NE.0) GOTO 9000

C     Print system wide summaries
      CALL MARSUM
     I           (NGAGE, GLU, MXGAGE+1,
     M            NETSUM)
      WRITE(STDOUT,*) ' '
      WRITE(STDOUT,*) ' NETWORK SUMMARY OF TRIBUTARY AREA'
      WRITE(STDOUT,70) (LABEL(J), J=1,GLU), TOTAL
      N = GLU + 1
      DO 950 I=1,NGAGE
        IF(NETSUM(I,GLU+1).GT.0.0) THEN
          DO 901 J=1,N
            TEMP(J) = NETSUM(I,J)
901       CONTINUE
          CALL FILL_VAR_DECIMAL_VECTOR(N, TEMP,
     O                                  CHAR8)
          WRITE(STDOUT,72) I, (CHAR8(J), J=1,N)
        ENDIF
 950  CONTINUE
      DO 951 J=1,N
        TEMP(J) = NETSUM(NGAGE+1,J)
951   CONTINUE
      CALL FILL_VAR_DECIMAL_VECTOR(N, TEMP,
     O                             CHAR8)
      WRITE(STDOUT,74) 'TOTAL',(CHAR8(J), J=1,N)

      RETURN
      END
C
C
C
      SUBROUTINE   VALLEY
     I                   (STDOUT, VUNIT, NBRA, X, ZW, Z, BRPT, NSEC)
 
C     + + + PURPOSE + + +
C     Compute and print valley storage.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, NBRA
      INTEGER BRPT(8,NBRA), NSEC(MNBN)
      REAL VUNIT, X(MNBN), Z(MNBN), ZW(MNBN)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     VUNIT  - conversion factor for volumes on output
C     NBRA   - number of branches in the model
C     X      - stations for cross sections
C     ZW     - elevation of water surface for nodes on a branch
C     Z      - bottom profile elevation at each node on a branch
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
C     NSEC   - number and also address of cross section table at a node
C               on a branch
 
C     + + + LOCAL VARIABLES + + +
      INTEGER FNODE, IBRA, J, LNODE
      REAL AL, AR, BL, DBL, DKL, DTL, KL, TL, XL, XR, YL, YR
      REAL*8 SUM, SYSTOT
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER GETUSB
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETUSB, XLKT20
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT('1','ESTIMATED VALLEY STORAGE BELOW THE STANDARD FLOOD',
     A       ' LEVEL')
 52   FORMAT(/,' BRANCH  STORAGE ',/,' NUMBER   AC-FT')
 53   FORMAT(/,' BRANCH  STORAGE ',/,' NUMBER   K M^3')
 54   FORMAT(/,' *ERR:149* Stand Fld Lvl at or below minimum point',
     A   ' in channel at branch',I4,' node',I6)
 56   FORMAT(I7,F10.1)
 58   FORMAT(' SYSTEM',F10.1)
C***********************************************************************
      WRITE(STDOUT,50)
      IF(VUNIT.LT.40000.0) THEN
        WRITE(STDOUT,53)
      ELSE
        WRITE(STDOUT,52)
      ENDIF
 
      SYSTOT = 0.D0
      DO 200 IBRA=1,NBRA
        FNODE = BRPT(3,IBRA)
        LNODE = BRPT(4,IBRA)
C       FIND AREA AT THE FIRST NODE ON THE BRANCH
 
        YL = ZW(FNODE) - Z(FNODE)
        IF(YL.LE.0.0) THEN
          WRITE(STDOUT,54) GETUSB(IBRA), BRPT(1,IBRA)
          STOP 'Abnormal stop: errors found.'
        ENDIF
 
        CALL XLKT20
     I             (NSEC(IBRA),
     M              YL,
     O              AL, TL, DTL, KL, DKL, BL, DBL)
        XL = X(FNODE)
 
        SUM = 0.D0
        DO 100 J=FNODE+1,LNODE
          XR = X(J)
          YR = ZW(J) - Z(J)
          IF(YR.LE.0.0) THEN
            WRITE(STDOUT,54) GETUSB(IBRA), BRPT(1,IBRA) + J - FNODE
            STOP 'Abnormal stop: errors found.'
          ENDIF
 
          CALL XLKT20
     I               (NSEC(J),
     M                YR,
     O                AR, TL, DTL, KL, DKL, BL, DBL)
          SUM = SUM + 0.5*(AL + AR)*(XR - XL)
 
          XL = XR
          AL = AR
 100    CONTINUE
        SUM = SUM/VUNIT
        WRITE(STDOUT,56) GETUSB(IBRA), SUM
 
        SYSTOT = SYSTOT + SUM
 200  CONTINUE
      WRITE(STDOUT,58) SYSTOT
 
      END
C
C
C
      SUBROUTINE   WROUT
     I                  (JTIME, STDOUT, QCHOP, DT)
 
C     + + + PURPOSE + + +
C     Write curent record for all output files.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT
      REAL QCHOP
      REAL*8 DT, JTIME
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     JTIME  - current modified julian time in the model
C     STDOUT   - Fortran unit number for user output and messages
C     QCHOP    - value to set small flows to zero.  Avoids noise that
C                inevitably exists in iterative numerical computations.
C     DT       - time step just completed.
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'wrcom.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'enelem.cmn'
 
C     + + + LOCAL VARIABLES + + +
C     Create parameters for coding ACTION
      INTEGER OUTA, OUTS, ADD, SUB, YES, NO, QUAD
      PARAMETER (OUTA=1, OUTS=2, ADD=3, SUB=4, YES=5, NO=6, QUAD=7)
      INTEGER I, FULL, IS_SUM_GOOD
      REAL VAL
      REAL*8 SUM
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *BUG:26* INVALID VALUE OF INTERNAL CODE FOR OUTPUT',
     A       ' FILES:',I5)
C***********************************************************************
      CALL UPDATE_DSSOUT_JTIME(JTIME, FULL)

C     Set SUM to no good!
      IS_SUM_GOOD = NO
      DO 500 I=1,NFOUT
 
        IF(ACTOUT(I).NE.QUAD) THEN
          GOTO(1, 2, 3, 4), ICDOUT(I)
            WRITE(STDOUT,50) ICDOUT(I)
            STOP 'Abnormal stop: errors found.'
     
 1        CONTINUE
            WRITE(STDOUT,50) ICDOUT(I)
            STOP 'Abnormal stop: errors found.'
     
 2        CONTINUE
C           NEW FORM OF OUTPUT.
            IF(BRAOUT(I).GT.0) THEN
              VAL = Y2(NODOUT(I)) + ZVEC(NODOUT(I))
            ELSE
              VAL = YE2(NODOUT(I)) + ZE(NODOUT(I))
            ENDIF
            GOTO 1000
     
 3        CONTINUE
            WRITE(STDOUT,50) ICDOUT(I)
            STOP 'Abnormal stop: errors found.'
     
 4        CONTINUE
C           OUTPUT A POINT VALUED FLOW IN THE NEW FORM
            IF(BRAOUT(I).GT.0) THEN
              VAL = Q2(NODOUT(I))
            ELSE
              VAL = QE2(NODOUT(I))
            ENDIF
            IF(ABS(VAL).LE.QCHOP) VAL = 0.0
            GOTO 1000
 
 1000     CONTINUE
        ENDIF
        IF(UNOUT(I).LT.1000) THEN
          IF(ACTOUT(I).EQ.ADD.OR.ACTOUT(I).EQ.OUTA) THEN
            IF(IS_SUM_GOOD.EQ.NO) THEN
C             Initialize SUM
              SUM = DBLE(VAL) 
              IS_SUM_GOOD = YES
            ELSE
              SUM = SUM + DBLE(VAL)
            ENDIF
          ELSEIF(ACTOUT(I).EQ.SUB.OR.ACTOUT(I).EQ.OUTS) THEN
            IF(IS_SUM_GOOD.EQ.NO) THEN
C             Initialize SUM
              SUM = -DBLE(VAL) 
              IS_SUM_GOOD = YES
            ELSE
              SUM = SUM - DBLE(VAL)
            ENDIF
          ENDIF
          IF(ACTOUT(I).EQ.OUTA.OR.ACTOUT(I).EQ.OUTS) THEN 
            VAL = SNGL(SUM)
            WRITE(UNOUT(I)) JTIME, VAL
C            WRITE(STDOUT,*) 'OUT ', NAMOUT(I)
C            WRITE(STDOUT,*) ' VAL=',VAL
            IS_SUM_GOOD = NO
          ELSEIF(ACTOUT(I).EQ.QUAD) THEN
            RUNQUAD(I) = RUNQUAD(I) + 0.5D0*DT*(OLDF(I) + SUM)
            OLDF(I) = SUM
            VAL = SNGL(RUNQUAD(I))
            WRITE(UNOUT(I)) JTIME, VAL
C            WRITE(STDOUT,*) 'QUAD ', NAMOUT(I)
C            WRITE(STDOUT,*) ' SUM=',SUM,' RUNQUAD(I)=',RUNQUAD(I)
            IS_SUM_GOOD = NO
          ENDIF
        ELSE
          CALL UPDATE_DSSOUT_BUFFER(DSS_BUFFER_COLUMN(I), VAL)
        ENDIF
 500  CONTINUE
      IF(FULL.EQ.1) THEN
C       The DSS output buffer is full.  It must be written and
C       reset.
        CALL OUTPUT_DSSOUT_BUFFER
      ENDIF
      RETURN
      END
C
C
C
      SUBROUTINE   WRQUIT(STDOUT)
 
C     + + + PURPOSE + + +
C     Write the terminating record and close output files.
 
      IMPLICIT NONE
      INTEGER STDOUT

C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'wrcom.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I
      REAL VAL1
      REAL*8 JT

C     External names

      EXTERNAL FREE_UNIT
C***********************************************************************
      VAL1 = 0.0
      JT = 0.D0
      DO 500 I=1,NFOUT
        IF(UNOUT(I).LT.1000.AND.UNOUT(I).GT.0) THEN
          WRITE(UNOUT(I)) JT, VAL1
          CALL FREE_UNIT(STDOUT, UNOUT(I))
        ENDIF
 500  CONTINUE
 
      IF(DSS_OUT_COUNT.GT.0) THEN
        CALL OUTPUT_DSSOUT_BUFFER
      ENDIF
 
      RETURN
      END
C
C
C
      SUBROUTINE   ZSUMRY
     I                   (STDOUT, NBRA, NODEID, TIME, SFAC, EMC, BRPT,
     I                    EXNODT, NEX, HSLOT, VUNIT, QCHOP)
 
C     + + + PURPOSE + + +
C     Output a summary of maximum elevations and extreme flows.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, NBRA, NEX
      INTEGER BRPT(8,NBRA), EMC(MREMC), EXNODT(9,NEX)
      REAL HSLOT, QCHOP, SFAC, TIME, VUNIT
      CHARACTER NODEID*4
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     NBRA   - number of branches in the model
C     NODEID - user node identification string
C     TIME   - elapsed time in seconds from start of run
C     SFAC   - conversion factor from user stations to internal stations
C     EMC    - vector containing coded form of the Matrix Control Input
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
C     NEX    - number of exterior nodes in the model
C     HSLOT  - height of bottom slot.  Currently 0.0 always
C     VUNIT  - conversion factor for volumes on output
C     QCHOP  - chopping value for output of flow
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'misccon.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'bnrslt.cmn'
      INCLUDE 'enrslt.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'enothr.cmn'
      INCLUDE 'bnpond.cmn'
      INCLUDE 'namcom.cmn'
      INCLUDE 'ftable.cmn'
      INCLUDE 'inusnb.cmn'
      INCLUDE 'title.cmn'
      INCLUDE 'julian.cmn'
      INCLUDE 'home.cmn'

C     + + + LOCAL VARIABLES + + +
      INTEGER ADDFLG, FA, FN, I, ID, II, KNT, LA, LPRFLG, NAD, NB, NTAB,
     A        NULL, STDHWM, USBRAN, BRAN, NODE, EFLAG, USR_BRAN_NODE,
     B        BRAN_NODE_PNT, SLOT(11)
      LOGICAL THERE
      REAL AUNIT, DIFF, PDV, QPUTMN, QPUTMX, VOL, X, YMAX,
     A     ADUM, TDUM, DTDUM, KATMAX, DCDUM, BDUM, DBDUM,
     B     TAUMAX, ELEVATION, OFFSET, ZHWM, XL, XR, ZL, ZR,
     C     LIM(11)
      REAL*8 HR, DSTATION
      CHARACTER OUT1*14, OUT2*14, OUT3*14, GISID*16, TABID*16,
     A          OUT4*10, LINE*80, HWMARK_LOC*40, CHAR8*8, USNODE*5,
     B          WORK8*8, WORK*128
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER LENSTR, GET_UNIT
      CHARACTER JTTOCT*14, GET_GISID*16, GET_TABID*16
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL JTTOCT, LKTAB, TDTCHK, GET_GISID, GET_TABID, LENSTR,
     A         GET_UNIT, INLINE, STRIP_L_BLANKS, GETINB, GETINN

      DATA NULL/-2147483647/ 
      DATA LIM/-100.,-1.0,-0.5,-0.25,-0.1,0.0,0.1,0.25,0.5,1.0,100./
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT(/,' SUMMARY OF EXTREME ELEVATIONS AND FLOWS')
 2010 FORMAT(/,' EXTREMES ACHIEVED BY TIME',F15.0)
 2020 FORMAT(/,' BRANCH NUMBER  =',I5)
 2021 FORMAT(/,' BRANCH NUMBER =',I5,' PONDING VOLUME=',F10.1,A6)
 2032 FORMAT(
     A'   Node  Node_Identifier   Station  Mx Depth   Mx Elev  Mx Vel',
     A  8X,'Qmax',8X,'Qmin',' Time of max Z Time of max Q',
     B       ' Time of min Q    GIS Id String')
 2040 FORMAT(1X,I5,F10.3,3F10.3,2(1PE12.4),3A14,1X,A16)
 2050 FORMAT(/,'  FREE NODES')
 2052 FORMAT(/,'  LEVEL-POOL RESERVOIR NODES')
 2054 FORMAT('  NODE MAX DEPTH  MAX ELEV   STORAGE SURF AREA')
 2056 FORMAT('   Node  Node Identifier  Mx Depth   Mx Elev',
     A       '   Storage Surf Area')
C 2057 FORMAT(1X,1X,A5,2F10.4,2(1PE10.3))
 2058 FORMAT(2X,A5,1X,A16,2F10.4,2(1PE10.3))
 2062 FORMAT('   Node  Node_Identifier  Mx Depth   Mx Elev Botm Elev',
     A     8X,'Qmax',8X,'Qmin',' Time of max Z Time of max Q',
     B     ' Time of min Q   Station')
C 2070 FORMAT(1X,1X,A5,3F10.4,2(1PE12.4),3A14)
 2072 FORMAT(2X,A5,1X,A16,3F10.4,2(1PE12.4),3A14,A10)
 2074 FORMAT(' ')
 2075 FORMAT(1X, A)
 2076 FORMAT(' *WRN:39* Depth at node:',I5,':',I7,' overtops ',
     A       ' TabId=',A,' by',F10.4)
 2078 FORMAT(/,' Extremes achieved at ',I5,'/',I3,'/',I3,'/',F7.3)
2080  FORMAT(/,' High-Water Mark Summary',/,
     A   1X,'High-Water Mark Location                ',
     B'  Bran    Node Elevation  Sim Elev      Diff')
2082  FORMAT(1X,A40,I6,A8,F10.3,F10.3,F10.3)
2084  FORMAT(/,'*ERR:413* Node number=',A8,
     A' on branch number=',I5,' is out of range.')
2086  FORMAT(/,' Difference-distribution summary',/,
     A  ' Difference range        Count  Proportion')
2088  FORMAT(F7.2,' < Diff <=',F6.2,I6,F12.2)
2090  FORMAT(/,' Analysis of ',I5,' high-water marks completed.')

18000 FORMAT(1X,I6,1X,A16,F10.0,F10.3,F10.3,F8.3,2(1PE12.4),3A14,1X,A16,
     A       0PF8.1)
18100 FORMAT(1X,I6,1X,A16,F10.1,F10.3,F10.3,F8.3,2(1PE12.4),3A14,1X,A16,
     A       0PF8.1)
18200 FORMAT(1X,I6,1X,A16,F10.2,F10.3,F10.3,F8.3,2(1PE12.4),3A14,1X,A16,
     A       0PF8.1)
18300 FORMAT(1X,I6,1X,A16,F10.3,F10.3,F10.3,F8.3,2(1PE12.4),3A14,1X,A16,
     A       0PF8.1)
18400 FORMAT(1X,I6,1X,A16,F10.4,F10.3,F10.3,F8.3,2(1PE12.4),3A14,1X,A16,
     A       0PF8.1)
C***********************************************************************
C     Define the index for the case selection of format for output
      ID = NINT( LOG10(SFAC))

 
      WRITE(STDOUT,2000)
      WRITE(STDOUT,2074) 
      DO 90 I=1,TITLE_N
        WRITE(STDOUT,2075) TITLE(I)(1:LENSTR(TITLE(I)))
90    CONTINUE

      HR = 24.*DYFRAC
      WRITE(STDOUT,2078) YR, MN, DY, HR
 
C     BRANCH LOOP
 
      DO 100 NB=1,NBRA
        FN = BRPT(1,NB) - 1
        FA = BRPT(3,NB)
        LA = BRPT(4,NB)
        IF(PNDFLG.EQ.0) THEN
          WRITE(STDOUT,2020) INBRUS(NB)
        ELSE
          IF(VUNIT.GT.20000.0) THEN
            WRITE(STDOUT,2021) INBRUS(NB), BPMAX(NB)/VUNIT,' AC-FT'
          ELSE
            WRITE(STDOUT,2021) INBRUS(NB), BPMAX(NB)/VUNIT,' K M^3'
          ENDIF
        ENDIF
 
        WRITE(STDOUT,2032)
 
        IF(ADDVEC(NB).LT.0) THEN
C         SUPPRESS OUTPUT OF ADDED NODES
          ADDFLG = ABS(ADDVEC(NB))
        ELSE
          ADDFLG = 0
        ENDIF
 
C       ALWAYS OUTPUT THE FIRST NODE
        NAD = FA
        FN = FN + 1
        X = XVEC(NAD)/SFAC
        YMAX = ZMAX(NAD) - ZVEC(NAD) + SDVEC(NAD)
 
        OUT1 = JTTOCT(TZMAX(NAD))
        OUT2 = JTTOCT(TQMAX(NAD))
        OUT3 = JTTOCT(TQMIN(NAD))
        GISID = GET_GISID(NSEC(NAD))
        QPUTMX = QMAX(NAD)
        IF(ABS(QPUTMX).LE.QCHOP) THEN
          QPUTMX = 0.0
        ENDIF
        QPUTMN = QMIN(NAD)
        IF(ABS(QPUTMN).LE.QCHOP) THEN
          QPUTMN = 0.0
        ENDIF


C       Compute an approx to maximum shear stress
C        CALL XLKT20
C     I        (NSEC(NAD),
C     M         YMAX,
C     O         ADUM, TDUM, DTDUM, KATMAX, DCDUM, BDUM, DBDUM)
C        TAUMAX = 62.4*YMAX*(QPUTMX/KATMAX)**2 

        SELECT CASE(ID)
          CASE(0)
            WRITE(STDOUT,18000) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A        VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
          CASE(1)
            WRITE(STDOUT,18100) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A        VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
          CASE(2)
            WRITE(STDOUT,18200) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A        VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
          CASE(3)
            WRITE(STDOUT,18300) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A        VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
          CASE DEFAULT
            WRITE(STDOUT,18400) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A        VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
        END SELECT


        KNT = ADDFLG
 
C       II) NODE LOOP
 
        DO 50 NAD=FA+1,LA
          IF(HLTAB(NAD).EQ.0.AND.KNT.GT.0) THEN
C           SKIP NODES
            KNT = KNT - 1
          ELSE
C           RESET KNT
            KNT = ADDFLG
            FN = FN + 1
            X = XVEC(NAD)/SFAC
            YMAX = ZMAX(NAD) - ZVEC(NAD) + SDVEC(NAD)
 
            OUT1 = JTTOCT(TZMAX(NAD))
            OUT2 = JTTOCT(TQMAX(NAD))
            OUT3 = JTTOCT(TQMIN(NAD))
            GISID = GET_GISID(NSEC(NAD))
            QPUTMX = QMAX(NAD)
            IF(ABS(QPUTMX).LE.QCHOP) THEN
              QPUTMX = 0.0
            ENDIF
            QPUTMN = QMIN(NAD)
            IF(ABS(QPUTMN).LE.QCHOP) THEN
              QPUTMN = 0.0
            ENDIF
C       Compute an approx to maximum shear stress
C        CALL XLKT20
C     I        (NSEC(NAD),
C     M         YMAX,
C     O         ADUM, TDUM, DTDUM, KATMAX, DCDUM, BDUM, DBDUM)
C        TAUMAX = 62.4*YMAX*(QPUTMX/KATMAX)**2 

            SELECT CASE(ID)
              CASE(0)
                WRITE(STDOUT,18000) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A            VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
              CASE(1)
                WRITE(STDOUT,18100) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A            VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
              CASE(2)
                WRITE(STDOUT,18200) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A            VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
              CASE(3)
                WRITE(STDOUT,18300) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A            VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
              CASE DEFAULT
                WRITE(STDOUT,18400) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A            VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
            END SELECT
          ENDIF
 50     CONTINUE
 100  CONTINUE
 
C     FREE NODES
 
      IF(NEX.GT.2*NBRA) THEN
 
        WRITE(STDOUT,2050)
          WRITE(STDOUT,2062)
        DO 200 II=1,NEX
          I = USNSRT(II)
          IF(EXNODT(3,I).LE.0) THEN
            IF(EXNODT(3,I).EQ.0) THEN
              YMAX = FNZMAX(I) - ZE(I) 
            ELSE
              YMAX = FNZMAX(I) - ZE(I)
            ENDIF
            OUT1 = JTTOCT(FTZMAX(I))
            OUT2 = JTTOCT(FTQMAX(I))
            OUT3 = JTTOCT(FTQMIN(I))
C           Convert the node station, if any
            IF(EXNODT(8,I).NE.NULL) THEN
              DSTATION = DBLE(EXNODT(8,I))/1.D4
              IF(SFAC.LE.1.0) THEN
                WRITE(OUT4,'(F10.0)') DSTATION
              ELSEIF(SFAC.LE.10.0) THEN
                WRITE(OUT4,'(F10.1)') DSTATION
              ELSEIF(SFAC.LE.100.0) THEN
                WRITE(OUT4,'(F10.2)') DSTATION
              ELSEIF(SFAC.LE.1000.0) THEN
                WRITE(OUT4,'(F10.3)') DSTATION
              ELSE
                WRITE(OUT4,'(F10.4)') DSTATION
              ENDIF
            ELSE
              OUT4 = ' '
            ENDIF

 
            QPUTMX = FNQMAX(I)
            IF(ABS(QPUTMX).LE.QCHOP) THEN
              QPUTMX = 0.0
            ENDIF
            QPUTMN = FNQMIN(I)
            IF(ABS(QPUTMN).LE.QCHOP) THEN
              QPUTMN = 0.0
            ENDIF
 
              WRITE(STDOUT,2072) INENUS(I), ENODID(I), YMAX, FNZMAX(I),
     A          ZE(I), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, OUT4
          ENDIF
 200    CONTINUE
 
C       SCAN EXNODT AND OUTPUT THE MAXIMUM STORAGES IF ANY LEVEL-POOL
C       RESERVOIRS FOUND.  MAKE A DOUBLE SCAN: THE FIRST DECIDES
C       IF AT LEAST ONE RESERVOIR IS PRESENT AND THE SECOND OUTPUTS
C       THE RESERVOIRS IF AT LEAST ONE IS PRESENT.
 
        LPRFLG = 0
        DO 253 I=1,NEX
          IF(EXNODT(3,I).LT.0) THEN
            LPRFLG = 1
            GOTO 254
          ENDIF
 253    CONTINUE
 254    CONTINUE
 
        IF(LPRFLG.EQ.1) THEN
          IF(VUNIT.LT.20000.) THEN
            AUNIT = 1.E6
          ELSE
            AUNIT = 43560.
          ENDIF
          WRITE(STDOUT,2052)
C          IF(NODEID.EQ.'NO') THEN
C            WRITE(STDOUT,2054)
C          ELSE
            WRITE(STDOUT,2056)
C          ENDIF
 
          DO 255 II=1,NEX
            I = USNSRT(II)
            IF(EXNODT(3,I).LT.0) THEN
C             LEVEL-POOL RESERVOIR FOUND.  LOOK UP THE VOLUME.
              YMAX = FNZMAX(I)-ZE(I)
              CALL LKTAB
     I                  (EXNODT(4,I), YMAX, 0,
     O                   VOL, NTAB, PDV)
C              IF(NODEID.EQ.'NO') THEN
C                WRITE(STDOUT,2057) INENUS(I), YMAX, FNZMAX(I),
C     A                           VOL/VUNIT, PDV/AUNIT
C              ELSE
                WRITE(STDOUT,2058) INENUS(I), ENODID(I), YMAX, 
     A                  FNZMAX(I), VOL/VUNIT, PDV/AUNIT
C              ENDIF
            ENDIF
 255      CONTINUE
        ENDIF
      ENDIF
 
C     CHECK IF MAXIMA HAVE EXCEEDED THE PHYSICAL TOP OF ANY CROSS
C     SECTION
 
      DO 300 NB=1,NBRA
        FN = BRPT(1,NB) - 1
        FA = BRPT(3,NB)
        LA = BRPT(4,NB)
        DO 250 NAD=FA,LA
          FN = FN + 1
          YMAX = ZMAX(NAD) - ZVEC(NAD)
          DIFF = YMAX - FTAB(NSEC(NAD)+6)
          IF(DIFF.GT.EXTTOL) THEN
            TABID = GET_TABID(ITAB(NSEC(NAD)+1))
            WRITE(STDOUT,2076)  INBRUS(NB), FN, TABID(1:LENSTR(TABID)),
     A                          DIFF
          ENDIF
 250    CONTINUE
 300  CONTINUE
 
C     Check for two-D tables being overtopped
      CALL TDTCHK
     I           (STDOUT, EXNODT, NEX, EMC)
 
C     Check for the state of two-D tables in Code 5 Type 6
      CALL TDTCHK_FREE
     I                (STDOUT, EXNODT, NEX, EMC)


C     Seek a hwmark.loc file and output comparisons if one is found
C     Attach the existing global home name to the file to define its
C     location. 
      CALL CLEAR_HOME()
      IF(GHOME.NE.' ') THEN
C       A global home directory name exists. Seek the file there.
        WORK = '/hwmark.loc'
        CALL MAYBE_ADD_HOME(
     M                      WORK)
      ELSE
C       No global home directory exists. Seek in current working directory
        WORK = 'hwmark.loc'
      ENDIF  


      INQUIRE(FILE=WORK, EXIST=THERE)
      IF(THERE) THEN
        STDHWM = GET_UNIT(STDOUT)
        OPEN(STDHWM, FILE = WORK, STATUS = 'OLD')
C       Get the heading line.
        CALL INLINE
     I            (STDHWM, STDOUT,
     O             LINE)
C       Write new heading for the results. 
        WRITE(STDOUT, 2080) 

C       Clear values for summary of differences
        KNT = 0
        DO 395 I=1,11
          SLOT(I) = 0
395     CONTINUE

C       Start reading lines from hwmark.loc
400     CONTINUE

C       Read each line from hwmark.loc and process.  
        CALL INLINE
     I            (STDHWM, STDOUT,
     O             LINE)
        IF(LINE(1:3).NE.'END'.AND.LINE(1:3).NE.'end') THEN
C         We have a line to process. 
          READ(LINE,'(A40,I6,A8,2F10.0)',ERR=999) 
     A                 HWMARK_LOC, USBRAN, CHAR8, OFFSET, ELEVATION

C         Find the internal branch number
          CALL GETINB(USBRAN,
     O                EFLAG, BRAN) 
          IF(BRAN.EQ.0) THEN
C           We have an exterior node reference.  OFFSET has no meaning. 
C           Get the internal node number
            WORK8 = CHAR8
            CALL STRIP_L_BLANKS(
     M                          WORK8)
            USNODE = WORK8
            CALL GETINN(USNODE,
     O                  EFLAG, NODE)
            IF(EXNODT(3,NODE).LE.0) THEN
C             Free node or LPR
              ZHWM = FNZMAX(NODE)
            ELSE
C             Node on a branch
              ZHWM = ZMAX(EXNODT(2,NODE))
            ENDIF              
          ELSE
C           We have a location on a branch. Find the pointer into the
C           branch vectors.
            READ(CHAR8,'(I8)',ERR=999) USR_BRAN_NODE
            IF(USR_BRAN_NODE.LT.BRPT(1,BRAN)
     A         .OR.USR_BRAN_NODE.GT.BRPT(2,BRAN)) THEN
              WRITE(STDOUT,2084) CHAR8, USBRAN
              STOP 'Abnormal stop. Error(s) found.'
            ENDIF
            BRAN_NODE_PNT = USR_BRAN_NODE - BRPT(1,BRAN) + BRPT(3,BRAN)
            IF(OFFSET.GE.0.0) THEN
C             Mark is dns of the node.
              XL = XVEC(BRAN_NODE_PNT)
              ZL = ZMAX(BRAN_NODE_PNT)
              XR = XVEC(BRAN_NODE_PNT+1)
              ZR = ZMAX(BRAN_NODE_PNT+1)
            ELSE
              XL = XVEC(BRAN_NODE_PNT)
              ZL = ZMAX(BRAN_NODE_PNT)
              XR = XVEC(BRAN_NODE_PNT-1)
              ZR = ZMAX(BRAN_NODE_PNT-1)
            ENDIF
            ZHWM = ZL + ABS(OFFSET)*(ZR - ZL)/ABS(XR - XL)
          ENDIF
          DIFF = ZHWM - ELEVATION
          WRITE(STDOUT,2082) 
     A       HWMARK_LOC, USBRAN, CHAR8, ELEVATION, ZHWM, DIFF
          KNT = KNT + 1
          DO 410 I=2,11
            IF(DIFF.GT.LIM(I-1).AND.DIFF.LE.LIM(I)) THEN
              SLOT(I) = SLOT(I) + 1
              GOTO 411
            ENDIF
410       CONTINUE
411       CONTINUE

          GOTO 400
        ENDIF

C       Output summary of differences.
        WRITE(STDOUT,2086) 
        DO 420 I=2,11
          WRITE(STDOUT,2088) 
     A         LIM(I-1), LIM(I), SLOT(I), FLOAT(SLOT(I))/FLOAT(KNT)
420     CONTINUE

        WRITE(STDOUT,2090) KNT
      ENDIF

      RETURN
 999  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE
        STOP 'Abnormal stop: errors found.'

      END
C
C
C
      CHARACTER*16 FUNCTION   JTTOCT_OLD
     I                              (JTIME)
 
C     + + + PURPOSE + + +
C     Convert modified julian time to calendar time.
 
C     + + + DUMMY ARGUMENTS + + +
      REAL*8 JTIME
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     JTIME  - current modified julian time in the model
 
C     + + + LOCAL VARIABLES + + +
      INTEGER DY, MJD, MN, YR
      REAL HR
      REAL*8 FRAC
 
C     + + + INTRINSICS + + +
      INTRINSIC DBLE, INT
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL INVMJD
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(I3,'/',I2,'/',I2,':',F6.3)
C***********************************************************************
      MJD = INT(JTIME)
      FRAC = JTIME - DBLE(MJD)
      CALL INVMJD
     I           (MJD,
     O            YR, MN, DY)
      HR = 24.0*FRAC
 
C      IF(YR.LT.2000) THEN
C        YR = YR - 1900
C      ELSE
C        YR = YR - 2000
C      ENDIF
      YR = MOD(YR,100)
      WRITE(JTTOCT_OLD,50) YR, MN, DY, HR
      RETURN
      END
C
C
C
      SUBROUTINE   ZSUMRY_OLD
     I                   (STDOUT, NBRA, NODEID, TIME, SFAC, EMC, BRPT,
     I                    EXNODT, NEX, HSLOT, VUNIT, QCHOP)
 
C     + + + PURPOSE + + +
C     Output a summary of maximum elevations and extreme flows in 
C     the pre-version 10 format.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, NBRA, NEX
      INTEGER BRPT(8,NBRA), EMC(MREMC), EXNODT(9,NEX)
      REAL HSLOT, QCHOP, SFAC, TIME, VUNIT
      CHARACTER NODEID*4
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     NBRA   - number of branches in the model
C     NODEID - user node identification string
C     TIME   - elapsed time in seconds from start of run
C     SFAC   - conversion factor from user stations to internal stations
C     EMC    - vector containing coded form of the Matrix Control Input
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
C     NEX    - number of exterior nodes in the model
C     HSLOT  - height of bottom slot.  Currently 0.0 always
C     VUNIT  - conversion factor for volumes on output
C     QCHOP  - chopping value for output of flow
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'misccon.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'bnrslt.cmn'
      INCLUDE 'enrslt.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'enothr.cmn'
      INCLUDE 'bnpond.cmn'
      INCLUDE 'namcom.cmn'
      INCLUDE 'ftable.cmn'
      INCLUDE 'inusnb.cmn'
      INCLUDE 'title.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADDFLG, FA, FN, I, ID, II, KNT, LA, LPRFLG, NAD, NB, NTAB
      REAL AUNIT, DIFF, PDV, QPUTMN, QPUTMX, VOL, X, YMAX,
     A     ADUM, TDUM, DTDUM, KATMAX, DCDUM, BDUM, DBDUM,
     B     TAUMAX
      CHARACTER OUT1*16, OUT2*16, OUT3*16, GISID*16
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER LENSTR
      CHARACTER JTTOCT_OLD*16, GET_GISID*16, GET_TABID*16
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL JTTOCT_OLD, LKTAB, TDTCHK, GET_GISID, GET_TABID, LENSTR
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT(/,' SUMMARY OF EXTREME ELEVATIONS AND FLOWS')
 2010 FORMAT(/,' EXTREMES ACHIEVED BY TIME',F15.0)
 2020 FORMAT(/,' BRANCH NUMBER  =',I5)
 2021 FORMAT(/,' BRANCH NUMBER =',I5,' PONDING VOLUME=',F10.1,A6)
 2032 FORMAT('  NODE   NODEID   STATION MAX DEPTH  MAX ELEV MAX VELOC',
     A  8X,'QMAX',8X,'QMIN','   TIME OF MAX Z   TIME OF MAX Q',
     B       '   TIME OF MIN Q    GIS Id String ')
 2040 FORMAT(1X,I5,F10.3,3F10.3,2(1PE12.4),3A16,1X,A16)
 2050 FORMAT(/,'  FREE NODES')
 2052 FORMAT(/,'  LEVEL-POOL RESERVOIR NODES')
 2054 FORMAT('  NODE MAX DEPTH  MAX ELEV   STORAGE SURF AREA')
 2056 FORMAT('  NODE   NODEID MAX DEPTH  MAX ELEV   STORAGE SURF AREA')
 2057 FORMAT(1X,1X,A4,2F10.4,2(1PE10.3))
 2058 FORMAT(1X,A5,1X,A8,2F10.4,2(1PE10.3))
 2062 FORMAT('  NODE   NODEID MAX DEPTH  MAX ELEV BOTM ELEV',
     A     8X,'QMAX',8X,'QMIN','   TIME OF MAX Z   TIME OF MAX Q',
     B     '   TIME OF MIN Q')
 2070 FORMAT(1X,1X,A4,3F10.4,2(1PE12.4),3A16)
 2072 FORMAT(1X,A5,1X,A8,3F10.4,2(1PE12.4),3A16)
 2074 FORMAT(' ')
 2075 FORMAT(1X, A)
 2076 FORMAT(' *WRN:39* Depth at node:',I5,':',I5,' overtops ',
     A       ' TabId=',A,' BY',F10.4)
18000 FORMAT(1X,I5,1X,A8,F10.0,F10.3,2F10.3,2(1PE12.4),3A16,1X,A16,
     A       0PF8.1)
18100 FORMAT(1X,I5,1X,A8,F10.1,F10.3,2F10.3,2(1PE12.4),3A16,1X,A16,
     A       0PF8.1)
18200 FORMAT(1X,I5,1X,A8,F10.2,F10.3,2F10.3,2(1PE12.4),3A16,1X,A16,
     A       0PF8.1)
18300 FORMAT(1X,I5,1X,A8,F10.3,F10.3,2F10.3,2(1PE12.4),3A16,1X,A16,
     A       0PF8.1)
18400 FORMAT(1X,I5,1X,A8,F10.4,F10.3,2F10.3,2(1PE12.4),3A16,1X,A16,
     A       0PF8.1)
C***********************************************************************
C     Define the index for the case selection of format for output
      ID = NINT( LOG10(SFAC))
 
C      WRITE(STDOUT,2010) TIME

      WRITE(STDOUT,2000)
      WRITE(STDOUT,2074) 
      DO 90 I=1,TITLE_N
        WRITE(STDOUT,2075) TITLE(I)(1:LENSTR(TITLE(I)))
90    CONTINUE

 
C     BRANCH LOOP
 
      DO 100 NB=1,NBRA
        FN = BRPT(1,NB) - 1
        FA = BRPT(3,NB)
        LA = BRPT(4,NB)
        IF(PNDFLG.EQ.0) THEN
          WRITE(STDOUT,2020) INBRUS(NB)
        ELSE
          IF(VUNIT.GT.20000.0) THEN
            WRITE(STDOUT,2021) INBRUS(NB), BPMAX(NB)/VUNIT,' AC-FT'
          ELSE
            WRITE(STDOUT,2021) INBRUS(NB), BPMAX(NB)/VUNIT,' K M^3'
          ENDIF
        ENDIF
 
        WRITE(STDOUT,2032)
 
        IF(ADDVEC(NB).LT.0) THEN
C         SUPPRESS OUTPUT OF ADDED NODES
          ADDFLG = ABS(ADDVEC(NB))
        ELSE
          ADDFLG = 0
        ENDIF
 
C       ALWAYS OUTPUT THE FIRST NODE
        NAD = FA
        FN = FN + 1
        X = XVEC(NAD)/SFAC
        YMAX = ZMAX(NAD) - ZVEC(NAD) + SDVEC(NAD)
 
        OUT1 = JTTOCT_OLD(TZMAX(NAD))
        OUT2 = JTTOCT_OLD(TQMAX(NAD))
        OUT3 = JTTOCT_OLD(TQMIN(NAD))
        GISID = GET_GISID(NSEC(NAD))
        QPUTMX = QMAX(NAD)
        IF(ABS(QPUTMX).LE.QCHOP) THEN
          QPUTMX = 0.0
        ENDIF
        QPUTMN = QMIN(NAD)
        IF(ABS(QPUTMN).LE.QCHOP) THEN
          QPUTMN = 0.0
        ENDIF


C       Compute an approx to maximum shear stress
C        CALL XLKT20
C     I        (NSEC(NAD),
C     M         YMAX,
C     O         ADUM, TDUM, DTDUM, KATMAX, DCDUM, BDUM, DBDUM)
C        TAUMAX = 62.4*YMAX*(QPUTMX/KATMAX)**2 

        SELECT CASE(ID)
          CASE(0)
            WRITE(STDOUT,18000) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A        VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
          CASE(1)
            WRITE(STDOUT,18100) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A        VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
          CASE(2)
            WRITE(STDOUT,18200) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A        VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
          CASE(3)
            WRITE(STDOUT,18300) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A        VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
          CASE DEFAULT
            WRITE(STDOUT,18400) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A        VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
        END SELECT
        KNT = ADDFLG
 
C       II) NODE LOOP
 
        DO 50 NAD=FA+1,LA
          IF(HLTAB(NAD).EQ.0.AND.KNT.GT.0) THEN
C           SKIP NODES
            KNT = KNT - 1
          ELSE
C           RESET KNT
            KNT = ADDFLG
            FN = FN + 1
            X = XVEC(NAD)/SFAC
            YMAX = ZMAX(NAD) - ZVEC(NAD)
 
            OUT1 = JTTOCT_OLD(TZMAX(NAD))
            OUT2 = JTTOCT_OLD(TQMAX(NAD))
            OUT3 = JTTOCT_OLD(TQMIN(NAD))
            GISID = GET_GISID(NSEC(NAD))
            QPUTMX = QMAX(NAD)
            IF(ABS(QPUTMX).LE.QCHOP) THEN
              QPUTMX = 0.0
            ENDIF
            QPUTMN = QMIN(NAD)
            IF(ABS(QPUTMN).LE.QCHOP) THEN
              QPUTMN = 0.0
            ENDIF
C       Compute an approx to maximum shear stress
C        CALL XLKT20
C     I        (NSEC(NAD),
C     M         YMAX,
C     O         ADUM, TDUM, DTDUM, KATMAX, DCDUM, BDUM, DBDUM)
C        TAUMAX = 62.4*YMAX*(QPUTMX/KATMAX)**2 
            SELECT CASE(ID)
              CASE(0)
                WRITE(STDOUT,18000) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A            VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
              CASE(1)
                WRITE(STDOUT,18100) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A            VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
              CASE(2)
                WRITE(STDOUT,18200) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A            VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
              CASE(3)
                WRITE(STDOUT,18300) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A            VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
              CASE DEFAULT
                WRITE(STDOUT,18400) FN, BNODID(NAD), X, YMAX, ZMAX(NAD),
     A            VMAX(NAD), QPUTMX, QPUTMN, OUT1, OUT2, OUT3, GISID
            END SELECT
          ENDIF
 50     CONTINUE
 100  CONTINUE
 
C     FREE NODES
 
      IF(NEX.GT.2*NBRA) THEN
 
        WRITE(STDOUT,2050)
        WRITE(STDOUT,2062)
        DO 200 II=1,NEX
          I = USNSRT(II)
          IF(EXNODT(3,I).LE.0) THEN
            IF(EXNODT(3,I).EQ.0) THEN
              YMAX = FNZMAX(I)-ZE(I) 
            ELSE
              YMAX = FNZMAX(I)-ZE(I)
            ENDIF
            OUT1 = JTTOCT_OLD(FTZMAX(I))
            OUT2 = JTTOCT_OLD(FTQMAX(I))
            OUT3 = JTTOCT_OLD(FTQMIN(I))
 
            QPUTMX = FNQMAX(I)
            IF(ABS(QPUTMX).LE.QCHOP) THEN
              QPUTMX = 0.0
            ENDIF
            QPUTMN = FNQMIN(I)
            IF(ABS(QPUTMN).LE.QCHOP) THEN
              QPUTMN = 0.0
            ENDIF
 
C            IF(NODEID.EQ.'NO') THEN
C              WRITE(STDOUT,2070) INENUS(I), YMAX, FNZMAX(I), ZE(I),
C     A                         QPUTMX, QPUTMN, OUT1, OUT2, OUT3
C            ELSE
              WRITE(STDOUT,2072) INENUS(I), ENODID(I), YMAX, 
     A          FNZMAX(I), ZE(I), QPUTMX, QPUTMN, OUT1, OUT2, OUT3
C            ENDIF
          ENDIF
 200    CONTINUE
 
C       SCAN EXNODT AND OUTPUT THE MAXIMUM STORAGES IF ANY LEVEL-POOL
C       RESERVOIRS FOUND.  MAKE A DOUBLE SCAN: THE FIRST DECIDES
C       IF AT LEAST ONE RESERVOIR IS PRESENT AND THE SECOND OUTPUTS
C       THE RESERVOIRS IF AT LEAST ONE IS PRESENT.
 
        LPRFLG = 0
        DO 253 I=1,NEX
          IF(EXNODT(3,I).LT.0) THEN
            LPRFLG = 1
            GOTO 254
          ENDIF
 253    CONTINUE
 254    CONTINUE
 
        IF(LPRFLG.EQ.1) THEN
          IF(VUNIT.LT.20000.) THEN
            AUNIT = 1.E6
          ELSE
            AUNIT = 43560.
          ENDIF
          WRITE(STDOUT,2052)
C          IF(NODEID.EQ.'NO') THEN
C            WRITE(STDOUT,2054)
C          ELSE
            WRITE(STDOUT,2056)
C          ENDIF
 
          DO 255 II=1,NEX
            I = USNSRT(II)
            IF(EXNODT(3,I).LT.0) THEN
C             LEVEL-POOL RESERVOIR FOUND.  LOOK UP THE VOLUME.
              YMAX = FNZMAX(I)-ZE(I)
              CALL LKTAB
     I                  (EXNODT(4,I), YMAX, 0,
     O                   VOL, NTAB, PDV)
C              IF(NODEID.EQ.'NO') THEN
C                WRITE(STDOUT,2057) INENUS(I), YMAX, FNZMAX(I),
C     A                           VOL/VUNIT, PDV/AUNIT
C              ELSE
                WRITE(STDOUT,2058) INENUS(I), ENODID(I), YMAX, 
     A                  FNZMAX(I), VOL/VUNIT, PDV/AUNIT
C              ENDIF
            ENDIF
 255      CONTINUE
        ENDIF
      ENDIF
 
C     CHECK IF MAXIMA HAVE EXCEEDED THE PHYSICAL TOP OF ANY CROSS
C     SECTION
 
      DO 300 NB=1,NBRA
        FN = BRPT(1,NB) - 1
        FA = BRPT(3,NB)
        LA = BRPT(4,NB)
        DO 250 NAD=FA,LA
          FN = FN + 1
          YMAX = ZMAX(NAD) - ZVEC(NAD)
          DIFF = YMAX - FTAB(NSEC(NAD)+6)
          IF(DIFF.GT.EXTTOL) THEN
            WRITE(STDOUT,2076)  INBRUS(NB), FN, 
     A                    GET_TABID(ITAB(NSEC(NAD)+1)), DIFF
          ENDIF
 250    CONTINUE
 300  CONTINUE
 
C     Check for two-D tables being overtopped
      CALL TDTCHK
     I           (STDOUT, EXNODT, NEX, EMC)
 
C     Check for the state of two-D tables in Code 5 Type 6
      CALL TDTCHK_FREE
     I                (STDOUT, EXNODT, NEX, EMC)

      RETURN
      END
