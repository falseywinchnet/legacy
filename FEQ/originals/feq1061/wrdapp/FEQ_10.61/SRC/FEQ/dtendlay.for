C     Contains routines for processing the input for delay and 
C     detention, as well as computing the description for 
C     detention ponds. 

C
C
C
      SUBROUTINE COPY_TRIB_DESCRIPTION_BLOCK(STDOUT,
     I         LAST_NDTA_PNT,
     O         LAST_DTA_PNT)

C     Make a copy of the tributary-area description block 
C     at LAST_NDTA_PNT and allocate space for the new 
C     tributary areas.  Return the address of the new block
C     in LAST_DTA_PNT.

      IMPLICIT NONE
      INTEGER STDOUT, LAST_NDTA_PNT, LAST_DTA_PNT

      INCLUDE 'arsize.prm'
      INCLUDE 'tam.cmn'

C     Local

      INTEGER I, IOFF_MAX

C     *************************Formats**********************************
50    FORMAT(/,' *ERR:327* Space for tributary area description blocks',
     A            ' exhausted.')
52    FORMAT(/,' *ERR:328* Space for tributary area values exhausted.')
C***********************************************************************
      IF(TAM_ITAB(LAST_NDTA_PNT+1).EQ.1) THEN
        IOFF_MAX = 9
      ELSE
        IOFF_MAX = 8
      ENDIF
      LAST_DTA_PNT = TAM_IPNT      
      IF(TAM_IPNT + IOFF_MAX.GT.TAM_MXNI) THEN
        WRITE(STDOUT,50)
        STOP 'Abnormal stop. Errors found.'
      ENDIF
      DO 100 I=0,IOFF_MAX
        TAM_ITAB(LAST_DTA_PNT+I) = TAM_ITAB(LAST_NDTA_PNT+I)
100   CONTINUE
C     Count the new block.
      TUNIT_KNT = TUNIT_KNT + 1
C     Update the pointer for space in TAM_ITAB
      TAM_IPNT = TAM_IPNT + IOFF_MAX + 1
      IF(TUNIT_KNT.GT.MXR_TRIBA) THEN
        WRITE(STDOUT,52)
        STOP 'Abnormal stop. Errors found.'
      ENDIF
      TAM_ITAB(LAST_DTA_PNT+3) = TUNIT_KNT


      RETURN
      END
C
C
C
      SUBROUTINE SET_DTEN_DEF(GRAV)

C     Sets the default detention values. 

      IMPLICIT NONE
      REAL GRAV

      INCLUDE 'dtendef.cmn'
C*********************************************************************** 
      DEF_DTEN_LUI = 1
      DEF_DTEN_ORIF_TABID = '10001'
      DEF_DTEN_UNIT_AREA_VOL_TABID = '10000'
C     Set the internal table numbers to 0.  
C     They are set if detention is simulated.
      DEF_DTEN_ORIF_TAB_NUM = 0
      DEF_DTEN_UNIT_AREA_VOL_TAB_NUM = 0

      DEF_DTEN_WC = 0.9
      DEF_DTEN_WZ = 50.0
      DEF_DTEN_BZ = 4.0
      DEF_DTEN_ORFCD = 0.6
      IF(GRAV.GT.16.0) THEN
C       US customary units are being used.     
        DEF_DTEN_YD = 5.0
C       Unit-area flow is in ft^3/s/ft^2= ft/s
        DEF_DTEN_UAQ = 0.1/43560.
C       Drainage area is in square feet
        DEF_DTEN_AVDA = 40.0*43560.
      ELSE
C       Metric set of units being used.
        DEF_DTEN_YD = 1.524
C       Unit-area flow is in m^3/s/m^2= m/s
        DEF_DTEN_UAQ = 0.69972/1.E6
C       Drainage area is in square meters
        DEF_DTEN_AVDA = .161874*1.E6
      ENDIF

      RETURN
      END
C
C
C
      SUBROUTINE USE_DTEN_DEFAULT(ROW_PNT)

C     Place the default values for a detention reservoir in the
C     row given by ROW_PNT

      IMPLICIT NONE
      INTEGER ROW_PNT
      INCLUDE 'arsize.prm'
      INCLUDE 'dtendef.cmn'
      INCLUDE 'tam.cmn'
C***********************************************************************
      DTEN_YD(ROW_PNT) =  DEF_DTEN_YD 
      DTEN_BZ(ROW_PNT) =  DEF_DTEN_BZ 
      DTEN_WZ(ROW_PNT) =  DEF_DTEN_WZ 
      DTEN_WC(ROW_PNT) =  DEF_DTEN_WC 
      DTEN_UAQ(ROW_PNT) = DEF_DTEN_UAQ 
      DTEN_ORFCD(ROW_PNT) = DEF_DTEN_ORFCD
      DTEN_AVDA(ROW_PNT) = DEF_DTEN_AVDA
      DTEN_UADV_TAB(ROW_PNT)= DEF_DTEN_UNIT_AREA_VOL_TAB_NUM
      DTEN_ORF_TAB(ROW_PNT) = DEF_DTEN_ORIF_TAB_NUM
      RETURN
      END

C
C
C

      SUBROUTINE SET_TRIB_AREAS(STDOUT, CVAL, NGAGE, GEND, GSTART,
     I           MAX_NVAL, CON_FAC,
     M           NVAL, BACK_PNT,
     M     RVAL, LAST_NDTA_PNT, LAST_DTA_PNT, TRIBA, EFLAG)

C     Dechipher the user instructions and set the tributary
C     area values accordingly.

      IMPLICIT NONE
      INCLUDE 'arsize.prm'

      INTEGER BACK_PNT, STDOUT, MAX_NVAL, NVAL, LAST_NDTA_PNT, 
     A        LAST_DTA_PNT, EFLAG, NGAGE, GEND(0:NGAGE), 
     B        GSTART(0:NGAGE)

      REAL CON_FAC, RVAL(MAX_NVAL), TRIBA(MXR_TRIBA,MXN_LU_G)

      CHARACTER CVAL(NVAL)*256

      INCLUDE 'tam.cmn'

C     Local
      
      INTEGER LAST_NDTA_ROW, GAGE, GAGE_NLUSE, 
     A        I, TRIBA_ROW 

      REAL FRACTION, RMAX, RMIN
C     *****************************Formats******************************
50    FORMAT(/,' *ERR:329* Detention given with DTEN before tributary',
     A         ' area is given.')
52    FORMAT(/,' *ERR:330* Detention fraction=',F7.4,' is <= 0 or > 1.')

54    FORMAT(/,' *ERR:331* Maximum number of detention reservoirs=',I5,
     A ' is too small.')
56    FORMAT(/,' *BUG:XXX* LAST_DTA_PNT=',I5,' In SET_TRIB_AREAS when',
     A         ' it should be 0!')
58    FORMAT(/,' *ERR:332* Found ',I3,' values after DTEN.  ',
     A  'Expected ',I3,' for gage number ',I3,'.')
60    FORMAT(/,' *ERR:333* Inconsistent signs for areas subject to',
     A         ' detention.')
62    FORMAT(/,' *ERR:334* No detention area given on DTEN line.')
64    FORMAT(/,' *BUG:XXX* BACK_PNT=',I10,' does not = LAST_NDTA_PNT=',
     A         I10)
C***********************************************************************
C     Check for proper sequence of input.  We must have some trib area
C     in TRIBA before we can process a DTEN line of input.  
C     The LAST_NDTA_PNT should be > 0. 
      IF(LAST_NDTA_PNT.GT.0) THEN
C       Get the row of TRIBA that contains the last tributrary area
C       given by the user. 
        LAST_NDTA_ROW = TAM_ITAB(LAST_NDTA_PNT+3)
      ELSE
        WRITE(STDOUT,50)
        STOP 'Abnormal stop. Errors found.'
      ENDIF

C     Make sure pointers are not confused
      
      IF(LAST_DTA_PNT.NE.0) THEN
C       Bug: LAST_DTA_PNT should be 0!
        WRITE(STDOUT,56) LAST_DTA_PNT
        STOP 'Abnormal stop. Bug found.'
      ENDIF
C     Compute the number of land uses for this gage. 

      GAGE = TAM_ITAB(LAST_NDTA_PNT+4)
      GAGE_NLUSE = GEND(GAGE) - GSTART(GAGE) + 1
C      WRITE(STDOUT,*) ' SET_TRIB_AREA: GAGE=',GAGE,
C     A   ' GEND(GAGE)=',GEND(GAGE),' GSTART(GAGE)=',GSTART(GAGE)
C     Now dechipher the user input.  There are three valid patterns:
C     1. DTEN followed by a series of REAL values that are >= 0.
C     2. DTEN followed by a series of REAL values that are <= 0.
C     3. DTEN followed by: FRACTION= a positive real number <= 1.0
C     We already know that the first value is DTEN because that is
C     how we got to this routine.

      IF(CVAL(2).EQ.'FRACTION') THEN
C       Pattern 3 here.  The response value is in RVAL(3). 
        FRACTION = RVAL(3)
C        WRITE(STDOUT,*) ' SET_TRIB_AREAS: FRACTION=',FRACTION
        IF(FRACTION.LE.0.0.OR.FRACTION.GT.1.0) THEN
C         Invalid value given for fraction.
          WRITE(STDOUT,52) FRACTION
          EFLAG = 1
          FRACTION = 0.5
        ENDIF
C       If all the area is subject to detention then we need
C       not add a new tributary area unit. 
        IF(ABS(FRACTION-1.0).LE.1.0E-5) THEN
C         Treat FRACTION as 1.0.  Set it to exactly 1.0 so 
C         that this case will be distinguished from the case
C         with FRACTION < 1.0 below. 
          FRACTION = 1.0
C         The area is already in current tributary area description block. 
C         Switch the last trib area pointer. 
          LAST_DTA_PNT = LAST_NDTA_PNT
          LAST_NDTA_PNT = 0
C         Assign a location and set the parameters for this
C         detention reservoir.  Default values used here. 
          DTEN_KNT = DTEN_KNT + 1
          IF(DTEN_KNT.GT.MXN_DTEN) THEN
            WRITE(STDOUT,54) MXN_DTEN
            STOP 'Abnormal stop. Errors found.'
          ENDIF
          TAM_ITAB(LAST_DTA_PNT+5) = DTEN_KNT
          CALL USE_DTEN_DEFAULT(DTEN_KNT)            
        ELSE
C         Compute the value of RVAL to make this option
C         look like the DTEN line with negative areas. 
          NVAL = GAGE_NLUSE + 1
C          WRITE(STDOUT,*)' SET_TRIB_AREA: GAGE_NLUSE=',GAGE_NLUSE,
C     A       ' LAST_NDTA_ROW=',LAST_NDTA_ROW,
C     B       ' LAST_NDTA_PNT=',LAST_NDTA_PNT,
C     C       ' NVAL=',NVAL
          DO 98 I=2,NVAL
            RVAL(I) = -FRACTION*TRIBA(LAST_NDTA_ROW,I-1)
98        CONTINUE
        ENDIF
      ELSE
C       Force a value on FRACTION < 1.0 so that patterns 1 and 2
C       and the DTEN  FRACTION < 1.0 patterns are all done
C       the same way.
        FRACTION = 0.1
C       Also convert the user trib area units to the internal units. 
        DO 99 I=2,NVAL
          RVAL(I) = CON_FAC*RVAL(I)
99      CONTINUE
      ENDIF
      IF(FRACTION.LT.1.0) THEN
C       Patterns 1, 2, and part of 3.  Must create a new tributary 
C       area description block.  Copy the old block to 
C       the new and allocate space for the new tributary
C       areas.   The forward-linked series of pointers for
C       trib area control blocks must be maintained.  At this
C       point BACK_PNT should be the same as LAST_NDTA_PNT
C       because that is the last trib area we have seen.  
C       When we allocate a new trib-area control block its
C       address must be placed in the forwared pointer location
C       in the LAST_NDTA_PNT block, and BACK_PNT must be 
C       reset to the newly allocated address.
        IF(BACK_PNT.NE.LAST_NDTA_PNT) THEN
          WRITE(STDOUT,64) BACK_PNT, LAST_NDTA_PNT
          STOP 'Abnormal stop. Bug found.'
        ENDIF
C        WRITE(STDOUT,*) ' Calling COPY_TRIB_DESCRIPTION_BLOCK'
C        WRITE(STDOUT,*) ' LAST_NDTA_PNT=',LAST_NDTA_PNT
        CALL COPY_TRIB_DESCRIPTION_BLOCK(STDOUT,
     I                                   LAST_NDTA_PNT,
     O                                   LAST_DTA_PNT)
C        WRITE(STDOUT,*) ' Return from COPY_T...: TUNIT_KNT=',
C     A              TUNIT_KNT,' LAST_DTA_PNT=',LAST_DTA_PNT

C       Adjust the pointer chain for trib-area control blocks.
C       Point to the just allocated block for the area subject to 
C       detention.
        TAM_ITAB(LAST_NDTA_PNT+2) = LAST_DTA_PNT
C       Update the back pointer so that we can make the connection
C       the next trib area unit that will be input from the user. 
        BACK_PNT = LAST_DTA_PNT
C       Set the forward pointer in the just allocated trib area block
C       to the end of list signal in case this is the last block in
C       the chain of blocks. 
        TAM_ITAB(LAST_DTA_PNT+2) = 0

C       Now dechipher the user input.  Check to make sure that
C       the correct number of values have been given. 
        IF(NVAL-1.NE.GAGE_NLUSE) THEN
          WRITE(STDOUT, 58) NVAL-1, GAGE_NLUSE, GAGE
          STOP 'Abnormal stop. Errors found.'
        ENDIF
C       Check that the signs of the values are consistent.
        RMIN = 1.E30
        RMAX = -1.E30
        DO 100 I=2,NVAL
          IF(RVAL(I).GT.RMAX) RMAX = RVAL(I)
          IF(RVAL(I).LT.RMIN) RMIN = RVAL(I)
100     CONTINUE
        IF(RMIN.NE.0.0.AND.RMAX.NE.0.0) THEN
C         Both are non-zero. 
          IF(RMIN*RMAX.LT.0.0) THEN
C           Inconsistent signs
            WRITE(STDOUT,60) 
            STOP 'Abnormal stop. Errors found.'
          ENDIF
        ELSE
          IF(RMIN.EQ.0.0.AND.RMAX.EQ.0.0) THEN
C           No detention area given on DTEN line
            WRITE(STDOUT,62)
            STOP 'Abnormal stop. Errors found.'
          ENDIF
        ENDIF
C       Get the row in TRIBA allocated to the area
C       subject to detention.
        TRIBA_ROW = TAM_ITAB(LAST_DTA_PNT+3)
        IF(RMAX.GT.0.0) THEN
C         User has given the non-detention area in
C         the trib area input and the detention area
C         on the DTEN line. Store the values in the
C         TRIBA slot for the detention area. 
          DO 110 I=2,NVAL
            TRIBA(TRIBA_ROW,I-1) = RVAL(I)
110       CONTINUE
        ELSE
C         User has given the total trib area in the trib
C         area input and the negative of the detention area on the 
C         DTEN line.  Add the values in RVAL to the 
C         non-detention areas and then place the 
C         absolute values into the detention area.
          DO 120 I=2,NVAL
            TRIBA(LAST_NDTA_ROW,I-1) = TRIBA(LAST_NDTA_ROW,I-1)
     A                                   + RVAL(I)
            TRIBA(TRIBA_ROW,I-1) = ABS(RVAL(I))
120       CONTINUE
        ENDIF
C       Establish the detention parameters
        DTEN_KNT = DTEN_KNT + 1
        IF(DTEN_KNT.GT.MXN_DTEN) THEN
          WRITE(STDOUT,54) MXN_DTEN
          STOP 'Abnormal stop. Errors found.'
        ENDIF
        TAM_ITAB(LAST_DTA_PNT+5) = DTEN_KNT
        CALL USE_DTEN_DEFAULT(DTEN_KNT)            
      ENDIF
      RETURN
      END
C
C
C
      SUBROUTINE ALLOCATE_DLAY_SPACE(STDOUT, TA_BLOCK_PNT,
     O                               DLAY_PNT)

C     Allocate space for a delay specification for the trib
C     area block given by TA_BLOCK_PNT, and return the
C     pointer to the space, DLAY_PNT.

      IMPLICIT NONE
      INTEGER TA_BLOCK_PNT, DLAY_PNT, STDOUT

      INCLUDE 'arsize.prm'
      INCLUDE 'tam.cmn'
C     *********************************Formats**************************
62    FORMAT(/,' *ERR:335* Delay values set more than once for a',
     A        ' tributary area unit.')
64    FORMAT(/,' *ERR:336* Maximum number of delay reservoirs=',I5,
     A ' is too small.')
C***********************************************************************

C      WRITE(STDOUT,*) ' ALLOCATE_DLAY_SPACE: TA_BLOCK_PNT=',
C     A                TA_BLOCK_PNT

      IF(TA_BLOCK_PNT.GT.0) THEN
C       Check for duplicate specifications.
        IF(TAM_ITAB(TA_BLOCK_PNT+6).NE.0) THEN
          WRITE(STDOUT,62)
          STOP 'Abnormal stop. Errors found.'
        ENDIF
        DLAY_KNT = DLAY_KNT + 1
        IF(DLAY_KNT.GT.MXN_DLAY) THEN
          WRITE(STDOUT,64) MXN_DLAY
          STOP 'Abnormal stop. Errors found.'
        ENDIF
        DLAY_PNT = DLAY_KNT
        TAM_ITAB(TA_BLOCK_PNT+6) = DLAY_PNT
      ELSE
        DLAY_PNT = 0
      ENDIF
      RETURN
      END


C     ***********
C     *         *
C     * SET_DLAY_PARAMETERS
C     *         *
C     ***********

      SUBROUTINE SET_DLAY_PARAMETERS(STDOUT, WHICH, ITEM_KNT, CLEN, 
     I                       TERML, TERMCLS, ITEM_TYPE, CVAL, TERM,
     I                       IVAL, RVAL, DPVAL, LAST_NDTA_PNT, 
     I                       LAST_DTA_PNT,
     M                       EFLAG)

C     Set the parameter values for a delay option for
C     a tributary area unit

      IMPLICIT NONE
      INCLUDE 'arsize.prm'

      INTEGER STDOUT, EFLAG, ITEM_KNT, CLEN(ITEM_KNT), 
     A        IVAL(ITEM_KNT), TERML(ITEM_KNT), TERMCLS(ITEM_KNT),
     B        ITEM_TYPE(ITEM_KNT), LAST_NDTA_PNT, 
     C        LAST_DTA_PNT

      REAL  RVAL(ITEM_KNT)

      REAL*8 DPVAL(ITEM_KNT)

      CHARACTER CVAL(ITEM_KNT)*256, TERM(ITEM_KNT)*1, WHICH*4

      INCLUDE 'tam.cmn'

C     Local

C     + + + LOCAL PARAMETERS + + +
      INTEGER  INTVAL, REAVAL, CONTINUATION_VALUE,
     A         CHRVAL, DPRVAL, EXACT_TYPE, LOWER_TYPE,
     B         N_SYMBOL, N_EQ_NAME
      PARAMETER(N_SYMBOL=7, INTVAL=1, REAVAL=2,
     A          DPRVAL=3, CHRVAL=4, CONTINUATION_VALUE=5,
     B          EXACT_TYPE=0,LOWER_TYPE=1, N_EQ_NAME=2)

      INTEGER  I, IP, SELECTION,
     A         DTA_DLAY_PNT, NDTA_DLAY_PNT, NLR

      REAL K

      CHARACTER KEY*16

      INTEGER LENSTR

      EXTERNAL LENSTR

C     + + + SAVED VALUES + + +
      INTEGER SYMBOL_VALUE(N_SYMBOL), RESPONSE_TYPE(N_SYMBOL),
     A        CONVERT_RULE(N_SYMBOL)
      CHARACTER SYMBOL_TABLE(N_SYMBOL)*16, EQ_NAME(N_EQ_NAME)*16

      REAL EQ_ID(N_EQ_NAME)

      SAVE SYMBOL_VALUE, SYMBOL_TABLE, RESPONSE_TYPE, CONVERT_RULE,
     A     EQ_ID


      DATA  SYMBOL_TABLE
     A      /'NLR     ','K       ','KEQ     ','DLAY    ',
     B       'DELAY   ','DLAY_DTA','DLAY_NDTA'/

      DATA SYMBOL_VALUE
     A      /        1,         2,         3,         4,
     B               4,         4,         4/

      DATA RESPONSE_TYPE
     A     /INTVAL, REAVAL, CHRVAL, 4*0/
      DATA CONVERT_RULE
     A     /EXACT_TYPE, LOWER_TYPE, EXACT_TYPE, 4*0/

      DATA EQ_NAME/'PURDUE','Purdue'/
      DATA EQ_ID/ -1.0,         -1.0/
C     *****************************FORMATS******************************
 52   FORMAT(/,' *BUG:XXX* Invalid index=',I5,' for name=',A,' in',
     A       ' subroutine SET_DLAY_PARAMETERS.')
54    FORMAT(/,' *ERR:337* Name=',A8,' is unknown in a delay',
     A   ' description.')
56    FORMAT(/,' Unable to continue due to previous errors.')
60    FORMAT(/,' Processing:',A)
62    FORMAT(/,' *WRN:54* Number of linear reservoirs=',I5,' not yet',
     A       ' supported.  NLR=1 assumed.')
64    FORMAT(/,' ERR:338* Delay-time constant=',F7.4,' <= 0.0 invalid.')
66    FORMAT(/,' *ERR:339* Name=',A16,' is unknown as a lag',
     A   '-equation name.')
68    FORMAT(/,' Processing stopped.  Errors encountered.')
C***********************************************************************
      CALL CHK_AND_CONVERT_RESPONSE(STDOUT,
     I       N_SYMBOL, SYMBOL_TABLE, RESPONSE_TYPE,
     I       CONVERT_RULE, ITEM_KNT, ITEM_TYPE, CVAL, CLEN,
     M       EFLAG,
     O       IVAL, RVAL, DPVAL)
      IF(EFLAG.NE.0) THEN
        WRITE(STDOUT,68)
        STOP 'Abnormal stop. Errors found.'
      ENDIF

C     Allocate space for the delay values.  If the 
C     trib area unit does not exist the delay pointer is 
C     returned as 0.
      IF(WHICH.EQ.'BOTH') THEN
        CALL ALLOCATE_DLAY_SPACE(STDOUT, LAST_NDTA_PNT,
     O                           NDTA_DLAY_PNT)
        CALL ALLOCATE_DLAY_SPACE(STDOUT, LAST_DTA_PNT,
     O                           DTA_DLAY_PNT)
      ELSEIF(WHICH.EQ.'DTA') THEN
        CALL ALLOCATE_DLAY_SPACE(STDOUT, LAST_DTA_PNT,
     O                           DTA_DLAY_PNT)
      ELSE
        CALL ALLOCATE_DLAY_SPACE(STDOUT, LAST_NDTA_PNT,
     O                           NDTA_DLAY_PNT)
      ENDIF
      I = 1
110   CONTINUE          
C       Find the value for the next item from the 
C       symbol table. 
        KEY = CVAL(I)(1:CLEN(I))
C        WRITE(STDOUT,*) ' SET_DELAY_PARM...: I=',I,
C     A      ' KEY=',KEY
        CALL LSTAB
     I            (KEY, SYMBOL_TABLE, N_SYMBOL,
     O             IP)
        IF(IP.EQ.0) THEN
C         error-symbol not found
          WRITE(STDOUT,54) KEY
          EFLAG = 1

        ELSE
          SELECTION = SYMBOL_VALUE(IP)            
        ENDIF

        GOTO(1, 2, 3, 4, 4),SELECTION

          WRITE(STDOUT,52) I, KEY
          STOP 'Abnormal stop. Errors found.'
 
 1      CONTINUE
C         Number of linear reserviors.  Currently limited  to 1.
          I = I + 1
          NLR = IVAL(I)
          IF(NLR.NE.1) THEN
            WRITE(STDOUT,62) NLR
            NLR = 1
          ENDIF
          IF(WHICH.EQ.'BOTH') THEN
            DLAY_NLR(NDTA_DLAY_PNT) = NLR
            DLAY_NLR(DTA_DLAY_PNT) = NLR
          ELSEIF(WHICH.EQ.'DTA') THEN
            DLAY_NLR(DTA_DLAY_PNT) = NLR
          ELSE
            DLAY_NLR(NDTA_DLAY_PNT) = NLR
          ENDIF
          GOTO 149
 2      CONTINUE
C         Explict storage constant value.  Given by the user in 
C         hours. Convert to seconds, the needed internal unit.  
          I = I + 1
          K = RVAL(I)
          IF(K.LE.0.0) THEN
            WRITE(STDOUT,64) K
            STOP 'Abnormal stop. Errors found.'
          ENDIF
          K = K*3600.
C         We set the number of reservoirs to 1 also.  Only value
C         supported at this time.
          IF(WHICH.EQ.'BOTH') THEN
            DLAY_K(NDTA_DLAY_PNT) = K
            DLAY_K(DTA_DLAY_PNT) = K
            DLAY_NLR(NDTA_DLAY_PNT) = 1
            DLAY_NLR(DTA_DLAY_PNT) = 1
          ELSEIF(WHICH.EQ.'DTA') THEN
            DLAY_NLR(DTA_DLAY_PNT) = 1
            DLAY_K(DTA_DLAY_PNT) = K
          ELSE
            DLAY_K(NDTA_DLAY_PNT) = K
            DLAY_NLR(NDTA_DLAY_PNT) = 1
          ENDIF
          GOTO 149
 3      CONTINUE
C         Equation request here.  We cannot compute the 
C         the values now because all the tables for the
C         the computation may not be available.  Thus 
C         give each equation a negative number as an 
C         id and store in the K slot.    We then compute
C         equation values later.
          I = I + 1
          KEY = CVAL(I)
          CALL LSTAB
     I              (KEY, EQ_NAME, N_EQ_NAME,
     O               IP)
          IF(IP.EQ.0) THEN
C           error-symbol not found
            WRITE(STDOUT,66) KEY
            EFLAG = 1
          ELSE
            IF(WHICH.EQ.'BOTH') THEN
              DLAY_K(NDTA_DLAY_PNT) = EQ_ID(IP)
              DLAY_K(DTA_DLAY_PNT) = EQ_ID(IP)
            ELSEIF(WHICH.EQ.'DTA') THEN
              DLAY_K(DTA_DLAY_PNT) = EQ_ID(IP)
            ELSE
              DLAY_K(NDTA_DLAY_PNT) = EQ_ID(IP)
            ENDIF
          ENDIF

          GOTO 149

 4      CONTINUE
C         Catch the line name and its aliases.  They are ignored
C         but they are present.
          GOTO 149

149     CONTINUE
          I = I + 1
          IF(I.GT.ITEM_KNT) RETURN
          GOTO 110

      END

C
C
C
      SUBROUTINE RESET_DETENTION_VALUES(STDOUT, WHICH, GRAV, ITEM_KNT, 
     I                       CLEN, TERML, TERMCLS, ITEM_TYPE, CVAL, 
     I                       TERM, IVAL, RVAL, DPVAL, DTA_PNT,
     M                       EFLAG)

C     Process the requests on a DEF line.  Resets one or more
C     of the default values for detention.

      IMPLICIT NONE
      INTEGER DTA_PNT, STDOUT, EFLAG, ITEM_KNT, CLEN(ITEM_KNT), 
     A        IVAL(ITEM_KNT), TERML(ITEM_KNT), TERMCLS(ITEM_KNT),
     B        ITEM_TYPE(ITEM_KNT) 

      REAL  GRAV, RVAL(ITEM_KNT)

      REAL*8 DPVAL(ITEM_KNT)

      CHARACTER CVAL(ITEM_KNT)*256, TERM(ITEM_KNT)*1, WHICH*4

      INCLUDE 'arsize.prm'
      INCLUDE 'dtendef.cmn'
      INCLUDE 'tam.cmn'
      
C     Local

C     + + + LOCAL PARAMETERS + + +
      INTEGER  INTVAL, REAVAL, CONTINUATION_VALUE,
     A         CHRVAL, DPRVAL, EXACT_TYPE, LOWER_TYPE,
     B         N_SYMBOL
      PARAMETER(N_SYMBOL=13, INTVAL=1, REAVAL=2,
     A          DPRVAL=3, CHRVAL=4, CONTINUATION_VALUE=5,
     B          EXACT_TYPE=0,LOWER_TYPE=1)

      INTEGER  I, IP, SELECTION, DTEN_PNT

      CHARACTER KEY*16

C     External names
      INTEGER LENSTR

      EXTERNAL LENSTR, GET_INTERNAL_TAB_NUMBER

C     + + + SAVED VALUES + + +
      INTEGER SYMBOL_VALUE(N_SYMBOL), RESPONSE_TYPE(N_SYMBOL),
     A        CONVERT_RULE(N_SYMBOL)
      CHARACTER SYMBOL_TABLE(N_SYMBOL)*16

      SAVE SYMBOL_VALUE, SYMBOL_TABLE


      DATA  SYMBOL_TABLE
     A      /'DEF     ','DEFAULT ','UAQ     ','YD      ',
     B       'AVDA    ','OFWC    ','BSS     ','WS      ',
     C       'UADV_TAB  ','ORIFICE_TAB', 'LUI     ','ORIFICE_CD',
     D       'PARM     '/

      DATA SYMBOL_VALUE
     A      /        1,         1,         2,         3,
     B               4,         5,         6,         7,
     C               8,         9,        10,        11,  1/

      DATA RESPONSE_TYPE
     A     /2*0, 6*REAVAL, 2*CHRVAL, INTVAL, REAVAL, 0/
      DATA CONVERT_RULE
     A     /2*0, 6*LOWER_TYPE,2*LOWER_TYPE,EXACT_TYPE, EXACT_TYPE, 0/
C     *****************************FORMATS******************************
 52   FORMAT(/,' *BUG:XXX* Invalid index=',I5,' for name=',A,' in',
     A       ' subroutine RESET_DEFAULT_PARAMETERS.')
54    FORMAT(/,' *ERR:340* Name=',A8,' is unknown as a default',
     A   ' value.')
56    FORMAT(/,' Unable to continue due to previous errors.')
60    FORMAT(/,' Processing:',A)
64    FORMAT(/,' *ERR:341* Average drainage area=',F10.1,' invalid.')
66    FORMAT(/,' *ERR:342* Design depth =',F10.1,' invalid.')
68    FORMAT(/,' *ERR:343* Unit-area flow =',F10.1,' invalid. Value',
     A      ' must be',/,11X,'>= 0.05 and <= 0.30')
69    FORMAT(/,' *ERR:344* Unit-area flow =',F10.1,' invalid. Value',
     A      ' must be',/,11X,'>= 0.35 and <= 2.099')
70    FORMAT(/,' *ERR:345* Overflow-weir coef=',F10.2,' invalid. Value',
     A      ' must be > 0.0 and < 1.10')
72    FORMAT(/,' *ERR:346* Basin side slope =',F10.1,' invalid.')
74    FORMAT(/,' *ERR:347* Weir slope =',F10.1,' invalid.')
80    FORMAT(/,' *ERR:350* Impervious area land use index=',I3,
     A           ' invalid.')
82    FORMAT(/,' *ERR:351* Orifice discharge coef=',F7.3,' invalid.',
     A    ' Value must be > 0.0 and < 1.0')
84    FORMAT(/,' Processing stopped.  Errors encountered.')
C***********************************************************************
      CALL CHK_AND_CONVERT_RESPONSE(STDOUT,
     I       N_SYMBOL, SYMBOL_TABLE, RESPONSE_TYPE,
     I       CONVERT_RULE, ITEM_KNT, ITEM_TYPE, CVAL, CLEN,
     M       EFLAG,
     O       IVAL, RVAL, DPVAL)
      IF(EFLAG.NE.0) THEN
        WRITE(STDOUT,84)
        STOP 'Abnormal stop. Errors found.'
      ENDIF
      IF(WHICH.EQ.'PARM') THEN
C       Get the address for the detention parameters
        DTEN_PNT = TAM_ITAB(DTA_PNT+5)
      ELSE
        DTEN_PNT = 0
      ENDIF
      I = 1
110   CONTINUE          
C       Find the value for the next item from the 
C       symbol table. 
        KEY = CVAL(I)(1:CLEN(I))
C        WRITE(STDOUT,*) ' RESET_DEFAULT...: I=',I,
C     A      ' KEY=',KEY
        CALL LSTAB
     I            (KEY, SYMBOL_TABLE, N_SYMBOL,
     O             IP)
        IF(IP.EQ.0) THEN
C         error-symbol not found
          WRITE(STDOUT,54) KEY
          EFLAG = 1

        ELSE
          SELECTION = SYMBOL_VALUE(IP)            
        ENDIF

        GOTO(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11),SELECTION

          WRITE(STDOUT,52) I, KEY
          STOP 'Abnormal stop. Errors found.'
 
 1      CONTINUE
C         Catch the line name and its aliases.  They are ignored
C         but they are present.
          GOTO 149

 2      CONTINUE
C       Unit area flow.
          I = I + 1
          IF(GRAV.GT.15.0) THEN
            IF(RVAL(I).LT.0.05.OR.RVAL(I).GT.0.30) THEN
              WRITE(STDOUT,68) RVAL(I)
              STOP 'Abnormal stop. Errors found.'
            ENDIF
            IF(DTEN_PNT.EQ.0) THEN
              DEF_DTEN_UAQ = RVAL(I)/43560.
            ELSE
              DTEN_UAQ(DTEN_PNT) = RVAL(I)/43560.
            ENDIF
          ELSE
            IF(RVAL(I).LT.0.35.OR.RVAL(I).GT.2.099) THEN
              WRITE(STDOUT,69) RVAL(I)
              STOP 'Abnormal stop. Errors found.'
            ENDIF
            IF(DTEN_PNT.EQ.0) THEN
              DEF_DTEN_UAQ = RVAL(I)/1.E6
            ELSE
              DTEN_UAQ(DTEN_PNT) = RVAL(I)/1.E6
            ENDIF
          ENDIF
          GOTO 149
 3      CONTINUE
C         Design depth
          I = I + 1
          IF(RVAL(I).LE.0.0) THEN
            WRITE(STDOUT,66) RVAL(I)
            STOP 'Abnormal stop. Errors found.'
          ENDIF
          IF(DTEN_PNT.EQ.0) THEN
            DEF_DTEN_YD = RVAL(I)
          ELSE
            DTEN_YD(DTEN_PNT) = RVAL(I)
          ENDIF
          GOTO 149

 4      CONTINUE
C         Average drainage area for a detention basin
          I = I + 1
          IF(RVAL(I).LE.0.0) THEN
            WRITE(STDOUT,64) RVAL(I)
            STOP 'Abnormal stop. Errors found.'
          ENDIF
          IF(DTEN_PNT.EQ.0) THEN
            IF(GRAV.GT.15.) THEN
              DEF_DTEN_AVDA = RVAL(I)*43560.
            ELSE
              DEF_DTEN_AVDA = RVAL(I)*1.E6
            ENDIF
          ELSE
            IF(GRAV.GT.15.) THEN
              DTEN_AVDA(DTEN_PNT) = RVAL(I)*43560.
            ELSE
              DTEN_AVDA(DTEN_PNT) = RVAL(I)*1.E6
            ENDIF
          ENDIF
          GOTO 149
 5      CONTINUE
C         Overflow-weir coefficient
          I = I + 1
          IF(RVAL(I).LE.0.0.OR.RVAL(I).GT.1.0) THEN
            WRITE(STDOUT,70) RVAL(I)
            STOP 'Abnormal stop. Errors found.'
          ENDIF
          IF(DTEN_PNT.EQ.0) THEN
            DEF_DTEN_WC = RVAL(I)
          ELSE
            DTEN_WC(DTEN_PNT) = RVAL(I)
          ENDIF
          GOTO 149
 6      CONTINUE
C         Basin side slope
          I = I + 1
          IF(RVAL(I).LT.0.0) THEN
            WRITE(STDOUT,72) RVAL(I)
            STOP 'Abnormal stop. Errors found.'
          ENDIF
          IF(DTEN_PNT.EQ.0) THEN
            DEF_DTEN_BZ = RVAL(I)
          ELSE
            DTEN_BZ(DTEN_PNT) = RVAL(I)
          ENDIF
          GOTO 149
 7      CONTINUE
C         Weir slope  
          I = I + 1
          IF(RVAL(I).LE.0.0) THEN
            WRITE(STDOUT,74) RVAL(I)
            STOP 'Abnormal stop. Errors found.'
          ENDIF
          IF(DTEN_PNT.EQ.0) THEN
            DEF_DTEN_WZ = RVAL(I)
          ELSE
            DTEN_WZ(DTEN_PNT) = RVAL(I)
          ENDIF
          GOTO 149
 8      CONTINUE
C         Unit-area detention volume table number
          I = I + 1
          KEY = CVAL(I)(1:16)
          CALL GET_INTERNAL_TAB_NUMBER
     I                                (STDOUT, KEY,
     M                                 EFLAG,
     O                                 IVAL(I))

          IF(DTEN_PNT.EQ.0) THEN
            DEF_DTEN_UNIT_AREA_VOL_TAB_NUM = IVAL(I)
          ELSE
            DTEN_UADV_TAB(DTEN_PNT) = IVAL(I)
          ENDIF

          GOTO 149
 9      CONTINUE
C         Orifice table
          I = I + 1
          KEY = CVAL(I)(1:16)
          CALL GET_INTERNAL_TAB_NUMBER
     I                                (STDOUT, KEY,
     M                                 EFLAG,
     O                                 IVAL(I))
          IF(DTEN_PNT.EQ.0) THEN
            DEF_DTEN_ORIF_TAB_NUM  = IVAL(I)
          ELSE
            DTEN_ORF_TAB(DTEN_PNT)  = IVAL(I)
          ENDIF
          GOTO 149
10      CONTINUE
C         Index for the impervious area in the land use sequence.
          I = I + 1
          IF(IVAL(I).LE.0.OR.IVAL(I).GT.MXN_LU_G) THEN
            WRITE(STDOUT,80) IVAL(I)
            STOP 'Abnormal stop. Errors found.'
          ENDIF
C         Land use index for impervious area is always global.
          IF(DTEN_PNT.EQ.0) THEN
            DEF_DTEN_LUI = IVAL(I)
          ELSE
            DEF_DTEN_LUI = IVAL(I)
          ENDIF
          
          GOTO 149

11      CONTINUE
C         Orifice discharge coeff
          I = I + 1
          IF(RVAL(I).LE.0.9.OR.RVAL(I).GT.1.0) THEN
            WRITE(STDOUT,82) RVAL(I)
            STOP 'Abnormal stop. Errors found.'
          ENDIF
          IF(DTEN_PNT.EQ.0) THEN
            DEF_DTEN_ORFCD = RVAL(I)
          ELSE
            DTEN_ORFCD(DTEN_PNT) = RVAL(I)
          ENDIF

          GOTO 149

149     CONTINUE
          I = I + 1
          IF(I.GT.ITEM_KNT) RETURN
          GOTO 110

      END




C     ***********
C     *         *
C     * PROCESS_DETENTION_DELAY_OPTIONS
C     *         *
C     ***********

      SUBROUTINE PROCESS_DETENTION_DELAY_OPTIONS(STDOUT, GRAV, CON_FAC,
     I             LINE112,  NGAGE, GSTART, GEND,
     M             LAST_NDTA_PNT, LAST_DTA_PNT, 
     M             BACK_PNT, TRIBA, EFLAG   )

C     Dechipher the lines of input specifying the detention and
C     delay characteristics. 


C     Parameters

      IMPLICIT NONE
      INCLUDE 'arsize.prm'

      INTEGER BACK_PNT, EFLAG, STDOUT, LAST_NDTA_PNT, LAST_DTA_PNT, 
     A        NGAGE, GSTART(0:NGAGE), GEND(0:NGAGE)
     B        

      REAL CON_FAC, GRAV, TRIBA(MXR_TRIBA,MXN_LU_G)

      CHARACTER LINE112*112

      INCLUDE 'usintp.cmn'
      INCLUDE 'inusnb.cmn'
      INCLUDE 'tam.cmn'


C     Local
      

      INTEGER MAX_ITEM_KNT
      PARAMETER (MAX_ITEM_KNT=20)

      INTEGER I, ITEM_KNT, OPT, N
      INTEGER CLEN(MAX_ITEM_KNT), IVAL(MAX_ITEM_KNT), 
     A        ITEM_TYPE(MAX_ITEM_KNT), TERML(MAX_ITEM_KNT), 
     B        TERMCLS(MAX_ITEM_KNT)
      REAL RVAL(MAX_ITEM_KNT)
      REAL*8 DPVAL(MAX_ITEM_KNT)
      CHARACTER CVAL(MAX_ITEM_KNT)*256, TERM(MAX_ITEM_KNT)*1, LINE*113,
     A          LINE_ID*16

      INTEGER LENSTR

      EXTERNAL GETVAL, SET_TRIB_AREAS, LENSTR
C     *****************************Formats******************************
50    FORMAT(/,' *ERR:352* Option:',A16,' unknown for delay/detention.')
56    FORMAT(/,' Unable to continue due to previous errors.')

C***********************************************************************
      N = LENSTR(LINE112)
      WRITE(STDOUT,'(A)') LINE112(1:N)

      LINE = LINE112

C     Search for user given quote.
      I = INDEX(LINE,'''')
      IF(I.EQ.0) THEN
C       Put one in to end the line. 
        LINE(113:113) = ''''
      ENDIF
     
      OPT = 2
      CALL GETVAL(STDOUT, LINE, MAX_ITEM_KNT, OPT,
     O            ITEM_TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O            TERM, TERML, TERMCLS, ITEM_KNT)
C      WRITE(STDOUT,*) 
C     A ' Return from GETVAL in PROCESS_DETENTION_DELAY_OPTIONS:',
C     B ' ITEM_KNT=',ITEM_KNT
C      DO 9213 I=1,ITEM_KNT
C        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I)
C99    FORMAT(' ',A12,' ',I5,' ',I5,' ',A1)
C9213  CONTINUE

      IF(EFLAG.NE.0) THEN
        WRITE(STDOUT,56)
        STOP 'Abnormal stop. Errors found.'
      ELSE
C       The first item on the line should be the line identifier.
C       Branch on this identifier. 

        LINE_ID = CVAL(1)
        IF(LINE_ID.EQ.'DTEN') THEN
          CALL SET_TRIB_AREAS(STDOUT, CVAL, NGAGE, GEND, GSTART,
     I                      MAX_ITEM_KNT, CON_FAC,
     M                      ITEM_KNT, BACK_PNT,
     M                      RVAL, LAST_NDTA_PNT, LAST_DTA_PNT, 
     M                      TRIBA, EFLAG)

        ELSEIF(LINE_ID.EQ.'DLAY'.OR.LINE_ID.EQ.'DELAY') THEN
          CALL SET_DLAY_PARAMETERS(STDOUT,'BOTH', ITEM_KNT, CLEN, 
     I                       TERML, TERMCLS, ITEM_TYPE, CVAL, TERM,
     I                       IVAL, RVAL, DPVAL, LAST_NDTA_PNT, 
     I                       LAST_DTA_PNT,
     M                       EFLAG)
        ELSEIF(LINE_ID.EQ.'DLAY_NDTA') THEN
          CALL SET_DLAY_PARAMETERS(STDOUT,'NDTA', ITEM_KNT, CLEN, 
     I                       TERML, TERMCLS, ITEM_TYPE, CVAL, TERM,
     I                       IVAL, RVAL, DPVAL, LAST_NDTA_PNT, 
     I                       LAST_DTA_PNT,
     M                       EFLAG)

        ELSEIF(LINE_ID.EQ.'DLAY_DTA') THEN
          CALL SET_DLAY_PARAMETERS(STDOUT,'DTA ', ITEM_KNT, CLEN, 
     I                       TERML, TERMCLS, ITEM_TYPE, CVAL, TERM,
     I                       IVAL, RVAL, DPVAL, LAST_NDTA_PNT, 
     I                       LAST_DTA_PNT,
     M                       EFLAG)

        ELSEIF(LINE_ID.EQ.'DEF') THEN
          CALL RESET_DETENTION_VALUES(STDOUT, 'DEF ', GRAV, ITEM_KNT, 
     I                       CLEN, TERML, TERMCLS, ITEM_TYPE, CVAL, 
     I                       TERM, IVAL, RVAL, DPVAL, LAST_DTA_PNT,
     M                       EFLAG)
        ELSEIF(LINE_ID.EQ.'PARM') THEN
          CALL RESET_DETENTION_VALUES(STDOUT, 'PARM', GRAV, ITEM_KNT, 
     I                       CLEN, TERML, TERMCLS, ITEM_TYPE, CVAL, 
     I                       TERM, IVAL, RVAL, DPVAL, LAST_DTA_PNT,
     M                       EFLAG)

        ELSE
          WRITE(STDOUT,50) LINE_ID
          STOP 'Abnormal stop. Errors found.'
        ENDIF
      ENDIF        

      RETURN
      END
C
C
C
      SUBROUTINE COMPUTE_DTEN_POND_VOLUME(STDOUT, DTEN_PNT, UADV_TAB,
     I                                    UNIT_PNT, GRAV,
     O                     POND_VOLUME, TOTAL_AREA, QFAC, IMP_FRACTION)

C     Compute the volume for a detention pond.

      IMPLICIT NONE
      INTEGER STDOUT, DTEN_PNT, UNIT_PNT, UADV_TAB

      REAL GRAV, POND_VOLUME, TOTAL_AREA, QFAC, IMP_FRACTION

      INCLUDE 'arsize.prm'
      INCLUDE 'tam.cmn'
      INCLUDE 'tsfcom.cmn'

C     Local


      REAL  UNIT_AREA_VOLUME, DFDR, DFDC, UAQ_LOOK

C***********************************************************************
C     Compute the total area and the impervious area fraction. 
      CALL COMPUTE_AREA_AND_IMP_FRACTION(STDOUT, UNIT_PNT,
     O                      TOTAL_AREA, IMP_FRACTION)
      
      IF(GRAV.GT.15.0) THEN
        UAQ_LOOK = DTEN_UAQ(DTEN_PNT)*43560.
      ELSE
        UAQ_LOOK = DTEN_UAQ(DTEN_PNT)*1.E6
      ENDIF
      CALL TDLK10
     I          (STDOUT, UADV_TAB, 10, IMP_FRACTION, UAQ_LOOK,
     O              UNIT_AREA_VOLUME, DFDR, DFDC)

      POND_VOLUME = UNIT_AREA_VOLUME*DTEN_AVDA(DTEN_PNT)

C     Compute how many average drainage areas fit into the total area
      QFAC = TOTAL_AREA/DTEN_AVDA(DTEN_PNT)
      RETURN
      END
C
C
C
      SUBROUTINE FIND_VOLUME_COEFFICIENTS(STDOUT, DTEN_PNT, GRAV,
     I                           POND_VOLUME,
     M                           EFLAG,
     O                           C1, C2, C3, DESIGN_A)      

C     Find the polynomial coefficients defining the pond 
C     volume as a function of depth in the pond.  We assume 
C     that there is always a conservation pool, that is, that
C     the area at zero depth is greater than zero. 

      IMPLICIT NONE
      INTEGER STDOUT, DTEN_PNT, EFLAG

      REAL C1, C2, C3, GRAV, POND_VOLUME, DESIGN_A

      INCLUDE 'arsize.prm'
      INCLUDE 'tam.cmn'

C     Local

      REAL R0, PI, BZ, YD, MIN_VOLUME


      DATA PI/3.1415927/
C     *******************************FORMATS****************************
50    FORMAT(/,' *ERR:353* Pond volume=',1PE10.3,' acre-feet <= ',
     A         'minimum',/,11X,' possible pond volume of:',
     B          1PE10.3,' acre-feet.')
52    FORMAT(/,' *ERR:354* Pond volume=',1PE10.3,' meter^3 <= ',
     A         'minimum',/,11X,' possible pond volume of:',
     B          1PE10.3,' meter^3.')
C***********************************************************************
C     Extract items from the detention storage data structure
      YD = DTEN_YD(DTEN_PNT)
      BZ = DTEN_BZ(DTEN_PNT)  

C     Check that the base area is > 0. The volume is given by 
C     V(Y) = PI*(R0^2*Y + R0*BZ*Y^2 + BZ^2*Y^3/3) where R0 is
C     the radius of the assumed circular base.  Thus if we
C     set R0 to zero and Y to YD and find that the computed 
C     volume is larger than POND_VOLUME, then we KNOW that
C     the area of the base cannot be > than zero and the
C     given values, YD, BZ, and POND_VOLUME and the assumption
C     of the pond being a frustrum of a cone are inconsistent. 

      MIN_VOLUME = PI*BZ**2*YD**3/3.0
      IF(MIN_VOLUME.GE.POND_VOLUME) THEN
C       Inconsistent specification.
        IF(GRAV.GT.15.0) THEN
          WRITE(STDOUT,50) POND_VOLUME/43560., MIN_VOLUME/43560.
        ELSE
          WRITE(STDOUT,52) POND_VOLUME, MIN_VOLUME
        ENDIF
        EFLAG = 1
      ELSE
C       Compute the coefficients. The value of R0 is given as one root
C       of the quadratic equation when the volume, depth, and 
C       basin side slope are given. 

        R0 = -0.5*BZ*YD + SQRT(POND_VOLUME/(PI*YD) - (BZ*YD)**2/12)

        
C       Compute the coefficients of the polynomial.

        C1 = PI*R0**2
        C2 = PI*R0*BZ
        C3 = PI*BZ**2/3.

        DESIGN_A = C1 + YD*(2.*C2 + YD*3.*C3)
      ENDIF
      RETURN
      END
C
C
C
      SUBROUTINE FIND_ORIFICE_DIAMETER(STDOUT, DTEN_PNT, ORF_TAB, GRAV,
     I                     TRIB_AREA, 
     O                     ORIFICE_D, DESIGN_Q, ORFCON)

C     Find the orifice diameter that will pass the design flow
C     at the design depth.  

      IMPLICIT NONE
      INTEGER STDOUT, DTEN_PNT, ORF_TAB

      REAL GRAV, TRIB_AREA, ORFCON, ORIFICE_D, DESIGN_Q

      INCLUDE 'arsize.prm'
      INCLUDE 'tam.cmn'

C     Local

      INTEGER KNT, NTAB

      REAL UAQ, QD, ORFCD, D, PI, YD, F, DF, ORF, DORF, CON,
     A     HOVERD, ROOTD, DELTA_D, TD

      DATA PI/3.1415927/

C     ****************************FORMATS*******************************
50    FORMAT(/,' *ERR:110* Orifice diameter not found after 20 tries.')
C***********************************************************************
C     Get the unit-area flow permitted.

      UAQ = DTEN_UAQ(DTEN_PNT)
      QD = UAQ*DTEN_AVDA(DTEN_PNT)
      DESIGN_Q = QD
C     Get the orifice discharge coefficient and design depth
      ORFCD = DTEN_ORFCD(DTEN_PNT)
      YD = DTEN_YD(DTEN_PNT)

C     Estimate the diameter of the orifice.  This estimate will be too
C     large since the base of the orifice is at depth zero and we 
C     assume for estimation that the center of the orifice is at 
C     depth zero. 

      D = SQRT(4.*QD/(PI*ORFCD*SQRT(2.*GRAV*YD)))


C     Now use Newton's method to find the final value of orifice
C     diameter. Compute the constant factor in the orfice flow
C     computation. 

      CON = ORFCD*SQRT(2.*GRAV)
      KNT = 0
100   CONTINUE

C       Compute flow through the orifice.  Get orifice flow 
C       function values.

        HOVERD = YD/D

        CALL LKTAB
     I            (ORF_TAB, HOVERD, 1,
     O             ORF, NTAB, DORF)

C       Compute the residual function and its derivative with respect
C       to D.  We compute relative to QD to make convergence testing
C       easier.  Note that the value: 2.5*ORF - HOVERD*DORF proves
C       to be always  > 0 if D > 0.  This means that DF is < 0.

        ROOTD = SQRT(D)
        F = 1.0 - CON*ROOTD*D**2*ORF/QD


        IF(ABS(F).GT.1.E-4) THEN
          DF = -CON*ROOTD*D*(2.5*ORF - HOVERD*DORF)/QD
        
C         Compute a correction to D

          DELTA_D = -F/DF
          IF(ABS(DELTA_D/D).GT.1.E-4) THEN
C           Compute the next value of D
            TD = D + DELTA_D
            IF(TD.LE.0.0) THEN
              TD = 0.5*D
            ENDIF
            D = TD
            KNT = KNT + 1
            IF(KNT.GT.20) THEN
              WRITE(STDOUT,50) 
              STOP 'Abnormal stop. Errors found.'
            ENDIF
            GOTO 100
          ENDIF
        ENDIF

      ORIFICE_D = D
      ORFCON = ORFCD*SQRT(D*2.*GRAV)*D**2
      RETURN
      END

C
C
C
      SUBROUTINE FIND_CHEBYSHEV_POINTS(N, A, B, 
     O                                Y)

C     For the interval [A, B] compute the N expanded Chebyshev
C     points. 

      IMPLICIT NONE
      INTEGER N

      REAL A, B, Y(N)

C     Local

      INTEGER J
      REAL PI, CONA, CONB, FN, APLUSB

      DATA PI/3.1415927/
C***********************************************************************
C     Avoid roundoff at the end points. 
      IF(N.LT.2) THEN
        STOP ' Abnormal stop. Bug found by FIND_CHEBYSHEV_POINTS'
      ELSEIF(N.EQ.2) THEN
        Y(1) = A
        Y(2) = B
      ELSE
        Y(1) = A
        Y(N) = B
        FN = REAL(N)
        CONA = PI/(FN + FN)
        APLUSB = A + B
        CONB = (B - A)/COS(CONA)
        DO 100 J=2,N-1
          Y(J) = 0.5*(APLUSB - CONB*COS(REAL(2*J-1)*CONA))
100     CONTINUE
      ENDIF
      RETURN
      END      
C
C
C
      SUBROUTINE FIND_POND_ROUTING_TABLE(STDOUT, DTEN_PNT, ORF_TAB,
     I                          GRAV, ORIFICE_D, ORFCON, C1, C2, C3,
     M                          FTP, EFLAG)

C     Compute the routing table for the detention basin.  The table
C     is of type 4 with an argument of basin volume, and with function 
C     values of flow and the derivative of flow wrt volume. 

      IMPLICIT NONE
      INTEGER STDOUT, DTEN_PNT, FTP, ORF_TAB, EFLAG

      REAL ORIFICE_D, ORFCON, C1, C2, C3, GRAV

      INCLUDE 'arsize.prm'
      INCLUDE 'tam.cmn'

C     Local

      INTEGER J, M, N1, N2, N3, NTAB, TAB_NUMBER, TAB_ADDRESS

      REAL A, H, ORF, DORF, HOVERD, YA, YD, V, WC, WZ, WEIRCON,
     A     QORF, DQORF, QSPILL, DQSPILL, Y(55), YT(50), Q(50), DQ(50),
     B     ARG(50)


C     Called program units

      INTEGER NEXTN

      EXTERNAL NEXTN
C     *******************************Formats****************************
50    FORMAT(1X,1PE14.6,1PE14.6,1PE14.6,1PE14.6)
52    FORMAT(1X,'    Pond Depth   Pond Volume  Pond Outflow    DQ/DV')
C***********************************************************************
C     Get values from data structure
      YD = DTEN_YD(DTEN_PNT)
      WC = DTEN_WC(DTEN_PNT)
      WZ = DTEN_WZ(DTEN_PNT)

C     Compute the weir coefficient. See page 32 of Bos.  We ignore velocity
C     of approach since this is an overflow from a basin of some depth.
C     Overflow depths are proabably small, maybe less than 10 per cent of
C     the design depth. 

      WEIRCON = 0.64*WC*WZ*SQRT(.4*GRAV)

C     The table will be constructed from a series of depth values designed
C     to fairly represent the relationship between storage in the pond and
C     outflow from the pond.  We will use three different applications
C     of the expanded Chebyshev point set.  The first set will be applied
C     in the depth range 0 to ORIFICE_D, the second set will be 
C     applied from ORIFICE_D to YD, the final set will apply from YD to 
C     1.5*YD.

      
C     We will place 11 points across [0,ORIFICE_D]
      N1 = 11
      CALL FIND_CHEBYSHEV_POINTS(N1, 0.0, ORIFICE_D, 
     O                                Y)

C     Use 21 points across [ORIFICE_D, YD].  The first point will
C     be the same as the last point in the previous interval.
      N2= 21
      CALL FIND_CHEBYSHEV_POINTS(N2, ORIFICE_D, YD,
     O                                YT)
      DO 100 J=2,N2
        Y(J+N1-1) = YT(J)
100   CONTINUE

C     Flow over the spillway begins and increases rapidly.  Use 
C     extra points and then go only halfway into the interval. 
      N3 = 39
      CALL FIND_CHEBYSHEV_POINTS(N3, YD, 2.*YD,
     O                                YT)
      DO 110 J=2,N3/2+1
        Y(J+N2+N1-2) = YT(J)
110   CONTINUE
      M = N1+N2-1+N3/2
C      WRITE(STDOUT,*) ' CHECK POINT SET FOR ROUTING TABLE. M=',M
C      DO 130 J=1,M
C
C        WRITE(STDOUT,*) 'J=',J,' Y(J)=',Y(J)
C130   CONTINUE

c      WRITE(STDOUT,52) 
C     Now we can finally compute the table values. 
      DO 150 J=1,M
        YA = Y(J)
C       Get the volume at this depth
        V = YA*(C1 + YA*(C2 +C3*YA))
C       Get the surface area at this depth
        A = C1 + YA*(2.0*C2 + YA*3.0*C3) 
C       Compute the flow and its derivative with respect
C       to depth. We always have flow through the orifice.

        HOVERD = YA/ORIFICE_D
        CALL LKTAB
     I            (ORF_TAB, HOVERD, 1,
     O             ORF, NTAB, DORF)
        QORF = ORFCON*ORF
        DQORF = ORFCON*DORF/ORIFICE_D
        IF(YA.GT.YD) THEN
C         Compute flow over spillway.
          H = YA - YD
          QSPILL = WEIRCON*SQRT(H)*H**2
          DQSPILL = 2.5*WEIRCON*SQRT(H)*H
          
        ELSE
          QSPILL = 0.0
          DQSPILL = 0.0
        ENDIF

        Q(J) = QORF + QSPILL

C       Convert derivative wrt y to wrt volume.
        DQ(J) = (DQORF + DQSPILL)/A
          
        ARG(J) = V
c        WRITE(STDOUT,50) Y(J), ARG(J), Q(J), DQ(J)
150   CONTINUE

C     Get an available table number for the table.         
        
      TAB_NUMBER = NEXTN()
      CALL PUT1D
     I          (STDOUT, TAB_NUMBER, 4, M, ARG, Q, DQ,
     M           FTP,
     O           TAB_ADDRESS)

C     Store the routing table address.
      DTEN_ROUT_TAB(DTEN_PNT) = TAB_ADDRESS
      RETURN
      END      
C  
C
C
      SUBROUTINE COMPUTE_DETENTION_DESCRIPTION(STDOUT, GRAV,
     I                  FTPNT, NBRA, BRPT,
     M                  FTP, EFLAG)      

C     Compute the description for each detention pond.  In 
C     that process the validity of the input will be checked
C     and errors reported.

      IMPLICIT NONE
      INCLUDE 'arsize.prm'
      INTEGER STDOUT, EFLAG, FTP, NBRA
      INTEGER FTPNT(MFTNUM), BRPT(8,NBRA)
      
      REAL GRAV

      INCLUDE 'tam.cmn'

C     Called program units
      CHARACTER GETUSN*5, GET_TABID*16
      INTEGER GETTYP, GETTBN, GETUSB

      EXTERNAL GETTYP, GETTBN, GETUSB, GETUSN, GET_TABID,
     A         STRIP_L_BLANKS, GET_INTERNAL_TAB_NUMBER

C     Local

      INTEGER UNIT_PNT, DTEN_PNT, UADV_TAB, ORF_TAB, NODE_CONVERT,
     A        FNODE, LNODE, IBRA

      REAL C1, C2, C3, POND_VOLUME, TRIB_AREA, QFAC, DESIGN_Q,
     A     DESIGN_A, IMP_FRACTION, CONV_OUT, ORFCON, ORIFICE_D

      CHARACTER LENGTH_UNIT*6, VOLUME_UNIT*8, AREA_UNIT*8, FLOW_UNIT*8,
     A          KEY*16



C     *****************************FORMATS******************************
50    FORMAT(/,' *ERR:98* Orifice-flow table id= ',A,' is type=',
     A            I3,'.  Expected type 4.')

52    FORMAT(/,' Summary of Detention Basins',//,
     A '  Trib    Ups    Dsn      Imp.    Design    Design      Base',
     B '    Design    Design   Orifice Routing   Basin',/,
     C ' to ID   node   node  fraction     depth    volume      area',
     D '      area      flow  diameter table#    count',/,
     E  34X,A6,2X,A8,2X,A8,2X,A8,2X,A8,4X,A6,/,
     E ' ----- ------ ------ --------- --------- --------- ---------',
     F ' --------- --------- --------- ------- -------' )
54    FORMAT(I6,2I7,F10.3,F10.1,1PE10.3,1PE10.3,1PE10.3,0PF10.2,
     A       F10.3,I8,F8.2)
56    FORMAT(I6,2I7,F10.3,F10.2,1PE10.3,1PE10.3,1PE10.3,0PF10.3,
     A       F10.4,I8,F8.2)
58    FORMAT(1X,A5,14X,F10.3,F10.1,1PE10.3,1PE10.3,1PE10.3,0PF10.2,
     A       F10.3,I8,F8.2)
60    FORMAT(1X,A5,14X,F10.3,F10.1,1PE10.3,0PF10.3,1PE10.3,1PE10.3,
     A       F10.4,I8,F8.2)
62    FORMAT(/,'  Unit-area detention volume table is missing.',
     A         '  Make sure DETAIN.TAB is in the list of files ',
     B         'for function tables.')
64    FORMAT(/,' Orifice-flow table missing.',
     A         '  Make sure DETAIN.TAB is in the list of files ',
     B         'for function tables.')
C***********************************************************************
      
      IF(DTEN_KNT.GT.0) THEN
        IF(GRAV.GT.15.0) THEN
          CONV_OUT = 43560.
          LENGTH_UNIT = ' (ft)'
          VOLUME_UNIT = ' (ac-ft)'
          AREA_UNIT =   ' (acres)'
          FLOW_UNIT =   '(ft^3/s)'
        ELSE
          CONV_OUT = 1.0
          LENGTH_UNIT = ' (m)  '
          VOLUME_UNIT = '  (m^3) '
          AREA_UNIT =   '  (m^2) '
          FLOW_UNIT =   ' (m^3/s)'
        ENDIF
        WRITE(STDOUT,52) LENGTH_UNIT, VOLUME_UNIT, AREA_UNIT, AREA_UNIT,
     A                   FLOW_UNIT, LENGTH_UNIT 
C       Traverse the trib-area management structure and check and compute
C       the values needed for modeling detention ponds.  All ponds are
C       assumed free of downstream influence on flow. 

        UNIT_PNT = 1

100     CONTINUE
          DTEN_PNT = TAM_ITAB(UNIT_PNT + 5)
          IF(DTEN_PNT.GT.0) THEN
C           There are detention ponds in this unit.  Do the following:
C           1. Check that the unit-area-detention volume table exists
C              and is the correct type.
C           2. Check that the orifice flow table exists and is the 
C              correct type. 
C           If both of these are ok then
C           3. Compute the description of the detention storage. 

C           This description will consist of an internally generated 
C           table of type 4 with argument of detention storage and 
C           function values of outflow and rate of change of outflow 
C           with respect to storage. Upon succesful completion,
C           the pointer to detention storage will be replaced 
C           by the address of this table. 

            UADV_TAB = DTEN_UADV_TAB(DTEN_PNT)
C            WRITE(KEY,'(I10)') UADV_TAB
C            CALL STRIP_L_BLANKS(
C     M                          KEY)
C            CALL GET_INTERNAL_TAB_NUMBER
C     I                                  (STDOUT, KEY,
C     M                                   EFLAG,
C     O                                   UADV_TAB)
            ORF_TAB = DTEN_ORF_TAB(DTEN_PNT)
C            WRITE(KEY,'(I10)') ORF_TAB
C            CALL STRIP_L_BLANKS(
C     M                          KEY)
C            CALL GET_INTERNAL_TAB_NUMBER
C     I                                  (STDOUT, KEY,
C     M                                   EFLAG,
C     O                                   ORF_TAB)

            CALL CHKTAB
     I                   (10, STDOUT, FTPNT, MFTNUM,
     M                    UADV_TAB, EFLAG)
            IF(EFLAG.GT.0) THEN
              WRITE(STDOUT,62) 
              STOP 'Abnormal stop. Errors found.'
            ENDIF
            CALL CHKTAB
     I                   (2, STDOUT, FTPNT, MFTNUM,
     M                    ORF_TAB, EFLAG)
            IF(EFLAG.EQ.0) THEN
C             Must have type 4.
              IF(GETTYP(ORF_TAB).NE.4) THEN
                WRITE(STDOUT,50) GET_TABID(GETTBN(ORF_TAB)), 
     A                GETTYP(ORF_TAB)
                STOP 'Abnormal stop. Errors found.'
              ENDIF      
            ELSE
              WRITE(STDOUT,64)
              STOP 'Abnormal stop. Errors found.'
            ENDIF
          

C           Compute the reqired pond volume. 
            CALL COMPUTE_DTEN_POND_VOLUME(STDOUT, DTEN_PNT, UADV_TAB,
     I                                    UNIT_PNT, GRAV,
     O                       POND_VOLUME, TRIB_AREA, QFAC, IMP_FRACTION)
        
C           Given the pond volume, the design depth, and the basin
C           side slope and the assumption that the pond is an 
C           inverted frustrum of a cone, compute the coefficients
C           that define the variation of volume from zero at 
C           a depth of zero to POND_VOLUME at the design depth.

            CALL FIND_VOLUME_COEFFICIENTS(STDOUT, DTEN_PNT, GRAV,
     I                             POND_VOLUME,
     M                             EFLAG,
     O                             C1, C2, C3, DESIGN_A)

C           Compute the orifice diameter.  
            CALL FIND_ORIFICE_DIAMETER(STDOUT, DTEN_PNT, ORF_TAB, GRAV,
     I                     TRIB_AREA, 
     O                     ORIFICE_D, DESIGN_Q, ORFCON)
        
C           Compute the type 4 table with storage volume as argument
C           and flow and its derivative as the two values tabulated. 
            CALL FIND_POND_ROUTING_TABLE(STDOUT, DTEN_PNT, ORF_TAB,
     I                            GRAV, ORIFICE_D, ORFCON, C1, C2, C3,
     M                            FTP, EFLAG)

C           Compute the average number of ponds. Reuse DTEN_AVDA for
C           this.  
            DTEN_AVDA(DTEN_PNT) = QFAC
        
C           Output a summary for this unit. 
            IF(TAM_ITAB(UNIT_PNT+1).EQ.1) THEN
C             Tributary to a branch. 
              FNODE = TAM_ITAB(UNIT_PNT+7)
              LNODE = TAM_ITAB(UNIT_PNT+8)
C             Get offset to convert from internal node number to 
C             the user node number. 
              IBRA = TAM_ITAB(UNIT_PNT)
              NODE_CONVERT = BRPT(1,IBRA) - BRPT(3,IBRA)
        
              IF(GRAV.GT.15.0) THEN
                WRITE(STDOUT,54) GETUSB(IBRA),
     A                       FNODE+NODE_CONVERT, LNODE+NODE_CONVERT,
     B                    IMP_FRACTION,
     B                    DTEN_YD(DTEN_PNT), POND_VOLUME/CONV_OUT,
     B                    C1/CONV_OUT, DESIGN_A/CONV_OUT,
     C                    DESIGN_Q, ORIFICE_D, 
     D                    GETTBN(DTEN_ROUT_TAB(DTEN_PNT)), QFAC
              ELSE
                WRITE(STDOUT,56) GETUSB(TAM_ITAB(UNIT_PNT)),
     A                       FNODE+NODE_CONVERT, LNODE+NODE_CONVERT,
     B                    IMP_FRACTION,
     B                    DTEN_YD(DTEN_PNT), POND_VOLUME/CONV_OUT,
     B                    C1/CONV_OUT, DESIGN_A/CONV_OUT,
     C                    DESIGN_Q, ORIFICE_D, 
     D                    GETTBN(DTEN_ROUT_TAB(DTEN_PNT)), QFAC
              ENDIF      

            ELSEIF(TAM_ITAB(UNIT_PNT+1).EQ.2) THEN
C             Tributary to a level-pool reservoir.
              IF(GRAV.GT.15.0) THEN
                WRITE(STDOUT,58) GETUSN(TAM_ITAB(UNIT_PNT)),
     B                    IMP_FRACTION,
     B                    DTEN_YD(DTEN_PNT), POND_VOLUME/CONV_OUT,
     B                    C1/CONV_OUT, DESIGN_A/CONV_OUT,
     C                    DESIGN_Q, ORIFICE_D, 
     D                    GETTBN(DTEN_ROUT_TAB(DTEN_PNT)), QFAC

              ELSE
                WRITE(STDOUT,60) GETUSN(TAM_ITAB(UNIT_PNT)),
     B                    IMP_FRACTION,
     B                    DTEN_YD(DTEN_PNT), POND_VOLUME/CONV_OUT,
     B                    C1/CONV_OUT, DESIGN_A/CONV_OUT,
     C                    DESIGN_Q, ORIFICE_D, 
     D                    GETTBN(DTEN_ROUT_TAB(DTEN_PNT)), QFAC
              ENDIF      
            ENDIF

          ENDIF
          UNIT_PNT = TAM_ITAB(UNIT_PNT+2)
          IF(UNIT_PNT.GT.0) THEN
C           There is another tributary area unit
            GOTO 100
          ENDIF
          
        WRITE(STDOUT,*) ' '
      ENDIF
      RETURN          
        
      END
C
C
C

      SUBROUTINE COMPUTE_AREA_AND_IMP_FRACTION(STDOUT, UNIT_PNT,
     O                      TRIB_AREA, IMP_FRACTION)

C     Compute the volume for a detention pond.

      IMPLICIT NONE
      INTEGER STDOUT, UNIT_PNT

      REAL TRIB_AREA, IMP_FRACTION

      INCLUDE 'arsize.prm'
      INCLUDE 'tam.cmn'
      INCLUDE 'tsfcom.cmn'
      INCLUDE 'dtendef.cmn'
C     Local

      INTEGER I, GAGE, N, TRIBA_PNT

      REAL TOTAL_AREA

C***********************************************************************
C     Compute the area in this unit.
      TOTAL_AREA = 0.0
      GAGE = TAM_ITAB(UNIT_PNT+4)
      N = GEND(GAGE) - GSTART(GAGE) + 1
      TRIBA_PNT = TAM_ITAB(UNIT_PNT+3)
      DO 100 I=1, N
        IF(TRIBA(TRIBA_PNT,I).GT.0.0) THEN
C         Skip negative areas.  Used for special purposes in some models.
          TOTAL_AREA = TOTAL_AREA + TRIBA(TRIBA_PNT,I)
        ENDIF
100   CONTINUE
      TRIB_AREA = TOTAL_AREA      
C     Get the impervious area and compute the impervious fraction.
      IF(TOTAL_AREA.GT.0.0) THEN              
        IMP_FRACTION = TRIBA(TRIBA_PNT,DEF_DTEN_LUI)/TOTAL_AREA
      ELSE
        IMP_FRACTION = 0.0
      ENDIF
      RETURN
      END

C
C
C
      SUBROUTINE COMPUTE_DELAY_EQUATIONS(STDOUT, GRAV, FTPNT,
     I                                   NBRA, BRPT,
     M                                   EFLAG)      

C     Compute the delay for any delay equation requests

      IMPLICIT NONE
      INCLUDE 'arsize.prm'
      INTEGER STDOUT, EFLAG, NBRA
      INTEGER FTPNT(MFTNUM), BRPT(8,NBRA)
      
      REAL GRAV

      INCLUDE 'tam.cmn'

C     Local

      INTEGER UNIT_PNT, DLAY_PNT, CONVERT_TAB, KEY, FNODE, LNODE,
     A        CONVERT_TAB_ADDRESS, NTAB, IBRA, NODE_CONVERT

      REAL TRIB_AREA, IMP_FRACTION, ITFRAC, DD, TBA
      DATA CONVERT_TAB/10002/
      
C     Called functions
      CHARACTER GETUSN*5
      INTEGER  GETUSB

      EXTERNAL GETUSB, GETUSN

C     *****************************FORMATS******************************
50    FORMAT(/,' *ERR:177* Imp. area conversion table is missing.')
52    FORMAT(/,' *ERR:371* Lag equation requested does not yet exist.')
54    FORMAT(/,' Summary of Delay Times',//,
     A '  Trib    Ups    Dsn      Imp.     Trib.     Delay',/,
     C ' to ID   node   node  fraction      area  time(hr)',/,
     E ' ----- ------ ------ --------- --------- ---------')
56    FORMAT(I6,2I7,F10.3,F10.4,F10.2)
58    FORMAT(1X,A5,14X,F10.3,F10.4,F10.2)
C***********************************************************************
  
      IF(DLAY_KNT.GT.0) THEN
C       Find internal number for the impervious-area conversion table

        WRITE(STDOUT,54)    
C       Traverse the trib-area management structure and check and compute
C       the lag times defined by equations.  The value of K for these 
C       will be negative and the negative value selects among the equations.
       
        UNIT_PNT = 1

100     CONTINUE
          DLAY_PNT = TAM_ITAB(UNIT_PNT + 6)
          IF(DLAY_PNT.GT.0) THEN
C           Compute the total trib area and the impervious fraction
            CALL COMPUTE_AREA_AND_IMP_FRACTION(STDOUT, UNIT_PNT, 
     O                        TRIB_AREA, IMP_FRACTION)
            IF(DLAY_K(DLAY_PNT).LT.0.0) THEN

              CONVERT_TAB_ADDRESS = CONVERT_TAB
              CALL CHKTAB
     I                   (2, STDOUT, FTPNT, MFTNUM,
     M                    CONVERT_TAB_ADDRESS, EFLAG)
              IF(EFLAG.NE.0) THEN
                WRITE(STDOUT,50)
                STOP 'Abnormal stop. Errors found.'
              ENDIF
          

C             Convert the impervious area from directly connected to 
C             total.
              CALL LKTAB
     I                  (CONVERT_TAB_ADDRESS, IMP_FRACTION, 1,
     O                  ITFRAC, NTAB, DD)

            
C             Now select the equation and compute the lag value. 
              KEY = INT(ABS(DLAY_K(DLAY_PNT)) + .1)
        
              IF(KEY.EQ.1) THEN
C               Equation from 1972 Purdue study. Area is mi^2,
C               imp fraction is a decimal fraction, and the
C               delay time is in hours.      
        
                IF(GRAV.GT.15.0) THEN
                  TBA = TRIB_AREA/(5280.**2)
                ELSE
C                 Convert square meters to mi^2
                  TBA = TRIB_AREA/(1609.344**2)
                ENDIF
                ITFRAC = ITFRAC + 1.0
                DLAY_K(DLAY_PNT) =
     A               3600.*0.803*TBA**0.512/ITFRAC**1.433
              ELSE
                WRITE(STDOUT,52)
                STOP 'Abnormal stop. Errors found.'
              ENDIF
            ENDIF
C           Output a summary for this unit. 
            IF(GRAV.GT.15.0) THEN
              TBA = TRIB_AREA/(5280.**2)
            ELSE
              TBA = TRIB_AREA/1.E6
            ENDIF
            IF(TAM_ITAB(UNIT_PNT+1).EQ.1) THEN
C             Tributary to a branch. 
              FNODE = TAM_ITAB(UNIT_PNT+7)
              LNODE = TAM_ITAB(UNIT_PNT+8)
C             Get offset to convert from internal node number to 
C             the user node number. 
              IBRA = TAM_ITAB(UNIT_PNT)
              NODE_CONVERT = BRPT(1,IBRA) - BRPT(3,IBRA)
        
              WRITE(STDOUT,56) GETUSB(IBRA),
     A                  FNODE+NODE_CONVERT, LNODE+NODE_CONVERT,
     B              IMP_FRACTION, TBA, DLAY_K(DLAY_PNT)/3600.
            ELSEIF(TAM_ITAB(UNIT_PNT+1).EQ.2) THEN
C             Tributary to a level-pool reservoir.
              WRITE(STDOUT,58) GETUSN(TAM_ITAB(UNIT_PNT)),
     B                  IMP_FRACTION, TBA, DLAY_K(DLAY_PNT)/3600.
            ENDIF
        
          ENDIF
          UNIT_PNT = TAM_ITAB(UNIT_PNT+2)
          IF(UNIT_PNT.GT.0) THEN
C           There is another tributary area unit
            GOTO 100
          ENDIF
          WRITE(STDOUT,*) ' '
      ENDIF
      RETURN
      END
