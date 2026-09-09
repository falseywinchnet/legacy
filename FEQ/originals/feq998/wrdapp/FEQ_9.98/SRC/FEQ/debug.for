C Routines used in debugging                                                    
C                                                                               
C                                                                               
C
C
C
      SUBROUTINE   BROUT
     I                  (STDOUT, NBN, NBRA, BRPT)
 
C     + + + PURPOSE + + +
C     Output the branch information for debugging.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, NBN, NBRA
      INTEGER BRPT(8,NBRA)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     NBN    - total number on nodes on branches in the model
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
      INCLUDE 'bnothr.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, J
 
C     + + + OUTPUT FORMATS + + +
 74   FORMAT(///,' BRANCH INFORMATION'//,' BRANCH POINTER TABLE')
 75   FORMAT(' ',' BRAN','   UN','   DN','   UP','   DP',
     A ' UEXN',' DEXN')
 76   FORMAT(' ',7I5)
 77   FORMAT(/,'BRANCH VECTORS')
 78   FORMAT(' ',' XSAD',7X,'UVX',7X,'UVY')
 79   FORMAT(' ',I5,2F10.6)
C***********************************************************************
      WRITE(STDOUT,74)
      WRITE(STDOUT,75)
         DO 500 I=1,NBRA
         WRITE(STDOUT,76) I, (BRPT(J,I), J=1,6)
 500     CONTINUE
      WRITE(STDOUT,77)
      WRITE(STDOUT,78)
         DO 600 I=1,NBN
         WRITE(STDOUT,79) NSEC(I), UVX(I), UVY(I)
 600     CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE   DMPJUN
     I                   (STDOUT, JUNKNT, LJUNP, JUNPNT, LJOIN, JOIN,
     I                    LEMC, EMC)
 
C     + + + PURPOSE + + +
C     Dump the junction contents for checking if output > 0.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER JUNKNT, LEMC, LJOIN, LJUNP, STDOUT
      INTEGER EMC(LEMC), JOIN(LJOIN), JUNPNT(LJUNP)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT - standard output unit for user messages
C     JUNKNT - junction counter
C     LJUNP  - length of the junction pointer vector
C     JUNPNT - junction counter
C     LJOIN  - length of the junction description vector: JOIN
C     JOIN   - vector for storing the junction descriptions
C     LEMC   - length of EMC(*)
C     EMC    - vector containing coded form of the Matrix Control Input
 
C     + + + SAVED VALUES + + +
      INTEGER OUT
      SAVE OUT
 
C     + + + LOCAL VARIABLES + + +
      INTEGER CODE, FLAG, I, IE, IJ, IS, JPT, KNT, LENGTH, M, N, ND,
     A        NODE, PNT, RPT
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER FDNUMR
      CHARACTER GETUSN*5
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL FDNUMR, GETUSN
 
C     + + + DATA INITIALIZATIONS + + +
      DATA OUT/0/
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT('  NODE FLAG POINT LENGTH')
 52   FORMAT(1X,A5,I5,I6,I7)
 54   FORMAT(/,'*WRN:13* Elevation relationship pattern may cause',
     A       ' problems.',/,11X,'Recast so that code 3 relationships',
     B       ' are all tied',/,11X,'to a single node.',/,
     C       ' Nodes at junction are:')
 56   FORMAT(1X,A5)
C***********************************************************************
      IF(OUT.GT.0) THEN
        WRITE(STDOUT,*) ' '
        WRITE(STDOUT,*) '  DUMP OF JUNCTION DATA'
        WRITE(STDOUT,*) ' '
      ENDIF
 
      DO 1000 IJ=1,JUNKNT
        JPT = JUNPNT(IJ)
        N = JOIN(JPT)
        IF(OUT.GT.0) THEN
          WRITE(STDOUT,*) ' '
          WRITE(STDOUT,*) ' '
          WRITE(STDOUT,*) '  DATA FOR JUNCTION NUMBER ',IJ,' JPT=',JPT
          WRITE(STDOUT,*) '    JUNCTION HAS ', N,' NODES.'
          WRITE(STDOUT,*) ' JUNCTION IS CODE:',EMC(JOIN(JPT+1))
 
          WRITE(STDOUT,*) ' '
          WRITE(STDOUT,50)
        ENDIF
        IS = JPT + 4
        IE = IS + N - 1
        DO 100 I=IS,IE
          NODE = JOIN(I)
          FLAG = JOIN(I+N)
          PNT = JOIN(I+2*N)
          LENGTH = JOIN(I+3*N)
          IF(OUT.GT.0) THEN
            WRITE(STDOUT,52) GETUSN(NODE), FLAG, PNT, LENGTH
          ENDIF
 100    CONTINUE
 
        IF(OUT.GT.0) THEN
          WRITE(STDOUT,*) ' RELATIONSHIPS INVOLVING THE NODES.'
        ENDIF
 
        KNT = 0
        DO 200 I=IS,IE
          NODE = JOIN(I)
          M = FDNUMR(NODE, JPT, LJOIN, JOIN)
          IF(M.GT.1) THEN
C           COUNT NODES WITH MORE THAN TWO RELATIONSHIPS TIED TO THEM
            KNT = KNT + 1
          ENDIF
          PNT = JOIN(I+2*N)
          IF(OUT.GT.0) THEN
            WRITE(STDOUT,*) ' '
            WRITE(STDOUT,*) ' NODE=',GETUSN(NODE)
          ENDIF
 150      CONTINUE
          IF(PNT.EQ.0) THEN
C           FINISHED WITH THIS NODE
          ELSE
            RPT = JOIN(PNT+1)
            ND = JOIN(PNT+2)
            PNT = JOIN(PNT)
            CODE = EMC(JOIN(RPT))
            IF(OUT.GT.0) THEN
              WRITE(STDOUT,*) ' CODE=',CODE, ' NODE2=',GETUSN(ND)
            ENDIF
            GOTO 150
          ENDIF
 200    CONTINUE
        IF(KNT.GT.1) THEN
          WRITE(STDOUT,54)
          DO 210 I=IS,IE
            WRITE(STDOUT,56) GETUSN(JOIN(I))
 210      CONTINUE
        ENDIF
 
 1000 CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE   DPWOUT
     I                   (DIFFUS, STDOUT, LPNT, MLPNT, NO, POINT, WIND,
     I                    MF, PFPNT)
 
C     + + + PURPOSE + + +
C     Output diffuse, point and wind loading information for debug.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, LPNT, MLPNT
      INTEGER PFPNT(3,MLPNT)
      REAL MF(MLPNT)
      CHARACTER DIFFUS*4, NO*4, POINT*4, WIND*4
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     DIFFUS - indicator if tributary area is present.  YES if so
C     STDOUT   - Fortran unit number for user output and messages
C     LPNT   - length of the point load point load array
C     MLPNT  - maximum length of the point load pointer arrays
C     NO     - character string 'NO'
C     POINT  - if YES then point inflows to a branch are present
C     WIND   - flag for presence of wind stress simulation
C     MF     - momentum flux value
C     PFPNT  - point flow pointer array
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'wincom.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, J
 
C     + + + OUTPUT FORMATS + + +
 2100 FORMAT(///,' POINT FLOW INFORMATION')
 2110 FORMAT(/,6X,' TYPE',' NTAB','  NBN','     MF     ')
 2120 FORMAT(4I5,E12.5)
 2200 FORMAT(///,' WIND LOADING INFORMATION')
 2210 FORMAT(/,' WIND TABLE ADDRESS  = ',I5,/,1X,
     A           'AIRWAT  = ',1PE10.3,/,1X,
     C           'VELOCITY AT MIN CD  = ',0PF7.2,/,1X,
     D           'MIN CD =',1PE10.3,/,1X,
     E           'VELOCITY AT MAX CD =',0PF7.2,/,1X,
     F           'MAX CD =',1PE10.3,/,1X,
     G           'VADIF=',0PF7.2,/,1X,
     H           'CDDIF=',1PE10.3)
C***********************************************************************
C     DIFFUSE FLOWS
 
      IF(DIFFUS.EQ.NO) GOTO 150
C          DUMMY FOR NOW. EXPAND LATER
C     POINT FLOWS
 
 150  CONTINUE
      IF(POINT.EQ.NO) GOTO 210
      WRITE(STDOUT,2100)
      WRITE(STDOUT,2110)
      DO 200 I=1,LPNT
        WRITE(STDOUT,2120) I, (PFPNT(J,I), J=1,3), MF(I)
 200  CONTINUE
 
C     WIND LOADING
 
 210  CONTINUE
      IF(WIND.EQ.NO) GOTO 220
      WRITE(STDOUT,2200)
      WRITE(STDOUT,2210) WINTAB, AIRWAT, VAMIN, CDMIN, VAMAX, CDMAX,
     A                 VADIF, CDDIF
 
 220  CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE   DUMPIT
     I                   (CONV, QEPS, KOUNT, STDOUT, NBRA, NEX, BRPT,
     I                    EXNODT)
 
C     + + + PURPOSE + + +
C     Outputs a summary of conditions at the end of an iteration.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER KOUNT, STDOUT, NBRA, NEX
      INTEGER BRPT(8,NBRA), EXNODT(9,NEX)
      REAL CONV, QEPS
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     CONV   - maximum relative error(correction) for current iteration
C     QEPS   - value of flow to prevent zero divide when computing
C               relative correction
C     KOUNT  - number of iterations to convergence or the maximum
C               number allowed
C     STDOUT   - Fortran unit number for user output and messages
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
      INCLUDE 'enelem.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER FA, FN, LA, NAD, NB
      REAL AREL, QREL, YREL
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT('1',/,'0','DEBUG OUTPUT AT ITERATION ',I5,
     A         /,1X,'MAXIMUM RELATIVE ERROR = ',1PE12.5)
 2010 FORMAT(/,' BRANCH NUMBER = ',I5)
 2020 FORMAT(/,' NODE',7X,'Q2',10X,'Q3',10X,'Y2',10X,'Y3')
 2030 FORMAT(1X,I5,9(1PE12.5))
 2040 FORMAT(//,' EXTERIOR NODES')
 2050 FORMAT(/,' NODE',7X,'QE2',10X,'QE3',10X,'YE2',10X,'YE3')
C***********************************************************************
C     TITLE
 
      WRITE(STDOUT,2000) KOUNT, CONV
 
C     WRITE OUT VALUES ETC FOR INTERIOR NODES
 
C     I) BRANCH LOOP
 
      DO 100 NB=1,NBRA
        FN = BRPT(1,NB) - 1
        FA = BRPT(3,NB)
        LA = BRPT(4,NB)
        WRITE(STDOUT,2010) NB
        WRITE(STDOUT,2020)
 
C       II) NODE LOOP
 
        DO 50 NAD=FA,LA
          FN = FN + 1
          QREL = ABS(Q2(NAD)-Q3(NAD))/(ABS(Q3(NAD))+QEPS)
          AREL = ABS((Y2(NAD)-Y3(NAD))/Y3(NAD))
          WRITE(STDOUT,2030) FN, Q2(NAD), Q3(NAD), Y2(NAD), Y3(NAD),
     A                     QREL, AREL
 50     CONTINUE
 100  CONTINUE
 
C     WRITE OUT VALUES FOR EXTERIOR NODES-FREE NODES ONLY
 
      WRITE(STDOUT,2040)
      WRITE(STDOUT,2050)
      DO 200 NAD=1,NEX
        IF(EXNODT(3,NAD).LE.0) THEN
          YREL = ABS((YE2(NAD)-YE3(NAD))/YE3(NAD))
          QREL = ABS(QE2(NAD)-QE3(NAD))/(ABS(QE3(NAD))+QEPS)
          WRITE(STDOUT,2030) NAD, QE2(NAD), QE3(NAD), YE2(NAD), 
     A                       YE3(NAD), QREL, YREL
        ENDIF
 200  CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE   EXOUT
     I                  (STDOUT, EPT, NEX, EMC, EXNODT)
 
C     + + + PURPOSE + + +
C     Output the exterior node table and the network-matrix
C     control vector information
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EPT, STDOUT, NEX
      INTEGER EMC(EPT), EXNODT(9,NEX)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     EPT    - current length of EMC(*)
C     NEX    - number of exterior nodes in the model
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
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, IDUM, J
      REAL RDUM
 
C     + + + EQUIVALENCES + + +
      EQUIVALENCE (RDUM,IDUM)
 
C     + + + OUTPUT FORMATS + + +
 40     FORMAT(I5,I10,F10.2)
 80   FORMAT(///,' EXNODT',/,' NODE',' SIGN',' IPNT',' BRAN',' XSAD')
 81   FORMAT(' ',5I5)
 82   FORMAT(///,' NETWORK-MATRIX CONTROL')
C***********************************************************************
      WRITE(STDOUT,80)
         DO 500 I=1,NEX
         WRITE(STDOUT,81) I, (EXNODT(J,I), J=1,4)
 500     CONTINUE
 
      WRITE(STDOUT,82)
 
        DO 100 I=1,EPT
        IDUM = EMC(I)
        WRITE(STDOUT,40) I, IDUM, RDUM
 100    CONTINUE
        RETURN
      END
C
C
C
      CHARACTER*63 FUNCTION   FNDEMC
     I                              (EMCADR, LEMC, EMC)
 
C     + + + PURPOSE + + +
C     Get summary of an EMC entry for debugging MAKEMC and return
C     in a character string ready for printing.
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EMCADR, LEMC
      INTEGER EMC(LEMC)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     EMCADR - address of relationship in EMC(*)
C     LEMC   - length of EMC(*)
C     EMC    - vector containing coded form of the Matrix Control Input
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'stdun.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER CODE, DNN, IPNT, IT, J, N, NBR, NUM, QNODE, UNN
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER GETUSB
      CHARACTER GETUSN*5
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETUSB, GETUSN
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(' Code=',I3,' Bra=',I5)
 52   FORMAT(' Code=',I3,9(1X,A5))
 54   FORMAT(' Code=',I3,2(1X,A5))
 56   FORMAT(' Code=',I3,' Hd Node=',A5,' Qnode=',A5)
 58   FORMAT(' Code=',I3,' Unn=',A5,' Dnn=',A5,' Qnn=',A5)
 60   FORMAT(' Code=',I3,1X,A5)
 62   FORMAT(' Code=',I3,' Node=',A5,1X,A5,1X,I5)
 64   FORMAT(' Code=',I3,1X,A5)
 66   FORMAT(' Code=',I3,1X, A5,1X,A5)
 68   FORMAT(' Code=',I3,1X,A5,1X,A5,1X,A5)
 70   FORMAT(' Code=',I3,1X,A5,1X,A5,1X,I5)
C***********************************************************************
C     INITIALIZE VARIABLES
 
 
C     CODE FROM MATRIX CONTROL VECTOR
      IPNT = EMCADR
      CODE = EMC(IPNT)
 
      GOTO(100,200,300,400,500,600,700,800,900,950, 950,
     A     1200, 950, 1200, 1500),CODE
        WRITE(STD6,*) ' *BUG:05* INVALID EMC CODE IN FNDEMC. CODE=',
     A      CODE
        STOP 'Abnormal stop: errors found.'
 
C     CODE 1 GIVES BRANCH NUMBERS
 
 100  CONTINUE
 
        NBR = EMC(IPNT+1)
        IF(NBR.LT.0) THEN
          IT = -GETUSB(ABS(NBR))
        ELSE
          IT = GETUSB(NBR)
        ENDIF
        WRITE(FNDEMC, 50) CODE, IT
      GOTO 9000
 
C     CODE 2 GIVES DISCHARGE CONTINUITY AT JUNCTIONS. NO VARIABLE
C     NUMBER ASSIGNMENTS.  UPDATE EQUATION COUNT
 
 200  CONTINUE
 
        N = EMC(IPNT+1)
        WRITE(FNDEMC,52) CODE, (GETUSN(EMC(IPNT+1+J)), J=1,N)
      GOTO 9000
 
C     CODE 3 - GIVES ELEVATION EQUALITY. CHECK FOR NON-RESERVOIR
C     NODES NOT ON A BRANCH.
 
 300  CONTINUE
        UNN = EMC(IPNT+1)
        DNN = EMC(IPNT+2)
        WRITE(FNDEMC,54) CODE, GETUSN(UNN), GETUSN(DNN)
      GOTO 9000
 
C     CODE 4 - CONTROL STRUCTURE WITH 1 NODE HEAD DISCHARGE
C     UNN = UPSTREAM NODE FOR HEAD
C     DNN = NODE FOR DISCHARGE
 
 400  CONTINUE
        UNN = EMC(IPNT+2)
        QNODE = EMC(IPNT+4)
        WRITE(FNDEMC,56) CODE, GETUSN(UNN), GETUSN(QNODE)
      GOTO 9000
 
C     CODE 5 - CONTROL STRUCTURE WITH 2 NODE HEAD DISCHARGE
 500  CONTINUE
 
 
        UNN = EMC(IPNT+2)
        DNN = EMC(IPNT+3)
        QNODE = EMC(IPNT+4)
        WRITE(FNDEMC,58) CODE, GETUSN(UNN), GETUSN(DNN), GETUSN(QNODE)
        GOTO 9000
 
C     CODE 6 - GIVES DETAILS OF FORCED BOUNDARY
 
 600  CONTINUE
        DNN = EMC(IPNT+2)
        WRITE(FNDEMC,60) CODE, GETUSN(DNN)
 
      GOTO 9000
 
C     CODE 7 - LEVEL POOL RESERVOIR
C     DNN = NODE OF RESERVOIR
 
 700  CONTINUE
        DNN =  EMC(IPNT+1)
        WRITE(FNDEMC,62) CODE, GETUSN(DNN), GETUSN(EMC(IPNT+5)),
     A                   EMC(IPNT+6)
      GOTO 9000
 
C     CODE 8 - CRITICAL DEPTH CONDITION
C     NUM = NODE NUMBER
 
 800  CONTINUE
        NUM = EMC(IPNT+1)
        WRITE(FNDEMC,64) CODE, GETUSN(NUM)
      GOTO 9000
 
 
C     CODE 9 MOMENTUM JUNCTION- NOT COMPLETE
 
 900  CONTINUE
        WRITE(STD6,*) ' SHOULD NOT GET HERE. FUNCTION FNDEMC.'
        STOP 'Abnormal stop: errors found.'
 
 
C     CODE 10 - EQUALITY OF ELEVATION OF TOTAL ENERGY LINE
 
 
 950  CONTINUE
        UNN = EMC(IPNT+1)
        DNN = EMC(IPNT+2)
        WRITE(FNDEMC,66) CODE, GETUSN(UNN), GETUSN(DNN)
      GOTO 9000
 
 1200 CONTINUE
C       THREE NODES INVOLVED HERE.
        WRITE(FNDEMC,68) CODE, (GETUSN(EMC(IPNT+J)), J=1,3)
        GOTO 9000
 
 1500 CONTINUE
C       NULL BRANCH
        WRITE(FNDEMC,70) CODE, GETUSN(EMC(IPNT+1)), GETUSN(EMC(IPNT+2)),
     A                   EMC(IPNT+3)
 9000 CONTINUE
 
      RETURN
      END
C
C
C
      SUBROUTINE   FTOUT
     I                  (STDOUT,
     M                   OUTPUT)
 
C     + + + PURPOSE + + +
C     Output the function tables for debugging.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, OUTPUT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     OUTPUT - output level for diagnostic work
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER FTP, HA, I, J, K, LA, NTAB, TYPE
 
C     + + + OUTPUT FORMATS + + +
 60   FORMAT(///,' FUNCTION TABLES')
 61   FORMAT(' ','*BUG:22* ADDRESSING BUG FOR TABLES*',2I5)
 62   FORMAT(' ','*BUG:23* TABLE TYPE INVALID:',I5)
 63   FORMAT(/,'TABLE = ',I5,/,' TYPE = ',I5,/,' FIRST ADD = ',I5,/,
     A      ' HIGH ADD = ',I5,/,' LAST ADD = ',I5)
 64   FORMAT(' ','STATION = ',F15.3,' ELEVATION = ',F10.2)
 65   FORMAT(' ',F7.3,F9.2,1P2E11.4,0PF7.3,1P2E11.4)
 66   FORMAT(' ','REFERENCE LEVEL = ',F10.2)
 67   FORMAT(/,'  ARGUMENT',' FUNCTION VALUE')
 68   FORMAT(' ',F10.2,2(1PE15.5))
 69   FORMAT(/,'  ARGUMENT    FUNCTION1        FUNCTION2')
 641  FORMAT(/,2X,'DEPTH',' TOPWIDTH',7X,'AREA',4X,'CONVFAC',
     1  3X,'BETA',8X,'YBA',9X,'SJ')
C***********************************************************************
      IF(OUTPUT.GT.0)
     1   WRITE(STDOUT,60)
 
         DO 3000 I=1,MFTNUM
         FTP = FTPNT(I)
         IF(FTP.EQ.0) GOTO 3000
 
C           TABLE EXISTS
 
            NTAB = ITAB(FTP+1)
            IF(NTAB.EQ.I) GOTO 100
               WRITE(STDOUT,61) NTAB, I
 100        CONTINUE
            TYPE = ITAB(FTP+2)
            IF(OUTPUT.GT.0)
     1         WRITE(STDOUT,63) NTAB, TYPE, FTP, ITAB(FTP), ITAB(FTP+3)
            IF(TYPE.GE.1 .AND. TYPE.LE.4) GOTO 500
            WRITE(STDOUT,62) TYPE
            GOTO 1000
 500        GOTO(1,2,3,3),TYPE
         WRITE(STDOUT,*) ' *BUG:24* INVALID TABLE TYPE IN FTOUT. TYPE=',
     A               TYPE
              STOP 'Abnormal stop: errors found.'
 
 1          CONTINUE
               IF(OUTPUT.GT.0)
     1            WRITE(STDOUT,64) FTAB(FTP+4), FTAB(FTP+5)
               IF(OUTPUT.GT.0)
     1            WRITE(STDOUT,641)
               LA = FTP+6
               HA = ITAB(FTP)
               IF(OUTPUT.EQ.0) GOTO 1000
                  DO 200 J=LA,HA,6
                  WRITE(STDOUT,65) (FTAB(J+K-1), K=1,6)
 200              CONTINUE
               GOTO 1000
 2          CONTINUE
               IF(OUTPUT.GT.0)
     1            WRITE(STDOUT,66) FTAB(FTP+4)
               IF(OUTPUT.GT.0)
     1            WRITE(STDOUT,67)
               LA = FTP+5
               HA = ITAB(FTP)
               IF(OUTPUT.EQ.0) GOTO 1000
                  DO 300 J=LA,HA,2
                  WRITE(STDOUT,68) (FTAB(J+K-1), K=1,2)
 300              CONTINUE
               GOTO 1000
 3          CONTINUE
               IF(OUTPUT.GT.0)
     1            WRITE(STDOUT,66) FTAB(FTP+4)
               IF(OUTPUT.GT.0)
     1            WRITE(STDOUT,69)
               LA = FTP+ 5
               HA = ITAB(FTP)
               IF(OUTPUT.EQ.0) GOTO 1000
               DO 400 J=LA,HA,3
                  WRITE(STDOUT,68) (FTAB(J+K-1), K=1,3)
 400           CONTINUE
               GOTO 1000
 1000       CONTINUE
 3000    CONTINUE
      IF(OUTPUT.EQ.0) OUTPUT = 1
      RETURN
      END
C
C
C
      SUBROUTINE   INOUT
     I                  (STDOUT, NBRA, NEX, BRPT)
 
C     + + + PURPOSE + + +
C     Output a summary of initial conditions for debugging purposes.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, NBRA, NEX
      INTEGER BRPT(8,NBRA)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
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
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'enelem.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER FA, FN, LA, NAD, NB
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT('1',/,/,' DEBUG OUTPUT FOR INITIAL CONDITIONS')
 2010 FORMAT(/,'BRANCH NUMBER = ',I5)
 2020 FORMAT(/,' NODE',10X,'Q1',10X,'Y1',10X,'A1',10X,'DX',
     A           10X,'DZ')
 2030 FORMAT(1X,I5,5(1PE12.5))
 2040 FORMAT(//,' EXTERIOR NODES')
 2050 FORMAT(/,'NODE',5X,'QE1',8X,'YE1',8X,'AE1',8X,'ZE')
C***********************************************************************
C     TITLE
 
      WRITE(STDOUT,2000)
 
C     WRITE OUT INITIAL CONDITIONS ETC FOR INTERIOR NODES
 
C     I) BRANCH LOOP
 
      DO 100 NB=1,NBRA
        FN = BRPT(1,NB) - 1
        FA = BRPT(3,NB)
        LA = BRPT(4,NB)
        WRITE(STDOUT,2010) NB
        WRITE(STDOUT,2020)
 
C       II) NODE LOOP
 
        DO 50 NAD=FA,LA
          FN = FN + 1
          WRITE(STDOUT,2030) FN, Q1(NAD), Y1(NAD), A1(NAD), DXVEC(NAD),
     A                     DZVEC(NAD)
 50     CONTINUE
 100  CONTINUE
 
C     WRITE OUT INITIAL CONDITIONS FOR EXTERIOR NODES
 
      WRITE(STDOUT,2040)
      WRITE(STDOUT,2050)
      DO 200 NAD=1,NEX
        WRITE(STDOUT,2030) NAD, QE1(NAD), YE1(NAD), AE1(NAD), ZE(NAD)
 200  CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE   QPVOUT
     I                   (NBRA, NBN, STDOUT, BRPT, QPVEC, NRWTA, RWTA,
     I                    RTAP)
 
C     + + + PURPOSE + + +
C     Output QPVEC(*) for checking.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, NBN, NBRA, NRWTA
      INTEGER BRPT(8,NBRA), RTAP(NRWTA), RWTA(NRWTA)
      REAL QPVEC(NBN)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NBRA   - number of branches in the model
C     NBN    - total number on nodes on branches in the model
C     STDOUT   - Fortran unit number for user output and messages
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
C     QPVEC  - lateral inflows for a time step
C     NRWTA  - number of reservoirs with tributary area
C     RWTA   - reservoirs with tributary area
C     RTAP   - reservoir tributary area pointer
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, IJ, J, JEND, JSTART
 
C     + + + OUTPUT FORMATS + + +
 4900 FORMAT(/,' BRANCH = ',I5)
 4901 FORMAT(' ',I5,1PE13.6)
C***********************************************************************
        IF(NRWTA.GT.0) THEN
          I = 0
          WRITE(STDOUT,4900) I
          DO 4100 I=1,NRWTA
            WRITE(STDOUT,4901) RWTA(I), QPVEC(RTAP(I))
 4100     CONTINUE
        ENDIF
 
        DO 4200 I=1,NBRA
          WRITE(STDOUT,4900) I
          JSTART = BRPT(3,I) + 1
          JEND = BRPT(4,I)
          IJ = BRPT(1,I) + 1
          DO 4150 J=JSTART,JEND
            WRITE(STDOUT,4901) IJ, QPVEC(J)
            IJ = IJ+1
 4150       CONTINUE
 4200     CONTINUE
 
      RETURN
      END
C
C
C
      SUBROUTINE  FIND_VOLUMES
     I                   (NBRA, NBN, NEX, RESNUM, DLAY_KNT, DTEN_KNT, 
     I                    BRPT, RESVEC, DXVEC, A, AE, POND, GEQVEC,
     I                    QVEC, WXVEC, MA, DLAY_Q, DLAY_K,
     I                    DTEN_S, DTEN_NBAR,
     O                    LPRB_VOL, DD_VOL)
 
C     + + + PURPOSE + + +
C     Find volume in the stream system.

      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER DLAY_KNT, DTEN_KNT, NBN, NBRA, NEX, RESNUM
      INTEGER BRPT(8,NBRA), GEQVEC(NBRA), RESVEC(NEX)
      REAL A(NBN), AE(NEX), DXVEC(NBN), MA(NBN), POND(NBN), QVEC(NBN),
     A     WXVEC(NBN), DTEN_S(DTEN_KNT), DTEN_NBAR(DTEN_KNT)
      REAL*8 DLAY_Q(DLAY_KNT), DLAY_K(0:DLAY_KNT), LPRB_VOL, DD_VOL

 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NBRA   - number of branches in the model
C     NBN    - total number on nodes on branches in the model
C     NEX    - number of exterior nodes in the model
C     RESNUM - number of level-pool reservoirs
C     DLAY_KNT - number of delay reservoirs
C     DTEN_KNT - number of detention ponds
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
C     RESVEC - index into area vector for each level-pool reservoir
C     DXVEC  - distance increments along the x-axis for the channel
C     A      - Cross sectional areas in the branches.
C     AE     - area at exterior nodes and if < 0 volume in a reservoir
C     POND   - volume of surcharge storage for each element
C     GEQVEC - code for the governing equation option for each branch
C     QVEC   - flow rate at each node on a branch
C     WXVEC  - value of weight for volumes when variable weight active
C     MA     - weight factor on area to get volume per unit length
C     DLAY_Q - outflow from delay reservoirs
C     DLAY_K - delay time for the linear delay reservoirs
C     DTEN_S - storage in a detention pond.
C     DTEN_NBAR - number of average ponds per trib-area unit.
C     LPRB_VOL - volume in level-pool reservoirs and branches
C     DD_VOL   - volume in detention and delay reservoirs

 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'stdun.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER FN, GEQ, I, J, LN
      REAL WA
      REAL*8 SUM, SUMA
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
C***********************************************************************
      SUM = 0.D0
      SUMA = 0.D0
      DO 200 I=1,NBRA
        FN = BRPT(3,I)+1
        LN = BRPT(4,I)
        GEQ = GEQVEC(I)
        GOTO(1, 2, 3, 4) GEQ
          WRITE(STD6,*) ' *BUG:XXX* INVALID GEQ OPTION IN FIND_VOLUMES'
          STOP 'Abnormal stop: errors found.'
 1      CONTINUE
C         TRAPEZOIDAL RULE FOR VOLUMES IN THE ELEMENTS
          DO 100 J=FN,LN
            SUM = SUM + DXVEC(J)*0.5*(A(J-1) + A(J)) + POND(J)
 100      CONTINUE
          GOTO 190
 
 2      CONTINUE
C         VARIABLE WEIGHTING.
          DO 110 J=FN,LN
            WA = WXVEC(J)
            IF(QVEC(J-1) + QVEC(J).LT.0.0) THEN
              WA = 1. - WA
            ENDIF
            SUM = SUM + DXVEC(J)*(A(J-1) + WA*(A(J)-A(J-1))) + POND(J)
 110      CONTINUE
          GOTO 190
 
 3      CONTINUE
C         CURVILINEAR WEIGHTS USED
          DO 120 J=FN,LN
            SUM = SUM + 0.5*DXVEC(J)*(MA(J-1)*A(J-1) + MA(J)*A(J))
     A                + POND(J)
 120      CONTINUE
          GOTO 190
 
 4      CONTINUE
C         CURVILINEAR WEIGHTS PLUS VARIABLE WEIGHTING.
          DO 130 J=FN,LN
            WA = WXVEC(J)
            IF(QVEC(J-1) + QVEC(J).LT.0.0) THEN
              WA = 1. - WA
            ENDIF
            SUM = SUM + DXVEC(J)*((1. - WA)*MA(J-1)*A(J-1) +  WA*
     A                MA(J)*A(J)) + POND(J)
 130      CONTINUE
          GOTO 190
 
 190    CONTINUE
 200  CONTINUE
 
      IF(RESNUM.EQ.0) GOTO 400
        DO 300 J=1,RESNUM
          SUM = SUM + ABS(AE(RESVEC(J)))
 300      CONTINUE
 400  CONTINUE


C     Delay reservoir volumes
      DO 500 J=1,DLAY_KNT
        SUMA = SUMA + DLAY_Q(J)*DLAY_K(J)
500   CONTINUE 
C     Detention ponds
      DO 600 J=1,DTEN_KNT
        SUMA = SUMA + DTEN_NBAR(J)*DTEN_S(J)
600   CONTINUE
      LPRB_VOL = SUM
      DD_VOL = SUMA
      RETURN
      END
