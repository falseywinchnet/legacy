c
c 
c 
      subroutine getsvn_rev(stdout, home_dir,
     o                      svn_rev, svn_mod)

c     Given a home directory name for input files:
c     1. Check if the directory is under Subversion
c     2. Run svnversion on the home directory and 
c       save its output.
c        
c     3. Open the temp file and read its contents:
c        the response can be:
c        3.1 a single integer-the latest revision number
c        3.2 a single integer followed by M or S or both
c        3.3 two integers with a colon between.  Gives the
c            range of revisions in the working copy with 
c            the larger number given last.
c        3.4 range of revisions followed by M or S or both. 
c 
c     We want to do:
c       1.1 extract the larger of the two revision numbers
c       1.2 note if an M is present and if so we write 
c           a warning message that there are uncommitted 
c           changes in the working copy.  Therefore, the
c           revision number DOES NOT fully specify the 
c           file status for this current run.  
c       1.3 Return the revision number. 

      implicit none

      integer stdout, svn_rev, svn_mod

      character*(*) home_dir

      integer system, get_unit
      external  get_unit
      intrinsic system

c     Local

      integer i, it, stdun, mflag

      character*256 temp

c     *******************************Formats****************************
50    format(/,' Version number is ',i8,' for the Subversion working ',
     a         'copy') 
52    format(/,'*WRN:XXX* The working copy contains local ',
     a 'modifications.', /,5x,' The version number given is therefore',
     b' not current and may not properly',/,5x,' provide the version',
     c' number required to retrieve all the same files ',
     d'at a later time.')
54    format(/,' Project not under Subversion version control.')
56    format(/,'*ERR:XXX Working directory is under Subversion but',
     a ' the command-line command: svnversion is not available.',/,
     b 5x,'Skipping any attempt at finding the version number.',
     c 5x,' Consult file:svn.zxcv_ in current working directory for',
     c ' details')
c***********************************************************************
      mflag = 0
      svn_rev = 0
      svn_mod = 0
      it = len_trim(home_dir)
      temp = home_dir(1:it)//'\.svn'
      it = len_trim(temp)
      if(system('dir -d '//temp//' > svn.zxcv_ 2>&1') /= 0) then
c       The home directory is under subversion.  Run svnversion and 
c       get the info on the versions
        it = len_trim(home_dir)
        i  =system('svnversion '//home_dir//' > svn.zxcv_ 2>&1')
        if(i /= 0) then
c         Some sort of error.  Command-line subversion may not be installed
          write(stdout,54)
        else  
          stdun = get_unit(stdout)        
          open(unit=stdun, file='svn.zxcv_',status='old')
          read(stdun,'(a)') temp
          it = len_trim(temp)
          if(temp(it:it) == 'S') then
c           Ignore switched state for now.
            it = it - 1
          endif
          if(temp(it:it) == 'M') then
            mflag = 1
            it = it -1
          endif
c         Check if there is still an S left.
          if(temp(it:it) == 'S') then
            it = it - 1
          endif

c         We should have only integers and perhaps a colon
c         left in the string:)
          i = index(temp,':')
          if(i == 0) then
c           No colon--should be only a single integer
            read(temp(1:it),'(i8)') svn_rev
          else
c           There is a colon.  Read the integer after it.
            read(temp(i+1:it),'(i8)') svn_rev
          endif
        endif
        call free_unit(stdout, stdun)
        i = system('del /q svn.zxcv_ > NUL 2>&1')
      endif
      if(svn_rev > 0 ) then
        write(stdout,50) svn_rev
        write(*,50) svn_rev
        if(mflag > 0) then
          svn_mod = 1
          write(stdout,52) 
          write(*,52)
        endif
      else
        write(stdout, 54)
        write(*,54)
      endif
      return
      end
        

