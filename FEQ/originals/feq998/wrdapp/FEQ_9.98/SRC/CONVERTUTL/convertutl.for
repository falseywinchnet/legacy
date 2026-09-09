C     ***********
C     *         *
C     * CONVERTUTL
C     *         *
C     ***********

C     Utility program to convert an FEQUTL input file to the
C     new form for version 9.5 and later.

      PROGRAM CONVERTUTL

      IMPLICIT NONE
      CHARACTER*64 FNAME1, FNAME2
      CHARACTER LINE*192, FNAME*64, CHAR4*4, CHAR5*5, HLCRITC*5,
     A          HLMAXC*5,NODEID*4, LINE2*192

      LOGICAL THERE
      
      INTEGER IOFLAG, MORG, STDIN, STDOUT, I, J, N, IS, TABLE, PNT,
     A        UNIT, JJ, LIM, NSUB, JE, JS, NARG, TYPE, LAST,
     B        DEPTAB, BEGTAB, NODE

      REAL  FAC, MN(100), HLCRIT, HLMAX, HSCALE, VSCALE, CSHIFT,
     A      RMFFAC

      INCLUDE 'stdun.cmn'

C     Program units.

      INTEGER GET_UNIT, IARGC, LENSTR

      EXTERNAL GET_UNIT, IARGC, GETARG, INITIALIZE_UNITS,
     A         STRIP_L_BLANKS
C     ***********************Formats************************************
 3    FORMAT(A4,I5,6F10.0)
 31   FORMAT(9X,6F10.0)
50    FORMAT('*ERR:XXX* Value of MORG wrong. Must be 0 or 1.')
54    FORMAT(1X,A)
56    FORMAT(/,' *ERR:XXX* Command:',A,' unknown.')
58    FORMAT(/,' Utility to convert FEQUTL Inputs',/,
     A         ' Version: 0.9 Beta',/,
     B         ' July 30, 1999')
80    FORMAT('NSUB',I5,6F10.3)
81    FORMAT(9X,6F10.3)
C***********************************************************************
C
C     Utility program to convert an FEQUTL input file to the
C     form required by version 9.5 and later

C     Set the command line argument offset.  This must be zero
C     for UNIX systems and the IARGC and GETARG program units
C     must be removed. 

      MORG = 1

C     Initialize the system for keeping track of unit numbers for 
C     Fortran I/O.  We assume this program will not be used with
C     main-frame computers that still have the old method of
C     dealing with files. 

      CALL INITIALIZE_UNITS

C     Get some IO units.  Note that in these two calls, that STDOUT
C     is invalid.  However, there should always be space for at least
C     two units.  In fact the default for number of units is always in
C     the 100's.

      STDIN = GET_UNIT (STDOUT)
      STDOUT = GET_UNIT (STDOUT)
      STD5 = STDIN
      STD6 = STDOUT

      IF(MORG.LT.0.OR.MORG.GT.1) THEN
        WRITE(*,50)
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
C     PROCESS COMMAND LINE ARGUMENTS
 
      NARG = IARGC()
      IF(NARG-MORG.LT.2) THEN
        WRITE(*,*) ' Too few arguments'
        WRITE(*,*) ' Give the input file name and the output file name'
        WRITE(*,*) ' after the command name with spaces used as'
        WRITE(*,*) ' delimiters like this: convert input output'
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
C     GET THE FIRST FILE ARGUMENT
 
      CALL GETARG (1+MORG,
     O            FNAME1)
 
      INQUIRE(FILE=FNAME1, EXIST=THERE)
      IF(THERE) THEN
        OPEN(STDIN, FILE = FNAME1, STATUS = 'OLD')
      ELSE
        WRITE(*,*) ' File named:',FNAME1,' not found.'
        WRITE(*,*) ' Please check spelling of input file name used.'
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
C     GET THE SECOND FILE ARGUMENT
 
      CALL GETARG (2+MORG,
     O            FNAME2)
      IF(FNAME1.EQ.FNAME2) THEN
        WRITE(*,*) ' Input and output file cannot be the same'
        STOP 'Abnormal stop: errors found.'
      ENDIF

      OPEN(STDOUT, FILE = FNAME2, STATUS = 'UNKNOWN', IOSTAT=IOFLAG)
 
      IF(IOFLAG.NE.0) THEN
        WRITE(*,*) ' Problem in opening file: ',FNAME2
        WRITE(*,*) ' Check path for output file.'
        STOP 'Abnormal stop: errors found.'
      ENDIF


      WRITE(*,*) ' '
      WRITE(*,58)
      WRITE(*,*) ' '

C     Now that we have the files opened and they seem to exist,
C     we can start processing the input. 

C     Scan for EPSF to skip over the header that contains some names
C     that could cause problems.
100   CONTINUE
        READ(STDIN,'(A)') LINE
        WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
        IF(LINE(1:4).NE.'EPSF') GOTO 100      


1000  CONTINUE
C       Transfer records unchanged except for stripping trailing
C       blanks while searching for the start of various blocks that
C       require changes
        CALL  INL192
     I              (STDIN, STDOUT,
     O                 LINE)
        IF(LINE(1:7).EQ.'ENDFILE') GOTO 10000
        N = LENSTR(LINE)

        IF(LINE(1:6).EQ.'FTABIN') THEN

C         Find and change references to files
          WRITE(STDOUT,'(A)') LINE(1:N)

2000      CONTINUE                                                                
            CALL  INL192
     I                  (STDIN, STDOUT,
     O                     LINE)
            N = LENSTR(LINE)
            IF(LINE(1:6).EQ.'TABLE#') THEN
              READ(LINE,'(7X,I5,A64)',ERR=991)  UNIT, FNAME

              IF(UNIT.LT.-1) THEN
C               This is a reference to a file name.  FNAME should be non-blank
                IF(FNAME.EQ.' ') THEN
                WRITE(STDOUT,*) ' File name expected but blanks found!'
                  STOP 'Abnormal stop.  File name not found.'
                ELSE
C                 Output the line in the new format
                  WRITE(STDOUT,'(''FILE= '',A)') FNAME(1:LENSTR(FNAME))
                ENDIF
              ELSE
                WRITE(STDOUT,'(A)') LINE(1:N)
               
              ENDIF
              IF(UNIT.EQ.-1) GOTO 9999
            ELSE
              WRITE(STDOUT,'(A)') LINE(1:N)
            ENDIF
            GOTO 2000 

        ELSEIF(LINE(1:5).EQ.'FEQX '.OR.LINE(1:5).EQ.'FEQXL') THEN

C         Correct potential problems with NSUB processing as well as
C         making sure the STATION value is non-blank.

          WRITE(STDOUT,'(A)') LINE(1:N)

3000      CONTINUE
            CALL INL192
     I              (STDIN, STDOUT,
     O               LINE)


            IF(LINE(1:7).EQ.'STATION') THEN
              IF(LINE(9:18).EQ.' ') THEN
                LINE(9:18) = '       0.0'
                WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
              ELSE
                WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
              ENDIF
            ELSEIF(LINE(1:4).EQ.'NSUB') THEN

C             Correct the standard format for NSUB.  Free format may be 
C             detected but could cause problems.  However, if NSUB is free format
C             it will not need correction. 
              READ(LINE,3,ERR=3999) CHAR4, NSUB, (MN(J),J=1,MIN(6,NSUB))
              IF(NSUB.EQ.0) THEN
C               We assume that line is not in the old format and is ok.
                WRITE(STDOUT,'(A)') 
     A           ';  NSUB line not in old format but assumed to be ok.'
                WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
                GOTO 9999
              ENDIF            
              DO 130 JJ=7,NSUB,6
                LIM = NSUB - JJ
                IF(LIM.GT.5) LIM = 5
                CALL INL192
     I                  (STDIN, STDOUT,
     O                   LINE)
                READ(LINE,31,ERR=991) (MN(JJ+J), J=0,LIM)
 130          CONTINUE
          
          
              JE = MIN(NSUB, 6)
          
              WRITE(STDOUT,80) NSUB, (MN(J), J=1,JE)
              IF(JE.LT.NSUB) THEN
                I = 7
225             CONTINUE
                  JS = I
                  JE = MIN(NSUB, I+5)
                  WRITE(STDOUT,81) (MN(J), J=JS,JE)
                  I = I + 6
                  IF(JE.LT.NSUB) GOTO 225
              ENDIF

C             When NSUB is processed, jump out to the main loop
              GOTO 9999
            ELSE
              WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
            ENDIF
            GOTO 3000
3999        CONTINUE
C             Branch here on read error.  We will assume that the format
C             is the new format and thus does not need conversion
              WRITE(STDOUT,'(A)') 
     A           ';  NSUB line not in old format but assumed to be ok.'
              WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
              GOTO 9999
        ELSEIF(LINE(1:7).EQ.'EMBANKQ') THEN
C         Change the line that gives the table id. 
          WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
          CALL INL192
     I            (STDIN, STDOUT,
     O             LINE)
          READ(LINE,'(7X,I5,I5,2A5,8X,F10.0,8X,F10.0,8X,F9.0)'
     A     ,ERR=991) 
     B      TABLE, TYPE, HLCRITC, HLMAXC, HSCALE, VSCALE, CSHIFT

          
          IF(TYPE.EQ.0) TYPE = 13
          IF(HLCRITC.EQ.' ') THEN
             HLCRIT = 0.15
          ELSE
            READ(HLCRITC,'(F5.0)') HLCRIT
          ENDIF
          IF(HLMAXC.EQ.' ') THEN
            HLMAX = 0.32
          ELSE
            READ(HLMAXC,'(F5.0)') HLMAX
          ENDIF
          IF(HSCALE.EQ.0.0) HSCALE = 1.0
          IF(VSCALE.EQ.0.0) VSCALE = 1.0
          LINE = ' '
          LAST = 0
          WRITE(LINE(LAST+1:LAST+12),'(''TABID= '',I5)') TABLE
          LAST = LAST + 12 + 1
          IF(TYPE.NE.13) THEN
            WRITE(LINE(LAST+1:LAST+9),'(''TYPE= '',I3)') TYPE
            LAST = LAST + 9 + 1
          ENDIF
          IF(HLCRIT.NE.0.15) THEN
            WRITE(LINE(LAST+1:LAST+17),'(''HLCRIT='',F10.2)') HLCRIT
            LAST = LAST + 17 + 1
          ENDIF
          IF(HLMAX.NE.0.32) THEN
            WRITE(LINE(LAST+1:LAST+16),'(''HLMAX='',F10.2)') HLMAX
            LAST = LAST + 16 + 1
          ENDIF
          IF(HSCALE.NE.1.0) THEN
            WRITE(LINE(LAST+1:LAST+17),'(''HSCALE='',F7.4)') HSCALE
            LAST = LAST + 17 + 1
          ENDIF
          IF(VSCALE.NE.1.0) THEN
            WRITE(LINE(LAST+1:LAST+17),'(''VSCALE='',F7.4)') VSCALE
            LAST = LAST + 17 + 1
          ENDIF
          IF(CSHIFT.NE.1.0) THEN
            WRITE(LINE(LAST+1:LAST+17),'(''CSHIFT='',F5.2)') CSHIFT
            LAST = LAST + 17 + 1
          ENDIF
          
          WRITE(STDOUT,'(A)') LINE(1:LAST)
        ELSEIF(LINE(1:6).EQ.'TABLE#') THEN
          LINE(1:7) = 'TABID= '
          WRITE(STDOUT,'(A)') LINE(1:N)
        ELSEIF(LINE(1:7).EQ.'CULVERT') THEN
C         Catch the departure reach table specification and change.
          WRITE(STDOUT,'(A)') LINE(1:N)

4000      CONTINUE
            CALL INL192
     I              (STDIN, STDOUT,
     O               LINE)
            IF(LINE(1:6).EQ.'DEPTAB') THEN
              READ(LINE,'(8X,I5,I5,A5)',ERR=991) DEPTAB, BEGTAB, CHAR5
              IF(CHAR5.EQ.' ') RMFFAC = 1.0
              LAST = 0
              WRITE(LINE(LAST+1:LAST+12),'(''DEPTAB='',I5)') DEPTAB
              LAST = LAST + 12 + 1
              IF(BEGTAB.GT.0) THEN
              WRITE(LINE(LAST+1:LAST+12),'(''BEGTAB='',i5)') BEGTAB
                LAST = LAST + 12 + 1
              ENDIF
              IF(RMFFAC.NE.1.0) THEN
                WRITE(LINE(LAST+1:LAST+12),'(''RMFFAC='',F10.3)') RMFFAC
                LAST = LAST + 17 + 1
              ENDIF
              WRITE(STDOUT,'(A)') LINE(1:LAST)

C             Jump out to main loop
              GOTO 9999
            ELSE
              WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
            ENDIF
            GOTO 4000
        
        ELSEIF(LINE(1:6).EQ.'EXPCON') THEN
C         Find and change the label for the 2-D tables.
          DO 5000 I=1,6
            WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
            CALL INL192
     I                (STDIN, STDOUT,
     O                 LINE)
5000      CONTINUE

C         Note that the last line read has not yet been written. 
C         Extend the heading for the label field so that the full label
C         will be read by heading-depending input. 
          LINE(24:73) = 
     A            'LABEL---------------------------------------------'
          WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))  
        ELSEIF(LINE(1:8).EQ.'XSINTERP') THEN
C         Add the NODEID= YES if it is not already present
          WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
          CALL INL192
     I              (STDIN, STDOUT,
     O               LINE)
          WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
          CALL INL192
     I              (STDIN, STDOUT,
     O               LINE)
          
          READ(LINE(8:11),'(A4)') NODEID
          CALL STRIP_L_BLANKS(
     M                        NODEID)
          IF(NODEID.EQ.'NO') THEN
C           Need to change to YES.
            WRITE(STDOUT,'(''NODEID='',''YES'')')
C           Insert NODEID column in the existing data.  Use blank 
C           value for the node id.  Fix the heading line first.
            CALL INL192
     I                (STDIN, STDOUT,
     O                 LINE)
            LINE2 = LINE(6:192)
            LINE(6:192) = ' '
            LINE(6:13) = ' NODEID '
            LINE(14:) = LINE2
            WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
6000        CONTINUE
              CALL INL192
     I                  (STDIN, STDOUT,
     O                   LINE)
              READ(LINE(1:5),'(I5)') NODE
              IF(NODE.GE.0) THEN
C               We have a line of data.  Insert the blank node id value.
                LINE2 = LINE(6:192)
                LINE(6:192) = ' '
                LINE(14:) = LINE2
                WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
              ELSE
C               Termination line
                WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
                GOTO 9999
              ENDIF
              GOTO 6000
          ELSE      
            WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
C           Skip out to main loop
            GOTO 9999
          ENDIF

        ELSEIF(LINE(1:6).EQ.'UFGATE') THEN
C         Correct headings for UFGATE.  No blanks allowed.
          WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
          CALL INL192
     I              (STDIN, STDOUT,
     O               LINE)
C         Change TABLE#= to TABID=
          LINE(1:7) = 'TABID= '
          WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
          DO 7000 I=1,11
            CALL INL192
     I                (STDIN, STDOUT,
     O                 LINE)
            WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
7000      CONTINUE
          CALL INL192
     I              (STDIN, STDOUT,
     O               LINE)
C         Replace the heading line with one that has headings without spaces.
          LINE = '   Opening 2-D_Table  Cc_Value Lip_Angle '
          WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
        ELSE
          WRITE(STDOUT,'(A)') LINE(1:N)
        ENDIF
9999  CONTINUE
      GOTO 1000

10000 CONTINUE
      CLOSE (STDIN)
      CLOSE (STDOUT)

      STOP 'Normal stop'
991   CONTINUE
        WRITE(STDOUT,*) ' Conversion error in line:'
        WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))
        STOP 'Abnormal stop.  Conversion error in an input line.'
      END

