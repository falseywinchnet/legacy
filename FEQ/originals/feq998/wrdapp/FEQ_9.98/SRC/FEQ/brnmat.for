C Routines used in creating the network matrix entries for the branch nodes.    
C                                                                               
C                                                                               
C
C
C
      SUBROUTINE   INSNOD
     I                   (STDOUT, ADDNOD, MNBN, FIRST,
     M                    LAST, NSEC, XVEC, ZVEC, KA, KD, HLTAB, UVX,
     M                    UVY, COEFIN, YCUT, STDFLD, KADJVEC, BNODID,
     O                    NBN)
 
C     + + + PURPOSE + + +
C     Add one or more nodes per element input by the user.  An
C     element with a head loss or drag force table will not have any
C     nodes added because we do not know which of the new elements
C     should receive the table.  Also the values of KA, KD, UVX, UVY,
C     and YCUT will be transfered unchanged to the new elements.
 
C     The stations, Bottom profile, and STDFLD will be interpolated
C     in the standard manner.  This routine changes the various
C     vectors as if the additional nodes had been input by the user.
C     The interpolations are done with pre-existing code in BRIN.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADDNOD, FIRST, LAST, MNBN, NBN, STDOUT
      INTEGER HLTAB(MNBN), NSEC(MNBN)
      REAL COEFIN(MNBN), KA(MNBN), KADJVEC(MNBN),KD(MNBN), 
     A     STDFLD(MNBN), UVX(MNBN), UVY(MNBN), XVEC(MNBN), 
     B     YCUT(MNBN), ZVEC(MNBN)
      CHARACTER BNODID(MNBN)*16
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT - standard output unit for user messages
C     ADDNOD - the number of nodes to be added to each element in the
C               branch for all elements that can be subdivided.
C     MNBN   - maximum number of branch nodes
C     FIRST  - address of the first node on a branch
C     LAST   - address of last node on a branch
C     NSEC   - number and also address of cross section table at a node
C               on a branch
C     XVEC   - station values for each node on a branch
C     ZVEC   - bottom profile elevations for nodes on a branch
C     KA     - velocity head factor for contraction loss
C     KD     - velocity head factor for expansions loss
C     HLTAB  - addresses of point loss tables.  0 if none present
C     UVX    - sine of azimuth angle for each element.
C     UVY    - cosine of azimuth angle for each element
C     COEFIN - effective discharge coefficient for storm sewer inflow
C     YCUT   - distance from invert of storm sewer to ground surface
C     STDFLD - standard flood elevation
C     KADJVEC _ adjustment factor on conveyance
C     BNODID - branch-node identification string
C     NBN    - total number on nodes on branches in the model
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, J, JE, JS, K, NEWNUM, NUMADD, XTAB
      REAL KATMP, KDTMP, UVXTMP, UVYTMP, YCUTTP
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *ERR:182 No space to add nodes.  Increase MNBN in ',
     A       'ARSIZE.PRM and recompile.')
C***********************************************************************
C     COMPUTE THE NUMBER OF NODES THAT WILL BE ADDED TO THE BRANCH
 
      NUMADD = 0
      DO 100 I=FIRST+1,LAST
        IF(HLTAB(I).EQ.0) THEN
          NUMADD = NUMADD + ADDNOD
 
        ENDIF
 100  CONTINUE
 
      NEWNUM = LAST - FIRST + 1 + NUMADD
 
      IF(LAST + NEWNUM.GT.MNBN) THEN
        WRITE(STDOUT,50)
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
C     TRANSFER THE FIRST NODE TO THE WORK SPACE. COMPUTE THE STARTING AND
C     ENDING LOCATIONS IN THE WORKSPACE AT THE END OF THE VECTORS.
 
      JS = MNBN - NEWNUM + 1
      J = JS
      JE = MNBN
 
      NSEC(J)   = NSEC(FIRST)
      XVEC(J)   = XVEC(FIRST)
      ZVEC(J)   = ZVEC(FIRST)
      KA(J)     = KA(FIRST)
      KD(J)     = KD(FIRST)
      HLTAB(J)  = HLTAB(FIRST)
      UVX(J)    = UVX(FIRST)
      UVY(J)    = UVY(FIRST)
      COEFIN(J) = COEFIN(FIRST)
      YCUT(J)   = YCUT(FIRST)
      STDFLD(J) = STDFLD(FIRST)
      KADJVEC(J) = KADJVEC(FIRST)
      BNODID(J) = BNODID(FIRST)
 
      J = J + 1
 
      DO 200 I=FIRST+1,LAST
 
        IF(HLTAB(I).EQ.0) THEN
C         ADD NODES TO THE ELEMENT.
 
          IF(NSEC(I-1).EQ.NSEC(I)) THEN
C           USE THE SAME TABLE NUMBER.  IT WILL BE CORRECT IN ALL
C           CASES
            XTAB = NSEC(I)
          ELSE
C           FORCE AN INTERPOLATED TABLE
            XTAB = -1000000
          ENDIF
 
          KATMP = KA(I)
          KDTMP = KD(I)
          UVXTMP = UVX(I)
          UVYTMP = UVY(I)
          YCUTTP = YCUT(I)
          DO 120 K=1,ADDNOD
 
            NSEC(J)   = XTAB
            XVEC(J)   = -1.E30
            ZVEC(J)   = -1.E30
            KA(J)     = KATMP
            KD(J)     = KDTMP
            HLTAB(J)  = 0
            UVX(J)    = UVXTMP
            UVY(J)    = UVYTMP
            COEFIN(J) = 0.0
            YCUT(J)   = YCUTTP
            STDFLD(J) = 0.0
            KADJVEC(J)= 0.0
            BNODID(J) = ' '
            J = J + 1
 120      CONTINUE
 
        ENDIF
 
C       NOW TRANSFER THE NEXT IN LINE USER VALUE TO THE WORK SPACE
 
        NSEC(J)   = NSEC(I)
        XVEC(J)   = XVEC(I)
        ZVEC(J)   = ZVEC(I)
        KA(J)     = KA(I)
        KD(J)     = KD(I)
        HLTAB(J)  = HLTAB(I)
        UVX(J)    = UVX(I)
        UVY(J)    = UVY(I)
        COEFIN(J) = COEFIN(I)
        YCUT(J)   = YCUT(I)
        STDFLD(J) = STDFLD(I)
        KADJVEC(J)= KADJVEC(I)
        BNODID(J) = BNODID(I)
        J = J + 1
 200  CONTINUE
 
 
C     NOW MOVE THE EXPANDED BRANCH DESCRIPTION BACK TO FIRST. ADJUST
C     NBN AND LAST TO REFLECT THE CHANGE IN SIZE.
 
      I = FIRST
      DO 300 J=JS,JE
 
        NSEC(I)   = NSEC(J)
        XVEC(I)   = XVEC(J)
        ZVEC(I)   = ZVEC(J)
        KA(I)     = KA(J)
        KD(I)     = KD(J)
        HLTAB(I)  = HLTAB(J)
        UVX(I)    = UVX(J)
        UVY(I)    = UVY(J)
        COEFIN(I) = COEFIN(J)
        YCUT(I)   = YCUT(J)
        STDFLD(I) = STDFLD(J)
        KADJVEC(I) = KADJVEC(J)
        BNODID(I) = BNODID(J)
        I = I + 1
 300  CONTINUE
 
      I = I - 1
      NBN = I
      LAST = I
 
      RETURN
      END
C
C
C
      SUBROUTINE   LKTSF
     I                  (STDOUT, JLTIME, DT,
     O                   CLSR, WYR)
 
C     + + + PURPOSE + + +
C     Find values of cumulative land surface runoff and the water
C     year corresponding to JLTIME.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, WYR
      REAL CLSR(MNDIFA)
      REAL*8 JLTIME, DT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     JLTIME - modified julian time for land surface runoff value
C     CLSR   - values of cumulative land surface runoff found
C     WYR    - current water year
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'tsfcom.cmn'
      INCLUDE 'julian.cmn'
      INCLUDE 'dssdif.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER DYT, I, J, KNT, LL, LM1, LP1, LR, LSTOP, LT, LTM1, MNT,
     A        YRT, NEED, GOT
      REAL RATE, RATEL, RUNOFF(MNDIFA)
      REAL*8 DYF, P, RI(MNDIFA), JTBASE, TEPS, TSFDT
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER IWYR
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL IWYR
 
      DATA TEPS/1.D-6/
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(' *BUG:35 SUBROUTINE LKTSF: UNEXPECTED END OF FILE',
     A  ' READING FROM DTSF. FILE JTIME=',1PD20.12,/,
     B  10X,'YEAR=',I5,' MONTH=',I3,' DAY=',I3,' DAYFRAC=',1PD20.12)
 52   FORMAT(10X,' RUN JTIME=',1PD20.12,' SEGMENT EJTIME=',1PD20.12)
 54   FORMAT(' *BUG:37* JTIME= 0 IN DTSF IN LKTSF. LOOKUP JTIME=',
     A         1PD20.12,/,
     A        10X,' RUN JTIME=', 1PD20.12,' RUN EJTIME=',1PD20.12)
60    FORMAT(/,' *BUG:XXX Need to backspace diffuse file system.',
     A  /,11X,'Probable cause is diffuse buffer that is too small.')
61    FORMAT(' Above message issued while searching buffer for HECDSS',
     A     ' access in LKTSF.')
 62   FORMAT(/,' *BUG:XXX* Times do not match for runoff in ',
     A               'LKTSF.')
C***********************************************************************
      IF(JLTIME.GE.BJTIME(LENTRY)) THEN
C       SEARCH BUFFER CLOCKWISE
 100    CONTINUE
          LP1 = LENTRY + 1
          IF(LP1.GT.NBUFF) LP1 = 1
          IF(LP1.EQ.LHEAD) THEN
C           MOVED BEYOND END OF BUFFER-READ NEW RECORD INTO LIST
C           HEAD LOCATION. NOTE: LIST HEAD WILL POINT TO OLDEST
C           RECORD IN THE BUFFER.
 
            IF(TIME_STEP_DIFF(1).LT.0) THEN
              IF(TSFTYP.EQ.0) THEN
                READ(TSFDSN, END=5000) BJTIME(LHEAD),
     A                                 DYF, YRT, MNT, DYT, NDFVAL,
     B                                 (RI(J),J=1,NDFVAL)
              ELSE
                READ(TSFDSN, END=5000) BJTIME(LHEAD), DYF, YRT, MNT,
     A                                 DYT, (RUNOFF(J), J=1,NDFVAL)
                DO 106 J=1,NDFVAL
                  RI(J) = RUNOFF(J)
 106            CONTINUE
              ENDIF
 
              IF(BJTIME(LHEAD).EQ.0.D0) THEN
                WRITE(STDOUT,54) JLTIME, JTIME, EJTIME
                STOP 'Abnormal stop: errors found.'
              ENDIF
 
              BWYR(LHEAD) = IWYR(YRT,MNT)
 
C             COMPUTE CUMULATIVE FORM IN THE BUFFER
C             LENTRY IS THE LAST UP-TO-DATE VALUE HERE.
 
              TSFDT = 86400.E0*(BJTIME(LHEAD) - BJTIME(LENTRY))
              IF(LAGTSF.EQ.0) THEN
                DO 150 J=1,NDFVAL
                  TSFBUF(LHEAD,J) = TSFBUF(LENTRY,J) + TSFDT*RI(J)
 150            CONTINUE
              ELSE
                TSFDT = 0.5*TSFDT
                DO 160 J=1,NDFVAL
                  TSFRAT(LHEAD,J) = RI(J)
                  TSFBUF(LHEAD,J) = TSFBUF(LENTRY,J) + TSFDT*
     A                                    (RI(J) + TSFRAT(LENTRY,J))
 160            CONTINUE
              ENDIF
 
              LHEAD = LHEAD + 1
              IF(LHEAD.GT.NBUFF) LHEAD = 1
            ELSE
C             Path name in HECDSS.  Find out how many
C             values need to be retained in the buffer so that
C             time step reductions due to convergence difficulties
C             do not require reading data already past.
              JTBASE = JLTIME - DT/86400.D0 - TEPS
C              WRITE(STDOUT,*) ' State of buffer before refresh'
C              CALL DUMP_DIFF_STATE(1, NBUFF, LHEAD, LENTRY)
 
              LT = LHEAD - 1
              IF(LT.LT.1) LT = NBUFF
C             LT gives index to the last item placed in the buffer.
              KNT = 1
110           CONTINUE
                IF(BJTIME(LT).GE.JTBASE) THEN
C                 Continue searching backwards.
                  LT = LT - 1
                  IF(LT.LT.1) LT = NBUFF
                  IF(LT.EQ.LHEAD) THEN
                    WRITE(STDOUT,60)
                    WRITE(STDOUT,61)
                    STOP 'Abnormal stop: errors found.'
                  ENDIF
 
                  KNT = KNT + 1
                  GOTO 110
                ENDIF
C             KNT  gives the number of values in the buffer that
C             must be retained.
              NEED = NBUFF - KNT
C              WRITE(STDOUT,*) ' LKTSF: KNT=',KNT,' NEED=',
C     A                     NEED
C             Set the desired julian time so that we do not
C             get a value twice.  Add .75 of the buffer time step
C             which is constant in time and space, to the julian time
C             of the last valid entry in the buffer.  This should
C             get the correct value for all valid HECDSS time steps.
              JTBASE =  BJTIME(LENTRY) + BUF_DT
 
C             Get the data from the pathnames and transfer to the
C             columns of the diffuse buffer.
 
              DO 510 J=1,NLUSE
                CALL GET_HECDSS_BLOCK(STDOUT, PATH_NAME_DIFF(J),
     A                   DSS_INDEX_DIFF(J), TIME_STEP_DIFF(J),
     B                   'PER-CUM ', JTBASE, NEED,
     B                   GOT, JTVEC, TMPVEC, NBUFF + 1)
C               Transfer to the buffer. Slot at LHEAD is the start
C               point.
                LT = LHEAD
                IF(J.EQ.1) THEN
C                 Transfer both the times and the values.
                  DO 190 I=1,GOT
                    TSFBUF(LT,J) = TMPVEC(I)
                    BJTIME(LT) = JTVEC(I)
                    LT = LT + 1
                    IF(LT.GT.NBUFF) LT = 1
190               CONTINUE
                ELSE
C                 Transfer the values and compare the times.
                  DO 205 I=1,GOT
                    TSFBUF(LT,J) = TMPVEC(I)
                    IF(ABS(BJTIME(LT) - JTVEC(I)).GT.1.D-5) THEN
C                     Problem in time steps.
                      WRITE(STDOUT,62)
                      STOP 'Abnormal stop: errors found.'
                    ENDIF
                    LT = LT + 1
                    IF(LT.GT.NBUFF) LT = 1
205               CONTINUE
                ENDIF
510           CONTINUE
              LHEAD = LT
C             COMPUTE CUMULATIVE FORM IN THE BUFFER
C             LENTRY IS THE LAST UP-TO-DATE VALUE HERE.
 
              LSTOP = LHEAD - 1
              IF(LSTOP.LT.1) LSTOP = NBUFF
              LTM1 = LENTRY
              LT = LENTRY + 1
              IF(LT.GT.NBUFF) LT = 1
 
520           CONTINUE
                IF(LAGTSF.EQ.0) THEN
                  DO 151 J=1,NLUSE
                    TSFBUF(LT,J) = TSFBUF(LTM1,J)
     A                                     + TSFDT_DSS*TSFBUF(LT,J)
 151              CONTINUE
                ELSE
                  DO 161 J=1,NDFVAL
                    TSFRAT(LT,J) = TSFBUF(LT,J)
                    TSFBUF(LT,J) = TSFBUF(LTM1,J) + HALF_TSFDT_DSS*
     A                                  (TSFBUF(LT,J) + TSFRAT(LTM1,J))
 161              CONTINUE
                ENDIF
                IF(LT.NE.LSTOP) THEN
                  LTM1 = LTM1 + 1
                  IF(LTM1.GT.NBUFF) LTM1 = 1
                  LT = LT + 1
                  IF(LT.GT.NBUFF) LT = 1
                  GOTO 520
                ENDIF
 
 
C              WRITE(STDOUT,*) ' State of buffer after refresh'
C              CALL DUMP_DIFF_STATE(1, NBUFF, LHEAD, LENTRY)
 
            ENDIF
          ENDIF
          IF(JLTIME.LE.BJTIME(LP1)) THEN
C           FOUND THE INTERVAL-SET THE LEFT AND RIGHT TIME POINTERS
            LL = LENTRY
            LR = LP1
            GOTO 1000
          ELSE
            LENTRY = LP1
            GOTO 100
          ENDIF
        ELSE
C         SEARCH COUNTER CLOCKWISE. PASSING THE LIST HEAD IS A
C         BUG BECAUSE IT SHOULD NOT HAPPEN.
 
 200        CONTINUE
              IF(LENTRY.EQ.LHEAD) THEN
                WRITE(STDOUT,*)
     A          ' *BUG:34 SUBROUTINE LKTSF-PASSING LIST HEAD',
     B          ' COUNTER CLOCKWISE. JTIME = ',JLTIME
                STOP 'Abnormal stop: errors found.'
              ENDIF
 
              LM1 = LENTRY - 1
              IF(LM1.LT.1) LM1 = NBUFF
              IF(JLTIME.GE.BJTIME(LM1)) THEN
C               FOUND INTERVAL
                LL = LM1
                LR = LENTRY
                GOTO 1000
              ELSE
                LENTRY = LM1
                GOTO 200
              ENDIF
            ENDIF
 
 1000 CONTINUE
C     INTERPOLATE FOR THE VALUE
 
      TSFDT = JLTIME - BJTIME(LL)
      P = TSFDT/(BJTIME(LR) - BJTIME(LL))
      WYR = BWYR(LR)
 
      IF(LAGTSF.EQ.0) THEN
        DO 600 J=1,NDFVAL
          CLSR(J) = TSFBUF(LL,J) + P*(TSFBUF(LR ,J) - TSFBUF(LL,J))
 600    CONTINUE
      ELSE
        TSFDT = 43200.D0*TSFDT
        DO 610 J=1,NDFVAL
          RATEL = TSFRAT(LL,J)
          RATE = RATEL + P*(TSFRAT(LR,J) - RATEL)
          CLSR(J) = TSFBUF(LL,J) + TSFDT*(RATE + RATEL)
 610    CONTINUE
      ENDIF
 
      RETURN
 
 5000 CONTINUE
      WRITE(STDOUT,50) BJTIME(LHEAD), YRT, MNT, DYT, DYF
      WRITE(STDOUT,52) JTIME, EJTIME
      STOP 'Abnormal stop: errors found.'
      END
C
C
C
      SUBROUTINE RECOMPUTE_DLAY_ROUTING(DT)

C     Recompute the coefficients for routing through the delay
C     reservoirs. 

      IMPLICIT NONE
      REAL*8 DT

      INCLUDE 'arsize.prm'
      INCLUDE 'tam.cmn'

C     Local

      INTEGER I

      REAL*8 DT_OVER_K

C***********************************************************************
      DO 100 I=1,DLAY_KNT
        DT_OVER_K = DT/DLAY_K(I)
        DLAY_EXP_OF_DT_OVER_K(I) = EXP(-DT_OVER_K)
        DLAY_K_OVER_DT(I) = 1.D0/DT_OVER_K
100   CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE   LOAD
     I                 (DIFFUS, BRPT, NBRA, STDOUT, LPNT, MLPNT, NBN,
     I                  OUTPUT, POINT, TIME, WIND, PFPNT, QPN, 
     I                  DT, DTLOAD, DJLOAD, DTIMLD,
     M                  EMC,
     O                  EFLAG, WYR)
 
C     + + + PURPOSE + + +
C     Set up values in vectors QPVEC & WSVEC for current time step.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, STDOUT, LPNT, MLPNT, NBN, NBRA,  OUTPUT,
     A        QPN, WYR
      INTEGER BRPT(8,NBRA),  EMC(MREMC), PFPNT(3,MLPNT)
      REAL DTIMLD, TIME
      REAL*8 DJLOAD, DT, DTLOAD
      CHARACTER DIFFUS*4, POINT*4, WIND*4
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     DIFFUS - indicator if tributary area is present.  YES if so
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
C     NBRA   - number of branches in the model
C     STDOUT   - Fortran unit number for user output and messages
C     LPNT   - length of the point load point load array
C     MLPNT  - maximum length of the point load pointer arrays
C     NBN    - total number on nodes on branches in the model
C     OUTPUT - output level for diagnostic work
C     POINT  - if YES then point inflows to a branch are present
C     TIME   - elapsed time in seconds from start of run
C     WIND   - flag for presence of wind stress simulation
C     PFPNT  - point flow pointer array
C     QPN    - number of lateral inflows
C     DT     - time step in seconds
C     DTLOAD - special value of time step for frozen time
C     DJLOAD - time adjustment offset to prevent problems during frozen
C               time computations
C     DTIMLD - special value of time step for frozen time
C     EMC    - vector containing coded form of the Matrix Control Input
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     WYR    - current water year
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'ts_mngt.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'difcom.cmn'
      INCLUDE 'tsfcom.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'julian.cmn'
      INCLUDE 'wincom.cmn'
      INCLUDE 'ts_mngt.cmn'
      INCLUDE 'tam.cmn'
      INCLUDE 'misccon.cmn'
      INCLUDE 'irrig.cmn'
      INCLUDE 'enelem.cmn'

C     + + + SAVED VALUES + + +
      REAL*8 PAST_DT, DT_TOLERANCE
      CHARACTER NO*4, YES*4
      SAVE NO, YES
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADRS, FNODE, GAGE, I, IBRA, IDUM, IT, ITYPE, J, K, LNODE,
     A        NB, NTAB, KS, KE, UNIT_PNT, TRIBA_PNT,
     B        FRACTION_PNT, QP_PNT, CAT_CODE, DLAY_PNT, DTEN_PNT,
     C        ROUT_TAB, KNT, NODE, PNT
      REAL ATIME, FLOW, PDV, RDUM, RI(MNDIFA), SHEAR,
     A     SHIFT, TEMP, TIME1, WX, WY, QQ1, QQ2, S1, S2, Q1P, Q2P,
     B      S2T, NUMBER_OF_PONDS, ELEV, DF, FRACTION, TIME2, DQ,
     C      TS_VALUE
      REAL*8 AJTIME, SUM, SUMA, HALF_DT, DT_OVER_12, QBAR, QEND,
     A       AJTIME1, AJTIME2
 
C     + + + EQUIVALENCES + + +
      EQUIVALENCE (RDUM, IDUM)
 
C     + + + INTRINSICS + + +
      INTRINSIC EXP
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LKTAB, LKTSF, RDGET, WSHEAR
 
C     + + + DATA INITIALIZATIONS + + +
      DATA YES/'YES'/,NO/'NO'/, PAST_DT/0.D0/, DT_TOLERANCE/1.D-7/
 
C     + + + OUTPUT FORMATS + + +
50    FORMAT(/,' *BUG:XXX* Invalid CAT_CODE=',I5,' in sub. LOAD')
 52   FORMAT(/,' DIFFUSE, POINT & WIND LOADINGS AT ',
     A           'TIME ',F14.0,/,1X,
     B           '  ELEMENT  ','   DISCHARGE  ','  WIND SHEAR  ')
 54   FORMAT(4X,I5,3(2X,1PE12.5))
 56   FORMAT(/,'*ERR:161* Unable to set up vectors QPVEC, ',
     A           ' WSVEC or forced boundary in SUBROUTINE LOAD')
 58   FORMAT(/,'Point flows read from table ',I5,' for branch ',
     A           'vector ',I5,' at time ',F14.0)
60    FORMAT(/,' *ERR:324* Detention reservoir failed to converge.')
C***********************************************************************
C     INITIALIZE
      EFLAG = 0
      DO 10 I=1,NBN
        WSVEC(I) = 0.
 10   CONTINUE
      DO 11 I=1,QPN
        QPVEC(I) = 0.0
 11   CONTINUE
 
C     Clear the local summation variables for evaporation and
C     rainfall
      L_WSI = 0.D0
      L_WSQ = 0.D0
C     SET THE TIME VALUES FOR THIS LOOK UP. DTLOAD, DJLOAD, AND
C     DTIMLD ARE SET TO GIVE THE PROPER RESULT
 
      ATIME = TIME + DTIMLD
      AJTIME = JTIME + DJLOAD
      TIME2 = TIME - 0.5*DT
      AJTIME2 = AJTIME - 5.787037037D-6*DTLOAD
 
      IF(DIFFUS.EQ.YES.OR.DIFFUS.EQ.'DSS ') THEN
        HALF_DT = 0.5D0*DT 
        DT_OVER_12 = 0.0833333333333333D0*DT
        CALL LKTSF
     I            (STDOUT, AJTIME, DT,
     O             CLSR2, WYR)
 
C        ATIME = TIME + DTIMLD
C        AJTIME = JTIME + DJLOAD

C       Check if the time step has changed from the past time
C       step.  If so, we must recompute the routing coefficients
C       for all delay reservoirs. 
        IF(ABS(DT - PAST_DT).GT.DT_TOLERANCE) THEN

          CALL RECOMPUTE_DLAY_ROUTING(DT)
          PAST_DT = DT
        ENDIF
C       COMPUTE RUNOFF OCCURRING IN THE CURRENT TIME STEP
        DO 105 J=1,NDFVAL
          RI(J) = (CLSR2(J) - CLSR1(J))/DTLOAD
 105    CONTINUE

C       Create the values for dual-source irrigation. 

        IF(IRRIG_KNT.GT.0) THEN
C         Dual-source irrigation is active.  
          DO 110 J=1,IRRIG_KNT
C           Find the factor from the control table.
            ADRS = IRRIG_CONTROL_TAB(J)
            FNODE = IRRIG_SOURCE(J)
            ELEV = ZE(FNODE) + YE1(FNODE)
            CALL LKTAB
     I                (ADRS, ELEV, 0,
     O                 FRACTION, NTAB, DF)
            IT = IRRIG_TRIBA_ROW(J)
            TRIBA(IT,IRRIG_LUI_COMPUTE(J)) = 
     A                 -FRACTION*TRIBA(IT,IRRIG_LUI_APPLY(J))
110       CONTINUE
        ENDIF           


C       Scan through the tributary-area management vector and 
C       compute the lateral inflows.
        UNIT_PNT = 1
      
C       Clear the sum of outflows to the branches and LPR's 
C       from tributary areas
        L_TAQ = 0.D0

C       Clear the sum of outflows to boundary nodes
        L_TAQBN = 0.D0

C       Clear the sum of inflows to the tributary areas.  This
C       should be the runoff total coming from the rainfall-runoff
C       computations. 
        L_TAI = 0.D0

9000    CONTINUE

C         All tributary-area unit categories do the computations in the same
C         way.  They only differ in how the results are stored in
C         QPVEC.  

          CAT_CODE = TAM_ITAB(UNIT_PNT+1)
          TRIBA_PNT = TAM_ITAB(UNIT_PNT+3)
          GAGE = TAM_ITAB(UNIT_PNT+4)
          DLAY_PNT = TAM_ITAB(UNIT_PNT+6)
          DTEN_PNT = TAM_ITAB(UNIT_PNT+5)
          SUM = 0.0D0
          KS = GSTART(GAGE) - 1
          KE = GEND(GAGE)
          DO 1010 K=1,KE-KS
            KS = KS + 1
            SUM = SUM + TRIBA(TRIBA_PNT,K)*RI(KS)
1010      CONTINUE
C         Set QBAR in case there is no detention/delay
          QBAR = SUM
C         Update the sum of inflows to tributary area.  This includes
C         tributarary area connected to a boundary node. 
          L_TAI = L_TAI + SUM

C         At this point we have the runoff from the area in
C         this trib-area unit. Check for delay or detention.
C         If delay is present, it is done first.  Detention
C         if any is done next.   The routing coefficients for
C         delay have already been computed for the current 
C         time step. 
          IF(DLAY_PNT.GT.0) THEN
C           Flow at end of time step.
            QEND = SUM + DLAY_EXP_OF_DT_OVER_K(DLAY_PNT)*
     A          (DLAY_Q1(DLAY_PNT) - SUM)
            DLAY_Q2(DLAY_PNT) = QEND
C           Mean flow for the time step.
            QBAR = SUM + DLAY_K_OVER_DT(DLAY_PNT)*
     A            (DLAY_Q1(DLAY_PNT) - QEND)
          ENDIF              

          IF(DTEN_PNT.GT.0) THEN
C           Detention reservoir is present. Get the address of the
C           routing table and the values at the start of the 
C           time step. 
            ROUT_TAB = DTEN_ROUT_TAB(DTEN_PNT)
            QQ1 = DTEN_Q1(DTEN_PNT)
            Q1P = DTEN_Q1P(DTEN_PNT)
            S1 = DTEN_S1(DTEN_PNT)
            NUMBER_OF_PONDS = DTEN_AVDA(DTEN_PNT)
            SUMA = QBAR/NUMBER_OF_PONDS
            KNT = 0
C           Compute the predicted value of the storage at the end 
C           of the time step.
            S2 = S1 + DT*(SUMA - QQ1)/(1.0 + HALF_DT*Q1P)
            IF(S2.LT.0.0) THEN
C             The prediction equation finds that the reservoir 
C             has no water at some point within the time step.
C             Set the end of time step storage to zero. 
              S2 = 0.0
            ENDIF
C           Now use the predicted value in the correcter equation 
C           to get an improved value of S2.  Find the flow 
C           and its derivative wrt to storage at S2.  This begins a 
C           loop to make more than one correction. 
1015        CONTINUE
              CALL LKTAB
     I                  (ROUT_TAB, S2, 0,
     O                   QQ2, NTAB, Q2P)
C             Compute the outflow from the reservoir using the trapezoidal
C             rule with derivative end corrections. 
              QBAR = 0.5*(QQ1 + QQ2) + DT_OVER_12*
     A                (Q1P*(SUMA - QQ1) - Q2P*(SUMA - QQ2))
                    
              S2T = S1 + DT*(SUMA - QBAR)
              IF(ABS(S2T - S2)/(S2 + LPRMIN).GT.1.E-4) THEN
                KNT = KNT + 1
                IF(KNT.GT.20) THEN
                  WRITE(STDOUT,60) 
                  STOP 'Abnormal stop.  Errors found.'
                ELSE
                  S2 = S2T
                  GOTO 1015
                ENDIF
              ENDIF
            IF(S2.LT.0.0) THEN
C             The reservoir emptied at some point within the time step. 
              S2 = 0.0
              QQ2 = 0.0
              Q2P = 0.0
              QBAR = SUMA + S1/DT
            ENDIF
            QEND = QQ2*NUMBER_OF_PONDS
            QBAR = QBAR*NUMBER_OF_PONDS
            DTEN_S2(DTEN_PNT) = S2
            DTEN_Q2(DTEN_PNT) = QQ2
            DTEN_Q2P(DTEN_PNT) = Q2P
          ENDIF

          GOTO (1000, 2000, 3000), CAT_CODE
            WRITE(STDOUT,50) CAT_CODE
            STOP 'Abnormal stop. Bug found.'

1000        CONTINUE
C             Destination is a branch.  Distribute the flows to the
C             elements in proportion to the element lengths.
              FNODE = TAM_ITAB(UNIT_PNT+7)
              LNODE = TAM_ITAB(UNIT_PNT+8)
              FRACTION_PNT = TAM_ITAB(UNIT_PNT+9)
              DO 1020 J=FNODE,LNODE
                QPVEC(J) = QPVEC(J) + QBAR*
     A                      TAM_FTAB(FRACTION_PNT+J-FNODE)
1020         CONTINUE
             L_TAQ =  L_TAQ + QBAR 

             GOTO 9999

2000        CONTINUE
C             Destination is a level-pool reservoir            
              QP_PNT = TAM_ITAB(UNIT_PNT+7)
              QPVEC(QP_PNT) = QPVEC(QP_PNT) + QBAR
              L_TAQ =  L_TAQ + QBAR
              GOTO 9999

3000        CONTINUE
C             At boundary nodes we must use the flow at the end of the
C             time step. 
              QP_PNT = TAM_ITAB(UNIT_PNT+7)
              QPVEC(QP_PNT) = QPVEC(QP_PNT) + QEND
              RDUM = QPVEC(QP_PNT)
C             Stuff the current flow into EMC for the boundary condition.
C             The last one done for a node will then contain the sum of the
C             flow from detention and non-detention areas. 
              EMC(TAM_ITAB(UNIT_PNT+8)) = IDUM
C             The flow at a boundary node must be a value at a point
C             in time.  However, we will use the true averaage outflow
C             in computing the water balance for the tributary area. 
C             The water balance for the LPR's and branches will 
C             not use the current value because the flows at boundary
C             nodes are computed elsewhere.  Also there can be a lower
C             limit for the flow at a boundary node so that the 
C             flow computed here will not be used at the boundary if
C             it is smaller than the lower limit. 

              L_TAQBN = L_TAQBN +  QBAR
              GOTO 9999
            

9999      CONTINUE
C         Point to the next unit.
          UNIT_PNT = TAM_ITAB(UNIT_PNT+2)
          IF(UNIT_PNT.GT.0) GOTO 9000
      ELSE
        L_TAI = 0.D0
        L_TAQ = 0.D0
        L_TAQBN = 0.D0    
      ENDIF
 
      DO 200 I=1,NUM_TS
        IT = SOURCE_ADDRESS(I)
       
        IF(DEST_CAT(I).EQ.FORCED_BDY) THEN
          TIME1 = TIME
          AJTIME1 = AJTIME
        ELSE
          TIME1 = TIME2
          AJTIME1 = AJTIME2 
        ENDIF
        IF(SOURCE_CAT(I).EQ.TS_FROM_TABLE) THEN
C         From time-series table
 
          CALL LKTAB
     I              (IT, TIME1, 0,
     O               TS_VALUE, NTAB, PDV)
        ELSE
C         From time-series file
          CALL RDGET
     I              (IT, STDOUT, AJTIME1, DT,
     O               TS_VALUE)
        ENDIF
C       Now place the result in its destination(s).
        IT = I
190     CONTINUE
          IF(DEST_CAT(IT).EQ.FORCED_BDY) THEN
            RDUM = TS_VALUE
            EMC(DEST_PNT(IT)) = IDUM
          ELSEIF(DEST_CAT(IT).EQ.BRA_RAIN) THEN
C           Rain on a branch surface. Compute
C           surface area for each element and multiply
C           by the rainfall intensity to get the 
C           average inflow rate. 
            IBRA = DEST_PNT(IT)
            FNODE = BRPT(3,IBRA) + 1
            LNODE = BRPT(4,IBRA)
            DO 140 NODE=FNODE,LNODE
              DQ = 0.5*TS_VALUE*ABS(XVEC(NODE) - XVEC(NODE-1))*
     A                                    (T1(NODE) + T1(NODE-1))
              QPVEC(NODE) = QPVEC(NODE) + DQ
              L_WSI = L_WSI + DQ
140         CONTINUE
          ELSEIF(DEST_CAT(IT).EQ.BRA_EVAP) THEN
C           Evaporation on a branch surface. Compute
C           surface area for each element and multiply
C           by the evaporation intensity to get the 
C           average outflow rate. 
            IBRA = DEST_PNT(IT)
            FNODE = BRPT(3,IBRA) + 1
            LNODE = BRPT(4,IBRA)
            DO 142 NODE=FNODE,LNODE
              DQ = 0.5*TS_VALUE*ABS(XVEC(NODE) - XVEC(NODE-1))*
     A                                    (T1(NODE) + T1(NODE-1))
              QPVEC(NODE) = QPVEC(NODE) - DQ
              L_WSQ = L_WSQ + DQ
142         CONTINUE
          ELSEIF(DEST_CAT(IT).EQ.LPR_RAIN) THEN
C           Rainfall on a reservoir surface.  Surface area is in
C           TE1.
            PNT = DEST_PNT(IT)
C           Get the reservoir node number.  At a fixed offset from PNT.
            NODE = EMC(PNT-7)
C           Compute the rainfall flux and stuff into EMC as a real.
            RDUM = TS_VALUE*TE1(NODE)
            EMC(PNT) = IDUM
            L_WSI = L_WSI + RDUM
          ELSEIF(DEST_CAT(IT).EQ.LPR_EVAP) THEN
C           Evaporation on a reservoir surface.  Surface area is in
C           TE1.
            PNT = DEST_PNT(IT)
C           Get the reservoir node number.  At a fixed offset from PNT.
            NODE = EMC(PNT-8)
C           Compute the evaporation flux and stuff into EMC as a real.
            RDUM = TS_VALUE*TE1(NODE)
            EMC(PNT) = IDUM
            L_WSQ = L_WSQ + RDUM
          ENDIF
          IT = DEST_LINK(IT)
          IF(IT.GT.0) GOTO 190 
       
 200  CONTINUE
 
 
      IF(POINT.EQ.YES) THEN
        DO 100 I=1,LPNT
          ITYPE = PFPNT(1,I)
          ADRS = PFPNT(2,I)
          SHIFT = FTAB(ADRS+4)
          NB   = PFPNT(3,I)
 
C         TAKE THE VALUE AT THE MIDPOINT OF THE CURRENT INTERVAL
C         AS THE AVERAGE VALUE TO USE.
 
          TIME1 = ATIME + SHIFT - 0.5*DTLOAD
 
          CALL LKTAB
     I              (ADRS, TIME1, 0,
     O               FLOW, NTAB, PDV)
          IF(ITYPE.EQ.2) FLOW = -FLOW
          QPVEC(NB) = QPVEC(NB) + FLOW
C          FPVEC(NB) = FPVEC(NB) + FLOW*ABS(FLOW)*MF(I)
          IF(OUTPUT.GT.1) WRITE(STDOUT,58) NTAB, NB, TIME
 100    CONTINUE
      ENDIF
 
 
 
C     WIND LOADING
 
      IF(WIND.EQ.NO) GOTO 350
        CALL WSHEAR
     I             (TIME,
     O              SHEAR, WX, WY)
        DO 320 IBRA=1,NBRA
          FNODE = BRPT(3,IBRA) + 1
          LNODE = BRPT(4,IBRA)
          TEMP = WDFVEC(IBRA)*SHEAR
          DO 300 I=FNODE,LNODE
            WSVEC(I) = TEMP*( UVX(I)*WX + UVY(I)*WY )
 300      CONTINUE
 320    CONTINUE
 
C     WRITE OUT DATA
 
 350  CONTINUE
      IF(OUTPUT.LT.3) GOTO 410
      WRITE(STDOUT,52) TIME
      DO 400 I=1,NBN
        WRITE(STDOUT,54) I, QPVEC(I), WSVEC(I)
 400  CONTINUE
 410  CONTINUE
      IF(EFLAG.EQ.0) GOTO 900
      WRITE(STDOUT,56)
      STOP 'Abnormal stop: errors found.'
 900  RETURN
      END
C
C
C
      SUBROUTINE   SETICW
     I                   (DT, NBR, NBRA, WT, BRPT,
     M                    IEQ, ERRP, ERRQ,
     O                    BERRP, NERRP, BERRQ, NERRQ)
 
C     + + + PURPOSE + + +
C     Create the portion of the matrix corresponding to the
C     given branch number, NBR. IEQ gives the last equation created
C     in the matrix.  Used only for branches which have 2 unknowns
C     per node. Variable weight in x direction used.
C     This routine uses the curvilinear elements MA and MQ.
C     Otherwise it is the same as SETINW.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER BERRP, BERRQ, IEQ, NBR, NBRA, NERRP, NERRQ
      INTEGER BRPT(8,NBRA)
      REAL ERRP, ERRQ, WT
      REAL*8 DT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     DT     - time step in seconds
C     NBR    - number of the branch being processed
C     NBRA   - number of branches in the model
C     WT     - weight factor for approximating time integrals
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
C     IEQ    - equation number
C     ERRP   - current maximum relative change in surcharge storage
C     ERRQ   - maximum value of the ratio of lateral inflow to the
C               average flow in the element
C     BERRP  - records the branch number(internal) that has the
C               greatest absolute value of the change in surcharge
C               storage relative to the storage in the storm sewer
C     NERRP  - node at which maximum correction to surcharge storage
C               occurs
C     BERRQ  - records the branch number(internal) that has the
C               greatest value of the ratio of lateral inflow
C               to average flow in an element
C     NERRQ  - node at which maximum relative lateral inflow occurs
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'misccon.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'matcom.cmn'
      INCLUDE 'bnpond.cmn'
      INCLUDE 'grav.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADRS, ELMADR, FN, JCOL, LN, NINC, NND, NTAB, UBNBAS
      REAL ABARU, ALD, ALU, AMD, AMU, ARD, ARU, B, BLD, BLU, BRD, BRU,
     A     C1, C2, C3, C4, CF, DBLU, DBRU, DH, DKHLM, DKLU, DKRU, DMALU,
     B     DMARU, DMQLU, DMQRU, DQPYLU, DQPYRU, DTLU, DTRU, DV, DV2, DX,
     C     DX2, DXDT, DXH, DXHDT, DY, DYNDIF, DZ, ERR, GDE, KAC, KDC,
     D     KHLM, KLD, KLU, KMD, KMU, KRD, KRU, KSUM, MALD, MALU, MARD,
     E     MARU, MQLD, MQLU, MQRD, MQRU, NEWMOM, NEWSUM, NEWVOL, OLDFLW,
     F     OLDIMP, OLDMOM, OLDSUM, OLDVOL, OLDWND, PFQLU, PFQRU, PFYLU,
     G     PFYRU, PGFU, QLD, QLU, QMAX, QP, QRD, QRU, RES, S1, S2, S3,
     H     SFMT, SFMU, TLD, TLU, TP, TPA, TPB, TPC, TPD, TRD, TRU, VLD,
     I     VLU, VRD, VRU, WA, WTC, WX, YC, YLD, YLU, YM, YRD, YRU, ZI,
     J     ZIT, ZIY
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS, SIGN, SQRT
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LKTAB, XLKT23
C***********************************************************************
      WTC = 1.0 - WT
 
C     SET THE DIRECTION OF PROCESSING FOR THIS BRANCH.  THE SIGN OF THE
C     VARIABLE NUMBER FOR THE FIRST VARIABLE ON THE BRANCH SETS THE
C     DIRECTION
 
      JCOL = BRPT(7,NBR)
      IF(JCOL.GT.0) THEN
        FN = BRPT(3,NBR)
        LN = BRPT(4,NBR)
        NINC = 1
C       SET THE USER BRANCH NODE BASE FOR REPORTING NERRQ AND NERRP
        UBNBAS = BRPT(1,NBR) + 1
      ELSE
        FN = BRPT(4,NBR)
        LN = BRPT(3,NBR)
        NINC = -1
        JCOL = -JCOL
        UBNBAS = BRPT(2,NBR)
      ENDIF
 
        ZI = ZIVEC(NBR)
        ZIT = ZI
        ZIY = ZILIM(NBR)
        IF(STFLAG.EQ.0) THEN
          IF(NINC.GT.0) THEN
            TLD = T1(FN)
            ALD = A1(FN)
            YLD = Y1(FN)
            BLD = B1(FN)
            QLD = Q1(FN)
            KLD = K1(FN)
            MALD = MA1(FN)
            MQLD = MQ1(FN)
          ELSE
            TRD = T1(FN)
            ARD = A1(FN)
            YRD = Y1(FN)
            BRD = B1(FN)
            QRD = Q1(FN)
            KRD = K1(FN)
            MARD = MA1(FN)
            MQRD = MQ1(FN)
          ENDIF
        ENDIF
 
        IF(NINC.GT.0) THEN
          QLU = Q2(FN)
          YLU = Y2(FN)
          CALL XLKT23
     I               (NSEC(FN),
     M                YLU,
     O                ALU, TLU, DTLU, KLU, DKLU, BLU, DBLU, MALU, DMALU,
     O                MQLU, DMQLU)
          T2(FN) = TLU
          A2(FN) = ALU
          B2(FN) = BLU
          K2(FN) = KLU
          MA2(FN) = MALU
          MQ2(FN) = MQLU
          FN = FN + 1
        ELSE
          QRU = Q2(FN)
          YRU = Y2(FN)
          CALL XLKT23
     I               (NSEC(FN),
     M                YRU,
     O                ARU, TRU, DTRU, KRU, DKRU, BRU, DBRU, MARU, DMARU,
     O                MQRU, DMQRU)
          T2(FN) = TRU
          A2(FN) = ARU
          B2(FN) = BRU
          K2(FN) = KRU
          MA2(FN) = MARU
          MQ2(FN) = MQRU
          FN = FN - 1
        ENDIF
 
        DO 100 NND=FN,LN,NINC
          IF(NINC.EQ.1) THEN
            ELMADR = NND
          ELSE
            ELMADR = NND + 1
          ENDIF
          DX = DXVEC(ELMADR)
          DXH = 0.5*DX
          DX2 = DX + DX
          DXDT = DX/DT
          DXHDT =0.5*DXDT
          DZ = DZVEC(ELMADR)
          KAC = KA(ELMADR)
          KDC = KD(ELMADR)
          ADRS = HLTAB(ELMADR)
          IF(STFLAG.EQ.0) THEN
            WX = WXVEC(ELMADR)
            WA = WXVEC1(ELMADR)
            IF(NINC.GT.0) THEN
              TRD = T1(NND)
              ARD = A1(NND)
              YRD = Y1(NND)
              BRD = B1(NND)
              QRD = Q1(NND)
              KRD = K1(NND)
              MARD = MA1(NND)
              MQRD = MQ1(NND)
            ELSE
              TLD = T1(NND)
              ALD = A1(NND)
              YLD = Y1(NND)
              BLD = B1(NND)
              QLD = Q1(NND)
              KLD = K1(NND)
              MALD = MA1(NND)
              MQLD = MQ1(NND)
            ENDIF
 
C           SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL.
            IF(YLD.LT.ZIY.OR.YRD.LT.ZIY) THEN
              ZI = 0.0
            ELSE
              ZI = ZIT
            ENDIF
 
C           COMPUTE VALUES AT THE START OF THE TIME STEP AND STORE
 
            OLDSUM = QLD + QRD
            OLDMOM = MQLD*QLD + MQRD*QRD
            MOMVEC(ELMADR) = OLDMOM
 
            SUMVEC(ELMADR) = OLDSUM
            IF(OLDSUM.LT.0.0) THEN
              WA = 1. - WA
            ENDIF
            VLD = QLD/ALD
            VRD = QRD/ARD
 
            GDE = 0.0
            IF(KDC.GT.0.0.OR.KAC.GT.0.0) THEN
C             PROCESS EXPANSION AND CONTRACTION LOSSES
              DV = VLD - VRD
              IF(DV.GT.0.0) THEN
C               FLOW IS UNDERGOING NEGATIVE ACCELERATION-TAKEN
C               TO INDICATE EXPANSION
 
                GDE = 0.5*SIGN(KDC, OLDSUM)*ABS(DV*(VLD + VRD))
              ELSE
C               FLOW IS UNDERGOING POSITIVE ACCELERATION- TAKEN TO
C               INDICATE CONTRACTION
 
                GDE = 0.5*SIGN(KAC, OLDSUM)*ABS(DV*(VLD + VRD))
              ENDIF
            ENDIF
 
            IF(ADRS.GT.0) THEN
C             POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT
              YM = 0.5*(YLD + YRD)
              CALL LKTAB
     I                  (ADRS, YM, 0,
     O                   KHLM, NTAB, DKHLM)
              IF(OLDSUM.LT.0.0) THEN
                KHLM = -KHLM
                DKHLM = - DKHLM
              ENDIF
 
              GDE = GDE + 0.5*KHLM*(OLDSUM/(ALD + ARD))**2
            ENDIF
 
            DY = YRD - YLD
            KMD = KLD + WX*(KRD - KLD)
            AMD = ALD + WA*(ARD - ALD)
            OLDIMP = (GRAV*(DZ
     A                 + 0.25*OLDSUM*ABS(OLDSUM)*DX/KMD**2 + DY)
     1                 + GDE)*AMD
     3                 + ZI*(BRD*VRD*QRD - BLD*VLD*QLD)
            IMPVEC(ELMADR) = OLDIMP
            IF(WSVEC(ELMADR).NE.0.0) THEN
C             COMPUTE THE WIND STRESS TERM.  WSVEC IS USED TO HOLD
C             VALUE BECAUSE THE WIND STRESS IS RECOMPUTED FOR EACH
C             TIME STEP AT THE START OF THE TIME STEP.  WE USE THE
C             EULER APPROXIMATION FOR THE INTEGRAL TO SIMPLIFY THE
C             EQUATIONS.
 
              OLDWND = DXH*(TLD + TRD)*WSVEC(ELMADR)
              WSVEC(ELMADR) = OLDWND
            ELSE
              OLDWND = 0.0
            ENDIF
 
            OLDVOL = (1. - WA)*MALD*ALD + WA*MARD*ARD
            VOLVEC(ELMADR) = OLDVOL
            OLDFLW = QRD - QLD
            FLWVEC(ELMADR) = OLDFLW
 
            IF(NINC.GT.0) THEN
              YLD = YRD
              TLD = TRD
              ALD = ARD
              BLD = BRD
              KLD = KRD
              QLD = QRD
              MALD = MARD
              MQLD = MQRD
            ELSE
              YRD = YLD
              TRD = TLD
              ARD = ALD
              BRD = BLD
              KRD = KLD
              QRD = QLD
              MARD = MALD
              MQRD = MQLD
            ENDIF
          ELSE
            OLDSUM = SUMVEC(ELMADR)
            OLDMOM = MOMVEC(ELMADR)
            OLDIMP = IMPVEC(ELMADR)
            OLDVOL = VOLVEC(ELMADR)
            OLDFLW = FLWVEC(ELMADR)
            OLDWND = WSVEC(ELMADR)
          ENDIF
 
          WA = WXVEC2(ELMADR)
 
          IF(NINC.GT.0) THEN
            QRU = Q2(NND)
            YRU = Y2(NND)
            CALL XLKT23
     I                 (NSEC(NND),
     M                  YRU,
     O                  ARU, TRU, DTRU, KRU, DKRU, BRU, DBRU, MARU,
     O                  DMARU, MQRU, DMQRU)
            T2(NND) = TRU
            A2(NND) = ARU
            B2(NND) = BRU
            K2(NND) = KRU
            MA2(NND) = MARU
            MQ2(NND) = MQRU
          ELSE
            QLU = Q2(NND)
            YLU = Y2(NND)
            CALL XLKT23
     I                 (NSEC(NND),
     M                  YLU,
     O                  ALU, TLU, DTLU, KLU, DKLU, BLU, DBLU, MALU,
     O                  DMALU, MQLU, DMQLU)
            T2(NND) = TLU
            A2(NND) = ALU
            B2(NND) = BLU
            K2(NND) = KLU
            MA2(NND) = MALU
            MQ2(NND) = MQLU
          ENDIF
          NEWSUM = QLU + QRU
          NEWMOM = MQLU*QLU + MQRU*QRU
          IF(NEWSUM.LT.0.0) THEN
            WA = 1. - WA
          ENDIF
          DY = YRU - YLU
C         SELECT NEW VALUE OF WX.
          KMU = 0.5*(KLU + KRU)
          IF(NEWSUM.GE.0.0) THEN
C           FLOW IS FROM LEFT TO RIGHT. UPSTREAM END IS ON LEFT.
C            WRITE(STD6,*) ' CRITERION=',DKRU*(-DY - DZ) - KMU
C            WRITE(STD6,*) ' DKRU=',DKRU,'DY+DZ=',DY+DZ,' KMU=',KMU
            IF(DKRU*(-DY - DZ) - KMU.GE.0.0) THEN
C             SHIFT TO UPSTREAM CONVEYANCE.
              WX = 0.4*KLU/(DKRU*(-DY-DZ) - 0.5*(KRU - KLU))
              KMU = KLU + WX*(KRU - KLU)
            ELSE
              WX = 0.5
            ENDIF
          ELSE
C           FLOW IS FROM RIGHT TO LEFT. UPSTREAM END IS ON RIGHT.
            IF(DKLU*(DY + DZ) - KMU.GE.0.0) THEN
C             SHIFT TO UPSTREAM CONVEYANCE
              WX = 1.0 - 0.4*KRU/(DKLU*(DY + DZ) - .5*(KRU - KLU))
              KMU = KLU + WX*(KRU - KLU)
            ELSE
              WX = 0.5
            ENDIF
          ENDIF
 
          AMU = ALU + WA*(ARU - ALU)
          NEWVOL = (1. - WA)*MALU*ALU + WA*MARU*ARU
          WXVEC(ELMADR) = WX
          KSUM = KMU + KMU
 
C          IF(STFLAG.EQ.0)
C     A     WRITE(STD6,'(6H RDVAL,6F10.3)') YRD, TRD, ARD, KRD, BRD, QRD
C        WRITE(STD6,'(6H RUVAL,7F10.3)') YRU, TRU, ARU, KRU, BRU, QRU, DKRU
 
C         SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL.
          IF(YLU.LT.ZIY.OR.YRU.LT.ZIY) THEN
            ZI = 0.0
          ELSE
            ZI = ZIT
          ENDIF
 
C         CONTINUITY EQUATION
C         1) PARTIAL DERIVATIVES
 
C          WRITE(STD6,*) ' DXHDT=',DXHDT,' TLU=',TLU,' TRU=',TRU
          C1 = DXDT*(1. - WA)*(MALU*TLU + ALU*DMALU)
          C2 = -WT
          C3 = DXDT*(WA)*(MARU*TRU + ARU*DMARU)
          C4 = WT
 
          QP = QPVEC(ELMADR)
          CF = COEFIN(ELMADR)
          IF(CF.GT.0.0) THEN
 
C            PROCESS INFLOW RESTRICTION ON SEWERS
 
             YC = YCUT(ELMADR)
             S1 = POND1(ELMADR)
             S2 = POND2(ELMADR)
             YM = 0.5*((YLU + YRU))
             DH = YC - YM
             IF(ABS(DH).LE.DHSTAR) THEN
                QMAX = DH*CF*QPCON
             ELSE
                QMAX = CF*SQRT(TWOG*ABS(DH))
                IF(DH.LT.0.0) QMAX = -QMAX
             ENDIF
 
C            CHECK FOR FLOW ALLOWED
 
             TP = QP + S1/DT
             IF(QMAX.GT.TP) THEN
                POND2(ELMADR) = 0.0
                QP = TP
                DQPYLU = 0.0
                DQPYRU = 0.0
             ELSE
                S3 = S1 + DT*(QP-QMAX)
                B = ABS(S2 -S3)/(DX*OLDVOL)
                IF(B.GT.ERRP) THEN
                  ERRP = B
                  NERRP = UBNBAS + NND - FN
                  BERRP = NBR
                ENDIF
                POND2(ELMADR) = S3
                QP = QMAX
                IF(ABS(DH).LE.DHSTAR) THEN
                  DQPYLU = -0.5*CF*QPCON
                  DQPYRU = DQPYLU
                ELSE
                  DQPYLU = -HALFG*CF*CF/ABS(QP)
                  DQPYRU = DQPYLU
                ENDIF
             ENDIF
             C1 = C1 - DQPYLU
             C3 = C3 - DQPYRU
 
          ENDIF
 
C         2) RESIDUAL
          IEQ = IEQ +1
 
        DYNDIF = OLDFLW + WT*(QRU - QLU - OLDFLW) - QP
        RES = -((NEWVOL - OLDVOL)*DXDT + DYNDIF)
 
C        WRITE(STD6,1932) C2, C1, C4, C3, -RES
 
C        RESCALE THE CURRENT EQUATION
 
C        CMAX = 1.0/MAX(ABS(C1), ABS(C2), ABS(C3), ABS(C4))
 
C         JCOL GIVES THE VARIABLE NUMBER AT THE FIRST COEFFICIENT IN
C         THE EQUATIONS.
 
          IF(NINC.GT.0) THEN
            PDAVEC(R(IEQ)) = C2
            PDAVEC(C(JCOL+1)) = C1
            PDAVEC(C(JCOL+2)-1) = C4
            PDAVEC(C(JCOL+3)-2) = C3
          ELSE
            PDAVEC(R(IEQ)) = C4
            PDAVEC(C(JCOL+1)) = C3
            PDAVEC(C(JCOL+2)-1) = C2
            PDAVEC(C(JCOL+3)-2) = C1
          ENDIF
 
          RHS(IEQ) = RES
 
 
        ERR = ABS(QP)/(ABS(0.5*OLDSUM)+0.1)
        IF(ERR.GT.ERRQ) THEN
          ERRQ = ERR
          BERRQ = NBR
          NERRQ = UBNBAS + NND - FN
        ENDIF
 
C       MOMENTUM EQUATION
 
        SFMT = ABS(NEWSUM)/KSUM**2
        SFMU = NEWSUM*SFMT
C        WRITE(STD6,*) ' SFMU=', SFMU
        PGFU = GRAV*(DZ +SFMU*DX + DY)
        VLU = QLU/ALU
        VRU = QRU/ARU
        TPA = (DX2 + DX2)*SFMU/KSUM
        TPB = AMU*GRAV*DX2*SFMT
 
C       PARTIAL DERIVATIVES
 
        C1 =
     A      WT*(AMU*GRAV*(-TPA*DKLU*(1. - WX) - 1.0) +
     B      PGFU*(1. - WA)*TLU -
     D      ZI*((DBLU*QLU - TLU*BLU*VLU)*VLU - DXHDT*QLU*DMQLU))
 
 
        C2 =
     A      ZI*MQLU*DXHDT + WT*(TPB - 2.*ZI*BLU*VLU)
 
        C3 =
     A      WT*(AMU*GRAV*(-TPA*DKRU*WX + 1.0) +
     B      PGFU*(WA)*TRU +
     D      ZI*((DBRU*QRU - TRU*BRU*VRU)*VRU + DXHDT*QRU*DMQRU))
 
        C4 =
     A      ZI*MQRU*DXHDT + WT*(TPB + 2.*ZI*BRU*VRU)
 
        IF(KDC.GT.0.0.OR.KAC.GT.0.0) THEN
          ABARU = 0.5*(ALU + ARU)
C         PROCESS EXPANSION AND CONTRACTION LOSSES
          DV2 = ABS((VRU - VLU)*(VRU + VLU))
          IF(VLU.GE.VRU) THEN
C           FLOW IS UNDERGOING NEGATIVE ACCELERATION
 
            KDC = SIGN(KDC, NEWSUM)
            PFQLU = KDC*ABARU*VLU/ALU
            PFQRU = -KDC*ABARU*VRU/ARU
            PFYLU = TLU*(0.25*KDC*DV2 - PFQLU*VLU)
            PFYRU = TRU*(0.25*KDC*DV2 - PFQRU*VRU)
            GDE = 0.5*KDC*DV2
          ELSE
C           FLOW IS UNDERGOING POSITIVE ACCELERATION
 
            KAC = SIGN(KAC, NEWSUM)
            PFQLU = -KAC*ABARU*VLU/ALU
            PFQRU = KAC*ABARU*VRU/ARU
            PFYLU = TLU*(0.25*KAC*DV2 - PFQLU*VLU)
            PFYRU = TRU*(0.25*KAC*DV2 - PFQRU*VRU)
            GDE = 0.5*KAC*DV2
          ENDIF
 
          PGFU = PGFU + GDE
          C1 = C1 + WT*PFYLU
          C2 = C2 + WT*PFQLU
          C3 = C3 + WT*PFYRU
          C4 = C4 + WT*PFQRU
 
        ENDIF
 
        IF(ADRS.GT.0) THEN
C         POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT
          YM = 0.5*(YLU + YRU)
          ABARU = 0.5*(ALU + ARU)
          CALL LKTAB
     I              (ADRS, YM, 0,
     O               KHLM, NTAB, DKHLM)
          IF(NEWSUM.LT.0.0) THEN
            KHLM = -KHLM
            DKHLM = -DKHLM
          ENDIF
 
          TPA = NEWSUM/(ALU + ARU)**2
          TPB = TPA*NEWSUM
          GDE = 0.5*KHLM*TPB
          PGFU = PGFU + GDE
          TPC = WT*ABARU
          TPD = KHLM*TPA
 
          C1 = C1 - TPC*(TPD*TLU - DKHLM*TPB)
          C2 = C2 + TPC*TPD
          C3 = C3 - TPC*(TPD*TRU - DKHLM*TPB)
          C4 = C4 + TPC*TPD
        ENDIF
 
C        IF(C1.EQ.0.0) THEN
C          WRITE(STD6,*) ' C1=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
C        IF(C2.EQ.0.0) THEN
C          WRITE(STD6,*) ' C2=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
C        IF(C3.EQ.0.0) THEN
C          WRITE(STD6,*) ' C3=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
C        IF(C4.EQ.0.0) THEN
C          WRITE(STD6,*) ' C4=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
 
 
C       RESIDUAL
 
        RES = ZI*(NEWMOM - OLDMOM)*DXHDT + WT*(PGFU*AMU +
     A      ZI*(BRU*QRU*VRU - BLU*QLU*VLU)) + WTC*OLDIMP - OLDWND
 
          IEQ = IEQ + 1
 
C        WRITE(STD6,1932) C2, C1, C4, C3, RES
 
C1932    FORMAT(1X,5(1PE11.3))
 
C         RESCALE THE CURRENT EQUATION
 
C          CMAX = 1.0/MAX(ABS(C1), ABS(C2), ABS(C3), ABS(C4))
 
 
          IF(NINC.GT.0) THEN
            PDAVEC(R(IEQ)-1) = C2
            PDAVEC(R(IEQ)  ) = C1
            PDAVEC(C(JCOL+2)) = C4
            PDAVEC(C(JCOL+3)-1) = C3
          ELSE
            PDAVEC(R(IEQ)-1) = C4
            PDAVEC(R(IEQ)  ) = C3
            PDAVEC(C(JCOL+2)) = C2
            PDAVEC(C(JCOL+3)-1) = C1
          ENDIF
 
          RHS(IEQ) = -RES
 
C         TRANSFER VALUES
 
          IF(NINC.GT.0) THEN
            QLU = QRU
            ALU = ARU
            TLU = TRU
            YLU = YRU
            KLU = KRU
            DKLU = DKRU
            BLU = BRU
            DBLU = DBRU
            MALU = MARU
            MQLU = MQRU
            DMALU = DMARU
            DMQLU = DMQRU
          ELSE
            QRU = QLU
            ARU = ALU
            TRU = TLU
            YRU = YLU
            KRU = KLU
            DKRU = DKLU
            BRU = BLU
            DBRU = DBLU
            MARU = MALU
            MQRU = MQLU
            DMARU = DMALU
            DMQRU = DMQLU
          ENDIF
          JCOL = JCOL + 2
 
 100    CONTINUE
 
 
      RETURN
      END
C
C
C
      SUBROUTINE   SETICX
     I                   (DT, NBR, NBRA, WT, BRPT,
     M                    IEQ, ERRP, ERRQ,
     O                    BERRP, NERRP, BERRQ, NERRQ)
 
C     + + + PURPOSE + + +
C     Create the portion of the matrix corresponding to the
C     given branch number, NBR. IEQ gives the last equation created
C     in the matrix.  Used only for branches which have 2 unknowns
C     per node.  This routine uses the curvilinear elements MA and MQ.
C     Otherwise it is the same as SETINX.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER BERRP, BERRQ, IEQ, NBR, NBRA, NERRP, NERRQ
      INTEGER BRPT(8,NBRA)
      REAL ERRP, ERRQ, WT
      REAL*8 DT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     DT     - time step in seconds
C     NBR    - number of the branch being processed
C     NBRA   - number of branches in the model
C     WT     - weight factor for approximating time integrals
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
C     IEQ    - equation number
C     ERRP   - current maximum relative change in surcharge storage
C     ERRQ   - maximum value of the ratio of lateral inflow to the
C               average flow in the element
C     BERRP  - records the branch number(internal) that has the
C               greatest absolute value of the change in surcharge
C               storage relative to the storage in the storm sewer
C     NERRP  - node at which maximum correction to surcharge storage
C               occurs
C     BERRQ  - records the branch number(internal) that has the
C               greatest value of the ratio of lateral inflow
C               to average flow in an element
C     NERRQ  - node at which maximum relative lateral inflow occurs
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'misccon.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'matcom.cmn'
      INCLUDE 'bnpond.cmn'
      INCLUDE 'grav.cmn'
      INCLUDE 'stdun.cmn'
      INCLUDE 'julian.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADRS, ELMADR, FN, JCOL, LN, NINC, NND, NTAB, UBNBAS, 
     A        STDOUT
      REAL  ALD, ALU, AMD, AMU, ARD, ARU, B, BLD, BLU, BRD, BRU,
     A     C1, C2, C3, C4, CF, DBLU, DBRU, DH, DKHLM, DKLU, DKRU, DMALU,
     B     DMARU, DMQLU, DMQRU, DQPYLU, DQPYRU, DTLU, DTRU, DV, DV2, DX,
     C     DX2, DXDT, DXH, DXHDT, DYT, DYNDIF, DZ, ERR, GDE, KAC, KDC,
     D     KHLM, KLD, KLU, KMD, KMU, KRD, KRU, KSUM, MALD, MALU, MARD,
     E     MARU, MQLD, MQLU, MQRD, MQRU, NEWMOM, NEWSUM, NEWVOL, OLDFLW,
     F     OLDIMP, OLDMOM, OLDSUM, OLDVOL, OLDWND, PFQLU, PFQRU, PFYLU,
     G     PFYRU, PGFU, QLD, QLU, QMAX, QP, QRD, QRU, RES, S1, S2, S3,
     H     SFMT, SFMU, TLD, TLU, TP, TPA, TPB, TPC, TPD, TRD, TRU, VLD,
     I     VLU, VRD, VRU, WTC, WX, YC, YLD, YLU, YM, YRD, YRU, ZI, ZIT,
     J     ZIY
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS, SIGN, SQRT
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LKTAB, XLKT23
C***********************************************************************
      WTC = 1.0 - WT
      WX = 0.5

C     SET THE DIRECTION OF PROCESSING FOR THIS BRANCH.  THE SIGN OF THE
C     VARIABLE NUMBER FOR THE FIRST VARIABLE ON THE BRANCH SETS THE
C     DIRECTION
 
      JCOL = BRPT(7,NBR)
      IF(JCOL.GT.0) THEN
        FN = BRPT(3,NBR)
        LN = BRPT(4,NBR)
        NINC = 1
C       SET THE USER BRANCH NODE BASE FOR REPORTING NERRQ AND NERRP
        UBNBAS = BRPT(1,NBR) + 1
      ELSE
        FN = BRPT(4,NBR)
        LN = BRPT(3,NBR)
        NINC = -1
        JCOL = -JCOL
        UBNBAS = BRPT(2,NBR)
      ENDIF
 
        ZI = ZIVEC(NBR)
        ZIT = ZI
        ZIY = ZILIM(NBR)
        IF(STFLAG.EQ.0) THEN
          IF(NINC.GT.0) THEN
            TLD = T1(FN)
            ALD = A1(FN)
            YLD = Y1(FN)
            BLD = B1(FN)
            QLD = Q1(FN)
            KLD = K1(FN)
            MALD = MA1(FN)
            MQLD = MQ1(FN)
          ELSE
            TRD = T1(FN)
            ARD = A1(FN)
            YRD = Y1(FN)
            BRD = B1(FN)
            QRD = Q1(FN)
            KRD = K1(FN)
            MARD = MA1(FN)
            MQRD = MQ1(FN)
          ENDIF
        ENDIF
 
        IF(NINC.GT.0) THEN
          QLU = Q2(FN)
          YLU = Y2(FN)
          CALL XLKT23
     I               (NSEC(FN),
     M                YLU,
     O                ALU, TLU, DTLU, KLU, DKLU, BLU, DBLU, MALU, DMALU,
     O                MQLU, DMQLU)
          T2(FN) = TLU
          A2(FN) = ALU
          B2(FN) = BLU
          K2(FN) = KLU
          MA2(FN) = MALU
          MQ2(FN) = MQLU
          FN = FN + 1
        ELSE
          QRU = Q2(FN)
          YRU = Y2(FN)
          CALL XLKT23
     I               (NSEC(FN),
     M                YRU,
     O                ARU, TRU, DTRU, KRU, DKRU, BRU, DBRU, MARU, DMARU,
     O                MQRU, DMQRU)
          T2(FN) = TRU
          A2(FN) = ARU
          B2(FN) = BRU
          K2(FN) = KRU
          MA2(FN) = MARU
          MQ2(FN) = MQRU
          FN = FN - 1
        ENDIF
 
C      WRITE(STD6,*) ' Dump of residual and derivatives'
        DO 100 NND=FN,LN,NINC
          IF(NINC.EQ.1) THEN
            ELMADR = NND
          ELSE
            ELMADR = NND + 1
          ENDIF
          DX = DXVEC(ELMADR)
          DXH = 0.5*DX
          DX2 = DX + DX
          DXDT = DX/DT
          DXHDT =0.5*DXDT
          DZ = DZVEC(ELMADR)
          KAC = KA(ELMADR)
          KDC = KD(ELMADR)
          ADRS = HLTAB(ELMADR)
          IF(STFLAG.EQ.0) THEN
C            WX = WXVEC(ELMADR)
            
            IF(NINC.GT.0) THEN
              TRD = T1(NND)
              ARD = A1(NND)
              YRD = Y1(NND)
              BRD = B1(NND)
              QRD = Q1(NND)
              KRD = K1(NND)
              MARD = MA1(NND)
              MQRD = MQ1(NND)
            ELSE
              TLD = T1(NND)
              ALD = A1(NND)
              YLD = Y1(NND)
              BLD = B1(NND)
              QLD = Q1(NND)
              KLD = K1(NND)
              MALD = MA1(NND)
              MQLD = MQ1(NND)
            ENDIF
 
C           SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL.
            IF(YLD.LT.ZIY.OR.YRD.LT.ZIY) THEN
              ZI = 0.0
            ELSE
              ZI = ZIT
            ENDIF
 
C           COMPUTE VALUES AT THE START OF THE TIME STEP AND STORE
 
            OLDSUM = QLD + QRD
            OLDMOM = MQLD*QLD + MQRD*QRD
 
            SUMVEC(ELMADR) = OLDSUM
            MOMVEC(ELMADR) = OLDMOM
            VLD = QLD/ALD
            VRD = QRD/ARD
 
            GDE = 0.0
            IF(KDC.GT.0.0.OR.KAC.GT.0.0) THEN
C             PROCESS EXPANSION AND CONTRACTION LOSSES
              DV = VLD - VRD
              IF(DV.GT.0.0) THEN
C               FLOW IS UNDERGOING NEGATIVE ACCELERATION-TAKEN
C               TO INDICATE EXPANSION
 
                GDE = 0.5*SIGN(KDC, OLDSUM)*ABS(DV*(VLD + VRD))
              ELSE
C               FLOW IS UNDERGOING POSITIVE ACCELERATION- TAKEN TO
C               INDICATE CONTRACTION
 
                GDE = 0.5*SIGN(KAC, OLDSUM)*ABS(DV*(VLD + VRD))
              ENDIF
            ENDIF
 
            IF(ADRS.GT.0) THEN
C             POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT
              YM = 0.5*(YLD + YRD)
              CALL LKTAB
     I                  (ADRS, YM, 0,
     O                   KHLM, NTAB, DKHLM)
              IF(OLDSUM.LT.0.0) THEN
                KHLM = -KHLM
                DKHLM = - DKHLM
              ENDIF
 
              GDE = GDE + 0.5*KHLM*(OLDSUM/(ALD + ARD))**2
            ENDIF
 
            DYT = YRD - YLD
            KMD = KLD + WX*(KRD - KLD)
C            AMD = ALD + 0.5*(ARD - ALD)
            AMD = 0.5*(ARD + ALD)
            OLDIMP = (GRAV*(DZ
     A                 + 0.25*OLDSUM*ABS(OLDSUM)*DX/KMD**2 + DYT)
     1                 + GDE)*AMD
     3                 + ZI*(BRD*VRD*QRD - BLD*VLD*QLD)
            IMPVEC(ELMADR) = OLDIMP
            IF(WSVEC(ELMADR).NE.0.0) THEN
C             COMPUTE THE WIND STRESS TERM.  WSVEC IS USED TO HOLD
C             VALUE BECAUSE THE WIND STRESS IS RECOMPUTED FOR EACH
C             TIME STEP AT THE START OF THE TIME STEP.  WE USE THE
C             EULER APPROXIMATION FOR THE INTEGRAL TO SIMPLIFY THE
C             EQUATIONS.
 
              OLDWND = DXH*(TLD + TRD)*WSVEC(ELMADR)
              WSVEC(ELMADR) = OLDWND
            ELSE
              OLDWND = 0.0
            ENDIF
 
            OLDVOL = 0.5*(MALD*ALD + MARD*ARD)
            VOLVEC(ELMADR) = OLDVOL
            OLDFLW = QRD - QLD
            FLWVEC(ELMADR) = OLDFLW
 
            IF(NINC.GT.0) THEN
              YLD = YRD
              TLD = TRD
              ALD = ARD
              BLD = BRD
              KLD = KRD
              QLD = QRD
              MALD = MARD
              MQLD = MQRD
            ELSE
              YRD = YLD
              TRD = TLD
              ARD = ALD
              BRD = BLD
              KRD = KLD
              QRD = QLD
              MARD = MALD
              MQRD = MQLD
            ENDIF
          ELSE
            OLDSUM = SUMVEC(ELMADR)
            OLDMOM = MOMVEC(ELMADR)
            OLDIMP = IMPVEC(ELMADR)
            OLDVOL = VOLVEC(ELMADR)
            OLDFLW = FLWVEC(ELMADR)
            OLDWND = WSVEC(ELMADR)
          ENDIF
 
 
          IF(NINC.GT.0) THEN
            QRU = Q2(NND)
            YRU = Y2(NND)
            CALL XLKT23
     I                 (NSEC(NND),
     M                  YRU,
     O                  ARU, TRU, DTRU, KRU, DKRU, BRU, DBRU, MARU,
     O                  DMARU, MQRU, DMQRU)
            T2(NND) = TRU
            A2(NND) = ARU
            B2(NND) = BRU
            K2(NND) = KRU
            MA2(NND) = MARU
            MQ2(NND) = MQRU
          ELSE
            QLU = Q2(NND)
            YLU = Y2(NND)
            CALL XLKT23
     I                 (NSEC(NND),
     M                  YLU,
     O                  ALU, TLU, DTLU, KLU, DKLU, BLU, DBLU, MALU,
     O                  DMALU, MQLU, DMQLU)
            T2(NND) = TLU
            A2(NND) = ALU
            B2(NND) = BLU
            K2(NND) = KLU
            MA2(NND) = MALU
            MQ2(NND) = MQLU
          ENDIF
          NEWSUM = QLU + QRU
          NEWMOM = MQLU*QLU + MQRU*QRU
 
          DYT = YRU - YLU
C         SELECT NEW VALUE OF WX.

C         Debugging test
C          WX = 0.5
          KMU = 0.5*(KLU + KRU)
C         Disable this adjustment.  Feb. 2001
C          GOTO 9125          
C          IF(NEWSUM.GE.0.0) THEN
CC           FLOW IS FROM LEFT TO RIGHT. UPSTREAM END IS ON LEFT.
CC            WRITE(STD6,*) ' CRITERION=',DKRU*(-DYT - DZ) - KMU
CC            WRITE(STD6,*) ' DKRU=',DKRU,'DYT+DZ=',DYT+DZ,' KMU=',KMU
C            IF(DKRU*(-DYT - DZ) - KMU.GE.0.0) THEN
CC             SHIFT TO UPSTREAM CONVEYANCE.
C              WX = 0.4*KLU/(DKRU*(-DYT-DZ) - 0.5*(KRU - KLU))
C              KMU = KLU + WX*(KRU - KLU)
C            ELSE
C              WX = 0.5
C            ENDIF
C          ELSE
CC           FLOW IS FROM RIGHT TO LEFT. UPSTREAM END IS ON RIGHT.
C            IF(DKLU*(DYT + DZ) - KMU.GE.0.0) THEN
CC             SHIFT TO UPSTREAM CONVEYANCE
C              WX = 1.0 - 0.4*KRU/(DKLU*(DYT + DZ) - .5*(KRU - KLU))
C              KMU = KLU + WX*(KRU - KLU)
C            ELSE
C              WX = 0.5
C            ENDIF
C          ENDIF
C 
C9125      CONTINUE

          AMU =  0.5*(ARU + ALU)
          NEWVOL = 0.5*(MALU*ALU + MARU*ARU)
C          WXVEC(ELMADR) = WX
          KSUM = KMU + KMU
 
C          IF(STFLAG.EQ.0)
C     A     WRITE(STD6,'(6H RDVAL,6F10.3)') YRD, TRD, ARD, KRD, BRD, QRD
C        WRITE(STD6,'(6H RUVAL,7F10.3)') YRU, TRU, ARU, KRU, BRU, QRU, DKRU
 
C         SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL.
          IF(YLU.LT.ZIY.OR.YRU.LT.ZIY) THEN
            ZI = 0.0
          ELSE
            ZI = ZIT
          ENDIF
 
C         CONTINUITY EQUATION
C         1) PARTIAL DERIVATIVES
 
          C1 = DXHDT*(MALU*TLU + ALU*DMALU)
          C2 = -WT
          C3 = DXHDT*(MARU*TRU + ARU*DMARU)
          C4 = WT
 
          QP = QPVEC(ELMADR)
          CF = COEFIN(ELMADR)
          IF(CF.GT.0.0) THEN
 
C            PROCESS INFLOW RESTRICTION ON SEWERS
 
             YC = YCUT(ELMADR)
             S1 = POND1(ELMADR)
             S2 = POND2(ELMADR)
             YM = 0.5*((YLU + YRU))
             DH = YC - YM
             IF(ABS(DH).LE.DHSTAR) THEN
                QMAX = DH*CF*QPCON
             ELSE
                QMAX = CF*SQRT(TWOG*ABS(DH))
                IF(DH.LT.0.0) QMAX = -QMAX
             ENDIF
 
C            CHECK FOR FLOW ALLOWED
 
             TP = QP + S1/DT
             IF(QMAX.GT.TP) THEN
                POND2(ELMADR) = 0.0
                QP = TP
                DQPYLU = 0.0
                DQPYRU = 0.0
             ELSE
                S3 = S1 + DT*(QP-QMAX)
                B = ABS(S2 -S3)/(DX*OLDVOL)
                IF(B.GT.ERRP) THEN
                  ERRP = B
                  NERRP = UBNBAS + NND - FN
                  BERRP = NBR
                ENDIF
                POND2(ELMADR) = S3
                QP = QMAX
                IF(ABS(DH).LE.DHSTAR) THEN
                  DQPYLU = -0.5*CF*QPCON
                  DQPYRU = DQPYLU
                ELSE
                  DQPYLU = -HALFG*CF*CF/ABS(QP)
                  DQPYRU = DQPYLU
                ENDIF
             ENDIF
             C1 = C1 - DQPYLU
             C3 = C3 - DQPYRU
 
          ENDIF
 
C         2) RESIDUAL
          IEQ = IEQ +1
 
        DYNDIF = OLDFLW + WT*(QRU - QLU - OLDFLW) - QP
        RES = -((NEWVOL - OLDVOL)*DXDT + DYNDIF)
 
 
C        WRITE(STD6,2345) ' CON EQ:C1,C2,C3,C4,RES', C1, C2, C3, C4, RES
C2345  FORMAT(A,5(1PE10.3))
C         JCOL GIVES THE VARIABLE NUMBER AT THE FIRST COEFFICIENT IN
C         THE EQUATIONS.
 
          IF(NINC.GT.0) THEN
            PDAVEC(R(IEQ)) = C2
            PDAVEC(C(JCOL+1)) = C1
            PDAVEC(C(JCOL+2)-1) = C4
            PDAVEC(C(JCOL+3)-2) = C3
          ELSE
            PDAVEC(R(IEQ)) = C4
            PDAVEC(C(JCOL+1)) = C3
            PDAVEC(C(JCOL+2)-1) = C2
            PDAVEC(C(JCOL+3)-2) = C1
          ENDIF
 
          RHS(IEQ) = RES
 
 
        ERR = ABS(QP)/(ABS(0.5*OLDSUM)+0.1)
        IF(ERR.GT.ERRQ) THEN
          ERRQ = ERR
          BERRQ = NBR
          NERRQ = UBNBAS + NND - FN
        ENDIF
 
C       MOMENTUM EQUATION
 
        SFMT = ABS(NEWSUM)/KSUM**2
        SFMU = NEWSUM*SFMT
C        WRITE(STD6,*) ' SFMU=', SFMU
        PGFU = GRAV*(DZ + SFMU*DX + DYT)
        VLU = QLU/ALU
        VRU = QRU/ARU
        TPA = (DX2 + DX2)*SFMU/KSUM
        TPB = AMU*GRAV*DX2*SFMT
 
C       PARTIAL DERIVATIVES
 
        C1 =
     A      WT*(AMU*GRAV*(-TPA*DKLU*(1. - WX) - 1.0) +
     B      PGFU*(0.5)*TLU -
     D      ZI*((DBLU*QLU - TLU*BLU*VLU)*VLU - DXHDT*QLU*DMQLU))
 
 
        C2 =
     A      ZI*MQLU*DXHDT + WT*(TPB - 2.*ZI*BLU*VLU)
 
        C3 =
     A      WT*(AMU*GRAV*(-TPA*DKRU*WX + 1.0) +
     B      PGFU*(0.5)*TRU +
     D      ZI*((DBRU*QRU - TRU*BRU*VRU)*VRU + DXHDT*QRU*DMQRU))
 
        C4 =
     A      ZI*MQRU*DXHDT + WT*(TPB + 2.*ZI*BRU*VRU)
 

C       Debugging output 
C        IF(JTIME.GE.PRTIME) THEN
C          IF(IEQ.EQ.99999) THEN
C           Output details for the momentum balance
C            WRITE(STDOUT,50)  IEQ + 1
C50    FORMAT(/,' Detail for Eqno=',I6)
C            WRITE(STDOUT,51) 
C51    FORMAT('Lctn        Flow       Depth        Area   Top Width',
C     A'  Conveyance dConveyance        Beta       dBeta          MA',
C     B'         dMA          MQ         dMQ')
C
C            WRITE(STDOUT,52) 'LU  ', QLU, YLU, ALU, TLU, KLU, DKLU, BLU,
C     A                       DBLU, MALU, DMALU, MQLU, DMQLU
C            WRITE(STDOUT,52) 'RU  ', QRU, YRU, ARU, TRU, KRU, DKRU, BRU,
C     A                       DBRU, MARU, DMARU, MQRU, DMQRU
C52    FORMAT(A4,12(1PE12.5))
C
C            WRITE(STDOUT,53) WT, WX, ZI, DYT, DZ, DX
C53    FORMAT( ' WT=',F5.3,' WX=',F5.3,' ZI=',F5.3,
C     A       ' DYT=',1PE12.5,' DZ=',1PE12.5,' DX=',1PE12.5)
C
C            WRITE(STDOUT,54) SFMT, SFMU, PGFU, VLU, VRU, TPA, TPB
C54    FORMAT(' SFMT=',1PE12.5,' SFMU=',1PE12.5,' PGFU=',1PE12.5,
C     A' VLU=',1PE12.5,' VRU=',1PE12.5,' TPA=',1PE12.5,
C     B' TPB=',1PE12.5)
C
C            WRITE(STDOUT,55) AMU, DXHDT
C55    FORMAT(' AMU=',1PE12.5,' DXHDT=',1PE12.5)
C
C            WRITE(STDOUT,56) 'first: ', C1, C2, C3, C4
C56    FORMAT(A7,' C1=',1PE12.5,' C2=',1PE12.5,' C3=',1PE12.5,
C     A           ' C4=',1PE12.5)
C          ENDIF
C        ENDIF

        IF(KDC.GT.0.0.OR.KAC.GT.0.0) THEN
C         PROCESS EXPANSION AND CONTRACTION LOSSES
          DV2 = ABS((VRU - VLU)*(VRU + VLU))
          IF(VLU.GE.VRU) THEN
C           FLOW IS UNDERGOING NEGATIVE ACCELERATION
 
            KDC = SIGN(KDC, NEWSUM)
            PFQLU = KDC*AMU*VLU/ALU
            PFQRU = -KDC*AMU*VRU/ARU
            PFYLU = TLU*(0.25*KDC*DV2 - PFQLU*VLU)
            PFYRU = TRU*(0.25*KDC*DV2 - PFQRU*VRU)
            GDE = 0.5*KDC*DV2
          ELSE
C           FLOW IS UNDERGOING POSITIVE ACCELERATION
 
            KAC = SIGN(KAC, NEWSUM)
            PFQLU = -KAC*AMU*VLU/ALU
            PFQRU = KAC*AMU*VRU/ARU
            PFYLU = TLU*(0.25*KAC*DV2 - PFQLU*VLU)
            PFYRU = TRU*(0.25*KAC*DV2 - PFQRU*VRU)
            GDE = 0.5*KAC*DV2
          ENDIF
 
          PGFU = PGFU + GDE
          C1 = C1 + WT*PFYLU
          C2 = C2 + WT*PFQLU
          C3 = C3 + WT*PFYRU
          C4 = C4 + WT*PFQRU
 
        ENDIF
 
        IF(ADRS.GT.0) THEN
C         POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT
          YM = 0.5*(YLU + YRU)
          CALL LKTAB
     I              (ADRS, YM, 0,
     O               KHLM, NTAB, DKHLM)
          IF(NEWSUM.LT.0.0) THEN
            KHLM = -KHLM
            DKHLM = -DKHLM
          ENDIF
 
          TPA = NEWSUM/(ALU + ARU)**2
          TPB = TPA*NEWSUM
          GDE = 0.5*KHLM*TPB
          PGFU = PGFU + GDE
          TPC = WT*AMU
          TPD = KHLM*TPA
 
          C1 = C1 - TPC*(TPD*TLU - DKHLM*TPB)
          C2 = C2 + TPC*TPD
          C3 = C3 - TPC*(TPD*TRU - DKHLM*TPB)
          C4 = C4 + TPC*TPD
        ENDIF
 
C        IF(C1.EQ.0.0) THEN
C          WRITE(STD6,*) ' C1=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
C        IF(C2.EQ.0.0) THEN
C          WRITE(STD6,*) ' C2=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
C        IF(C3.EQ.0.0) THEN
C          WRITE(STD6,*) ' C3=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
C        IF(C4.EQ.0.0) THEN
C          WRITE(STD6,*) ' C4=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
 
 
C       RESIDUAL
 
        RES = ZI*(NEWMOM - OLDMOM)*DXHDT + WT*(PGFU*AMU +
     A      ZI*(BRU*QRU*VRU - BLU*QLU*VLU)) + WTC*OLDIMP - OLDWND
 
          IEQ = IEQ + 1

C        IF(JTIME.GE.PRTIME) THEN
C          IF(IEQ.EQ.9999) THEN
C            WRITE(STDOUT,56) 'scnd : ', C1, C2, C3, C4
C
C            WRITE(STDOUT,57) RES
C57    FORMAT('RES=',1PE12.5)
C          ENDIF
C        ENDIF


C        WRITE(STD6,2345) ' MOM EQ:C1,C2,C3,C4,RES', C1, C2, C3, C4, RES
 
 
          IF(NINC.GT.0) THEN
            PDAVEC(R(IEQ)-1) = C2
            PDAVEC(R(IEQ)  ) = C1
            PDAVEC(C(JCOL+2)) = C4
            PDAVEC(C(JCOL+3)-1) = C3
          ELSE
            PDAVEC(R(IEQ)-1) = C4
            PDAVEC(R(IEQ)  ) = C3
            PDAVEC(C(JCOL+2)) = C2
            PDAVEC(C(JCOL+3)-1) = C1
          ENDIF
 
          RHS(IEQ) = -RES
 
C         TRANSFER VALUES
 
          IF(NINC.GT.0) THEN
            QLU = QRU
            ALU = ARU
            TLU = TRU
            YLU = YRU
            KLU = KRU
            DKLU = DKRU
            BLU = BRU
            DBLU = DBRU
            MALU = MARU
            MQLU = MQRU
            DMALU = DMARU
            DMQLU = DMQRU
          ELSE
            QRU = QLU
            ARU = ALU
            TRU = TLU
            YRU = YLU
            KRU = KLU
            DKRU = DKLU
            BRU = BLU
            DBRU = DBLU
            MARU = MALU
            MQRU = MQLU
            DMARU = DMALU
            DMQRU = DMQLU
          ENDIF
          JCOL = JCOL + 2
 
 100    CONTINUE

C      WRITE(STD6,*) ' '
 
 
      RETURN
      END
C
C
C
      SUBROUTINE   SETINW
     I                   (DT, NBR, NBRA, WT, BRPT,
     M                    IEQ, ERRP, ERRQ,
     O                    BERRP, NERRP, BERRQ, NERRQ)
 
C     + + + PURPOSE + + +
C     Create the portion of the matrix corresponding to the
C     given branch number, NBR. IEQ gives the last equation created
C     in the matrix.  Used only for branches which have 2 unknowns
C     per node. Variable weight in x direction used.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER BERRP, BERRQ, IEQ, NBR, NBRA, NERRP, NERRQ
      INTEGER BRPT(8,NBRA)
      REAL ERRP, ERRQ, WT
      REAL*8 DT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     DT     - time step in seconds
C     NBR    - number of the branch being processed
C     NBRA   - number of branches in the model
C     WT     - weight factor for approximating time integrals
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
C     IEQ    - equation number
C     ERRP   - current maximum relative change in surcharge storage
C     ERRQ   - maximum value of the ratio of lateral inflow to the
C               average flow in the element
C     BERRP  - records the branch number(internal) that has the
C               greatest absolute value of the change in surcharge
C               storage relative to the storage in the storm sewer
C     NERRP  - node at which maximum correction to surcharge storage
C               occurs
C     BERRQ  - records the branch number(internal) that has the
C               greatest value of the ratio of lateral inflow
C               to average flow in an element
C     NERRQ  - node at which maximum relative lateral inflow occurs
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'misccon.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'matcom.cmn'
      INCLUDE 'bnpond.cmn'
      INCLUDE 'grav.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADRS, ELMADR, FN, JCOL, LN, NINC, NND, NTAB, UBNBAS
      REAL ABARU, ALD, ALU, AMD, AMU, ARD, ARU, B, BLD, BLU, BRD, BRU,
     A     C1, C2, C3, C4, CF, DBLU, DBRU, DH, DKHLM, DKLU, DKRU,
     B     DQPYLU, DQPYRU, DTLU, DTRU, DV, DV2, DX, DX2, DXDT, DXH,
     C     DXHDT, DY, DYNDIF, DZ, ERR, GDE, KAC, KDC, KHLM, KLD, KLU,
     D     KMD, KMU, KRD, KRU, KSUM, NEWSUM, OLDFLW, OLDIMP, OLDSUM,
     E     OLDVOL, OLDWND, PFQLU, PFQRU, PFYLU, PFYRU, PGFU, QLD, QLU,
     F     QMAX, QP, QRD, QRU, RES, S1, S2, S3, SFMT, SFMU, TLD, TLU,
     G     TP, TPA, TPB, TPC, TPD, TRD, TRU, VLD, VLU, VRD, VRU, WA,
     H     WTC, WX, YC, YLD, YLU, YM, YRD, YRU, ZI, ZIT, ZIY
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS, SIGN, SQRT
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LKTAB, XLKT20
C***********************************************************************
      WTC = 1.0 - WT
 
C     SET THE DIRECTION OF PROCESSING FOR THIS BRANCH.  THE SIGN OF THE
C     VARIABLE NUMBER FOR THE FIRST VARIABLE ON THE BRANCH SETS THE
C     DIRECTION
 
      JCOL = BRPT(7,NBR)
      IF(JCOL.GT.0) THEN
        FN = BRPT(3,NBR)
        LN = BRPT(4,NBR)
        NINC = 1
C       SET THE USER BRANCH NODE BASE FOR REPORINT NERRQ AND NERRP
        UBNBAS = BRPT(1,NBR) + 1
      ELSE
        FN = BRPT(4,NBR)
        LN = BRPT(3,NBR)
        NINC = -1
        JCOL = -JCOL
        UBNBAS = BRPT(2,NBR)
      ENDIF
 
        ZI = ZIVEC(NBR)
        ZIT = ZI
        ZIY = ZILIM(NBR)
        IF(STFLAG.EQ.0) THEN
          IF(NINC.GT.0) THEN
            TLD = T1(FN)
            ALD = A1(FN)
            YLD = Y1(FN)
            BLD = B1(FN)
            QLD = Q1(FN)
            KLD = K1(FN)
          ELSE
            TRD = T1(FN)
            ARD = A1(FN)
            YRD = Y1(FN)
            BRD = B1(FN)
            QRD = Q1(FN)
            KRD = K1(FN)
          ENDIF
        ENDIF
 
        IF(NINC.GT.0) THEN
          QLU = Q2(FN)
          YLU = Y2(FN)
          CALL XLKT20
     I               (NSEC(FN),
     M                YLU,
     O                ALU, TLU, DTLU, KLU, DKLU, BLU, DBLU)
          T2(FN) = TLU
          A2(FN) = ALU
          B2(FN) = BLU
          K2(FN) = KLU
          FN = FN + 1
        ELSE
          QRU = Q2(FN)
          YRU = Y2(FN)
          CALL XLKT20
     I               (NSEC(FN),
     M                YRU,
     O                ARU, TRU, DTRU, KRU, DKRU, BRU, DBRU)
          T2(FN) = TRU
          A2(FN) = ARU
          B2(FN) = BRU
          K2(FN) = KRU
          FN = FN - 1
        ENDIF
 
        DO 100 NND=FN,LN,NINC
          IF(NINC.EQ.1) THEN
            ELMADR = NND
          ELSE
            ELMADR = NND + 1
          ENDIF
          DX = DXVEC(ELMADR)
          DXH = 0.5*DX
          DX2 = DX + DX
          DXDT = DX/DT
          DXHDT =0.5*DXDT
          DZ = DZVEC(ELMADR)
          KAC = KA(ELMADR)
          KDC = KD(ELMADR)
          ADRS = HLTAB(ELMADR)
          IF(STFLAG.EQ.0) THEN
            WX = WXVEC(ELMADR)
            WA = WXVEC1(ELMADR)
C            WRITE(STD6,3421) NND, ELMADR, WA
C3421  FORMAT(' SETINW: NND=',I5,' ELMADR=',I5,' WA 1=',F10.5)
            IF(NINC.GT.0) THEN
              TRD = T1(NND)
              ARD = A1(NND)
              YRD = Y1(NND)
              BRD = B1(NND)
              QRD = Q1(NND)
              KRD = K1(NND)
            ELSE
              TLD = T1(NND)
              ALD = A1(NND)
              YLD = Y1(NND)
              BLD = B1(NND)
              QLD = Q1(NND)
              KLD = K1(NND)
            ENDIF
 
C           SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL.
            IF(YLD.LT.ZIY.OR.YRD.LT.ZIY) THEN
              ZI = 0.0
            ELSE
              ZI = ZIT
            ENDIF
 
C           COMPUTE VALUES AT THE START OF THE TIME STEP AND STORE
 
            OLDSUM = QLD + QRD
 
            SUMVEC(ELMADR) = OLDSUM
            IF(OLDSUM.LT.0.0) THEN
              WA = 1. - WA
            ENDIF
            VLD = QLD/ALD
            VRD = QRD/ARD
 
            GDE = 0.0
            IF(KDC.GT.0.0.OR.KAC.GT.0.0) THEN
C             PROCESS EXPANSION AND CONTRACTION LOSSES
              DV = VLD - VRD
              IF(DV.GT.0.0) THEN
C               FLOW IS UNDERGOING NEGATIVE ACCELERATION-TAKEN
C               TO INDICATE EXPANSION
 
                GDE = 0.5*SIGN(KDC, OLDSUM)*ABS(DV*(VLD + VRD))
              ELSE
C               FLOW IS UNDERGOING POSITIVE ACCELERATION- TAKEN TO
C               INDICATE CONTRACTION
 
                GDE = 0.5*SIGN(KAC, OLDSUM)*ABS(DV*(VLD + VRD))
              ENDIF
            ENDIF
 
            IF(ADRS.GT.0) THEN
C             POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT
              YM = 0.5*(YLD + YRD)
              CALL LKTAB
     I                  (ADRS, YM, 0,
     O                   KHLM, NTAB, DKHLM)
              IF(OLDSUM.LT.0.0) THEN
                KHLM = -KHLM
                DKHLM = - DKHLM
              ENDIF
 
              GDE = GDE + 0.5*KHLM*(OLDSUM/(ALD + ARD))**2
            ENDIF
 
            DY = YRD - YLD
            KMD = KLD + WX*(KRD - KLD)
            AMD = ALD + WA*(ARD - ALD)
            OLDIMP = (GRAV*(DZ
     A                 + 0.25*OLDSUM*ABS(OLDSUM)*DX/KMD**2 + DY)
     1                 + GDE)*AMD
     3                 + ZI*(BRD*VRD*QRD - BLD*VLD*QLD)
            IMPVEC(ELMADR) = OLDIMP
            IF(WSVEC(ELMADR).NE.0.0) THEN
C             COMPUTE THE WIND STRESS TERM.  WSVEC IS USED TO HOLD
C             VALUE BECAUSE THE WIND STRESS IS RECOMPUTED FOR EACH
C             TIME STEP AT THE START OF THE TIME STEP.  WE USE THE
C             EULER APPROXIMATION FOR THE INTEGRAL TO SIMPLIFY THE
C             EQUATIONS.
 
              OLDWND = DXH*(TLD + TRD)*WSVEC(ELMADR)
              WSVEC(ELMADR) = OLDWND
            ELSE
              OLDWND = 0.0
            ENDIF
 
            OLDVOL = AMD
            VOLVEC(ELMADR) = OLDVOL
            OLDFLW = QRD - QLD
            FLWVEC(ELMADR) = OLDFLW
 
            IF(NINC.GT.0) THEN
              YLD = YRD
              TLD = TRD
              ALD = ARD
              BLD = BRD
              KLD = KRD
              QLD = QRD
            ELSE
              YRD = YLD
              TRD = TLD
              ARD = ALD
              BRD = BLD
              KRD = KLD
              QRD = QLD
            ENDIF
          ELSE
            OLDSUM = SUMVEC(ELMADR)
            OLDIMP = IMPVEC(ELMADR)
            OLDVOL = VOLVEC(ELMADR)
            OLDFLW = FLWVEC(ELMADR)
            OLDWND = WSVEC(ELMADR)
          ENDIF
 
          WA = WXVEC2(ELMADR)
C            WRITE(STD6,3423) NND, ELMADR, WA
C3423  FORMAT(' SETINW: NND=',I5,' ELMADR=',I5,' WA 2=',F10.5)
 
          IF(NINC.GT.0) THEN
            QRU = Q2(NND)
            YRU = Y2(NND)
            CALL XLKT20
     I                 (NSEC(NND),
     M                  YRU,
     O                  ARU, TRU, DTRU, KRU, DKRU, BRU, DBRU)
            T2(NND) = TRU
            A2(NND) = ARU
            B2(NND) = BRU
            K2(NND) = KRU
          ELSE
            QLU = Q2(NND)
            YLU = Y2(NND)
            CALL XLKT20
     I                 (NSEC(NND),
     M                  YLU,
     O                  ALU, TLU, DTLU, KLU, DKLU, BLU, DBLU)
            T2(NND) = TLU
            A2(NND) = ALU
            B2(NND) = BLU
            K2(NND) = KLU
          ENDIF
          NEWSUM = QLU + QRU
          IF(NEWSUM.LT.0.0) THEN
            WA = 1. - WA
          ENDIF
          DY = YRU - YLU
C         SELECT NEW VALUE OF WX.
          KMU = 0.5*(KLU + KRU)
          IF(NEWSUM.GE.0.0) THEN
C           FLOW IS FROM LEFT TO RIGHT. UPSTREAM END IS ON LEFT.
C            WRITE(STD6,*) ' CRITERION=',DKRU*(-DY - DZ) - KMU
C            WRITE(STD6,*) ' DKRU=',DKRU,'DY+DZ=',DY+DZ,' KMU=',KMU
            IF(DKRU*(-DY - DZ) - KMU.GE.0.0) THEN
C             SHIFT TO UPSTREAM CONVEYANCE.
              WX = 0.4*KLU/(DKRU*(-DY-DZ) - 0.5*(KRU - KLU))
              KMU = KLU + WX*(KRU - KLU)
            ELSE
              WX = 0.5
            ENDIF
          ELSE
C           FLOW IS FROM RIGHT TO LEFT. UPSTREAM END IS ON RIGHT.
            IF(DKLU*(DY + DZ) - KMU.GE.0.0) THEN
C             SHIFT TO UPSTREAM CONVEYANCE
              WX = 1.0 - 0.4*KRU/(DKLU*(DY + DZ) - .5*(KRU - KLU))
              KMU = KLU + WX*(KRU - KLU)
            ELSE
              WX = 0.5
            ENDIF
          ENDIF
 
          AMU = ALU + WA*(ARU - ALU)
          WXVEC(ELMADR) = WX
          KSUM = KMU + KMU
 
C          IF(STFLAG.EQ.0)
C     A     WRITE(STD6,'(6H RDVAL,6F10.3)') YRD, TRD, ARD, KRD, BRD, QRD
C        WRITE(STD6,'(6H RUVAL,7F10.3)') YRU, TRU, ARU, KRU, BRU, QRU, DKRU
 
C         SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL.
          IF(YLU.LT.ZIY.OR.YRU.LT.ZIY) THEN
            ZI = 0.0
          ELSE
            ZI = ZIT
          ENDIF
 
 
 
C         CONTINUITY EQUATION
C         1) PARTIAL DERIVATIVES
 
C          WRITE(STD6,*) ' DXHDT=',DXHDT,' TLU=',TLU,' TRU=',TRU
          C1 = DXDT*(1. - WA)*TLU
          C2 = -WT
          C3 = DXDT*(WA)*TRU
          C4 = WT
 
          QP = QPVEC(ELMADR)
          CF = COEFIN(ELMADR)
          IF(CF.GT.0.0) THEN
 
C            PROCESS INFLOW RESTRICTION ON SEWERS
 
             YC = YCUT(ELMADR)
             S1 = POND1(ELMADR)
             S2 = POND2(ELMADR)
             YM = 0.5*((YLU + YRU))
             DH = YC - YM
             IF(ABS(DH).LE.DHSTAR) THEN
                QMAX = DH*CF*QPCON
             ELSE
                QMAX = CF*SQRT(TWOG*ABS(DH))
                IF(DH.LT.0.0) QMAX = -QMAX
             ENDIF
 
C            CHECK FOR FLOW ALLOWED
 
             TP = QP + S1/DT
             IF(QMAX.GT.TP) THEN
                POND2(ELMADR) = 0.0
                QP = TP
                DQPYLU = 0.0
                DQPYRU = 0.0
             ELSE
                S3 = S1 + DT*(QP-QMAX)
                B = ABS(S2 -S3)/(DX*OLDVOL)
                IF(B.GT.ERRP) THEN
                  ERRP = B
                  NERRP = UBNBAS + NND - FN
                  BERRP = NBR
                ENDIF
                POND2(ELMADR) = S3
                QP = QMAX
                IF(ABS(DH).LE.DHSTAR) THEN
                  DQPYLU = -0.5*CF*QPCON
                  DQPYRU = DQPYLU
                ELSE
                  DQPYLU = -HALFG*CF*CF/ABS(QP)
                  DQPYRU = DQPYLU
                ENDIF
             ENDIF
             C1 = C1 - DQPYLU
             C3 = C3 - DQPYRU
 
          ENDIF
 
C         2) RESIDUAL
          IEQ = IEQ +1
 
        DYNDIF = OLDFLW + WT*(QRU - QLU - OLDFLW) - QP
        RES = -((AMU - OLDVOL)*DXDT + DYNDIF)
 
 
C        WRITE(STD6,1932) C2, C1, C4, C3, -RES
 
C         RESCALE THE CURRENT EQUATION
 
C          CMAX = 1.0/MAX(ABS(C1), ABS(C2), ABS(C3), ABS(C4))
 
C         JCOL GIVES THE VARIABLE NUMBER AT THE FIRST COEFFICIENT IN
C         THE EQUATIONS.
 
          IF(NINC.GT.0) THEN
            PDAVEC(R(IEQ)) = C2
            PDAVEC(C(JCOL+1)) = C1
            PDAVEC(C(JCOL+2)-1) = C4
            PDAVEC(C(JCOL+3)-2) = C3
          ELSE
            PDAVEC(R(IEQ)) = C4
            PDAVEC(C(JCOL+1)) = C3
            PDAVEC(C(JCOL+2)-1) = C2
            PDAVEC(C(JCOL+3)-2) = C1
          ENDIF
 
          RHS(IEQ) = RES
 
 
        ERR = ABS(QP)/(ABS(0.5*OLDSUM)+0.1)
        IF(ERR.GT.ERRQ) THEN
          ERRQ = ERR
          BERRQ = NBR
          NERRQ = UBNBAS + NND - FN
        ENDIF
 
 
 
 
 
C       MOMENTUM EQUATION
 
        SFMT = ABS(NEWSUM)/KSUM**2
        SFMU = NEWSUM*SFMT
C        WRITE(STD6,*) ' SFMU=', SFMU
        PGFU = GRAV*(DZ +SFMU*DX + DY)
        VLU = QLU/ALU
        VRU = QRU/ARU
        TPA = (DX2 + DX2)*SFMU/KSUM
        TPB = AMU*GRAV*DX2*SFMT
 
C       PARTIAL DERIVATIVES
 
        C1 =
     A      WT*(AMU*GRAV*(-TPA*DKLU*(1. - WX) - 1.0) +
     B      PGFU*(1. - WA)*TLU -
     D      ZI*(DBLU*QLU - TLU*BLU*VLU)*VLU)
 
 
        C2 =
     A      ZI*DXHDT + WT*(TPB -  2.*ZI*BLU*VLU)
 
        C3 =
     A      WT*(AMU*GRAV*(-TPA*DKRU*WX + 1.0) +
     B      PGFU*(WA)*TRU +
     D      ZI*(DBRU*QRU - TRU*BRU*VRU)*VRU)
 
        C4 =
     A      ZI*DXHDT + WT*(TPB + 2.*ZI*BRU*VRU)
 
        IF(KDC.GT.0.0.OR.KAC.GT.0.0) THEN
          ABARU = 0.5*(ALU + ARU)
C         PROCESS EXPANSION AND CONTRACTION LOSSES
          DV2 = ABS((VRU - VLU)*(VRU + VLU))
          IF(VLU.GE.VRU) THEN
C           FLOW IS UNDERGOING NEGATIVE ACCELERATION
 
            KDC = SIGN(KDC, NEWSUM)
            PFQLU = KDC*ABARU*VLU/ALU
            PFQRU = -KDC*ABARU*VRU/ARU
            PFYLU = TLU*(0.25*KDC*DV2 - PFQLU*VLU)
            PFYRU = TRU*(0.25*KDC*DV2 - PFQRU*VRU)
            GDE = 0.5*KDC*DV2
          ELSE
C           FLOW IS UNDERGOING POSITIVE ACCELERATION
 
            KAC = SIGN(KAC, NEWSUM)
            PFQLU = -KAC*ABARU*VLU/ALU
            PFQRU = KAC*ABARU*VRU/ARU
            PFYLU = TLU*(0.25*KAC*DV2 - PFQLU*VLU)
            PFYRU = TRU*(0.25*KAC*DV2 - PFQRU*VRU)
            GDE = 0.5*KAC*DV2
          ENDIF
 
          PGFU = PGFU + GDE
          C1 = C1 + WT*PFYLU
          C2 = C2 + WT*PFQLU
          C3 = C3 + WT*PFYRU
          C4 = C4 + WT*PFQRU
 
        ENDIF
 
        IF(ADRS.GT.0) THEN
C         POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT
          YM = 0.5*(YLU + YRU)
          ABARU = 0.5*(ALU + ARU)
          CALL LKTAB
     I              (ADRS, YM, 0,
     O               KHLM, NTAB, DKHLM)
          IF(NEWSUM.LT.0.0) THEN
            KHLM = -KHLM
            DKHLM = -DKHLM
          ENDIF
 
          TPA = NEWSUM/(ALU + ARU)**2
          TPB = TPA*NEWSUM
          GDE = 0.5*KHLM*TPB
          PGFU = PGFU + GDE
          TPC = WT*ABARU
          TPD = KHLM*TPA
 
          C1 = C1 - TPC*(TPD*TLU - DKHLM*TPB)
          C2 = C2 + TPC*TPD
          C3 = C3 - TPC*(TPD*TRU - DKHLM*TPB)
          C4 = C4 + TPC*TPD
        ENDIF
 
C        IF(C1.EQ.0.0) THEN
C          WRITE(STD6,*) ' C1=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
C        IF(C2.EQ.0.0) THEN
C          WRITE(STD6,*) ' C2=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
C        IF(C3.EQ.0.0) THEN
C          WRITE(STD6,*) ' C3=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
C        IF(C4.EQ.0.0) THEN
C          WRITE(STD6,*) ' C4=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
 
 
C       RESIDUAL
 
        RES = ZI*(NEWSUM - OLDSUM)*DXHDT + WT*(PGFU*AMU +
     A      ZI*(BRU*QRU*VRU - BLU*QLU*VLU)) + WTC*OLDIMP - OLDWND
 
C        WRITE(STD6,1932) ,C2, C1, C4, C3, RES
C1932    FORMAT(1X,5(1PE11.3))
 
C         RESCALE THE CURRENT EQUATION
 
C          CMAX = 1.0/MAX(ABS(C1), ABS(C2), ABS(C3), ABS(C4))
 
 
          IEQ = IEQ + 1
          IF(NINC.GT.0) THEN
            PDAVEC(R(IEQ)-1) = C2
            PDAVEC(R(IEQ)  ) = C1
            PDAVEC(C(JCOL+2)) = C4
            PDAVEC(C(JCOL+3)-1) = C3
          ELSE
            PDAVEC(R(IEQ)-1) = C4
            PDAVEC(R(IEQ)  ) = C3
            PDAVEC(C(JCOL+2)) = C2
            PDAVEC(C(JCOL+3)-1) = C1
          ENDIF
 
          RHS(IEQ) = -RES
 
C         TRANSFER VALUES
 
          IF(NINC.GT.0) THEN
            QLU = QRU
            ALU = ARU
            TLU = TRU
            YLU = YRU
            KLU = KRU
            DKLU = DKRU
            BLU = BRU
            DBLU = DBRU
          ELSE
            QRU = QLU
            ARU = ALU
            TRU = TLU
            YRU = YLU
            KRU = KLU
            DKRU = DKLU
            BRU = BLU
            DBRU = DBLU
          ENDIF
          JCOL = JCOL + 2
 
 100    CONTINUE
 
 
      RETURN
      END
C
C
C
      SUBROUTINE  XXLKT20
     I                   (ADRS,
     M                    YA,
     O                    A, T, DT, K, DK, B, DB)
 
C     Experiment with speed up of look up.
C     + + + PURPOSE + + +
C     Given depth find area, top-width, conveyance, etc.
C     using direct linear interpolation for top width.
 
      IMPLICIT  NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
      REAL A, B, DB, DK, DT, K, T, YA
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB
C     YA     - depth to use for table look up
C     A      - Cross sectional area from the cross section table
C     T      - top width of the cross section
C     DT     - derivative of the top width with respect to depth
C     K      - conveyance
C     DK     - derivative of conveyance with respect to depth
C     B      - the value of the momentum flux correction coef. from the
C               table
C     DB     - derivative of B with respect to depth
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'offcom.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER  IT, L, TYPE, XOFF
      REAL B0, DY, DYI, H, K0, T0, Y, Y0
 
C***********************************************************************
C     L = ADDRESS FOUND ON THE LAST CALL TO XLKT20
 
      Y = YA
      L = ITAB(ADRS+3)
 
      TYPE = ITAB(ADRS+2)
      XOFF = OFFVEC(TYPE)
 
      IF(Y.GE.FTAB(L)) THEN
 100   CONTINUE
         IF(Y.GT.FTAB(L+XOFF)) THEN
           L = L + XOFF
           GOTO 100
         ENDIF
      ELSE
 110   CONTINUE
         L = L - XOFF
         IF(Y.LT.FTAB(L)) GOTO 110
      ENDIF
C     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE
C     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED
C     FOR ARGUMENT OUT OF RANGE.
 
C     RESET POINTER FOR LAST ADDRESS
 
      ITAB(ADRS+3) = L
 
C     FETCH VALUES FROM FTAB
 
      Y0 = FTAB(L)
      T0 = FTAB(L+1)
      K0 = FTAB(L+3)
      B0 = FTAB(L+4)
 
C     DIRECT LINEAR INTERPOLATION FOR T AND SQRT(CONVEYANCE)
C     N.B. K IN FTAB IS SQRT(CONVEYANCE)
 
      IT = L + XOFF
      DY = FTAB(IT) - Y0
      H = Y - Y0
      DYI = 1.0/DY
      DB = (FTAB(IT+4) - B0)*DYI
      DT = (FTAB(IT+1) - T0)*DYI
      DK = (FTAB(IT+3) - K0)*DYI
      T = T0 + H*DT
      B = B0 + H*DB
      A = FTAB(L+2) + 0.5*H*(T + T0)
      K = K0 + H*DK
      DK = (K + K)*DK
      K = K*K
 
      RETURN
      END
C
C
C
      SUBROUTINE   SETINX
     I                   (DT, NBR, NBRA, WT, BRPT,
     M                    IEQ, ERRP, ERRQ,
     O                    BERRP, NERRP, BERRQ, NERRQ)
 
C     + + + PURPOSE + + +
C     Create the portion of the matrix corresponding to the
C     given branch number, NBR. IEQ gives the last equation created
C     in the matrix.  Used only for branches which have 2 unknowns
C     per node.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER BERRP, BERRQ, IEQ, NBR, NBRA, NERRP, NERRQ
      INTEGER BRPT(8,NBRA)
      REAL ERRP, ERRQ, WT
      REAL*8 DT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     DT     - time step in seconds
C     NBR    - number of the branch being processed
C     NBRA   - number of branches in the model
C     WT     - weight factor for approximating time integrals
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
C     IEQ    - equation number
C     ERRP   - current maximum relative change in surcharge storage
C     ERRQ   - maximum value of the ratio of lateral inflow to the
C               average flow in the element
C     BERRP  - records the branch number(internal) that has the
C               greatest absolute value of the change in surcharge
C               storage relative to the storage in the storm sewer
C     NERRP  - node at which maximum correction to surcharge storage
C               occurs
C     BERRQ  - records the branch number(internal) that has the
C               greatest value of the ratio of lateral inflow
C               to average flow in an element
C     NERRQ  - node at which maximum relative lateral inflow occurs
 
      INCLUDE 'arsize.prm'         
      INCLUDE 'misccon.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'matcom.cmn'
      INCLUDE 'bnpond.cmn'
      INCLUDE 'grav.cmn'
      INCLUDE 'ftable.cmn'
      INCLUDE 'offcom.cmn'
      INCLUDE 'stdun.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADRS, ELMADR, FN, JCOL, LN, NINC, NND, NTAB, UBNBAS
      REAL ABARU, ALD, ALU, AMD, AMU, ARD, ARU, B, BLD, BLU, BRD, BRU,
     A     C1, C2, C3, C4, CF, DBLU, DBRU, DH, DK, DKHLM, DKLU, DKRU,
     B     DQPYLU, DQPYRU, DTLU, DTRU, DV, DV2, DX, DX2, DXDT, DXH,
     C     DXHDT, DY, DYNDIF, DZ, ERR, GDE, KAC, KDC, KHLM, KLD, KLU,
     D     KMD, KMU, KRD, KRU, KSUM, NEWSUM, OLDFLW, OLDIMP, OLDSUM,
     E     OLDVOL, OLDWND, PFQLU, PFQRU, PFYLU, PFYRU, PGFU, QLD, QLU,
     F     QMAX, QP, QRD, QRU, RES, S1, S2, S3, SFMT, SFMU, TLD, TLU,
     G     TP, TPA, TPB, TPC, TPD, TRD, TRU, VLD, VLU, VRD, VRU, WTC,
     H     WX, YC, YLD, YLU, YM, YRD, YRU, ZI, ZIT, ZIY
 
C     + + + LOCAL VARIABLES for inline table lookup
      INTEGER  IT, L, TYPE, XOFF
      REAL B0, DYI, H, K0, T0, Y0

C     + + + INTRINSICS + + +
      INTRINSIC ABS, SIGN, SQRT
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LKTAB, XXLKT20
C***********************************************************************
      WTC = 1.0 - WT
 
C     SET THE DIRECTION OF PROCESSING FOR THIS BRANCH.  THE SIGN OF THE
C     VARIABLE NUMBER FOR THE FIRST VARIABLE ON THE BRANCH SETS THE
C     DIRECTION
 
      JCOL = BRPT(7,NBR)
      IF(JCOL.GT.0) THEN
        FN = BRPT(3,NBR)
        LN = BRPT(4,NBR)
        NINC = 1
C       SET THE USER BRANCH NODE BASE FOR REPORTING NERRQ AND NERRP
        UBNBAS = BRPT(1,NBR) + 1
      ELSE
        FN = BRPT(4,NBR)
        LN = BRPT(3,NBR)
        NINC = -1
        JCOL = -JCOL
        UBNBAS = BRPT(2,NBR)
      ENDIF
 
        ZI = ZIVEC(NBR)
        ZIT = ZI
        ZIY = ZILIM(NBR)
        IF(STFLAG.EQ.0) THEN
          IF(NINC.GT.0) THEN
            TLD = T1(FN)
            ALD = A1(FN)
            YLD = Y1(FN)
            BLD = B1(FN)
            QLD = Q1(FN)
            KLD = K1(FN)
          ELSE
            TRD = T1(FN)
            ARD = A1(FN)
            YRD = Y1(FN)
            BRD = B1(FN)
            QRD = Q1(FN)
            KRD = K1(FN)
          ENDIF
        ENDIF
 
        IF(NINC.GT.0) THEN
          QLU = Q2(FN)
          YLU = Y2(FN)
          CALL XXLKT20
     I               (NSEC(FN),
     M                YLU,
     O                ALU, TLU, DTLU, KLU, DKLU, BLU, DBLU)
          T2(FN) = TLU
          A2(FN) = ALU
          B2(FN) = BLU
          K2(FN) = KLU
          FN = FN + 1
        ELSE
          QRU = Q2(FN)
          YRU = Y2(FN)
          CALL XXLKT20
     I               (NSEC(FN),
     M                YRU,
     O                ARU, TRU, DTRU, KRU, DKRU, BRU, DBRU)
          T2(FN) = TRU
          A2(FN) = ARU
          B2(FN) = BRU
          K2(FN) = KRU
          FN = FN - 1
        ENDIF
 
C      WRITE(STD6,*) ' Dump of residual and derivatives'
        DO 100 NND=FN,LN,NINC
          IF(NINC.EQ.1) THEN
            ELMADR = NND
          ELSE
            ELMADR = NND + 1
          ENDIF
          DX = DXVEC(ELMADR)
          DXH = 0.5*DX
          DX2 = DX + DX
          DXDT = DX/DT
          DXHDT =0.5*DXDT
          DZ = DZVEC(ELMADR)
          KAC = KA(ELMADR)
          KDC = KD(ELMADR)
          ADRS = HLTAB(ELMADR)
          IF(STFLAG.EQ.0) THEN
            WX = WXVEC(ELMADR)
            IF(NINC.GT.0) THEN
              TRD = T1(NND)
              ARD = A1(NND)
              YRD = Y1(NND)
              BRD = B1(NND)
              QRD = Q1(NND)
              KRD = K1(NND)
            ELSE
              TLD = T1(NND)
              ALD = A1(NND)
              YLD = Y1(NND)
              BLD = B1(NND)
              QLD = Q1(NND)
              KLD = K1(NND)
            ENDIF
 
C           SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL.
            IF(YLD.LT.ZIY.OR.YRD.LT.ZIY) THEN
              ZI = 0.0
            ELSE
              ZI = ZIT
            ENDIF
 
C           COMPUTE VALUES AT THE START OF THE TIME STEP AND STORE
 
            OLDSUM = QLD + QRD
 
            SUMVEC(ELMADR) = OLDSUM
            VLD = QLD/ALD
            VRD = QRD/ARD
 
            GDE = 0.0
            IF(KDC.GT.0.0.OR.KAC.GT.0.0) THEN
C             PROCESS EXPANSION AND CONTRACTION LOSSES
              DV = VLD - VRD
              IF(DV.GT.0.0) THEN
C               FLOW IS UNDERGOING NEGATIVE ACCELERATION-TAKEN
C               TO INDICATE EXPANSION
 
                GDE = 0.5*SIGN(KDC, OLDSUM)*ABS(DV*(VLD + VRD))
              ELSE
C               FLOW IS UNDERGOING POSITIVE ACCELERATION- TAKEN TO
C               INDICATE CONTRACTION
 
                GDE = 0.5*SIGN(KAC, OLDSUM)*ABS(DV*(VLD + VRD))
              ENDIF
            ENDIF
 
            IF(ADRS.GT.0) THEN
C             POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT
              YM = 0.5*(YLD + YRD)
              CALL LKTAB
     I                  (ADRS, YM, 0,
     O                   KHLM, NTAB, DKHLM)
              IF(OLDSUM.LT.0.0) THEN
                KHLM = -KHLM
                DKHLM = - DKHLM
              ENDIF
 
              GDE = GDE + 0.5*KHLM*(OLDSUM/(ALD + ARD))**2
            ENDIF
 
            DY = YRD - YLD
            KMD = KLD + WX*(KRD - KLD)
            AMD = ALD + 0.5*(ARD - ALD)
            OLDIMP = (GRAV*(DZ
     A                 + 0.25*OLDSUM*ABS(OLDSUM)*DX/KMD**2 + DY)
     1                 + GDE)*AMD
     3                 + ZI*(BRD*VRD*QRD - BLD*VLD*QLD)
            IMPVEC(ELMADR) = OLDIMP
            IF(WSVEC(ELMADR).NE.0.0) THEN
C             COMPUTE THE WIND STRESS TERM.  WSVEC IS USED TO HOLD
C             VALUE BECAUSE THE WIND STRESS IS RECOMPUTED FOR EACH
C             TIME STEP AT THE START OF THE TIME STEP.  WE USE THE
C             EULER APPROXIMATION FOR THE INTEGRAL TO SIMPLIFY THE
C             EQUATIONS.
 
              OLDWND = DXH*(TLD + TRD)*WSVEC(ELMADR)
              WSVEC(ELMADR) = OLDWND
            ELSE
              OLDWND = 0.0
            ENDIF
 
            OLDVOL = AMD
            VOLVEC(ELMADR) = OLDVOL
            OLDFLW = QRD - QLD
            FLWVEC(ELMADR) = OLDFLW
 
            IF(NINC.GT.0) THEN
              YLD = YRD
              TLD = TRD
              ALD = ARD
              BLD = BRD
              KLD = KRD
              QLD = QRD
            ELSE
              YRD = YLD
              TRD = TLD
              ARD = ALD
              BRD = BLD
              KRD = KLD
              QRD = QLD
            ENDIF
          ELSE
            OLDSUM = SUMVEC(ELMADR)
            OLDIMP = IMPVEC(ELMADR)
            OLDVOL = VOLVEC(ELMADR)
            OLDFLW = FLWVEC(ELMADR)
            OLDWND = WSVEC(ELMADR)
          ENDIF
 
 
          IF(NINC.GT.0) THEN
            QRU = Q2(NND)
            YRU = Y2(NND)
C            CALL XXLKT20
C     I                 (NSEC(NND),
C     M                  YRU,
C     O                  ARU, TRU, DTRU, KRU, DKRU, BRU, DBRU)

C     Inline lookup code

      IT = NSEC(NND)
      L = ITAB(IT+3)
 
      TYPE = ITAB(IT+2)
      XOFF = OFFVEC(TYPE)
 
      IF(YRU.GE.FTAB(L)) THEN
 8100  CONTINUE
         IF(YRU.GT.FTAB(L+XOFF)) THEN
           L = L + XOFF
           GOTO 8100
         ENDIF
      ELSE
 8110  CONTINUE
         L = L - XOFF
         IF(YRU.LT.FTAB(L)) GOTO 8110
      ENDIF
      ITAB(IT+3) = L
 
      Y0 = FTAB(L)
      T0 = FTAB(L+1)
      K0 = FTAB(L+3)
      B0 = FTAB(L+4)
 
      IT = L + XOFF
      DY = FTAB(IT) - Y0
      H = YRU - Y0
      DYI = 1.0/DY
      DBRU = (FTAB(IT+4) - B0)*DYI
      DTRU = (FTAB(IT+1) - T0)*DYI
      DK = (FTAB(IT+3) - K0)*DYI
      TRU = T0 + H*DTRU
      BRU = B0 + H*DBRU
      ARU = FTAB(L+2) + 0.5*H*(TRU + T0)
      KRU = K0 + H*DK
      DKRU = (KRU + KRU)*DK
      KRU = KRU*KRU

C     End inline lookup code.

            T2(NND) = TRU
            A2(NND) = ARU
            B2(NND) = BRU
            K2(NND) = KRU
          ELSE
            QLU = Q2(NND)
            YLU = Y2(NND)
C            CALL XXLKT20
C     I                 (NSEC(NND),
C     M                  YLU,
C     O                  ALU, TLU, DTLU, KLU, DKLU, BLU, DBLU)

C     Inline lookup code

      IT = NSEC(NND)
      L = ITAB(IT+3)
 
      TYPE = ITAB(IT+2)
      XOFF = OFFVEC(TYPE)
 
      IF(YLU.GE.FTAB(L)) THEN
 9100  CONTINUE
         IF(YLU.GT.FTAB(L+XOFF)) THEN
           L = L + XOFF
           GOTO 9100
         ENDIF
      ELSE
 9110  CONTINUE
         L = L - XOFF
         IF(YLU.LT.FTAB(L)) GOTO 9110
      ENDIF
      ITAB(IT+3) = L
 
      Y0 = FTAB(L)
      T0 = FTAB(L+1)
      K0 = FTAB(L+3)
      B0 = FTAB(L+4)
 
      IT = L + XOFF
      DY = FTAB(IT) - Y0
      H = YLU - Y0
      DYI = 1.0/DY
      DBLU = (FTAB(IT+4) - B0)*DYI
      DTLU = (FTAB(IT+1) - T0)*DYI
      DK = (FTAB(IT+3) - K0)*DYI
      TLU = T0 + H*DTLU
      BLU = B0 + H*DBLU
      ALU = FTAB(L+2) + 0.5*H*(TLU + T0)
      KLU = K0 + H*DK
      DKLU = (KLU + KLU)*DK
      KLU = KLU*KLU

C     End inline lookup code.

            T2(NND) = TLU
            A2(NND) = ALU
            B2(NND) = BLU
            K2(NND) = KLU
          ENDIF
          NEWSUM = QLU + QRU
 
          DY = YRU - YLU
C         SELECT NEW VALUE OF WX.
          KMU = 0.5*(KLU + KRU)
          IF(NEWSUM.GE.0.0) THEN
C           FLOW IS FROM LEFT TO RIGHT. UPSTREAM END IS ON LEFT.
C            WRITE(STD6,*) ' CRITERION=',DKRU*(-DY - DZ) - KMU
C            WRITE(STD6,*) ' DKRU=',DKRU,'DY+DZ=',DY+DZ,' KMU=',KMU
            IF(DKRU*(-DY - DZ) - KMU.GE.0.0) THEN
C             SHIFT TO UPSTREAM CONVEYANCE.
              WX = 0.4*KLU/(DKRU*(-DY-DZ) - 0.5*(KRU - KLU))
              KMU = KLU + WX*(KRU - KLU)
            ELSE
              WX = 0.5
            ENDIF
          ELSE
C           FLOW IS FROM RIGHT TO LEFT. UPSTREAM END IS ON RIGHT.
            IF(DKLU*(DY + DZ) - KMU.GE.0.0) THEN
C             SHIFT TO UPSTREAM CONVEYANCE
              WX = 1.0 - 0.4*KRU/(DKLU*(DY + DZ) - .5*(KRU - KLU))
              KMU = KLU + WX*(KRU - KLU)
            ELSE
              WX = 0.5
            ENDIF
          ENDIF
 
          AMU = ALU + 0.5*(ARU - ALU)
          WXVEC(ELMADR) = WX
          KSUM = KMU + KMU
 
C          IF(STFLAG.EQ.0)
C     A     WRITE(STD6,'(6H RDVAL,6F10.3)') YRD, TRD, ARD, KRD, BRD, QRD
C        WRITE(STD6,'(6H RUVAL,7F10.3)') YRU, TRU, ARU, KRU, BRU, QRU, DKRU
 
C         SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL.
          IF(YLU.LT.ZIY.OR.YRU.LT.ZIY) THEN
            ZI = 0.0
          ELSE
            ZI = ZIT
          ENDIF
 
C         CONTINUITY EQUATION
C         1) PARTIAL DERIVATIVES
 
C          WRITE(STD6,*) ' DXHDT=',DXHDT,' TLU=',TLU,' TRU=',TRU
          C1 = DXHDT*TLU
          C2 = -WT
          C3 = DXHDT*TRU
          C4 = WT
 
          QP = QPVEC(ELMADR)
          CF = COEFIN(ELMADR)
          IF(CF.GT.0.0) THEN
 
C            PROCESS INFLOW RESTRICTION ON SEWERS
 
             YC = YCUT(ELMADR)
             S1 = POND1(ELMADR)
             S2 = POND2(ELMADR)
             YM = 0.5*((YLU + YRU))
             DH = YC - YM
             IF(ABS(DH).LE.DHSTAR) THEN
                QMAX = DH*CF*QPCON
             ELSE
                QMAX = CF*SQRT(TWOG*ABS(DH))
                IF(DH.LT.0.0) QMAX = -QMAX
             ENDIF
 
C            CHECK FOR FLOW ALLOWED
 
             TP = QP + S1/DT
             IF(QMAX.GT.TP) THEN
                POND2(ELMADR) = 0.0
                QP = TP
                DQPYLU = 0.0
                DQPYRU = 0.0
             ELSE
                S3 = S1 + DT*(QP-QMAX)
                B = ABS(S2 -S3)/(DX*OLDVOL)
                IF(B.GT.ERRP) THEN
                  ERRP = B
                  NERRP = UBNBAS + NND - FN
                  BERRP = NBR
                ENDIF
                POND2(ELMADR) = S3
                QP = QMAX
                IF(ABS(DH).LE.DHSTAR) THEN
                  DQPYLU = -0.5*CF*QPCON
                  DQPYRU = DQPYLU
                ELSE
                  DQPYLU = -HALFG*CF*CF/ABS(QP)
                  DQPYRU = DQPYLU
                ENDIF
             ENDIF
             C1 = C1 - DQPYLU
             C3 = C3 - DQPYRU
 
          ENDIF
 
C         2) RESIDUAL
          IEQ = IEQ +1
 
        DYNDIF = OLDFLW + WT*(QRU - QLU - OLDFLW) - QP
        RES = -((AMU - OLDVOL)*DXDT + DYNDIF)
 
C        WRITE(STD6,2345) ' CON EQ:C1,C2,C3,C4,RES', C1, C2, C3, C4, RES
C2345  FORMAT(A,5(1PE10.3))
 
C         JCOL GIVES THE VARIABLE NUMBER AT THE FIRST COEFFICIENT IN
C         THE EQUATIONS.
 
          IF(NINC.GT.0) THEN
            PDAVEC(R(IEQ)) = C2
            PDAVEC(C(JCOL+1)) = C1
            PDAVEC(C(JCOL+2)-1) = C4
            PDAVEC(C(JCOL+3)-2) = C3
          ELSE
            PDAVEC(R(IEQ)) = C4
            PDAVEC(C(JCOL+1)) = C3
            PDAVEC(C(JCOL+2)-1) = C2
            PDAVEC(C(JCOL+3)-2) = C1
          ENDIF
 
          RHS(IEQ) = RES
 
 
        ERR = ABS(QP)/(ABS(0.5*OLDSUM)+0.1)
        IF(ERR.GT.ERRQ) THEN
          ERRQ = ERR
          BERRQ = NBR
          NERRQ = UBNBAS + NND - FN
        ENDIF
 
C       MOMENTUM EQUATION
 
        SFMT = ABS(NEWSUM)/KSUM**2
        SFMU = NEWSUM*SFMT
C        WRITE(STD6,*) ' SFMU=', SFMU
        PGFU = GRAV*(DZ +SFMU*DX + DY)
        VLU = QLU/ALU
        VRU = QRU/ARU
        TPA = (DX2 + DX2)*SFMU/KSUM
        TPB = AMU*GRAV*DX2*SFMT
 
C       PARTIAL DERIVATIVES
 
        C1 =
     A      WT*(AMU*GRAV*(-TPA*DKLU*(1. - WX) - 1.0) +
     B      PGFU*(0.5)*TLU -
     D      ZI*(DBLU*QLU - TLU*BLU*VLU)*VLU)
 
 
        C2 =
     A      ZI*DXHDT + WT*(TPB -  2.*ZI*BLU*VLU)
 
        C3 =
     A      WT*(AMU*GRAV*(-TPA*DKRU*WX + 1.0) +
     B      PGFU*(0.5)*TRU +
     D      ZI*(DBRU*QRU - TRU*BRU*VRU)*VRU)
 
        C4 =
     A      ZI*DXHDT + WT*(TPB + 2.*ZI*BRU*VRU)
 
        IF(KDC.GT.0.0.OR.KAC.GT.0.0) THEN
          ABARU = 0.5*(ALU + ARU)
C         PROCESS EXPANSION AND CONTRACTION LOSSES
          DV2 = ABS((VRU - VLU)*(VRU + VLU))
          IF(VLU.GE.VRU) THEN
C           FLOW IS UNDERGOING NEGATIVE ACCELERATION
 
            KDC = SIGN(KDC, NEWSUM)
            PFQLU = KDC*ABARU*VLU/ALU
            PFQRU = -KDC*ABARU*VRU/ARU
            PFYLU = TLU*(0.25*KDC*DV2 - PFQLU*VLU)
            PFYRU = TRU*(0.25*KDC*DV2 - PFQRU*VRU)
            GDE = 0.5*KDC*DV2
          ELSE
C           FLOW IS UNDERGOING POSITIVE ACCELERATION
 
            KAC = SIGN(KAC, NEWSUM)
            PFQLU = -KAC*ABARU*VLU/ALU
            PFQRU = KAC*ABARU*VRU/ARU
            PFYLU = TLU*(0.25*KAC*DV2 - PFQLU*VLU)
            PFYRU = TRU*(0.25*KAC*DV2 - PFQRU*VRU)
            GDE = 0.5*KAC*DV2
          ENDIF
 
          PGFU = PGFU + GDE
          C1 = C1 + WT*PFYLU
          C2 = C2 + WT*PFQLU
          C3 = C3 + WT*PFYRU
          C4 = C4 + WT*PFQRU
 
        ENDIF
 
        IF(ADRS.GT.0) THEN
C         POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT
          YM = 0.5*(YLU + YRU)
          ABARU = 0.5*(ALU + ARU)
          CALL LKTAB
     I              (ADRS, YM, 0,
     O               KHLM, NTAB, DKHLM)
          IF(NEWSUM.LT.0.0) THEN
            KHLM = -KHLM
            DKHLM = -DKHLM
          ENDIF
 
          TPA = NEWSUM/(ALU + ARU)**2
          TPB = TPA*NEWSUM
          GDE = 0.5*KHLM*TPB
          PGFU = PGFU + GDE
          TPC = WT*ABARU
          TPD = KHLM*TPA
 
          C1 = C1 - TPC*(TPD*TLU - DKHLM*TPB)
          C2 = C2 + TPC*TPD
          C3 = C3 - TPC*(TPD*TRU - DKHLM*TPB)
          C4 = C4 + TPC*TPD
        ENDIF
 
C        IF(C1.EQ.0.0) THEN
C          WRITE(STD6,*) ' C1=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
C        IF(C2.EQ.0.0) THEN
C          WRITE(STD6,*) ' C2=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
C        IF(C3.EQ.0.0) THEN
C          WRITE(STD6,*) ' C3=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
C        IF(C4.EQ.0.0) THEN
C          WRITE(STD6,*) ' C4=0.0 AT IEQ=',IEQ
C          STOP 'Abnormal stop: errors found.'
C        ENDIF
 
 
C       RESIDUAL
 
        RES = ZI*(NEWSUM - OLDSUM)*DXHDT + WT*(PGFU*AMU +
     A      ZI*(BRU*QRU*VRU - BLU*QLU*VLU)) + WTC*OLDIMP - OLDWND
 
          IEQ = IEQ + 1
 
C        WRITE(STD6,2345) ' MOM EQ:C1,C2,C3,C4,RES', C1, C2, C3, C4, RES
 
 
          IF(NINC.GT.0) THEN
            PDAVEC(R(IEQ)-1) = C2
            PDAVEC(R(IEQ)  ) = C1
            PDAVEC(C(JCOL+2)) = C4
            PDAVEC(C(JCOL+3)-1) = C3
          ELSE
            PDAVEC(R(IEQ)-1) = C4
            PDAVEC(R(IEQ)  ) = C3
            PDAVEC(C(JCOL+2)) = C2
            PDAVEC(C(JCOL+3)-1) = C1
          ENDIF
 
          RHS(IEQ) = -RES
 
C         TRANSFER VALUES
 
          IF(NINC.GT.0) THEN
            QLU = QRU
            ALU = ARU
            TLU = TRU
            YLU = YRU
            KLU = KRU
            DKLU = DKRU
            BLU = BRU
            DBLU = DBRU
          ELSE
            QRU = QLU
            ARU = ALU
            TRU = TLU
            YRU = YLU
            KRU = KLU
            DKRU = DKLU
            BRU = BLU
            DBRU = DBLU
          ENDIF
          JCOL = JCOL + 2
 
 100    CONTINUE
 
C      WRITE(STD6,*) ' '
      RETURN
      END
C
C
C
      SUBROUTINE   SIDEWR
     I                   (IPNT, STDOUT, TIME, NEX, MREMC, EMC,
     I                    EXNODT, QE2, YE2, ZE,
     O                    RES, PYL, PQL, PYR, PQR, PYM, PQM)
 
C     + + + PURPOSE + + +
C     Compute the residual and derivatives for side weir flows when
C     flows are defined by water surface elevation.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IPNT, STDOUT, MREMC, NEX
      INTEGER EMC(MREMC), EXNODT(9,NEX)
      REAL PQL, PQM, PQR, PYL, PYM, PYR, QE2(NEX), RES, TIME,
     A     YE2(NEX), ZE(NEX)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IPNT   - pointer into EMC for description of control structure
C     STDOUT   - Fortran unit number for user output and messages
C     TIME   - elapsed time in seconds from start of run
C     NEX    - number of exterior nodes in the model
C     MREMC  - maximum length of EMC(*). Same as LEMC
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
C     QE2    - flow at exterior nodes at end of time step
C     YE2    - depths at exterior nodes at end of time step
C     ZE     - elevation of datum for depth at exterior node
C     RES    - value of the residual function
C     PYL    - partial derivative of residual function wrt depth at
C               left node
C     PQL    - partial derivative of residual function wrt flow at left
C               node
C     PYR    - partial derivative of residual function wrt depth at
C               right node
C     PQR    - partial derivative of residual function wrt flow at right
C               node
C     PYM    - partial derivative of residual function wrt depth at
C               middle node
C     PQM    - partial derivative of residual wrt to flow at middle
C               node
 
C     + + + LOCAL VARIABLES + + +
      INTEGER DNN, DUTAB, FREE, IDUM, MDN, MFTAB, TYPE, UDTAB, UNN,
     A        CREST_TAB, NTAB
      REAL ABAR, B, CF, CON, DB, DCFQ, DCFY, DCON, DQZBAR, DQZM, DT,
     A     HCREST, Q, QBAR, QM, RDUM, TBAR, W, WC, YBAR, ZBAR, ZM,
     B     HTOE, P, PDV, HEAD
 
C     + + + EQUIVALENCES + + +
      EQUIVALENCE (IDUM, RDUM)
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER GETTYP
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL FINDCF, GETTYP, LKTAB, TDLK13, TDLK6, XLKT20
C***********************************************************************
C     GET KEY VALUES
 
      UNN = EMC(IPNT+1)
      DNN = EMC(IPNT+2)
C     THE MIDDLE NODE(MDN) IS ALWAYS THE FLOW NODE FOR A SIDE WEIR
 
      MDN = EMC(IPNT+3)
      UDTAB = EMC(IPNT+4)
      DUTAB = EMC(IPNT+5)
      MFTAB = EMC(IPNT+6)
      CREST_TAB = EMC(IPNT+7) 
      IDUM = EMC(IPNT+8)
      W = RDUM
      IDUM = EMC(IPNT+9)
      HCREST = RDUM
      IDUM = EMC(IPNT+10)
      HTOE = RDUM
 
C     Compute current crest elevation. 
      IF(CREST_TAB.GT.0) THEN
        CALL LKTAB
     I            (CREST_TAB, TIME, 1,
     O             P, NTAB, PDV)
C       P gives the decimal fraction of the distance from 
C       the original crest to the toe of the overflow structure
C       that is added to the original crest elevation.  Thus
C       P > 0 represents a flood fight in raising the crest 
C       and P < 0 represent erosion, settling, or collapse 
C       during a levee failure. 

        HCREST = HCREST + P*(HCREST - HTOE)
      ENDIF

      WC = 1.0 - W
 
      YBAR = W*YE2(UNN) + WC*YE2(DNN)
      ZBAR = YBAR + ZE(UNN)
      ZM = YE2(MDN) + ZE(MDN)
 
      QBAR = W*QE2(UNN) + WC*QE2(DNN)
      QM = QE2(MDN)
 
C     BASE FLOW DIRECTION ON WATER SURFACE ELEVATION.
 
      IF(ZBAR.GE.ZM) THEN
        IF(ZBAR.GT.HCREST) THEN
C         OUTFLOW FROM THE SOURCE CHANNEL
          TYPE = GETTYP(UDTAB)
          IF(TYPE.EQ.6) THEN
            CALL TDLK6
     I              (STDOUT, UDTAB, 6, MFTAB, TIME, ZM, ZBAR, HCREST,
     O               Q, DQZM, DQZBAR, FREE)
          ELSE
            CALL TDLK13
     I               (STDOUT, UDTAB, 13, MFTAB, TIME, ZM, ZBAR, HCREST,
     O                Q, DQZM, DQZBAR, FREE)
          ENDIF

C         FIND THE AREA AND TOP WIDTH AT THE MEAN DEPTH IN THE
C         SOURCE CHANNEL
 
          CALL XLKT20
     I             (EXNODT(4,UNN),
     M              YBAR,
     O              ABAR, TBAR, DT, CON, DCON, B, DB)
 
C         FIND THE HAGER SIDE WEIR FUNCTION AT THE MEAN PARAMETERS
C         FOR THE SIDE WEIR
 
          HEAD = ZBAR - HCREST
          CALL FINDCF
     I             (STDOUT, ABAR, TBAR, QBAR, HEAD,
     O              CF, DCFY, DCFQ)

        ELSE
C         Water below crest on both sides.
          Q = 0.0
          DQZM = 0.0
          DQZBAR = 0.0
          CF = 1.0
          DCFY = 0.0
          DCFQ = 0.0
        ENDIF

 
        PYL = (CF*DQZBAR + DCFY*Q)*W
        PQL = DCFQ*W*Q
        PYR = (CF*DQZBAR + DCFY*Q)*WC
        PQR = DCFQ*WC*Q
        PYM = CF*DQZM
 
C       EVALUATE THE FLOW NODE SIGN DEPENDENT TERMS.  IF FLOW NODE SIGN
C       IS -1 THEN FLOW AT THE FLOW NODE IS GIVEN AS POSITIVE FOR
C       OUTFLOW FROM THE SOURCE CHANNEL.  OTHERWISE IT IS NEGATIVE.
C       ALL VALUES DERIVED FROM THE TABLES GIVE POSITIVE FLOWS.  THUS
C       WE MUST ADJUST THE COMPUTATION OF THE RESIDUAL AND THE DERIVATIVE
C       WITH RESPECT TO FLOW AT THE  FLOW NODE.
 
        IF(EXNODT(1,MDN).EQ.-1) THEN
          RES = CF*Q - QM
          PQM = -1.
        ELSE
          RES = CF*Q + QM
          PQM = +1.
        ENDIF
 
      ELSE
        IF(ZM.GT.HCREST) THEN
C         FLOW INTO THE SOURCE CHANNEL.  THE HAGER SIDE WEIR FUNCTION
C         NO LONGER APPLIES.  NOW THE MIDDLE NODE IS THE PHYSICALLY
C         UPSTREAM NODE.
        
          TYPE = GETTYP(DUTAB)
          IF(TYPE.EQ.6) THEN
            CALL TDLK6
     I                (STDOUT, DUTAB, 6, MFTAB, TIME, ZBAR, ZM, HCREST,
     O                 Q, DQZBAR, DQZM, FREE)
          ELSE
 
            CALL TDLK13
     I               (STDOUT, DUTAB, 13, MFTAB, TIME, ZBAR, ZM, HCREST,
     O                Q, DQZBAR, DQZM, FREE)
          ENDIF
        ELSE
C         No flow.  Both sides below crest
          Q = 0.0
          DQZM = 0.0
          DQZBAR = 0.0
        ENDIF  
 
        PYL = DQZBAR*W
        PQL = 0.0
        PYR = DQZBAR*WC
        PQR = 0.0
        PYM = DQZM
 
        IF(EXNODT(1,MDN).EQ.-1) THEN
C         FLOW AT FLOW NODE IS NEGATIVE
          RES = Q + QM
          PQM = +1.
        ELSE
          RES = Q - QM
          PQM = -1.
        ENDIF
 
      ENDIF
 
      RETURN
 
      END
C
C
C
      SUBROUTINE   WSHEAR
     I                   (TIME,
     O                    SHEAR, WX, WY)
 
C     + + + PURPOSE + + +
C     Compute wind shear and its directional components.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      REAL SHEAR, TIME, WX, WY
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     TIME   - elapsed time in seconds from start of run
C     SHEAR  - wind shear value
C     WX     - sine of the wind direction
C     WY     - cosine of the wind direction
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'wincom.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER NTAB
      REAL VP, WINDCO, WINDIR, WINDV
 
C     + + + INTRINSICS + + +
      INTRINSIC COS, SIN
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LKTAB
C***********************************************************************
      CALL LKTAB
     I          (WINTAB, TIME, 0,
     O           WINDV, NTAB, WINDIR)
 
      IF(WINDV.GE.VAMAX) THEN
        WINDCO = CDMAX
      ELSEIF(WINDV.LE.VAMIN) THEN
        WINDCO = CDMIN
      ELSE
        VP = (WINDV - VAMIN)/VADIF
 
        WINDCO = CDMIN - CDDIF*(VP*(2.0*VP**2 - 3.0*VP))
      ENDIF
      SHEAR = WINDCO*AIRWAT*WINDV**2
      WX = SIN(WINDIR)
      WY = COS(WINDIR)
 
      RETURN
      END
