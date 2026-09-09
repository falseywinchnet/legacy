C Miscellaneious routines.                                                      
C                                                                               
C                                                                               
C
C
C
      SUBROUTINE   OUTPRO
     I                   (STDOUT)
 
C     + + + PURPOSE + + +
C     Output the profile form of the matrix.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'matcom.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(' INDEX     VALUE')
 52   FORMAT(I6,1PE10.3)
 54   FORMAT(' INDEX       RHS')
 56   FORMAT(I6,1PE10.3)
C***********************************************************************
      WRITE(STDOUT,*) ' '
      WRITE(STDOUT,50)
 
      DO 100 I=1,C(NUMEQ)
        WRITE(STDOUT,52) I, PDAVEC(I)
 100  CONTINUE
 
C     OUTPUT THE RHS
      WRITE(STDOUT,*) ' '
      WRITE(STDOUT,54)
      DO 110 I=1,NUMEQ
        WRITE(STDOUT,56) I, RHS(I)
 110  CONTINUE
 
      WRITE(STDOUT,*) ' '
      RETURN
      END
C
C
C
      SUBROUTINE   FBRND
     I                  (INNODE, NBRA, BRPT, STDOUT,
     O                   BRA, NODE)
 
C     + + + PURPOSE + + +
C     Find the external branch and external node for a
C     given internal node number for the branch vectors
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER BRA, INNODE, STDOUT, NBRA, NODE
      INTEGER BRPT(8,NBRA)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     INNODE - internal node number for a node on a branch
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
C     STDOUT   - Fortran unit number for user output and messages
C     BRA    - branch number
C     NODE   - node number
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, IB, J
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *BUG:19* ERROR IN BRPT OR INNODE DETECTED IN FBRND.')
 51   FORMAT(I6,I5,/,(6I10))
C***********************************************************************
      DO 100 IB=1,NBRA
        IF(INNODE.GE.BRPT(3,IB).AND.INNODE.LE.BRPT(4,IB)) THEN
C         FOUND THE BRANCH
 
          NODE = BRPT(1,IB) + INNODE - BRPT(3,IB)
          BRA = IB
          RETURN
        ENDIF
 100  CONTINUE
 
      WRITE(STDOUT,50)
      WRITE(STDOUT, 51) INNODE, NBRA, ((BRPT(I,J), I=1,6), J=1,NBRA)
      STOP 'Abnormal stop: errors found.'
      END
C
C
C
      REAL FUNCTION   FMNARG
     I                      (ADRS)
 
C     + + + PURPOSE + + +
C     Find the minimum argument for the table stored at ADRS.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'stdun.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER TYPE
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER GETTBN
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETTBN
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(' *BUG:XXX* FMNARG INVALID WITH 2-D TABLE. TAB#=',I5,
     A       ' IS A 2-D TABLE.')
C***********************************************************************
      TYPE = ITAB(ADRS+2)
      IF(TYPE.EQ.6.OR.TYPE.EQ.10.OR.TYPE.EQ.13.OR.TYPE.EQ.14) THEN
        WRITE(STD6,50) GETTBN(ADRS)
        STOP 'Abnormal stop: errors found.'
      ELSE
        IF(TYPE.EQ.1.OR.TYPE.EQ.12.OR.
     A      (TYPE.GE.20.AND.TYPE.LE.25)) THEN
C         CROSS SECTION TABLE
          FMNARG = 0.0
        ELSE
C         TABLE OF TYPE 2, 3, 4, OR 11 AT THIS POINT
          FMNARG = FTAB(ADRS+OFF234)
        ENDIF
        RETURN
      ENDIF
      END
C
C
C
      SUBROUTINE   FNDELV
     I                   (NUM, STDOUT,
     O                    EFLAG, ELEV)
 
C     + + + PURPOSE + + +
C     Find the invert elevation of the cross section from the table
C     given by the table number in NUM.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, STDOUT, NUM
      REAL ELEV
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NUM    - table number
C     STDOUT   - Fortran unit number for user output and messages
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     ELEV   - value of elevation
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'

C     External program units
      CHARACTER GET_TABID*16
      EXTERNAL GET_TABID
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADRS
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *ERR:198* Cross sec. table Id= ',A,' not found for',
     A        ' elevation.')
 52   FORMAT(/,' *BUG:XXX* NUM < 0 in sub. FNDELV.')
C***********************************************************************
      IF(NUM.LE.0) THEN
        WRITE(STDOUT,52) NUM
        EFLAG = 1
        ELEV = 0.0
      ELSE
        ADRS = FTPNT(NUM)
        IF(ADRS.GT.0) THEN
          ELEV = FTAB(ADRS + 5)
        ELSE
C         TABLE DOES NOT EXIST
 
          WRITE(STDOUT,50) GET_TABID(NUM)
          EFLAG = 1
          ELEV = 0.0
        ENDIF
      ENDIF
      RETURN
      END


C
C
C
      SUBROUTINE FIND_HDD_FROM_TABN(
     I                              TABN, STDOUT,
     O                              STATUS, HDATUM)

C     Find the head datum for a two-D table given the table number.

      IMPLICIT NONE
      INTEGER TABN, STDOUT, STATUS

      REAL HDATUM

C     Called program units
      REAL GETHDD
      EXTERNAL GETHDD

C     Local
      INTEGER ADRS

      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
C     *********************************FORMATS**************************
 52   FORMAT(/,' *BUG:XXX* NUM < 0 in sub. FIND_HDD_FROM_TABN.')
C***********************************************************************
      IF(TABN.LE.0) THEN
        WRITE(STDOUT,52) TABN
        STOP 'Abnormal stop.  Bug found.'
      ELSE
        ADRS = FTPNT(TABN)
        IF(ADRS.GT.0) THEN
          STATUS = 1
          HDATUM = GETHDD(ADRS)
        ELSE
C         TABLE DOES NOT EXIST
          HDATUM = -1.E30
          STATUS = 0
        ENDIF
      ENDIF
      RETURN
      END

C
C
C
      SUBROUTINE   FNDGISID
     I                     (NUM, STDOUT,
     O                      EFLAG, GISID)
 
C     + + + PURPOSE + + +
C     Find the GISID string of the cross section from the table
C     given by the table number in NUM.

      IMPLICIT NONE 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, STDOUT, NUM
      CHARACTER*16 GISID
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NUM    - table number
C     STDOUT   - Fortran unit number for user output and messages
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     GISID  - GISID string for the cross section.  Any id the user
C              gives.
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'

C     External program units
      CHARACTER GET_GISID*16
      EXTERNAL GET_GISID

C     + + + LOCAL VARIABLES + + +
      INTEGER ADRS
 
C     + + + OUTPUT FORMATS + + +
 52   FORMAT(/,' *BUG:XXX* NUM < 0 in sub. FNDELV.')
C***********************************************************************
      IF(NUM.LE.0) THEN
        WRITE(STDOUT,52) NUM
        EFLAG = 1
        GISID = ' '
      ELSE
        ADRS = FTPNT(NUM)
        IF(ADRS.GT.0) THEN
         GISID = GET_GISID(ADRS)
        ELSE
         GISID = ' '
        ENDIF
      ENDIF
      RETURN
      END
C
C
C
      REAL FUNCTION   FROUDE
     I                      (ADRS, Y, Q, A, T, G)
 
C     + + + PURPOSE + + +
C     Find the square of the froude number for output.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
      REAL A, G, Q, T, Y
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB
C     Y      - maximum depth in section
C     Q      - flow rate
C     A      - Area of flow
C     T      - top width of the cross section
C     G      - acceleration due to gravity
 
C     + + + SAVED VALUES + + +
      INTEGER VTYPE(35)
      SAVE VTYPE
 
C     + + + LOCAL VARIABLES + + +
      REAL QC, YA
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER GETTYP
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETTYP, LKTQC
 
C     + + + DATA INITIALIZATIONS + + +
      DATA VTYPE/21*0,1,0,0,1,10*0/
C***********************************************************************
C     CHECK THE TABLE TYPE.  IF CRITICAL FLOW IS IN THE TABLE USE IT.
C     OTHERWISE IGNORE THE EFFECT OF NON-UNIFORM VELOCITY DISTRIBUTION
C     IN COMPUTING THE FROUDE NUMBER
 
 
      YA = Y
      IF(VTYPE(GETTYP(ADRS)).EQ.1) THEN
C       CRITICAL FLOW IS TABULATED.  FIND IT
 
        CALL LKTQC
     I            (ADRS,
     M             YA,
     O             QC)
 
        FROUDE =  (Q/QC)**2
      ELSE
        FROUDE = Q**2*T/(G*A**3)
      ENDIF
      RETURN
      END
C
C
C
      INTEGER FUNCTION   GETTYP
     I                         (ADRS)
 
C     + + + PURPOSE + + +
C     Get the table type of the table at ADRS.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
C***********************************************************************
      GETTYP = ITAB(ADRS+2)
      RETURN
      END
C
C
C
      CHARACTER*5 FUNCTION   GETUSN
     I                             (INN)
 
C     + + + PURPOSE + + +
C     Get the id string for a user node given the internal node number.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER INN
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     INN    - internal exterior node number
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'inusnb.cmn'
C***********************************************************************
      IF(INN.EQ.0) THEN
        GETUSN = '    0'
      ELSE
        GETUSN = INENUS(INN)
      ENDIF
      RETURN
      END
C
C
C
      SUBROUTINE   IASORT
     I                   (N,
     M                    X)
 
C     + + + PURPOSE + + +
C     Sort the integer array, X(*), of length N into ascending
C     numerical order.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER N
      INTEGER X(N)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     N      - number of items to sort
C     X      - values to sort
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, J, T
C***********************************************************************
      DO 200 I=2,N
        J = I
        T = X(J)
 100    CONTINUE
          IF(J.GT.1.AND.X(J-1).GT.T) THEN
            X(J) = X(J-1)
            J = J-1
            GOTO 100
          ENDIF
        X(J) = T
 200  CONTINUE
 
      RETURN
      END
C
C
C
      CHARACTER*5 FUNCTION   MAKENN
     I                             (PREFIX, NUM)
 
C     + + + PURPOSE + + +
C     Given the branch number and the prefix construct a valid
C     exterior node id for the new input style.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER NUM
      CHARACTER PREFIX*1
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     PREFIX - prefix for an exterior node label
C     NUM    - branch number
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'stdun.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, IS
      CHARACTER CHR5*5
C***********************************************************************
C     VALID NAME MUST BE THE CHARACTER FORM OF THE USER BRANCH
C     NUMBER PREFIXED BY THE PREFIX CHARACTER.  NO SPACES ALLOWED
C     IN THE ID AND THE ID SHOULD BE RIGHT JUSTIFIED IN THE STRING.
 
      WRITE(CHR5,'(I5)') NUM
C     SEARCH FOR SPACE FROM END OF STRING
      IS = 0
      DO 100 I=4,1,-1
        IF(CHR5(I:I).EQ.' ') THEN
          IS = I
          GOTO 110
        ENDIF
 100  CONTINUE
 
      IF(IS.EQ.0.AND.PREFIX.NE.' ') THEN
        WRITE(STD6,*) ' *BUG:XXX* IS=0 IN MAKENN'
        STOP 'Abnormal stop: errors found.'
      ELSE
        MAKENN = CHR5
        RETURN
      ENDIF
 110  CONTINUE
      CHR5(IS:IS) = PREFIX
      MAKENN = CHR5
      RETURN
      END
C
C
C
      CHARACTER*10 FUNCTION   NOTE
     I                            (J, EMC, EXNODT, EPT, NEX)
 
C     + + + PURPOSE + + +
C     Construct a note to help identify exterior nodes more clearly
C     in error messages.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EPT, J, NEX
      INTEGER EMC(EPT), EXNODT(9,NEX)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     J      - pointer to node number in EMC(*)
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
      INCLUDE 'inusnb.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER NODE
      CHARACTER DUMMY*10
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
C***********************************************************************
        NODE = ABS(EMC(J))
        IF(EXNODT(3,NODE).GT.0) THEN
                WRITE(DUMMY,'(A6,I4)') 'ON BR ',
     A                                    INBRUS(EXNODT(3, NODE))
        NOTE = DUMMY
        ELSE IF(EXNODT(3,NODE).EQ.0) THEN
                NOTE = 'FREE NODE '
        ELSE
                NOTE = 'RESERVOIR '
        ENDIF
        RETURN
        END
C
C
C
      SUBROUTINE   SORTCI
     I                   (N,
     M                    CVAL, IVAL)
 
C     + + + PURPOSE + + +
C     Sort CVAL in ascending order and move other values at
C     same time
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER N
      INTEGER IVAL(N)
      CHARACTER CVAL(N)*5
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     N      - number of items to sort
C     CVAL   - character values to sort
C     IVAL   - integer values to move as sort on CVAL takes place
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, J, TA
      CHARACTER T*5
C***********************************************************************
C     USE INSERTION SORT FROM PROGRAMMING PEARLS
C     COMM. OF ACM APRIL 1984
 
      DO 200 I=2,N
         J = I
         T = CVAL(J)
         TA = IVAL(J)
 100     CONTINUE
 
            IF(J.GT.1.AND.CVAL(J-1).GT.T) THEN
               CVAL(J) = CVAL(J-1)
               IVAL(J) = IVAL(J-1)
 
               J = J-1
 
               GOTO 100
            ENDIF
         CVAL(J) = T
         IVAL(J) = TA
 
 200  CONTINUE
 
      RETURN
      END
C
C
C
      SUBROUTINE   SORT2I
     I                   (N,
     M                    IVALS, IVAL)
 
C     + + + PURPOSE + + +
C     Sort IVALS in ascending order and move other values at
C     same time
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER N
      INTEGER IVALS(N), IVAL(N)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     N      - number of items to sort
C     IVALS   - character values to sort
C     IVAL   - integer values to move as sort on IVALS takes place
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, J, T, TA
C***********************************************************************
C     USE INSERTION SORT FROM PROGRAMMING PEARLS
C     COMM. OF ACM APRIL 1984
 
      DO 200 I=2,N
         J = I
         T = IVALS(J)
         TA = IVAL(J)
 100     CONTINUE
 
            IF(J.GT.1.AND.IVALS(J-1).GT.T) THEN
               IVALS(J) = IVALS(J-1)
               IVAL(J) = IVAL(J-1)
 
               J = J-1
 
               GOTO 100
            ENDIF
         IVALS(J) = T
         IVAL(J) = TA
 
 200  CONTINUE
 
      RETURN
      END
C
C
C
      SUBROUTINE   STRTY5
     I                   (NEWTAB, NDEP, Y, QC, M,
     M                    FTP, FTKNT, EFLAG)
 
C     + + + PURPOSE + + +
C     Store an internally generated table of type 5.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, FTKNT, FTP, NDEP, NEWTAB
      REAL*8 M(NDEP), QC(NDEP), Y(NDEP)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NEWTAB - table number
C     NDEP   - number of depth values
C     Y      - depth values
C     QC     - critical flows
C     M      - slope for the special internal table of type 5
C     FTP    - next open location in the function table storage
C     FTKNT  - function table counter
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADRS, I
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL KIL
C***********************************************************************
C     Check for space.
      IF((FTP+4+3*NDEP).GE.MRFTAB) CALL KIL
     I                                      (10,
     M                                       FTP, EFLAG)
 
      ADRS = FTP
C     Record address for the table
      FTPNT(NEWTAB) = ADRS
      FTKNT = FTKNT + 1
 
      ITAB(ADRS+1) = NEWTAB
      ITAB(ADRS+2) = 5
 
C     INITIALIZE LAST ADDRESS ACCESSED
      ITAB(ADRS+3) = ADRS + 5
      FTAB(ADRS+4) = 0.0
 
      ADRS = ADRS + 5
 
      DO 100 I=1,NDEP
        FTAB(ADRS)= Y(I)
        FTAB(ADRS+1) = QC(I)
        FTAB(ADRS+2) = M(I)
        ADRS = ADRS + 3
 100  CONTINUE
 
C     Store the high address
      ITAB(FTP) = ADRS - 3
      FTP = ADRS
 
      RETURN
      END
C
C
C
      SUBROUTINE   TBOX
     I                 (STDOUT)
 
C     + + + PURPOSE + + +
C     Write out title box.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
 
      INCLUDE 'version.cmn'
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT(1X,77('*'))
 2001 FORMAT(//)
 2010 FORMAT(1X,'*',75X,'*')
 2020 FORMAT(1X,'*',24X,'FULL EQUATIONS FLOW ROUTING',24X,'*')
 2030 FORMAT(/,' Version:',F5.2,' ',A)
 2040 FORMAT(
     A ' WARNING: This program is large and complex.  User is ',
     B 'totally responsible for',/,
     C ' any consequences resulting from application of ',
     D 'this program.  Read ',/,
     E ' disclaimer in the source code.  This program is not ',
     F 'to be sold in any form.')
C***********************************************************************

      WRITE(STDOUT,2001)
      WRITE(STDOUT,2000)
      WRITE(STDOUT,2010)
      WRITE(STDOUT,2020)
      WRITE(STDOUT,2010)
      WRITE(STDOUT,2010)
      WRITE(STDOUT,2000)
 
      WRITE(STDOUT,2030)  VERSION_NUMBER, VERSION_DATE
      WRITE(STDOUT,*) ' '
      WRITE(STDOUT,2040) 
      WRITE(STDOUT,*) ' '
      RETURN
      END
C
C
C
      REAL FUNCTION GET_STATION(ADRS)

C     Get the station from a cross-section table given the address of the table.
C     The table is known to exist. 

      IMPLICIT NONE
      INTEGER ADRS

      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
C***********************************************************************
      GET_STATION = FTAB(ADRS+4)
      RETURN
      END

C
C
C
      SUBROUTINE SEEK_FREE_NODE_STATIONS(STDOUT, NBRA, NEX, BRPT, 
     I            EMC,
     M            EXNODT)

C     Scan EMC seeking to assign stations to all free nodes for
C     which this is possible. 
C     
      IMPLICIT NONE
      INCLUDE 'arsize.prm'
      INTEGER NBRA, NEX, STDOUT, BRPT(8,NBRA), EXNODT(9,NEX),
     A        EMC(MREMC)

      REAL*8 NODEX, NODEY

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

      INCLUDE 'bnothr.cmn'
      INCLUDE 'matcom.cmn'


C     Called program units
      REAL GET_STATION
      EXTERNAL GET_STATION



C     Local
      INTEGER ADRS, CODE, IENTRY, IPNT, J, K, KNT, N, CNN, CLASS,
     A        NULL

      REAL*8 X,  SUMX, STATION

      DATA  NULL/-2147483647/
C***********************************************************************
C     Scan over all CODE 2 entries and ccompute the stations for any
C     free nodes that are in the junction with one or more branch nodes.

      IENTRY = 0


 100  CONTINUE
        IENTRY = IENTRY + 1
        IPNT = ADD(IENTRY)
        CODE = EMC(IPNT)
        IF(CODE.EQ.2) THEN
          N = EMC(IPNT+1)
C         Scan for nodes on branches and compute the average station
C         for them.  
          KNT = 0
          SUMX = 0.D0
          DO 150 K=1,N
            CNN = EMC(IPNT+1+K)
            CLASS = EXNODT(3,CNN)
            IF(CLASS.GT.0) THEN
C             We have a branch. Get the station.
              ADRS = EXNODT(4,CNN)
              X = GET_STATION(ADRS)
              KNT = KNT + 1
              SUMX = SUMX + X
            ENDIF
150       CONTINUE 
          IF(KNT.GT.0) THEN
C           Compute the average value for the station
            STATION = SUMX/DBLE(KNT)
C           Now scan the junction again and assign the average station from
C           branch nodes to any free nodes in the junction but only if
C           the free node has a NULL value for station. 
            DO 160 K=1,N
              CNN = EMC(IPNT+1+K)
              CLASS = EXNODT(3,CNN)
              IF(CLASS.LE.0) THEN
C               We have a free node
                IF(EXNODT(8,CNN).EQ.NULL) THEN
                  EXNODT(8,CNN) = NINT(STATION*1.D4)
                ENDIF
              ENDIF
160         CONTINUE 
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
      SUBROUTINE DMPEQS(STDOUT, FIRST, LAST, KOUNT, JTIME)


C     Ouput the selected equations in the network matrix.  Used
C     for special debugging 

      IMPLICIT NONE
      INTEGER STDOUT, FIRST, LAST, KOUNT
      REAL*8 JTIME

C     Called program units
      CHARACTER GETUSN*5

      EXTERNAL GETUSN

C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'matcom.cmn'
      

C     Local variables
      INTEGER HALF,LOWER, UPPER, NEQ
      PARAMETER (HALF=5000)
      INTEGER I, J, K, N, KMIN, KMAX,
     A        VARNUM(20), VN, GLOBAL_KMIN, GLOBAL_KMAX
      REAL*8 A(-HALF:HALF), COEF(50), MINCOEF, MAXCOEF,
     A  GLOBAL_MINCOEF, GLOBAL_MAXCOEF
      CHARACTER OUTPUT(10)*12, EQVAR*12, OUTMIN*12, OUTMAX*12
C     *****************************FORMATS******************************
50    FORMAT(/,' Selected block of equations from Network Matrix',
     *   ' KOUNT=',I5,/,
     A'EqNum  Coefficients . . . . . . . . . . . . . . . . . . . . .',
     B' . . . . . . . . . . . . . . . . . . . .  Rghthnd Sd',
     C'  Correction Variable ID')
52    FORMAT(I10,I10,I10)
54    FORMAT(25I10)
55    FORMAT(I5,10A12,A12,2A12)
56    FORMAT(5X,10A12)
58    FORMAT(/,' Band limits=',I10,I10)
60    FORMAT(/,' Min/Max coef=',1PD15.5,1PD15.5)
C***********************************************************************
      GLOBAL_KMIN = 123456789
      GLOBAL_KMAX =-123456789
      GLOBAL_MINCOEF = 1.D100
      GLOBAL_MAXCOEF =-1.D100

      WRITE(STDOUT,50) KOUNT
C     Place the diagonal element at index 0. 

      IF(LAST.LT.0) THEN
        UPPER = NUMEQ
      ELSEIF(LAST.GT.NUMEQ) THEN
        UPPER = NUMEQ
      ELSE
        UPPER = LAST
      ENDIF

      IF(FIRST.LT.0) THEN
        LOWER = 1
      ELSEIF(FIRST.GT.NUMEQ) THEN
        LOWER = 1
      ELSE
        LOWER = FIRST
      ENDIF

      NEQ = UPPER - LOWER + 1

C      WRITE(45) NEQ, KOUNT, JTIME
      DO 500 I=LOWER, UPPER 

C       Define the id string for the variable on the diagonal of this
C       equation.
        EQVAR = ' '
        IF(VARID(I).EQ.0) THEN
C         We don't have an assigned id.  Use the 
C         variable number itself
          IF(MOD(I,2).EQ.0) THEN
            WRITE(EQVAR,'(6X,I4,'':Y'')') I
          ELSE
            WRITE(EQVAR,'(6X,I4,'':Q'')') I
          ENDIF
        ELSE
C         We have an exterior node number
          IF(MOD(I,2).EQ.0) THEN
            EQVAR(6:12) = GETUSN(VARID(I))//':Y'
          ELSE
            EQVAR(6:12) = GETUSN(VARID(I))//':Q'
          ENDIF
        ENDIF


C       C(I) points to the last element in the column that ends with the
C       diagonal element  for the I-th equation.  It only includes 
C       the potentially non-zero values from the diagonal element 
C       upward to the equations above the I-th equation.  Its first
C       element is given by R(I) + 1.

C       R(I) points to the last element on the I-th row that ends just
C       to the left of the diagonal element.   The first element
C       in the potentially non-zero values on ths row is given 
C       by C(I-1) + 1.  

C       Extract the elements on the row that are to the left of the 
C       main diagonal if they exist. They may not exist in all cases.
C         

        K = 0
        DO 100 J=R(I), C(I-1) +1, -1
          K = K - 1
          A(K) = PDAVEC2(J)
100     CONTINUE
        KMIN = K 

C       Now extract the diagonal element and those to the right. 

        K = 0
        A(K) = PDAVEC2(C(I))
        K = 1
        KMAX = EQEND(I)
200     CONTINUE
        
          IF(K.LE.KMAX) THEN
            IF(C(I+K) - K.GE.R(I+K) + 1) THEN
              A(K) = PDAVEC2(C(I+K) - K)
            ELSE
              A(K) = 0.0
            ENDIF
            K = K + 1
            GOTO 200
          ENDIF
      
C        WRITE(STDOUT,52) I, KMIN, KMAX
        GLOBAL_KMIN = MIN(KMIN, GLOBAL_KMIN)
        GLOBAL_KMAX = MAX(KMAX, GLOBAL_KMAX)

C        WRITE(45) I, KMIN, KMAX, (A(K), K=KMIN,KMAX), RHS2(I), RHS(I),
C     A           EQVAR
        N = 0
        MINCOEF = 1.D100
        MAXCOEF = -1.D100
        DO 300 K=KMIN,KMAX
          IF(A(K).NE.0.0) THEN
            N = N + 1
            VARNUM(N) = K + I
            COEF(N) = A(K)
            MINCOEF = MIN(ABS(COEF(N)), MINCOEF)
            MAXCOEF = MAX(ABS(COEF(N)), MAXCOEF)
          ENDIF
300     CONTINUE
        DO 350 J=1,N
C         Construct variable numbers and names (when known)
          VN = VARNUM(J)
          OUTPUT(J) = ' '
          IF(VARID(VN).EQ.0) THEN
C           We don't have an assigned id.  Use the 
C           variable number itself
            IF(MOD(VN,2).EQ.0) THEN
              WRITE(OUTPUT(J),'(6X,I4,'':Y'')') VN
            ELSE
              WRITE(OUTPUT(J),'(6X,I4,'':Q'')') VN
            ENDIF
          ELSE
C           We have an exterior node number
            IF(MOD(VN,2).EQ.0) THEN
              OUTPUT(J)(6:12) = GETUSN(VARID(VN))//':Y'
            ELSE
              OUTPUT(J)(6:12) = GETUSN(VARID(VN))//':Q'
            ENDIF
          ENDIF
350     CONTINUE

        DO 360 J=N+1,10
          OUTPUT(J) = ' '
360     CONTINUE

        WRITE(STDOUT,56) OUTPUT
        
        DO 370 J=1,N
          WRITE(OUTPUT(J),'(1PE12.4)') COEF(J)
370     CONTINUE
        DO 380 J=N+1,8
          OUTPUT(J) = ' . . . . . .'
380     CONTINUE
        WRITE(OUTPUT(9),'(1PE12.4)') RHS2(I)
        WRITE(OUTPUT(10),'(1PE12.4)') RHS(I)
        WRITE(OUTMIN,'(1PE12.4)') MINCOEF
        WRITE(OUTMAX,'(1PE12.4)') MAXCOEF
        WRITE(STDOUT,55) I, OUTPUT, EQVAR, OUTMIN, OUTMAX
    
        GLOBAL_MINCOEF = MIN(MINCOEF, GLOBAL_MINCOEF)
        GLOBAL_MAXCOEF = MAX(MAXCOEF, GLOBAL_MAXCOEF)

500   CONTINUE
      WRITE(STDOUT,58) GLOBAL_KMIN, GLOBAL_KMAX
      WRITE(STDOUT,60) GLOBAL_MINCOEF, GLOBAL_MAXCOEF

      RETURN
      END

              




