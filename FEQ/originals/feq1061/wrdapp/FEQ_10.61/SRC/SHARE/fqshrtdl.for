C
C
C
      SUBROUTINE   TDLK10
     I                   (LOUT, IP, PTYPE, ARGR, ARGC,
     O                    F, DFDR, DFDC)
 
C     + + + PURPOSE + + +
C     Do 2-D lookup for function in rectangular grid table.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IP, LOUT, PTYPE
      REAL ARGC, ARGR, DFDC, DFDR, F
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     LOUT   - Fortran unit number for user output and messages
C     IP     - address of table
C     ARGR   - argument for rows in the table
C     ARGC   - argument for columns in the table
C     F      - function value
C     DFDR   - derivative of function wrt row argument
C     DFDC   - derivative of function wrt column argument
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
 
C     Called subprograms
      CHARACTER*16 GET_TABID
      EXTERNAL GET_TABID

C     + + + LOCAL VARIABLES + + +
      INTEGER HARGC, HARGR, INC, J, LARGC, LARGR, NARGC, PARGC, PARGR,
     A        TAB, TYPE
      REAL COLARG, DC, DELC, DF, DFDCA, DFDCB, DR, FA, FB, ROWARG
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT('*ERR:690* ROW ARG.=',F10.2,' BELOW RANGE IN TABID=',A)
 51   FORMAT('*ERR:691* ROW ARG.=',F10.2,' ABOVE RANGE IN TABID=',A)
 52   FORMAT('*ERR:692* COLUMN ARG.=',F10.2,
     A             ' BELOW RANGE IN TABID=',A)
 53   FORMAT('*ERR:693* COLUMN ARG.=',F10.2,
     A             ' ABOVE RANGE IN TABID=',A)
 54   FORMAT('*ERR:73* UNEXPECTED TYPE IN TWO-D TABID=',A,
     A       ' TYPE=',I5,' EXPECTED TYPE=',I5)
C***********************************************************************
C     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT
C     POINTERS ARE SET TO THE PROPER VALUES AT START
 
      TAB = ITAB(IP+1)
      TYPE = ITAB(IP+2)
      PARGR = ITAB(IP+3)
      HARGR = ITAB(IP+4)
      LARGR = ITAB(IP+5)
C      NARGR = FTAB(IP+6)
 
      PARGC = ITAB(IP+7)
      HARGC = ITAB(IP+8)
      LARGC = ITAB(IP+9)
      NARGC = ITAB(IP+10)
 
C      WRITE(LOUT,*) 'TDLK10 ON ENTRY: LARGR=',LARGR,' LARGC=',LARGC
 
      ROWARG = ARGR
      COLARG = ARGC
 
C      WRITE(LOUT,*) 'TDLK10: ROWARG=',ROWARG,' COLARG=',COLARG
 
      IF(TYPE.NE.PTYPE) THEN
        WRITE(LOUT,54) GET_TABID(TAB), TYPE, PTYPE
        STOP 'Abnormal stop.  Errors found.'
      ENDIF
 
C     FIND THE INTERVAL IN THE ROW ARGUMENT LIST CONTAINING THE
C     CURRENT ROW ARGUMENT.
C     MAKE SURE THE ARGUMENT IS IN THE RANGE OF THE TABLE
 
      IF(ROWARG.LT.FTAB(PARGR)) THEN
        WRITE(LOUT,50) ROWARG, GET_TABID(TAB)
        STOP 'Abnormal stop.  Errors found.'
      ELSE IF(ROWARG.GT.FTAB(HARGR)) THEN
        WRITE(LOUT,51) ROWARG, GET_TABID(TAB)
        STOP 'Abnormal stop.  Errors found.'
      ENDIF
 
      INC = NARGC + 1
 
      IF(ROWARG.GE.FTAB(LARGR)) THEN
 100    CONTINUE
          IF(ROWARG.LE.FTAB(LARGR+INC)) GOTO 120
          LARGR = LARGR + INC
          GOTO 100
      ELSE
 110    CONTINUE
          LARGR = LARGR - INC
          IF(ROWARG.GE.FTAB(LARGR)) GOTO 120
          GOTO 110
      ENDIF
 120  CONTINUE
      ITAB(IP+5) = LARGR
 
C     FIND INTERVAL IN THE COLUMN ARGUMENT LIST CONTAINING THE CURRENT
C     COLUMN ARGUMENT.
C     MAKE SURE THE ARGUMENT IS IN THE RANGE OF THE TABLE
 
      IF(COLARG.LT.FTAB(PARGC)) THEN
        WRITE(LOUT,52) COLARG, GET_TABID(TAB)
        STOP  'Abnormal stop.  Errors found.'
      ELSE IF(COLARG.GT.FTAB(HARGC)) THEN
        WRITE(LOUT,53) COLARG, GET_TABID(TAB)
        STOP  'Abnormal stop.  Errors found.'
      ENDIF
 
      IF(COLARG.GE.FTAB(LARGC)) THEN
 200    CONTINUE
          IF(COLARG.LE.FTAB(LARGC+1)) GOTO 220
          LARGC = LARGC + 1
          GOTO 200
      ELSE
 210    CONTINUE
          LARGC = LARGC - 1
          IF(COLARG.GE.FTAB(LARGC)) GOTO 220
          GOTO 210
      ENDIF
 220  CONTINUE
      ITAB(IP+9) = LARGC
 
C      WRITE(LOUT,*) 'TDLK10 AFTER LOOKUP: LARGR=',LARGR,' LARGC=',LARGC
 
      J = LARGC - PARGC + 1
 
C     INTERPOLATE ALONG EACH ROW FIRST. DC-difference between
C     the tabulated column arguments; DR-difference between tabulated
C     row arguments;  DELC- offset with the column argument interval;
C
 
      DC = FTAB(LARGC+1) - FTAB(LARGC)
      DELC = COLARG - FTAB(LARGC)
 
      DR = FTAB(LARGR+INC) - FTAB(LARGR)
      DF = FTAB(LARGR+J+1) - FTAB(LARGR+J)
      DFDCA = DF/DC
 
      DF = FTAB(LARGR+INC+J+1) - FTAB(LARGR+INC+J)
      DFDCB = DF/DC
 
      FA = FTAB(LARGR+J) + DFDCA*DELC
      FB = FTAB(LARGR+INC+J) + DFDCB*DELC
 
C     NOW INTERPOLATE BETWEEN ROWS FOR FUNCTION AND DERIVATIVE
 
      DFDR = (DFDCB - DFDCA)/DR
      DFDC = DFDCA + DFDR*(ROWARG - FTAB(LARGR))
      DFDR =  (FB - FA)/DR
      F = FA + DFDR*(ROWARG - FTAB(LARGR))
 
C      WRITE(LOUT,*) 'TDLK10 ON RETURN:F=',F,' DFDR=',DFDR,' DFDC=',DFDC
      RETURN
      END
C
C
C
      SUBROUTINE   TDLK13
     I                   (STDOUT, IP, PTYPE, MFTAB, JTIME, EDA, EUA,
     I                    HBASE,
     O                    Q, DQED, DQEU, FREE)
 
C     + + + PURPOSE + + +
C     Do 2-d lookup for flow for tables of type 13.
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER FREE, IP, STDOUT, MFTAB, PTYPE
      REAL DQED, DQEU, EDA, EUA, HBASE, Q
      real*8 jtime
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     IP     - address of the table
C     PTYPE  - expected table type
C     MFTAB  - table number and later table address of the function
C               table that supplies an adjustment factor for flows
C     TIME   - elapsed time in seconds from start of run
C     EDA    - water surface elevation at downstream node
C     EUA    - elevation of water surface at upstream node
C     HBASE  - datum for heads
C     Q      - flow rate
C     DQED   - derivative of flow wrt downstream elevation
C     DQEU   - derivative flow wrt upstream elevation
C     FREE   - flag for free flow
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
 
C     + + + LOCAL PARAMETERS + + +
      INTEGER INC
      PARAMETER(INC=4)
 
C     + + + LOCAL VARIABLES + + +
      INTEGER LHU, LP, LPFD, NTAB, OFFL, OFFR, TAB, TYPE
      REAL DDROPU, DP, DPEU, DQ, DQHU, DQLED, DQLEU, DQLP, DQRED, DQREU,
     A     DQRP, DROP, ED, EU, FAC, HDROP, HDROPL, HDROPR, HMAX, HU,
     B     HUL, HUR, P, PDV, PLD, PLU, PRD, PRU, QL, QLD, QLU, QR, QRD,
     C     QRU, THDROP
 
C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_TABID
      EXTERNAL GET_TABID, LKTSTAB
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT('*ERR:72* EU < ED in two-D TABID=',A,' EU=',
     A       F10.2,' ED=',F10.2)
 52   FORMAT('*WRN:04* HU > HMAX in two-D TABID=',A,' HU=',
     A       F10.2,' HMAX=',F10.2)
 54   FORMAT('*ERR:73* Unexpected type in two-D TABID= ',A,
     A       ' Type=',I5,' expected Type=',I5)
C***********************************************************************
C     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT
C     POINTERS ARE SET TO THE PROPER VALUES AT START
 
      TAB = ITAB(IP+1)
      TYPE = ITAB(IP+2)
      LHU = ITAB(IP+4)
      HMAX = FTAB(IP+9)

C      WRITE(STDOUT,*) ' TDLK13: TAB=',TAB,' TYPE=',TYPE,' LHU=',LHU
 
C     IMPORTANT: THE DESIGNATIONS UPSTREAM AND DOWNSTREAM REFER TO
C     THE TRUE RELATIONSHIP.  THUS EU >= ED ALWAYS.
 
      EU = EUA
      ED = EDA
 
      IF(TYPE.NE.PTYPE) THEN
        WRITE(STDOUT,54) GET_TABID(TAB), TYPE, PTYPE
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
      IF(EU.LT.ED) THEN
        WRITE(STDOUT,50) GET_TABID(TAB), EU, ED
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
 
      HU = EU - HBASE
 
      IF(HU.GT.HMAX) THEN
        WRITE(STDOUT,52) GET_TABID(TAB), HU, HMAX
        DROP = EU - ED
        HU = HMAX
        EU = HBASE + HMAX
        ED = EU - DROP
      ENDIF
 
C     DETERMINE IF THERE IS FLOW AND IF IT IS KNOWN TO BE FREE
 
      IF(EU.LE.HBASE) THEN
C       FLOW IS ZERO AND SO ARE DERIVATIVES
        Q = 0.0
        DQED = 0.0
        DQEU = 0.0
        FREE = 0
        RETURN
      ENDIF
 
C     UPSTREAM LEVEL IS ABOVE BASE.  FIND THE UPSTREAM LEVEL INTERVAL
C     CONTAINING EU
 
      IF(HU.GE.FTAB(LHU)) THEN
 100    CONTINUE
          IF(HU.LE.FTAB(LHU+INC)) GOTO 120
          LHU = LHU + INC
          GOTO 100
      ELSE
 110    CONTINUE
          LHU = LHU - INC
          IF(HU.GE.FTAB(LHU)) GOTO 120
          GOTO 110
      ENDIF
 120  CONTINUE
      ITAB(IP+4) = LHU

C      WRITE(STDOUT,*) ' LHU AFTER SEARCH=',LHU
 
C     FREE FLOW MAY RESULT IF THE DOWNSTREAM HEAD IS
C     SMALL ENOUGH
 
C     FIND THE HEAD DROP CORRESPONDING TO HU
 
      HUL = FTAB(LHU)
      HUR = FTAB(LHU+INC)
      HDROPL = FTAB(LHU+1)
      HDROPR = FTAB(LHU+INC+1)
      DDROPU = (HDROPR - HDROPL)/(HUR - HUL)
      THDROP = HDROPL + DDROPU*(HU - HUL)

C      WRITE(STDOUT,*) ' THDROP=',THDROP 
C     THDROP IS THE TABLE VALUE OF THE HEAD DROP TO FREE FLOW
C     FOR THE CURRENT UPSTREAM LEVEL
C     HDROP IS THE CURRENT HEAD DROP
 
      HDROP = EU - ED
 
      IF(HDROP.GE.THDROP) THEN
C       FREE FLOW
 
        QL = FTAB(LHU+2)
        QR = FTAB(LHU+INC+2)
        DQEU = (QR - QL)/(HUR - HUL)
        Q = QL + DQEU*(HU - HUL)
        DQED = 0.0
        FREE = 1
 
        GOTO 9000
      ENDIF
 
C     SUBMERGED FLOW HERE
 
      OFFL = ITAB(LHU+3)
      OFFR = ITAB(LHU+INC+3)
      LPFD = ITAB(IP+6)
 
C     FIND THE FRACTION OF FREE FLOW DROP REPRESENTED BY THE CURRENT DROP
 
      P = HDROP/THDROP
 
C      WRITE(STDOUT,*) ' P=',P

C     WE HAVE TWO LINES OF CONSTANT UPSTREAM LEVEL.  ONE IS ON THE LEFT
C     AND WILL BE DESIGNATED BY THE SUFFIX L.  THE OTHER IS ON THE RIGHT
C     AND WILL BE DESIGNATED BY THE SUFFIX R.  ON EACH LINE THERE WILL BE
C     A POINT ABOVE AND BELOW P.  THE ONE ABOVE IS DENOTED AS U AND THE
C     ONE BELOW AS D.  WE INTERPOLATE IN EACH LINE WITH P AND THEN
C     INTERPOLATE ON THE UPSTREAM LEVEL. IN TYPES 13 AND 14 WE HAVE
C     ONLY ONE SEQUENCE OF PARTIAL FREE DROPS.  THUS WE SEARCH ONLY
C     ONCE.
 
C      WRITE(STDOUT,*) ' TDLK13: OFFL=',OFFL,' OFFR=',OFFR,' LPFD=',LPFD
 
C     SEARCH IN THE PARTIAL FREE DROP LIST
 
      LP = LPFD
      IF(P.GE.FTAB(LP)) THEN
 130    CONTINUE
          IF(P.LE.FTAB(LP+1)) GOTO 150
            LP = LP + 1
            GOTO 130
      ELSE
 140    CONTINUE
          LP = LP - 1
          IF(P.GE.FTAB(LP)) GOTO 150
          GOTO 140
      ENDIF
 150  CONTINUE
      ITAB(IP+6) = LP

C      WRITE(STDOUT,*) ' LP=',LP
 
      PLD = FTAB(LP)
      QLD = FTAB(OFFL+LP)
      PLU = FTAB(LP+1)
      QLU = FTAB(OFFL+LP+1)
      DQ = QLU - QLD
      DP = PLU - PLD
      DQLP = DQ/DP
 
C      DQLP = (QLU - QLD)/(PLU - PLD)
      QL = QLD + DQLP*(P - PLD)
 
      PRD = PLD
      QRD = FTAB(OFFR+LP)
      QRU = FTAB(OFFR+LP+1)
      PRU = PLU
      DQRP = (QRU - QRD)/(PRU - PRD)
      QR = QRD + DQRP*(P - PRD)
 
C     COMPUTE THE FLOW AND ITS DERIVATIVES
 
      DQHU = (QR - QL)/(HUR - HUL)
      Q = QL + DQHU*(HU - HUL)
 
      FAC = (HU - HUL)/(HUR - HUL)
      DPEU = (1.0 - P*DDROPU)/THDROP
      DQLEU = DQLP*DPEU
      DQREU = DQRP*DPEU
      DQEU = DQLEU + DQHU + FAC*(DQREU - DQLEU)
 
      DQLED = -DQLP/THDROP
      DQRED = -DQRP/THDROP
      DQED = DQLED + FAC*(DQRED - DQLED)
 
      FREE = 0
 
 9000 CONTINUE
 
      RETURN
 
      END
C
C
C
      SUBROUTINE   CKTY15
     I                   (TABADR, STDOUT,
     O                    EFLAG)
 
C     + + + PURPOSE + + +
C     Check the 2-D table numbers in a table of type 15 and
C     replace the table numbers with the addresses of the tables.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, STDOUT, TABADR
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     TABADR - table address
C     STDOUT - standard output unit for user messages
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER EF, HIGH, I, LOW, TAB, TYPE

C     Called program units
      CHARACTER*16 GET_TABID
      EXTERNAL GET_TABID
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,'*ERR:240* In Table Id=',A,' of type 15 at argument=',
     A             F10.2,' 2-D Table Id=',A,' is invalid')
 52   FORMAT(/,'*ERR:241* In Table Id=',A,' of type 15 at argument=',
     A            F10.2,' 2-D Table Id=',A,' is missing.')
 54   FORMAT(/,'*ERR:242* In Table Id=',A,' of type 15 at argument=',
     A        F10.2,' 2-D Table Id=',A,' is Type=',I5,'.  Type must',
     B        ' be 6, 13, or 43.')
C***********************************************************************
      LOW = TABADR + OFF234
C     Added July 29,1996.
      IF(ITAB(TABADR+3).LT.0) THEN
C       Table has already been processed.
        RETURN
      ENDIF
      HIGH = ITAB(TABADR)
      DO 100 I=LOW,HIGH,5
        EF = 0
        TAB = ITAB(I+1)
        IF(TAB.GT.MFTNUM) THEN
          WRITE(STDOUT,50) GET_TABID(ITAB(TABADR+1)), FTAB(I),
     A                     GET_TABID(TAB)
          EFLAG = 1
          EF = 1
          STOP 'Abnormal stop.  Errors found.'
        ENDIF
        IF(EF.EQ.0) THEN
C         The table number is valid.  Convert the table number to the
C         address if the table exists.
          IF(FTPNT(TAB).GT.0) THEN
C           The table exists.  Put its address in place of the table#
            ITAB(I+1) = FTPNT(TAB)
          ELSE
            WRITE(STDOUT,52) GET_TABID(ITAB(TABADR+1)), FTAB(I),
     A                       GET_TABID(TAB)
            EFLAG = 1
            EF = 1
          ENDIF
        ENDIF
        IF(EF.EQ.0) THEN
C         Table number is valid and the table exists.  Is it the
C         correct type?
          TYPE = ITAB(ITAB(I+1)+2)
          IF(TYPE.NE.6.AND.TYPE.NE.13.and.type.ne.43) THEN
C           Not the right type.
            WRITE(STDOUT,54) GET_TABID(ITAB(TABADR+1)), FTAB(I), 
     A                   GET_TABID(TAB), TYPE
            EFLAG = 1
          ENDIF
        ENDIF
 100  CONTINUE

C     Set flag to signal that table has been processed.
      ITAB(TABADR+3) = -1
      RETURN
      END
C
C
C
      SUBROUTINE   TDLK15
     I                   (STDOUT, IP, MFTAB, JTIME, EDA, EUA, HG, HBASE,
     O                    Q, DQED, DQEU, NEWHG, FTYPE, FTYPE_CODE)
 
C     + + + PURPOSE + + +
C     Do 3-d lookup for flow for tables of type 15
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IP, MFTAB, STDOUT, FTYPE_CODE
      REAL DQED, DQEU, EDA, EUA, HBASE, HG, NEWHG, Q
      real*8 jtime
      CHARACTER FTYPE*8
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT - standard output unit for user messages
C     IP     - address of the table
C     MFTAB  - table number and later table address of the function
C               table that supplies an adjustment factor for flows
C     JTIME   - julian time in days
C     EDA    - water surface elevation at downstream node
C     EUA    - elevation of water surface at upstream node
C     HG     - underflow gate opening
C     HBASE  - datum for heads
C     DQED   - derivative of flow wrt downstream elevation
C     DQEU   - derivative flow wrt upstream elevation
C     NEWHG  - new gate opening for weir flow
C     FTYPE  - descriptor of the state of the underflow gate
C     FTYPE_CODE - code number for the string for use in plotting program 
C               interface 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER FLAG, FLAGL, FLAGR, FREE, FREEL, FREER, HIGH, LOW, LSTADR,
     A        TAB, TAB2DL, TAB2DR, type
      REAL DQEDL, DQEDR, DQEUL, DQEUR, H1, H1FAC, H1FW, H1FWL, H1FWR,
     A     H1FWRL, H1FWRR, H1L, H1R, H4, H4FAC, H4FW, H4FWL, H4FWR,
     B     H4FWRL, H4FWRR, H4L, H4R, H4SW, H4SWL, H4SWR, H4SWRL, H4SWRR,
     C     HGL, HGR, MGATE, QL, QR, RL, RLCUBE, RLSQR, RR, RRCUBE,
     D     RRSQR
 
C     + + + INTRINSICS + + +
      INTRINSIC SQRT
 
C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_TABID
      EXTERNAL GET_TABID, TDLK13, TSTSOW
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *ERR:258* Gate opening=',F10.3,' > maximum=',F10.3,
     A    ' in TabId=',A)
C***********************************************************************
      TAB = ITAB(IP+1)
      LSTADR = ITAB(IP+4)
      HIGH = ITAB(IP)
      LOW = IP + OFF234
 
C     Compute the heads and eliminate the simple cases.
      H1 = EUA - HBASE
      H4 = EDA - HBASE
C      WRITE(STDOUT,*) ' TDLK15: H1=',H1,' H4=',H4
      IF(H1.LE.0.0.OR.HG.EQ.0.0) THEN
C       The flow is zero.  Simple case.
        Q = 0.0
        DQEU = 0.0
        DQED = 0.0
        FTYPE = ' NO FLOW'
        FTYPE_CODE = 3
        RETURN
      ENDIF
 
C     Find the interval containing the argument.   Table underflow
C     is OK.
 
      IF(HG.LT.FTAB(LOW)) THEN
        TAB2DL = 0
        HGL = 0.0
        H1FWRL = 0.0
        H4FWRL = 0.0
        H4SWRL = 0.0
        HGR = FTAB(LOW)
        TAB2DR = ITAB(LOW+1)
        H1FWRR = FTAB(LOW+2)
        H4FWRR = FTAB(LOW+3)
        H4SWRR = FTAB(LOW+4)
        H1FWR = HGR*H1FWRR
        H4FWR = HGR*H4FWRR
        H4SWR = HGR*H4SWRR
      ELSEIF(HG.GT.FTAB(HIGH)) THEN
C       Table overflow on the third argument.  Give message and stop.
        WRITE(STDOUT,50) HG, FTAB(HIGH), GET_TABID(TAB)
        STOP 'Abnormal stop: errors found.'
      ELSE
C       Seems to be in range of the table.  Search from last access
C       point.
 
        IF(HG.GE.FTAB(LSTADR)) THEN
 100      CONTINUE
            IF(HG.GT.FTAB(LSTADR+5)) THEN
              LSTADR = LSTADR + 5
              GOTO 100
            ENDIF
        ELSE
 110      CONTINUE
            LSTADR = LSTADR - 5
            IF(HG.LT.FTAB(LSTADR)) GOTO 110
        ENDIF
C       AT THIS POINT LSTADR DEFINES THE LOW ARGUMENT END OF THE
C       INTERVAL CONTAINING THE ARGUMENT
 
C       RESET POINTER FOR LAST ADDRESS
 
        ITAB(IP+4) = LSTADR
 
        HGL = FTAB(LSTADR)
        TAB2DL = ITAB(LSTADR+1)
        H1FWRL = FTAB(LSTADR+2)
        H4FWRL = FTAB(LSTADR+3)
        H4SWRL = FTAB(LSTADR+4)
        H1FWL = HGL*H1FWRL
        H4FWL = HGL*H4FWRL
        H4SWL = HGL*H4SWRL
 
        HGR = FTAB(LSTADR+5)
        TAB2DR = ITAB(LSTADR+6)
        H1FWRR = FTAB(LSTADR+7)
        H4FWRR = FTAB(LSTADR+8)
        H4SWRR = FTAB(LSTADR+9)
        H1FWR = HGR*H1FWRR
        H4FWR = HGR*H4FWRR
        H4SWR = HGR*H4SWRR
      ENDIF
 
c     set type for 2-d lookup
      type = itab(tab2dr+2)

C      WRITE(STDOUT,*) ' TDLK15: HGL=',HGL,' HG=',HG,' HGR=',HGR

      MGATE = (HG - HGL)/(HGR - HGL)
 
C      WRITE(STDOUT,*) ' TDLK15: TAB2DL=',ITAB(TAB2DL+1),
C     A                 ' TAB2DR=',ITAB(TAB2DR+1)
C      WRITE(STDOUT,*) ' H1FWRL=',H1FWRL,' H4FWRL=',H4FWRL,
C     A                ' H4SWRL=',H4SWRL
C      WRITE(STDOUT,*) ' H1FWRR=',H1FWRR,' H4FWRR=',H4FWRR,
C     A                ' H4SWRR=',H4SWRR
 
C     Compute the upper limit of upstream head for FW flow.
      H1FW = HG*(H1FWRL + MGATE*(H1FWRR - H1FWRL))
 
C     Compute the values for the boundary between SW and SO
      H4FW = HG*(H4FWRL + MGATE*(H4FWRR - H4FWRL))
      H4SW = HG*(H4SWRL + MGATE*(H4SWRR - H4SWRL))
 
C     Decide what flow type is involved at the gate opening, HG.
      IF(H1.LE.HG) THEN
C       The flow is weir flow.  Lookup in the right-hand table because
C       it should have weir flow high enough for any intermediate
C       point.
        if(type.eq.13) then
          CALL TDLK13
     I             (STDOUT, TAB2DR, 13, MFTAB, JTIME, EDA, EUA, HBASE,
     O              Q, DQED, DQEU, FREE)
        else
          call tdlk43
     i             (STDOUT, tab2dr, 43, MFTAB, JTIME, EDA, EUA, HBASE,
     O              Q, DQED, DQEU, FREE)
        endif

C        WRITE(STDOUT,*) ' Q=',Q,' DQED=',DQED,' DQEU=',DQEU
        IF(FREE.EQ.1) THEN
          FTYPE = '      FW'
          FTYPE_CODE = 2
          NEWHG = H4FW
        ELSE
          FTYPE = '      SW'
          FTYPE_CODE = 1
          NEWHG = EDA - HBASE
        ENDIF
        RETURN
      ELSEIF(H1.LE.H1FW) THEN
C       Flow might be weir flow.
        CALL TSTSOW
     I             (H1, H4, HG, H1FW, H4FW, H4SW,
     O              FLAG)
        IF(FLAG.EQ.0) THEN
C         The flow is weir flow.
          if(type.eq.13) then
            CALL TDLK13
     I               (STDOUT, TAB2DR, 13, MFTAB, JTIME, EDA, EUA, HBASE,
     O                Q, DQED, DQEU, FREE)
          else
            call tdlk43
     i             (STDOUT, tab2dr, 43, MFTAB, JTIME, EDA, EUA, HBASE,
     O              Q, DQED, DQEU, FREE)
          endif

C          WRITE(STDOUT,*) ' Q=',Q,' DQED=',DQED,' DQEU=',DQEU
          IF(FREE.EQ.1) THEN
            FTYPE = '      FW'
            FTYPE_CODE = 2
            NEWHG = H4FW
          ELSE
            FTYPE = '      SW'
            FTYPE_CODE = 1
            NEWHG = EDA - HBASE
          ENDIF
          RETURN
        ELSE
C         At least one table is in SO for the intermediate
C         point to be in SO.
        ENDIF
      ENDIF
 
C     Orifice flow remains.  Two cases: 1. The left-hand table is
C     for HG=0.  2. Both tables have non-zero HG.
C
      IF(TAB2DL.EQ.0) THEN
C       The gate opening is between 0.0 and the first table.
C       We assume that all values at Hg=0.0 are zero.
 
        if(type.eq.13) then
          CALL TDLK13
     I             (STDOUT, TAB2DR, 13, MFTAB, JTIME, EDA, EUA, HBASE,
     O              QR, DQEDR, DQEUR, FREER)
        else
          call tdlk43
     i             (STDOUT, tab2dr, 43, MFTAB, JTIME, EDA, EUA, HBASE,
     O              Qr, DQEDR, DQEUR, FREER)
        endif

 
        Q =   HG*QR/HGR
        DQED =  HG*DQEDR/HGR
        DQEU =  HG*DQEUR/HGR
        IF(FREER.EQ.1) THEN
          FTYPE = '      FO'
          FTYPE_CODE = 11
        ELSE
          FTYPE = '      SO'
          FTYPE_CODE = 12
        ENDIF
      ELSE
C       Test if tables are in orifice flow.
        FLAGL = 0
        IF(H1.LE.H1FWL) THEN
          CALL TSTSOW
     I               (H1, H4, HGL, H1FWL, H4FWL, H4SWL,
     O                FLAGL)
C          IF(FLAGL.EQ.1) THEN
C            WRITE(STDOUT,*) ' Left tab in SO above SW'
C          ENDIF
        ELSE
          FLAGL = 1
        ENDIF
        FLAGR = 0
        IF(H1.LE.H1FWR) THEN
          CALL TSTSOW
     I               (H1, H4, HGR, H1FWR, H4FWR, H4SWR,
     O                FLAGR)
C          IF(FLAGR.EQ.1) THEN
C            WRITE(STDOUT,*) ' Right tab in SO above SW'
C          ENDIF
        ELSE
          FLAGR = 1
        ENDIF
 
        H1FAC = H1/HG
        H4FAC = H4/HG
        H1L = H1FAC*HGL
        H4L = H4FAC*HGL
 
        H1R = H1FAC*HGR
        H4R = H4FAC*HGR
 
        if(type.eq.13) then
          CALL TDLK13
     I             (STDOUT, TAB2DL, 13, MFTAB, JTIME, H4L+HBASE,
     I              H1L+HBASE, HBASE,
     O              QL, DQEDL, DQEUL, FREEL)
        else
          call tdlk43
     i             (STDOUT, tab2dl, 43, MFTAB, JTIME, H4L+HBASE,
     i              H1L+HBASE, HBASE,
     O              QL, DQEDL, DQEUL, FREEL)
        endif

C        WRITE(STDOUT,*) ' H1L=',H1L,' H4L=',H4L
C        WRITE(STDOUT,*) ' QL=',QL,' DQEUL=',DQEUL,' DQEDL=',DQEDL
        if(type.eq.13) then
          CALL TDLK13
     I             (STDOUT, TAB2DR, 13, MFTAB, JTIME, H4R+HBASE,
     I              H1R+HBASE, HBASE,
     O              QR, DQEDR, DQEUR, FREER)
        else
          call tdlk43
     I             (STDOUT, TAB2DR, 43, MFTAB, JTIME, H4R+HBASE,
     I              H1R+HBASE, HBASE,
     O              QR, DQEDR, DQEUR, FREER)
        endif      
C        WRITE(STDOUT,*) ' H1R=',H1R,' H4R=',H4R
C        WRITE(STDOUT,*) ' QR=',QR,' DQEUR=',DQEUR,' DQEDR=',DQEDR
 
        RL = HG/HGL
        RLSQR = RL**2
        RLCUBE = RL*RLSQR
        RR = HG/HGR
        RRSQR = RR**2
        RRCUBE = RR*RRSQR
 
        Q =  SQRT(RLCUBE*QL**2 + MGATE*(RRCUBE*QR**2 -
     A            RLCUBE*QL**2))
 
        RLSQR = RLSQR*QL
        RRSQR = RRSQR*QR
        DQEU = (RLSQR*DQEUL + MGATE*(RRSQR*DQEUR -
     A            RLSQR*DQEUL))/Q
        DQED = (RLSQR*DQEDL + MGATE*(RRSQR*DQEDR -
     A            RLSQR*DQEDL))/Q
C        WRITE(STDOUT,*) ' Rescaled interpolation:'
C        WRITE(STDOUT,*) ' Q=',Q,' DQEU=',DQEU,' DQED=',DQED
 
C       Set the flow type
        IF(FREEL.EQ.1) THEN
          IF(FREER.EQ.1) THEN
            FTYPE = '      FO'
            FTYPE_CODE = 11
          ELSE
            FTYPE = '      OR'
            FTYPE_CODE = 13
          ENDIF
        ELSE
          IF(FREER.EQ.1) THEN
            FTYPE = '      OR'
            FTYPE_CODE = 13
          ELSE
            FTYPE = '      SO'
            FTYPE_CODE = 12
          ENDIF
        ENDIF
      ENDIF
      RETURN
      END
