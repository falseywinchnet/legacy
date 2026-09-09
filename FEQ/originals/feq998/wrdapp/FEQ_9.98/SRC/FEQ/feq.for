C
C
C
      SUBROUTINE MAKE_STANDARD_FILE_NAMES(FNAME,
     O                                    FNAME2)

C     Given the name for the input file to FEQ form the standard names for
C     the remaining file name. 

      IMPLICIT NONE

      CHARACTER*64 FNAME, FNAME2


C     Local

      INTEGER I, L, N

C***********************************************************************
C     The input file name may or may not have an extension.  Also
C     this should work with more than one period in the file name. 
C     The period closest to the end of the string will be taken to 
C     be the delimiter for the extension.  If no period is found, 
C     then the whole name is used for the base name of the remaining
C     file names unless the period is in the first position and is
C     the only period present. 

      N = LEN_TRIM(FNAME)

C     Set L for case of no period found
      L = N
      DO I=N,1,-1

        IF(FNAME(I:I).EQ.'.') THEN
          IF(I.GT.1) THEN
            L = I - 1
          ELSE
            L = N
          ENDIF
          EXIT
        ENDIF

      END DO

      FNAME2 = FNAME(1:L)//'.out'
      RETURN
      END
C
C
C
      SUBROUTINE STAT_TRAN(NEX, 
     M                          EXNODT)

C     Transfer the node locations to exterior nodes on branches.

      IMPLICIT NONE
      
      INTEGER NEX, EXNODT(9,NEX)

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

C     Called program units
      REAL*8 GET_DP_FROM_FT
      EXTERNAL GET_DP_FROM_FT

C     Local

      INTEGER ADRS, I
      REAL*8 X, Y

C***********************************************************************
      DO 100 I=1,NEX
        IF(EXNODT(3,I).GT.0) THEN
C         It is on a branch
          ADRS = EXNODT(4,I)
          X = GET_DP_FROM_FT(ADRS+8)
          Y = GET_DP_FROM_FT(ADRS+10)
          EXNODT(6,I) = NINT(100.D0*X)
          EXNODT(7,I) = NINT(100.D0*Y)
        ENDIF
100   CONTINUE
      RETURN
      END

C     ***********
C     *         *
C     * TS_MNGT_INIT
C     *         *
C     ***********

      SUBROUTINE TS_MNGT_INIT

C     Clear counters in the common blocks.

      IMPLICIT NONE
      INCLUDE 'arsize.prm'
      INCLUDE 'ts_mngt.cmn'

C     Local

      INTEGER I
C***********************************************************************
      NUM_TS = 0
      NUM_DEST = 0
      NEXT_LINK = MXN_TS + 1

C     Clear the time-series id table as well as the
C     link pointer, and the table contents.  We must be able to decide
C     if a destination has already been established.
      DO 100 I=1,MXN_TS
        TS_ID(I) = ' '
        DEST_CAT(I) = 0
        DEST_PNT(I) = 0
        DEST_LINK(I) = 0
100   CONTINUE

      RETURN
      END
C
C
C
      SUBROUTINE SET_VERSION()

C     Sets the current version number and date in the version 
C     common block
      IMPLICIT NONE

      INCLUDE 'version.cmn'
C***********************************************************************
      VERSION_NUMBER = 9.98
      VERSION_DATE = '21 April 2003'
      RETURN
      END
      
C
C
C
      SUBROUTINE  OUTPUT_BALANCE_LEGEND(STDOUT)

C     Output a legend for the balance summary output

      IMPLICIT NONE
      INTEGER STDOUT

C     *****************************FORMATS******************************
 50   FORMAT(/,' Legend for balance checking output:',
     A /,' S1 = initial volume in level-pool reservoirs and branches',
     B /,' S2 = current volume in level-pool reservoirs and branches',
     C /,' BNI = inflow for boundary nodes',
     D /,' BNQ = outflow from boundary nodes',
     E /,' TAQ = flow from tributary areas into level-pool reservoirs',
     F          ' and branches',/,'      excluding boundary nodes',
     f /,' WSI = rainfall on water surfaces',
     f /,' WSQ = evaporation from water surfaces',
     G /,' TAQBN = flow from tributary areas into boundary nodes',
     G /,' TAI = flow to tributary areas',
     H /,' D1 = initial volume in detention-delay reservoirs',
     I /,' D2 = current volume in detention-delay reservoirs')
C***********************************************************************
      WRITE(STDOUT,50)
      WRITE(STDOUT,*) ' '
      RETURN
      END
     
C  ***********************************************************************
C  *  Warning:  This program is large and complex and  extensive         *  
C  *  knowledge of its design, purpose, and limitations is required      *  
C  *  in order to apply it properly.  Application of this program by an  *
C  *  unqualified user for any other purpose than an educational one is  *
C  *  not only unwise but is also unethical.  The user of this           *
C  *  program is totally responsible for its use and application and for *
C  *  any actions or events which follow therefrom.  Any user of this    *
C  *  program  holds the developer of the program harmless from          *
C  *  damages of any kind.                                               *
C  *                                                                     *       
C  *  The developer has used reasonable care in the construction and     *
C  *  testing of the program.  However, in a program of this size and    *
C  *  complexity, it is impossible to verify more than a minute number of*
C  *  possible options or applications.  The developer is continuing to  *
C  *  modify and use the program and is interested in information on     *
C  *  operational problems encountered in its application.  However, the *
C  *  developer gives no assurance that the problem can or will be       *
C  *  rectified.                                                         *
C  *                                                                     *       
C  *  This program is not to be sold in any form modified or otherwise.  *
C  ***********************************************************************

      PROGRAM   FEQ
 
      IMPLICIT NONE
C     + + + PURPOSE + + +
C     Compute unsteady open channel flow in a network of channels.
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'morg.prm'
      INCLUDE 'misccon.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'bnpond.cmn'
      INCLUDE 'bnrslt.cmn'
      INCLUDE 'difcom.cmn'
      INCLUDE 'dtcom.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'enothr.cmn'
      INCLUDE 'enrslt.cmn'
      INCLUDE 'ftable.cmn'
      INCLUDE 'infcom.cmn'
      INCLUDE 'julian.cmn'
      INCLUDE 'namcom.cmn'
      INCLUDE 'tsfcom.cmn'
      INCLUDE 'rdcom.cmn'
      INCLUDE 'wrcom.cmn'
      INCLUDE 'xscom.cmn'
      INCLUDE 'grav.cmn'
      INCLUDE 'clcom.cmn'
      INCLUDE 'timcom.cmn'
      INCLUDE 'inusnb.cmn'
      INCLUDE 'stdun.cmn' 
      INCLUDE 'genscn.cmn'    
      INCLUDE 'tam.cmn' 
      INCLUDE 'code14.cmn'   
 
C     + + + SAVED VALUES + + +
      CHARACTER NO*4, YES*4
      SAVE NO, YES
 
C     + + + LOCAL VARIABLES + + +
      INTEGER BDYNUM, BERRP, BERRQ, BMXRE, BNODE, CFLAG, I, IBP, IBQ,
     A        IOFLAG, IPRT, ITEMP, J, KNT, KNTA, KOUNT, LDCALL, LKOUNT,
     B        LMXRES, MINPRT, N, NERRP, NERRQ, NFREE, NMXRE,
     C        NRWTA, NTINT, NUMLIM, QPN, RESNUM, SUMITR, WYR, BNODE_MAX,
     D        START_EQ, END_EQ, STDEXT_OPTION
      INTEGER BMXREV(MNITER), KNTVEC(MNITER),
     A        LMXRV(MNITER), NMXREV(MNITER), RTAP(MNFREE), RWTA(MNFREE)
      REAL ABSTOL, BAL, DTHR, DTIMLD, ERRP, ERRQ, ET, HR, HSLOT,
     A     LAMBDA, MXRE, MXRES, MXREV(MNITER), MXRV(MNITER),
     B     MXSSRV(MNITER), NSLOT, RBAL, RTAFAC(MNFREE), SRLIM, SRNEW,
     C     SROLD, VUNIT, WSLOT, WT, DTMIN_OUT
      REAL*8 DJLOAD, DT, DTLOAD, EVENT_BASE, HRD,
     A       S1, S2, D1, D2, 
     B       BNI, BNQ, TAI, TAQ, TAQBN, WSI, WSQ
      CHARACTER FNAME*64, FNAME2*64, GCHK*4, NODEID*4, QOUT(MNSOUT)*8,
     A          ZOUT(MNSOUT)*8, OLD_SUMMARY*4, CD14_TAB_DATUM*4, 
     B          CD5T6_TAB_DATUM*4
      LOGICAL THERE
 
C     + + + INTRINSICS + + +
      INTRINSIC FLOAT, MOD, SNGL
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER IARGC, LPYEAR, GET_UNIT
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL BDYFLW, BROUT, BWGET, CHKGEO, CMPCOR, CRSET2, CSMAT,
     A         DPWOUT, DUMPIT, ESTBN, ESTEN, EXOUT, FINCHK, FMXMN,
     B         FTOUT, GETARG, IARGC, INFO, INOUT, LOAD, LPYEAR, MAKCOR,
     C         MANTIM, OPER, OPINIT, OUTSP, PRTLOG, QPVOUT, RESOUT,
     D         RPLSET, RSTNZD, RSTSTA, SETSTA, STINT, WRINIT,
     E         WROUT, GET_UNIT, FIND_VOLUMES, CLEAR_HOME,
     F         RESET_KOUNT_OF_INTERNAL_TABIDS, TBOX
 
C     + + + DATA INITIALIZATIONS + + +
      DATA YES/'YES'/, NO/'NO'/
 
C     + + + OUTPUT FORMATS + + +
 2010 FORMAT(/)
 2020 FORMAT(/,' SIMULATION ending at ',I5,'/',I2,'/',I2,':',F10.7,
     A '.  Time step=', F9.2, ' sec')
 2021 FORMAT('+At ',I4,'/',I2,'/',I2,':',F6.3,' DT=', F8.2, ' sec')
 2030 FORMAT(/,' *WRN:24* Non-convergence. Time step will be',
     A       ' reduced.')
 2150 FORMAT(' Balance 1: S1=',1PE9.3,' S2=',1PE9.3,' BNI=',1PE9.3,
     A       ' BNQ=',1PE9.3,' TAQ=',1PE9.3, ' WSI=',1PE9.3,
     B       ' WSQ=',1PE9.3)
 2152 FORMAT(' Bal diff=BAL=S2-S1-BNI-TAQ+BNQ-WSI+WSQ=',1PE10.3,
     A       '    Rel bal=BAL/(S2+BNQ)=',1PE10.3)
 2153 FORMAT(' Balance 2: D1=',1PE9.3,' D2=',1PE9.3,' TAI=',1PE9.3,
     A       ' TAQBN=',1PE9.3)
 2154 FORMAT(' Bal diff=BAL=D2-D1-TAI+TAQ+TAQBN=',1PE10.3,
     A       ' Rel Bal=BAL/(D2+TAQ+TAQBN)=',1PE10.0)
 2180 FORMAT(' CSUR=',1PE8.1,' AT ND=',I4,':',I6,' RLTQ=',
     A       1PE8.1,' AT ND=',I4,':',I6,' DT/ITER=',0PF8.1)
 3000 FORMAT(/,' PNC SROLD=',1PE9.2,
     A       ' SRNEW=',1PE9.2,' LAMBDA WAS ',0PF9.6)
 3022 FORMAT(/,' Initialization time=',F10.2,' secs or ',F10.4,' mins')
 3023 FORMAT(' Setup time=',F10.2,' secs or ',F10.4,' mins')
 3210 FORMAT(/,' SRLIM=',1PE12.5)
 3220 FORMAT('*ERR:165* Value of MORG wrong in ARSIZE. Must be 0 or 1.')
 3230 FORMAT(/,' Processing stopped.  Errors encountered.')
3240  FORMAT(/,' Master-input file name: ',A,/,
     A         ' Master-output file name: ',A) 
95    FORMAT(/,' Invalid number of command-line arguments: FEQ',
     A/,' expects exactly one argument or exactly two arguments.',
     B/,' If one argument is given, FEQ strips the last extension,',
     C/,' if there is one, and appends .out to create the second',
     D/,' file name.  Otherwise give two file names: (1) master-input',
     E/,' file, and (2) master-output file.')
96    FORMAT(/,' The operating system cannot open the master-output',
     A/,' file: ',A,'.','  Check for invalid characters in the',
     B/,' name.  If part or all of the path is given with the name,',
     C/,' make sure that all directories exist as spelled.')
C***********************************************************************
C
C     strings for Unix what command
      fname =
     &   '@(#)FEQ - Full Equations Flow Routing Model'
      fname = '@(#)FEQ - Franz, D.D., and Melching, C.S., WRIR 96-xxxx'
      fname = '@(#)FEQ - Contact: h2osoft@usgs.gov'
      fname = '@(#)FEQ - Version: 8.92 1998/06/01'
C     set string for use with RCS ident command
      fname =
     &'$Id: feq.f,v 8.5 1996/02/28 18:30:45 rsregan Exp rsregan $'


C     Clear the HOME portion of file names for function tables
C     and time series.
      CALL CLEAR_HOME()

C     Initialize selector-name processing
      CALL SELECTOR_SYMBOL_INIT()

C
C     Initialize the mechanism for tracking I/O unit numbers. 
C     User is not permitted to select any unit number. 
      CALL INITIALIZE_UNITS
C     Set the GENSCN values to their defaults
      CALL INITIALIZE_GENSCN()

C     Initialize the count of internal tabids
      CALL RESET_KOUNT_OF_INTERNAL_TABIDS()
      
C     Set the version number and date
      CALL SET_VERSION()
      
C     Clear the count of detention and delay reservoirs
      DTEN_KNT = 0
      DLAY_KNT = 0

C     Start the time-keeping
      CALL TIMERL(ITICK)
 
C     The values for the standard input and output units are given
C     in the file: stdun.cmn.  Set their value here because the
C     common block is used in some cases where the normal units
C     have not been transferred.  It is assumed that unit 0 is
C     output to the current console.  That output only used
C     if a bug is detected in GET_UNIT.

      STD5 = GET_UNIT(0)
      STD6 = GET_UNIT(0)       

      IN = STD5
      STDOUT = STD6

C     Initialize HEC DSS system.  This call may be a dummy if
C     the DSS access is detached. 
      CALL HECDSS_INIT(STDOUT)

C     Initialize the time-series file tracking system
      CALL TS_MNGT_INIT
 
      IF(MORG.LT.0.OR.MORG.GT.1) THEN
        WRITE(*,3220)
        STOP 'Abnormal stop: errors found.'
      ENDIF

C     Set the carriage-return character value
      CALL SETCR()
C     PROCESS COMMAND LINE ARGUMENTS
 
      NARG = 0
      NXT = 1
      NARG = IARGC()
      
      IF(NARG.EQ.1+MORG) THEN
C       If only one file argument is given we assume that the 
C       extension, if any, from the file given is stripped and the 
C       remaining  file name IS formed by adding .out 
C       to the file name given by the user name stripped of its extension.

        STDEXT_OPTION = 1
      ELSEIF(NARG-MORG.LT.2) THEN
        WRITE(*,95)
        STOP 'Abnormal stop: errors found.'
      ELSE
        STDEXT_OPTION = 0
      ENDIF
 
C     GET THE FIRST FILE ARGUMENT
 
      CALL GETARG
     I           (1+MORG,
     O            FNAME)
 
      INQUIRE(FILE=FNAME, EXIST=THERE)
      IF(THERE) THEN
        OPEN(IN, FILE = FNAME, STATUS = 'OLD')
      ELSE
        N = LEN_TRIM(FNAME)
        WRITE(*,*) ' '
        WRITE(*,*) ' File named: ',FNAME(1:N),' not found.'
        WRITE(*,*) ' Please check spelling of master-input file.'
        STOP 'Abnormal stop. Errors found.'
      ENDIF
 
      IF(STDEXT_OPTION.EQ.1) THEN
C       Form the other file name
        CALL MAKE_STANDARD_FILE_NAMES(FNAME,
     O                                FNAME2)
      ELSE

C       GET THE SECOND FILE ARGUMENT
 
        CALL GETARG
     I             (2+MORG,
     O              FNAME2)
      ENDIF
      WRITE(*,*) ' '
      IF(FNAME.EQ.FNAME2) THEN
        WRITE(*,*) ' The names given for the two command-line'
        WRITE(*,*) ' arguments are the same.  They must be different.'
        STOP 'Abnormal stop: errors found.'
      ENDIF
      OPEN(STDOUT, FILE = FNAME2, STATUS = 'UNKNOWN', IOSTAT=IOFLAG)
 
      IF(IOFLAG.NE.0) THEN
        N = LEN_TRIM(FNAME2)
        WRITE(*,96) FNAME2(1:N)
        STOP 'Abnormal stop: errors found.'
      ENDIF



C     Open the file we will use for checking.  Do not make part of
C     the standard package.  Comment out after testing

C      OPEN(UNIT=45, FILE='fromfeq.D',STATUS='UNKNOWN',
C     A          FORM='UNFORMATTED')


C     Output the header to the standard output
      CALL TBOX
     I         (STDOUT)

C     Output the names of the standard input file 
      WRITE(STDOUT,3240) FNAME, FNAME2

C     Initialize the macro facility and the symbol table.
      CALL MACRO_SYMBOL_INIT()
 
      LPNT = 0
      NTINT = 0
      IPRT = 1
 
 
      CALL INFO(FNAME2, FNAME,
     O          QPN, NRWTA, RTAP, RWTA, LDCALL, 
     O          NODEID, MINPRT, LAGTSF, NFREE, GCHK, VUNIT, ABSTOL,
     O          HSLOT, WSLOT, NSLOT, NUMLIM, BNODE, BDYNUM, RESNUM,
     O          RTAFAC, OLD_SUMMARY, CD14_TAB_DATUM, CD5T6_TAB_DATUM,
     O          START_EQ, END_EQ, DTMIN_OUT)

C     Assign the formats for detailed branch output.  FTID is in common 
C     group file name bnelem.cmn
      IF(GRAV.GT.15.0) THEN
        IF(SFAC.LE.1.0) THEN       
          FTID = 1
        ELSEIF(SFAC.LE.10.0) THEN  
          FTID = 2
        ELSEIF(SFAC.LE.100.0) THEN 
          FTID = 3
        ELSEIF(SFAC.LE.1000.0) THEN
          FTID = 4
        ELSE                       
          FTID = 5
        ENDIF                      
      ELSE
        IF(SFAC.LE.1.0) THEN       
          FTID = 6
        ELSEIF(SFAC.LE.10.0) THEN  
          FTID = 7
        ELSEIF(SFAC.LE.100.0) THEN 
          FTID = 8
        ELSEIF(SFAC.LE.1000.0) THEN
          FTID = 9
        ELSE                       
          FTID = 10
        ENDIF                      
      ENDIF


 
 
      IF(IFRZ.GT.0) THEN
        DTLOAD = 1.D0
        DJLOAD = 1.157407D-5
        DTIMLD = 1.0
      ELSE
        DJLOAD = 0.D0
        DTIMLD = 0.0
      ENDIF
      WT = BWT
 
      IF(SQREPS.LT.0.0) THEN
        SRLIM = 1.E30
      ELSE
        SRLIM = SQREPS
      ENDIF
      WRITE(STDOUT,3210) SRLIM
      IF(EFLAG.NE.0) THEN
        WRITE(STDOUT,3230)
        STOP 'Abnormal stop: errors found.'
      ENDIF 
      IF(GCHK.EQ.'YES') THEN
C       CHECK STREAM CHANNEL GEOMETRY

        CALL CHKGEO
     I             (STDOUT, NBRA, BRPT)
      ENDIF
 
C     Set the time to its value at the start of the run.  
      TIME = 86400.D0*(SJTIME - TAB_789_JTBASE)
     
      CALL STINT
     I          (TSFDSN, STDOUT, NBRA, NEX, BRPT, EXNODT, EFLAG, EPSB,
     I           GRAV, IN, MAXIT, NBN, OUTPUT, SNGL(TIME), SFAC, NBLK,
     I           OPBLK, BWFDSN, FFFDSN, DIFFUS, UNDERF, IFRZ, DT,
     I           GETDSN, UJTIME, EPT, BNODE, QEPS,
     M           EMC,
     O           WT, SITER)
 
 
      IF(EFLAG.NE.0) THEN
        STOP 'Abnormal stop: errors found.'
      ENDIF
C     DEBUG OUTPUT HERE
 
      IF(OUTPUT.NE.0) THEN
 
        CALL BROUT
     I            (STDOUT, NBN, NBRA, BRPT)
        CALL EXOUT
     I            (STDOUT, EPT, NEX, EMC, EXNODT)
 
C        IF(POINT.EQ.NO.AND.DIFFUS.EQ.NO.AND.WIND.EQ.NO) GOTO 3
        IF(POINT.EQ.YES.OR.DIFFUS.EQ.YES.OR.WIND.EQ.YES) THEN
          CALL DPWOUT
     I             (DIFFUS, STDOUT, LPNT, MRPFPT, NO, POINT, WIND, MF,
     I              PFPNT)
        ENDIF
 
        CALL FTOUT
     I            (STDOUT,
     M             OUTPUT)
        CALL INOUT
     I            (STDOUT, NBRA, NEX, BRPT)
      ENDIF
 

C     Check side-weir relationships against initial conditions.
      
      IF(CODE14_PRESENT.GT.0) THEN
        CALL SIDE_WEIR_CHK
     I                     (STDOUT, GRAV, NEX, EXNODT, EPT,
     M                      EMC)
      ENDIF

C     MAKE CHECK OF THE INITIAL CONDITIONS AND VALUES WHICH COULD
C     NOT BE CHECKED IN INFO2()
      CALL FINCHK
     I           (STDOUT, NEX, EXNODT, HSLOT, QCHOP, EPT,
     I            CD14_TAB_DATUM, CD5T6_TAB_DATUM,
     M            EMC)

C     RESET OUTPUT
      IF(OUTPUT.EQ.0) OUTPUT = 1
 
      IF(GETDSN.GT.0) THEN
        ISITER = SITER
C       OUTPUT CHECK VALUES FOR INITIAL CONDITIONS
        WRITE(STDOUT,*) ' '
        WRITE(STDOUT,*) ' INITIAL VALUES FROM GETIC FILE:',GETNAM
C       CLEAR QPVEC TO AVOID ERRONEOUS OUTPUT FOR THE INITIAL
C       CONDITIONS
        DO 9125 I=1,NBN
          QPVEC(I) = 0.0
 9125   CONTINUE
        CALL RESOUT
     I             (GRAV, VUNIT, STDOUT, NBRA, NODEID, NEX, TIME,
     I              SFAC, BRPT, EXNODT, QCHOP)
      ELSE
C       SET INITIAL PONDING TO ZERO WHEN INITIAL CONDITIONS ARE NOT
C       READ FROM A FILE.  CLEAR EXTRAPOLATION VECTORS.  Also clear
C       the count of exterior nodes appearing as the last items in
C       the iteration log when convergence fails. Clear the counter
C       for branch nodes as well.
 
        DO 9124 I=1,NBN
          MY(I) = 0.0
          MQ(I) = 0.0
          POND1(I) = 0.0
          NON_CONV_BNODE(I) = 0
 9124   CONTINUE
        DO 9126 I=1,NEX
          MYE(I) = 0.0
          MQE(I) = 0.0
          NON_CONV_ENODE(I) = 0
 9126   CONTINUE
 
      ENDIF
 
 
C     COMPUTE THE INITIALIZATION TIME
 
      CALL TIMERL(ITICK0)
      IF(ITICK0.LT.ITICK) THEN
        ITICK0 = ITICK0 + 100*86400
      ELSE
        ET = FLOAT(ITICK0 - ITICK)/100.0
        WRITE(STDOUT,3022) ET, ET/60.
        WRITE(*,3023) ET, ET/60.
        WRITE(*,*) ' '
      ENDIF
 
 
C     INITIALIZE FOR THIS SEGMENT OF TIME. MULTIPLE SEGMENTS IF
C     DIFFUS = YES.  FOR MULTIPLE SEGMENTS FORCE THE LINE COUNTER
C     FOR THE SPECIAL OUTPUT FILE TO BE CONTINUOUS ACROSS SEGMENTS
 
      LKOUNT = 0
 
 
 9000 CONTINUE
        RESET = 0
        SEFLAG = 0
        YR = SYR
        LEAP = LPYEAR(YR)
        MN = SMN
        DY = SDY
        DYFRAC = SFRAC/24.D0
        HR = SFRAC
        JTIME = SJTIME
        TIME = 86400.D0*(SJTIME - TAB_789_JTBASE)
        EVENT_BASE = TIME
        SUMITR = 0
        SITER = ISITER
        IF(GETDSN.EQ.0) DT = MAXDT
        BNI = 0.D0
        BNQ = 0.D0
        TAI = 0.D0
        TAQ = 0.D0
        TAQBN = 0.D0
C       Clear values used in BDYFLW even if there is no diffuse inflow
        L_TAI = 0.D0
        L_TAQ = 0.D0
        L_TAQBN = 0.D0
        L_WSI = 0.D0
        L_WSQ = 0.D0
C       WSI is the inflow to water surfaces from rainfall and WSQ is
C       outflow from water surfaces from evaporation.
        WSI = 0.D0
        WSQ = 0.D0
        LAMBDA = 1.0
 
C     Reset extreme values  and initialize various  values.
 
      DO 1 I=1,NBN
        QPVEC(I) = 0.
        WSVEC(I) = 0.
C        MY(I) = 0.
C        MQ(I) = 0.
        QMIN(I) = 1.E30
        ZMAX(I) = -9999.
        QMAX(I) = -1.E30
        VMAX(I) = -1.E30
C       POND1(I) = 0.0
        POND2(I) = 0.0
        TZMAX(I) = SJTIME
        TQMAX(I) = SJTIME
        TQMIN(I) = SJTIME
 1    CONTINUE

C     Initialize the values for any delay reservoirs if diffuse inflows
C     are simulated. Also initialize the values for any detention 
C     reservoirs present. 
      IF(NLUSE.GT.0.AND.GETDSN.EQ.0) THEN
        DO 2 I=1,DLAY_KNT
          DLAY_Q1(I) = 0.D0
2       CONTINUE
        DO 3 I=1,DTEN_KNT
          DTEN_S1(I) = 0.0
          DTEN_Q1(I) = 0.0
          DTEN_Q1P(I) = 0.0
3       CONTINUE
      ENDIF


      DO 4 I=1,NBRA
        BPMAX(I) = 0.0
        BPOND(I) = 0.0
 4    CONTINUE
      DO 5 I=1,NEX
C        MYE(I) = 0.0
C        MQE(I) = 0.0
        FNQMAX(I) = -1.E30
        FNQMIN(I) =  1.E30
        FNZMAX(I) = -1.E30
        FTZMAX(I) = SJTIME
        FTQMAX(I) = SJTIME
        FTQMIN(I) = SJTIME
 5    CONTINUE
 
C     Clear the initial value for cumulation of certain
C     time-series files.  We clear all even though none or
C     some need cumulative values.  Clear the new values
C     as well to avoid errors with checking undefined variables
      DO 6 I=1,NUM_TS_F
        OLD_CUM(I) = 0.D0
        NEW_CUM(I) = 0.D0
6     CONTINUE

C     INITIALIZE THE SYSTEM.
      IF(DIFFUS.EQ.YES) REWIND BWFDSN
      IF(IFRZ.EQ.0) THEN
        IF(DIFFUS.EQ.YES) THEN
          CALL BWGET
     I              (BWFDSN, NBRA, NBN, NEX, MNBLK, NBLK, OPBLK,
     O               WT)
          WRITE(STDOUT,*) ' BWF BEING READ WHEN IFRZ=0. WT=',WT
          IF(NBLK.GT.0) THEN
            CALL OPINIT(NBLK, OPBLK)
            CALL SET_INITIAL_OPER_BLK(NBLK, OPBLK, SNGL(TIME), EPT,
     M                                EMC)
          ENDIF
        ENDIF
        CALL SETSTA
     I             (STDOUT, NEX, GRAV, EXNODT, EPT,
     M              EMC)
 
C       COMPUTE INITIAL VOLUME OF WATER IN THE SYSTEM
 

        CALL FIND_VOLUMES(NBRA, NBN, NEX, RESNUM, DLAY_KNT, DTEN_KNT, 
     I              BRPT, RESVEC, DXVEC, A1, AE1, POND1, GEQVEC, Q1, 
     I              WXVEC1, MA1, DLAY_Q1, DLAY_K, DTEN_S1, DTEN_AVDA,
     O              S1, D1)
 
        IF(NFOUT.GT.0) CALL WRINIT
     I                            (SJTIME)
 
C       CHECK THE INITIAL VALUES FOR EXTREMES
 
        CALL FMXMN
     I            (NBN, NEX, NBRA, EXNODT, BRPT, JTIME)

C       Output the first record to the GENSCN system.
        IF(FEO_UNIT.GT.0) THEN
          CALL OUT_GENSCN
     I                   (STDOUT, JTIME)
        ENDIF
        
 
      ENDIF
 
 
C     *************** SOLUTION SECTION ****************************
      KOUNT = 0
      NTINT = 0
      STFLAG = 0
C     SET CONVERGENCE FLAG TO YES AT START OF EACH SEGMENT OF TIME
 
      CFLAG = 1
 
C     SELECT NEXT TIME STEP AND INCREMENT TIME
 
 8000 CONTINUE
 
C       FORCE LARGE VALUE OF SRNEW TO PREVENT EARLY TERMINATION
 
        SRNEW = 1.E30
 
        CALL MANTIM
     I             (BRPT, BWFDSN, DIFFUS, VUNIT, DTVEC, EXNODT, NBLK,
     I              NBN, NBRA, NODEID, NEX, OPBLK, RESNUM, RESVEC, SFAC,
     I              FFFDSN, MINPRT, HSLOT, PUTDSN, BNODE, QCHOP, 
     I              BNI, BNQ, TAI, TAQ, TAQBN, WSI, WSQ, OLD_SUMMARY,
     M              CFLAG, DT, IFRZ, WT, SEFLAG,
     O              EMC, SUMITR, S1, D1)
 
 
 
C       CATCH END OF SEGMENT IN TSF. RESET = 0 ALWAYS IF NO TSF
C       SET TO 1 TO SIGNAL END OF A SEGMENT IF TSF IS PRESENT.
 
        IF(RESET.EQ.1) GOTO 9000
 
C       TIME STEP SELECTED AND MORE TIME REMAINS TO BE DONE
C       FIND VALUES DETERMINED FULLY BY THE TIME.
 
        IF(JTIME.GT.PRTIME) THEN
          OUTPUT = PROUT
        ENDIF
        IF(NBLK.GT.0) THEN
          IF(IFRZ.EQ.0) THEN
            DTHR = DT/3600.
          ELSE
            DTHR = 0.0
          ENDIF
          CALL OPER(SNGL(TIME), NBLK, OPBLK, DTHR,
     O              EMC)
        ENDIF
 
 
        IF(LDCALL.GT.0) THEN
          IF(IFRZ.EQ.0) THEN
            DTLOAD = DT
            DJLOAD = 0.D0
            DTIMLD = 0.0
          ENDIF
          CALL LOAD
     I             (DIFFUS, BRPT, NBRA, STDOUT, LPNT, MRPFPT, NBN, 
     I              OUTPUT, POINT, SNGL(TIME), WIND, PFPNT, QPN, 
     I              DT, DTLOAD, DJLOAD, DTIMLD,
     M              EMC,
     O              EFLAG, WYR)
 
        ENDIF
 
        IF(GEQOPT.EQ.2) THEN
C         RESET THE WEIGHT FACTORS FOR DISTANCE INTEGRALS
          CALL RSTNZD
     I               (NBRA, BRPT)
        ENDIF
 
C       MAKE ESTIMATE OF DEPENDENT VARIABLES FOR NODES ON BRANCH
 
        CALL ESTBN
     I            (DT, NBN, MRE)
 
C       MAKE ESTIMATE OF DEPENDENT VARIABLES FOR EXTERIOR NODES
 
        CALL ESTEN
     I            (DT, NEX, MRE, EXNODT)
 
C       COMPUTE  MATRIX, UPDATE SROLD, AND SOLVE MATRIX
 
        LAMBDA = 1.0
        KOUNT = 0

        CALL CSMAT
     I            (DT, WT, NBN, NBRA, NEX, BRPT, HSLOT, EPT, DTMIN_OUT,
     I             START_EQ, END_EQ, JTIME, PRTIME, KOUNT, QEPS,
     M             EMC, EXNODT,
     O             SROLD, MXRES, LMXRES, ERRP, ERRQ, BERRQ, NERRQ,
     O             NERRP, BERRP)
 
C       INITIALIZE FOR ITERATIVE SOLUTION FOR CURRENT TIME POINT.
 
 
        MXSSRV(KOUNT+1) = SROLD
        MXRV(KOUNT+1) = MXRES
        LMXRV(KOUNT+1) = LMXRES
 
 8200   CONTINUE
 
          KOUNT = KOUNT + 1
          STFLAG = 1
          IF(KOUNT.GT.MKNT) THEN
            CFLAG = 0
            STFLAG = 0
            KOUNT = KOUNT - 1
            IF(MINPRT.EQ.0.OR.MINPRT.EQ.2) THEN
              HRD = 24.*DYFRAC
              HR = HRD
              WRITE(STDOUT,2030)
              WRITE(STDOUT,2020) YR, MN, DY, HRD, DT
              CALL PRTLOG
     I                   (STDOUT, KOUNT, MXREV, BMXREV, NMXREV, MXRV,
     I                    LMXRV, MXSSRV, KNTVEC)
            ENDIF
C           Count the exterior nodes, if any, that appear as the
C           the last location of maximum relative correction
C           when convergence fails.

            IF(BMXREV(KOUNT).EQ.0) THEN
              NON_CONV_ENODE(ABS(NMXREV(KOUNT))) =
     A             NON_CONV_ENODE(ABS(NMXREV(KOUNT))) + 1
            ELSE
              NON_CONV_BNODE(BNODE_MAX) =
     A             NON_CONV_BNODE(BNODE_MAX) + 1
            ENDIF
            
            SITER = AUTO*SITER + (1. - AUTO)*KOUNT
            SUMITR = SUMITR + KOUNT
            IF(MINPRT.EQ.0) THEN
              IF(BERRP.EQ.0) THEN
                IBP = 0
              ELSE
                IBP = INBRUS(BERRP)
              ENDIF
              IF(BERRQ.EQ.0) THEN
                IBQ = 0
              ELSE
                IBQ = INBRUS(BERRQ)
              ENDIF
              WRITE(STDOUT,2180) ERRP, IBP, NERRP, ERRQ,
     A                         IBQ, NERRQ, 
     B                         (TIME - EVENT_BASE)/FLOAT(SUMITR)
            ENDIF
            GOTO 8000
          ENDIF
 
C         COMPUTE CORRECTIONS AND SAVE IN ENCORY(*), ENCORQ(*),
C         BNCORY(*), AND BNCORQ(*)
 
          CALL CMPCOR
     I               (NBRA, NEX, BRPT, EXNODT, QEPS, EPSSYS, EPSSY2,
     I                ABSTOL,
     O                MXRE, BMXRE, NMXRE, KNT, KNTA, BNODE_MAX)
 
          MXREV(KOUNT) = MXRE
          BMXREV(KOUNT) = BMXRE
          NMXREV(KOUNT) = NMXRE
          KNTVEC(KOUNT) = KNT
 
C         SAVE SET2 IN SET3
 
          DO 303 I=1,NBN
            Y3(I) = Y2(I)
            Q3(I) = Q2(I)
 303      CONTINUE
          DO 307 I=1,NEX
            YE3(I) = YE2(I)
            QE3(I) = QE2(I)
 307      CONTINUE
 
C         APPLY A FRACTION OF THE CORRECTION.
 
 8400     CONTINUE
 
            CALL MAKCOR
     I                 (NEX, NBRA, NBN, STDOUT, EXNODT, BRPT, LAMBDA,
     A                  QCHOP)
 
            IF(OUTPUT.GT.2)
     A        CALL DUMPIT
     I                   (MXRE, QEPS, KOUNT, STDOUT, NBRA, NEX, BRPT,
     I                    EXNODT)
 
C           CHECK FOR CONVERGENCE
 
            IF(GEQOPT.GE.1) THEN
              IF(KNTA.EQ.0) THEN
                ITEMP = KNT
              ELSE
                ITEMP = 1000000
              ENDIF
            ELSE
              ITEMP = 1000000
            ENDIF
            IF(MXRE.LT.EPSSYS.AND.ERRP.LT.SSEPS.OR.
     A         ITEMP.LE.NUMLIM.AND.ERRP.LT.SSEPS) THEN
 
C             CONVERGENCE
 
              CFLAG = 1
              STFLAG = 0
 
              NTINT = NTINT + 1
              IF(MOD(NTINT,PRTINT).EQ.0) THEN
                IPRT = 1
              ELSE
                IPRT = 0
              ENDIF
 
 
C             COMPUTE REMAINDER OF SET2
 
              CALL CRSET2
     I                   (NBRA, NEX, BRPT,
     M                    EXNODT)
 
 
C             UPDATE THE RUNNING ITERATION VALUE
 
              SITER = AUTO*SITER+(1.- AUTO)*KOUNT
 
C             UPDATE CUMULATIVE ITERATION COUNT
 
              SUMITR = SUMITR + KOUNT
 
C             COMPUTE THE CUMULATIVE FLOW AT SYSTEM BOUNDARIES
 
              IF(IFRZ.EQ.0) THEN
                CALL BDYFLW
     I                     (BDYNUM, DT, EXNODT, NEX, QE1, QE2,
     I                      WT, BDYVEC,
     M                      BNI, BNQ, TAI, TAQ, TAQBN, WSI, WSQ)
              ENDIF
 
C             WRITE TO ANY OUTPUT FILES OPEN
 
              IF(IFRZ.EQ.0. AND.NFOUT.GT.0)
     A          CALL WROUT
     I                    (JTIME, STDOUT, QCHOP, DT)
 
C             UPDATE OPERATION BLOCKS WITH THE OLD SET 1 VALUES
 
              IF(NBLK.GT.0) CALL OPINIT
     I                                 (NBLK, OPBLK)
 
C             REPLACE SET 1 VALUES WITH SET 2 VALUES FOR NEXT TIME STEP
 
              CALL RPLSET
     I                   (DT, FAC, NBN, NEX)
 
C             UPDATE FLOW STATE VALUES
 
              CALL RSTSTA
     I                   (2, STDOUT,
     M                    EMC)
 
C              Update the delay  and detention reservoirs.
               IF(NLUSE.GT.0) THEN
                 DO 223 J=1,DLAY_KNT
                   DLAY_Q1(J) = DLAY_Q2(J)
223              CONTINUE
                 DO 224 J=1,DTEN_KNT
                   DTEN_Q1(J) = DTEN_Q2(J)
                   DTEN_Q1P(J) = DTEN_Q2P(J)
                   DTEN_S1(J) = DTEN_S2(J)
224              CONTINUE
                  
               ENDIF
C              Diffuse flow cumulative values
               IF(IFRZ.EQ.0) THEN
                 DO 225 J=1,NLUSE
                   CLSR1(J) = CLSR2(J)
 225             CONTINUE

C              Time series files that involve cumulative values.
C              We do them all-even though only some or none need
C              cumulative values
              
               DO 226 J=1,NUM_TS_F
                OLD_CUM(J) = NEW_CUM(J)
226            CONTINUE              
               ENDIF
 
C              FIND MAXIMUM AND MINIMUM FLOWS AND DEPTHS(ELEVATIONS)
 
               IF(IFRZ.LE.1)
     A          CALL FMXMN
     I                    (NBN, NEX, NBRA, EXNODT, BRPT, JTIME)
 
C              PRINT OUT RESULTS
 
               HRD = 24.*DYFRAC
               HR = HRD
               IF(OUTPUT.GT.2) WRITE(STDOUT,2010)
               IF(MINPRT.EQ.0) THEN
                 WRITE(STDOUT,2020) YR, MN, DY, HRD, DT
                 WRITE(*,2021) YR, MN, DY, HR, DT
                 CALL PRTLOG
     I                      (STDOUT, KOUNT, MXREV, BMXREV, NMXREV, MXRV,
     I                       LMXRV, MXSSRV, KNTVEC)
                 IF(BERRP.EQ.0) THEN
                   IBP = 0
                 ELSE
                   IBP = INBRUS(BERRP)
                 ENDIF
                 IF(BERRQ.EQ.0) THEN
                   IBQ = 0
                 ELSE
                   IBQ = INBRUS(BERRQ)
                 ENDIF
                 WRITE(STDOUT,2180) ERRP, IBP, NERRP, ERRQ,
     A                            IBQ, NERRQ, 
     B                            (TIME - EVENT_BASE)/FLOAT(SUMITR)
               ENDIF
               IF(IPRT.EQ.1.OR.JTIME.GT.PRTIME.OR.DT.LT.DTMIN_OUT)
     A           CALL RESOUT
     I                      (GRAV, VUNIT, STDOUT, NBRA, NODEID, NEX,
     I                       TIME, SFAC, BRPT, EXNODT,
     I                       QCHOP)
               IF(IFRZ.EQ.0) THEN
 
                 IF(IPRT.EQ.1.OR.JTIME.GT.PRTIME.OR.
     A                   DT.LT.DTMIN_OUT) THEN
C                  COMPUTE FINAL VOLUME AND OUTPUT SUMMARY FOR TIME STEP
                   CALL FIND_VOLUMES(NBRA, NBN, NEX, RESNUM, DLAY_KNT, 
     I                     DTEN_KNT, BRPT, RESVEC, DXVEC, A2, AE2,
     I                     POND2, GEQVEC, Q2, WXVEC2, MA2, DLAY_Q2, 
     I                     DLAY_K, DTEN_S2, DTEN_AVDA,
     O                     S2, D2)
 
                   BAL = S2 + BNQ + WSQ - 
     A                  (S1 +  BNI + TAQ + WSI)
                   RBAL = BAL/(S2 + BNQ)
                   WRITE(STDOUT,2150) S1, S2, BNI, BNQ, TAQ, WSI, WSQ
                   WRITE(STDOUT,2152)  BAL, RBAL
                   IF(DIFFUS.NE.NO) THEN
                     WRITE(STDOUT,2153) D1, D2, TAI, TAQBN
                     BAL = D2 + TAQ + TAQBN - (D1 + TAI)
                     RBAL = BAL/(D2 + TAQ + TAQBN + 1.0)
                     WRITE(STDOUT,2154) BAL, RBAL
                    ENDIF
C                   SUMIT = 0.0
C                   DO 2134 JK=1,NBN
C                    SUMIT = SUMIT + QPVEC(JK)
C2134               CONTINUE
C                   SUMIT = SUMIT*DT
C                   WRITE(STDOUT,*) ' DIFFUSE INFLOW VOL. AFTER=',SUMIT
                 ENDIF
 
C                OUTPUT QPVEC
 
                 IF(OUTPUT.GT.4) THEN
                   CALL QPVOUT
     I                        (NBRA, NBN, STDOUT, BRPT, QPVEC, NRWTA,
     I                         RWTA, RTAP)
                 ENDIF

C                Output to the GENSCN file. 
                 IF(FEO_UNIT.GT.0) THEN
                   CALL OUT_GENSCN
     I                            (STDOUT, JTIME)
                 ENDIF
               ENDIF
 
               IF(NOUT.GT.0)
     A           CALL OUTSP
     I                     (EXNODT, NEX, YR, MN, DY, HR, NOUT, UNIT, 
     I                      POUT,
     M                      QOUT, ZOUT, LKOUNT)
 
C              GOTO NEXT TIME INTERVAL

C      CALL MISSVOL(NBRA, NBN, BRPT, DXVEC, A2, GEQVEC, K2, T2, Q2,
C     A             0, JTIME)
 
               GOTO 8000
 
            ENDIF
 
C           NON-CONVERGENCE FALLS TO HERE

            
C           MAKE EXTERIOR NODES ON BRANCHES SAME VALUE AS THE
C           INTERIOR NODE VALUES.
 
            DO 400 I=1,NBRA
              YE2(BRPT(5,I)) = Y2(BRPT(3,I))
              TE2(BRPT(5,I)) = T2(BRPT(3,I))
              AE2(BRPT(5,I)) = A2(BRPT(3,I))
              QE2(BRPT(5,I)) = Q2(BRPT(3,I))
              YE2(BRPT(6,I)) = Y2(BRPT(4,I))
              TE2(BRPT(6,I)) = T2(BRPT(4,I))
              AE2(BRPT(6,I)) = A2(BRPT(4,I))
              QE2(BRPT(6,I)) = Q2(BRPT(4,I))
 400        CONTINUE
 
C           COMPUTE  MATRIX, UPDATE SRNEW, AND SOLVE MATRIX
 
 
            CALL CSMAT
     I                (DT, WT, NBN, NBRA, NEX, BRPT, HSLOT, EPT,
     I                 DTMIN_OUT, START_EQ, END_EQ, JTIME, PRTIME, 
     I                 KOUNT, QEPS,
     M                 EMC, EXNODT,
     O                 SRNEW, MXRES, LMXRES, ERRP, ERRQ, BERRQ, NERRQ,
     O                 NERRP, BERRP)
 
C           HAS THE CORRECTION IMPROVED THE SUM OF SQUARES OF THE
C           RESIDUALS?
 
            MXSSRV(KOUNT+1) = SRNEW
            MXRV(KOUNT+1) = MXRES
            LMXRV(KOUNT+1) = LMXRES
 
 

            IF(SRNEW.LE.SROLD + SRLIM) THEN
C            IF(SROLD.EQ.SROLD) THEN
 
C             YES, IMPROVEMENT
 
              LAMBDA = 1.0
              SROLD = SRNEW
 
C             COMPUTE NEW CORRECTION SET FROM CURRENT RESULT
 
              GOTO 8200
 
            ELSE
 
C             NO IMPROVEMENT
 
              IF(MINPRT.EQ.0) WRITE(STDOUT,3000) SROLD, SRNEW, LAMBDA
              LAMBDA = 0.5*LAMBDA
 
              SUMITR = SUMITR + 1
              IF(LAMBDA.LT.0.07) THEN
 
CCCCCCCCCCCCCC  IF(SRNEW.LT.SRLIM) THEN
                  WRITE(STDOUT,*) ' NO IMPROVEMENT BUT USE ANYWAY'
 
                  LAMBDA = 1.0
                  SROLD = SRNEW
                  GOTO 8200
 
CCCCCCCCCCCCCC  ENDIF
CCCCCCCCCCCCCC  CFLAG = 0
 
C               TRY AGAIN WITH A SMALLER TIME STEP
 
CCCCCCC         IF(MINPRT.EQ.0) THEN
CCCCCC            CALL PRTLOG(STDOUT, KOUNT, MXREV, BMXREV, NMXREV, MXRV,
CCCC A                        LMXRV, MXSSRV, KNTVEC)
CCCCCCC           WRITE(STDOUT,*) 'LAMBDA TOO SMALL. REDUCE TIME STEP'
CCCCCCC         ENDIF
 
CCCCCCC         GOTO 8000
              ENDIF
 
              GOTO 8400
            ENDIF
          END
C  ***********************************************************************
C  *  Warning:  This program is large and complex and  extensive         *  
C  *  knowledge of its design, purpose, and limitations is required      *  
C  *  in order to apply it properly.  Application of this program by an  *
C  *  unqualified user for any other purpose than an educational one is  *
C  *  not only unwise but is also unethical.  The user of this           *
C  *  program is totally responsible for its use and application and for *
C  *  any actions or events which follow therefrom.  Any user of this    *
C  *  program  holds the developer of the program harmless from          *
C  *  damages of any kind.                                               *
C  *                                                                     *       
C  *  The developer has used reasonable care in the construction and     *
C  *  testing of the program.  However, in a program of this size and    *
C  *  complexity, it is impossible to verify more than a minute number of*
C  *  possible options or applications.  The developer is continuing to  *
C  *  modify and use the program and is interested in information on     *
C  *  operational problems encountered in its application.  However, the *
C  *  developer gives no assurance that the problem can or will be       *
C  *  rectified.                                                         *
C  *                                                                     *       
C  *  This program is not to be sold in any form modified or otherwise.  *
C  ***********************************************************************
