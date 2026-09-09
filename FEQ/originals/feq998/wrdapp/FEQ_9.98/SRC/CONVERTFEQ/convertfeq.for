C     ***********
C     *         *
C     * CONVERTFEQ
C     *         *
C     ***********

C     Utility program to convert an FEQ input file to the
C     new form for version 9.5 and later.

      PROGRAM CONVERTFEQ


      CHARACTER*64 FNAME1, FNAME2
      CHARACTER LINE*192, LINE2*256, CODE*5, NC(10)*4, F(5)*7,
     A          COMMENT*112, DIFFUS*4, CHR21*21, FNAME*64

      LOGICAL THERE
      
      INTEGER IOFLAG, MORG, STDIN, STDOUT, ICODE, ITYPE,
     A        N10, MINPRT, LAGTSF, DMYEAR, DMMN,
     B        MKNT, NUMGT, IFRZ, I, J, N, IS, BWFDSN, GETDSN,
     C        TABLE, PNT

      REAL EPSSYS, ABSTOL, EPSFAC, QSMALL, QCHOP, DTVEC(10),
     A      MAXDT, MINDT, AUTO, SITER, HIGH, LOW, HFAC, LFAC,
     B      MRE, FAC
      INCLUDE 'stdun.cmn'

C     Program units.

      INTEGER GET_UNIT, IARGC, LENSTR

      EXTERNAL GET_UNIT, IARGC, GETARG, INITIALIZE_UNITS,
     A         PROCESS_OLD_IOUNITS, STRIP_BLANKS_AND_ZEROS
      INTRINSIC INDEX
C     ***********************Formats************************************
50    FORMAT('*ERR:XXX* Value of MORG wrong. Must be 0 or 1.')
54    FORMAT(1X,A)
56    FORMAT(/,' *ERR:XXX* Command:',A,' unknown.')
58    FORMAT(/,' Utility to convert FEQ Inputs',/,
     A         ' Version: 1.0 Beta',/,
     B         ' 30 October 2000')
60    FORMAT('MAXDT=',F8.1,2X,'MINDT=',F8.1,2X,'AUTO=',F5.2, 2X,
     A       'SITER=',F5.1,2X,'HIGH=',F5.2,2X,'LOW=',F5.2,2X,
     B       'HFAC=',F5.2,2X,'LFAC=',F5.2)
C***********************************************************************
C
C     Utility program to convert an FEQ input file to the
C     new form of the network matrix.
C     files in support of unsteady flow simulation using FEQ.

C     strings for Unix what command
      line =
     &'@(#)NETUTL - Convert FEQ input file to new network matrix format'
      line =
     &      '@(#)NETUTL - Franz, D.D., and Melching, C.S., WRIR 96-4240'
      line = '@(#)NETUTL - Contact: h2osoft@usgs.gov'
      line = '@(#)NETUTL - Version: 1.0 Beta 2000/10/30'
C     set string for use with RCS ident command
      line =
     &'$Id: netutl.f,v 1.0 1998/06/04 19:16:54 rsregan Exp rsregan $'
C
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
C     the 100's to allow for HECDSS stuff later. 

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
        WRITE(*,*) ' delimiters like this: convertfeq input output'
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
C     we can start processing the input.  Look for the string 
C     NETWORK

1000  CONTINUE
C       Transfer records unchanged except for stripping trailing
C       blanks while searching for the start of various blocks that
C       require changes
        CALL  INL192
     I              (STDIN, STDOUT,
     O                 LINE)
        IF(LINE(1:7).EQ.'ENDFILE') GOTO 10000
        N = LENSTR(LINE)

        IF(LINE(1:7).EQ.'NETWORK'.OR.LINE(1:8).EQ.'EXTERIOR') THEN

          IF(LINE(1:8).EQ.'EXTERIOR') THEN
            LINE(1:8) = 'NETWORK '
          ENDIF
C         Change the block heading to include NEW                                 
                                                                                  
          LINE2 = 'NEW '//LINE(1:LENSTR(LINE))                                    
          WRITE(STDOUT,'(A)') LINE2(1:LENSTR(LINE2))                              
                                                                                  
C         Transfer the heading line                                               
          CALL  INL192
     I                (STDIN, STDOUT,
     O                   LINE)
          WRITE(STDOUT,'(A)') LINE(1:LENSTR(LINE))                                
                                                                                  
C         Now we are into the Network-Matrix Control Input.                       
          N10 = 0                                                                 
2000      CONTINUE                                                                
            CALL  INL192
     I                  (STDIN, STDOUT,
     O                     LINE)
            N = LENSTR(LINE)                                                      
            IF(LINE(1:1).EQ.'*'.OR.LINE(1:1).EQ.';'.OR.                           
     A         N.EQ.0) THEN                                                       
              IF(N.EQ.0) THEN                                                     
                WRITE(STDOUT,'(A1)') ' '                                          
              ELSE                                                                
                WRITE(STDOUT,'(A)') LINE(1:N)                                     
              ENDIF                                                               
            ELSE                                                                  
C             This is a line of input.                                            
              READ(LINE,'(A5,10A4,5A7,A112)') CODE, NC, F, COMMENT                
C             Strip  leading blanks and zeros from F
              DO 85 I=1,5
                CALL STRIP_BLANKS_AND_ZEROS(
     M                                       F(I))
85            CONTINUE
              READ(CODE,'(I5)') ICODE                                             
              IF(N10.GT.0.AND.CODE.EQ.'     ') THEN                               
                READ(NC(10),'(I4)') N10                                           
                IF(N10.GT.0) NC(10) = ' '                                         
              ENDIF                                                               
              IF(ICODE.EQ.5) THEN                                                 
                READ(NC(1),'(I4)') ITYPE                                          
                IF(ITYPE.EQ.6) THEN                                               
                  READ(NC(10),'(I4)') N10                                         
                  IF(N10.GT.0) THEN                                               
                    NC(10) = ' '                                                  
                  ENDIF                                                           
                ENDIF                                                             
              ENDIF                                                               
C             Check for blank fields interspesed among non-blank fields           
C             and fill any found with a place holder value.                       
              N = 0                                                               
              IF(ICODE.EQ.0) THEN                                                 
C               This is a continuation line.                                      
                IS = 5                                                            
              ELSE                                                                
                IS = 1                                                            
              ENDIF                                                               
              DO 90 I=10,IS,-1                                                    
                IF(N.GT.0) THEN                                                   
                  IF(NC(I).EQ.'    ') THEN                                        
                    NC(I)(4:4) = '*'                                              
                  ENDIF                                                           
                ENDIF                                                             
                IF(NC(I).NE.'    ') THEN                                          
                  N = 1                                                           
                ENDIF                                                             
90            CONTINUE                                                            
              N = 0                                                               
              DO 92 I=5,1,-1                                                      
                IF(N.GT.0) THEN                                                   
                  IF(F(I).EQ.'       ') THEN                                     
                    F(I)(5:7) = '0.0'                                               
                  ENDIF                                                           
                ENDIF                                                             
                IF(F(I).NE.'      ') THEN
                  N = 1 
C                 Make sure a decimal point is present 

                  PNT = INDEX(F(I),'.')
                  IF(PNT.EQ.0) THEN
C                   No decimal point found.  Assume that it must go at
C                   the  right-hand end. 
                    PNT = LENSTR(F(I)) + 1
                    IF(PNT.GT.7) THEN
                      WRITE(STDOUT,*) 
     A              ' No room for decimal point in F(I)=',F(I), ' I=',I
                      STOP 'Abnormal stop. No room for decimal point!'
                    ELSE
                     F(I)(PNT:PNT) = '.'
                    ENDIF
                  ENDIF                                           
                ENDIF                                                             
92            CONTINUE                                                            
C             Transfer the line, adding a continuation char as needed.            
              LINE2 = ' '                                                         
              LINE2(1:5) = CODE                                                   
              IS = 6                                                              
              DO 100 I=1,10                                                       
                LINE2(IS+1:IS+4) = NC(I)                                          
                IS = IS + 5                                                       
100           CONTINUE                                                            
              N = 1                                                               
              DO 101 I=5,1,-1                                                     
                IF(F(I).NE.'       ') THEN                                        
                  N = I                                                           
                  GOTO 102                                                        
                ENDIF                                                             
101           CONTINUE                                                            
102           CONTINUE                                                            
              DO 104 I=1,N                                                        
                LINE2(IS+1:IS+7) = F(I)                                           
                IS = IS + 8                                                       
104           CONTINUE                                                            
                                                                                  
              IF(N10.GT.0) THEN                                                   
C               Terminate the line with space, continuation char and quote        
                LINE2(IS:IS+2) = ' /'''                                           
                IS = IS + 3                                                       
              ELSE                                                                
C               Terminate with two spaces and a quote                             
                LINE2(IS:IS+2) = '  '''                                           
                IS = IS + 3                                                       
              ENDIF                                                               
                                                                                  
C             Append any trailing comments.                                       
                                                                                  
              LINE2(IS:192) = COMMENT                                             
              WRITE(STDOUT,'(A)') LINE2(1:LENSTR(LINE2))                          
            ENDIF                                                                 
            IF(ICODE.LT.0) GOTO 9999
            GOTO 2000 
        ELSEIF(LINE(1:4).EQ.'NBRA') THEN
C         This is the start of the Run-Control Block.  Insert the new 
C         block heading and then do a scan for other lines in the 
C         block that require changes. 
       
          WRITE(STDOUT,'(A)') 'RUN CONTROL BLOCK'
          WRITE(STDOUT,'(A)') LINE(1:N)

3000      CONTINUE
            CALL  INL192
     I                  (STDIN, STDOUT,
     O                     LINE)

            N = LENSTR(LINE)                                                      
            IF(LINE(1:6).EQ.'DIFFUS') THEN
C             Expand the DIFFUS line
              READ(LINE,'(7X,A4,2I1,2I5)') DIFFUS, MINPRT, LAGTSF,
     A             DMYEAR, DMMN
              WRITE(STDOUT,'(A,A4)') 'DIFFUS=',DIFFUS
              IF(MINPRT.GT.0) THEN
                WRITE(STDOUT,'(A,I3)') 'MINPRT=',MINPRT
              ENDIF
              IF(LAGTSF.GT.0) THEN
                WRITE(STDOUT,'(A,I3)') 'LAGTSF=',LAGTSF
              ENDIF
              IF(DMYEAR.GT.0) THEN
                WRITE(STDOUT,'(A,I4,2X,A,I2)') 'DMYEAR=',DMYEAR,
     A                  'DMMN=',DMMN
              ENDIF
            ELSEIF(LINE(1:6).EQ.'EPSSYS') THEN
C             Process convergence tolerance
              READ(LINE,'(7X,3F5.0)') EPSSYS, ABSTOL, EPSFAC
              WRITE(STDOUT,'(A,F6.3)') 'EPSSYS=',EPSSYS 
              IF(ABSTOL.GT.0.0) THEN
                WRITE(STDOUT,'(A,F6.3)') 'ABSTOL=',ABSTOL
              ENDIF
              IF(EPSFAC.GT.0.0) THEN
                WRITE(STDOUT,'(A,F5.1)') 'EPSFAC=',EPSFAC
              ENDIF
            ELSEIF(LINE(1:4).EQ.'MKNT') THEN
C             Process the count of iterations. 
              READ(LINE,'(5X,2I5)') MKNT, NUMGT
              WRITE(STDOUT,'(A,I5)') 'MKNT=',MKNT
              IF(NUMGT.GT.0) THEN
                WRITE(STDOUT,'(A,I5)') 'NUMGT=',NUMGT
              ENDIF
            ELSEIF(LINE(1:6).EQ.'OUTPUT') THEN
C             Delete this line.  The default is always correct.
            ELSEIF(LINE(1:6).EQ.'PRTINT') THEN
C             Expand the print interval line.  Get the optional date-time string
              CHR21 = LINE(14:)
              WRITE(STDOUT,'(A)') LINE(1:12)
              IF(CHR21.NE.' ') THEN
                WRITE(STDOUT,'(A,A)') 'DPTIME=',CHR21
              ENDIF
            ELSEIF(LINE(1:6).EQ.'QSMALL') THEN
C             Expand QSMALL line
              READ(LINE,'(7x,2F10.0)') QSMALL, QCHOP
              WRITE(STDOUT,'(A,F10.3)') 'QSMALL=',QSMALL
              IF(QCHOP.GT.0.0) THEN
                WRITE(STDOUT,'(A,F10.5)') 'QCHOP=',QCHOP
              ENDIF
            ELSEIF(LINE(1:4).EQ.'IFRZ') THEN
C             Process frozen time. 
              READ(LINE,'(5X,I5)') IFRZ
              IF(IFRZ.EQ.0) THEN
                 WRITE(STDOUT,'(A,I5)') 'IFRZ=',IFRZ
              ELSE
                CALL  INL192
     I                     (STDIN, STDOUT,
     O                       LINE)
                READ(LINE,'(10F8.0)') DTVEC
                WRITE(STDOUT,'(A,I5,10F8.1)') 'IFRZ=',IFRZ, 
     A                   (DTVEC(J),J=1,IFRZ)        
              ENDIF
C             Process the time control line.  No identifying marks available.
3020          CONTINUE
              CALL  INL192
     I                   (STDIN, STDOUT,
     O                     LINE)
              READ(LINE,'(8F5.0)') MAXDT, MINDT, AUTO, SITER, HIGH, 
     A                  LOW, HFAC, LFAC

              WRITE(STDOUT,60) MAXDT, MINDT, AUTO, SITER, HIGH, 
     A              LOW, HFAC, LFAC               
            ELSEIF(LINE(1:3).EQ.'MRE') THEN
C             Process extrapolation control. 
              READ(LINE,'(4X,2F10.0)') MRE, FAC
              WRITE(STDOUT,'(A,F8.2)') 'MRE=',MRE
              WRITE(STDOUT,'(A,F8.2)') 'FAC=',FAC
            ELSEIF(LINE(1:6).EQ.'BWFDSN') THEN
C             Process reference to initial conditions file. 
              CALL PROCESS_OLD_IOUNITS(STDOUT, LINE(8:), 
     O                                 BWFDSN, FNAME)
              N = LENSTR(FNAME)
              IF(N.GT.0.AND.BWFDSN.NE.0) THEN
                WRITE(STDOUT,'(A,A)') 'BWFDSN=',FNAME(1:N)
              ENDIF
            ELSEIF(LINE(1:5).EQ.'GETIC') THEN
C             Process the file name for getting the initial condition from a 
C             file. 
              READ(LINE,'(6X,I5,A)') GETDSN, FNAME
              N = LENSTR(FNAME)
              IF(N.GT.0) THEN
                WRITE(STDOUT,'(A,A)') 'GETIC=',FNAME
              ENDIF
            ELSEIF(LINE(1:5).EQ.'PUTFC') THEN
C             Process the file name for putting the initial condition from
C             a file.
              READ(LINE,'(6X,I5,A)') GETDSN, FNAME
              N = LENSTR(FNAME)
              IF(N.GT.0) THEN
                WRITE(STDOUT,'(A,A)') 'PUTFC=',FNAME
              ENDIF
              GOTO 9999
            ELSE
             IF(N.EQ.0) THEN
               WRITE(STDOUT,'(A1)') ' '
             ELSE
               WRITE(STDOUT,'(A)') LINE(1:N)
             ENDIF
         
            ENDIF
            GOTO 3000
        ELSEIF(LINE(1:6).EQ.'OUTPUT') THEN
C         Fix the heading for the file name on the next input line
          WRITE(STDOUT,'(A)') LINE(1:N)
          CALL  INL192
     I                (STDIN, STDOUT,
     O                   LINE)
          N = LENSTR(LINE)
          LINE(N+1:)=
     A  '------------------------------------------------------------'
          N = LENSTR(LINE)
          WRITE(STDOUT,'(A)') LINE(1:N)
          GOTO 9999
        ELSEIF(LINE(1:4).EQ.'FREE') THEN
C         Fix the heading for the free node initial conditions.
          WRITE(STDOUT,'(A)') LINE(1:N)
          CALL  INL192
     I                (STDIN, STDOUT,
     O                   LINE)
          N = LENSTR(LINE)
          LINE(7:14) = 'NodeId__'
C         Wipe out the node sign information.  It should be in 
C         columns 46-50
          LINE(46:50) = ' '
          N = 45
          WRITE(STDOUT,'(A)') LINE(1:N)
4000      CONTINUE
            CALL  INL192
     I                  (STDIN, STDOUT,
     O                     LINE)
            N = LENSTR(LINE)
            IF(LINE(1:4).EQ.'BACK') THEN
              WRITE(STDOUT,'(A)') LINE(1:N)
              GOTO 4100
            ELSE
C             Wipe out the node sign information.
              LINE(46:50) = ' '              
              N = 45
              WRITE(STDOUT,'(A)') LINE(1:N)
              GOTO 4000
            ENDIF
4100      CONTINUE

          GOTO 9999
        ELSEIF(LINE(1:6).EQ.'TABLE#') THEN
C         Process table references
          READ(LINE,'(7X,I5)') TABLE
          IF(TABLE.GT.0.OR.TABLE.EQ.-1) THEN
C           Change variable name.
            LINE(1:7) = 'TABID= '
C           Write the table number to eliminate any leading zeros
            WRITE(LINE(8:12),'(I5)') TABLE
            N = 12
          ELSE
C            Reference to a file name.  Wipe out the table number as well.
             LINE(1:12) = 'FILE=       '
          ENDIF
          WRITE(STDOUT,'(A)') LINE(1:N)
          GOTO 9999
        ELSEIF(LINE(1:4).EQ.'BNUM') THEN
C         Make sure the node id label is in the correct columns
          WRITE(STDOUT,'(A)') LINE(1:N)
          CALL  INL192
     I                (STDIN, STDOUT,
     O                   LINE)
          N = LENSTR(LINE)
          LINE(7:14) ='NodeId__'
          WRITE(STDOUT,'(A)') LINE(1:N)
          GOTO 9999          
        ENDIF
        IF(N.EQ.0) THEN
          WRITE(STDOUT,'(A1)') ' '
        ELSE
          WRITE(STDOUT,'(A)') LINE(1:N)
        ENDIF
9999  CONTINUE
      GOTO 1000

10000 CONTINUE
      CLOSE (STDIN)
      CLOSE (STDOUT)

      STOP 'Normal stop'
      END

