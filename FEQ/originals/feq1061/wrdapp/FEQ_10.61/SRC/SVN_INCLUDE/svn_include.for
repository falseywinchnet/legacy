c     Program to read various files created by the command line
c     use of subversion and  create a file to be included
c     in a special Fortran subroutine that will report selected
c     items to one or more output files.  Needed to establish the
c     precise set of software that was used to create one or 
c     more output files.

      program svn_include

      implicit none

      integer stdin, stdstatus, stdinfo, stdupdate, it,
     a         stdinclude

      logical there

      character*32  status, info, update, revnum

      character*256 line

c     ******************************Formats*****************************
50    format(6x,'data urla/',/,5x,'a',"'",a,"'",'/')
52    format(6x,'data revisiona/',/,5x,'a',"'",a,"'",'/')
c***********************************************************************
      stdin = 2
      stdstatus = 8
      stdinfo = 10
      stdupdate = 12
      stdinclude = 14

c     All output will be to standard output which is the screen--we hope

      inquire(file='status.out', exist=there)
      if(there) then
        open(stdstatus, file='status.out', status='old')
      else
        write(*,*) 'File: status.out not found. Must halt.'
        stop 'Missing file'
      endif

      inquire(file='update.out', exist=there)
      if(there) then
        open(stdupdate, file='update.out', status='old')
      else
        write(*,*) 'File: update.out not found. Must halt.'
        stop 'Missing file'
      endif

      inquire(file='info.out', exist=there)
      if(there) then
        open(stdinfo, file='info.out', status='old')
      else
        write(*,*) 'File: info.out not found. Must halt.'
        stop 'Missing file'
      endif


c     Check on the status of the working copy.
      do
        read(stdstatus,'(a)', end=100) line
        if(line(1:1) == 'M') then
c         Check if it is a recent exe or lx file.  If so, 
c         let it pass because we are recompiling it, maybe!
          it = len_trim(line)
          if(line(it-3:it) == '.exe' .or. line(it-2:it) == '.lx') then

          else
            write(*,*) 'Local changes not committed. Please commit'
            stop 'Uncommitted changes not allowed'
          endif
        elseif(line(1:1) == 'A') then
c         Check if it is a recent exe or lx file.  If so, 
c         let it pass because we are recompiling it, maybe!
          it = len_trim(line)
          if(line(it-3:it) == '.exe' .or. line(it-2:it) == '.lx') then

          else
            write(*,*) 'Local changes not committed. Please commit'
            stop 'Uncommitted changes not allowed'
          endif
        endif
      enddo

100   continue

c     We have passed the check for outstanding local changes. 
c     Use the contents of info.out to create an include file. 

      open(stdinclude, file='include.out', status='unknown')

      write(stdinclude,"(7x,'character*256 urla, revisiona')")
      do
        read(stdinfo,'(a)') line
        if(line(1:4) == 'URL:') then
          it = len_trim(line)
          write(stdinclude,50) line(1:it)
        endif
        if(line(1:9) == 'Revision:') then
          revnum = line(10:it)
          it = len_trim(revnum)
          write(stdinclude, 52) 'Rev:'//revnum(1:it)
          exit
        endif

      enddo

      close(stdstatus)
      close(stdinfo)
      close(stdupdate)
      close(stdinclude)
        
      stop
      end


      
