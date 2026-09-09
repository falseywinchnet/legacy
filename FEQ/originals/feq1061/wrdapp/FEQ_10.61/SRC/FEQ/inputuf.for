C Routines used in input of the user input file

c
c
c
      subroutine set_time_step_tables(stdout,
     o                                 eflag)

c     Set values for time-step table handling.

      implicit none
      integer stdout, eflag
      
      include 'arsize.prm'
      include 'timetab.cmn'
      include 'ftable.cmn'

      integer get_unit


c     Local

      integer ioflag, it

c***********************************************************************
      if(make_dt_tab.eq.' ') then
        stddtout = 0
      else
        stddtout = get_unit(stdout)
        CALL MAYBE_ADD_GHOME_OUT(
     M                      make_dt_tab)
        call maybe_add_ext(
     m                      make_dt_tab)

        call os_file_style(
     m                              make_dt_tab)
        OPEN(UNIT=stddtout, FILE=make_dt_tab, 
     a                   STATUS='UNKNOWN',IOSTAT=IOFLAG)
        IF(IOFLAG.NE.0) THEN
          IT = LEN_TRIM(make_dt_tab)
          WRITE(STDOUT,*) ' Problem in opening file: ',make_dt_tab(1:IT)
          WRITE(STDOUT,*) ' Check path for making a time step table.'
          STOP 'Abnormal stop: errors found.'
        ENDIF

      endif
      if(use_maxdt_tab.ne.' ') then
        call FIND_INTERNAL_TAB_NUMBER
     I                               (use_maxdt_tab,
     O                                 tab_for_maxdt)
        if(tab_for_maxdt.gt.0) then
          call CHKTAB
     I               (2, STDOUT, FTPNT, MFTnum,
     M               tab_for_maxdt,
     O               EFLAG)
        else
          write(stdout,*) ' Max. time-step table not found'
          stop 'Abnormal stop.  Missing max time step table.'
        endif

      else
        tab_for_maxdt = 0
        
      endif

      return
      end
  

C
C
C
      SUBROUTINE IRRIG_CHECK(STDOUT, FTPNT, GEND, GSTART,
     M                     EFLAG)

C     Check the dual-source irrigation control values. 

      IMPLICIT NONE
      INCLUDE 'arsize.prm'

      INTEGER STDOUT, FTPNT(MFTNUM), GEND(0:MXGAGE),
     A        GSTART(0:MXGAGE), EFLAG

      INCLUDE 'irrig.cmn'
      INCLUDE 'tam.cmn'
      INCLUDE 'inusnb.cmn'

C     Local

      CHARACTER*5 BRANCH_NODE*5

      INTEGER I, EXN_BRA, NEXT_TAU, CAT_CODE, ROW_NUMBER, GAGE

      EXTERNAL CHKTAB

C     ***********************FORMATS************************************
50    FORMAT(/,'*ERR:XXX Irrigation not allowed for exterior node: ',
     A  A5,' because',/,' the node has no tributary area.',
     B '  Please check the Tributary Area Input block.')
52    FORMAT(/,'*ERR:XXX Irrigation not allowed for branch: ',
     A  I5,' because',/,' the branch has no tributary area.',
     B '  Please check the Tributary Area Input block.')
54    FORMAT(/,'*ERR:XXX* Land-use index=',I5,' for node or branch=',
     A      A5,' is out of bounds for IRRIGATION.')
56    FORMAT(/,'*ERR:XXX* Land-use indices for node or branch=',
     A   A5,' are the same for IRRIGATION.')
C***********************************************************************

      DO 200 I=1,IRRIG_KNT

        EXN_BRA = IRRIG_TRIBA_ROW(I)
C       Find the tributary area unit that has an internal node or 
C       branch number matching the number stored in IRRIG_TRIBA_ROW.

        TAM_IPNT = 1

100     CONTINUE
          NEXT_TAU = TAM_ITAB(TAM_IPNT+2)
          CAT_CODE = TAM_ITAB(TAM_IPNT+1)
          IF(CAT_CODE.EQ.2.OR.CAT_CODE.EQ.3) THEN
C           We have a tributrary-area unit attached to an exterior node.
            IF(EXN_BRA.EQ.TAM_ITAB(TAM_IPNT)) THEN
C             We have a match!
              ROW_NUMBER = TAM_ITAB(TAM_IPNT+3)
              GAGE = TAM_ITAB(TAM_IPNT+4)
C             Get label for possible error messages.
              BRANCH_NODE = INENUS(EXN_BRA)
            ELSE
              IF(NEXT_TAU.GT.0) THEN
                TAM_IPNT = NEXT_TAU
                GOTO 100
              ELSE
C               No match found.  Error in Trib area specification or in 
C               irrigation specification.
                WRITE(STDOUT,50) INENUS(EXN_BRA)
                EFLAG = 1
                GOTO 200
              ENDIF
            ENDIF
          ELSE
C           Category is a branch. 
            IF(ABS(EXN_BRA).EQ.TAM_ITAB(TAM_IPNT)) THEN
C             We have a match!                        
              ROW_NUMBER = TAM_ITAB(TAM_IPNT+3)
              GAGE = TAM_ITAB(TAM_IPNT+4)
              WRITE(BRANCH_NODE,'(I5)') INBRUS(ABS(EXN_BRA))
            ELSE
              IF(NEXT_TAU.GT.0) THEN
                TAM_IPNT = NEXT_TAU
                GOTO 100
              ELSE
C               No match found.  Branch not present in Trib. area.
                WRITE(STDOUT,52) INBRUS(EXN_BRA)
                EFLAG = 1
                GOTO 200
              ENDIF           
            ENDIF            
          ENDIF

C       We have the row number here!
        IRRIG_TRIBA_ROW(I) = ROW_NUMBER

C       Check to make sure that the land-use indices make
C       sense for this tributary-area unit.
c        WRITE(STDOUT,*) ' IRRIG_CHK: GAGE=',GAGE,
c     A        ' GSTART=',GSTART(GAGE),' GEND=',GEND(GAGE)
c
c        WRITE(STDOUT,*) ' IRRIG_LUI_APPLY=',IRRIG_LUI_APPLY(I)
c        WRITE(STDOUT,*) ' IRRIG_LUI_COMPUTE=',IRRIG_LUI_COMPUTE(I)
        IF(IRRIG_LUI_APPLY(I).LT.1.OR.IRRIG_LUI_APPLY(I).GT.
     A      GEND(GAGE) - GSTART(GAGE) + 1) THEN
          WRITE(STDOUT,54) IRRIG_LUI_APPLY(I), BRANCH_NODE
          EFLAG = 1
        ENDIF

C       Check the irrigation computation index.
        IF(IRRIG_LUI_COMPUTE(I).LT.1.OR. IRRIG_LUI_COMPUTE(I).GT.
     A      GEND(GAGE) - GSTART(GAGE) + 1) THEN
          WRITE(STDOUT,54) IRRIG_LUI_COMPUTE(I), BRANCH_NODE
          EFLAG = 1
        ENDIF
        
C       The two land-use indices must differ.
        IF(IRRIG_LUI_COMPUTE(I).EQ.IRRIG_LUI_APPLY(I)) THEN
          WRITE(STDOUT,56) BRANCH_NODE
          EFLAG = 1
        ENDIF

C       Check the irrigation control table and find its
C       address if it exists. 
        CALL CHKTAB
     I             (2, STDOUT, FTPNT, MFTNUM,
     M              IRRIG_CONTROL_TAB(I),
     O              EFLAG)

200   CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE IRRIG_INPUT(IN, STDOUT, 
     M                     ENODEN, EFLAG)

C     Input irrigation specification for dual-source irrigation.
C     When near-surface water is available it is used.  When 
C     near-surface water becomes scarce, then use shifts rapidly
C     to other sources: imported from outside the basin being 
C     modeled or from deep ground water.  These sources are assumed
C     to have no limit so that the irrigation water applied in
C     the rainfall runoff model will also be applied in the 
C     unsteady-flow model.

      IMPLICIT NONE
      INTEGER IN, STDOUT, EFLAG, ENODEN

      INCLUDE 'arsize.prm'
      INCLUDE 'irrig.cmn'
      INCLUDE 'inusnb.cmn'
      INCLUDE 'usintp.cmn'

C     Local

      CHARACTER LINE*80, EXN_BRA*5, H2O_SOURCE*5, ENF*5,
     A          TABID*16

      INTEGER I, LUI, NODE, IRRIG_INDEX, TAB_NUMBER, SOURCE_NODE

      EXTERNAL inline, STRIP_L_BLANKS, GET_INTERNAL_TAB_NUMBER
C     **************************FORMATS*********************************
50    FORMAT(' ',A80)
52    FORMAT(/,'*ERR:XXX* Number of tributary-area units with',
     A ' dual-source irrigation >',I5,/,11X,
     B /,' the number allowed. Increase parameter MXN_IRRIG in file',
     C ' arsize.prm and recompile FEQ.')
C***********************************************************************
C     Clear the irrigation counter.
      IRRIG_KNT = 0

C     Read the two heading lines
      CALL inline(IN, STDOUT,
     O           LINE)
      WRITE(STDOUT,50) LINE
      CALL inline(IN, STDOUT,
     O           LINE)
      WRITE(STDOUT,50) LINE

C     Read lines of input until the -1 termination flag is found
      I= 0
100   CONTINUE
        CALL inline(IN, STDOUT,
     O             LINE)
        READ(LINE,'(A5,I5,I5,A5,A16)') EXN_BRA, LUI, IRRIG_INDEX,
     A             H2O_SOURCE, TABID

        WRITE(STDOUT,50) LINE

C       Convert the exterior node/branch number item.
        CALL STRIP_L_BLANKS(
     M                     EXN_BRA)
        IF(EXN_BRA(1:1).EQ.'F') THEN
C         Exterior node
          ENF = EXN_BRA(1:5)
          CALL FNDINN
     I               (
     M                ENF, ENODEN, USENIN,
     O                EFLAG, INENUS, NODE)
        ELSEIF(EXN_BRA(1:2).EQ.'-1') THEN
C         Done with input.

          IRRIG_KNT = I
          GOTO 101
        ELSE
C         Assume it is a branch number.
C         Use the variable NODE for the branch number
          READ(EXN_BRA,'(I5)',ERR=991) NODE
          NODE = -NODE
        ENDIF

C       Convert the H2O source node.
        CALL STRIP_L_BLANKS(
     M                      H2O_SOURCE)
        ENF = H2O_SOURCE(1:5)
        CALL FNDINN
     I             (
     M              ENF, ENODEN, USENIN,
     O              EFLAG, INENUS, SOURCE_NODE)

C       Store the items in the data structure. 
        I = I + 1
        IF(I.GT.MXN_IRRIG) THEN
          WRITE(STDOUT,52) MXN_IRRIG
          STOP 'Abnormal stop: errors found.'
        ENDIF

C       Note: IRRIG_TRIBA_ROW is not yet the row number. 
C       Currently it holds the internal exterior node number
C       or the negative of the internal branch number. 
C       The conversion to TRIBA row number will be made 
C       when the input is checked in a later routine. 
        IRRIG_TRIBA_ROW(I) = NODE
        IRRIG_LUI_APPLY(I) = LUI
        IRRIG_LUI_COMPUTE(I) = IRRIG_INDEX
        IRRIG_SOURCE(I) = SOURCE_NODE
        CALL STRIP_L_BLANKS(
     M                     TABID)
        CALL GET_INTERNAL_TAB_NUMBER
     I                               (STDOUT, TABID,
     M                                EFLAG,
     O                                TAB_NUMBER)

        IRRIG_CONTROL_TAB(I) = TAB_NUMBER
      
        GOTO 100

101   CONTINUE
      RETURN

 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE
        STOP 'Abnormal stop: errors found.'
      END                
C     ***********
C     *         *
C     * TS_CHK_AND_UPDATE
C     *         *
C     ***********

      SUBROUTINE TS_CHK_AND_UPDATE(STDOUT, NEW_FORM, NC_LONGA, DST_CAT,
     I                             DST_PNT, 
     M                             TAB_NUM, LDCALL, EFLAG)

C     Process a possible time-series reference.  If present,
C     check ranges and update the time-series management data
C     structure.

      IMPLICIT NONE
      CHARACTER*16 NC_LONGA

      INTEGER LDCALL, NEW_FORM, TAB_NUM, DST_CAT, DST_PNT, EFLAG, STDOUT

C     Definitions:

C     STDOUT- standard output unit number.
C     NEW_FORM - flag for new input form for Network Matrix: 0 old
C               form, not 0- new form.
C     TAB_NUM - table number from old form
C     NC_LONG - identifier string from new form as well as the
C               character sequence of the old form.
C     DST_CAT- destination category for values taken from the time series:
C              forced boundary, lpr evaporation,etc.
C     DST_PNT- integer index giving the location that will contain
C              the value taken from the time series.  Its nature
C              may depend on the destination category. 
C     LDCALL - flag for calling the LOAD subroutine to process
C              time series.
 
      INCLUDE 'arsize.prm'
      INCLUDE 'ts_mngt.prm'
      INCLUDE 'ts_mngt.cmn'

      EXTERNAL KIL, LSATAB

C     Local

      CHARACTER*16 NC_LONG

      INTEGER  TS_INDEX, LOCAL_EFLAG, IPNT, IT

C     ******************************Formats*****************************
50    FORMAT(/,' *ERR:277* Count of time-series=',I5,' > ',I5,', the',
     A         ' current limit.')
52    FORMAT(/,' *ERR:278* Count of time-series references=',I5,' > ',
     A         I5,', the current limit.')
C***********************************************************************
      NC_LONG = NC_LONGA
      LOCAL_EFLAG = 0
C     If TAB_NUM > 0 we have a reference to a time-series table.
C     If TAB_NUM = 0 we have a reference to a value local to the instruction.
C     If TAB_NUM < 0 we have a reference to a time-series file.

      IF(TAB_NUM.NE.0) THEN
        LDCALL = 1
C       We have a reference to a time-series. Check the 
C       time-series id table for the reference. If not
C       seen before, add it; in any case return the
C       index. 
        NUM_DEST = NUM_DEST + 1
        CALL  LSATAB
     I             (STDOUT, NC_LONG, MXN_TS,
     M                TS_ID, NUM_TS,
     O                TS_INDEX, LOCAL_EFLAG)
        IF(LOCAL_EFLAG.GT.0) THEN
          WRITE(STDOUT,50) NUM_TS, MXN_TS
          EFLAG = 1
        ENDIF
C       Is this the first occurrence or another occurence?
        IF(DEST_CAT(TS_INDEX).EQ.0) THEN
C         First time for this time-series.

          IF(TAB_NUM.GT.0) THEN
            SOURCE_CAT(TS_INDEX) = TS_FROM_TABLE
          ELSE
            SOURCE_CAT(TS_INDEX) = TS_FROM_FILE
          ENDIF
          SOURCE_ADDRESS(TS_INDEX) = TAB_NUM
          DEST_CAT(TS_INDEX) = DST_CAT
          DEST_PNT(TS_INDEX) = DST_PNT
          DEST_LINK(TS_INDEX) = 0
        ELSE
C         We have another reference to the same time series
C         with a different destination.
          IPNT = TS_INDEX
200       CONTINUE
            IT = DEST_LINK(IPNT)
            IF(IT.EQ.0) THEN
C             Store in the next open location.
              DEST_LINK(IPNT) = NEXT_LINK
              
              DEST_CAT(NEXT_LINK) = DST_CAT
              DEST_PNT(NEXT_LINK) = DST_PNT
              DEST_LINK(NEXT_LINK) = 0
              NEXT_LINK = NEXT_LINK + 1
              IF(NEXT_LINK.GT.MXN_DEST) THEN
                WRITE(STDOUT,52) NEXT_LINK, MXN_DEST
                EFLAG = 1
                NEXT_LINK = MXN_DEST
              ENDIF
            ELSE
              IPNT = IT
              GOTO 200
            ENDIF
        ENDIF

      ENDIF
      RETURN
      END  

C
C
C
      SUBROUTINE PROCESS_INVERT_SPEC(STDOUT, XTAB, STRING,
     O                                ELEV, EFLAG)

C     Dechipher the invert elevation specification.  It can have 
C     the following forms: 
C         TAB 
C         tab
C         TAB+num
C         TAB-num 
C         tab+num 
C         tab-num
C         num
C         num+num
C         num-num

C     A blank value is NOT taken to be zero.  It is given a large
C     negative value.
    
      IMPLICIT NONE
      INTEGER EFLAG, STDOUT, XTAB

      CHARACTER STRING*16

      REAL ELEV

C     Called program units
      INTEGER LENSTR
      EXTERNAL LENSTR, STRIP_L_BLANKS, FNDELV

C     Local

      INTEGER IT, L

      CHARACTER TPC*16

      REAL DELTA
C***********************************************************************
      IF(STRING.EQ.' ') THEN
        ELEV = -1.E30
      ELSE
C       Find the arithmetic operator if any
        IT = INDEX(STRING,'+')
        IF(IT.EQ.0) THEN
          IT = INDEX(STRING,'-')
        ENDIF
        L = LENSTR(STRING)

C       Get the substring following the operator
        IF(IT.GT.0) THEN
          TPC = STRING(IT+1:L)
          CALL STRIP_L_BLANKS(
     M                        TPC)
C         Put the operator back on
          TPC = STRING(IT:IT)//TPC

          READ(TPC,'(F10.0)', ERR=991) DELTA
        ELSE
          DELTA = 0.0
        ENDIF

C       Now process the rest
        IF(IT.EQ.0) THEN
          TPC = STRING
        ELSE
          TPC = STRING(1:IT-1)
        ENDIF
        CALL STRIP_L_BLANKS(
     M                      TPC)
        IF(TPC(1:3).EQ.'TAB'.OR.TPC(1:3).EQ.'tab') THEN
C         Lookup the elevation. 
      
          CALL FNDELV
     I               (XTAB, STDOUT,
     O                EFLAG, ELEV)
        ELSE
          READ(TPC,'(F10.0)', ERR=991) ELEV
        ENDIF

        ELEV = ELEV + DELTA
      ENDIF
      RETURN
991   CONTINUE
      WRITE(STDOUT,*) ' *ERR:500* Conversion error in:'
      WRITE(STDOUT,*) TPC
      STOP 'Abnormal stop: errors found.'

      END
      
C
C
C
      SUBROUTINE   BRIN
     I                 (SFAC, IN, STDOUT, MNBN, NEX, 
     I                  MFTNUM, ISTYLE, GISID_TO_NODEID, 
     I                  TABID_TO_NODEID, dz_for_output,
     M                  EFLAG, USBRIN, ENODEN, NBRA,
     O                  NBN, BRPT, NSEC, UVX, UVY, XVEC, ZVEC, KA, KD,
     O                  HLTAB, COEFIN, YCUT, BNODID, ZIVEC, STDFLD,
     O                  PNDFLG, WDFVEC, USENIN, INBRUS, INENUS, EXNODT,
     O                  ENODID, ADDVEC, GEQVEC, GEQOPT, KADJVEC)
 
C     + + + PURPOSE + + +
C     Input the branch description information.
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, ENODEN, GEQOPT, IN, STDOUT, MFTNUM, MNBN, NBN, 
     A        NBRA, NEX, PNDFLG
      INTEGER ADDVEC(NBRA), BRPT(8,NBRA), EXNODT(9,NEX), GEQVEC(NBRA),
     A        HLTAB(MNBN), INBRUS(9999), NSEC(MNBN), USBRIN(9999),
     B        USENIN(-9999:19998)
      REAL COEFIN(MNBN), KA(MNBN), KADJVEC(MNBN), KD(MNBN), 
     A     SFAC, STDFLD(MNBN), UVX(MNBN), UVY(MNBN), 
     B     WDFVEC(NBRA), XVEC(MNBN), YCUT(MNBN), 
     C     ZIVEC(NBRA), ZVEC(MNBN), dz_for_output
      CHARACTER BNODID(MNBN)*16, ENODID(NEX)*16, INENUS(NEX)*5, 
     A          ISTYLE*4, GISID_TO_NODEID*4, TABID_TO_NODEID*4
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     SFAC   - conversion factor from user stations to internal stations
C     IN     - unit number for the user input file
C     STDOUT   - Fortran unit number for user output and messages
C     MNBN   - maximum number of branch nodes
C     NBRA   - on entry, max allocate number of branches.
C              on exit,number of branches in the model 
C     NEX    - max allocated number of exterior nodes in the model
C     MFTNUM - maximum function table number
C     ISTYLE - input style: NEW or OLD
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     USBRIN - conversion from user branch number to internal branch
C               number
C     ENODEN - internal exterior-node number
C     NBN    - total number on nodes on branches in the model
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
C     UVX    - sine of azimuth angle for each element.
C     UVY    - cosine of azimuth angle for each element
C     XVEC   - station values for each node on a branch
C     ZVEC   - bottom profile elevations for nodes on a branch
C     KA     - velocity head factor for contraction loss
C     KD     - velocity head factor for expansions loss
C     HLTAB  - addresses of point loss tables.  0 if none present
C     COEFIN - effective discharge coefficient for storm sewer inflow
C     YCUT   - distance from invert of storm sewer to ground surface
C     BNODID - branch-node identification string
C     ZIVEC  - inertia factor for each branch
C     STDFLD - standard flood elevation
C     PNDFLG - flag to signal simulation of surcharge storage
C     WDFVEC - adjustment factor for wind stress for a branch
C     USENIN - conversion from user exterior node number to internal
C               exterior node number
C     INBRUS - conversion from internal branch number to user branch
C               number
C     INENUS - conversion from internal exterior node number to user
C              exterior node designation
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
C     ENODID - exterior node identification string given by user
C     ADDVEC - the number of nodes to be added to each element on each
C               branch in the model
C     GEQVEC - code for the governing equation option for each branch
C     GEQOPT - governing equation option code
C     KADJVEC- adjustment factor for conveyance
 
C     + + + SAVED VALUES + + +
      CHARACTER GENVEC(4)*5
      SAVE GENVEC
 
C     + + + LOCAL VARIABLES + + +
      INTEGER MXITEM
      PARAMETER (MXITEM=13)
      INTEGER ADDNOD, BNIN, BNUM, FIRST, FTID, HL, I, J, JZERO,
     A        K, LAST, LNODE, LXTAB, NODE, XTAB, ZCFLAG, DIRECTION,
     B        LOCAL_DIRECTION, ITEM_START(MXITEM), ITEM_END(MXITEM),
     C        NITEM, IT, IDLEN, HLIDLEN, OLD_NBN
     
      REAL AZM, AZMOLD, AZMOUT, CA, CD, CF, CFRATE, DX, DZ, ELEV, FAC,
     A     FINT, INERT, KADJ, STAT, STATL, STATR, STD, STDL, 
     B     STDR, WDFAC, X, YC, YCOLD, Z, QPATH_LENGTH
      CHARACTER AZMC*5, GENAME*5, HEAD*120,  JUST*5,
     A          LINE*120, NAME*16,  XCHAR*10, XTABN*5, YCCHAR*8,
     B          ZCHAR*16, TABID*16, TEMPC*16, HLTABID*16, BLANK*16,
     C          DXOUT*10
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS, COS, FLOAT, SIN
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER LENSTR
      CHARACTER GETTOK*10, MAKENN*5, GET_TABID*16, GET_GISID
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL FNDSTA, GETTOK, inline, inlineb, INSNOD, KIL,
     A         MAKENN, GET_BRANCH_ITEMS,  GET_GISID,
     B         GET_ITEM_LIMITS, GET_TABID, LENSTR, GET_BRHD, SET_BRHD,
     C         PROCESS_INVERT_SPEC
 
C     + + + DATA INITIALIZATIONS + + +
      DATA GENVEC/'STDX ','STDW ','STDCX','STDCW'/
      DATA BLANK/' '/
 
C     + + + INPUT FORMATS + + +
 1    FORMAT(A)
 2    FORMAT(5X,I5,9X,A5,8X,F5.0,9X,A5,8X,A5,8X,A5)
 13   FORMAT(I5,A5,2A10,2F5.0,I5,A5,F5.0,A8,F7.0)
 16   FORMAT(I5,1X,A8,1X,A5,2A10,2F5.0,I5,A5,F5.0,A8,F7.0)
 
C     + + + OUTPUT FORMATS + + +
 11   FORMAT(' ',A)
 12   FORMAT(/,' ','BRANCH NUMBER=',I5,' INERTIA=',F5.1,
     A       ' CFRATE=',F6.1,' WINDFAC=',F5.2,' ADDNOD=',I5,
     B       ' GEQOPT=',A5)
 50   FORMAT(' *ERR:108* Cross section table id must be > 0',
     A       ' at first node on branch')
 52   FORMAT(' *ERR:109* Inlet area given but inlet cutoff height',
     A       ' is missing for node:',I7)
 54   FORMAT(' *ERR:186* Two stations match in branch',I5, ' Station=',
     A        F15.4)
 56   FORMAT(' *ERR:228* Branch number=',I5,' is a duplicate number.')
 58   FORMAT(' *ERR:167* Incorrect number of branches given or BNUM',
     A       ' misspelled.')
 59   FORMAT(/,' End of Branch-Description Block detected.',/,
     A       ' Number of branches found=',I5)
 75   FORMAT(/,' *ERR:393* Unknown option=',A5,
     A' for GEQOPT on this branch.')
 76   FORMAT(/,' *ERR:184*  Elevation=',F10.3,' on branch=',I5,' at',
     A       ' node=',I7,' has no station.')
 78   FORMAT(/,' *ERR:251* Bottom profile elevation missing at',
     A         ' first node on branch:', I7)
 79   FORMAT(/,' *ERR:252* Bottom profile elevation missing at',
     A         ' last node on branch:',I7)
 81   FORMAT(/,' *ERR:253* YC <= 0 at node:',I7,' on branch:',I5)
 82   FORMAT(/,' *ERR:69* Station direction inconsistent at node:',I7)
83    FORMAT(/,' *ERR:111* Last node on branch number=',I7,
     A       ' has a missing or invalid table id.')
84    FORMAT('   Node  Node Identifier',1X,A,
     A 'TabId   Station Elevation',
     B '   KA   KD',A,'HL Id  AZM   CF    YCUT    STDFLD      KADJ',
     C ' Delta Stn')
85    FORMAT(/,' *ERR:394* Only one node on branch=',I5,
     A       '  Need at least two nodes per branch.')

86    FORMAT(/,' Length of all branch flow paths=',F10.3)

18000 FORMAT(1X,I6,1X,A16,1X,A,F10.0,F10.3,2F5.2,A,F5.0,F5.1,
     A           F8.1,F10.2,F10.3,A10)
18100 FORMAT(1X,I6,1X,A16,1X,A,F10.1,F10.3,2F5.2,A,F5.0,F5.1,
     A           F8.1,F10.2,F10.3,A10)
18200 FORMAT(1X,I6,1X,A16,1X,A,F10.2,F10.3,2F5.2,A,F5.0,F5.1,
     A           F8.1,F10.2,F10.3,A10)
18300 FORMAT(1X,I6,1X,A16,1X,A,F10.3,F10.3,2F5.2,A,F5.0,F5.1,
     A           F8.1,F10.2,F10.3,A10)
18400 FORMAT(1X,I6,1X,A16,1X,A,F10.4,F10.3,2F5.2,A,F5.0,F5.1,
     A           F8.1,F10.2,F10.3,A10)
C***********************************************************************
C     Create index for case selection of the output format.
      FTID = NINT( LOG10(SFAC))
 
C     CLEAR EXNODT(*,*) FOR USE IN DETECTING WHEN EXTERIOR NODES HAVE
C     BEEN DEFINED MORE THAN ONCE.
 
      DO 99 I=1,NEX
        DO 98 J=1,5
          EXNODT(J,I) = 0
 98     CONTINUE
C       Set rows 6, 7, and 8 to the most negative integer number
c        EXNODT(6,I) = -(2**31 - 1)
c        EXNODT(7,I) = -(2**31 - 1)
c        EXNODT(8,I) = -(2**31 - 1)
        EXNODT(6,I) = -2147483647
        EXNODT(7,I) = -2147483647
        EXNODT(8,I) = -2147483647

C       Set the latest row, 9 to zero
        EXNODT(9,I) = 0
 99   CONTINUE
 
 
      JUST = 'RIGHT'
      
C     Clear the simulation of ponding flag
      PNDFLG = 0
 
      STDFLD(1) = 0.0
C     SET UP INITIAL VALUES OF POINTERS AND COUNTERS
      BNUM = 0
      NBN = 0
      QPATH_LENGTH = 0.0
      DO 140 I=1,NBRA
        AZMOLD = 0.0
        LNODE = 0
        IDLEN = 0
        HLIDLEN = 0
C       Clear the ground surface elevation option flag
        ZCFLAG = 0
        YC = 0.0
        YCOLD = 0.0
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        IF(LINE(1:4).NE.'BNUM'.AND.LINE(1:6).NE.'BRANCH') THEN
C          WRITE(STDOUT,58)
C          STOP 'Abnormal stop: errors found.'
          WRITE(STDOUT,59) BNUM
          NBRA = BNUM
          BACKSPACE(IN)
          GOTO 9000
        ENDIF

        BACKSPACE(IN)
        CALL GET_BRHD(IN, STDOUT, 
     M                   EFLAG)
        CALL SET_BRHD(
     O                BNIN, INERT, CFRATE, WDFAC, ADDNOD, GENAME)

C       CONVERT THE EXTERNAL BRANCH NUMBER TO INTERNAL AND CREATE
C       TRANSLATION VECTORS.
        BNUM = BNUM + 1
        IF(BNIN.LT.1.OR.BNIN.GT.9999) CALL KIL
     I                                        (1,
     M                                         BNIN, EFLAG)
        IF(USBRIN(BNIN).EQ.0) THEN
C         FIRST TIME BRANCH HAS BEEN SEEN. MAKE ASSIGNMENTS
          USBRIN(BNIN) = BNUM
          INBRUS(BNUM) = BNIN
        ELSE
C         ERROR. DUPLICATE BRANCH ID FROM USER.
            WRITE(STDOUT,56) BNIN
          EFLAG = 1
        ENDIF
 
        ZIVEC(BNUM) = INERT
        IF(CFRATE.GT.0.0) PNDFLG = 1
        WDFVEC(BNUM) = WDFAC
 
        ADDVEC(BNUM) = ADDNOD
 
C       CHECK ON THE GOVERNING EQUATION OPTION FOR THE BRANCH.
        IF(GENAME.NE.'    ') THEN
C         WE HAVE A NON-DEFAULT SELECTION
          IF(GENAME.EQ.'STDX ') THEN
            GEQVEC(BNUM) = 1
          ELSEIF(GENAME.EQ.'STDW ') THEN
            GEQVEC(BNUM) = 2
            GEQOPT = 2
          ELSEIF(GENAME.EQ.'STDCX') THEN
            GEQVEC(BNUM) = 3
          ELSEIF(GENAME.EQ.'STDCW') THEN
            GEQVEC(BNUM) = 4
            GEQOPT = 2
          ELSE
            WRITE(STDOUT,75) GENAME
            STOP 'Abnormal stop.  Error found.'
          ENDIF
        ELSE
C         SUPPLY THE DEFAULT VALUE AS GIVEN IN THE RUN CONTROL BLOCK
          GENAME = GENVEC(GEQVEC(BNUM))
        ENDIF
        WRITE(STDOUT,12) BNIN, ZIVEC(BNUM), CFRATE, WDFVEC(BNUM), 
     A                   ADDNOD, GENAME
        ADDNOD = ABS(ADDNOD)
 
 
C       SET THE NUMBER OF UNKNOWNS PER NODE FOR THE BRANCH. CURRENTLY
C       THERE IS ONLY ONE KIND OF BRANCH 
 
        BRPT(8,BNUM) = 2
 
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,1) HEAD
C       Define the limits for the items on a line.
        CALL GET_ITEM_LIMITS(
     I                       STDOUT, LINE, MXITEM, JUST,
     O                       NITEM, ITEM_START, ITEM_END)

C       Track the number of nodes on this branch to catch 
C       error of only one node on the branch. April 26, 2000.
        OLD_NBN = NBN
 100    CONTINUE
          CALL inlineb
     I               (IN, STDOUT,
     O                 LINE)
          CALL GET_BRANCH_ITEMS(
     I                          STDOUT, LINE, NITEM, ITEM_START,
     I                          ITEM_END,
     M                          EFLAG, IDLEN, HLIDLEN, 
     O                          NODE, NAME, XTABN, XCHAR, 
     O                          ZCHAR, CA, CD, HL, AZMC, CF, 
     O                          YCCHAR, STD, KADJ, TABID)
 
          IF(NODE.EQ.-1) GOTO 120
          IF(LNODE.NE.0) NODE = LNODE+1
 
          IF(CF.GT.0.0) PNDFLG = 1
          IF(NODE.LE.0) CALL KIL
     I                           (2,
     M                            NODE, EFLAG)
          IF(NODE.LE.LNODE) CALL KIL
     I                               (3,
     M                                NODE, EFLAG)
          IF(XTABN(1:1).EQ.'-') THEN
            XTAB = -1000000
          ELSE
            READ(XTABN,'(I5)',ERR=991) XTAB
            IF(ABS(XTAB).GT.MFTNUM) CALL KIL
     I                                       (9,
     M                                        XTAB, EFLAG)
          ENDIF
          IF(LNODE.NE.0.AND.YCCHAR.NE.' ') THEN
            READ(YCCHAR,'(F8.0)',ERR=991) YC
            YCOLD = YC
          ENDIF
          IF(LNODE.NE.0.AND.YCCHAR.EQ.' ') THEN
            IF(ZCFLAG.EQ.0.AND.YCOLD.GT.0.0) THEN
              YC = YCOLD
            ELSEIF(ZCFLAG.EQ.1) THEN
              YC = -1.E30
            ELSE
              YC = 0.0
            ENDIF
          ENDIF
          IF(CF.GT.0.0) THEN
            IF(YC.EQ.0.0) THEN
              WRITE(STDOUT,52) NODE
              EFLAG = 1
            ENDIF
          ENDIF
 
C         SET THE AZIMUTH FOR THIS ELEMENT
          IF(AZMC.EQ.' ') THEN
            AZM = AZMOLD
          ELSE
            READ(AZMC,'(F5.0)',ERR=991) AZM
            AZMOLD = AZM
          ENDIF
 
C         VALID NODE NUMBER HERE
 
C         CATCH THE FIRST NODE NUMBER AND SET THE POINTER
 
          IF(LNODE.EQ.0) THEN
            BRPT(1,BNUM) = NODE
            BRPT(3,BNUM) = NBN + 1
            IF(XTAB.LE.0) THEN
              WRITE(STDOUT,50)
              EFLAG = 1
              XTAB = 1
            ENDIF
            LXTAB = XTAB
            IF(YCCHAR.NE.' ') THEN
C             Non-blank at upstream node for YCUT.  Means that the
C             value is an elevation and the elevation option for YCUT
C             has been selected.
              ZCFLAG = 1
              READ(YCCHAR,'(F8.0)',ERR=991) YC
            ENDIF
          ENDIF
          LNODE = NODE
 
C         STORE VALUES FOR THIS NODE
 
          NBN = NBN+1
          IF(NBN.GT.MNBN) CALL KIL
     I                             (27,
     M                              NBN, EFLAG)
          IF(XTAB.EQ.0) THEN
            XTAB = LXTAB
          ELSE
            LXTAB = XTAB
          ENDIF
          NSEC(NBN) = XTAB
C         PROCESS THE STATION AND ELEVATION VALUES
          XCHAR = GETTOK(XCHAR)
C          ZCHAR = GETTOK(ZCHAR)
          IF(XCHAR(1:3).EQ.'TAB'.OR.XCHAR(1:3).EQ.'tab') THEN
C           FIND THE STATION FROM THE CROSS SECTION TABLE XTAB
            CALL FNDSTA
     I                 (XTAB, STDOUT,
     O                  EFLAG, X)
          ELSEIF(XCHAR.EQ.'          ') THEN
            X = -1.E30
          ELSE
            READ(XCHAR,'(F10.0)',ERR=991) X
          ENDIF
          CALL PROCESS_INVERT_SPEC(STDOUT, XTAB, ZCHAR,
     O                             Z, EFLAG)

C          IF(ZCHAR(1:3).EQ.'TAB'.OR.ZCHAR(1:3).EQ.'tab') THEN
C           FIND THE ELEVATION FROM THE CROSS SECTION TABLE XTAB
C            CALL FNDELV
C     I                 (XTAB, STDOUT,
C     O                  EFLAG, Z)
C          ELSEIF(ZCHAR.EQ.'          ') THEN
C            Z = -1.E30
C          ELSE
C            READ(ZCHAR,'(F10.0)',ERR=991) Z
C          ENDIF
 
          XVEC(NBN) = X
          ZVEC(NBN) = Z
          KA(NBN) = CA
          KD(NBN) = CD
          HLTAB(NBN) = HL
          AZMOUT = AZM
          AZM = AZM*1.745329E-2
          UVX(NBN) = SIN(AZM)
          UVY(NBN) = COS(AZM)
          COEFIN(NBN) = CF
          YCUT(NBN) = YC
          STDFLD(NBN) = STD
          KADJVEC(NBN) = KADJ
          IF(NAME.EQ.'   ') THEN
C           Set the nodeid.  
            IF(GISID_TO_NODEID.EQ.'YES') THEN
              IF(XTAB.GT.0) THEN
                CALL FNDGISID
     I                       (XTAB, STDOUT,
     O                        EFLAG, NAME)
              ENDIF
            ELSEIF(TABID_TO_NODEID.EQ.'YES') THEN
              NAME = TABID
            ENDIF
          ENDIF
            
          BNODID(NBN) = NAME
 
          GOTO 100
 
 120    CONTINUE

C       Make sure we have at least two nodes given on this 
C       branch.  There were cases where a single-node branch 
C       would pass all tests and would compute without warnings!
        IF(NBN.LT.OLD_NBN+2) THEN
          WRITE(STDOUT, 85) BNIN
          EFLAG = 1
        ENDIF
C       Check that the last node on the branch has a valid cross-
C       section table number. 
        IF(NSEC(NBN).LT.0) THEN
C         Invalid number got through! 
          WRITE(STDOUT,83) BNIN
          EFLAG = 1
        ENDIF

 
 
C       PROCESS ANY REQUEST FOR ADDING NODES FOR CONVERGENCE TESTING
        LAST = NBN
        FIRST = BRPT(3,BNUM)
        IF(ADDNOD.GT.0) THEN
C         NOTE: THE VALUES OF LAST AND NBN ARE CHANGED IN INSNOD.
C               ALL THE BRANCH VECTORS ARE CHANGED ALSO!
          CALL INSNOD
     I               (STDOUT, ADDNOD, MNBN, FIRST,
     M                LAST, NSEC, XVEC, ZVEC, KA, KD, HLTAB, UVX, UVY,
     M                COEFIN, YCUT, STDFLD, KADJVEC, BNODID,
     O                NBN)
        ENDIF
 
C       CLEAN UP FOR THIS BRANCH
C       UVX & UVY ARE MEANINGLESS AT FIRST NODE ON BRANCH
C       SO ARE KA, KD, AND CF
 
        BRPT(4,BNUM) = NBN
C       COMPUTE THE NODE NUMBER OF THE LAST NODE ON THE BRANCH
        BRPT(2,BNUM) = BRPT(1,BNUM) + BRPT(4,BNUM) - BRPT(3,BNUM)
 
        UVX(FIRST) = 0.
        UVY(FIRST) = 0.
        KA(FIRST) = 0.0
        KD(FIRST) = 0.0
        COEFIN(FIRST) = 0.0
 
C       ASSIGN INTERNAL EXTERIOR NODE NUMBERS AND EXTERNAL NAMES
C       IF THE INPUT IS IN THE NEW STYLE. It will always be so 
C       in this and later versions.  Old style is obsolete and not
C       supported.
        IF(ISTYLE.EQ.'NEW') THEN
C         INCREMENT THE EXTERIOR NODE NUMBER FOR THE UPSTREAM NODE
          ENODEN = ENODEN + 1
          INENUS(ENODEN) = MAKENN('U', BNIN)
          USENIN(BNIN) = ENODEN
          EXNODT(1,ENODEN) = -1
          EXNODT(2,ENODEN) = BRPT(3,BNUM)
          EXNODT(3,ENODEN) = BNUM
          EXNODT(4,ENODEN) = NSEC(BRPT(3,BNUM))
          ENODID(ENODEN) = BNODID(BRPT(3,BNUM))
          BRPT(5,BNUM) = ENODEN
C         INCREMENT THE EXTERIOR NODE NUMBER FOR THE DOWNSTREAM NODE
          ENODEN = ENODEN + 1
          INENUS(ENODEN) = MAKENN('D', BNIN)
          USENIN(BNIN+9999) = ENODEN
          EXNODT(1,ENODEN) = +1
          EXNODT(2,ENODEN) = BRPT(4,BNUM)
          EXNODT(3,ENODEN) = BNUM
          EXNODT(4,ENODEN) = NSEC(BRPT(4,BNUM))
          ENODID(ENODEN) = BNODID(BRPT(4,BNUM))
          BRPT(6,BNUM) = ENODEN
        ENDIF
 
C       Update the sum of flow-path lengths.  We are still in the 
C       user units for station here.
        QPATH_LENGTH = QPATH_LENGTH + ABS(XVEC(FIRST) - XVEC(LAST))


C       CHECK FOR REQUESTS FOR INTERPOLATION OF BOTTOM PROFILE
C       BEFORE CHECKING FOR REQUESTS FOR STATION AND BOTTOM
C       PROFILE.
C       Requests for interpolation are signaled by a value of
C       -1.e30.
C       AT A MINIMUM THE FIRST AND LAST NODE ON THE BRANCH MUST HAVE
C       PROFILE VALUES GIVEN.
 
        IF(ZVEC(FIRST).GT.-1.E30.AND.ZVEC(LAST).GE.-1.E30) THEN
          JZERO = 0
C         SCAN ALL NODES BUT THE FIRST FOR REQUESTS
          DO 2400 J=FIRST+1,LAST
            IF(ZVEC(J).LE.-1.E29) THEN
C             REQUEST FOUND- SAVE INDEX OF FIRST REQUEST
              IF(JZERO.EQ.0) THEN
                JZERO = J
              ENDIF
            ELSE
C             NO REQUEST AT THIS POINT.  CHECK FOR PREVIOUS REQUESTS
              IF(XVEC(J).LE.-1.E29) THEN
                WRITE(STDOUT,76) ZVEC(J), BNIN, J-FIRST+BRPT(1,BNUM)
                EFLAG = 1
              ENDIF
              IF(JZERO.GT.0) THEN
C               ONE OR MORE INTERPOLATION REQUESTS ARE OUTSTANDING.
C               JZERO POINTS TO THE FIRST REQUEST. JZERO-1 POINTS
C               TO THE PREVIOUS VALID STATION-PROFILE PAIR AND
C               J POINTS TO THE CURRENT VALID PAIR.
 
C               GET THE STATION AND PROFILE FROM THE PREVIOUS VALID
C               PAIR
 
                STATL = XVEC(JZERO-1)
                STDL = ZVEC(JZERO-1)
 
C               GET CURRENT VALID VALUE
 
                STATR = XVEC(J)
                STDR = ZVEC(J)
 
                IF(STATR.EQ.STATL) THEN
                  WRITE(STDOUT,54) BNIN, STATL
                  EFLAG = 1
                  FAC = SFAC
                ELSE
                  FAC = (STDR - STDL)/(STATR - STATL)
                ENDIF
                DO 2300 K=JZERO, J-1
                  IF(XVEC(K).GT.-1.E29) THEN
C                   Station is known value.
                    ZVEC(K) = STDL + (XVEC(K) - STATL)*FAC
                  ENDIF
 2300           CONTINUE
                JZERO = 0
              ENDIF
            ENDIF
 2400     CONTINUE
        ELSE
C         Problem here.
          IF(ZVEC(FIRST).EQ.-1.E30) THEN
            WRITE(STDOUT,78) BNIN
            EFLAG = 1
          ENDIF
          IF(ZVEC(LAST).EQ.-1.30) THEN
            WRITE(STDOUT,79)  BNIN
            EFLAG = 1
          ENDIF
        ENDIF
 
 
C        CHECK FOR REQUESTS FOR INTERPOLATION OF STATION AND
C        ELEVATION AND DO THE REQUESTS. NOTE: THE FIRST AND LAST
C        NODES ON A BRANCH ARE ASSUMED TO HAVE VALID VALUES
C        OF STATION AND ELEVATION.  THESE CANNOT BE CHECKED!
 
         JZERO = 0
C        SCAN ALL NODES BUT THE FIRST FOR REQUESTS
         DO 2000 J=FIRST+1,LAST
           IF(ZVEC(J).LE.-1.E29.AND.XVEC(J).LE.-1.E29) THEN
C            REQUEST FOUND- SAVE INDEX OF FIRST REQUEST
             IF(JZERO.EQ.0) THEN
               JZERO = J
             ENDIF
           ELSE
C            NO REQUEST AT THIS POINT.  CHECK FOR PREVIOUS REQUESTS
             IF(JZERO.GT.0) THEN
C              ONE OR MORE INTERPOLATION REQUESTS ARE OUTSTANDING.
C              JZERO POINTS TO THE FIRST REQUEST. JZERO-1 POINTS
C              TO THE PREVIOUS VALID STATION-ELEVATION PAIR AND
C              J POINTS TO THE CURRENT VALID PAIR.
 
C              GET THE FLOAT PNT FORM OF THE NUMBER OF INTERVALS
 
               FINT = FLOAT(J - JZERO + 1)
 
C              GET THE STATION AND ELEVATION FROM THE PREVIOUS VALID
C              STATION-ELEVATION PAIR
 
               STAT = XVEC(JZERO-1)
               ELEV = ZVEC(JZERO-1)
 
C              FIND THE CHANGE IN STATION AND ELEVATION
 
               DX = XVEC(J) - STAT
               DZ = ZVEC(J) - ELEV
 
               DO 1000 K=JZERO, J-1
                 FAC = FLOAT(K-JZERO+1)/FINT
                 XVEC(K) = STAT + DX*FAC
                 ZVEC(K) = ELEV + DZ*FAC
 1000          CONTINUE
               JZERO = 0
             ENDIF
           ENDIF
 2000    CONTINUE
 
 
C        CHECK FOR REQUESTS FOR INTERPOLATION OF STANDARD FLOOD
C        LEVEL.  NOTE: THE FIRST AND LAST
C        NODES ON A BRANCH ARE ASSUMED TO HAVE VALID VALUES
C        OF STANDARD FLOOD LEVEL
 
 
          IF(STDFLD(FIRST).NE.0.0) THEN
           JZERO = 0
C          SCAN ALL NODES BUT THE FIRST FOR REQUESTS
           DO 2200 J=FIRST+1,LAST
             IF(STDFLD(J).EQ.0.0) THEN
C              REQUEST FOUND- SAVE INDEX OF FIRST REQUEST
               IF(JZERO.EQ.0) THEN
                 JZERO = J
               ENDIF
             ELSE
C              NO REQUEST AT THIS POINT.  CHECK FOR PREVIOUS REQUESTS
               IF(JZERO.GT.0) THEN
C                ONE OR MORE INTERPOLATION REQUESTS ARE OUTSTANDING.
C                JZERO POINTS TO THE FIRST REQUEST. JZERO-1 POINTS
C                TO THE PREVIOUS VALID STATION-STANDARD FLOOD PAIR AND
C                J POINTS TO THE CURRENT VALID PAIR.
 
C                GET THE STATION AND STANDARD FLOOD FROM THE PREVIOUS VALID
C                PAIR
 
                 STATL = XVEC(JZERO-1)
                 STDL = STDFLD(JZERO-1)
 
C                GET CURRENT VALID VALUE
 
                 STATR = XVEC(J)
                 STDR = STDFLD(J)
 
                 IF(STATR.EQ.STATL) THEN
                   WRITE(STDOUT,54) BNIN, STATL
                   EFLAG = 1
                   FAC = SFAC
                 ELSE
                   FAC = (STDR - STDL)/(STATR - STATL)
                 ENDIF
 
                 DO 2100 K=JZERO, J-1
                   STDFLD(K) = STDL + (XVEC(K) - STATL)*FAC
 2100            CONTINUE
                 JZERO = 0
               ENDIF
             ENDIF
 2200      CONTINUE
         ENDIF

C        Check for request for conveyance adjustment factor. 
C        Note: The first and last nodes on a branch must have
C          positive values of the conveyance adjustment factor. 
 
 
          IF(KADJVEC(FIRST).NE.0.0) THEN
           JZERO = 0
C          SCAN ALL NODES BUT THE FIRST FOR REQUESTS
           DO 2350 J=FIRST+1,LAST
             IF(KADJVEC(J).EQ.0.0) THEN
C              REQUEST FOUND- SAVE INDEX OF FIRST REQUEST
               IF(JZERO.EQ.0) THEN
                 JZERO = J
               ENDIF
             ELSE
C              NO REQUEST AT THIS POINT.  CHECK FOR PREVIOUS REQUESTS
               IF(JZERO.GT.0) THEN
C                ONE OR MORE INTERPOLATION REQUESTS ARE OUTSTANDING.
C                JZERO POINTS TO THE FIRST REQUEST. JZERO-1 POINTS
C                TO THE PREVIOUS VALID STATION-STANDARD FLOOD PAIR AND
C                J POINTS TO THE CURRENT VALID PAIR.
 
C                GET THE STATION AND STANDARD FLOOD FROM THE PREVIOUS VALID
C                PAIR
 
                 STATL = XVEC(JZERO-1)
                 STDL = KADJVEC(JZERO-1)
 
C                GET CURRENT VALID VALUE
 
                 STATR = XVEC(J)
                 STDR = KADJVEC(J)
 
                 IF(STATR.EQ.STATL) THEN
                   WRITE(STDOUT,54) BNIN, STATL
                   EFLAG = 1
                   FAC = SFAC
                 ELSE
                   FAC = (STDR - STDL)/(STATR - STATL)
                 ENDIF
 
                 DO 2250 K=JZERO, J-1
                   KADJVEC(K) = STDL + (XVEC(K) - STATL)*FAC
 2250            CONTINUE
                 JZERO = 0
               ENDIF
             ENDIF
 2350      CONTINUE
         ENDIF

 
C        COMPUTE THE INLET COEFFICIENTS FOR SEWER INFLOWS
         IF(CFRATE.GT.0.0) THEN
           DO 3000 J=FIRST+1,LAST
C            AT THIS POINT ALL STATIONS ARE DEFINED
 
             IF(COEFIN(J).EQ.0.0) THEN
               COEFIN(J) = CFRATE*ABS(XVEC(J) - XVEC(J-1))
               IF(YCUT(J).EQ.0.0) THEN
                 WRITE(STDOUT,52) BRPT(1,BNUM) + J - FIRST
                 EFLAG = 1
               ENDIF
             ENDIF
 3000      CONTINUE
         ENDIF
 
C       Compute requests for interpolation of ground elevation
 
        IF(ZCFLAG.NE.0) THEN
          JZERO = 0
C         SCAN ALL NODES BUT THE FIRST FOR REQUESTS
          DO 3200 J=FIRST+1,LAST
            IF(YCUT(J).LE.-1.E29) THEN
C             REQUEST FOUND- SAVE INDEX OF FIRST REQUEST
              IF(JZERO.EQ.0) THEN
                JZERO = J
              ENDIF
            ELSE
C             NO REQUEST AT THIS POINT.  CHECK FOR PREVIOUS REQUESTS
              IF(JZERO.GT.0) THEN
C               ONE OR MORE INTERPOLATION REQUESTS ARE OUTSTANDING.
C               JZERO POINTS TO THE FIRST REQUEST. JZERO-1 POINTS
C               TO THE PREVIOUS VALID STATION-YCUT PAIR AND
C               J POINTS TO THE CURRENT VALID PAIR.
 
C               GET THE STATION AND YCUT FROM THE PREVIOUS VALID
C               PAIR
 
                STATL = XVEC(JZERO-1)
                STDL = YCUT(JZERO-1)
 
C               GET CURRENT VALID VALUE
 
                STATR = XVEC(J)
                STDR = YCUT(J)
 
                IF(STATR.EQ.STATL) THEN
                  WRITE(STDOUT,54) BNIN, STATL
                  EFLAG = 1
                  FAC = SFAC
                ELSE
                  FAC = (STDR - STDL)/(STATR - STATL)
                ENDIF
                DO 3100 K=JZERO, J-1
                  YCUT(K) = STDL + (XVEC(K) - STATL)*FAC
 3100           CONTINUE
                JZERO = 0
              ENDIF
            ENDIF
 3200     CONTINUE
 
C         Convert elevations to depths from invert
          DO 3300 J=FIRST+1,LAST
            YCUT(J) = YCUT(J) - ZVEC(J)
            IF(YCUT(J).LE.0.0) THEN
              WRITE(STDOUT,81) BRPT(1,BNUM) + J - FIRST, BNIN
              EFLAG = 1
            ENDIF
 3300     CONTINUE
 
C         Clear the initial value in the branch.
          YCUT(FIRST) = 0.0
        ENDIF

C       Set the station direction flag for this branch based
C       on the initial element.
        IF(XVEC(FIRST+1).GT.XVEC(FIRST)) THEN
          DIRECTION = 1
        ELSEIF(XVEC(FIRST+1).EQ.XVEC(FIRST)) THEN
          DIRECTION = 0
        ELSE
          DIRECTION = -1
        ENDIF
        NODE = BRPT(1,BNUM)

        IF(IDLEN.LT.6) IDLEN = 6
        IF(HLIDLEN.LT.6) HLIDLEN = 6
        WRITE(STDOUT,84) BLANK(1:IDLEN-5), BLANK(1:HLIDLEN-5)
        DO 4000 J=FIRST,LAST
          IF(NSEC(J).EQ.-1000000) THEN
            TABID = ' '
            TABID(IDLEN:IDLEN) = '-'
          ELSE
            TEMPC = GET_TABID(NSEC(J))
            IT = LENSTR(TEMPC)
            TABID = ' '
            TABID(IDLEN-IT+1:IDLEN) = TEMPC(1:IT)
          ENDIF
          IF(HLTAB(J).GT.0) THEN
            TEMPC = GET_TABID(HLTAB(J))
            IT = LENSTR(TEMPC)
            HLTABID = ' '
            HLTABID(HLIDLEN-IT+1:HLIDLEN) = TEMPC(1:IT)
          ELSE
            HLTABID = ' '
          ENDIF

          IF(J.GT.FIRST) THEN
            DX = XVEC(J) - XVEC(J-1)
          ELSE
            DX = 0.0
          ENDIF
            
          SELECT CASE(FTID)

          CASE(0)
            IF(DX.NE.0.0) THEN
              WRITE(DXOUT,'(F10.0)') DX
            ELSE
              DXOUT = ' '
            ENDIF
            WRITE(STDOUT,18000) NODE, BNODID(J), TABID(1:IDLEN), 
     A XVEC(J), ZVEC(J)+dz_for_output, KA(J), KD(J), HLTABID(1:HLIDLEN),
     B       AZMOUT, COEFIN(J), YCUT(J), STDFLD(J), KADJVEC(J), DXOUT
          CASE(1)
            IF(DX.NE.0.0) THEN
              WRITE(DXOUT,'(F10.1)') DX
            ELSE
              DXOUT = ' '
            ENDIF
            WRITE(STDOUT,18100) NODE, BNODID(J), TABID(1:IDLEN), 
     A XVEC(J), ZVEC(J)+dz_for_output, KA(J), KD(J), HLTABID(1:HLIDLEN),
     B       AZMOUT, COEFIN(J), YCUT(J), STDFLD(J), KADJVEC(J), DXOUT
          CASE(2)
            IF(DX.NE.0.0) THEN
              WRITE(DXOUT,'(F10.2)') DX
            ELSE
              DXOUT = ' '
            ENDIF
            WRITE(STDOUT,18200) NODE, BNODID(J), TABID(1:IDLEN), 
     A XVEC(J), ZVEC(J)+dz_for_output, KA(J), KD(J), HLTABID(1:HLIDLEN),
     B       AZMOUT, COEFIN(J), YCUT(J), STDFLD(J), KADJVEC(J), DXOUT
          CASE(3)
            IF(DX.NE.0.0) THEN
              WRITE(DXOUT,'(F10.3)') DX
            ELSE
              DXOUT = ' '
            ENDIF
            WRITE(STDOUT,18300) NODE, BNODID(J), TABID(1:IDLEN), 
     A XVEC(J), ZVEC(J)+dz_for_output, KA(J), KD(J), HLTABID(1:HLIDLEN),
     B       AZMOUT, COEFIN(J), YCUT(J), STDFLD(J), KADJVEC(J), DXOUT
          CASE DEFAULT
            IF(DX.NE.0.0) THEN
              WRITE(DXOUT,'(F10.4)') DX
            ELSE
              DXOUT = ' '
            ENDIF
            WRITE(STDOUT,18400) NODE, BNODID(J), TABID(1:IDLEN), 
     A XVEC(J), ZVEC(J)+dz_for_output, KA(J), KD(J), HLTABID(1:HLIDLEN),
     B       AZMOUT, COEFIN(J), YCUT(J), STDFLD(J), KADJVEC(J), DXOUT

          END SELECT


          IF(J.GT.FIRST) THEN
            IF(XVEC(J).GT.XVEC(J-1)) THEN
              LOCAL_DIRECTION = 1
            ELSEIF(XVEC(J).EQ.XVEC(J-1)) THEN
              LOCAL_DIRECTION = 0
            ELSE
              LOCAL_DIRECTION = -1
            ENDIF
            IF(LOCAL_DIRECTION.NE.DIRECTION) THEN
C             Stationing changes direction.
              EFLAG = 1
              WRITE(STDOUT,82) NODE
            ENDIF
          ENDIF  
          NODE = NODE + 1
 4000   CONTINUE
        DO 4010 J=FIRST,LAST
          XVEC(J) = SFAC*XVEC(J)
 4010   CONTINUE
 140  CONTINUE
C     Drop through indicates allocated space is exhausted.
      CALL KIL 
     I            (29,
     M             BNUM, EFLAG)                                     
      STOP 'Abnormal stop.  Error(s) found.'


9000  CONTINUE
      WRITE(STDOUT,86) QPATH_LENGTH

      RETURN
 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE
        STOP 'Abnormal stop: errors found.'
      END
C     ***********
C     *         *
C     * FBTYPE  *
C     *         *
C     ***********

      CHARACTER*5 FUNCTION FBTYPE(ARG)

C     Translate numeric value for type of forced boundary to a 
C     string.

      CHARACTER*4 ARG

C     Local

      CHARACTER*4 TEMP

      EXTERNAL STRIP_L_BLANKS
C***********************************************************************
      TEMP = ARG
      CALL STRIP_L_BLANKS(
     M                     TEMP)
      IF(TEMP.EQ.'1') THEN
        FBTYPE = ' Flow'
      ELSE
        FBTYPE = ' Elev'
      ENDIF
      RETURN
      END 
C
C
C
      SUBROUTINE FIND_TABIDL(
     I                       N,
     O                       TABID, L)

C     Find the Table Id and its actual length.

      IMPLICIT NONE
      INTEGER L, N
      CHARACTER TABID*16

C     External names
      INTEGER LENSTR
      CHARACTER GET_TABID*16
      EXTERNAL GET_TABID, LENSTR

C     Local

      CHARACTER TEMP*16
C***********************************************************************
      TEMP = GET_TABID(N)
      TABID =TEMP(1:LENSTR(TEMP))
      RETURN
      END
c
c 
c 
      subroutine chk_dummy_branches
     i                             (stdout, nex, exnodt, inenus,
     o                              hit)

c     Seek to find free nodes not connected properly..  
      IMPLICIT NONE

      include 'arsize.prm'

      integer stdout, nex, hit
      integer exnodt(9,MNEX)
      character inenus(MNEX)*5

c     Local
      integer i

c     **********************Formats*************************************
50    format(' Exterior node: ',a5,' has no dummy branch.') 
c***********************************************************************
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
c 
c     Here are the items of information that we will use to sniff out the
c     errant nodes:
c 
c     exnodt(2,i) is 0 if the node is on a dummy branch. 
c     exnodt(4,i) should then be > 0 and give the index in 
c                 exnodt of the other node
      hit = 0
      do i=1,nex
        if(exnodt(2,i) == 0) then
c         We think we have a node on a dummy branch.
          if(exnodt(4,i) < 1 .or. exnodt(4,i) > nex) then
c           Something is wrong with this exterior node
            write(stdout,50) inenus(i)
            hit = hit + 1
          endif
        endif
      end do 
      
      return
      end
   
C
C
C
      SUBROUTINE   EXIN
     I                 (IN, STDOUT, MFT, NBRA, MLEMC, USBRIN, 
     I                  INBRUS, NEW_FORM, dz_for_output,
     M                  EFLAG, EXNODT, USENIN, ENODEN,
     O                  NEX, EPT, EMC, QE2, YE2, LDCALL, 
     O                  NENTRY, ADD, CHKSQ, INENUS)
 
C     + + + PURPOSE + + +
C     Input the network-matrix control table.
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, ENODEN, EPT, IN, LDCALL, STDOUT, MFT, MLEMC, NBRA,
     A        NENTRY, NEW_FORM, NEX
      INTEGER ADD(MNETRY), CHKSQ(MNETRY), EMC(MLEMC),
     A        EXNODT(9,MNEX), INBRUS(NBRA), USBRIN(9999),
     B        USENIN(-9999:19998)
      REAL QE2(MNEX), YE2(MNEX), dz_for_output
      CHARACTER INENUS(MNEX)*5
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     STDOUT   - Fortran unit number for user output and messages
C     MFT    - maximum function table pointer value.  Same as maximum
C               function table number
C     NEX    - number of exterior nodes in the model
C     NBRA   - number of branches in the model
C     MLEMC  - maximum length of EMC(*)
C     USBRIN - conversion from user branch number to internal branch
C               number
C     INBRUS - conversion from internal branch number to user branch
C               number
C     NEW_FORM - flag for the new format for input: 0-old, <>0-new
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     EXNODT - exterior node table.  Contains the following items
C              for each exterior node.
C              Row   Content
C               1    sign of the node
C               2    pointer into vectors for nodes on a branch
C               3    descriptive code: if -1 then a reservoir;
C                    if  0 then not on a branch and not a reservoir;
C                    if > 0 then a branch number
C 
C               4    pointer to a cross section table if on a branch, 
C                    to storage table if a reservoir, to other node if
C                    a dummy branch
C               5    gives the variable number(in the system matrix) for
C                    the flow at the exterior node. Also a junction
C                    pointer in initial processing of input
C     USENIN - conversion from user exterior node number to internal
C               exterior node number
C     ENODEN - internal exterior-node number
C     EPT    - pointer into EMC(*)
C     EMC    - vector containing coded form of the Matrix Control Input
C     QE2    - flow at exterior nodes at end of time step
C     YE2    - depths at exterior nodes at end of time step
C     LDCALL - flag to signal that subroutine LOAD must be called
C     NENTRY - number of entries in Network Matrix input
C     ADD    - Address of entry in EMC, that is, the index in EMC
C               at which a matrix control specification begins.
C     CHKSQ  - gives number of times an exterior node is used as a flow
C               node in the network matrix input
C     INENUS - conversion from internal exterior node number to user
C              exterior node designation
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'gatcom.cmn'
      INCLUDE 'macro.cmn'
      INCLUDE 'ts_mngt.prm'
      INCLUDE 'code14.cmn'
      INCLUDE 'eqsum.cmn'

C     + + + LOCAL PARAMETERS + + +
      INTEGER NEGOFF
      REAL ASUR, KFAC
      PARAMETER(KFAC=1.E-8, ASUR=1., NEGOFF=1)
 
C     + + + LOCAL VARIABLES + + +
      INTEGER CODE, I, IDUM, IENTRY, II, IOFF, IP, J, LN, M, MCODE,
     A        MLOC, MODE, N2EQ, NGTMP, NT, USBR, STATUS, hit
      INTEGER N(10)
      REAL F(5), RDUM, HDATUM, datum_shift
      CHARACTER  NAME*16, NC(10)*5, NC_LONG(10)*16,
     A          LONG_LINE*196, FC(5)*4, CHR10*10
 
C     + + + EQUIVALENCES + + +
      EQUIVALENCE (RDUM,IDUM)
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + EXTERNAL FUNCTIONS + + +
      CHARACTER GETTOK*5, FBTYPE*5
      INTEGER LENSTR

C     + + + EXTERNAL NAMES + + +
      EXTERNAL CNVRTN, GETTOK, inline, KIL, KILC, LSATAB, POP_LINE,
     A         LENSTR, FIND_TABIDL, FIND_HDD_FROM_TABN
 
C     + + + INPUT FORMATS + + +
 20   FORMAT(5X,16X,6I4,F7.0)
 24   FORMAT(I5,10A4,5F7.0)
 
C     + + + OUTPUT FORMATS + + +
 23   FORMAT(/,' Code=',I5,' Input order#=',I5)
 26   FORMAT(4X,'Branch=',I5)
 27   FORMAT(4X,'The',I5,' nodes for sum of Q are:',9A6)
 28   FORMAT(4X,'Elevation equality between nodes ',A5,' and ',A5)
 29   FORMAT(4X,'Type=',A5,' Ups node=',A5,' Dir=',A5,' Q node=',A5)
 30   FORMAT(4X,'Type=',A5,' Ups head node=',A5,' Dwns head node=',A5,
     1       ' Q node=',A5)
 31   FORMAT(4X,'Forced value at boundary: ',4X,/,
     1'  Type=',A5,'   Ups node=',A5,' Dir=',A5,
     2' TsId=',A5,/,' Value=',F10.2,4X,' Factor=',F5.2)
 32   FORMAT(4X,'Reservoir node=',A5,
     1           ' Storage table Id=',A,/,
     3           4X,'Inflow node=',A5,' Slope factor=',1PE10.4)
 33   FORMAT(4X,'Critical depth at node=',A5)
 34   FORMAT(4X,'Forced value at boundary: ',4X,/,
     1'  Type=',A5,'   Ups node=',A5,' Dir=',A5,
     2' Time-series Id= ',A,'  Value=',F10.2,/,4X,' Factor=',F5.2)
 35   FORMAT(4X,'Energy head equality between nodes ',A5,' AND ',A5)
 36   FORMAT(4X,'Weir coef. Tab Id=',A,' Weir elev.=',A10,
     1        ' Weir length=',F10.1)
 37   FORMAT(4X,'Flow tab Id=',A,' Base elev.=',A10)
 38   FORMAT(4X,'Slope source=',I5,' Input slope=',F10.5)
 39   FORMAT(4X,'Q vs. Head tab Id=',A,' P vs. Time tab Id=',A,
     1        ' Base elev.=',A10)
 40   FORMAT(4X,'Q vs. Head tab Id=',A,' Oper. block#=',A,
     1        ' Base elev.=',A10)
 41   FORMAT(4X,'Transition sign=',I5,
     1        ' Critical flow tab Id=',A,/,
     2        4X,'Loss factor for pos flow=',F5.2,
     3        ' Loss factor for neg flow=',F5.2,/,
     4        4X,'Base elev. for critical table=',F10.2)
 42   FORMAT(4X,'TabId for pos flow=',A,' TabId for sub. corr.=',
     1       A,/,4X,'TabId for neg flow=',A,
     2       ' TabId for sub.corr.=',A,/,
     3       4X,'Key(0-elev; 1-flow)=',I5,' Switch node=',A5,
     4       /,4X,'Base elev.=',A10,
     3       ' Dist. for slope=',F10.1,/,4X,'Pump rate=',F10.1,
     4       ' Inlet elev.=',F10.2,' Turnon elev.=',F10.2)
 43   FORMAT(4X,' Q vs. Head table Id=',A,' Controlling level vs.',
     1     ' Time source=',A,/,4X,'Limiting Q vs. Controlling level',
     2     ' Table Id=',A,/,4X,'Elevation of zero head=',F10.2)
 44   FORMAT(4X,'Variable-head, variable-speed pump: ',A5,/,
     1       4X,'Flow direction=',I5,' TabId for pump curve=',A,
     A       ' TabId for losses=',A,/,4X,'TabId for outlet loss=',A,
     B       ' Source for pump control=',A,/,4X,'Outlet elev=',F10.2,
     C       ' Outlet area=',F10.2,' Inlet elev=',F10.2,/,4X,
     D       'Factor on source velocity head=',F5.1,
     E       ' Factor on target velocity head=',F5.1)
 46   FORMAT(4X,'TabId for loss coef for + direction=',A,/
     1 4X,'TabId for loss coef for - direction=',A,/
     2 4X,'TabId for area vs depth for bridge opening=',A,/
     3 4X,'TabId for flow over road vs head +dir=',A,/
     4 4X,'TabId for flow over road vs head -dir=',A,/
     5 4X,'TabId for flow ratio vs submergence ratio= ',A,/
     6 4X,'Bridge opening area= ',F10.1,/,
     6 4X,'Max elev of bridge opening=',F10.1,/,
     7 4X,'Discharge coef for fully submerged flow= ',F10.3,/,
     8 4X,'Elev for computing head on road= ',F10.2)
 52   FORMAT(/,' *ERR:122* Upstream node:',A5,' for Code 5 Type 5',
     1       ' must be on downstream end of a branch.')
 54   FORMAT(/,' *ERR:123* Downstream node:',A5,' for Code 5 Type 5',
     1       ' must be on upstream end of a branch.')
 55   FORMAT(4X,'Impulse+momentum equality between nodes ',A5,' AND '
     A       ,A5)
 56   FORMAT(4X,'TabId for pos flow=',A,' TabId for neg flow=',A,
     2 /,4X,'Source for capacity fraction=',A,' Base elev.=',A10,
     3 /,4X,'TabId for variable base elevation=',A, 
     4      ' Structure name=',a)
 57   FORMAT(/,' *ERR:124* flow node for Code 5 Type 5 must be the',
     1       ' upstream node')
 58   FORMAT(4X,' Abrupt expansion.  TabId for critical flow=',A)
 59   FORMAT(4X,'Variable-elevation overflow gate: ',A5,/,4X,
     1       ' Oper. code=',A ,' TabId for crest elev=',A,
     2       ' TabId for C pos=',A,
     3       /,4X,' TabId for C neg=',A,' TabId for sub. corr.=',A,
     4       /, ' Weir length=',F9.2,' Vel head factor=',F7.2)
 60   FORMAT(4X,'Match average of elevations at nodes:',2A6,' with',
     A        /,4X,'elevation at node:',A5,' using weight of:',F6.2,
     B        ' on node:',A5)
 61   FORMAT(4X,' Oper. code=',A,' Datum for heads=',F10.2,
     A       ' Maximum gate opening=',F10.2,/,4X,' Factor on Q=',F10.3)
 62   FORMAT(/,' *ERR:166* Weight coefficient for averaging elevation',
     A   ' is invalid.',/,10X,' must be >=0 and <=1.0. Weight=',F6.2)
 63   FORMAT(4X,'Variable-opening underflow gate: ',A5,/,
     A       4X,' Operation code=',A,' TabId for positive',
     B       ' flow=',A,/,4X,' TabId for negative flow=',A,
     C       ' TabId for gate-efficiency factor=',A,/,
     D       ' Exterior-node id for gate-efficiency factor=',A5,/,
     E       ' Datum for heads=',F10.2,/,4X,' Max. gate opening=',F10.2)
 64   FORMAT(4X,'Momentum or energy balance between nodes: ', A5,
     A     ' and ', A5,/,4X,'Factor for energy loss=',F6.2)
 65   FORMAT(/,'*ERR:239* Maximum gate opening=',F10.2,' <=0 invalid.')
 66   FORMAT(4X,'Side-weir flow between nodes:', A5,' and ',A5,' at',
     A ' node:',A5,'.',/,4X,'TabId for outflow=',A,' TabId for inflow=',
     B   A,/,4X,'TabId for adjustment factor=',A, 
     C   /,4X,'Weight for average elevation=',F6.2,
     C        ' Crest elevation=',A10)
 67   FORMAT(/,' *ERR:256* Loss coefficient for mechanical energy loss',
     A    ' is invalid.',/,10X,' must be >=0 and <=1.0.')
 68   FORMAT(4X,'Side-weir flow between nodes:', A5,' and ',A5,' at',
     A' node:',A5,'.',/,4X,'TabId for outflow=',A,' TabId for inflow=',
     B A,/,4X,' TabId for adjustment factor=',A, 
     C' TabId for rate of crest change=',A
     D   ,/,4X,'Weight for average elevation=',F6.2,
     E   ' Crest elevation=',A10,' Toe elevation=',F10.3)
 69   FORMAT(4X,'Side node=',A5,' Effective entry angle=',F5.1,' deg.')
 70   FORMAT(' *WRN:26* Computational problems likely: Cutoff',
     A ' elevation=',F10.2,/,10X,'should be less than elevation for',
     B ' head=',F10.2)
 72   FORMAT(' *ERR:179* Branch number=',I5,' does not appear in NMC',
     A       ' input.')
 73   FORMAT('    Base elev  shifted ',f8.3,
     a        ' relative to datum in table.')
 74   FORMAT(' *ERR:180* Expected ',I5,' entries in NMC input but',
     A   ' found',I5,' entries.')
 76   FORMAT(' *ERR:185* Exterior node=',A5,' never appears in',
     A       ' Codes 2, 4, 6, or 8.')
 78   FORMAT(' *ERR:181* Exterior node=',A5,' appears in codes',
     A       ' 2 or 6 more than once.')
 86   FORMAT(4X,'Dummy branch: Ups node=',A5,' Dns node=',A5,/,4X,
     A       'Slope factor=',1PE10.4,' Surface area=',0PF10.1)
 88   FORMAT(' *ERR:236* Outlet area for pump=',F10.2,' <= 0 invalid.')
 89   FORMAT(/,' *ERR:257* Gate or pump name=',A16,' already in use.')
 90   FORMAT(/,' *ERR:91* Number of side nodes=',I5,' > 2.')
 91   FORMAT(/,' *ERR:402* Head datum missing from instruction.')
92    FORMAT(/,' *ERR:403*  You have used the TAB option when the',
     A' function table is unknown.',/,'  Please move the ',
     B' FUNCTION-TABLES block ahead of',
     A ' the BRANCH-DESCRIPTION block.')
93    FORMAT(/,' Number of exterior nodes found=',I5)
94    FORMAT
     A(/,' *ERR:410* Number of exterior nodes=',I5,
     B  ' is odd. Must be even.')
95    format(
     a' *ERR:XXX* Add dummy branches to correct the errant free nodes.')

 2000 FORMAT(/,' *ERR:83* Node for channel control depth ', A5,
     A           ' not on a branch')
 2005 FORMAT(/,' *ERR:84* Channel control node',A5,
     1      ' not at downstream end of branch')
 3003 FORMAT(/,' *ERR:121* Bottom slope for normal depth < 0. S=',F10.4)
C***********************************************************************
c     Clear the count for each code
      do i=1,15
        eqsum_knt(i) = 0
      end do

C     SET QE2 TO ZERO FOR FLOW NODE CHECKING
C     ALSO SET CHKSQ(*) TO ZERO FOR COUNTING OCCURRENCES OF NODES
C     IN CODES 2, 4, 6, 8 FOR ERROR CHECKING
 
      DO 111 J=1,MNEX
        QE2(J) = 0.0
C        CHKSQ(J) = 0
C        CHKSQ(NEX+J) = 0
 111  CONTINUE
      DO 113 J=1,MNETRY
        CHKSQ(J) = 0
113   CONTINUE
C     SET YE2 TO ZERO FOR BRANCH CODE CHECKING
 
      DO 112 J=1,NBRA
        YE2(J) = 0.0
 112  CONTINUE

C     Clear or set various counters and limits
      CODE14_PRESENT = 0 
      MCODE = 15
      IENTRY = 0
      N2EQ = 0
      NGATE = 0
 
C     ESTABLISH STANDARD OFFSETS FOR EACH CODE IN EMC
 
C     EMC(1) RESERVED FOR POINTER TO FIRST CODE IN EMC. NEGOFF GIVES
C     THE NUMBER OF NEGATIVE OFFSETS TO RESERVE FOR EACH ENTRY IN
C     EMC(*).
 
      EPT = MCODE + 2 + NEGOFF
      EMC(1) = EPT
      EMC(1+1) = 2  + NEGOFF
      EMC(2+1) = 2  + NEGOFF
      EMC(3+1) = 3  + NEGOFF
      EMC(4+1) = 11  + NEGOFF
      EMC(5+1) = 6  + NEGOFF
      EMC(6+1) = 11 + NEGOFF
      EMC(7+1) = 10  + NEGOFF
      EMC(8+1) = 2  + NEGOFF
      EMC(9+1) = 10 + NEGOFF
      EMC(10+1) = 3 + NEGOFF
      EMC(11+1) = 3 + NEGOFF
      EMC(12+1) = 5 + NEGOFF
      EMC(13+1) = 11 + NEGOFF
      EMC(14+1) = 11 + NEGOFF
      EMC(15+1) = 6 + NEGOFF
 1000 CONTINUE
      IF(NEW_FORM.EQ.0) THEN
        WRITE(STDOUT,*) ' Bug in EXIN. NEW_FORM=0'
        STOP 'Abnormal stop.  Bug found.'
      ELSE
C       New format for Network Matrix input.
        IF(MACRO_STACK_TOP.EQ.0) THEN
          CALL inline
     I                (IN, STDOUT,
     O                 LONG_LINE)
        ELSE
C         Get the next line from the top of the
C         macro stack.
          CALL POP_LINE(LONG_LINE)
        ENDIF         

        MODE = 0
        CALL GET_CODE_NC_F(STDOUT, MODE, LONG_LINE,
     O                     CODE, NC, NC_LONG, F, FC, EFLAG)
        IF(EFLAG.GT.0) THEN
          STOP 'Abnormal stop: errors found.'
        ENDIF
        IF(CODE.EQ.999) THEN
C         Macro found and has been expanded on the macro stack.
C         Go to top of major loop and get the next line of code.
C         Flags have been set so that the first line of the just
C         expanded macro should be processed next
          GOTO 8001
        ENDIF
      ENDIF

C     SAVE ADDRESS OF THIS ENTRY IN THE ADDRESS VECTOR
 
      IENTRY = IENTRY + 1
      ADD(IENTRY) = EPT
      IF(CODE.EQ.-1) GOTO 8500
 
      WRITE(STDOUT,23) CODE, IENTRY
 
         IF(CODE.LE.0.OR.CODE.GT.MCODE) CALL KIL
     I                                           (11,
     M                                            CODE, EFLAG)
 
C        Convert the exterior node id's to internal numbers, convert integers,
C        and find or assign internal table numbers.
         CALL CNVRTN
     I              (STDOUT, CODE, NC, NC_LONG,
     M               USENIN, ENODEN,
     O               EFLAG, INENUS, N)
 
 
C        STORE ITEMS THAT ARE AT THE SAME OFFSET FOR ALL CODE OPTIONS.
 
         EMC(EPT-1) = IENTRY
         EMC(EPT) = CODE

c        Count the code numbers
         eqsum_knt(code) = eqsum_knt(code) + 1
         GOTO(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15),CODE
           WRITE(STDOUT,*) ' *BUG:11* INVALID EMC CODE IN EXIN. CODE=',
     A                   CODE
           STOP 'Abnormal stop: errors found.'
 
 
C     CODE FOR A BRANCH
 
 1       CONTINUE
C           N(1) = user branch number; N(2) = time-series indicator for
C           rainfall on water surface; N(3) = time-series indicator for
C           evaporation on water surface
C           Note: N(2) and N(3) are input values but they are not stored as
C           part of the instruction.  They only set values in the time-series
C           management system.  The effect of rainfall and evaporation on
C           the branch water surface is represented as a lateral inflow.

C           COUNT THE NUMBER OF EMC ENTRIES THAT WILL GENERATE 2 OR
C           MORE EQUATIONS IN THE MATRIX
 
            N2EQ = N2EQ + 1
 
            USBR = N(1)
            WRITE(STDOUT,26) USBR
            NT = USBRIN(USBR)
            IF(NT.EQ.0) THEN
              CALL KIL
     I                 (15,
     M                  USBR, EFLAG)
              STOP 'Abnormal stop: errors found.'
            ENDIF
            IF((EPT+2).GT.MLEMC) CALL KIL
     I                                    (13,
     M                                     EPT, EFLAG)
            IF(YE2(NT).GT.0.0) THEN
C             BRANCH NUMBER HAS ALREADY APPEARED IN INPUT
              CALL KIL
     I                 (51,
     M                  USBR, EFLAG)
            ELSE
              YE2(NT) = 1.0
            ENDIF
            EMC(EPT+1) = NT

C           Process possible time-series references.  
            CALL TS_CHK_AND_UPDATE(STDOUT, NEW_FORM, NC_LONG(2), 
     I                             BRA_RAIN, NT, 
     M                             N(2), LDCALL, EFLAG)
            CALL TS_CHK_AND_UPDATE(STDOUT, NEW_FORM, NC_LONG(3), 
     I                             BRA_EVAP, NT, 
     M                             N(3), LDCALL, EFLAG)

            
            IF(NC_LONG(2).NE.' '.OR.NC_LONG(3).NE.' ') THEN
              IF(N(2).GT.0) THEN
                WRITE(STDOUT,'(4X,''TS TABID for rainfall='',A)') 
     A                                               NC_LONG(2)
              ELSEIF(N(2).LT.0) THEN
                WRITE(STDOUT,'(4X,''TS File ref. for rainfall='',A)')
     A                                               NC_LONG(2)
              ENDIF
              IF(N(3).GT.0) THEN
                WRITE(STDOUT,'(4X,''TS TABID for evaporation='',A)') 
     A                                               NC_LONG(3)
              ELSEIF(N(3).LT.0) THEN
                WRITE(STDOUT,'(4X,''TS File ref. for evaporation='',A)')
     A                         NC_LONG(3)
              ENDIF
            ENDIF



            GOTO 8000
 
C     CODE FOR SUM OF FLOW RATES EQUALS ZERO
 
 2       CONTINUE
 
C     VALIDITY IS CHECKED IN CNVRTN
 
            M = N(1)
            WRITE(STDOUT,27) M, (NC(J), J=2,M+1)
 
C     STORE THE INFORMATION
            IF((EPT+M+2).GT.MLEMC) CALL KIL
     I                                      (13,
     M                                       EPT, EFLAG)
            EMC(EPT+1) = M
               DO 220 J=1,M
               EMC(EPT+J+1) = N(J+1)
               II = ABS(N(J+1))
               CHKSQ(2*(II-1) + 1) = CHKSQ(2*(II-1) + 1) + 1
 220           CONTINUE
            EPT = EPT+M
            GOTO 8000
 
C     ELEVATION EQUALITY
 
 3       CONTINUE
            WRITE(STDOUT,28) NC(1), NC(2)
 
 
            IF((EPT+3).GT.MLEMC) CALL KIL
     I                                    (13,
     M                                     EPT, EFLAG)
            EMC(EPT+1) = N(1)
            EMC(EPT+2) = N(2)
            GOTO 8000
 
C     ONE-NODE HEAD-DISCHARGE
 
 4       CONTINUE
 
C        N(1) = TYPE; N(2) = HEAD; N(3) = DIRECTION; N(4) = FLOW NODE
C        CHECK AND REPORT STANDARD INFOR FOR CODE = 4.
 
         WRITE(STDOUT,29) (NC(J), J=1,4)
         IF(N(1).LT.1.OR.N(1).GT.6) CALL KIL
     I                                       (7,
     M                                        N(1), EFLAG)
 
C        CHECK FOR DUPLICATE USE OF FLOW NODE
 
         IF(QE2(N(4)).NE.0.0) CALL KILC
     I                                  (NC(4), -43,
     M                                   EFLAG)
         QE2(N(4)) = 10.
C        COUNT THE NUMBER OF OCCURRENCES OF THE FLOW NODE.
 
         CHKSQ(2*(N(4)-1) + 2) = CHKSQ(2*(N(4)-1) + 2) + 1
 
C        INITIAL CHECKING COMPLETE-STORE STANDARD INFORMATION
 
         IF((EPT+5).GT.MLEMC) CALL KIL
     I                                 (13,
     M                                  EPT, EFLAG)
           DO 400 J=1,4
             EMC(EPT+J) = N(J)
 400       CONTINUE
 
C        BRANCH ON N(1) AND COMPLETE PROCESSING
         I = N(1)
         GOTO(401, 402, 403, 404, 405, 406),I
           WRITE(STDOUT,*) ' *BUG:12* INVALID CODE=4 TYPE IN',
     A                    ' EXIN. TYPE=', I
           STOP 'Abnormal stop: errors found.'
 
 401       CONTINUE
C          N(5) = TABLE NUMBER; F(1) = ELEVATION; F(2) = WEIR LENGTH
           IF(FC(1).EQ.'NONE'.OR.FC(1).EQ.'LKUP') THEN
             WRITE(STDOUT,91) 
             EFLAG = 1
             F(1) = 3.E30
             CHR10 = 'missing'
           ELSE 
             WRITE(CHR10,'(F10.3)') F(1) +dz_for_output
           ENDIF
 
           WRITE(STDOUT,36) NC_LONG(5), CHR10, F(2)

           IF(EPT+8.GT.MLEMC) CALL KIL
     I                                 (13,
     M                                  EPT, EFLAG)
           EMC(EPT+5) = N(5)
           RDUM = F(1)
           EMC(EPT+6) = IDUM
           RDUM = F(2)
           EMC(EPT+7) = IDUM
           GOTO 499
 
 402       CONTINUE
 
C            N(5) = TABLE NUMBER; F(1) = ELEVATION
 
             IF(FC(1).EQ.'NONE'.OR.FC(1).EQ.'LKUP') THEN
               WRITE(STDOUT,91) 
               EFLAG = 1
               F(1) = 3.E30
               CHR10 = 'missing'
             ELSE 
               WRITE(CHR10,'(F10.3)') F(1) + dz_for_output
             ENDIF
             WRITE(STDOUT,37) NC_LONG(5), CHR10
             IF(EPT+7.GT.MLEMC) CALL KIL
     I                                   (13,
     M                                    EPT, EFLAG)
             EMC(EPT+5) = N(5)
             RDUM = F(1)
             EMC(EPT+6) = IDUM
             GOTO 499
 
 403       CONTINUE
 
C       N(5)  = SLOPE SOURCE INDICATOR; F(1) = BOTTOM SLOPE FROM
C       INPUT(IF ANY).
 
        WRITE(STDOUT,38) N(5), F(1)
        IF(N(5).NE.-1.AND.N(5).NE.0.AND.N(5).NE.1)
     1          CALL KIL
     I                   (45,
     M                    N(5), EFLAG)
 
 
        IF(N(5).NE.-1) GOTO 430
          IF(F(1).GT.0.0) GOTO 430
            WRITE(STDOUT,3003) F(1)
            EFLAG = 1
 430      CONTINUE
 
        IF(EPT+7.GT.MLEMC) CALL KIL
     I                              (13,
     M                               EPT, EFLAG)

C       Check that the node for head is on a branch and if
C       slope is to be computed in FEQ, N(5) >=0, it must 
C       be at the downstream end of a branch.
        IF(EXNODT(3,N(2)).LE.0) THEN
          WRITE(STDOUT,2000) NC(2)
          EFLAG = 1
        ELSE
          IF(N(5).GE.0) THEN
            IF(EXNODT(1,N(2)).LT.0) THEN
              WRITE(STDOUT,2005) NC(2)
              EFLAG = 1
            ENDIF
          ENDIF
        ENDIF  
      
        EMC(EPT+5) = N(5)
        RDUM = F(1)
        EMC(EPT+6) = IDUM
        GOTO 499
 
 
 404       CONTINUE
 
C            N(5) = TABLE NUMBER; N(6) = TABLE NUMBER; F(1) = ELEVATION
 
             IF(FC(1).EQ.'NONE'.OR.FC(1).EQ.'LKUP') THEN
               WRITE(STDOUT,91) 
               EFLAG = 1
               F(1) = 3.E30
               CHR10 = 'missing'
             ELSE 
               WRITE(CHR10,'(F10.3)') F(1) + dz_for_output
             ENDIF

             WRITE(STDOUT,39) NC_LONG(5), NC_LONG(6), CHR10
 
             IF(EPT+8.GT.MLEMC) CALL KIL
     I                                   (13,
     M                                    EPT, EFLAG)
             EMC(EPT+5) = N(5)
             EMC(EPT+6) = N(6)
             RDUM = F(1)
             EMC(EPT+7) = IDUM
             GOTO 499
 
 405       CONTINUE
 
 
C            N(5) = TABLE NUMBER; N(6) = OPERATION BLOCK NUMBER
C            F(1) = ELEVATION
             IF(FC(1).EQ.'NONE'.OR.FC(1).EQ.'LKUP') THEN
               WRITE(STDOUT,91) 
               EFLAG = 1
               F(1) = 3.E30
               CHR10 = 'missing'
             ELSE 
               WRITE(CHR10,'(F10.3)') F(1) + dz_for_output
             ENDIF
 
             WRITE(STDOUT,40) NC_LONG(5), NC_LONG(6), CHR10
             IF(N(6).LE.0) CALL KIL
     I                              (41,
     M                               N(6), EFLAG)
             IF(EPT+10.GT.MLEMC) CALL KIL
     I                                   (13,
     M                                    EPT, EFLAG)
             EMC(EPT+5) = N(5)
             EMC(EPT+6) = N(6)
             RDUM = F(1)
             EMC(EPT+7) = IDUM
 
C            EMC(EPT+8) IS NEEDED BY OPERATION BLOCK FOR STORAGE
C            OF OPENING FRACTION.  EMC(EPT+9) must contain a 
C            floating point zero to be compatible with sluice
C            gate monitoring. 
             RDUM = 0.0
             EMC(EPT+9) = IDUM
 
C            Check for a name in the optional name field.
             IF(NC_LONG(10).NE.' ') THEN
C              Take value to be a name for the pump.
               NAME = NC_LONG(10)
 
C              Check if pump name is already in the table. If it is
C              in the table it is an error otherwise add it to the table.
               NGTMP = NGATE
               CALL LSATAB
     I                    (STDOUT, NAME, MNGATE,
     M                     GNAME, NGATE,
     O                     IP, EFLAG)
               IF(NGATE.EQ.NGTMP) THEN
C                The new name did not increase the size of the table.
C                Therefore the name was in the table and is not new!
                 WRITE(STDOUT,89) NAME
                 EFLAG = 1
               ENDIF
C              Store the pointer to the location of NAME in GNAME(*).
               EMC(EPT+10) = IP
             ELSE
               EMC(EPT+10) = 0
             ENDIF

             GOTO 499
 
 406       CONTINUE
C            N(5) = RATING TABLE NUMBER, N(6) = SOURCE FOR CONTROLLING
C            LEVEL.  N(6) > 0: TIME SERIES TABLE; N(6) < 0 FILE IN
C            CONNECTION FORMAT. N(7)= TABLE CONVERTING CONTROLLING LEVEL
C            INTO FLOWRATE
C            TABLE NUMBER, F(1) = ELEVATION OF ZERO HEAD FOR RATING
C            TABLE

             WRITE(STDOUT,43) NC_LONG(5), NC_LONG(6), NC_LONG(7), 
     a                   F(1) + dz_for_output
 
             EMC(EPT+5) = N(5)
             EMC(EPT+6) = N(6)
             EMC(EPT+7) = N(7)
 
             RDUM = F(1)
             EMC(EPT+8) = IDUM
 
             GOTO 499
 499       CONTINUE
           GOTO 8000
 
 5       CONTINUE
 
C        N(1) = TYPE; N(2) = UPN; N(3) = DNN; N(4) = FLOW NODE;
 
         WRITE(STDOUT,30) NC(1), NC(2), NC(3), NC(4)
 
C         USE EMC(EPT+5) TO FLAG THE SIGN GIVEN WITH THE
C         FLOW NODE. Old option from pre-version 7 days. 
C         Sign is always set as positive.
 
          EMC(EPT+5) = 1
 
         IF(N(1).LE.0.OR.N(1).GT.9) CALL KIL
     I                                       (7,
     M                                        N(1), EFLAG)
         IF(N(4).NE.N(2).AND.N(4).NE.N(3)) CALL KILC
     I                                               (NC(4), -23,
     M                                                EFLAG)
         IF(N(2).EQ.N(3)) CALL KILC
     I                              (NC(2), -22,
     M                               EFLAG)
         IF(EPT+5.GT.MLEMC) CALL KIL
     I                               (13,
     M                                EPT, EFLAG)
 
C        CHECK ON DUPLICATE USE OF A NODE AS A FLOW NODE
 
         IF(QE2(N(4)).NE.0.0) CALL KILC
     I                                  (NC(4), -43,
     M                                   EFLAG)
         QE2(N(4)) = 10.
 
           DO 530 J=1,4
           EMC(EPT+J) = N(J)
 530     CONTINUE
 
C        BRANCH ON N(1) AND COMPLETE PROCESSING
         I = N(1)
         GOTO(501, 502, 503, 504, 505, 506, 507, 508, 509),I
           WRITE(STDOUT,*) ' *BUG:13* INVALID CODE=5 TYPE IN',
     A                     ' EXIN. TYPE=', I
           STOP 'Abnormal stop: errors found.'
 
 501       CONTINUE
 
C            EXPANSION-CONTRACTION WITH CRITICAL DEPTH POSSIBLE
 
C            N(5) = TRANSITION SIGN; N((6) = TABLE# FOR
C            COMPUTING CRITICAL FLOW; F(1) = LOSS FACTOR FOR FLOW FROM
C            UPSTREAM NODE TO DOWNSTREAM NODE; F(2) = LOSS FACTOR FOR
C            FLOW FROM DOWNSTREAM NODE TO UPSTREAM NODE; F(3) =  BASE
C            ELEVATION FOR DEFINING DEPTH AT THE CRITICAL SECTION.
 
             WRITE(STDOUT,41) N(5), NC_LONG(6), F(1), F(2), 
     a                 F(3) + dz_for_output
 
             IF(N(6).LE.0.OR.N(6).GT.MFT) CALL KIL
     I                                             (9,
     M                                              N(6), EFLAG)
             IF(EPT+EMC(CODE+1)+CD5TY1.GT.MLEMC)
     A                                    CALL KIL
     I                                             (13,
     M                                              EPT, EFLAG)
C            NOTE THAT EMC(EPT+5) IS USED ABOVE
 
             EMC(EPT+6) = N(5)
             EMC(EPT+7) = N(6)
             DO 535 J=1,3
               RDUM = F(J)
               EMC(EPT+8+J) = IDUM
 535         CONTINUE
 
             EPT = EPT + CD5TY1
 
             GOTO 599
 
 502       CONTINUE
 
C            BIDIRECTIONAL FLOW GIVEN BY ONE OR MORE TABLES OR
C            BY CONVEYANCE TABLE AND SLOPE COMPUTED BY THE PROGRAM.
C            SIMPLE PUMP OPERATION IS ALSO POSSIBLE IF BDF FROM
C            TABLES IS SELECTED.
 
C            N(5) = TABLE NUMBER FOR UPSTREAM TO DOWNSTREAM FLOW
C            VERSUS HEAD; N(6) = TABLE NUMBER FOR SUBMERGENCE
C            CORRECTION FOR TABLE GIVEN BY N(5); N(7) = TABLE NUMBER
C            FOR DOWNSTREAM TO UPSTREAM FLOW VERSUS HEAD; N(8) =
C            TABLE NUMBER FOR SUBMERGENCE CORRECTION FOR TABLE
C            GIVEN BY N(7); F(1) = BASE ELEVATION FOR COMPUTING
C            HEAD; F(2) = DISTANCE TO USE IN COMPUTING SLOPE IF
C            SLOPE OPTION IS SELECTED.  SLOPE OPTION IS SELECTED
C            WHEN BOTH SUBMERGENCE TABLE NUMBERS ARE ZERO.
 
C            N(9) = KEY. KEY = 0 IF TURNON IS ELEVATION, KEY = 1
C             IF TURNON IS FLOWRATE
C            N(10) = SWITCH NODE. IF FLOW AT NODE IS > 0 THEN PUMP
C                    IF ON MUST BE TURN OFF AND IF OFF SHOULD NOT BE
C                    TURNED ON BY OTHER RULES.
C            F(3) = PUMPING RATE FOR PUMP.
C            F(4) = INLET ELEVATION FOR PUMP.  INLET SIDE.
C            F(5) = TURNON LEVEL(FLOW OR ELEV) FOR PUMP. OUTLET SIDE.
             IF(FC(1).EQ.'NONE') THEN
               WRITE(STDOUT,91) 
               EFLAG = 1
               F(1) = 3.E30
               CHR10 = 'missing'
             ELSE 
               WRITE(CHR10,'(F10.3)') F(1) + dz_for_output
             ENDIF


             WRITE(STDOUT,42) (NC_LONG(J), J=5,8), N(9), NC(10), 
     A                                           CHR10, (F(J), J=2,5)
 
             IF(EPT+EMC(CODE+1)+CD5TY2.GT.MLEMC)
     A                                    CALL KIL
     I                                             (13,
     M                                              EPT, EFLAG)
             IF(N(5).LE.0.OR.N(5).GT.MFT) CALL KIL
     I                                             (9,
     M                                              N(5), EFLAG)
 
             DO 540 J=6,8
               IF(N(J).LT.0.OR.N(J).GT.MFT) CALL KIL
     I                                               (9,
     M                                                N(J), EFLAG)
 540         CONTINUE
 
             DO 545 J=5,8
               EMC(EPT+J+1) = N(J)
 545         CONTINUE
 
             DO 546 J=1,5
               RDUM = F(J)
               EMC(EPT+9+J) = IDUM
 546         CONTINUE
 
             EMC(EPT+16) = N(9)
             EMC(EPT+17) = N(10)
 
             EPT = EPT + CD5TY2
 
             IF(N(9).EQ.0.AND.F(5).GE.F(1)) THEN
C              CUTOFF ELEVATION > ELEVATION FOR HEAD DOES NOT MAKE SENSE
               WRITE(STDOUT,70) F(5), F(1)
             ENDIF
             GOTO 599
 
 503    CONTINUE
 
C         Pump with variable head and optional conduit and
C         entrance and exit losses
 
C         N(5)-flow direction: 1 is U to D and -1 is D to U
C         N(6)-Table number for the pump curve.  Flow through the
C              pump for given head.  Defined for the standard or
C              base speed if the pump is variable speed.
C         N(7)-Table number for the losses at the inlet, in the
C              inlet conduit, and in the outlet conduit.  Taken
C              as a function of the flow through the pump.
C         N(8)-Table number for the coefficient on the velocity
C              head difference between the end of the outlet
C              conduit and the target node.  Is a function of the
C              depth of submergence of the outlet.  Must be 1.0 at
C              zero submergence.
C         N(9)-Table number for pump speed as a function of time if
C              < 0.  Operation block number controlling the pump if > 0.
C         NC(10) - optional name for pump for output to special output
C                   file.
C         F(1)- elevation of the outlet conduit.   Used to determine
C               submergence of the outlet.
C         F(2)- area of the outlet conduit when flowing full.  The pump
C               is assumed to keep the outlet conduit flowing full
C               at all speeds.
C         F(3)- elevation of the inlet conduit.  Flow is zero if
C               the elevation at the inlet is below the inlet.
C         F(4)- factor on velocity head at the inlet.  Usually 0 or 1.
C         F(5)- factor on velocity head at the outlet.  Usually 0 or 1.
C         Note: FEQ will force the factors on velocity head to be 0 if
C               the node involved is a free node.  Otherwise the
C               value given by the user is used.
 
          WRITE(STDOUT,44) NC(10), N(5), (NC_LONG(J), J=6,9), 
     a             f(1) + dz_for_output, f(2), f(3) + dz_for_output,
     b             f(4), f(5)
c     A                    (F(J), J=1,5)
 
          IF(EPT+EMC(CODE+1)+CD5TY3.GT.MLEMC) CALL KIL
     I                                                 (13,
     M                                                  EPT, EFLAG)
C         Make sure the pump curve is present
          IF(N(6).LE.0) CALL KIL
     I                           (6,
     M                            N(6), EFLAG)
 
C         Make sure outlet area is > 0.0
 
          IF(F(2).LE.0.0) THEN
            WRITE(STDOUT,88) F(2)
            F(2) = 1.0
            EFLAG = 1
          ENDIF
 
          DO 531 J=5,9
            EMC(EPT+J+1) = N(J)
 531      CONTINUE
 
C         Store the direction in another location so that 2-way
C         pumps are able to report the pump direction in 
C         special output. 
          EMC(EPT+22) = EMC(EPT+6)

          DO 532 J=1,5
            RDUM = F(J)
            EMC(EPT+J+12) = IDUM
 532      CONTINUE
 
C         Check for a name in the optional name field.
          IF(NC_LONG(10).NE.' ') THEN
C           Take value to be a name for the pump.
            NAME = NC_LONG(10)
 
C           Check if pump name is already in the table. If it is
C           in the table it is an error otherwise add it to the table.
            NGTMP = NGATE
            CALL LSATAB
     I                 (STDOUT, NAME, MNGATE,
     M                  GNAME, NGATE,
     O                  IP, EFLAG)
            IF(NGATE.EQ.NGTMP) THEN
C             The new name did not increase the size of the table.
C             Therefore the name was in the table and is not new!
              WRITE(STDOUT,89) NAME
              EFLAG = 1
            ENDIF
C           Store the pointer to the location of NAME in GNAME(*).
            EMC(EPT+21) = IP
          ELSE
            EMC(EPT+21) = 0
          ENDIF
 
          EPT = EPT + CD5TY3
          GOTO 599
 
 504      CONTINUE
 
C         BRIDGE / FLOW OVER THE ROADWAY POSSIBLE
C         N(5) - TABLE# OF HEAD LOSS COEF VS DEPTH + FLOW
C         N(6) - TABLE# OF HEAD LOSS COEF VS DEPTH - FLOW
C         N(7) - TABLE# OF AREA VS DEPTH FOR BRIDGE OPENING
C         N(8) - TABLE# OF FLOW OVER ROAD VS HEAD  + FLOW
C         N(9) - TABLE# OF FLOW OVER ROAD VS HEAD  - FLOW
C         N(10)- TABLE# GIVING FLOW RATIO VS SUBMERGENCE RATIO
C         F(1) - AREA OF BRIDGE OPENING AT FULL FLOW
C         F(2) - MAX ELEV OF BRIDGE OPENING
C         F(3) - DISCHARGE COEF FOR FULLY SUBMERGED FLOW
C         F(4) - ELEV FOR COMPUTING HEAD OVER ROADWAY

          WRITE(STDOUT,46) (NC_LONG(J), J=5,10), (F(J), J=1,4)
 
 
          IF(EPT+EMC(CODE+1)+CD5TY4.GT.MLEMC)
     A                                     CALL KIL
     I                                              (13,
     M                                               EPT, EFLAG)
          IF(N(6).EQ.0) N(6) = N(5)
          IF(N(9).EQ.0) N(9) = N(8)
          DO 565 J=5,10
            IF(J.NE.6) THEN
              IF(N(J).LE.0.OR.N(J).GT.MFT) CALL KIL
     I                                              (9,
     M                                               N(J), EFLAG)
            ENDIF
 565      CONTINUE
          DO 567 J = 5,10
             EMC(EPT+1+J) = N(J)
 567      CONTINUE
          DO 569 J=1,4
              RDUM = F(J)
              EMC(EPT+11+J) = IDUM
 569      CONTINUE
 
          EPT = EPT + CD5TY4
          GOTO 599
 
 505      CONTINUE
 
C           ABRUPT EXPANSION-
C           N(5) = TABLE NUMBER OF CRITICAL FLOW TABLE
C           CHECK RESTRICTIONS UNIQUE
C           TO THIS TYPE.
 
            WRITE(STDOUT,58) NC_LONG(5)
 
            IF(EXNODT(3,N(2)).LE.0.OR.EXNODT(1,N(2)).NE.1) THEN
              WRITE(STDOUT,52) N(2)
              EFLAG = 1
            ENDIF
            IF(EXNODT(3,N(3)).LE.0.OR.EXNODT(1,N(3)).NE.-1) THEN
              WRITE(STDOUT,54) N(3)
              EFLAG = 1
            ENDIF
 
            IF(N(4).NE.N(2)) THEN
              WRITE(STDOUT,57)
              EFLAG = 1
            ENDIF
 
            IF(N(5).LE.0.OR.N(5).GT.MFT) CALL KIL
     I                                            (9,
     M                                             N(5), EFLAG)
 
            IF(EPT+EMC(CODE+1)+CD5TY5.GT.MLEMC)
     A                                    CALL KIL
     I                                             (13,
     M                                              EPT, EFLAG)
 
            EMC(EPT+8) = N(5)
 
            EPT = EPT + CD5TY5
            GOTO 599
 
 506      CONTINUE
C           TWO-D FLOW TABLE WITH ELEVATION AS ARGUMENTS
C
C           N(5) = TABLE NUMBER FOR FLOW FROM U TO D
C           N(6) = TABLE NUMBER FOR FLOW FROM D TO U
C           N(7) =  if > 0 then an operation control block number
c                   if < 0 then a table id for a time-series table
c                   giving the multiplying factor on the flow. 
c                   Only makes sense if flow tables are of type 13
C                  TO USE TO MULTIPLY THE VALUE DERIVED FROM THE TABLES.
C                  IF ZERO FACTOR IS TAKEN AS 1.0
C           N(8) = OPTIONAL TABLE NUMBER FOR TABLE GIVING THE ELEVATION
C                  FOR COMPUTING HEAD VERSUS TIME.  IF ZERO THE ELEVATION
C                  FOR COMPUTING HEAD IS THE VALUE IN F(1)
C           N(9) = Name for structure when it is dynamically varied with 
c                  an operation control block
C           N(10) = IF GT 0 THEN INDICATES A CONTINUATION LINE FOLLOWS
C                   THE CONTINUATION LINE WILL HAVE ONLY N(5:10), AND
C                   F(1) ON IT IN THE SAME FORMAT AS THE FIRST LINE OF
C                   INPUT FOR THIS TYPE.  THIS ALLOWS MULTIPLE TABLES
C                   FOR THE FLOW BETWEEN THE TWO NODES.
C           F(1) = ELEVATION FOR COMPUTING HEADS
 
C         Establish the head datum
          datum_shift = 0.0
          IF(FC(1).EQ.'LKUP') THEN
            CALL FIND_HDD_FROM_TABN(
     I                             N(5), STDOUT,
     O                             STATUS, HDATUM)
            IF(STATUS.EQ.1) THEN
c             Add increment.  f(1) is 0.0 if none was given
              datum_shift = f(1)
              F(1) = datum_shift + HDATUM
              WRITE(CHR10,'(F10.3)') f(1) + dz_for_output
            ELSE
              CHR10 = 'from table'
              F(1) = 2.E30
            ENDIF
          ELSE
            IF(FC(1).EQ.'NONE') THEN
              WRITE(STDOUT,91) 
              EFLAG = 1
              F(1) = 3.E30
              CHR10 = 'missing'
            ELSE 
              WRITE(CHR10,'(F10.3)') F(1) + dz_for_output
            ENDIF
          ENDIF

          MLOC = EPT + 6
          WRITE(STDOUT,56) NC_LONG(5), NC_LONG(6), NC_LONG(7), CHR10, 
     A                     NC_LONG(8), nc_long(9)
          if(datum_shift.ne.0.0) then
            write(stdout,73) datum_shift
          endif

          IF(CHR10.EQ.'from table') THEN
            WRITE(STDOUT,92)
            EFLAG = 1
          ENDIF
          M = 1
          IOFF = 0
 560      CONTINUE
 
            IF(EPT+EMC(CODE+1)+1+M*CD5TY6.GT.MLEMC)
     A                                     CALL KIL
     I                                              (13,
     M                                               EPT, EFLAG)
 
            EMC(EPT + IOFF + 7) = N(5)
            EMC(EPT + IOFF + 8) = N(6)
            EMC(EPT + IOFF + 9) = N(7)
            EMC(EPT + IOFF + 10) = N(8)

c           22 Jan 2007: try the TRANSFER function
            EMC(EPT + IOFF + 11) = TRANSFER(F(1), IDUM)

c            RDUM = F(1)
c            EMC(EPT + IOFF + 11) = IDUM
c           The following line is needed to force g95 0.91 of Jan 9, 2007
c           to properly process the information in the preceding statements.
c           The stored value of F(1) is incorrect in at least one critcal 
c           instance if this superfluous write is not here!
c            write(long_line,'(f10.0,i10,i10)')  rdum, idum, ept+ioff+11

c           Set the pointer into the gate-name table. If 
c           no gate name was given this value is zero and the 
c           table contains a blank entry at an index of 0!
            EMC(EPT + IOFF + 12) = n(9)
c           Set the opening fraction to 1.0
            rdum = 1.0
            EMC(EPT + IOFF + 13) = idum
c           Set the extra location required to zero
            rdum = 0.0
            EMC(EPT + IOFF + 14) = idum
            
c           
 
            IF(N(10).GT.0) THEN
C             New format for Network Matrix input.
              IF(MACRO_STACK_TOP.EQ.0) THEN
                CALL inline
     I                     (IN, STDOUT,
     O                      LONG_LINE)
              ELSE
C               Get the next line from the top of the
C               macro stack.
                LONG_LINE = MACRO_STACK(MACRO_STACK_TOP)
                MACRO_STACK_TOP = MACRO_STACK_TOP - 1
              ENDIF         
              MODE = 1
              CALL GET_CODE_NC_F(STDOUT, MODE, LONG_LINE,
     O                           CODE, NC, NC_LONG, F, FC, EFLAG)
              IF(EFLAG.GT.0) THEN
                STOP 'Abnormal stop: errors found.'
              ENDIF
C             Do fields not converted in GET_CODE_NC_F
              CALL DOCODE_5_6(
     I                        STDOUT, NC_LONG,
     O                        EFLAG, N)
C             Get the head datum
              IF(FC(1).EQ.'LKUP') THEN
                CALL FIND_HDD_FROM_TABN(
     I                           N(5), STDOUT,
     O                           STATUS, HDATUM)
                IF(STATUS.EQ.1) THEN
c                 Add increment.  f(1) is 0.0 if none was given
                  datum_shift = f(1)
                  F(1) = datum_shift + HDATUM
                  WRITE(CHR10,'(F10.3)') f(1) + dz_for_output
c                  WRITE(CHR10,'(F10.3)') HDATUM
c                  F(1) = f(1) + HDATUM
                ELSE
                  CHR10 = 'from table'
                  F(1) = 2.E30
                  
                ENDIF
              ELSE
                IF(FC(1).EQ.'NONE') THEN
                  WRITE(STDOUT,91) 
                  EFLAG = 1
                  F(1) = 3.E30
                  CHR10 = 'missing'
                ELSE 
                  WRITE(CHR10,'(F10.3)') F(1) + dz_for_output
                ENDIF
              ENDIF
              M = M + 1
              WRITE(STDOUT,'(''   M = '',I5)') M
              WRITE(STDOUT,56) NC_LONG(5), NC_LONG(6), NC_LONG(7), 
     A                         CHR10, NC_LONG(8), nc_long(9)
              IF(CHR10.EQ.'from table') THEN
                WRITE(STDOUT,92)
                EFLAG = 1
              ENDIF
              IOFF = IOFF + CD5TY6
              GOTO 560
            ENDIF
 
C         SAVE THE COUNT OF TABLE SETS
          EMC(MLOC) = M
          EPT = EPT + 1 + IOFF + CD5TY6
          GOTO 599
 
 507       CONTINUE
 
C            BIDIRECTIONAL FLOW OVER A WEIR WITH VARIABLE HEIGHT
C            AND DISCHARGE COEFFICIENT
 
 
C            N(5) = OPERATION BLOCK NUMBER OR NEGATIVE OF
C            TABLE NUMBER GIVING THE OPENING FRACTION AS
C            A FUNCTION OF TIME; N(6) = TABLE NUMBER
C            OF THE TABLE GIVING THE ELEVATION OF THE WEIR CREST
C            VS. P; N(7)= TABLE NUMBER OF TABLE GIVING C VS. P
C            FOR POSITIVE FLOW; N(8) = TABLE NUMBER OF TABLE GIVING
C            C VS. P FOR NEGATIVE FLOW; N(9)= TABLE NUMBER OF TABLE
C            GIVING SUMERGENCE CORRECTION FOR BOTH DIRECTIONS;
C            NC(10)- optional name for the gate.
C            F(1) = WEIR LENGTH; AND F(2) = VELOCITY HEAD FACTOR
C            FOR THE VELOCITY HEAD COMPUTED FROM THE AVERAGE VELOCITY.
 
             WRITE(STDOUT,59) NC(10), (NC_LONG(J), J=5,9), (F(J), J=1,2)
 
             IF(EPT+EMC(CODE+1)+CD5TY7.GT.MLEMC)
     A                                    CALL KIL
     I                                             (13,
     M                                              EPT, EFLAG)
 
             DO 575 J=6,9
               EMC(EPT+J+1) = N(J)
 575         CONTINUE
 
             EMC(EPT+6) = N(5)
 
             DO 576 J=1,2
               RDUM = F(J)
               EMC(EPT+10+J) = IDUM
 576         CONTINUE
 
             IF(NC_LONG(10).NE.' ') THEN
C              Take to be name for the gate.
               NAME = NC_LONG(10)
C              Check if gate name is already in the table. If it is
C              in the table it is an error otherwise add it to the table.
               NGTMP = NGATE
               CALL LSATAB
     I                    (STDOUT, NAME, MNGATE,
     M                     GNAME, NGATE,
     O                     IP, EFLAG)
               IF(NGATE.EQ.NGTMP) THEN
C                The new name did not increase the size of the table.
C                Therefore the name was in the table and is not new!
                 WRITE(STDOUT,89) NAME
                 EFLAG = 1
               ENDIF
C              Store the pointer to the location of NAME in GNAME(*).
               EMC(EPT+15) = IP
             ELSE
               EMC(EPT+15) = 0
             ENDIF
C            Force EPT+14 slot to hold a FP 0 to avoid conflict with
C            the weir-flow condition through underflow gates. 
             RDUM = 0.0
             EMC(EPT+14) = IDUM
 
             EPT = EPT + CD5TY7
             GOTO 599
 
 508      CONTINUE
C           MCHENRY SLUICE GATES ON THE FOX RIVER BELOW FOX CHAIN OF
C           LAKES.
 
C            N(5) = OPERATION BLOCK NUMBER OR NEGATIVE OF
C            TABLE NUMBER GIVING THE OPENING FRACTION AS
C            A FUNCTION OF TIME.
C            F(1) = DATUM FOR HEADS
C            F(2) = MAXIMUM GATE OPENING.  USED TO CONVERT THE
C                   FRACTION OF GATE OPENING WHEN USING AN OPERATION
C                   BLOCK TO A GATE OPENING.
C            F(3) = MULTIPLIER ON THE FLOWS TO ALLOW USE OF
C                   MCHENRY RATING FOR ROUGH ESTIMATES OF OTHER
C                   GATES.  DEFAULT VALUE IS 1.0 IF THE FIELD IS
C                   0.0 OR IS LEFT BLANK.
             IF(F(3).LE.0.0) F(3) = 1.0
             WRITE(STDOUT,61) NC_LONG(5), (F(J), J=1,3)
 
             IF(EPT+EMC(CODE+1)+CD5TY8.GT.MLEMC)
     A                                    CALL KIL
     I                                             (13,
     M                                              EPT, EFLAG)
 
             EMC(EPT+6) = N(5)
             EMC(EPT+7) = 0
             DO 586 J=1,2
               RDUM = F(J)
               EMC(EPT+7+J) = IDUM
 586         CONTINUE

C            Force slot one beyond opening fraction to 0.0
             RDUM = 0.0
             EMC(EPT+11) = IDUM
             RDUM = F(3)
             EMC(EPT+12) = IDUM
 
             IF(F(2).LE.0) THEN
               WRITE(STDOUT,65) F(2)
               EFLAG = 1
             ENDIF
 
             EPT = EPT + CD5TY8
             GOTO 599
 
 509       CONTINUE
 
C            Generic gate
 
C            N(5) = OPERATION BLOCK NUMBER OR NEGATIVE OF
C            TABLE NUMBER GIVING THE OPENING FRACTION AS
C            A FUNCTION OF TIME
C            NC(6) = 5-character gate id.
C            N(7) = table number of type 15 for flow u to d
C            N(8) = table number of type 15 for flow d to u
C            N(9) = table number for gate-efficiency table.  
C                   should be type 2, 3, or 4.
C            N(10)= exterior node containing the flow used to
C                   lookup the gate efficiency factor.
C            F(1) = sill elevation for the gate, datum for heads
C            F(2) = maximum gate opening.
 
             IF(FC(1).EQ.'NONE') THEN
               WRITE(STDOUT,91) 
               EFLAG = 1
               F(1) = 3.E30
               CHR10 = 'missing'
             ELSE 
               WRITE(CHR10,'(F10.3)') F(1) + dz_for_output
             ENDIF

             WRITE(STDOUT,63) NC(6), NC_LONG(5), NC_LONG(7), 
     A                        NC_LONG(8), NC_LONG(9), NC(10),
     B                        F(1), F(2)
 
             IF(EPT+EMC(CODE+1)+CD5TY9.GT.MLEMC)
     A                                    CALL KIL
     I                                             (13,
     M                                              EPT, EFLAG)
 
             EMC(EPT+6) = N(5)
 
             EMC(EPT+7) = 0
             IF(NC_LONG(6).NE.' ') THEN
               NAME = NC_LONG(6)
 
C              Check if gate name is already in the table. If it is
C              in the table it is an error otherwise add it to the table.
               NGTMP = NGATE
               CALL LSATAB
     I                    (STDOUT, NAME, MNGATE,
     M                     GNAME, NGATE,
     O                     IP, EFLAG)
               IF(NGATE.EQ.NGTMP) THEN
C                The new name did not increase the size of the table.
C                Therefore the name was in the table and is not new!
                 WRITE(STDOUT,89) NAME
                 EFLAG = 1
               ENDIF
C              Store the pointer to the location of NAME in GNAME(*).
               EMC(EPT+10) = IP
             ELSE
               EMC(EPT+10) = 0
             ENDIF
             EMC(EPT+8) = N(7)
             EMC(EPT+9) = N(8)
 
             DO 596 J=1,2
               RDUM = F(J)
               EMC(EPT+10+J) = IDUM
 596         CONTINUE
 
             IF(F(2).LE.0) THEN
               WRITE(STDOUT,65) F(2)
               EFLAG = 1
             ENDIF
C            EPT + 13 is used for storing the opening fraction for
C            the gate.  EPT + 14 is used for storing the gate opening
C            when weir flow is active.  It is used to bring the gate
C            close to the water so that gate movement time is kept
C            within reasonable bounds. 

C            Check for the gate-efficiency factor table.
             IF(N(9).GT.0) THEN
C              A gate-efficiency factor table is present. 
               EMC(EPT+15) = N(9)
               EMC(EPT+16) = N(10)
             ELSE
               EMC(EPT+15) = 0
               EMC(EPT+16) = 0
             ENDIF
    
 
             EPT = EPT + CD5TY9
 
             GOTO 599
 
 
 599       CONTINUE
           GOTO 8000
 
C     FORCED BOUNDARY
 
 6      CONTINUE
 
C         N(1)=TYPE; N(2)=NODE; N(3)=DIRECTION; N(4)=time series
C         source; N(5)=optional time-seris table giving factor on the
C         value applied at the boundary
C         F(1)=FLOW IF GIVEN, F(2)= factor on flow
 
          IF(F(2).EQ.0.0) F(2) = 1.0
          IF(NEW_FORM.EQ.0) THEN 
            WRITE(STDOUT,31) FBTYPE(NC(1)),(NC(J), J=2,4), F(1), F(2)
          ELSE
            WRITE(STDOUT,34) FBTYPE(NC_LONG(1)(1:4)),(NC_LONG(J),J=2,4),
     A                       F(1), F(2)
          ENDIF
 
          IF(N(3).NE.1.AND.N(3).NE.-1) CALL KIL
     I                                          (50,
     M                                           N(3), EFLAG)
 
          IF(N(1).LT.1.OR.N(1).GT.2) CALL KIL
     I                                        (16,
     M                                         N(1), EFLAG)

          CALL TS_CHK_AND_UPDATE(STDOUT, NEW_FORM, NC_LONG(4), 
     I                           FORCED_BDY, EPT+6, 
     M                           N(4), LDCALL, EFLAG)

C         CHECK FOR DUPLICATE USE OF FLOW NODE.  INCLUDE STAGE
C         AS A FLOW NODE BECAUSE ONLY ONE VALUE CAN BE FORCED.
 
          IF(QE2(N(2)).NE.0.0) CALL KILC
     I                                   (NC(2), -43,
     M                                    EFLAG)
          QE2(N(2)) = 10.
 
          CHKSQ(2*(N(2)-1) + 1) = CHKSQ(2*(N(2)-1) + 1) + 1
          IF(EPT+9.GT.MLEMC) CALL KIL
     I                                (13,
     M                                 EPT, EFLAG)
 
          DO 600 J=1,4
            EMC(EPT+J) = N(J)
 600      CONTINUE
 
C         Remember nodes that are involved with type 2
          IF(N(1).EQ.2) THEN
            EXNODT(9,N(2)) = 62
          ENDIF
 
C         STORE THE STEADY FLOW- EPT+5 RESERVED FOR FLOW STATE
 
          RDUM = F(1)
C         EPT +6 is the location in which the flow/or elevation
C         at the boundary node is placed.  If it is flow, there
C         may be two sources for flow: a time series of some
C         sort AND inflow from tributary area to the boundary
C         node.  ONLY ONE of these two sources can be used
C         for a node.  In the case of no time series then
C         a constant value is applied.  That value is stored 
C         in EPT + 8 and serves as the minimum flow at any time.
C         We have several cases. 

C         1. Constant flow given and no tributary area. 
C              There are two cases: Positive flow and negative
C              flow.  If the flow is positive we can set EPT+6 to
C              zero and EPT+8 to the constant value.  EPT+6 will
C              not be changed because there is no time series input
C              and there is no tributary area assigned to this boundary
C              node.  Then the value in EPT+6 will always be less than
C              the value in EPT+8 and the flow will always be EPT+8.
C              However, if the flow is negative, this will fail. 
C              A value of zero in EPT+6 will be larger than the negative
C              value in EPT+8 and the flow at the boundary will be zero.
C              It does not make sense to give a negative flow at 
C              boundary node if it has tributary area attached to 
C              it.  Therefore, if the constant flow is negative
C              EPT+6 should match the value in EPT+8.
C              
C         2. Constant flow given and tributary area. 
C             The flow in EPT + 6 will be set to the flow from
C             the delay reservoir that MUST exist at this
C             boundary node.  Again the flow in EPT + 8 will
C             provide the minimum value at the boundary node. 

C         3. A time series, either in a function table or in
C            a file is given.  Then EPT + 6 will be set to the
C            time series value.  Again the flow in EPT + 8 
C            will provide the minimum value at the boundary node. 


          IF(N(4).EQ.0.AND.F(1).LT.0) THEN
            EMC(EPT+6) = IDUM
          ELSE
            EMC(EPT+6) = 0
          ENDIF
 
C         STORE STEADY FLOW VALUE IN ADDITIONAL LOCATION FOR
C         USE IN HANDLING BASE FLOW PROBLEMS. EPT+7
C         RESERVED FOR PREVIOUS FLOW STATE.
 
          EMC(EPT+8) = IDUM
C         STORE THE ADJUSTMENT FACTOR
          RDUM = F(2)
          EMC(EPT+9) = IDUM
 
C         Store the table number for the adjusting factor table
          EMC(EPT+10) = N(5)
          GOTO 8000
 
C     LEVEL POOL RESERVOIR
 
 7       CONTINUE
         N2EQ = N2EQ + 1
 
C        N(1) = NODE NUMBER; N(2) = STORAGE TABLE NUMBER;
C        N(3) = NUMBER OF INFLOW NODES; N(4) = INFLOW NODE NUMBER
C        N(5) = time-series indicator for rainfall on surface
C        N(6) =  time-series indicator for evaporation on surface
C        Note: N(5) and N(6) are input values but they are not stored as
C        part of the instruction.  They only set values in the time-series
C        management system.  The effect of rainfall on a reservoir surface 
C        is stored in EMC(EPT+8).   The effect of evaporation on a reservoir
C        surface is stored in EMC(EPT+9).  Too many complications
C        in accessing lateral inflow because not all reservoirs will have
C        lateral inflow.

C        F(1) = KINEMATIC FACTOR FOR INDUCING A SMALL SLOPE ON THE
C               SURFACE FOR NON-ZERO FLOWS.  DEFAULT IS KFAC
C        IN THIS VERSION N(3) MUST BE 1!
            M = N(3)
            IF(M.NE.1) CALL KIL
     I                          (17,
     M                           M, EFLAG)
            IF(F(1).LE.0.0) THEN
              F(1) = KFAC
            ENDIF
            WRITE(STDOUT,32) NC(1), NC_LONG(2), NC(4),
     A                F(1)
            IF(NC_LONG(5).NE.' '.OR.NC_LONG(3).NE.' ') THEN
              IF(N(5).GT.0) THEN
                WRITE(STDOUT,'(4X,''TS TABID for rainfall='',A)') 
     A                                               NC_LONG(5)
              ELSEIF(N(5).LT.0) THEN
                WRITE(STDOUT,'(4X,''TS File ref. for rainfall='',A)')
     A                                               NC_LONG(5)
              ENDIF
              IF(N(6).GT.0) THEN
                WRITE(STDOUT,'(4X,''TS TABID for evaporation='',A)') 
     A                                               NC_LONG(6)
              ELSEIF(N(6).LT.0) THEN
                WRITE(STDOUT,'(4X,''TS File ref. for evaporation='',A)')
     A                         NC_LONG(6)
              ENDIF
            ENDIF
 
C     STORAGE TABLE NUMBER IS CHECKED ELSEWHERE
 
            LN = N(4)
C           THE INFLOW NODE MUST BE A FREE NODE NOT USED ELSEWHERE
 
            IF(LN.GT.0) THEN
              IF(EXNODT(3,LN).NE.0) THEN
                CALL KILC
     I                    (NC(4), -32,
     M                     EFLAG)
              ENDIF
              IF(EXNODT(3,LN).EQ.0.AND.EXNODT(2,LN).NE.0) THEN
                CALL KILC
     I                    (NC(4), -32,
     M                     EFLAG)
              ENDIF
 
C             MARK NODE AS IN USE.  GIVE THE NEGATIVE OF THE EMC ADDRESS
C             TO DISTINGUISH IT FROM THE FREE NODES ON A NULL BRANCH
C             FOR MAKEMC.
 
              EXNODT(2,LN) = -EPT
 
C             SET SIGN OF THE INFLOW NODE
              IF(EXNODT(1,LN).NE.0) THEN
                CALL KILC
     I                    (NC(4), -32,
     M                     EFLAG)
              ELSE
                EXNODT(1,LN) = -1
              ENDIF
            ENDIF
 
 
            IF((EPT+8).GT.MLEMC) CALL KIL
     I                                    (13,
     M                                     EPT, EFLAG)
 
            EMC(EPT+1) = N(1)
            EMC(EPT+2) = N(2)
C            WRITE(STDOUT,*) ' STORAGE TAB INTERNAL NO=',N(2)
            EMC(EPT+3) = 0
            EMC(EPT+4) = 1
            EMC(EPT+5) = N(4)
C           SET THE THE DIRECTION INDICATOR TO DEFAULT VALUE
            EMC(EPT+6) = 1
 
C           SET THE SLOPE FACTOR.
            RDUM = F(1)
            EMC(EPT+7) = IDUM
 
C     ADD EXTERIOR NODE FOR THE RESERVOIR AND SET SIGN
 
            IF(EXNODT(1,N(1)).NE.0) CALL KILC
     I                                        (NC(1), -24,
     M                                         EFLAG)
            IF(EXNODT(2,N(1)).NE.0) CALL KILC
     I                                        (NC(1), -24,
     M                                         EFLAG)
 
            EXNODT(3,N(1)) = -1
            EXNODT(1,N(1)) = 1
C           ALSO MARK THE RESEVOIR NODE TO POINT TO THIS ENTRY. FOR
C           USE IN MAKEMC
            EXNODT(2,N(1)) = -EPT
 
C           Process possible time-series references.   The fifth argument
C           is the destination pointer for the resultant values.  This 
C           points into the proper slot in EMC.  We need the exterior node
C           number of the reservoir in order to get the surface area of
C           the reservoir.  The reservoir exterior node number is stored
C           at EMC(EPT+1).  Therefore, in subroutine LOAD we
C           can subtract 7 from the rainfall destination pointer to 
C           get the location in EMC of the reservoir node number and 
C           subtract 8 from the evap destination pointer to get same
C           info there.   THis is getting a bit complex! 
            CALL TS_CHK_AND_UPDATE(STDOUT, NEW_FORM, NC_LONG(5), 
     I                             LPR_RAIN, EPT+8, 
     M                             N(5), LDCALL, EFLAG)
            CALL TS_CHK_AND_UPDATE(STDOUT, NEW_FORM, NC_LONG(6), 
     I                             LPR_EVAP, EPT+9, 
     M                             N(6), LDCALL, EFLAG)

C           Set the rain and evap slots to a floating point zero.
            RDUM = 0.0
            EMC(EPT+8) = IDUM
            EMC(EPT+9) = IDUM
            GOTO 8000
 
C     CRITICAL DEPTH
 
 8       CONTINUE
            WRITE(STDOUT,33) NC(1)
            IF((EPT+2).GT.MLEMC) CALL KIL
     I                                    (13,
     M                                     EPT, EFLAG)
 
            EMC(EPT+1) = N(1)
            CHKSQ(2*(N(1)-1) + 2) = CHKSQ(2*(N(1)-1) + 2) + 1
            GOTO 8000
 
 
C     MOMENTUM JUNCTION
 
 9    CONTINUE
        WRITE(STDOUT,*) ' CODE 9 NOT YET SUPPORTED'
        GOTO 8000
 
C     ENERGY HEAD EQUALITY
 
 10   CONTINUE
         WRITE(STDOUT,35) NC(1), NC(2)
 
            IF((EPT+3).GT.MLEMC) CALL KIL
     I                                    (13,
     M                                     EPT, EFLAG)
            EMC(EPT+1) = N(1)
            EMC(EPT+2) = N(2)
            GOTO 8000
 
C     MOMENTUM FLUX PLUS PRESSURE FORCE EQUALITY.  USE ONLY
C     IF UPSTREAM AND DOWNSTREAM SECTION ARE SAME SIZE AND FLOW
C     CHANGES AT RIGHT ANGLES TO THE CHANNEL TAKE PLACE
 
 11   CONTINUE
         WRITE(STDOUT,55) NC(1), NC(2)
            IF(N(1).EQ.N(2)) CALL KILC
     I                                 (NC(1), -46,
     M                                  EFLAG)
 
            IF((EPT+3).GT.MLEMC) CALL KIL
     I                                    (13,
     M                                     EPT, EFLAG)
            EMC(EPT+1) = N(1)
            EMC(EPT+2) = N(2)
            GOTO 8000
 
C     MATCH AN AVERAGE ELEVATION WITH THE ELEVATION AT A THIRD NODE
C     USEFUL WHEN MOMENTUM IS CONSERVED AT A JUNCTION INVOLVING A
C     RIGHT ANGLED ENTRY OR NEARLY SO!
 
 12   CONTINUE
        WRITE(STDOUT,60) NC(1), NC(2), NC(3), F(1), NC(1)
        IF(F(1).LT.0.0.OR.F(1).GT.1.0) THEN
          WRITE(STDOUT,62) F(1)
          EFLAG = 1
        ENDIF
 
        IF(N(1).EQ.N(2)) CALL KILC
     I                             (NC(1), -46,
     M                              EFLAG)
        IF(N(2).EQ.N(3)) CALL KILC
     I                             (NC(2), -46,
     M                              EFLAG)
        IF(N(1).EQ.N(3)) CALL KILC
     I                             (NC(3), -46,
     M                              EFLAG)
 
        IF((EPT+5).GT.MLEMC) CALL KIL
     I                                (13,
     M                                 EPT, EFLAG)
        EMC(EPT+1) = N(1)
        EMC(EPT+2) = N(2)
        EMC(EPT+3) = N(3)
        RDUM = F(1)
        EMC(EPT+4) = IDUM
        GOTO 8000
 
C     EQUALITY OF MOMENTUM AT A SIMPLE JUNCTION IF FLOW IS
C     ENTERING OR A SPECIFIC ENERGY BALANCE IF FLOW IS LEAVING.
C     REPLACEMENT FOR CODE 11 BUT CODE 11 IS RETAINED FOR
C     CONSISTENCY WITH PAST USAGE AND FOR SPECIAL CASES.
 
 13   CONTINUE
        WRITE(STDOUT,64) NC(1), NC(2), F(1)
        IF(N(3).GT.0) THEN
C         Check number of side nodes.
          IF(N(3).GT.2) THEN
            WRITE(STDOUT,90) N(3)
            EFLAG = 1
            N(3) = 2
          ENDIF
          DO 1301 J=1,N(3)
            WRITE(STDOUT,69) NC(3+J), F(1+J)
1301      CONTINUE
          IF(N(4).EQ.N(1)) CALL KILC
     I                           (NC(4), -46,
     M                            EFLAG)
          IF(N(4).EQ.N(2))CALL KILC
     I                           (NC(4), -46,
     M                            EFLAG)
          IF(N(3).GT.1) THEN
            IF(N(5).EQ.N(1)) CALL KILC
     I                             (NC(5), -46,
     M                              EFLAG)
            IF(N(5).EQ.N(2))CALL KILC
     I                             (NC(5), -46,
     M                              EFLAG)
          ENDIF
 
        ENDIF
        IF(N(1).EQ.N(2)) CALL KILC
     I                             (NC(1), -46,
     M                              EFLAG)
        IF(F(1).LT.0.0.OR.F(1).GT.1.0) THEN
          WRITE(STDOUT,67)
          EFLAG = 1
          F(1) = 0.0
        ENDIF
 
 
        IF((EPT+11).GT.MLEMC) CALL KIL
     I                                (13,
     M                                 EPT, EFLAG)
        EMC(EPT+1) = N(1)
        EMC(EPT+2) = N(2)
        EMC(EPT+3) = 0
        EMC(EPT+4) = 0
        RDUM = F(1)
        EMC(EPT+5) = IDUM
        EMC(EPT+6) = N(3)
        DO 1302 J=1,N(3)
          EMC(EPT + 6 + J) = N(3+J)
          RDUM = COS(0.017453*F(1+J))
          EMC(EPT + 8 + J) = IDUM
1302    CONTINUE
        GOTO 8000
 
C     SIDE-WEIR FLOW COMPUTATION. USED IN CONJUNCTION WITH
C     CODE 13.
 
 14   CONTINUE

C       Signal that code 14 is present
        CODE14_PRESENT = 1
C       Establish the head datum
        datum_shift = 0.0
        IF(FC(2).EQ.'LKUP') THEN
          CALL FIND_HDD_FROM_TABN(
     I                           N(4), STDOUT,
     O                           STATUS, HDATUM)
          IF(STATUS.EQ.1) THEN
c           Add the increment.  f(2) is 0.0 if none was given
            datum_shift = f(2)
            F(2) =  f(2) + HDATUM
            WRITE(CHR10,'(F10.3)') f(2) + dz_for_output
          ELSE
            CHR10 = 'from table'
            F(2) = 2.E30
          ENDIF
        ELSE
          IF(FC(2).EQ.'NONE') THEN
            WRITE(STDOUT,91) 
            EFLAG = 1
            F(2) = 3.E30
            CHR10 = 'missing'
          ELSE 
            WRITE(CHR10,'(F10.3)') F(2) + dz_for_output
          ENDIF
        ENDIF


        IF(NC_LONG(7).EQ.' ') THEN

          WRITE(STDOUT,66) NC(1), NC(2), NC(3), NC_LONG(4), NC_LONG(5), 
     A                     NC_LONG(6),  F(1), CHR10
          if(datum_shift.ne.0.0) then
            write(stdout,73) datum_shift
          endif

        ELSE 
C         Check for computation of the elevation of the toe of the levee. 
C         This is used to force a standard false levee height so that the
C         user can shift the datum for heads by a known elevation increment
C         and not a fraction of the levee height.  Thus the user can determine
C         the effective head datum in terms relative to the true levee height 
C         or in absolute terms. 
          IF(F(4).NE.0.0) THEN
C           We are computing the toe of the levee relative to the crest of
C           levee.  Since the toe of the levee is below the crest of the levee
C           and a height value makes most sense when it is postive, we use
C           subtraction to obtain our result.  If F(2) is incorrect because the
C           user left out a table, then F(3) will be incorrect as well.  However,
C           model will not run because a table is missing.
            F(3) = F(2) - F(4)
          ENDIF
          WRITE(STDOUT,68) NC(1), NC(2), NC(3), NC_LONG(4), NC_LONG(5), 
     A                     NC_LONG(6), NC_LONG(7), F(1), CHR10, 
     b                    F(3) + dz_for_output
        ENDIF
        IF(F(1).LT.0.0.OR.F(1).GT.1.0) THEN
          WRITE(STDOUT,62) F(1)
          EFLAG = 1
        ENDIF
        IF(N(1).EQ.N(2)) CALL KILC
     I                             (NC(1), -46,
     M                              EFLAG)
        IF(N(2).EQ.N(3)) CALL KILC
     I                             (NC(2), -46,
     M                              EFLAG)
        IF(N(1).EQ.N(3)) CALL KILC
     I                             (NC(3), -46,
     M                              EFLAG)
 
        IF((EPT+11).GT.MLEMC) CALL KIL
     I                                 (13,
     M                                  EPT, EFLAG)
        EMC(EPT+1) = N(1)
        EMC(EPT+2) = N(2)
        EMC(EPT+3) = N(3)
        EMC(EPT+4) = N(4)
        EMC(EPT+5) = N(5)
        EMC(EPT+6) = N(6)
        EMC(EPT+7) = N(7)
        RDUM = F(1)
        EMC(EPT+8) = IDUM
        RDUM = F(2)
        EMC(EPT+9) = IDUM
        RDUM = F(3)
        EMC(EPT+10) = IDUM
        GOTO 8000
 
 
C     DUMMY BRANCH
 
 15   CONTINUE
        N2EQ = N2EQ + 1
 
C       N(1) = UPSTREAM NODE; N(2)= DOWNSTREAM NODE. F(1) =
C       SLOPE FACTOR, AND F(2) = SURFACE AREA FACTOR.
C       Set the default values if the user has not given values
        IF(F(1).LE.0.0) THEN
          F(1) = KFAC
        ENDIF
        IF(F(2).LE.0.0) THEN
          F(2) = ASUR + ASUR
        ENDIF
        WRITE(STDOUT,86) NC(1), NC(2), F(1), F(2)
        IF(N(1).EQ.N(2)) CALL KILC
     I                             (NC(1), -46,
     M                              EFLAG)
 
        DO 150 I=1,2
C         MAKE SURE NEITHER NODE IS ALREADY IN USE
          IF(EXNODT(3,N(I)).NE.0) THEN
C           ALREADY IN USE FOR A BRANCH OR FOR A RESERVOIR
            CALL KILC
     I                (NC(I), -33,
     M                 EFLAG)
          ENDIF
          IF(EXNODT(3,N(I)).EQ.0.AND.EXNODT(2,N(I)).NE.0) THEN
C           ALREADY IN USE FOR A DIFFERENT DUMMY BRANCH
            CALL KILC
     I                (NC(I), -33,
     M                 EFLAG)
          ENDIF
C         STORE THE ADDRESS OF THE EMC ENTRY FOR LATER ACCESS
 
          EXNODT(2,N(I)) = EPT
 
C         SET NODE TYPE TO A NON-RESERVOIR AND NON-BRANCH NODE.
          EXNODT(3,N(I)) = 0
 150    CONTINUE
 
C       SET SIGNS FOR THE NODES. UPSTREAM NODE IS ALWAYS GIVEN FIRST.
 
        EXNODT(1,N(1)) = -1
        EXNODT(1,N(2)) = 1

C       Set the pointers to the other node.  Used later to find the
C       other end of the dummy branch when we know only one node
C       on the dummy branch. 
        EXNODT(4,N(1)) = N(2)
        EXNODT(4,N(2)) = N(1)

        IF((EPT+6).GT.MLEMC) CALL KIL
     I                                (13,
     M                                 EPT, EFLAG)
        EMC(EPT+1) = N(1)
        EMC(EPT+2) = N(2)
C       SET THE DEFAULT DIRECTION
        EMC(EPT+3) = 1
 
C       SET THE OPTIONAL INPUT VALUES
        RDUM = F(1)
        EMC(EPT+4) = IDUM
 
C       THE USER INPUTS THE SURFACE AREA BUT FEQ STORES ONE-HALF THE
C       SURFACE AREA TO BE CONSISTENT WITH THE EQUATION AS IMPLEMENTED
C       IN SUBROUTINE SETEXT.
        RDUM = 0.5*F(2)
        EMC(EPT+5) = IDUM
 
        GOTO 8000
 
 
 8000   CONTINUE
          EPT = EPT+EMC(CODE+1)
 8001   CONTINUE
        GOTO 1000
 
 8500 CONTINUE
 
C     WRAPUP THE INPUT
 
      EMC(EPT) = -1
 
C     Set the exterior node count.
      NEX = ENODEN
      WRITE(STDOUT,93) NEX
c     Check if there are some unattached free nodes.  Could be an 
c     even number of these and nex would still be even but the 
c     information would be flawed!
      call chk_dummy_branches
     i                  (stdout, nex, exnodt, inenus,
     o                   hit)
      if(hit > 0) then
        write(stdout, 95) 
        STOP 'Abnormal stop.  Error(s) found.'
      endif
      IF(MOD(NEX,2).NE.0) THEN
        WRITE(STDOUT,94) NEX

        STOP 'Abnormal stop.  Error(s) found.'
      ENDIF 
C     CHECK FOR MISSING BRANCHES
      DO 8600 J=1,NBRA
        IF(YE2(J).EQ.0.0) THEN
          WRITE(STDOUT,72) INBRUS(J)
          EFLAG = 1
        ENDIF
 8600 CONTINUE
 
C     CHECK FOR MISSING EXTERIOR NODES
C     AND TOO MANY OCCURRENCES OF AN EXTERIOR NODE NUMBER IN
C     FLOW RELATIONSHIPS
 
      DO 8700 J=1,NEX
        IF(CHKSQ(2*(J-1)+1).EQ.0.AND.CHKSQ(2*(J-1)+2).EQ.0) THEN
          WRITE(STDOUT,76) INENUS(J)
          EFLAG = 1
        ENDIF
        IF(CHKSQ(2*(J-1)+1).GT.1) THEN
          WRITE(STDOUT,78) INENUS(J)
          EFLAG = 1
        ENDIF
 
 8700 CONTINUE
C     CHECK FOR THE CORRECT NUMBER OF ENTRIES
 
      IF(IENTRY-1.NE.2*NEX-N2EQ) THEN
        WRITE(STDOUT,74) 2*NEX - N2EQ, IENTRY-1
C        EFLAG = 1
      ENDIF
      NENTRY = IENTRY - 1
      RETURN
C 991  CONTINUE
C        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
C        WRITE(STDOUT,*) LINE
C        STOP 'Abnormal stop: errors found.'
      END
C
C
C
      SUBROUTINE   EXTRAP
     I                   (TYPE, XOFF, MLFT,
     M                    EFLAG, EXT, FTP)
 
C     + + + PURPOSE + + +
C     Extend a cross-section table by extrapolation
 
C     PARAMTERS
 
      IMPLICIT NONE

C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, FTP, MLFT, TYPE, XOFF
      REAL EXT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     TYPE   - table type
C     XOFF   - offset for the cross section table being modified
C     MLFT   - maximum length of FTAB/ITAB
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     EXT    - extent and nature of extrapolation of the table
C     FTP    - next open location in the function table storage
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'stdun.cmn'
      INCLUDE 'misccon.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER JID(25), QCID(25)
      SAVE JID, QCID
 
C     + + + LOCAL VARIABLES + + +
      INTEGER IOFF, it
      REAL A2, A3, ALP2, ALP3, B2, B3, DA, DAEXT, DALP, DALPDA, DB,
     A     DBDA, DKH, DKHDA, DMA, DMADA, DMQ, DMQDA, DQC, DQCDA, DT,
     B     DTDY, DY, KH2, KH3, MA2, MA3, MQ2, MQ3, QC2, QC3, T2, T3, Y2,
     C     Y3, YB2, YB3
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL KIL
 
C     + + + DATA INITIALIZATIONS + + +
      DATA  JID/1,10*0, 1,8*0, 1 ,1, 0, 1 ,1/
      DATA QCID/11*0, 1,9*0, 1, 0, 0, 1/
 
C     + + + OUTPUT FORMATS + + +
 1    FORMAT(/,' *WRN:01* EXTRAPOLATION NOT DONE. TOP WIDTH',
     A      ' < 0. EXT = ',F10.2)
 50   FORMAT(/,'  *WRN:571 Extrapolation not done.',
     A           '  Section is slotted.')
C***********************************************************************
C     ON ENTRY FTP POINTS TO THE NEXT OPEN LOCATION IN
C     (FTAB,ITAB).  ON EXIT FTP SHOULD POINT TO THE NEW
C     NEXT OPEN LOCATION IN (FTAB,ITAB).
 
C     DO THE VALUES THAT ARE COMMON TO ALL OF THE 8 TABLE TYPES.
C     THEN BRANCH TO SPECIAL SECTIONS TO FINISH TABLES THAT
C     HAVE MORE TABULATED VALUES IN THEM THAN THE BARE MINIMUM
 
C     GET THE LAST LEVEL IN THE TABLE JUST ADDED TO FTAB/ITAB
 
      Y2 = FTAB(FTP-XOFF)
      T2 = FTAB(FTP-XOFF+1)
      A2 = FTAB(FTP-XOFF+2)
      KH2 = FTAB(FTP-XOFF+3)
      B2 = FTAB(FTP-XOFF+4)
 
C     Do not do extrapolation on slotted cross section tables.
      IF(T2.LT.MXSLOT) THEN
        WRITE(STD6,50)
        RETURN
      ENDIF
C     COMPUTE THE RATE OF CHANGE OF T, KH AND B
 
      IOFF = 2*XOFF
      DY = Y2 - FTAB(FTP-IOFF)
      DT = T2 - FTAB(FTP-IOFF+1)
      DA = A2 - FTAB(FTP-IOFF+2)
      DKH = KH2 - FTAB(FTP-IOFF+3)
      DB = B2 - FTAB(FTP-IOFF+4)
      DTDY = DT/DY
      DKHDA = DKH/DA
      DBDA = DB/DA
 
C     CHECK FOR MODE OF TOP WIDTH EXTRAPOLATION.
 
      IF(EXT.LT.0) DTDY = 0.0
      EXT = ABS(EXT)
 
C     NOW COMPUTE THE NEW LEVEL
 
      Y3 = Y2 + EXT
      T3 = T2 + DTDY*EXT
      IF(T3.LE.0.0) THEN
C       EXTRAPOLATION OF TOP WIDTH LEADS TO NON-POSITIVE VALUE.
        WRITE(STD6,1) EXT
        RETURN
      ENDIF
 
      DAEXT = 0.5*EXT*(T2 + T3)
      A3 = A2 + DAEXT
      KH3 = KH2 + DKHDA*DAEXT
      B3 = B2 + DBDA*DAEXT
      IF(B3.LT.1.0) B3 = 1.0
 
C     NOW STORE AWAY THE VALUES
 
      IF((FTP+XOFF).GE.MLFT) CALL KIL
     I                                (10,
     M                                 FTP, EFLAG)
      FTAB(FTP) = Y3
      FTAB(FTP+1) = T3
      FTAB(FTP+2) = A3
      FTAB(FTP+3) = KH3
      FTAB(FTP+4) = B3
 
 
C     THE CORE SET HAS BEEN DONE.  NOW DO THE TABLES THAT CONTAIN
C     ADDITIONAL ELEMENTS
 
      if(type.gt.25) then
        it = type - 10
      else
        it = type
      endif

      IF(JID(it).EQ.1) THEN
C       FIRST MOMENT EXISTS IN THESE TABLES.
        YB2 = FTAB(FTP-XOFF+5)
        YB3 = YB2 + 0.5*EXT*(A2 + A3) - EXT*EXT*(T3 - T2)/12.
        FTAB(FTP+5) = YB3
      ENDIF
 
      IF(QCID(it).EQ.1) THEN
C       ALP AND QC EXISTS IN THESE TABLES.
        ALP2 = FTAB(FTP-XOFF+6)
        QC2 = FTAB(FTP-XOFF+7)
        DALP =  ALP2 - FTAB(FTP-IOFF+6)
        DQC = QC2 - FTAB(FTP-IOFF+7)
        DALPDA = DALP/DA
        DQCDA = DQC/DA
        ALP3 = ALP2 + DALPDA*DAEXT
        QC3 = QC2 + DQCDA*DAEXT
        IF(QC3.LT.QC2) QC3 = QC2
        IF(ALP3.LT.1.0) ALP3 = 1.0
        FTAB(FTP+6) = ALP3
        FTAB(FTP+7) = QC3
      ENDIF
 
      IF(it.GE.23) THEN
C       WE HAVE THE WEIGHT COEFFICIENTS TO EXTRAPOLATE.  THESE
C       VARY IN POSITION AND MUST BE DONE INDIVIDUALLY.  COMPUTE
C       THE RATES OF CHANGE FOR EACH TYPE.  THEN EXTRAPOLATE
C       AND THEN STORE FOR EACH TYPE
 
        IF(it.EQ.23) THEN
C         MA AND MQ ARE AT OFFSETS OF 5 AND 6
          MA2 = FTAB(FTP-XOFF+5)
          DMA = MA2 - FTAB(FTP-IOFF+5)
          DMADA = DMA/DA
          MA3 = MA2 + DMADA*DAEXT
 
          MQ2 = FTAB(FTP-XOFF+6)
          DMQ = MQ2 - FTAB(FTP-IOFF+6)
          DMQDA = DMQ/DA
          MQ3 = MQ2 + DMQDA*DAEXT
          FTAB(FTP+5) = MA3
          FTAB(FTP+6) = MQ3
        ELSEIF(it.EQ.24) THEN
C         MA AND MQ ARE AT OFFSETS OF 6 AND 7
          MA2 = FTAB(FTP-XOFF+6)
          DMA = MA2 - FTAB(FTP-IOFF+6)
          DMADA = DMA/DA
          MA3 = MA2 + DMADA*DAEXT
 
          MQ2 = FTAB(FTP-XOFF+7)
          DMQ = MQ2 - FTAB(FTP-IOFF+7)
          DMQDA = DMQ/DA
          MQ3 = MQ2 + DMQDA*DAEXT
          FTAB(FTP+6) = MA3
          FTAB(FTP+7) = MQ3
        ELSEIF(it.EQ.25) THEN
C         MA AND MQ ARE AT OFFSETS OF 8 AND 9
          MA2 = FTAB(FTP-XOFF+8)
          DMA = MA2 - FTAB(FTP-IOFF+8)
          DMADA = DMA/DA
          MA3 = MA2 + DMADA*DAEXT
 
          MQ2 = FTAB(FTP-XOFF+9)
          DMQ = MQ2 - FTAB(FTP-IOFF+9)
          DMQDA = DMQ/DA
          MQ3 = MQ2 + DMQDA*DAEXT
          FTAB(FTP+8) = MA3
          FTAB(FTP+9) = MQ3
        ENDIF
      ENDIF
 
c     Make adjustments to the derivatives wrt depth if 30 <= type <=35
      if(type.eq.30) then
        ftab(ftp+5) = (kh3 - kh2)/(y3 - y2)
        ftab(ftp+6) = (b3 - b2)/(y3 - y2)
      elseif(type.eq.31) then
        ftab(ftp+6) = (kh3 - kh2)/(y3 - y2)
        ftab(ftp+7) = (b3 - b2)/(y3 - y2)
      elseif(type.eq.32) then
        ftab(ftp+8) = (kh3 - kh2)/(y3 - y2)
        ftab(ftp+9) = (alp3 - alp2)/(y3 - y2)
        ftab(ftp+10) = (b3 - b2)/(y3 - y2)
      elseif(type.eq.33) then
        ftab(ftp+7) = (kh3 - kh2)/(y3 - y2)
        ftab(ftp+8) = (b3 - b2)/(y3 - y2)
        ftab(ftp+9) = (ma3 - ma2)/(y3 - y2)
        ftab(ftp+10) = (mq3 - mq2)/(y3 - y2)
      elseif(type.eq.34) then
        ftab(ftp+8) = (kh3 - kh2)/(y3 - y2)
        ftab(ftp+9) = (b3 - b2)/(y3 - y2)
        ftab(ftp+10) = (ma3 - ma2)/(y3 - y2)
        ftab(ftp+11) = (mq3 - mq2)/(y3 - y2)
      elseif(type.eq.35) then
        ftab(ftp+10) = (kh3 - kh2)/(y3 - y2)
        ftab(ftp+11) = (alp3 - alp2)/(y3 - y2)
        ftab(ftp+12) = (b3 - b2)/(y3 - y2)
        ftab(ftp+13) = (ma3 - ma2)/(y3 - y2)
        ftab(ftp+14) = (mq3 - mq2)/(y3 - y2)
      endif

      FTP = FTP + XOFF
 
      RETURN
 
      END
C
C
C
      SUBROUTINE   INFO(FNAME2, FNAME1,
     O                  QPN, NRWTA, RTAP, RWTA, LDCALL, 
     O                  NODEID, MINPRT, LAGTSF, NFREE, GCHK,
     O                  VUNIT, ABSTOL, HSLOT, WSLOT, NSLOT, NUMLIM,
     O                  BNODE, BDYNUM, RESNUM, RTAFAC, OLD_SUMMARY,
     O                  CD14_TAB_DATUM, CD5T6_TAB_DATUM,
     O                  START_EQ, END_EQ, DTMIN_OUT, hi_iq_ns, 
     o                  hi_iq_ns_dwn, hi_iq_ns_up, hi_iq_ns_lmt,
     o                  ty13_to_ty43, upgrade_xsec_tab, 
     O                  make_dt_tab, use_maxdt_tab, hi_iq_ns_numgt, 
     o                  hi_iq_ns_knt, hi_iq_ns_dt,frcst_wth_dtsf,
     o                  make_tab_index, dz_for_output)
 
C     + + + PURPOSE + + +
C     Read the input to FEQ.
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER BDYNUM, BNODE, LAGTSF, LDCALL, MINPRT, 
     A        NFREE, NRWTA, NUMLIM, QPN, RESNUM, START_EQ, END_EQ,
     B        hi_iq_ns_numgt, hi_iq_ns_knt
      INTEGER  RTAP(MNFREE), RWTA(MNFREE)
      REAL ABSTOL, HSLOT, NSLOT, RTAFAC(MNFREE), VUNIT, WSLOT,
     A     DTMIN_OUT, hi_iq_ns_dwn, hi_iq_ns_up, hi_iq_ns_lmt, 
     B     hi_iq_ns_dt, dz_for_output
      CHARACTER GCHK*4, NODEID*4, OLD_SUMMARY*4, CD14_TAB_DATUM*4,
     A          CD5T6_TAB_DATUM*4, FNAME2*64, FNAME1*64, hi_iq_ns*4,
     a          ty13_to_ty43*4, upgrade_xsec_tab*4, make_dt_tab*256,
     b          use_maxdt_tab*16, frcst_wth_dtsf*4,
     *          make_tab_index*4


 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     QPN    - number of lateral inflows
C     NRWTA  - number of reservoirs with tributary area
C     RTAP   - reservoir tributary area pointer
C     RWTA   - reservoirs with tributary area
C     LDCALL - flag to signal that subroutine LOAD must be called
C     NODEID - user node identification string
C     MINPRT - flag to select minimum print out to the user message
C               file when DIFFUS=YES
C     LAGTSF - flag for signaling lagging of the runoff values from
C               the time series file
C     NFREE  - number of free nodes
C     GCHK   - flag for channel geometry check
C     VUNIT  - conversion factor for volumes on output
C     ABSTOL - Absolute tolerance in depth that overrides relative
C               change in declaring convergence.
C     HSLOT  - height of bottom slot.  Currently 0.0 always
C     WSLOT  - width of bottom slot
C     NSLOT  - Manning's roughness for bottom slot.
C     NUMLIM - maximum number of variables allowed to exceed the
C               primary tolerance
C     BNODE  - boundary node number at which to start defining the
C               coefficient matrix
C
C     BDYNUM - number of boundary nodes in the model
C     RESNUM - number of level-pool reservoirs
C     RTAFAC - reservoir tributary area factor
C     OLD_SUMMARY - if YES summary of extremes is in pre-version 10 format,
C                   otherwise it is in version 10 format.
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'misccon.cmn'
      INCLUDE 'infcom.cmn'
      INCLUDE 'xscom.cmn'
      INCLUDE 'grav.cmn'
      INCLUDE 'dtcom.cmn'
      INCLUDE 'namcom.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'inusnb.cmn'
      INCLUDE 'tabid.cmn'
 
C     + + + SAVED VALUES + + +
      CHARACTER NEW*4, YES*4
      SAVE NEW, YES
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I
      REAL ZIY
      CHARACTER ISTYLE*4,
     A     GISID_TO_NODEID*4, TABID_TO_NODEID*4, DO_SCHEMATIC*4,
     B     NEW_GENSCN_FEO*4
 
C     + + + EXTERNAL NAMES + + +
      INTEGER GET_UNIT
      EXTERNAL INFO1, INFO2, inline, KIL, FREE_UNIT,
     A         SET_DTEN_DEF, GET_UNIT
 
C     + + + DATA INITIALIZATIONS + + +
      DATA  YES/'YES'/, NEW/'NEW'/
 
 
C     + + + OUTPUT FORMATS + + +
 52   FORMAT(/,' Input style is: NEW.')
 54   FORMAT(/,' OLD input style no longer supported.')
 58   FORMAT(/,' Extrapolation tolerance=',F10.3)
 62   FORMAT(/,' Squared residual tolerance=',1PE10.4)
 70   FORMAT(/,' Get initial conditions file name=',/,5X,A)
 72   FORMAT(/,' Put initial conditions file name=',/,5X,A)
 75   FORMAT(/,' The current input cannot be processed.',/,
     A         '  NODEID must be YES and ISTYLE must be NEW.')
 1090 FORMAT(/,' WT increment/decrement = ',F6.3)
 1092 FORMAT(' Base value for WT = ',F10.2)
 1096 FORMAT(/,' Steady-flow result file name=',A)
 1100 FORMAT(/,' Geometry checking has been selected.  Computation of',
     A       ' both steady',/,' and unsteady flow is suppressed')
 1101   FORMAT(/,' Geometry will not be checked')
 2160 FORMAT(/,' Maximum allowed relative correction= ',F6.2,
     A         ' Extrapolation factor for initial estimate= ',F6.2)
 3018 FORMAT(/,' Number of time steps with frozen time=',I5,
     A       '  Frozen time steps are:',/,10F8.0)
 3020 FORMAT(/,' Time-step control parameters:',/,
     A  ' Maximum time step=',F10.0,' secs.',
     B  ' Minimum time step=',F5.1,' secs.',/,
     B  ' Weight factor for sum of iterations=',F5.2,/,
     C  ' Initial weighted sum of iteration count=',F5.1,/,
     D  ' High value for sum of iterations=',F5.1,/,
     E  ' Low value for sum of iterations=',F5.1,/,
     F  ' Factor to increase time step=',F5.1,/,
     G  ' Factor to decrease time step=',F5.1)
C***********************************************************************
C     Clear the flag for calling subroutine LOAD
      LDCALL = 0
C     Clear table id counter in common tabid.cmn
      NUM_TABID = 0 

      CALL INFO1
     I          (IN, FNAME2, FNAME1,
     O           STDOUT, 
     O           EFLAG, SSEPS, GRAV, VUNIT, ABSTOL, OUTPUT, PROUT, 
     O           LDCALL, ZIY, NODEID, MINPRT, LAGTSF, GEQOPT, NUMLIM,
     O           GEQVEC, OLD_SUMMARY, GISID_TO_NODEID,
     O           TABID_TO_NODEID, DO_SCHEMATIC, CD14_TAB_DATUM,
     O           CD5T6_TAB_DATUM, NEW_GENSCN_FEO, START_EQ, END_EQ,
     O           DTMIN_OUT, hi_iq_ns, hi_iq_ns_dwn, hi_iq_ns_up, 
     o           hi_iq_ns_lmt, ty13_to_ty43, upgrade_xsec_tab,
     o           make_dt_tab, use_maxdt_tab, hi_iq_ns_numgt, 
     o           hi_iq_ns_knt, hi_iq_ns_dt, frcst_wth_dtsf,
     o           make_tab_index, dz_for_output)

C     Set the default values for detention storage sizing.
      CALL SET_DTEN_DEF(GRAV)
 

C     DEFINE GRAVATATIONAL CONSTANTS
 
      TWOG = GRAV + GRAV
      HALFG = .5*GRAV
 
 

      CALL SET_RCB2(
     O                   IFRZ, DTVEC,
     O                   MAXDT, MINDT, AUTO, SITER,                    
     O                   HIGH, LOW, HFAC, LFAC, MRE, FAC, HSLOT,       
     O                   WSLOT, NSLOT, DWT, BWT, EXTTOL, SQREPS,     
     O                   BWFNAM, GCHK, ISTYLE,                     
     O                   GETNAM, PUTNAM)

 
      IF(NODEID.NE.'YES '.OR.ISTYLE.NE.'NEW ') THEN
        WRITE(STDOUT,75) 
        STOP 'Abnormal stop. Errors found.'
      ENDIF
      WRITE(STDOUT,3018) IFRZ, (DTVEC(I), I=1,IFRZ)
 
C     INCREMENT IFRZ TO COMPENSATE FOR LATER DECREMENT BEFORE
C     USE IN SUBROUTINE MANTIM BUT ONLY IF IFRZ IS INPUT AS > 0
 
      IF(IFRZ.GT.0) IFRZ = IFRZ + 1
 
 
      WRITE(STDOUT,3020) MAXDT, MINDT, AUTO, SITER, HIGH, LOW, HFAC, 
     A                   LFAC


 
C     SAVE THE INITIAL VALUE OF SITER TO RESET SITER AT THE START
C     OF EACH EVENT
 
      ISITER = SITER
 
 
      WRITE(STDOUT,2160) MRE, FAC
 
      WRITE(STDOUT,1090) DWT
 
      WRITE(STDOUT,1092) BWT
 
      WRITE(STDOUT,1096)  BWFNAM
      IF(DIFFUS.EQ.YES) THEN
C       Allocate the unit number
        BWFDSN = GET_UNIT(STDOUT)
      ENDIF

      IF(GCHK.EQ.'YES') THEN
        WRITE(STDOUT,1100)
      ELSE
        WRITE(STDOUT,1101)
      ENDIF
 
      IF(ISTYLE.EQ.NEW) THEN
        WRITE(STDOUT,52)
      ELSE
        WRITE(STDOUT,54)
        STOP 'Abnormal stop. OLD input style no longer supported.'
      ENDIF
 
      WRITE(STDOUT,58) EXTTOL
 
      WRITE(STDOUT,62) SQREPS
 
 
      WRITE(STDOUT,70) GETNAM
      IF(GETNAM.NE.' ') THEN
        GETDSN = GET_UNIT(STDOUT)
      ELSE
        GETDSN = 0
      ENDIF
 
      WRITE(STDOUT,72) PUTNAM
      IF(PUTNAM.NE.' ') THEN
        PUTDSN = GET_UNIT(STDOUT)
      ELSE
        PUTDSN = 0
      ENDIF
 
      CALL INFO2
     I          (IN, STDOUT, OUTPUT, NODEID, VUNIT, HSLOT, ISTYLE,
     I           GRAV, GISID_TO_NODEID, TABID_TO_NODEID,
     I           DO_SCHEMATIC, NEW_GENSCN_FEO, dz_for_output,
     M           EFLAG,
     O           QPN, NRWTA, RTAP, RWTA, LDCALL, 
     O           NFREE, BNODE, BDYNUM, RESNUM, RTAFAC)
 
      LAPD = 2*(NBN-NBRA)
 
      DO 100 I=1,NBRA
        ZILIM(I) = ZIY
 100  CONTINUE
 
 
      RETURN
      END
C
C
C
      SUBROUTINE   INFO1
     I                  (STDIN, FNAME2, FNAME1,
     O                   STDOUT, 
     O                   EFLAG, SSEPS, GRAV, VUNIT, ABSTOL, OUTPUT,
     O                   PROUT, LDCALL, ZIY, NODEID, MINPRT,
     O                   LAGTSF, GEQOPT, NUMLIM, GEQVEC, OLD_SUMMARY,
     O                   GISID_TO_NODEID, TABID_TO_NODEID,
     O                   DO_SCHEMATIC, CD14_TAB_DATUM, CD5T6_TAB_DATUM,
     O                   NEW_GENSCN_FEO, START_EQ, END_EQ, DTMIN_OUT,
     o                   hi_iq_ns, hi_iq_ns_dwn, hi_iq_ns_up, 
     o                   hi_iq_ns_lmt, ty13_to_ty43, upgrade_xsec_tab,
     o                   make_dt_tab, use_maxdt_tab, hi_iq_ns_numgt, 
     o                   hi_iq_ns_knt, hi_iq_ns_dt, frcst_wth_dtsf,
     o                   make_tab_index, dz_for_output)
 
C     + + + PURPOSE + + +
C     Input much of the Run Control Block in FEQ.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, GEQOPT, STDIN, LAGTSF, LDCALL, STDOUT, MINPRT, 
     A        NUMLIM, OUTPUT, PROUT, START_EQ, END_EQ, hi_iq_ns_numgt, 
     b        hi_iq_ns_knt
      INTEGER GEQVEC(MNBRA)
      REAL ABSTOL, GRAV, SSEPS, VUNIT, ZIY, DTMIN_OUT, hi_iq_ns_dwn, 
     *     hi_iq_ns_up, hi_iq_ns_lmt, hi_iq_ns_dt, dz_for_output
      CHARACTER NODEID*4, OLD_SUMMARY*4, GISID_TO_NODEID*4,
     A          TABID_TO_NODEID*4, DO_SCHEMATIC*4,
     B          CD14_TAB_DATUM*4, CD5T6_TAB_DATUM*4,
     C          NEW_GENSCN_FEO*4, FNAME2*64, FNAME1*64,
     *          hi_iq_ns*4, ty13_to_ty43*4, upgrade_xsec_tab*4,
     *          make_dt_tab*256, use_maxdt_tab*16, frcst_wth_dtsf*4,
     *          make_tab_index*4
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     STDOUT   - Fortran unit number for user output and messages
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     SSEPS  - surcharge storage relative correction convergence limit
C     GRAV   - value of acceleration due to gravity
C     VUNIT  - conversion factor for volumes on output
C     ABSTOL - Absolute tolerance in depth that overrides relative
C               change in declaring convergence.
C     OUTPUT - output level for diagnostic work
C     PROUT  - output level during delayed diagnostic output
C     TIME   - elapsed time in seconds from start of run
C     LDCALL - flag to signal that subroutine LOAD must be called
C     ZIY    - depth below which an element is forced to zero inertia
C     NODEID - user node identification string
C     MINPRT - flag to select minimum print out to the user message
C               file when DIFFUS=YES
C     LAGTSF - flag for signaling lagging of the runoff values from
C               the time series file
C     GEQOPT - governing equation option code
C     NUMLIM - maximum number of variables allowed to exceed the
C               primary tolerance
C     GEQVEC - code for the governing equation option for each branch
C     OLD_SUMMARY - if YES outputs extreme summary in pre-version 10 format
C                   otherwise in version 10 format.
C     GISID_TO_NODEID - if YES places the GISID from a cross-section function
C                       table into the node id for a branch node if the node id 
C                       is blank.  Otherwise no change to any nodeid.
C     TABID_TO_NODEID - if YES places the TABID from a cross_section function
C                       table into the node id for a branch node if the node id
C                       is blank.  Othersise no change to any nodeid.
C     DO_SCHEMATIC - if YES create an IntelliCAD scriprt file to draw a schematic
C                    of the system.  The (x,y) location of cross sections, LPR's,
C                    and many of the remaining free nodes on dummy branches must
C                    be known. 
C     CD14_TAB_DATUM - if YES use the datum stored in the 2-D flow table to 
C                      replace any datum given in the NMCI instruction.  Otherwise
C                      retain the datum in the instruction. 
C     CD5T6_TAB_DATUM - if YES use the datum stored in the 2-D flow tables to 
C                       to replace any datum given in the NMCI instruction.  Otherwise
C                       use the datum in the instruction.  Note that the datum
C                       in both table must be the same if the tables differ.   
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'misccon.cmn'
      INCLUDE 'julian.cmn'
      INCLUDE 'infcom.cmn'
      INCLUDE 'namcom.cmn'
      INCLUDE 'title.cmn'
      INCLUDE 'version.cmn'
      INCLUDE 'home.cmn'
      INCLUDE 'stdun.cmn'
      include 'datetime.cmn'
      include 'grid_datum.cmn'

C     + + + SAVED VALUES + + +
      CHARACTER NO*4, YES*4
      SAVE NO, YES
 
C     + + + LOCAL VARIABLES + + +
      INTEGER GEQLOC, I, IT, IOFLAG, KMLDUM, N, VALUES(8), STDTMP
      REAL EPSFAC
      REAL*8 HR
      CHARACTER  GENAME*5, NAME*4, GLB_HOME*128,
     A          LINE120*120, DATE*8, ZEIT*10, TZONE*5,
     B          LONGLINE*196, TEMP_FILE_NAME*128,
     C          SB_HOME*128, WORK*256
 
C     + + + INTRINSICS + + +
      INTRINSIC DBLE, SQRT
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER MJD, GET_UNIT
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL CHKDAT, CHKMJD, inline, inlineb, KIL, MJD,
     A         inline_ALL, STRIP_L_BLANKS, GET_UNIT,
     B      WHAT_EXECUTABLE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA NO/'NO'/, YES/'YES'/
 
C     + + + INPUT FORMATS + + +
 1    FORMAT(80A)
 
C     + + + OUTPUT FORMATS + + +
 4    FORMAT(/,' NBRA is no longer used on input (since version 9.93).',
     A       /,'  FEQ counts the number of branches and ignores any',
     B         ' value of NBRA that you give.')
 6    FORMAT(/,' NEX is no longer used on input (since version 9.93).',
     A       /,'  FEQ counts the number of exterior nodes and ignores',
     B         ' any value of NEX that you give.')
 8    FORMAT(/,' Zero inertia limit = ',F10.2,' feet')
 10   FORMAT(' ',80A)
11    format(/,' High IQ Newton-solution option is:',A4)
12    format(/,' High IQ Newton-solution reduction factor =',F10.3)
13    format(/,' High IQ Newton-solution increase factor =',F10.3)
14    format(/,' High IQ Newton-solution lower limit =',F10.3)
15    format(/,' High IQ Newton-solution time step =',F10.3)
16    format(/,' High IQ Newton-solution number greater than=',i7)
 20   FORMAT(/,' Gravity = ',F10.2)
 22   FORMAT(/,' Convergence limit(surcharge storage)  = ',1PE10.3)
 23   FORMAT(/,' ',A4,'= ',I5)
 24   FORMAT(/,' Convergence limits(system solution):',/,
     A          10X,' Primary = ',1PE10.3,/,
     B          10X,' Secondary =',1PE10.3,/,
     C          10X,' Absolute =',0PF7.3)
 25   FORMAT(/,' Maximum no. of iterations in system solution  = ',
     A       I5,' Max. NUMGT=',I5)
 26   FORMAT(/,' Print out option is: OUTPUT = ',I5)
 27   FORMAT(/,' Print out will be given every ',I8,' time steps')
 28   FORMAT(/,' Detailed print out starts at time interval ',I5)
 29   FORMAT(/,' Detailed print out ends at time interval ',I5)
 30   FORMAT(/,' Point flow option = ',A4)
 31   FORMAT(/,' Diffuse flow option = ',A4,' MINPRT=',I1,' LAGTSF=',
     A       I1, ' Dummy YEAR/MONTH=',I5,'/',I2)
 32   FORMAT(/,' Wind loading option = ',A4)
 34   FORMAT(/,' Underflow messages are : ',A4)
 35   FORMAT(/,' Diffuse flow option = ',A4,' MinPrt=',I1)
 36   FORMAT(/,' Node id string present? ',A4)
 39   FORMAT(/,' Convergence criterion for backwater = ',1PE10.3)
 40   FORMAT(/,' Max.no. iterations for backwater analysis = ',I5)
 42   FORMAT(/,' Stationing factor = ',1PE12.5)
 43   FORMAT(/,' Q small for relative error = ',F7.2,' Q chop for',
     A       ' output=',1PE10.2)
54    FORMAT(/,' *ERR;XXX* The following file could not be opened:',
     A       /,5X, A,/,' Make sure the pathname exists and that you',
     B       ' have permission to write to the file.')
 57   FORMAT(/,' Special operation block option = ',A4)
 58   FORMAT(/,' The size limits set for this program are:')
 59   FORMAT(' Number of branches:',I5,/
     A     ,' Number of exterior nodes:',I5,/
     B     ,' Number of nodes on branches:',I5,/
     C     ,' Number of operation blocks:',I5,/
     D     ,' Function table number:',I5,/
     E     ,' Length of the function table:',I8,/
     G     ,' Number of point flows:',I5,/
     H     ,' Length of Network-Matrix Control:',I7,/
     I     ,' Number of rows in array of partial deriv.:',I5,/
     J     ,' Length of array of partial deriv. :',I7,/
     K     ,' Number of matrix blocks:',I5,/
     L     ,' Number of land uses for trib. area:',I5,/
     M     ,' Number of inflow time-series files:',I5,/
     N     ,' Number of outflow time-series files:',I5,/
     O     ,' Number of special outputs:',I5,/
     P     ,' Number of input time-series :',I5,/
     Q     ,' Number of input time-series references=',I5)
 62   FORMAT(/,' Start time = ',I5,'/',I2,'/',I2,':',F12.9)
 64   FORMAT(/,' End time = ',I5,'/',I2,'/',I2,':',F12.9)
 65   FORMAT(/,' *WRN:15*',I2,' Iterations requested for system',
     A       ' solution but only',I2,' allowed.')
C 66   FORMAT(/,' *ERR:132* only',I3,' exterior nodes given but at',
C     A       ' least 2*NBRA = ',I3,' required.')
C 67   FORMAT(/,' *ERR:133* NBRA = 0 invalid.  NBRA > 0 required.')
 68   FORMAT(/,' *ERR:163* Convergence criterion for surcharge ',
     A   'storage is too small.',/,10X,'must be larger than 0.01')
 70   FORMAT(/,' Standard governing equations with WX=0.5 not ',
     A       'available.')
 71   FORMAT(/,' Standard governing equations selected. WX variable')
 72   FORMAT(/,' Govern. eqs. selected: WX variable, NZD option')
 73   FORMAT(/,' Gov. Eqs.: curvilinear axis, WX variable')
 74   FORMAT(/,' Gov. Eqs.: curvilinear axis, WX variable, NZD option')
 75   FORMAT(/,' *WRN:30* UNKNOWN OPTION=',A5,' FOR GEQOPT. ',
     A       ' STDX OPTION ASSUMED.')
76    format(/,' Make function-table index: ',a)
77    format(/,
     a  ' Elevation increment to add for datum shift on output: ',f10.4)
 79   FORMAT(/,' Tributary area unit factor=',1PE12.5)
80    FORMAT(' Version: ',F6.2,' Version date: ',A17,5X,
     A          'Date/time of run: ',A4,'/',A2,'/',A2,': ',
     B          A2,'.',A2,'.',A6)
81    FORMAT(/,' *ERR:376* Too many lines in the title block or ',
     A          'Run-Control Block heading is missing.') 
82    FORMAT(/,' Run Control Block Summary')
83    format(/,' Horizontal grid: Zone:',a,' Name:',a)  
84    FORMAT(/,' Summary of Extremes is in pre-version 9.5 format.')
85    format(/,' Vertical-datum: ',a)
86    FORMAT(/,' Summary of Extremes is in version 9.5 format.') 
87    format(/,' Unit system: ',a)                                                                            
88    FORMAT(/,' GISID placed into NODEID for branch nodes.')
89    format(/,' Function-table basis: ',a)
90    FORMAT(/,' TABID placed into NODEID for branch nodes.')
91    FORMAT(/,' Script file for schematic will be created.')
92    FORMAT(/,' Script file for schematic is not created.')
93    FORMAT(/,' FEO format is old.')
94    FORMAT(/,' FEO format is new.')
95    FORMAT(/,' Minimum time step to force detailed output=',F8.1,
     A       ' seconds.')
96    FORMAT(/,' Equation output will start at Eqno=',I6,' and',
     A       ' end at Eqno=',I6,'.')
97    FORMAT(/,' Global value for home directory= ',A)
C***********************************************************************
C     INITIALIZATIONS
 
      EFLAG = 0
      FTP = 1
      KMLDUM = 1
      GHOME = ' '
      SB_HOME = ' '
 
C     OUTPUT THE SIZE LIMITS
 
      WRITE(STDOUT,58)
      WRITE(STDOUT,59) MNBRA, MNEX, MNBN, MNBLK, MFTNUM,
     A               MRFTAB, MCPFPT, MREMC,
     B               MRMAT, MLPDA, MRMBLK, MNDIFA, MXN_TS_F,
     C               MNFOUT, MNSOUT, MXN_TS, MXN_DEST


C     Look for a SET SELECTORS block here.  If found, read the block
C     and then preprocess the master input file to create the 
C     one to be used. 
      
c     skip blank lines at the start of the file
101   continue      
        CALL  inline_ALL
     I                  (STDIN,
     O                   LONGLINE)
        if(longline.eq.' ') goto 101

      CALL STRIP_L_BLANKS(
     M             LONGLINE)
      IF(LONGLINE(1:13).EQ.'SET SELECTORS') THEN
        I = LEN_TRIM(LONGLINE)
        WRITE(STDOUT, *) ' '
        WRITE(STDOUT,'(A)') LONGLINE(1:I)
C       Process the Set-selectors block.
        CALL GET_SELECTORS(STDIN, STDOUT,
     O                     TEMP_FILE_NAME, SB_HOME)
        WRITE(STDOUT, *) ' '

        CALL SCAN_MASTER_INPUT(STDIN, STDOUT, TEMP_FILE_NAME, SB_HOME,
     I                         FNAME1,
     O                         EFLAG)
        IF(SB_HOME.NE.' ') THEN
C         User has given a home directory in the Set-selectors block. 
C         We want the user-output from FEQ to go into that directory. 
C         Therefore: 1. Open a file in that directory with a name 
C         given in FNAME2, the name derived from the command line when
C         FEQ was invoked.  2. Copy contents of STDOUT to the newly 
C         opened file.  3. Close STDOUT. 4. Replace STDOUT with the
C         value in the temp unit number. 
          STDTMP = GET_UNIT(0)
          WORK = SB_HOME
          IT = LEN_TRIM(WORK)
          WORK = WORK(1:IT)//'/'//FNAME2
          call os_file_style(
     m                         work)
          OPEN(UNIT=STDTMP, FILE=WORK, STATUS='UNKNOWN',IOSTAT=IOFLAG)
          IF(IOFLAG.NE.0) THEN
            IT = LEN_TRIM(WORK)
            WRITE(STDOUT,54) WORK(1:IT)
            STOP 'Abnormal stop. Error(s) found.'
          ENDIF
          CLOSE(STDOUT)
          OPEN(UNIT=STDOUT, FILE=FNAME2, STATUS='OLD')
200       CONTINUE
            READ(STDOUT,'(A)',END=210) LONGLINE
            IT = LEN_TRIM(LONGLINE)
            WRITE(STDTMP,'(A)') LONGLINE(1:IT)
            GOTO 200
210       CONTINUE
          CLOSE(STDOUT)
          STDOUT = STDTMP
          STD6 = STDOUT
        ENDIF
      ELSE
C       Restore file and process as usual
        BACKSPACE(STDIN)
      ENDIF
      
      
 
      WRITE(STDOUT, *) ' '
      DO 100 I=1,max_title_n

        CALL inlineb
     I              (STDIN, STDOUT,
     O               LINE120)
        IF(LINE120(1:7).NE.'RUN CON') THEN
C         This is part of the title group
          TITLE(I) = LINE120
          WRITE(STDOUT,'(1X ,A)') LINE120
        ELSE
C         Start of run-control block found.
          TITLE_N = I
C         Write the version, date of version, and the current date on the
C         last line of the title block. 
          CALL DATE_AND_TIME(DATE, ZEIT, TZONE, VALUES)
          WRITE(TITLE(I),80) VERSION_NUMBER, VERSION_DATE, DATE(1:4), 
     A          DATE(5:6), DATE(7:8), ZEIT(1:2), ZEIT(3:4), ZEIT(5:10)
c         Save the version/run date time
          version_run_date_time_string = title(i)

          WRITE(STDOUT,'(A)') TITLE(I)
          CALL WHAT_EXECUTABLE(STDOUT)
          call svn_report(stdout, 0)   !Report the repository loc, etc.
                                       
          WRITE(STDOUT,*) ' '
          WRITE(STDOUT,'(A)') LINE120
          GOTO 105
        ENDIF
100   CONTINUE
C     If we get here, the user has  used more than 200 lines for the header or
C     has forgotten the run-control block heading line.
       WRITE(STDOUT,81)
       STOP 'Abnormal stop: errors found.'
105   CONTINUE      

      CALL GET_RCB(STDIN, STDOUT,
     M             EFLAG)

      CALL SET_RCB1(
     O             NBRA, NEX, MINPRT, LAGTSF, DMYEAR, DMMN,
     O             ZIY, SYR, SMN, SDY, SFRAC, EYR, EMN, EDY,            
     O             EFRAC, GRAV, SSEPS, PAGESP, EPSSYS, ABSTOL,          
     O             EPSFAC, MKNT, NUMLIM, OUTPUT, PROUT,                 
     O             PRTINT, YR, MN, DY, HR, EPSB, MAXIT, SFAC,          
     O             TAUFAC, QEPS, QCHOP, SOPER, POINT, DIFFUS, WIND,
     O             UNDERF, NODEID, GENAME, OLD_SUMMARY,
     O             GISID_TO_NODEID, TABID_TO_NODEID, DO_SCHEMATIC,
     O             CD14_TAB_DATUM, CD5T6_TAB_DATUM, NEW_GENSCN_FEO,
     O             START_EQ, END_EQ, DTMIN_OUT, GLB_HOME, hi_iq_ns,
     o             hi_iq_ns_dwn, hi_iq_ns_up, hi_iq_ns_lmt,
     o             ty13_to_ty43, upgrade_xsec_tab, make_dt_tab,
     o             use_maxdt_tab, hi_iq_ns_numgt, hi_iq_ns_knt, 
     o             hi_iq_ns_dt, frcst_wth_dtsf,
     o             g_zone, g_hgrid, g_vdatum, g_unitsys, g_basis, 
     o             make_tab_index, dz_for_output)

                      
C     Set global home in common block home.cmn.  Note the HOME value 
C     given in the RCB over rides the one given in the SET Selectors block. 
c     8 Dec 2005:  Added a global home name for output.  Thus the global home
c     name given in the run-control block only applies to input files.  Also,
c     the getic file is an exception.  It is given the global output home name
c     because it is created by FEQ in a previous run and will appear in the 
c     global output home name!  As of this date, the user can only create a 
c     global home name using the set-selectors block.  If there is a need, 
c     we can add the ability to give output home names elsewhere.  

      IF(SB_HOME.NE.' ') THEN
        GHOME_OUT = SB_HOME
      ENDIF
      IF(GLB_HOME.NE.' ') THEN
        GHOME = GLB_HOME                                                
      ENDIF
        
      
      WRITE(STDOUT,82)
      IF(NBRA.GT.0) THEN
        WRITE(STDOUT,4)
      ENDIF 
            
      IF(NEX.GT.0) THEN                       
        WRITE(STDOUT,6)
      ENDIF
      IF(EFLAG.NE.0) STOP 'Abnormal stop: errors found.'
 
      WRITE(STDOUT,57) SOPER
      IF(SOPER.NE.YES.AND.SOPER.NE.NO) CALL KIL
     I                                          (42,
     M                                           KMLDUM, EFLAG)
 
C     At version 9.84 POINT inflows were disabled.
C      WRITE(STDOUT,30) POINT
      IF(POINT.NE.NO) CALL KIL
     I                        (36,
     M                         KMLDUM, EFLAG)
C      IF(POINT.EQ.YES) LDCALL = 1
 
 
      IF(DIFFUS.EQ.'DSS '.OR.DIFFUS.EQ.'NO  ') THEN
        WRITE(STDOUT, 35) DIFFUS, MINPRT
      ELSE
        WRITE(STDOUT,31) DIFFUS, MINPRT, LAGTSF, DMYEAR, DMMN
      ENDIF
 
      CALL CHKMJD
     I           (STDOUT, DMYEAR, DMMN,
     O            EFLAG)
 
      IF(DIFFUS.NE.YES.AND.DIFFUS.NE.NO.AND.DIFFUS.NE.'DSS ')
     A                                     CALL KIL
     I                                              (37,
     M                                               KMLDUM, EFLAG)
      IF(DIFFUS.EQ.YES.OR.DIFFUS.EQ.'DSS ') LDCALL = 1
 
 
      WRITE(STDOUT,32) WIND
      IF(WIND.NE.YES .AND. WIND.NE.NO) CALL KIL
     I                                          (38,
     M                                           KMLDUM, EFLAG)
      IF(WIND.EQ.YES) LDCALL = 1
 
 
      WRITE(STDOUT,8) ZIY
 
      WRITE(STDOUT,62) SYR, SMN, SDY, SFRAC
      CALL CHKDAT
     I           (STDOUT, SYR,
     M            SMN, SDY,
     O            EFLAG)
      CALL CHKMJD
     I           (STDOUT, SYR, SMN,
     O            EFLAG)
 
      WRITE(STDOUT,64) EYR, EMN, EDY, EFRAC
      CALL CHKDAT
     I           (STDOUT, EYR,
     M            EMN, EDY,
     O            EFLAG)
      CALL CHKMJD
     I           (STDOUT, EYR, EMN,
     O            EFLAG)
 
      dyfrac = sfrac/24.d0
      SJTIME = DBLE(MJD(SYR,SMN,SDY)) + dyfrac
      UJTIME = SJTIME
      JTIME = SJTIME
      EJTIME = DBLE(MJD(EYR,EMN,EDY)) + EFRAC/24.D0
      VJTIME = EJTIME

C     Set the base time for tables of types 7, 8, and 9.
C     The only time multiple events are done in sequence is
C     when DIFFUS=YES.
      IF(DIFFUS.NE.YES) THEN
        TAB_789_JTBASE = SJTIME
      ELSE
C       Compute the julian time at the first point of the
C       dummy event.  The day for the dummy event is always
C       1.  Used to compute the offsets for function tables of types
C       7, 8, and 9.
       TAB_789_JTBASE = DBLE(MJD(DMYEAR,DMMN,1))
      ENDIF
 
      WRITE(STDOUT,20) GRAV
      IF(GRAV.LT.30.0) THEN
C       SET CONVERSION FOR VOLUMES
        VUNIT= 1000.0
        RESEPS = 0.0003048
        C52EPS = 0.03048
        EPSB2 = 0.0003048
        DHSTAR = 0.1524
        QPCON = SQRT(2.*GRAV*DHSTAR)/DHSTAR
        LPRDY = .3048
        LPRMIN = 28.3
        MXSLOT = 0.07
      ELSE
        VUNIT = 43560.0
        RESEPS = 0.001
        C52EPS = 0.1
        EPSB2 = 0.001
        DHSTAR = 0.5
        QPCON = SQRT(2.*GRAV*DHSTAR)/DHSTAR
        LPRDY = 1.0
        LPRMIN = 1000.
        MXSLOT = 0.02134
      ENDIF
 
      WRITE(STDOUT,36) NODEID
 
      WRITE(STDOUT,22) SSEPS
      IF(SSEPS.LT.0.01) THEN
        WRITE(STDOUT,68)
        EFLAG = 1
      ENDIF
 
      NAME = 'Page'
      WRITE(STDOUT,23) NAME, PAGESP
 
      IF(EPSFAC.LE.1.0) EPSFAC = 2.0
      EPSSY2 = EPSFAC*EPSSYS
      WRITE(STDOUT,24) EPSSYS, EPSSY2, ABSTOL
 
      WRITE(STDOUT,25) MKNT, NUMLIM
      IF(MKNT+1.GT.MNITER) THEN
        WRITE(STDOUT,65) MKNT, MNITER-1
        MKNT = MNITER - 1
      ENDIF
 
      IF(OUTPUT.GT.0) OUTPUT = 0
      IF(PROUT.EQ.0) PROUT = 1
      WRITE(STDOUT,26) OUTPUT
 
      IF(YR.NE.0) THEN
C       REQUEST FOR PRINTING GREATER DETAIL AFTER A GIVEN TIME
        CALL CHKDAT
     I             (STDOUT, YR,
     M              MN, DY,
     O              EFLAG)
        PRTIME = DBLE(MJD(YR, MN, DY)) + HR/24.D0
      ELSE
        PRTIME = 1.D30
      ENDIF
 
      WRITE(STDOUT,27) PRTINT
 
 
      IF(GENAME.EQ.'STD  ') THEN
        WRITE(STDOUT,70)
        GEQOPT= 0
        EFLAG =1
      ELSEIF(GENAME.EQ.'STDX ') THEN
        WRITE(STDOUT,71)
        GEQOPT = 1
      ELSEIF(GENAME.EQ.'STDW ') THEN
        WRITE(STDOUT,72)
        GEQOPT = 2
      ELSEIF(GENAME.EQ.'STDCX') THEN
        WRITE(STDOUT,73)
        GEQOPT = 3
      ELSEIF(GENAME.EQ.'STDCW') THEN
        WRITE(STDOUT,74)
        GEQOPT = 4
      ELSE
        WRITE(STDOUT,75) GENAME
        GEQOPT = 1
      ENDIF
 
C     SET THE DEFAULT VALUES FOR THE GOVERNING EQUATIONS FOR EACH
C     BRANCH.  Bug in Lahey 5.01 requires local variable in loop
C     to get correct result.
 
      GEQLOC = GEQOPT
      DO 110 I=1,MNBRA
        GEQVEC(I) = GEQLOC
 110  CONTINUE
 
C     RESET THE GEQOPT VALUE SO THAT THE DEPTH VARYING WEIGHT WILL
C     BE PROCESSED ON INPUT PROPERLY
      IF(GEQOPT.EQ.4) GEQOPT = 2

      WRITE(STDOUT,39) EPSB
 
      WRITE(STDOUT,40) MAXIT
 
      WRITE(STDOUT,42) SFAC
 
      WRITE(STDOUT,79) TAUFAC

      IF(QCHOP.LT.0.0) THEN
        IF(GRAV.GT.15.0) THEN
          QCHOP = 1.E-3
        ELSE
          QCHOP = 3.048E-4
        ENDIF
      ENDIF
      WRITE(STDOUT,43) QEPS, QCHOP
 
      IF(OLD_SUMMARY.EQ.'YES') THEN
        WRITE(STDOUT,84)
      ELSE
        WRITE(STDOUT,86)
      ENDIF
      IF(GISID_TO_NODEID.EQ.'YES') THEN
        IF(TABID_TO_NODEID.EQ.'YES') THEN
C         GISID is dominant. 
          WRITE(STDOUT,88)
          TABID_TO_NODEID = 'NO'
        ELSE
          WRITE(STDOUT,88)
        ENDIF
      ELSE
        IF(TABID_TO_NODEID.EQ.'YES') THEN
          WRITE(STDOUT,90)
        ENDIF
      ENDIF

      IF(DO_SCHEMATIC.EQ.'YES') THEN
        WRITE(STDOUT,91)
      ELSE
        WRITE(STDOUT,92)
      ENDIF

      IF(NEW_GENSCN_FEO.EQ.'NO') THEN
        WRITE(STDOUT,93)
      ELSE
        WRITE(STDOUT,94)
      ENDIF

      WRITE(STDOUT,95) DTMIN_OUT
      
      IF(START_EQ.LE.END_EQ) THEN
        WRITE(STDOUT,96) START_EQ, END_EQ
      ENDIF

      IF(GLB_HOME.NE.' ') THEN
        N = LEN_TRIM(GLB_HOME)
        WRITE(STDOUT,97) GLB_HOME(1:N)
      ENDIF

      write(stdout,11) hi_iq_ns
      if(hi_iq_ns.ne.'NO') then
c       Check for special values.
        if(hi_iq_ns_up.lt.0.0) then
c         Compute value from hi_iq_ns_dwn
          hi_iq_ns_up = (1.0/hi_iq_ns_dwn)**(1.0/abs(hi_iq_ns_up))
        endif
        write(stdout,12) hi_iq_ns_dwn
        write(stdout,16) hi_iq_ns_numgt
        write(stdout,13) hi_iq_ns_up
        write(stdout,14) hi_iq_ns_lmt
        write(stdout,15) hi_iq_ns_dt
      endif

      if(g_zone /= 'NONE') then
        write(stdout,83) g_zone, g_hgrid
      endif
      if(g_vdatum /= 'NONE') then
        write(stdout,85) g_vdatum
      endif
      if(g_unitsys /= 'NONE') then
        write(stdout,87) g_unitsys
      endif
      if(g_basis /= 'NONE') then
        write(stdout,89) g_basis
      endif
      if(make_tab_index == 'YES') then
        write(stdout,76) make_tab_index
      endif
      if(dz_for_output /= 0.0) then
        write(stdout,77) dz_for_output
      endif
      RETURN
      END
C
C
C
      SUBROUTINE EXTRACT_SLOT_DEPTH
     I                             (STDOUT, NBRA, BRPT)

C     Extract the slot-depth values and place in a vector
C     for later use in output of results

      IMPLICIT NONE
      INTEGER STDOUT, NBRA, BRPT(8,NBRA)

      INCLUDE 'arsize.prm'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'bnothr.cmn'

C     Called program units
      REAL GET_SLOT_DEPTH
      EXTERNAL GET_SLOT_DEPTH

C     Local
      INTEGER I, J, FIRST, LAST

C***********************************************************************      

      DO 200 I=1,NBRA
        FIRST = BRPT(3,I)
        LAST = BRPT(4,I)
        DO 100 J=FIRST,LAST
          SDVEC(J) = GET_SLOT_DEPTH(NSEC(J))
100     CONTINUE
200   CONTINUE
      RETURN
      END

C
C
C
      SUBROUTINE   INFO2
     I                  (IN, STDOUT, OUTPUT, NODEID, VUNIT, HSLOT, 
     I                   ISTYLE, GRAV, GISID_TO_NODEID, TABID_TO_NODEID,
     I                   DO_SCHEMATIC, NEW_GENSCN_FEO, dz_for_output,
     M                   EFLAG,
     O                   QPN, NRWTA, RTAP, RWTA, LDCALL, 
     O                   NFREE, BNODE, BDYNUM, RESNUM,
     O                   RTAFAC)
 
C     + + + PURPOSE + + +
C     Input tables for each block in the input to FEQ.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER BDYNUM, BNODE, EFLAG, IN, LDCALL, STDOUT, 
     A        NFREE, NRWTA, OUTPUT, QPN, RESNUM
      INTEGER  RTAP(MNFREE), RWTA(MNFREE)
      REAL GRAV, HSLOT, RTAFAC(MNFREE), VUNIT, dz_for_output
      CHARACTER ISTYLE*4, NODEID*4, GISID_TO_NODEID*4, 
     A          DO_SCHEMATIC*4, TABID_TO_NODEID*4,
     B          NEW_GENSCN_FEO*4
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     STDOUT   - Fortran unit number for user output and messages
C     OUTPUT - output level for diagnostic work
C     NODEID - user node identification string
C     VUNIT  - conversion factor for volumes on output
C     HSLOT  - height of bottom slot.  Currently 0.0 always
C     ISTYLE - input style: NEW or OLD
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     QPN    - number of lateral inflows
C     NRWTA  - number of reservoirs with tributary area
C     RTAP   - reservoir tributary area pointer
C     RWTA   - reservoirs with tributary area
C     LDCALL - flag to signal that subroutine LOAD must be called
C     NFREE  - number of free nodes
C     BNODE  - boundary node number at which to start defining the
C               coefficient matrix
C
C     BDYNUM - number of boundary nodes in the model
C     RESNUM - number of level-pool reservoirs
C     RTAFAC - reservoir tributary area factor

C     GLB_HOME - global value for home directory/drive
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'misccon.cmn'
      INCLUDE 'infcom.cmn'
      INCLUDE 'ftable.cmn'
      INCLUDE 'tsfcom.cmn'
      INCLUDE 'bnothr.cmn'
      INCLUDE 'enothr.cmn'
      INCLUDE 'bnpond.cmn'
      INCLUDE 'enelem.cmn'
      INCLUDE 'bnelem.cmn'
      INCLUDE 'rdcom.cmn'
      INCLUDE 'wrcom.cmn'
      INCLUDE 'wincom.cmn'
      INCLUDE 'nzdcom.cmn'
      INCLUDE 'matcom.cmn'
      INCLUDE 'usintp.cmn'
      INCLUDE 'inusnb.cmn'
      INCLUDE 'ts_mngt.cmn'
      INCLUDE 'irrig.cmn'
      INCLUDE 'tabid.cmn'
      INCLUDE 'dtendef.cmn'
      include 'maketabindex.cmn'
      include 'svn.cmn'
 
C     + + + SAVED VALUES + + +
      CHARACTER  NEW*4, NO*4, YES*4
      SAVE NEW, NO, YES
 
C     + + + LOCAL VARIABLES + + +
      INTEGER BDYFLG, EMCADR, ENODEN, FTKNT, FUNFLG, I, IS, J, JUNKNT,
     A        LBUFF, LEN, LIM, LJUNC, LVAR, MINLEN, MINNOD, N, NEW_FORM, 
     B        SPOUT_STYLE, TABLE, TWON, DEFKNT, ioflag, it
      INTEGER CHKSQ(MNETRY), BASE_NODE_VEC(MNEX), WORK(MLPDA) 
      
      REAL AIRSPW, WATSPW
      CHARACTER CHR5*5, CHR6*6, HEAD*196, LINE*196, NXTNAM*256,
     A          C5VEC(MNEX)*5, KEY*16, current_file*256, 
     b          index_filename*256
      LOGICAL THERE
 
C     + + + INTRINSICS + + +
      INTRINSIC IABS
 
C     + + + EXTERNAL FUNCTIONS + + +
      CHARACTER GETUSN*5
      INTEGER GET_UNIT
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL BRIN, CHKBR, CHKEX, CHKPT, CHKWIN, DMPJUN, EXIN,
     A         EXINIT, FTABIN, GETINN, GETUSN, inline, KIL, MAKEMC,
     B         MAKJUN, MAKMAT, NZDCON, OPIN, OUTIN, PMPCTB, RDFIN,
     C         RTBADJ, SCAN, SETCON, SORTCI, STEXAG, TABRC, TRIBIN, 
     D         VALLEY, WRFIN, GET_UNIT, FREE_UNIT, 
     E         FIND_GATE_TABLE_ADDRESS, IRRIG_INPUT, 
     F         OUTPUT_BALANCE_LEGEND, EXTRACT_SLOT_DEPTH,
     G         SEEK_FREE_NODE_STATIONS, FREE_NODE_LOCATION_DEFINE,
     H         OUTPUT_SCHEMATIC_SCRIPT, MAYBE_ADD_gHOME_out,
     i         maybe_add_ext, os_file_style, braxy_to_exnodt 

 
C     + + + DATA INITIALIZATIONS + + +
      DATA YES/'YES'/, NO/'NO'/, NEW/'NEW'/
      DATA index_filename/'/ftab_index'/
 
C     + + + INPUT FORMATS + + +
 1    FORMAT(A)
 15   FORMAT(7X,F10.0)
 16   FORMAT(7X,A)
 17   FORMAT(6X,F10.0)
 
C     + + + OUTPUT FORMATS + + +
 11   FORMAT(/,' ',A)
 12   FORMAT(' ',A)
 40   FORMAT(/,' Wind Table Id  = ',A,/,1X,
     A           'Air Sp Wt  = ',1PE10.3,/,1X,
     B           'Water Sp Wt  = ',1PE10.3,/,1X,
     C           'Velocity at min Cd  = ',0PF7.2,/,1X,
     D           'Min Cd =',1PE10.3,/,1X,
     E           'Velocity at max Cd =',0PF7.2,/,1X,
     F           'Max Cd =',1PE10.3)
 50   FORMAT(/,' Run TERMINATED. Errors encountered.')
58    format(/,' File name for funtion-table index is:',/,5x,a)
 59   FORMAT(' ','Number of branches:',I5,/
     A     ,' Number of exterior nodes:',I5,/
     B     ,' Number of nodes on branches:',I5,/
     C     ,' Number of operation blocks:',I5,/
     D     ,' Function table count:',I5,/
     E     ,' Length of the function-table vector:',I7,/
     G     ,' Number of point flows:',I5,/
     H     ,' Length of Network-Matrix Control:',I7,/
     I     ,' Number of rows in array of partial deriv.:',I5,/
     J     ,' Length of array of partial deriv. :',I7,/
     K     ,' Number of matrix blocks:',I5,/
     L     ,' Number of land uses for trib. area:',I5,/
     M     ,' Number of inflow time-series files:',I5,/
     N     ,' Number of outflow time-series files:',I5,/
     O     ,' Number of special outputs:',I5,/
     P     ,' Number of input time-series :',I5,/
     Q     ,' Number of input time-series references=',I5)
 60   FORMAT(/,' ','True sizes:')
 62   FORMAT(/,' *ERR:192* Number of equations required=',I5,
     A       ' exceeds number available=',I5)
 64   FORMAT(/,' *ERR:229* Number of matrix elements required=',I7,
     A  ' exceeds number available=',I7)
 68   FORMAT(/,' Number of elements in matrix.',/,' Bdy Node  Length')
 70   FORMAT(4X,A5,I8)
 72   FORMAT(/,' Boundary node used=',A5)
 74   FORMAT(' *ERR:230* No valid boundary point exists.  Must add ',
     A       ' dummy boundary to model.')
 76   FORMAT(' *ERR:231* NODE=',A5,' not on a boundary.')
 78   FORMAT(' *ERR:232* Beginning node input missing. Add before',
     A       ' Special Output heading.')
 80   FORMAT(' Number of elements in network matrix=',I8)
 82   FORMAT(//,' Order of equations in Network Matrix.')
 84   FORMAT(' Equation Input Summary of Input',/,
     A       '   Number  VarId Order')
 85   FORMAT(/,' This input cannot be processed.  The',/,
     A        ' Network-Matrix Control Input must be NEW.')
86    FORMAT(/,' *ERR:395* Boundary node= ',A5,' not valid',
     A         ' for a beginning node.')
88    FORMAT(/,'*ERR:408* FEQ has found ',I8,' function tables',
     A/,' but ',I8,' unique table ids.  These numbers differ thus',
     B/,' some table ids with non-printing characters  may appear', 
     C/,' somewhere in the input.  One or more tables may also be',
     D ' missing.')
C***********************************************************************
c     Setup for a possible index for the function tables.

      index_knt = 0  !We track everything for the index even if the 
                     !user does not request its output.  Propably 
                     ! should make output of an index the default:)
      if(make_tab_index == 'YES') then
c       open a file with a standard name for the function-table index
        stdindex = get_unit(stdout)
        call maybe_add_ghome_out(
     m                          index_filename)
        call maybe_add_ext(
     m                      index_filename)

        call os_file_style(
     m                      index_filename)
        write(stdout,58) index_filename(1:len_trim(index_filename))
        OPEN(UNIT=stdindex, FILE=index_filename, 
     a                   STATUS='UNKNOWN',IOSTAT=IOFLAG)
        IF(IOFLAG.NE.0) THEN
          WRITE(STDOUT,*) 
     a          ' Problem in opening file: ', 
     b          index_filename(1:LEN_TRIM(index_filename))
          WRITE(STDOUT,*) 
     a          ' Check path for making the function-table index.'
          STOP 'Abnormal stop: errors found.'
        ENDIF
c       Clear the counter of tables in the index.
        index_knt = 0
      endif

C     INPUT THE BRANCH DESCRIPTION TABLES or maybe the function tables
 
C     CLEAR THE TRANSLATION VECTORS FOR USER BRANCHES AND
C     USER EXTERIOR NODES.
 
      DO 500 I=1,9999
        USBRIN(I) = 0
 500  CONTINUE
      DO 501 I=-9999,19998
        USENIN(I) = 0
 501  CONTINUE
C     CLEAR THE EXTERIOR NODE COUNTER FOR INTERNAL EXTERIOR NODE NUMBERS
      ENODEN = 0
 
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,1) HEAD
      WRITE(STDOUT,11) HEAD
      IF(HEAD(1:6).EQ.'BRANCH'.OR.HEAD(1:6).EQ.'Branch') THEN
        FUNFLG = 0
        DO 203 J=1,MFTNUM
          FTPNT(J) = 0
 203    CONTINUE
 
        NBRA = MNBRA
        NEX = MNEX
        CALL BRIN
     I           (SFAC, IN, STDOUT, MNBN, NEX, MFTNUM, ISTYLE,
     I            GISID_TO_NODEID, TABID_TO_NODEID, dz_for_output,
     M            EFLAG, USBRIN, ENODEN, NBRA, 
     O            NBN, BRPT, NSEC, UVX, UVY, XVEC, ZVEC, KA, KD, HLTAB,
     O            COEFIN, YCUT, BNODID, ZIVEC, STDFLD, PNDFLG, WDFVEC,
     O            USENIN, INBRUS, INENUS, EXNODT, ENODID, ADDVEC,
     O            GEQVEC, GEQOPT, KADJVEC)
 
      ELSEIF(HEAD(1:8).EQ.'FUNCTION'.OR.HEAD(1:8).EQ.'Function') THEN
        FUNFLG = 1
 
C       Clear the local home value
        CALL CLEAR_HOME()

C       INPUT THE FUNCTION TABLES  BEFORE THE BRANCH TABLES
 
        FTKNT = 0
 
         DO 202 J=1,MFTNUM
           FTPNT(J) = 0
 202     CONTINUE
 
        IS = IN
        current_file = 'master_input_file'  ! Set the current file for reading function tables
 1002   CONTINUE
          CALL FTABIN
     I               (IS, IN, STDOUT, OUTPUT, FTP, MFTNUM, MRFTAB, 
     I                HSLOT, current_file,
     M                EFLAG, FTKNT, FTPNT,
     O                TABLE, NXTNAM)
 
          IF(TABLE.EQ.-1) GOTO 302

C          write(stdout,*) ' At return from ftabin: is=',is,' in=',in
          IF(IS.NE.IN) THEN
C            write(stdout,*) ' Freeing unit=',is
            CALL FREE_UNIT(STDOUT, IS)
c           Make sure that IS is not longer active.
            is = in
            current_file = 'master_input_file'
          ENDIF

          IF(TABLE.EQ.-15) THEN
            IS = GET_UNIT(STDOUT)
C            write(stdout,*) ' After get_unit: is=', is
C            write(stdout,*) ' File name=',nxtnam
            INQUIRE(FILE=NXTNAM, EXIST=THERE)
            IF(THERE) THEN
              OPEN(UNIT=IS, FILE=NXTNAM, STATUS='OLD')
              current_file = nxtnam  ! reset the current file for input of function tables.
            ELSE
              it = len_trim(nxtnam)
              WRITE(STDOUT,*) ' FILE NAMED:', NXTNAM(1:it),' NOT FOUND.'
              WRITE(STDOUT,*) ' CHECK SPELLING OF TABLE INPUT FILE.'
              STOP 'Abnormal stop: errors found.'
            ENDIF
          ELSEIF(TABLE.EQ.-16) THEN
C           Set the local value of the home directory
            CALL SET_HOME(NXTNAM)
c           Check for version control and report
            call getsvn_rev(stdout, nxtnam,
     o                      svn_rev, svn_mod)
            
          ELSE
            IS = IN
            current_file = 'master_input_file'  ! Set the current file for reading function tables
          ENDIF

          GOTO 1002
 302    CONTINUE
        if(make_tab_index == 'YES') then
          call output_ftab_index(stdout)
        endif

C        write(stdout,*) 
C     a     ' At end of function-table input: is=',is,' in=',in
        IF(IS.NE.IN) THEN
          CALL FREE_UNIT(STDOUT, IS)
        ENDIF


 
C       NOW INPUT THE BRANCH TABLE AFTER THE INPUT OF FUNCTION
C       TABLES.
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,1) HEAD
        WRITE(STDOUT,12) HEAD
        NBRA = MNBRA
        NEX = MNEX
        CALL BRIN
     I           (SFAC, IN, STDOUT, MNBN, NEX, MFTNUM, ISTYLE,
     I            GISID_TO_NODEID, TABID_TO_NODEID, dz_for_output,
     M            EFLAG, USBRIN, ENODEN, NBRA, 
     O            NBN, BRPT, NSEC, UVX, UVY, XVEC, ZVEC, KA, KD, HLTAB,
     O            COEFIN, YCUT, BNODID, ZIVEC, STDFLD, PNDFLG, WDFVEC,
     O            USENIN, INBRUS, INENUS, EXNODT, ENODID, ADDVEC,
     O            GEQVEC, GEQOPT, KADJVEC)
 
 
      ENDIF
 
 
      QPN = NBN
 
      IF(DIFFUS.EQ.YES.OR.DIFFUS.EQ.'DSS ') THEN
        CALL TRIBIN
     I             (DIFFUS, SFAC, IN, STDOUT, NBN, NBRA, BRPT, NEX,
     I              GRAV, TAUFAC,
     M              EFLAG, ENODEN,
     O              NLUSE, TSFDSN, FFFDSN, TRIBA, QPN, NRWTA, RTAP,
     O              RWTA, GEND, GSTART, RTAFAC, TAFAC)
C       If irrigation has been requested, input the control values
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        IF(LINE(1:10).EQ.'IRRIGATION') THEN
          WRITE(STDOUT,'(/,A)') LINE
C         The user has requested irrigation computations.  
          CALL IRRIG_INPUT(IN, STDOUT, 
     M                     ENODEN, EFLAG)
        ELSE
          BACKSPACE(IN)
          IRRIG_KNT = 0
        ENDIF
      
      ELSE
        TSFDSN = 0
        FFFDSN = 0
        BWFDSN = 0
        NLUSE = 0
        NRWTA = 0
        IRRIG_KNT = 0
      ENDIF
 
 
C     INITIALIZE THE BASE ELEVATION FOR THE EXTERIOR NODES
C     ON BRANCHES
      DO 105 I=1,NBRA
        ZE(BRPT(5,I)) = ZVEC(BRPT(3,I)) - HSLOT
        ZE(BRPT(6,I)) = ZVEC(BRPT(4,I)) - HSLOT
 105  CONTINUE
 
C     INPUT THE OPTIONAL TABLE FOR SETINW- VARIABLE WEIGHT IN THE
C     INTEGRALS OVER DISTANCE.
 
      IF(GEQOPT.EQ.2) THEN
C       INPUT THE CONTROL INFORMATION
        CALL NZDCON
     I             (IN, STDOUT, NBRA, GEQVEC,
     O              EFLAG, NZDTYP, YATONE, YATHAF)
C       INITIALIZE THE WEIGHT VECTORS TO THE DEFAULT VALUE
        DO 109 I=1,NBN
          WXVEC1(I) = 0.5
          WXVEC2(I) = 0.5
 109    CONTINUE
      ENDIF


 
C     INPUT THE NETWORK-MATRIX CONTROL TABLE and detect the
C     optional DEFINE MACROS block.

       
C  110  CONTINUE  Looks like it is no longer used.


      CALL inline
     I          (IN, STDOUT,
     O           LINE)

      IF(LINE(1:8).EQ.'DEFINE M') THEN
C       The define macros block is present. 
        READ(LINE,1) HEAD
        WRITE(STDOUT,11) HEAD
C       Process the define macros block. 
          CALL DEFINE_MACRO(IN, STDOUT, EFLAG)
C       Upon return we have terminated with the END MACROS line.
C       The next non-comment, non-blank line should be the 
C       heading for the network-matrix block.
        CALL inline
     I            (IN, STDOUT,
     O             LINE)

      ENDIF

      READ(LINE,1) HEAD
      WRITE(STDOUT,11) HEAD
C     Catch the new format flag for the Network Matrix Control
C     input.
      IF(HEAD(1:3).EQ.'NEW'.OR.HEAD(1:3).EQ.'new') THEN
        NEW_FORM = 1
      ELSE
        NEW_FORM = 0
        WRITE(STDOUT,85)
        STOP 'Abnormal stop.  Errors found.'
      ENDIF
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,1) HEAD
      WRITE(STDOUT,12) HEAD
 
      CALL EXIN
     I         (IN, STDOUT, MFTNUM, NBRA, MREMC, USBRIN, INBRUS,
     I          NEW_FORM, dz_for_output,
     M          EFLAG, EXNODT, USENIN, ENODEN,
     O          NEX, EPT, EMC, QE2, YE2, LDCALL, 
     O          NENTRY, ADD, CHKSQ, INENUS)
 
 
 
C     CHECK THE TRANSLATION VECTORS.
 
C      WRITE(STDOUT,*) ' '
C      WRITE(STDOUT,*) ' USBRAN INBRAN USBRAN'
C      DO 9123 I=1,9999
C        IF(USBRIN(I).GT.0) THEN
C          II = USBRIN(I)
C          WRITE(STDOUT,'(3I7)') I,USBRIN(I), INBRUS(II)
C        ENDIF
C9123  CONTINUE
C
C      WRITE(STDOUT,*) ' '
C      WRITE(STDOUT,*) ' USNODE INDODE USNODE'
C      DO 9124 I=-9999,19998
C        IF(USENIN(I).GT.0) THEN
C          II = USENIN(I)
C          WRITE(STDOUT,'(2I7,3X,A5)') I, USENIN(I), INENUS(II)
C        ENDIF
C9124  CONTINUE
 
C      WRITE(STDOUT,*) ' CHECKING BRPT'
C      WRITE(STDOUT,*) '  BRA    1    2    3    4    5    6'
C      DO 9125 I=1,NBRA
C        WRITE(STDOUT,'(7I5)') I,(BRPT(J,I),J=1,6)
C9125  CONTINUE
C      WRITE(STDOUT,*) ' '
C      WRITE(STDOUT,*) ' CHECKING EXNODT'
C      WRITE(STDOUT,*) ' NODE    1    2    3    4'
C      DO 9126 I=1,NEX
C        WRITE(STDOUT,'(5I5)') I,(EXNODT(J,I),J=1,4)
C9126  CONTINUE
 
 
C     CREATE DESCRIPTION OF THE NETWORK FOR USE IN REORDERING EMC
C     FOR MATRIX GENERATION. WORK STORES THE JUNCTION INFORMATION.
 
C     ESTABLISH THE VECTORS NEEDED FOR THE CONTINUITY CHECK AND FOR
C     DEVELOPING THE MATRIX.
 
      CALL SETCON
     I           (NEX, EMC, EXNODT,
     O            BDYNUM, RESNUM)
 
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,'(A6,A5)',ERR=991) CHR6, CHR5
      IF(CHR6.NE.'BNODE=') THEN
        WRITE(STDOUT,78)
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
      IF(CHR5.EQ.'     ') THEN
C       USER DID NOT SUPPLY A BOUNDARY NODE.  SEEK THE MINIMUM VALUE
 
        LIM = BDYNUM
        MINLEN = 2000000
        BDYFLG = 1
      ELSE
C       USER DID SUPPLY A BOUNDARY NODE.  USE IT.
 
C        BNODE = GETINN(CHR5, EFLAG)
        CALL GETINN
     M             (CHR5,
     O              EFLAG, BNODE)
        LIM = 1
        BDYFLG = 0
        MINLEN = 0
      ENDIF
 
      WRITE(STDOUT,*) ' '
      WRITE(STDOUT,*) '  BNODE=',CHR5
      WRITE(STDOUT,*) ' '
 
C     IF USER SUPPLIES BNODE, USE IT, OTHERWISE TRY ALL VALID
C     BOUNDARY NODES AND PICK THE MINIMUM VALUE
 
      IF(BDYFLG.EQ.1) WRITE(STDOUT,68)
 
 1199 CONTINUE
 
      DO 1200 I=1,LIM
 
C       IF IN THE SEARCH MODE, GET THE NEXT BOUNDARY NODE TO
C       TRY
 
        IF(BDYFLG.EQ.1) THEN
          BNODE = BDYVEC(I)
        ELSE
          WRITE(STDOUT,72) GETUSN(BNODE)
          WRITE(STDOUT,82)
          WRITE(STDOUT,*) ' '
          WRITE(STDOUT,84)
        ENDIF
 
        CALL MAKJUN
     I             (STDOUT, NEX, NBRA, MREMC, MLPDA, NENTRY, ADD,
     M              EMC, BRPT,
     O              EXNODT, WORK, JUNKNT, CHKSQ, LJUNC, EFLAG)
 
C       CHECK IF THE BOUNDARY NODE IS A GOOD STARTING NODE.
C       CODE 6 TYPE 2 DOES NOT WORK FOR STARTING.
 
        IF(EXNODT(5,BNODE).LT.0) THEN
C         NODE IS A BOUNDARY NODE.  IS IT VALID?
          EMCADR = -EXNODT(5,BNODE)
          IF(EMC(EMCADR).EQ.6) THEN
            IF(EMC(EMCADR+1).EQ.2) THEN
C             INVALID BOUNDARY.  SKIP THIS NODE IN THE LIST.
              IF(LIM.EQ.1) THEN
C               Problem:  No valid start.
                IF(BDYFLG.EQ.0) THEN
                  WRITE(STDOUT,86) CHR5
                  STOP 'Abnormal stop.  Error(s) found.'
                ENDIF
              ENDIF
              GOTO 1200
            ENDIF
          ENDIF
        ELSE
C         INVALID NODE IN BOUNDARY LIST.
 
          WRITE(STDOUT,76) GETUSN(BNODE)
          STOP 'Abnormal stop: errors found.'
        ENDIF
 
 
C       DUMP THE JUNCTION DATA FOR CHECKING. ALSO CHECK FOR PROPER
C       CONNECTIONS AT THE JUNCTIONS.
 
       CALL DMPJUN
     I            (STDOUT, JUNKNT, MNETRY, CHKSQ, LJUNC, WORK, MREMC,
     I             EMC)
 
 
        IF(EFLAG.GT.0) THEN
          WRITE(STDOUT,*) ' '
          WRITE(STDOUT,*) '  PROCESSING CANNOT CONTINUE.'
          WRITE(STDOUT,*) '   CORRECT REPORTED ERRORS.'
          STOP 'Abnormal stop: errors found.'
        ENDIF
 
C       REORDER EMC STARTING AT THE BOUNDARY NODES.
 
C       FIND SPACE AVAILABLE FOR THE PENDING BUFFER.
        LBUFF = MLPDA - LJUNC
 
 
        LVAR = 2*(NBN + NEX - 2*NBRA)
        IF(LVAR.GT.MRMAT) THEN
          WRITE(STDOUT,62) LVAR, MRMAT
          STOP 'Abnormal stop: errors found.'
        ENDIF
        CALL MAKEMC
     I             (STDOUT, BNODE, NENTRY, MREMC, LJUNC, LBUFF, NEX, 
     I              NBRA, EXNODT, BRPT, NBN, BDYFLG, MRMAT,
     M              WORK, EMC,
     O              WORK(LJUNC+1), ADD, R, C, NUMEQ, VARID)
 
 
C       TRANSFER THE INDEX NUMBERS FOR THE VARIABLES FROM THE
C       TEMPORARY VECTORS.
 
 
        DO 111 J=1,NEX
C          WRITE(STDOUT,*) ' NODE=',J, ' VAR INDEX=',R(J)
          EXNODT(5,J) = R(J)
 111    CONTINUE
        DO 112 J=1,NBRA
C          WRITE(STDOUT,*) ' BRAN=',J,' VAR INDEX=',C(J)
          BRPT(7,J) = C(J)
 112    CONTINUE
 
 
C       CREATE THE POINTERS FOR THE PROFILE MATRIX AND ASSIGN THE
C       BLOCKS FOR THE MATRIX.
 
        CALL MAKMAT
     I             (STDOUT, NBRA, NEX, NBN, BRPT, EXNODT,
     M              EMC)
 
        IF(C(NUMEQ).GT.MLPDA) THEN
          WRITE(STDOUT,64) C(NUMEQ), MLPDA
          STOP 'Abnormal stop: errors found.'
        ELSE
 
 
          LEN = C(NUMEQ)
          IF(LEN.LT.MINLEN) THEN
            MINLEN = LEN
            MINNOD = BNODE
          ENDIF
 
          IF(BDYFLG.EQ.1) THEN
            WRITE(STDOUT,70) GETUSN(BNODE), LEN
          ELSE
            WRITE(STDOUT,*) ' '
            WRITE(STDOUT,80) LEN
          ENDIF
        ENDIF
C       OUTPUT THE CONTROL INFORMATION FOR CHECKING
 
C        CALL DMPMC(STDOUT, NBRA, NEX, BRPT, EXNODT)
 
 1200 CONTINUE
 
      IF(MINLEN.EQ.2000000) THEN
C       NO VALID BONDARY POINT EXISTS.
 
        WRITE(STDOUT,74)
        STOP 'Abnormal stop: errors found.'
      ENDIF
      IF(BDYFLG.EQ.1) THEN
C       TAKE THE MINIMUM POINT AND MAKE THE FINAL PASS
 
        BDYFLG = 0
        LIM = 1
        MINLEN = 0
        BNODE = MINNOD
        GOTO 1199
      ENDIF
 
c     Output a summary of the sources, and types of equations 
c     in the model

      call eqsummary
     i              (STDOUT, nbn)

C     INPUT THE POINT FLOW INFORMATION
c     Disabled at version 9.84
c 
c      IF(POINT.EQ.NO) GOTO 120
c      CALL inline
c     I          (IN, STDOUT,
c     O           LINE)
c      READ(LINE,1) HEAD
c      WRITE(STDOUT,11) HEAD
c      CALL inline
c     I          (IN, STDOUT,
c     O           LINE)
c      READ(LINE,1) HEAD
c      WRITE(STDOUT,12) HEAD
c      CALL PFIN
c     I         (IN, STDOUT, MCPFPT, NBRA, BRPT,
c     O          EFLAG, LPNT, MF, PFPNT)
c 
C     INPUT WIND INFORMATION
 
 120  CONTINUE
      IF(WIND.EQ.NO) GOTO 130
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,1) HEAD
        WRITE(STDOUT,11) HEAD
 
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,16,ERR=991) KEY
        CALL GET_INTERNAL_TAB_NUMBER
     I                              (STDOUT, KEY,
     M                               EFLAG,
     O                               WINTAB)
        
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,15,ERR=991) AIRSPW
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,15,ERR=991) WATSPW
        AIRWAT = AIRSPW/WATSPW
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,17,ERR=991) VAMIN
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,17,ERR=991) CDMIN
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,17,ERR=991) VAMAX
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,17,ERR=991) CDMAX
        VADIF = VAMAX - VAMIN
        CDDIF = CDMAX - CDMIN
 
        WRITE(STDOUT,40) KEY, AIRSPW, WATSPW, VAMIN, CDMIN, VAMAX,
     A    CDMAX
 
C     INPUT SPECIAL OUTPUT LOCATIONS
 130  CONTINUE


      CALL inline
     I          (IN, STDOUT,
     O           LINE)


      READ(LINE,1) HEAD
      WRITE(STDOUT,11) HEAD
      IF(HEAD(1:7).EQ.'Special') THEN
C       Set the style flag for columnar form.
        SPOUT_STYLE = 1
      ELSE
        SPOUT_STYLE = 2
      ENDIF
      CALL OUTIN
     I          (BRPT, NBRA, NRWTA, RWTA, RTAP, SPOUT_STYLE,
     O           POUT, NOUT, UNIT)

c     Put the dual-source block here.  If it is not present we
c     should get the block title for input files.  Backspace
c     the file and return. 

      call dual_source 
     i                (in, stdout,
     m                 eflag)
 
C     READ THE INPUT FILE SPECIFICATION
 
      CALL RDFIN
     I          (IN, STDOUT,
     M           EFLAG)
 
C     READ THE OUTPUT FILE SPECIFICATION
 
      CALL WRFIN
     I          (IN, STDOUT, NBRA, BRPT,
     M           EFLAG)
 
C     INPUT CONTROL STRUCTURE OPERATION INFORMATION
      NBLK = 0
      IF(SOPER.EQ.YES)
     A  CALL OPIN
     I           (NBRA, MRFTAB, IN, STDOUT, BRPT,
     M            NBLK, EFLAG, FTP,
     O            OPBLK)
 
C     INPUT THE FUNCTION TABLES
 
      IF(FUNFLG.EQ.0) THEN
        CALL CLEAR_HOME()
        FTKNT = 0
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,1) HEAD
        WRITE(STDOUT,11) HEAD
 
         DO 200 J=1,MFTNUM
           FTPNT(J) = 0
 200     CONTINUE
 
        IS = IN
        current_file = 'master_input_file'  ! Set the current file for reading function tables
 1000   CONTINUE
          CALL FTABIN
     I               (IS, IN, STDOUT, OUTPUT, FTP, MFTNUM, MRFTAB, 
     I                HSLOT, current_file,
     M                EFLAG, FTKNT, FTPNT,
     O                TABLE, NXTNAM)
 
          IF(TABLE.EQ.-1) GOTO 300
          IF(IS.NE.IN) THEN
            CALL FREE_UNIT(STDOUT, IS)
          ENDIF

          IF(TABLE.EQ.-15) THEN
            IS = GET_UNIT(STDOUT)
            INQUIRE(FILE=NXTNAM, EXIST=THERE)
            IF(THERE) THEN
              OPEN(UNIT=IS, FILE=NXTNAM, STATUS='OLD')
              current_file = nxtnam 
            ELSE
              WRITE(STDOUT,*) ' FILE NAMED:', NXTNAM,' NOT FOUND.'
              WRITE(STDOUT,*) ' CHECK SPELLING OF TABLE INPUT FILE.'
              STOP 'Abnormal stop: errors found.'
            ENDIF
          ELSEIF(TABLE.EQ.-16) THEN
C           Set the local value of the home directory
C           Set the local value of the home directory. This is for function-table
c           files.  nxtnam contains the home name directory.  If 
            CALL SET_HOME(NXTNAM)            
            call getsvn_rev(stdout, nxtnam,
     o                      svn_rev, svn_mod)
          ELSE
            IS = IN
            current_file = 'master_input_file'  ! Set the current file for reading function tables
          ENDIF
 
          GOTO 1000
 300    CONTINUE
        if(make_tab_index == 'YES') then
          call output_ftab_index(stdout)
        endif

        IF(IS.NE.IN) THEN
          CALL FREE_UNIT(STDOUT, IS)
        ENDIF
 
      ENDIF
C     INPUT INITIAL CONDITIONS FOR FREE NODES
C     EXINIT ONLY READS IF THERE ARE FREE NODES
 
      CALL EXINIT
     I           (IN, STDOUT, NEX, NBRA, MREMC, EMC,
     M            EXNODT,
     O            EFLAG, NFREE, YE1, ZE, QE1, ENODID,
     O            BASE_NODE_VEC)
 
C     PRINT OUT TRUE SIZES
 
      WRITE(STDOUT,60)
      WRITE(STDOUT,59) NBRA, NEX, NBN, NBLK, FTKNT, FTP,
     A               LPNT, EPT, NUMEQ, C(NUMEQ), MATBLK, NLUSE,
     B               NUM_TS_F, NFOUT, NOUT, NUM_TS, NUM_DEST
 

C     Add check on the count of function tables and the count 
C     of TABID's.  When they disagree a table is missing or 
C     a table id has extra non-printing characters at some 
C     point in the input.  The tables for modeling detention
C     storage complicate matters because tabids might be 
C     defined there and no function table is ever input. 
C     As long as detention is not being modeled, no error
C     is implied.  Thus we must check to see if in fact
C     the default function tables have been input.

      DEFKNT = 0
      IF(DIFFUS.EQ.YES.OR.DIFFUS.EQ.'DSS ') THEN
        DEFKNT = 2
        IF(ftpnt(DEF_DTEN_UNIT_AREA_VOL_TAB_NUM).GT.0) THEN
C         The default function table has been input. 
          DEFKNT = DEFKNT - 1
        ENDIF
        IF(ftpnt(DEF_DTEN_ORIF_TAB_NUM).GT.0) THEN
C         The default function table has been input.
          DEFKNT = DEFKNT - 1
        ENDIF
      ENDIF
                      
                      

      IF(FTKNT+DEFKNT.NE.NUM_TABID) THEN
        WRITE(STDOUT,88) FTKNT+defknt, NUM_TABID
      ENDIF

      CALL OUTPUT_BALANCE_LEGEND(STDOUT)

C     RESOLVE REFERENCES AND DO FURTHER CHECKING IFF EFLAG=0
 
      IF(EFLAG.NE.0) GOTO 2500
C       CHKBR converts the positive values in NSEC to table addresses
C       from the internal table number. 
        CALL CHKBR
     I            (STDOUT, NBN, NBRA, NEX, MFTNUM, BRPT, FTPNT, GEQVEC,
     I             GRAV, SFAC, XVEC,
     M             NSEC, HLTAB,
     O             EFLAG, EXNODT)
 
C       Adjust the arguments for reservoir storage tables.
        CALL RTBADJ
     I            (STDOUT, NEX, EXNODT, MREMC, EMC, FTKNT, FTPNT,
     M             ZE, YE1)

        CALL CHKEX
     I            (STDOUT, NEX, MFTNUM, EPT, OPBLK, NBLK, NRWTA, RTAP,
     M             EFLAG, EMC, EXNODT, FTP, FTKNT, RWTA)

 
C       Lookup addresses for pump control tables
 
        IF(NBLK.GT.0) THEN
          CALL PMPCTB
     I               (NBLK, OPBLK, MFTNUM,
     O                EFLAG)
          CALL FIND_GATE_TABLE_ADDRESS
     I                   (STDOUT, NBLK, OPBLK, MFTNUM,
     O                    EFLAG)
        ENDIF
 
C       Check and complete the dual-source irrigation values
        IF(IRRIG_KNT.GT.0) THEN
          CALL IRRIG_CHECK(STDOUT, FTPNT, GEND, GSTART,
     M                     EFLAG)
        ENDIF
C       Lookup addresses for any main channel tables in special
C       output.
        CALL CHKSPOUT(STDOUT, NOUT, MFTNUM, FTPNT, 
     M                                            EFLAG)
 
c       Disabled in version 9.84
c        IF(POINT.EQ.NO) GOTO 2100
c
c          CALL CHKPT
c     I             (STDOUT, LPNT, MFTNUM, FTPNT,
c     M              PFPNT,
c     O              EFLAG)
 2100   IF(DIFFUS.EQ.NO) GOTO 2200
C         Check for detention storage and compute the 
C         values needed during simulation. 
          CALL COMPUTE_DETENTION_DESCRIPTION(STDOUT, GRAV,
     I                  FTPNT, NBRA, BRPT, 
     M                  FTP, EFLAG)      
C         Compute lag times from defining equations.
          CALL COMPUTE_DELAY_EQUATIONS(STDOUT, GRAV, FTPNT,
     I                                 NBRA, BRPT,
     M                                 EFLAG)      
 2200   IF(WIND.EQ.NO) GOTO 2300
          CALL CHKWIN
     I             (STDOUT, MFTNUM, FTPNT,
     M              WINTAB,
     O              EFLAG)
 2300   GOTO 3000
 2500 CONTINUE
 
C     TERMINATE BECAUSE OF ERRORS
 
         WRITE(STDOUT,50)
         STOP 'Abnormal stop: errors found.'
 3000 CONTINUE
      IF(EFLAG.EQ.0) GOTO 3100
        WRITE(STDOUT,50)
        STOP 'Abnormal stop: errors found.'
 3100 CONTINUE
 
 
C     RECOMPUTE THE TOP-WIDTH DEPENDENT VALUES IN THE CROSS
C     SECTION TABLES.  THIS WILL MAKE ALL VALUES CONSISTENT WITH
C     THE TABULATED TOPWIDTH.  THIS ACCOUNTS FOR THE TRUNCATION OF
C     THE TOP WIDTH WHEN PRINTING THE TABLES.   Also checks for
C     blunders in computing the area and first moment of area
C     for the tables. 
 
      CALL TABRC
     I          (STDOUT)
 
C     CHECK FOR REQUESTS FOR CROSS SECTION INTERPOLATION.
 
      CALL SCAN
     I         (STDOUT, NBRA, NBN, MFTNUM, MRFTAB, BRPT, NSEC, XVEC, 
     I          ZVEC, SFAC,
     M          EFLAG, FTP, FTKNT)
 
C     Adjust conveyance as requested 
      CALL ADJ_CONVEY
     I               (STDOUT, NBRA, NBN, BRPT, NSEC, KADJVEC,
     M                EFLAG)

C     Extract the slot depth values for use in output of depth 
C     values.
      CALL EXTRACT_SLOT_DEPTH
     I                       (STDOUT, NBRA, BRPT)

 
C     SET THE MAXIMUM ARGUMENT VALUE FOR NODES ON BRANCHES AND
C     FOR RESERVOIR NODES.  OTHER FREE NODES WILL HAVE MAX ARGUMENT
C     SET TO A LARGE POSTIVE VALUE.
 
      CALL STEXAG
     I           (NBRA, NEX, BRPT, EXNODT)

C     ESTABLISH THE VALUES IN USER NODE SORT ORDER VECTOR FOR OUTPUT
 
C     OUTPUT EXTERIOR NODE ON BRANCHES IN INTERNAL NODE NUMBER ORDER
C     THESE ARE ALWAYS FIRST BECAUSE INTERNAL NODE NUMBERS ARE
C     ASSIGNED IN THE ORDER THAT THE USER NODES APPEAR.  BRANCH
C     INPUT IS ALWAYS BEFORE ANY INPUT OF FREE NODES.
 
      TWON = 2*NBRA
      DO 201 I=1,TWON
        USNSRT(I) = I
 201  CONTINUE
      DO 204 I=TWON+1,NEX
        USNSRT(I) = I
        C5VEC(I) = INENUS(I)
 204  CONTINUE
 
      N = NEX - TWON
      IF(N.GT.0) THEN
C       THERE ARE SOME FREE NODES, AT LEAST 2.  SORT ON THE NODE
C       NAME.
        CALL SORTCI
     I             (N,
     M              C5VEC(TWON+1), USNSRT(TWON+1))
      ENDIF
 

C     Transfer the (x,y) locations known from branches to 
c     exnodt for the exterior nodes on branches. 
      call braxy_to_exnodt(NEX, 
     M                        EXNODT)

      IF(DO_SCHEMATIC.EQ.'YES') THEN
C       Process the possible schematic output here.  First do the
C       location definitions for free nodes. 
        IF(N.GT.0) THEN
          CALL FREE_NODE_LOCATION_DEFINE(STDOUT, NEX, BASE_NODE_VEC,
     M                                   EXNODT,
     O                                   EFLAG)
        ENDIF


        CALL OUTPUT_SCHEMATIC_SCRIPT(STDOUT, NBRA, NEX, BRPT, 
     I              EXNODT, EMC)
      ENDIF

C     Compute the stations for free nodes whenever that is possible. 
      CALL SEEK_FREE_NODE_STATIONS(STDOUT, NBRA, NEX, BRPT, 
     I            EMC,
     M            EXNODT)


C     Process the GENSCN block here since the address for all cross section
C     tables will be known. If the block is NOT present, we should get 
C     the backwater title line.  We must put it back. 

      CALL inline
     I            (IN, STDOUT,
     O             LINE)

      IF(LINE(1:13).EQ.'GENSCN OUTPUT') THEN
C       The GENSCN output block is present
        READ(LINE,1) HEAD
        WRITE(STDOUT,11) HEAD
C       Process the GENSCN block. 
          CALL GENSCN_INPUT(
     I          IN, STDOUT, BRPT, EXNODT, NBRA, NEX, NRWTA, RWTA, RTAP,
     I           SFAC, FTP,
     O           EFLAG)

C       Upon return we have terminated with the last line of the
C       GENSCN input
      ELSEIF(LINE(1:17).EQ.'NEW GENSCN OUTPUT') THEN
C       The revised GNSCN output block is present
        READ(LINE,1) HEAD
        WRITE(STDOUT,11) HEAD
C       Process the GENSCN block. 
          CALL GENSCN_INPUT_NEW(
     I          IN, STDOUT, BRPT, EXNODT, NBRA, NBN, NEX, NRWTA, 
     I          RWTA, RTAP, SFAC, FTP, NEW_GENSCN_FEO,
     O          EFLAG)

C       Upon return we have terminated with the last line of the
C       GENSCN input
      ELSE
        BACKSPACE(IN)
      ENDIF


 
      IF(STDFLD(1).NE.0.0) THEN
C       REQUEST FOR COMPUTATION OF VALLEY STORAGE
        CALL VALLEY
     I             (STDOUT, VUNIT, NBRA, XVEC, STDFLD, ZVEC, BRPT, NSEC)
      ENDIF
 
      IF(EFLAG.EQ.0) RETURN
 
        WRITE(STDOUT,50)
        STOP 'Abnormal stop: errors found.'
 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE
        STOP 'Abnormal stop: errors found.'
      END
C
C
C
      SUBROUTINE   NZDCON
     I                   (IN, STDOUT, NBRA, GEQVEC,
     O                    EFLAG, NZDTYP, YATONE, YATHAF)
 
C     + + + PURPOSE + + +
C     Input the parameters for control of problems at near zero depths.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, IN, STDOUT, NBRA
      INTEGER GEQVEC(NBRA), NZDTYP(NBRA)
      REAL YATHAF(NBRA), YATONE(NBRA)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     STDOUT   - Fortran unit number for user output and messages
C     NBRA   - number of branches in the model
C     GEQVEC - code for the governing equation option for each branch
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     NZDTYP - flag for selecting the near-zero depth weights
C     YATONE - depth value when the weight factor for distance values is
C               1.0(or essentially 1.0)
C     YATHAF - depth value when the weight factor for distance values is
C               0.5
 
C     + + + LOCAL VARIABLES + + +
      INTEGER BRAN, I, III, IS, IT
      REAL TP1, TP2
      CHARACTER CARD*80, CHAR8*8, LINE*80, TEMP*8
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER GETUSB
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETINB, GETNXT, GETUSB, inline
 
C     + + + INPUT FORMATS + + +
 2    FORMAT(A80)
 4    FORMAT(I5,2F10.0,A8)
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(1X,I5,2F10.3,A8)
 51   FORMAT(/,1X,A80)
 52   FORMAT(' *ERR:217* Depth when WX=.98 >= depth when WX=0.5.')
 54   FORMAT(' *ERR:218* Interpolation request:',A8,' invalid. Must be',
     A        /,11X,'linear, LINEAR, cubic, CUBIC, or a blank.')
 56   FORMAT(/,' *ERR:178* Branch number',I4,' requires near-zero-',
     A      'depth data but none found.')
C***********************************************************************
C     PLACE UNDEFINED VALUES INTO THE ARRAYS
      DO 101 III=1,NBRA
        YATONE(III) = -1.
        YATHAF(III) = -1.
        NZDTYP(III) = -1
 101  CONTINUE
 
C     READ AND ECHO THE BLOCK HEADING LINE
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,2) CARD
      WRITE(STDOUT,51) CARD
 
C     READ AND ECHO THE COLUMN HEADING LINE
 
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,2) CARD
      WRITE(STDOUT,51) CARD
 
      DO 100 III=1,NBRA
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
C        READ(LINE,4,ERR=991) BRAN, YATONE(I), YATHAF(I), CHAR8
        READ(LINE,4,ERR=991) BRAN, TP1, TP2, CHAR8
        IF(BRAN.LT.0) THEN
C         WE HAVE ENCOUNTERED THE END OF THE TABLE. SKIP OUT OF THE
C         LOOP
          GOTO 105
        ENDIF
 
        WRITE(STDOUT,50) BRAN, TP1, TP2, CHAR8
 
        IF(TP1.GE.TP2) THEN
          WRITE(STDOUT,52)
          EFLAG = 1
        ENDIF
C        I = GETINB(BRAN, EFLAG)
        CALL GETINB
     M             (BRAN,
     O              EFLAG, I)
        YATONE(I) = TP1
        YATHAF(I) = TP2
        IS = 1
        CALL GETNXT
     I             (CHAR8, IS,
     O              IT, TEMP)
 
        IF(TEMP.EQ.' ') THEN
          NZDTYP(I) = 0
        ELSEIF(TEMP.EQ.'linear'.OR.TEMP.EQ.'LINEAR') THEN
          NZDTYP(I) = 0
        ELSEIF(TEMP.EQ.'cubic'.OR.TEMP.EQ.'CUBIC') THEN
          NZDTYP(I) = 1
        ELSE
          WRITE(STDOUT,54) TEMP
          EFLAG = 1
        ENDIF
 100  CONTINUE
C     READ THE TERMINATING -1
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      WRITE(STDOUT,'(1X,A)') LINE
 
 105  CONTINUE
 
C     MAKE SURE THAT ALL THE BRANCHES THAT REQUIRE THIS INFORMATION
C     HAVE THE INFORMATION
      DO 120 I=1,NBRA
        IF(GEQVEC(I).EQ.2.OR.GEQVEC(I).EQ.4) THEN
          IF(NZDTYP(I).LT.0) THEN
            WRITE(STDOUT,56)  GETUSB(I)
            EFLAG = 1
          ENDIF
        ENDIF
 120  CONTINUE
 
      RETURN
 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE
        STOP 'Abnormal stop: errors found.'
      END
C
C
C 
      SUBROUTINE READ_PUMP_ITEMS(
     I                            STDOUT, LINE, NITEM, ITEM_START,
     I                            ITEM_END,
     M                            EFLAG,
     O                            IDLRISE, IDLFALL,
     O                            USBRA, USNODE, CHAR5, MNRATE, TBRISE,
     O                            TBFALL, ONPRI, OFFPRI)

C     Get the items of data from a line of input for pump control

      IMPLICIT NONE
      INTEGER STDOUT, NITEM, ITEM_START(NITEM), ITEM_END(NITEM),
     A         EFLAG, TBRISE, TBFALL, ONPRI, OFFPRI, USBRA,
     B         IDLRISE, IDLFALL
      REAL MNRATE
      CHARACTER LINE*(*), USNODE*5, CHAR5*5

C     Local

      INTEGER IE, IS, N
      CHARACTER TPC*20, KEY*16

C     Called program units
      INTEGER NONBLANK_NONZERO, LENSTR
      EXTERNAL STRIP_L_BLANKS, NONBLANK_NONZERO, LENSTR,
     A         GET_INTERNAL_TAB_NUMBER, STRIP_BLANKS_AND_ZEROS
C     ***********************FORMATS************************************
50    FORMAT(/,' *ERR:377* Only ',I3,' items given in ',
     A   'pump-control  line.  Need eight items.')
C***********************************************************************
      IF(NITEM.LT.8) THEN
        WRITE(STDOUT,50) NITEM
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      N = 1
C     Process the branch field. 
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      READ(TPC,'(I10)',ERR=991) USBRA
      
c     If branch number is < 0 go to end and return
      if(usbra < 0) goto 990

C     Process the node
      N = 2
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      USNODE = TPC

C     Process the selection field
      N = 3
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      CHAR5 = TPC

C     Process the minimum rate field
      N = 4
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      READ(TPC,'(F10.0)', ERR=991) MNRATE

C     Process the rising table id
      N = 5
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      KEY = TPC
C     Convert from the table id to an internal number.
C     We have an id given.
      IDLRISE = LENSTR(KEY)
      CALL GET_INTERNAL_TAB_NUMBER
     I                             (STDOUT, KEY,
     M                              EFLAG,
     O                              TBRISE)

C     Process the falling table id
      N = 6
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      KEY = TPC
C     Convert from the table id to an internal number.
C     We have an id given.
      IDLFALL = LENSTR(KEY)
      CALL GET_INTERNAL_TAB_NUMBER
     I                             (STDOUT, KEY,
     M                              EFLAG,
     O                              TBFALL)

C     Process the on priority
      N = 7
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      READ(TPC,'(I10)',ERR=991) ONPRI

C     Process the off priority
      N = 8
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      READ(TPC,'(I10)',ERR=991) OFFPRI

990   continue

      RETURN

991   CONTINUE
      WRITE(STDOUT,52) TPC
52    FORMAT(/,' *ERR:500* Conversion error in: ',A)
      EFLAG = 1
      RETURN

      END
C
C
C 
      SUBROUTINE READ_GATETABLE_ITEMS(
     I                            STDOUT, LINE, NITEM, ITEM_START,
     I                            ITEM_END,
     M                            EFLAG,
     O                            IDLTAB, IDLTABF,
     O                            CONTROL_NODE, USNODE, 
     O                            DSNODE, TAB_NUMBER, TST1, TST2,
     O                            DIRECTION_EPS, TAB_NUMBERF,
     O                            TST1F, TST2F)

C     Get the items of data from a line of input for GATETABLE control

      IMPLICIT NONE
      INTEGER STDOUT, NITEM, ITEM_START(NITEM), ITEM_END(NITEM),
     A         EFLAG, TAB_NUMBER, IDLTAB, TAB_NUMBERF, IDLTABF
      
      REAL DIRECTION_EPS

      CHARACTER LINE*(*), USNODE*5, CONTROL_NODE*5, DSNODE*5,
     A          TST1*5, TST2*5, TST1F*5, TST2F*5

C     Local

      INTEGER IE, IS, N
      CHARACTER TPC*20, KEY*16

C     Called program units
      INTEGER NONBLANK_NONZERO, LENSTR
      EXTERNAL STRIP_L_BLANKS, NONBLANK_NONZERO, LENSTR,
     A         GET_INTERNAL_TAB_NUMBER
C     ***********************FORMATS************************************
50    FORMAT(/,' *ERR:378* Only ',I3,' items given in ',
     A   'gate-table control  line.  Needs six items.')
52    FORMAT(/,' *ERR:396* Only ',I3,' items given in a gate-table',
     A ' control line. Must be exactly ten.')
C***********************************************************************
      IF(NITEM.LT.6) THEN
        WRITE(STDOUT,50) NITEM
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      N = 1
C     Process the control-node 
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      CONTROL_NODE = TPC

C     Process the upstream node
      N = 2
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      USNODE = TPC

C     Process the downstream node
      N = 3
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      DSNODE = TPC

C     Process the  table id
      N = 4
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      KEY = TPC
C     Convert from the table id to an internal number.
C     We have an id given.
      IDLTAB = LENSTR(KEY)
      CALL GET_INTERNAL_TAB_NUMBER
     I                             (STDOUT, KEY,
     M                              EFLAG,
     O                              TAB_NUMBER)

C     Process TST1
      N = 5
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      TST1 = TPC

C     Process the TST2
      N = 6
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      TST2 = TPC

      IF(NITEM.GT.6) THEN
C       We assume we have additional information to give
C       for the control.  
        IF(NITEM.LT.10) THEN
          WRITE(STDOUT,52) NITEM
          STOP 'Abnormal stop.  Errors found.'
        ENDIF

C       Process the direction tolerance
        N = 7
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_L_BLANKS(
     M                      TPC)
        READ(TPC,'(F15.0)') DIRECTION_EPS

C       Process the table id for falling stage
        N = 8
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_L_BLANKS(
     M                      TPC)
        KEY = TPC
C       Convert from the table id to an internal number.
C       We have an id given.
        IDLTABF = LENSTR(KEY)
        CALL GET_INTERNAL_TAB_NUMBER
     I                               (STDOUT, KEY,
     M                                EFLAG,
     O                                TAB_NUMBERF)

C       Process TST1F
        N = 9
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_L_BLANKS(
     M                    TPC)
        TST1F = TPC

C       Process the TST2F
        N = 10
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_L_BLANKS(
     M                    TPC)
        TST2F = TPC
      ELSE
C       If only one set is given, we copy the rising information to 
C       the falling information.  
        IDLTABF = IDLTAB
        DIRECTION_EPS = 0.0
        TAB_NUMBERF = TAB_NUMBER
        TST1F = TST1
        TST2F = TST2
      ENDIF

      RETURN

      END
C
C
C
      SUBROUTINE   OPIN
     I                 (NBRA, MLFT, IN, STDOUT, BRPT,
     M                  NBLK, EFLAG, FTP,
     O                  OPBLK)
 
C     + + + PURPOSE + + +
C     Input the operation information for dynamically
C     operated control structures.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, FTP, IN, STDOUT, MLFT, NBLK, NBRA
      INTEGER BRPT(8,NBRA), OPBLK(MNBLK)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NBRA   - number of branches in the model
C     MLFT   - maximum length of FTAB/ITAB
C     IN     - unit number for the user input file
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
C     NBLK   - number of operation blocks
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     FTP    - next open location in the function table storage
C     OPBLK  - pointer into the function table storage(FTAB/ITAB) for
C               each operation block.
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'ftable.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER MAXN
      PARAMETER (MAXN=20)
      INTEGER BLK, BRA, FN, HPRI, I, J, KEY, LN, LPRI, MODE, NODE, NPRI,
     A        ND, NUMB, OFFPRI, ONPRI, TBFALL, TBRISE, USBRA, SPEEDS,
     B        TAB_NUMBER, AUXTEST, FIRST, NITEM, IDLRISE, IDLFALL,
     D        IDLTAB, TAB_NUMBERF, IDLTABF, AUXTESTF
      INTEGER NDVEC(7), ITS(MAXN), ITE(MAXN)
      REAL DPDT, LL, LM, LU, MINDT, ML, MNRATE, MU, NDWT(7), NZHW,
     A     PINIT, DIRECTION_EPS
      CHARACTER BLKTYP*8, CHAR5*5, HEAD*80, LINE*80, NDVECC(7)*5,
     A          USNODE*5, TST1*5, TST2*5, CONTROL_NODE*5,
     B          DSNODE*5, JUST*5, TST1F*5, TST2F*5,
     C          TPA*20, TPB*20, TPC*20, TPD*20, TPE*20, TPF*20,
     D          TPG*20, TPH*20, TPI*20, TPJ*20
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER LENSTR
      CHARACTER GETTOK*5, GET_TABID*16
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETINB, GETINN, GETTOK, inline, KIL, STRIP_L_BLANKS,
     A         GET_TABID, READ_PUMP_ITEMS, LENSTR
 
C     + + + INPUT FORMATS + + +
 1    FORMAT(A80)
 3    FORMAT(4X,I5)
 5    FORMAT(6X,F10.0)
 7    FORMAT(I5,2A5,I5,5F7.0,3I5,F5.0)
 9    FORMAT(I5,2A5,I5,6F7.0,3I3,F5.0)
 10   FORMAT(I5,F5.0,7(A5,F5.0))
 11   FORMAT(8X,A8,8X,I5)
 12   FORMAT(6X,F10.0)
 13   FORMAT(I5,2A5,F7.0,4I5)
 14   FORMAT(3A5,I5,2A5)

C     + + + OUTPUT FORMATS + + +
 2    FORMAT(/,1X,A80)
 4    FORMAT(/,' Operation block number = ',I5)
 6    FORMAT(/,' Initial setting = ',F8.5)
 8    FORMAT(' ',I5,2A5,I5,5F7.2,3I5,F5.3)
49    FORMAT(' ',I5,2A5,I5,6F7.2,3I3,F5.3)
 50   FORMAT(' *ERR:187* KEY=',A5,' invalid option. Valid options are:',
     A   ' ELEV, QCON, or QVAR.')
 51   FORMAT(' ',A,A,A,A,A,A,A,A,A,A)
 52   FORMAT(/,' *ERR:188* Number of nodes for KEY=QVAR <= 0.')
53    FORMAT(/,' *ERR:355* Control node=',A5,' invalid in GATETABL.',
     A        '  Must be an exterior node.')
 54   FORMAT(/,' *ERR:189* Null zone half width <= 0.')
55    FORMAT(/,' *ERR:356* Upstream node=',A5,' invalid in GATETABL.',
     A        '  Must be an exterior node.')
 56   FORMAT(/,' *ERR:190* Branch number for KEY=QVAR > 0.')
57    FORMAT(/,' *ERR:357* Downstream node=',A5,' invalid in GATETABL.',
     A        '  Must be an exterior node.')
 58   FORMAT(/,' *ERR:191* Source node=',A5,' same as sense node.')
 60   FORMAT(' ',I5,F5.0,7(A5,F5.1))
 62   FORMAT(/,' *ERR:237* Block type= ',A8,' invalid. Must be GATE',
     A        ' PUMP, GATEVNZ, or GATETABL.')
 64   FORMAT(/,' Type of block is:',A8,'.')
 65   FORMAT(/,' Type of block is:',A8,'.  Pump has ',I2,' speeds.')
 66   FORMAT(/,' Minimum elapsed time for changing setting=',F7.1,
     A       ' seconds.')
 68   FORMAT(' ',I5,2A5,F7.2,A,A,2I5)
 70   FORMAT(/,' *ERR:238* Variable null zone for PUMP or GATEVNZ ',
     A         'operation invalid.')
 71   FORMAT(/,' *ERR:92* Null zone lower limit=',F8.2,' >= null',
     A         ' zone upper limit=',F8.2)
 72   FORMAT(/,' *ERR:93* Null zone middle level=',F8.2,' is on or',
     A         ' outside',/,' null zone limits=(',F8.2,',',F8.2,')')
73    FORMAT(/,' Number of speeds given as 0.  Probable',
     A        ' cause is missing SPEEDS input.',/,4X,' The default',
     B        ' number of speeds is:',I3)
C***********************************************************************
      JUST = 'RIGHT'
      DO 89 I=1,MNBLK
        OPBLK(I) = 0
 89   CONTINUE
 
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,1) HEAD
      WRITE(STDOUT,2) HEAD
 
 90   CONTINUE
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,3,ERR=991) BLK
      IF(BLK.LT.0) RETURN
      WRITE(STDOUT,4) BLK
      IF(BLK.LE.0.OR.BLK.GT.MNBLK) CALL KIL
     I                                      (41,
     M                                       BLK, EFLAG)
 
      ITAB(FTP) = BLK
      ITAB(FTP+6) = BLK
      OPBLK(BLK) = FTP
      NBLK = NBLK + 1
      IF(FTP+12.GT.MLFT) CALL KIL
     I                           (10,
     M                            FTP, EFLAG)
 
C     Input the block type: PUMP, GATE, GATEVNZ, PUMP2WAY, GATETABL
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,11,ERR=991) BLKTYP, SPEEDS
      IF(BLKTYP(1:4).EQ.'PUMP') THEN
        IF(SPEEDS.EQ.0) THEN
C         Default to ON/OFF operation.
          SPEEDS = 1
          WRITE(STDOUT,73) SPEEDS
        ENDIF
        WRITE(STDOUT,65) BLKTYP, SPEEDS
      ELSE
        WRITE(STDOUT,64) BLKTYP
      ENDIF
      CALL STRIP_L_BLANKS(
     M                    BLKTYP)
      IF(BLKTYP.EQ.'GATE') THEN
        ITAB(FTP+3) = 1
      ELSEIF(BLKTYP.EQ.'PUMP') THEN
        ITAB(FTP+3) = 2
      ELSEIF(BLKTYP.EQ.'GATEVNZ') THEN
        ITAB(FTP+3) = 1
      ELSEIF(BLKTYP.EQ.'PUMP2WAY') THEN
        ITAB(FTP+3) = 4
      ELSEIF(BLKTYP.EQ.'GATETABL') THEN
        ITAB(FTP+3) = 3
      ELSE
        WRITE(STDOUT,62) BLKTYP
        EFLAG = 1
        ITAB(FTP+3) = 1
      ENDIF
      ITAB(FTP+11) = SPEEDS
 
C     Input the minimum elapsed time before changing setting
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,12,ERR=991) MINDT
      WRITE(STDOUT,66) MINDT
      FTAB(FTP+4) = MINDT/3600.
 
C     Set the elapsed time since last change  to a large
C     value to ensure that a change takes place at the start of the run
      FTAB(FTP+5) = 1.E30
 
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,5,ERR=991) PINIT
      WRITE(STDOUT,6) PINIT
      FTAB(FTP+1) = PINIT
      FTAB(FTP+2) = PINIT

C     Set the active flag to -2 to signal inactive block.  
C     Initialization operation will change the setting for 
C     all operation blocks referenced in EMC.  Any that
C     are not referenced will not be used during the
C     simulation.

      ITAB(FTP+7) = -2

C     Location +8 is used only when multiple operation 
C     blocks per structure is selected.
      ITAB(FTP+8) = -2
      
C     Locations +9 and +10 are used by 2-way pumps only at 
C     this time.  Set values to 0, invalid values.
      ITAB(FTP+9) = 0
      ITAB(FTP+10) = 0

C     UPDATE POINTER TO START OF BODY OF THE OPERATION BLOCK
C     Note that the the first items are a header block and
C     numerical offsets are from a new base value for FTP.
      FTP = FTP + 12

      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,1) HEAD
      WRITE(STDOUT,2) HEAD
C     Get the column limits as defined by the user heading items.

      CALL GET_ITEM_LIMITS(
     I                     STDOUT, HEAD, MAXN, JUST,
     O                     NITEM, ITS, ITE)

C     Set the flag for detection of the first line.
      FIRST = 1

 100  CONTINUE
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      IF(BLKTYP.EQ.'GATE') THEN
        READ(LINE,7,ERR=991) USBRA, USNODE, CHAR5, MODE, MNRATE, ML,
     A                       LL, LU, MU, LPRI, NPRI, HPRI, DPDT
        CALL GETINB
     M             (USBRA,
     O              EFLAG, BRA)
        IF(BRA.LT.0) GOTO 250
        WRITE(STDOUT,8) USBRA, USNODE, CHAR5, MODE, MNRATE, ML, LL, LU,
     A                MU, LPRI, NPRI, HPRI, DPDT
      ELSEIF(BLKTYP(1:4).EQ.'PUMP') THEN
C       Note: this picks up both one-way and two-way pumps.
C        READ(LINE,13,ERR=991) USBRA, USNODE, CHAR5, MNRATE, TBRISE,
C     A                       TBFALL, ONPRI, OFFPRI
        CALL READ_PUMP_ITEMS(
     I                       STDOUT, LINE, NITEM, ITS,
     I                       ITE,
     M                       EFLAG, 
     O                       IDLRISE, IDLFALL,
     O                       USBRA, USNODE, CHAR5, MNRATE, TBRISE,
     O                       TBFALL, ONPRI, OFFPRI)
        CALL GETINB
     M             (USBRA,
     O              EFLAG, BRA)

        IF(BRA.LT.0) GOTO 250

        TPA = ' '
        TPB = ' '
        TPA(ITE(2)-ITS(2)+1-LENSTR(USNODE)+1:) = USNODE
        TPB(ITE(3)-ITS(3)+1-LENSTR(CHAR5)+1:) = CHAR5
        
        TPC = ' '
        TPD = ' '
        TPC(ITE(5)-ITS(5)+1-IDLRISE+1:) = GET_TABID(TBRISE)
        TPD(ITE(6)-ITS(6)+1-IDLFALL+1:) = GET_TABID(TBFALL)
        WRITE(STDOUT,68) USBRA, 
     A       TPA(1:ITE(2)-ITS(2)+1), 
     A       TPB(1:ITE(3)-ITS(3)+1),
     A       MNRATE, 
     A       TPC(1:ITE(5)-ITS(5)+1), 
     B       TPD(1:ITE(6)-ITS(6)+1), 
     C       ONPRI, OFFPRI
        LPRI = ONPRI
        NPRI = OFFPRI
        HPRI = 0
      ELSEIF(BLKTYP.EQ.'GATEVNZ') THEN
        READ(LINE,9,ERR=991) USBRA, USNODE, CHAR5, MODE, MNRATE, ML,
     A                       LL, LM, LU, MU, LPRI, NPRI, HPRI, DPDT
        CALL GETINB
     M             (USBRA,
     O              EFLAG, BRA)
        IF(BRA.LT.0) GOTO 250
        WRITE(STDOUT,49) USBRA, USNODE, CHAR5, MODE, MNRATE, ML, LL, LM,
     A                LU, MU, LPRI, NPRI, HPRI, DPDT

      ELSEIF(BLKTYP.EQ.'GATETABL') THEN
C        READ(LINE,14,ERR=991) CONTROL_NODE, USNODE, 
C     A                       DSNODE, TAB_NUMBER, TST1,
C     A        TST2
       CALL READ_GATETABLE_ITEMS(
     I                            STDOUT, LINE, NITEM, ITS,
     I                            ITE,
     M                            EFLAG,
     O                            IDLTAB, IDLTABF, 
     O                            CONTROL_NODE, USNODE, 
     O                            DSNODE, TAB_NUMBER, TST1, TST2,
     O                            DIRECTION_EPS, TAB_NUMBERF,
     O                            TST1F, TST2F)

        LPRI = 0
        NPRI = 0
        HPRI = 0
        IF(CONTROL_NODE(1:2).EQ.'-1') GOTO 250
        TPA = ' '
        TPB = ' '
        TPC = ' '
        TPD = ' '
        TPE = ' '
        TPF = ' '
        TPA(ITE(1)-ITS(1)+1-LENSTR(CONTROL_NODE)+1:) = CONTROL_NODE
        TPB(ITE(2)-ITS(2)+1-LENSTR(USNODE)+1:) = USNODE
        TPC(ITE(3)-ITS(3)+1-LENSTR(DSNODE)+1:) = DSNODE
        TPD(ITE(4)-ITS(4)+1-IDLTAB+1:) = GET_TABID(TAB_NUMBER)
        TPE(ITE(5)-ITS(5)+1-LENSTR(TST1)+1:) = TST1
        TPF(ITE(6)-ITS(6)+1-LENSTR(TST2)+1:) = TST2
        IF(NITEM.EQ.6) THEN
          WRITE(STDOUT,51)
     A                    TPA(1:ITE(1)-ITS(1)+1),
     B                    TPB(1:ITE(2)-ITS(2)+1),
     C                    TPC(1:ITE(3)-ITS(3)+1),
     D                    TPD(1:ITE(4)-ITS(4)+1),
     E                    TPE(1:ITE(5)-ITS(5)+1),
     F                    TPF(1:ITE(6)-ITS(6)+1)
        ELSE
          TPG = ' '
          TPH = ' '
          TPI = ' '
          TPJ = ' '
          WRITE(CHAR5, '(F5.3)') DIRECTION_EPS
          TPG(ITE(7)-ITS(7)+1-5+1:) = CHAR5
C          WRITE(STDOUT,*) ' ITE(8)=',ITE(8),' ITS(I)=',ITS(8)
C          WRITE(STDOUT,*) ' IDLTABF=',IDLTABF
          TPH(ITE(8)-ITS(8)+1-IDLTABF+1:) = GET_TABID(TAB_NUMBERF)
          TPI(ITE(9)-ITS(9)+1-LENSTR(TST1F)+1:) = TST1F
          TPJ(ITE(10)-ITS(10)+1-LENSTR(TST2F)+1:) = TST2F
          
          WRITE(STDOUT,51)
     A                    TPA(1:ITE(1)-ITS(1)+1),
     B                    TPB(1:ITE(2)-ITS(2)+1),
     C                    TPC(1:ITE(3)-ITS(3)+1),
     D                    TPD(1:ITE(4)-ITS(4)+1),
     E                    TPE(1:ITE(5)-ITS(5)+1),
     F                    TPF(1:ITE(6)-ITS(6)+1),
     G                    TPG(1:ITE(7)-ITS(7)+1),
     H                    TPH(1:ITE(8)-ITS(8)+1),
     I                    TPI(1:ITE(9)-ITS(9)+1),
     J                    TPJ(1:ITE(10)-ITS(10)+1)
        ENDIF

C        WRITE(STDOUT,*)' TABR=', (TAB_NUMBER), 
C     A                 ' TABF=', (TAB_NUMBERF)
C       Complete processing for GATETABL here since it does not
C       fit the pattern for the other options. 
C       Get the control node 
        IF((FTP+17).GE.MLFT) CALL KIL
     I                                (10,
     M                                 FTP, EFLAG)
        CALL GETINN
     M             (CONTROL_NODE,
     O              EFLAG, NODE)
        IF(EFLAG.EQ.0) THEN
C         It was an exterior node. Store the
C         negative of its address as the location to 
C         sense
          ITAB(FTP) = -NODE
C         Set the KEY value, used in OPINIT, for force setting of the 
C         water surface elevation as the level at the sensed node.
          ITAB(FTP+1) = 0
        ELSE
          WRITE(STDOUT,53) CONTROL_NODE
     
          STOP 'Abnormal stop.  Errors found.'
        ENDIF
C       Get the node upstream of the structure being operated
        CALL GETINN
     M             (USNODE,
     O              EFLAG, ND)
        IF(EFLAG.EQ.0) THEN
C         It was an exterior node. 
          ITAB(FTP+2) = ND
        ELSE
          WRITE(STDOUT,55) USNODE
          STOP 'Abnormal stop.  Errors found.'
        ENDIF

C       Get the node downstream of the structure.  May be 
C       zero.
        CALL STRIP_L_BLANKS(
     M                      DSNODE)
C       Check if DSNODE is a 0 or blank.
        READ(DSNODE,'(I5)',ERR=150) ND
          IF(ND.EQ.0) THEN
            ITAB(FTP+3) = ND
            GOTO 160
          ENDIF

150     CONTINUE

        CALL GETINN
     M             (DSNODE,
     O              EFLAG, ND)

        IF(EFLAG.EQ.0) THEN
C         It was an exterior node. 
          ITAB(FTP+3) = ND
        ELSE
          WRITE(STDOUT,57) DSNODE
          STOP 'Abnormal stop.  Errors found.'
        ENDIF

160     CONTINUE

        ITAB(FTP+7) = TAB_NUMBER
        ITAB(FTP+10) = TAB_NUMBERF
        FTAB(FTP+6) = DIRECTION_EPS

C       At the start of the run we will assume that the state for
C       each control point is rising. 
        ITAB(FTP+5) = 1

C       Set the previous level to small value.  Will be reset 
C       elsewhere
        FTAB(FTP+4) = -1.E20

        IF(FIRST.EQ.1) THEN
C         This is the first line for this structure. Set the table
C         to the dominant role. Rising stage
          ITAB(FTP+8) = 1
C         Set the sense for the table
          IF(TST1.EQ.'MIN') THEN
            ITAB(FTP+9) = 1
          ELSEIF(TST1.EQ.'MAX') THEN
            ITAB(FTP+9) = 2
          ELSEIF(TST1.EQ.' ') THEN
C           Default to MAX
            ITAB(FTP+9) = 2
          ENDIF
C         Set the table for falling stage to dominant role.
          ITAB(FTP+11) = 1
          IF(TST1F.EQ.'MIN') THEN
            ITAB(FTP+12) = 1
          ELSEIF(TST1F.EQ.'MAX') THEN
            ITAB(FTP+12) = 2
          ELSEIF(TST1F.EQ.' ') THEN
C           Default to MAX
            ITAB(FTP+12) = 2
          ENDIF

C         Set the test for the auxilliary tables-rising stage
          IF(TST2.EQ.'MIN') THEN
            AUXTEST = 1
          ELSEIF(TST2.EQ.'MAX') THEN
            AUXTEST = 2
          ELSEIF(TST2.EQ.' ') THEN
C           Default to MAX
            AUXTEST = 2
          ENDIF
C         Set the test for the auxilliary tables-falling stage
          IF(TST2F.EQ.'MIN') THEN
            AUXTESTF = 1
          ELSEIF(TST2F.EQ.'MAX') THEN
            AUXTESTF = 2
          ELSEIF(TST2F.EQ.' ') THEN
C           Default to MAX
            AUXTESTF = 2
          ENDIF

          FIRST = 2
        ELSE
C         Set the the AUX role and the sense for AUX lines. Rising stage
          ITAB(FTP+8) = 2
          ITAB(FTP+9) = AUXTEST
C         Set the AUX role and send for the AUX lines. Falling stage
          ITAB(FTP+11) = 2
          ITAB(FTP+12) = AUXTESTF
        ENDIF

        FTP = FTP + 17
        GOTO 100

      ENDIF
      IF(BLKTYP.EQ.'GATE'.OR.BLKTYP.EQ.'GATEVNZ') THEN
        IF(LL.GE.LU) THEN
C         Null zone invalid.
          WRITE(STDOUT,71) LL, LU
          EFLAG = 1
        ENDIF
        IF(BLKTYP.EQ.'GATEVNZ') THEN
          IF(LM.LE.LL.OR.LM.GE.LU) THEN
C           Variable null zone given for gate invalid
            WRITE(STDOUT,72) LM, LL, LU
            EFLAG = 1
          ENDIF
        ENDIF
      ENDIF

      
      IF((FTP+17).GE.MLFT) CALL KIL
     I                              (10,
     M                               FTP, EFLAG)
 
      CHAR5 = GETTOK(CHAR5)
      IF(CHAR5.EQ.'ELEV') THEN
        KEY = 0
      ELSEIF(CHAR5.EQ.'QCON') THEN
        KEY = 1
      ELSEIF(CHAR5.EQ.'QVAR') THEN
        KEY = 2
        IF(BLKTYP(1:4).EQ.'PUMP'.OR.BLKTYP.EQ.'GATEVNZ') THEN
          WRITE(STDOUT, 70)
          EFLAG = 1
        ENDIF
      ELSE
C       The KEY might be an exterior node to signal use of
C       an elevation difference as the argument to use in
C       controlling the structure. 
        CALL GETINN
     M             (CHAR5,
     O              EFLAG, ND)

        IF(EFLAG.EQ.0) THEN
C         It was an exterior node. Store the
C         negative of its address as the KEY value.
          KEY = -ND
        ELSE
          WRITE(STDOUT,50) CHAR5
          KEY = 0
          EFLAG = 1
        ENDIF
      ENDIF
C     GET ADDRESS OF NODE TO SENSE
 
      IF(BRA.GT.0) GOTO 200
 
C       BRA = 0 HERE
        CALL GETINN
     M             (USNODE,
     O              EFLAG, NODE)
 
C       STORE NEGATIVE OF NODE TO FLAG THE EXTERIOR NODE
 
        ITAB(FTP) = -NODE
        GOTO 210
 200  CONTINUE
 
C       BRA >0 HERE
 
        READ(USNODE,'(I5)',ERR=991) NODE
        IF(BRA.GT.NBRA) CALL KIL
     I                           (1,
     M                            BRA, EFLAG)
        FN = BRPT(1,BRA)
        LN = BRPT(2,BRA)
        IF(NODE.LT.FN.OR.NODE.GT.LN) CALL KIL
     I                                        (2,
     M                                         NODE, EFLAG)
        ITAB(FTP) = BRPT(3,BRA) + NODE - FN
        GOTO 210
 210  CONTINUE
 
C     STORE OTHER VALUES
 
      ITAB(FTP+1) = KEY
      IF(BLKTYP.EQ.'GATE'.OR.BLKTYP.EQ.'GATEVNZ') THEN
        ITAB(FTP+2) = MODE
        FTAB(FTP+3) = MNRATE
        FTAB(FTP+4) = 0.0
        FTAB(FTP+5) = ML
        FTAB(FTP+6) = LL
        FTAB(FTP+7) = LU
        FTAB(FTP+8) = MU
        FTAB(FTP+12) = DPDT
        IF(BLKTYP.EQ.'GATE') THEN
C         Store the standard values to reset the null zone.
C         In this case the null zone is a constant but the values
C         are reset anyway so that the same code can handle
C         GATE and GATEVNZ, GATE with Variable Null Zone.
          FTAB(FTP+13) = LL
          FTAB(FTP+14) = LL
          FTAB(FTP+15) = LU
          FTAB(FTP+16) = LU
        ELSE
C         Save the standard values to reset the variable null zone.
          FTAB(FTP+13) = LL
          FTAB(FTP+14) = LM
          FTAB(FTP+15) = LM
          FTAB(FTP+16) = LU
        ENDIF
      ELSEIF(BLKTYP.EQ.'GATETABL') THEN

      ELSE
        ITAB(FTP+2) = 0
        FTAB(FTP+3) = MNRATE
        FTAB(FTP+4) = 0.0
        ITAB(FTP+5) = TBRISE
        ITAB(FTP+6) = TBFALL
        FTAB(FTP+7) = 0.0
        FTAB(FTP+8) = 0.0
        FTAB(FTP+12) = 0.0
C       Following not used by pump but set 0 to all chk option in compiler
        FTAB(FTP+13) = 0.0
        FTAB(FTP+14) = 0.0
        FTAB(FTP+15) = 0.0
        FTAB(FTP+16) = 0.0
      ENDIF
      ITAB(FTP+9) = LPRI
      ITAB(FTP+10) = NPRI
      ITAB(FTP+11) = HPRI
 
      IF(KEY.LE.1) THEN
        FTP = FTP + 17
      ELSE
C       PROCESS THE INFORMATION DEFINING THE SOURCE NODES FOR THE
C       DEFINITION OF THE VARIABLE FLOW NULL ZONE.
 
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,1) HEAD
        WRITE(STDOUT,2) HEAD
 
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE, 10,ERR=991) NUMB, NZHW,(NDVECC(J), NDWT(J), J=1,NUMB)
        WRITE(STDOUT, 60) NUMB, NZHW,(NDVECC(J), NDWT(J), J=1,NUMB)
        IF(NUMB.LE.0) THEN
          WRITE(STDOUT,52)
          NUMB = 1
          EFLAG = 1
        ENDIF
 
        IF((FTP+15+2*NUMB).GE.MLFT) CALL KIL
     I                                       (10,
     M                                        FTP, EFLAG)
 
        IF(NZHW.LE.0.0) THEN
          WRITE(STDOUT,54)
          NZHW = 1.0
          EFLAG = 1
        ENDIF
        IF(BRA.GT.0) THEN
          WRITE(STDOUT,56)
          EFLAG = 1
        ENDIF
        FTAB(FTP+13) = NZHW
        ITAB(FTP+14) = NUMB
 
        DO 220 J=1,NUMB
          CALL GETINN
     M               (NDVECC(J),
     O                EFLAG, NDVEC(J))
          IF(NDVEC(J).EQ.NODE) THEN
            WRITE(STDOUT,58) NDVECC(J)
            EFLAG = 1
          ENDIF
          ITAB(FTP+14+2*J -1) = NDVEC(J)
          FTAB(FTP+14+2*J)    = NDWT(J)
 220    CONTINUE
 
        FTP = FTP + 15 +2*NUMB
      ENDIF
 
C     READ THE NEXT LINE
 
      GOTO 100
 
 250  CONTINUE
 
C     END OF THE BLOCK FOR THIS CONTROL STRUCTURE
 
      ITAB(FTP) = 0
      FTP = FTP+1
      IF(FTP.GT.MLFT) CALL KIL
     I                         (10,
     M                          FTP, EFLAG)
 
C     LOOK FOR THE NEXT SPECIAL OPERATION BLOCK INPUT
 
      GOTO 90
 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE
        STOP 'Abnormal stop: errors found.'
      END
 
C
C
C 
      SUBROUTINE READ_SPOUT_ITEMS(
     I                            STDOUT, LINE, NITEM, ITEM_START,
     I                            ITEM_END,
     M                            EFLAG,
     O                            BRAIN, NAME, HEAD1, HEAD2, TABID)
  
C     Get the items of data from a line of input to OUTIN

      IMPLICIT NONE
      INTEGER STDOUT, NITEM, ITEM_START(NITEM), ITEM_END(NITEM),
     A         EFLAG, BRAIN
      
      CHARACTER LINE*(*), NAME*16, HEAD1*7, HEAD2*7, TABID*16

C     Local

      INTEGER IE, IS, N
      CHARACTER TPC*20

C     Called program units
      EXTERNAL STRIP_L_BLANKS
C     ***********************FORMATS************************************
50    FORMAT(/,' *ERR:379* Only ',I3,' items given in ',
     A   'SPECIAL-OUTPUT line.  Need at least two items.')
C***********************************************************************
      IF(NITEM.LT.2) THEN
        WRITE(STDOUT,50) NITEM
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      N = 1
C     Process the branch field. 
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      READ(TPC,'(I10)',ERR=991) BRAIN

C     Process the NAME field
      N = 2
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      NAME = TPC

C     Process HEAD1
      IF(NITEM.GE.3) THEN
        N = 3
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_L_BLANKS(
     M                      TPC)
        HEAD1 = TPC
      ELSE
        HEAD1 = ' '
      ENDIF

C     Process HEAD2
      IF(NITEM.GE.4) THEN
        N = 4
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_L_BLANKS(
     M                      TPC)
        HEAD2 = TPC
      ELSE
        HEAD2 = ' '
      ENDIF

C     Process TABID
      IF(NITEM.GE.5) THEN
        N = 5
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_L_BLANKS(
     M                      TPC)
        TABID = TPC
      ELSE
        TABID = ' '
      ENDIF

      RETURN
991   CONTINUE
      WRITE(STDOUT,52) TPC
52    FORMAT(/,' *ERR:500* Conversion error in: ',A)
      EFLAG = 1
      RETURN

      END
C
C
C
      SUBROUTINE   OUTIN
     I                  (BRPT, NBRA, NRWTA, RWTA, RTAP, STYLE,
     O                   POUT, NOUT, UNIT)
 
C     + + + PURPOSE + + +
C     Input the nodes at which special output is to be created.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER NBRA, NOUT, NRWTA, STYLE, UNIT
      INTEGER BRPT(8,NBRA), POUT(MNSOUT), RTAP(MNFREE),
     A        RWTA(MNFREE)
 
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
C     NBRA   - number of branches in the model
C     NRWTA  - number of reservoirs with tributary area
C     RWTA   - reservoirs with tributary area
C     RTAP   - reservoir tributary area pointer
C     STYLE  - style for special output.
C     STYLE  - flag to set the style of output
C     POUT   - pointer to the value to output
C     NOUT   - number of special outputs
C     UNIT   - unit number
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'misccon.cmn'
      INCLUDE 'xscom.cmn'
      INCLUDE 'namcom.cmn'
      INCLUDE 'julian.cmn'
      INCLUDE 'gatcom.cmn'
      INCLUDE 'spout.cmn'
      INCLUDE 'home.cmn'
      include 'datetime.cmn'
      include 'svn.cmn'
 
C     + + + LOCAL VARIABLES + + +

      INTEGER MAXN
      PARAMETER (MAXN=5)
      INTEGER BRA, BRAIN, FA, FN, I, IOFLAG, IP, IT, ITT, J, LN, 
     A        NDE, NODE, TABLE_NUMBER, NITEM, NXT, ITEM_START(MAXN),
     B        ITEM_END(MAXN)
      CHARACTER  HEAD*196, HEAD1*7, HEAD2*7, LINE*196, NAME*16,
     A          OUTNAM*256, tpc*196, TABID*16, JUST*5, CHAR5*5,
     b          sponam*256
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + EXTERNAL FUNCTIONS + + +
      integer get_unit
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETINB, GETINN, GETTOK, inline, KIL, LSTAB, FREE_UNIT,
     A         GET_INTERNAL_TAB_NUMBER, STRIP_L_BLANKS,
     B         GET_ITEM_LIMITS, READ_SPOUT_ITEMS, get_unit
 
C     + + + INPUT FORMATS + + +
 1    FORMAT(5X,A)
C 3    FORMAT(A)
 5    FORMAT(I5,A5,1X,2A7,1X,A16)
 
C     + + + OUTPUT FORMATS + + +
 2    FORMAT(' Special output file name= ',A)
 4    FORMAT(' Brnch Node/Name------- Head1-- Head2-- Main-Chan-Tabid-')
 6    FORMAT(I6,1X,A16,1X,A7,1X,A7,1X,A16)
 7    FORMAT(' *ERR:147* Output requested at too many nodes. NOUT = ',
     1   I5)
 8    format('Q brnch ',i5,' nd ',a7, 2x,2a8)
 9    format('Z brnch ',i5,' nd ',a7, 2x,2a8)


 50   FORMAT(2I5,2F15.7,I5)
 52   FORMAT(' *ERR:172* Exterior node',A5,' does not have trib.',
     A    ' area or is not a reservoir.')
54    FORMAT(/,' *ERR:279* Special output style must be multi-line for',
     A    ' output of more than two values per location.')
58    FORMAT(/,' *WRN:58* No home name found following HOME=. ',
     A         ' Home name cleared.')
59    FORMAT(/,' Home directory/drive is: ',A)
86    format(';Version number is ',i8,' for the Subversion working ',
     a         'copy') 
87    format(';*WRN:XXX* The working copy contains local ',
     a 'modifications.',/,';',5x,
     b 'The version number given is therefore',
     b' not current and may not properly',/,';',5x,
     b  'provide the version',
     c' number required to retrieve all the same files ',
     d'at a later time.')
C***********************************************************************
      CALL CLEAR_HOME()
      JUST = 'RIGHT'
      SPOUT_STYLE = STYLE
      CALL inline
     I          (IN, STDOUT,
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
          WRITE(STDOUT,58) 
          HOME = ' '
C          STOP 'Abnormal stop: errors found.'
        ENDIF
        CALL STRIP_L_BLANKS(
     M                      HOME)
        IT = LEN_TRIM(HOME)
        WRITE(STDOUT,59) HOME(1:IT)

        CALL inline
     I            (IN, STDOUT,
     O             LINE)
      ENDIF

      READ(LINE,1,ERR=991) tpc
      CALL PROCESS_OLD_IOUNITS(STDOUT, tpc,
     O                               stdspout, OUTNAM)
      CALL MAYBE_ADD_GHOME_OUT(
     M                    OUTNAM)
      call maybe_add_ext(
     m                    outnam)

      call os_file_style(
     m                       outnam)
      WRITE(STDOUT,2) OUTNAM
      IF(stdspout.NE.0) THEN
        OPEN(UNIT=stdspout, FILE=OUTNAM, STATUS='UNKNOWN',IOSTAT=IOFLAG)
        IF(IOFLAG.NE.0) THEN
          IT = LEN_TRIM(OUTNAM)
          WRITE(STDOUT,*) ' Problem in opening file: ',OUTNAM(1:IT)
          WRITE(STDOUT,*) ' Check path for Special Output File.'
          STOP 'Abnormal stop: errors found.'
        ENDIF
c       create the descriptor file.
        stdspo = get_unit(stdout)
        call trim_last_extension(outnam, 
     o                         sponam)
        it = len_trim(sponam)
        sponam = sponam(1:it)//'.spi'
        call maybe_add_ext(
     m                     sponam)

        OPEN(UNIT=stdspo, FILE=sponam, STATUS='UNKNOWN',IOSTAT=IOFLAG)
        IF(IOFLAG.NE.0) THEN
          IT = LEN_TRIM(sponam)
          WRITE(STDOUT,*) ' Problem in opening file: ',sponam(1:IT)
          WRITE(STDOUT,*) ' Check path for Special Output File.'
          STOP 'Abnormal stop: errors found.'
        ENDIF

c       Output the version/run date-time string.  Note:  Only written to 
c       this file.  Users must keep this file in order to document the 
c       special-output file:)
        write(stdspo,'(a)') '; Written by program feq:'
        write(stdspo,'(a1,a)') ';',version_run_date_time_string
        write(stdspo,
     a    "('; Source code repository location and revision are:')")
        it = len_trim(url)
        write(stdspo,"(';',a)") url(1:it)
        it = len_trim(revision)
        write(stdspo,"(';',a)") revision(1:it)
        if(svn_rev >0 ) then
          write(stdspo,86) svn_rev
          if(svn_mod > 0) then
            write(stdspo,87)
          endif
        endif
        
        write(stdspo,2) outnam(1:len_trim(outnam))
        write(stdspo,4)
      ENDIF
 
C     Clear the counter for extra output items.  Flow and elevation
C     are always output.  Extra items are defined in an optional
C     OPTIONS input line.
 
      SPOUT_KNT = 0
 
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
 
C     Check for optional line of input.
      IF(LINE(1:8).EQ.'OPTIONS='.OR.LINE(1:8).EQ.'options=') THEN
C       We have an options line to process.
        IF(SPOUT_STYLE.NE.2) THEN
          WRITE(STDOUT,54) 
          STOP 'Abnormal stop: errors found.'
        ENDIF       
        WRITE(STDOUT,'(A)') LINE
        CALL SET_SPOUT_OPTIONS(STDOUT, LINE(9:80), EFLAG)
 
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
      ENDIF
 
      LINE_KNT = SPOUT_KNT + SPOUT_STYLE
       HEAD = LINE
C      WRITE(STDOUT,4) HEAD
      WRITE(STDOUT,4)

C     Get the column limits as defined by the user heading items.

      CALL GET_ITEM_LIMITS(
     I                     STDOUT, HEAD, MAXN, JUST,
     O                     NITEM, ITEM_START, ITEM_END)
 
      NOUT = 0
 100    CONTINUE
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
C        READ(LINE,5,ERR=991) BRAIN, CHAR5, HEAD1, HEAD2,
C     A                       TABID
        CALL READ_SPOUT_ITEMS(
     I                        STDOUT, LINE, NITEM, ITEM_START,
     I                        ITEM_END,
     M                        EFLAG,
     O                        BRAIN, NAME, HEAD1, HEAD2, TABID)
        IF(BRAIN.LT.0) GOTO 150
        IF(TABID.EQ.' ') THEN
          WRITE(STDOUT,6) BRAIN, NAME, HEAD1, HEAD2
          WRITE(stdspo,8) BRAIN, NAME, HEAD1, HEAD2
          WRITE(stdspo,9) BRAIN, NAME, HEAD1, HEAD2
          TABLE_NUMBER = 0
        ELSE
          WRITE(STDOUT,6) BRAIN, NAME, HEAD1, HEAD2, TABID
          CALL STRIP_L_BLANKS(
     M                        TABID)
          CALL GET_INTERNAL_TAB_NUMBER
     I                                (STDOUT, TABID,
     M                                 EFLAG,
     O                                 TABLE_NUMBER)
        ENDIF
        NOUT = NOUT +1
        IF(NOUT.LE.MNSOUT) GOTO 110
        WRITE(STDOUT,7) NOUT
        NOUT = 1
        EFLAG = 1
 110    CONTINUE
        SPHEAD(NOUT,1) = HEAD1
        SPHEAD(NOUT,2) = HEAD2
        SPOUT_MAIN_CHANNEL_TABLE(NOUT) = TABLE_NUMBER
 
 
C       CATCH THE SPECIAL DESIGNATION FOR MCHENRY SLUICE GATES
        IF(NAME.EQ.'MCHN') THEN
          POUT(NOUT) = -20000
          GOTO 100
        ENDIF
 
C       Now check if the node designation field has a name for
C       an adjustable gate.
        IF(NGATE.GT.0) THEN
          CALL LSTAB
     I              (NAME, GNAME, NGATE,
     O              IP)
        ELSE
          IP = 0
        ENDIF
        IF(IP.GT.0) THEN
C         Name found in the table.  Add pointer to 20000 and store
C         negative value as a flag to a special value.
          POUT(NOUT) = -(20000 + IP)
          GOTO 100
        ENDIF
 
 
        IF(BRAIN.NE.0) GOTO 120
        CHAR5 = NAME 
C       EXTERIOR NODE
           CALL GETINN
     M                (CHAR5,
     O                 EFLAG, NODE)
           IF(NODE.GT.0) THEN
             POUT(NOUT) = -NODE
           ELSE
C            ONLY RESERVOIR NODES WITH TRIBUTARY AREA ARE VALID
C            HERE.
             NODE = ABS(NODE)
             DO 112 I=1,NRWTA
               IF(NODE.EQ.RWTA(I)) THEN
                 POUT(NOUT) = -(RTAP(I) + 10000)
                 GOTO 100
               ENDIF
 112         CONTINUE
             WRITE(STDOUT,52) CHAR5
             EFLAG = 1
           ENDIF
           GOTO 100
 120    CONTINUE
        READ(NAME,'(I10)',ERR=991) NODE
C        BRA = GETINB(BRAIN, EFLAG)
        CALL GETINB
     M             (BRAIN,
     O              EFLAG, BRA)
        FN = BRPT(1,BRA)
        LN = BRPT(2,BRA)
        FA = BRPT(3,BRA)
        IF(ABS(NODE).LT.FN.OR.ABS(NODE).GT.LN) THEN
          NDE = ABS(NODE)
          CALL KIL
     I             (2,
     M              NDE, EFLAG)
          NODE = -NDE
        ENDIF
 
C       COMPUTE ADDRESS FOR THIS BRANCH AND NODE NUMBER
 
        IF(NODE.GT.0) THEN
          POUT(NOUT) = FA + NODE - FN
        ELSE
         POUT(NOUT) = FA + ABS(NODE) - FN + 10000
        ENDIF
 
        GOTO 100
 
 150  CONTINUE
C     Make sure that the number of lines  per page is
C     an integral multiple of the LINE_KNT plus 2.
      IT = PAGESP - 2
      ITT = MOD(IT,LINE_KNT)
      IF(ITT.NE.0) THEN
        IT = IT - ITT
        PAGESP = IT + 2
      ENDIF
C     WRITE CURRENT VALUE OF PAGESP TO THE FIRST LINE OF THE FILE
      IF(NOUT.GT.0)  then
        WRITE(stdspout,50) PAGESP, NOUT, UJTIME, VJTIME, LINE_KNT
        write(stdspo,'(a)') 'end'
        WRITE(stdspo,50) PAGESP, NOUT, UJTIME, VJTIME, LINE_KNT
c       clear the record count
        spo_knt = 0      
      endif

      IF(SPOUT_KNT.GT.0) THEN
C       Clear the extra buffer space so that only those items
C       that are meaningfull need to be set in subroutine OUTSP.
        DO 200 I=1,NOUT
          DO 190 J=1,SPOUT_KNT
            EXTRA_BUFFER(I,J) = ' '
190       CONTINUE
200     CONTINUE
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
c      SUBROUTINE   PFIN
c     I                 (IN, STDOUT, MLPNT, NBRA, BRPT,
c     O                  EFLAG, LPNT, MF, PFPNT)
c 
cC     + + + PURPOSE + + +
cC     Input the point load information.
c 
c      IMPLICIT NONE
cC     + + + DUMMY ARGUMENTS + + +
c      INTEGER EFLAG, IN, STDOUT, LPNT, MLPNT, NBRA
c      INTEGER BRPT(8,NBRA), PFPNT(3,MLPNT)
c      REAL MF(MLPNT)
c 
cC     + + +DUMMY ARGUMENT DEFINITIONS + + +
cC     IN     - unit number for the user input file
cC     STDOUT   - Fortran unit number for user output and messages
cC     MLPNT  - maximum length of the point load pointer arrays
cC     NBRA   - number of branches in the model
cC     BRPT   - branch pointer table.  Values for each branch are:
cC              ROW       Meaning
cC              1         upstream user node number
cC              2         downstream user node number
cC              3         pointer into branch vector for upstream node
cC              4         pointer into branch vector for downstream node
cC              5         upstream exterior node number
cC              6         downstream exterior node number
cC              7         pointer to address in EMC for the branch
cC              8         number of unknowns at a node for the branch
cC     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
cC     LPNT   - length of the point load point load array
cC     MF     - momentum flux value
cC     PFPNT  - point flow pointer array
c 
cC     + + + LOCAL VARIABLES + + +
c      INTEGER BRA, BRAIN, NODE, TABLE, TYPE
c      REAL MFAC
c      CHARACTER LINE*80, NODEIN*5, TABID*16
c 
cC     + + + EXTERNAL NAMES + + +
c      EXTERNAL GETINB, GETINN, inline, KIL, KILC,
c     A         STRIP_L_BLANKS, GET_INTERNAL_TAB_NUMBER
c 
cC     + + + INPUT FORMATS + + +
c 35   FORMAT(I5,A5,I5,A16,F10.0)
c 
cC     + + + OUTPUT FORMATS + + +
c 36   FORMAT(' ',I5,A5,I5,1X,A16,F10.5)
cC***********************************************************************
c      LPNT = 1
c 1000 CONTINUE
c         CALL inline
c     I             (IN, STDOUT,
c     O              LINE)
c         READ(LINE,35,ERR=991) BRAIN, NODEIN, TYPE, TABID, MFAC
c         IF(BRAIN.EQ.-1) GOTO 2000
c         WRITE(STDOUT,36) BRAIN, NODEIN, TYPE, TABID, MFAC
c         CALL GETINB
c     M              (BRAIN,
c     O               EFLAG, BRA)
c          CALL GETINN
c     M               (NODEIN,
c     O                EFLAG, NODE)
c          CALL STRIP_L_BLANKS(
c     M                        TABID)
c          CALL GET_INTERNAL_TAB_NUMBER
c     I                                (STDOUT, TABID,
c     M                                 EFLAG,
c     O                                 TABLE)
c          
c         IF(NODE.LT.BRPT(1,BRA).OR.NODE.GT.BRPT(2,BRA))
c     1      CALL KILC
c     I                (NODEIN, -2,
c     M                 EFLAG)
c         IF(TYPE.LE.0.OR.TYPE.GT.2) CALL KIL
c     I                                       (18,
c     M                                        TYPE, EFLAG)
c         IF(NODE.EQ.BRPT(1,BRA)) CALL KILC
c     I                                     (NODEIN, -28,
c     M                                      EFLAG)
c 
cC     TABLE IDS WILL BE CHECKED ELSEWHERE
c 
c         IF(LPNT.GE.MLPNT) CALL KIL
c     I                              (19,
c     M                               LPNT, EFLAG)
c         PFPNT(1,LPNT) = TYPE
c         PFPNT(2,LPNT) = TABLE
c         MF(LPNT) = MFAC
c 
cC     COMPUTE THE NODE LOCATION IN THE BRANCH VECTORS
c 
c         PFPNT(3,LPNT) = BRPT(3,BRA)-BRPT(1,BRA)+NODE
c         LPNT = LPNT+1
c         GOTO 1000
c 2000 CONTINUE
c      PFPNT(1,LPNT) = -1
c      LPNT = LPNT-1
c      RETURN
c 991  CONTINUE
c        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
c        WRITE(STDOUT,*) LINE
c        STOP 'Abnormal stop: errors found.'
c      END

C
C
C
      SUBROUTINE   RDFIN
     I                  (IN, STDOUT,
     M                   EFLAG)
 
C     + + + PURPOSE + + +
C     Read user input specifing time-series found in one or
C     more files or data storage and retrieval systems.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, IN, STDOUT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     STDOUT   - Fortran unit number for user output and messages
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'rdcom.cmn'
      INCLUDE 'home.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER DSS_INDEX, HECDSS, TIME_STEP, MAX_KNT, ITEM_KNT,
     A        I, IT, NXT

      INTEGER  CHRVAL, INTVAL
      PARAMETER(INTVAL=1, CHRVAL=4)

      PARAMETER (MAX_KNT=3)
      INTEGER ITEM_LENGTH(MAX_KNT), ITEM_TYPE(MAX_KNT),
     A        TERM_CLASS(MAX_KNT), UN

      CHARACTER HEAD*196, LINE*196, NAME*256, 
     A          ITEMS(MAX_KNT)*128, TS_ID_FOR_FILE*16,
     B          C_FACTOR*10, WORK*256

      REAL FACTOR

C     + + + EXTERNAL NAMES + + +
      INTEGER GET_UNIT
      EXTERNAL inline, KIL, GET_UNIT
 
C     + + + INPUT FORMATS + + +
 1    FORMAT(A)
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' ',A)
 51   FORMAT(1X,A)
 52   FORMAT(/,' *ERR:150* Number of input files requested is larger',
     A       'than the current maximum of:',I3)
53    FORMAT(/,' *ERR:260: Path name:',/,1X,A,/,11X,' does not exist.')
54    FORMAT(/,' *ERR:280* Expected -1 to terminate input but ',
     A         A,' found instead.')
56    FORMAT(/,' *ERR:281* Expected time series id as an integer or',
     A    ' an identifier. Found:',/,5X,A,' instead.')
58    FORMAT(/,' *ERR:282* Expected a file name but found:',/,5X,A,
     A       ' instead.')
60    FORMAT(/,' *ERR:283* Expected a conversion factor but found:',/,
     A           5X,A,' instead.')
62    FORMAT(/,' *ERR:284* Found ',I3,' file definitions but',
     A   ' there are only',/,5X,I3,' unique time-series ids.',
     B   ' Check for duplicate ids.')
64    FORMAT(/,' *ERR:285* Something wrong with termination of',
     A         ' time-series file input. FLAG=',I5)
66    FORMAT(/,' *ERR:286* No path name found for HEC DSS',
     A        ' access.')
68    FORMAT(/,' *ERR:287* Item given as conversion factor=',
     A     A,' is not a valid number.')
70    FORMAT(5X,' Factor on values in file=',1PE12.5)
72    FORMAT(/,
     A' *ERR:411* Expected at most 3 items in line but found:',I5,/,
     B  5X,'Check for special characters:-,+, and so forth in',
     C'  a file name.')
73    FORMAT(/,' Home directory/drive is: ',A)
74    FORMAT(/,' *WRN:58* No home name found following HOME=. ',
     A         ' Home name cleared.')
C***********************************************************************
      CALL CLEAR_HOME()
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,1) HEAD
      WRITE(STDOUT,50) HEAD(1:len_trim(head))
      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,1) HEAD
      WRITE(STDOUT,50) HEAD(1:len_trim(head))

      ID_KNT = 0 
      NUM_TS_F = 0
      HECDSS = 0
 100  CONTINUE
        CALL inline
     I          (IN, STDOUT,
     O           LINE)
      
C       Make indentation possible for HOME variable without changing
C       the other processing. 
        WORK = LINE
        CALL STRIP_L_BLANKS(
     M                      WORK)

C       Catch the special input line used to switch to special
C       data storage and retrieval systems.   
        IF(LINE(1:6).EQ.'HECDSS') THEN
C         Get a HECDSS file name and set the flag.
          IF(LINE(8:9).NE.'  ') THEN
            HECDSS = 1
            CALL PROCESS_HECDSS_NAME(STDOUT, LINE(8:71), DSS_INDEX,
     A                     'INPUT', EFLAG)
            WRITE(STDOUT,50) HEAD(1:len_trim(head))
          ELSE
            HECDSS = 0
          ENDIF
C         Get the next line.
          CALL inline
     I              (IN, STDOUT,
     O               LINE)
        ELSEIF(WORK(1:4).EQ.'HOME'.OR.WORK(1:4).EQ.'home') THEN
          HECDSS = 0
          IT = INDEX(WORK, '=')
          NXT = IT + 1
          CALL NXTTOK
     I               (WORK,
     M                NXT,
     O                HOME)
          IF(NXT.LE.0) THEN
            WRITE(STDOUT,74)
            HOME = ' '
          ENDIF
          CALL STRIP_L_BLANKS(
     M                        HOME)
          IT = LEN_TRIM(HOME)
          WRITE(STDOUT,73) HOME(1:IT)

          CALL inline 
     I              (IN, STDOUT,
     O               LINE)
          
        ENDIF

        WRITE(STDOUT,51) LINE

        IF(HECDSS.EQ.0) THEN
C         Get non HECDSS file names: no spaces, no dashes,
C         no funny stuff. 

          CALL GET_ITEMS(STDOUT, LINE, MAX_KNT,
     O                     ITEM_KNT, ITEMS, ITEM_LENGTH, 
     O                     ITEM_TYPE, TERM_CLASS, EFLAG)

          IF(EFLAG.EQ.0) THEN
C           Process the info.  We expect one, two or three items per 
C           line of input.  If two, first is the TS_ID for the file.
C           The TS_ID is the way the user references the time series.            
C           The second is the file name for whatever system is               
C           active: HECDSS path name if HECDSS=1, or an operating            
C           system file name:DOS, UNIX, or Windows NT.                       
C           The third value, optional, is a conversion factor to             
C           apply to the file values before they are used.                   
C           The number of items has been checked in GET_ITEMS                
C           so that the number is no more than three here.                   
C           The number of items could be zero, meaning that the              
C           line was not blank but had only non-printing characters          
C           or has a quoted comment on it.                                   
C           If there is one item it should be the terminating flag.          
                                                                        
            IF(ITEM_KNT.EQ.1) THEN                                      
C             Should be terminating signal.                             
              IF(ITEM_TYPE(1).EQ.INTVAL) THEN                           
                READ(ITEMS(1)(1:3), '(I3)') UN                          
                IF(UN.EQ.-1) THEN                                       
                  GOTO 900                                              
                ELSE                                                    
                  WRITE(STDOUT,64) UN                                   
                  STOP 'Abnormal stop: errors found.'                   
                ENDIF                                                   
                                                                        
              ELSE                                                      
                WRITE(STDOUT,54) ITEMS(1)(1:ITEM_LENGTH(1))             
                STOP 'Abnormal stop: errors found.'                     
              ENDIF                                                     
            ELSEIF(ITEM_KNT.EQ.2.OR.ITEM_KNT.EQ.3) THEN                 
C             This would be the time series id plus the                 
C             file name,  or conver. factor.               
              IF(ITEM_TYPE(1).EQ.INTVAL.OR.                             
     A           ITEM_TYPE(1).EQ.CHRVAL) THEN                           
                 TS_ID_FOR_FILE = ITEMS(1)                              
              ELSE                                                      
                WRITE(STDOUT,56) ITEMS(1)(1:ITEM_LENGTH(1))             
                STOP 'Abnormal stop: errors found.'                     
              ENDIF                                                     
              IF(ITEM_TYPE(2).EQ.CHRVAL) THEN                           
                 NAME = ITEMS(2)
                 CALL MAYBE_ADD_HOME(
     M                               NAME) 
                 call os_file_style(
     m                                name)                             
              ELSE                                                      
                WRITE(STDOUT,58) ITEMS(2)(1:ITEM_LENGTH(2))             
                STOP 'Abnormal stop: errors found.'                     
              ENDIF                                                     
              IF(ITEM_KNT.EQ.3) THEN                                    
                IF(ITEM_TYPE(3).NE.CHRVAL) THEN                         
                  READ(ITEMS(3)(1:ITEM_LENGTH(3)),*) FACTOR             
                ELSE                                                    
                  WRITE(STDOUT,60) ITEMS(3)(1:ITEM_LENGTH(2))           
                  STOP 'Abnormal stop: errors found.'                   
                ENDIF                                                   
              ELSE                                                      
                FACTOR = 1.0                                            
              ENDIF                                                     
            ELSE
              WRITE(STDOUT, 72) ITEM_KNT
              STOP 'Abnormal stop: errors found.'
            ENDIF                                                       
          ENDIF

        ELSE
C         Get the funny pathnames used by HECDSS-spaces,
C         dashes and who knows what else will appear.

C         There will always be, if things are correct,
C         a time-series id of some sort.  This will be an
C         integer or an identifier. 
          WRITE(STDOUT,*) LINE

          NXT = 1
          CALL NXTTOK
     I               (LINE,
     M                NXT,
     O                TS_ID_FOR_FILE)
          IF(NXT.LE.0) THEN
C           Nothing found. 
            WRITE(STDOUT,*) 
     A          ' Bug: blank line in RDFIN.'
            STOP 'Abnormal stop: errors found.'
          ENDIF          
          IF(TS_ID_FOR_FILE.EQ.'-1') GOTO 900

          CALL  GET_HECDSS_PATH(LINE,
     M                          NXT,
     O                          NAME, EFLAG)
          IF(NXT.LT.0) THEN
            WRITE(STDOUT,66) 
            STOP 'Abnormal stop: errors found.'
          ENDIF

          IF(NXT.GT.0) THEN
C           Now look for the optional conversion factor.
            CALL NXTTOK
     I                 (LINE,
     M                  NXT,
     O                  C_FACTOR)
            IF(NXT.GT.0) THEN
              READ(C_FACTOR,'(F10.0)',ERR=200) FACTOR
              GOTO 210
200           CONTINUE
                WRITE(STDOUT,68) C_FACTOR
                STOP 'Abnormal stop: errors found.'
210           CONTINUE
            ELSE
              FACTOR = 1.0
            ENDIF
          ELSE
            FACTOR = 1.0
          ENDIF
        ENDIF
      
        WRITE(STDOUT,70) FACTOR   
        IF(EFLAG.EQ.0) THEN
C         Do additional checking of the input.  
          IF(HECDSS.EQ.1) THEN
C           Check the path name and get the nature of the time
C           step and its numeric value.
            CALL PROCESS_HECDSS_PATH_NAME(STDOUT, NAME, TIME_STEP,
     A                                    EFLAG)
            IF(EFLAG.EQ.0) THEN
C              CALL CHECK_EXIST(DSS_INDEX, NAME, IERR)
C              IF(IERR.GT.0) THEN
C                WRITE(STDOUT,53) NAME
C                STOP 'Abnormal stop: errors found.'
C              ENDIF
            ENDIF
          ELSE
C           Assign a unit for the file. 
            UN = GET_UNIT(STDOUT)
          ENDIF
 
          NUM_TS_F = NUM_TS_F + 1
          IF(NUM_TS_F.GT.MXN_TS) THEN
            WRITE(STDOUT, 52) MXN_TS
            NUM_TS_F = MXN_TS
            EFLAG = 1
          ENDIF
      
C         Add the time-series id to the table
C         to detect duplicates. 
          CALL  LSATAB
     I             (STDOUT, TS_ID_FOR_FILE, MXN_TS,
     M                TS_ID_FOR_FILE_TABLE, ID_KNT,
     O                I, EFLAG)
    
          TS_CONVERSION_FACTOR(NUM_TS_F) = FACTOR
          NAMIN(NUM_TS_F) = NAME
          IF(HECDSS.EQ.0) THEN
            UNIN(NUM_TS_F) = UN
            DSS_INDEX_IN(NUM_TS_F) = 0
            TIME_STEP_IN(NUM_TS_F) = 0
          ELSE
            DSS_INDEX_IN(NUM_TS_F) = DSS_INDEX
            TIME_STEP_IN(NUM_TS_F) = TIME_STEP
          ENDIF
          GOTO 100
        ENDIF
 
900     CONTINUE

        IF(ID_KNT.NE.NUM_TS_F) THEN
          WRITE(STDOUT,62) NUM_TS_F, ID_KNT
          STOP 'Abnormal stop: errors found.'
        ENDIF

        IF(EFLAG.NE.0) THEN
          STOP 'Abnormal stop: errors found.'
        ENDIF          
        RETURN
        END


C     ***********
C     *         *
C     * FILL_VAR_DECIMAL_VECTOR
C     *         *
C     ***********
      
      SUBROUTINE FILL_VAR_DECIMAL_VECTOR(N, X,
     A                                  RESULT)

C     Fill a vector of character strings, RESULT, of fixed length, 
C     with the values in the real vector, X, using a variable
C     number of decimal places so that each number will have
C     a near optimum number of digits appearing. 

      IMPLICIT NONE
      INTEGER N

      REAL X(N)

      CHARACTER*(*) RESULT(N)

C     Local

      INTEGER I

      EXTERNAL VAR_DECIMAL
C***********************************************************************

      DO 100 I=1,N
        CALL VAR_DECIMAL(X(I), 
     O                   RESULT(I))
100   CONTINUE
      RETURN
      END


C
C
C
C     ***********
C     *         *
C     * STORE_BRANCH_TRIB_AREA
C     *         *
C     ***********

      SUBROUTINE STORE_BRANCH_TRIB_AREA(STDOUT, GAGE, GEND, GSTART,
     I         XVEC, UNODE, DNODE, IBRA, A1,
     M         TAM_IPNT, TAM_FPNT, TUNIT_KNT, BACK_PNT, TAM_ITAB, 
     M         TAM_FTAB, TRIBA, LAST_NDTA_PNT)


C     Create the entries for tributary area to a branch in the 
C     tributary-area management system. Applies to a branch as
C     a unit, including all the computational elements on the 
C     branch as well as to a single computational element or 
C     a consecutive sequence of computational elements. 

      IMPLICIT NONE
      INCLUDE 'arsize.prm'

      INTEGER STDOUT, GAGE, GEND(0:MXGAGE), GSTART(0:MXGAGE), IBRA,
     A        UNODE, DNODE, TAM_IPNT, TAM_FPNT, TUNIT_KNT, BACK_PNT, 
     B        LAST_NDTA_PNT, TAM_ITAB(TAM_MXNI)

      REAL  TAM_FTAB(TAM_MXNF), TRIBA(MXR_TRIBA,MXN_LU_G), 
     A      A1(MXN_LU_G), XVEC(MNBN)

C     Local

      INTEGER J, K
      
      REAL STRLEN, ELEN
C     **********************************FORMATS*************************
 54   FORMAT(/,' *ERR:358* Trib area management requires',I3,
     A       ' locations in TAM_TAB but only',I3,' are available.')
 55   FORMAT(/,' Diffuse TSF name=',A)
 57   FORMAT(/,' *ERR:359* Trib area management requires',I3,
     A       ' locations in TRIBA but only',I3,' are available.')
 58   FORMAT(/,' *ERR:360* Trib area management requires',I3,
     A       ' locations in TAM_FTAB but only',I3,' are available.')
C***********************************************************************
C     Set the pointer to the trib area unit so that we can
C     find it if subsequent lines defining detention or delay
C     are found.   Trib area is assumed to have no detention
C     until the user tells us otherwise. 
      LAST_NDTA_PNT = TAM_IPNT
      IF(TAM_IPNT+9.GT.TAM_MXNI) THEN
        WRITE(STDOUT, 54) TAM_IPNT+9, TAM_MXNI
        STOP 'Abnormal stop: errors found.'
      ELSE
C       Set the forward pointer in the previous
C       trib area unit, if there is any.
        IF(BACK_PNT.GT.0) THEN
          TAM_ITAB(BACK_PNT+2) = TAM_IPNT
          BACK_PNT = TAM_IPNT
        ELSE
          BACK_PNT = TAM_IPNT
        ENDIF
C       Store the stuff.
        TAM_ITAB(TAM_IPNT) = ABS(IBRA)
C       Set the category code for a branch
        TAM_ITAB(TAM_IPNT+1) = 1
C       Clear the forward pointer to terminate
C       if this is the last trib area unit. 
        TAM_ITAB(TAM_IPNT+2) = 0
C       Store the nodes delimiting range of this unit
        TAM_ITAB(TAM_IPNT+7) = UNODE + 1
        TAM_ITAB(TAM_IPNT+8) = DNODE
C       Check counter for storing the distribution factors
        IF(TAM_FPNT+(DNODE-UNODE).GT.TAM_MXNF) THEN
          WRITE(STDOUT, 58) TAM_FPNT, TAM_MXNF
          STOP 'Abnormal stop: errors found.'
        ENDIF
C        WRITE(STDOUT,*) ' Pointer to first dist. factor=',TAM_FPNT
        TAM_ITAB(TAM_IPNT+9) = TAM_FPNT
C       Store the tributary areas. 
        TUNIT_KNT = TUNIT_KNT + 1
        IF(TUNIT_KNT.GT.MXR_TRIBA) THEN
          WRITE(STDOUT, 57) TUNIT_KNT, MXR_TRIBA
          STOP 'Abnormal stop: errors found.'
        ELSE
          TAM_ITAB(TAM_IPNT+3) = TUNIT_KNT
          TAM_ITAB(TAM_IPNT+4) = GAGE
C         Store the trib area
          DO 412 J=1, GEND(GAGE)-GSTART(GAGE)+1
            TRIBA(TUNIT_KNT,J) = A1(J)
 412      CONTINUE

C         Compute the distribution coefficients.
C         Find length of branch or branch fragment associated 
C         with this tributary area unit. TAM_FPNT points to 
C         the next OPEN slot in TAM_FTAB not the last USED
C         slot in TAM_FTAB.
 
          STRLEN = ABS(XVEC(UNODE) - XVEC(DNODE))
C          WRITE(STDOUT,*) ' UNODE=',UNODE,' DNODE=',DNODE
          DO 420 K=UNODE+1,DNODE
            ELEN = ABS(XVEC(K) - XVEC(K-1))
            TAM_FTAB(TAM_FPNT+K-UNODE-1) = ELEN/STRLEN
 420      CONTINUE
          TAM_FPNT = TAM_FPNT + DNODE - UNODE 
C          WRITE(STDOUT,*) ' TAM_FPNT=',TAM_FPNT
        ENDIF

C       Clear the pointers for detention and delay
C       descriptions. 
        TAM_ITAB(TAM_IPNT+5) = 0
        TAM_ITAB(TAM_IPNT+6) = 0

        TAM_IPNT = TAM_IPNT + 10
      ENDIF

      RETURN
      END
C
C
C
      SUBROUTINE   TRIBIN
     I                   (DIFFUS, SFAC, IN, STDOUT, NBN, NBRA, BRPT, 
     I                    NEX, GRAV, TAUFAC,
     M                    EFLAG, ENODEN,
     O                    NLUSE, TSFDSN, FFFDSN, TRIBA, QPN, NRWTA,
     O                    RTAP, RWTA, GEND, GSTART, RTAFAC,
     O                    TAFAC)
 
C     + + + PURPOSE + + +
C     Input the tributary area.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      CHARACTER DIFFUS*4
      INTEGER EFLAG, ENODEN, FFFDSN, IN, STDOUT, NBN, NBRA, NEX, NLUSE,
     A        NRWTA, QPN, TSFDSN
      INTEGER BRPT(8,NBRA),  GEND(0:MXGAGE),
     A        GSTART(0:MXGAGE), RTAP(MNFREE), RWTA(MNFREE)
      REAL GRAV, RTAFAC(MNFREE), SFAC, TAUFAC, TAFAC(MNBRA),
     A     TRIBA(MXR_TRIBA,MXN_LU_G)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     DIFFUS - defines prescence of trib area and source of runoff
C     SFAC   - conversion factor from user stations to internal stations
C     IN     - unit number for the user input file
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
C     NEX    - max allocated number of exterior nodes in the model
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     ENODEN - internal exterior-node number
C     NLUSE  - number of land uses summed over all gages
C     TSFDSN - unit number for the time series file
C     FFFDSN - unit number for output of the flood frequency file
C     TRIBA  - tributary areas for the model
C     QPN    - number of lateral inflows
C     NRWTA  - number of reservoirs with tributary area
C     RTAP   - reservoir tributary area pointer
C     RWTA   - reservoirs with tributary area
C     GEND   - ending address for storing land uses for each gage
C     GSTART - starting address for storing land uses for each gage
C     RTAFAC - reservoir tributary area factor
C     TAFAC  - factor to adjust tributary areas
C     TAUFAC - global factor from the Run Control Block designed 
C              to convert units of the tributary area block. 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'bnelem.cmn'
      INCLUDE 'namcom.cmn'
      INCLUDE 'usintp.cmn'
      INCLUDE 'inusnb.cmn'
      INCLUDE 'dssdif.cmn'
      INCLUDE 'tam.cmn'
      INCLUDE 'dtendef.cmn'
      INCLUDE 'home.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER MAXITEMA, MAXITEMB
      PARAMETER (MAXITEMA=2, MAXITEMB=MXN_LU_G+3)
      INTEGER DNODE, FNODE, GAGE, GLU, I, IADRS, IB, IBRA, IBRAN, IT, J,
     A        LNODE, ND, NGAGE, NITEMA, NITEMB, NODE, NUM, QPNN,
     B        UNODE, USBRA, DSS_INDEX, TIME_STEP, N, BACK_PNT,
     C        LAST_NDTA_PNT, LAST_DTA_PNT
      INTEGER ITEM_STARTA(MAXITEMA), ITEM_ENDA(MAXITEMA),
     A        ITEM_STARTB(MAXITEMB), ITEM_ENDB(MAXITEMB)
      REAL CON_FAC, DSTAT, FAC,  NEGFAC, SFAC2, USTAT
      CHARACTER CHR5*5, ENF*5, HEAD*80, LINE*80, USNODE*5, LINE112*112,
     A          CHAR6(MXN_LU_G)*6, FAC_STRING*12,
     B          JUST*5
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER FNDNOD, INDEX, GET_UNIT
      CHARACTER GETTOK*5 
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL FNDINN, FNDNOD, GETINB, GETTOK, inline, KIL, 
     A         TRBOUT, PROCESS_OLD_IOUNITS, FILL_VAR_DECIMAL_VECTOR, 
     B         VAR_DECIMAL, GET_INTERNAL_TAB_NUMBER, GET_TABHD,
     C         GET_TABBRH, GET_LUSE_ITEMS, GET_UNIT, os_file_style
 
C     + + + INPUT FORMATS + + +
 1    FORMAT(A80)
 2    FORMAT(6X,I5)
C 3    FORMAT(7X,I5, 5X, F10.0,5X,F10.0)
 5    FORMAT(7X,A)
 6    FORMAT(6X,I5)
 7    FORMAT(2I5)
 8    FORMAT(A5,I5,12F6.0)
 9    FORMAT(2F10.0, I5, 12F6.0)
 10   FORMAT(2I5,12F6.0)
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(1X,A80)
 51   FORMAT(/,1X,A80)
 52   FORMAT(/,1X,'Number of land uses = ',I5)
 53   FORMAT(/,1X,'BRANCH = ',I5,' FAC=',A12)
 54   FORMAT(/,' *ERR:358* Trib area management requires',I3,
     A       ' locations in TAM_ITAB but only',I3,' are available.')
 55   FORMAT(/,' Diffuse TSF name= ',A)
 56   FORMAT(/,' Flood Frequency File name= ',A)
 57   FORMAT(/,' *ERR:359* Trib area management requires',I3,
     A       ' locations in TRIBA but only',I3,' are available.')
 58   FORMAT(/,' *ERR:361* Too many nodes given for branch=',I5)
 61   FORMAT(/,' *ERR:135* Nodes on a branch out of range or sequence',
     1      ' in Trib. Area input')
 62   FORMAT(/,' *ERR:136* Trib area for reservoirs requires',I3,
     A       ' locations in QPVEC but only',I3,' are available.')
 63   FORMAT(/,' *WRN:40* Branch number = 0 has been found more than',
     A       ' once in trib area input.')
 64   FORMAT(/,' Number of raingages = ',I5)
 65   FORMAT(/,' *ERR:138* Number of gages < 1 or > ',I5)
 66   FORMAT(' ',I5,I6)
 67   FORMAT(/,' *ERR:139* Gage number:',I5,' out of sequence')
 68   FORMAT(/,' *ERR:140* Sum of gage land uses in error')
 69   FORMAT(/,' *ERR:141* Gage number:',I5,' out of range')
 70   FORMAT(' ',A5,I5,12A6)
 71   FORMAT(' ',2I5,12A6)
 72   FORMAT( ' ',2F10.3, I5, 12A6)
 74   FORMAT(/,' *ERR:142* Upstream station:',F10.3, ' not found',
     A       ' in branch:',I5)
 76   FORMAT(/,' *ERR:143* Downstream station:',F10.3,' not found',
     A       ' in branch:',I5)
 78   FORMAT(/,' *ERR:144* Upstream node=',I5,' >= ',' downstream ',
     a       'node=',I5,' for trib. area.')
 79   FORMAT(/,' *ERR:145* Number of land uses <1 or > ',I5)
 80   FORMAT(' *ERR:169* Number of gage land uses=',I5,' exceeds max',
     A       ' of ',I5,' at gage ',I5)
 81   FORMAT(' *ERR:170* Number of gage land uses=',I5,' invalid.')
82    FORMAT(/,' *ERR:261* Path name: ',A,11X,' is invalid.')
83    FORMAT(/,' *ERR:262* No gages given for tributary area.')
84    FORMAT(/,' *ERR:262* HEC DSS name appeared before GAGE=')
85    FORMAT(/,' *ERR:264* Path name appeared before GAGE=')
86    FORMAT(/,' Gage=',I5)
87    FORMAT(/,' *ERR:265* Runoff intensity data for land use number=',
     A    I5,' in path name=',/,1X,A,/,5X,'has time step=',I5,
     B    ' minutes which differs from time step=',I5,/,5X,
     C    ' for land use number 1.')
88    FORMAT(/,' *ERR:266* At least one HEC DSS file name must appear',
     A         ' before a path',/,11X,' name appears.')
C89    FORMAT(/,' *ERR:362* KLR input no longer supported.',
C     A         '  Use DLAY option line instead.')
91    FORMAT(/,' *ERR:363* The heading line printed above appears to',
     A         ' be invalid. Check',/,
     B         5X,'to see if you have omitted a heading line.  To be',
     C        ' valid the first',/,
     D         5X,'non-blank information on the line must be NODE',
     E        ' or USTAT.')
C***********************************************************************
      CALL CLEAR_HOME()

C     Set justification for processing heading-dependent input. 
      JUST = 'RIGHT'

      GSTART(0) = 1
      GEND(0) = 1
C     SFAC2 represents the effect of the default trib-area unit given
C     by the square of the stationing factor as well as the effect
C     of using a station unit and a tributrary-area unit that are
C     incompatible.  FAC in TRIBIN was intended for this function.
C     However, it has been used in most cases to adjust for other 
C     conditions-such as approximating the variation of runoff 
C     based on mean patterns of rainfall.  

      SFAC2 = SFAC*SFAC*TAUFAC*TAUFAC
 
      DO 95 I=1,MXR_TRIBA
        DO 90 J=1,MXN_LU_G
          TRIBA(I,J) = 0.0
 90     CONTINUE
 95   CONTINUE
 
      IBRAN = 0
      NRWTA = 0

C     Initialize values to manage tributary area. TAM_IPNT is the
C     counter for the management info stored in TAM_ITAB,
C     which holds a forward linked list describing each tributary
C     area unit.  TAM_FPNT is the counter for the floating point
C     values needed in describing the unit. DTEN_KNT counts the
C     detention reservoirs and DLAY_KNT counts the delay 
C     systems where a system can be one or more linear reservoirs. 
C     TUNIT_KNT  is the count of trib area units stored in
C     the array TRIBA.
C     TAM_IPNT points to the next OPEN slot in TAM_ITAB
      TAM_IPNT = 1
C     TAM_FPNT points to the next OPEN slot in TAM_FTAB
      TAM_FPNT = 1
      DTEN_KNT = 0 
      DLAY_KNT = 0
      TUNIT_KNT = 0
C     Clear the backwards pointer for creating the forward linked
C     list in TAM_ITAB
      BACK_PNT = 0

C     Establish internal table numbers for the default detention table ids
      CALL GET_INTERNAL_TAB_NUMBER
     I                     (STDOUT, DEF_DTEN_UNIT_AREA_VOL_TABID,
     M                      EFLAG,
     O                      DEF_DTEN_UNIT_AREA_VOL_TAB_NUM)
      CALL GET_INTERNAL_TAB_NUMBER
     I                             (STDOUT, DEF_DTEN_ORIF_TABID,
     M                              EFLAG,
     O                              DEF_DTEN_ORIF_TAB_NUM)
      
      CALL inline
     I          (IN, STDOUT,                              
     O           LINE)                                    
      READ(LINE,1) HEAD
      WRITE(STDOUT,51) HEAD
 
      IF(DIFFUS.EQ.'YES ') THEN
C       Source of flows is a DTSF that has collected all runoff
C       intensities into one file.
        TIME_STEP_DIFF(1) = -1

        CALL GET_TABHD(IN, STDOUT,
     M                   EFLAG)

        CALL SET_TABHD(
     O                 TSFNAM, FFFNAM, NLUSE, NGAGE, HOME)

C       Perhaps add home directory to the file name.  This file gets
c       the input home name that is active. 
        CALL MAYBE_ADD_HOME(
     M                      TSFNAM)
        call os_file_style(
     m                         tsfnam)
c       We add the global output home name here and also the extension, if 
c       any, from the master-output file
        CALL MAYBE_ADD_GHOME_OUT(
     M                      FFFNAM)
        call maybe_add_ext(
     m                      fffnam)
        call os_file_style(
     m                         fffnam)


        WRITE(STDOUT,55) TSFNAM
        TSFDSN = GET_UNIT(STDOUT)

 
        WRITE(STDOUT,56) FFFNAM
        IF(FFFNAM.NE.' ') THEN
          FFFDSN = GET_UNIT(STDOUT)
        ENDIF
 

        WRITE(STDOUT,52) NLUSE
 
        IF(NLUSE.LT.1.OR.NLUSE.GT.MNDIFA) THEN
          WRITE(STDOUT,79) MNDIFA
          EFLAG = 1
        ENDIF
C        CALL inline
C     I            (IN, STDOUT,
C     O             LINE)
C        READ(LINE,6,ERR=992) NGAGE
        WRITE(STDOUT,64) NGAGE
        IF(NGAGE.LT.1.OR.NGAGE.GT.MXGAGE) THEN
          WRITE(STDOUT,65) MXGAGE
          EFLAG = 1
          NGAGE = 1
        ENDIF
 
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
C        READ(LINE,1) HEAD

        CALL GET_ITEM_LIMITS(
     I                       STDOUT, LINE, MAXITEMA, JUST,
     O                       NITEMA, ITEM_STARTA, ITEM_ENDA)


C        WRITE(STDOUT,51) HEAD
        WRITE(STDOUT,'(A)') '  Gage NLUse'
        IT = 1
        GLU = 0
        DO 300 I=1,NGAGE
          CALL inline
     I              (IN, STDOUT,
     O               LINE)

          CALL GET_LUSE_ITEMS(
     I                        STDOUT, LINE, NITEMA, ITEM_STARTA,
     I                        ITEM_ENDA,
     M                        EFLAG,
     O                        GAGE, NUM)

C          READ(LINE,7,ERR=992) GAGE, NUM
          WRITE(STDOUT,66) GAGE, NUM
          IF(NUM.GT.GLU) GLU = NUM
          IF(NUM.GT.MXN_LU_G) THEN
            WRITE(STDOUT,80) NUM, MXN_LU_G, GAGE
            EFLAG = 1
            NUM = MXN_LU_G
          ENDIF
          IF(NUM.LE.0) THEN
            WRITE(STDOUT,81) NUM
            EFLAG = 1
            NUM = 1
          ENDIF
          IF(GAGE.NE.I) THEN
            WRITE(STDOUT,67) GAGE
            EFLAG = 1
            GAGE = 1
          ENDIF
 
          GSTART(I) = IT
          GEND(I) = IT + NUM - 1
          IT = IT + NUM
 300    CONTINUE
        IF(NLUSE.NE.IT-1) THEN
          WRITE(STDOUT,68)
          EFLAG = 1
        ENDIF
      ELSE
C       Source of flows is from HECDSS files with a single path
C       name associated with each land use and gage combination
C       in the model.
        CALL inline
     I          (IN, STDOUT,
     O           LINE)
        READ(LINE,1) HEAD
        WRITE(STDOUT,51) HEAD
 
        NGAGE = 0
        NLUSE = 0
        DSS_INDEX = 0
310     CONTINUE
          CALL inline
     I              (IN, STDOUT,
     O              LINE)
          IF(LINE(1:4).EQ.'GAGE') THEN
C           Process a gage number
            READ(LINE(6:10),'(I5)',ERR=992) GAGE
            WRITE(STDOUT,86) GAGE
            IF(GAGE.LE.0) THEN
              IF(NGAGE.EQ.0) THEN
                WRITE(STDOUT,83)
                EFLAG = 1
                NGAGE = 1
              ENDIF
              GEND(NGAGE) = NLUSE
              N = GEND(NGAGE) - GSTART(NGAGE) + 1
              IF(N.GT.MXN_LU_G) THEN
                WRITE(STDOUT,80) N, MXN_LU_G, GAGE
                STOP 'Abnormal stop: errors found.'
              ENDIF
              GOTO 320
            ELSE
              NGAGE = NGAGE + 1
              IF(GAGE.NE.NGAGE) THEN
                WRITE(STDOUT,67) GAGE
                EFLAG = 1
              ENDIF
              IF(NGAGE.GT.MXGAGE) THEN
                WRITE(STDOUT,65) MXGAGE
                EFLAG = 1
                NGAGE = 1
              ENDIF
              IF(GAGE.GT.1) THEN
                GEND(NGAGE-1) = NLUSE
                N = GEND(NGAGE-1) - GSTART(NGAGE-1) + 1
                IF(N.GT.MXN_LU_G) THEN
                  WRITE(STDOUT,80) N, MXN_LU_G, NGAGE-1
                  STOP 'Abnormal stop: errors found.'
                ENDIF
                
              ENDIF
              GSTART(NGAGE) = NLUSE + 1
 
            ENDIF
          ELSEIF(LINE(1:6).EQ.'HECDSS') THEN
            WRITE(STDOUT,'(/,1X,A)') LINE
            IF(NGAGE.EQ.0) THEN
              WRITE(STDOUT,84)
              NGAGE = 1
              EFLAG = 1
            ENDIF
C           Get a HECDSS file name and set the flag.
            CALL PROCESS_HECDSS_NAME(STDOUT, LINE(8:71), DSS_INDEX,
     A                    'INPUT', EFLAG)
          ELSE
            WRITE(STDOUT,'(1X,A)') LINE
            IF(NGAGE.EQ.0) THEN
              WRITE(STDOUT,85)
              NGAGE = 1
              EFLAG = 1
            ENDIF
            IF(DSS_INDEX.EQ.0) THEN
              WRITE(STDOUT,88)
              DSS_INDEX = 1
              EFLAG = 1
            ENDIF
C           Take the line to be a path name for a HECDSS.
            IT = INDEX(LINE,'/')
            IF(IT.EQ.0.OR.IT.GT.78) THEN
C             Invalid path name.
              WRITE(STDOUT,82) LINE
              EFLAG = 1
            ELSE
              CALL PROCESS_HECDSS_PATH_NAME(STDOUT, LINE(IT:80),
     A                                           TIME_STEP, EFLAG)
              IF(EFLAG.EQ.0) THEN
                NLUSE = NLUSE + 1
                IF(NLUSE.GT.MNDIFA) THEN
                  WRITE(STDOUT,79) MNDIFA
                  EFLAG = 1
                  NLUSE = MNDIFA
                ENDIF
                PATH_NAME_DIFF(NLUSE) = LINE(IT:80)
                DSS_INDEX_DIFF(NLUSE) = DSS_INDEX
                TIME_STEP_DIFF(NLUSE) = TIME_STEP
              ENDIF
            ENDIF
          ENDIF
          GOTO 310
320     CONTINUE
        CALL SET_NDFVAL(NLUSE)
        GLU = 0
        DO 330 I=1,NGAGE
          GLU = MAX(GLU, GEND(I) - GSTART(I) + 1)
330     CONTINUE
 
C       Check the time steps of the pathnames.  They must be identical.
        DO 340 J=2,NLUSE
          IF(TIME_STEP_DIFF(J).NE.TIME_STEP_DIFF(1)) THEN
            WRITE(STDOUT,87) J, PATH_NAME_DIFF(J), TIME_STEP_DIFF(J),
     A                      TIME_STEP_DIFF(1)
            EFLAG = 1
          ENDIF
340     CONTINUE
      ENDIF
 
      QPNN = 0
      IBRAN = 0
      NRWTA = 0
 
      IF(EFLAG.NE.0) THEN
        WRITE(STDOUT,92)
92    FORMAT(/,' Previous errors preclude continuing.')
        STOP 'Abnormal stop.  Error(s) found.'
      ENDIF

      DO 200 IB=1,NBRA


C       Head of special loop when branch number is zero to 
C       signal a level-pool reservoir or a dummy branch with
C       tributary area. 
 100    CONTINUE

        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        IF(LINE(1:6).EQ.'BRANCH'.OR.
     A    LINE(1:6).EQ.'DEFINE'.OR.
     B    LINE(1:7).EQ.'NETWORK'.OR.LINE(1:7).EQ.'NEW NET'.OR.
     C    LINE(1:8).EQ.'EXTERIOR'.OR.
     D    LINE(1:4).EQ.'NEAR'.OR.
     E    LINE(1:10).EQ.'IRRIGATION') THEN
C         Put the line back for subsequent read statements
          BACKSPACE(IN)
          IF(LINE(1:6).NE.'BRANCH') THEN
C           End of trib-area input. 
            GOTO 201
          ENDIF
        ENDIF




        CALL GET_TABBRH(IN, STDOUT,
     M                   EFLAG)

        CALL SET_TABBRH(
     O                  USBRA, FAC)



C        READ(LINE,3,ERR=992) USBRA, FAC, KLR

        IF(FAC.EQ.0.0) FAC = 1.0
        IF(FAC.LT.0.0) THEN
          NEGFAC = -1.0
          FAC = ABS(FAC)
        ELSE
          NEGFAC = 1.0
        ENDIF

C       Set the net conversion factor for use in processing DTEN option
        CON_FAC = FAC*SFAC2
        
        CALL VAR_DECIMAL(NEGFAC*FAC,
     O                       FAC_STRING)
        WRITE(STDOUT,53) USBRA, FAC_STRING

C       Clear the pointers to the last tributary area 
C       units processed.  These are used to find the 
C       trib area description when detention or delay 
C       information is encountered.  

        LAST_NDTA_PNT = 0
        LAST_DTA_PNT = 0
 
C       INTERCEPT USBRA = 0 BECAUSE IT INDICATES TRIB AREA FOR
C       RESERVOIRS
 
        IF(USBRA.EQ.0) THEN
C         PROCESS TRIB AREA FOR RESERVOIRS
          IF(IBRAN.NE.0) THEN
            WRITE(STDOUT,63)
          ENDIF
 
          CALL inline
     I              (IN, STDOUT,
     O               LINE112)
          READ(LINE112,1,ERR=991) HEAD
          WRITE(STDOUT,51) HEAD
C         Check if HEAD really is a heading.  Catch error of omitting
C         a heading line.  This can cause insiduous errors with 
C         input apparently processed properly but with one or more
C         lines of numerical input treated as a heading!
          CHR5 = GETTOK(HEAD)
          IF(CHR5(1:4).NE.'NODE'.AND.CHR5.NE.'USTAT') THEN
            EFLAG = 1
            WRITE(STDOUT,91) 
          ENDIF
          CALL GET_ITEM_LIMITS(
     I                       STDOUT, LINE112, MAXITEMB, JUST,
     O                       NITEMB, ITEM_STARTB, ITEM_ENDB)

 
C         START LOOP OVER RESERVOIRS.  TERMINATED BY INPUT FLAG.
C         Boundary nodes are read here also and are processed 
C         here as if they were reservoirs.  Then in sub CHKEX
C         the boundary nodes are detected and the category 
C         code is changed and the pointer to the destination
C         of the flow in the trib area management block is 
C         set to its proper value.  Tributary area at a
C         boundary node is treated in all other respects as if
C         a reservoir were present.  The user must supply 
C         the delay time for the delay reservoir at the boundary.
C         A delay reservoir MUST be present in order to convert the
C         mean flow over the time interval to a flow at the end of
C         time interval.  It is not possible to reliably force a 
C         mean flow at a boundary. 
 900      CONTINUE
 
            DO 107 J=1,NLUSE
              A1(J) = 0.0
 107        CONTINUE
            CALL inline
     I                (IN, STDOUT,
     O                 LINE112)
C           Try to read the line as if it described 
C           a tributary area unit.  Detention/delay will
C           cause a read error.  Set the LPR flag to YES to 
C           signal that we are reading a node/branch format
C           and that we are in the 
          
            CALL GET_TRB_A_ITEMS_NDBR(
     I                           STDOUT, LINE112, NITEMB, ITEM_STARTB,
     I                           ITEM_ENDB, 'LPR', GEND, GSTART,
     M                           EFLAG, 
     O                           USNODE, NODE, GAGE, A1)
 

C            READ(LINE112,8,ERR=950) USNODE, GAGE,(A1(J), 
C     A                J=1,GEND(GAGE) - GSTART(GAGE) + 1)

            IF(EFLAG.GT.0) GOTO 950
            GOTO 108 
C             Branch to here on read error of an input line. 
C             Process the various detention/delay options. 
950           CONTINUE
               EFLAG = 0
               CALL PROCESS_DETENTION_DELAY_OPTIONS(STDOUT, GRAV, 
     I                           CON_FAC, LINE112, NGAGE, GSTART, GEND,
     M                              LAST_NDTA_PNT, LAST_DTA_PNT, 
     M                               BACK_PNT, TRIBA, EFLAG)
              GOTO 900

108         CONTINUE            
C           DEFINE THE INTERNAL NODE NUMBER AND DETECT THE END
C           OF INPUT FLAG. STRIP OFF LEADING BLANKS IN USNODE
 
            CHR5 = GETTOK(USNODE)
            IF(CHR5(1:1).EQ.'-') THEN
C             END OF INPUT
              NODE = -1
            ELSE
C             NODE NUMBER.  GET THE INTERNAL NODE NUMBER.
 
              ENF = CHR5
              CALL FNDINN
     I                   (
     M                    ENF, ENODEN, USENIN,
     O                    EFLAG, INENUS, NODE)
            ENDIF
 
            IF(NODE.GT.0) THEN
              N = GEND(GAGE) - GSTART(GAGE) + 1
              CALL FILL_VAR_DECIMAL_VECTOR(N, A1,
     A                                  CHAR6)
              WRITE(STDOUT,70) USNODE, GAGE, (CHAR6(J), J=1,N)
            ENDIF
            IF(NODE.GT.0.AND.GAGE.LT.1.OR.GAGE.GT.NGAGE) THEN
              WRITE(STDOUT, 69) GAGE
              EFLAG = 1
              GAGE = 1
            ENDIF
 
            IF(NODE.GT.0) THEN
              NRWTA = NRWTA + 1
C             SELECT A SLOT IN QPVEC vector that is open. 
C             We use the slots at the upstream node of each 
C             branch since it is not used by the branch 
C             tributary area. A slot will be assigned to 
C             boundary nodes as well but this location 
C             will be used to sum the contributions from 
C             the detention and non-detention trib areas.
              IBRAN = IBRAN + 1
              IF(IBRAN.LE.NBRA) THEN
                IADRS = BRPT(3,IBRAN)
              ELSE
                QPNN = QPNN + 1
                IADRS = NBN + QPNN
                IF(IADRS.GT.MNBN) THEN
                  WRITE(STDOUT,62) IADRS, MNBN
                  EFLAG = 1
                ENDIF
              ENDIF
 
              RWTA(NRWTA) = NODE
              RTAP(NRWTA) = IADRS
              RTAFAC(NRWTA) = NEGFAC*FAC
C             Store values in the trib area management system
              IF(TAM_IPNT+8.GT.TAM_MXNI) THEN
                WRITE(STDOUT, 54) TAM_IPNT, TAM_MXNI
                EFLAG = 1
                STOP 'Abnormal stop: errors found.'
              ELSE
C               Set the forward pointer in the previous
C               trib area unit, if there is any.
                IF(BACK_PNT.GT.0) THEN
                  TAM_ITAB(BACK_PNT+2) = TAM_IPNT
                  BACK_PNT = TAM_IPNT
                ELSE
                  BACK_PNT = TAM_IPNT
                ENDIF
C               Set the pointers to the tributary area unit
C               treating it like it has no detention, the
C               default assumption, until subsequent lines
C               of user input tell us otherwise.  At this point
C               we do not know if detention is present or not.
                LAST_NDTA_PNT = TAM_IPNT
                LAST_DTA_PNT = 0
C                WRITE(STDOUT,*)' TRBIN: LAST_NDTA_PNT=',LAST_NDTA_PNT
C               Store the stuff.
                TAM_ITAB(TAM_IPNT) = NODE
                TAM_ITAB(TAM_IPNT+7) = IADRS
C               Set value to point to RWTA, RTAP, RTAFAC
                TAM_ITAB(TAM_IPNT+8) = NRWTA
C               Set the category code for LPR
                TAM_ITAB(TAM_IPNT+1) = 2
C               Clear the forward pointer to terminate
C               if this is the last trib area unit.  Will not be
C               here because branch trib areas are yet
C               to come but make zero anyway.
                TAM_ITAB(TAM_IPNT+2) = 0
C               Store the tributary areas. 
                TUNIT_KNT = TUNIT_KNT + 1
                IF(TUNIT_KNT.GT.MXR_TRIBA) THEN
                  WRITE(STDOUT, 57) TUNIT_KNT, MXR_TRIBA
                  STOP 'Abnormal stop: errors found.'
                ELSE
                  TAM_ITAB(TAM_IPNT+3) = TUNIT_KNT
                  TAM_ITAB(TAM_IPNT+4) = GAGE

                  DO 901 J=1, GEND(GAGE)-GSTART(GAGE)+1
                    TRIBA(TUNIT_KNT,J) = FAC*A1(J)*SFAC2
 901              CONTINUE
                ENDIF

C               Clear the pointers for detention and delay
C               descriptions. 
                TAM_ITAB(TAM_IPNT+5) = 0
                TAM_ITAB(TAM_IPNT+6) = 0

                TAM_IPNT = TAM_IPNT + 9
              ENDIF
 
              GOTO 900

            ELSE
C             END OF RESERVOIR LIST
              QPN = NBN + QPNN
 
              IF(QPN.GT.MNBN) THEN
                WRITE(STDOUT,62) QPN, MNBN
                EFLAG = 1
              ENDIF
 
              GOTO 100
            ENDIF
        ENDIF
 
C       DEFINE IBRA AS THE INTERNAL BRANCH NUMBER.  IT MUST BE SIGNED
C       TO FLAG SPECIAL CONDITIONS
        IF(USBRA.LT.0) THEN
          USBRA = ABS(USBRA)
          CALL GETINB
     M               (USBRA,
     O                EFLAG, IBRA)
          IBRA = -IBRA
        ELSE
          CALL GETINB
     M               (USBRA,
     O                EFLAG, IBRA)
        ENDIF
 
C       PROCESS BRANCHES. SAVE THE FACTOR FOR USE IN SUB. TRBOUT,
 
        TAFAC(ABS(IBRA)) = NEGFAC*FAC
 
        CALL inline
     I            (IN, STDOUT,
     O             LINE112)
        READ(LINE112,1,ERR=991) HEAD
        WRITE(STDOUT,50) HEAD
C       Check if HEAD really is a heading.  Catch error of omitting
C       a heading line.  This can cause insiduous errors with 
C       input apparently processed properly but with one or more
C       lines of numerical input treated as a heading!
        CHR5 = GETTOK(HEAD)
        IF(CHR5(1:4).NE.'NODE'.AND.CHR5.NE.'USTAT') THEN
          EFLAG = 1
          WRITE(STDOUT,91) 
        ENDIF

        CALL GET_ITEM_LIMITS(
     I                     STDOUT, LINE112, MAXITEMB, JUST,
     O                     NITEMB, ITEM_STARTB, ITEM_ENDB)
 
 
        FNODE = BRPT(3,ABS(IBRA)) + 1
 
C       FIRST NODE VALID FOR TRIBUTARY AREA IS SECOND NODE ON THE BRANCH
 
        LNODE = BRPT(4,ABS(IBRA))
        ND = BRPT(1,ABS(IBRA)) + 1
 
        IF(IBRA.LT.0) THEN
C         PROCESS THE STATION RANGE INPUT OPTION
 400      CONTINUE
 
            CALL inline
     I                (IN, STDOUT,
     O                 LINE112)

            CALL GET_TRB_A_ITEMS_STRNG(
     I                           STDOUT, LINE112, NITEMB, ITEM_STARTB,
     I                           ITEM_ENDB, GEND, GSTART,
     M                           EFLAG, 
     O                           USTAT, DSTAT, GAGE, A1)

            IF(EFLAG.GT.0) GOTO 952
C            READ(LINE112,9,ERR=952) USTAT, DSTAT, GAGE, (A1(J),J=1,
C     A                 GEND(GAGE)-GSTART(GAGE)+1)
 
            IF(USTAT.EQ.DSTAT) GOTO 200
 
            N = GEND(GAGE)-GSTART(GAGE)+1
            CALL FILL_VAR_DECIMAL_VECTOR(N, A1,
     A                                CHAR6)
            WRITE(STDOUT,72) USTAT, DSTAT, GAGE,(CHAR6(J),J=1, N)
            USTAT = SFAC*USTAT
            DSTAT = SFAC*DSTAT
            DO 410 J=1, GEND(GAGE)-GSTART(GAGE)+1
              A1(J) = FAC*SFAC2*A1(J)
 410        CONTINUE
 
C           FIND THE NODES CORRESPONDING TO UPSTREAM AND DOWNSTREAM
C           STATION VALUES FOR THIS BRANCH
 
            UNODE = FNDNOD(FNODE-1, MNBN, LNODE, USTAT, XVEC)
            IF(UNODE.LT.0) THEN
              WRITE(STDOUT,74) USTAT/SFAC, USBRA
              STOP 'Abnormal stop: errors found.'
            ENDIF
 
            DNODE = FNDNOD(FNODE-1, MNBN, LNODE, DSTAT, XVEC)
            IF(DNODE.LT.0) THEN
              WRITE(STDOUT,76) DSTAT/SFAC, USBRA
              STOP 'Abnormal stop: errors found.'
            ENDIF
 
C           MAKE SURE UNODE AND DNODE HAVE PROPER RELATIONSHIP
 
            IF(UNODE.GE.DNODE) THEN
              WRITE(STDOUT,78) UNODE, DNODE
              STOP 'Abnormal stop: errors found.'
            ENDIF
 
            CALL STORE_BRANCH_TRIB_AREA(STDOUT, GAGE, GEND, GSTART, 
     I         XVEC, UNODE, DNODE, IBRA, A1, 
     M         TAM_IPNT, TAM_FPNT, TUNIT_KNT, BACK_PNT, TAM_ITAB, 
     M         TAM_FTAB, TRIBA, LAST_NDTA_PNT)
C                WRITE(STDOUT,*)' TRBIN: LAST_NDTA_PNT=',LAST_NDTA_PNT

            GOTO 400

952         CONTINUE
C           Branch here on read error to process detention/delay
C           requests.
            EFLAG = 0
            CALL PROCESS_DETENTION_DELAY_OPTIONS(STDOUT, GRAV, CON_FAC,
     I                           LINE112, NGAGE, GSTART, GEND,
     M                           LAST_NDTA_PNT, LAST_DTA_PNT, 
     M                            BACK_PNT, TRIBA, EFLAG)
            GOTO 400

        ENDIF

C       Start loop over the values for the branch. 
        I = FNODE
117     CONTINUE         
          CALL inline
     I              (IN, STDOUT,
     O               LINE112)
          IF(LINE112(1:6).EQ.'BRANCH'.OR.
     A       LINE112(1:6).EQ.'DEFINE'.OR.
     B       LINE112(1:7).EQ.'NETWORK'.OR.LINE112(1:7).EQ.'NEW NET'.OR.
     C       LINE112(1:8).EQ.'EXTERIOR'.OR.
     D       LINE112(1:4).EQ.'NEAR'.OR.
     E       LINE112(1:10).EQ.'IRRIGATION') THEN
            NODE = -1
            BACKSPACE(IN)
            IF(LINE112(1:6).NE.'BRANCH') THEN
C             End of trib-area input. 
              GOTO 201
            ENDIF
          ELSE
            CALL GET_TRB_A_ITEMS_NDBR(
     I                           STDOUT, LINE112, NITEMB, ITEM_STARTB,
     I                           ITEM_ENDB, 'BRA', GEND, GSTART,
     M                           EFLAG, 
     O                           USNODE, NODE, GAGE, A1)
C            READ(LINE112,10,ERR=954) NODE, GAGE, (A1(J), 
C     A                                J=1,GEND(GAGE)-GSTART(GAGE)+1)
            IF(EFLAG.GT.0) GOTO 954
          ENDIF
          IF(NODE.LT.0) GOTO 200

          N = GEND(GAGE)-GSTART(GAGE)+1
          CALL FILL_VAR_DECIMAL_VECTOR(N, A1,
     O                              CHAR6)
          WRITE(STDOUT,71) NODE, GAGE, (CHAR6(J), J=1, N)
 
          IF(GAGE.LT.1.OR.GAGE.GT.NGAGE) THEN
             WRITE(STDOUT,69) GAGE
             EFLAG = 1
             GAGE = 1
          ENDIF
          DO 119 J=1,GEND(GAGE)-GSTART(GAGE)+1
            A1(J) = FAC*SFAC2*A1(J)
 119      CONTINUE
          IF(NODE.EQ.0) THEN
C           Branch mode of input. Tributary area given for the
C           branch as a whole.  The tributary area effective for
C           each computational element on the branch is then 
C           made proportional to the ratio of element length to
C           branch length. 
            IF(I.NE.FNODE) THEN
              WRITE(STDOUT,*) '*ERR:146* Request for automatic ',
     A          'trib. area allocation invalid.'
              WRITE(STDOUT,*) '      Must be first and only entry for',
     A                      ' the branch'
              STOP 'Abnormal stop: errors found.'
            ENDIF
 
            CALL STORE_BRANCH_TRIB_AREA(STDOUT, GAGE, GEND, GSTART, 
     I         XVEC, FNODE-1, LNODE, IBRA, A1, 
     M         TAM_IPNT, TAM_FPNT, TUNIT_KNT, BACK_PNT, TAM_ITAB, 
     M         TAM_FTAB, TRIBA, LAST_NDTA_PNT)
C                WRITE(STDOUT,*)' TRBIN: LAST_NDTA_PNT=',LAST_NDTA_PNT

            GOTO 117

          ELSE
C           Node mode of input.  Tributary area given for 
C           each node except the first node on the branch. 
      
            IF(NODE.NE.ND) THEN
              WRITE(STDOUT,61)
              EFLAG = 1
              STOP 'Abnormal stop: errors found.'
            ENDIF
            IF(I.GT.LNODE) THEN
              WRITE(STDOUT,58) USBRA
              STOP 'Abnormal stop: errors found.'
            ENDIF
C           Store trib area for an individual computational element.
            CALL STORE_BRANCH_TRIB_AREA(STDOUT, GAGE, GEND, GSTART, 
     I         XVEC, I-1, I, IBRA, A1, 
     M         TAM_IPNT, TAM_FPNT, TUNIT_KNT, BACK_PNT, TAM_ITAB, 
     M         TAM_FTAB, TRIBA, LAST_NDTA_PNT)
 
            ND = ND +1
            I = I + 1
            GOTO 117
          ENDIF

954       CONTINUE
          EFLAG = 0
          CALL PROCESS_DETENTION_DELAY_OPTIONS(STDOUT, GRAV, CON_FAC,
     I                         LINE112, NGAGE, GSTART, GEND,
     M                         LAST_NDTA_PNT, LAST_DTA_PNT, 
     M                          BACK_PNT, TRIBA, EFLAG)
          GOTO 117

 200  CONTINUE

C     Exit from branch loop BEFORE all branches are seen jumps 
C     to here.  Thus branches with no trib area can be left out of
C     the tributary area input. 

 201  CONTINUE 


C      WRITE(STDOUT,*) ' In TRIBIN before call to TRBOUT: TUNIT_KNT=',
C     A                  TUNIT_KNT
      IF(EFLAG.EQ.0) THEN
        CALL TRBOUT
     I           (SFAC, SFAC2, STDOUT, NBRA, BRPT, TRIBA, NRWTA, RTAP,
     I            RWTA, GSTART, GEND, NGAGE, GLU, RTAFAC, TAFAC,
     I            XVEC, GRAV)
      ENDIF

      RETURN
 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE112
        STOP 'Abnormal stop: errors found.'
 992  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE
        STOP 'Abnormal stop: errors found.'
      END
C
C
C 
      SUBROUTINE READ_WRFIN_ITEMS(
     I                            STDOUT, LINE, NITEM, ITEM_START,
     I                            ITEM_END,
     M                            EFLAG,
     O                        ACTION, USBRA, USNODE, ITEM, TYPE, NAME)

C     Get the items of data from a line of input to WRFIN

      IMPLICIT NONE
      INTEGER STDOUT, NITEM, ITEM_START(NITEM), ITEM_END(NITEM),
     A         EFLAG, USBRA
      
      CHARACTER LINE*(*), USNODE*6, NAME*(*), TYPE*4, ITEM*4, ACTION*4

C     Local

      INTEGER IE, IS, N
      CHARACTER TPC*20

C     Called program units
      INTEGER NONBLANK_NONZERO, LENSTR
      EXTERNAL STRIP_L_BLANKS, NONBLANK_NONZERO, LENSTR,
     A         GET_INTERNAL_TAB_NUMBER
C     ***********************FORMATS************************************
50    FORMAT(/,' *ERR:380* Only ',I3,' items given in ',
     A   'OUTPUT-FILES-BLOCK  line.  Need six items.')
C***********************************************************************
      IF(NITEM.LT.6) THEN
        WRITE(STDOUT,50) NITEM
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      N = 1
C     Process the action field. 
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      ACTION = TPC

C     Process the branch number
      N = 2
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      READ(TPC,'(I10)',ERR=991) USBRA

C     Process the user node
      N = 3
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      USNODE = TPC

C     Process the output item 
      N = 4
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      ITEM = TPC

C     Process the data recording type
      N = 5
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      TYPE = TPC

C     Process the output destination name
      N = 6
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      NAME = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    NAME)

      RETURN
991   CONTINUE
      WRITE(STDOUT,52) TPC
52    FORMAT(/,' *ERR:500* Conversion error in: ',A)
      EFLAG = 1
      RETURN

      END

C
C
C
      SUBROUTINE   WRFIN
     I                  (IN, STDOUT, NBRA, BRPT,
     M                   EFLAG)
 
C     + + + PURPOSE + + +
C     Read user input specifing the output files.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, IN, STDOUT, NBRA
      INTEGER BRPT(8,NBRA)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
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
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'wrcom.cmn'
      INCLUDE 'home.cmn'
 
C     + + + LOCAL VARIABLES + + +
C     Create parameters for coding ACTION
      INTEGER OUTA, OUTS, ADD, SUB, QUAD
      PARAMETER (OUTA=1, OUTS=2, ADD=3, SUB=4, QUAD=7)
      INTEGER MAXN
      PARAMETER (MAXN=6)
      INTEGER BRA, HECDSS, NODE, UN, USBRA, DSS_INDEX, TIME_STEP,
     A        NITEM, ITEM_START(MAXN), ITEM_END(MAXN), IT, NXT
      CHARACTER HEAD*196, ITEM*4, LINE*196, NAME*256, TYPE*4, USNODE*6,
     A          JUST*5, ACTION*4
 
C     + + + EXTERNAL NAMES + + +
      INTEGER GET_UNIT, LENSTR

      EXTERNAL GETINB, GETINN, inline, KIL, GET_UNIT, LENSTR,
     A         GET_ITEM_LIMITS
    
 
C     + + + INPUT FORMATS + + +
C 1    FORMAT(A80)
C 2    FORMAT(2I5,1X,A5,1X,A4,1X,A4,1X,A)
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' ',A)
C 51   FORMAT(' ',I5,I5,A5,1X,A4,1X,A4,1X,A)
 52   FORMAT(' ',5X,I5,1X,A5,1X,A4,1X,A4,1X,A)
 53   FORMAT(/,' *ERR:156* Item field must be: "ELEV" OR "FLOW"')
 54   FORMAT(/,' *ERR:157* Type field must be: "PNT " OR "STAR"')
 56   FORMAT(/,' *ERR:158* Number of output files requested larger',/,
     A     15X,' than the current maximum of:', I3)
 57   FORMAT(/,' *ERR:159* Mean values cannot be output')
58    FORMAT(/,'*ERR:412* Action=',A,' unknown in OUTPUT FILES block')
73    FORMAT(/,' Home directory/drive is: ',A)
74    FORMAT(/,' *WRN:58* No home name found following HOME=. ',
     A         ' Home name cleared.')
C***********************************************************************
      CALL CLEAR_HOME()
      HECDSS = 0
      DSS_OUT_COUNT = 0
      IRR_DT = 0
      JUST = 'RIGHT'
      CALL inline
     I          (IN, STDOUT,
     O           HEAD)
C      READ(LINE,1) HEAD
      WRITE(STDOUT,50) HEAD(1:LENSTR(HEAD))
      CALL inline
     I          (IN, STDOUT,
     O           HEAD)
C      READ(LINE,1) HEAD
      WRITE(STDOUT,50) HEAD(1:LENSTR(HEAD))
 
C     Get the column limits as defined by the user heading items.

      CALL GET_ITEM_LIMITS(
     I                     STDOUT, HEAD, MAXN, JUST,
     O                     NITEM, ITEM_START, ITEM_END)

      NFOUT = 0
 
 100  CONTINUE
 
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        IF(LINE(1:6).EQ.'HECDSS') THEN
C         Get a HECDSS file name and set the flag.
          IF(LINE(8:9).NE.'  ') THEN
            HECDSS = 1
            CALL PROCESS_HECDSS_NAME(STDOUT, LINE(8:71), DSS_INDEX,
     A                     'OUTPUT', EFLAG)
            WRITE(STDOUT,50) HEAD(1:LENSTR(HEAD))
          ELSE
            HECDSS = 0
          ENDIF
C         Get the next line.
          CALL inline
     I              (IN, STDOUT,
     O               LINE)
        ELSEIF(LINE(1:4).EQ.'HOME'.OR.LINE(1:4).EQ.'home') THEN
          HECDSS = 0
          IT = INDEX(LINE, '=')
          NXT = IT + 1
          CALL NXTTOK
     I               (LINE,
     M                NXT,
     O                HOME)
          IF(NXT.LE.0) THEN
            WRITE(STDOUT,74) 
            HOME = ' '
          ENDIF
          CALL STRIP_L_BLANKS(
     M                        HOME)
          IT = LEN_TRIM(HOME)
          WRITE(STDOUT,73) HOME(1:IT)

          CALL inline
     I              (IN, STDOUT,
     O               LINE)

        ENDIF
 

         CALL READ_WRFIN_ITEMS(
     I                         STDOUT, LINE, NITEM, ITEM_START,
     I                         ITEM_END,
     M                         EFLAG,
     O                         ACTION, USBRA, USNODE, ITEM, TYPE, NAME)
    
        IF(ACTION(1:2).NE.'-1') THEN
          WRITE(STDOUT,52)  USBRA, USNODE, ITEM, TYPE, NAME
          IF(HECDSS.EQ.0) THEN
C           Assign an I/O unit but only if action is OUT in first three characters. blank,
c           or QUAD
            IF(ACTION(1:3).EQ.'OUT'.OR.ACTION.EQ.' '
     A         .OR.ACTION.EQ.'QUAD') THEN
              UN = GET_UNIT(STDOUT)
              CALL MAYBE_ADD_GHOME_OUT(
     M                            NAME)
              call maybe_add_ext( 
     m                            name)
              call os_file_style(
     m                             name)
            ELSE
              UN = 0
            ENDIF
          ENDIF
 
          IF(ACTION.NE.'QUAD') THEN
            CALL GETINB
     M               (USBRA,
     O                EFLAG, BRA)
            IF(BRA.LT.0.OR.BRA.GT.NBRA) CALL KIL
     I                                         (12,
     M                                          BRA, EFLAG)
            IF(BRA.EQ.0) THEN
              CALL GETINN
     M                   (USNODE,
     O                    EFLAG, NODE)
            ELSE
              READ(USNODE,'(I6)',ERR=991) NODE
              IF(NODE.LT.BRPT(1,BRA).OR.NODE.GT.BRPT(2,BRA)) THEN
                CALL KIL
     I                  (2,
     M                   NODE, EFLAG)
                NODE = BRPT(2,BRA)
              ENDIF
 
C             COMPUTE POINTER INTO BRANCH VECTORS
              NODE = BRPT(3,BRA) + NODE - BRPT(1,BRA)
            ENDIF
          ELSE
            BRA = 0
            NODE = 0
          ENDIF
 
          IF(ITEM.NE.'ELEV'.AND.ITEM.NE.'FLOW') THEN
            WRITE(STDOUT,53)
            ITEM = 'FLOW'
            EFLAG = 1
          ENDIF
 
          IF(TYPE.EQ.'MEAN') THEN
            WRITE(STDOUT,57)
            EFLAG = 1
          ENDIF
          IF(TYPE.NE.'PNT '.AND.TYPE.NE.'STAR') THEN
            WRITE(STDOUT,54)
            TYPE = 'STAR'
            EFLAG = 1
          ENDIF
 
          IF(HECDSS.EQ.1) THEN
C           Check the path name and get the nature of the time
C           step and its numeric value.
            CALL PROCESS_HECDSS_PATH_NAME(STDOUT, NAME, TIME_STEP, 
     I                                    EFLAG)
C           Count the number of output data sets DSS files.
            DSS_OUT_COUNT = DSS_OUT_COUNT + 1
            IF(TIME_STEP.EQ.0) THEN
C             There is an irregular time step data set.
              IRR_DT = 1
            ENDIF
          ENDIF
          NFOUT = NFOUT +1
          IF(NFOUT.GT.MNFOUT) THEN
            WRITE(STDOUT,56) MNFOUT
            NFOUT = MNFOUT
            EFLAG = 1
          ENDIF
 
C         STORE THE VALUES FOR THE CURRENT LINE
 
          IF(HECDSS.EQ.0) THEN
            UNOUT(NFOUT) = UN
            DSS_INDEX_OUT(NFOUT) = 0
            TIME_STEP_OUT(NFOUT) = 0
            DSS_BUFFER_COLUMN(NFOUT) = 0
          ELSE
C           Set the unit value to larger than 1000. 
            UNOUT(NFOUT) = 1001
            DSS_INDEX_OUT(NFOUT) = DSS_INDEX
            TIME_STEP_OUT(NFOUT) = TIME_STEP
            DSS_BUFFER_COLUMN(NFOUT) = DSS_OUT_COUNT
          ENDIF
          BRAOUT(NFOUT) = BRA
          NODOUT(NFOUT) = NODE
          NAMOUT(NFOUT) = NAME
c         Set the record number to the first record in the file. 
          wr_rec(nfout) = 1
          IF(ITEM.EQ.'ELEV') THEN
            ICDOUT(NFOUT) = 2
          ELSE
            ICDOUT(NFOUT) = 4
          ENDIF

C         Process the action values and set codes
          IF(ACTION.EQ.' ') THEN
C           Treat as add with output. 
            ACTOUT(NFOUT) = OUTA
          ELSEIF(ACTION.EQ.'OUTA'.OR.ACTION.EQ.'OUT') THEN
            ACTOUT(NFOUT) = OUTA
          ELSEIF(ACTION.EQ.'OUTS') THEN
            ACTOUT(NFOUT) = OUTS
          ELSEIF(ACTION.EQ.'ADD') THEN
            ACTOUT(NFOUT) = ADD
          ELSEIF(ACTION.EQ.'SUB') THEN
            ACTOUT(NFOUT) = SUB
          ELSEIF(ACTION.EQ.'QUAD') THEN
            ACTOUT(NFOUT) = QUAD
          ELSE
            WRITE(STDOUT,58) ACTION
            EFLAG = 1
          ENDIF      
        ELSE
          RETURN
        ENDIF
 
        GOTO 100
 
 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE
        STOP 'Abnormal stop: errors found.'
        END

C     ***********
C     *         *
C     * PROCESS_OLD_IOUNITS
C     *         *
C     ***********

      SUBROUTINE PROCESS_OLD_IOUNITS(STDOUT, UNIT_STRING, 
     O                               UNIT, NAME_STRING)

C     Process old I/O unit specifications so that the old format will
C     be read properly, a info message will be sent to the user,
C     and the value of the assigned unit and the name of the file
C     will be returned.

      IMPLICIT NONE
      INTEGER STDOUT, UNIT

      CHARACTER UNIT_STRING*(*), NAME_STRING*(*)

C     Local

      INTEGER IT

      INTEGER GET_UNIT
      EXTERNAL STRIP_L_BLANKS, GET_UNIT
C     ****************************Formats*******************************
50    FORMAT(/,' This version of FEQ no longer uses I/O unit numbers',
     A   ' in its input.  Any you supply',/,' will be ignored.  You ',
     B   'may give a file name which can begin after',/,
     C   ' the = in the input. The file name may be blank.')
C***********************************************************************
C     We assume that the unit string contains everything following
C     the = in the old specification.  We always used I5 for the
C     input of the unit number.  Thus we seek a unit number in the
C     first 5 characters.  If we find one, then we assume that we
C     have the old format. 

      READ(UNIT_STRING(1:5),'(I5)',ERR=100) IT
C       Ok here.  We found an integer. 
        NAME_STRING = UNIT_STRING(6:)
        IF(IT.EQ.0) THEN
          UNIT = 0
        ELSE
          WRITE(STDOUT,50)
          UNIT = GET_UNIT(STDOUT)
        ENDIF
        GOTO 110
100   CONTINUE
C       Read for an integer failed.  Assume that unit was not
C       given and the name string begins at first character
        NAME_STRING = UNIT_STRING
        UNIT = GET_UNIT(STDOUT)
110   CONTINUE
      CALL STRIP_L_BLANKS(
     M                  NAME_STRING)
      RETURN
      END
