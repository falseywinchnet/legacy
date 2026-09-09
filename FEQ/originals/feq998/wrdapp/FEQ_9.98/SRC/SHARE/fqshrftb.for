C
C
C
      SUBROUTINE MAYBE_ADD_HOME(
     M                          NAME)

C     Add home to front of file names that start with 
C     a / or \ but only if HOME or GHOME are not blank.
C     Also set local home to global home if local home is blank.

      IMPLICIT NONE

      CHARACTER*(*) NAME

      INCLUDE 'home.cmn'

C     Called program units
      EXTERNAL STRIP_L_BLANKS
C     Local
      INTEGER N
      CHARACTER*200 TEMP_LINE
C***********************************************************************
      IF(NAME.NE.' ') THEN
        CALL STRIP_L_BLANKS(
     M                      NAME)

        IF(NAME(1:1).EQ.'/'.OR.NAME(1:1).EQ.'\') THEN
C         Check for global home if HOME is blank
          IF(HOME.EQ.' ') THEN
            IF(GHOME.NE.' ') THEN
              HOME = GHOME
            ENDIF
          ENDIF
          IF(HOME.NE.' ') THEN
            N = LEN_TRIM(HOME)
            TEMP_LINE = HOME(1:N)//NAME
            NAME = TEMP_LINE
          ENDIF
        ENDIF
      ENDIF
      RETURN
      END
C
C
C
      REAL FUNCTION   GETHDD
     I                      (ADRS)
 
C     + + + PURPOSE + + +
C     Get the head datum for two-d tables. expand later to all
C     tables that have a head datum.
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
C***********************************************************************
      GETHDD = FTAB(ADRS)
      RETURN
      END
C
C
C
      SUBROUTINE   PUT1D
     I                  (STDOUT, TABNUM, TYPE, N, ARG, F1, F2,
     M                   NEXT,
     O                   TABADR)
 
C     + + + PURPOSE + + +
C     Put a one-dimensional table of type, TYPE, into the function
C     table storage system.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER N, NEXT, STDOUT, TABADR, TABNUM, TYPE
      REAL ARG(N), F1(N), F2(N)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT - Fortran unit number for user output and messages
C     TABNUM - table number to use
C     TYPE   - function table type
C     N      - number of tabulated arguments
C     ARG    - sequence of argument values for the 1-D table
C     F1     - seqence of values for first function
C     F2     - seqence of values for second function
C     NEXT   - pointer into scratch portion of ITAB/FTAB
C     TABADR - Table address in ITAB/FTAB
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER VTYPE(35)
      SAVE VTYPE
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, NFUN, PNT, SPACE
      REAL BARG
 
C     + + + DATA INITIALIZATIONS + + +
      DATA VTYPE/0,1,2,2,0,0,1,2,2,0,2,24*0/
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *ERR:694* PUT1D needs limit of ',I8,' for function',
     A    ' table storage',/,11X,' but current limit is',I8)
C***********************************************************************
C      WRITE(STDOUT,*) ' PUT1D: NEXT=',NEXT
C     A valid type number has a entry > 0 in VTYPE and the number
C     gives the number of functions that are stored in the table
C     of that type.  Of course the argument is always stored.
 
      NFUN = VTYPE(TYPE)
      IF(NFUN.EQ.0) THEN
C       Bug.  Invalid type sent to this routine.
 
        WRITE(STDOUT,*) ' *BUG;XXX* Invalid type=',TYPE,
     A         ' in subroutine PUT1D.'
        STOP 'Abnormal stop. Bug found.'
      ELSE
C       Is there room in FTAB
        SPACE = 4 + N*(NFUN + 1)
        IF(SPACE + NEXT.GT. MRFTAB) THEN
          WRITE(STDOUT,50)  SPACE + NEXT, NEXT
          STOP 'Abnormal stop. Error found.'
        ENDIF
 
C       Set the local pointer
        PNT = NEXT
 
C       Set the table address
        TABADR = PNT
 
C       Establish the header information.
        ITAB(PNT+1) = TABNUM
        ITAB(PNT+2) = TYPE
C       INITIALIZE LAST ADDRESS ACCESSED
        ITAB(PNT+3) = PNT + 5
        FTAB(PNT+4) = 0.0
        PNT = PNT + 5
 
C       Set the monotone increasing argument flag.
        BARG = ARG(1) - 100.
 
        DO 100 I=1,N
          IF(ARG(I).GT.BARG) THEN
C           Argument is greater than the last one.
            FTAB(PNT) = ARG(I)
            FTAB(PNT + 1) = F1(I)
            IF(NFUN.EQ.2) THEN
              FTAB(PNT+2) = F2(I)
              PNT = PNT + 3
            ELSE
              PNT = PNT + 2
            ENDIF
            BARG = ARG(I)
          ELSE
            WRITE(STDOUT,*) ' *BUG:XXX Non-increasing argument',
     A                 ' in PUT1D.'
            STOP 'Abnormal stop. Bug found.'
          ENDIF
 100    CONTINUE
 
C       Save address of last argument in the table.
        ITAB(NEXT) = PNT - NFUN - 1
        NEXT = PNT
      ENDIF
      RETURN
      END
C
C
C
      CHARACTER*16 FUNCTION GET_GISID
     I                              (ADRS)

C     + + + PURPOSE + + +
C     Get the GIS id string from the table at ADRS.

      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS

C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB

C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'

      CHARACTER*16 GET_STRING_FROM_FT
      EXTERNAL GET_STRING_FROM_FT
C     Local

      INTEGER TYPE
C***********************************************************************
      IF(ADRS.EQ.0) THEN
C       Tables not available yet.  Return blanks
        GET_GISID = '                '
      ELSE        
        TYPE = ITAB(ADRS+2)
        IF(TYPE.LE.25.AND.TYPE.GE.20) THEN
C         Cross section table.  Only cross section tables have GISID's!
          GET_GISID = GET_STRING_FROM_FT(ADRS+12)
        ELSE
          GET_GISID = '                '
        ENDIF
      ENDIF
      RETURN
      END
C     ***********
C     *         *
C     * PUT_STRING_IN_FT
C     *         *
C     ***********

      SUBROUTINE PUT_STRING_IN_FT(FTP, STRING)

C     Put the characters in STRING into a function-table header block
C     with the first character being stored in the first byte of 
C     the four-byte word at FTP.  STRING is of fixed length.

      IMPLICIT NONE
      CHARACTER*16 STRING

      INTEGER FTP

      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'

C     Local

      CHARACTER  CS8*8
      REAL*4 SP(2)
      REAL*8 DP

      REAL*8 CHAR_TO_DP

      EQUIVALENCE (SP(1), DP)
C***********************************************************************
C     Do upper half of STRING
      CS8 = STRING(1:8)
      DP = CHAR_TO_DP(CS8)
      FTAB(FTP) = SP(1)
      FTAB(FTP+1) = SP(2)
C     Do lower half of STRING
      CS8 = STRING(9:16)
      DP = CHAR_TO_DP(CS8)
      FTAB(FTP+2) = SP(1)
      FTAB(FTP+3) = SP(2)
      RETURN
      END
C     ***********
C     *         *
C     * GET_STRING_FROM_FT
C     *         *
C     ***********

      CHARACTER*16 FUNCTION GET_STRING_FROM_FT(FTP)

C     Get a string stored in a function-table header block  and
C     return it. 

      IMPLICIT NONE
      INTEGER FTP

      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      
C     Called program units
      CHARACTER*8  DP_TO_CHAR
      EXTERNAL DP_TO_CHAR

C     Local

      CHARACTER CS8*8, CS16*16
      REAL*4 SP(2)
      REAL*8 DP


      EQUIVALENCE (SP(1), DP)
C***********************************************************************
C     Get upper half of string.
      SP(1) = FTAB(FTP)
      SP(2) = FTAB(FTP+1)
      CS8 = DP_TO_CHAR(DP)
      CS16(1:8) = CS8
C     Get lower half of string
      SP(1) = FTAB(FTP+2)
      SP(2) = FTAB(FTP+3)
      CS8 = DP_TO_CHAR(DP)
      CS16(9:16) = CS8
      GET_STRING_FROM_FT = CS16
      RETURN
      END      
C     ***********
C     *         *
C     * PUT_DP_IN_FT
C     *         *
C     ***********

      SUBROUTINE PUT_DP_IN_FT(FTP, DPIN)

C     Put the real*8 value in DPIN into a function-table header block
C     with the first byte being stored in the first byte of 
C     the four-byte word at FTP.  STRING is of fixed length.

      IMPLICIT NONE
      REAL*8 DPIN

      INTEGER FTP

      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'

C     Local

      REAL*4 SP(2)
      REAL*8 DP

      EQUIVALENCE (SP(1), DP)
C***********************************************************************
      DP = DPIN
      FTAB(FTP) = SP(1)
      FTAB(FTP+1) = SP(2)
      RETURN
      END
C     ***********
C     *         *
C     * GET_DP_FROM_FT
C     *         *
C     ***********

      REAL*8 FUNCTION GET_DP_FROM_FT(FTP)

C     Get a a REAL*8 value stored in a function-table header block and
C     return it. 

      IMPLICIT NONE
      INTEGER FTP

      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      
C     Local

      REAL*4 SP(2)
      REAL*8 DP

      EQUIVALENCE (SP(1), DP)
C***********************************************************************
      SP(1) = FTAB(FTP)
      SP(2) = FTAB(FTP+1)
      GET_DP_FROM_FT = DP
      RETURN
      END      
C
C
C
      SUBROUTINE   ATABIN
     I                   (IN, STDOUT, MLFT, NTAB,
     M                    EFLAG, FTP, TYPE)
 
C     + + + PURPOSE + + +
C     Input an arbitrary interval table
C     TYPE = 2 - single function - linear interpolation
C     TYPE = 3 - 2 function - quadratic
C     TYPE = 4 - 2 function - hermite interpolation
C     TYPE = 6 - not read by atabin- read by twodin
C     TYPE=  7 - single function, linear interpolation but time argument
C                given in yr mn dy hr with hr allowed to be fractional
C     TYPE = 8 - like type 3 but with argument like 7
C     TYPE = 9 - like type 4 but with argument like 7
C     TYPE =11 - like type 7 but two functions not related by any
C                simple rule. Reserved for wind, giving speed and
C                direction.
C     TYPE =15-  1-D table of 2-D table numbers to represent a
C                simple form of 3-D table.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, FTP, IN, STDOUT, MLFT, NTAB, TYPE
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     STDOUT   - Fortran unit number for user output and messages
C     MLFT   - maximum length of FTAB/ITAB
C     NTAB   - table number
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     FTP    - next open location in the function table storage
C     TYPE   - table type
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'julian.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER DPM(12,2), STEP(4)
      SAVE DPM, STEP
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ARGFLG, FTPOLD, I, LP, N, OLDDY, OLDMN, OLDYR, OUT
      REAL AFAC, ARG, BARG, F(7), FAC, REFLEV, SHIFT
      DOUBLE PRECISION HR, JT
      CHARACTER HEAD*80, LINE*80
 
C     + + + INTRINSICS + + +
      INTRINSIC DBLE, IABS
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER LPYEAR, MJD
      CHARACTER GET_TABID*16
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL INL80, KIL, LPYEAR, MJD, GET_TABID
 
C     + + + DATA INITIALIZATIONS + + +
      DATA STEP/0,2,3,3/
      DATA DPM/31,28,31,30,31,30,31,31,30,31,30,31,
     1         31,29,31,30,31,30,31,31,30,31,30,31/
 
C     + + + INPUT FORMATS + + +
 1    FORMAT(80A)
 46   FORMAT(5X,F10.0,5X,F10.0,6X,F10.0,7X,F10.0)
 48   FORMAT(8F10.0)
 50   FORMAT(I4,1X,I2,1X,I2,7F10.0)
 
C     + + + OUTPUT FORMATS + + +
 11   FORMAT(' ',80A)
 47   FORMAT(' Function scale fac= ',1PE12.5,
     B     ' Arg scale fac=',1PE12.5,' Arg shift=',1PE12.5)
 49   FORMAT(' ',F10.2,7(1PE10.3))
 51   FORMAT(' ',I4,1X,I2,1X,I2,F10.3,5(1PE10.3))
58    FORMAT(/,' *WRN:53* Unexpected end of a function table.')
 60   FORMAT(/,' *WRN:55* End of file found before end of table.')
C***********************************************************************
      OLDYR = 1925
      OLDMN = 1
      OLDDY = 1
      CALL INL80
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,46,ERR=991) REFLEV, FAC, AFAC, SHIFT
      IF(FAC.EQ.0.0) FAC = 1.0
      IF(AFAC.EQ.0.0) AFAC = 1.0
      WRITE(STDOUT,47) FAC, AFAC, SHIFT
 
      IF((FTP+4).GE.MLFT) CALL KIL
     I                             (10,
     M                              FTP, EFLAG)
 
C     FTP RESERVED FOR THE HIGH ADDRESS OF THE TABLE
 
      OUT = 1
      IF(TYPE.LT.0) OUT = 0
      TYPE = IABS(TYPE)
 
C     CONVERT TYPES 7, 8, AND 9 TO 2, 3, AND 4 AND SET AN ARGUMENT FLAG
 
      IF(TYPE.GE.7.AND.TYPE.LE.9) THEN
        TYPE = TYPE - 5
        ARGFLG = 1
      ELSE
        ARGFLG = 0
      ENDIF
      IF(TYPE.EQ.11) THEN
        ARGFLG = 1
      ENDIF
      ITAB(FTP+1) = NTAB
      ITAB(FTP+2) = TYPE
      IF(TYPE.LE.4) N = STEP(TYPE) - 1
      IF(TYPE.EQ.11) N = 2
 
C     INITIALIZE LAST ADDRESS ACCESSED
 
      ITAB(FTP+3) = FTP + 5
C     FTAB(FTP+4) = REFLEV
      FTAB(FTP+4) = SHIFT
      FTPOLD = FTP
      FTP = FTP+5
 
      CALL INL80
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,1) HEAD
      WRITE(STDOUT,11) HEAD
 
      BARG = -1.0E37
 
 1000 CONTINUE
 
         CALL INL80
     I             (IN, STDOUT,
     O              LINE)
         IF(LINE(1:6).EQ.'TABLE#'.OR.LINE(1:5).EQ.'TABID') THEN
          WRITE(STDOUT,58) 
          BACKSPACE IN
          GOTO 1500
         ENDIF

         IF(LINE(1:7).EQ.'ENDFILE') THEN
            WRITE(STDOUT,60)
            STOP 'Abnormal stop.  End of file before end of table!'
         ENDIF
    
         IF(ARGFLG.EQ.0) THEN
           READ(LINE,48,ERR=991) ARG, (F(I), I=1,N)
C          Apply scale factor to argument.  Scale factor
C          does not apply to time series tables.
           ARG = ARG*AFAC
         ELSE
           READ(LINE,50,ERR=991) YR, MN, DY, HR, (F(I), I=1,N)
 
C          PROPAGATE YR, MN, AND DY. FIRST VALUES ASSUMED TO BE
C          CORRECT
 
            IF(YR.EQ.0) YR = OLDYR
            IF(MN.EQ.0) MN = OLDMN
            IF(DY.EQ.0) DY = OLDDY
            LP = LPYEAR(YR)
 
C            WRITE(STDOUT,*) 'ATABIN: DATE=',YR, MN, DY, HR
            OLDYR = YR
            OLDMN = MN
            OLDDY = DY
            IF(MN.LT.1.OR.MN.GT.12) THEN
              WRITE(STDOUT,*) 
     A    ' *ERR:74* INVALID MONTH IN TABLE#=',GET_TABID(NTAB)
              EFLAG = 1
            ENDIF
            IF(DY.LT.1.OR.DY.GT.DPM(MN,LP)) THEN
              WRITE(STDOUT,*) 
     A     ' *ERR:75* Invalid DAY in TABID=',GET_TABID(NTAB)
              EFLAG = 1
            ENDIF
            IF(YR.LE.1859) THEN
              WRITE(STDOUT,*) 
     A     ' *ERR:76* Invalid YEAR in TABID=',GET_TABID(NTAB)
              EFLAG = 1
            ENDIF

            IF(HR.GT.24.D0.OR.HR.LT.0.D0) THEN
              WRITE(STDOUT,*) 
     A     ' *ERR:119* Invalid HOUR in TABID=',GET_TABID(NTAB)
              EFLAG = 1
            ENDIF

 
 
C           CONVERT THE DATE AND TIME TO JULIAN DAY
            JT = DBLE(MJD(YR,MN,DY)) + HR/24.D0
C           CONVERT JULIAN TIME TO THE NUMBER OF SECONDS ELAPSED
C           FROM THE START of the first event if DIFFUS=YES or
C           the start of the run if not.
 
            ARG = 86400.*(JT - TAB_789_JTBASE)
C            WRITE(STDOUT,*) ' ATABIN: ARG=',ARG, ' JT=',JT,
C     A                 ' TAB_789_JTBASE=', TAB_789_JTBASE
         ENDIF
 
         IF(ARG.LE.BARG) GOTO 1500
         BARG = ARG
         IF(OUT.EQ.1) THEN
           IF(ARGFLG.EQ.0) THEN
             WRITE(STDOUT,49) ARG, (F(I), I=1,N)
           ELSE
             WRITE(STDOUT,51) YR, MN, DY, HR, (F(I), I=1,N)
           ENDIF
         ENDIF
         IF((FTP+N).GE.MLFT) CALL KIL
     I                                (10,
     M                                 FTP, EFLAG)
         FTAB(FTP) = ARG + SHIFT
         IF(TYPE.NE.11) THEN
           DO 1200 I=1,N
              FTP = FTP + 1
              FTAB(FTP) = F(I)*FAC
 1200      CONTINUE
         ELSE
           FTP = FTP + 1
           FTAB(FTP) = F(1)*FAC
           FTP = FTP + 1
C          ADJUST THE AZIMUTH TO ACCOUNT FOR THE MANNER OF REFERING
C          TO WIND DIRECTION.  WE NEED THE DIRECTION THE WIND IS
C          GOING AND NOT THE DIRECTION IT IS COMING FROM.
 
           F(2) = F(2) + 180.0
           IF(F(2).GE.360.0) F(2) = F(2) - 360.
           FTAB(FTP) = F(2)*1.745329E-2
         ENDIF
         FTP = FTP + 1
         GOTO 1000
 
 1500 CONTINUE
      ITAB(FTPOLD) = FTP - N - 1
      RETURN
 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE
        STOP 'Abnormal stop: errors found.'
      END
C
C
C
      SUBROUTINE   CHKTYP
     I                   (STDOUT, ADRS, CTYPE,
     O                    EFLAG)
 
C     + + + PURPOSE + + +
C     Given the address of the table and its desired type class,
C     check if the type of the table is in the class.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS, CTYPE, EFLAG, STDOUT
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     ADRS   - address of the function table in FTAB/ITAB
C     CTYPE  - type class number for checking valid table types
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
 
C     Common blocks

      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'

C     + + + SAVED VALUES + + +
      INTEGER VRTYPE(100)
      SAVE VRTYPE
 
C     + + + LOCAL VARIABLES + + +
      INTEGER J, LSTVAL, N, PNT, TAB, TYPE
      INTEGER VALID(10)
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS

C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_TABID
      EXTERNAL GET_TABID
 
C     + + + DATA INITIALIZATIONS + + +
      DATA (VRTYPE(J), J=  1, 10)/36,45, 0, 0, 0,54, 0, 0, 0,96/
      DATA (VRTYPE(J), J= 11, 20)/60,63, 0, 0,98, 0, 0, 0, 0,68/
      DATA (VRTYPE(J), J= 21, 30)/76,83,87,91,94, 0, 0, 0, 0, 0/
      DATA (VRTYPE(J), J= 31, 40)/ 0, 0, 0, 0, 0, 1,12,21,22,24/
      DATA (VRTYPE(J), J= 41, 50)/25, 0, 0, 0, 2, 3, 4, 7, 8, 9/
      DATA (VRTYPE(J), J= 51, 60)/ 0, 0, 0, 6,13,14, 0, 0, 0,11/
      DATA (VRTYPE(J), J= 61, 70)/ 0, 0,12,22,25, 0, 0,20,21,22/
      DATA (VRTYPE(J), J= 71, 80)/23,24,25, 0, 0,21,22,24,25, 1/
      DATA (VRTYPE(J), J= 81, 90)/12, 0,22,25,12, 0,23,24,25, 0/
      DATA (VRTYPE(J), J= 91,100)/24,25, 0,25, 0,10, 0,15, 0, 0/
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *ERR:174* Table  Id=',A,' of type=',I3,' invalid in ',
     A       'current',
     B      ' context.',/,10X,' Valid table types are:',10I3)
 56   FORMAT('0*BUG:42* CTYPE=',I5,' IS INVALID IN SUBROUTINE CHKTYP')
C***********************************************************************
C     VRTYPE contains either a zero or an index value in its
C     first 35 locations.  These are set aside for indexing by the
C     expected range of table types.  A zero value at the table type
C     location indicates an invalid desired type.  This does not mean
C     that the table type is invalid; just that CHKTYP does not now
C     expect that that type will appear as representative of a class
C     of tables.  A non-zero value points to a subsequent location
C     in VRTYPE containing a consecutive list of the types that
C     are valid for the expected type class.  Each list is terminated
C     by a 0 value.  A negative value is a continuation index to
C     allow for expansion of any type class without having to
C     change the existing values.
 
C     CONTENTS OF VRTYPE(*,*)
 
C  INDEX VRTYPE  INDEX VRTYPE  INDEX VRTYPE  INDEX VRTYPE
C      1     36     31      0     61      0     91     24
C      2     45     32      0     62      0     92     25
C      3      0     33      0     63     12     93      0
C      4      0     34      0     64     22     94     25
C      5      0     35      0     65     25     95      0
C      6     54     36      1     66      0     96     10
C      7      0     37     12     67      0     97      0
C      8      0     38     21     68     20     98     15
C      9      0     39     22     69     21     99      0
C     10     96     40     24     70     22    100      0
C     11     60     41     25     71     23    101
C     12     63     42      0     72     24    102
C     13      0     43      0     73     25    103
C     14      0     44      0     74      0    104
C     15     98     45      2     75      0    105
C     16      0     46      3     76     21    106
C     17      0     47      4     77     22    107
C     18      0     48      7     78     24    108
C     19      0     49      8     79     25    109
C     20     68     50      9     80      1    110
C     21     76     51      0     81     12    111
C     22     83     52      0     82      0    112
C     23     87     53      0     83     22    113
C     24     91     54      6     84     25    114
C     25     94     55     13     85     12    115
C     26      0     56     14     86      0    116
C     27      0     57      0     87     23    117
C     28      0     58      0     88     24    118
C     29      0     59      0     89     25    119
C     30      0     60     11     90      0    120
 
      IF(CTYPE.LT.1.OR.CTYPE.GT.35) THEN
        WRITE(STDOUT,56) CTYPE
        STOP 'Abnormal stop: errors found.'
      ELSE
        PNT = VRTYPE(CTYPE)
        IF(PNT.EQ.0) THEN
          WRITE(STDOUT,56) CTYPE
          STOP 'Abnormal stop: errors found.'
        ELSE
C         WE HAVE A VALID TYPE GROUPING.  GET THE TYPE OF THE
C         TABLE BEING CHECKED AND SEEK IT IN THE LIST.  ALL TABLES
C         MUST HAVE THEIR TYPE AT OFFSET +2.
 
          TYPE = ITAB(ADRS+2)
          TAB = ITAB(ADRS+1)
 
C         CLEAR THE COUNT OF VALID TYPES ENCOUNTERED
          N = 0
 
 100      CONTINUE
            LSTVAL = VRTYPE(PNT)
            IF(LSTVAL.GT.0) THEN
C             FOUND A TYPE TO CHECK AGAINST. PUT IT ON THE LIST.
C             FOR ERROR REPORTING IF NEEDED.
              N = N + 1
              VALID(N) = LSTVAL
 
              IF(TYPE.EQ.LSTVAL) THEN
                RETURN
              ELSE
C               INCREMENT TO THE NEXT LOCATION
                PNT = PNT + 1
                GOTO 100
              ENDIF
            ELSEIF(LSTVAL.LT.0) THEN
C             RESET THE POINTER TO CONTINUE WITH THE CURRENT LIST
              PNT = ABS(LSTVAL)
              GOTO 100
            ENDIF
 
C           NO MATCH FOUND.
            EFLAG = 1
            WRITE(STDOUT,50) GET_TABID(TAB), TYPE, (VALID(PNT),PNT=1,N)
          RETURN
        ENDIF
      ENDIF
      END
C
C
C
      REAL FUNCTION   FMXARG
     I                      (ADRS)
 
C     + + + PURPOSE + + +
C     Find the maximum argument for the table stored at ADRS.
 
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
 50   FORMAT(' *BUG:46* FMXARG INVALID WITH 2-D TABLE. TAB#=',I5,
     A       ' IS A 2-D TABLE.')
C***********************************************************************
      TYPE = ITAB(ADRS+2)
      IF(TYPE.EQ.5.OR.TYPE.EQ.6.OR.TYPE.EQ.10.OR.TYPE.EQ.13.OR.
     A   TYPE.EQ.14.OR.TYPE.EQ.15) THEN
        WRITE(STD6,50) GETTBN(ADRS)
        STOP 'Abnormal stop: errors found.'
      ELSE
        FMXARG = FTAB(ITAB(ADRS))
        RETURN
      ENDIF
      END
C
C
C
      SUBROUTINE   FNDSTA
     I                   (NUM, STDOUT,
     O                    EFLAG, X)
 
C     + + + PURPOSE + + +
C     Find the station of the cross section from the table
C     given by the table number in NUM.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, STDOUT, NUM
      REAL X
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     NUM    - table number
C     STDOUT   - Fortran unit number for user output and messages
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     X      - station value
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'

C     External program units
      CHARACTER GET_TABID*16
      EXTERNAL GET_TABID
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADRS
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *ERR:197* Cross sec. table Id= ',A,' not found for',
     A        ' station.')
 52   FORMAT(/,' *BUG:XXX* NUM < 0 in sub. FNDSTA')
C***********************************************************************
      IF(NUM.LE.0) THEN
        WRITE(STDOUT,52) NUM
        EFLAG = 1
        X = 0.0
      ELSE
        ADRS = FTPNT(NUM)
        IF(ADRS.GT.0) THEN
          X = FTAB(ADRS + 4)
        ELSE
C         TABLE DOES NOT EXIST
 
          WRITE(STDOUT,50) GET_TABID(NUM)
          EFLAG = 1
          X = 0.0
        ENDIF
      ENDIF
      RETURN
      END
C
C
C
      SUBROUTINE GET_NEXT_TABID
     I                         (STDOUT, LINEA,
     O                          EFLAG, TABID, TABLE, NXTNAM)

C     Get the next table id and the optional NXTNAM from LINE.
      IMPLICIT NONE
      INTEGER EFLAG, STDOUT, TABLE
      CHARACTER LINEA*(*), TABID*16, NXTNAM*128

      INCLUDE 'home.cmn'

C     + + + EXTERNAL NAMES + + +
      EXTERNAL STRIP_L_BLANKS, MAYBE_ADD_HOME

C     Local

      INTEGER IT, NXT, N
      CHARACTER LINE*196, TEMP_LINE*196
C     *****************************FORMATS******************************
 50   FORMAT(/,' *ERR:735* Expected line with a TABID=, FILE=,',
     A        ' or HOME= but found:', /,5X,A)
 52   FORMAT(/,' *ERR:736* No = found as expected in input line:',/,A)
 54   FORMAT(/,' *ERR:737* No file name found following FILE=')
 56   FORMAT(/,' *ERR:738* No table id found following TABID or TABLE#')
 58   FORMAT(/,' *WRN:58* No home name found following HOME=. ',
     A         ' Home name cleared.')
C***********************************************************************
      LINE = LINEA
C     Get the name field for the table id.  Do a search for
C     the equal sign because some table ids might have no intervening
C     space after the equal. 

      CALL STRIP_L_BLANKS(
     M                      LINE)
      IF(LINE(1:3).NE.'TAB'.AND.LINE(1:3).NE.'Tab'.AND.
     A   LINE(1:4).NE.'FILE'.AND.LINE(1:4).NE.'File'.AND.
     B   LINE(1:4).NE.'HOME'.AND.LINE(1:4).NE.'Home') THEN
        WRITE(STDOUT,50) LINE
        STOP 'Abnormal stop: errors found.'
      ENDIF
      IT = INDEX(LINE, '=')
      IF(IT.EQ.0) THEN
        WRITE(STDOUT,52) LINE
        STOP 'Abnormal stop: errors found.'
      ENDIF
      IF(LINE(1:4).EQ.'FILE'.OR.LINE(1:4).EQ.'File') THEN
C       We have a file name given.  No TabId given.
        NXT = IT + 1
        CALL NXTTOK
     I             (LINE,
     M              NXT,
     O              NXTNAM)
        IF(NXT.LE.0) THEN
          WRITE(STDOUT,54) 
          STOP 'Abnormal stop: errors found.'
        ENDIF
C       Set signal that a file name was found
        TABLE = -15
        TABID = ' '
C       Add the prefix of HOME here if conditions are right. 
        CALL MAYBE_ADD_HOME(
     M                      NXTNAM)
      ELSEIF(LINE(1:4).EQ.'HOME'.OR.LINE(1:4).EQ.'Home') THEN
C       We have a home name given.  No TabId given.
        NXT = IT + 1
        CALL NXTTOK
     I             (LINE,
     M              NXT,
     O              NXTNAM)
        IF(NXT.LE.0) THEN
          WRITE(STDOUT,58) 
          NXTNAM = ' '
C          STOP 'Abnormal stop: errors found.'
        ENDIF
C       Set signal that a home name was found
        HOME = NXTNAM
        CALL STRIP_L_BLANKS(
     M                      HOME)
        TABLE = -16
        TABID = ' '
      ELSE      
        NXT = IT + 1
C       Get the TABID field
        CALL NXTTOK
     I             (LINE,
     M              NXT,
     O              TABID)

        IF(NXT.LE.0) THEN
          WRITE(STDOUT,56) 
          STOP 'Abnormal stop: errors found.'
        ENDIF
C       Get the optional file name.  If nothing found, NXTNAM is
C       returned with blanks.  
        CALL NXTTOK
     I             (LINE,
     M              NXT,
     O              NXTNAM)

        IF(NXT.GT.0) THEN
C         Check if a comment was found.
          IF(NXTNAM(1:1).EQ.'''') THEN
C           Clear the the value
            NXTNAM = ' '
          ENDIF
        ENDIF 
        IF(NXTNAM.EQ.' ') THEN
          IF(TABID(1:1).EQ.'-') THEN
C           Signal end of the Function-Table Block
            TABLE = -1
          ELSE
C           Convert TABID to an internal number
            CALL GET_INTERNAL_TAB_NUMBER
     I                                  (STDOUT, TABID,
     M                                   EFLAG,
     O                                   TABLE)
          ENDIF
        ELSE
C         Signal another file name to process
          TABLE = -15
          TABID = ' '
        ENDIF  
      ENDIF     
      RETURN
      END      
      
C
C
C
      SUBROUTINE   FTABIN
     I                   (IN, INA, STDOUT, OUTPUT, FTP, MFT, MLFT, 
     I                    HSLOT,
     M                    EFLAG, FTKNT, FTPNT,
     O                    TABLE, NXTNAM)
 
C     + + + PURPOSE + + +
C     Input function tables.
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, FTKNT, FTP, IN, INA, STDOUT, MFT, MLFT, OUTPUT,
     A        TABLE
      INTEGER FTPNT(MFT)
      REAL HSLOT
      CHARACTER NXTNAM*128
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     INA    - unit number for the user input file
C     STDOUT   - Fortran unit number for user output and messages
C     OUTPUT - output level for diagnostic work
C     FTP    - next open location in the function table storage
C     MFT    - maximum function table pointer value.  Same as maximum
C               function table number
C     MLFT   - maximum length of FTAB/ITAB
C     HSLOT  - height of bottom slot.  Currently 0.0 always
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     FTKNT  - function table counter
C     FTPNT  - function table pointer giving the table address for each
C              table number.  If the address is zero the table does not
C              exist.
C     TABLE  - table number
C     NXTNAM - next file name for function table input

 
C     + + + LOCAL PARAMETERS + + +
      INTEGER MAXOUT, MAXTYP
      PARAMETER(MAXTYP=35, MAXOUT=18)
 
C     + + + SAVED VALUES + + +
      INTEGER OUTTYP(MAXOUT), VTYPE(MAXTYP)
      SAVE OUTTYP, VTYPE
 
C     + + + LOCAL VARIABLES + + +
      INTEGER IT, TYPE
      REAL HDATUM
      CHARACTER CHR69*69, LINE*196, TABID*16, GARBAGE*1
 
C     + + + INTRINSICS + + +
      INTRINSIC IABS
 
C     + + + EXTERNAL NAMES + + +
      INTEGER LENSTR
      EXTERNAL ATABIN, INL80, KIL, STRIP_L_BLANKS, TWODIN, TY15IN, 
     A         XSECIN, GET_INTERNAL_TAB_NUMBER, LENSTR, GET_NEXT_TABID,
     B         INL196, CLEAR_HOME
 
C     + + + DATA INITIALIZATIONS + + +
      DATA VTYPE/0,3*1,0, 4*1, 1, 1, 0,2*1,1,4*0,6*1,   10*0/
      DATA OUTTYP/2,3,4,6,7,8,9,10,11,13,14,15,20,21,22,23,24,25/
 
C     + + + INPUT FORMATS + + +
 2    FORMAT(5X,I5,1X,A69)
C 37   FORMAT(7X,A16,A)
 
C     + + + OUTPUT FORMATS + + +
 38   FORMAT(/,' Table Id= ',A,' Internal number=',I6)
 39   FORMAT(/,' Table Id= ',A,'  Internal number=',I6,'  Type=',I5)
 40   FORMAT(/,' Table Id= ',A,'  Internal number=',I6,'  Type=',I5,
     A       '  Hdatum=',F10.3)
 50   FORMAT(/,' Next function-table file name= ',A)
 51   FORMAT(/,' *ERR:175* Table type=',I3,' unimplemented in FTABIN.',
     A       /,10X,' Valid types are:',25I3)
 52   FORMAT(/,' Cannot continue with invalid table types.')
53    FORMAT(/,' *ERR:366* Expected to find: TABLE#, TABID, FILE,'
     A         ' or HOME but found',
     A       /,5X, A20,' instead.  Check for invalid end in the',
     B       ' current function table.')
54    FORMAT(/' HOME name changed to:',A)
C***********************************************************************
C     Set the garbage character that seems to appear at the end of 
C     ASCII files for currently unknown reasons. 
      GARBAGE = CHAR(26)      
C     DEFINITION OF CONTENTS OF VTYPE
C     CURRENTLY VALID TABLE TYPES HAVE A VALUE OF
C     1 IN VTYPE(ABS(TYPE))
C                                                20
C                                                21
C                         6                  16  22
C                    2    7                  17  23
C                    3    8            13    18  24
C                1   4 5  9   10 11 12 14 15 19  25    26-35
C     DATA VTYPE/0,3*1,0, 4*1, 1, 1, 0,2*1,1,4*0,6*1,   10*0/
 
 1000 CONTINUE
        CALL INL196
     I            (IN, STDOUT,
     O             LINE)
        CALL STRIP_L_BLANKS(
     M                      LINE)
        IF(LINE(1:1).EQ.GARBAGE) THEN
          LINE = 'ENDFILE'
        ENDIF
        IF(LINE(1:7).EQ.'ENDFILE') GOTO 3000
        IF(LINE(1:6).NE.'TABLE#'.AND.LINE(1:5).NE.'TABID'.AND.
     A     LINE(1:4).NE.'FILE'.AND.LINE(1:4).NE.'File'.AND.
     B     LINE(1:4).NE.'HOME'.AND.LINE(1:4).NE.'Home') THEN
          WRITE(STDOUT,53) LINE(1:20)
          STOP 'Abnormal stop: errors found.'
        ENDIF
        CALL GET_NEXT_TABID
     I                     (STDOUT, LINE,
     O                      EFLAG, TABID, TABLE, NXTNAM)
        

        IF(TABLE.LT.0) GOTO 2000
        FTKNT = FTKNT+1
C        WRITE(STDOUT,38) TABID(1:LENSTR(TABID)), TABLE
 
C       STORE THE TABLE POINTER
 
        IF(FTPNT(TABLE).EQ.0) GOTO 300
C          ERROR-DUPLICATE TABLE NUMBER
           CALL KIL
     I              (25,
     M               TABLE, EFLAG)
 300    CONTINUE
        FTPNT(TABLE) = FTP
 
        CALL INL196
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,2,ERR=991) TYPE, CHR69
 
C       CATCH OLD USES OF TYPE 1 AND 12
        IF(TYPE.EQ.1) THEN
          TYPE = 21
        ELSEIF(TYPE.EQ.12) THEN
          TYPE = 22
        ELSEIF(TYPE.EQ.-1) THEN
          TYPE = -21
        ELSEIF(TYPE.EQ.-12) THEN
          TYPE= -22
        ENDIF
        IF(CHR69(1:6).NE.'HDATUM') THEN
          WRITE(STDOUT,39) TABID(1:LENSTR(TABID)), TABLE, TYPE
          HDATUM = -9999.0
        ELSE
          READ(CHR69(8:17),'(F10.0)',ERR=991) HDATUM
          WRITE(STDOUT, 40) TABID(1:LENSTR(TABID)), TABLE, TYPE, HDATUM
          IF(TYPE.EQ.14.OR.TYPE.EQ.-14) THEN
C           Bring possible WSPRO source flag to head of string
            CHR69(1:17) = ' '
            CALL STRIP_L_BLANKS(
     M                          CHR69)
C            WRITE(STDOUT,*) ' FTABIN: CHR69=',CHR69(1:5)
          ELSE  
            CHR69 = ' '
          ENDIF
        ENDIF
        IT = IABS(TYPE)
        IF(VTYPE(IT).EQ.0) THEN
C         UNSUPPORTED TYPE FOUND.  CANNOT CONTINUE WITH PROCESSING
          WRITE(STDOUT,51) TYPE, OUTTYP
          WRITE(STDOUT,52)
          STOP 'Abnormal stop: errors found.'
        ENDIF
 
        GOTO(110,102,102,102,105,106,102,102,102,106,102,110,
     A       106,106, 107, 110, 110, 110, 110, 101,
     B        101,101,101,101,101),IT
          WRITE(STDOUT,*) ' *BUG:14* INVALID TABLE TYPE IN FTABIN.',
     A                    ' TYPE=', IT
          STOP 'Abnormal stop: errors found.'
 
 101    CONTINUE
C          CROSS-SECTION TABLE HERE
           IF(HSLOT.EQ.0.0) THEN
             CALL XSECIN
     I                  (IN, STDOUT, MLFT, TABLE, OUTPUT,
     M                   EFLAG, FTP, TYPE)
           ELSE
             WRITE(STDOUT,*) ' AUTOMATIC SLOT ADDITION NO LONGER ',
     A                  'SUPPORTED'
             STOP 'Abnormal stop: errors found.'
           ENDIF
 
           GOTO 1500
 102    CONTINUE
C          ARBITRARY INTERVAL FUNCTION TABLE
           CALL ATABIN
     I                (IN, STDOUT, MLFT, TABLE,
     M                 EFLAG, FTP, TYPE)
           GOTO 1500
 
 105    CONTINUE
           WRITE(STDOUT,*) ' *BUG:XXX* TABLE TYPE 5 NOT SUPPORTED.'
           STOP 'Abnormal stop: errors found.'
 
 106    CONTINUE
C          TWO-D TABLE INPUT
           CALL TWODIN
     I                (IN, STDOUT, MLFT, TABLE, HDATUM, CHR69,
     M                 EFLAG, FTP, TYPE)
           GOTO 1500
 107    CONTINUE
C          Simple 3-D table via table type 15
           CALL TY15IN
     I                (IN, STDOUT, MLFT, TABLE,
     M                 EFLAG, FTP, TYPE)
           GOTO 1500
 110    CONTINUE
C          UNIMPLEMENTED TABLE TYPES
 
           WRITE(STDOUT,*) ' *BUG:14* INVALID TABLE TYPE IN FTABIN.',
     A            ' TYPE=', IT
           STOP 'Abnormal stop: errors found.'
 
 1500   CONTINUE
           GOTO 1000
 2000 CONTINUE
      IF(NXTNAM.NE.' ') THEN
        IF(TABLE.EQ.-15) THEN
          WRITE(STDOUT,50) NXTNAM(1:LENSTR(NXTNAM))
        ELSEIF(TABLE.EQ.-16) THEN
          WRITE(STDOUT,54) NXTNAM(1:LENSTR(NXTNAM))
        ENDIF
      ENDIF
      RETURN
 3000 CONTINUE
C     READ THE NEXT TABLE VALUE FROM INA
      CALL INL196
     I          (INA, STDOUT,
     O           LINE)
C      READ(LINE,37,ERR=991) TABID, NXTNAM
      CALL GET_NEXT_TABID
     I                   (STDOUT, LINE,
     O                    EFLAG, TABID, TABLE, NXTNAM)

      IF(TABLE.GT.0) THEN
        WRITE(STDOUT,*) ' *ERR:131* INVALID USE OF AUXILIARY TABLE',
     A                  ' FILES'
        WRITE(STDOUT,*) '  FEQIN TABLE INPUT MUST BE COMPLETE BEFORE'
        WRITE(STDOUT,*) '  USING AUXILIARY FILES.'
        STOP 'Abnormal stop: errors found.'
      ENDIF
      IF(NXTNAM.NE.' ') THEN
        IF(TABLE.EQ.-15) THEN
          WRITE(STDOUT,50) NXTNAM(1:LENSTR(NXTNAM))
        ELSEIF(TABLE.EQ.-16) THEN
          WRITE(STDOUT,54) NXTNAM(1:LENSTR(NXTNAM))
        ENDIF
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
      INTEGER FUNCTION   GETTBN
     I                         (ADRS)
 
C     + + + PURPOSE + + +
C     Get the table number of the table at ADRS.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
C***********************************************************************
      GETTBN = ITAB(ADRS+1)
      RETURN
      END
C
C
C
      REAL FUNCTION GET_SLOT_DEPTH
     I                            (ADRS)
 
C     + + + PURPOSE + + +
C     Get the slot depth of the cross-section function table at ADRS.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the cross-section function table in FTAB/ITAB
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
C***********************************************************************
      GET_SLOT_DEPTH = FTAB(ADRS+7)
      RETURN
      END
C
C
C
      SUBROUTINE   INTERP
     I                   (STDOUT, TABL, TABR, XL, XR, N, NBN, NIN, MLFT,
     I                    X, Z, TAB, NODE, SFAC,
     I                    YSLOT_LEFT, YSLOT_RIGHT,
     M                    EFLAG, FTP,
     O                    NSEC)
 
C     + + + PURPOSE + + +
C     Interpolate at one or more points between left hand section at
C     XL with elements stored at TABL and right hand section at
C     XR with elements stored at TABR.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, FTP, STDOUT, MLFT, N, NBN, NIN, TABL, TABR
      INTEGER NODE(NIN), NSEC(NBN), TAB(NIN)
      REAL SFAC, X(NIN), XL, XR, Z(NIN), YSLOT_LEFT(N),
     A     YSLOT_RIGHT(N)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     TABL   - address of the cross section table on the left
C     TABR   - address of the cross section table on the right
C     XL     - station of known section on the left
C     XR     - station of known section on the right
C     N      - number of depth values for the interpolated cross section
C               tables
C     NBN    - total number on nodes on branches in the model
C     NIN    - number of interpolated sections
C              
C     MLFT   - maximum length of FTAB/ITAB
C     X      - stations for interpolated cross sections
C     YSLOT_LEFT - depth valuse to use for the left-hand section
C     YSLOT_RIGHT- depth values to use for the right-hand section
C     Z      - bottom elevations for interpolated cross sections
C     TAB    - table number
C     NODE   - node number
C     SFAC   - conversion factor from user stations to internal stations
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     FTP    - next open location in the function table storage
C     NSEC   - number and also address of cross section table at a node
C               on a branch
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'offcom.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER JID(25), NEWTYP(6,6), QCID(25)
      SAVE JID, NEWTYP, QCID
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, IJ, ISP, ISR, IT, J, TYPE, TYPEL, TYPER, XOFF
      INTEGER IP(MNMID)
      REAL A, AL, ALP, ALPL, ALPR, AR, B, BL, BR, DALPL, DALPR, DBL,
     A     DBR, DKL, DKR, DMAL, DMAR, DMQL, DMQR, DTL, DTR, DX, FAC, H,
     B     K, KL, KR, MA, MAL, MAR, MQ, MQL, MQR, QC, QCL, QCR, T, TL,
     C     TR, XM, YAL, YAR, YB, YBL, YBR, YMAX, SDL, SDR
 
      REAL*8 EASTL, EASTR, NORTHL, NORTHR, EAST, NORTH

      CHARACTER INTERNAL_TABID*16

C     + + + INTRINSICS + + +
      INTRINSIC MIN, SQRT
 
C     + + + EXTERNAL FUNCTIONS + + +
      REAL GET_SLOT_DEPTH
      REAL*8 GET_DP_FROM_FT
      CHARACTER*16 GET_TABID
      INTEGER GETTBN
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETTBN, KIL, XLKT20, XLKT21, XLKT22, XLKT23, XLKT24,
     A         XLKT25, PUT_DP_IN_FT, PUT_STRING_IN_FT,
     B         GET_TABID, GET_SLOT_DEPTH, GET_DP_FROM_FT
 
C     + + + DATA INITIALIZATIONS + + +
      DATA NEWTYP/20, 20, 20, 20, 20, 20,
     A            20, 21, 21, 23, 21, 21,
     B            20, 21, 22, 20, 21, 22,
     C            20, 23, 20, 23, 23, 23,
     D            20, 21, 21, 23, 24, 24,
     E            20, 21, 22, 23, 24, 25/
      DATA  JID/20*0, 1 ,1, 0, 1 ,1/
      DATA QCID/21*0, 1, 0, 0, 1/
 
C     + + + OUTPUT FORMATS + + +
 51   FORMAT(/,' *BUG:XXX* Right hand table type=',I5,' invalid in',
     A      ' subroutine INTERP.')
 52   FORMAT(/,' *BUG:XXX* Left hand table type=',I5,' invalid in',
     A      ' subroutine INTERP.')
 2000 FORMAT(' *ERR:86* INVALID CROSS-SECTION INTERPOLATION REQUEST',
     1   ' XL = ',F10.3,' XM = ',F10.3,' XR = ',F10.3,/,
     2   11X,' UPS TABID=',A,' DNS TABID=',A)
C***********************************************************************
      TYPEL = ITAB(TABL+2)
      TYPER = ITAB(TABR+2)
      SDL = GET_SLOT_DEPTH(TABL)
      SDR = GET_SLOT_DEPTH(TABR)
      EASTL = GET_DP_FROM_FT(TABL+8)
      NORTHL = GET_DP_FROM_FT(TABL+10)
      EASTR = GET_DP_FROM_FT(TABR+8)
      NORTHR = GET_DP_FROM_FT(TABR+10)

C      XOFFL = OFFVEC(TYPEL)
C      XOFFR = OFFVEC(TYPER)
 
      IF(TYPEL.LT.20.OR.TYPEL.GT.25) THEN
        WRITE(STDOUT,51) TYPEL
        STOP 'Abnormal stop: errors found.'
      ENDIF
      IF(TYPER.LT.20.OR.TYPER.GT.25) THEN
        WRITE(STDOUT,52) TYPER
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
C     SET THE TYPE OF THE TABLE THAT CAN BE INTERPOLATED BETWEEN THE
C     TWO GIVEN TABLES.
      TYPE = NEWTYP(TYPEL-19,TYPER-19)
 
      XOFF = OFFVEC(TYPE)
 
C     SET MAXIMUM ARGUMENT FOR TABLES AS IF THEY HAD NOT BEEN
C     EXTRAPOLATED VERTICALLY.  YMAX GIVES THE MAXIMUM DEPTH
C     DEFINED BY THE CROSS SECTION MEASUREMENTS.
 
      YMAX = MIN(FTAB(TABL+6), FTAB(TABR+6))
 
C     CHECK SPACE LEFT IN FTAB.
C     NIN = NUMBER OF INTERPOLATED SECTIONS AND N = NUMBER OF DEPTH
C     LEVELS IN EACH TABLE.  ALL TABLES WILL HAVE SAME NUMBER OF
C     DEPTH VALUES. XOFF IS NUMBER OF ENTRIES PER ROW.
C     XTIOFF GIVES THE NUMBER OF ITEMS IN THE HEADING OF THE TABLE.
 
      ISR = NIN*(XTIOFF + N*XOFF)
      IF((FTP+ISR).GE.MLFT) CALL KIL
     I                               (10,
     M                                FTP, EFLAG)
 
C     SET UP POINTERS SO THAT EACH TABLE CAN BE CONSTRUCTED AT EACH
C     DEPTH LEVEL.  ISP = SPACE REQUIRED FOR EACH TABLE
 
      ISP = XTIOFF + N*XOFF
        DO 100 I=1,NIN
        IP(I) = FTP
        FTP = FTP + ISP
  100   CONTINUE
 
C     CHECK FOR VALIDITY OF INTERPOLATION REQUEST
 
      DO 110 I=1,NIN
        XM = X(I)
        IF((XL.LT.XM.AND.XM.LT.XR).OR.(XR.LT.XM.AND.XM.LT.XL)) GOTO 110
        EFLAG = 1
        WRITE(STDOUT,2000) XL/SFAC, XM/SFAC, XR/SFAC, 
     A                    GET_TABID(GETTBN(TABL)),
     A                    GET_TABID(GETTBN(TABR))
 110  CONTINUE
 
 
C    STORE HEADINGS AND ESTABLISH ADDRESSES FOR ALL THE INTERMEDIATE
C     TABLES
 
      DX = XR - XL
      DO 150 J=1,NIN
        IT = IP(J)
        ITAB(IT) = IT + ISP - XOFF
        ITAB(IT+1) = TAB(J)
        ITAB(IT+2) = TYPE
        ITAB(IT+3) = IT + XTIOFF
        FTAB(IT+4) = X(J)/SFAC
        FTAB(IT+5) = Z(J)
        FTAB(IT+6) = YMAX

C       Set the slot depth for the interpolated sections.
        H = X(J) - XL
        FAC = H/DX
        FTAB(IT+7) = SDL + FAC*(SDR - SDL)

C       Set the Easting value as well
        EAST = EASTL + FAC*(EASTR - EASTL)
        
C       Set the Northing value as well
        NORTH = NORTHL + FAC*(NORTHR - NORTHL)

        CALL PUT_DP_IN_FT(IT+8, EAST)
        CALL PUT_DP_IN_FT(IT+10, NORTH)
        
        CALL PUT_STRING_IN_FT(IT+12, 'Interpolated    ')
        INTERNAL_TABID = GET_TABID(TAB(J))
        CALL PUT_STRING_IN_FT(IT+16, INTERNAL_TABID)

C       Set source flag to interpolated 
        ITAB(IT+20) = 1

        IJ = TAB(J)
        IF(FTPNT(IJ).EQ.0) GOTO 120
C         ERROR-DUPLICATE INTERPOLATION TABLE NUMBER
          CALL KIL
     I             (25,
     M              IJ, EFLAG)
 120    CONTINUE

C       Treat all tables as if they could be referenced with
C       their internal table number or tabid.  Will not happen
C       but is needed to avoid confusion of internal table
C       numbers in FEQUTL. 
        FTPNT(TAB(J)) = IT
        NSEC(NODE(J)) = IT
 
C       POINT TO LOCATION OF FIRST DEPTH VALUE
        IP(J) = IT + XTIOFF
 150  CONTINUE
 
C     NOW INTERPOLATE FOR THE BODY OF THE TABLES
 
      DO 200 I=1,N
        YAL = YSLOT_LEFT(I)
        YAR = YSLOT_RIGHT(I)
 
C       FIND THE ELEMENTS ON THE RIGHT AND LEFT.  LOOKUP ROUTINE
C       IS BASED ON THE TABLE TYPE AT THAT LOCATION.
 
        GOTO(20, 21, 22, 23, 24, 25), TYPEL-19
 
 20     CONTINUE
          CALL XLKT20
     I               (TABL,
     M                YAL,
     O                AL, TL, DTL, KL, DKL, BL, DBL)
          GOTO 30
 21     CONTINUE
          CALL XLKT21
     I               (TABL,
     M                YAL,
     O                AL, TL, DTL, YBL, KL, DKL, BL, DBL)
          GOTO 30
 22     CONTINUE
          CALL XLKT22
     I               (TABL,
     M                YAL,
     O                AL, TL, DTL, YBL, KL, DKL, BL, DBL, ALPL, DALPL,
     O                QCL)
          GOTO 30
 23     CONTINUE
          CALL XLKT23
     I               (TABL,
     M                YAL,
     O                AL, TL, DTL, KL, DKL, BL, DBL, MAL, DMAL, MQL,
     O                DMQL)
          GOTO 30
 24     CONTINUE
          CALL XLKT24
     I               (TABL,
     M                YAL,
     O                AL, TL, DTL, YBL, KL, DKL, BL, DBL, MAL, DMAL,
     O                MQL, DMQL)
          GOTO 30
 25     CONTINUE
          CALL XLKT25
     I               (TABL,
     M                YAL,
     O                AL, TL, DTL, YBL, KL, DKL, BL, DBL, ALPL, DALPL,
     O                QCL, MAL, DMAL, MQL, DMQL)
          GOTO  30
 30     CONTINUE
 
        GOTO(40, 41, 42, 43, 44, 45), TYPER-19
 
 40     CONTINUE
          CALL XLKT20
     I               (TABR,
     M                YAR,
     O                AR, TR, DTR, KR, DKR, BR, DBR)
          GOTO 50
 41     CONTINUE
          CALL XLKT21
     I               (TABR,
     M                YAR,
     O                AR, TR, DTR, YBR, KR, DKR, BR, DBR)
          GOTO 50
 42     CONTINUE
          CALL XLKT22
     I               (TABR,
     M                YAR,
     O                AR, TR, DTR, YBR, KR, DKR, BR, DBR, ALPR, DALPR,
     O                QCR)
          GOTO 50
 43     CONTINUE
          CALL XLKT23
     I               (TABR,
     M                YAR,
     O                AR, TR, DTR, KR, DKR, BR, DBR, MAR, DMAR, MQR,
     O                DMQR)
          GOTO 50
 44     CONTINUE
          CALL XLKT24
     I               (TABR,
     M                YAR,
     O                AR, TR, DTR, YBR, KR, DKR, BR, DBR, MAR, DMAR,
     O                MQR, DMQR)
          GOTO 50
 45     CONTINUE
          CALL XLKT25
     I               (TABR,
     M                YAR,
     O                AR, TR, DTR, YBR, KR, DKR, BR, DBR, ALPR, DALPR,
     O                QCR, MAR, DMAR, MQR, DMQR)
          GOTO 50
 50     CONTINUE
 
        KL = SQRT(KL)
        KR = SQRT(KR)
        DO 160 J=1,NIN
          IT = IP(J)
          H = X(J) - XL
          FAC = H/DX
 
C         DO THE CORE ELEMENTS THAT ARE COMMON TO ALL TABLES AND
C         STORE THEM.
          T = TL + FAC*(TR - TL)
          A = AL + FAC*(AR - AL)
          K = KL + FAC*(KR - KL)
          B = BL + FAC*(BR - BL)
          FTAB(IT) = YAL + FAC*(YAR - YAL)
          FTAB(IT+1) = T
          FTAB(IT+2) = A
          FTAB(IT+3) = K
          FTAB(IT+4) = B
 
C         THE CORE SET HAS BEEN DONE.  NOW DO THE TABLES THAT CONTAIN
C         ADDITIONAL ELEMENTS
 
          IF(JID(TYPE).EQ.1) THEN
C           FIRST MOMENT EXISTS IN THESE TABLES.
            YB = YBL + FAC*(YBR - YBL)
            FTAB(IT+5) = YB
          ENDIF
 
          IF(QCID(TYPE).EQ.1) THEN
C           ALP AND QC EXISTS IN THESE TABLES.
            ALP = ALPL + FAC*(ALPR - ALPL)
            QC = QCL + FAC*(QCR - QCL)
            FTAB(IT+6) = ALP
            FTAB(IT+7) = QC
          ENDIF
 
          IF(TYPE.GE.23) THEN
C           WE HAVE THE WEIGHT COEFFICIENTS TO INTERPOLATE.
 
            MA = MAL + FAC*(MAR - MAL)
            MQ = MQL + FAC*(MQR - MQL)
 
            IF(TYPE.EQ.23) THEN
              FTAB(IT+5) = MA
              FTAB(IT+6) = MQ
            ELSEIF(TYPE.EQ.24) THEN
              FTAB(IT+6) = MA
              FTAB(IT+7) = MQ
            ELSEIF(TYPE.EQ.25) THEN
              FTAB(IT+8) = MA
              FTAB(IT+9) = MQ
            ENDIF
          ENDIF
 
          IP(J) = IP(J) + XOFF
 
  160   CONTINUE
  200 CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE   KIL
     I                 (ICODE,
     M                  N, IFLAG)
 
C     + + + PURPOSE + + +
C     Prints out error messages and sets a flag
C     and adjusts the value of N
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ICODE, IFLAG, N
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ICODE  - code number for the error message to output
C     N      - reference value to report and adjust
C     IFLAG  - error flag
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'xscom.cmn'
 
C     Called program units
      CHARACTER GET_TABID*16
      EXTERNAL GET_TABID

C     + + + SAVED VALUES + + +
      CHARACTER MESG(51)*72
      SAVE MESG
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS
 
C     + + + DATA INITIALIZATIONS + + +
      DATA MESG(1)/' Branch number out of range'/
      DATA MESG(2)/' Node on a branch outside valid range'/
      DATA MESG(3 )/' Node on a branch out of sequence or a duplicate'/
      DATA MESG(4 )/' Upstream exterior node number out of range'/
      DATA MESG(5 )/' Downstream exterior node number out of range'/
      DATA MESG(6 )/' AVAILABLE MESSAGE '/
      DATA MESG(7 )/' Invalid device type for a control structure'/
      DATA MESG(8 )/' Message available'/
      DATA MESG(9 )/' Internal table number out of valid range'/
      DATA MESG(10)/' Function table space exceeded'/
      DATA MESG(11)/' Invalid code for Network Matrix Control'/
      DATA MESG(12)/' AVAILABLE MESSAGE'/
      DATA MESG(13)/' Network Matrix Control space exceeded'/
      DATA MESG(14)/' Number of nodes at a junction > 9 or < 2'/
      DATA MESG(15)/' Unknown branch number in Ntwrk Mtrx Cntrl input'/
      DATA MESG(16)/' Type must be 1,or 2 for a forced boundary'/
      DATA MESG(17)/' Number of reservoir inflow nodes must be 1'/
      DATA MESG(18)/' Type for point flows > 2 or < 1'/
      DATA MESG(19)/' Too many point flows given'/
      DATA MESG(20)/' MESSAGE AVAILABLE'/
      DATA MESG(21)/' Message available'/
      DATA MESG(22)/' The nodes for head must be distinct'/
      DATA MESG(23)
     A/' The node for flow must equal one of the head nodes'/
      DATA MESG(24)/' Reservoir node duplicates an existing node'/
      DATA MESG(25)/' Duplicate function table id'/
      DATA MESG(26)/' Message available'/
      DATA MESG(27)/' Too many nodes'/
      DATA MESG(28)/' Point flow invalid for upstream node'/
      DATA MESG(29)/' Too many branches'/
      DATA MESG(30)/' Too many exterior nodes'/
      DATA MESG(31)/' Invalid operation block number in CHKEX'/
      DATA MESG(32)
     A/' Level pool reservoir inflow node is not free or is in use elsew
     Bhere.'/
      DATA MESG(33)
     A/' Free node on a dummy branch is not free or is in use elsewhere.
     B'/
      DATA MESG(34)/'AVAILABLE MESSAGE'/
      DATA MESG(35)/' Invalid print out option'/
      DATA MESG(36)/' Point flows no longer supported'/
      DATA MESG(37)/' Invalid option for diffuse flows'/
      DATA MESG(38)/' Invalid option for wind loading'/
      DATA MESG(39)/' Message available'/
      DATA MESG(40)/' Message available'/
      DATA MESG(41)/' Special Operation Block number out of range'/
      DATA MESG(42)/' Invalid option for Special Operation Block'/
      DATA MESG(43)
     A/' Exterior node used as a flow node more than once'/
      DATA MESG(44)/' Exterior node appears on more than one branch'/
      DATA MESG(45)
     A/' Invalid slope source for channel control:-1,0,1, are valid'/
      DATA MESG(46)
     A/' This node matches another when nodes must be distinct.'/
      DATA MESG(47)/'Message available'/
      DATA MESG(48)/'Message available'/
      DATA MESG(49) /' Message available'/
      DATA MESG(50) /' Invalid direction: 1 or -1 are valid.'/
      DATA MESG(51) 
     A/' Branch has already appeared in Ntwrk Mtrx Cntrl input.'/
 
C     + + + OUTPUT FORMATS + + +
10000 FORMAT('0','*ERR:',I2,'*')
10100 FORMAT(' REFERENCE VALUE= ',I10)
10102 FORMAT(' Table id= ',A)
10200 FORMAT(A)
10300 FORMAT(/,' PREVIOUS ERROR FORCES CESSATION OF PROCESSING.')
C***********************************************************************
C     NOTE: DO NOT USE ICODE GREATER THAN 60 FOR SUBROUTINE
C     KIL. OTHERWISE DUPLICATE NUMBERS WILL APPEAR FOR ERROR
C     MESSAGES.
 
      WRITE(STDOUT,10000) ABS(ICODE)
 
      IFLAG = IFLAG+1
      IF(ABS(ICODE).EQ.25) THEN
        WRITE(STDOUT,10102) GET_TABID(N)
      ELSE
        WRITE(STDOUT,10100) N
      ENDIF
      N = 1
 
      IF(ICODE.LT.0.OR.ICODE.GT.51) THEN
        WRITE(STDOUT,*) ' *BUG:01* INVALID ICODE IN KIL. CODE=',ICODE
        STOP 'Abnormal stop: errors found.'
      ENDIF
      WRITE(STDOUT,10200) MESG(ICODE)
      IF(ICODE.EQ.10.OR.ICODE.EQ.13) THEN
        WRITE(STDOUT,10300)
        STOP 'Abnormal stop: errors found.'
      ENDIF
      RETURN
      END
C
C
C
      SUBROUTINE   LKTAB
     I                  (ADRS, ARGA, SKLT,
     O                   FUNC, NTAB, PDV)
 
C     + + + PURPOSE + + +
C     Do function table look up for all but cross-section tables
C     and two-d tables.

      IMPLICIT NONE 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS, NTAB, SKLT
      REAL ARGA, FUNC, PDV
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB
C     ARGA   - argument for finding values in a function table
C     SKLT   - flag for skipping the lower bound test on table lookup
C     FUNC   - value of function found at ARGA
C     NTAB   - table number
C     PDV    - partial derivative value
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'xscom.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER STEP(5)
      SAVE STEP
 
C     + + + LOCAL VARIABLES + + +
      INTEGER HA, INC, LA, LSTA, TYPE
      REAL A2, A3, ADIFF, AONE, ARG, ARG2, AZERO, DF, FACT, FONE, FPONE,
     A     FPZERO, FZERO, H, P, PH, SHIFT
 
C     + + + INTRINSICS + + +
      INTRINSIC EXP, LOG
 

C     Called subprograms
      CHARACTER*16 GET_TABID
      EXTERNAL GET_TABID
      
C     + + + DATA INITIALIZATIONS + + +
      DATA STEP/0,2,3,3,3/
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,'*BUG:XXX* Invalid TYPE=',I5,' in LKTAB for TABID=',A)
 2000 FORMAT('0','*ERR:70* Argument below range in LKTAB',
     A       /,1X,' Table Id   = ',A,
     B       /,1X,' Time           = ',F14.0,
     C       /,1X,' Arguument      = ',F10.4)
 2010 FORMAT('0','*ERR:71* Argument above range in LKTAB',
     A       /,1X,' Table Id   = ',A,
     B       /,1X,' Time           = ',F14.0,
     C       /,1X,' Argument       = ',F10.4)
C***********************************************************************
C     HA = HIGH ADDRESS
C     LA = LOW ADDRESS
C     ITAB(ADRS+1) = TABLE NUMBER
C     LSTA = LAST ADDRESS
 
      HA = ITAB(ADRS)
      LA = ADRS + 5
      LSTA = ITAB(ADRS+3)
      TYPE = ITAB(ADRS+2)
      NTAB = ITAB(ADRS+1)
      SHIFT = FTAB(ADRS+4)
      ARG = ARGA + SHIFT
      ARG = ARGA
      IF(TYPE.GT.4) THEN
        INC = 3
      ELSE
        INC = STEP(TYPE)
      ENDIF
 
      IF(TYPE.EQ.5) THEN
        ARG2 = ARG
        ARG = LOG(ARG)
      ENDIF
 
C     INITIALIZE
 
      ADIFF = ARG - FTAB(LSTA)
      IF(ADIFF) 100,300,200
 
C     ARGUMENT PASSED LESS THAN AT PREVIOUS ACCESS TO TABLE
 
 100  IF( LSTA.GE.LA ) GOTO 110
      IF(SKLT.EQ.0) GOTO 105
 
C     SKIP LOWER BOUND TEST
 
      LSTA = LSTA + INC
      ARG = FTAB(LSTA)
      GOTO 300
 
 105  WRITE(STDOUT,2000) GET_TABID(ITAB(ADRS+1)), TIME, ARG
      EFLAG = 1
      STOP 'Abnormal stop: errors found.'
C      RETURN
 
 110  IF( ARG.GE.FTAB(LSTA) ) GOTO 300
      LSTA = LSTA - INC
      GOTO 100
 
C     ARGUMENT PASSED GREATER THAN AT PREVIOUS ACCESS TO TABLE
 
 200  IF( LSTA.LT.HA ) GOTO 210
      WRITE(STDOUT,2010) GET_TABID(ITAB(ADRS+1)), TIME, ARG
      EFLAG = 1
      LSTA = HA - INC
      ARG = FTAB(HA)
      GOTO 300
 210  IF( ARG.LE.FTAB(LSTA+INC) ) GOTO 300
      LSTA = LSTA + INC
      GOTO 200
 
 300  CONTINUE
 
      GOTO (1,2,3,4,5,1,1,1,1,1,11), TYPE
 
 1    CONTINUE
        WRITE(STDOUT,50) TYPE, GET_TABID(NTAB)
        STOP 'Abnormal stop: errors found.'
 
 2    CONTINUE
 
C     SINGLE FUNCTION - LINEAR INTERPOLATION
 
C       FETCH VALUES FROM FTAB
 
        AZERO = FTAB(LSTA)
        FZERO = FTAB(LSTA+1)
        AONE = FTAB(LSTA+2)
        FONE = FTAB(LSTA+3)
 
C       INTERPOLATE
 
        FACT = (ARG - AZERO)/(AONE - AZERO)
        FUNC = FZERO + FACT*(FONE - FZERO)
        PDV  = (FONE - FZERO)/(AONE - AZERO)
        GOTO 1000
 
C     Dual value- trapezoidal rule interpolation
 
 3    CONTINUE
 
C       FETCH VALUES
        AZERO = FTAB(LSTA)
        FZERO = FTAB(LSTA+1)
        FPZERO = FTAB(LSTA+2)
        AONE = FTAB(LSTA+3)
        FONE = FTAB(LSTA+4)
        FPONE = FTAB(LSTA+5)
        PH = ARG - AZERO
        H = AONE - AZERO
        P = PH/H
        PDV = FPZERO + P*(FPONE- FPZERO)
        FUNC = FZERO + 0.5*PH*(FPZERO+ PDV)
        GOTO 1000
 
C     HERMITE CUBIC  INTERPOLATION
 
 4    CONTINUE
        AZERO = FTAB(LSTA)
        FZERO = FTAB(LSTA+1)
        FPZERO = FTAB(LSTA+2)
        AONE = FTAB(LSTA+3)
        FONE = FTAB(LSTA+4)
        FPONE = FTAB(LSTA+5)
        PH = ARG - AZERO
        H = AONE - AZERO
        P = PH/H
        DF = FONE - FZERO
        A2 = 3.*DF - H*(FPZERO + FPZERO + FPONE)
        A3 = H*(FPZERO+FPONE) - 2.*DF
        PDV = FPZERO + P*(A2 + A2 + 3.*A3*P)/H
        FUNC = FZERO + PH*FPZERO + P*P*(A2 + P*A3)
        GOTO 1000
 
 
C     Log-log linear
 
 5    CONTINUE
 
C       Special treatment needed if in the first panel of the
C       breakpoint sequence.  We will extrapolate from the second
C       panel because the zero argument point is included implicitly.
 
        IF(LSTA.EQ.LA) THEN
          LSTA = LA + 3
        ENDIF
        AZERO = FTAB(LSTA)
        FZERO = FTAB(LSTA+1)
        FPZERO = FTAB(LSTA+2)
        PH = ARG - AZERO
        FUNC = EXP(FZERO + PH*FPZERO)
        PDV = FUNC*FPZERO/ARG2
        GOTO 1000
 
C     TIME SERIES WITH TWO VALUES PER TIME POINT
 
 11   CONTINUE
        AZERO = FTAB(LSTA)
        FZERO = FTAB(LSTA+1)
        FPZERO = FTAB(LSTA+2)
        AONE = FTAB(LSTA+3)
        FONE = FTAB(LSTA+4)
        FPONE = FTAB(LSTA+5)
        PH = ARG- AZERO
        H = AONE - AZERO
        P = PH/H
 
        FUNC = FZERO + P*(FONE - FZERO)
        PDV = FPZERO + P*(FPONE - FPZERO)
        GOTO 1000
 
 1000 CONTINUE
 
C     RESET POINTER TO LAST ADDRESS
 
      ITAB(ADRS+3) = LSTA
 
 
      RETURN
 
      END
C
C
C
      SUBROUTINE   LSATAB
     I                   (STDOUT, KEY, NMAX,
     M                    TABLE, N,
     O                    INDEX, EFLAG)
 
C     + + + PURPOSE + + +
C     Do a linear search for KEY in the entries in TABLE.  If match
C     is found, return the index of the match, otherwise, add the
C     value to the end of the table, increment N, and return an
C     index of N.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, INDEX, N, NMAX, STDOUT
      CHARACTER*(*) KEY, TABLE(NMAX)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT - standard output unit for user messages
C     KEY    - search value
C     NMAX   - maximum permit extent of the table
C     TABLE  - table of values to be searched
C     N      - number of items in the table
C     INDEX  - index into the table at the match point
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *ERR:651* Too many entries in LSATAB. Number=',I5)
C***********************************************************************
      DO 100 I=1,N
        IF(KEY.EQ.TABLE(I)) THEN
C         FOUND MATCH
          INDEX = I
          RETURN
        ENDIF
 100  CONTINUE
C     MATCH NOT FOUND
      N = N + 1
      IF(N.GT.NMAX) THEN
        WRITE(STDOUT,50) N
        EFLAG = 1
        N = NMAX
      ENDIF
      TABLE(N) = KEY
      INDEX = N
      RETURN
      END
C
C
C
      SUBROUTINE   LSTAB
     I                  (KEY, TABLE, N,
     O                   INDEX)
 
C     + + + PURPOSE + + +
C     Do a linear search for KEY in the entries in TABLE.  If match
C     is found, return the index of the match, otherwise, return
C     a zero value for the index.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER INDEX, N
      CHARACTER*(*) KEY, TABLE(N)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     KEY    - search value
C     TABLE  - table of values to be searched
C     N      - number of items in the table
C     INDEX  - index into the table at the match point
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I
C***********************************************************************
      DO 100 I=1,N
        IF(KEY.EQ.TABLE(I)) THEN
C         FOUND MATCH
          INDEX = I
          RETURN
        ENDIF
 100  CONTINUE
      INDEX = 0
      RETURN
      END
C
C
C
      SUBROUTINE   MERGE
     I                  (STDOUT, TABL, TABR,
     O                   EFLAG, N, Y)
 
C     + + + PURPOSE + + +
C     Compile the list of merged depth values from the left hand
C     section (TABL) and the right hand section(TABR).  place
C     list into Y(*) with N giving the number of depth values in
C     Y(*).  The merged list must contain strictly increasing
C     values of depth-- no duplicate values allowed.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, STDOUT, N, TABL, TABR
      REAL Y(MNDEP)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     TABL   - address of the cross section table on the left
C     TABR   - address of the cross section table on the right
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     N      - number of depth values in final merged list
C     Y      - merged depth values
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'offcom.cmn'
      INCLUDE 'ftable.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADL, ADR, LIST, TYPEL, TYPER, XOFFL, XOFFR
      REAL CRVAL, TVAL, YL, YMAX, YR
 
C     + + + INTRINSICS + + +
      INTRINSIC AMIN1

C     Called program units
      CHARACTER*16 GET_TABID

      EXTERNAL GET_TABID
 
C     + + + OUTPUT FORMATS + + +
 10   FORMAT(' *ERR:87* More than',I5,' depth values between',
     A               ' TABIDS ',A, ' and ',A)
 50   FORMAT(' *BUG:XXX* TYPE=',I5,' INVALID IN TABID=',A,' IN MERGE.')
C***********************************************************************
C     FIND MINIMUM VALUE OF MAXIMUM DEPTH FOR THE TWO SECTIONS
 
      YMAX = AMIN1(FTAB(ITAB(TABL)),FTAB(ITAB(TABR)))
 
C     INITIALIZE ADDRESSES FOR DEPTH VALUE IN FTAB
 
      ADL = TABL + XTIOFF
      ADR = TABR + XTIOFF
 
C     SET THE OFFSETS FOR EACH TABLE
 
      TYPEL = ITAB(TABL+2)
      XOFFL = OFFVEC(TYPEL)
      IF(XOFFL.EQ.0) THEN
        WRITE(STDOUT,50) TYPEL, GET_TABID(ITAB(TABL+1))
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
      TYPER = ITAB(TABR+2)
      XOFFR = OFFVEC(TYPER)
      IF(XOFFR.EQ.0) THEN
        WRITE(STDOUT,50) TYPER, GET_TABID(ITAB(TABR+1))
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
C     COMPILE MERGED LIST OF DEPTH VALUES FROM MINIMUM DEPTH
C     (WHICH MUST BE ZERO FOR BOTH SECTIONS) UNTIL YMAX.
 
      N = 0
 
C     GET NEXT PAIR OF DEPTH VALUES
 
   90 CONTINUE
        YL = FTAB(ADL)
        YR = FTAB(ADR)
        IF(YL.NE.YR) GOTO 100
 
C        EQUALITY. STORE ONE VALUE IN Y
 
         IF(N.LT.MNDEP) GOTO 92
           WRITE(STDOUT,10) MNDEP, GET_TABID(ITAB(TABL+1)),
     A            GET_TABID(ITAB(TABR+1))
           STOP 'Abnormal stop: errors found.'
   92      CONTINUE
         N = N+1
         Y(N) = YL
         IF(YL.EQ.YMAX) RETURN
         ADL = ADL + XOFFL
         ADR = ADR + XOFFR
         GOTO 90
  100   CONTINUE
          IF(YL.LT.YR) GOTO 120
C           YL > YR.  PUT MINIMUM VALUE IN Y AND INITIALIZE CURRENT
C           VALUE, SET SOURCE LIST TO RIGHT HAND SECTION.
 
            LIST = 1
            IF(N.LT.MNDEP) GOTO 102
              WRITE(STDOUT,10) MNDEP, GET_TABID(ITAB(TABL+1)),
     A                         GET_TABID(ITAB(TABR+1))
              EFLAG = 1
              STOP 'Abnormal stop: errors found.'
  102       CONTINUE
            N = N+1
            Y(N) = YR
            CRVAL = YL
            GOTO 130
  120     CONTINUE
C           YL<YR.  PUT MIN VALUE IN Y, INITIALIZE CURRENT VALUE, AND
C           SET SOURCE LIST TO LEFT HAND SECTION.
 
            LIST = -1
            IF(N.LT.MNDEP) GOTO 122
              WRITE(STDOUT,10) MNDEP, GET_TABID(ITAB(TABL+1)), 
     A                         GET_TABID(ITAB(TABR+1))
              EFLAG = 1
              STOP 'Abnormal stop: errors found.'
  122       CONTINUE
            N = N+1
            Y(N) = YL
            CRVAL = YR
  130     CONTINUE
            IF(Y(N).EQ.YMAX) RETURN
 
C             INCREMENT SOURCE LIST POINTER AND GET TEST VALUE THEREFROM
 
              IF(LIST.EQ.-1) GOTO 140
                ADR = ADR + XOFFR
                TVAL = FTAB(ADR)
                GOTO 150
  140         CONTINUE
                ADL = ADL + XOFFL
                TVAL = FTAB(ADL)
  150         CONTINUE
              IF(TVAL.EQ.CRVAL) GOTO 200
                IF(TVAL.GT.CRVAL) GOTO 170
                   IF(N.LT.MNDEP) GOTO 165
                     WRITE(STDOUT,10) MNDEP, GET_TABID(ITAB(TABL+1)), 
     A                               GET_TABID(ITAB(TABR+1))
                     EFLAG = 1
                     STOP 'Abnormal stop: errors found.'
  165              CONTINUE
                   N = N+1
                   Y(N) = TVAL
                   GOTO 130
  170          CONTINUE
                 IF(N.LT.MNDEP) GOTO 175
                   WRITE(STDOUT,10) MNDEP, GET_TABID(ITAB(TABL+1)), 
     A                               GET_TABID(ITAB(TABR+1))
                   EFLAG = 1
                   STOP 'Abnormal stop: errors found.'
  175            CONTINUE
                 N = N+1
                 Y(N) = CRVAL
                 CRVAL = TVAL
                 LIST = -LIST
                 GOTO 130
  200        CONTINUE
                 IF(N.LT.MNDEP) GOTO 205
                   WRITE(STDOUT,10) MNDEP, GET_TABID(ITAB(TABL+1)), 
     A                             GET_TABID(ITAB(TABR+1))
                   EFLAG = 1
                   STOP 'Abnormal stop: errors found.'
  205            CONTINUE
                 N = N+1
                 Y(N) = TVAL
                 ADR = ADR + XOFFR
                 ADL = ADL + XOFFL
                 IF(Y(N).EQ.YMAX) RETURN
                 GOTO 90
      END
C
C
C
      SUBROUTINE   GET_REAL_DEPTHS(STDOUT, ADRS,
     O               SD, N, REAL_DEPTH)

C     Get the sequence of "real" depths from a cross section
C     that may have a slot.  A real depth has a datum at the 
C     invert of the cross section BEFORE any slot was added.

      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'

      INTEGER STDOUT, ADRS, N

      REAL SD, REAL_DEPTH(MNDEP)                

C     + + + COMMON BLOCKS + + +
      INCLUDE 'offcom.cmn'
      INCLUDE 'ftable.cmn'

C     Called program units
      INTEGER GETTBN
      REAL GET_SLOT_DEPTH
      CHARACTER*16 GET_TABID

      EXTERNAL GETTBN, GET_SLOT_DEPTH, GET_TABID

C     Local
      INTEGER I, FIRST, TYPE, OFF, LAST
      
      REAL DEPTH

C     **************************FORMATS*********************************
50    FORMAT(/,' *ERR:406 There are ', I5,' > ',I5,' depth',
     A'         values in TABID=',A)
C***********************************************************************
C     Get the slot depth.  It will be zero or negative.  We want
C     its absolute value in the current context. 
      
      SD = ABS(GET_SLOT_DEPTH(ADRS)) 

C     Get the address of the first depth value in the table.

      FIRST = ADRS + XTIOFF

C     Get the address of the last depth value in the table
      LAST = ITAB(ADRS)
 
C     Find the offset for the depth arguments for this table.  
C     Depends on table type.
 
      TYPE = ITAB(ADRS+2)
      OFF = OFFVEC(TYPE)

C     Outline of method: scan all depths in the table and subtact
C     the slot depth.  If the remaining value is positive, store
C     in the real-depth vector.  Initialize the real-depth vector so that
C     its first element is 0.0. 

      N = 1
      REAL_DEPTH(1) = 0.0
      
      DO 100 I=FIRST,LAST,OFF

        DEPTH = FTAB(I) - SD
        IF(DEPTH.GT.0.0) THEN
          N = N + 1
          IF(N.GT.MNDEP) THEN
            WRITE(STDOUT,50) N, MNDEP, GET_TABID(GETTBN(ADRS))
            STOP 'Abnormal stop. Error(s) found.'
          ENDIF 
          REAL_DEPTH(N) = DEPTH
        ENDIF
100   CONTINUE

      RETURN
      END


C
C
C
      SUBROUTINE   MERGE_WITH_SLOT
     I                  (STDOUT, TABL, TABR,
     O                   EFLAG, N, Y, SDL, SDR)
 
C     + + + PURPOSE + + +
C     Compile the list of merged depth values from the left hand
C     section (TABL) and the right hand section(TABR).  place
C     list into Y(*) with N giving the number of depth values in
C     Y(*).  The merged list must contain strictly increasing
C     values of depth-- no duplicate values allowed.
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, STDOUT, N, TABL, TABR
      REAL SDL, SDR, Y(MNDEP)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     TABL   - address of the cross section table on the left
C     TABR   - address of the cross section table on the right
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     N      - number of depth values in final merged list
C     Y      - merged depth values
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'offcom.cmn'
      INCLUDE 'ftable.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER IL, IR, LIST, NL, NR
      REAL CRVAL, TVAL, YL, YMAX, YR, YLEFT(MNDEP), YRIGHT(MNDEP)
 
C     + + + INTRINSICS + + +
      INTRINSIC AMIN1

C     Called program units
      CHARACTER*16 GET_TABID

      EXTERNAL GET_TABID, GET_REAL_DEPTHS
 
C     + + + OUTPUT FORMATS + + +
 10   FORMAT(' *ERR:87* More than',I5,' depth values between',
     A               ' TABIDS ',A, ' and ',A)
C***********************************************************************
C     Find the tabulated depth sequence for each table with 
C     only depths in the real section, starting at 0.0, being
C     included.
      CALL GET_REAL_DEPTHS(STDOUT, TABL,
     O               SDL, NL, YLEFT)
      CALL GET_REAL_DEPTHS(STDOUT, TABR,
     O               SDR, NR, YRIGHT)

      
C     FIND MINIMUM VALUE OF MAXIMUM DEPTH FOR THE TWO SECTIONS
 
      YMAX = AMIN1(YLEFT(NL), YRIGHT(NR))
 
 
C     COMPILE MERGED LIST OF DEPTH VALUES FROM MINIMUM DEPTH
C     (WHICH MUST BE ZERO FOR BOTH SECTIONS) UNTIL YMAX.
 
      N = 0
      IL = 1
      IR = 1
 
C     GET NEXT PAIR OF DEPTH VALUES
 
   90 CONTINUE
        YL = YLEFT(IL)
        YR = YRIGHT(IR)
        IF(YL.NE.YR) GOTO 100
 
C        EQUALITY. STORE ONE VALUE IN Y
 
         N = N + 1
         IF(N.GT.MNDEP) THEN
           WRITE(STDOUT,10) MNDEP, GET_TABID(ITAB(TABL+1)),
     A            GET_TABID(ITAB(TABR+1))
           STOP 'Abnormal stop: errors found.'
         ENDIF
         Y(N) = YL
         IF(YL.EQ.YMAX) RETURN
         IL = IL + 1
         IR = IR + 1
         GOTO 90
  100   CONTINUE
          IF(YL.LT.YR) GOTO 120
C           YL > YR.  PUT MINIMUM VALUE IN Y AND INITIALIZE CURRENT
C           VALUE, SET SOURCE LIST TO RIGHT HAND SECTION.
 
            LIST = 1
            N = N + 1
            IF(N.GT.MNDEP) THEN
              WRITE(STDOUT,10) MNDEP, GET_TABID(ITAB(TABL+1)),
     A            GET_TABID(ITAB(TABR+1))
              STOP 'Abnormal stop: errors found.'
            ENDIF
            Y(N) = YR
            CRVAL = YL
            GOTO 130
  120     CONTINUE
C           YL<YR.  PUT MIN VALUE IN Y, INITIALIZE CURRENT VALUE, AND
C           SET SOURCE LIST TO LEFT HAND SECTION.
 
            LIST = -1
            N = N + 1
            IF(N.GT.MNDEP) THEN
              WRITE(STDOUT,10) MNDEP, GET_TABID(ITAB(TABL+1)),
     A            GET_TABID(ITAB(TABR+1))
              STOP 'Abnormal stop: errors found.'
            ENDIF
            Y(N) = YL
            CRVAL = YR
  130     CONTINUE
            IF(Y(N).EQ.YMAX) RETURN
 
C             INCREMENT SOURCE LIST POINTER AND GET TEST VALUE THEREFROM
 
              IF(LIST.EQ.-1) GOTO 140
                IR = IR + 1
                TVAL = YRIGHT(IR)
                GOTO 150
  140         CONTINUE
                IL = IL + 1
                TVAL = YLEFT(IL)
  150         CONTINUE
              IF(TVAL.EQ.CRVAL) GOTO 200
                IF(TVAL.GT.CRVAL) GOTO 170
                   N = N+1
                   IF(N.GT.MNDEP) THEN
                     WRITE(STDOUT,10) MNDEP, GET_TABID(ITAB(TABL+1)),
     A                  GET_TABID(ITAB(TABR+1))
                     STOP 'Abnormal stop: errors found.'
                   ENDIF
                   Y(N) = TVAL
                   GOTO 130
  170          CONTINUE
                 N = N+1
                 IF(N.GT.MNDEP) THEN
                   WRITE(STDOUT,10) MNDEP, GET_TABID(ITAB(TABL+1)),
     A                GET_TABID(ITAB(TABR+1))
                   STOP 'Abnormal stop: errors found.'
                  ENDIF
                 Y(N) = CRVAL
                 CRVAL = TVAL
                 LIST = -LIST
                 GOTO 130
  200        CONTINUE
                 N = N+1
                 IF(N.GT.MNDEP) THEN
                   WRITE(STDOUT,10) MNDEP, GET_TABID(ITAB(TABL+1)),
     A               GET_TABID(ITAB(TABR+1))
                 STOP 'Abnormal stop: errors found.'
                 ENDIF
                 Y(N) = TVAL
                 IR = IR + 1
                 IL = IL + 1
                 IF(Y(N).EQ.YMAX) RETURN
                 GOTO 90
      END

C
C
C
      SUBROUTINE MAKE_YSLOT(MAXNDEP, NPSLOT, N,
     I                          SD, Y,
     O                          NEWN, YSLOT)  

C     Make the sequence of depths for a section with a slot
C     so that interpolation for an intermediate table between
C     two tables that have a slot, will produce a valid
C     slotted intermediate result. 

      IMPLICIT NONE
      INTEGER MAXNDEP, NPSLOT, N, NEWN
      REAL SD, YSLOT(MAXNDEP), Y(N)

C     Local
      INTEGER I
C***********************************************************************
C     Distribute the depths in the slot uniformly over the slot depth.
      DO 100 I=1,NPSLOT-1
        YSLOT(I) = SD*REAL(I-1)/REAL(NPSLOT-1)
100   CONTINUE

C     The first value in Y(*) is 0.0 always.  We add SD to each value
C     in Y and place it in YSLOT starting at NPSLOT

      DO 110 I=1,N
        YSLOT(NPSLOT + I - 1) = Y(I) + SD
110   CONTINUE
      NEWN = NPSLOT + N - 1
      RETURN
      END
       



C
C
C
      INTEGER FUNCTION  GET_KOUNT_OF_INTERNAL_TABIDS()

C     Get the existing count of table ids.  

      INCLUDE 'itbidnm.cmn'
C***********************************************************************
      GET_KOUNT_OF_INTERNAL_TABIDS = KOUNT_OF_INTERNAL_TABIDS 
      RETURN
      END
C
C
C
      SUBROUTINE  RESET_KOUNT_OF_INTERNAL_TABIDS()

C     Initialize the KOUNT_OF_INTERNAL_TABIDS

      INCLUDE 'itbidnm.cmn'
C***********************************************************************
      KOUNT_OF_INTERNAL_TABIDS = 0
      RETURN
      END
 
C
C
C
      INTEGER FUNCTION   NEXTN()
 
C     + + + PURPOSE + + +
C     Use to assign an internally generated table id that 
C     cannot be duplicated by the user on input.  Will be
C     to make sure that the internal table numbers follow
C     a standard pattern.  Needed in FEQUTL because we cannot
C     ensure that all user tables are stored before any 
C     cross-section interpolation requests are made. 
C     This can and is done in FEQ. 

 
      IMPLICIT NONE
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'stdun.cmn'
      INCLUDE 'itbidnm.cmn'
      
 
C     Called program units
      EXTERNAL GET_INTERNAL_TAB_NUMBER

 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, EFLAG, INTERNAL_TAB_NUMBER
      CHARACTER TABID*16, CHAR6*6
 
C***********************************************************************
C     Create a tabid that contains special characters that cannot
C     appear in a valid tabid supplied in the input.  Index so
C     that we will be unique.
 
      KOUNT_OF_INTERNAL_TABIDS = KOUNT_OF_INTERNAL_TABIDS + 1
      WRITE(CHAR6,'(I6)') KOUNT_OF_INTERNAL_TABIDS
      TABID = 'Internal:'//CHAR6
      EFLAG = 0
      CALL GET_INTERNAL_TAB_NUMBER
     I                            (STD6, TABID,
     M                             EFLAG,
     O                             INTERNAL_TAB_NUMBER)
      IF(EFLAG.NE.0) THEN
        WRITE(STD6, * ) 
     A' *ERR:164* Tabid table exhausted by cross-section interpolations'
        STOP 'Abnormal stop.  Error found.'
      ENDIF
      NEXTN = INTERNAL_TAB_NUMBER
      RETURN
      END
C
C
C
      SUBROUTINE RESET_LAST_LEVEL(ADRS)

C     Reset the last level accessed in a cross-section function table
C     to the default value. 

      INTEGER ADRS

C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
C     Local
      INTEGER LA

C***********************************************************************
C     Compute address of the first level ( Low Address) in the table.
      LA = ADRS + XTIOFF
      ITAB(ADRS+3) = LA
      RETURN
      END

C
C
C
      SUBROUTINE   SCAN
     I                 (STDOUT, NBRA, NBN, MFT, MLFT, BRPT, NSEC, XVEC,
     I                  ZVEC, SFAC,
     M                  EFLAG, FTP, FTKNT)
 
C     + + + PURPOSE + + +
C     Scan the branch tables to find requests for interpolation
C     and do the requested interpolation.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, FTKNT, FTP, STDOUT, MFT, MLFT, NBN, NBRA
      INTEGER BRPT(8,NBRA), NSEC(NBN)
      REAL SFAC, XVEC(NBN), ZVEC(NBN)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     NBRA   - number of branches in the model
C     NBN    - total number on nodes on branches in the model
C     MFT    - maximum function table pointer value.  Same as maximum
C               function table number
C     MLFT   - maximum length of FTAB/ITAB
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
C     NSEC   - address of cross section table at a node on a branch
C     XVEC   - station values for each node on a branch
C     ZVEC   - bottom profile elevations for nodes on a branch
C     SFAC   - conversion factor from user stations to internal stations
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     FTP    - next open location in the function table storage
C     FTKNT  - function table counter
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
 
      INTEGER MAXNDEP
      PARAMETER (MAXNDEP = MNDEP + NPSLOT)

C     + + + LOCAL VARIABLES + + +
      INTEGER FN, IB, ITAB, LN, N, NEWN, ND, NIN, TABL, TABR,
     A        START_KNT, END_KNT, I
     
      INTEGER NODE(MNMID), TAB(MNMID)

      REAL SDL, SDR, X(MNMID), XL, XR, XTL, XTR, Y(MNDEP), Z(MNMID),
     A     YSLOT_LEFT(MAXNDEP), YSLOT_RIGHT(MAXNDEP)
 
C     + + + INTRINSICS + + +
      INTRINSIC IABS
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER GETUSB, NEXTN, GET_KOUNT_OF_INTERNAL_TABIDS, GETTBN
      CHARACTER*16 GET_TABID
      
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETUSB, INTERP, KIL, MERGE, NEXTN, RDUP,
     A     GET_KOUNT_OF_INTERNAL_TABIDS, GETTBN, GET_TABID
 
C     + + + OUTPUT FORMATS + + +
 10   FORMAT(/,' ',I5,' X-sections interpolated between ',
     A ' stations',F10.3, ' and',F10.3,/,5X,' Max. depth = ',F10.3,
     B ' NUMBER OF DEPTH VALUES = ',I5)
 11   FORMAT(5X,' Start internal Tabid#=',I6,
     A            ' End internal Tabid#=',I6)
 12   FORMAT(6X,'There are now ',I6,' function tables and ',I8,
     A       ' locations left in FTAB.')
 16   FORMAT(' *ERR:148* in branch ',I5,' There have been ',I4,
     A ' consecutive interpolation',/,9X,'requests.  Only',I5,' are ',
     B 'allowed.')
18    FORMAT(/,' *ERR:407* Ups Tabid=',A16,' has slot depth=',F10.3,/,
     A ' but dns Tabid=',A16,' has slot depth=',F10.3,/,' Both must',
     B ' be 0.0 or both must be > 0.0 for interpolation.')
C***********************************************************************
      DO 200 IB=1,NBRA
      FN = BRPT(3,IB)
      LN = BRPT(4,IB)
 
      START_KNT = GET_KOUNT_OF_INTERNAL_TABIDS()
      NIN = 0
        DO 100 ND=FN,LN
        ITAB = NSEC(ND)
        IF(ITAB.GT.0) GOTO 50
C         KEEP RECORD OF all NEGATIVE VALUES HERE
          NIN = NIN+1
          IF(NIN.GT.MNMID) THEN
            WRITE(STDOUT,16) GETUSB(IB), NIN, MNMID
            STOP 'Abnormal stop: errors found.'
          ENDIF
 
C         Assign a valid internal table number to 
C         interpolation requests given with only a -
          IF(ITAB.EQ.-1000000) THEN
            ITAB = NEXTN()
          ENDIF
          ITAB = IABS(ITAB)
          IF(ITAB.GT.MFT) CALL KIL
     I                             (9,
     M                              ITAB, EFLAG)
          TAB(NIN) = ITAB
          X(NIN) = XVEC(ND)
          Z(NIN) = ZVEC(ND)
          NODE(NIN) = ND
          GOTO 100
   50   CONTINUE
          IF(NIN.EQ.0) GOTO 70
C           WE HAVE FOUND THE TERMINAL KNOWN CROSS-SECTION AFTER
C           A REQUEST  FOR ONE OR MORE INTERPOLATIONS
            TABR = ITAB
            XR = XVEC(ND)
C           PROCESS THE REQUESTS FOR INTERPOLATION.
C           ESTABLISH THE DEPTH VALUES FOR INTERPOLATION
 
            CALL MERGE_WITH_SLOT
     I                  (STDOUT, TABL, TABR,
     O                   EFLAG, N, Y, SDL, SDR)


            CALL RDUP
     I               (N,
     M                Y,
     O                NEWN)
 
            N = NEWN

C           Y(*) contains the unique series of depth values, relative to
C           the real invert.  Construct a vector for each of the two tables
C           that contains a depth sequence relative to the bottom elevation
C           of the slot if both have a slot.  If only one has a slot, it 
C           is an error.  Mixtures potentially create interpolated sections
C           that are not what we want.
            IF(SDL.EQ.0.0) THEN
              IF(SDR.EQ.0.0) THEN
C               No slot present.  Transfer Y(*) to each vector.
                DO 52 I=1,N
                  YSLOT_LEFT(I) = Y(I)
                  YSLOT_RIGHT(I) = Y(I)
52              CONTINUE
              ELSE
                WRITE(STDOUT,18) GET_TABID(GETTBN(TABL)), SDL,
     A               GET_TABID(GETTBN(TABR)), SDR
                STOP 'Abnormal stop.  Error(s) found.'
              ENDIF
            ELSE
              IF(SDR.EQ.0.0) THEN
                WRITE(STDOUT,18)  GET_TABID(GETTBN(TABL)), SDL,
     A               GET_TABID(GETTBN(TABR)), SDR
                STOP 'Abnormal stop.  Error(s) found.'
              ELSE
C               Both have a slot here.  
                CALL MAKE_YSLOT(MAXNDEP, NPSLOT, N,
     I                          SDL, Y,
     O                          NEWN, YSLOT_LEFT)   
                CALL MAKE_YSLOT(MAXNDEP, NPSLOT, N,
     I                          SDR, Y,
     O                          NEWN, YSLOT_RIGHT) 
                N = NEWN
              ENDIF
            ENDIF  

            CALL INTERP
     I                 (STDOUT, TABL, TABR, XL, XR, N, NBN, NIN, MLFT,
     I                  X, Z, TAB, NODE, SFAC, 
     I                  YSLOT_LEFT, YSLOT_RIGHT,
     M                  EFLAG, FTP,
     O                  NSEC)
 
C           Interpolation has changed the stored value of the address
C           of the last level accessed.  This must be reset to the 
C           default so that potential adjustment of conveyance 
C           which follows will take place. 
            CALL RESET_LAST_LEVEL(TABL)
            CALL RESET_LAST_LEVEL(TABR)

            END_KNT = GET_KOUNT_OF_INTERNAL_TABIDS()
C           REPORT OPERATIONS
 
            XTL = XL/SFAC
            XTR = XR/SFAC
            WRITE(STDOUT,10) NIN, XTL, XTR, YSLOT_LEFT(N), N
            IF(START_KNT.LT.END_KNT) THEN
              WRITE(STDOUT,11) START_KNT + 1, END_KNT
            ENDIF
            FTKNT = FTKNT+NIN
            WRITE(STDOUT,12) FTKNT, MRFTAB - FTP
 
C           INITIALIZE AS IF NEXT SECTION IS A REQUEST FOR INTERP
            START_KNT = END_KNT
            TABL = TABR
            XL = XR
            NIN = 0
            GOTO 100
   70     CONTINUE
            TABL = ITAB
            XL = XVEC(ND)
  100   CONTINUE
  200 CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE   TWODIN
     I                   (IN, STDOUT, MLFT, TABLE, HDATUM, CHR69,
     M                    EFLAG, FTP, TYPE)
 
C     + + + PURPOSE + + +
C     Input two-D tables
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, FTP, IN, STDOUT, MLFT, TABLE, TYPE
      REAL HDATUM
      CHARACTER CHR69*69
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     STDOUT   - Fortran unit number for user output and messages
C     MLFT   - maximum length of FTAB/ITAB
C     TABLE  - table number
C     HDATUM - datum for heads
C     CHR69  - optional format for reading function tables of type 10
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     FTP    - next open location in the function table storage
C     TYPE   - table type
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
 
C     + + + SAVED VALUES + + +
      CHARACTER BLANK*8
      SAVE BLANK
 
C     + + + LOCAL VARIABLES + + +
      INTEGER FTPOLD, I, IHU, INC, IP, J, JBASE, JE, JS, K, N, NARGC,
     A        NARGR, NHU, NHUP, NPFD, OUT, PHU, PPFD, QPNT, FTPBASE,
     B        MAX_COL
      REAL COLVEC(MCDT10), DROP, FDVEC(10), HU, HUPVEC(10), OLDARG,
     A     OLDHU, P, PFD, POLD, Q, QVEC(10), ROWARG
      CHARACTER COLARG(MCDT10)*8, HDIN*24, HDITEM*24, HDOUT*24, HEAD*80,
     A          LINE*80, ROWIN*24, ROWLAB*8, ROWOUT*24, LINE120*120,
     B          CHR3*3
 
C     + + + INTRINSICS + + +
      INTRINSIC MIN
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL INL80, INL120, KIL, STRIP_L_BLANKS
 
C     + + + DATA INITIALIZATIONS + + +
      DATA BLANK/'      '/
 
C     + + + INPUT FORMATS + + +
 1    FORMAT(80A)
 2    FORMAT(2F10.0)
 4    FORMAT(2F10.0)
 10   FORMAT(5X,I5)
 12   FORMAT(7X,10F7.0)
 14   FORMAT(11F7.0)
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' ',A80)
 51   FORMAT(' ',A80)
 52   FORMAT(' ',2F10.3)
 54   FORMAT(' ',2F10.3)
 56   FORMAT(/,'0*ERR:77* FIRST VALUE OF P FOR CONSTANT HEAD LINE',
     A       ' NOT ZERO. P=',F10.3)
 58   FORMAT(/,'0*ERR:78* P DECREASES P=',F10.3,' POLD=',F10.3)
 62   FORMAT(/,'0*ERR:79* VALUES OF UPSTREAM HEAD ARE DECREASING',
     A         ' IN 2-D TABLE.')
 68   FORMAT(/,'0*ERR:547* COLUMN ARGUMENTS MUST BE STRICTLY',
     A         ' INCREASING')
 70   FORMAT(' NHUP=',I5)
 71   FORMAT(' NPFD=',I5)
 72   FORMAT(/,' *ERR:367* Conversion error in reading user format for',
     A         ' Type 10 table:',A)
C***********************************************************************
      IF(FTP+10.GE.MLFT) CALL KIL
     I                            (10,
     M                             FTP, EFLAG)
 
C     STORE THE DATUM FOR HEADS FOR THIS TABLE.  Also save the base value
C     of FTP for possible use later.
      FTAB(FTP) = HDATUM
      FTPBASE = FTP
      ITAB(FTP+1) = TABLE
      IF(TYPE.GT.0) THEN
        OUT = 1
      ELSE
        TYPE = -TYPE
        OUT = 0
      ENDIF
      ITAB(FTP+2) = TYPE
      FTPOLD = FTP
 
      IF(TYPE.EQ.6) THEN
        FTP = FTP + 10
 
C       SET POINTER VALUES FOR THE UPSTREAM LEVELS
        ITAB(FTPOLD+3) = FTP
        ITAB(FTPOLD+4) = FTP
 
        CALL INL80
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,1) HEAD
        WRITE(STDOUT,50) HEAD
 
C       INPUT THE UPSTREAM HEAD AND THE HEAD DROP TO FREE FLOW
 
        NHU = 0
        INC = 5
        OLDHU = -1.0
 100    CONTINUE
          CALL INL80
     I              (IN, STDOUT,
     O               LINE)
          READ(LINE,2,ERR=991) HU, DROP
          IF(HU.LT.0.0) GOTO 110
          IF(OUT.EQ.1) WRITE(STDOUT,52) HU, DROP
          IF(HU.LE.OLDHU) THEN
            WRITE(STDOUT,62)
            EFLAG = 1
          ENDIF
          OLDHU = HU
          NHU = NHU + 1
          IF(FTP+INC.GE.MLFT) CALL KIL
     I                                 (10,
     M                                  FTP, EFLAG)
          FTAB(FTP) = HU
          FTAB(FTP+1) = DROP
          FTP = FTP + INC
          GOTO 100
 110    CONTINUE
 
C       SET THE MAXIMUM UPSTREAM HEAD VALUE
 
        FTAB(FTPOLD+9) = FTAB(FTP-INC)
 
C       INPUT THE VALUES DEFINING THE LINES OF CONSTANT UPSTREAM HEAD
 
C       SET POINTERS FOR THE UPSTREAM HEAD VALUES
 
        IP = ITAB(FTPOLD+3)
 
        CALL INL80
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,1) HEAD
        WRITE(STDOUT,50) HEAD
 
        DO 300 J=1,NHU
          IF(FTP+2.GE.MLFT) CALL KIL
     I                               (10,
     M                                FTP, EFLAG)
          CALL INL80
     I              (IN, STDOUT,
     O               LINE)
          READ(LINE,4,ERR=991) P, Q
          IF(OUT.EQ.1) WRITE(STDOUT,54) P,Q
          IF(P.NE.0.0) THEN
            WRITE(STDOUT,56) P
            EFLAG = 1
          ENDIF
          POLD = P
 
C         SET POINTERS FOR THIS CONSTANT HEAD LINE
          ITAB(IP+2) = FTP
          ITAB(IP+3) = FTP
 
          FTAB(FTP) = P
          FTAB(FTP+1) = Q
          FTP = FTP + 2
 
 
 200      CONTINUE
            IF(FTP+2.GE.MLFT) CALL KIL
     I                                 (10,
     M                                  FTP, EFLAG)
            CALL INL80
     I                (IN, STDOUT,
     O                 LINE)
            READ(LINE,4,ERR=991) P, Q
            IF(OUT.EQ.1) WRITE(STDOUT,54) P,Q
            IF(P.LE.POLD) THEN
              WRITE(STDOUT,58) P, POLD
              EFLAG = 1
            ENDIF
            POLD = P
            FTAB(FTP) = P
            FTAB(FTP+1) = Q
            FTP = FTP + 2
            IF(P.EQ.1.0) GOTO 210
            GOTO 200
 210      CONTINUE
C         STORE THE FREE FLOW IN THE MAIN TABLE
 
          FTAB(IP+4) = Q
          IP = IP + INC
 300    CONTINUE
 
 
C       CHECK TABLE CONTENTS
 
C        WRITE(STDOUT,*) ' TABLE#=',ITAB(FTPOLD+1)
C        WRITE(STDOUT,*) ' TYPE=',ITAB(FTPOLD+2)
C        WRITE(STDOUT,*) ' HU BASE=',ITAB(FTPOLD+3)
C        WRITE(STDOUT,*) ' HU LAST=',ITAB(FTPOLD+4)
C        WRITE(STDOUT,*) ' HU MAX=',FTAB(FTPOLD+9)
C
C        IP = ITAB(FTPOLD+3)
C
C        DO 500 I=1,NHU
C          WRITE(STDOUT,60) FTAB(IP), FTAB(IP+1), ITAB(IP+2),
C     A                   ITAB(IP+3), FTAB(IP+4)
C
C          IPQ = ITAB(IP+2)
C400       CONTINUE
C            WRITE(STDOUT,*) '    P=',FTAB(IPQ),' Q=',FTAB(IPQ+1)
C            IF(FTAB(IPQ).EQ.1.0) GOTO 410
C            IPQ = IPQ + 2
C            GOTO 400
C410       CONTINUE
C
C          IP = IP + INC
C500     CONTINUE
 
      ELSE IF(TYPE.EQ.10) THEN
C       PROCESS TABLE TYPE=10. TRADITIONAL TWO-D TABLE
C       MEANING OF ARGUMENTS DEPENDS ON CONTEXT OF USE OF THE
C       TABLE.
 
C       Set formats for processing the table.
        IF(CHR69.NE.' ') THEN
          LINE = CHR69
          READ(CHR69,*,ERR=991) HDIN, HDOUT, HDITEM, ROWIN, ROWOUT
C         Try to find the number of columns from the provided format.
C         Assumes that HDIN will start (xxA...) where xx is one, two 
C         or three digits.

          CALL STRIP_L_BLANKS(
     M                         HDIN)
C          WRITE(STDOUT,*) ' HDIN=',HDIN
          CHR3 = HDIN(2:4)
C          WRITE(STDOUT,*) ' CHR3=',CHR3
          IF(CHR3(2:2).EQ.'A'.OR.CHR3(2:2).EQ.'a') THEN
C           There is one digit.
            READ(CHR3(1:1),'(I1)',ERR=993) MAX_COL
            MAX_COL = MAX_COL - 1
          ELSEIF(CHR3(3:3).EQ.'A'.OR.CHR3(3:3).EQ.'a') THEN
C           There are two digits
            READ(CHR3(1:2),'(I2)',ERR=993) MAX_COL
            MAX_COL = MAX_COL - 1
          ELSE
C           Assume there are 3 digits.
            READ(CHR3(1:3),'(I3)',ERR=993) MAX_COL
            MAX_COL = MAX_COL -1
          ENDIF
C          WRITE(STDOUT,*) ' MAX_COL=',MAX_COL
                        
        ELSE
C         Use the default values.
          HDIN = '(20A6)'
          HDOUT = '(1X,20A6)'
          HDITEM = '(F6.0)'
          ROWIN = '(20F6.0)'
          ROWOUT = '(1X,F6.2,19F6.3)'
          MAX_COL = 19
        ENDIF
 
C       READ AND ECHO THE LABEL FOR THE TABLE, this might also be the
C       optional line giving the head datum for the table.
 
        CALL INL80
     I            (IN, STDOUT,
     O             LINE)
        IF(LINE(1:6).EQ.'HDATUM') THEN
          READ(LINE(8:17),'(F10.0)', ERR=991) HDATUM 
C         Store HDATUM
          FTAB(FTPBASE) = HDATUM
          CALL INL80
     I              (IN, STDOUT,
     O               LINE)
        ENDIF
        READ(LINE,1) HEAD
        WRITE(STDOUT,50) HEAD

C       READ argument heading and count the number of arguments on the
C       columns of the table.

        CALL INL120
     I            (IN, STDOUT,
     O             LINE120)
        READ(LINE120,HDIN,ERR=992) ROWLAB, (COLARG(J), J=1,MAX_COL)
        IF(OUT.EQ.1) WRITE(STDOUT,HDOUT) ROWLAB, (COLARG(J),J=1,MAX_COL)
        NARGC = 0
        OLDARG = -1.E35
        DO 600 J=1, MAX_COL
          IF(COLARG(J).NE.BLANK) THEN
            NARGC = NARGC + 1
            READ(COLARG(J), HDITEM, ERR=991) COLVEC(J)
            IF(COLVEC(J).LE.OLDARG) THEN
              WRITE(STDOUT,68) J
              EFLAG = 1
            ENDIF
            OLDARG = COLVEC(J)
          ENDIF
 600    CONTINUE
 
C       STORE THE COLUMN ARGUMENTS
 
        FTP = FTP + 11
 
C       ESTABLISH PARGC, HARGC, LARGC, AND NARGC IN THE HEADER
        ITAB(FTPOLD+7) = FTP
        ITAB(FTPOLD+8) = FTP + NARGC - 1
        ITAB(FTPOLD+9) = FTP
        ITAB(FTPOLD+10) = NARGC
 
C       STORE THE VALUES
        IF(FTP+NARGC.GE.MLFT) CALL KIL
     I                                 (10,
     M                                  FTP, EFLAG)
 
        DO 610 J=1,NARGC
          FTAB(FTP+J-1) = COLVEC(J)
 610    CONTINUE
 
        FTP = FTP + NARGC
 
C       READ AND STORE THE ROW ARGUMENTS AND THE ROW CONTENTS
 
C       ESTABLISH PARGR, AND LARGR
 
        ITAB(FTPOLD+3) = FTP
        ITAB(FTPOLD+5) = FTP
 
        NARGR = 0
        OLDARG = -1.E35
 700    CONTINUE
        CALL INL120
     I            (IN, STDOUT,
     O             LINE120)
          READ(LINE120, ROWIN,ERR=992) ROWARG, (COLVEC(J), J=1,NARGC)
          IF(ROWARG.GT.OLDARG) THEN
            OLDARG = ROWARG
            IF(OUT.EQ.1) WRITE(STDOUT,ROWOUT) ROWARG,
     A                                (COLVEC(J), J=1,NARGC)
C           PROCESS THIS ROW OF INFORMATION
 
            IF(FTP+NARGC+1.GE.MLFT) CALL KIL
     I                                       (10,
     M                                        FTP, EFLAG)
 
            NARGR = NARGR + 1
            FTAB(FTP) = ROWARG
            FTP = FTP + 1
            DO 710 J=1,NARGC
              FTAB(FTP) = COLVEC(J)
              FTP = FTP + 1
 710        CONTINUE
 
            GOTO 700
          ELSE
C           INPUT COMPLETE. ESTABLISH HARGR AND NARGR IN HEADER
            ITAB(FTPOLD+4) = FTP - NARGC - 1
            ITAB(FTPOLD+6) = NARGR
          ENDIF
      ELSEIF(TYPE.EQ.13.OR.TYPE.EQ.14) THEN
 
 
C       SET POINTER VALUES FOR THE UPSTREAM HEAD
        PHU = FTP + 10
 
C        WRITE(STDOUT,*) ' PHU=',PHU
C       STORE POINTER TO THE START OF THE DOWNSTREAM HEADS.
 
        IF(TYPE.EQ.14) THEN
          ITAB(FTPOLD+3) = PHU + 1
        ELSE
          ITAB(FTPOLD+3) = PHU
        ENDIF
 
        ITAB(FTPOLD+4) = PHU
 
C       READ AND ECHO THE LABEL
        CALL INL80
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,1) HEAD
        WRITE(STDOUT,51) HEAD
 
C       GET THE NUMBER OF NON-ZERO UPSTREAM HEADS
        CALL INL80
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,10,ERR=991) NHUP
        IF(OUT.EQ.1) WRITE(STDOUT,70) NHUP
 
C       GET NUMBER OF NON-ZERO PARTIAL FREE DROPS
        CALL INL80
     I            (IN, STDOUT,
     O             LINE)
        READ(LINE,10,ERR=991) NPFD
        IF(OUT.EQ.1) WRITE(STDOUT,71) NPFD
 
C       CHECK FOR SPACE
        N = 10 + 4*(NHUP+1) + (NHUP + 2)*(NPFD + 1)
        IF(FTP+N.GE.MLFT) CALL KIL
     I                             (10,
     M                              FTP, EFLAG)
 
C       COMPUTE THE START LOCATION FOR PARTIAL FREE DROPS. NOTE:
C       ZERO UPSTREAM HEAD, ZERO PARTIAL FREE DROP, ZERO FLOWS ARE
C       NOT IN THE INPUT TABLE BUT THEY WILL BE STORED TO MAKE
C       SEARCHING AND TABLE LOOKUP SIMPLER AND SAFER.  THERE ARE
C       4 VALUES STORED AT EACH UPSTREAM HEAD: THE UPSTREAM HEAD,
C       THE FREE DROP, THE FREE FLOW, AND A POINTER TO THE
C       FLOWS FOR THE PARTIAL FREE DROPS.
 
C       FOR TABLE TYPE 14 THE VALUES DIFFER.  THE
C       CORRESPONDENCE IS:
 
C           TYPE 13                 TYPE 14
C       UPSTREAM HEAD            FREE FLOW
C       FREE DROPS               DOWNSTREAM HEAD
C       PARTIAL FREE DROPS       PARTIAL FREE FLOWS
C       FLOWS                    UPSTREAM HEADS
 
C       AT ZERO DOWNSTREAM HEAD THE FREE FLOW AND UPSTREAM HEAD
C       ARE ZERO.  AT A PARTIAL FREE FLOW OF ZERO HOWEVER THE
C       UPSTREAM HEAD IS THE SAME AS THE DOWNSTREAM HEAD.
C       ALL VARIABLES ARE NAMED ACCORDING TO THEIR TYPE 13 ROLE.
 
        PPFD = PHU + 4*(NHUP + 1)
C        WRITE(STDOUT,*) ' PPFD=',PPFD
        ITAB(FTPOLD+5) = PPFD
        ITAB(FTPOLD+6) = PPFD

C       Set the source flag location
        IF(TYPE.EQ.14) THEN
          IF(CHR69(1:5).EQ.'WSPRO') THEN
            ITAB(FTPOLD+7) = 1
          ELSE
            ITAB(FTPOLD+7) = 0
          ENDIF
        ENDIF
 
C       COMPUTE THE BASE LOCATION FOR THE FLOWS IN THE TABLE
 
        QPNT = PPFD + NPFD + 1
C        WRITE(STDOUT,*) ' QPNT=',QPNT
 
C       STORE THE VALUES FOR ZERO UPSTREAM HEAD
 
        FTAB(PHU) = 0.0
        FTAB(PHU+1) = 0.0
        FTAB(PHU+2) = 0.0
C       STORE THE OFFSET BETWEEN THE ORIGIN OF THE PARTIAL FREE
C       DROP SEQUENCE AND THE ORIGIN OF THE FLOWS AT ZERO UPSTREAM
C       HEAD SO THAT A SINGLE ADDITION CAN BE USED TO FIND THE
C       FLOWS ONCE THE LOCATION OF THE PARTIAL FREE DROP ARGUMENT
C       IS FOUND IN THE PARTIAL FREE DROP SEQUENCE.
 
        ITAB(PHU+3) = QPNT - PPFD
C        WRITE(STDOUT,*) ' OFFSET AT ORIGIN=',ITAB(PHU+3)
 
C       STORE THE ZERO PARTIAL FREE DROP VALUE(TYPE 13) AND THE ZERO
C       PARTIAL FREE FLOW(TYPE 14).
 
        FTAB(PPFD) = 0.0
 
C       STORE THE ZERO FLOWS FOR ZERO UPSTREAM HEAD
 
        DO 800 I=QPNT,QPNT+NPFD
          FTAB(I) = 0.0
 800    CONTINUE
 
C       STORE THE ZERO FLOWS FOR ZERO PARTIAL FREE DROPS FOR NON
C       ZERO HEADS.  FOR TYPE 14 OVERWRITTEN LATER BY THE
C       DOWNSTREAM HEAD.
 
        DO 802 I=1, NHUP
          IP = QPNT + I*(NPFD + 1)
          FTAB(IP) = 0.0
 802    CONTINUE
 
C       NOW STORE THE VALUES FOR NON-ZERO HEAD AND NON-ZERO PARTIAL
C       FREE DROPS
 
C       INITALIZE BASE COUNTER FOR TYPE 14.  USED  TO STORE THE
C       DOWNSTREAM HEADS AT ZERO PARTIAL FREE FLOW.
 
        JBASE = 0
        DO 850 I=1,NHUP,10
          JS = 1
          JE = MIN(10, NHUP - I + 1)
 
C         READ LINE OF UPSTREAM HEADS FOR THIS BLOCK.  FREE FLOW
C         FOR TYPE 14
          CALL INL80
     I              (IN, STDOUT,
     O               LINE)
          READ(LINE,1) HEAD
          IF(OUT.EQ.1) WRITE(STDOUT,51) HEAD
          READ(LINE,12,ERR=991) (HUPVEC(J), J=JS,JE)
 
C         READ LINE OF FREE DROPS.  DOWNSTREAM HEADS FOR TYPE 14
          CALL INL80
     I              (IN, STDOUT,
     O               LINE)
          READ(LINE,1) HEAD
          IF(OUT.EQ.1) WRITE(STDOUT,51) HEAD
          READ(LINE,12,ERR=991) (FDVEC(J), J=JS,JE)
 
          IF(TYPE.EQ.14) THEN
C           STORE THE DOWNSTREAM HEADS AT ZERO PARTIAL FREE FLOW
            DO 849 J=JS,JE
              IP = QPNT + (JBASE + J)*(NPFD + 1)
              FTAB(IP) = FDVEC(J)
 849        CONTINUE
          ENDIF
 
C         STORE THE HEADS AND DROPS WITH OFFSET BETWEEN THE
C         START OF THE PARTIAL FREE DROP SEQUENCE AND THE FLOW
C         SEQUENCE FOR EACH UPSTREAM HEAD.
 
          DO 804 J=JS,JE
C           IHU GIVES THE COUNT OF NON ZERO UPSTREAM HEADS
            IHU = I + J - 1
            IP = PHU + 4*IHU
            FTAB(IP  ) = HUPVEC(J)
            FTAB(IP+1) = FDVEC(J)
C           FREE FLOW IS FILLED AT OFFSET +2 LATER.  THIS IS
C           UPSTREAM HEAD AT FREE FLOW FOR TYPE 14.
 
C           STORE THE OFFSET VALUE TO START OF THE LIST OF
C           FLOWS FOR EACH UPSTREAM HEAD(TYPE 13) LIST OF
C           UPSTREAM HEADS FOR EACH DOWNSTREAM HEAD(TYPE 14)
 
            ITMP = QPNT + IHU*(NPFD + 1) - PPFD
C            WRITE(STDOUT,*) ' IP =',IP,' J=',J,' OFFSET=',ITMP
            ITAB(IP+3) = ITMP
 804      CONTINUE
 
C         READ HEADING FOR BODY OF TABLE
 
        CALL INL80
     I            (IN, STDOUT,
     O             LINE)
          READ(LINE,1) HEAD
          IF(OUT.EQ.1) WRITE(STDOUT,51) HEAD
 
C         READ THE TABLE BODY AND STORE THE NON-ZERO PARTIAL
C         FREE DROPS AND FLOWS.  NON-ZERO FREE FLOWS AND
C         UPSTREAM HEAD AT FREE FLOW FOR TYPE 14.
 
          DO 810 K=1,NPFD
            CALL INL80
     I                (IN, STDOUT,
     O                 LINE)
            READ(LINE,1) HEAD
            IF(OUT.EQ.1) WRITE(STDOUT,51) HEAD
            READ(LINE,14,ERR=991) PFD, (QVEC(J), J=JS,JE)
 
C           STORE THE VALUES
 
 
            FTAB(PPFD+K) = PFD
            DO 808 J=JS,JE
              IHU = I + J - 1
              IP = QPNT + IHU*(NPFD + 1) + K
              FTAB(IP) = QVEC(J)
 808        CONTINUE
 810      CONTINUE
 
C         QVEC CONTAINS THE FREE FLOWS AT THIS POINT
          DO 820 J=JS,JE
            IHU = I + J - 1
            FTAB(PHU + 4*IHU+2) = QVEC(J)
 820      CONTINUE
          JBASE = JBASE + 10
 850    CONTINUE
 
C       STORE THE MAXIMUM UPSTREAM HEAD. MAXIMUM FREE FLOW FOR
C       TYPE 14
 
        FTAB(FTPOLD+9) = HUPVEC(JE)
 
C       STORE THE MAXIMUM DOWNSTREAM HEAD FOR TYPE 14.  IN FDVEC
        IF(TYPE.EQ.14) THEN
          FTAB(FTPOLD+5) = FDVEC(JE)
        ENDIF
 
C       UPDATE THE FUNCTION TABLE POINTER
 
        FTP = IP + 1
C       CHECK TABLE CONTENTS
 
C        WRITE(STDOUT,*) ' TABLE#=',ITAB(FTPOLD+1)
C        WRITE(STDOUT,*) ' TYPE=',ITAB(FTPOLD+2)
C        IF(TYPE.EQ.13) THEN
C          WRITE(STDOUT,*) ' HU BASE=',ITAB(FTPOLD+3)
C        ELSE
C          WRITE(STDOUT,*) ' HU BASE=',ITAB(FTPOLD+3) - 1
C        ENDIF
C        WRITE(STDOUT,*) ' HU LAST=',ITAB(FTPOLD+4)
C        IF(TYPE.EQ.13) THEN
C          WRITE(STDOUT,*) ' PFD LIST BASE=',ITAB(FTPOLD+5)
C        ELSE
C          WRITE(STDOUT,*) ' MAXIMUM DNS HEAD=',FTAB(FTPOLD+5)
C        ENDIF
C        WRITE(STDOUT,*) ' PFD LIST LAST=',ITAB(FTPOLD+6)
C        WRITE(STDOUT,*) ' HU MAX=',FTAB(FTPOLD+9)
C
C        ITMP = ITAB(FTPOLD+3)
C        IF(TYPE.EQ.13) THEN
C          IP = ITMP
C        ELSE
C          IP = ITMP -1
C        ENDIF
C
C        DO 500 I=0,NHUP
C          IOFF = ITAB(IP+3)
C          WRITE(STDOUT,72) FTAB(IP), FTAB(IP+1), FTAB(IP+2),
C     A                   ITAB(IP+3)
C          WRITE(STDOUT,*) ' PARTIAL FREE DROP LIST'
C          IT = ITAB(FTPOLD+6)
C          WRITE(STDOUT,'('' PAR DROP DISCHARGE'')')
C400       CONTINUE
C            WRITE(STDOUT,'(F10.4,F10.2)') FTAB(IT), FTAB(IT + IOFF)
C            IF(FTAB(IT).EQ.1.0) GOTO 410
C            IT = IT + 1
C            GOTO 400
C410       CONTINUE
C
C          IP = IP + 4
C500     CONTINUE
 
      ENDIF
      RETURN
 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,'(A)') LINE
        STOP 'Abnormal stop: errors found.'
 992  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,'(A)') LINE120
        STOP 'Abnormal stop: errors found.'
 
 993  CONTINUE
        WRITE(STDOUT,72) HDIN
        STOP 'Abnormal stop: errors found.'

      END
C
C
C 
      SUBROUTINE READ_TABTY15_ITEMS(
     I            STDOUT, LINE, NITEM, ITEM_START,
     I            ITEM_END, BARG, 
     M            EFLAG,
     O            ARG, TAB2D, F)

C     Get the items of data from a line of input in at table of type 15.

      IMPLICIT NONE
      INTEGER STDOUT, NITEM, ITEM_START(NITEM), ITEM_END(NITEM),
     A         EFLAG, TAB2D
      REAL ARG, BARG, F(3)
      CHARACTER LINE*(*)

C     Local

      INTEGER IE, IS, N, INTERNAL_TAB_NUMBER
      CHARACTER TPC*20, TABID*16

C     Called program units
     
      EXTERNAL STRIP_L_BLANKS, GET_INTERNAL_TAB_NUMBER

C     ***********************FORMATS************************************
50    FORMAT(/,' *ERR:383* Only ',I3,' items given in a Type 15 ',
     A ' table line.  Need five items.')
C***********************************************************************
      IF(NITEM.LT.5) THEN
        WRITE(STDOUT,50) NITEM
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      N = 1
C     Process the argument field
      IS = ITEM_START(N)
      IE = ITEM_END(N)
      TPC = LINE(IS:IE)
      CALL STRIP_L_BLANKS(
     M                    TPC)
      READ(TPC,*,ERR=991) ARG

      IF(ARG.LE.BARG) THEN
C       Last line in the table. 
        TAB2D = 0
        F(1) = 0
        F(2) = 0
        F(3) = 0
      ELSE
C       Process the 2-D table id
        N = 2
        IS = ITEM_START(N)
        IE = ITEM_END(N)
        TPC = LINE(IS:IE)
        CALL STRIP_L_BLANKS(
     M                      TPC)
        TABID = TPC
        CALL GET_INTERNAL_TAB_NUMBER
     I                              (STDOUT, TABID,
     M                               EFLAG,
     O                               INTERNAL_TAB_NUMBER)
        TAB2D = INTERNAL_TAB_NUMBER

C       Process three points for each argument
        DO 100 N=3,5
          IS = ITEM_START(N)
          IE = ITEM_END(N)
          TPC = LINE(IS:IE)
          CALL STRIP_L_BLANKS(
     M                        TPC)
          READ(TPC,*,ERR=991) F(N-2)
100     CONTINUE
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
      SUBROUTINE   TY15IN
     I                   (IN, STDOUT, MLFT, NTAB,
     M                    EFLAG, FTP, TYPE)
 
C     + + + PURPOSE + + +
C     Input a table of type 15.

      IMPLICIT NONE 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, FTP, IN, STDOUT, MLFT, NTAB, TYPE
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     MLFT   - maximum length of FTAB/ITAB
C     NTAB   - table number
C     FTP    - next open location in the function table storage
C     TYPE   - table type
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER FTPOLD, OUT, TAB2D
      REAL ARG, BARG, F(3), REFLEV
      CHARACTER HEAD*80, LABEL*50, LINE*80
      INTEGER MAX_ITEM, NITEM
      PARAMETER (MAX_ITEM=5)
      INTEGER ITEM_START(MAX_ITEM), ITEM_END(MAX_ITEM)
      CHARACTER JUST*5
 
C     + + + INTRINSICS + + +
      INTRINSIC IABS
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL INL80, KIL, READ_TABTY15_ITEMS
 
C     + + + INPUT FORMATS + + +
 1    FORMAT(80A)
 46   FORMAT(5X,F10.0,7X,A50)
 48   FORMAT(F10.0,I5,3F10.0)
 
C     + + + OUTPUT FORMATS + + +
 11   FORMAT(' ',80A)
 47   FORMAT(' ','LABEL=',A50)
 49   FORMAT(' ',F10.3,I5,3F10.3)
C***********************************************************************
      JUST = 'RIGHT'
      CALL INL80
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,46,ERR=991) REFLEV, LABEL
      WRITE(STDOUT,47) LABEL
 
      IF((FTP+4).GE.MLFT) CALL KIL
     I                             (10,
     M                              FTP, EFLAG)
 
C     FTP RESERVED FOR THE HIGH ADDRESS OF THE TABLE
 
      OUT = 1
      IF(TYPE.LT.0) OUT = 0
      TYPE = IABS(TYPE)
 
      ITAB(FTP+1) = NTAB
      ITAB(FTP+2) = TYPE

C     Set flag to indicate that table needs processing.
      ITAB(FTP+3) = 1

 
C     INITIALIZE LAST ADDRESS ACCESSED
 
      ITAB(FTP+4) = FTP + 5
      FTPOLD = FTP
      FTP = FTP + 5
 
      CALL INL80
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,1) HEAD
      WRITE(STDOUT,11) HEAD


      CALL GET_ITEM_LIMITS(
     I                      STDOUT, HEAD, MAX_ITEM, JUST,
     O                      NITEM, ITEM_START, ITEM_END)

      BARG = -1.0E37
 
 1000 CONTINUE
 
         CALL INL80
     I             (IN, STDOUT,
     O              LINE)
         READ(LINE,48,ERR=991) ARG, TAB2D, F
         CALL READ_TABTY15_ITEMS(
     I            STDOUT, LINE, NITEM, ITEM_START,
     I            ITEM_END, BARG,
     M            EFLAG,
     O            ARG, TAB2D, F)
 
         IF(ARG.LE.BARG) GOTO 1500
         BARG = ARG
         IF(OUT.EQ.1) THEN
           WRITE(STDOUT,49) ARG, TAB2D, F
         ENDIF
         IF((FTP+5).GE.MLFT) CALL KIL
     I                                (10,
     M                                 FTP, EFLAG)
         FTAB(FTP) = ARG
         ITAB(FTP+1) = TAB2D
         FTAB(FTP+2) = F(1)
         FTAB(FTP+3) = F(2)
         FTAB(FTP+4) = F(3)
         FTP = FTP + 5
         GOTO 1000
 
 1500 CONTINUE
      ITAB(FTPOLD) = FTP - 5
      RETURN
 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,*) LINE
        STOP 'Abnormal stop: errors found.'
      END
C
C
C
      SUBROUTINE   XLKT20
     I                   (ADRS,
     M                    YA,
     O                    A, T, DT, K, DK, B, DB)
 
C     + + + PURPOSE + + +
C     Given depth find area, top-width, conveyance, etc.
C     using direct linear interpolation for top width.
 
      IMPLICIT NONE
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
      INCLUDE 'xscom.cmn'
      INCLUDE 'offcom.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER VTYPE(35)
      SAVE VTYPE
 
C     + + + LOCAL VARIABLES + + +
      INTEGER HA, IT, L, LA, TYPE, XOFF
      REAL B0, DY, DYI, H, HH, K0, T0, Y, Y0
      CHARACTER CS*16

C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_STRING_FROM_FT
      EXTERNAL GET_STRING_FROM_FT, XSTYPE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA VTYPE/1,10*0,1,7*0,6*1,10*0/
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT(' ','*WRN:02* X-SECTION BELOW RANGE IN XLKT20',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
 2010 FORMAT(' ','*WRN:03* X-SECTION ABOVE RANGE IN XLKT20',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
C***********************************************************************
C     HA = HIGH ADDRESS
C     LA = LOW ADDRESS
C     L = ADDRESS FOUND ON THE LAST CALL TO XLKT20
 
      Y = YA
      HA = ITAB(ADRS)
      LA = ADRS + XTIOFF
      L = ITAB(ADRS+3)
 
      TYPE = ITAB(ADRS+2)
      XOFF = OFFVEC(TYPE)
      IF(VTYPE(TYPE).EQ.0) THEN
        CALL XSTYPE
     I             (STDOUT, VTYPE, ADRS)
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
      IF(Y.GE.FTAB(L)) THEN
C       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE
        IF(Y.GT.FTAB(HA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2010) CS, FTAB(ADRS+4), 
     A                       TIME, Y
          L = HA - XOFF
          Y = FTAB(HA)
          YA = Y
        ELSE
 100      CONTINUE
            IF(Y.GT.FTAB(L+XOFF)) THEN
              L = L + XOFF
              GOTO 100
            ENDIF
        ENDIF
      ELSE
C       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE
        IF(Y.LT.FTAB(LA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2000) CS, FTAB(ADRS+4), 
     A              TIME, Y
          L = LA
          Y = FTAB(L+XOFF)
          YA = Y
        ELSE
 110      CONTINUE
            L = L - XOFF
            IF(Y.LT.FTAB(L)) GOTO 110
        ENDIF
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
      HH = 0.5*H
      DYI = 1.0/DY
      DB = (FTAB(IT+4) - B0)*DYI
      DT =  (FTAB(IT+1) - T0)*DYI
      DK = (FTAB(IT+3) - K0)*DYI
      T = T0 + H*DT
      B = B0 + H*DB
      A = FTAB(L+2) + HH*(T + T0)
      K = K0 + H*DK
      DK = (K +K)*DK
      K = K*K
 
      RETURN
      END
C
C
C
      SUBROUTINE   XLKT21
     I                   (ADRS,
     M                    YA,
     O                    A, T, DT, J, K, DK, B, DB)
 
C     + + + PURPOSE + + +
C     Given depth find area, top-width, conveyance, etc.
C     using direct linear interpolation for top width.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
      REAL A, B, DB, DK, DT, J, K, T, YA
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB
C     YA     - depth to use for table look up
C     A      - Cross sectional area from the cross section table
C     T      - top width of the cross section
C     DT     - derivative of the top width with respect to depth
C     J      - first moment of area about water surface in the table
C     K      - conveyance
C     DK     - derivative of conveyance with respect to depth
C     B      - the value of the momentum flux correction coef. from the
C               table
C     DB     - derivative of B with respect to depth
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'xscom.cmn'
      INCLUDE 'offcom.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER VTYPE(35)
      SAVE VTYPE
 
C     + + + LOCAL VARIABLES + + +
      INTEGER HA, L, LA, TYPE, XOFF
      REAL A0, B0, DY, DYI, H, HH, J0, K0, T0, Y, Y0
      CHARACTER CS*16

C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_STRING_FROM_FT
      EXTERNAL GET_STRING_FROM_FT, XSTYPE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA VTYPE/1,10*0,1,7*0,0,2*1,0,2*1,10*0/
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT(' ','*WRN:02* X-SECTION BELOW RANGE IN XLKT21',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
 2010 FORMAT(' ','*WRN:03* X-SECTION ABOVE RANGE IN XLKT21',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
C***********************************************************************
C     HA = HIGH ADDRESS
C     LA = LOW ADDRESS
C     L = ADDRESS FOUND ON THE LAST CALL TO XLKT21
 
      Y = YA
      HA = ITAB(ADRS)
      LA = ADRS + XTIOFF
      L = ITAB(ADRS+3)
 
      TYPE = ITAB(ADRS+2)
      XOFF = OFFVEC(TYPE)
      IF(VTYPE(TYPE).EQ.0) THEN
        CALL XSTYPE
     I             (STDOUT, VTYPE, ADRS)
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
      IF(Y.GE.FTAB(L)) THEN
C       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE
        IF(Y.GT.FTAB(HA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2010) CS, FTAB(ADRS+4),
     A                       TIME, Y
          L = HA - XOFF
          Y = FTAB(HA)
          YA = Y
        ELSE
 100      CONTINUE
            IF(Y.GT.FTAB(L+XOFF)) THEN
              L = L + XOFF
              GOTO 100
            ENDIF
        ENDIF
      ELSE
C       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE
        IF(Y.LT.FTAB(LA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2000) CS, FTAB(ADRS+4), 
     A                       TIME, Y
          L = LA
          Y = FTAB(L+XOFF)
          YA = Y
        ELSE
 110      CONTINUE
            L = L - XOFF
            IF(Y.LT.FTAB(L)) GOTO 110
        ENDIF
      ENDIF
C     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE
C     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED
C     FOR ARGUMENT OUT OF RANGE.
 
C     RESET POINTER FOR LAST ADDRESS
 
      ITAB(ADRS+3) = L
 
C     FETCH VALUES FROM FTAB
 
      Y0 = FTAB(L)
      T0 = FTAB(L+1)
      A0 = FTAB(L+2)
      K0 = FTAB(L+3)
      B0 = FTAB(L+4)
      J0 = FTAB(L+5)
 
C     DIRECT LINEAR INTERPOLATION FOR T AND SQRT(CONVEYANCE)
C     N.B. K IN FTAB IS SQRT(CONVEYANCE)
 
      DY = FTAB(L+XOFF) - Y0
      H = Y - Y0
      HH = 0.5*H
      DYI = 1.0/DY
      DB = (FTAB(L+XOFF+4) - B0)*DYI
      DT =  (FTAB(L+XOFF+1) - T0)*DYI
      DK = (FTAB(L+XOFF+3) - K0)*DYI
      T = T0 + H*DT
      B = B0 + H*DB
      A = A0 + HH*(T + T0)
      J = J0 + HH*(A + A0 - H*(T - T0)*0.1666667)
      K = K0 + H*DK
      DK = (K +K)*DK
      K = K*K
 
      RETURN
      END
C
C
C
      SUBROUTINE   XLKT22
     I                   (ADRS,
     M                    YA,
     O                    A, T, DT, J, K, DK, B, DB, ALP, DALP, QC)
 
C     + + + PURPOSE + + +
C     Given the depth, YA, find: A-area; T-top width; DT- derivative
C     of top width; J-first moment of area about water surface;
C     K-conveyance; DK=derivative of conveyance; B- beta;
C     DB- derivative of beta; ALP-alpha; and DALP-derivative of
C     alpha, and QC, critical flow.  Use linear interpolation
C     on logarithms of QC and depth.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
      REAL A, ALP, B, DALP, DB, DK, DT, J, K, QC, T, YA
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB
C     YA     - depth to use for table look up
C     A      - Cross sectional area from the cross section table
C     T      - top width of the cross section
C     DT     - derivative of the top width with respect to depth
C     J      - first moment of area about water surface in the table
C     K      - conveyance
C     DK     - derivative of conveyance with respect to depth
C     B      - the value of the momentum flux correction coef. from the
C               table
C     DB     - derivative of B with respect to depth
C     ALP    - value of energy flux correction coefficient
C     DALP   - derivative wrt depth of the energy flux coefficient
C     QC     - critical flow
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'xscom.cmn'
      INCLUDE 'offcom.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER VTYPE(35)
      SAVE VTYPE
 
C     + + + LOCAL VARIABLES + + +
      INTEGER HA, L, LA, TYPE, XOFF
      REAL A0, ALP0, B0, DY, H, HH, J0, K0, P, QC0, QC1, T0, Y, Y0, Y1
      CHARACTER CS*16 
C     + + + INTRINSICS + + +
      INTRINSIC EXP, LOG
 
C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_STRING_FROM_FT
      EXTERNAL GET_STRING_FROM_FT, XSTYPE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA VTYPE/11*0,1,9*0,1,0,0,1,10*0/
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT(' ','*WRN:33* X-SECTION BELOW RANGE IN XLKT22',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
 2010 FORMAT(' ','*WRN:34* X-SECTION ABOVE RANGE IN XLKT22',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
C***********************************************************************
C     HA = HIGH ADDRESS
C     LA = LOW ADDRESS
C     L = ADDRESS FOUND ON THE LAST CALL TO XLKT22
 
      Y = YA
      HA = ITAB(ADRS)
      LA = ADRS + XTIOFF
      L = ITAB(ADRS+3)
 
      TYPE = ITAB(ADRS+2)
      XOFF = OFFVEC(TYPE)
      IF(VTYPE(TYPE).EQ.0) THEN
        CALL XSTYPE
     I             (STDOUT, VTYPE, ADRS)
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
      IF(Y.GE.FTAB(L)) THEN
C       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE
        IF(Y.GT.FTAB(HA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2010) CS, FTAB(ADRS+4), 
     A                       TIME, Y
          L = HA - XOFF
          Y = FTAB(HA)
          YA = Y
        ELSE
 100      CONTINUE
            IF(Y.GT.FTAB(L+XOFF)) THEN
              L = L + XOFF
              GOTO 100
            ENDIF
        ENDIF
      ELSE
C       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE
        IF(Y.LT.FTAB(LA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2000) CS, FTAB(ADRS+4), 
     A                       TIME, Y
          L = LA
          Y = FTAB(L+XOFF)
          YA = Y
        ELSE
 110      CONTINUE
            L = L - XOFF
            IF(Y.LT.FTAB(L)) GOTO 110
        ENDIF
      ENDIF
C     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE
C     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED
C     FOR ARGUMENT OUT OF RANGE.
 
C     RESET POINTER FOR LAST ADDRESS
 
      ITAB(ADRS+3) = L
 
C     FETCH VALUES FROM FTAB
 
      Y0 = FTAB(L)
      T0 = FTAB(L+1)
      A0 = FTAB(L+2)
      K0 = FTAB(L+3)
      B0 = FTAB(L+4)
      J0 = FTAB(L+5)
      ALP0 = FTAB(L+6)
      QC0 = FTAB(L+7)
 
C     DIRECT LINEAR INTERPOLATION FOR T AND SQRT(CONVEYANCE)
C     N.B. K IN FTAB IS SQRT(CONVEYANCE)
 
      Y1 = FTAB(L+XOFF)
      DY = Y1 - Y0
      H = Y - Y0
      HH = 0.5*H
      DB = (FTAB(L+XOFF+4) - B0)/DY
      DT =  (FTAB(L+XOFF+1) - T0)/DY
      DK = (FTAB(L+XOFF+3) - K0)/DY
      DALP = (FTAB(L+XOFF+6) - ALP0)/DY
      QC1 = FTAB(L+XOFF+7)
      T = T0 + H*DT
      B = B0 + H*DB
      ALP = ALP0 + H*DALP
      A = A0 + HH*(T + T0)
      J = J0 + HH*(A + A0 -H*(T - T0)/6.)
      K = K0 + H*DK
      DK = 2.*K*DK
      K = K*K
C     COMPUTE VALUE OF QC USING LOGARITHMS
 
      IF(Y0.EQ.0.0) THEN
        L = L + XOFF
        Y0 = FTAB(L)
        Y1 = FTAB(L+XOFF)
        QC0 = FTAB(L+7)
        QC1 = FTAB(L+XOFF+7)
      ENDIF
 
      IF(Y.GT.0.0) THEN
        P = LOG(Y/Y0)*LOG(QC1/QC0)/LOG(Y1/Y0)
        QC = QC0*EXP(P)
      ELSE
        QC = 0.0
      ENDIF
 
      RETURN
      END
C
C
C
      SUBROUTINE   XLKT23
     I                   (ADRS,
     M                    YA,
     O                    A, T, DT, K, DK, B, DB, MA, DMA, MQ, DMQ)
 
C     + + + PURPOSE + + +
C     Given depth, YA, compute the area, top width, derivative
C     of top width, DT, the conveyance, K, the derivative of conveyanc, DK,
C     the momentum flux correction coefficient, B, its
C     derivative, DB, the correction factor on area
C     to give volume per unit length for the distance axis, MA,
C     the derivative wrt depth of MA, DMA; the correction factor
C     on Q to give momentum per unit length for the distance
C     axis, MQ; and the derivative wrt depth of MQ, DMQ.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
      REAL A, B, DB, DK, DMA, DMQ, DT, K, MA, MQ, T, YA
 
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
C     MA     - weight factor on area to get volume per unit length
C     DMA    - derivative of the sinuosity correction of area wrt depth
C     MQ     - weight factor on flow to get momentum per unit length
C     DMQ    - derivative of the sinuosity correction of momentum wrt
C               depth
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'xscom.cmn'
      INCLUDE 'offcom.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER VTYPE(35)
      SAVE VTYPE
 
C     + + + LOCAL VARIABLES + + +
      INTEGER HA, IT, L, LA, TYPE, XOFF
      REAL B0, DY, DYI, H, HH, K0, MA0, MQ0, T0, Y, Y0
      CHARACTER CS*16
C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_STRING_FROM_FT
      EXTERNAL GET_STRING_FROM_FT, XSTYPE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA VTYPE/22*0,1,1,1,10*0/
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT(' ','*WRN:02* X-SECTION BELOW RANGE IN XLKT23',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
 2010 FORMAT(' ','*WRN:03* X-SECTION ABOVE RANGE IN XLKT23',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
C***********************************************************************
C     HA = HIGH ADDRESS
C     LA = LOW ADDRESS
C     L = ADDRESS FOUND ON THE LAST CALL TO XLKT23
 
      Y = YA
      HA = ITAB(ADRS)
      LA = ADRS + XTIOFF
      L = ITAB(ADRS+3)
 
      TYPE = ITAB(ADRS+2)
      XOFF = OFFVEC(TYPE)
      IF(VTYPE(TYPE).EQ.0) THEN
        CALL XSTYPE
     I             (STDOUT, VTYPE, ADRS)
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
      IF(Y.GE.FTAB(L)) THEN
C       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE
        IF(Y.GT.FTAB(HA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2010) CS, FTAB(ADRS+4), 
     A                       TIME, Y
          L = HA - XOFF
          Y = FTAB(HA)
          YA = Y
        ELSE
 100      CONTINUE
            IF(Y.GT.FTAB(L+XOFF)) THEN
              L = L + XOFF
              GOTO 100
            ENDIF
        ENDIF
      ELSE
C       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE
        IF(Y.LT.FTAB(LA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2000) CS, FTAB(ADRS+4), 
     A                       TIME, Y
          L = LA
          Y = FTAB(L+XOFF)
          YA = Y
        ELSE
 110      CONTINUE
            L = L - XOFF
            IF(Y.LT.FTAB(L)) GOTO 110
        ENDIF
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
      HH = 0.5*H
      DYI = 1.0/DY
      DB = (FTAB(IT+4) - B0)*DYI
      DT =  (FTAB(IT+1) - T0)*DYI
      DK = (FTAB(IT+3) - K0)*DYI
      T = T0 + H*DT
      B = B0 + H*DB
      A = FTAB(L+2) + HH*(T + T0)
      K = K0 + H*DK
      DK = (K +K)*DK
      K = K*K
 
      GOTO(23, 24, 25), TYPE-22
 
 23   CONTINUE
C       FIND THE CURVILINEAR ELEMENTS FROM TYPE 23
        MA0 = FTAB(L+5)
        MQ0 = FTAB(L+6)
        DMA = (FTAB(IT+5) - MA0)*DYI
        DMQ = (FTAB(IT+6) - MQ0)*DYI
        MA = MA0 + DMA*H
        MQ = MQ0 + DMQ*H
 
        RETURN
 
 24   CONTINUE
C       FIND THE CURVILINEAR ELEMENTS FROM TYPE 24
        MA0 = FTAB(L+6)
        MQ0 = FTAB(L+7)
        DMA = (FTAB(IT+6) - MA0)*DYI
        DMQ = (FTAB(IT+7) - MQ0)*DYI
        MA = MA0 + DMA*H
        MQ = MQ0 + DMQ*H
        RETURN

 25   CONTINUE
C       FIND THE CURVILINEAR ELEMENTS FROM TYPE 25
        MA0 = FTAB(L+8)
        MQ0 = FTAB(L+9)
        DMA = (FTAB(IT+8) - MA0)*DYI
        DMQ = (FTAB(IT+9) - MQ0)*DYI
        MA = MA0 + DMA*H
        MQ = MQ0 + DMQ*H
        RETURN
 
      END
C
C
C
      SUBROUTINE   XLKT24
     I                   (ADRS,
     M                    YA,
     O                    A, T, DT, J, K, DK, B, DB, MA, DMA, MQ, DMQ)
 
C     + + + PURPOSE + + +
C     Given depth find area, top-width, conveyance, etc.
C     using direct linear interpolation for top width.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
      REAL A, B, DB, DK, DMA, DMQ, DT, J, K, MA, MQ, T, YA
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB
C     YA     - depth to use for table look up
C     A      - Cross sectional area from the cross section table
C     T      - top width of the cross section
C     DT     - derivative of the top width with respect to depth
C     J      - first moment of area about water surface in the table
C     K      - conveyance
C     DK     - derivative of conveyance with respect to depth
C     B      - the value of the momentum flux correction coef. from the
C               table
C     DB     - derivative of B with respect to depth
C     MA     - weight factor on area to get volume per unit length
C     DMA    - derivative of the sinuosity correction of area wrt depth
C     MQ     - weight factor on flow to get momentum per unit length
C     DMQ    - derivative of the sinuosity correction of momentum wrt
C               depth
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'xscom.cmn'
      INCLUDE 'offcom.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER VTYPE(35)
      SAVE VTYPE
 
C     + + + LOCAL VARIABLES + + +
      INTEGER HA, IT, L, LA, TYPE, XOFF
      REAL A0, B0, DY, DYI, H, HH, J0, K0, MA0, MQ0, T0, Y, Y0
      CHARACTER CS*16
 
C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_STRING_FROM_FT
      EXTERNAL GET_STRING_FROM_FT, XSTYPE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA VTYPE/23*0,1,1,10*0/
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT(' ','*WRN:02* X-SECTION BELOW RANGE IN XLKT24',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
 2010 FORMAT(' ','*WRN:03* X-SECTION ABOVE RANGE IN XLKT24',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
C***********************************************************************
C     HA = HIGH ADDRESS
C     LA = LOW ADDRESS
C     L = ADDRESS FOUND ON THE LAST CALL TO XLKT24
 
      Y = YA
      HA = ITAB(ADRS)
      LA = ADRS + XTIOFF
      L = ITAB(ADRS+3)
 
      TYPE = ITAB(ADRS+2)
      XOFF = OFFVEC(TYPE)
      IF(VTYPE(TYPE).EQ.0) THEN
        CALL XSTYPE
     I             (STDOUT, VTYPE, ADRS)
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
      IF(Y.GE.FTAB(L)) THEN
C       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE
        IF(Y.GT.FTAB(HA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2010) CS, FTAB(ADRS+4), 
     A                       TIME, Y
          L = HA - XOFF
          Y = FTAB(HA)
          YA = Y
        ELSE
 100      CONTINUE
            IF(Y.GT.FTAB(L+XOFF)) THEN
              L = L + XOFF
              GOTO 100
            ENDIF
        ENDIF
      ELSE
C       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE
        IF(Y.LT.FTAB(LA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2000) CS, FTAB(ADRS+4), 
     A                       TIME, Y
          L = LA
          Y = FTAB(L+XOFF)
          YA = Y
        ELSE
 110      CONTINUE
            L = L - XOFF
            IF(Y.LT.FTAB(L)) GOTO 110
        ENDIF
      ENDIF
C     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE
C     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED
C     FOR ARGUMENT OUT OF RANGE.
 
C     RESET POINTER FOR LAST ADDRESS
 
      ITAB(ADRS+3) = L
 
C     FETCH VALUES FROM FTAB
 
      Y0 = FTAB(L)
      T0 = FTAB(L+1)
      A0 = FTAB(L+2)
      K0 = FTAB(L+3)
      B0 = FTAB(L+4)
      J0 = FTAB(L+5)
 
C     DIRECT LINEAR INTERPOLATION FOR T AND SQRT(CONVEYANCE)
C     N.B. K IN FTAB IS SQRT(CONVEYANCE)
 
      IT = L + XOFF
      DY = FTAB(IT) - Y0
      H = Y - Y0
      HH = 0.5*H
      DYI = 1.0/DY
      DB = (FTAB(L+XOFF+4) - B0)*DYI
      DT =  (FTAB(L+XOFF+1) - T0)*DYI
      DK = (FTAB(L+XOFF+3) - K0)*DYI
      T = T0 + H*DT
      B = B0 + H*DB
      A = A0 + HH*(T + T0)
      J = J0 + HH*(A + A0 - H*(T - T0)*0.1666667)
      K = K0 + H*DK
      DK = (K +K)*DK
      K = K*K
 
      IF(TYPE.EQ.24) THEN
C       FIND THE CURVILINEAR ELEMENTS FROM TYPE 24
        MA0 = FTAB(L+6)
        MQ0 = FTAB(L+7)
        DMA = (FTAB(IT+6) - MA0)*DYI
        DMQ = (FTAB(IT+7) - MQ0)*DYI
        MA = MA0 + DMA*H
        MQ = MQ0 + DMQ*H
      ELSE
C       FIND THE CURVILINEAR ELEMENTS FROM TYPE 25
        MA0 = FTAB(L+8)
        MQ0 = FTAB(L+9)
        DMA = (FTAB(IT+8) - MA0)*DYI
        DMQ = (FTAB(IT+9) - MQ0)*DYI
        MA = MA0 + DMA*H
        MQ = MQ0 + DMQ*H
      ENDIF
 
      RETURN
      END
C
C
C
      SUBROUTINE   XLKT25
     I                   (ADRS,
     M                    YA,
     O                    A, T, DT, J, K, DK, B, DB, ALP, DALP, QC, MA,
     O                    DMA, MQ, DMQ)
 
C     + + + PURPOSE + + +
C     Given the depth, YA, find: A-area; T-top width; DT- derivative
C     of top width; J-first moment of area about water surface;
C     K-conveyance; DK=derivative of conveyance; B- beta;
C     DB- derivative of beta; ALP-alpha;  DALP-derivative of
C     alpha;  QC, critical flow; MA= correction factor on area
C     to give volume per unit length for the distance axis;
C     DMA= derivative wrt depth of MA; MQ= correction factor
C     on Q to give momentum per unit length for the distance
C     axis; and DMQ= derivative wrt depth of MQ.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
      REAL A, ALP, B, DALP, DB, DK, DMA, DMQ, DT, J, K, MA, MQ, QC, T,
     A     YA
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB
C     YA     - depth to use for table look up
C     A      - Cross sectional area from the cross section table
C     T      - top width of the cross section
C     DT     - derivative of the top width with respect to depth
C     J      - first moment of area about water surface in the table
C     K      - conveyance
C     DK     - derivative of conveyance with respect to depth
C     B      - the value of the momentum flux correction coef. from the
C               table
C     DB     - derivative of B with respect to depth
C     ALP    - value of energy flux correction coefficient
C     DALP   - derivative wrt depth of the energy flux coefficient
C     QC     - critical flow
C     MA     - weight factor on area to get volume per unit length
C     DMA    - derivative of the sinuosity correction of area wrt depth
C     MQ     - weight factor on flow to get momentum per unit length
C     DMQ    - derivative of the sinuosity correction of momentum wrt
C               depth
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'xscom.cmn'
      INCLUDE 'offcom.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER VTYPE(35)
      SAVE VTYPE
 
C     + + + LOCAL VARIABLES + + +
      INTEGER HA, L, LA, TYPE, XOFF
      REAL A0, ALP0, B0, DY, H, HH, J0, K0, MA0, MQ0, P, QC0, QC1, T0,
     A     Y, Y0, Y1
      CHARACTER CS*16 
C     + + + INTRINSICS + + +
      INTRINSIC EXP, LOG
 
C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_STRING_FROM_FT
      EXTERNAL  GET_STRING_FROM_FT, XSTYPE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA VTYPE/24*0,1,10*0/
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT(' ','*WRN:33* X-SECTION BELOW RANGE IN XLKT25',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
 2010 FORMAT(' ','*WRN:34* X-SECTION ABOVE RANGE IN XLKT25',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
C***********************************************************************
C     HA = HIGH ADDRESS
C     LA = LOW ADDRESS
C     L = ADDRESS FOUND ON THE LAST CALL TO XLKT25
 
      Y = YA
      HA = ITAB(ADRS)
      LA = ADRS + XTIOFF
      L = ITAB(ADRS+3)
 
      TYPE = ITAB(ADRS+2)
      XOFF = OFFVEC(TYPE)
      IF(VTYPE(TYPE).EQ.0) THEN
        CALL XSTYPE
     I             (STDOUT, VTYPE, ADRS)
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
      IF(Y.GE.FTAB(L)) THEN
C       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE
        IF(Y.GT.FTAB(HA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2010) CS, FTAB(ADRS+4), 
     A                       TIME, Y
          L = HA - XOFF
          Y = FTAB(HA)
          YA = Y
        ELSE
 100      CONTINUE
            IF(Y.GT.FTAB(L+XOFF)) THEN
              L = L + XOFF
              GOTO 100
            ENDIF
        ENDIF
      ELSE
C       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE
        IF(Y.LT.FTAB(LA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2000) CS, FTAB(ADRS+4), 
     A                       TIME, Y
          L = LA
          Y = FTAB(L+XOFF)
          YA = Y
        ELSE
 110      CONTINUE
            L = L - XOFF
            IF(Y.LT.FTAB(L)) GOTO 110
        ENDIF
      ENDIF
C     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE
C     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED
C     FOR ARGUMENT OUT OF RANGE.
 
C     RESET POINTER FOR LAST ADDRESS
 
      ITAB(ADRS+3) = L
 
C     FETCH VALUES FROM FTAB
 
      Y0 = FTAB(L)
      T0 = FTAB(L+1)
      A0 = FTAB(L+2)
      K0 = FTAB(L+3)
      B0 = FTAB(L+4)
      J0 = FTAB(L+5)
      ALP0 = FTAB(L+6)
      QC0 = FTAB(L+7)
      MA0 = FTAB(L+8)
      MQ0 = FTAB(L+9)
 
C     DIRECT LINEAR INTERPOLATION FOR T AND SQRT(CONVEYANCE)
C     N.B. K IN FTAB IS SQRT(CONVEYANCE)
 
      Y1 = FTAB(L+XOFF)
      DY = Y1 - Y0
      H = Y - Y0
      HH = 0.5*H
      DB = (FTAB(L+XOFF+4) - B0)/DY
      DT =  (FTAB(L+XOFF+1) - T0)/DY
      DK = (FTAB(L+XOFF+3) - K0)/DY
      DALP = (FTAB(L+XOFF+6) - ALP0)/DY
      QC1 = FTAB(L+XOFF+7)
      DMA = (FTAB(L+XOFF+8) - MA0)/DY
      DMQ = (FTAB(L+XOFF+9) - MQ0)/DY
      T = T0 + H*DT
      B = B0 + H*DB
      ALP = ALP0 + H*DALP
      MA = MA0 + H*DMA
      MQ = MQ0 + H*DMQ
      A = A0 + HH*(T + T0)
      J = J0 + HH*(A + A0 -H*(T - T0)/6.)
      K = K0 + H*DK
      DK = 2.*K*DK
      K = K*K
C     COMPUTE VALUE OF QC USING LOGARITHMS
 
      IF(Y0.EQ.0.0) THEN
        L = L + XOFF
        Y0 = FTAB(L)
        Y1 = FTAB(L+XOFF)
        QC0 = FTAB(L+7)
        QC1 = FTAB(L+XOFF+7)
      ENDIF
 
      IF(Y.GT.0.0) THEN
        P = LOG(Y/Y0)*LOG(QC1/QC0)/LOG(Y1/Y0)
        QC = QC0*EXP(P)
      ELSE
        QC = 0.0
      ENDIF
 
      RETURN
      END
C
C
C
      SUBROUTINE   XLKTAL
     I                   (ADRS,
     M                    YA,
     O                    A, T, DT, J, K, DK, B, DB, ALP, DALP)
 
C     + + + PURPOSE + + +
C     Given the depth, YA, find: A-area; T-top width; DT- derivative
C     of top width; J-first moment of area about water surface;
C     K-conveyance; DK=derivative of conveyance; B- beta;
C     DB- derivative of beta; ALP-alpha; and DALP-derivative of
C     alpha.  QC is in the table but not looked up or returned.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
      REAL A, ALP, B, DALP, DB, DK, DT, J, K, T, YA
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - address of the function table in FTAB/ITAB
C     YA     - depth to use for table look up
C     A      - Cross sectional area from the cross section table
C     T      - top width of the cross section
C     DT     - derivative of the top width with respect to depth
C     J      - first moment of area about water surface in the table
C     K      - conveyance
C     DK     - derivative of conveyance with respect to depth
C     B      - the value of the momentum flux correction coef. from the
C               table
C     DB     - derivative of B with respect to depth
C     ALP    - value of energy flux correction coefficient
C     DALP   - derivative wrt depth of the energy flux coefficient
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'xscom.cmn'
      INCLUDE 'offcom.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER VTYPE(35)
      SAVE VTYPE
 
C     + + + LOCAL VARIABLES + + +
      INTEGER HA, L, LA, TYPE, XOFF
      REAL A0, ALP0, B0, DY, H, HH, J0, K0, T0, Y, Y0
      CHARACTER CS*16
 
C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_STRING_FROM_FT
      EXTERNAL  GET_STRING_FROM_FT, XSTYPE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA VTYPE/21*0,1,0,0,1,10*0/
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT(' ','*WRN:31* X-SECTION BELOW RANGE IN XLKTAL',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
 2010 FORMAT(' ','*WRN:32* X-SECTION ABOVE RANGE IN XLKTAL',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F14.0,
     D      /,1X,' DEPTH          = ',F10.2)
C***********************************************************************
C     HA = HIGH ADDRESS
C     LA = LOW ADDRESS
C     L = ADDRESS FOUND ON THE LAST CALL TO XLKTAL
 
      Y = YA
      HA = ITAB(ADRS)
      LA = ADRS + XTIOFF
      L = ITAB(ADRS+3)
 
      TYPE = ITAB(ADRS+2)
      XOFF = OFFVEC(TYPE)
      IF(VTYPE(TYPE).EQ.0) THEN
        CALL XSTYPE
     I             (STDOUT, VTYPE, ADRS)
        STOP 'Abnormal stop: errors found.'
      ENDIF
      IF(Y.GE.FTAB(L)) THEN
C       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE
        IF(Y.GT.FTAB(HA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2010) CS, FTAB(ADRS+4), 
     A                       TIME, Y
          L = HA - XOFF
          Y = FTAB(HA)
          YA = Y
        ELSE
 100      CONTINUE
            IF(Y.GT.FTAB(L+XOFF)) THEN
              L = L + XOFF
              GOTO 100
            ENDIF
        ENDIF
      ELSE
C       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE
        IF(Y.LT.FTAB(LA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(STDOUT,2000) CS, FTAB(ADRS+4), 
     A                       TIME, Y
          L = LA
          Y = FTAB(L+XOFF)
          YA = Y
        ELSE
 110      CONTINUE
            L = L - XOFF
            IF(Y.LT.FTAB(L)) GOTO 110
        ENDIF
      ENDIF
C     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE
C     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED
C     FOR ARGUMENT OUT OF RANGE.
 
C     RESET POINTER FOR LAST ADDRESS
 
      ITAB(ADRS+3) = L
 
C     FETCH VALUES FROM FTAB
 
      Y0 = FTAB(L)
      T0 = FTAB(L+1)
      A0 = FTAB(L+2)
      K0 = FTAB(L+3)
      B0 = FTAB(L+4)
      J0 = FTAB(L+5)
      ALP0 = FTAB(L+6)
 
C     DIRECT LINEAR INTERPOLATION FOR T AND SQRT(CONVEYANCE)
C     N.B. K IN FTAB IS SQRT(CONVEYANCE)
 
      DY = FTAB(L+XOFF) - Y0
      H = Y - Y0
      HH = 0.5*H
      DB = (FTAB(L+XOFF+4) - B0)/DY
      DT =  (FTAB(L+XOFF+1) - T0)/DY
      DK = (FTAB(L+XOFF+3) - K0)/DY
      DALP = (FTAB(L+XOFF+6) - ALP0)/DY
      T = T0 + H*DT
      B = B0 + H*DB
      ALP = ALP0 + H*DALP
      A = A0 + HH*(T + T0)
      J = J0 + HH*(A + A0 -H*(T - T0)/6.)
      K = K0 + H*DK
      DK = 2.*K*DK
      K = K*K
 
      RETURN
      END
C
C
C
      SUBROUTINE   LKTQC
     I                  (ADRS,
     M                   YA,
     O                   QC)
 
C     + + + PURPOSE + + +
C     Given depth lookup critical flow.
 
      IMPLICIT NONE

C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS
      REAL QC, YA
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     ADRS   - Address of function table
C     YA     - maximum depth in a cross section
C     QC     - Critical flow
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'xscom.cmn'
      INCLUDE 'offcom.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER VTYPE(35)
      SAVE VTYPE
 
C     + + + LOCAL VARIABLES + + +
      INTEGER HA, L, LA, TYPE, XOFF
      REAL DY, P, QC0, QC1, Y, Y0, Y1
      CHARACTER CS*16
      
C     + + + INTRINSICS + + +
      INTRINSIC EXP, LOG
 
C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_STRING_FROM_FT
      EXTERNAL GET_STRING_FROM_FT, XSTYPE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA VTYPE/11*0,1,9*0,1,0,0,1,10*0/
 
C     + + + OUTPUT FORMATS + + +
 2000 FORMAT('0','*WRN:35* X-SECTION BELOW RANGE IN LKTQC',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F10.0,
     D      /,1X,' DEPTH          = ',F10.2)
 2010 FORMAT('0','*WRN:36* X-SECTION ABOVE RANGE IN LKTQC',
     A      /,1X,' TABLE ID   = ',A,
     B      /,1X,' STATION NUMBER = ',F10.3
     C      /,1X,' TIME           = ',F10.0,
     D      /,1X,' DEPTH          = ',F10.2)
C***********************************************************************
C     HA = HIGH ADDRESS
C     LA = LOW ADDRESS
C     L = ADDRESS FOUND ON THE LAST CALL TO XLOOKY
 
      Y = YA
      HA = ITAB(ADRS)
      LA = ADRS + XTIOFF
      L = ITAB(ADRS+3)
 
      TYPE = ITAB(ADRS+2)
      XOFF = OFFVEC(TYPE)
      IF(VTYPE(TYPE).EQ.0) THEN
        CALL XSTYPE
     I             (LOUT, VTYPE, ADRS)
        STOP 'Abnormal stop.  Errors found.'
      ENDIF
 
      IF(Y.GE.FTAB(L)) THEN
C       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE
        IF(Y.GT.FTAB(HA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(LOUT,2010) CS, FTAB(ADRS+4), 
     A                     TIME, Y
          L = HA - XOFF
          Y = FTAB(HA)
          YA = Y
        ELSE
 100      CONTINUE
            IF(Y.GT.FTAB(L+XOFF)) THEN
              L = L + XOFF
              GOTO 100
            ENDIF
        ENDIF
      ELSE
C       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE
        IF(Y.LT.FTAB(LA)) THEN
          CS = GET_STRING_FROM_FT(ADRS+16)
          WRITE(LOUT,2000) CS, FTAB(ADRS+4), 
     A                     TIME, Y
          L = LA
          Y = FTAB(L+XOFF)
          YA = Y
        ELSE
 110      CONTINUE
            L = L - XOFF
            IF(Y.LT.FTAB(L)) GOTO 110
        ENDIF
      ENDIF
C     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE
C     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED
C     FOR ARGUMENT OUT OF RANGE.
 
C     RESET POINTER FOR LAST ADDRESS
 
      ITAB(ADRS+3) = L
 
C     FETCH VALUES FROM FTAB
 
      Y0 = FTAB(L)
      QC0 = FTAB(L+7)
 
C     DIRECT LINEAR INTERPOLATION FOR T AND SQRT(CONVEYANCE)
C     N.B. K IN FTAB IS SQRT(CONVEYANCE)
 
      Y1 = FTAB(L+XOFF)
      DY = Y1 - Y0
 
      QC1 = FTAB(L+XOFF+7)
 
C     COMPUTE VALUE OF QC USING LOGARITHMS
 
      IF(Y0.EQ.0.0) THEN
        L = L + XOFF
        Y0 = FTAB(L)
        Y1 = FTAB(L+XOFF)
        QC0 = FTAB(L+7)
        QC1 = FTAB(L+XOFF+7)
      ENDIF
 
      P = LOG(Y/Y0)*LOG(QC1/QC0)/LOG(Y1/Y0)
      QC = QC0*EXP(P)
 
      RETURN
      END
C
C
C
      SUBROUTINE   XSECIN
     I                   (IN, STDOUT, MLFT, NTAB, OUTPUT,
     M                    EFLAG, FTP, TYPE)
 
C     + + + PURPOSE + + +
C     Input a cross-section table.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, FTP, IN, STDOUT, MLFT, NTAB, OUTPUT, TYPE
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     STDOUT   - Fortran unit number for user output and messages
C     MLFT   - maximum length of FTAB/ITAB
C     NTAB   - table number
C     OUTPUT - output level for diagnostic work
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
C     FTP    - next open location in the function table storage
C     TYPE   - table type
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
      INCLUDE 'offcom.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER FORM(25), HDLEN(25)
      CHARACTER INFORM(6)*51, PRFORM(6)*63
      SAVE FORM, HDLEN, INFORM, PRFORM
 
C     + + + LOCAL VARIABLES + + +
      INTEGER FORMID, FTPOLD, HEADL, J, OUT, XOFF
      REAL CUTOFF, DROP, ELEM(10), ELEV, EXT, FAC, KHOLD, STAT,
     A     SLOT_DEPTH
      REAL*8 EASTING, NORTHING     
      CHARACTER HEAD*112, LINE*112, GISID*16, TABID*16
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS, SQRT
 
C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_TABID
      EXTERNAL EXTRAP, INL112, INL80, KIL, PUT_DP_IN_FT,
     A         PUT_STRING_IN_FT, GET_TABID
 
C     + + + DATA INITIALIZATIONS + + +
      DATA  FORM/2,10*0,3,7*0,1,2,3,4,5,6/,
     A     HDLEN/80,10*0,92,7*0,80,80,92,80,92,112/
      DATA INFORM/
     1'(F10.0,F10.0,2E13.0,F10.0)',
     2'(F10.0,F10.0,2E13.0,F10.0,E13.0)',
     3'(F10.0,F10.0,2E13.0,F10.0,E13.0,F10.0,E13.0)',
     4'(F10.0,F10.0,2E13.0,3F10.0)',
     5'(F10.0,F10.0,2E13.0,F10.0,E13.0,2F10.0)',
     6'(F10.0,F10.0,2E13.0,F10.0,E13.0,F10.0,E13.0,2F10.0)'/
      DATA PRFORM/
     1'(F10.5,F10.3,1P2E13.5,0PF10.4)',
     2'(F10.5,F10.3,1P2E13.5,0PF10.4,1PE13.5)',
     3'(F10.5,F10.3,1P2E13.5,0PF10.4,1PE13.5,0PF10.4,1PE13.5)',
     4'(F10.5,F10.3,1P2E13.5,0P3F10.4)',
     5'(F10.5,F10.3,1P2E13.5,0PF10.4,1PE13.5,0P2F10.4)',
     6'(F10.5,F10.3,1P2E13.5,0PF10.4,1PE13.5,0PF10.4,1PE13.5,0P2F10.4)'/
 
C     + + + INPUT FORMATS + + +
 1    FORMAT(A)
 40   FORMAT(8X,E12.0,7X,A16,9X,F15.0,10X,F15.0)
 39   FORMAT(8X,E12.0)
 42   FORMAT(10X,E12.0,7X,F10.0,5X,F10.0,5X,F5.0,6X,F10.0)
 
C     + + + OUTPUT FORMATS + + +
 41   FORMAT(' ','STATION=',F10.3,' GISID=',A16,' EASTING=',F15.3,
     A         ' NORTHING=',F15.3)
 43   FORMAT(' ','ELEVATION=',F10.2,' CUTOFF=',F10.2,' EXT=',F10.2,
     1  ' FAC=',F5.3,' SLOT=',F10.3)
 46   FORMAT(/,' *WRN:09* CONVEYANCE NONINCREASING AT DEPTH=',F8.3)
 48   FORMAT(/,' *WRN:11* DROP OF',F4.0, ' PER CENT IN CONVEYANCE',
     A       ' AT DEPTH=',F8.3)
 76   FORMAT(/,' *BUG:XXX* Type=',I3,' has zero offset in XSECIN.')
C***********************************************************************
C     The values in each of the 8 tables are in the following
C     order in the tables.  This is also the order in which the
C     values are stored in FTAB.
 
C              Cross Section Function Table Type
C     Order   1   12   20   21   22   23   24   25
C       1     Y    Y    Y    Y    Y    Y    Y    Y
C       2     T    T    T    T    T    T    T    T
C       3     A    A    A    A    A    A    A    A
C       4    KH   KH   KH   KH   KH   KH   KH   KH
C       5     B    B    B    B    B    B    B    B
C       6     J    J    -    J    J   MA    J    J
C       7     -  ALP    -    -  ALP   MQ   MA  ALP
C       8     -   QC    -    -   QC    -   MQ   QC
C       9     -    -    -    -    -    -    -   MA
C      10     -    -    -    -    -    -    -   MQ
C      In this table Y= maximum depth in the section; T= top
C      width of the wetted area; A= the wetted area;, KH=
C      square root of conveaycne; B= momentum flux coefficient;
C      J= first moment of area about the water surface;
C      ALP= kinetic energy flux coefficient; QC= critical flow;
C      MA= weight factor to convert A to the water volume per
C      unit length along the distance axis; and MQ= the weight
C      factor to convert flowrate(Q) to momentum per unit
C      length along the distance axis.  Note: Table types 1 and
C      12 are the same as types 21 and 22.  Types 1 and 12 are
C      being phased out.  They are given the new type numbers when
C      they are encountered during input.
 
      OUT = OUTPUT
      IF(TYPE.LT.0) THEN
       OUT = 0
        TYPE = -TYPE
      ENDIF
      FORMID = FORM(TYPE)
      HEADL = HDLEN(TYPE)
      XOFF = OFFVEC(TYPE)
      IF(XOFF.EQ.0) THEN
        WRITE(STDOUT,76) TYPE
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
      CALL INL112
     I          (IN, STDOUT,
     O           LINE)
      IF(LINE(26:31).EQ.'Interp') THEN
        READ(LINE,39, ERR=991) STAT
        GISID = ' '
        EASTING = 0.D0
        NORTHING = 0.D0
      ELSE
        READ(LINE,40,ERR=991) STAT, GISID, EASTING, NORTHING
      ENDIF
      IF(OUT.GT.0) WRITE(STDOUT,41) STAT, GISID, EASTING, NORTHING
 
      CALL INL80
     I          (IN, STDOUT,
     O           LINE)
      READ(LINE,42,ERR=991) ELEV, CUTOFF, EXT, FAC, SLOT_DEPTH
 
C     CHECK FOR ZERO VALUE OF FAC AND SET DEFAULT OF UNITY
 
      IF(FAC.EQ.0.0) FAC = 1.0
      IF(OUT.GT.0) WRITE(STDOUT,43) ELEV, CUTOFF, EXT, FAC, SLOT_DEPTH
 
C     CHANGE THE FACTOR TO APPLY TO THE SQRT OF CONVEYANCE
 
      FAC = SQRT(FAC)
 
      IF((FTP+XOFF).GE.MLFT) CALL KIL
     I                                (10,
     M                                 FTP, EFLAG)
 
      ITAB(FTP+1) = NTAB
      ITAB(FTP+2) = ABS(TYPE)
 
C     SET INITIAL ADDRESS FOR TABLE LOOK UP
 
      ITAB(FTP+3) = FTP + XTIOFF
      FTAB(FTP+4) = STAT
      FTAB(FTP+5) = ELEV
      FTAB(FTP+7) = SLOT_DEPTH
      CALL PUT_DP_IN_FT(FTP+8, EASTING)
      CALL PUT_DP_IN_FT(FTP+10, NORTHING)
      CALL PUT_STRING_IN_FT(FTP+12, GISID)
      TABID = GET_TABID(NTAB)
      CALL PUT_STRING_IN_FT(FTP+16, TABID)

C     Set the source flag to input source
      ITAB(FTP+20) = 0

      FTPOLD = FTP
C     POINT TO FIRST DEPTH ENTRY IN THE TABLE
      FTP = FTP + XTIOFF
 
 
      CALL INL112
     I           (IN, STDOUT,
     O            LINE)
      READ(LINE,1) HEAD(1:HEADL)
      IF(OUT.GT.0)  WRITE(STDOUT,'(A)') HEAD(1:HEADL)
 
C       SET OLD VALUES
 
        KHOLD = -1.
 
 1000 CONTINUE
        CALL INL112
     I             (IN, STDOUT,
     O              LINE)
        READ(LINE,INFORM(FORMID),ERR=991) (ELEM(J),J=1,XOFF)
 
C       CHECK FOR THE END OF THE TABLE
        IF(ELEM(1).LT.0.0) GOTO 1500
 
C       SUPPORT THE CUTOFF OPTION.  NOT USED RECENTLY.
        IF(ELEM(1).LT.CUTOFF) GOTO 1000
 
C       APPLY THE FACTOR ADJUSTMENT TO THE SQRT OF CONVEYANCE
 
        ELEM(4) = ELEM(4)/FAC
        IF(OUT.GT.0) THEN
          WRITE(STDOUT,PRFORM(FORMID)) (ELEM(J), J=1,XOFF)
        ENDIF
 
C       CHECK FOR ROOM IN FTAB
        IF((FTP+XOFF).GE.MLFT) CALL KIL
     I                                  (10,
     M                                   FTP, EFLAG)
 
C       STORE IN FTAB
        DO 1010 J=1,XOFF
          FTAB(FTP+J-1) = ELEM(J)
 1010   CONTINUE
        FTP = FTP + XOFF
 
C       CHECK FOR NONINCREASING CONVEYANCE
 
        IF(ELEM(4).LE.KHOLD) THEN
          IF(KHOLD.GT.0.0.AND.ELEM(2).GT.0.1) THEN
            DROP = -(ELEM(4)**2 - KHOLD**2)/KHOLD**2
            IF(DROP.GT.0.005) WRITE(STDOUT,48) DROP*100., ELEM(1)
          ELSE
           WRITE(STDOUT,46) ELEM(1)
          ENDIF
        ENDIF
        KHOLD = ELEM(4)
 
         GOTO 1000
 1500 CONTINUE
 
C     SAVE THE UNEXTRAPOLATED MAXIMUM ARGUMENT IN THE TABLE
C     FOR CHECKING THE MAXIMUM RESULTS.
 
      FTAB(FTPOLD+6) = FTAB(FTP-XOFF)
 
C     CALL EXTRAPOLATION IF NEEDED
 
      IF(EXT.NE.0.0) CALL EXTRAP
     I                          (TYPE, XOFF, MLFT,
     M                           EFLAG, EXT, FTP)
 
C     STORE THE HIGH ADDRESS FOR RUN TIME CHECKING
 
      ITAB(FTPOLD) = FTP - XOFF
      RETURN
 
 991  CONTINUE
        WRITE(STDOUT,*) ' *ERR:500* Conversion error in line:'
        WRITE(STDOUT,'(A)') LINE(1:HEADL)
        STOP 'Abnormal stop: errors found.'
      END
C
C
C
      SUBROUTINE   XSTYPE
     I                   (STDOUT, VTYPE, ADRS)
 
C     + + + PURPOSE + + +
C     Dump valid list of cross section table types.
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER STDOUT, ADRS
      INTEGER VTYPE(*)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     VTYPE  - list of valid cross section table types
C     ADRS    - address of the cross section table
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I
      CHARACTER CS*16

C     Called program units
      CHARACTER*16 GET_STRING_FROM_FT
      EXTERNAL GET_STRING_FROM_FT
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT('0*ERR:195* Data deficiency in Tabid= ',A,' Valid Types:')
 52   FORMAT(11X,'Type=',I5)
C***********************************************************************
      CS = GET_STRING_FROM_FT(ADRS+16)
      WRITE(STDOUT,50) CS
      DO 100 I=1,35
        IF(VTYPE(I).GT.0) THEN
          WRITE(STDOUT,52) I
        ENDIF
 100  CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE   TSTSOW
     I                   (H1, H4, HG, H1FW, H4FW, H4SW,
     O                    FLAG)
 
C     + + + PURPOSE + + +
C     Test for being in the SO flow region that exists above the
C     the SW flow region.  On entry H1 is known to be between
C     H1FW and HG.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER FLAG
      REAL H1, H1FW, H4, H4FW, H4SW, HG
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     H1     - head at section 1
C     H4     - head at section 4
C     HG     - underflow gate opening
C     H1FW   - head at section 1 at the limit of FW flow
C     H4FW   - head at section 4 at the limit of FW flow
C     H4SW   - head at section 4 when the head at section 1 is
C              at the mid-point of the special SO region
C     FLAG   - flag for being in the special SO region
 
C     + + + LOCAL VARIABLES + + +
      REAL H1SW, H4STAR
C***********************************************************************
      H1SW = 0.5*(HG + H1FW)
 
      IF(H1.LE.H1SW) THEN
        H4STAR = HG + (H1 - HG)*(H4SW - HG)/(H1SW - HG)
      ELSE
        H4STAR = H4SW + (H1 - H1SW)*(H4FW - H4SW)/(H1FW - H1SW)
      ENDIF
      IF(H4.GT.H4STAR) THEN
C       The point is in the special SO region.
        FLAG = 1
      ELSE
        FLAG = 0
      ENDIF
      RETURN
      END
