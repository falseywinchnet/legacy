c
c 
c 
      subroutine pwd(
     o               cwd_path)

c     Find the path to the current working directory.
c     For lf95 under MSW.  

      implicit none
      character*(*) cwd_path

      integer get_unit
      external get_unit, free_unit
     

c     Local
      integer stddum, it
c***********************************************************************
      call system('cd > pwd.pwd')
      stddum = get_unit(0)
      open(unit=stddum, file='pwd.pwd', status='old')
      read(stddum,'(a)') cwd_path
      close(unit=stddum, status='delete')
      return
      end



      



