C     This file contains the subprograms that are specific to 
C     access to the HECDSS.  
C     ***********
C     *         *
C     * HECDSS_INIT
C     *         *
C     ***********

      SUBROUTINE HECDSS_INIT(STDOUT)

C     Set various values for managing HECDSS

      IMPLICIT NONE
      INTEGER STDOUT
      
      INCLUDE 'arsize.prm'
      INCLUDE 'hecdss.cmn'
      INCLUDE 'dssout.cmn'
      INCLUDE 'version.cmn'

C     Local

      CHARACTER NAME*6, VERSION*5

      INTEGER I      
C**********************************************************************
      WRITE(VERSION,'(F5.2)') VERSION_NUMBER
      NAME(1:1) = 'F'
      NAME(2:6) = VERSION
      CALL ZSET('PROG', NAME, 0)
      CALL ZSET('MUNIT', ' ', STDOUT)

      NUMBER_OF_HECDSS_FILES = 0
      NDSSOUT = 0
      DO 100 I=1,MAXDSS
        DSSOPN(I) = 0
        DSS_NAME(I) = ' '
100   CONTINUE
      RETURN
      END
C     ***********
C     *         *
C     * HECDSS_QUIT
C     *         *
C     ***********

      SUBROUTINE HECDSS_QUIT(STDOUT)

C     Shut down any HECDSS files.
      
      IMPLICIT NONE
      INTEGER STDOUT

      INCLUDE 'arsize.prm'
      INCLUDE 'hecdss.cmn'

C     Local

      CHARACTER*8 DUMMY
      INTEGER I, UNIT

      EXTERNAL ZINQIR, ZCLOSE, RELEASE_HECDSS_UNIT
C***********************************************************************
      DO 100 I=1,NUMBER_OF_HECDSS_FILES
        IF(DSSOPN(I).EQ.1) THEN
          CALL ZINQIR(IFLTAB(1,I),'UNIT', DUMMY, UNIT)
          CALL ZCLOSE(IFLTAB(1,I))
          DSSOPN(I) = 0
          CALL RELEASE_HECDSS_UNIT(STDOUT, UNIT)
        ENDIF
100   CONTINUE
      RETURN
      END
C     ***********
C     *         *
C     * PROCESS_HECDSS_NAME
C     *         *
C     ***********

      SUBROUTINE PROCESS_HECDSS_NAME(STDOUT, NAME, INDEX, OPTION, 
     A                               EFLAG )

C     Process a reference to a HECDSS file name.  

      IMPLICIT NONE
      INCLUDE 'arsize.prm'

      CHARACTER NAME*64, OPTION*6

      INTEGER EFLAG, INDEX, STDOUT

      INCLUDE 'hecdss.cmn'

C     Local

      CHARACTER*64 NEW_NAME

      LOGICAL THERE

      INTEGER I, IOSTAT, LENGTH, LOCAL_EFLAG, UNIT

      INTEGER GET_HECDSS_UNIT

      EXTERNAL GET_HECDSS_UNIT, ZFNAME, ZSET, ZOPEN
C     *********************FORMATS***************************************
50    FORMAT(/,' *ERR:267* HEC DSS file: ',A,/,11X,'exceeds ',
     A    'maximum number of HEC DSS files=',I5)
51    FORMAT(/,' *ERR:268* HEC DSS file: ',A,/,11X,' returns error',
     A       ' code=',I5,' during ZOPEN.')
52    FORMAT(/,' *ERR:269* HEC DSS file: ',A,/,
     A                     11X,'not found for input.')
C***********************************************************************
      LOCAL_EFLAG = 0
C     Make sure the file has the proper extension and also check if
C     the file exists.  Existence only required for INPUT option. 
      CALL ZFNAME(NAME, NEW_NAME, LENGTH, THERE)
      NAME = NEW_NAME(1:LENGTH)

C     Has this file name been seen before?
      DO 100  I=1,NUMBER_OF_HECDSS_FILES
        IF(NAME.EQ.DSS_NAME(I)) THEN
C         Yes, the file has been seen before.  Thus it is already
C         in the file reference system. 
          INDEX = I
          GOTO 1000
        ENDIF
100   CONTINUE
C     The file has not been seen before.  

C     Count the file.  Count it even if there is an error in 
C     the process.  Any error will abort the run so an invalid
C     count does not matter. 
      NUMBER_OF_HECDSS_FILES = NUMBER_OF_HECDSS_FILES + 1
      IF(NUMBER_OF_HECDSS_FILES.GT.MAXDSS) THEN
        EFLAG = 1
        WRITE(STDOUT, 50) NAME, MAXDSS
        GOTO 1000
      ENDIF
      DSS_NAME(NUMBER_OF_HECDSS_FILES) = NAME
C     Get a unit number and assign it to this DSS file
      UNIT =  GET_HECDSS_UNIT (STDOUT)
      CALL ZSET('UNIT', ' ', UNIT)
      IF(LOCAL_EFLAG.EQ.0) THEN
        IF(OPTION.EQ.'OUTPUT') THEN
C         Open the file.  If it does not exist, it is created. 
          CALL ZOPEN(IFLTAB(1,NUMBER_OF_HECDSS_FILES), NAME, IOSTAT)
          IF(IOSTAT.NE.0) THEN
C           Error of some kind in opening the file.
            WRITE(STDOUT,51) NAME, IOSTAT
            LOCAL_EFLAG = 1
            GOTO 1000
          ENDIF
          DSSOPN(NUMBER_OF_HECDSS_FILES) = 1
        ELSE
C         Assume input option.
          IF(THERE) THEN
C           The file exists.  Open it. 
            CALL ZOPEN(IFLTAB(1,NUMBER_OF_HECDSS_FILES), NAME, IOSTAT)
            IF(IOSTAT.NE.0) THEN
C             Error of some kind in opening the file.
              WRITE(STDOUT,51) NAME, IOSTAT
              LOCAL_EFLAG = 1
              GOTO 1000
            ENDIF
            DSSOPN(NUMBER_OF_HECDSS_FILES) = 1
          ELSE
            WRITE(STDOUT,52) NAME
            LOCAL_EFLAG = 1
          ENDIF
        ENDIF
      ENDIF
      INDEX = NUMBER_OF_HECDSS_FILES
1000  CONTINUE
      EFLAG = LOCAL_EFLAG
      RETURN
      END
C     ***********
C     *         *
C     * PROCESS_HECDSS_PATH_NAME
C     *         *
C     ***********

      SUBROUTINE PROCESS_HECDSS_PATH_NAME(STDOUT, NAME, TIME_STEP, 
     A                                    EFLAG)

C     Process a path name. 

      IMPLICIT NONE
      CHARACTER*80 NAME

      INTEGER EFLAG, STDOUT, TIME_STEP

C     Local

      INTEGER IERR, LENGTH, IS(6), IE(6), IL(6), NUMBER, IDT



C     ************************FORMATS***********************************
50    FORMAT(/,' *ERR:270* Path name:',A,/,11X,'produces HEC DSS error',
     A      ' code=',I5)
51    FORMAT(/, '*ERR:271* Path name: ',A,/,11X,'has invalid',
     A        ' E-part for a time series.')     
C***********************************************************************
C     Check the path name. 
      CALL CHRLNB(NAME, LENGTH)
      CALL ZCHKPN(NAME, LENGTH, IERR)
      IF(IERR.LT.0) THEN
        WRITE(STDOUT,50) NAME, IERR
        EFLAG = 1
        GOTO 100
      ENDIF
C     Extract the time step portion and find its value. 
      CALL ZUPATH(NAME, IS, IE, IL, IERR)
      IERR = 1
      CALL ZGINTL(IDT, NAME(IS(5):IE(5)), NUMBER, IERR)
      IF(IERR.EQ.0) THEN
C       Regular interval
        TIME_STEP = IDT
      ELSEIF(IERR.EQ.1) THEN
C       Irregular interval.
        TIME_STEP = 0
      ELSE
        WRITE(STDOUT,51) NAME
        EFLAG = 1
      ENDIF

100   CONTINUE
      RETURN
      END
C     ***********
C     *         *
C     * CHECK_EXIST
C     *         *
C     ***********

      SUBROUTINE CHECK_EXIST(DSS_INDEX, NAME, IERR)

C     Try checking for the existence of a time-series record
C     without a D part defined.

      IMPLICIT NONE
      INTEGER DSS_INDEX, IERR

      CHARACTER NAME*80

      INCLUDE 'arsize.prm'
      INCLUDE 'hecdss.cmn'

C     Local

      LOGICAL THERE

      INTEGER LENGTH, NHEAD, NDATA
C***********************************************************************
      CALL CHRLNB(NAME, LENGTH)
      CALL ZCHECK(IFLTAB(1,DSS_INDEX), NAME, LENGTH, NHEAD, NDATA,
     A             THERE)
      IF(THERE) THEN
        IERR = 0
      ELSE
        IERR = 1
      ENDIF
      RETURN
      END
C     ***********
C     *         *
C     * UPDATE_DSSOUT_JTIME
C     *         *
C     ***********

      SUBROUTINE UPDATE_DSSOUT_JTIME(JTIME, FULL)

C     Add the next FEQ Julian time to the buffer for output going
C     to HECDSS data sets.  Set the FULL flag when the last row
C     in the buffer is used. 

      IMPLICIT NONE
      INTEGER FULL

      REAL*8 JTIME

      INCLUDE 'arsize.prm'
      INCLUDE 'dssout.cmn'
C***********************************************************************
      NDSSOUT = NDSSOUT + 1
      FEQJT(NDSSOUT) = JTIME
      IF(NDSSOUT.EQ.MNDSSOUT) THEN
        FULL = 1
      ELSE
        FULL = 0
      ENDIF
      RETURN
      END
C     ***********
C     *         *
C     * UPDATE_DSSOUT_BUFFER
C     *         *
C     ***********

      SUBROUTINE UPDATE_DSSOUT_BUFFER(COLUMN, VAL)

C     Add an output value to the DSS output buffer.  The row index
C     is already set in UPDATE_DSSOUT_JTIME.

      IMPLICIT NONE
      INTEGER COLUMN

      REAL VAL

      INCLUDE 'arsize.prm'
      INCLUDE 'dssout.cmn'
C***********************************************************************
      DSS_OUTPUT_BUFFER(NDSSOUT,COLUMN) = VAL

      RETURN
      END
C     ***********
C     *         *
C     * INITIALIZE_DSSOUT_JTIME
C     *         *
C     ***********

      SUBROUTINE INITIALIZE_DSSOUT_JTIME(JTIME)

C     Add starting JTIME to zero row in the buffer

      IMPLICIT NONE
      REAL*8 JTIME

      INCLUDE 'arsize.prm'
      INCLUDE 'dssout.cmn'
C***********************************************************************
      FEQJT(0) = JTIME
      RETURN
      END
C     ***********
C     *         *
C     * INITIALIZE_DSSOUT_BUFFER
C     *         *
C     ***********

      SUBROUTINE INITIALIZE_DSSOUT_BUFFER(COLUMN, VAL)

C     Put the run-start values in the zero row of the buffer.

      IMPLICIT NONE
      INTEGER COLUMN

      REAL VAL

      INCLUDE 'arsize.prm'
      INCLUDE 'dssout.cmn'
C***********************************************************************
      DSS_OUTPUT_BUFFER(0,COLUMN) = VAL

      RETURN
      END
C     ***********
C     *         *
C     * OUTPUT_DSSOUT_BUFFER
C     *         *
C     ***********

      SUBROUTINE OUTPUT_DSSOUT_BUFFER 

C     Output the DSS output buffer when it is full and at the end
C     of the run.  

      IMPLICIT NONE
      INCLUDE 'arsize.prm'
      INCLUDE 'wrcom.cmn'
      INCLUDE 'dssout.cmn'
      INCLUDE 'hecdss.cmn'
      INCLUDE 'xscom.cmn'
      INCLUDE 'grav.cmn'

C     Called program units

      INTEGER M2IHM

      EXTERNAL M2IHM

C     Local

      CHARACTER CUNITS*8, CTYPE*8, CDATE*20, CTIME*4

      INTEGER I, J, K, JBDATE, IT, KNT, IRR_DT_OUT_KNT, REPLACE, IERR,
     A        L, MJDS, MJDE, IDT, MINUTE_OFFSET_START,
     B        MINUTE_OFFSET_END, MIN_OFFSET, YR, MN, DY, NDATE,
     C        ITIME, NVALUES

      REAL*8 DSS_OFFSET, JTS, JTE, JT, P, TEPS, MIN_BUFFER

      DATA REPLACE/1/, TEPS/1.0D-6/
C     ****************************FORMATS*******************************
50    FORMAT(/,' *ERR:272* HECDSS returns error code=',I5,' from ZSITS',
     A  ' for DSS:',/,1X,A,/,' and path:',A)
51    FORMAT(/,' *BUG:XXX* YMDDAT cannot convert YR=',I5,' MN=',I3,
     A      ' DY=',I3)
52    FORMAT(/,' *ERR:273* HECDSS returns error code=',I5,' from ZSRTS',
     A  ' for DSS:',/,1X,A,/,' and path:',A)
55    FORMAT(' INDEX OFFS VALUE')
56    FORMAT(I6, I5, F10.3)
57    FORMAT(/,' *ERR:274* Path name: ',/,1X,A,/,5X,'requires',
     A  ' simultaneous output of',I5,' values > maximum of',I5,'.',/,
     B  5X,'Ratio of FEQ time step to path-name time step too large.')

C***********************************************************************
      IF(IRR_DT.EQ.1) THEN
C       Irregular time step option in at least one path name.
C       Compute the vector of minute offsets.  Set the value
C       pointer to allow for any values skipped.  
C       Note that HECDSS requires there be no gap between 
C       successive writes with point valued data.  Thus we
C       write the ending value of a record again as the first
C       value of the following record
        JBDATE = INT(FEQJT(0)) - 15019
        DSS_OFFSET = DBLE(JBDATE) + 15019.D0        
        MINUTE_OFFSET(1) = 
     A             INT((FEQJT(0) - DSS_OFFSET)*1440.D0 + 0.5)
C        WRITE(STDOUT,*) ' OUTPUT_DSSOUT_BUFFER: MINUTE_OFFSET(1)=',
C     A               MINUTE_OFFSET(1),' JBDATE=',JBDATE

        KNT = 1
C       VALUE_POINTER points to the row of the buffer that contains
C       the corresponding time series value.  Some values in the 
C       buffer may be skipped because times to the nearest minute
C       match. 
        VALUE_POINTER(KNT) = 0
C        WRITE(STDOUT,*) ' OUTPUT_DSSOUT_BUFFER: NDSSOUT=',NDSSOUT
        DO 100 I=1,NDSSOUT
          IT = INT((FEQJT(I) - DSS_OFFSET)*1440.D0 + 0.5)
          IF(IT.EQ.MINUTE_OFFSET(KNT)) THEN
C           Consecutive times to the nearest minute match. Discard
C           the current value.
C            WRITE(STDOUT,*) ' MATCHING TIMES: IT=',IT
          ELSE
            KNT = KNT + 1
            MINUTE_OFFSET(KNT) = IT
            VALUE_POINTER(KNT) = I
          ENDIF
100     CONTINUE
        IRR_DT_OUT_KNT = KNT              
      ENDIF
      DO 1000  I=1,NFOUT
        IF(UNOUT(I).GE.1000) THEN
C         This is an output for a DSS file.  Set the units and the
C         reporting mode of the data. 
          CTYPE = 'INST-VAL'
          IF(ICDOUT(I).EQ.2) THEN
C           Elevation output.
            IF(GRAV.LT.10.0) THEN
              CUNITS = 'METERS'
            ELSE
              CUNITS = 'FEET'
            ENDIF
          ELSE
C           Flow output.
            IF(GRAV.LT.10.0) THEN
              CUNITS = 'CMS'
            ELSE
              CUNITS = 'CFS'
            ENDIF
          ENDIF        

          IF(TIME_STEP_OUT(I).EQ.0) THEN
C           This data set has an irregular time step.  
C           Adjust the values for any deleted by times being closer
C           than one minute.
C            WRITE(STDOUT,*) ' IRR_DT_OUT_KNT=',IRR_DT_OUT_KNT
C            WRITE(STDOUT,55)
            DO 200 J=1, IRR_DT_OUT_KNT
              VALOUT(J) =  DSS_OUTPUT_BUFFER(VALUE_POINTER(J),I)
C              WRITE(STDOUT,56) J, MINUTE_OFFSET(J), VALOUT(J)
200         CONTINUE
            CALL ZSITS(IFLTAB(1,DSS_INDEX_OUT(I)), NAMOUT(I), 
     A                 MINUTE_OFFSET, VALOUT, IRR_DT_OUT_KNT,
     B                 JBDATE, CUNITS, CTYPE, REPLACE, IERR)
            IF(IERR.GT.0) THEN
              WRITE(STDOUT,50) IERR, DSS_NAME(DSS_INDEX_OUT(I)),
     A          NAMOUT(I)
              STOP 'Abnormal stop: errors found.'
            ENDIF
          ELSE
C           This data set has a regular time step.   Compute the
C           starting and ending time of the values to be stored.
            IDT = TIME_STEP_OUT(I)
            JTS = FEQJT(0)
            MJDS = INT(JTS)
C           We must locate the time point of the DSS series that
C           is at or later than the time of the first item in the
C           buffer.   Compute the offset from the start day in minutes.
            MIN_BUFFER = (JTS - DBLE(MJDS))*1440.D0
C           Now compute the offset in integral minutes in the 
C           DSS time series 
            MINUTE_OFFSET_START =  (INT(MIN_BUFFER)/IDT)*IDT
            IF(DBLE(MINUTE_OFFSET_START).LT.MIN_BUFFER) THEN
C             We must increment to get the point within the time
C             span of the current buffer.
              MINUTE_OFFSET_START = MINUTE_OFFSET_START + IDT
            ENDIF
C           Compute the julian time of the first value in the
C           DSS series.
            JTS = MJDS + MINUTE_OFFSET_START/1440.D0

            IF(ABS(JTS - FEQJT(0)).LE.TEPS) THEN
              FEQJT(0) = JTS
            ENDIF

            JTE = FEQJT(NDSSOUT)
            MJDE = INT(JTE)
            MINUTE_OFFSET_END = 
     A        (INT((JTE - DBLE(MJDE))*1440.D0)/IDT)*IDT
            JTE = MJDE + MINUTE_OFFSET_END/1440.D0

C           Compute the number of values that must be interpolated 
C           and output. 
            NVALUES = ((MJDE - MJDS)*1440 + MINUTE_OFFSET_END 
     A                - MINUTE_OFFSET_START)/IDT + 1
C            WRITE(STDOUT,*) ' NUMBER OF VALUES TO INTERPOLATE=',NVALUES
            IF(ABS(JTE - FEQJT(NDSSOUT)).LE.TEPS) THEN
              FEQJT(NDSSOUT) = JTE
            ENDIF
            IF(JTE.GT.FEQJT(NDSSOUT)) THEN
C             Rounding to the nearest minute extends a point 
C             beyond the end of the buffer. 
C              WRITE(STDOUT,*) ' TIME SPAN OF WRITE BUFFER AND',
C     A           ' TIME SPAN FOR REGULAR TIME STEP DO NOT MATCH.'
              NVALUES = NVALUES - 1
C              WRITE(STDOUT,*) ' NVALUES BECOMES:', NVALUES
            ENDIF
            IF(NVALUES.GT.MNVALOUT) THEN
C             Too many intermediate values.
              WRITE(STDOUT,57) NAMOUT(I), NVALUES, MNVALOUT
              STOP 'Abnormal stop: errors found.'
            ENDIF

C           Interpolate for the values to be output. 
C            WRITE(STDOUT,*) ' INTERPOLATING WITH:'
C            WRITE(STDOUT,'(A,F20.10,A,F20.10)') 
C     A                     ' FEQJT(0)=',FEQJT(0),' JTS=',JTS
C            CALL JTIME_OUT(STDOUT, FEQJT(0))
C            CALL JTIME_OUT(STDOUT, JTS)
            
C            WRITE(STDOUT,'(A,F20.10,A,F20.10)') 
C     A                  ' FEQJT(NDSSOUT)=',FEQJT(NDSSOUT),' JTE=',JTE
C            CALL JTIME_OUT(STDOUT, FEQJT(NDSSOUT))
C            CALL JTIME_OUT(STDOUT, JTE)

C            WRITE(STDOUT,*) ' MINUTE_OFFSET_START=',MINUTE_OFFSET_START
C            WRITE(STDOUT,*) ' MINUTE_OFFSET_END=',MINUTE_OFFSET_END
            JT = JTS
            MIN_OFFSET = MINUTE_OFFSET_START
            L = 1
            DO 500 K=1,NVALUES
C             Find the containing interval.  JT is known to 
C             always be contained within the extended range
C             of julian times.  L may be 0.
              IF(JT.LT.FEQJT(L)) THEN
300             CONTINUE
                  L = L - 1
                  IF(L.LT.0) THEN
                    WRITE(STDOUT,*) ' *BUG* Underflow in search in',
     A                            ' OUTPUT_DSSOUT_BUFFER'
                    WRITE(STDOUT,*) ' FEQJT(0)=',FEQJT(0)
                    WRITE(STDOUT,*) ' JT=',JT
            WRITE(STDOUT,*) ' INTERPOLATING WITH:'
            WRITE(STDOUT,'(A,F20.10,A,F20.10)') 
     A                     ' FEQJT(0)=',FEQJT(0),' JTS=',JTS
            CALL JTIME_OUT(STDOUT, FEQJT(0))
            CALL JTIME_OUT(STDOUT, JTS)
           
            WRITE(STDOUT,'(A,F20.10,A,F20.10)') 
     A                  ' FEQJT(NDSSOUT)=',FEQJT(NDSSOUT),' JTE=',JTE
            CALL JTIME_OUT(STDOUT, FEQJT(NDSSOUT))
            CALL JTIME_OUT(STDOUT, JTE)

            WRITE(STDOUT,*) ' MINUTE_OFFSET_START=',MINUTE_OFFSET_START
            WRITE(STDOUT,*) ' MINUTE_OFFSET_END=',MINUTE_OFFSET_END

                    STOP 'Abnormal stop: errors found.'
                  ENDIF
                  IF(JT.LT.FEQJT(L)) GOTO 300
              ELSEIF(JT.GT.FEQJT(L+1)) THEN
400             CONTINUE
                  L = L + 1
                  IF(L.GT.NDSSOUT) THEN
                    WRITE(STDOUT,*) ' *BUG* Overflow in search in',
     A                            ' OUTPUT_DSSOUT_BUFFER'
                    STOP 'Abnormal stop: errors found.'
                  ENDIF
                  IF(JT.GT.FEQJT(L+1)) GOTO 400
              ENDIF
C             Here we have FEQJT(L) <= JT <= FEQJT(L+1). Interpolate
C             linearly.
              P = (JT - FEQJT(L))/(FEQJT(L+1) - FEQJT(L))              
              VALOUT(K) = DSS_OUTPUT_BUFFER(L,I) +
     A           P*(DSS_OUTPUT_BUFFER(L+1,I) - DSS_OUTPUT_BUFFER(L,I))

C             Update JT                 
              MIN_OFFSET = MIN_OFFSET + IDT
              JT = MJDS + MIN_OFFSET/1440.D0
500         CONTINUE                    

C           Compute the starting date and time. 
            CALL INVMJD
     I                   (MJDS,
     O                    YR, MN, DY)

            CDATE = ' '
            CALL YMDDAT(YR, MN, DY, -11, CDATE, NDATE, IERR)
            IF(IERR.NE.0) THEN
              WRITE(STDOUT,51) YR, MN, DY
              STOP 'Abnormal stop: errors found.'
            ENDIF
            ITIME = M2IHM(MINUTE_OFFSET_START, CTIME)
C           Write to the DSS file. 
            CALL ZSRTS(IFLTAB(1,DSS_INDEX_OUT(I)), NAMOUT(I),
     A                 CDATE, CTIME, NVALUES, VALOUT, 
     B                 CUNITS, CTYPE, 0, IERR)
            IF(IERR.NE.0) THEN
              WRITE(STDOUT,52) IERR, DSS_NAME(DSS_INDEX_OUT(I)),
     A          NAMOUT(I)
              STOP 'Abnormal stop: errors found.'
            ENDIF
          ENDIF
        ENDIF

1000  CONTINUE

C     Transfer the last line in the buffer system to line 0 to 
C     represent the complete time span for interpolation.
      FEQJT(0) = FEQJT(NDSSOUT)
      DO 1200 I=1,NFOUT
        DSS_OUTPUT_BUFFER(0,I) = DSS_OUTPUT_BUFFER(NDSSOUT,I)
1200  CONTINUE
      NDSSOUT = 0

      RETURN
      END        
C     ***********
C     *         *
C     * GET_HECDSS_BLOCK  *
C     *         *
C     ***********

      SUBROUTINE GET_HECDSS_BLOCK(STDOUT, NAMEIN, DSS_FILE_INDEX,
     A                           TIME_STEP, REPORT_MODE, JTIME, NMAX,
     B                              NVALUES, JTIMES, VALUES, MRJTIMES)

C     Get a consecutive sequence of values from a HECDSS pathname
C     attached to an input unit.  The sequence begins on or after
C     a FEQ julian time and will return no more than a given
C     number of values. 

      IMPLICIT NONE
      CHARACTER NAMEIN*80, REPORT_MODE*8

      INTEGER DSS_FILE_INDEX, TIME_STEP, STDOUT, NMAX, NVALUES, 
     A        MRJTIMES

      REAL VALUES(MRJTIMES)

      REAL*8 JTIME, JTIMES(MRJTIMES)

C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'hecdss.cmn'
      INCLUDE 'endrun.cmn'

C     Called program units

      INTEGER M2IHM
      EXTERNAL M2IHM

C     Local

      CHARACTER CUNITS*8, CTYPE*8, CTIME*4, CDATE*20
      
      INTEGER I, ITIME, YR, MN, DY, JBDATE, MJDS, 
     A          JDS, JDE, MOFF_START, MOFF_END, IERR,
     B          JD, NDATE, IOFF, IT,
     D          MINUTE_OFFSETS(MRRBUF+5)

C     ****************************FORMATS*******************************
50    FORMAT(/,' *ERR:275* Path name: ',A,/,11X,'produces HECDSS error',
     A      ' code=',I5,' in DSS file: ',/,' ',A)
51    FORMAT(/,' *ERR:276* Data in path name: ',A,/,11X,
     A         'is not  reporting mode ',A8)
52    FORMAT(/,' *BUG:XXX* YMDDAT cannot convert YR=',I5,' MN=',I3,
     A      ' DY=',I3)
C***********************************************************************
C     Get the HEC julian dates  and offsets from start of the day.
      MJDS = INT(JTIME)
      JDS = MJDS - 15019
      MOFF_START =  INT((JTIME - DBLE(MJDS))*1440.D0 + 0.5)
      IF(MOFF_START.EQ.0) THEN
C       HECDSS treats the boundary between days as belonging only
C       to the previous day when retrieving data. 
        MOFF_START = 1440
        JDS = JDS - 1
        MJDS = MJDS -1
      ENDIF

      IF(TIME_STEP.EQ.0) THEN
C       Irregular time step series.   
        JDE = JDE_RUN
        MOFF_END = MOFF_END_RUN
        CTYPE = ' '
        CUNITS = ' '
C       HECDSS appears to not function as documented.  ZRITS returns
C       one more than the limit requested in this case.  Furthermore
C       the extra value returned is incorrect!  Thus make the arrays
C       that return the values a bit longer and if the returned number
C       is greater than the requested maximum, discard the extra
C       values. 

        CALL ZRITS(IFLTAB(1,DSS_FILE_INDEX), NAMEIN,        
     A             JDS, MOFF_START, JDE, MOFF_END,
     B             MINUTE_OFFSETS, VALUES, NMAX, NVALUES,
     C             JBDATE, CUNITS, CTYPE, IERR)
        IF(IERR.EQ.1) THEN
C         Fix for HECDSS bug.
          CTYPE = 'INST-VAL'
        ENDIF
        IF(NVALUES.GT.NMAX) THEN
C         Fix for another bug.
          NVALUES = NMAX
        ENDIF
        
        IF(IERR.GE.4) THEN
          WRITE(STDOUT,50) NAMEIN, IERR, DSS_NAME(DSS_FILE_INDEX)
          STOP 'Abnormal stop: errors found.'
        ENDIF
          
C       Compute the FEQ julian times. 
        JD = JBDATE + 15019
        IF(CTYPE.EQ.REPORT_MODE) THEN
          DO 100 I=1,NVALUES
            JTIMES(I) =  JD + DBLE(MINUTE_OFFSETS(I))/1440.D0
100       CONTINUE
        ELSE
          WRITE(STDOUT,51) NAMEIN, REPORT_MODE
          STOP 'Abnormal stop: errors found.'
        ENDIF
      ELSE
C       Regular time-step series.
C       Adjust MOFF_START so that it is at the end point of the
C       time step that ends after the time given by JTIME.  That is,
C       the value in the time series must start on or after the time
C       JTIME.   

        IT = (MOFF_START/TIME_STEP)*TIME_STEP
        IF(IT.NE.MOFF_START) THEN
          MOFF_START = IT + TIME_STEP
        ENDIF
        IF(MOFF_START.GT.1440) THEN
          MOFF_START = MOFF_START - 1440
          MJDS = MJDS + 1
        ENDIF
        
        ITIME = M2IHM(MOFF_START, CTIME)

C       Compute the starting date and time. 
        CALL INVMJD
     I               (MJDS,
     O                YR, MN, DY)

        CTYPE = ' '
        CDATE = ' '
        CALL YMDDAT(YR, MN, DY, -11, CDATE, NDATE, IERR)
        IF(IERR.NE.0) THEN
          WRITE(STDOUT,52) YR, MN, DY
          STOP 'Abnormal stop: errors found.'
        ENDIF
        NVALUES = NMAX
        CALL ZRRTS(IFLTAB(1,DSS_FILE_INDEX), NAMEIN, 
     A             CDATE, CTIME, NVALUES, VALUES,
     B             CUNITS, CTYPE, IOFF, IERR)
        IF(IERR.NE.0) THEN
C         Check for missing data or records and extract only 
C         contiguous data at the start of the request.  
          IF(IERR.LE.3) THEN
C           Some data was found in the window.
            DO 103 I=1,NVALUES
              IF(VALUES(I).EQ.-901.0.OR.VALUES(I).EQ.-902.0) THEN
C               Found missing data.  End the scan.
                NVALUES = I - 1
                GOTO 105
              ENDIF
103         CONTINUE
            WRITE(STDOUT,*) ' *BUG:XXX* GET_HECDSS_BLOCK: ZRRTS',
     A     ' claims missing data but none found.'
            STOP 'Abnormal stop: errors found.'
105         CONTINUE
            IF(NVALUES.GT.0) GOTO 107
          ENDIF
          WRITE(STDOUT,50) NAMEIN, IERR, DSS_NAME(DSS_FILE_INDEX)
          STOP 'Abnormal stop: errors found.'
        ENDIF
107     CONTINUE
C       Compute the FEQ julian times. 
        IF(CTYPE.EQ.REPORT_MODE) THEN
          DO 110 I=1,NVALUES
            JTIMES(I) =  DBLE(MJDS) + DBLE(MOFF_START+IOFF)/1440.D0
            MOFF_START = MOFF_START + TIME_STEP
110       CONTINUE
        ELSE
          WRITE(STDOUT,51) NAMEIN, REPORT_MODE
          STOP 'Abnormal stop: errors found.'
        ENDIF
      ENDIF
      RETURN
      END        
C     ***********
C     *         *
C     * CHK_HECDSS_RECORD  *
C     *         *
C     ***********

      SUBROUTINE CHK_HECDSS_RECORD(STDOUT, NAMEIN, DSS_FILE_INDEX,
     A                           TIME_STEP, REPORT_MODE, JTIME, 
     B                           START_TIME, EFLAG)

C     Check to make sure that the DSS time series is of the
C     proper reporting mode; and find the start time needed
C     so the GET_HECDSS_BLOCK will obtain data from the time series
C     at or before the start time of the run.  

      IMPLICIT NONE
      CHARACTER NAMEIN*80, REPORT_MODE*8

      INTEGER DSS_FILE_INDEX, TIME_STEP, STDOUT, EFLAG

      REAL*8 JTIME, START_TIME

C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'hecdss.cmn'

C     Called program units

      INTEGER M2IHM
      EXTERNAL M2IHM
      
C     Local

      CHARACTER CUNITS*8, CTYPE*8, CTIME*4, CDATE*20

      LOGICAL LFLAGS, LFREAD
      
      INTEGER ITIME, YR, MN, DY, JBDATE, MJDS, NMAX, NVALUES,
     A          JDS, JDE, MOFF_START, MOFF_END, IERR,
     B          NDATE, IOFF, NHEADU, INFLAG,
     D          MINUTE_OFFSETS(25), M_FROM_DSS,
     E          M_FROM_JTIME

      REAL VALUES(25), FLAGS(1), HEADU(1)

      DATA LFLAGS/.FALSE./
C     ****************************FORMATS*******************************
50    FORMAT(/,' *ERR:275* Path name:',A,/,11X,'produces HEC DSS error',
     A      ' code=',I5,' in DSS file: ',/,' ',A)
51    FORMAT(/,' *ERR:276* Data in path name; ',A,/,11X,
     A         'is not reporting mode ',A8)
52    FORMAT(/,' *BUG:XXX* YMDDAT cannot convert YR=',I5,' MN=',I3,
     A      ' DY=',I3)
C***********************************************************************
      NMAX = 24
C     Get the HEC julian dates  and offsets from start of the day.
      MJDS = INT(JTIME)
      JDS = MJDS - 15019
      MOFF_START =  INT((JTIME - DBLE(MJDS))*1440.D0 + 0.00001)
      IF(MOFF_START.EQ.0) THEN
C       HECDSS treats the boundary between days as belonging only
C       to the previous day when retrieving data. 
        MOFF_START = 1440
        JDS = JDS - 1
        MJDS = MJDS -1
      ENDIF

      IF(TIME_STEP.EQ.0) THEN
C       Irregular time step series.   Request a 15 minute window
C       starting at the start time and also request return of the
C       previous value in the time series. 
        MOFF_END = MOFF_START + 15
        JDE = JDS
        IF(MOFF_END.GT.1440) THEN
          MOFF_END = MOFF_END - 1440
          JDE = JDE + 1
        ENDIF          

        CTYPE = ' '
        CUNITS = ' '
        INFLAG = 1
        CALL ZRITSX(IFLTAB(1,DSS_FILE_INDEX), NAMEIN,        
     A             JDS, MOFF_START, JDE, MOFF_END,
     B             MINUTE_OFFSETS, VALUES, NMAX, NVALUES,
     C             JBDATE, FLAGS, LFLAGS, LFREAD, CUNITS, CTYPE,
     D             HEADU, 0, NHEADU, INFLAG, IERR)
        IF(NVALUES.GT.NMAX) THEN
C         Fix for another bug.
          NVALUES = NMAX
        ENDIF
        
        IF(IERR.GE.4) THEN
          WRITE(STDOUT,50) NAMEIN, IERR, DSS_NAME(DSS_FILE_INDEX)
          EFLAG = 2
          RETURN
        ENDIF
          
C       Compute the FEQ julian times. 
        IF(CTYPE.EQ.REPORT_MODE) THEN
          M_FROM_DSS = 1440*JBDATE + MINUTE_OFFSETS(1)
          M_FROM_JTIME = 1440*JDS + MOFF_START
          START_TIME = DBLE(JBDATE + 15019) + 
     A                               DBLE(MINUTE_OFFSETS(1))/1440.D0
          IF(M_FROM_DSS.GT.M_FROM_JTIME) THEN
            EFLAG = 1
            RETURN
          ENDIF
        ELSE
          WRITE(STDOUT,51) NAMEIN, REPORT_MODE
          STOP 'Abnormal stop: errors found.'
        ENDIF
      ELSE
C       Regular time-step series.
C       MOFF_START must be adjusted to give a point in the
C       time series at or before the time derived from JTIME.
        MOFF_START = (MOFF_START/TIME_STEP)*TIME_STEP

        IF(MOFF_START.EQ.0) THEN
          MOFF_START =  1440
          MJDS = MJDS - 1
        ENDIF
        
        ITIME = M2IHM(MOFF_START, CTIME)

C       Compute the starting date and time. 
        CALL INVMJD
     I               (MJDS,
     O                YR, MN, DY)

        CTYPE = ' '
        CDATE = ' '
        CALL YMDDAT(YR, MN, DY, -11, CDATE, NDATE, IERR)
        IF(IERR.NE.0) THEN
          WRITE(STDOUT,52) YR, MN, DY
          STOP 'Abnormal stop: errors found.'
        ENDIF
        NVALUES = 2
        CALL ZRRTS(IFLTAB(1,DSS_FILE_INDEX), NAMEIN, 
     A             CDATE, CTIME, NVALUES, VALUES,
     B             CUNITS, CTYPE, IOFF, IERR)
        IF(IERR.GT.2) THEN
          WRITE(STDOUT,50) NAMEIN, IERR, DSS_NAME(DSS_FILE_INDEX)
          EFLAG = 2
          RETURN
        ENDIF
C       Compute the FEQ julian times. 
        IF(CTYPE.EQ.REPORT_MODE) THEN
          IF(VALUES(1).EQ.-901.00) THEN
            EFLAG = 2
            RETURN
          ELSE
            START_TIME =  DBLE(MJDS) + DBLE(MOFF_START)/1440.D0
          ENDIF
        ELSE
          WRITE(STDOUT,51) NAMEIN, REPORT_MODE
          STOP 'Abnormal stop: errors found.'
        ENDIF
      ENDIF
      RETURN
      END        




