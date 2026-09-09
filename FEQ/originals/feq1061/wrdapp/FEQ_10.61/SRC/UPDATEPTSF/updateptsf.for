C     *****************
C     *               *
C     * updateptsf
C     *               *
C     *****************

      PROGRAM updateptsf

c     Update one or more ptsf's to the new direct-access format.
c     This program must be compiled using the same compiler as was
c     used to compile the program that created the ptsf being 
c     updated. 

      implicit none

      
      INCLUDE 'morg.prm'


      CHARACTER*48 INFILE

      CHARACTER INNAM(500)*256, OUTNAM(500)*256, what*1, unused*1,
     a    s72*72, node*8, fname*256

      integer*2 file_version
      INTEGER INCD, I, j, N, m, first_rec, record_length, wr_rec,
     a      branch, mjd, narg, nxt

      logical there

      REAL VALA

      DOUBLE PRECISION JTIME, jtime_last , jtime_even_day

c     Called units
      integer iargc

C     **************************** FORMATS *****************************
50    format(' Processing file: ',A)      
52    format(' Processing completed for: ',A)
C***********************************************************************
      file_version = 1
      first_rec = 30
      record_length = 12
c     Set up JTIME with an initial value that will be replaced so that
c     jtime_last will be set properly
      jtime = 0.d0

      NARG = 0
      NXT = 1
      NARG = IARGC()
      
      if(narg.eq.1+morg) then

C       GET THE FIRST and only FILE ARGUMENT
 
        CALL GETARG
     I             (1+MORG,
     O              FNAME)
    
        INQUIRE(FILE=FNAME, EXIST=THERE)
        IF(THERE) THEN
          OPEN(unit=8, FILE = FNAME, STATUS = 'OLD')
        ELSE
          N = LEN_TRIM(FNAME)
          WRITE(*,*) ' '
          WRITE(*,*) ' File named: ',FNAME(1:N),' not found.'
          WRITE(*,*) ' Please check spelling of input file.'
          STOP 'Abnormal stop. Errors found.'
        ENDIF
      else
c       No command line arguments. 

        WRITE(*,*) ' '
        WRITE(*,*) ' '
        WRITE(*,*) ' '

        WRITE(*,*) ' Update Point Time Series File Utility'
        WRITE(*,*) ' Version 0.8  6 January 2005'
        WRITE(*,*) ' '
        WRITE(*,*) ' Name of file containing the file names of files',
     A      ' to be updated:'

        READ(*,'(A)') INFILE

        WRITE(*,*) ' INFILE=',INFILE
        INQUIRE(FILE=infile, EXIST=THERE)
        IF(THERE) THEN
          OPEN(unit=8, FILE = infile, STATUS = 'OLD')
        ELSE
          N = LEN_TRIM(infile)
          WRITE(*,*) ' '
          WRITE(*,*) ' File named: ',infile(1:N),' not found.'
          WRITE(*,*) ' Please check spelling of input file.'
          STOP 'Abnormal stop. Errors found.'
        ENDIF

        OPEN(UNIT=8, FILE=INFILE, STATUS='OLD',FORM='FORMATTED')

      endif


      I = 1
100   CONTINUE
        READ(8,*, END=110) INNAM(I), OUTNAM(I)
        IF(INNAM(I).EQ.OUTNAM(I)) THEN
          WRITE(*,*) ' INPUT FILE:',INNAM(I),' SAME AS OUTPUT FILE.'
          STOP
        ENDIF
        I = I + 1
        GOTO 100
110   CONTINUE
      N = I - 1
      CLOSE(8)

      open(unit=8,file='update.out',status='unknown')
      DO 300 I=1,N
        OPEN(UNIT=9, FILE=INNAM(I), FORM='UNFORMATTED',STATUS='OLD')
        OPEN(UNIT=15, FILE=OUTNAM(I), STATUS='UNKNOWN',access='direct',
     a          recl=12)

        
        WRITE(*,*) ' '
        m = len_trim(innam(i))
        WRITE(*,50) INNAM(I)(1:m)

        READ(9) INCD
        IF(INCD.LT.1.OR.INCD.GT.4) THEN
          WRITE(*,*) ' Internal code=',INCD,' invalid for file:',
     A                 INNAM(I)
          STOP
        ENDIF

        unused = ' '
        if(incd == 2) then
          what = 'Z'
        elseif(incd == 4)  then
          what = 'Q'
        else
          write(*,*) 'Code for file is invalid.'
          stop
        endif

        
c       write header information to the new file.  We do not know
c       the branch and node info.  However, use the file name as given.
c       Set the branch to -1 and the node to blanks to denote that they 
c       are unknown. 

        wr_rec = 1
        write(15,rec=wr_rec) record_length, 
     a       file_version, what, unused,
     b       first_rec 
        wr_rec = wr_rec + 1

        branch = -1
        node = ' '
        write(15,rec=wr_rec) branch, node
        wr_rec = wr_rec + 1

        n = len_trim(outnam(i))
        do j=n-1,1,-1
          if(outnam(i)(j:j) == '/' .or.
     a       outnam(i)(j:j) == '\') then
              exit
          endif
        end do
c      Drop through is valid.  It means that no part of the path
c      name was given.  The name beyond 72 chars in length is 
c      discarded.  User has to be terse in selecting names!
        s72 = outnam(i)(j+1:n)
        do j=0,5
           write(15, rec=wr_rec) s72(j*12+1:12*(j+1))
           wr_rec = wr_rec + 1
        end do
        if(wr_rec /= 9) then
          write(*, *) ' Bug found!'
          STOP 'Abnormal stop: bug found.'
        endif 

c       Fill empty records with blanks
        do j=wr_rec,first_rec-1
          write(15,rec=j) '            '
        enddo        
       
        
c       Update pointer to the record for the first time-series value
        wr_rec = first_rec

        

200     CONTINUE
          jtime_last = jtime
          READ(9,END=290) JTIME, VALA
          WRITE(15, rec=wr_rec) JTIME, VALA
          wr_rec = wr_rec + 1
          IF(JTIME.GT.0.D0) GOTO 200

290   CONTINUE
c     There is a potential problem with jtime_last.  It sometimes
c     has a minute roundoff error that makes it too small by 
c     about 5 x 10^-9 day.  Thus we will check for that small 
c     difference here on the assumption that most runs end 
c     on an even day.  Thus we will truncate jtime_last to 
c     an integer.  Then add 1 and then convert back to 
c     dble precision.  If the difference is less than 
c     1 x 10^-8, then we will set jtime to the integral
c     value.  We also need to update the jtime for the last
c     point as well so that they are in perfect agreement. 

      mjd = int(jtime_last)
      jtime_even_day = dble(mjd + 1)
      if(abs(jtime_even_day - jtime_last).lt.1.d-8) then
        jtime_last = jtime_even_day
        read(15,rec=wr_rec - 2) jtime, vala
        write(15,rec=wr_rec - 2) jtime_last, vala
      endif  
c     write the record number for the last time-series point.
      write(15, rec=first_rec - 1) 
     a          jtime_last, wr_rec - 2
c      write(8,*) 'jtime_last=',jtime_last

      m = len_trim(outnam(i))
      WRITE(*,52) OUTNAM(I)(1:m)
        
        CLOSE(9)
        CLOSE(15)
300   CONTINUE

      STOP
      END

