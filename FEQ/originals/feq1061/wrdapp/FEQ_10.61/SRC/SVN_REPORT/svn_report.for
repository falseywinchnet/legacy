c     Subroutine that will report selected items
c     to an output file from an included file so 
c     that we can compile software and have it 
c     report its own repository location and revision
c     number.

      subroutine svn_report(stdout, stdtab)

      implicit none

      integer stdout, stdtab


      include 'svn.cmn'

c     Local
      integer it

      include 'include.out'

c     ***************************Formats********************************
50    format('; Source code repository location and revision are:')
52    format(';',5x,a)
c***********************************************************************
      url = urla          !Circumvent block data mess in Fortran:)
      revision = revisiona
      write(stdout,50) 
      it = len_trim(url)
      write(stdout,52) url(1:it)
      it = len_trim(revision)
      write(stdout,52) revision(1:it)

      if(stdtab > 0) then
        write(stdtab,50) 
        it = len_trim(url)
        write(stdtab,52) url(1:it)
        it = len_trim(revision)
        write(stdtab,52) revision(1:it)
      endif
      return
      end

