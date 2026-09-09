c
c
c
      subroutine maybe_add_quote(
     m                           line)

c     Add a comma and quote to the end of the line if no
c     quote is found. If a quote is found replace it with 
c     a comma quote

      implicit none

      character*(*) line

c     Local

      integer :: i
c     ******************************************************************
      I = INDEX(LINE,'''')
      IF(I.EQ.0) THEN
c       No quote found.  add comma and quote to make later work 
c       easier.
        i = len_trim(line)
        LINE(i+1:i+2) = ','''        
      ELSE
C       Revise user quote to ,quote
        LINE(I:I+1) = ','''
      ENDIF

      end
c
c
c
      SUBROUTINE tsf_init_smooth(STDOUT, OLDTSF, OLDDSN,  
     i                    newtsf, NEWDSN, old_len,
     M                    NDFVAL, 
     O                    TSFTYP, last_header_rec)
 
C     Read header records in the TSF given by OLDTSF and 
C     create the header records for the  newtsf in the 
c     format for a smoothed DTSF  

      implicit none
      integer :: last_header_rec, old_len
      CHARACTER*(*) OLDTSF, newtsf
 
      INTEGER OLDDSN, NEWDSN, NDFVAL, STDOUT, TSFTYP

C     LOCAL

      INTEGER I, J, NDF, dtsf_version, record_len, 
     a   first_event_rec, nrecold, nrecnew, old_limit,
     b   new_limit

      INTEGER :: aold(:), anew(:)
      ALLOCATABLE :: aold, anew

      INTEGER TEMP(10)
 
C     ************************* FORMATS *******************************
10    FORMAT(/,' The current TSF was created on ',
     1I4,'/',I2,'/',I2,' AT ',I4,' and has ',I3,
     2' LSRO values.')
11    FORMAT(' ','Simulation for the ',
     1'runoff values began on ',I4,'/',
     2I2,'/',I2,' and ended on ',I4,'/',I2,'/',I2,'.')
 
14    FORMAT(/,1X,20A4)
16    FORMAT(4X,'LSRO# ',I3,':',20A4)
50    FORMAT(/,' *ERR:XXX* ',I5,' Runoff values found in ',A,/,
     A    5X,' when ',I5,' were expected.')
54    FORMAT(\,' DTSF=',1X,A,/,
     A         '     uses 4 Bytes for each runoff value.')
56    FORMAT(//,' Information from the header records in the DSTF:')
C**********************************************************************
C     READ THE FIRST PART OF THE FIRST RECORD TO ESTABLISH THE FORMAT OF
C     THE source DTSF

c     compute limit for old from the known record length. 
      old_limit = (old_len - 28)/4
      ALLOCATE (aold(old_limit))


      READ(OLDDSN,rec=2) aold
      NDF = aold(6)
      TSFTYP = aold(7)
      NDFVAL = NDF

      
      WRITE(STDOUT,54) OLDTSF(1:len_trim(oldtsf))
      WRITE(STDOUT,*) ' '

c     The new record length will have an additional 4 bytes for 
c     each time series in it. 

      new_limit = 7 + NDFVAL + NDFVAL
      ALLOCATE (anew(new_limit))

      record_len = 4*new_limit
      dtsf_version = 2
      first_event_rec = 4 + ndfval + 1
      close(newdsn)
      OPEN(NEWDSN,FILE=newtsf, FORM='UNFORMATTED',
     A         STATUS = 'UNKNOWN',  access='direct', recl=record_len)
      anew = 0
      anew(1) = record_len
      write(newdsn,rec=1) anew


      READ(OLDDSN, rec=2) aold

      do i=1,old_limit
        anew(i) = aold(i)
      end do

C     WRITE second RECORD OF THE NEW TSF

      last_header_rec = anew(5)
      anew(7) = dtsf_version
      WRITE(NEWDSN, rec=2) anew
 
      DO 12 I=1,4
        temp(I) = aold(I)
12    CONTINUE

      READ(OLDDSN,rec=3) aold
      do i=1,old_limit
        anew(i) = aold(i)
      end do
      
C     WRITE third RECORD OF THE NEW TSF

      WRITE(NEWDSN, rec=3) anew

      DO 13 I=5,10
        TEMP(I) = Aold(I-4)
13    CONTINUE

      READ(OLDDSN, rec=4) aold
      do i=1,old_limit
        anew(i) = aold(i)
      end do

C     WRITE fourth  RECORD OF THE TSF

      WRITE(NEWDSN, rec=4) anew

      WRITE(STDOUT,56)
      WRITE(STDOUT,14) (aold(I), I=1,MIN(20,old_limit))
      WRITE(STDOUT,10) (TEMP(I), I=1,4), NDFVAL
      WRITE(STDOUT,11) (TEMP(I), I=5,10)
      DO 15 I=1,NDFVAL
        READ(OLDDSN, rec=4+i) aold
        do j=1,old_limit
          anew(j) = aold(j)
       end do

        WRITE(NEWDSN, rec=4+i) anew
        WRITE(STDOUT,16) I, (Aold(J), J=1,MIN(20,new_limit))
15    CONTINUE

      DEALLOCATE ( aold, anew)

      RETURN
      END

c
c
c
      SUBROUTINE smooth_tsf(STDOUT, OLDDSN, NEWDSN, OLDNAME, 
     i                      newname, old_len,
     O                       EFLAG)

C     Smooth a tsf. 

      implicit none
      INTEGER EFLAG, OLDDSN, NEWDSN, STDOUT, old_len

      CHARACTER*(*) OLDNAME, newname

C     Local

      INTEGER I, j, k, SYR, SMN, SDY, TSFTYP, last_header_rec,
     a     nrecnew, nrecold, ndfval, knt, nrec_start,
     b     n, is, ie, ilast, ii, nadj, js, je, na, ni 

      REAL  R(2)

      real*8 EJTIME, SFRAC, JTIME, DUMMY, factor, ival, diff,
     a     maxdiff, mindiff,  peak, z, ratio, time_factor, 
     a     maxratio, minratio,  p(9), h, rimat(:,:),
     a     mat(:,:), jt(:), x(:), s(:),  sp(:), spp(:),
     a     arun(:), irun(:), jt_arun(:), jt_irun(:)

      real*4 RI(:), rout(:)

      character*1 variation(:,:), var_adj(:)

      ALLOCATABLE :: RI, rout, mat, jt, x, s, sp, spp, variation, 
     a            var_adj, rimat, arun, irun, jt_arun, jt_irun

      EQUIVALENCE(DUMMY, R(1))

      data p/0.0d0, 0.125d0, 0.25d0, 0.375d0, 0.5d0, 0.625d0,
     a       0.75d0, 0.875d0, 1.0d0/
c**************************************formats**************************
50    format(' Point count=',i7)

C***********************************************************************
c     Convert runoff intensity from feet/second to inches/hour
      factor = 43200
c     Convert time from days to hours
      time_factor = 24.d0 
C     Disable checking for proper number of diffuse areas.
      NDFVAL = 0
      CALL TSF_INIT_smooth(STDOUT, OLDNAME, OLDDSN, 
     i                    newname, NEWDSN, old_len, 
     M                    NDFVAL,
     O                    TSFTYP, last_header_rec)
      

      ALLOCATE ( RI(NDFVAL), rout(2*ndfval))
      
      last_header_rec = 4 + ndfval 
      nrecold = last_header_rec + 1
      nrecnew = last_header_rec + 1


1000  CONTINUE

c       Find the number of records in the event.
        nrec_start = nrecold - 1
c       read the first record because it has the ending time
        READ(OLDDSN, rec=nrecold) JTIME, SFRAC, SYR, SMN, SDY, RI


        if(jtime == 0.d0) return


        nrecold = nrecold + 1
        r(1) = ri(1)
        r(2) = ri(2)
        ejtime = dummy
        knt = 1
c        write(stdout,*) ' ejtime=',ejtime

        do
          READ(OLDDSN, rec=nrecold) JTIME, SFRAC, SYR, SMN, SDY, RI
          nrecold = nrecold + 1
c          write(stdout,*) ' jtime=',jtime
          knt = knt + 1

          if(abs(jtime - ejtime).lt.1.d-7) then
            exit
          endif
        end do

        write(stdout, 50) knt
        allocate ( jt(knt),  mat(knt+1,2*ndfval), x(knt), s(knt), 
     a             sp(knt), rimat(knt,ndfval),
     a             spp(knt), variation(knt,ndfval), var_adj(knt),
     a             arun(2*knt), irun(8*knt), jt_arun(2*knt), 
     a             jt_irun(8*knt) )

c       make sure all of variation is blank at the start
        variation = ' '

c       Reread the event
      
        READ(OLDDSN, rec=nrec_start+1) JTIME, SFRAC, SYR, SMN, SDY, RI
        ri(1) = 0.0
        ri(2) = 0.0

c       transfer first record to the work space.  jtime < 0 for 
c       the first record. 
        jt(1) = abs(jtime)*time_factor
        do j=1,ndfval
          rimat(1,j) = ri(j)*factor
          mat(1,j) = dble(ri(j))*factor
        end do

c       transfer remaining records.
        do i=2,knt        
          READ(OLDDSN, rec=nrec_start+i) JTIME, SFRAC, SYR, SMN, SDY, RI
          jt(i) = jtime*time_factor
          do j=1,ndfval
            rimat(i,j) = ri(j)*factor
            mat(i,j) = dble(ri(j))*factor
          end do
        end do

c       Set the start point for the next event
        nrecold = nrec_start + knt + 1

c       Set the extra row to zero to cover the case when there are no 
c       zeros in the series other than the  first one. 
        do j=1,ndfval
          mat(knt+1,j) = 0.d0
        end do
        

c       Scan each time series to find segments that have every interval
c       with positive runoff.  As each segment is delineated, compute 
c       the integral values at the time points. Then fit with a cubic
c       spline with zero derivative at each end, force the resulting
c       piecewise cubic to be monotone in every interval, then compute
c       the first and second derivative.  The second derivative must 
c       at each point, but the last, must be computed so that it comes
c       from the cubic contained within the interval.  The second 
c       derivative is discontinuous at each point adjusted to force
c       monotone behavior.  We are defining the piece-wise quadratic
c       function in each interval by the function values at the 
c       ends of the interval and the first derivative at the beginning
c       of the interval.  

c       As the values are found, store them in mat. 

        js = 14
        je = 14
        do j=js, je
          n = 0
          is = 0
          ilast = 1
c         Start loop at 2 because the first row  always has zero runoff

          do i=2,knt+1
            if (mat(i,j) > 0.d0) then
c             Is this the first one we have seen?
              if(is == 0) then
c               yes.  Do some setup work. Get the time for 
c               the first point, and set is, 
                n = n + 1
                s(n) = 0.d0
                x(n) = jt(i-1)
c               compute the value of the integral at the 
c               current time.
                n = n + 1
                x(n) = jt(i) 
                s(n) = s(n-1) + mat(i,j)*(x(n) - x(n-1))

c               set start point
                is = i - 1
              else
c               no,  there have been earlier ones in sequence
                n = n + 1
                x(n) = jt(i) 
                s(n) = s(n-1) + mat(i,j)*(x(n) - x(n-1))
              endif
            elseif(mat(i,j) == 0) then
c             Have we seen a non-zero interval already?
              if(is > 0) then
c               yes.  We have an end of segment signal 
c               Set the end point for the segment. 
                ie = i - 1

                write(stdout,55) is, ie, n, ilast
55    format(' is=',i5,'ie=',i5,' n=',i5, ' ilast=',i5)
                write(stdout,*)  ' jt    and   s'
                do k=1,n
                  write(stdout,57) jt(k)/time_factor, s(k)
                end do

57    format(f15.7, f15.7)

c               Do we have a null zone behind us that we need to
c               set? 
                if( is > ilast) then
c                 yes we do.  
                  do ii=ilast, is-1
                    mat(ii,j+ndfval) = 0.d0
                  enddo
                endif

c               reset ilast
                ilast = i

c               Compute a cubic-spline fit to the segment we have in hand.
c               We use zero-derivative end conditions.  

                call  spline
     i                   (stdout, x, s, n, 1, 0.d0, 1, 0.d0,
     o                    sp)

c               Impose variation limiation
    
                call vrlim
     i                  (n, x, s,
     m                   sp,
     o                   nadj, var_adj)

c               compute the second derivatives.  
                call find_fpp(n, x, s, sp,
     o              spp)
                                                       
c               Store the results. 
                do ii=is,ie
                  mat(ii,j) = sp(ii - is + 1)
                  if(ii < ie) then
                    mat(ii,j+ndfval) = spp(ii - is +1)
                    variation(ii,j) = var_adj(ii - is + 1)
                  else
c                   Do not transfer last second derivative. 
c                   we do not use it because we use only the
c                   value at the left end of each interval. 
                    mat(ii,j+ndfval) = 0.d0
                    variation(ii,j) = ' '
                  endif 
                end do

c               Setup for the next segment, if any.
                is = 0
                n = 0
              endif
            endif
          end do                   
        end do     

c       Output the results for this event .

        write(stdout,*) ' '
        write(stdout,*) ' dump of results'
        do i=1,knt
          write(stdout,60) i,
     a        (mat(i,j), mat(i,j+ndfval), variation(i,j), j=js,je)
        end do

60    format(i5, 50(1pe10.3, 1pe10.3,a1))

c       check by integrating over each interval to compute the 
c       original value. 
      
        maxdiff = -1.d0
        mindiff =  1.d0
        maxratio = 1.d0
        minratio = 1.d0
        do i=2,knt
          do j=js,je
            ival = (2.*mat(i-1,j) + mat(i,j) + 0.5*mat(i-1,j+ndfval))*
     a               (jt(i) - jt(i-1))/3.d0

            diff = ival - rimat(i,j)
            if(rimat(i,j) > 0.d0) diff = diff/rimat(i,j)
            maxdiff = max(diff, maxdiff)
            mindiff = min(diff, mindiff)
c           compute peak value in the interval.  The interval is always
c           1 hour in this test case!!! but not in general.
            z = -0.5*mat(i-1,j+ndfval)/
     a         (mat(i,j) - mat(i-1,j) - mat(i-1,j+ndfval))
            if(z .LE. 0.d0) then
              peak = mat(i-1,j)
            elseif(z .GE. 1.d0) then
              peak = mat(i,j)
            else
              peak = (mat(i,j) - mat(i-1,j) - mat(i-1,j+ndfval))*z**2 +
     a                z*mat(i-1,j+ndfval) + mat(i-1,j)
            endif
            if(rimat(i,j) > 0.d0) then
              ratio = peak/rimat(i,j)
            else
              ratio = 1.0
            endif
            maxratio = max(ratio, maxratio)
            minratio = min(ratio, minratio)
          end do
          write(stdout,59) i, jt(i), rimat(i,js), ival, diff, peak, 
     a            ratio
59    format(i5,f15.6,f15.6,f15.6,1pe10.3,0pf15.6, f15.6)
        end do 
        write(stdout,*) ' '
        write(stdout,*) ' maxdiff=',maxdiff, ' maxratio=',maxratio
        write(stdout,*) ' mindiff=',mindiff, ' minratio=',minratio


c       Compute a polyline following the average runoff for 
c       js

       
        na = 0
        do i= 1,knt-1
          na = na + 1
          arun(na) = rimat(i,js)
          jt_arun(na) = jt(i)
          na = na + 1
          arun(na) = rimat(i+1,js)
          jt_arun(na) = jt(i)
        end do
        na = na + 1
        arun(na) = rimat(knt,js)
        jt_arun(na) = jt(knt)
        na = na + 1
        arun(na) = 0.d0
        jt_arun(na) = jt(knt)

c       comput a poly line of the instantaneous values.  Use
c       eight sub-intervales. 

        ni = 0
        do i= 2,knt
          h = jt(i) - jt(i-1)
          ni = ni + 1
          irun(ni) = mat(i-1,js)
          jt_irun(ni) = jt(i-1)
          do k=2,8
            ni = ni + 1
            irun(ni) = 
     a        mat(i-1,js) + p(k)*h*mat(i-1,js+ndfval) + (mat(i,js) 
     a               - mat(i-1,js) - h*mat(i-1,js+ndfval))*p(k)**2
            jt_irun(ni) = jt(i-1) + p(k)*h
          end do
        end do
        ni = ni + 1
        irun(ni) = mat(knt,js)
        jt_irun(ni) = jt(knt)

        write(stdout,*) ' '
        write(stdout,*) 
     a     ' Output of the average runoff in histogram form'
        write(stdout,*) ' na=',na
        do i=1,na
          write(stdout,80) jt_arun(i)/time_factor, arun(i)
        end do
80    format(f15.6, f15.6)

        write(stdout,*) ' '
        write(stdout,*) 
     a     ' Output of the instant. runoff with intermediate points'
        write(stdout,*) ' ni=',ni
        do i=1,ni
          write(stdout,80) jt_irun(i)/time_factor, irun(i)
        end do

        


        deallocate ( jt,  mat, x, s, 
     a             sp, rimat,
     a             spp, variation, var_adj, arun, irun, 
     a             jt_arun, jt_irun  )

      goto 1000

      END

c
c
c
      SUBROUTINE smooth(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 

C     Smooth a DTSF by fitting the cumulative form with a cubic 
c     spline, forcing monotone behavior, then taking the first
c     derivative, and second derivative to form a piecewise 
c     parabolic continuous function whose integral over each 
c     interval of the TSF will produce the same average value 
c     as in the base DTSF.  
c     
c     Note addedd 12 Jan 2005:  This set of routines is incomplete
c     because early testing revealed that the smoothing is too 
c     erratic at points of abrupt change in the runoff series. 
c     Such abrupt changes in runoff intensity occur frequently.
c     Thus the code is left as is until some future time when I
c     can refine the methodology to better smooth abrupt changes. 
c     
      implicit none
      INTEGER IFIRST, NVAL, MVAL, TYPE(NVAL), CLEN(NVAL),
     A        TERML(NVAL), TERMCLS(NVAL), IVAL(NVAL), STDOUT,
     B        STDIN,  EFLAG

      REAL RVAL(NVAL)

      DOUBLE PRECISION DPVAL(NVAL)

      CHARACTER CVAL(NVAL)*(*), TERM(NVAL)*1

C     Local

      LOGICAL THERE

      CHARACTER COMMAND*64, LINE*192, LINE2*194, STRINGS(3)*3,
     A          OLDNAME*128, NEWNAME*128

      INTEGER I, ISTART, CL, OPT, OLDDSN, NEWDSN,
     A        NSTRING, ITERM, IT, ifound, ioflag, record_len

C     Program units

      INTEGER GET_UNIT

      EXTERNAL GET_UNIT
           
      DATA NSTRING/3/, STRINGS/'NEW','OLD','END'/
C     *****************************FORMATS******************************
50    FORMAT(/,' *ERR:XXX* No second level command found.')
52    FORMAT(/,' *ERR:XXX* Invalid values given for current command.')
54    FORMAT(1X,A)
56    FORMAT(/,' *ERR:XXX* Old DTSF file name appears twice.')
58    FORMAT(/,' *ERR:XXX* No file name found for Old DTSF.')
60    FORMAT(/,' *ERR:XXX* File name=',A,/,11X,'not found. Please ',
     A  'check name, path, and drive letter.')
62    FORMAT(/,' *ERR:XXX* New DTSF file name appears twice.')
64    FORMAT(/,' *ERR:XXX* No file name found for New DTSF.')
66    FORMAT(/,' *ERR:XXX* Could not open file name=',/,A,/,11X,
     A      'Please check name, path, and driver letter.')
68    FORMAT(/,' *ERR:XXX* Old DTSF is already in new format.')
70    FORMAT(/,' *ERR:XXX* Second level command invalid.')
72    FORMAT(/,' Processing command: SMOOTH DTSF')
C***********************************************************************
      write(*,*) ' SMOOTH is incomplete.  Not usable.'
      write(*,*) ' May be refined in the future.'
      write(stdout,*) ' SMOOTH is incomplete.  Not usable.'
      write(stdout,*) ' May be refined in the future.'

      return
   
      OPT = 1
C     Clear the unit numbers so that they can be used to 
C     verify that both the old and the new file have been
C     properly defined. 
      OLDDSN = 0
      NEWDSN = 0

C     Find the next string in the list.
      ISTART = IFIRST
      CALL FIND_NEXT_CHARACTER_STRING(MVAL, TYPE,
     M                                      ISTART)
      IF(ISTART.EQ.0) THEN
        WRITE(STDOUT,50) 
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      COMMAND = CVAL(ISTART)
      CL = CLEN(ISTART)
      
      IF(COMMAND(1:CL).EQ.'DTSF') THEN
        WRITE(*,72)
C       Found valid response.  Process subsequent lines.

100     CONTINUE
          CALL inline(STDIN, STDOUT,
     O                LINE)

          WRITE(STDOUT,54) LINE(1:len_trim(line))

          LINE2 = LINE
          call maybe_add_quote(
     m                           line2)
          CALL GETVAL(STDOUT, LINE2, NVAL, OPT,
     O                 TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O                 TERM, TERML, TERMCLS, MVAL)
        
          ITERM = 1
          CALL FIND_TERMINATER(MVAL, TERM, '=',
     O                       ITERM)

          ISTART = 1
          IF(ITERM.GT.0) THEN
            IT = ITERM
          ELSE
            IT = MVAL
          ENDIF
          CALL FIND_ANY_STRING_IN_LIST(IT, NSTRING, TYPE, CVAL, CLEN,
     I                                  STRINGS,
     M                                  ISTART,
     O                                  IFOUND)

          IF(IFOUND.EQ.0) THEN
            WRITE(STDOUT,52)
            STOP 'Abnormal stop. Errors found.'
          ENDIF

          IF(STRINGS(IFOUND).EQ.'OLD') THEN
C           Process the old file name.
            IF(OLDDSN.EQ.0) THEN
              OLDDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,56) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              OLDNAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,58) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

            INQUIRE(FILE=OLDNAME, EXIST=THERE)
            IF(THERE) THEN
              OPEN(OLDDSN,FILE=OLDNAME, FORM='UNFORMATTED',STATUS='OLD',
     a            access='direct',recl=4)
              read(olddsn,rec=1) record_len
              close(olddsn)
              OPEN(OLDDSN,FILE=OLDNAME, FORM='UNFORMATTED',STATUS='OLD',
     a            access='direct',recl=record_len)
 
            ELSE
              WRITE(STDOUT,60) OLDNAME(1:len_trim(oldname))
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'NEW') THEN
C           Process the new file name.
            IF(NEWDSN.EQ.0) THEN
              NEWDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,62)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              NEWNAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,66) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

c           Open the new file, which may not yet exist, with 
c           dummy record length to make sure the path name 
c           and so forth are valid.  Later on, when we know
c           the record length, it will be closed and reopened.
            OPEN(NEWDSN,FILE=NEWNAME,FORM='UNFORMATTED',
     A               STATUS = 'UNKNOWN', IOSTAT=IOFLAG,
     b               access='direct',recl=4)
            IF(IOFLAG.NE.0) THEN
              WRITE(STDOUT,64) NEWNAME(1:len_trim(newname))
              STOP 'Abnormal stop: Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'END') THEN
C           Check if both the requireded files have been given.
            IF(OLDDSN.EQ.0) THEN
              WRITE(STDOUT,58)
              STOP 'Abnormal stop.  Errors found.'
            ELSEIF(NEWDSN.EQ.0) THEN
              WRITE(STDOUT,64)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
            WRITE(STDOUT,72)
            WRITE(STDOUT,*) ' '

            EFLAG = 0
            CALL smooth_tsf(STDOUT, OLDDSN, NEWDSN, OLDNAME,
     i                       newname, record_len,
     O                       EFLAG)
            CALL FREE_UNIT (STDOUT, OLDDSN)
            CALL FREE_UNIT (STDOUT, NEWDSN)
            RETURN
          ENDIF
          GOTO 100            
      ELSE
        WRITE(STDOUT,70)
        CALL FREE_UNIT (STDOUT, OLDDSN)
        CALL FREE_UNIT (STDOUT, NEWDSN)
        EFLAG = 1
      ENDIF

      RETURN
      END
                              


C     ***********
C     *         *
C     * PRINT_DTSF
C     *         *
C     ***********

      SUBROUTINE PRINT_DTSF(STDOUT, DTSFDSN, SJTIME, EJTIME,
     I                        DTSF_NAME,
     O                        EFLAG)

C     Print DTSF from SJTIME through EJTIME.  All values requested
C     are printed and event boundaries are ignored. 
      implicit none
      INTEGER STDOUT, DTSFDSN, EFLAG

      DOUBLE PRECISION SJTIME, EJTIME

      CHARACTER*(*) DTSF_NAME

C     Local

      INTEGER I, NDFVAL, TSFTYP, YR, MN, DY, NVAL,
     A           EYR, EMN, EDY, KOUNT, IOUT(:),
     B           MAXIMUM(:), MINIMUM(:), SUMMARY_OUTPUT_NEEDED,
     C           START_EVENT_FOUND, last_header_rec, nrec

      REAL R(2), R4(:), EHR, HOUR, SUM(:),
     A     AVERAGE(:), OUT(:)

      DOUBLE PRECISION JTIME, FRAC, DUMMY,  EJT

      ALLOCATABLE :: R4, MAXIMUM, MINIMUM, SUM, AVERAGE, OUT,
     A               IOUT

C     Called program units and intrinsics
      EXTERNAL INVMJD

      EQUIVALENCE (DUMMY, R(1))
C     *******************************FORMATS****************************
14    FORMAT(' Event start:',I5,'/',I2,'/',I2,':',F8.4,
     A       ' Event end:',I5,'/',I2,'/',I2,':',F8.4)
12    FORMAT(5X,'START TIME:',I4,'/',I2,'/',I2,':',F10.6,' JTIME=',
     A       F25.12)
15    FORMAT(17X,'  Runoff intensity is in units of 0.001 inch',
     A        ' per hour.')
16    FORMAT(I5,'/',I2,'/',I2,':',F6.3,100I5)
50    FORMAT(' Year Mn Dy   Hour',100I5)
51    FORMAT(' Maximum in event:',100I5)
52    FORMAT(' Minimum in event:',100I5)
53    FORMAT(' Average in event:',100F5.2)
54    FORMAT(' Hours in event=',I8)
70    FORMAT(/,' End of DTSF file found.')
72    FORMAT(/,' End of time window found.')
C***********************************************************************
C     Clear the start of event flag to prevent starting to print
C     in the middle of an event.
      START_EVENT_FOUND = 0

C     Supress checking of the number of diffuse values
      NDFVAL = 0
      CALL TSF_INIT(STDOUT, DTSF_NAME, DTSFDSN, 0, 
     M                    NDFVAL, 
     O                    TSFTYP, last_header_rec)

      ALLOCATE ( R4(NDFVAL), MAXIMUM(NDFVAL), 
     A           MINIMUM(NDFVAL), SUM(NDFVAL), AVERAGE(NDFVAL),
     B           OUT(NDFVAL), IOUT(NDFVAL) )

      nrec = last_header_rec + 1
100   CONTINUE
        READ(DTSFDSN,rec=nrec) JTIME, FRAC, YR, MN, DY, R4
        nrec = nrec + 1
        HOUR = 24.*FRAC
        
        IF(JTIME.EQ.0.D0) THEN
          WRITE(STDOUT,70)
          DEALLOCATE ( R4, MAXIMUM, MINIMUM, SUM, AVERAGE, OUT,
     A                 IOUT)
          RETURN
        ENDIF

        IF(ABS(JTIME).LT.SJTIME) THEN
C         Keep scanning 
          GOTO 100
        ELSEIF(ABS(JTIME).GT.EJTIME) THEN
C         Found end of requested time window.
          IF(SUMMARY_OUTPUT_NEEDED.EQ.1) THEN
            DO 105 I=1,NDFVAL
              AVERAGE(I) = SUM(I)/REAL(KOUNT)
105         CONTINUE
            WRITE(STDOUT,51) MAXIMUM
            WRITE(STDOUT,52) MINIMUM
            WRITE(STDOUT,53) AVERAGE
            WRITE(STDOUT,54) KOUNT
          ENDIF

          WRITE(STDOUT,72)
          DEALLOCATE ( R4, MAXIMUM, MINIMUM, SUM, AVERAGE, OUT,
     A                 IOUT)
          RETURN
        ENDIF          

        IF(JTIME.LT.0.D0) THEN 
C         FIRST RECORD OF THE EVENT
          R(1) = R4(1)
          R(2) = R4(2)
          EJT = DUMMY
          R4(1) = 0.0
          R4(2) = 0.0
C         Set the summary output flag used to prevent double summary
C         output.
          SUMMARY_OUTPUT_NEEDED = 1

C         Set the start event flag
          START_EVENT_FOUND = 1
          WRITE(STDOUT,*) ' '

          CALL JTIME_TO_FEQ_DATE(EJT,
     O                             EYR, EMN, EDY, EHR)
          WRITE(STDOUT,14)  YR, MN, DY, HOUR, EYR, EMN, EDY, EHR
          WRITE(STDOUT,15)
          WRITE(STDOUT,50) (I, I=1,NDFVAL)
C         Set values for computing statistics for each series.
          KOUNT = 0
          DO 110 I=1,NDFVAL
            SUM(I) = 0.0
            MAXIMUM(I) = -1
            MINIMUM(I) = 9999999
110       CONTINUE
        ELSEIF(START_EVENT_FOUND.EQ.1) THEN
C         Compute the rescaled values and statistics
          KOUNT = KOUNT + 1          
          DO 130 I=1,NDFVAL
            OUT(I) = 43200.E3*R4(I)
            IOUT(I) = INT(OUT(I) + 0.5)
130       CONTINUE
          WRITE(STDOUT,16) YR, MN, DY, HOUR, 
     A                   (IOUT(I), I=1,NDFVAL)
          DO 140 I=1,NDFVAL
            SUM(I) = SUM(I) + OUT(I)
            MAXIMUM(I) = MAX (MAXIMUM(I), IOUT(I))
            MINIMUM(I) = MIN (MINIMUM(I), IOUT(I))
140       CONTINUE

C         Is this the end of the event?
          IF(JTIME.EQ.EJT) THEN
C           Yes.  Output the statistics
            DO 150 I=1,NDFVAL
              AVERAGE(I) = SUM(I)/REAL(KOUNT)
150         CONTINUE
            WRITE(STDOUT,51) MAXIMUM
            WRITE(STDOUT,52) MINIMUM
            WRITE(STDOUT,53) AVERAGE
            WRITE(STDOUT,54) KOUNT
C           Clear the summary output flag used to prevent double summary
C           output.
            SUMMARY_OUTPUT_NEEDED = 0
          ENDIF
        ENDIF
        GOTO 100
      END

C     ***********
C     *         *
C     * PRINT  *
C     *         *
C     ***********

      SUBROUTINE PRINT(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 

C     Print a TSF
      implicit none
      INTEGER IFIRST, NVAL, MVAL, TYPE(NVAL), CLEN(NVAL),
     A        TERML(NVAL), TERMCLS(NVAL), IVAL(NVAL), STDOUT,
     B        STDIN,  EFLAG

      REAL RVAL(NVAL)

      DOUBLE PRECISION DPVAL(NVAL)

      CHARACTER CVAL(NVAL)*(*), TERM(NVAL)*1

C     Local

      LOGICAL THERE

      CHARACTER COMMAND*64, LINE*192, LINE2*194, STRINGS(4)*5,
     A          DTSF_NAME*64, KIND*5

      INTEGER I, ISTART, CL, OPT, DTSFDSN,
     A        NSTRING, ITERM, IT, record_len, ifound

      DOUBLE PRECISION  SJTIME, EJTIME

C     Program units

      INTEGER GET_UNIT

      EXTERNAL GET_UNIT, inline
           
      DATA NSTRING/4/, STRINGS/'START','STOP','DTSF','END'/
C     *****************************FORMATS******************************
50    FORMAT(/,' *ERR:XXX* No second level command found.')
52    FORMAT(/,' *ERR:XXX* Invalid values given for current command.')
54    FORMAT(1X,A)
56    FORMAT(/,' *ERR:XXX* DTSF file name appears twice.')
58    FORMAT(/,' *ERR:XXX* No file name found for DTSF.')
60    FORMAT(/,' *ERR:XXX* File name=',A,/,11X,'not found. Please ',
     A  'check name, path, and drive letter.')
64    FORMAT(/,' *ERR:XXX* Errors prevent printing.')
66    FORMAT(/,' *ERR:XXX* Could not open file name=',/,A,/,11X,
     A      'Please check name, path, and driver letter.')
68    FORMAT(/,' *ERR:XXX* No START time given.')
69    FORMAT(/,' *ERR:XXX* No STOP time given.')
70    FORMAT(/,' *ERR:XXX* Second level command invalid.')
72    FORMAT(/,' Processing command: PRINT DTSF')
C***********************************************************************
      OPT = 1
C     Clear the unit numbers so that they can be used to 
C     verify that both the old and the new file have been
C     properly defined. 
      DTSFDSN = 0

C     Clear the starting and ending time for error detection
      SJTIME = 0.D0
      EJTIME = 0.D0

C     Find the next string in the list.
      ISTART = IFIRST
      CALL FIND_NEXT_CHARACTER_STRING(MVAL, TYPE,
     M                                      ISTART)
      IF(ISTART.EQ.0) THEN
        WRITE(STDOUT,50) 
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      COMMAND = CVAL(ISTART)
      CL = CLEN(ISTART)
      
      IF(COMMAND(1:CL).EQ.'DTSF') THEN
C       Found valid response.  Process subsequent lines.
        WRITE(*,72) 
100     CONTINUE
          CALL inline (STDIN, STDOUT,
     O                LINE)

          WRITE(STDOUT,54) LINE(1:len_trim(line))

          LINE2 = LINE
          call maybe_add_quote(
     m                           line2)
          CALL GETVAL(STDOUT, LINE2, NVAL, OPT,
     O                 TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O                 TERM, TERML, TERMCLS, MVAL)
        
C          CALL DUMP_FINDINGS(STDOUT, MVAL, TYPE, CLEN, 
C     I                         TERM, TERMCLS, CVAL)

          ITERM = 1
          CALL FIND_TERMINATER(MVAL, TERM, '=',
     O                       ITERM)

          ISTART = 1
          IF(ITERM.GT.0) THEN
            IT = ITERM
          ELSE
            IT = MVAL
          ENDIF
          CALL FIND_ANY_STRING_IN_LIST(IT, NSTRING, TYPE, CVAL, CLEN,
     I                                  STRINGS,
     M                                  ISTART,
     O                                  IFOUND)

          IF(IFOUND.EQ.0) THEN
            WRITE(STDOUT,52)
            STOP 'Abnormal stop. Errors found.'
          ENDIF

          IF(STRINGS(IFOUND).EQ.'DTSF') THEN
C           Process the DTSF file name.
            IF(DTSFDSN.EQ.0) THEN
              DTSFDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,56) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              DTSF_NAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,58) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

            INQUIRE(FILE=DTSF_NAME, EXIST=THERE)
            IF(THERE) THEN
c             Open with recl = 4 to read the record length
              OPEN(DTSFDSN,FILE=DTSF_NAME,FORM='UNFORMATTED',
     A             STATUS='OLD', access='direct', recl=4)
              read(dtsfdsn, rec=1) record_len
              close(dtsfdsn)
              OPEN(DTSFDSN,FILE=DTSF_NAME,FORM='UNFORMATTED',
     A             STATUS='OLD', access='direct', recl=record_len)
            ELSE
              WRITE(STDOUT,60) DTSF_NAME
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'START') THEN
C           Get the start time.
            KIND = 'START'
            CALL GET_NEXT_TIME(STDOUT, KIND, ITERM+1, MVAL, 
     M                 TYPE, CVAL, TERM, 
     O                 SJTIME, EFLAG)
            IF(EFLAG.NE.0) SJTIME = 0.D0 

          ELSEIF(STRINGS(IFOUND).EQ.'END') THEN
C           Check if  the DTSF file was given.
            IF(DTSFDSN.EQ.0) THEN
              WRITE(STDOUT,58)
              EFLAG = 1
            ENDIF

            IF(SJTIME.EQ.0.D0) THEN
              WRITE(STDOUT,68)
              EFLAG = 1
            ENDIF
            IF(EJTIME.EQ.0.D0) THEN
              WRITE(STDOUT,69)
              EFLAG = 1
            ENDIF
        
            IF(EFLAG.EQ.0) THEN
C             Print the stuff!
              WRITE(STDOUT,72)
              WRITE(STDOUT,*) ' '

              CALL PRINT_DTSF(STDOUT, DTSFDSN, SJTIME, EJTIME,
     I                        DTSF_NAME,
     O                        EFLAG)
            ELSE
              WRITE(STDOUT,64)
            ENDIF
            CALL FREE_UNIT (STDOUT, DTSFDSN)
            RETURN
          ELSEIF(STRINGS(IFOUND).EQ.'STOP') THEN
C           Get the next time value, check for validity and put
C           it on the list.  The list will be sorted later
C           to make sure that it is in ascending order. 
 
            KIND = 'STOP'
            CALL GET_NEXT_TIME(STDOUT, KIND, ITERM+1, MVAL, 
     M                 TYPE, CVAL, TERM, 
     O                 EJTIME, EFLAG) 
            IF(EFLAG.NE.0) EJTIME = 0.D0
          ENDIF
          GOTO 100            
      ELSE
        WRITE(STDOUT,70)
        CALL FREE_UNIT(STDOUT, DTSFDSN)
        EFLAG = 1
      ENDIF

      RETURN
      END
C     ***********
C     *         *
C     * RESTORE_DTSF
C     *         *
C     ***********

      SUBROUTINE RESTORE_DTSF(STDOUT, ASCIIDSN, 
     i                       dtsf_name, DTSFDSN, 
     M                       EFLAG)

C     Restore a DTSF from its character dump format.
      implicit none
      INTEGER STDOUT, ASCIIDSN, DTSFDSN, EFLAG
      character*(*) dtsf_name

C     Local

      INTEGER I, j, TEMP(7), A(:), NDFVAL, TSFTYP, LIMIT, IR4(:),
     A        MJD, IFRAC, YR, MN, DY, record_len,
     b        last_header_rec, nrec

      REAL FACTOR, R(2), R4(:)

      DOUBLE PRECISION DUMMY, JTIME, EJTIME, FRAC

      CHARACTER*4 LINE(:)

      ALLOCATABLE :: A, R4, LINE, IR4


C     Called program units and intrinsics

      EXTERNAL INVMJD

      EQUIVALENCE (DUMMY, R(1))      
C     ****************************FORMATS******************************
2     FORMAT(7X,E15.0)
3     FORMAT(7I5)
4     FORMAT(20A4)
6     FORMAT(I7,I7,2I7,198I6)
50    FORMAT(/,' *WRN:XXX* TSF TYPE in ASCII file is not 1.',
     A ' It is taken to be 1.')
C*************************************l**********************************
C     Read the FACTOR
      READ(ASCIIDSN,2) FACTOR

C     Read the next line to define sizes
      READ(ASCIIDSN,3) TEMP
      NDFVAL = TEMP(6)
      TSFTYP = TEMP(7)
      IF(TSFTYP.NE.1) THEN
        WRITE(STDOUT,50)       
        TSFTYP = 1
        TEMP(7) = 1
      ENDIF

      LIMIT = 7 + NDFVAL
      record_len = 4*limit
      last_header_rec = 4 + ndfval
      close(dtsfdsn)
      OPEN(DTSFDSN,FILE=DTSF_NAME,FORM='UNFORMATTED',
     A         STATUS = 'UNKNOWN', 
     a         access='direct', recl=record_len)


      ALLOCATE ( A(LIMIT), R4(NDFVAL),  LINE(LIMIT), IR4(NDFVAL) )

c     write record length
      write(dtsfdsn, rec=1) record_len
C     Create second  record of DTSF
      DO 100 I=1,7
        A(I) = TEMP(I)
100   CONTINUE
      DO 102 I=8,LIMIT
        A(I) = 0
102   CONTINUE

      WRITE(DTSFDSN, rec=2) A

C     Do third record

      A = 0
      READ(ASCIIDSN,3) (A(I), I=1,6)
      WRITE(DTSFDSN,rec=3) A

C     The next NDFVAL + 1 records are all character strings of info.

      DO 110 I=1,NDFVAL+1
        DO 108 J=1,LIMIT
          LINE(J) = '    '
108     CONTINUE
        READ(ASCIIDSN,4) (LINE(J), J=1,MIN(20,LIMIT))
        WRITE(DTSFDSN, rec=3+i) LINE
110   CONTINUE

C     All heading lines have been written.  Now process the lines for the events. 

      nrec = last_header_rec + 1
500   CONTINUE
        READ(ASCIIDSN,6) MJD, IFRAC, IR4
        
C       Branch on value of MJD: < 0-first record of an event
C                               = 0-last record of the DTSF
C                               > 0-data record in an event

        IF(MJD.LT.0.0) THEN
C         First record of an event.  Define the julian times.
          MJD = -MJD
          FRAC = DBLE(IFRAC)/9999999.D0
          JTIME = DBLE(MJD) + FRAC
          JTIME = -JTIME
          
          EJTIME = DBLE(IR4(1)) + DBLE(IR4(2))/9999999.D0
         
C         Get the calender date.
          CALL INVMJD(MJD,
     O                 YR, MN, DY)                                        

C         Set the end time in the data record
          DUMMY = EJTIME
          R4(1) = R(1)
          R4(2) = R(2)
          DO 115 I=3,NDFVAL
            R4(I) = 0.0
115       CONTINUE

          WRITE(DTSFDSN, rec=nrec) JTIME, FRAC, YR, MN, DY, R4
          nrec = nrec + 1

        ELSEIF(MJD.GT.0.0) THEN
C         Data record not first in event. Get the julian time and 
C         calendar date.
          FRAC = DBLE(IFRAC)/9999999.D0
          JTIME = DBLE(MJD) + FRAC
          CALL INVMJD(MJD,
     O                 YR, MN, DY)                                        
                        
C         Convert the data values
          DO 120 I=1,NDFVAL
            R4(I) = REAL(IR4(I))/FACTOR
120       CONTINUE
          WRITE(DTSFDSN, rec=nrec) JTIME, FRAC, YR, MN, DY, R4
          nrec = nrec + 1

        ELSE
C         MJD = 0 here.  End of the DTSF
          JTIME = 0.D0
          FRAC = 0.D0
          YR = 0
          MN = 0
          DY = 0
          DO 125 I=1,NDFVAL
            R4(I) = 0.0
125       CONTINUE
          WRITE(DTSFDSN, rec=nrec) JTIME, FRAC, YR, MN, DY, R4
          DEALLOCATE ( A, R4,  LINE, IR4 )
          WRITE(STDOUT,*) ' '
          WRITE(STDOUT,*) ' All events restored to DTSF file.'
          RETURN
        ENDIF
        GOTO 500
      END
C        
C     ***********
C     *         *
C     * RESTORE  *
C     *         *
C     ***********

      SUBROUTINE RESTORE(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 

C     Restore a TSF from its character dump format. 
      implicit none
      INTEGER IFIRST, NVAL, MVAL, TYPE(NVAL), CLEN(NVAL),
     A        TERML(NVAL), TERMCLS(NVAL), IVAL(NVAL), STDOUT,
     B        STDIN,  EFLAG

      REAL RVAL(NVAL)

      DOUBLE PRECISION DPVAL(NVAL)

      CHARACTER CVAL(NVAL)*(*), TERM(NVAL)*1

C     Local

      LOGICAL THERE

      CHARACTER COMMAND*64, LINE*80, LINE2*82, STRINGS(3)*5,
     A          ASCII_NAME*64, DTSF_NAME*64

      INTEGER I, ISTART, CL, OPT, ASCIIDSN, DTSFDSN,
     A        NSTRING, ITERM, IT, ifound, ioflag

C     Program units

      INTEGER GET_UNIT

      EXTERNAL GET_UNIT
           
      DATA NSTRING/3/, STRINGS/'ASCII','DTSF','END'/
C     *****************************FORMATS******************************
50    FORMAT(/,' *ERR:XXX* No second level command found.')
52    FORMAT(/,' *ERR:XXX* Invalid values given for current command.')
54    FORMAT(1X,A)
56    FORMAT(/,' *ERR:XXX* DTSF file name appears twice.')
58    FORMAT(/,' *ERR:XXX* No file name found for DTSF.')
60    FORMAT(/,' *ERR:XXX* File name=',A,/,11X,'not found. Please ',
     A  'check name, path, and drive letter.')
62    FORMAT(/,' *ERR:XXX* ASCII file name appears twice.')
64    FORMAT(/,' *ERR:XXX* No file name found for ASCII file.')
66    FORMAT(/,' *ERR:XXX* Could not open file name=',/,A,/,11X,
     A      'Please check name, path, and driver letter.')
68    FORMAT(/,' *ERR:XXX* SHOULD NOT SEE THIS MESSAGE.')
70    FORMAT(/,' *ERR:XXX* Second level command invalid.')
72    FORMAT(/,' Processing command: RESTORE DTSF')
C***********************************************************************
      OPT = 1
C     Clear the unit numbers so that they can be used to 
C     verify that both the old and the new file have been
C     properly defined. 
      ASCIIDSN = 0
      DTSFDSN = 0

C     Find the next string in the list.
      ISTART = IFIRST
      CALL FIND_NEXT_CHARACTER_STRING(MVAL, TYPE,
     M                                      ISTART)
      IF(ISTART.EQ.0) THEN
        WRITE(STDOUT,50) 
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      COMMAND = CVAL(ISTART)
      CL = CLEN(ISTART)
      
      IF(COMMAND(1:CL).EQ.'DTSF') THEN
        WRITE(*,72)
C       Found valid response.  Process subsequent lines.

100     CONTINUE
          CALL inline(STDIN, STDOUT,
     O                LINE)

          WRITE(STDOUT,54) LINE(1:len_trim(line))

          LINE2 = LINE
          call maybe_add_quote(
     m                           line2)
          CALL GETVAL(STDOUT, LINE2, NVAL, OPT,
     O                 TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O                 TERM, TERML, TERMCLS, MVAL)
        
          ITERM = 1
          CALL FIND_TERMINATER(MVAL, TERM, '=',
     O                       ITERM)

          ISTART = 1
          IF(ITERM.GT.0) THEN
            IT = ITERM
          ELSE
            IT = MVAL
          ENDIF
          CALL FIND_ANY_STRING_IN_LIST(IT, NSTRING, TYPE, CVAL, CLEN,
     I                                  STRINGS,
     M                                  ISTART,
     O                                  IFOUND)

          IF(IFOUND.EQ.0) THEN
            WRITE(STDOUT,52)
            STOP 'Abnormal stop. Errors found.'
          ENDIF

          IF(STRINGS(IFOUND).EQ.'ASCII') THEN
C           Process the old file name.
            IF(ASCIIDSN.EQ.0) THEN
              ASCIIDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,56) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              ASCII_NAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,58) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

            INQUIRE(FILE=ASCII_NAME, EXIST=THERE)
            IF(THERE) THEN
              OPEN(ASCIIDSN,FILE=ASCII_NAME,FORM='FORMATTED',
     A             STATUS='OLD')
            ELSE
              WRITE(STDOUT,60) ASCII_NAME
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'DTSF') THEN
C           Process the new file name.
            IF(DTSFDSN.EQ.0) THEN
              DTSFDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,62)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              DTSF_NAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,66) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

            OPEN(DTSFDSN,FILE=DTSF_NAME,FORM='UNFORMATTED',
     A               STATUS = 'UNKNOWN', IOSTAT=IOFLAG,
     a               access='direct', recl=4)
            IF(IOFLAG.NE.0) THEN
              WRITE(STDOUT,64) DTSF_NAME
              STOP 'Abnormal stop: Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'END') THEN
C           Check if both the required files have been given.
            IF(ASCIIDSN.EQ.0) THEN
              WRITE(STDOUT,58)
              STOP 'Abnormal stop.  Errors found.'
            ELSEIF(DTSFDSN.EQ.0) THEN
              WRITE(STDOUT,64)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
            WRITE(STDOUT,72)
            WRITE(STDOUT,*) ' '

            EFLAG = 0
            CALL RESTORE_DTSF(STDOUT, ASCIIDSN, 
     i                        dtsf_name, DTSFDSN,
     O                       EFLAG)
            IF(EFLAG.GT.0) THEN
              WRITE(STDOUT,68) 
            ENDIF
            CALL FREE_UNIT (STDOUT, ASCIIDSN)
            CALL FREE_UNIT (STDOUT, DTSFDSN)
            RETURN
          ENDIF
          GOTO 100            
      ELSE
        WRITE(STDOUT,70)
        CALL FREE_UNIT (STDOUT, ASCIIDSN)
        CALL FREE_UNIT (STDOUT, DTSFDSN)
        EFLAG = 1
      ENDIF

      RETURN
      END
C     **************
C     *            *
C     *  TSF_INIT_DUMP    *
C     *            *
C     **************
 
      SUBROUTINE TSF_INIT_DUMP(STDOUT, DTSF_NAME, DTSFDSN, ASCIIDSN,
     I                    FACTOR,
     M                    NDFVAL, 
     O                    TSFTYP, last_header_rec)
 
C     Read header records in the TSF given by DTSF_NAME, 
C     and dump the information to the character format file
C     attached to ASCIDSN
      implicit none
      CHARACTER*(*) DTSF_NAME
 
      INTEGER DTSFDSN, ASCIIDSN, NDFVAL, STDOUT, TSFTYP,
     a last_header_rec

      REAL FACTOR

C     LOCAL

      INTEGER I, J, limit

      INTEGER A(:)

      ALLOCATABLE :: A

      INTEGER TEMP(10)
 
C     ************************* FORMATS *******************************
10    FORMAT(/,' The current TSF was created on ',
     1I4,'/',I2,'/',I2,' AT ',I4,' and has ',I3,
     2' LSRO values.')
11    FORMAT(' ','Simulation for the ',
     1'runoff values began on ',I4,'/',
     2I2,'/',I2,' and ended on ',I4,'/',I2,'/',I2,'.')
 
14    FORMAT(/,1X,20A4)
16    FORMAT(4X,'LSRO# ',I3,':',20A4)
19    FORMAT('FACTOR=',1PE15.6)
20    FORMAT(7I5)
21    FORMAT(20A4)
52    FORMAT(\,' DTSF=',1X,A,/,
     A         '     uses 8 Bytes for each runoff value.')
53    format(4x,'Please convert to 4 bytes/runoff value.')
54    FORMAT(\,' DTSF=',A,/,
     A         '     uses 4 Bytes for each runoff value.')
56    FORMAT(//,' Information from the header records in the DSTF:')
C**********************************************************************
C     Read the first part of the second record to establish the format of
C     the DTSF

      READ(DTSFDSN, rec=2) (TEMP(I), I=1,7)
      NDFVAL = TEMP(6)
      TSFTYP = TEMP(7)
      
      IF(TSFTYP.EQ.0) THEN
        WRITE(STDOUT,*) ' '
        WRITE(STDOUT,52) DTSF_NAME(1:len_trim(dtsf_name))
        write(stdout,53) 
      ELSE
        WRITE(STDOUT,54) DTSF_NAME(1:len_trim(dtsf_name))
        WRITE(STDOUT,*) ' '
      ENDIF

C     Reopen the tsf file to restart at first record

      
      LIMIT = 7 + NDFVAL

C     Output the mulitplying factor to the character file.
      WRITE(ASCIIDSN,19) FACTOR

      ALLOCATE (A(LIMIT))


      READ(DTSFDSN, rec=2) A

      WRITE(ASCIIDSN, 20) (A(I), I=1,7)
 
      DO 12 I=1,4
        TEMP(I) = A(I)
12    CONTINUE

      READ(DTSFDSN, rec=3) A
      
C     Write second line

      WRITE(ASCIIDSN,20) (A(I), I=1, 6)

      DO 13 I=5,10
        TEMP(I) = A(I-4)
13    CONTINUE

      DO 103 I=1,LIMIT
        A(I) = 0
103   CONTINUE 
      READ(DTSFDSN, rec=4) (A(I), I=1,LIMIT)
C     WRITE THIRD RECORD OF THE TSF

      WRITE(ASCIIDSN,21) (A(I), I=1, MIN(7 + NDFVAL, 20))

      WRITE(STDOUT,56)
      WRITE(STDOUT,14) (A(I), I=1,MIN(20,LIMIT))
      WRITE(STDOUT,10) (TEMP(I), I=1,4), NDFVAL
      WRITE(STDOUT,11) (TEMP(I), I=5,10)
      DO 15 I=1,NDFVAL
        READ(DTSFDSN, rec=4+i) A
        WRITE(ASCIIDSN,21) (A(J), J=1,MIN(7 + NDFVAL,20))
        WRITE(STDOUT,16) I, (A(J), J=1,MIN(20,LIMIT))
15    CONTINUE

      DEALLOCATE ( A)
      last_header_rec = 4 + ndfval
      RETURN
      END
C     ***********
C     *         *
C     * DUMP_DTSF
C     *         *
C     ***********

      SUBROUTINE DUMP_DTSF(STDOUT, DTSFDSN, ASCIIDSN, DTSF_NAME,
     I                         FACTOR,
     O                         EFLAG)
      implicit none
C     Dump a DTSF in character form.

      INTEGER STDOUT, DTSFDSN, ASCIIDSN,  EFLAG

      CHARACTER*(*) DTSF_NAME

      REAL FACTOR

C     Local
      
      INTEGER NDFVAL, TSFTYP, I, YR, MN, DY, NVAL, MJD, 
     A        IFRAC, IRUNOFF(:), last_header_rec, nrec

      REAL R(2), R4(:)

      DOUBLE PRECISION DUMMY, FRAC, JTIME,  EJTIME, RT(:), 
     A                 TRUNCATION_ERROR(:)

      ALLOCATABLE ::  R4, IRUNOFF, TRUNCATION_ERROR, RT

C     Called program units.

      INTRINSIC DBLE, INT

      EXTERNAL TSF_INIT_DUMP
      
      EQUIVALENCE(DUMMY, R(1))

C     ********************************FORMATS***************************
22    FORMAT(I7,I7,2I7,198I6)
C***********************************************************************
C     Dump the header records.
      CALL TSF_INIT_DUMP(STDOUT, DTSF_NAME, DTSFDSN, ASCIIDSN,
     I                    FACTOR,
     M                    NDFVAL, 
     O                    TSFTYP, last_header_rec)

      ALLOCATE (IRUNOFF(NDFVAL),TRUNCATION_ERROR(NDFVAL), RT(NDFVAL) )


      ALLOCATE (R4(NDFVAL))

      nrec = last_header_rec + 1
C     Read each record.  The header records have been converted
C     to character form in TSF_INIT_DUMP.  
      

100   CONTINUE
        READ(DTSFDSN, rec=nrec) JTIME, FRAC, YR, MN, DY,  R4
        nrec = nrec + 1
        DO 105 I=1,NDFVAL
          RT(I) = DBLE(R4(I))
105     CONTINUE

        IF(JTIME.GT.0.0) THEN
C         Convert JTIME to MJD and a fraction of the day.  The MJD
C         is 5 characters.  Make the fraction of the day 7 chars.
          
          MJD = INT(JTIME)
          FRAC = JTIME - DBLE(MJD)
          IFRAC = INT(9999999.D0*FRAC + 0.5D0)
          DO 110 I=1,NDFVAL
            IRUNOFF(I) = INT(FACTOR*(RT(I) + TRUNCATION_ERROR(I)) + 0.5)
            TRUNCATION_ERROR(I) = TRUNCATION_ERROR(I) +
     A                             (RT(I) - DBLE(IRUNOFF(I))/FACTOR)
110       CONTINUE
          WRITE(ASCIIDSN, 22) MJD, IFRAC, IRUNOFF
        ELSEIF(JTIME.LT.0.0) THEN
C         This is the first record of an event.  Must extract
C         the ending time and store properly.
          R(1) = R4(1)
          R(2) = R4(2)
          EJTIME = DUMMY
          MJD = INT(EJTIME)
          FRAC = EJTIME - DBLE(MJD)
          IFRAC = INT(9999999.D0*FRAC + 0.5D0)
          IRUNOFF(1) = MJD
          IRUNOFF(2) = IFRAC
          DO 115 I=3,NDFVAL
            IRUNOFF(I) = 0
115       CONTINUE

C         Now convert the JTIME value and make its MJD < 0
          JTIME = -JTIME
          MJD = INT(JTIME)
          FRAC = JTIME - DBLE(MJD)
          IFRAC = INT(9999999.D0*FRAC + 0.5D0)
          MJD = -MJD
          WRITE(ASCIIDSN, 22) MJD, IFRAC, IRUNOFF
C         Clear the running sum of truncation error 
          DO 117 I=1,NDFVAL
            TRUNCATION_ERROR(I) = 0.D0
117       CONTINUE
        ELSEIF(JTIME.EQ.0.0D0) THEN
          DEALLOCATE (R4)

          MJD = 0
          IFRAC = 0
          DO 120 I=1,NDFVAL
            IRUNOFF(I) = 0
120       CONTINUE            
          WRITE(ASCIIDSN, 22) MJD, IFRAC, IRUNOFF
          DEALLOCATE (IRUNOFF, TRUNCATION_ERROR, RT)
          WRITE(STDOUT,*) ' '
          WRITE(STDOUT,*) ' All events transfered to ASCII file.'
         RETURN
        ENDIF

        GOTO 100

      END
C     ***********
C     *         *
C     * DUMP
C     *         *
C     ***********

      SUBROUTINE DUMP(STDIN, STDOUT, IFIRST, NVAL, 
     M              MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M              TERM, TERML, TERMCLS, 
     O              EFLAG) 

C     Output an ASCII dump to transfer unformated time series
C     files to another hardware platform.
      implicit none
      INTEGER IFIRST, NVAL, MVAL, TYPE(NVAL), CLEN(NVAL),
     A        TERML(NVAL), TERMCLS(NVAL), IVAL(NVAL), STDOUT,
     B        STDIN,  EFLAG

      REAL RVAL(NVAL)

      DOUBLE PRECISION DPVAL(NVAL)

      CHARACTER CVAL(NVAL)*(*), TERM(NVAL)*1

C     Local

      INTEGER  CHRVAL, INTVAL, REAVAL, DPRVAL
      PARAMETER(INTVAL=1, REAVAL=2, DPRVAL=3, CHRVAL=4)

      LOGICAL THERE

      CHARACTER COMMAND*64, LINE*192, LINE2*194, STRINGS(4)*6,
     A          DTSF_NAME*128, ASCII_NAME*128

      INTEGER I, ISTART, CL, OPT, DTSFDSN, ASCIIDSN,
     A        NSTRING, ITERM, IT, record_len, ifound, ioflag

      REAL FACTOR

C     Program units

      INTEGER GET_UNIT

      EXTERNAL GET_UNIT, FIND_NEXT_CHARACTER_STRING, inline,
     A         GETVAL, DUMP_FINDINGS, FIND_TERMINATER,
     B         FIND_ANY_STRING_IN_LIST, FREE_UNIT,
     C         DUMP_DTSF
           
      DATA NSTRING/4/, STRINGS/'FACTOR','DTSF','ASCII','END'/
C     *****************************FORMATS******************************
50    FORMAT(/,' *ERR:XXX* No second level command found.')
52    FORMAT(/,' *ERR:XXX* Invalid values given for current command.')
54    FORMAT(1X,A)
56    FORMAT(/,' *ERR:XXX* DTSF file name appears twice.')
58    FORMAT(/,' *ERR:XXX* No file name found for DTSF.')
60    FORMAT(/,' *ERR:XXX* File name=',A,/,11X,'not found. Please ',
     A  'check name, path, and drive letter.')
62    FORMAT(/,' *ERR:XXX* ASCII file name appears twice.')
64    FORMAT(/,' *ERR:XXX* No file name found for ASCII file.')
66    FORMAT(/,' *ERR:XXX* Could not open file name=',/,A,/,11X,
     A      'Please check name, path, and driver letter.')
68    FORMAT(/,' *ERR:XXX* No FACTOR given.')
70    FORMAT(/,' *ERR:XXX* Second level command invalid.')
72    FORMAT(/,' Processing command: DUMP DTSF')
C***********************************************************************
      OPT = 1
C     Clear the unit numbers so that they can be used to 
C     verify that both the old and the new file have been
C     properly defined. 
      DTSFDSN = 0
      ASCIIDSN = 0

C     Clear the multiplying factor 
      FACTOR = 0.0

C     Find the next string in the list.
      ISTART = IFIRST
      CALL FIND_NEXT_CHARACTER_STRING(MVAL, TYPE,
     M                                      ISTART)
      IF(ISTART.EQ.0) THEN
        WRITE(STDOUT,50) 
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      COMMAND = CVAL(ISTART)
      CL = CLEN(ISTART)
      
      IF(COMMAND(1:CL).EQ.'DTSF') THEN
C       Found valid response.  Process subsequent lines.
        WRITE(*,72) 
100     CONTINUE
          CALL inline (STDIN, STDOUT,
     O                LINE)

          WRITE(STDOUT,54) LINE(1:len_trim(line))

          LINE2 = LINE
          call maybe_add_quote(
     m                           line2)
          CALL GETVAL(STDOUT, LINE2, NVAL, OPT,
     O                 TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O                 TERM, TERML, TERMCLS, MVAL)
        
C          CALL DUMP_FINDINGS(STDOUT, MVAL, TYPE, CLEN, 
C     I                         TERM, TERMCLS, CVAL)

          ITERM = 1
          CALL FIND_TERMINATER(MVAL, TERM, '=',
     O                       ITERM)

          ISTART = 1
          IF(ITERM.GT.0) THEN
            IT = ITERM
          ELSE
            IT = MVAL
          ENDIF
          CALL FIND_ANY_STRING_IN_LIST(IT, NSTRING, TYPE, CVAL, CLEN,
     I                                  STRINGS,
     M                                  ISTART,
     O                                  IFOUND)

          IF(IFOUND.EQ.0) THEN
            WRITE(STDOUT,52)
            STOP 'Abnormal stop. Errors found.'
          ENDIF

          IF(STRINGS(IFOUND).EQ.'DTSF') THEN
C           Process the DTSF file name.
            IF(DTSFDSN.EQ.0) THEN
              DTSFDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,56) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              DTSF_NAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,58) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

            INQUIRE(FILE=DTSF_NAME, EXIST=THERE)
            IF(THERE) THEN
c             open with recl=4 to get the true record length             
              OPEN(DTSFDSN,FILE=DTSF_NAME,FORM='UNFORMATTED',
     A             STATUS='OLD', access='direct', recl=4)
              read(dtsfdsn, rec=1) record_len
              close(dtsfdsn)
              OPEN(DTSFDSN,FILE=DTSF_NAME,FORM='UNFORMATTED',
     A             STATUS='OLD', access='direct', recl=record_len)
            ELSE
              WRITE(STDOUT,60) DTSF_NAME
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'ASCII') THEN
C           Process the new file name.
            IF(ASCIIDSN.EQ.0) THEN
              ASCIIDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,62)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              ASCII_NAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,66) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

            OPEN(ASCIIDSN,FILE=ASCII_NAME,FORM='FORMATTED',
     A               STATUS = 'UNKNOWN', IOSTAT=IOFLAG)
            IF(IOFLAG.NE.0) THEN
              WRITE(STDOUT,64) ASCII_NAME
              STOP 'Abnormal stop: Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'END') THEN
C           Check if both the requireded files have been given.
            IF(DTSFDSN.EQ.0) THEN
              WRITE(STDOUT,58)
              STOP 'Abnormal stop.  Errors found.'
            ELSEIF(ASCIIDSN.EQ.0) THEN
              WRITE(STDOUT,64)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
            IF(FACTOR.LE.0.0) THEN
              WRITE(STDOUT,68)
              CALL FREE_UNIT(STDOUT, DTSFDSN)
              CALL FREE_UNIT(STDOUT, ASCIIDSN)
              EFLAG = 1
              RETURN
            ENDIF
            WRITE(STDOUT,72)
            WRITE(STDOUT,*) ' '

            EFLAG = 0
            CALL DUMP_DTSF(STDOUT, DTSFDSN, ASCIIDSN, DTSF_NAME,
     I                         FACTOR,
     O                         EFLAG)
            CALL FREE_UNIT (STDOUT, DTSFDSN)
            CALL FREE_UNIT (STDOUT, ASCIIDSN)
            RETURN
          ELSEIF(STRINGS(IFOUND).EQ.'FACTOR') THEN
C           Get the multiplying factor for converting the
C           runoff values to large integers. 
            IF(ITERM.GT.0) THEN
              IF(TYPE(ITERM+1).NE.CHRVAL) THEN
C               Take any type but an identifier.  
                READ(CVAL(ITERM+1)(1:15),'(BN,E15.0)') FACTOR
              ELSE
                WRITE(STDOUT,68)
                EFLAG = 1
              ENDIF
            ELSE
              WRITE(STDOUT,68) 
              EFLAG = 1
            ENDIF            
                    
          ENDIF
          GOTO 100            
      ELSE
        WRITE(STDOUT,70)
        CALL FREE_UNIT(STDOUT, DTSFDSN)
        CALL FREE_UNIT(STDOUT, ASCIIDSN)
        EFLAG = 1
      ENDIF

      RETURN
      END

C     ***********
C     *         *
C     * JTIME_TO_FEQ_DATE
C     *         *
C     ***********

      SUBROUTINE JTIME_TO_FEQ_DATE(JTIME,
     O                             YEAR, MONTH, DAY, HOUR)

C     Convert a julian time to the values needed for FEQ date
C     format. 
      implicit none
      INTEGER YEAR, MONTH, DAY

      REAL HOUR

      DOUBLE PRECISION JTIME

C     Local

      INTEGER MJDATE

C     Called program units

      INTRINSIC INT, DBLE

      EXTERNAL INVMJD
C***********************************************************************
      MJDATE = INT (JTIME)                                       
      HOUR = 24.D0*(JTIME - DBLE (MJDATE))                       
      CALL INVMJD(MJDATE,                                              
     O              YEAR, MONTH, DAY)                                        
      RETURN
      END
C     *******************
C     *                 *
C     *  MERGE_DTSF
C     *                 *
C     *******************

      SUBROUTINE MERGE_DTSF(STDOUT, OLDTSF, OLDDSN, NEWDSN, SECTSF,
     i                      record_len,
     M                       NSEC)

C     Merge DTSF's in the following manner:

C     A primary TSF and one or more secondary TSF's exist. The 
C     time spans of the secondary TSF's are disjoint where the time 
C     span of a TSF is the time interval beginning at the start time
C     of the first event in the TSF(excluding the null event which 
C     starts every TSF) and ending at the end of the last event in the
C     TSF.  This restriction means that the secondary TSF's do not
C     need to be merged themselves.  

C     MERTSF also converts any old format TSF's to the new format in the
C     process of merging.  Thus the new TSF created by the program is
C     always in the new format.  The primary and secondary TSF's may be
C     in either format.
      implicit none
      INTEGER STDOUT, OLDDSN, NEWDSN, record_len, nsec

      CHARACTER*(*) SECTSF(NSEC), OLDTSF
      

C     Local

      INTEGER I, TSFTYP,  PFLAG, NDFVAL, KNT, SECDSN,
     A        DONE, SYROLD, SYRNEW, SYRSEC, SMNOLD, SMNNEW, SMNSEC, 
     B        SDYOLD, SDYNEW, SDYSEC, SECTYP, YR, MN, DY,
     c        last_header_rec, nrecold, nrecnew, nrecsec, nrecdummy,
     d        sopt, popt

      REAL R4(:), R(2), hour

      DOUBLE PRECISION SJTOLD, SJTNEW, SJTSEC, DYFOLD, DYFNEW, DYFSEC,
     A                 EJTOLD, EJTNEW, EJTSEC, DUMMY


      ALLOCATABLE :: R4
      
C     Called program units and intrinsics

      INTEGER GET_UNIT
      EXTERNAL GET_UNIT, FREE_UNIT, TSF_INIT, MEVENT,
     A         JTIME_TO_FEQ_DATE
      
      EQUIVALENCE(DUMMY, R(1))
C     ******************************** FORMATS *************************
50    FORMAT(' Event with starting time=',I5,'/',I2,'/',I2,':',F6.3,
     A      ' has been transfered.')
52    FORMAT(' All events for DTSF=',A,
     a  /,5x,' transfered.')
C*********************************************************************** 

c     sopt  - option flag for secondary DTSF.  Set to 1 if the first
c             record of an event has already been read before mevent
c             is called to process a secondary event. 
c     popt - option flag for primary DTSF.  Set to 1 if first record 
c            of an event has already been read before mevent is called. 
     
C     Clear the primary tsf endfile flag

      PFLAG = 0

c     Clear both first-event-record flags
      popt = 0
      sopt = 0

C     Request setting of the number of diffuse values(number of runoff
C     values per record

      NDFVAL = 0

      CALL TSF_INIT(STDOUT, OLDTSF, OLDDSN, NEWDSN, 
     M               NDFVAL,
     O               TSFTYP, last_header_rec)

      ALLOCATE (  R4(NDFVAL) )

      nrecold = last_header_rec + 1
      nrecnew = last_header_rec + 1
      nrecdummy = 1

C     Transfer the null event- first record has not been read

      CALL MEVENT(STDOUT, popt, OLDDSN, NEWDSN, NDFVAL, TSFTYP, 
     M            SJTOLD, DYFOLD, SYROLD, SMNOLD, SDYOLD, EJTOLD, 
     M            R4,
     m            nrecold, nrecnew,
     O            DONE)

      CALL JTIME_TO_FEQ_DATE(ABS(SJTOLD),
     O                       YR, MN, DY, HOUR)
      WRITE(STDOUT,50) YR, MN, DY, HOUR
      WRITE(*,50) YR, MN, DY, HOUR

C     Process the secondary DTSF's in order given by user

      KNT = 1
200   CONTINUE

        IF(NSEC.EQ.0) THEN
C         Check if the primary tsf has been transfered
          IF(PFLAG.EQ.1) THEN
C           All events have been transfered to the new tsf.
            SJTNEW = 0.D0
            DYFNEW = 0.D0
            SYRNEW = 0
            SMNNEW = 0
            SDYNEW = 0
            DO 210 I=1,NDFVAL
              R4(I) = 0.0
210         CONTINUE
            WRITE(NEWDSN, rec=nrecnew) 
     a        SJTNEW, DYFNEW, SYRNEW, SMNNEW, SDYNEW, R4
            nrecnew = nrecnew + 1
            WRITE(STDOUT,52) OLDTSF(1:len_trim(oldtsf))            
            DEALLOCATE(R4)                   
            RETURN
          ELSE
C           Not all events in the primary DTSF have been transfered.
C           Complete the transfer 

           
220         CONTINUE
              CALL MEVENT(STDOUT, popt, OLDDSN, NEWDSN, NDFVAL, TSFTYP, 
     M                 SJTOLD, DYFOLD, SYROLD, SMNOLD, SDYOLD, EJTOLD, 
     M                 R4,
     m            nrecold, nrecnew,
     O                 DONE)
              IF(DONE.EQ.0) THEN
                CALL JTIME_TO_FEQ_DATE(ABS(SJTOLD),
     O                                 YR, MN, DY, HOUR)
                WRITE(STDOUT,50) YR, MN, DY, HOUR
                WRITE(*,50) YR, MN, DY, HOUR
              ENDIF
c             clear primary opt flag because the event has been completed.
              popt = 0
              IF(DONE.EQ.0) GOTO 220
            SJTNEW = 0.D0
            DYFNEW = 0.D0
            SYRNEW = 0
            SMNNEW = 0
            SDYNEW = 0
            DO 230 I=1,NDFVAL
              R4(I) = 0.0
230         CONTINUE
c           write the end-of-file record to the new tsf. 
            WRITE(NEWDSN, rec=nrecnew) 
     a    SJTNEW, DYFNEW, SYRNEW, SMNNEW, SDYNEW, R4
            nrecnew = nrecnew + 1
            WRITE(STDOUT,52) OLDTSF(1:len_trim(oldtsf))            
                                 
            DEALLOCATE(R4)                   
            RETURN
          ENDIF
        ELSE
C         Secondary DTSF's remain to be transfered    

          SECDSN = GET_UNIT (STDOUT)
          OPEN(UNIT=SECDSN, FILE=SECTSF(KNT), FORM='UNFORMATTED',
     A          STATUS='OLD', access='direct', recl=record_len)

C         Read and discard header and check for compatibility

          CALL TSF_INIT(STDOUT, SECTSF(KNT), SECDSN, 0, 
     M                  NDFVAL, 
     O                  SECTYP, last_header_rec)

          nrecsec = last_header_rec + 1

          KNT = KNT + 1
          NSEC = NSEC - 1
          sopt = 0
C         Read and discard the null event
                          
          CALL MEVENT(STDOUT, sopt, SECDSN, 0, NDFVAL, SECTYP, 
     M             SJTSEC, DYFSEC, SYRSEC, SMNSEC, SDYSEC, EJTSEC, 
     M             R4,
     m             nrecsec, nrecdummy,
     O             DONE)
          
500       CONTINUE

C         Read the first record of the next non-null event in the
C         secondary DTSF

          READ(SECDSN, rec=nrecsec) 
     a          SJTSEC, DYFSEC, SYRSEC, SMNSEC, SDYSEC, R4
          nrecsec = nrecsec + 1
          R(1) = R4(1)
          R(2) = R4(2)
          EJTSEC = DUMMY
          sopt = 1

          IF(SJTSEC.EQ.0.D0) THEN
            CALL FREE_UNIT(STDOUT, SECDSN)
            WRITE(STDOUT,52) SECTSF(KNT-1)(1:len_trim(sectsf(knt-1)))
            GOTO 200
          ENDIF

C         Is primary DTSF exhausted?

550       CONTINUE
          IF(PFLAG.EQ.1) THEN
C           Yes, the primary DTSF has been transferred
C           Transfer remaining events in the secondary DTSF
            
            
600         CONTINUE
              CALL MEVENT(STDOUT, sopt, SECDSN, NEWDSN, NDFVAL, SECTYP, 
     M                 SJTSEC, DYFSEC, SYRSEC, SMNSEC, SDYSEC, EJTSEC, 
     M                 R4,
     m                 nrecsec, nrecnew,
     O                 DONE)
              IF(DONE.EQ.0) THEN
                CALL JTIME_TO_FEQ_DATE(ABS(SJTSEC),
     O                         YR, MN, DY, HOUR)
                WRITE(STDOUT,50) YR, MN, DY, HOUR
                WRITE(*,50) YR, MN, DY, HOUR
              ENDIF

              sopt = 0
              IF(DONE.EQ.0) GOTO 600
C           Current secondary DTSF is transfered
            CALL FREE_UNIT(STDOUT,SECDSN)
            WRITE(STDOUT,52) SECTSF(KNT-1)(1:len_trim(sectsf(knt-1)))
C           Check for more secondary DTSF'S
            GOTO 200
          ELSE
C           No, primary DTSF has not been completely transfered
C           Get first record of the next event


            IF(popt.EQ.0) THEN
              READ(OLDDSN, rec=nrecold) 
     a          SJTOLD, DYFOLD, SYROLD, SMNOLD, SDYOLD, R4
              nrecold = nrecold + 1
              R(1) = R4(1)
              R(2) = R4(2)
              EJTOLD = DUMMY
              popt = 1
            ENDIF

            IF(SJTOLD.EQ.0.D0) THEN
C             End of file on the primary DTSF

              PFLAG = 1
C             Transfer the remaining events in the current secondary DTSF
700           CONTINUE
                CALL MEVENT(STDOUT, sopt, SECDSN, NEWDSN, NDFVAL, 
     i                   SECTYP, 
     M                   SJTSEC, DYFSEC, SYRSEC, SMNSEC, SDYSEC, EJTSEC, 
     M                   R4,
     m                   nrecsec, nrecnew,
     O                   DONE)

                IF(DONE.EQ.0) THEN
                  CALL JTIME_TO_FEQ_DATE(ABS(SJTSEC),
     O                                   YR, MN, DY, HOUR)
                  WRITE(STDOUT,50) YR, MN, DY, HOUR
                  WRITE(*,50) YR, MN, DY, HOUR
                ENDIF
                sopt = 0

                IF(DONE.EQ.0) GOTO 700
C             Current secondary DTSF is transfered
              CALL FREE_UNIT(STDOUT,SECDSN)
              WRITE(STDOUT,52) SECTSF(KNT-1)(1:len_trim(sectsf(knt-1)))
C             Check for more secondary DTSF'S
              GOTO 200
            ELSE
C             No, events still remain in primary DTSF
C             Compare the start times of the current events
              IF(ABS(SJTOLD).GT.ABS(SJTSEC)) THEN
C               Transfer secondary event because it is earlier in time
               

                CALL MEVENT(STDOUT, sopt, SECDSN, NEWDSN, NDFVAL, 
     i                   SECTYP, 
     M                   SJTSEC, DYFSEC, SYRSEC, SMNSEC, SDYSEC, EJTSEC, 
     M                   R4,
     m                   nrecsec, nrecnew,
     O                   DONE)

                 CALL JTIME_TO_FEQ_DATE(ABS(SJTSEC),
     O                                 YR, MN, DY, HOUR)
                WRITE(STDOUT,50) YR, MN, DY, HOUR
                WRITE(*,50) YR, MN, DY, HOUR
                sopt = 0
                GOTO 500
              ELSE
C               Transfer primary event because it is earlier in time

               

                CALL MEVENT(STDOUT, popt, OLDDSN, NEWDSN, NDFVAL, 
     i                   TSFTYP, 
     M                   SJTOLD, DYFOLD, SYROLD, SMNOLD, SDYOLD, EJTOLD, 
     M                   R4,
     m                   nrecold, nrecnew,
     O                   DONE)
                CALL JTIME_TO_FEQ_DATE(ABS(SJTOLD),
     O                                 YR, MN, DY, HOUR)
                WRITE(STDOUT,50) YR, MN, DY, HOUR
                WRITE(*,50) YR, MN, DY, HOUR
                popt = 0
                GOTO 550
              ENDIF
            ENDIF
          ENDIF
        ENDIF      
      
      END
C     ***********
C     *         *
C     * MERGE  *
C     *         *
C     ***********

      SUBROUTINE MERGE(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 

C     Merge one or more secondary DTSF's with a primary DTSF
C     to create a new DTSF.
      implicit none
      INTEGER IFIRST, NVAL, MVAL, TYPE(NVAL), CLEN(NVAL),
     A        TERML(NVAL), TERMCLS(NVAL), IVAL(NVAL), STDOUT,
     B        STDIN,  EFLAG

      REAL RVAL(NVAL)

      DOUBLE PRECISION DPVAL(NVAL)

      CHARACTER CVAL(NVAL)*(*), TERM(NVAL)*1

C     Local

      LOGICAL THERE

      CHARACTER COMMAND*64, LINE*192, LINE2*194, STRINGS(4)*9,
     A          OLDNAME*128, NEWNAME*128,
     B          SECTSF(50)*64

      INTEGER I, ISTART, CL, OPT, OLDDSN, NEWDSN,
     A        NSTRING, ITERM, IT, NSEC, record_len, ifound, ioflag,
     b        n


C     Program units

      INTEGER GET_UNIT

      EXTERNAL GET_UNIT
           
      DATA NSTRING/4/, STRINGS/'PRIMARY','NEW','SECONDARY','END'/
C     *****************************FORMATS******************************
50    FORMAT(/,' *ERR:XXX* No second level command found.')
52    FORMAT(/,' *ERR:XXX* Invalid values given for current command.')
54    FORMAT(1X,A)
56    FORMAT(/,' *ERR:XXX* Old DTSF file name appears twice.')
58    FORMAT(/,' *ERR:XXX* No file name found for Primary DTSF.')
60    FORMAT(/,' *ERR:XXX* File name=',A,/,11X,'not found. Please ',
     A  'check name, path, and drive letter.')
62    FORMAT(/,' *ERR:XXX* New DTSF file name appears twice.')
64    FORMAT(/,' *ERR:XXX* No file name found for New DTSF.')
66    FORMAT(/,' *ERR:XXX* Could not open file name=',/,A,/,11X,
     A      'Please check name, path, and driver letter.')

68    FORMAT(/,' *ERR:XXX* No file name found for a Secondary DTSF.')
70    FORMAT(/,' *ERR:XXX* Second level command invalid.')
72    FORMAT(/,' Processing command: MERGE DTSF')
C***********************************************************************
      OPT = 1
C     Clear the unit numbers so that they can be used to 
C     verify that both the old and the new file have been
C     properly defined. 
      OLDDSN = 0
      NEWDSN = 0

C     Clear the counter for the numer of secondary
C     DTSF's
      NSEC = 0

C     Find the next string in the list.
      ISTART = IFIRST
      CALL FIND_NEXT_CHARACTER_STRING(MVAL, TYPE,
     M                                      ISTART)
      IF(ISTART.EQ.0) THEN
        WRITE(STDOUT,50) 
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      COMMAND = CVAL(ISTART)
      CL = CLEN(ISTART)
      
      IF(COMMAND(1:CL).EQ.'DTSF') THEN
C       Found valid response.  Process subsequent lines.
        WRITE(*,72) 
100     CONTINUE
          CALL inline (STDIN, STDOUT,
     O                LINE)

          WRITE(STDOUT,54) LINE(1:len_trim(line))

          LINE2 = LINE
          call maybe_add_quote(
     m                           line2)
          CALL GETVAL(STDOUT, LINE2, NVAL, OPT,
     O                 TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O                 TERM, TERML, TERMCLS, MVAL)
        
C          CALL DUMP_FINDINGS(STDOUT, MVAL, TYPE, CLEN, 
C     I                         TERM, TERMCLS, CVAL)

          ITERM = 1
          CALL FIND_TERMINATER(MVAL, TERM, '=',
     O                       ITERM)

          ISTART = 1
          IF(ITERM.GT.0) THEN
            IT = ITERM
          ELSE
            IT = MVAL
          ENDIF
          CALL FIND_ANY_STRING_IN_LIST(IT, NSTRING, TYPE, CVAL, CLEN,
     I                                  STRINGS,
     M                                  ISTART,
     O                                  IFOUND)

          IF(IFOUND.EQ.0) THEN
            WRITE(STDOUT,52)
            STOP 'Abnormal stop. Errors found.'
          ENDIF

          IF(STRINGS(IFOUND).EQ.'PRIMARY') THEN
C           Process the old file name.
            IF(OLDDSN.EQ.0) THEN
              OLDDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,56) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              OLDNAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,58) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

            INQUIRE(FILE=OLDNAME, EXIST=THERE)
            IF(THERE) THEN
              OPEN(OLDDSN,FILE=OLDNAME,FORM='UNFORMATTED',STATUS='OLD',
     a            access='direct', recl=4)
              read(olddsn, rec=1) record_len
              close(olddsn)
              OPEN(OLDDSN,FILE=OLDNAME,FORM='UNFORMATTED',STATUS='OLD',
     a            access='direct', recl=record_len)
            ELSE
              WRITE(STDOUT,60) OLDNAME(1:len_trim(oldname))
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'NEW') THEN
C           Process the new file name.
            IF(NEWDSN.EQ.0) THEN
              NEWDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,62)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              NEWNAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,66) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

            OPEN(NEWDSN,FILE=NEWNAME,FORM='UNFORMATTED',
     A               STATUS = 'UNKNOWN', IOSTAT=IOFLAG,
     b            access='direct', recl=record_len)
            IF(IOFLAG.NE.0) THEN
              WRITE(STDOUT,64) NEWNAME(1:len_trim(newname))
              STOP 'Abnormal stop: Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'END') THEN
C           Check if both the requireded files have been given.
            IF(OLDDSN.EQ.0) THEN
              WRITE(STDOUT,58)
              STOP 'Abnormal stop.  Errors found.'
            ELSEIF(NEWDSN.EQ.0) THEN
              WRITE(STDOUT,64)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
            WRITE(STDOUT,72)
            WRITE(STDOUT,*) ' '
  
            CALL MERGE_DTSF(STDOUT, OLDNAME, OLDDSN, NEWDSN, SECTSF,
     i                      record_len,
     M                       NSEC)

            CALL FREE_UNIT(STDOUT, OLDDSN)
            CALL FREE_UNIT(STDOUT, NEWDSN)
            RETURN
          ELSEIF(STRINGS(IFOUND).EQ.'SECONDARY') THEN
C           Get the next secondary DTSF file name.
C           Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              INQUIRE(FILE=CVAL(ITERM+1), EXIST=THERE)
              IF(.NOT.THERE) THEN
               n = clen(iterm+1)
                WRITE(STDOUT,60) cval(iterm+1)(1:n)
                EFLAG = 1
              ELSE              
                NSEC = NSEC + 1
                SECTSF(NSEC) = CVAL(ITERM+1)
              ENDIF
            ELSE
              WRITE(STDOUT,68) 
              EFLAG = 1
            ENDIF            
          ENDIF
          if(eflag.eq.1) then
              STOP 'Abnormal stop.  Errors found.'
          endif             
          GOTO 100            
      ELSE
        WRITE(STDOUT,70)
        CALL FREE_UNIT(STDOUT, OLDDSN)
        CALL FREE_UNIT(STDOUT, NEWDSN)
        EFLAG = 1
      ENDIF

      RETURN
      END
C     ***********
C     *         *
C     * LPYEAR
C     *         *
C     ***********

      INTEGER FUNCTION   LPYEAR
     I                         (YR)
 
C     + + + PURPOSE + + +
C     Compute code for leap year for the Gregorian calender for
C     all possible cases.
      implicit none
C     + + + DUMMY ARGUMENTS + + +
      INTEGER YR
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     YR     - calendar year
 
C     + + + INTRINSICS + + +
      INTRINSIC MOD
C***********************************************************************
      IF(MOD(YR,4).EQ.0) THEN
C       This could be a leap year.
        IF(MOD(YR,100).EQ.0) THEN
C         It is a century year.
          IF(MOD(YR,400).EQ.0) THEN
C           It is a century year divisible by 4 and by 400.  Therefore
C           it is a leap year.
            LPYEAR = 2
          ELSE
C           Not divisible by 400.  Therefore it is not a leap year.
            LPYEAR = 1
          ENDIF
        ELSE
C         Not a century year and divisible by 4-leap year.
          LPYEAR = 2
        ENDIF
      ELSE
C       Not divisible by 4- not a leap year
        LPYEAR = 1
      ENDIF
      RETURN
      END
C     *******************
C     *                 *
C     *  MEVENT         *
C     *                 *
C     *******************

      SUBROUTINE MEVENT(STDOUT, OPT, SOURCE, SINK, NDFVAL, TSFTYP, 
     M                  SJTIME,
     M                  SFRAC, SYR, SMN, SDY, EJTIME,  R4,
     m                  nrecold, nrecnew,                            
     O                  DONE)

C     Move an event from the TSF given by the unit number in SOURCE
C     to the TSF given by the unit number in SINK. 
C     If the unit number for the destination TSF is 0 then the
C     event is read and discarded.
C     If end of file is detected DONE is set and no records are written
      implicit none
      INTEGER OPT, SOURCE, SINK, NDFVAL, TSFTYP, SYR, SMN, SDY, DONE,
     A        STDOUT, nrecold, nrecnew

      REAL R4(NDFVAL)

      DOUBLE PRECISION SJTIME, SFRAC, EJTIME

C     LOCAL

      INTEGER I, J, YR, MN, DY

      REAL R(2)

      DOUBLE PRECISION DUMMY, FRAC, JTIME

      EQUIVALENCE(DUMMY, R(1))
C***********************************************************************
      DONE = 0
      IF(OPT.EQ.0) THEN
C       First record of the source TSF not yet read.  Read it to define
C       the key values.

        READ(SOURCE, rec=nrecold) JTIME, SFRAC, SYR, SMN, SDY, R4
        nrecold = nrecold + 1
        R(1) = R4(1)
        R(2) = R4(2)
        EJTIME = DUMMY

        SJTIME = JTIME

c        write(stdout,*) 'mevent: opt=',opt,' jtime=',jtime,
c     a        ' ejtime=',ejtime

        IF(JTIME.LT.0.D0.AND.EJTIME.LT.1.D0) THEN
          WRITE(STDOUT,*) ' ++ERR++ INVALID END TIME READ FROM',
     A                ' TSF ON UNIT=', SOURCE
          WRITE(STDOUT,*) ' OPT=',OPT,' TSFTYP=',TSFTYP
          STOP 'Abnormal stop.  Errors found.'
        ENDIF 

        IF(JTIME.EQ.0.D0) THEN
          DONE = 1
          RETURN
        ENDIF
      ELSE
C       ESTABLISH FIRST RECORD OF INFORMATION FROM VALUES PASSED AS
C       ARGUMENTS

        JTIME = SJTIME
        DO 110 I=1,NDFVAL
          R4(I) = 0.0
110     CONTINUE
        DUMMY = EJTIME
        R4(1) = R(1)
        R4(2) = R(2)

c        write(stdout,*) 'mevent: opt=',opt,' jtime=',jtime,
c     a        ' ejtime=',ejtime
        IF(EJTIME.LT.1.D0) THEN
          WRITE(STDOUT,*) ' ++ERR++ INVALID END TIME PASSED FROM UNIT=',
     A                SOURCE
          WRITE(STDOUT,*) ' OPT=',OPT,' TSFTYP=',TSFTYP
          STOP 'Abnormal stop.  Errors found.'
        ENDIF

      ENDIF

C     WRITE THE FIRST RECORD TO THE NEW TSF

      IF(SINK.GT.0)  then
        WRITE(SINK, rec=nrecnew) JTIME, SFRAC, SYR, SMN, SDY, R4
        nrecnew = nrecnew + 1
      endif

C      WRITE(STDOUT,*) ' IN MEVENT. EJTIME=',EJTIME
        
300   CONTINUE
C       TRANSFER THE REMAINING RECORDS IN THE EVENT

        READ(SOURCE,rec=nrecold) JTIME, FRAC, YR, MN, DY,  R4
        nrecold = nrecold + 1

C        WRITE(STDOUT,*) ' IN MEVENT. JTIME=',JTIME

        IF(SINK.GT.0) then
           WRITE(SINK, rec=nrecnew) JTIME, FRAC, YR, MN, DY, R4
           nrecnew = nrecnew + 1
        endif

      
c        write(stdout,*) ' In mevent: abs(jtime-ejtime)=',
c     a                       abs(jtime-ejtime)
c        write(stdout,*) ' jtime=',jtime,' ejtime=',ejtime

        IF(ABS(JTIME - EJTIME).GT.1.D-7) GOTO 300

C      SJTIME = JTIME

      RETURN
      END
C     ***********
C     *         *
C     * DELETE_EVENTS
C     *         *
C     ***********

      SUBROUTINE DELETE_EVENTS(STDOUT, OLDDSN, NEWDSN, OLDNAME,
     I                         TIME_KNT, JTIME_LIST,
     O                         EFLAG)

C     Create a new DTSF by transfering evetns from the old
C     DTSF but deleting any that contain the list of 
C     event delete Jtimes in JTIME_LIST.  The dummy event
C     CAN be deleted. 
      implicit none
      INTEGER STDOUT, OLDDSN, NEWDSN, TIME_KNT, EFLAG

      DOUBLE PRECISION JTIME_LIST(100)

      CHARACTER*(*) OLDNAME

C     Local
      
      INTEGER NDFVAL, TSFTYP, I, SYR, SMN, SDY,
     A        FIRST_RECORD_READ, YR, MN, DY,
     B        DONE, J, last_header_rec, nrecold,
     c        nrecnew

      REAL R(2), HOUR, R4(:)

      DOUBLE PRECISION DUMMY, SFRAC, JTIME, DELETE_JTIME,
     A                 SJTIME, EJTIME, FRAC
      ALLOCATABLE :: R4

C     Called program units.

      INTRINSIC ABS

      EXTERNAL JTIME_TO_FEQ_DATE, TSF_INIT, MEVENT
      
      EQUIVALENCE(DUMMY, R(1))

C     ********************************FORMATS***************************
50    FORMAT(/,' *WRN:XXX* Delete time=',I5,'/',I2,'/',I2,':',F6.3,
     A  ' has no matching event.')
52    FORMAT(' Event with starting time=',I5,'/',I2,'/',I2,':',F6.3,
     A      ' has been deleted.')
54    FORMAT(/,' *WRN:XXX* DTSF exhausted.  Delete times at and ',
     A   ' following',/,11X,' time=',
     B   I4,'/',I2,'/',I2,':',F8.3,' were not done.')
56    FORMAT(' Event with starting time=',I5,'/',I2,'/',I2,':',F6.3,
     A      ' has been transfered.')
60    FORMAT(/,' Selected events deleted.  New DTSF is complete.')
C***********************************************************************

C     Suprees checking of the number of diffuse values
      NDFVAL = 0
      CALL TSF_INIT(STDOUT, OLDNAME, OLDDSN, NEWDSN, 
     M                    NDFVAL, 
     O                    TSFTYP, last_header_rec)

C     Allow for conversion to new format DTSF.  New format is created
C     in all cases. 

      ALLOCATE ( R4(NDFVAL) )

      nrecold = last_header_rec + 1
      nrecnew = last_header_rec + 1

C     Clear the first record read flag.  Needed to handle certain
C     user errors.
      FIRST_RECORD_READ = 0

      WRITE(STDOUT,*) ' '
      DO 500 I=1,TIME_KNT

        DELETE_JTIME = JTIME_LIST(I)


200     CONTINUE
          IF(FIRST_RECORD_READ.EQ.0) THEN                               
C           Read the next record in the old DTSF.  It will be either the
C           first record of an event or it will be the last record of
C           the DTSF.
            READ(OLDDSN, rec=nrecold) SJTIME, SFRAC, SYR, SMN, SDY, R4 
            nrecold = nrecold + 1 
            R(1) = R4(1)                                                
            R(2) = R4(2)                                                
            EJTIME = DUMMY                                              
            FIRST_RECORD_READ = 1                                       
          ENDIF                                                         
                                                                        
C         Note: SJTIME < 0 to signal the first record of an event.      
                                                                        
          IF(SJTIME.EQ.0.D0) THEN                                       
C           This is the end of the DTSF.  Write last record to the      
C           new DTSF.                                                   
C             ALL EVENTS HAVE BEEN TRANSFERED TO THE NEW TSF.           
              JTIME = 0.D0                                              
              FRAC = 0.D0                                               
              SYR = 0                                                   
              SMN = 0                                                   
              SDY = 0                                                   
              DO 110 J=1,NDFVAL                                         
                R4(J) = 0.0                                             
110           CONTINUE                                                  
              WRITE(NEWDSN, rec=nrecnew) JTIME, FRAC, SYR, SMN, SDY, R4 
              nrecnew = nrecnew + 1


              CALL JTIME_TO_FEQ_DATE(ABS(DELETE_JTIME),
     O                             YR, MN, DY, HOUR)
              WRITE(STDOUT,54) YR, MN, DY, HOUR                         
              RETURN
              
          ELSE                                                          
C           We have the start and end time of an event in hand.  Check to see  
C           if we will transfer this event or discard this event.              
            IF(DELETE_JTIME.LT.ABS(SJTIME)) THEN                        
C             The delete Jtime does not define an event in the old DTSF        
                                                                       
              CALL JTIME_TO_FEQ_DATE(ABS(DELETE_JTIME),
     O                             YR, MN, DY, HOUR)
              WRITE(STDOUT,50) YR, MN, DY, HOUR                         
              GOTO 500                                                  
            ELSEIF(DELETE_JTIME.GE.ABS(SJTIME).AND.                     
     A             DELETE_JTIME.LE.EJTIME) THEN                         
C             The current event should be discarded because it contains 
C             the delete Jtime.                                         
              JTIME = ABS(SJTIME)                                       
              CALL JTIME_TO_FEQ_DATE(ABS(JTIME),
     O                             YR, MN, DY, HOUR)
              WRITE(STDOUT,52) YR, MN, DY, HOUR                         
              WRITE(*,52) YR, MN, DY, HOUR                              
              
                                                                        
C             Move the event into the bit bucket!                       
              CALL MEVENT(STDOUT, FIRST_RECORD_READ, OLDDSN, 0, NDFVAL,
     I                    TSFTYP, 
     M                    SJTIME, SFRAC, SYR, SMN, SDY, EJTIME, R4,
     m                    nrecold, nrecnew,                                        
     O                    DONE)                                         
C             Clear the first-record-read flag because the first        
C             record is no-longer valid.                                
              FIRST_RECORD_READ = 0                                     
              GOTO 500                                                  
            ELSE                                                        
C             The delete Jtime is at a point beyond the current event.  
C             Transfer the current event to the new DTSF.               
              CALL MEVENT(STDOUT, FIRST_RECORD_READ, OLDDSN, NEWDSN,
     I                    NDFVAL, 
     I                    TSFTYP, 
     M                    SJTIME, SFRAC, SYR, SMN, SDY, EJTIME, R4,
     m                    nrecold, nrecnew,
     O                    DONE)
              FIRST_RECORD_READ = 0
 
              JTIME = ABS(SJTIME)                                              
              CALL JTIME_TO_FEQ_DATE(ABS(JTIME),
     O                             YR, MN, DY, HOUR)
              WRITE(STDOUT,56) YR, MN, DY, HOUR                                
              WRITE(*,56) YR, MN, DY, HOUR                                
                                                                                            
C             Got back and get the next event to catch up to the
C             current delete Jtime.

              GOTO 200                                                         
            ENDIF                                                              
          ENDIF                                                                
500   CONTINUE

C     We arrive here with at least one record left in the old DTSF.
C     If the delete times are exhausted on or before the last 
C     event in the old DTSF we may have some events left to transfer.

600   CONTINUE
        CALL MEVENT(STDOUT, FIRST_RECORD_READ, OLDDSN, NEWDSN, NDFVAL, 
     I              TSFTYP, 
     M              SJTIME, SFRAC, SYR, SMN, SDY, EJTIME, R4,
     m              nrecold, nrecnew,                                        
     O              DONE)
        FIRST_RECORD_READ = 0
        IF(DONE.EQ.0) THEN
          JTIME = ABS(SJTIME)                                              
           CALL JTIME_TO_FEQ_DATE(ABS(JTIME),
     O                            YR, MN, DY, HOUR)
          WRITE(STDOUT,56) YR, MN, DY, HOUR                                
          WRITE(*,56) YR, MN, DY, HOUR                                
        ENDIF

        IF(DONE.EQ.0) GOTO 600

C     Write the last record in the new DTSF
      JTIME = 0.D0                                                     
      FRAC = 0.D0                                                      
      SYR = 0                                                          
      SMN = 0                                                          
      SDY = 0                                                          
      DO 610 I=1,NDFVAL                                                
        R4(I) = 0.0                                                    
610   CONTINUE                                                         
      WRITE(NEWDSN, rec=nrecnew) JTIME, FRAC, SYR, SMN, SDY, R4                     

 
      WRITE(STDOUT,60)   
      DEALLOCATE ( R4 )
  
      RETURN

      END
C     *****************
C     *               *
C     * DBLE_SORT_ASCENDING        *
C     *               *
C     *****************

      SUBROUTINE DBLE_SORT_ASCENDING(N, 
     M                               DVAL)

c     Sort DVAL in ascending order  
      implicit none
      INTEGER N

      DOUBLE PRECISION DVAL(N)

C     LOCAL

      INTEGER I, J

      DOUBLE PRECISION T
C***********************************************************************
C     Use insertion sort from Programming Pearls
C     COMM. OF ACM April 1984

      DO 200 I=2,N
        J = I
        T = DVAL(J)
100     CONTINUE
          IF(J.GT.1.AND.DVAL(J-1).GT.T) THEN
            DVAL(J) = DVAL(J-1)
            J = J-1
            
            GOTO 100
          ENDIF
        DVAL(J) = T
200   CONTINUE
      RETURN
      END
C     ***********
C     *         *
C     * SET_DEFAULT_TIME
C     *         *
C     ***********

      SUBROUTINE SET_DEFAULT_TIME(KIND, 
     O                            DEFAULT_MONTH, DEFAULT_DAY,
     O                            DEFAULT_HOUR)
C     Set the default values for time.  Depends on the kind of time.
C     Starting times will default to the start of the interval and
C     ending times will default to the end of the interval. 
      implicit none
      INTEGER DEFAULT_MONTH, DEFAULT_DAY

      REAL DEFAULT_HOUR

      CHARACTER KIND*5
C***********************************************************************
      IF(KIND.EQ.'START') THEN
        DEFAULT_MONTH = 1
        DEFAULT_DAY = 1
        DEFAULT_HOUR = 0.0
      ELSE
        DEFAULT_MONTH = 12
        DEFAULT_DAY = 31
        DEFAULT_HOUR = 24.0
      ENDIF
      RETURN
      END
C     ***********
C     *         *
C     * CHKMJD  *
C     *         *
C     ***********

      SUBROUTINE   CHKMJD
     I                   (STDOUT, YEAR, MONTH,
     O                    EFLAG)
 
C     + + + PURPOSE + + +
C     Check YEAR and MONTH to make sure that the modified
C     julian date  and its inverse will be computed properly.
 
      implicit none
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, MONTH, STDOUT, YEAR
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT - standard output unit for user messages
C     YEAR   - calendar year
C     MONTH  - number of the month
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *ERR:130* Month=',I5,' in date < 1 or > 12.')
 52   FORMAT(/,' *ERR:137* Year=',I5,' too early for modified julian',
     A     ' date computation.'/,10X,' Must be 1859 or later.')
C***********************************************************************
C     YEAR MUST BE THE FULL YEAR DESIGNATION NOT JUST THE LAST TWO DIGITS.
C     On March 10, 1992 changed to be valid for any date on or following
C     January 1, 1859.
C
      IF(MONTH.LT.1.OR.MONTH.GT.12) THEN
        WRITE(STDOUT,50) MONTH
        EFLAG = 1
      ENDIF
 
      IF(YEAR.LT.1859) THEN
        WRITE(STDOUT,52) YEAR
        EFLAG = 1
      ENDIF
 
      RETURN
      END
C     ***********
C     *         *
C     * CHKDAT  *
C     *         *
C     ***********

      SUBROUTINE   CHKDAT
     I                   (STDOUT, YR,
     M                    MN, DY,
     O                    EFLAG)
 
C     + + + PURPOSE + + +
C     Check a Gregorian calender date for validity.
 
      implicit none
C     + + + DUMMY ARGUMENTS + + +
      INTEGER DY, EFLAG, MN, STDOUT, YR
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT - standard output unit for user messages
C     YR     - calendar year
C     MN     - number of month(1-12)
C     DY     - day in the month
C     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors
 
C     + + + SAVED VALUES + + +
      INTEGER DPM(12,2)
      SAVE DPM
 
C     + + + LOCAL VARIABLES + + +
      INTEGER LEAP
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER LPYEAR
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LPYEAR
 
C     + + + DATA INITIALIZATIONS + + +
      DATA DPM/31,28,31,30,31,30,31,31,30,31,30,31,
     1         31,29,31,30,31,30,31,31,30,31,30,31/
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *ERR:243* Month=',I3,' is invalid.')
 52   FORMAT(/,' *ERR:244* Day=',I3,' is invalid for month=',I3)
C***********************************************************************
      LEAP = LPYEAR (YR)
      IF(MN.GT.12.OR.MN.LT.1) THEN
        WRITE(STDOUT,50) MN
        MN = 1
        EFLAG = 1
      ENDIF
      IF(DY.LT.1.OR.DY.GT.DPM(MN,LEAP)) THEN
        WRITE(STDOUT,52) DY, MN
        DY = DPM(MN,LEAP)
        EFLAG = 1
      ENDIF
      RETURN
      END
C     ***********
C     *         *
C     * CHK_TIME
C     *         *
C     ***********

      SUBROUTINE CHK_TIME(STDOUT, YEAR, MONTH, DAY, HOUR, EFLAG)

C     Check a time for FEQ/FEQUTL so that MJD will work and the
C     date and hour part are valid. 

      implicit none
      INTEGER YEAR, MONTH, DAY, EFLAG, STDOUT

      REAL HOUR

      EXTERNAL CHKMJD, CHKDAT
C     ************************FORMATS***********************************
50    FORMAT(/,' *ERR:XXX* Hour=',F10.3,' < 0.0 or > 24.0')
C***********************************************************************
      CALL CHKDAT(STDOUT, YEAR,
     M                    MONTH, DAY,
     O                    EFLAG)

      CALL CHKMJD (STDOUT, YEAR, MONTH,
     O                    EFLAG)

      IF(HOUR.LT.0.0.OR.HOUR.GT.24.0) THEN
        WRITE(STDOUT,50) HOUR
        EFLAG = 1
      ENDIF
      RETURN
      END
C     ***********
C     *         *
C     * DUMP_FINDINGS
C     *         *
C     ***********

      SUBROUTINE DUMP_FINDINGS(STDOUT, MVAL, TYPE, CLEN, 
     I                         TERM, TERMCLS, CVAL)

      implicit none
      INTEGER MVAL, TYPE(MVAL), CLEN(MVAL), TERMCLS(MVAL),
     A        STDOUT

      CHARACTER TERM(MVAL)*1, CVAL(MVAL)*(*)


C     Dump the results of parsing the line into its parts 
C     for debugging. 

C     Local

      INTEGER I      
C     **************************FORMATS*********************************
51    FORMAT(' Index Type Size  Term Class String value of the item')
52    FORMAT(I6,I5,I5,5X,A1,I6,1X,A64)
C***********************************************************************
      WRITE(STDOUT,51)
      DO 200 I=1,MVAL
        WRITE(STDOUT,52) I, TYPE(I), CLEN(I), TERM(I), TERMCLS(I),
     A                   CVAL(I)
200   CONTINUE
      WRITE(STDOUT,*) ' '

      RETURN
      END
C     ***********
C     *         *
C     * GET_NEXT_TIME
C     *         *
C     ***********

      SUBROUTINE GET_NEXT_TIME(STDOUT, KIND, IFIRST, MVAL, 
     M                 TYPE, CVAL, TERM, 
     O                 JTIME, EFLAG) 

C     Get the next time value 

      implicit none
      INTEGER IFIRST, MVAL, TYPE(MVAL), STDOUT,
     B        EFLAG


      DOUBLE PRECISION JTIME

      CHARACTER CVAL(MVAL)*(*), TERM(MVAL)*1, KIND*5

C     Local

      INTEGER  CHRVAL, INTVAL, REAVAL, DPRVAL
      PARAMETER(INTVAL=1, REAVAL=2, DPRVAL=3, CHRVAL=4)

      INTEGER DEFAULT_MONTH, DEFAULT_DAY, 
     A         YEAR, MONTH, DAY, I

      REAL DEFAULT_HOUR, HOUR


      INTEGER MJD

      EXTERNAL MJD, CHK_TIME

C     ****************************FORMATS*******************************
50    FORMAT(/,' *ERR:XXX* Year is missing/invalid in a time value.')
52    FORMAT(/,' *ERR:XXX* Month is missing/invalid in a time value.')
54    FORMAT(/,' *ERR:XXX* Day is missing/invalid in a time value.')
56    FORMAT(/,' *ERR:XXX* Hour is missing/invalidin a time value.')
C***********************************************************************
      CALL SET_DEFAULT_TIME(KIND, 
     O                      DEFAULT_MONTH, DEFAULT_DAY,
     O                      DEFAULT_HOUR)

C     The time values should begin with the year at IFIRST, the
C     first item after the equal sign in the time specification.
c     Default values can be given for the month, day, and hour.
C     They can also be omitted so that all we may find is
C     the year.  MVAL gives the number of items found, including
C     the end of line quote mark item.  

C     Set the time values to signal no data.
      YEAR = -1
      MONTH = -1
      DAY = -1
      HOUR = -1.0

C     Try to convert the items to internal numeric form.
      I = IFIRST
      IF(I.LE.MVAL-1) THEN
C       There is a value and it should be the year.
        IF(TYPE(I).EQ.INTVAL) THEN
          READ(CVAL(I)(1:10),'(BN,I10)') YEAR
        ELSE
          WRITE(STDOUT,50)         
          EFLAG =1
          RETURN
        ENDIF
      ELSE
        WRITE(STDOUT,50)         
        EFLAG =1
        RETURN
      ENDIF

      I = I + 1
      IF(I.LE.MVAL-1) THEN
C       There is a value and it could be the month
        IF(TYPE(I).EQ.INTVAL) THEN
C         It is the month.
          READ(CVAL(I)(1:10),'(BN,I10)') MONTH
        ELSEIF(TYPE(I).EQ.REAVAL) THEN
C         This is the hour.  Take default value for the
C         month and day.
          MONTH = DEFAULT_MONTH
          DAY = DEFAULT_DAY
          READ(CVAL(I)(1:10),'(BN,F10.0)') HOUR
        ELSEIF(TYPE(I).EQ.CHRVAL) THEN
          IF(CVAL(I)(1:1).EQ.'*') THEN
C             Take default value of month.
            MONTH = DEFAULT_MONTH
          ELSE
            WRITE(STDOUT,52) 
            EFLAG = 1
            RETURN
          ENDIF
        ELSE
          WRITE(STDOUT,52) 
          EFLAG = 1
          RETURN
        ENDIF
      ELSE
C       No more values. Take defaults for month, day, and hour
        MONTH = DEFAULT_MONTH
        DAY = DEFAULT_DAY
        HOUR = DEFAULT_HOUR
      ENDIF

      I = I + 1
      IF(I.LE.MVAL-1) THEN
C       There is a value and it could be the day
        IF(TYPE(I).EQ.INTVAL) THEN
C         It is the day.
          READ(CVAL(I)(1:10),'(BN,I10)') DAY
        ELSEIF(TYPE(I).EQ.REAVAL) THEN
C         This is the hour.  Take default value for the day.
          DAY = DEFAULT_DAY
          READ(CVAL(I)(1:10),'(BN,F10.0)') HOUR
        ELSEIF(TYPE(I).EQ.CHRVAL) THEN
          IF(CVAL(I)(1:1).EQ.'*') THEN
C           Take default value of day.
            DAY = DEFAULT_DAY
          ELSE
            WRITE(STDOUT,54) 
            EFLAG = 1
            RETURN
          ENDIF
        ELSE
          WRITE(STDOUT,54) 
          EFLAG = 1
          RETURN
        ENDIF
      ELSE
C       No more values. Take defaults for day, and hour
          DAY = DEFAULT_DAY
        HOUR = DEFAULT_HOUR
      ENDIF

      I = I + 1
      IF(I.LE.MVAL-1) THEN
C       There is a value and it should be the hour.
                  
        IF(TYPE(I).EQ.REAVAL) THEN
C         This is the hour.
          READ(CVAL(I)(1:10),'(BN,F10.0)') HOUR
        ELSEIF(TYPE(I).EQ.CHRVAL) THEN
          IF(CVAL(I)(1:1).EQ.'*') THEN
C           Take default value of hour.
            HOUR = DEFAULT_HOUR
          ELSE
            WRITE(STDOUT,56) 
            EFLAG = 1
            RETURN
          ENDIF
        ELSE
          WRITE(STDOUT,56) 
          EFLAG = 1
          RETURN
        ENDIF
      ELSE
C       No more values.  Take default for the hour.
        HOUR = DEFAULT_HOUR
      ENDIF          

C     Check for missing values. 
      IF(YEAR.LT.0) THEN
        WRITE(STDOUT,50)
        EFLAG = 1
      ENDIF
      IF(MONTH.LT.0) THEN
        WRITE(STDOUT,52)
        EFLAG = 1
      ENDIF
      IF(DAY.LT.0) THEN
        WRITE(STDOUT,54)
        EFLAG = 1
      ENDIF
      IF(HOUR.LT.0) THEN
        WRITE(STDOUT,56)
        EFLAG = 1
      ENDIF

C     Check for validity of the time. 
      CALL CHK_TIME(STDOUT, YEAR, MONTH, DAY, HOUR, EFLAG)
      IF(EFLAG.NE.0) RETURN

      JTIME = DBLE(  MJD (YEAR, MONTH, DAY)) + DBLE(HOUR)/24.D0
      RETURN
      END
      
C     ***********
C     *         *
C     * DELETE  *
C     *         *
C     ***********

      SUBROUTINE DELETE(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 

C     Delete one or more events from a DTSF.  A new DTSF is created
C     in the process.  Any old format DTSF'S are converted to 
C     the new form.

      implicit none
      INTEGER IFIRST, NVAL, MVAL, TYPE(NVAL), CLEN(NVAL),
     A        TERML(NVAL), TERMCLS(NVAL), IVAL(NVAL), STDOUT,
     B        STDIN,  EFLAG

      REAL RVAL(NVAL)

      DOUBLE PRECISION DPVAL(NVAL)

      CHARACTER CVAL(NVAL)*(*), TERM(NVAL)*1

C     Local

      LOGICAL THERE

      CHARACTER COMMAND*64, LINE*192, LINE2*194, STRINGS(4)*4,
     A          OLDNAME*128, NEWNAME*128, KIND*5

      INTEGER I, ISTART, CL, OPT, OLDDSN, NEWDSN,
     A        NSTRING, ITERM, IT, 
     B        TIME_KNT, record_len, ifound, ioflag

      DOUBLE PRECISION JTIME, JTIME_LIST(500)

C     Program units

      INTEGER GET_UNIT

      EXTERNAL GET_UNIT
           
      DATA NSTRING/4/, STRINGS/'TIME','NEW','OLD','END'/
C     *****************************FORMATS******************************
50    FORMAT(/,' *ERR:XXX* No second level command found.')
52    FORMAT(/,' *ERR:XXX* Invalid values given for current command.')
54    FORMAT(1X,A)
56    FORMAT(/,' *ERR:XXX* Old DTSF file name appears twice.')
58    FORMAT(/,' *ERR:XXX* No file name found for Old DTSF.')
60    FORMAT(/,' *ERR:XXX* File name=',A,/,11X,'not found. Please ',
     A  'check name, path, and drive letter.')
62    FORMAT(/,' *ERR:XXX* New DTSF file name appears twice.')
64    FORMAT(/,' *ERR:XXX* No file name found for New DTSF.')
66    FORMAT(/,' *ERR:XXX* Could not open file name=',/,A,/,11X,
     A      'Please check name, path, and driver letter.')
68    FORMAT(/,' *ERR:XXX* No delete times given.')
70    FORMAT(/,' *ERR:XXX* Second level command invalid.')
72    FORMAT(/,' Processing command: DELETE EVENTS')
C***********************************************************************
      OPT = 1
C     Clear the unit numbers so that they can be used to 
C     verify that both the old and the new file have been
C     properly defined. 
      OLDDSN = 0
      NEWDSN = 0

C     Clear the counter for the numer of TIME values
C     designating events to be deleted.
      TIME_KNT = 0

C     Find the next string in the list.
      ISTART = IFIRST
      CALL FIND_NEXT_CHARACTER_STRING(MVAL, TYPE,
     M                                      ISTART)
      IF(ISTART.EQ.0) THEN
        WRITE(STDOUT,50) 
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      COMMAND = CVAL(ISTART)
      CL = CLEN(ISTART)
      
      IF(COMMAND(1:CL).EQ.'EVENTS') THEN
C       Found valid response.  Process subsequent lines.
        WRITE(*,72) 
100     CONTINUE
          CALL inline (STDIN, STDOUT,
     O                LINE)

          WRITE(STDOUT,54) LINE(1:len_trim(line))

          LINE2 = LINE
          call maybe_add_quote(
     m                           line2)
          CALL GETVAL(STDOUT, LINE2, NVAL, OPT,
     O                 TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O                 TERM, TERML, TERMCLS, MVAL)
        
C          CALL DUMP_FINDINGS(STDOUT, MVAL, TYPE, CLEN, 
C     I                         TERM, TERMCLS, CVAL)

          ITERM = 1
          CALL FIND_TERMINATER(MVAL, TERM, '=',
     O                       ITERM)

          ISTART = 1
          IF(ITERM.GT.0) THEN
            IT = ITERM
          ELSE
            IT = MVAL
          ENDIF
          CALL FIND_ANY_STRING_IN_LIST(IT, NSTRING, TYPE, CVAL, CLEN,
     I                                  STRINGS,
     M                                  ISTART,
     O                                  IFOUND)

          IF(IFOUND.EQ.0) THEN
            WRITE(STDOUT,52)
            STOP 'Abnormal stop. Errors found.'
          ENDIF

          IF(STRINGS(IFOUND).EQ.'OLD') THEN
C           Process the old file name.
            IF(OLDDSN.EQ.0) THEN
              OLDDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,56) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              OLDNAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,58) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

            INQUIRE(FILE=OLDNAME, EXIST=THERE)
            IF(THERE) THEN
              OPEN(OLDDSN,FILE=OLDNAME,FORM='UNFORMATTED',STATUS='OLD',
     a          access='direct', recl=4)
              read(olddsn,rec=1) record_len
              close(olddsn)
              OPEN(OLDDSN,FILE=OLDNAME,FORM='UNFORMATTED',STATUS='OLD',
     a          access='direct', recl=record_len)
            ELSE
              WRITE(STDOUT,60) OLDNAME
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'NEW') THEN
C           Process the new file name.
            IF(NEWDSN.EQ.0) THEN
              NEWDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,62)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              NEWNAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,66) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

            OPEN(NEWDSN,FILE=NEWNAME,FORM='UNFORMATTED',
     A               STATUS = 'UNKNOWN', IOSTAT=IOFLAG,
     b               access='direct', recl=record_len)
            IF(IOFLAG.NE.0) THEN
              WRITE(STDOUT,64) NEWNAME
              STOP 'Abnormal stop: Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'END') THEN
C           Check if both the required files have been given.
            IF(OLDDSN.EQ.0) THEN
              WRITE(STDOUT,58)
              STOP 'Abnormal stop.  Errors found.'
            ELSEIF(NEWDSN.EQ.0) THEN
              WRITE(STDOUT,64)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
C           Sort the delete Jtimes into ascending order.
C           They will normally be given in ascending order but 
C           make sure they are. 
            IF(TIME_KNT.EQ.0) THEN
              WRITE(STDOUT,68)
              CALL FREE_UNIT(STDOUT, OLDDSN)
              CALL FREE_UNIT(STDOUT, NEWDSN)
              EFLAG = 1
              RETURN
            ENDIF
            WRITE(STDOUT,72)
            WRITE(STDOUT,*) ' '

            EFLAG = 0
            CALL  DBLE_SORT_ASCENDING(TIME_KNT,
     M                                 JTIME_LIST)

            CALL DELETE_EVENTS(STDOUT, OLDDSN, NEWDSN, OLDNAME,
     I                         TIME_KNT, JTIME_LIST,
     O                         EFLAG)
            CALL FREE_UNIT (STDOUT, OLDDSN)
            CALL FREE_UNIT (STDOUT, NEWDSN)
            RETURN
          ELSEIF(STRINGS(IFOUND).EQ.'TIME') THEN
C           Get the next time value, check for validity and put
C           it on the list.  The list will be sorted later
C           to make sure that it is in ascending order. 
 
            KIND = 'START'
            CALL GET_NEXT_TIME(STDOUT, KIND, ITERM+1, MVAL, 
     M                 TYPE, CVAL, TERM, 
     O                 JTIME, EFLAG) 
            IF(EFLAG.EQ.0) THEN
              TIME_KNT = TIME_KNT + 1
              JTIME_LIST(TIME_KNT) = JTIME
            ENDIF
          ENDIF
          GOTO 100            
      ELSE
        WRITE(STDOUT,70)
        CALL FREE_UNIT(STDOUT, OLDDSN)
        CALL FREE_UNIT(STDOUT, NEWDSN)
        EFLAG = 1
      ENDIF

      RETURN
      END
C     ***********
C     *         *
C     * INVMJD
C     *         *
C     ***********

      SUBROUTINE   INVMJD
     I                   (MJD,
     O                    YR, MN, DY)
 
C     + + + PURPOSE + + +
C     Invert the modified julian date as computed by function MJD
 
      implicit none
C     + + + DUMMY ARGUMENTS + + +
      INTEGER DY, MJD, MN, YR
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     MJD    - value of modified julian data number to invert
C     YR     - calendar year
C     MN     - number of month(1-12)
C     DY     - day in the month
 
C     Developed from information given in: "Astronomical Formulae
C     for Calculators', Jean Meeus, published by Willmann-Bell.
 
C     + + + LOCAL VARIABLES + + +
      INTEGER A, ALPHA, B, C, D, E, Z
 
C     + + + INTRINSICS + + +
      INTRINSIC DBLE, INT
C***********************************************************************
C     CONVERT TO JULIAN TIME PLUS THE .5 DAY CORRECTION. YIELDS AN
C     INTEGER
 
      Z = MJD + 679006 + 1720994 + 1
 
      IF(Z.LT.2299161) THEN
        A = Z
      ELSE
        ALPHA = INT((DBLE(Z) - 1867216.24D0)/36524.25D0)
        A = Z + 1 + ALPHA - ALPHA/4
      ENDIF
 
      B = A + 1524
      C = INT((DBLE(B) - 122.1D0)/365.25D0)
      D = INT(365.25D0*DBLE(C))
      E = INT(DBLE(B-D)/30.6001D0)
 
      DY = B - D - INT(30.6001D0*DBLE(E))
      IF(E.LE.13) THEN
        MN = E - 1
      ELSE
        MN = E - 13
      ENDIF
      IF(MN.GE.3) THEN
        YR = C - 4716
      ELSE
        YR = C - 4715
      ENDIF
 
      RETURN
      END
C     ***********
C     *         *
C     * MJD
C     *         *
C     ***********

      INTEGER FUNCTION   MJD
     I                      (YR, MN, DY)
 
C     + + + PURPOSE + + +
C     Compute modified julian date for any date with a year greater
C     than 1582.  We take the resulting date to represent the
C     elapsed time from some point in the past to the first instant
C     of the given day.
C     The date must be later than Nov. 17, 1858 for MJD to be
C     a positive number.  Thus for use in FEQ the year must be
C     1859 or greater.
 
C     This routine and INVMJD have been checked for every day
C     from 1860 through the year 25000.
 
C     Developed from information given in: "Astronomical Formulae
C     for Calculators', Jean Meeus, published by Willmann-Bell.

      implicit none
C     + + + DUMMY ARGUMENTS + + +
      INTEGER DY, MN, YR
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     YR     - calendar year
C     MN     - number of month(1-12)
C     DY     - day in the month
 
C     + + + LOCAL VARIABLES + + +
      INTEGER A, B, M, Y
 
C     + + + INTRINSICS + + +
      INTRINSIC INT
C***********************************************************************
      IF(MN.GT.2) THEN
        Y = YR
        M = MN
      ELSE
        Y = YR - 1
        M = MN + 12
      ENDIF
 
      A = Y/100
      B = 2 - A + A/4
 
      MJD = (36525*Y)/100 + INT(30.6001*(M+1)) + DY + B - 679006
      RETURN
      END
C     ***********
C     *         *
C     * GET  *
C     *         *
C     ***********

      SUBROUTINE GET(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 

C     Implement the GET operation.
C     For now it has only the GET dates implemented.

      implicit none
      INTEGER IFIRST, NVAL, MVAL, TYPE(NVAL), CLEN(NVAL),
     A        TERML(NVAL), TERMCLS(NVAL), IVAL(NVAL), STDOUT,
     B        STDIN,  EFLAG

      REAL RVAL(NVAL)

      DOUBLE PRECISION DPVAL(NVAL)

      CHARACTER CVAL(NVAL)*(*), TERM(NVAL)*1

C     Local

      LOGICAL THERE

      CHARACTER COMMAND*64, LINE*192, LINE2*194, STRINGS(3)*7,
     A          OLDNAME*128

      INTEGER I, ISTART, CL, OPT, TSFDSN, 
     A        NSTRING, ITERM, IT, ifound, record_len

C     Program units

      INTEGER GET_UNIT

      EXTERNAL GET_UNIT
           
      DATA NSTRING/3/, STRINGS/'FILE','OPTIONS','END'/
C     *****************************FORMATS******************************
50    FORMAT(/,' *ERR:XXX* No second level command found.')
52    FORMAT(/,' *ERR:XXX* Invalid values given for current command.')
54    FORMAT(1X,A)
56    FORMAT(/,' *ERR:XXX* File name appears twice.')
58    FORMAT(/,' *ERR:XXX* No file name found for DTSF.')
60    FORMAT(/,' *ERR:XXX* File name=',A,/,11X,'not found. Please ',
     A  'check name, path, and drive letter.')
62    FORMAT(/,' OPTIONS list not yet supported.')
70    FORMAT(/,' *ERR:XXX* Second level command invalid.')
72    FORMAT(/,' Processing command: GET DATES')
C***********************************************************************
      OPT = 1
C     Clear the unit number so that it can be used to 
C     verify that both the old and the new file have been
C     properly defined. 
      TSFDSN = 0

C     Find the next string in the list.
      ISTART = IFIRST
      CALL FIND_NEXT_CHARACTER_STRING(MVAL, TYPE,
     M                                      ISTART)
      IF(ISTART.EQ.0) THEN
        WRITE(STDOUT,50) 
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      COMMAND = CVAL(ISTART)
      CL = CLEN(ISTART)

      IF(COMMAND(1:CL).EQ.'DATES') THEN
        WRITE(*,72)

C       Found valid response.  Process subsequent lines.

100     CONTINUE
          CALL inline (STDIN, STDOUT,
     O                LINE)

          WRITE(STDOUT,54) LINE(1:len_trim(line))

          LINE2 = LINE
          call maybe_add_quote(
     m                           line2)
          CALL GETVAL(STDOUT, LINE2, NVAL, OPT,
     O                 TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O                 TERM, TERML, TERMCLS, MVAL)
        
          ITERM = 1
          CALL FIND_TERMINATER(MVAL, TERM, '=',
     O                       ITERM)

          ISTART = 1
          IF(ITERM.GT.0) THEN
            IT = ITERM
          ELSE
            IT = MVAL
          ENDIF
          CALL FIND_ANY_STRING_IN_LIST(IT, NSTRING, TYPE, CVAL, CLEN,
     I                                  STRINGS,
     M                                  ISTART,
     O                                  IFOUND)

          IF(IFOUND.EQ.0) THEN
            WRITE(STDOUT,52)
            STOP 'Abnormal stop. Errors found.'
          ENDIF

          IF(STRINGS(IFOUND).EQ.'FILE') THEN
C           Process the file name.
            IF(TSFDSN.EQ.0) THEN
              TSFDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,56) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              OLDNAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,58) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

            INQUIRE(FILE=OLDNAME, EXIST=THERE)
            IF(THERE) THEN
              OPEN(TSFDSN,FILE=OLDNAME,FORM='UNFORMATTED',STATUS='OLD',
     a           access='direct', recl=4)
              read(tsfdsn, rec=1) record_len
              close(tsfdsn)
              OPEN(TSFDSN,FILE=OLDNAME,FORM='UNFORMATTED',STATUS='OLD',
     a           access='direct', recl=record_len)

            ELSE
              WRITE(STDOUT,60) OLDNAME
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'OPTIONS') THEN
C           Process the options list

            WRITE(STDOUT,62)

          ELSEIF(STRINGS(IFOUND).EQ.'END') THEN
C           Check if the requireded file has been given.
            IF(TSFDSN.EQ.0) THEN
              WRITE(STDOUT,58)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
            WRITE(STDOUT,72)
            WRITE(STDOUT,*) ' '


            EFLAG = 0
            CALL GET_DATES(STDOUT, TSFDSN, OLDNAME)

            CALL FREE_UNIT(STDOUT, TSFDSN)
            RETURN
          ENDIF
          GOTO 100            
      ELSE
        WRITE(STDOUT,70)
        EFLAG = 1
      ENDIF

      RETURN
      END
C     ********************
C     *                  *
C     *  GET_DATES
C     *                  *
C     ********************

      SUBROUTINE GET_DATES(STDOUT, TSFDSN, OLDNAME)

C     SCAN A TSF FILE AND OUTPUT THE STARTING AND ENDING TIME FOR
C     EACH EVENT. HEADER RECORDS WILL HAVE ALREADY BEEN READ

      implicit none
      INTEGER STDOUT, TSFDSN

      CHARACTER*(*) OLDNAME

C     Local
      INTEGER YRT, MNT, DYT, YR, MN, DY, NEWDSN, TSFTYP, NDFVAL,
     A        I, last_header_rec, nrec

      REAL R4(:), FACTOR

      DOUBLE PRECISION PTIME, PFRAC, JTIME, DYFRAC

      ALLOCATABLE :: R4
C     **************************** FORMATS ****************************
10    FORMAT(5X,'END TIME:  ',I4,'/',I2,'/',I2,':',F10.6,' JTIME=',
     A       F25.12)
12    FORMAT(5X,'START TIME:',I4,'/',I2,'/',I2,':',F10.6,' JTIME=',
     A       F25.12)
50    FORMAT(/,' Multiplying factor to create character dump=',
     A    1PE12.5)
C**********************************************************************
C     Set the value of FACTOR to get the minimum value.
      FACTOR = 1E30
C     Suppress copy to a new DTSF.
      NEWDSN = 0

C     Suprees checking of the number of diffuse values
      NDFVAL = 0
      CALL TSF_INIT(STDOUT, OLDNAME, TSFDSN, NEWDSN, 
     M                    NDFVAL, 
     O                    TSFTYP, last_header_rec)

      ALLOCATE (R4(NDFVAL))

      YRT = 0
      

      nrec = last_header_rec + 1
100   CONTINUE
        READ(TSFDSN, rec=nrec) JTIME, DYFRAC, YR, MN, DY,  R4
        nrec = nrec + 1

        IF(JTIME.GT.0.0) THEN
C         Remember time values 

          YRT = YR
          MNT = MN
          DYT = DY
          PTIME = JTIME
          PFRAC = DYFRAC

C         Update the value of FACTOR that can be used
C         to create a character dump of the time series
C         file. 
          DO 110 I=1,NDFVAL
            IF(R4(I).GT.0.0) THEN            
              FACTOR = MIN(FACTOR, 999999.0/R4(I))
            ENDIF
110       CONTINUE
          GOTO 100
        ENDIF

        IF(JTIME.LE.0.0) THEN
          IF(YRT.GT.0) THEN
C           WRITE ENDING TIME FOR PREVIOUS EVENT

C           REDUCE THE ENDING TIME TO MAKE SURE OF A PROPER END IN 
C           FEQ

C            PFRAC = PFRAC - 0.1/86400.D0
            WRITE(STDOUT,10) YRT, MNT, DYT, 24.*PFRAC, PTIME

          ENDIF

          IF(JTIME.EQ.0.0D0) THEN
            DEALLOCATE (R4)

            WRITE(STDOUT,50) FACTOR

           RETURN
          ENDIF

          WRITE(STDOUT,*) '  '
          WRITE(STDOUT,12) YR, MN, DY, 24.*DYFRAC, JTIME
        ENDIF

        GOTO 100

      END
C     **************
C     *            *
C     *  TSF_INIT_update    *
C     *            *
C     **************
 
      SUBROUTINE tsf_init_update(STDOUT, OLDTSF, OLDDSN,  
     i                    newtsf, NEWDSN,
     M                    NDFVAL, 
     O                    TSFTYP, last_header_rec)
 
C     Read header records in the TSF given by OLDTSF and 
C     create the header records for the  newtsf in the 
c     new format.  

      implicit none
      integer :: last_header_rec
      CHARACTER*(*) OLDTSF, newtsf
 
      INTEGER OLDDSN, NEWDSN, NDFVAL, STDOUT, TSFTYP

C     LOCAL

      INTEGER I, J, NDF, dtsf_version, record_len, limit,
     a   first_event_rec

      INTEGER :: A(:)
      ALLOCATABLE :: A

      INTEGER TEMP(10)
 
C     ************************* FORMATS *******************************
10    FORMAT(/,' The current TSF was created on ',
     1I4,'/',I2,'/',I2,' AT ',I4,' and has ',I3,
     2' LSRO values.')
11    FORMAT(' ','Simulation for the ',
     1'runoff values began on ',I4,'/',
     2I2,'/',I2,' and ended on ',I4,'/',I2,'/',I2,'.')
 
14    FORMAT(/,1X,20A4)
16    FORMAT(4X,'LSRO# ',I3,':',20A4)
50    FORMAT(/,' *ERR:XXX* ',I5,' Runoff values found in ',A,/,
     A    5X,' when ',I5,' were expected.')
52    FORMAT(\,' DTSF=',1X,A,/,
     A         '     uses 8 Bytes for each runoff value.')
53    format(4x,'Please convert to 4 bytes/runoff value first.')
54    FORMAT(\,' DTSF=',1X,A,/,
     A         '     uses 4 Bytes for each runoff value.')
56    FORMAT(//,' Information from the header records in the DSTF:')
C**********************************************************************
C     READ THE FIRST PART OF THE FIRST RECORD TO ESTABLISH THE FORMAT OF
C     THE old DTSF

      READ(OLDDSN) (TEMP(I), I=1,7)
      NDF = TEMP(6)
      TSFTYP = TEMP(7)
      CLOSE(OLDDSN)
      NDFVAL = NDF

      
      IF(TSFTYP.EQ.0) THEN
        WRITE(STDOUT,*) ' '
        WRITE(STDOUT,52) OLDTSF(1:len_trim(oldtsf))
        write(stdout,53)
        stop
      ELSE
        WRITE(STDOUT,54) OLDTSF(1:len_trim(oldtsf))
        WRITE(STDOUT,*) ' '
      ENDIF

C     REOPEN THE  old TSF FILE TO RESTART AT FIRST RECORD

      
      OPEN(OLDDSN, FILE= OLDTSF, FORM='UNFORMATTED', STATUS='OLD')

      LIMIT = 7 + NDFVAL
      ALLOCATE (A(LIMIT))

      record_len = 4*limit
      dtsf_version = 1
      first_event_rec = 4 + ndfval + 1
      close(newdsn)
      OPEN(NEWDSN,FILE=newtsf, FORM='UNFORMATTED',
     A         STATUS = 'UNKNOWN',  access='direct', recl=record_len)
      a = 0
      a(1) = record_len
      write(newdsn,rec=1) A


      READ(OLDDSN) A

C     WRITE second RECORD OF THE NEW TSF

c     increase the header-record count by 1
      a(5) = 4 + ndfval
      last_header_rec = a(5)
      A(7) = dtsf_version
      WRITE(NEWDSN, rec=2) A
 
      DO 12 I=1,4
        TEMP(I) = A(I)
12    CONTINUE

      READ(OLDDSN) A
      
C     WRITE third RECORD OF THE NEW TSF

      WRITE(NEWDSN, rec=3) A

      DO 13 I=5,10
        TEMP(I) = A(I-4)
13    CONTINUE

      DO 103 I=1,LIMIT
        A(I) = 0
103   CONTINUE 
      READ(OLDDSN) A
C     WRITE fourth  RECORD OF THE TSF

      WRITE(NEWDSN, rec=4) A

      WRITE(STDOUT,56)
      WRITE(STDOUT,14) (A(I), I=1,MIN(20,LIMIT))
      WRITE(STDOUT,10) (TEMP(I), I=1,4), NDFVAL
      WRITE(STDOUT,11) (TEMP(I), I=5,10)
      DO 15 I=1,NDFVAL
        READ(OLDDSN) A
        WRITE(NEWDSN, rec=4+i) A
        WRITE(STDOUT,16) I, (A(J), J=1,MIN(20,LIMIT))
15    CONTINUE

      DEALLOCATE ( A)

      RETURN
      END
C     *******************
C     *                 *
C     *  update_TSF
C     *                 *
C     *******************

      SUBROUTINE update_tsf(STDOUT, OLDDSN, NEWDSN, OLDNAME, 
     i                      newname,
     O                       EFLAG)

C     Update an old TSF to the new form

      implicit none
      INTEGER EFLAG, OLDDSN, NEWDSN, STDOUT

      CHARACTER*(*) OLDNAME, newname

C     Local

      INTEGER I, SYR, SMN, SDY, TSFTYP, last_header_rec,
     a     nrecnew,  ndfval

      REAL  R(2)

      real*8 EJTIME, SFRAC, JTIME, DUMMY

      real*4 RI(:)

      ALLOCATABLE :: RI

      EQUIVALENCE(DUMMY, R(1))

C***********************************************************************
C     Disable checking for proper number of diffuse areas.
      NDFVAL = 0
      CALL TSF_INIT_update(STDOUT, OLDNAME, OLDDSN, 
     i                    newname, NEWDSN, 
     M                    NDFVAL,
     O                    TSFTYP, last_header_rec)
      

      ALLOCATE ( RI(NDFVAL))
      
      last_header_rec = 4 + ndfval 
      nrecnew = last_header_rec + 1

1000  CONTINUE


C       READ AND WRITE THE FIRST RECORD OF THE EVENT 
        READ(OLDDSN) JTIME, SFRAC, SYR, SMN, SDY, RI
    
c       Extract emding time of the event
        r(1) = ri(1)
        r(2) = ri(2)
        ejtime = dummy


        WRITE(NEWDSN,rec=nrecnew) JTIME, SFRAC, SYR, SMN, SDY, RI
        nrecnew = nrecnew + 1

        IF(JTIME.EQ.0.D0) THEN
C         END OF FILE FOR THE TSF.

          DEALLOCATE (RI )
          WRITE(STDOUT,*) ' '
          WRITE(STDOUT,*) ' All events updated to new format.'
          RETURN
        ENDIF

C       PROCESS THE REMAINDER OF THE RECORDS IN THE CURRENT EVENT

2000    CONTINUE
C         TRANSFER INFORMATION FOR THIS EVENT

            READ(OLDDSN) JTIME, SFRAC, SYR, SMN, SDY, RI

            WRITE(NEWDSN, rec=nrecnew) JTIME, SFRAC, SYR, SMN, SDY, RI
            nrecnew = nrecnew + 1


            IF(JTIME.LT.EJTIME) GOTO 2000

        GOTO 1000

      END
C     ***********
C     *         *
C     * FIND_TERMINATER
C     *         *
C     ***********

      SUBROUTINE FIND_TERMINATER(MVAL, TERM, STRING,
     M                       ISTART)

C     Find STRING in the list of terminater strings and return
C     its location in ISTART.  ISTART points to the item  at
C     which to begin the search.  If STRING is not found, return
C     ISTART= 0.
      implicit none
      INTEGER MVAL, ISTART

      CHARACTER TERM(MVAL)*1
      CHARACTER*1 STRING

C     Local


      INTEGER I
C***********************************************************************
      DO 100 I=ISTART,MVAL
        IF(TERM(I).EQ.STRING) THEN
C         Found match.
          ISTART = I
          GOTO 101
        ENDIF
100   CONTINUE
      ISTART = 0
101   CONTINUE
      RETURN
      END      
C     ***********
C     *         *
C     * FIND_STRING
C     *         *
C     ***********

      SUBROUTINE FIND_STRING (MVAL, TYPE, CVAL, CLEN, STRING,
     M                       ISTART)

C     Find STRING in the list of character strings and return
C     its location in ISTART.  ISTART points to the item  at
C     which to begin the search.  If STRING is not found, return
C     ISTART= 0.

      INTEGER MVAL, TYPE(MVAL), CLEN(MVAL), ISTART

      CHARACTER CVAL(MVAL)*(*)
      CHARACTER*(*) STRING

C     Local

      INTEGER  CHRVAL, INTVAL, REAVAL, DPRVAL
      PARAMETER(INTVAL=1, REAVAL=2, DPRVAL=3, CHRVAL=4)

      INTEGER I
C***********************************************************************
      DO 100 I=ISTART,MVAL
        IF(CVAL(I)(1:CLEN(I)).EQ.STRING) THEN
C         Found match.
          ISTART = I
          GOTO 101
        ENDIF
100   CONTINUE
      ISTART = 0
101   CONTINUE
      RETURN
      END      
C     ***********
C     *         *
C     * FIND_ANY_STRING_IN_LIST
C     *         *
C     ***********

      SUBROUTINE FIND_ANY_STRING_IN_LIST(MVAL, NSTRING, TYPE, CVAL, 
     I                                    CLEN, STRINGS,
     M                                    ISTART,
     O                                    IFOUND)

C     Search for any string in STRINGS in the list in CVAL.  Start the
C     search each time at ISTART.  If a string is found ISTART points
C     to location in CVAL containing the string and IFOUND points
C     to the location in STRINGS containing the string.  If no string
C     is found, ISTART is unchanged and IFOUND is 0.

      INTEGER MVAL, TYPE(MVAL), CLEN(MVAL), ISTART, IFOUND

      CHARACTER CVAL(MVAL)*(*), STRINGS(NSTRING)*(*)

C     Local

      INTEGER  CHRVAL, INTVAL, REAVAL, DPRVAL
      PARAMETER(INTVAL=1, REAVAL=2, DPRVAL=3, CHRVAL=4)

      INTEGER I, ISTART_LOCAL
C***********************************************************************
      DO 200 I=1,NSTRING
        ISTART_LOCAL = ISTART

        CALL FIND_STRING (MVAL, TYPE, CVAL, CLEN, STRINGS(I),
     M                       ISTART_LOCAL)
        IF(ISTART_LOCAL.GT.0) THEN
C         Found a string.  
          ISTART = ISTART_LOCAL
          IFOUND = I
          GOTO 201
        ENDIF
200   CONTINUE
      IFOUND = 0
201   CONTINUE
      RETURN
      END                


C     ***********
C     *         *
C     * FIND_NEXT_CHARACTER_STRING
C     *         *
C     ***********

      SUBROUTINE FIND_NEXT_CHARACTER_STRING(MVAL, TYPE,
     M                                      NEXT_STRING_POINTER)

C     Find the pointer to the character string at or following the
C     value of NEXT_STRING_POINTER on entry.

      INTEGER MVAL, NEXT_STRING_POINTER, TYPE(MVAL)

C     Local

      INTEGER  CHRVAL, INTVAL, REAVAL, DPRVAL
      PARAMETER(INTVAL=1, REAVAL=2, DPRVAL=3, CHRVAL=4)

      INTEGER I
C***********************************************************************
      DO 100 I=NEXT_STRING_POINTER, MVAL
        IF(TYPE(I).EQ.CHRVAL) THEN
          NEXT_STRING_POINTER = I
          GOTO 101
        ENDIF
100   CONTINUE
C     Error- no string found in the list.
      NEXT_STRING_POINTER = 0
101   CONTINUE
      RETURN
      END
      

C     ***********
C     *         *
C     * update  *
C     *         *
C     ***********

      SUBROUTINE update(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 

C     Update a DTSF from the old form, using sequential access,
c     to the new form, using direct accsess. 
      implicit none
      INTEGER IFIRST, NVAL, MVAL, TYPE(NVAL), CLEN(NVAL),
     A        TERML(NVAL), TERMCLS(NVAL), IVAL(NVAL), STDOUT,
     B        STDIN,  EFLAG

      REAL RVAL(NVAL)

      DOUBLE PRECISION DPVAL(NVAL)

      CHARACTER CVAL(NVAL)*(*), TERM(NVAL)*1

C     Local

      LOGICAL THERE

      CHARACTER COMMAND*64, LINE*192, LINE2*194, STRINGS(3)*3,
     A          OLDNAME*128, NEWNAME*128

      INTEGER I, ISTART, CL, OPT, OLDDSN, NEWDSN,
     A        NSTRING, ITERM, IT, ifound, ioflag

C     Program units

      INTEGER GET_UNIT

      EXTERNAL GET_UNIT
           
      DATA NSTRING/3/, STRINGS/'NEW','OLD','END'/
C     *****************************FORMATS******************************
50    FORMAT(/,' *ERR:XXX* No second level command found.')
52    FORMAT(/,' *ERR:XXX* Invalid values given for current command.')
54    FORMAT(1X,A)
56    FORMAT(/,' *ERR:XXX* Old DTSF file name appears twice.')
58    FORMAT(/,' *ERR:XXX* No file name found for Old DTSF.')
60    FORMAT(/,' *ERR:XXX* File name=',A,/,11X,'not found. Please ',
     A  'check name, path, and drive letter.')
62    FORMAT(/,' *ERR:XXX* New DTSF file name appears twice.')
64    FORMAT(/,' *ERR:XXX* No file name found for New DTSF.')
66    FORMAT(/,' *ERR:XXX* Could not open file name=',/,A,/,11X,
     A      'Please check name, path, and driver letter.')
68    FORMAT(/,' *ERR:XXX* Old DTSF is already in new format.')
70    FORMAT(/,' *ERR:XXX* Second level command invalid.')
72    FORMAT(/,' Processing command: UPDATE DTSF')
C***********************************************************************
      OPT = 1
C     Clear the unit numbers so that they can be used to 
C     verify that both the old and the new file have been
C     properly defined. 
      OLDDSN = 0
      NEWDSN = 0

C     Find the next string in the list.
      ISTART = IFIRST
      CALL FIND_NEXT_CHARACTER_STRING(MVAL, TYPE,
     M                                      ISTART)
      IF(ISTART.EQ.0) THEN
        WRITE(STDOUT,50) 
        STOP 'Abnormal stop.  Errors found.'
      ENDIF

      COMMAND = CVAL(ISTART)
      CL = CLEN(ISTART)
      
      IF(COMMAND(1:CL).EQ.'DTSF') THEN
        WRITE(*,72)
C       Found valid response.  Process subsequent lines.

100     CONTINUE
          CALL inline(STDIN, STDOUT,
     O                LINE)

          WRITE(STDOUT,54) LINE(1:len_trim(line))

          LINE2 = LINE
          call maybe_add_quote(
     m                           line2)
          CALL GETVAL(STDOUT, LINE2, NVAL, OPT,
     O                 TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O                 TERM, TERML, TERMCLS, MVAL)
        
          ITERM = 1
          CALL FIND_TERMINATER(MVAL, TERM, '=',
     O                       ITERM)

          ISTART = 1
          IF(ITERM.GT.0) THEN
            IT = ITERM
          ELSE
            IT = MVAL
          ENDIF
          CALL FIND_ANY_STRING_IN_LIST(IT, NSTRING, TYPE, CVAL, CLEN,
     I                                  STRINGS,
     M                                  ISTART,
     O                                  IFOUND)

          IF(IFOUND.EQ.0) THEN
            WRITE(STDOUT,52)
            STOP 'Abnormal stop. Errors found.'
          ENDIF

          IF(STRINGS(IFOUND).EQ.'OLD') THEN
C           Process the old file name.
            IF(OLDDSN.EQ.0) THEN
              OLDDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,56) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              OLDNAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,58) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

            INQUIRE(FILE=OLDNAME, EXIST=THERE)
            IF(THERE) THEN
              OPEN(OLDDSN,FILE=OLDNAME,FORM='UNFORMATTED',STATUS='OLD')
            ELSE
              WRITE(STDOUT,60) OLDNAME
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'NEW') THEN
C           Process the new file name.
            IF(NEWDSN.EQ.0) THEN
              NEWDSN = GET_UNIT (STDOUT)
            ELSE
              WRITE(STDOUT,62)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF                    

C           Get the file name.  Is on the same line but must be after the
C           = terminater.  It is the identifier after the equal sign.
            IF(ITERM.GT.0) THEN
              NEWNAME = CVAL(ITERM+1)
            ELSE
              WRITE(STDOUT,66) 
              STOP 'Abnormal stop.  Errors found.'
            ENDIF            

c           Open the new file, which may not yet exist, with 
c           dummy record length to make sure the path name 
c           and so forth are valid.  Later on, when we know
c           the record length, it will be closed and reopened.
            OPEN(NEWDSN,FILE=NEWNAME,FORM='UNFORMATTED',
     A               STATUS = 'UNKNOWN', IOSTAT=IOFLAG,
     b               access='direct',recl=4)
            IF(IOFLAG.NE.0) THEN
              WRITE(STDOUT,64) NEWNAME
              STOP 'Abnormal stop: Errors found.'
            ENDIF
          ELSEIF(STRINGS(IFOUND).EQ.'END') THEN
C           Check if both the requireded files have been given.
            IF(OLDDSN.EQ.0) THEN
              WRITE(STDOUT,58)
              STOP 'Abnormal stop.  Errors found.'
            ELSEIF(NEWDSN.EQ.0) THEN
              WRITE(STDOUT,64)
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
            WRITE(STDOUT,72)
            WRITE(STDOUT,*) ' '

            EFLAG = 0
            CALL update_tsf(STDOUT, OLDDSN, NEWDSN, OLDNAME,
     i                       newname, 
     O                       EFLAG)
            IF(EFLAG.GT.0) THEN
              WRITE(STDOUT,68) 
            ENDIF
            CALL FREE_UNIT (STDOUT, OLDDSN)
            CALL FREE_UNIT (STDOUT, NEWDSN)
            RETURN
          ENDIF
          GOTO 100            
      ELSE
        WRITE(STDOUT,70)
        CALL FREE_UNIT (STDOUT, OLDDSN)
        CALL FREE_UNIT (STDOUT, NEWDSN)
        EFLAG = 1
      ENDIF

      RETURN
      END
                              
C     **************
C     *            *
C     *  TSF_INIT    *
C     *            *
C     **************
 
      SUBROUTINE TSF_INIT(STDOUT, OLDTSF, OLDDSN, NEWDSN,
     M                    NDFVAL, 
     O                    TSFTYP, last_header_rec)
 
C     Read header records in the TSF given by OLDTSF, optionally
C     check for validity of the number of runoff values, and 
C     by NEWDSN.
      implicit none
      CHARACTER*(*) OLDTSF
 
      INTEGER OLDDSN, NEWDSN, NDFVAL, STDOUT, TSFTYP, last_header_rec

C     LOCAL

      INTEGER I, J, NDF, limit

      INTEGER A(:)
      ALLOCATABLE :: A

      INTEGER TEMP(10)
 
C     ************************* FORMATS *******************************
10    FORMAT(/,' The current TSF was created on ',
     1I4,'/',I2,'/',I2,' AT ',I4,' and has ',I3,
     2' LSRO values.')
11    FORMAT(' ','Simulation for the ',
     1'runoff values began on ',I4,'/',
     2I2,'/',I2,' and ended on ',I4,'/',I2,'/',I2,'.')
 
14    FORMAT(/,1X,20A4)
16    FORMAT(4X,'LSRO# ',I3,':',20A4)
50    FORMAT(/,' *ERR:XXX* ',I5,' Runoff values found in ',A,/,
     A    5X,' when ',I5,' were expected.')
52    FORMAT(\,' DTSF=',1X,A,/,
     A         '     uses 8 Bytes for each runoff value.')
53    format(4x,'Please convert to 4 bytes/runoff value.')
54    FORMAT(\,' DTSF=',1X,A,/,
     A         '     uses 4 Bytes for each runoff value.')
56    FORMAT(//,' Information from the header records in the DSTF:')
C**********************************************************************
C     READ THE FIRST PART OF THE second RECORD TO ESTABLISH THE FORMAT OF
C     THE DTSF

      READ(OLDDSN, rec=2) (TEMP(I), I=1,7)
      last_header_rec = temp(5)
      NDF = TEMP(6)
      TSFTYP = TEMP(7)
      IF(NDFVAL.GT.0) THEN 
C       CHECK FOR AGREEMENT
        IF(NDFVAL.NE.NDF) THEN 
          WRITE(STDOUT,50) NDF, OLDTSF, NDFVAL
          STOP 'Abnormal stop. Errors found.'
        ENDIF
      ELSE
        NDFVAL = NDF
      ENDIF

      
      IF(TSFTYP.EQ.0) THEN
        WRITE(STDOUT,*) ' '
        WRITE(STDOUT,52) OLDTSF(1:len_trim(oldtsf))
        write(stdout,53)
      ELSE
        WRITE(STDOUT,54) OLDTSF(1:len_trim(oldtsf))
        WRITE(STDOUT,*) ' '
      ENDIF

      
      LIMIT = 7 + NDFVAL

      ALLOCATE (A(LIMIT))

      READ(OLDDSN, rec=1 ) A
      IF(NEWDSN.GT.0) WRITE(NEWDSN, rec=1)  A


      READ(OLDDSN, rec=2 ) A
      IF(NEWDSN.GT.0) WRITE(NEWDSN, rec=2) A
 
c     Remember the dates and times from the second record
      DO 12 I=1,4
        TEMP(I) = A(I)
12    CONTINUE

      READ(OLDDSN, rec=3 ) A
      IF(NEWDSN.GT.0) WRITE(NEWDSN, rec=3) A

c     Remember dates and times from the third record
      DO 13 I=5,10
        TEMP(I) = A(I-4)
13    CONTINUE

      READ(OLDDSN, rec=4 ) A
      IF(NEWDSN.GT.0) WRITE(NEWDSN, rec=4) A

      WRITE(STDOUT,56)
      WRITE(STDOUT,14) (A(I), I=1,MIN(20,LIMIT))
      WRITE(STDOUT,10) (TEMP(I), I=1,4), NDFVAL
      WRITE(STDOUT,11) (TEMP(I), I=5,10)
      DO 15 I=1,NDFVAL
        READ(OLDDSN, rec=4+i) A
        IF(NEWDSN.GT.0) WRITE(NEWDSN, rec=4+i) A
        WRITE(STDOUT,16) I, (A(J), J=1,MIN(20,LIMIT))
15    CONTINUE


      DEALLOCATE ( A)

      RETURN
      END
C
C
C
      SUBROUTINE TO_UPPER(
     M            STRING)
C
C     Convert a character string from lower case to upper case
C     Modified from USGS routine.
      CHARACTER*(*) STRING

C     + + + ARGUMENT DEFINITIONS + + +
C     STRING - character string to be made upper case

C     + + + LOCAL VARIABLES + + +
      INTEGER   I, ICH, IEND

C     + + + INTRINSICS + + +
      INTRINSIC  ICHAR, LEN, CHAR
C***********************************************************************
      IEND = LEN(STRING)
      DO 10 I = 1, IEND
        ICH = ICHAR(STRING(I:I))
        IF(ICH.GE.97 .AND. ICH.LE.122) THEN
C         Character is lower case.
          STRING(I:I)= CHAR(ICH-32)
        ENDIF
 10   CONTINUE

      RETURN
      END
C
C
C
      SUBROUTINE   STAINT
     I                   (CLASS,
     O                    STATE)
 
C     + + + PURPOSE + + +
C     Initialize the STATE from the CLASS of the first character
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER CLASS, STATE
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     CLASS  - Class for the character being processed
C     STATE  - Status for the scanner
 
      INTEGER PERIOD, ASTERISK, PLUS_OR_MINUS, COMMA, SLASH, BLANK, 
     A        COLON, EQUAL, UNDERLINE, BACKSLASH, QUOTE, DIGIT, A_TO_C,
     B        D, E, F_TO_Z, IDENTIFIER, INTEGER, FIXED, SINGLE1, 
     C        SINGLE2, SINGLE3, DOUBLE1, DOUBLE2, DOUBLE3,
     D        ASTERISKP, COMMAP, SLASHI, BACKSLASHI, COLONI,
     E        EQUALI

      PARAMETER (PERIOD=1, ASTERISK=2, PLUS_OR_MINUS=3, COMMA=4,
     A           SLASH=5, BLANK=6, COLON=7, EQUAL=8, UNDERLINE=9, 
     B           BACKSLASH=10, QUOTE=11, DIGIT=12, A_TO_C=13, D=14,
     C           E=15, F_TO_Z=16, IDENTIFIER=1, INTEGER=2, FIXED=3,
     D           SINGLE1=4, SINGLE2=5, SINGLE3=6, DOUBLE1=7,         
     E           DOUBLE2=8, DOUBLE3=9, ASTERISKP=10, COMMAP=11, 
     F          SLASHI=12, BACKSLASHI=13, COLONI=14, EQUALI=15)

      INTEGER CLASS_TO_STATE(16)

      DATA CLASS_TO_STATE/FIXED,      ASTERISKP,   INTEGER,   COMMAP,
     A                    SLASHI,     -1,          COLONI,    EQUALI,
     B                    IDENTIFIER, BACKSLASHI,  -1,        INTEGER,
     C                    4*IDENTIFIER/              
     
C     + + + COMMON BLOCKS + + +
      INCLUDE 'stdun.cmn'
C***********************************************************************
C     State initialization rules:

C     Char Class     State value assigned 
C       period          fixed
C      asterisk         asteriskp
C      plus/minus       integer
C      comma            commap
C      slash            slashi
C      blank            should not appear 
C      colon            coloni
C      equal            equali
C      underline        identifier
C      backslash        backslashi
C      quote            should not appear here
C      digit            integer
C      a:c              identifier
C       d               identifier
C       e               identifier
C      f:z              identifier

      STATE = CLASS_TO_STATE(CLASS)
      IF(STATE.LE.0) THEN
        WRITE(STD6,*) ' BUG:Invalid CLASS=', CLASS,' in STAINT.'
        STOP 'Abnormal stop.  Errors found.'
      ENDIF
      END
C
C
C
      SUBROUTINE   GITEM
     I                  (LINE,
     M                   FIRST,
     O                   ITEM, ITML, ITMSTA,  TERM, TERML, TERMCLS, EOS)
 
C     + + + PURPOSE + + +
C     Get an item from a LINE of input.  GITEM keeps track of the
C     call sequence and signals EOS=1 if the string has been exhausted
C     by the item returned.
C     
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EOS, ITMSTA, ITML, TERML, TERMCLS
      CHARACTER ITEM*(*), LINE*(*), TERM*(*)
      LOGICAL FIRST
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     LINE   - Character string to be processed
C     FIRST  - Flag for first call to GITEM
C     ITEM   - Value of the next item in the search string
C     ITML   - Number of characters in the item found
C     ITMSTA   - State for the item found
C     EOS    - End of string flag
C     TERM   - string value of terminating entity
C     TERML  - number of characters in the terminating entity
C     TERMCLS - class number for the terminator
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'stdun.cmn'
 
C     + + + SAVED VALUES + + +
      INTEGER ACTION(15,16), CHRCLS(0:255), L, NEXT, SLEN, STATE
      CHARACTER VAL*80
      SAVE ACTION, CHRCLS, L, NEXT, SLEN, STATE, VAL
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ACT, CLASS, J
      CHARACTER CHR*1
 
C     + + + INTRINSICS + + +
      INTRINSIC ICHAR, LEN
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL STAINT

 
C     This is the action matrix in two forms: labeled for a human reader
C     and in data input form for a computer reader. 

C                 Class of the next character:                                                            
C                    1        2       3      4     5      6     7     8    9     10    11    12   13  14  15   16
C                  period asterisk  plus  comma  slash blank colon equal under back  quote digit a:c   d   e  f:z
C     STATE                         minus                                line  slash                       
C  --------        ------ -------- ------ ----- ------ ----- ----- ----- ----- ----- ----- ----- --- --- --- ----
C  1  identifier      1      2        2     3      1    11     1     3     1     1     9     1    1    1   1   1 
C  2  integer         4      3       10     3      3    11     3     2     2     2     9     1    2   13   5   2     
C  3  fixed           2      2       10     3      2    11     2     2     2     2     9     1    2   13   5   2            
C  4  single1         2      2       10     2      2     2     2     2     2     2     2    15    2    2   2   2 
C  5  single2         2      2        2     2      2     2     2     2     2     2     2    15    2    2   2   2 
C  6  single3         2      2        2     3      2    11     2     2     2     2     9     1    2    2   2   2 
C  7  double1         2      2       14     2      2     2     2     2     2     2     2    16    2    2   2   2       
C  8  double2         2      2        2     2      2     2     2     2     2     2     2    16    2    2   2   2 
C  9  double3         2      2        2     3      2    11     2     2     2     2     9     1    2    2   2   2
C 10  asteriskp       2      2        2     3      2    11     2     2     2     2     9     2    2    2   2   2
C 11  commap          7      7        7     7      7     7     2     2     7     7     8     7    7    7   7   7
C 12  slashi          2      2        2     2      2     2     2     2    12     2     2    12   12   12  12  12
C 13  backslashi      2      2        2     2      2     2     2     2    12     2     2    12   12   12  12  12
C 14  coloni          2      2        2     2      2     2     2     2     2     2     2     2    2    2   2   2
C 15  equali          2      2        2     2      2     2     2     2     2     2     2     2    2    2   2   2



C     Summary statement of each action. 
C     Action#   Description
C        1      add a character to the current item
C        2      error condition-invalid sequence of characters
C        3      Terminate and return the current item. 
C        4      Add character to the current item and change state to a fixed point number.
C        5      Add char to current item and change state to single1 item.
C        6      open
C        7      Terminate and return an asteriskp with comma as terminater
C        8      Terminate and return an asteriskp with quote as trminater- end of line
C        9      End of input line.  Return the item and set the end of string flag.
C       10      Add char to item and change the state to single2.
C       11      Find next non-blank and reset terminator as needed. 
C       12      Add to current item and change state to identifier
C       13      Add char to current item and change state to double1 item.
C       14      Add char to current item and change state to double2
C       15      Add char to current item and change state to single3
C       16      Add char to current item and change state to double3

C     State initialization rules:

C     Char Class     State value assigned 
C       period          fixed
C      asterisk         asteriskp
C      plus/minus       integer
C      comma            commap
C      slash            slashi
C      blank            skip to non-blank and try again
C      colon            coloni
C      equal            error
C      underline        identifier
C      backslash        backslashi
C      quote            end of line
C      digit            integer
C      a:c              identifier
C       d               identifier
C       e               identifier
C      f:z              identifier


      INTEGER PERIOD, ASTERISK, PLUS_OR_MINUS, COMMA, SLASH, BLANK, 
     A        COLON, EQUAL, UNDERLINE, BACKSLASH, QUOTE, DIGIT, A_TO_C,
     B        D, E, F_TO_Z, IDENTIFIER, INTEGER, FIXED, SINGLE1, 
     C        SINGLE2, SINGLE3, DOUBLE1, DOUBLE2, DOUBLE3,
     D        ASTERISKP, COMMAP, SLASHI, BACKSLASHI, COLONI,
     E        EQUALI

      PARAMETER (PERIOD=1, ASTERISK=2, PLUS_OR_MINUS=3, COMMA=4,
     A           SLASH=5, BLANK=6, COLON=7, EQUAL=8, UNDERLINE=9, 
     B           BACKSLASH=10, QUOTE=11, DIGIT=12, A_TO_C=13, D=14,
     C           E=15, F_TO_Z=16, IDENTIFIER=1, INTEGER=2, FIXED=3,
     D           SINGLE1=4, SINGLE2=5, SINGLE3=6, DOUBLE1=7,         
     E           DOUBLE2=8, DOUBLE3=9, ASTERISKP=10, COMMAP=11, 
     F           SLASHI=12, BACKSLASHI=13, COLONI=14, EQUALI=15)


C     Set the class for each of the 256 characters that might be seen in
C     a string.  Assumes the ASCII sequence!  This will not work with
C     EBCIDC.  Characters that are skipped(ignored) are given the class
C     of zero.  

      DATA CHRCLS/32*0,BLANK,6*0,QUOTE,2*0, ASTERISK, PLUS_OR_MINUS, 
     A            COMMA, PLUS_OR_MINUS, PERIOD, SLASH, 10*DIGIT, 
     B            COLON, 2*0, EQUAL,3*0, 3*A_TO_C, D, E, 21*F_TO_Z,
     C            0, BACKSLASH, 2*0, UNDERLINE, 0, 3*A_TO_C, D, E, 
     D            21*F_TO_Z, 133*0/


      DATA ((ACTION(I,J),J=1,16),I=1,15)/
     A       1, 2, 2, 3, 1,11, 1, 3, 1, 1, 9, 1, 1, 1, 1, 1, 
     B       4, 3,10, 3, 3,11, 3, 2, 2, 2, 9, 1, 2,13, 5, 2, 
     C       2, 2,10, 3, 2,11, 2, 2, 2, 2, 9, 1, 2,13, 5, 2, 
     D       2, 2,10, 2, 2, 2, 2, 2, 2, 2, 2,15, 2, 2, 2, 2, 
     E       2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,15, 2, 2, 2, 2, 
     F       2, 2, 2, 3, 2,11, 2, 2, 2, 2, 9, 1, 2, 2, 2, 2, 
     G       2, 2,14, 2, 2, 2, 2, 2, 2, 2, 2,16, 2, 2, 2, 2, 
     H       2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,16, 2, 2, 2, 2, 
     I       2, 2, 2, 3, 2,11, 2, 2, 2, 2, 9, 1, 2, 2, 2, 2, 
     J       2, 2, 2, 3, 2,11, 2, 2, 2, 2, 9, 2, 2, 2, 2, 2, 
     K       7, 7, 7, 7, 7, 7, 2, 2, 7, 7, 8, 7, 7, 7, 7, 7, 
     L       2, 2, 2, 2, 2, 2, 2, 2,12, 2, 2,12,12,12,12,12, 
     M       2, 2, 2, 2, 2, 2, 2, 2,12, 2, 2,12,12,12,12,12, 
     N       2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     O       2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2/
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' Offending line:',/,1X,A)
 52   FORMAT(/,' Invalid item:',A)
C***********************************************************************
      IF(FIRST) THEN
C       THIS IS THE FIRST CALL FOR LINE
        FIRST = .FALSE.
 
C       CLEAR THE LOCAL ITEM LENGTH
        L = 0
C       CLEAR THE END OF STRING FLAG
        EOS = 0
C       GET THE LENGTH OF THE CURRENT STRING
        SLEN = LEN(LINE)
        NEXT = 1
      ENDIF

6000  CONTINUE
        CHR = LINE(NEXT:NEXT)
        CLASS = CHRCLS(ICHAR(CHR))
        IF(CLASS.EQ.0.OR.CLASS.EQ.BLANK) THEN
          NEXT = NEXT + 1
          GOTO 6000
        ENDIF
      L = 1
      VAL(L:L) = CHR

      IF(CLASS.NE.QUOTE) THEN
        CALL STAINT (CLASS,
     O               STATE)
        NEXT = NEXT + 1  
      ENDIF
      
C     NOT THE FIRST TIME FOR THIS LINE
C     GET THE NEXT CHARACTER AND PROCESS.
 
 9000 CONTINUE
        CHR = LINE(NEXT:NEXT)
        CLASS = CHRCLS(ICHAR(CHR))
        IF(CLASS.EQ.0) THEN
          NEXT = NEXT + 1
          GOTO 9000
        ENDIF

C        WRITE(STD6,*) ' CHR=',CHR,' ICHAR=',ICHAR(CHR)
 
C       NOW SELECT THE NEXT ACTION USING THE MATRIX, STATE, AND
C       CLASS
 
        ACT = ACTION(STATE,CLASS)
C        WRITE(STD6,*) ' STATE=',STATE,' CLASS=',CLASS,' ACT=',ACT
 
        GOTO(100, 200, 300, 400, 500, 600, 700, 800, 900, 1000,
     A       1100, 1200, 1300, 1400, 1500, 1600), ACT
 
          WRITE(STD6,*) ' BUG: INVALID INDEX FOR COMP. GOTO.'
          WRITE(STD6,*) ' IN SUB. GITEM. INDEX=',ACT
          STOP
 
 100      CONTINUE
C           Add a character to the current item
            L = L + 1
            VAL(L:L) = CHR
            GOTO 8900
 
 200      CONTINUE
C           Error condition
 
            WRITE(STD6,52) VAL(1:L)//CHR
            WRITE(STD6,50) LINE(1:len_trim(line))
 
            EOS = 1
            ITEM = ' '
            ITML = 0
            ITMSTA = STATE
            TERM = ' '
            TERML = 0
            TERMCLS = -1
            FIRST = .TRUE.
            RETURN
 
 300      CONTINUE
C           Terminate and return the current item 

            ITEM = VAL(1:L)
            ITML = L
            ITMSTA = STATE

            TERM = CHR
            TERML = 1
            TERMCLS = CLASS
 
            NEXT = NEXT + 1
            RETURN
 
 400      CONTINUE
C           Add character to the current item and change state to
C           a fixed point number
            L = L + 1
            VAL(L:L) = CHR
            STATE = FIXED
            GOTO 8900
 
 500      CONTINUE
C           Add char to current item and change state to SINGLE1
            L = L + 1
            VAL(L:L) = CHR
            STATE = SINGLE1
            GOTO 8900
 
 600      CONTINUE
            STOP 'PROGRAM BUG AT 600 IN GITEM'
 
 
 700      CONTINUE
C           Terminate and return an asteriskp with comma as terminater
            ITEM = '*'
            ITML = 1
            ITMSTA = ASTERISKP

            TERM = ','
            TERML = 1
            TERMCLS = COMMA
 
C           Do not increment NEXT because the char at NEXT must be 
C           used for the next item.
C            NEXT = NEXT + 1
            RETURN

 
 800      CONTINUE
C           Terminate and return an asteriskp with quote as trminater- 
C           end of line
            ITEM = '*'
            ITML = 1
            ITMSTA = ASTERISKP

            TERM = ''''
            TERML = 1
            TERMCLS = QUOTE

            EOS = 1 
            FIRST = .TRUE.
            RETURN
 
 900      CONTINUE
C           End of input line.  Return the item and set the end of 
C           string flag.
            ITEM = VAL(1:L)
            ITML = L
            ITMSTA = STATE
            TERM = ''''
            TERML = 1
            TERMCLS = QUOTE
            EOS = 1
            FIRST = .TRUE.
            RETURN
 
 1000     CONTINUE
C           Add char to item and change the state to single2.
            L = L + 1
            VAL(L:L) = CHR
            STATE = SINGLE2
            GOTO 8900
 
 1100     CONTINUE
C           Find next non-blank and reset terminator as needed. 
C           Must set terminater to the correct value.  May not be
C           a blank.  The following values could be the terminater
C           with one or more blanks between it and the current value:
C            comma, equal
 
            ITEM = VAL(1:L)
            ITML = L
            ITMSTA = STATE

 
C           Chr contains a blank.  Next points at its location.
C           Search ahead for the next non-blank or end of string.
 
            DO 1101 J=NEXT+1,SLEN
              CHR = LINE(J:J)
              CLASS = CHRCLS(ICHAR(CHR))
              IF(CLASS.NE.BLANK) THEN
                IF(CLASS.EQ.COMMA) THEN
C                 Found a comma. Adjust the pointer to use
C                 it as the terminater instead of the space.
                  TERM = ','
                  TERMCLS = COMMA
                  NEXT = J+1
                ELSEIF(CLASS.EQ.EQUAL) THEN
                  TERM = '='
                  TERMCLS = EQUAL
                  NEXT = J+1
                ELSE
C                 The blank is the terminater.
                  TERM = ' '
                  TERMCLS = BLANK
                  NEXT = J 
                ENDIF
                TERML = 1
                RETURN
              ELSE
               
              ENDIF
 1101       CONTINUE
C           DROP THROUGH MEANS NO NON-BLANK FOUND UNTIL END OF LINE
C           SIMULATE WITH A COMMA ALSO
            NEXT = SLEN + 1
            TERM = ' '
            TERML = 1
            TERMCLS = BLANK
            EOS = 1
            RETURN


1200      CONTINUE
C           Add to current item and change state to identifier
            L = L + 1
            VAL(L:L) = CHR
            STATE = IDENTIFIER
            GOTO 8900

1300      CONTINUE
C           Add char to current item and change state to double1.
            L = L + 1
            VAL(L:L) = CHR
            STATE = DOUBLE1
            GOTO 8900

1400      CONTINUE
C           Add char to current item and change state to double2
            L = L + 1
            VAL(L:L) = CHR
            STATE = DOUBLE2
            GOTO 8900

1500      CONTINUE
C           Add char to current item and change state to single3
            L = L + 1
            VAL(L:L) = CHR
            STATE = SINGLE3
            GOTO 8900
 
1600      CONTINUE
C           Add char to current item and change state to double3
            L = L + 1
            VAL(L:L) = CHR
            STATE = DOUBLE3
            GOTO 8900

 8900   CONTINUE
 
        NEXT = NEXT + 1
        GOTO 9000
 
      END
C
C
C
      SUBROUTINE   GETVAL
     I                   (STDERR, LINE, NVAL, OPT,
     O                    TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O                    TERM, TERML, TERMCLS,
     O                    MVAL)
 
C     + + + PURPOSE + + +
C     Get values from LINE and store them in the appropriate element
C     of the vector(IVAL, RVAL, DPVAL, or CVAL) of the proper type.
C     Report errors in type that prevent proper conversions.  Report
C     excess values.
 
C     STDERR- unit number for output of errors and messages.
C     LINE- the character string to scan.
C     NVAL- the maximum number of values to expect.  It is an error if
C           this number is exceeded.
C     OPT-  if 0 then
C       TYPE- vector giving the type of value expected for each value in
C              LINE
C       IVAL, RVAL, DPVAL, CVAL- vectors of the correct type for storing
C           the values found in LINE.
C       CLEN- vector giving the length of the character string if the
C             value is of type CHARACTER.
C       EFLAG- set to 1 if an error was found in LINE.
C       MVAL- the number of values actually found. A value may be null or
C             defaulted and it is still counted.
C     else if 1
C       TYPE- vector giving the type of value found in LINE
C       CVAL- gives the value returned
C       CLEN- give the length of the value
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, MVAL, NVAL, OPT, STDERR
      INTEGER CLEN(NVAL), IVAL(NVAL), TYPE(NVAL), TERML(NVAL),
     A        TERMCLS(NVAL)
      REAL RVAL(NVAL)
      DOUBLE PRECISION DPVAL(NVAL)
      CHARACTER CVAL(NVAL)*(*), LINE*(*), TERM(NVAL)*1
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDERR - Fortran unit number for output of error messages
C     LINE   - Character string to be processed
C     NVAL   - Number of items expected in the string
C     OPT    - If OPT=0 then number and type of items are known else
C               if OPT=1 then number and type are unknown
C     TYPE   - Type of item: real, integer, char, double precision
C     IVAL   - Contains integer value for an integer item
C     RVAL   - Return value for a real item
C     DPVAL  - Return for a double precision value
C     CVAL   - Contains character string returned for a string value
C     CLEN   - Vector giving the length of the character string if the
C               value is of type CHARACTER
C     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors
C     MVAL   - Number of item found in the string
 
C     + + + LOCAL PARAMETERS + + +
      INTEGER  CHRVAL, INTVAL, REAVAL, DPRVAL
      PARAMETER(INTVAL=1, REAVAL=2, DPRVAL=3, CHRVAL=4)
 
      INTEGER PERIOD, ASTERISK, PLUS_OR_MINUS, COMMA, SLASH, BLANK, 
     A        COLON, EQUAL, UNDERLINE, BACKSLASH, QUOTE, DIGIT, A_TO_C,
     B        D, E, F_TO_Z, IDENTIFIER, INTEGER, FIXED, SINGLE1, 
     C        SINGLE2, SINGLE3, DOUBLE1, DOUBLE2, DOUBLE3,
     D        ASTERISKP, COMMAP, SLASHI, BACKSLASHI, COLONI

      PARAMETER (PERIOD=1, ASTERISK=2, PLUS_OR_MINUS=3, COMMA=4,
     A           SLASH=5, BLANK=6, COLON=7, EQUAL=8, UNDERLINE=9, 
     B           BACKSLASH=10, QUOTE=11, DIGIT=12, A_TO_C=13, D=14,
     C           E=15, F_TO_Z=16, IDENTIFIER=1, INTEGER=2, FIXED=3,
     D           SINGLE1=4, SINGLE2=5, SINGLE3=6, DOUBLE1=7,         
     E           DOUBLE2=8, DOUBLE3=9, ASTERISKP=10, COMMAP=11, 
     F           SLASHI=12, BACKSLASHI=13, COLONI=14)

C     + + + SAVED VALUES + + +
      INTEGER DEFTYP(14)
      SAVE DEFTYP
 
C     + + + LOCAL VARIABLES + + +
      INTEGER EOS, ITMSTA, ITML, TRML, TRMCLS
      CHARACTER ITEM*64, TRM*1
      LOGICAL FIRST
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GITEM
 
C     + + + DATA INITIALIZATIONS + + +
      DATA DEFTYP/CHRVAL, INTVAL, REAVAL,-1,-1,-1,-1,-1,
     A            DPRVAL,-1,-2,-2,-2,-2/
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,'*ERR:552* Found at least',I5,' items. Expected no more',
     A       ' than',I5)
 51   FORMAT(/,'*BUG:XXX* Invalid type=',I5,' found in GETVAL.')
 52   FORMAT(/,'*ERR:553* Expected an integer number but found ',A20,
     A         ' instead.')
 53   FORMAT(/,'*ERR:554* Expected a number but found ',A20,' instead.')
 54   FORMAT(/,'*WRN:555* Expected an identifier but found ',A20,
     A       ' instead.')
 56   FORMAT(/,' Offending line:',A)
C***********************************************************************
C     CLEAR THE COUNTER FOR VALUES FOUND
 
      MVAL = 0
 
C     SET THE FIRST CALL TO TRUE
 
      FIRST = .TRUE.
 
C     SEEK SUCCESSIVE ITEMS FROM LINE AND TAKE THE REQUIRED ACTION.
 
99999 CONTINUE
        CALL GITEM
     I            (LINE,
     M             FIRST,
     O             ITEM, ITML, ITMSTA, 
     O             TRM, TRML, TRMCLS, EOS)
        IF(EOS.EQ.1.AND.ITML.EQ.0) THEN
C         END OF STRING FOUND.
            
          RETURN
        ELSE
C         PROCESS A VALUE.
          MVAL = MVAL + 1
          IF(OPT.EQ.1) THEN
            TYPE(MVAL) = DEFTYP(ITMSTA)
            CVAL(MVAL) = ITEM
            CLEN(MVAL) = ITML
            TERM(MVAL) = TRM
            TERML(MVAL) = TRML
            TERMCLS(MVAL) = TRMCLS
          ENDIF
          IF(MVAL.GT.NVAL) THEN
            WRITE(STDERR,50) MVAL, NVAL
            EFLAG = 1
            RETURN
          ENDIF
 
          IF(OPT.EQ.1) GOTO 70000
 
C         BRANCH ON THE TYPE EXPECTED.
 
          GOTO(10000, 20000, 30000, 40000), TYPE(MVAL)
 
            WRITE(STDERR,51) TYPE(MVAL)
            STOP
 
10000       CONTINUE
C             EXPECTING AN INTEGER VALUE
              IF(ITMSTA.NE.INTEGER) THEN
                WRITE(STDERR,52) ITEM(1:ITML)
                EFLAG = 1
                WRITE(STDERR,56) LINE(1:len_trim(line))
                WRITE(STDERR,*) ' '
              ELSE
                READ(ITEM(1:ITML),'(I10)') IVAL(MVAL)
              ENDIF
              GOTO 70000
 
20000       CONTINUE
C             Expecting a real value.  Accept INTEGER and SINGLE3

              IF(ITMSTA.EQ.INTEGER.OR.ITMSTA.EQ.SINGLE3) THEN
                READ(ITEM(1:ITML),'(F20.0)') RVAL(MVAL)
              ELSE
                WRITE(STDERR,53) ITEM(1:ITML)
                EFLAG = 1
                WRITE(STDERR,56) LINE(1:len_trim(line))
                WRITE(STDERR,*) ' '
              ENDIF
              GOTO 70000
 
30000       CONTINUE
C             EXPECTING A DOUBLE PRECISION VALUE.  ACCEPT ANYTHING
C             BUT AN IDENTIFIER
              IF(ITMSTA.EQ.IDENTIFIER) THEN
                WRITE(STDERR,53) ITEM(1:ITML)
                EFLAG = 1
                WRITE(STDERR,56) LINE(1:len_trim(line))
                WRITE(STDERR,*) ' '
              ELSE
                READ(ITEM(1:ITML),'(D20.0)') DPVAL(MVAL)
              ENDIF
              GOTO 70000
 
40000       CONTINUE
C             EXPECTING AN IDENTIFIER.  ACCEPT ANYTHING BUT WRITE
C             A WARNING IF IT IS NOT AN IDENTIFIER.
              IF(ITMSTA.NE.IDENTIFIER) THEN
                WRITE(STDERR,54) ITEM(1:ITML)
                WRITE(STDERR,56) LINE(1:len_trim(line))
                WRITE(STDERR,*) ' '
              ENDIF
              CVAL(MVAL) = ITEM
              CLEN(MVAL) = ITML
              GOTO 70000
 
70000     CONTINUE
        ENDIF
        IF(EOS.EQ.1) RETURN
        GOTO 99999
 
        END
C
C
C
      SUBROUTINE   INLINE
     I                   (IN, OUT,
     O                    LINE)
 
C     + + + PURPOSE + + +
C     Function to read lines from the input, detect comments, 
C     and return only valid input lines to the point of call.
C     This routine treats blank lines like echoing comments.
 
C     Jan. 8, 2002: Experiment with a generic-length string 
C     to see how well it works.  

      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IN, OUT
      CHARACTER LINE*(*)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     OUT    - unit number for output
C     LINE   - buffer for an input line

C     Local

      INTEGER N
 
C     + + + SAVED VALUES + + +
      CHARACTER INONLY*1, INOUT*1, PLUS*1, BLINE*80

      SAVE INONLY, INOUT, PLUS, BLINE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA INOUT/'*'/, PLUS/'+'/, INONLY/';'/,BLINE/' '/

C     Called program units

      EXTERNAL FILTER_CR
C***********************************************************************
 100  CONTINUE
        READ(IN,'(A)',END=200) LINE
        CALL FILTER_CR(
     M                 LINE)

        IF(LINE(1:1).EQ.INOUT.OR.LINE(1:1).EQ.PLUS) THEN
C         OUTPUT THE LINE AND GO BACK AND GET NEXT LINE
          N = LEN_TRIM(LINE)
          WRITE(OUT,'(1X,A)') LINE(1:N)
          GOTO 100
        ELSEIF(LINE.EQ.BLINE) THEN
C         Treat a blank line as an echoing comment
          WRITE(OUT,'(1X,A1)') ' '
          GOTO 100
        ELSEIF(LINE(1:1).NE.INONLY) THEN
C         LINE IS NOT BLANK AND NOT A COMMENT.  RETURN THE LINE TO
C         THE POINT OF CALL.
 
          RETURN
        ENDIF
 
      GOTO 100
 
 200  CONTINUE
        LINE = 'ENDFILE'
        RETURN
 
      END
C     ***********
C     *         *
C     * INITIALIZE_UNITS
C     *         *
C     ***********

      SUBROUTINE INITIALIZE_UNITS

C     Set the unit number common block values to their default
C     values.  Unit numbers 5 and 6 are not used in any case
C     to avoid what seemed to be unavoidable confusion on some
C     Unix systems where these units were tied to console input
C     and console output and that connection could not be
C     changed.

      INCLUDE 'forunit.cmn'

C     Local

      INTEGER I
C***********************************************************************
      DO 100 I=1,DIM_UNIT
        UNIT_STATUS(I) = 0
100   CONTINUE
C     Mark units 5 and 6 as not available ever.
      UNIT_STATUS(5) = -1
      UNIT_STATUS(6) = -1

C     Set the value of the current unit count.  DOES not include
C     the never used units. 
      UNIT_KNT = 0
      RETURN
      END
C     ***********
C     *         *
C     * GET_UNIT
C     *         *
C     ***********

      INTEGER FUNCTION GET_UNIT (STDOUT)

C     Get a unit number for Fortran I/O.

      INTEGER STDOUT

      INCLUDE 'forunit.cmn'

C     Local

      INTEGER I
C     *********************************FORMATS**************************
50    FORMAT(/,' *ERR:XXX* I/O unit numbers exhausted.')
C***********************************************************************
      DO 100 I=1,DIM_UNIT
        IF(UNIT_STATUS(I).EQ.0) THEN
C         Found one!
          GET_UNIT = I
          UNIT_KNT = UNIT_KNT + 1
C         Mark unit as in use for Fortran I/O
          UNIT_STATUS(I) = FORTRAN_IO
          GOTO 110
        ENDIF
100   CONTINUE
C     If we get here then there are no unit numbers left.  This is
C     a fatal error. 
      WRITE(STDOUT,50) 
      STOP 'Abnormal stop: errors found.'

110   CONTINUE
      RETURN
      END      

C     ***********
C     *         *
C     * FREE_UNIT
C     *         *
C     ***********

      SUBROUTINE FREE_UNIT(STDOUT, UNIT)

C     Free an I/O unit number.  This also implies closing the
C     associated file, if any. 

      INTEGER STDOUT, UNIT

      INCLUDE 'forunit.cmn'

C     *****************************Formats******************************
50    FORMAT(/,' *BUG:XXX* Unit=',I5,' out of range in FREE_UNIT.')
52    FORMAT(/,' *BUG:XXX* Unit=',I5,' was not in use in FREE_UNIT.')
C************************************************************************
      IF(UNIT.LE.0.OR.UNIT.GT.DIM_UNIT) THEN
        WRITE(STDOUT,50) UNIT
        STOP 'Abnormal stop: bug found.'
      ELSEIF(UNIT_STATUS(UNIT).LE.0) THEN
        WRITE(STDOUT,52) UNIT
        STOP 'Abnormal stop: bug found.'
      ELSE
C       UNIT appears to be valid.  Close the file if it is for
C       Fortran I/O.
        IF(UNIT_STATUS(UNIT).EQ.FORTRAN_IO) THEN
 
          CLOSE(UNIT)
        
C         Free for use later.
          UNIT_STATUS(UNIT) = 0
        ELSE
C        For now do nothing. 
        ENDIF
      ENDIF
      RETURN
      END        
C     ***********
C     *         *
C     * TSFUTL  *
C     *         *
C     ***********

C     Utility program to do a variety of operations on Time Series 
C     files in support of unsteady flow simulation using FEQ.
C     This program will have a command structure similar in 
C     concept to FEQUTL but with some extensions. 

c     Starting 8 January 2005:  This version will update 
c     sequential unformatted files used in FEQ at and before 
c     version 10.17.  However, all other operations assume that
c     the tsf's involved are stored in the unformatted direct-access
c     structure used for versions of FEQ following version 10.17.

      implicit none

      CHARACTER*128 FNAME1, FNAME2
      CHARACTER LINE*192, LINE2*194

      LOGICAL THERE
      
      INTEGER IOFLAG, MORG, STDIN, STDOUT, MAX_NVAL

      PARAMETER (MAX_NVAL=40)

      INTEGER  CHRVAL, INTVAL, REAVAL, DPRVAL
      PARAMETER(INTVAL=1, REAVAL=2, DPRVAL=3, CHRVAL=4)


      INTEGER EFLAG, MVAL, NVAL, OPT, I, IFIRST, CL, narg
      
      INTEGER CLEN(MAX_NVAL), IVAL(MAX_NVAL), TYPE(MAX_NVAL),
     A        TERML(MAX_NVAL), TERMCLS(MAX_NVAL)
      REAL RVAL(MAX_NVAL)
      DOUBLE PRECISION DPVAL(MAX_NVAL)
      CHARACTER CVAL(MAX_NVAL)*256, TERM(MAX_NVAL)*1, COMMAND*64

      INCLUDE 'stdun.cmn'

C     Program units.

      INTEGER GET_UNIT, IARGC, INDEX

      INTRINSIC INDEX
      EXTERNAL GET_UNIT, IARGC, GETARG, INITIALIZE_UNITS, 
     A         MERGE, DELETE, GET
C     ***********************Formats************************************
50    FORMAT('*ERR:XXX* Value of MORG wrong in TSFUTL. Must be 0 or 1.')
54    FORMAT(1X,A)
56    FORMAT(/,' *ERR:XXX* Command:',A,' unknown.')
58    FORMAT(/,' Utility for Time Series Files',/,
     A         ' Version: 1.0 Beta',/,
     B         ' 12 January, 2005')
C***********************************************************************
      
C     Set the command line argument offset.  This must be zero
C     for UNIX systems

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
        WRITE(*,*) 'Too few arguments'
        WRITE(*,*) ' Give the input file name and the output file name'
        WRITE(*,*) ' after the command name with spaces used as'
        WRITE(*,*) ' seperaters like this: TSFUTL INPUT OUTPUT'
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
C     GET THE FIRST FILE ARGUMENT
 
      CALL GETARG (1+MORG,
     O            FNAME1)
 
      INQUIRE(FILE=FNAME1, EXIST=THERE)
      IF(THERE) THEN
        OPEN(STDIN, FILE = FNAME1, STATUS = 'OLD')
      ELSE
        WRITE(*,*) 
     a     ' File named:',FNAME1(1:len_trim(fname1)),' not found.'
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
        WRITE(*,*) 
     a    ' Problem in opening file: ',FNAME2(1:len_trim(fname2))
        WRITE(*,*) ' Check path for output file.'
        STOP 'Abnormal stop: errors found.'
      ENDIF


      WRITE(STDOUT,58)
      WRITE(STDOUT,*) ' '

C     Now that we have the files opened and they seem to exist,
C     we can start processing the input.  To that end, start
C     reading lines, skipping blank lines, and searching for
C     the next command. Note that inline takes care of comment
C     lines and echos blank lines to the output file.  We only see
C     non-comment and non-blank lines here.  

C     Set the option flag for subroutine GETVAL to return values
C     found as character strings with a code giving the type
C     of value in the string. 

      OPT = 1
      NVAL = MAX_NVAL
100   CONTINUE

        CALL inline (STDIN, STDOUT,
     O              LINE)

        WRITE(STDOUT,54) LINE(1:len_trim(line))

        LINE2 = LINE
        call maybe_add_quote(
     m                         line2)
c       Parse the contents of the current line of input. 
        CALL GETVAL(STDOUT, LINE2, NVAL, OPT,
     O               TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG,
     O               TERM, TERML, TERMCLS, MVAL)


C        CALL DUMP_FINDINGS(STDOUT, MVAL, TYPE, CLEN, 
C     I                         TERM, TERMCLS, CVAL)

C       Select further action based on the first character 
C       response found in the returned values. 
        IFIRST = 1
        CALL FIND_NEXT_CHARACTER_STRING(MVAL, TYPE,
     M                                      IFIRST)

        IF(IFIRST.EQ.0) THEN
          WRITE(STDOUT,*) ' No command found in line.'
          STOP ' Abnormal stop.  Errors found.'
        ENDIF



        COMMAND = CVAL(IFIRST)
        CL = CLEN(IFIRST)
        IF(COMMAND(1:CL).EQ.'UPDATE') THEN
          IFIRST = IFIRST + 1
          CALL UPDATE(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 
        ELSEIF(COMMAND(1:CL).EQ.'DUMP') THEN
          IFIRST = IFIRST + 1
          CALL DUMP(STDIN, STDOUT, IFIRST, NVAL, 
     M              MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M              TERM, TERML, TERMCLS, 
     O              EFLAG) 

        ELSEIF(COMMAND(1:CL).EQ.'GET') THEN
          IFIRST = IFIRST + 1
          CALL GET(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 

        ELSEIF(COMMAND(1:CL).EQ.'PRINT') THEN
          IFIRST = IFIRST + 1
          CALL PRINT(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 
        ELSEIF(COMMAND(1:CL).EQ.'RESTORE') THEN
          IFIRST = IFIRST + 1
          CALL RESTORE(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 

        ELSEIF(COMMAND(1:CL).EQ.'DELETE') THEN
          IFIRST = IFIRST + 1
          CALL DELETE(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 


        ELSEIF(COMMAND(1:CL).EQ.'MERGE') THEN
          IFIRST = IFIRST + 1
          CALL MERGE(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 

        elseif(command(1:cl).eq.'SMOOTH') then
          IFIRST = IFIRST + 1
          CALL smooth(STDIN, STDOUT, IFIRST, NVAL, 
     M                 MVAL, TYPE, CVAL, CLEN, IVAL, RVAL, DPVAL, 
     M                 TERM, TERML, TERMCLS, 
     O                 EFLAG) 

        ELSEIF(COMMAND(1:CL).EQ.'FINISH') THEN
          GOTO 90000
        ELSE
          WRITE(STDOUT,56) COMMAND
          STOP 'Abnormal stop.  Errors found.'
        ENDIF        

        GOTO 100


90000 CONTINUE

      CALL FREE_UNIT(STDOUT, STDIN)
      CALL FREE_UNIT(STDOUT, STDOUT)


      STOP 'Normal stop'
      END
