C     Code for input of various blocks that differ from fixed-format
C
C
C
      SUBROUTINE GET_BRANCH_ITEMS(
     I                            STDOUT, LINE, NITEM, ITEM_START,
     I                            ITEM_END,
     M                            EFLAG, IDLEN, HLIDLEN, 
     O                            NODE, NAME, XTABN, XCHAR, 
     O                            ZCHAR, CA, CD, HL, AZMC, CF, 
     O                            YCCHAR, STD, KADJ, TABID)

C     Get the items of data from a branch table input line.  
      IMPLICIT NONE
      INTEGER STDOUT, NITEM, ITEM_START(NITEM), ITEM_END(NITEM),
     A        NODE, HL, EFLAG, IDLEN, HLIDLEN
      REAL CA, CD, CF, STD, KADJ
      CHARACTER LINE*120, NAME*16, XTABN*5, XCHAR*10, ZCHAR*16, 
     A          AZMC*5, YCCHAR*8, TABID*16

C     Local

      INTEGER IE, IS, ITAB, N
      CHARACTER TPC*20, KEY*16

C     Called program units
      INTEGER NONBLANK_NONZERO, LENSTR
      EXTERNAL STRIP_L_BLANKS, NONBLANK_NONZERO, LENSTR,
     A         GET_INTERNAL_TAB_NUMBER, STRIP_BLANKS_AND_ZEROS
C     ***********************FORMATS************************************
50    FORMAT(/,' *ERR:375* Only ',I3,' items given in ',
     A          'Branch-Description.  Need at least five items.')
C*******************************************************************************
      IF(NITEM.LT.5) THEN
        WRITE(STDOUT,50) NITEM
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      N = 1
C     Process the NODE
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      IF(TPC(1:1).EQ.' ') THEN
        NODE = 0
      ELSE
        READ(TPC,*) NODE
      ENDIF

C     Process the node id
      N = 2
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      NAME = TPC

C     Process the table id
      N = 3
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      KEY = TPC
C     Convert from the table id to an internal number.
      IF(KEY.NE.' '.AND.KEY(1:1).NE.'-') THEN
C       We have an id given.
        TABID = KEY
        IDLEN = MAX(IDLEN, LENSTR(KEY))
        CALL GET_INTERNAL_TAB_NUMBER
     I                               (STDOUT, KEY,
     M                                EFLAG,
     O                                ITAB)
        WRITE(XTABN,'(I5)') ITAB
      ELSE
        TABID = ' '
        XTABN = TPC
      ENDIF
      
C     Process the station 
      N = 4
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_BLANKS_AND_ZEROS(
     M                            TPC)
      XCHAR = TPC

C     Process the invert elevation
      N = 5
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_BLANKS_AND_ZEROS(
     M                            TPC)
      ZCHAR = TPC

C     Process the local acceleration losses
      N = 6
      IF(N.GT.NITEM) THEN
        CA = 0.0
      ELSE
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_BLANKS_AND_ZEROS(
     M                              TPC)
        IF(TPC(1:1).EQ.' ') THEN
          CA = 0.0
        ELSE
          READ(TPC(1:5),'(F5.0)') CA
        ENDIF
      ENDIF

C     Process local decceleration losses
      N = 7
      IF(N.GT.NITEM) THEN
        CD = 0.0
      ELSE
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_BLANKS_AND_ZEROS(
     M                              TPC)
        IF(TPC(1:1).EQ.' ') THEN
          CD = 0.0
        ELSE
          READ(TPC(1:5),'(F5.0)') CD
        ENDIF
      ENDIF

C     Process local structure losses
      N = 8
      IF(N.GT.NITEM) THEN
        HL = 0
      ELSE
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_L_BLANKS(
     M                      TPC)
        KEY = TPC
        IF(NONBLANK_NONZERO(KEY).GT.0) THEN
C         We have a reference to a loss table.
          HLIDLEN = MAX(HLIDLEN,LENSTR(KEY))
          CALL GET_INTERNAL_TAB_NUMBER
     I                                (STDOUT, KEY,
     M                                 EFLAG,
     O                                 HL)
        ELSE
          HL = 0.0
        ENDIF
      ENDIF

C     Process the element azimuth
      N = 9
      IF(N.GT.NITEM) THEN
        AZMC = ' '
      ELSE
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_BLANKS_AND_ZEROS(
     M                              TPC)
        AZMC = TPC
      ENDIF

C     Process the effective area for local inflow-outflow
      N = 10
      IF(N.GT.NITEM) THEN
        CF = 0.0
      ELSE
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_BLANKS_AND_ZEROS(
     M                              TPC)
        IF(TPC(1:1).EQ.' ') THEN
          CF = 0.0
        ELSE
          READ(TPC(1:5),'(F5.0)') CF
        ENDIF
      ENDIF

C     Process the distance to the sewer invert
      N = 11
      IF(N.GT.NITEM) THEN
        YCCHAR = ' '
      ELSE
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_BLANKS_AND_ZEROS(
     M                              TPC)
        YCCHAR = TPC
      ENDIF

C     Process standard flood elevation
      N = 12
      IF(N.GT.NITEM) THEN
        STD = 0.0
      ELSE
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_BLANKS_AND_ZEROS(
     M                      TPC)
        IF(TPC(1:1).EQ.' ') THEN
          STD = 0.0
        ELSE
          READ(TPC(1:5),'(F5.0)') STD
        ENDIF
      ENDIF

C     Process conveyance adjustment factor
      N = 13
      IF(N.GT.NITEM) THEN
        KADJ = 1.0
      ELSE
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_BLANKS_AND_ZEROS(
     M                      TPC)
        IF(TPC(1:1).EQ.' ') THEN
          KADJ = 1.0
        ELSE
          READ(TPC(1:10),'(F10.0)') KADJ
        ENDIF
      ENDIF

      RETURN
      END

C
C
C
      SUBROUTINE SET_CONTROL_SOURCE(
     I                              STDOUT, MFTNUM, MNBLK, NC_LONG,
     O                              EFLAG, N)

C     Processs the references to an operation block number in an 
C     instruction in the NWMCI. The user can give any of the following
C     values in response to this item:

C     1. A negative integer      |
C                                |-specifies a time series table of a 
C     2. A negative alphanumeric |   structure setting.
C     3. A positive integer
C        3.1 >  MNBLK - gives numeric table id for time series table of
C                        operation block numbers.
C        3.2 <= MNBLK - gives an operation block number
C     4. A positive alphanumeric- gives alphanumeric table id for time series
C                                 table of operation block numbers.          

      IMPLICIT NONE
      INTEGER STDOUT, MFTNUM, MNBLK, EFLAG, N
      CHARACTER*16 NC_LONG


C     Local
      
      CHARACTER TEMP*16
C***********************************************************************
      IF(NC_LONG(1:1).EQ.'-') THEN
C       Table id.  Strip off leading -
        TEMP = NC_LONG(2:16)
        CALL GET_INTERNAL_TAB_NUMBER
     I                              (STDOUT, TEMP,
     M                               EFLAG,
     O                               N)
        N = -N
      ELSE
C       If not negative, could be a number giving the operation
C       block number.  If it cannot be read as an integer, it is a
C       time-series table id that gives the operation block numbers
C       as a function of time. 
        READ(NC_LONG,'(I5)',ERR=5431) N
C       Number here.  If it is larger than the current maximum number
C       of operation blocks, it is the id for a time-series table that
C       gives the operation block numbers to be used for the structure.

        IF(N.GT.MNBLK) GOTO 5431

        GOTO 5432
5431    CONTINUE
C       Table id here
          CALL GET_INTERNAL_TAB_NUMBER
     I                                (STDOUT, NC_LONG,
     M                                 EFLAG,
     O                                 N)
C         Increment the internal table number by a value that is 
C         larger than any internal table number as a signal 
C         for later processing of the reference to a table 
C         containing the operation-block numbers. 
          N = N + MFTNUM + 1
            
5432    CONTINUE
      ENDIF
      RETURN
      END
C
C
C
      SUBROUTINE SET_RCB_DEFAULTS()

C     Set the default values in the vectors used to process the 
C     Run-Control Block values.

      IMPLICIT NONE
      INCLUDE 'rcblock.cmn'
C***********************************************************************
C     Default for: NBRA. Changed from 1 to 0. Version 9.93
      RCBITAB(  1) = 0           
C     Default for: NEX. Changed from 2 to 0. Version 9.93
      RCBITAB(  2) = 0           
C     Default for: MINPRT      
      RCBITAB(  3) = 0           
C     Default for: LAGTSF      
      RCBITAB(  4) = 0           
C     Default for: DMYEAR      
      RCBITAB(  5) = 1925        
C     Default for: DMMN        
      RCBITAB(  6) = 1           
C     Default for: ZIY         
      RCBFTAB(  7) = 0.0         
C     Default for: SYR         
      RCBITAB(  8) = 1901        
C     Default for: SMN         
      RCBITAB(  9) = 1           
C     Default for: SDY         
      RCBITAB( 10) = 1           
C     Default for: SFRAC       
      RCBDTAB(  6) = 0.0D0       
C     Default for: EYR         
      RCBITAB( 14) = 1900 
C     Default for: EMN
      RCBITAB( 15) = 1       
C     Default for: EDY         
      RCBITAB( 16) = 1           
C     Default for: EFRAC       
      RCBDTAB(  9) = 0.0D0       
C     Default for: GRAV        
      RCBFTAB( 19) = 32.174      
C     Default for: SSEPS       
      RCBFTAB( 20) = 0.1         
C     Default for: PAGE        
      RCBITAB( 21) = 24          
C     Default for: EPSSYS      
      RCBFTAB( 22) = 0.05        
C     Default for: ABSTOL      
      RCBFTAB( 23) = 0.000005       
C     Default for: EPSFAC      
      RCBFTAB( 24) = 2.0         
C     Default for: MKNT        
      RCBITAB( 25) = 5           
C     Default for: NUMLIM      
      RCBITAB( 26) = 0           
C     Default for: OUTPUT      
      RCBITAB( 27) = 0           
C     Default for: PROUT       
      RCBITAB( 28) = 0           
C     Default for: PRTINT      
      RCBITAB( 29) = 1           
C     Default for: YR          
      RCBITAB( 30) = 9999        
C     Default for: MN          
      RCBITAB( 31) = 12          
C     Default for: DY          
      RCBITAB( 32) = 31          
C     Default for: HR          
      RCBDTAB( 17) = 24.D0       
C     Default for: EPSB        
      RCBFTAB( 36) = 0.0005      
C     Default for: MAXIT       
      RCBITAB( 38) = 30          
C     Default for: SFAC        
      RCBFTAB( 39) = 5280.       
C     Default for: TAUFAC      
      RCBFTAB( 40) = 1.0         
C     Default for: QEPS        
      RCBFTAB( 41) = 1.0         
C     Default for: QCHOP --Special value to get correct units depending on GRAV.      
      RCBFTAB( 42) = -1.0
C     Default for: IFRZ
      RCBITAB(43) = 1       
C     Default for: DTVEC(1)    
      RCBFTAB( 44) = 300.0       
C     Default for: DTVEC(2)    
      RCBFTAB( 45) = 300.0       
C     Default for: DTVEC(3)    
      RCBFTAB( 46) = 300.0       
C     Default for: DTVEC(4)    
      RCBFTAB( 47) = 300.0       
C     Default for: DTVEC(5)    
      RCBFTAB( 48) = 300.0       
C     Default for: DTVEC(6)    
      RCBFTAB( 49) = 300.0       
C     Default for: DTVEC(7)    
      RCBFTAB( 50) = 300.0       
C     Default for: DTVEC(8)    
      RCBFTAB( 51) = 300.0       
C     Default for: DTVEC(9)    
      RCBFTAB( 52) = 300.0       
C     Default for: DTVEC(10)   
      RCBFTAB( 53) = 300.0       
C     Default for: MAXDT       
      RCBFTAB( 54) = 1800.       
C     Default for: MINDT       
      RCBFTAB( 55) = 1.0         
C     Default for: AUTO        
      RCBFTAB( 56) = 0.7         
C     Default for: SITER       
      RCBFTAB( 57) = 2.8         
C     Default for: HIGH        
      RCBFTAB( 58) = 3.2         
C     Default for: LOW         
      RCBFTAB( 59) = 2.4
C     Default for: HFAC        
      RCBFTAB( 60) = 2.0         
C     Default for: LFAC        
      RCBFTAB( 61) = 0.5         
C     Default for: MRE         
      RCBFTAB( 62) = 0.20        
C     Default for: FAC         
      RCBFTAB( 63) = 0.0         
C     Default for: HSLOT       
      RCBFTAB( 64) = 0.0         
C     Default for: WSLOT       
      RCBFTAB( 65) = 0.0         
C     Default for: NSLOT       
      RCBFTAB( 66) = 0.0         
C     Default for: DWT         
      RCBFTAB( 67) = 0.1         
C     Default for: BWT         
      RCBFTAB( 68) = 0.55        
C     Default for: EXTTOL      
      RCBFTAB( 69) = 0.0         
C     Default for: SQREPS      
      RCBFTAB( 70) = 1E30 

C     Control for detailed printout and dumping of equations added: Feb. 14, 2001
C     Default for: START_EQ
      RCBITAB( 71) = 2
C     Default for: END_EQ
      RCBITAB( 72) = 1
C     Default for: DTMIN_OUT
      RCBFTAB(73) = 0.0

c     High IQ Newton solution control added: Feb. 26, 2003
c     Default for: HI_IQ_NS_DWN
      rcbftab(74) = 0.5
c     Default for: HI_IQ_NS_UP
      rcbftab(75) = sqrt(1.0/rcbftab(74))
c     Default for: HI_IQ_NS_LMT
      rcbftab(76) = 0.1
c     Default for: HI_IQ_NS_NUMGT  added 8 april 2003.
c     The default value was near optimum for a test model having 13,808 unknowns!
c     I think that a small number will always prove to be optimum no matter the size of the
c     model.       
      rcbitab( 77) = 4

c     Default for: HI_IQ_NS_KNT 
      rcbitab( 78) = 25

c     Default for: HI_IQ_NS_DT
      rcbftab( 79) = 40.0
c     Default for: DZ_FOR_OUTPUT
      rcbftab( 80) = 0.0

             
C     Default for: SOPER       
      RCBCTAB(  1) = 'NO'        
C     Default for: POINT       
      RCBCTAB(  2) = 'NO'        
C     Default for: DIFFUS      
      RCBCTAB(  3) = 'NO'        
C     Default for: WIND        
      RCBCTAB(  4) = 'NO'        
C     Default for: UNDERF      
      RCBCTAB(  5) = 'NO'        
C     Default for: NODEID      
      RCBCTAB(  6) = 'YES'       
C     Default for: GENAME      
      RCBCTAB(  7) = 'STDX'      
C     Default for: BWFNAM      
      RCBCTAB(  8) = '     '     
C     Default for: CHKGEO      
      RCBCTAB(  9) = 'NO'        
C     Default for: ISTYLE      
      RCBCTAB( 10) = 'NEW'       
C     Default for: GETIC       
      RCBCTAB( 11) = '   '       
C     Default for: PUTFC       
      RCBCTAB( 12) = '   '       
C     Default for OLD_SUMMARY--added June 1999
      RCBCTAB( 13) = 'YES'
C     Default for GISID_TO_NODEID--added Dec 1999
      RCBCTAB( 14) = 'NO'
C     Default for TABID_TO_NODEID--added Dec 1999
      RCBCTAB( 15) = 'NO'
C     Default for DO_SCHEMATIC--added July 31, 2000
      RCBCTAB( 16) = 'NO'
C     Default for CD14_TAB_DATUM--added August 2, 2000
      RCBCTAB( 17) = 'NO'
C     Default for CDT6_TAB_DATUM--added August 2, 2000
      RCBCTAB( 18) = 'NO'      
C     Default for NEW_GENSCN_FEO--Added Sept. 27, 2000
c     Changed to YES 28 March 2006.  GENSCN will be changed!
      RCBCTAB( 19) = 'YES'
C     Default for global HOME value--Added May 17, 2002
      RCBCTAB( 20) = ' '
c     Default for HI_IQ_NS value--Added Feb. 26, 2003
      RCBCTAB( 21) = 'NO'
c     Default for TY13_TO_TY43
      RCBCTAB( 22) = 'NO'
c     Default for UPGRADE_XSEC_TAB
      RCBCTAB( 23) = 'NO'
c     Default for MAKE_DT_TAB-Added April 7, 2003
      RCBCTAB( 24) = ' '
c     Default for USE_MAXDT_TAB
      RCBCTAB( 25) = ' '
c     Default for forecasting with a DTSF present-added 27 Sept 2005
      rcbctab( 26) = 'NO'

c     The following five values express what FEQ expects or demands to see in the
c     header block of function tables it uses.
c 
c     Default for the zone of the horizontal grid used to define location
c     of a function table
      rcbctab( 27) = 'NONE'
c     Default for the horizontal-grid name defining location.
      rcbctab( 28) = 'NONE'
c       Rules: 1. Zone and hgrid must both be non-NONE if one of them is.  That is,
c                 we assume that any hgrid will have some zone designation.  If the one
c                 in use does not, well, make one up, and just be consistent!
c              2. If non-NONE, FEQ will output a file in the home output directory, that contains
c                 a list of all table ids that have a zone/hgrid value that differs from the
c                 one given in the run-control block.  The run will continue however, and 
c                 currently, FEQ makes not direct use of these two values. 
c             3.  If non-NONE, FEQ will report in a file, the table ids and the easting
c                 and northings for all tables that have these values missing and for 
c                 which FEQ is able to deduce a location by its internal rules.  This
c                 information, combined with a table index, requested below, and a utility
c                 program, will then update all function tables, to have that easting and
c                 northing.  Also, in some cases, the utility program will also update
c                 the FEQUTL input used to generate the table so that on the next 
c                 computation of the table, the easting and northing will be correct.
c             4.  If both are NONE, then FEQ ignores any information, if it is present,
c                 on the horizontal grid differences in the input tables.  Also nothing 
c                 is done about missing easting and northing items.

c     Default for the name of the vertical datum used for elevations in the table, if any
      rcbctab( 29) = 'NONE'
c       Rules:  1. If NONE, FEQ ignores any information, even if present, in function tables. 
c                  This is necessary to support models that know nothing about these new features.
c               2. If non-NONE, FEQ reports all table ids that disagree in vertical datum and
c                  terminates the run!  Mixed datums are deadly:)
c               3. Some utilities will be created to help in updating vertical datums.  However,
c                  some updates will be manual. 

c     Default for the unit system used in a function table
      rcbctab( 30) = 'NONE'
c       Rules:  1. If non-NONE, FEQ will report all table ids that differ and terminate
c                  the run.  The disparate units will have to be corrected either manually
c                  or by using the features present in FEQ to produce a function table in 
c                  the proper unit system. 
c     Default for the basis for the information in function tables.  This relates to dates,
c       and nature of the basic data.  
      rcbctab( 31) = 'NONE'
c       Rules:  1. If non-NONE, FEQ will report those tab ids that differ.  This can then
c                  be used to find tables that need to be updated. 
c               2. The string is only 8 characters long, so be careful in what you pick to 
c                  describe the basis.  A year and a few well-chosen characters should do it!
c     Default for requesting a function-table index
      rcbctab( 32) = 'NO'
c       Rules:  1. If YES, then FEQ will construct an index of table ids, with the ids sorted
c                  in whatever sequence Fortran uses for character strings, with the table
c                  type, and with the fully qualified file name that contains the table. 
c                  This table is usable manually, searching with a text editor, or usable
c                  by a utility program to find the file that contains a given table id.
c                  If standard naming conventions, and locations are used for the input 
c                  file to FEQUTL, then it could be possible to update the input file
c                  that created the function table. 


      RETURN
      END
C
C
C

      SUBROUTINE  SET_RCB1(
     O                     NBRA, NEX, MINPRT, LAGTSF, DMYEAR, DMMN,
     O                     ZIY, SYR, SMN, SDY, SFRAC, EYR, EMN, EDY,    
     O                     EFRAC, GRAV, SSEPS, PAGESP, EPSSYS, ABSTOL,  
     O                     EPSFAC, MKNT, NUMLIM, OUTPUT, PROUT,         
     O                     PRTINT, YR, MN, DY, HR, EPSB, MAXIT, SFAC,   
     O                     TAUFAC, QEPS, QCHOP, SOPER, POINT, DIFFUS, 
     O                     WIND, UNDERF, NODEID, GENAME, OLD_SUMMARY,
     O                     GISID_TO_NODEID, TABID_TO_NODEID,
     O                     DO_SCHEMATIC, CD14_TAB_DATUM,
     O                     CD5T6_TAB_DATUM, NEW_GENSCN_FEO, START_EQ,
     O                     END_EQ, DTMIN_OUT, GLB_HOME, hi_iq_ns,
     o                     hi_iq_ns_dwn, hi_iq_ns_up, hi_iq_ns_lmt,
     o                     ty13_to_ty43, upgrade_xsec_tab, make_dt_tab,
     o                     use_maxdt_tab, hi_iq_ns_numgt, hi_iq_ns_knt,
     o                     hi_iq_ns_dt, frcst_wth_dtsf, zone, hgrid,
     o                     vdatum, unitsys, basis, make_tab_index, 
     o                     dz_for_output)                                 

C     Set the values in the run-control block in INFO1
C     All values not set explicitly by user are at their default value.
      IMPLICIT NONE
      INTEGER NBRA, NEX, MINPRT, LAGTSF, DMYEAR, DMMN,
     *        SYR, SMN, SDY,  EYR, EMN, EDY,
     *        PAGESP,  MKNT, NUMLIM, OUTPUT, PROUT,
     *        PRTINT, YR, MN, DY, MAXIT, START_EQ,
     *        END_EQ, hi_iq_ns_numgt , hi_iq_ns_knt

      REAL  ZIY,  GRAV, SSEPS, EPSSYS, ABSTOL,
     *      EPSFAC, EPSB, SFAC, TAUFAC, QEPS, QCHOP,
     *      DTMIN_OUT, hi_iq_ns_dwn, hi_iq_ns_up, hi_iq_ns_lmt,
     *      hi_iq_ns_dt, dz_for_output

      REAL*8  SFRAC, EFRAC, HR

      CHARACTER  SOPER*4, POINT*4, DIFFUS*4, WIND*4, UNDERF*4,                                       
     *      NODEID*4, GENAME*5, OLD_SUMMARY*4, GISID_TO_NODEID*4,
     *      TABID_TO_NODEID*4, DO_SCHEMATIC*4, CD14_TAB_DATUM*4,
     *      CD5T6_TAB_DATUM*4, NEW_GENSCN_FEO*4, GLB_HOME*128 ,
     *      hi_iq_ns*4, ty13_to_ty43*4, upgrade_xsec_tab*4,
     *      make_dt_tab*256, use_maxdt_tab*16,frcst_wth_dtsf*4,
     *      zone*8, hgrid*8, vdatum*8, unitsys*8, basis*8,
     *      make_tab_index*4

      INCLUDE 'rcblock.cmn'
C***********************************************************************
      NBRA        = RCBITAB(  1)
      NEX         = RCBITAB(  2)
      MINPRT      = RCBITAB(  3)
      LAGTSF      = RCBITAB(  4)
      DMYEAR      = RCBITAB(  5)
      DMMN        = RCBITAB(  6)
      ZIY         = RCBFTAB(  7)
      SYR         = RCBITAB(  8)
      SMN         = RCBITAB(  9)
      SDY         = RCBITAB( 10)
      SFRAC       = RCBDTAB(  6)
      EYR         = RCBITAB( 14)
      EMN         = RCBITAB( 15)
      EDY         = RCBITAB( 16)
      EFRAC       = RCBDTAB(  9)
      GRAV        = RCBFTAB( 19)
      SSEPS       = RCBFTAB( 20)
      PAGESP        = RCBITAB( 21)
      EPSSYS      = RCBFTAB( 22)
      ABSTOL      = RCBFTAB( 23)
      EPSFAC      = RCBFTAB( 24)
      MKNT        = RCBITAB( 25)
      NUMLIM      = RCBITAB( 26)
      OUTPUT      = RCBITAB( 27)
      PROUT       = RCBITAB( 28)
      PRTINT      = RCBITAB( 29)
      YR          = RCBITAB( 30)
      MN          = RCBITAB( 31)
      DY          = RCBITAB( 32)
      HR          = RCBDTAB( 17)
      EPSB        = RCBFTAB( 36)
      MAXIT       = RCBITAB( 38)
      SFAC        = RCBFTAB( 39)
      TAUFAC      = RCBFTAB( 40)
      QEPS        = RCBFTAB( 41)
      QCHOP       = RCBFTAB( 42)
      START_EQ    = RCBITAB( 71)
      END_EQ      = RCBITAB( 72)
      DTMIN_OUT   = RCBFTAB( 73)
      hi_iq_ns_dwn = rcbftab(74)
      hi_iq_ns_up = rcbftab(75)
      hi_iq_ns_lmt = rcbftab(76)
      hi_iq_ns_numgt = rcbitab(77)
      hi_iq_ns_knt = rcbitab(78)
      hi_iq_ns_dt  = rcbftab(79)
      dz_for_output  = rcbftab(80)

      SOPER       = RCBCTAB(  1)
      POINT       = RCBCTAB(  2)
      DIFFUS      = RCBCTAB(  3)
      WIND        = RCBCTAB(  4)
      UNDERF      = RCBCTAB(  5)
      NODEID      = RCBCTAB(  6)
      GENAME      = RCBCTAB(  7)
      OLD_SUMMARY = RCBCTAB( 13)
      GISID_TO_NODEID = RCBCTAB( 14)
      TABID_TO_NODEID = RCBCTAB( 15)
      DO_SCHEMATIC = RCBCTAB( 16)
      CD14_TAB_DATUM = RCBCTAB( 17)
      CD5T6_TAB_DATUM = RCBCTAB( 18)
      NEW_GENSCN_FEO = RCBCTAB( 19)
      GLB_HOME = RCBCTAB( 20)
      hi_iq_ns = rcbctab( 21)
      ty13_to_ty43 = rcbctab( 22)
      upgrade_xsec_tab = rcbctab( 23)
      make_dt_tab = rcbctab( 24)
      use_maxdt_tab = rcbctab( 25)
      frcst_wth_dtsf = rcbctab( 26)
      zone = rcbctab( 27)
      hgrid = rcbctab( 28)
      vdatum = rcbctab( 29)
      unitsys = rcbctab( 30)
      basis = rcbctab( 31)
      make_tab_index = rcbctab( 32)

      RETURN
      END 

      SUBROUTINE SET_RCB2(
     O                   IFRZ, DTVEC,
     O                   MAXDT, MINDT, AUTO, SITER,                                     
     O                   HIGH, LOW, HFAC, LFAC, MRE, FAC, HSLOT,                                   
     O                   WSLOT, NSLOT, DWT, BWT, EXTTOL, SQREPS,                                   
     O                   BWFNAM, CHKGEO, ISTYLE,                                   
     O                   GETIC, PUTFC)

C     Transfer values into INFO2
C     All values not set explicitly by user are at their default value.

      IMPLICIT NONE
     
      INTEGER  IFRZ
  
      REAL DTVEC(10),
     *      MAXDT, MINDT, AUTO, SITER,
     *      HIGH, LOW, HFAC, LFAC, MRE, FAC, HSLOT,                    
     *      WSLOT, NSLOT, DWT, BWT, EXTTOL, SQREPS   

      CHARACTER BWFNAM*256, CHKGEO*4, ISTYLE*4,
     *      GETIC*256, PUTFC*256

      INCLUDE 'rcblock.cmn'

C*******************************************************************************
C     Force local home name to blank
      CALL CLEAR_HOME()
C     After the first call to MAYBE_ADD_HOME the local home will be the same
C     as the global home.  This is ok here, but may not be elsewhere!
      IFRZ        = RCBITAB( 43)
      DTVEC(1)    = RCBFTAB( 44)                                  
      DTVEC(2)    = RCBFTAB( 45)                                  
      DTVEC(3)    = RCBFTAB( 46)                                  
      DTVEC(4)    = RCBFTAB( 47)                                  
      DTVEC(5)    = RCBFTAB( 48)                                  
      DTVEC(6)    = RCBFTAB( 49)                                  
      DTVEC(7)    = RCBFTAB( 50)                                  
      DTVEC(8)    = RCBFTAB( 51)                                  
      DTVEC(9)    = RCBFTAB( 52)                                  
      DTVEC(10)   = RCBFTAB( 53)                                  
      MAXDT       = RCBFTAB( 54)                                  
      MINDT       = RCBFTAB( 55)                                  
      AUTO        = RCBFTAB( 56)                                  
      SITER       = RCBFTAB( 57)                                  
      HIGH        = RCBFTAB( 58)                                  
      LOW         = RCBFTAB( 59)                                  
      HFAC        = RCBFTAB( 60)                                  
      LFAC        = RCBFTAB( 61)                                  
      MRE         = RCBFTAB( 62)                                  
      FAC         = RCBFTAB( 63)                                  
      HSLOT       = RCBFTAB( 64)                                  
      WSLOT       = RCBFTAB( 65)                                  
      NSLOT       = RCBFTAB( 66)                                  
      DWT         = RCBFTAB( 67)                                  
      BWT         = RCBFTAB( 68)
      EXTTOL      = RCBFTAB( 69)
      SQREPS      = RCBFTAB( 70)
      BWFNAM      = RCBCTAB(  8)
      CALL MAYBE_ADD_GHOME_OUT(
     M                    BWFNAM)
      call maybe_add_ext(
     m                    bwfnam)
      call os_file_style(
     m                       bwfnam)
      CHKGEO      = RCBCTAB(  9)
      ISTYLE      = RCBCTAB( 10)
      GETIC       = RCBCTAB( 11)
c     Note: A global output home name is added to the getic name because
c           this file can only be created by a previous run of FEQ.  Therefore, 
c           if a global output home name is present, that file will be in the 
c           output location.  The user must add any additional extension to 
c           read the proper file.  Therefore we do not add an extension because
c           it could be the wrong one!
      CALL MAYBE_ADD_GHOME_OUT(
     M                    GETIC)
      call os_file_style(
     m                       getic)
      PUTFC       = RCBCTAB( 12)
      CALL MAYBE_ADD_GHOME_OUT(
     M                    PUTFC)
      call maybe_add_ext(
     m                    putfc)

      call os_file_style(
     m                       putfc)
      RETURN
      END


C     ***********
C     *         *
C     * GET_RCB
C     *         *
C     ***********

      SUBROUTINE GET_RCB(STDIN, STDOUT,
     M                   EFLAG)

C     Get the values from the run-control block

      IMPLICIT NONE

C      INCLUDE 'arsize.prm'

      INTEGER STDIN, STDOUT, EFLAG

      INCLUDE 'rcblock.cmn'

C     Local

C     + + + LOCAL PARAMETERS + + +
      INTEGER  N_SYMBOL

      PARAMETER(N_SYMBOL=89)
      INTEGER INTVAL, REAVAL, CHRVAL, DPRVAL, EXACT, LOWER,
     B         DATETIME, MULTR, NUMERIC, CHAR, NXTBLK, ENDSIG,
     C         NONE
      PARAMETER(INTVAL=1, REAVAL=2,  DPRVAL=3, CHRVAL=4, 
     B          EXACT=0, LOWER=1,DATETIME=7, MULTR=8, 
     C          NUMERIC=0, CHAR=1, NXTBLK=2, ENDSIG=3, NONE=0)


      INTEGER MAX_LINE


      EXTERNAL SET_RCB_DEFAULTS, GET_NAMED_ITEMS

C     + + + SAVED VALUES + + +
      INTEGER GROUP(N_SYMBOL), RESPONSE_TYPE(N_SYMBOL),
     A        CONVERT_RULE(N_SYMBOL), GROUP_INDEX(N_SYMBOL)
      CHARACTER SYMBOL_TABLE(N_SYMBOL)*16

      SAVE  SYMBOL_TABLE, GROUP, RESPONSE_TYPE, CONVERT_RULE,
     A      GROUP_INDEX


      DATA  SYMBOL_TABLE /
     *'NBRA','NEX','MINPRT','LAGTSF','DMYEAR','DMMN','ZL','STIME',      
     *'ETIME','GRAV','SSEPS','PAGE','EPSSYS','ABSTOL','EPSFAC','MKNT',  
     *'NUMGT','OUTPUT','PROUT','PRTINT','DPTIME','EPSB','MAXIT','SFAC', 
     *'TAUFAC','QSMALL','QCHOP','IFRZ','MAXDT','MINDT','AUTO','SITER',  
     *'HIGH','LOW','HFAC','LFAC','MRE','FAC','HSLOT','WSLOT','NSLOT',   
     *'DWT','BWT','EXTTOL','SQREPS','SOPER','POINT','DIFFUS','WIND',    
     *'UNDERFLOW','NODEID','GEQOPT','BWFDSN','CHKGEO','ISTYLE','GETIC',
     *'PUTFC','FUNCTION','BRANCH','OLD_SUMMARY','GISID_TO_NODEID',
     *'TABID_TO_NODEID','DO_SCHEMATIC','CD14_TAB_DATUM', 
     *'CD5T6_TAB_DATUM','NEW_GENSCN_FEO','START_EQ','END_EQ',
     *'DTMIN_OUT','HOME','HI_IQ_NS','HI_IQ_NS_DWN','HI_IQ_NS_UP',
     *'HI_IQ_NS_LMT','TY13_TO_TY43','UPGRADE_XSEC_TAB',
     *'MAKE_DT_TAB','USE_MAXDT_TAB','HI_IQ_NS_NUMGT','HI_IQ_NS_KNT',
     *'HI_IQ_NS_DT','FRCST_WTH_DTSF','G_ZONE','G_HGRID','G_VDATUM',
     *'G_UNITSYS','G_BASIS','MAKE_TAB_INDEX','DZ_FOR_OUTPUT'/                                                                 

      DATA GROUP  /
     *NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,          
     *NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,          
     *NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,          
     *NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,          
     *NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,          
     *NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,CHAR,CHAR,CHAR,CHAR,CHAR,
     *CHAR,CHAR,CHAR,CHAR,CHAR,CHAR,CHAR,NXTBLK, NXTBLK,CHAR,CHAR,
     *CHAR,CHAR,CHAR,CHAR,CHAR,NUMERIC,NUMERIC,NUMERIC,CHAR,CHAR,
     *NUMERIC,NUMERIC,NUMERIC,CHAR,CHAR,CHAR,CHAR,NUMERIC,NUMERIC,
     *NUMERIC,CHAR,CHAR,CHAR,CHAR,CHAR,CHAR,CHAR, NUMERIC/

      DATA GROUP_INDEX /
     *1,2,3,4,5,6,7,8,14,19,20,21,22,23,24,25,26,27,28,29,30,36,38,39,          
     *40,41,42,43,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,1,         
     *2,3,4,5,6,7,8,9,10,11,12,0,0,13,14,15,16,17,18,19,71,72,73,20,
     *21,74,75,76,22,23,24,25,77,78,79,26,27,28,29,30,31,32,80/                                                 
                                       

      DATA RESPONSE_TYPE  /
     *INTVAL,INTVAL,INTVAL,INTVAL,INTVAL,INTVAL,REAVAL,DATETIME,                
     *DATETIME,REAVAL,REAVAL,INTVAL,REAVAL,REAVAL,REAVAL,INTVAL,INTVAL,         
     *INTVAL,INTVAL,INTVAL,DATETIME,REAVAL,INTVAL,REAVAL,REAVAL,REAVAL,         
     *REAVAL,MULTR, REAVAL,REAVAL,REAVAL,REAVAL,REAVAL,REAVAL,REAVAL,           
     *REAVAL,REAVAL,REAVAL,REAVAL,REAVAL,REAVAL,REAVAL,REAVAL,REAVAL,           
     *REAVAL,CHRVAL,CHRVAL,CHRVAL,CHRVAL,CHRVAL,CHRVAL,CHRVAL,CHRVAL,
     *CHRVAL,CHRVAL,CHRVAL,CHRVAL,NONE, NONE,CHRVAL,CHRVAL,CHRVAL,
     *CHRVAL,CHRVAL, CHRVAL,CHRVAL,INTVAL, INTVAL, REAVAL, CHRVAL,
     *CHRVAL,REAVAL,REAVAL,REAVAL,CHRVAL,CHRVAL,CHRVAL,CHRVAL,
     *INTVAL,INTVAL,REAVAL,CHRVAL,6*CHRVAL,REAVAL/                                                                     
    
      DATA CONVERT_RULE /
     *EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,0,0,EXACT,EXACT,EXACT,
     *EXACT,EXACT,LOWER,EXACT,EXACT,EXACT,EXACT,EXACT,0,EXACT,EXACT,
     *LOWER,LOWER,LOWER,EXACT,EXACT,LOWER,LOWER,EXACT,LOWER,LOWER,
     *LOWER,LOWER,LOWER,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,
     *EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,
     *EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,
     *EXACT,EXACT,EXACT,EXACT,EXACT,LOWER,EXACT,EXACT,LOWER,LOWER,
     *LOWER,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,LOWER,EXACT,5*LOWER,
     *EXACT,LOWER/
   
C***********************************************************************
C     Set Defaults
 
      CALL SET_RCB_DEFAULTS()

      MAX_LINE = 1000
      CALL GET_NAMED_ITEMS(
     I                     STDIN, STDOUT,  MAX_LINE, N_SYMBOL,
     I  GROUP, RESPONSE_TYPE, CONVERT_RULE, GROUP_INDEX, SYMBOL_TABLE,
     I  MAXR_RC, HMAXR_RC,  MAXC_RC, 'Run-Control Block',
     O  RCBITAB, RCBFTAB, RCBDTAB, RCBCTAB,
     O  EFLAG)

      RETURN
      END
C
C
C
      SUBROUTINE SET_BRHD_DEFAULTS()

C     Set the default values in the vectors used to process a
C     branch header line
      IMPLICIT NONE
      INCLUDE 'brhd.cmn'

C***********************************************************************
C     Default for: BNIN
      BRHDITAB(  1) = 1           
C     Default for: INERT
      BRHDFTAB(  2) = 1.0
C     Default for: CFRATE
      BRHDFTAB(  3) = 0.0        
C     Default for: WDFAC
      BRHDFTAB(  4) = 1.0
C     Default for: ADDNOD      
      BRHDITAB(  5) =  0       
C     Default for: GENAME
      BRHDCTAB(  1) = '    '
      RETURN
      END
C
C
C
      SUBROUTINE  SET_BRHD(
     O                     BNIN, INERT, CFRATE, WDFAC, ADDNOD, GENAME)

C     Set the values in the run-control block in INFO1
C     All values not set explicitly by user are at their default value.
      IMPLICIT NONE

      INTEGER BNIN, ADDNOD
      REAL INERT, CFRATE, WDFAC
      CHARACTER GENAME*5


      INCLUDE 'brhd.cmn'
C***********************************************************************
      BNIN        = BRHDITAB(  1)
      INERT       = BRHDFTAB(  2)
      CFRATE      = BRHDFTAB(  3)
      WDFAC       = BRHDFTAB(  4)
      ADDNOD      = BRHDITAB(  5)
      GENAME      = BRHDCTAB(  1)
      RETURN
      END

C     ***********
C     *         *
C     * GET_BRHD
C     *         *
C     ***********

      SUBROUTINE GET_BRHD(STDIN, STDOUT,
     M                   EFLAG)

C     Get the values from the Branch header

      IMPLICIT NONE

C      INCLUDE 'arsize.prm'

      INTEGER STDIN, STDOUT, EFLAG

      INCLUDE 'brhd.cmn'

C     Local

C     + + + LOCAL PARAMETERS + + +
      INTEGER  INTVAL, REAVAL, 
     A         CHRVAL, DPRVAL, EXACT, LOWER,
     B         NUMERIC, CHAR, N_SYMBOL
      PARAMETER(N_SYMBOL=8, INTVAL=1, REAVAL=2,
     A          DPRVAL=3, CHRVAL=4, 
     B          EXACT=0,LOWER=1, NUMERIC=0, CHAR=1)

      INTEGER MAX_LINE
     A        

      EXTERNAL GET_NAMED_ITEMS, SET_BRHD_DEFAULTS

C     + + + SAVED VALUES + + +
      INTEGER GROUP(N_SYMBOL), RESPONSE_TYPE(N_SYMBOL),
     A        CONVERT_RULE(N_SYMBOL), GROUP_INDEX(N_SYMBOL)
      CHARACTER SYMBOL_TABLE(N_SYMBOL)*16

      SAVE  SYMBOL_TABLE, GROUP, RESPONSE_TYPE, CONVERT_RULE,
     A      GROUP_INDEX

      DATA  SYMBOL_TABLE /
     *'BNUM','BRANCH','INERTIA','CFRATE','WINDFAC','ADDNOD',
     *'ADDNODE','GEQOPT'/
                                                                      
      DATA GROUP  /
     *NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,NUMERIC,CHAR/          

      DATA GROUP_INDEX /
     *1,1,2,3,4,5,5,1/
                                       
      DATA RESPONSE_TYPE  /
     *INTVAL,INTVAL,REAVAL,REAVAL,REAVAL,INTVAL,INTVAL,CHRVAL/
    
      DATA CONVERT_RULE /
     *EXACT,EXACT,LOWER,LOWER,LOWER,EXACT,EXACT,EXACT/
   
C***********************************************************************
C     Set Defaults
 
      CALL SET_BRHD_DEFAULTS()

      MAX_LINE = 1
      CALL GET_NAMED_ITEMS(
     I                     STDIN, STDOUT,  MAX_LINE, N_SYMBOL,
     I  GROUP, RESPONSE_TYPE, CONVERT_RULE, GROUP_INDEX, SYMBOL_TABLE,
     I  MAXR_BRHD, MAXDP_BRHD, MAXC_BRHD, 'Branch-header items',
     O  BRHDITAB, BRHDFTAB, BRHDDTAB, BRHDCTAB,
     O  EFLAG)
      
      RETURN

      END
C
C
C
      SUBROUTINE SET_TABHD_DEFAULTS()

C     Set the default values in the vectors used to process a
C     tributary area header block
      IMPLICIT NONE
      INCLUDE 'tabhd.cmn'

C***********************************************************************
C     Default for: NLUSE -Number of land uses summed over all gages
      TABHDITAB(  1) = 4           
C     Default for: NGAGE - Number of gates
      TABHDITAB(  2) = 2
C     Default for: TSFNAM  - Name of file for time series of runoff intensity 
      TABHDCTAB(  1) = '    '
C     Default for: FFFNAM - Name for flood-frequency data file
      TABHDCTAB(  2) = '   '
C     Default for: HOME
      TABHDCTAB(  3) = ' '
      RETURN
      END
C
C
C
      SUBROUTINE  SET_TABHD(
     O                     TSFNAM, FFFNAM, NLUSE, NGAGE, TABHOME)

C     All values not set explicitly by user are at their default value.
      IMPLICIT NONE

      INTEGER NLUSE, NGAGE
      CHARACTER TSFNAM*256, FFFNAM*256, TABHOME*128


      INCLUDE 'tabhd.cmn'
C***********************************************************************
      NLUSE       = TABHDITAB(  1)
      NGAGE       = TABHDITAB(  2)
      TSFNAM      = TABHDCTAB(  1)
      FFFNAM      = TABHDCTAB(  2)
      TABHOME     = TABHDCTAB(  3)
      RETURN
      END

C     ***********
C     *         *
C     * GET_TABHD
C     *         *
C     ***********

      SUBROUTINE GET_TABHD(STDIN, STDOUT,
     M                   EFLAG)

C     Get the values from the Tributary Area Block HeaDer

      IMPLICIT NONE

C      INCLUDE 'arsize.prm'

      INTEGER STDIN, STDOUT, EFLAG

      INCLUDE 'tabhd.cmn'

C     Local

C     + + + LOCAL PARAMETERS + + +
      INTEGER  INTVAL, REAVAL, NXTBLK,
     A         CHRVAL, DPRVAL, EXACT, LOWER,
     B         NUMERIC, CHAR, N_SYMBOL
      PARAMETER(N_SYMBOL=8, INTVAL=1, REAVAL=2,
     A          DPRVAL=3, CHRVAL=4, NXTBLK=2, 
     B          EXACT=0,LOWER=1, NUMERIC=0, CHAR=1)

      INTEGER MAX_LINE
     A        

      EXTERNAL GET_NAMED_ITEMS, SET_TABHD_DEFAULTS

C     + + + SAVED VALUES + + +
      INTEGER GROUP(N_SYMBOL), RESPONSE_TYPE(N_SYMBOL),
     A        CONVERT_RULE(N_SYMBOL), GROUP_INDEX(N_SYMBOL)
      CHARACTER SYMBOL_TABLE(N_SYMBOL)*16

      SAVE  SYMBOL_TABLE, GROUP, RESPONSE_TYPE, CONVERT_RULE,
     A      GROUP_INDEX

      DATA  SYMBOL_TABLE /
     *'TSFDSN','TSFNAM','FFFDSN','FFFNAM','NLUSE','NGAGE',
     *'GAGE','HOME'/
                                                                      
      DATA GROUP  /
     *CHAR,CHAR,CHAR,CHAR,NUMERIC,NUMERIC,NXTBLK,CHAR/          

      DATA GROUP_INDEX /
     *1,1,2,2,1,2,1,3/

C     Note that the response type for the group: NXTBLK
C     is 0.  This skips any conversion attempt on the value.                                       
      DATA RESPONSE_TYPE  /
     *CHRVAL,CHRVAL,CHRVAL,CHRVAL,INTVAL,INTVAL,0,CHRVAL/
    
      DATA CONVERT_RULE /
     *EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT,EXACT/
   
C***********************************************************************
C     Set Defaults
 
      CALL SET_TABHD_DEFAULTS()

      MAX_LINE = 5
      CALL GET_NAMED_ITEMS(
     I                     STDIN, STDOUT,  MAX_LINE, N_SYMBOL,
     I  GROUP, RESPONSE_TYPE, CONVERT_RULE, GROUP_INDEX, SYMBOL_TABLE,
     I  MAXR_TABHD, MAXDP_TABHD, MAXC_TABHD, 'Trib-area items',
     O  TABHDITAB, TABHDFTAB, TABHDDTAB, TABHDCTAB,
     O  EFLAG)
      
      RETURN

      END




C
C
C
      SUBROUTINE SET_TABBRH_DEFAULTS()

C     Set the default values in the vectors used to process a
C     tributary area block branch header
      IMPLICIT NONE
      INCLUDE 'tabbrh.cmn'

C***********************************************************************
C     Default for: USBRA -User branch number
      TABBRHITAB(  1) = 1           
C     Default for: FAC - Adjustment factor for tributary areas
      TABBRHFTAB(  2) = 1.0
      END
C
C
C
      SUBROUTINE  SET_TABBRH(
     O                     USBRA, FAC)

C     All values not set explicitly by user are at their default value.
      IMPLICIT NONE

      INTEGER USBRA
      REAL FAC

      INCLUDE 'tabbrh.cmn'
C***********************************************************************
      USBRA       = TABBRHITAB(  1)
      FAC         = TABBRHFTAB(  2)
      RETURN
      END

C     ***********
C     *         *
C     * GET_TABBRH
C     *         *
C     ***********

      SUBROUTINE GET_TABBRH(STDIN, STDOUT,
     M                   EFLAG)

C     Get the values from the Tributary Area Block BRanch Header 

      IMPLICIT NONE

C      INCLUDE 'arsize.prm'

      INTEGER STDIN, STDOUT, EFLAG

      INCLUDE 'tabbrh.cmn'

C     Local

C     + + + LOCAL PARAMETERS + + +
      INTEGER  INTVAL, REAVAL, NXTBLK,
     A         CHRVAL, DPRVAL, EXACT, LOWER,
     B         NUMERIC, CHAR, N_SYMBOL
      PARAMETER(N_SYMBOL=2, INTVAL=1, REAVAL=2,
     A          DPRVAL=3, CHRVAL=4, NXTBLK=2, 
     B          EXACT=0,LOWER=1, NUMERIC=0, CHAR=1)

      INTEGER MAX_LINE
     A        

      EXTERNAL GET_NAMED_ITEMS, SET_TABBRH_DEFAULTS

C     + + + SAVED VALUES + + +
      INTEGER GROUP(N_SYMBOL), RESPONSE_TYPE(N_SYMBOL),
     A        CONVERT_RULE(N_SYMBOL), GROUP_INDEX(N_SYMBOL)
      CHARACTER SYMBOL_TABLE(N_SYMBOL)*16

      SAVE  SYMBOL_TABLE, GROUP, RESPONSE_TYPE, CONVERT_RULE,
     A      GROUP_INDEX

      DATA  SYMBOL_TABLE /
     *'BRANCH','FAC'/
                                                                      
      DATA GROUP  /
     *NUMERIC,NUMERIC/          

      DATA GROUP_INDEX /
     *1,2/

      DATA RESPONSE_TYPE  /
     *INTVAL,REAVAL/
    
      DATA CONVERT_RULE /
     *EXACT,LOWER/
   
C***********************************************************************
C     Set Defaults
 
      CALL SET_TABBRH_DEFAULTS()

      MAX_LINE = 1
      CALL GET_NAMED_ITEMS(
     I                     STDIN, STDOUT,  MAX_LINE, N_SYMBOL,
     I  GROUP, RESPONSE_TYPE, CONVERT_RULE, GROUP_INDEX, SYMBOL_TABLE,
     I  MAXR_TABBRH, MAXDP_TABBRH, MAXC_TABBRH, 
     I  'Trib-area blck brnch hdr',
     O  TABBRHITAB, TABBRHFTAB, TABBRHDTAB, TABBRHCTAB,
     O  EFLAG)
      
      RETURN

      END



C
C
C
      SUBROUTINE GET_LUSE_ITEMS(
     I                          STDOUT, LINE, NITEM, ITEM_START,
     I                          ITEM_END,
     M                          EFLAG,
     O                          GAGE, NUM)

C     Get the items of data from gage-land use line
      IMPLICIT NONE
      INTEGER STDOUT, NITEM, ITEM_START(NITEM), ITEM_END(NITEM),
     A        EFLAG, GAGE, NUM
      CHARACTER LINE*80

C     Local

      INTEGER IE, IS, N
      CHARACTER TPC*20

C     Called program units
      EXTERNAL STRIP_L_BLANKS
C     ***********************FORMATS************************************
50    FORMAT(/,' *ERR:400* ',I3,' items given in ',
     A          'Gage-land use line.  Need exactly two items.')
C*******************************************************************************
      IF(NITEM.NE.2) THEN
        WRITE(STDOUT,50) NITEM
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      N = 1
C     Process the gage number
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      
      READ(TPC,'(i5)') GAGE

C     Process the number of land uses for the gage
      N = 2
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      READ(TPC,'(i5)') NUM

      RETURN
      END
C
C
C
      SUBROUTINE GET_TRB_A_ITEMS_NDBR(
     I                           STDOUT, LINE, NITEM, ITEM_START,
     I                           ITEM_END, LPR, GEND, GSTART,
     M                           EFLAG, 
     O                           USNODE, NODE, GAGE, A)

C     Get the items of data from a tributary area line in NODE or
C     BRANCH format

      IMPLICIT NONE
      INCLUDE 'arsize.prm'

      INTEGER STDOUT, NITEM, ITEM_START(NITEM), ITEM_END(NITEM),
     A        NODE, EFLAG, GEND(0:MXGAGE), GSTART(0:MXGAGE)
      REAL A(MXN_LU_G)
      CHARACTER LPR*3, USNODE*5, LINE*112

C     Local

      INTEGER I, IE, IS, N, NEEDED, GAGE
      CHARACTER TPC*20

C     Called program units
      EXTERNAL STRIP_L_BLANKS

C     ***********************FORMATS************************************
50    FORMAT(/,' *ERR:401* Only ',I3,' items given in a ',
     A          'Trib-Area line.  Need at least ',I3,' items.')
52    FORMAT(/,' *ERR:401* Only ',I3,' items given in a ',
     A          'Trib-Area line.  Need at least 4 items.')
54    FORMAT(/,' *ERR:141* Gage number:',I5,' out of range')
C*******************************************************************************
      IF(NITEM.LT.2) THEN
        WRITE(STDOUT,52) NITEM
        STOP 'Abnormal stop.  Errors found.'
      ENDIF
     
      N = 1
C     Process the USNODE (LPR =LPR) or NODE(LPR not= LPR)
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      IF(LPR.EQ.'LPR') THEN
C       Level-pool reservoirs or boundary nodes.  
        USNODE = TPC(1:5)
        IF(USNODE(1:1).EQ.'-') THEN
C         We have found the terminating line for this
C         set of LPR's or boundary nodes. 
          NODE = -1
        ELSE
          NODE = 1
        ENDIF
      ELSE
        READ(TPC,*,ERR=999) NODE
        USNODE = ' '
      ENDIF

C     Process the raingage number
      N = 2
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      IF(TPC.EQ.' ') THEN
        GAGE = 0
      ELSE
        READ(TPC,*,ERR=999) GAGE
      ENDIF
      
      IF(NODE.LT.0) THEN
C       Input complete for LPR or boundary node
        RETURN
      ENDIF

C     GAGE should be valid here
      IF(GAGE.LT.1.OR. GAGE.GT.MXGAGE) THEN
        WRITE(STDOUT,54) GAGE
        STOP 'Abnormal stop.  Errors found.'
      ENDIF


      NEEDED = 2 + GEND(GAGE) - GSTART(GAGE) + 1
      IF(NITEM.LT.NEEDED) THEN
        WRITE(STDOUT,50) NITEM, NEEDED
        STOP 'Abnormal stop.  Errors found.'
      ENDIF


      IF(GAGE.GT.0) THEN
C       Process the trib-area values.  There should be NEEDED-2 of them
        DO 100 N=3,NEEDED 
          I = N - 2
          IS = ITEM_START(N)
          IE = ITEM_END(N)
          TPC = LINE(IS:IE)
          CALL STRIP_L_BLANKS(
     M                        TPC)
          READ(TPC,'(F15.0)',ERR=998) A(I)
100     CONTINUE
      ELSE
        A = 0.0
      ENDIF
      RETURN

998   CONTINUE
      WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
      WRITE(STDOUT,*) TPC
      STOP 'Abnormal stop: errors found.'
      RETURN
999   CONTINUE
      EFLAG = 1
      RETURN
      END


C
C
C
      SUBROUTINE GET_TRB_A_ITEMS_STRNG(
     I                           STDOUT, LINE, NITEM, ITEM_START,
     I                           ITEM_END, GEND, GSTART,
     M                           EFLAG, 
     O                           USTAT, DSTAT, GAGE, A)

C     Get the items of data from a tributary area line in Station-
C     Range format

      IMPLICIT NONE
      INCLUDE 'arsize.prm'

      INTEGER STDOUT, NITEM, ITEM_START(NITEM), ITEM_END(NITEM),
     A        NODE, EFLAG, GEND(0:MXGAGE), GSTART(0:MXGAGE)
      REAL A(MXN_LU_G), USTAT, DSTAT
      CHARACTER  LINE*112

C     Local

      INTEGER I, IE, IS, N, NEEDED, GAGE
      CHARACTER TPC*20

C     Called program units
      EXTERNAL STRIP_L_BLANKS

C     ***********************FORMATS************************************
50    FORMAT(/,' *ERR:401* Only ',I3,' items given in a ',
     A          'Trib-Area line.  Need at least ',I3,' items.')
52    FORMAT(/,' *ERR:401* Only ',I3,' items given in a ',
     A          'TRib-Area line.  Need at least 4 items.')
54    FORMAT(/,' *ERR:141* Gage number:',I5,' out of range')
C*******************************************************************************
      IF(NITEM.LT.2) THEN
        WRITE(STDOUT,52) NITEM
        STOP 'Abnormal stop.  Errors found.'
      ENDIF
     
      N = 1
C     Process USTAT
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      READ(TPC,*,ERR=999) USTAT

      N = 2
C     Process DSTAT
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      READ(TPC,'(f20.0)',ERR=999) DSTAT

C     Process the raingage number
      N = 3
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      IF(TPC.EQ.' ') THEN
        GAGE = 0
      ELSE
        READ(TPC,'(i5)',ERR=999) GAGE
      ENDIF
      
      IF(GAGE.GT.0) THEN
C       GAGE should be valid.
        IF(GAGE.LT.1.OR. GAGE.GT.MXGAGE) THEN
          WRITE(STDOUT,54) GAGE
          STOP 'Abnormal stop.  Errors found.'
        ENDIF
      ENDIF
      NEEDED = 3 + GEND(GAGE) - GSTART(GAGE) + 1
      IF(NITEM.LT.NEEDED) THEN
        WRITE(STDOUT,50) NITEM, NEEDED
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      IF(GAGE.GT.0) THEN
C       Process the trib-area values.  There should be NEEDED-3 of them
        DO 100 N=4,NEEDED 
          I = N - 3
          IS = ITEM_START(N)
          IE = ITEM_END(N)
          TPC = LINE(IS:IE)
          CALL STRIP_L_BLANKS(
     M                        TPC)
          READ(TPC,'(f20.0)',ERR=998) A(I)
100     CONTINUE
      ELSE
        A = 0.0
      ENDIF
      RETURN

998   CONTINUE
      WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
      WRITE(STDOUT,*) TPC
      STOP 'Abnormal stop: errors found.'
      RETURN
999   CONTINUE
      EFLAG = 1
      RETURN
      END
