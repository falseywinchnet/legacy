C
C
C
      SUBROUTINE INITIALIZE_GENSCN()

C     Initialize various values in the GENSCN system 
      IMPLICIT NONE

      INCLUDE 'genscn.cmn'
C***********************************************************************
C     Clear the unit numbers, location counter, and set the record
C     counter to its default initial value.
      FEO_UNIT = 0
      TSD_UNIT = 0
      FTF_UNIT = 0
      GENSCN_NOUT = 0
      GENSCN_RECORD_KNT = 0
      RETURN
      END

C
C
C
      SUBROUTINE WRITE_FTFA(STDOUT, FTF_UNIT, FTP,
     O                  NUMBER_OF_FULL_RECORDS, ITEMS_PER_RECORD,
     O                  LEFTOVER_ITEM_KNT)

C     Output the function table vector.  Some changes to
C     the original to set the zero-th element and also
C     correct the error in the number of full records
C     that results in there being an extra element written.

      IMPLICIT NONE
      INTEGER FTF_UNIT, FTP, NUMBER_OF_FULL_RECORDS, 
     A  ITEMS_PER_RECORD, LEFTOVER_ITEM_KNT, STDOUT

      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'

C     Local

      INTEGER  I, J, JS, JE
C******************************************************************
      FTAB(0) = 0.0
C      WRITE(STDOUT,*) ' In WRITE_FTFA: FTP=',FTP
      ITEMS_PER_RECORD = 512
      NUMBER_OF_FULL_RECORDS = (FTP)/ITEMS_PER_RECORD
C      WRITE(STDOUT,*) ' In WRITE_FTFA: NUMBER_OF_FULL_RECORDS=',
C     A                  NUMBER_OF_FULL_RECORDS
      
      LEFTOVER_ITEM_KNT = FTP  - 
     A   NUMBER_OF_FULL_RECORDS*ITEMS_PER_RECORD

C      WRITE(STDOUT,*) ' In WRITE_FTFA: LEFTOVER=',
C     A            LEFTOVER_ITEM_KNT

      JS = 0
      DO 100 I=1,NUMBER_OF_FULL_RECORDS
        JE = JS + ITEMS_PER_RECORD - 1
C        WRITE(FTF_UNIT,REC=I) (FTAB(J), J=JS,JE)
        WRITE(FTF_UNIT) (FTAB(J), J=JS,JE)
        JS = JE + 1
100   CONTINUE
      IF(LEFTOVER_ITEM_KNT.GT.0) THEN
C       Write a partial record.
        JE = JS + LEFTOVER_ITEM_KNT -1
C        DO 110 J=JE+1,ITEMS_PER_RECORD
C          FTAB(J) = 0.0
C110     CONTINUE
C        JE = JS + ITEMS_PER_RECORD - 1
C        WRITE(FTF_UNIT,REC=NUMBER_OF_FULL_RECORDS+1) (FTAB(J), J=JS,JE)
        WRITE(FTF_UNIT) (FTAB(J), J=JS,JE)
      ENDIF
      RETURN
      END

C
C
C
      SUBROUTINE WRITE_FTF(STDOUT, FTF_UNIT, FTP,
     O                  NUMBER_OF_FULL_RECORDS, ITEMS_PER_RECORD,
     O                  LEFTOVER_ITEM_KNT)

C     Output the function table vector. 

      IMPLICIT NONE
      INTEGER FTF_UNIT, FTP, NUMBER_OF_FULL_RECORDS, 
     A  ITEMS_PER_RECORD, LEFTOVER_ITEM_KNT, STDOUT

      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'

C     Local

      INTEGER  I, J, JS, JE
C******************************************************************
      FTAB(0) = 0.0
C      WRITE(STDOUT,*) ' In WRITE_FTF: FTP=',FTP
      ITEMS_PER_RECORD = 512
      NUMBER_OF_FULL_RECORDS = (FTP+1)/ITEMS_PER_RECORD
C      WRITE(STDOUT,*) ' In WRITE_FTF: NUMBER_OF_FULL_RECORDS=',
C     A                  NUMBER_OF_FULL_RECORDS
      
      LEFTOVER_ITEM_KNT = FTP +1 - 
     A   NUMBER_OF_FULL_RECORDS*ITEMS_PER_RECORD

C      WRITE(STDOUT,*) ' In WRITE_FTF: LEFTOVER=',
C     A            LEFTOVER_ITEM_KNT

      JS = 0
      DO 100 I=1,NUMBER_OF_FULL_RECORDS
        JE = JS + ITEMS_PER_RECORD - 1
        WRITE(FTF_UNIT) (FTAB(J), J=JS,JE)
        JS = JE + 1
100   CONTINUE
      IF(LEFTOVER_ITEM_KNT.GT.0) THEN
C       Write a partial record.
        JE = JS + LEFTOVER_ITEM_KNT -1
        WRITE(FTF_UNIT) (FTAB(J), J=JS,JE)
      ENDIF
      RETURN
      END

C
C
C
      SUBROUTINE GENSCN_INPUT(
     I          STDIN, STDOUT, BRPT, EXNODT, NBRA, NEX, NRWTA, RWTA,
     I          RTAP, SFAC, FTP,
     O           EFLAG)

      IMPLICIT NONE
C     Process the specification for the GENSCN data. 
      INCLUDE 'arsize.prm'

      INTEGER EFLAG, STDIN, STDOUT, NBRA, NRWTA, FTP, NEX
     A        
      INTEGER BRPT(8,NBRA), EXNODT(9,NEX), RTAP(MNFREE),
     A        RWTA(MNFREE)
 
      REAL SFAC
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
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
C     NBRA   - number of branches in the model
C     NRWTA  - number of reservoirs with tributary area
C     RWTA   - reservoirs with tributary area
C     RTAP   - reservoir tributary area pointer
C     SFAC   - station factor for branches.
C     FTP    - pointer to next open location in FTAB/ITAB function
C              table storage vector.

      INCLUDE 'genscn.cmn'
      INCLUDE 'misccon.cmn'
      INCLUDE 'julian.cmn'
      INCLUDE 'gatcom.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'enothr.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'version.cmn'
      INCLUDE 'home.cmn'

C     Local variables.

      CHARACTER  FEO_NAME*64, TSD_NAME*64, FTF_NAME*64, LINE*80,
     A           CHAR5*5, USER_ID_STRING*12, HEAD*80,
     B        LOCATION_CLASS*5

      INTEGER IOFLAG, TSD_START, BRAIN, FA, FN, NDE, NODE, LN, IP,
     A        FTAB_INDEX, RECORD_LENGTH_IN_BYTES, BRA, I, IT, NXT,
     B        NUMBER_OF_FULL_RECORDS, ITEMS_PER_RECORD,
     C        LEFTOVER_ITEM_KNT

      REAL STATION, INVERT_ELEVATION


      INTEGER GET_UNIT
      CHARACTER GETTOK*5
      EXTERNAL GET_UNIT, GETTOK, LSTAB, FREE_UNIT
C     ***************************FORMATS***************************************
2     FORMAT(A)

 3    FORMAT(80A)
 5    FORMAT(I5,A5,1X,A12)
 
 4    FORMAT(' ',A80)
 6    FORMAT(' ',I5,A5,1X,A12)
 7    FORMAT(' *ERR:147* Output requested at too many nodes. NOUT = ',
     1   I5)

50    FORMAT('-VERSION',/,'FEQ:',F5.2,//,'-FILES')
 51   FORMAT(' *ERR:172* Exterior node',A5,' does not have trib.',
     A    ' area or is not a reservoir.')
52    FORMAT(A64)

54    FORMAT(//,'-UNITS',/,
     A       'STATION_UNIT_NAME= miles               ',/,
     B       'ELEVATION_UNIT_NAME= feet              ',/,
     C       'FLOW_UNIT_NAME= Cubic feet per second  ',/,
     D       'GATE_OPENING_UNIT_NAME= feet           ',/,
     E       'STORAGE_UNIT_NAME= acre-feet           ',/,
     F       'STORAGE_UNIT_FACTOR=2.295684E-5        ',/,
     G       'SURFACE_AREA_UNIT_NAME=square miles    ',/,
     H       'SURFACE_AREA_FACTOR=3.587006e-8        ')

56    FORMAT(//,'-TSD',/
     A       'LOCATION_KNT=',I8,/,
     B       ' SYR SMN SDY    SHOUR          SJTIME       SREC',/,
     C       I4,I4,I4,F9.5,F16.8,I11)
C     D       ' EYR EMN EDY    EHOUR          EJTIME       EREC',/,
C     E       I4,I4,I4,F9.5,F16.8,I11)

58    FORMAT(//,'-TSDDIR',/,
     A'      FEQ LOCTN BRAN   NODE         STATION     INVERT ',
     A'       USERID',
     B'     FTAB   Series',/,
     C'    LABEL CLASS   #      ID                   ELEVATION',
     C'       STRING',
     D'    index   offset',/,
     E' -------- ----- -----  ----- --------------- ----------',
     E' ------------',
     F' -------- --------')
68    FORMAT(/,' *WRN:58* No home name found following HOME=. ',
     A         ' Home name cleared.')
69    FORMAT(/,' Home directory/drive is: ',A)
70    FORMAT(1X,A8,1X,A5,1X,I5,1X,A6,1X,1PE15.6,1X,0PF10.4,1X,A12,1X,
     A I8,1X,I8)
72    FORMAT(1X,8X,1X,5X,1X,'   -1')
74    FORMAT(//'-FTF',/,
     A 'NUMBER_OF_FULL_RECORDS=',I8,/,
     B 'ITEMS_PER_RECORD=',I8,/,
     C 'LETOVER_ITEM_KNT=',I8)

C*********************************************************************
      CALL CLEAR_HOME()
      CALL INL80
     I          (STDIN, STDOUT,
     O           LINE)
      CALL STRIP_L_BLANKS(
     M                     LINE)
      IF(LINE(1:4).EQ.'HOME'.OR.LINE(1:4).EQ.'home') THEN
        IT = INDEX(LINE, '=')
        NXT = IT + 1
        CALL NXTTOK
     I             (LINE,
     M              NXT,
     O              HOME)
        IF(NXT.LE.0) THEN
          WRITE(STDOUT,68) 
          HOME = ' '
        ENDIF
        CALL STRIP_L_BLANKS(
     M                      HOME)
        IT = LEN_TRIM(HOME)
        WRITE(STDOUT,69) HOME(1:IT)

        CALL INL80
     I            (STDIN, STDOUT,
     O             LINE)
      ENDIF
C     Input the three file names for now.  Refine later
C      CALL INL80
C     I          (STDIN, STDOUT,
C     O           LINE)

      READ(LINE,2) FEO_NAME
      CALL MAYBE_ADD_HOME(
     M                    FEO_NAME)
      WRITE(STDOUT,'(A)') FEO_NAME
      CALL INL80
     I          (STDIN, STDOUT,
     O           LINE)
      READ(LINE,2) TSD_NAME
      CALL MAYBE_ADD_HOME(
     M                    TSD_NAME)
      WRITE(STDOUT,'(A)') TSD_NAME
      CALL INL80
     I          (STDIN, STDOUT,
     O           LINE)
      READ(LINE,2) FTF_NAME
      CALL MAYBE_ADD_HOME(
     M                    FTF_NAME)
      WRITE(STDOUT,'(A)') FTF_NAME


C     Open the FEO file.  Assume each case is new for now.  Add support
C     for update later.
      FEO_UNIT = GET_UNIT(STDOUT)
      OPEN(FEO_UNIT, FILE=FEO_NAME, FORM='FORMATTED',
     A        STATUS='UNKNOWN', IOSTAT=IOFLAG)
 
      IF(IOFLAG.NE.0) THEN
        WRITE(STDOUT,*) ' Problem in opening file: ',FEO_NAME
        WRITE(STDOUT,*) ' Check path for *.feo file.'
        STOP 'Abnormal stop: errors found.'
      ENDIF

      WRITE(FEO_UNIT,50) VERSION_NUMBER
      WRITE(FEO_UNIT,52) FEO_NAME
      WRITE(FEO_UNIT,52) TSD_NAME
      WRITE(FEO_UNIT,52) FTF_NAME

C     Write the unit names and conversion factors.  Expand later.

      WRITE(FEO_UNIT,54) 


C     Open the FTF file and store the function table vector in it. 
      FTF_UNIT = GET_UNIT(STDOUT)
      OPEN(FTF_UNIT, FILE=FTF_NAME, FORM='UNFORMATTED',
     A        STATUS='UNKNOWN', IOSTAT=IOFLAG)
 
      IF(IOFLAG.NE.0) THEN
        WRITE(STDOUT,*) ' Problem in opening file: ',FTF_NAME
        WRITE(STDOUT,*) ' Check path for *.ftf file.'
        STOP 'Abnormal stop: errors found.'
      ENDIF
      CALL WRITE_FTF(STDOUT, FTF_UNIT, FTP,
     O              NUMBER_OF_FULL_RECORDS, ITEMS_PER_RECORD,
     O              LEFTOVER_ITEM_KNT)
      CALL FREE_UNIT(STDOUT, FTF_UNIT)

C     Write description of the FTF file to the FEO file
      WRITE(FEO_UNIT,74) NUMBER_OF_FULL_RECORDS, ITEMS_PER_RECORD,
     O              LEFTOVER_ITEM_KNT

     

C     For initial testing adapt the special output processing code
C     and expand to include some generic groups of nodes later. 

      CALL INL80
     I            (STDIN, STDOUT,
     O             LINE)
      READ(LINE,3) HEAD
      WRITE(STDOUT,4) HEAD

      WRITE(FEO_UNIT,58)  
      GENSCN_NOUT = 0
 100    CONTINUE
        CALL INL80
     I            (STDIN, STDOUT,
     O             LINE)
        READ(LINE,5,ERR=991) BRAIN, CHAR5, USER_ID_STRING
        IF(BRAIN.LT.0) GOTO 150
        WRITE(STDOUT,6) BRAIN, CHAR5, USER_ID_STRING
        GENSCN_NOUT = GENSCN_NOUT +1
        IF(GENSCN_NOUT.LE.MNGSOUT) GOTO 110
          WRITE(STDOUT,7) GENSCN_NOUT
          GENSCN_NOUT = 1
          EFLAG = 1
 110    CONTINUE
 
        IF(BRAIN.NE.0) GOTO 120
 
C       EXTERIOR NODE
           CALL GETINN
     M                (CHAR5,
     O                 EFLAG, NODE)
           IF(NODE.GT.0) THEN
             GENSCN_POUT(GENSCN_NOUT) = -NODE
           ELSE
C            ONLY RESERVOIR NODES WITH TRIBUTARY AREA ARE VALID
C            HERE.
             NODE = IABS(NODE)
             DO 112 I=1,NRWTA
               IF(NODE.EQ.RWTA(I)) THEN
                 GENSCN_POUT(GENSCN_NOUT) = -(RTAP(I) + 10000)
                 GOTO 100
               ENDIF
 112         CONTINUE
             WRITE(STDOUT,51) CHAR5
             EFLAG = 1
           ENDIF

           WRITE(STDOUT,*) ' Internal node #=',NODE

C          Identify the character of the exterior node.
           IF(EXNODT(3,NODE).GT.0) THEN
C            Exterior node for a branch. 
             IP = EXNODT(2,NODE)
             STATION = XVEC(IP)/SFAC
             INVERT_ELEVATION = ZVEC(IP)
             FTAB_INDEX = EXNODT(4,NODE)
             LOCATION_CLASS = 'BNODE'
           ELSEIF(EXNODT(3,NODE).EQ.0) THEN
C            Exterior node not on a branch and not a LPR
             STATION = -1.E30
             INVERT_ELEVATION = ZE(NODE)
             FTAB_INDEX = 0
             LOCATION_CLASS = 'FNODE'
           ELSE
C            Has to be a LPR node.  
             STATION = -1.E30
             INVERT_ELEVATION = ZE(NODE)
             FTAB_INDEX = EXNODT(4,NODE)
             LOCATION_CLASS = 'LPR  '
           ENDIF
C          Write the next line to the FEO file.

           WRITE(FEO_UNIT,70) ENODID(NODE), LOCATION_CLASS, BRAIN, 
     A        CHAR5, STATION, INVERT_ELEVATION, USER_ID_STRING,
     B                       FTAB_INDEX, 1+2*(GENSCN_NOUT-1)

           GOTO 100
 120    CONTINUE
        READ(CHAR5,'(I5)',ERR=991) NODE
        CALL GETINB
     M             (BRAIN,
     O              EFLAG, BRA)
        FN = BRPT(1,BRA)
        LN = BRPT(2,BRA)
        FA = BRPT(3,BRA)

        IF(NODE.EQ.0) THEN
C         Dump the whole branch option.
          GENSCN_NOUT = GENSCN_NOUT - 1
          DO 130 NODE=FN,LN
            GENSCN_NOUT = GENSCN_NOUT + 1
            IP = FA + ABS(NODE) - FN
            GENSCN_POUT(GENSCN_NOUT) = IP
            STATION = XVEC(IP)/SFAC
            INVERT_ELEVATION = ZVEC(IP)
            FTAB_INDEX = NSEC(IP)
            LOCATION_CLASS = 'BNODE'
            WRITE(CHAR5,'(I5)') NODE
            WRITE(FEO_UNIT,70) BNODID(IP), LOCATION_CLASS, BRAIN, CHAR5,
     A                      STATION, INVERT_ELEVATION, USER_ID_STRING,
     B                      FTAB_INDEX, 1+2*(GENSCN_NOUT-1)
130      CONTINUE
         GOTO 100
        ENDIF

        IF(ABS(NODE).LT.FN.OR.ABS(NODE).GT.LN) THEN
          NDE = ABS(NODE)
          CALL KIL
     I             (2,
     M              NDE, EFLAG)
          NODE = -NDE
        ENDIF
 
C       COMPUTE ADDRESS FOR THIS BRANCH AND NODE NUMBER
        IP = FA + ABS(NODE) - FN
        IF(NODE.GT.0) THEN
          GENSCN_POUT(GENSCN_NOUT) = IP
        ELSE
         GENSCN_POUT(GENSCN_NOUT) = IP + 10000
        ENDIF
 
C       Identify character of the node.
        STATION = XVEC(IP)/SFAC
        INVERT_ELEVATION = ZVEC(IP)
        FTAB_INDEX = NSEC(IP)
        LOCATION_CLASS = 'BNODE'
        WRITE(FEO_UNIT,70) BNODID(IP), LOCATION_CLASS, BRAIN, CHAR5,
     A                    STATION, INVERT_ELEVATION, USER_ID_STRING,
     B                    FTAB_INDEX, 1+2*(GENSCN_NOUT-1)

        GOTO 100
 
 150  CONTINUE

C     Write a terminating signal to the directory list. 
      WRITE(FEO_UNIT,72) 


C     Only write the starting values now because we do not know the 
C     ending record at this time. 

      TSD_START = 1
      WRITE(FEO_UNIT,56) GENSCN_NOUT, SYR, SMN, SDY, SFRAC, SJTIME,
     A                   TSD_START


C     Open the TSD direct file. 

      RECORD_LENGTH_IN_BYTES = 8*(1 + GENSCN_NOUT)

      TSD_UNIT = GET_UNIT(STDOUT)
      OPEN(TSD_UNIT, FILE=TSD_NAME, FORM='UNFORMATTED',
     A        STATUS='UNKNOWN', ACCESS='DIRECT',
     B        RECL=RECORD_LENGTH_IN_BYTES, IOSTAT=IOFLAG)
 
      IF(IOFLAG.NE.0) THEN
        WRITE(STDOUT,*) ' Problem in opening file: ',TSD_NAME
        WRITE(STDOUT,*) ' Check path for *.tsd file.'
        STOP 'Abnormal stop: errors found.'
      ENDIF

      RETURN

 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE
        STOP 'Abnormal stop: errors found.'
      END
C
C
C
      SUBROUTINE GENSCN_CLOSE(STDOUT, TERMINATION) 

C     Close the GENSCN system

      IMPLICIT NONE
      INTEGER TERMINATION,  STDOUT


      INCLUDE 'genscn.cmn'

C     Local
      CHARACTER*8 TERM_NATURE

      INTEGER MJD, YR, MN, DY

      REAL HR

      REAL*8 DYFRAC
      EXTERNAL FREE_UNIT, INVMJD
C     **************************FORMATS*********************************
56    FORMAT( 
     D       ' EYR EMN EDY    EHOUR          EJTIME       EREC',/,
     E       I4,I4,I4,F9.5,F16.8,I11)

58    FORMAT(//,'-TERMINATION',/,A8)
C***********************************************************************

C     This routine will be called even if GENSCN has not been enabled.
      IF(FEO_UNIT.GT.0) THEN

C       Construct the calander date from the last JTIME written to
C       the TSD file.  The current JTIME and date may not be the 
C       same as the time point last written to the TSD file if
C       termination is abnormal. 

        MJD = INT(GENSCN_JTIME)
        DYFRAC = GENSCN_JTIME - DBLE(MJD)
        HR = 24.D0*DYFRAC
        CALL INVMJD
     I               (MJD,
     O                YR, MN, DY)
        
        WRITE(FEO_UNIT,56)  YR, MN, DY, HR, GENSCN_JTIME, 
     A                     GENSCN_RECORD_KNT 

C       Write the termination category
        IF(TERMINATION.EQ.1) THEN
          TERM_NATURE = 'NORMAL'
        ELSE
          TERM_NATURE = 'ABNORMAL'
        ENDIF
        WRITE(FEO_UNIT,58) TERM_NATURE

        CALL FREE_UNIT(STDOUT,FEO_UNIT)
        CALL FREE_UNIT(STDOUT,TSD_UNIT) 
      ENDIF
      RETURN
      END              





C
C
C
       SUBROUTINE   OUT_GENSCN
     I                  (STDOUT, JTIME)
 
C     + + + PURPOSE + + +
C     Write a record for the file used to define results for
C     later access using the GENSCN software
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT
      REAL*8 JTIME 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     JTIME - modified julian time.
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'misccon.cmn'
      INCLUDE 'genscn.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'gatcom.cmn'
C      INCLUDE 'mhenry.cmn'

 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADR, I, J, IOFF 
     
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C***********************************************************************
C     Fill the vector for output.       
      DO 100 I=1,GENSCN_NOUT
        IOFF = 1 + 2*(I-1)
        ADR = GENSCN_POUT(I)
        IF(ADR.GT.0) GOTO 90
C          EXTERIOR NODE
           ADR = ABS(ADR)
C           WRITE(STDOUT,*) ' ADR for exnode=',ADR
           IF(ADR.LT.10000) THEN
C             WRITE(STDOUT,*) ' IOFF=',IOFF, 'Q=',QE1(ADR)
             GENSCN_OUT_VEC(IOFF) =  QE1(ADR)
              GENSCN_OUT_VEC(IOFF+1) = YE1(ADR) + ZE(ADR)
           ELSEIF(ADR.LT.20000) THEN
C            Tributary-area flow at an exterior node.
             ADR = ADR - 10000
             GENSCN_OUT_VEC(IOFF) =  QPVEC(ADR)
             GENSCN_OUT_VEC(IOFF+1) = 1.0
           ELSEIF(ADR.EQ.20000) THEN
C            MCHENRY SLUICE GATE
C            REPORT FLOW TYPE AND GATE OPENING.
             GENSCN_OUT_VEC(IOFF) = FCLASS_CODE(MNGATE+1) 
             GENSCN_OUT_VEC(IOFF+1) = GOPEN(MNGATE+1)
           ELSE
C            Gates/pumps other than McHenry.   Get items from standard
C            locations set by subroutines called in SETEXT. 
             ADR = ADR - 20000
             GENSCN_OUT_VEC(IOFF) = FCLASS_CODE(ADR) 
             GENSCN_OUT_VEC(IOFF+1) = GOPEN(ADR)
           ENDIF
           GOTO 100
 90     CONTINUE
        IF(ADR.LT.10000) THEN
           GENSCN_OUT_VEC(IOFF) = Q1(ADR)
           GENSCN_OUT_VEC(IOFF+1) = Y1(ADR) + ZVEC(ADR)
        ELSE
C         Tributrary-area flow at for an element on a branch.
          ADR = ADR - 10000
          GENSCN_OUT_VEC(IOFF) =  QPVEC(ADR)
          GENSCN_OUT_VEC(IOFF+1) = 1.0
        ENDIF
 100  CONTINUE
      GENSCN_RECORD_KNT = GENSCN_RECORD_KNT + 1
      GENSCN_JTIME = JTIME
      WRITE(TSD_UNIT,REC=GENSCN_RECORD_KNT) JTIME,
     A                (GENSCN_OUT_VEC(J), J=1,IOFF+1)
      RETURN
      END
C
C
C
      INTEGER FUNCTION GET_SOURCE
     I                           (ADR)

C     Get the source flag for the cross section table at address, ADR.

      INTEGER ADR

      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
C***********************************************************************
      GET_SOURCE = ITAB(ADR+20)
      RETURN
      END

C
C
C
      SUBROUTINE GENSCN_INPUT_NEW(
     I          STDIN, STDOUT, BRPT, EXNODT, NBRA, NBN, NEX, NRWTA,
     I          RWTA, RTAP, SFAC, FTP, NEW_GENSCN_FEO,
     O          EFLAG)

C     Process the specification for the GENSCN data. 
C     Revised input using node classes to specify nodes in addition
C     to using an itemized list.

      IMPLICIT NONE

      INCLUDE 'arsize.prm'

      CHARACTER NEW_GENSCN_FEO*4

      INTEGER EFLAG, STDIN, STDOUT, nbn, NBRA, NRWTA, FTP, NEX
     A        
      INTEGER BRPT(8,NBRA), EXNODT(9,NEX), RTAP(MNFREE),
     A        RWTA(MNFREE)
 
      REAL SFAC
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
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
C               2    pointer into vectors for nodes on a branch, 
C                    pointer to the other node if on a level-pool reservoir,
C                    0 if on a dummy branch.
C               3    descriptive code: if -1 then a reservoir node;
C                    if  0 then not on a branch and not a reservoir node;
C                    if > 0 then a branch number.  The inflow node
C                    to a reservoir has the value of 0.  The way it is
C                    distinguished from a free node on a dummy branch
C                    is that EXNODT(4, ) is zero for a reservoir-inflow
C                    node but is positive for a free node on a dummy 
C                    branch. 
C               4    pointer to a cross section table if on a branch, 
C                    to storage table if a reservoir, to other node if
C                    a dummy branch, 0 if the inflow node to a reservoir.
C               5    gives the variable number(in the system matrix) for
C                    the flow at the exterior node. Also a junction
C                    pointer in initial processing of input
C               6    X location of the node in a cartesian coordinate system
C               7    Y location of the node in a cartesian coordinate system. 
C                   The (X,Y) are scaled upward by 100.  That is 
C                   a coordinate value of 1234.51 becomes then integer
C                   123451.  If the coordinate value is -(2**31 -1) it
C                   indicates that no value for a coordinate exists. 
C                   The scaling permits a maximum value of 2**31/100 
C                   distance units.  When the length unit is feet the 
C                   maximum coordinate is 21,474,836.48 feet or
C                   about 4067 miles.  This appears to be adequate 
C                   for any reasonable purpose!
C                8  Contains the station for the free node.  These
C                   stations are assigned by the user.  The utility
C                   program OVERFLOW, used to compute outflows/inflows
C                   between adjacent flow paths, assigns the station
C                   of the source location to the upstream node
C                   and the station of the sink to the downstream 
C                   node, if either exist.  If neither exists it 
C                   assigns -(2**31 - 1).  The station is 
C                   multiplied by 10,000 and rounded before 
C                   being placed in the integer location.  This
C                   gives a maximum station of at least 40 miles
C                   if feet are being used for the stations.  This
C                   should be adequate because using feet for stationing
C                   over such a distance would be unusual. 
C     NBRA   - number of branches in the model
C     NBN    - number of nodes on branches
C     NEX    - number of exterior nodes
C     NRWTA  - number of reservoirs with tributary area
C     RWTA   - reservoirs with tributary area
C     RTAP   - reservoir tributary area pointer
C     SFAC   - station factor for branches.
C     FTP    - pointer to next open location in FTAB/ITAB function
C              table storage vector.

      INCLUDE 'genscn.cmn'
      INCLUDE 'misccon.cmn'
      INCLUDE 'julian.cmn'
      INCLUDE 'gatcom.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'enothr.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'version.cmn'
      INCLUDE 'inusnb.cmn'
      INCLUDE 'home.cmn'

C     Local variables.
      INTEGER N_CLASS, N_GP_STATUS
      PARAMETER (N_CLASS=11, N_GP_STATUS=13)

      CHARACTER  FEO_NAME*64, TSD_NAME*64, FTF_NAME*64, LINE*80,
     A           CHAR5*5, USER_ID_STRING*16, HEAD*80,
     B        LOCATION_CLASS*5, CHAR4*4, NAME*80, OPTION*3,
     C        NODE_CLASS*16, CLASS_TABLE(N_CLASS)*16,
     D        OPT5*5, CHAR7*7, EASTSTRING*12, NORTHSTRING*12,
     E        GP_STATUS(N_GP_STATUS)*8, NODE_ITEM*16,
     F        GATE_PUMP_NAME(MNGATE+1)*16

      INTEGER IOFLAG, TSD_START, BRAIN, FA, FN, NDE, NODE, LN, IP,
     A        FTAB_INDEX, RECORD_LENGTH_IN_BYTES, BRA, I, II, IT,
     B        IBRA, J, NULL, NXT,
     B        NUMBER_OF_FULL_RECORDS, ITEMS_PER_RECORD,
     C        LEFTOVER_ITEM_KNT, CLASS, ADDFLAG

      INTEGER BNODE_FLAG(MNBN), BNODE_BRA(MNBN), ENODE_FLAG(MNEX),
     A        ENODE_BRA(MNEX), CLASS_VALUE(N_CLASS),
     B        GATE_PUMP_FLAG(MNGATE+1), GATE_PUMP_IP(MNGATE+1)

      REAL STATION, INVERT_ELEVATION
      REAL*8 EASTING, NORTHING, X, Y


      INTEGER GET_SOURCE, GET_UNIT, LENSTR
      CHARACTER GETTOK*5
      REAL*8 GET_DP_FROM_FT

      EXTERNAL GET_SOURCE, GET_UNIT, GETTOK, LENSTR, LSTAB, 
     A         FREE_UNIT, STRIP_L_BLANKS, GET_DP_FROM_FT

      DATA  CLASS_TABLE
     A      /'ALL_NODES','ALL_BRANCHES','ALL_EXN', 'INTERPOLATED',
     B       'INPUT_XSEC','FREE_NODES','LPR_NODES','LPR_INFLOW',
     C       'BRANCH_EXN','DUMMY_BRANCHES', 'NONE'/

      DATA CLASS_VALUE  /  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11/


C     Set the gate/pump status values.  Used to label points of pump speed and
C     gate opening or structure opening.
      DATA GP_STATUS
     A /'SW','FW','No Flow','Closed','Open','Max Open','Off','No H2O',
     B  'FP','SP','FO','SO','OR'/
C     ***************************FORMATS********************************
2     FORMAT(A)

 3    FORMAT(80A)
 5    FORMAT(A5,I5,1X, A16)
 
 4    FORMAT(' ',A80)
 6    FORMAT(' ',A5,I5,1X,A16)
 7    FORMAT(' *ERR:147* Output requested at too many nodes. NOUT = ',
     1   I5)

50    FORMAT('-VERSION',/,'FEQ:',F5.2)
 51   FORMAT(' *ERR:172* Exterior node',A5,' does not have trib.',
     A    ' area or is not a reservoir.')
52    FORMAT(A64)

53    FORMAT(//,'-FILES')
54    FORMAT(//,'-UNITS',/,
     A       'STATION_UNIT_NAME= miles               ',/,
     B       'ELEVATION_UNIT_NAME= feet              ',/,
     C       'FLOW_UNIT_NAME= Cubic feet per second  ',/,
     D       'GATE_OPENING_UNIT_NAME= feet           ',/,
     E       'STORAGE_UNIT_NAME= acre-feet           ',/,
     F       'STORAGE_UNIT_FACTOR=2.295684E-5        ',/,
     G       'SURFACE_AREA_UNIT_NAME=square miles    ',/,
     H       'SURFACE_AREA_FACTOR=3.587006e-8        ')

55    FORMAT(//,'-GATE_PUMP_STATUS',/,' Code String--')
56    FORMAT(//,'-TSD',/
     A       'LOCATION_KNT=',I8,/,
     B       ' SYR SMN SDY    SHOUR          SJTIME       SREC',/,
     C       I4,I4,I4,F9.5,F16.8,I11)
C     D       ' EYR EMN EDY    EHOUR          EJTIME       EREC',/,
C     E       I4,I4,I4,F9.5,F16.8,I11)

57    FORMAT(I5,1X,A8)
C58    FORMAT(//,'-TSDDIR',/,
C     A'      FEQ LOCTN BRAN   NODE         STATION     INVERT ',
C     A'       USERID',
C     B'     FTAB   Series',/,
C     C'    LABEL CLASS   #      ID                   ELEVATION',
C     C'       STRING',
C     D'    index   offset',/,
C     E' -------- ----- -----  ----- --------------- ----------',
C     E' ------------',
C     F' -------- --------')
58    FORMAT(//,'-TSDDIR',/,
     A'              FEQ Loctn  Bran    Node         Station',
     B'     Invert           UserId     FTAB   Series',
     C'     Easting      Northing',/,
     D'            Label Class   #        Id                ',
     E'  Elevation           String    Index   Offset',
     F'                          ',/,
     G' ---------------- ----- ----- ------- ---------------',
     H' ---------- ---------------- -------- --------',
     I' ------------ ------------')
59    FORMAT(//,'-FILE_FORMAT',/,' 1',//,'-FILES')
68    FORMAT(/,' *WRN:58* No home name found following HOME=. ',
     A         ' Home name cleared.')
69    FORMAT(/,' Home directory/drive is: ',A)
C70    FORMAT(1X,A8,1X,A5,1X,I5,1X,A6,1X,1PE15.6,1X,0PF10.4,1X,A12,1X,
C     A I8,1X,I8)
70    FORMAT(1X,A16,1X,A5,1X,I5,1X,A7,1X,1PE15.6,1X,0PF10.4,
     A       1X,A16,1X,I8,1X,I8,1X,A12,1X,A12)
72    FORMAT(1X,8X,1X,5X,1X,'   -1')
74    FORMAT(//'-FTF',/,
     A 'NUMBER_OF_FULL_RECORDS=',I8,/,
     B 'ITEMS_PER_RECORD=',I8,/,
     C 'LETOVER_ITEM_KNT=',I8)
75    FORMAT(/,' The file names for  GENSCN transfer are:')
76    FORMAT(/,' *ERR:372* GENSCN expected: FILE but found: ',A4)
77    FORMAT(/,' *ERR:373* Option= ',A3,' unknown.',
     A         '  ADD and SUB are known.')
78    FORMAT(/,' *ERR:374* Node class= ',A16,
     A       ' unknown in GENSCN output.')
79    FORMAT(/,' Node class: ',A16,' not implemented.')
80    FORMAT(/,' Adding nodes in class: ',A,' to GENSCN output.')
81    FORMAT(/,' Subtracting nodes in class: ',A,' from ',
     A         'GENSCN output.')
82    FORMAT(/,' Node class operations completed.  ',
     A          'Seeking item-level instructions.')
83    FORMAT(/,' GENSCN output requested at ',I5,' nodes.')
88    FORMAT(//,'-TSDDIR',/,
     A'      FEQ LOCTN BRAN   NODE         STATION     INVERT ',
     A'       USERID',
     B'     FTAB   Series',/,
     C'    LABEL CLASS   #      ID                   ELEVATION',
     C'       STRING',
     D'    index   offset',/,
     E' -------- ----- -----  ----- --------------- ----------',
     E' ------------',
     F' -------- --------')
90    FORMAT(1X,A8,1X,A5,1X,I5,1X,A6,1X,1PE15.6,1X,0PF10.4,1X,A12,1X,
     A I8,1X,I8)
C*********************************************************************
      NULL = -(2**31 -1)
      CALL CLEAR_HOME()
      CALL INL80
     I          (STDIN, STDOUT,
     O           LINE)
      CALL STRIP_L_BLANKS(
     M                     LINE)
      IF(LINE(1:4).EQ.'HOME'.OR.LINE(1:4).EQ.'home') THEN
        IT = INDEX(LINE, '=')
        NXT = IT + 1
        CALL NXTTOK
     I             (LINE,
     M              NXT,
     O              HOME)
        IF(NXT.LE.0) THEN
          WRITE(STDOUT,68) 
          HOME = ' '
        ENDIF
        CALL STRIP_L_BLANKS(
     M                      HOME)
        IT = LEN_TRIM(HOME)
        WRITE(STDOUT,69) HOME(1:IT)

        CALL INL80
     I            (STDIN, STDOUT,
     O             LINE)
      ENDIF
C     Input the main file name.  Extensions added here.
C      CALL INL80
C     I          (STDIN, STDOUT,
C     O           LINE)

C      CALL STRIP_L_BLANKS(
C     M                    LINE)

      READ(LINE,'(A4)') CHAR4
      IF(CHAR4.EQ.'FILE') THEN
C       Looks ok
        READ(LINE,'(4X,A)') NAME
        CALL STRIP_L_BLANKS(
     M                      NAME)
        IF(NAME(1:1).EQ.'=') THEN
          NAME(1:1) = ' '
          CALL STRIP_L_BLANKS(
     M                        NAME)
        ENDIF
        I = LENSTR(NAME)
C       Now create the three file names.
        FEO_NAME = NAME(1:I)
        FEO_NAME(I+1: ) = '.feo'
        TSD_NAME = NAME(1:I)
        TSD_NAME(I+1: ) = '.tsd'
        FTF_NAME = NAME(1:I)
        FTF_NAME(I+1: ) = '.ftf'

        CALL MAYBE_ADD_HOME(
     M                      FEO_NAME)
        CALL MAYBE_ADD_HOME(
     M                      TSD_NAME)
        CALL MAYBE_ADD_HOME(
     M                      FTF_NAME)

        WRITE(STDOUT,75)         
        WRITE(STDOUT,'(A)') FEO_NAME
        WRITE(STDOUT,'(A)') TSD_NAME
        WRITE(STDOUT,'(A)') FTF_NAME
      ELSE
        WRITE(STDOUT,76) CHAR4
        STOP 'Abnormal stop: errors found.'
      ENDIF


C     Open the FEO file.  Assume each case is new for now.  Add support
C     for update later.
      FEO_UNIT = GET_UNIT(STDOUT)
      OPEN(FEO_UNIT, FILE=FEO_NAME, FORM='FORMATTED',
     A        STATUS='UNKNOWN', IOSTAT=IOFLAG)
 
      IF(IOFLAG.NE.0) THEN
        WRITE(STDOUT,*) ' Problem in opening file: ',FEO_NAME
        WRITE(STDOUT,*) ' Check path for *.feo file.'
        STOP 'Abnormal stop: errors found.'
      ENDIF

      WRITE(FEO_UNIT,50) VERSION_NUMBER
      IF(NEW_GENSCN_FEO.EQ.'NO') THEN
        WRITE(FEO_UNIT,53)
      ELSE
        WRITE(FEO_UNIT,59)
      ENDIF 
      WRITE(FEO_UNIT,52) FEO_NAME
      WRITE(FEO_UNIT,52) TSD_NAME
      WRITE(FEO_UNIT,52) FTF_NAME

C     Write the unit names and conversion factors.  Expand later.

      WRITE(FEO_UNIT,54) 


      IF(NEW_GENSCN_FEO.NE.'NO') THEN
C       Output the pump and gate description classes.
        WRITE(FEO_UNIT,55)
        DO 99 I=1,N_GP_STATUS
          WRITE(FEO_UNIT,57) I, GP_STATUS(I)
99      CONTINUE
        WRITE(FEO_UNIT,57) -1, ' '
      ENDIF


C     Open the FTF file and store the function table vector in it. 
      FTF_UNIT = GET_UNIT(STDOUT)
      OPEN(FTF_UNIT, FILE=FTF_NAME, FORM='UNFORMATTED',
     A        STATUS='UNKNOWN', IOSTAT=IOFLAG)
 

C      RECORD_LENGTH_IN_BYTES =4*512
C      OPEN(FTF_UNIT, FILE=FTF_NAME, FORM='UNFORMATTED',
C     A        STATUS='UNKNOWN', ACCESS='DIRECT',
C     B        RECL=RECORD_LENGTH_IN_BYTES, IOSTAT=IOFLAG)






      IF(IOFLAG.NE.0) THEN
        WRITE(STDOUT,*) ' Problem in opening file: ',FTF_NAME
        WRITE(STDOUT,*) ' Check path for *.FTF file.'
        STOP 'Abnormal stop: errors found.'
      ENDIF
      CALL WRITE_FTFA(STDOUT, FTF_UNIT, FTP,
     O              NUMBER_OF_FULL_RECORDS, ITEMS_PER_RECORD,
     O              LEFTOVER_ITEM_KNT)
      CALL FREE_UNIT(STDOUT, FTF_UNIT)

C     Write description of the FTF file to the FEO file
      WRITE(FEO_UNIT,74) NUMBER_OF_FULL_RECORDS, ITEMS_PER_RECORD,
     O              LEFTOVER_ITEM_KNT

C     Read lines of input expecting to find ADD and SUB requests 
C     refering to classes of nodes by name.   Build a record of 
C     the nodes in scratch space.      


C     Clear the flag values
      DO 500 I=1,MNBN
        BNODE_FLAG(I) = 0
500   CONTINUE
      DO 505 I=1,NEX
        ENODE_FLAG(I) = 0
        ENODE_BRA(I) = 0
505   CONTINUE
C     We must zero all possible to be able to handle McHenry gates
C     since they do not fit the pattern for the other gates and pumps.
C     McHenry will always be placed in position MNGATE+1
      DO 507 I=1,MNGATE+1
        GATE_PUMP_FLAG(I) = 0
        GATE_PUMP_NAME(I) = ' '
507   CONTINUE

550   CONTINUE
        CALL INL80
     I            (STDIN, STDOUT,
     O             LINE)
        CALL STRIP_L_BLANKS(
     M                      LINE)
        
        READ(LINE,'(A3)') OPTION
        IF(OPTION.EQ.'ADD') THEN
          ADDFLAG = 1
          
        ELSEIF(OPTION.EQ.'SUB') THEN
          ADDFLAG = -1
        ELSE
          WRITE(STDOUT,77) OPTION
          STOP 'Abnormal stop: errors found.'
        ENDIF

C       Now get the node class response.
        LINE = LINE(4: )
        CALL STRIP_L_BLANKS(
     M                      LINE)
        IF(LINE(1:1).EQ.'=') THEN
          LINE(1:1) = ' '
          CALL STRIP_L_BLANKS(
     M                        LINE)
        ENDIF
        READ(LINE,'(A16)') NODE_CLASS

        IP = LENSTR(NODE_CLASS)

        IF(NODE_CLASS(1:IP).EQ.'NONE') THEN
          WRITE(STDOUT,82) 
        ELSEIF(ADDFLAG.EQ.1) THEN
          WRITE(STDOUT,80) NODE_CLASS(1:IP)
        ELSE
          WRITE(STDOUT,81) NODE_CLASS(1:IP)
        ENDIF

        CALL LSTAB
     I            (NODE_CLASS, CLASS_TABLE, N_CLASS,
     O             IP)
        IF(IP.EQ.0) THEN
          WRITE(STDOUT,78) NODE_CLASS
          STOP 'Abnormal stop: errors found.'
        ENDIF

        CLASS = CLASS_VALUE(IP)
        GOTO(1000, 2000, 3000, 4000, 5000, 6000, 
     A                         7000, 8000, 9000, 10000, 11000), CLASS

1000    CONTINUE
C         Add or subtract all nodes in the system.
          DO 1010 IBRA=1,NBRA
            FN = BRPT(3,IBRA)
            LN = BRPT(4,IBRA)
            DO 1005 J=FN,LN
              IF(ADDFLAG.EQ.1) THEN
                BNODE_FLAG(J) = 1
                BNODE_BRA(J) = IBRA
              ELSE
                BNODE_FLAG(J) = 0
              ENDIF
1005        CONTINUE
1010      CONTINUE
          DO 1020 I=1,NEX
            IF(ADDFLAG.EQ.1) THEN
              ENODE_FLAG(I) = 1
              ENODE_BRA(I) = EXNODT(3,I)
            ELSE
              ENODE_FLAG(I) = 0
              ENODE_BRA(I) = 0
            ENDIF
1020      CONTINUE
          GOTO 20000

2000    CONTINUE
C         Add or subtract all nodes on branches.
          DO 2010 IBRA=1,NBRA
            FN = BRPT(3,IBRA)
            LN = BRPT(4,IBRA)
            DO 2005 J=FN,LN
              IF(ADDFLAG.EQ.1) THEN
                BNODE_FLAG(J) = 1
                BNODE_BRA(J) = IBRA
              ELSE
                BNODE_FLAG(J) = 0
              ENDIF
2005        CONTINUE
2010      CONTINUE
          GOTO 20000

3000    CONTINUE
C         Add or subtract all exterior nodes
          DO 3020 I=1,NEX
            IF(ADDFLAG.EQ.1) THEN
              ENODE_FLAG(I) = 1
              ENODE_BRA(I) = EXNODT(3,I)
            ELSE
              ENODE_FLAG(I) = 0
              ENODE_BRA(I) = 0
            ENDIF
3020      CONTINUE
          GOTO 20000

4000    CONTINUE
C         Add or subtract nodes on branches at which FEQ
C         interpolated a cross section.
          DO 4010 IBRA=1,NBRA
            FN = BRPT(3,IBRA)
            LN = BRPT(4,IBRA)
            DO 4005 J=FN, LN
C             Check each cross section table for its source.
              IF(GET_SOURCE(NSEC(J)).EQ.1) THEN
C               The cross-section table at this node was interpolated.
                IF(ADDFLAG.EQ.1) THEN
                  BNODE_FLAG(J) = 1
                  BNODE_BRA(J) = IBRA
                ELSE
                  BNODE_FLAG(J) = 0
                ENDIF
              ENDIF
4005        CONTINUE
4010      CONTINUE
          GOTO 20000

5000    CONTINUE
C         Add or subtract nodes on a branch at which FEQ
C         had an input cross section (NOT interpolated by FEQ).
          DO 5010 IBRA=1,NBRA
            FN = BRPT(3,IBRA)
            LN = BRPT(4,IBRA)
            DO 5005 J=FN, LN
C             Check each cross section table for its source.
              IF(GET_SOURCE(NSEC(J)).EQ.0) THEN
C               The cross-section table at this node was NOT
C               interpolated by FEQ.
                IF(ADDFLAG.EQ.1) THEN
                  BNODE_FLAG(J) = 1
                  BNODE_BRA(J) = IBRA
                ELSE
                  BNODE_FLAG(J) = 0
                ENDIF
              ENDIF
5005        CONTINUE
5010      CONTINUE
          GOTO 20000

6000    CONTINUE
C         Add or subtract free nodes
          DO 6020 I=1,NEX
            IF(EXNODT(3,I).LE.0) THEN
C             We have a free node
              IF(ADDFLAG.EQ.1) THEN
                ENODE_FLAG(I) = 1
                ENODE_BRA(I) = EXNODT(3,I)
              ELSE
                ENODE_FLAG(I) = 0
                ENODE_BRA(I) = 0
              ENDIF
            ENDIF
6020      CONTINUE
          GOTO 20000

7000    CONTINUE
C         Add or subtract level-pool reservoir nodes.
          DO 7020 I=1,NEX
            IF(EXNODT(3,I).LT.0) THEN
C             We have an LPR node
              IF(ADDFLAG.EQ.1) THEN
                ENODE_FLAG(I) = 1
                ENODE_BRA(I) = EXNODT(3,I)
              ELSE
                ENODE_FLAG(I) = 0
                ENODE_BRA(I) = 0
              ENDIF
            ENDIF
7020      CONTINUE
          GOTO 20000

8000    CONTINUE
C         Inflow nodes to reservoirs

          WRITE(STDOUT,79) NODE_CLASS
          GOTO 20000

9000    CONTINUE
C         Exterior nodes on branches.
C         Add or subtract exterior nodes on branches
          DO 9020 I=1,NEX
            IF(EXNODT(3,I).GT.0) THEN
C             We have an LPR node
              IF(ADDFLAG.EQ.1) THEN
                ENODE_FLAG(I) = 1
                ENODE_BRA(I) = EXNODT(3,I)
              ELSE
                ENODE_FLAG(I) = 0
                ENODE_BRA(I) = 0
              ENDIF
            ENDIF
9020      CONTINUE
          GOTO 20000

10000   CONTINUE
          WRITE(STDOUT,79) NODE_CLASS
          GOTO 20000

11000   CONTINUE
C         User is done making selections by node class.
C         See if node by node specification exists.

          GOTO 21000

20000   CONTINUE
        GOTO 550
  
21000 CONTINUE

      CALL INL80
     I            (STDIN, STDOUT,
     O             LINE)
      READ(LINE,3) HEAD
      WRITE(STDOUT,4) HEAD

      IF(NEW_GENSCN_FEO.EQ.'NO') THEN
        WRITE(FEO_UNIT,88)
      ELSE
        WRITE(FEO_UNIT,58)  
      ENDIF


 100    CONTINUE
        CALL INL80
     I            (STDIN, STDOUT,
     O             LINE)
        READ(LINE,5,ERR=991) OPT5, BRAIN, NODE_ITEM
        CALL STRIP_L_BLANKS(
     M                      OPT5)
        IF(OPT5(1:3).EQ.'END') GOTO 150
        WRITE(STDOUT,6) OPT5, BRAIN, NODE_ITEM
        
        CALL STRIP_L_BLANKS(
     M                      OPT5)
        IF(OPT5(1:3).EQ.'ADD') THEN
          ADDFLAG = 1
        ELSEIF(OPT5(1:3).EQ.'SUB') THEN
          ADDFLAG = -1
        ELSE
          WRITE(STDOUT,77) OPT5(1:3)
          STOP 'Abnormal stop: errors found.'
        ENDIF        
 
        IF(BRAIN.NE.0) GOTO 120
 
C       EXTERIOR NODE or pump or gate name
C         Make sure the node name is left justified
          CALL STRIP_L_BLANKS(
     M                        NODE_ITEM)

C         Is this a pump or gate name?

C         CATCH THE SPECIAL DESIGNATION FOR MCHENRY SLUICE GATES
          IF(NODE_ITEM.EQ.'MCHN') THEN
            IF(ADDFLAG.EQ.1) THEN
              GATE_PUMP_FLAG(MNGATE+1) = 1
              GATE_PUMP_NAME(MNGATE+1) = 'MCHN'
              GATE_PUMP_IP(MNGATE+1) = 0
            ELSE
              GATE_PUMP_FLAG(MNGATE+1) = 0
            ENDIF
            GOTO 100
          ENDIF
          IF(NGATE.GT.0) THEN
C           Now check if the node designation field has a name for
C           an adjustable gate or pump.
          
            CALL LSTAB
     I                (NODE_ITEM, GNAME, NGATE,
     O                IP)
          ELSE
            IP = 0
          ENDIF
          IF(IP.GT.0) THEN
C           Name found in the table. 
            IF(ADDFLAG.EQ.1) THEN
              GATE_PUMP_FLAG(IP) = 1
              GATE_PUMP_NAME(IP) = NODE_ITEM
              GATE_PUMP_IP(IP) = IP
            ELSE
              GATE_PUMP_FLAG(IP) = 0
            ENDIF
            GOTO 100
          ENDIF


          CHAR5 = NODE_ITEM
          CALL GETINN
     M               (CHAR5,
     O                EFLAG, NODE)
          IF(NODE.GT.0) THEN

            IF(ADDFLAG.EQ.1) THEN
              ENODE_FLAG(NODE) = 1
              ENODE_BRA(NODE) = EXNODT(3,NODE)
            ELSE
              ENODE_FLAG(NODE) = 0
              ENODE_BRA(NODE) = 0
            ENDIF

          ELSE
C           The user has prefixed the exterior node id with a - to 
C           signal that output of tributary area flow for the reservoir
C           is desired.
            NODE = IABS(NODE)
            DO 112 I=1,NRWTA
              IF(NODE.EQ.RWTA(I)) THEN
                IF(ADDFLAG.EQ.1) THEN
                  ENODE_FLAG(NODE) = 1
                  ENODE_BRA(NODE) = -(RTAP(I) + 10000)
                ELSE
                  ENODE_FLAG(NODE) = 0
                  ENODE_BRA(NODE) = 0
                ENDIF
              ENDIF
 112        CONTINUE
            WRITE(STDOUT,51) CHAR5
            EFLAG = 1
          ENDIF

          GOTO 100

C       Branch number has been given
 120    CONTINUE
        READ(NODE_ITEM,'(I8)',ERR=991) NODE
        CALL GETINB
     M             (BRAIN,
     O              EFLAG, BRA)
        FN = BRPT(3,BRA)
        LN = BRPT(4,BRA)

        IF(NODE.EQ.0) THEN
C         Dump the whole branch option.
          DO 130 J=FN,LN
            GENSCN_NOUT = GENSCN_NOUT + 1
            IF(ADDFLAG.EQ.1) THEN
              BNODE_FLAG(J) = 1
              BNODE_BRA(J) = BRA
            ELSE
              BNODE_FLAG(J) = 0
            ENDIF
130      CONTINUE
         GOTO 100
        ENDIF

        FA = BRPT(3,BRA)
        FN = BRPT(1,BRA)
        LN = BRPT(2,BRA)

        IF(ABS(NODE).LT.FN.OR.ABS(NODE).GT.LN) THEN
          NDE = ABS(NODE)
          CALL KIL
     I             (2,
     M              NDE, EFLAG)
          NODE = -NDE
          STOP 'Abnormal stop.  Errors found.'
        ENDIF
 
C       COMPUTE ADDRESS FOR THIS BRANCH AND NODE NUMBER
        J = FA + ABS(NODE) - FN
        IF(NODE.GT.0) THEN
          IF(ADDFLAG.EQ.1) THEN
            BNODE_FLAG(J) = 1
            BNODE_BRA(J) = BRA
          ELSE
            BNODE_FLAG(J) = 0
          ENDIF
        ELSE
          IF(ADDFLAG.EQ.1) THEN
            BNODE_FLAG(J) = 1
            BNODE_BRA(J) = -BRA
          ELSE
            BNODE_FLAG(J) = 0
          ENDIF
        ENDIF
 
        GOTO 100
 
 150  CONTINUE
C     Construct and output the directory information to the FEO file.
C     We will output the exterior nodes first, followed by the 
C     nodes on branches.  We will permit duplication of the exterior
C     nodes on branches.   The user can avoid this duplication if 
C     they so wish. 

C     Finally we output information on pumps and gates

      GENSCN_NOUT = 0

      DO 200 II=1,NEX
        I = USNSRT(II)
        IF(ENODE_FLAG(I).EQ.1) THEN
C         Output this item
          GENSCN_NOUT = GENSCN_NOUT + 1
          IF(GENSCN_NOUT.GT.MNGSOUT) THEN
            WRITE(STDOUT,7) GENSCN_NOUT
            GENSCN_NOUT = 1
            EFLAG = 1
          ENDIF 

C         Setup the internal pointer to get the node info
          IF( ENODE_BRA(I).GT.-10000) THEN
            GENSCN_POUT(GENSCN_NOUT) = -I
          ELSE
            GENSCN_POUT(GENSCN_NOUT) = ENODE_BRA(I)
          ENDIF
 
C         Identify the character of the exterior node.
          IF(EXNODT(3,I).GT.0) THEN
C           Exterior node for a branch. 
            IP = EXNODT(2,I)
            STATION = XVEC(IP)/SFAC
            INVERT_ELEVATION = ZVEC(IP)
            FTAB_INDEX = EXNODT(4,I)
            LOCATION_CLASS = 'BNODE'
            BRAIN = INBRUS(EXNODT(3,I))
          ELSEIF(EXNODT(3,I).EQ.0) THEN
C           Exterior node not on a branch and not a LPR
            IF(EXNODT(8,I).NE.NULL) THEN
              STATION = DBLE(EXNODT(8,I))/1.D4
            ELSE
              STATION = -1.E30
            ENDIF
            INVERT_ELEVATION = ZE(I)
            FTAB_INDEX = 0
            LOCATION_CLASS = 'FNODE'
            BRAIN = 0
          ELSE
C           Has to be a LPR node.  
            IF(EXNODT(8,I).NE.NULL) THEN
              STATION = DBLE(EXNODT(8,I))/1.D4
            ELSE
              STATION = -1.E30
            ENDIF
            INVERT_ELEVATION = ZE(I)
            FTAB_INDEX = EXNODT(4,I)
            LOCATION_CLASS = 'LPR  '
            BRAIN = 0
          ENDIF
C         Write the next line to the FEO file.

          IF(EXNODT(6,I).NE.NULL) THEN
C           We have (x,y) location
            EASTING = DBLE(EXNODT(6,I))/100.D0
            NORTHING = DBLE(EXNODT(7,I))/100.D0
          ELSE
            EASTING = 0.D0
            NORTHING = 0.D0
          ENDIF
          WRITE(EASTSTRING,'(F12.2)') EASTING
          WRITE(NORTHSTRING,'(F12.2)') NORTHING
          CHAR7 = INENUS(I)
          USER_ID_STRING = ENODID(I)
          IF(NEW_GENSCN_FEO.EQ.'NO') THEN
           CALL STRIP_L_BLANKS(
     M                         CHAR7)
           CHAR5 = CHAR7
           WRITE(FEO_UNIT,90) ENODID(I), LOCATION_CLASS, BRAIN, 
     A        CHAR5, STATION, INVERT_ELEVATION, USER_ID_STRING,
     B                       FTAB_INDEX, 1+2*(GENSCN_NOUT-1)

          ELSE
            WRITE(FEO_UNIT,70) ENODID(I), LOCATION_CLASS, BRAIN, 
     A       CHAR7, STATION, INVERT_ELEVATION, USER_ID_STRING,
     B                      FTAB_INDEX, 1+2*(GENSCN_NOUT-1),
     C       EASTSTRING, NORTHSTRING
          ENDIF
        ENDIF
200   CONTINUE        

C     Do the nodes on branches next
      DO 300 I=1,NBN
        IF(BNODE_FLAG(I).EQ.1) THEN
          GENSCN_NOUT = GENSCN_NOUT + 1
          IF(GENSCN_NOUT.GT.MNGSOUT) THEN
            WRITE(STDOUT,7) GENSCN_NOUT
            GENSCN_NOUT = 1
            EFLAG = 1
          ENDIF 
C         Output this node on a branch
          IBRA = BNODE_BRA(I)
          IF(IBRA.GT.0) THEN
            GENSCN_POUT(GENSCN_NOUT) = I
          ELSE
            GENSCN_POUT(GENSCN_NOUT) = I + 10000
            IBRA = ABS(IBRA)
          ENDIF
          STATION = XVEC(I)/SFAC
          INVERT_ELEVATION = ZVEC(I)
          FTAB_INDEX = NSEC(I)
          LOCATION_CLASS = 'BNODE'
C         Compute the user node number on the branch.
          FN = BRPT(1,IBRA)
          FA = BRPT(3,IBRA)
          WRITE(CHAR7,'(I7)') I - FA + FN
          BRAIN = INBRUS(BNODE_BRA(I))
          USER_ID_STRING = BNODID(I)
          X = GET_DP_FROM_FT(FTAB_INDEX+8)
          Y = GET_DP_FROM_FT(FTAB_INDEX+10)

          WRITE(EASTSTRING,'(F12.2)') X
          WRITE(NORTHSTRING,'(F12.2)') Y
          IF(NEW_GENSCN_FEO.EQ.'NO') THEN
            CALL STRIP_L_BLANKS(
     M                          CHAR7)
            CHAR5 = CHAR7
        WRITE(FEO_UNIT,90) BNODID(I), LOCATION_CLASS, BRAIN, CHAR5,
     A                    STATION, INVERT_ELEVATION, USER_ID_STRING,
     B                    FTAB_INDEX, 1+2*(GENSCN_NOUT-1)


          ELSE
            WRITE(FEO_UNIT,70) BNODID(I), LOCATION_CLASS, BRAIN, CHAR7,
     A                    STATION, INVERT_ELEVATION, USER_ID_STRING,
     B                    FTAB_INDEX, 1+2*(GENSCN_NOUT-1),
     C                    EASTSTRING, NORTHSTRING
          ENDIF
        ENDIF

300   CONTINUE

      IF(NEW_GENSCN_FEO.EQ.'YES') THEN
        DO 400 I=1,MNGATE+1
          IF(GATE_PUMP_FLAG(I).GT.0) THEN
            GENSCN_NOUT = GENSCN_NOUT + 1
            IF(GENSCN_NOUT.GT.MNGSOUT) THEN
              WRITE(STDOUT,7) GENSCN_NOUT
              GENSCN_NOUT = 1
              EFLAG = 1
            ENDIF 
            GENSCN_POUT(GENSCN_NOUT) =-(20000 + GATE_PUMP_IP(I))
            STATION = -1.E30
            INVERT_ELEVATION = -3000.0
            FTAB_INDEX = 0
            LOCATION_CLASS = 'PMPGT'
            CHAR7 = ' '
            BRAIN = 0
            USER_ID_STRING = GATE_PUMP_NAME(I)
            EASTSTRING = ' '
            NORTHSTRING = ' '
            WRITE(FEO_UNIT,70) GATE_PUMP_NAME(I), LOCATION_CLASS, 
     A                    BRAIN, CHAR7,
     A                    STATION, INVERT_ELEVATION, USER_ID_STRING,
     B                    FTAB_INDEX, 1+2*(GENSCN_NOUT-1),
     C                    EASTSTRING, NORTHSTRING
          ENDIF
400     CONTINUE
      ENDIF

      WRITE(STDOUT,83) GENSCN_NOUT
C     Write a terminating signal to the directory list. 
      WRITE(FEO_UNIT,72) 


C     Only write the starting values now because we do not know the 
C     ending record at this time. 

      TSD_START = 1
      WRITE(FEO_UNIT,56) GENSCN_NOUT, SYR, SMN, SDY, SFRAC, SJTIME,
     A                   TSD_START


C     Open the TSD direct file. 

      RECORD_LENGTH_IN_BYTES = 8*(1 + GENSCN_NOUT)

      TSD_UNIT = GET_UNIT(STDOUT)
      OPEN(TSD_UNIT, FILE=TSD_NAME, FORM='UNFORMATTED',
     A        STATUS='UNKNOWN', ACCESS='DIRECT',
     B        RECL=RECORD_LENGTH_IN_BYTES, IOSTAT=IOFLAG)
 
      IF(IOFLAG.NE.0) THEN
        WRITE(STDOUT,*) ' Problem in opening file: ',TSD_NAME
        WRITE(STDOUT,*) ' Check path for *.tsd file.'
        STOP 'Abnormal stop: errors found.'
      ENDIF

      RETURN

 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE
        STOP 'Abnormal stop: errors found.'
      END
