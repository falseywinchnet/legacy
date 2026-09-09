C Routines used in time keeping and timestep control and management             
C                                                                               
C                                                                               
C
C
C
      INTEGER FUNCTION   IWYR
     I                       (YR, MN)
 
C     + + + PURPOSE + + +
C     Return water year for calendar year and month.
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER MN, YR
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     YR     - calendar year
C     MN     - number of month(1-12)
C***********************************************************************
      IWYR = YR
      IF(MN.GE.10) IWYR = YR+1
      RETURN
      END
C     ***********
C     *         *
C     * JTIME_OUT  *
C     *         *
C     ***********
 
      SUBROUTINE JTIME_OUT(STDOUT, JTIME)
 
C     Output JTIME in normal calendar form.
 
      IMPLICIT NONE
      INTEGER STDOUT
 
      REAL*8 JTIME
 
C     Local
 
      INTEGER YR, MN, DY, IHR, MIN, MJD
 
      REAL*8 DYFRAC, HOUR
C***********************************************************************
      MJD = INT(JTIME)
      DYFRAC = JTIME - DBLE(MJD)
      CALL INVMJD(MJD, YR, MN, DY)
      HOUR = DYFRAC*24.D0
      IHR = INT(HOUR)
      MIN = INT((HOUR - DBLE(IHR))*60.D0 + 0.5D0)
      WRITE(STDOUT,50) JTIME, YR, MN, DY, IHR, MIN
50    FORMAT(' JTIME=',F20.10,1X,I5,'/',I2,'/',I2,'::',I2,':',I2)
      RETURN
      END
C
C
C
      CHARACTER*14 FUNCTION   JTTOCT
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
 50   FORMAT(I3.2,I2.2,I2.2,':',F6.3)
C***********************************************************************
      MJD = INT(JTIME)
      FRAC = JTIME - DBLE(MJD)
      CALL INVMJD
     I           (MJD,
     O            YR, MN, DY)
      HR = sngl(24.d0*FRAC)
 
C      IF(YR.LT.2000) THEN
C        YR = YR - 1900
C      ELSE
C        YR = YR - 2000
C      ENDIF
      YR = MOD(YR,100)
      WRITE(JTTOCT,50) YR, MN, DY, HR
      RETURN
      END
C
C
C
      SUBROUTINE   MANTIM
     I                   (BRPT, BWFDSN, DIFFUS, VUNIT, DTVEC, EXNODT,
     I                    NBLK, NBN, NBRA, NODEID, NEX, OPBLK, RESNUM,
     I                    RESVEC, SFAC, FFFDSN, MINPRT, HSLOT, PUTDSN,
     I                    getdsn, BNODE, QCHOP, BNI, BNQ, TAI, TAQ, 
     i                    TAQBN, WSI, WSQ, OLD_SUMMARY,
     M                    CFLAG, DT, DTDY, IFRZ, WT, SEFLAG, 
     O                    EMC, SUMITR, S1, D1, dt_adjust, dz_for_output)
 
C     + + + PURPOSE + + +
C     Subroutine to manage time, time step, and time-integrating
C     factor.  It also detects end of run conditions.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER BNODE, BWFDSN, CFLAG, FFFDSN, IFRZ, MINPRT, NBLK, NBN,
     A        NBRA, NEX, PUTDSN, RESNUM, SEFLAG, SUMITR,
     a        dt_adjust, getdsn
      INTEGER BRPT(8, NBRA), EMC(MREMC), EXNODT(9,NEX), OPBLK(MNBLK),
     A        RESVEC(NEX)
      REAL DTVEC(MNFRDT), HSLOT, QCHOP, SFAC, VUNIT, WT, dz_for_output
      REAL*8 D1, DT, dtdy, S1, BNI, BNQ, TAI, TAQ, TAQBN, WSI, WSQ
      CHARACTER DIFFUS*4, NODEID*4, OLD_SUMMARY*4
 
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
C     BWFDSN - unit number for the initial conditions file
C     DIFFUS - indicator if tributary area is present.
C     VUNIT  - conversion factor for volumes on output
C     DTVEC  - sequence of time steps for frozen time simulation
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
C     NBLK   - number of operation blocks
C     NBN    - total number on nodes on branches in the model
C     NBRA   - number of branches in the model
C     NODEID - user node identification string
C     NEX    - number of exterior nodes in the model
C     OPBLK  - pointer into the function table storage(FTAB/ITAB) for
C               each operation block.
C     RESNUM - number of level-pool reservoirs
C              number of level-pool reservoirs
C     RESVEC - index into area vector for each level-pool reservoir
C     SFAC   - conversion factor from user stations to internal stations
C     FFFDSN - unit number for output of the flood frequency file
C     MINPRT - flag to select minimum print out to the user message
C               file when DIFFUS=YES
C     HSLOT  - height of bottom slot.  Currently 0.0 always
C     PUTDSN - unit number for storing final conditions
C     BNODE  - boundary node number at which to start defining the
C               coefficient matrix
C
C     QCHOP  - chopping value for output of flow
C     BNI  - inflows to the stream system from boundary nodes and
C              from tributary area.  
C     BNQ - outflow from the stream system at boundary nodes
C     TAI -  total inflow to tributary area
C     TAQ - total outflow from trib area into branches and LPR's 
C           excluding boundary nodes
C     TAQBN - total outflow from trib area to boundary nodes
C     OLD_SUMMARY - if YES summary of extremes is in per-version 10 format,
C                   otherwise it is in version 10 format.
C     CFLAG  - convergence flag: 1- convergence; 0-no convergence
C     DT     - time step in seconds
C     IFRZ   - count of frozen time steps
C     WT     - weight factor for approximating time integrals
C     SEFLAG - segment end flag
C     EMC    - vector containing coded form of the Matrix Control Input
C     SUMITR - cumulative sum of iterations to convergence
C     S1  - initial storage of water in the model in
C           level-pool reservoirs and branches
C     D1  - initial storage of water in the model in detention and delay
C           reservoirs
c     dt_adjust - pass value of TFLAG to FEQ so that small time steps
c                 resulting from adjustment to synchronize time with
c                 even increments of the hour do not get used in 
c                 computing the minimum time step for the run.
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'stdun.cmn'
      INCLUDE 'julian.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'bnpond.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'xscom.cmn'
      INCLUDE 'grav.cmn'
      INCLUDE 'dtcom.cmn'
      INCLUDE 'wrcom.cmn'
      INCLUDE 'timcom.cmn'
      INCLUDE 'namcom.cmn'
      INCLUDE 'genscn.cmn'
      INCLUDE 'tam.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER TFLAG
      CHARACTER YES*4
      SAVE TFLAG, YES
 
C     + + + LOCAL VARIABLES + + +
      integer bwrec
      REAL BAL, DTHR, ET, HR, RBAL, WTOLD
      REAL*8 D2, DTOLD, DTT, S2
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS, FLOAT, SNGL
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL BFINIT, BWPUT, NWDTWT, OPER, PUTFC, RESOUT, SEGEND,
     A         TIMINC, WRINIT, WRQUIT, ZSUMRY, FIND_VOLUMES,
     B         NON_CONV_SUMMARY, ZSUMRY_OLD
 
C     + + + DATA INITIALIZATIONS + + +
      DATA YES/'YES'/, TFLAG/0/
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT(/,' SIMULATION COMPLETE AT ',F15.0,' SECS.')
 2010 FORMAT(/)
 2020 FORMAT(/,' SIMULATION ENDING AT ',I5,'/',I3,'/',I3,'/',F7.3)
 2080 FORMAT(/,' SIMULATION COMPLETED')
 2100 FORMAT(/,6X,'Time step reset to',F10.2,' sec',' WT = ',F5.3)
 2110 FORMAT(6X,'Time step too small. RUN TERMINATED.')
 2120 FORMAT(/,' Time step reset in mantim to',F10.2,' secs to match',
     a       ' event end')
 2150 FORMAT(' Balance 1: S1=',1PE9.3,' S2=',1PE9.3,' BNI=',1PE9.3,
     A       ' BNQ=',1PE9.3,' TAQ=',1PE9.3,' WSI=',1PE9.3,
     B       ' WSQ=',1PE9.3)
 2152 FORMAT(' Bal diff=BAL=S2-S1-BNI-TAQ+BNQ-WSI+WSQ=',1PE10.3,
     A       ' Rel bal=BAL/(S2+BNQ)=',1PE10.3)
 2153 FORMAT(' Balance 2: D1=',1PE9.3,' D2=',1PE9.3,' TAI=',1PE9.3,
     A       ' TAQBN=',1PE9.3)
 2154 FORMAT(' Bal diff=BAL=D2-D1-TAI+TAQ+TAQBN=',1PE10.3,
     A       ' Rel Bal=BAL/(D2+TAQ+TAQBN)=',1PE10.0)
 2149 FORMAT(/,' Balance for current runoff event:')
 3018 FORMAT(/,' IFRZ = ',I5)
 3020 FORMAT(/,' Computation time=',F10.2,' secs or ',F10.4,' mins',/,
     a          5x,'Minimum time step=',f10.2,' secs')
 3021 FORMAT(/,' Comp time=',F9.2,' secs ',F8.3,' mins',/,
     a          5x,'Minimum time step=',f10.2,' secs')
C 3022 FORMAT(' TIME IN COMPUTING NETWORK MATRIX=',F10.2,' SECS.')
C 3023 FORMAT(' TIME IN SOLVING NETWORK MATRIX=',F10.2,' SECS.')
C***********************************************************************
c       set signal for non-computational adjustment of time step
        dt_adjust = tflag
C       SAVE THE OLD TIME STEP FOR POSSIBLE USE LATER
        DTOLD = DT
        WTOLD = WT
        IF(CFLAG.EQ.1) THEN
 
C         CONVERGENCE ON TIME POINT JUST COMPLETED- CONTINUE  IN
C         TIME
 
C         CLEAR CONVERGENCE FLAG
 
          CFLAG = 0
 
          IF(IFRZ.GT.0) THEN
 
C           FROZEN TIME STILL IN EFFECT.
 
            IFRZ = IFRZ - 1
            WRITE(STDOUT, 3018) IFRZ
 
            IF(IFRZ.EQ.0) THEN
 
C             FROZEN TIME OVER. SAVE STATE OF SYSTEM AS NEEDED.
 
              IF(DIFFUS.EQ.YES) THEN
                if(getdsn+putdsn == 0) then
                  bwrec = 1
                  CALL BWPUT
     I                  (BWFDSN, WT, NBRA, NBN, NEX, NBLK, OPBLK,
     m                   bwrec)
                  WRITE(STD6,*) ' BWF being written at IFRZ=0 in MANTIM'
                endif
              ENDIF
 
              IF(NFOUT.GT.0) CALL WRINIT
     I                                  (SJTIME)
 
C             COMPUTE INITIAL SYSTEM VOLUME
 
              CALL FIND_VOLUMES(NBRA, NBN, NEX, RESNUM, DLAY_KNT, 
     I                    DTEN_KNT, BRPT, RESVEC, DXVEC, A1, AE1, 
     I                    POND1, GEQVEC, Q1, WXVEC1, MA1, DLAY_Q1, 
     I                    DLAY_K, DTEN_S1, DTEN_AVDA,
     O                    S1, D1)

              IF(FEO_UNIT.GT.0) THEN 
                CALL OUT_GENSCN
     I                          (STDOUT, SJTIME, dz_for_output)
              ENDIF
              CALL NWDTWT
     I                   (SITER, MAXDT, MINDT, LOW, HIGH, LFAC, HFAC,
     I                    BWT, DWT, STDOUT, MINPRT, JTIME, TIME,
     M                    WT, TFLAG,
     O                    DT, DTDY)

              IF(DT.LT.MINDT) THEN
C               Close any GENSCN files. -1 signals normal termination
                CALL GENSCN_CLOSE(STDOUT, -1) 
c               Close any special output file and its description file
                 call spo_close(stdout)

                WRITE(STDOUT,2110)
                CALL NON_CONV_SUMMARY(STDOUT, NEX, NBN, NBRA, BRPT)
                CALL TIMERL(ITICK1)
                IF(ITICK1.LT.ITICK0) THEN
                  ITICK1 = ITICK1 + 100*86400
                ENDIF
                ET = FLOAT(ITICK1 - ITICK0)/100.0
                WRITE(STDOUT,3020) ET, ET/60., min_time_step
                WRITE(*,3021) ET, ET/60., min_time_step

                STOP 'Abnormal stop: time step too small.'
              ENDIF
 
C             UPDATE THE TIME
 
              TIME = TIME + DT
              CALL TIMINC
     I                   (DT,
     M                    JTIME, YR, MN, DY, DYFRAC, LEAP)
              SUMITR = 0
            ELSE
 
C             FROZEN TIME STILL ACTIVE
 
              DT = DTVEC(IFRZ)
              dtdy = dt/86400.d0
            ENDIF
          ELSE
 
C           FROZEN TIME OVER AND CONVERGENCE ON THE LAST TIME POINT
 
            CALL NWDTWT
     I                 (SITER, MAXDT, MINDT, LOW, HIGH, LFAC, HFAC, BWT,
     I                  DWT, STDOUT, MINPRT, JTIME, TIME,
     M                  WT, TFLAG,
     O                  DT, DTDY)
 
            IF(DT.LT.MINDT.AND.SEFLAG.EQ.0) THEN
C             Close any GENSCN files. -1 signals normal termination
              CALL GENSCN_CLOSE(STDOUT, -1) 
c             Close any special output file and its description file
              call spo_close(stdout)
              WRITE(STDOUT,2110)
              CALL NON_CONV_SUMMARY(STDOUT, NEX, NBN, NBRA, BRPT)
              CALL TIMERL(ITICK1)
              IF(ITICK1.LT.ITICK0) THEN
                ITICK1 = ITICK1 + 100*86400
              ENDIF
              ET = FLOAT(ITICK1 - ITICK0)/100.0
              WRITE(STDOUT,3020) ET, ET/60., min_time_step
              WRITE(*,3021) ET, ET/60., min_time_step
              STOP 'Abnormal stop: time step too small.'

            ENDIF

            TIME = TIME + DT
            CALL TIMINC
     I                 (DT,
     M                  JTIME, YR, MN, DY, DYFRAC, LEAP)
          ENDIF
        ELSE
 
C         CLEAR THE TIME ADJUSTMENT FLAG
 
          TFLAG = 0
          dt_adjust = tflag
 
C         NON-CONVERVENCE ON LAST TIME POINT.
 
C         MOVE BACK ANY OPERATED CONTROL STRUCTURES
 
          IF(NBLK.GT.0) THEN
            DTHR = sngl(-DT/3600.d0)
            CALL OPER
     I               (jtime, NBLK, OPBLK, DTHR,
     O                EMC)
          ENDIF
 
C         MOVE TIME COUNTERS BACK
 
          IF(IFRZ.EQ.0) THEN
            TIME = TIME - DT
            DTT = -DT
            CALL TIMINC
     I                 (DTT,
     M                  JTIME, YR, MN, DY, DYFRAC, LEAP)
          ENDIF
 
C         DECREASE THE TIME STEP
 
          DT = DT*LFAC

          SEFLAG = 0
 
          WT = WT + DWT
          IF(WT.GT.1.0) WT = 1.0
 
          IF(MINPRT.EQ.0) WRITE(STDOUT,2100) DT, WT
 
 
          IF(DT.LT.MINDT) THEN
C           Close any GENSCN files. -1 signals normal termination
            CALL GENSCN_CLOSE(STDOUT, -1) 
            WRITE(STDOUT,2110)
            CALL NON_CONV_SUMMARY(STDOUT, NEX, NBN, NBRA, BRPT)

            CALL TIMERL(ITICK1)
            IF(ITICK1.LT.ITICK0) THEN
              ITICK1 = ITICK1 + 100*86400
            ENDIF
            ET = FLOAT(ITICK1 - ITICK0)/100.0
            WRITE(STDOUT,3020) ET, ET/60., min_time_step
            WRITE(*,3021) ET, ET/60., min_time_step
            STOP 'Abnormal stop: time step too small.'

          ENDIF
 
          IF(IFRZ.EQ.0) THEN
            TIME = TIME + DT
            CALL TIMINC
     I                 (DT,
     M                  JTIME, YR, MN, DY, DYFRAC, LEAP)
          ENDIF
        ENDIF
 
C       CHECK FOR COMPLETION OF RUN ON BASIS OF JTIME
 
        IF(JTIME.GE.EJTIME) THEN
 
 
C         RUN IS COMPLETE
 
          IF(SEFLAG.EQ.0) THEN
C           WE HAVE NEVER BEEN HERE OR WE WERE HERE AND THE TIME
C           STEP WAS SUBSEQUENTLY REDUCED SO THAT WE WOULD NOT MATCH
C           EXACTLY THE END TIME. BACKUP THE TIME KEEPING.
 
            TIME = TIME - DT
            CALL TIMINC
     I                 (-DT,
     M                  JTIME, YR, MN, DY, DYFRAC, LEAP)
 
C           RECOMPUTE DT SO THAT WE MATCH EXACTLY
            DT = 86400.D0*(EJTIME - JTIME)
            IF(MINPRT.EQ.0) WRITE(STDOUT,2120) DT
 
            TIME = TIME + DT
            CALL TIMINC
     I                 (DT,
     M                  JTIME, YR, MN, DY, DYFRAC, LEAP)
            SEFLAG = 1
            IF(ABS(DT).LT.0.01) THEN
              GOTO 100
            ENDIF
            dt_adjust = tflag
            RETURN
          ENDIF
 
 
 100      CONTINUE
 
 
          IF(JTIME.GT.EJTIME) THEN
            DTT = 86400.D0*(JTIME - EJTIME)
            TIME = TIME - DTT
            CALL TIMINC
     I                 (-DTT,
     M                  JTIME, YR, MN, DY, DYFRAC, LEAP)
            JTIME = EJTIME
          ENDIF
 
 
C         MAKE SURE THAT THE TIME STEP IS THE LAST ONE USED
C         AND NOT THE LAST ONE SET!
 
          DT = DTOLD
          dtdy = dt/86400.d0
          WT = WTOLD
 
          IF(DIFFUS.EQ.YES) THEN
C           END OF A SEGMENT. INITIALIZE FOR THE NEXT SEGMENT.
C           BFINIT SETS RESET = -1 IF THERE IS NO NEXT SEGMENT IN
C           THE TSF. RESET = 1 OTHERWISE.
 
            IF(JTIME.GE.VJTIME) THEN
C             WE HAVE REACHED THE GLOBAL ENDING TIME.  SIMULATE
C             THE END OF THE TSF TO FORCE SEGEND TO FINISH THE
C             THE RUN PROPERLY
 
              RESET = -1
            ELSE
              RESET = 1
              CALL BFINIT(DT)
            ENDIF
 
C           Compute a water balance for the segment just ended.

            CALL FIND_VOLUMES(NBRA, NBN, NEX, RESNUM, DLAY_KNT, 
     I              DTEN_KNT, BRPT, RESVEC, DXVEC, A2, AE2,
     I              POND2, GEQVEC, Q2, WXVEC2, MA2, DLAY_Q2, 
     I              DLAY_K, DTEN_S2, DTEN_AVDA,
     O              S2, D2)
 
            BAL = sngl(S2 + BNQ + WSQ - 
     A           (S1 +  BNI + TAQ + WSI))
            RBAL = BAL/(S2 + BNQ)
            WRITE(STDOUT,2149)
            WRITE(STDOUT,2150) S1, S2, BNI, BNQ, TAQ, WSI, WSQ
            WRITE(STDOUT,2152)  BAL, RBAL
            WRITE(STDOUT,2153) D1, D2, TAI, TAQBN
            BAL = sngl(D2 + TAQ + TAQBN - (D1 + TAI))
            RBAL = BAL/(D2 + TAQ + TAQBN + 1.0)
            WRITE(STDOUT,2154) BAL, RBAL


C           PROCESS THE SEGMENT JUST COMPLETED.  SEGEND DOES NOT
C           RETURN IF RESET = -1
 
 
            CALL SEGEND
     I                 (BRPT, DT, EXNODT, FFFDSN, NBN, NBRA, NODEID,
     I                  NEX, SFAC, MINPRT, HSLOT, VUNIT, PUTDSN, EMC,
     I                  NBLK, OPBLK, WT, SITER, BNODE, QCHOP,
     I                  OLD_SUMMARY, dz_for_output)
 
C           WRITE THE CONDITIONS AT THE END OF THE DUMMY SEGMENT.
C           CURRENT YEAR AND MONTH FOR DUMMY SEGMENT IS MONTH: DMMN
C           AND YEAR: DMYEAR
 
            IF(YR.EQ.DMYEAR.AND.MN.EQ.DMMN) THEN
c              REWIND(BWFDSN)
              bwrec = 1
              CALL BWPUT
     I                (BWFDSN, WT, NBRA, NBN, NEX, NBLK, OPBLK,
     m                 bwrec)
              WRITE(STD6,*) ' BWF BEING WRITTEN: YR=',YR,' MN=',MN
            ENDIF

            dt_adjust = tflag
            RETURN
          ENDIF
 
          WRITE(STDOUT,2000) TIME
          WRITE(STDOUT,2010)
 
C         OUTPUT RESULT AND MAX ELEVATION SUMMARY
 
          IF(OUTPUT.GT.2) WRITE(STDOUT,2010)
          HR = sngl(24.d0*DYFRAC)
          WRITE(STDOUT,2020) YR, MN, DY, HR
          CALL RESOUT
     I               (GRAV, VUNIT, STDOUT, NBRA, NODEID, NEX, time,
     I                SFAC, BRPT, EXNODT, QCHOP, dz_for_output)
 
          WRITE(STDOUT,2080)
 
          IF(OLD_SUMMARY.NE.'YES') THEN
            CALL ZSUMRY
     I                 (STDOUT, NBRA, NODEID,  SFAC, EMC,     
     I                  BRPT, EXNODT, NEX, HSLOT, VUNIT, QCHOP,
     i                  dz_for_output)
          ELSE
            CALL ZSUMRY_OLD
     I                 (STDOUT, NBRA, NODEID, SFAC, EMC,     
     I                  BRPT, EXNODT, NEX, HSLOT, VUNIT, QCHOP,
     i                  dz_for_output)
          ENDIF 
C         Close time series output files.
          IF(NFOUT.GT.0) CALL WRQUIT(STDOUT, jtime)
 
C         Close time series input files.
          CALL RDQUIT(STDOUT)
 
C         Close any HECDSS files.
          CALL HECDSS_QUIT(STDOUT)
 
c         Close any special output file and its description file
          call spo_close(stdout)

C         Close any GENSCN files. 1 signals normal termination
          CALL GENSCN_CLOSE(STDOUT, 1) 

          IF(PUTDSN.GT.0) THEN
C           SAVE THE FINAL CONDITIONS IN A FILE
            CALL PUTFC
     I                (STDOUT, PUTDSN, PUTNAM, WT, NBRA, NBN, NEX,
     I                 VJTIME, NBLK, OPBLK, SITER, DT, BNODE, EXNODT)
          ENDIF
 
          CALL NON_CONV_SUMMARY(STDOUT, NEX, NBN, NBRA, BRPT)

          CALL TIMERL(ITICK1)
          IF(ITICK1.LT.ITICK0) THEN
            ITICK1 = ITICK1 + 100*86400
          ENDIF
          ET = FLOAT(ITICK1 - ITICK0)/100.0
          WRITE(STDOUT,3020) ET, ET/60., min_time_step
          WRITE(*,3021) ET, ET/60., min_time_step
C          WRITE(STDOUT,3022) FLOAT(CMPEXT)/100.
C          WRITE(STDOUT,3023) FLOAT(SLVEXT)/100.
 
C          CLOSE(45)

          STOP ' Normal stop in MANTIM'
 
        ENDIF
      dt_adjust = tflag
      RETURN
      END
C
C
C
      SUBROUTINE   NWDTWT
     I                   (SITER, MAXDT, MINDT, LOW, HIGH, LFAC, HFAC,
     I                    BWT, DWT, STDOUT, MINPRT, JTIME, TIME,
     M                    WT, TFLAG,
     O                    DT, DTDY)
 
C     + + + PURPOSE + + +
C     Adjust time step and time integrating weight factor.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, MINPRT, TFLAG
      REAL BWT, DWT, HFAC, HIGH, LFAC, LOW, MAXDT, MINDT, SITER, WT
      REAL*8 DT, dtdy, JTIME, TIME
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     SITER  - weighted sum of iterations to convergence
C     MAXDT  - maximum time step value in seconds
C     MINDT  - minimum value of time step in seconds
C     LOW    - lower limit on weighted sum of number of iterations
C               to convergence.
C     HIGH   - upper limit on weighted sum of number of iterations
C               to convergence.
C     LFAC   - factor for reducing size of time step
C     HFAC   - factor for increasing the time step
C     BWT    - base value of the time integrating factor, WT
C     DWT    - increment to used in adjusting current value of WT
C     STDOUT   - Fortran unit number for user output and messages
C     MINPRT - flag to select minimum print out to the user message
C               file when DIFFUS=YES
C     TIME   - elapsed time in seconds from start of run
C     WT     - weight factor for approximating time integrals
C     TFLAG  - signal to force maximum type step
C     DT     - time step in seconds
 
      INCLUDE 'timetab.cmn'

C     + + + INTRINSICS + + +
      INTRINSIC DBLE, MOD

c     Local
      integer ntab
      real df
 
C     + + + OUTPUT FORMATS + + +
 2100 FORMAT(6X,'Time step reset to',F10.2,' sec',' WT = ',F5.3)
 2101 format(6x,'Reducing time step to synchronize time.')
 2110 FORMAT(6X,'Time step too samll. RUN TERMINATED.')
C***********************************************************************

      if(tab_for_maxdt.gt.0) then
        CALL LKTSTAB
     I            (tab_for_maxdt, JTIME,
     O             maxdt, NTAB, DF)
      endif

        
      IF(SITER.LE.LOW) THEN
 
C       INCREASE THE TIME STEP
 
        IF(TFLAG.EQ.1) THEN
          DT = MAXDT
          TFLAG = 0
        ENDIF
        DT = DT*HFAC
C        IF(DT.GT.MAXDT) DT = MAXDT
 
C       DECREASE WT
 
        WT = WT - DWT
        IF(WT.LT.BWT) WT = BWT
        IF(DT.GT.MAXDT) THEN
           DT = MAXDT
        ELSE
          IF(MINPRT.EQ.0) WRITE(STDOUT,2100) DT, WT
        ENDIF
      ELSE
        IF(SITER.GT.HIGH) THEN
 
C         DECREASE THE TIME STEP
 
          DT = DT*LFAC
 
C         INCREASE WT
 
          WT = WT + DWT
          IF(WT.GT.1.0) WT = 1.0
          IF(MINPRT.EQ.0) WRITE(STDOUT,2100) DT, WT
C          IF(DT.LT.MINDT) THEN
C           Close any GENSCN files. -1 signals normal termination
C            CALL GENSCN_CLOSE(STDOUT, -1) 
C            WRITE(STDOUT,2110)
C            STOP ' Time step too small.'
C          ENDIF
        ELSE
 
C         LEAVE DT UNCHANGED BUT DECREASE WT
 
          WT = WT - DWT
          IF(WT.LT.BWT) WT = BWT
        ENDIF
      ENDIF
 
      IF(DT.EQ.MAXDT) THEN
C       Try to adjust DT to place time at an even multiple 
c       of MAXDT.  
        DT = MAXDT - MOD(TIME, DBLE(MAXDT))
        if(dt.le.mindt) then
          dt = maxdt
        endif
        IF(DT.LT.MAXDT)then
          write(stdout,2101)
          TFLAG = 1
        endif
      ENDIF

      dtdy = dt /86400.d0

      RETURN
      END
C
C
C
      SUBROUTINE   SEGEND
     I                   (BRPT, DT, EXNODT, FFFDSN, NBN, NBRA, NODEID,
     I                    NEX, SFAC, MINPRT, HSLOT, VUNIT, PUTDSN, EMC,
     I                    NBLK, OPBLK, WT, SITER, BNODE, QCHOP,
     I                    OLD_SUMMARY, dz_for_output)
 
C     + + + PURPOSE + + +
C     Process the end of a time segment when DIFFUS = YES
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER BNODE, FFFDSN, MINPRT, NBLK, NBN, NBRA, NEX, PUTDSN
      INTEGER BRPT(8,NBRA), EMC(MREMC), EXNODT(9,NEX), OPBLK(1)
      REAL HSLOT, QCHOP, SFAC, SITER, VUNIT, WT, dz_for_output
      REAL*8 DT
      CHARACTER NODEID*4, OLD_SUMMARY*4
 
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
C     FFFDSN - unit number for output of the flood frequency file
C     NBN    - total number on nodes on branches in the model
C     NBRA   - number of branches in the model
C     NODEID - user node identification string
C     NEX    - number of exterior nodes in the model
C     SFAC   - conversion factor from user stations to internal stations
C     MINPRT - flag to select minimum print out to the user message
C               file when DIFFUS=YES
C     HSLOT  - height of bottom slot.  Currently 0.0 always
C     VUNIT  - conversion factor for volumes on output
C     PUTDSN - unit number for storing final conditions
C     EMC    - vector containing coded form of the Matrix Control Input
C     NBLK   - number of operation blocks
C     OPBLK  - pointer into the function table storage(FTAB/ITAB) for
C               each operation block.
C     WT     - weight factor for approximating time integrals
C     SITER  - weighted sum of iterations to convergence
C     BNODE  - boundary node number at which to start defining the
C               coefficient matrix
C     OLD_SUMMARY - if YES summary of extremes is in pre-version 10 format,
C                   otherwise it is in version 10 format.
C
C     QCHOP  - chopping value for output of flow
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'xscom.cmn'
      INCLUDE 'julian.cmn'
      INCLUDE 'wrcom.cmn'
      INCLUDE 'timcom.cmn'
      INCLUDE 'namcom.cmn'
 
C     + + + LOCAL VARIABLES + + +
      REAL ET, HR
 
C     + + + INTRINSICS + + +
      INTRINSIC FLOAT, SNGL
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL PUTFC, WRQUIT, ZSUMRY, FREE_UNIT, NON_CONV_SUMMARY,
     A         ZSUMRY_OLD
 
C     + + + OUTPUT FORMATS + + +
 2190 FORMAT('1MAXIMA DURING EVENT',
     A ' ENDING AT:',/,' YEAR/MONTH/DAY:HOUR',
     B  I5,'/',I3,'/',I3,':',F7.3,' JTIME = ',1PD25.16)
 2240 FORMAT(' EVENT ENDING AT:',I4,'/',I2,'/',I2,':',F7.3,' JTIME=',
     A        F14.6,' IS COMPLETED')
 3020 FORMAT(' Total elapsed time=',F10.2,' secs or ',F10.4,' mins')
 3021 FORMAT(' Elapsed time=',F9.2,' secs ',F8.3,' mins')
 3022 FORMAT(/,' Event computation time=',F10.2,' secs or ',
     a      F10.4,' mins')
C 3024 FORMAT(' Time in computing network matrix=',F10.2,' secs.')
C 3025 FORMAT(' Time in solving network matrix=',F10.2,' secs.')
 3030 FORMAT(' Elapsed time=',F10.2,' secs or ',F10.4,' mins')
C***********************************************************************
C         CURRENT TIME SEGMENT IS COMPLETE. THE TIME POINT REQUESTED
C         WAS NOT DONE BECAUSE THE END OF TIME SEGMENT WAS
C         ENCOUNTERED. THEREFORE, DECREASE TIME.
 
c          TIME = TIME - DT
c          CALL TIMINC(-DT, JTIME, YR, MN, DY, DYFRAC, LEAP)
          HR = sngl(24.d0*DYFRAC)
          IF(FFFDSN.GT.0) THEN
            WRITE(FFFDSN,2190) YR, MN, DY, HR, JTIME
            IF(OLD_SUMMARY.NE.'YES') THEN
              CALL ZSUMRY
     I                   (FFFDSN, NBRA, NODEID,  SFAC, EMC,
     I                    BRPT, EXNODT, NEX, HSLOT, VUNIT, QCHOP,
     i                    dz_for_output)
            ELSE
              CALL ZSUMRY_OLD
     I                   (FFFDSN, NBRA, NODEID,  SFAC, EMC,
     I                    BRPT, EXNODT, NEX, HSLOT, VUNIT, QCHOP,
     i                    dz_for_output)
            ENDIF
          ENDIF
          IF(MINPRT.EQ.0) THEN
            WRITE(STDOUT,2190) YR, MN, DY, HR, JTIME
            IF(OLD_SUMMARY.NE.'YES') THEN
              CALL ZSUMRY
     I                   (STDOUT, NBRA, NODEID, SFAC, EMC, 
     I                    BRPT, EXNODT, NEX, HSLOT, VUNIT, QCHOP,
     i                    dz_for_output)
            ELSE
              CALL ZSUMRY_OLD
     I                   (STDOUT, NBRA, NODEID,  SFAC, EMC, 
     I                    BRPT, EXNODT, NEX, HSLOT, VUNIT, QCHOP,
     i                    dz_for_output)
            ENDIF
          ENDIF
 
 
          IF(MINPRT.EQ.1.OR.MINPRT.EQ.2) THEN
            WRITE(*,2240) YR, MN, DY, HR, JTIME
            WRITE(STDOUT,2240) YR, MN, DY, HR, JTIME
          ENDIF
 
C         COMPUTE THE EVENT COMPUTATION TIME
 
          CALL TIMERL(ITICK1)
          IF(ITICK1.LT.ITICK0) THEN
            ITICK1 = ITICK1 + 100*86400
          ENDIF
          ET = FLOAT(ITICK1 - ITICK0)/100.0
          WRITE(STDOUT,3022) ET, ET/60.
          WRITE(*,3022) ET, ET/60.
          WRITE(*,*) ' '
          ET = FLOAT(ITICK1 - ITICK)/100.0
          WRITE(STDOUT,3030) ET, ET/60.
          ITICK0 = ITICK1
 
 
          IF(RESET.LT.0) THEN
 
            IF(FFFDSN.GT.0) CALL FREE_UNIT(STDOUT, FFFDSN)
 
C           CLOSE ANY OUTPUT PTSF FILES. MUST WRITE THE TERMINATING
C           RECORD
 
            IF(NFOUT.GT.0) CALL WRQUIT(STDOUT, jtime)
 
C           Close any time series input files.
            CALL RDQUIT(STDOUT)
 
C           Close any HECDSS files
            CALL HECDSS_QUIT(STDOUT)
 
C           Close any GENSCN files. 1 signals normal termination
            CALL GENSCN_CLOSE(STDOUT, 1) 

c           Close any special output file and its description file
            call spo_close(stdout)

            IF(PUTDSN.GT.0) THEN
C             SAVE FINAL CONDITION TO FILE
              CALL PUTFC
     I                  (STDOUT, PUTDSN, PUTNAM, WT, NBRA, NBN, NEX,
     I                   VJTIME, NBLK, OPBLK, SITER, DT, BNODE, EXNODT)
            ENDIF
 
            CALL NON_CONV_SUMMARY(STDOUT, NEX, NBN, NBRA, BRPT)

C           COMPUTE TOTAL COMPUTATION TIME
            CALL TIMERL(ITICK1)
            IF(ITICK1.LT.ITICK0) THEN
              ITICK1 = ITICK1 + 100*86400
            ENDIF
            ET = FLOAT(ITICK1 - ITICK)/100.0
            WRITE(STDOUT,3020) ET, ET/60.
            WRITE(*,3021) ET, ET/60.
C            WRITE(STDOUT,3024) FLOAT(CMPEXT)/100.
C            WRITE(STDOUT,3025) FLOAT(SLVEXT)/100.
 
 
            STOP 'Normal stop in SEGEND'
          ENDIF
 
      RETURN
 
      END
C
C
C
      SUBROUTINE   TIMINC
     I                   (DT,
     M                    JTIME, YR, MN, DY, DYFRAC, LEAP)
 
C     + + + PURPOSE + + +
C     Change the time by DT. ABS(DT) < 1 day. DT in seconds.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER DY, LEAP, MN, YR
      REAL*8 DT, DYFRAC, JTIME
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     DT     - time step in seconds
C     JTIME  - current modified julian time in the model
C     YR     - calendar year
C     MN     - number of month(1-12)
C     DY     - day in the month
C     DYFRAC - fraction of day
C     LEAP   - flag to signal leap year
 
C     + + + SAVED VALUES + + +
      INTEGER DPM(12,2)
      SAVE DPM
 
C     + + + LOCAL VARIABLES + + +
      REAL*8 DTEMP
 
C     + + + INTRINSICS + + +
      INTRINSIC DBLE
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER LPYEAR
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LPYEAR
 
C     + + + DATA INITIALIZATIONS + + +
      DATA DPM/31,28,31,30,31,30,31,31,30,31,30,31,
     1         31,29,31,30,31,30,31,31,30,31,30,31/
C***********************************************************************
C     UPDATE THE JULIAN TIME
 
      DTEMP = DBLE(DT)/86400.D0
      JTIME = JTIME + DTEMP
 
C     UPDATE THE FRACTION OF THE DAY
 
      DYFRAC = DYFRAC + DTEMP
      IF(DYFRAC.GE.0.D0.AND.DYFRAC.LT.1.D0) RETURN
 
      IF(DYFRAC.LT.0.D0) GOTO 100
 
C       UPDATE THE DATE. LEAP MUST BE DEFINED ON ENTRY.
 
        DYFRAC = DYFRAC -1.D0
        DY = DY +1
        IF(DY.LE.DPM(MN,LEAP)) RETURN
          DY = 1
          MN = MN + 1
          IF(MN.LE.12) RETURN
            MN = 1
            YR = YR + 1
            LEAP = LPYEAR(YR)
            RETURN
 
 100  CONTINUE
 
C       DECREMENT HERE.
 
        DYFRAC = DYFRAC +1.D0
        DY = DY -1
        IF(DY.GE.1) RETURN
          MN = MN - 1
          IF(MN.LT.1) GOTO 200
            DY = DPM(MN,LEAP)
            RETURN
 200      CONTINUE
            DY = 31
            MN = 12
            YR = YR - 1
            LEAP = LPYEAR(YR)
            RETURN
      END
