c     Program units relating to processing of home names

c
c
c
      subroutine maybe_add_ext(
     m                          name)

c     if stdext is non-blank, add it to the end of name as 
c     an additional extension. The standard extension is 
c     already stored with a leading period. 
      IMPLICIT NONE

      CHARACTER*(*) NAME

      INCLUDE 'home.cmn'

c     Local
      integer i, iend
      character*128 ext

c***********************************************************************
      if(name /= ' ') then
        if(stdext /= ' ') then
c         Cut the last extension from name, including the period, 
c         then add the standard extension from the master-output file, 
c         and then add in the original extension
          iend = len_trim(name)
          do i=iend,1,-1
            if(name(i:i) == '.') then
              exit
            endif
          end do 
          if(i > 1) then
c           There was a period found during the reverse search. Thus name 
c           had an extension
            ext = name(i:iend)
c           In at least one case, special output file, it is possible that 
c`          the information file already has the master-output file extension
c           added.  This may well happen in the future.  Thus, take action here
c           to prevent such duplication.  If the master-output file extension
c           is already present, we should then find it at the end 
c           of name(1:i-1). 
            iend = len_trim(stdext)
            if(name(i-1-iend+1:i-1) /= stdext) then
              name = name(1:i-1)//trim(stdext)//trim(ext)
            else
              name = name(1:i-1)//trim(ext)
            endif  
          else
c           No period was found.  We exclude an initial period in a name.  Such
c           a period does not denote an extension but is part of the file name.
            name = trim(name)//trim(stdext) 
          endif
        endif
      endif
      return
      end
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
      CHARACTER*256 TEMP_LINE
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
c           Check to see if a home name already exists at
c           the start of the file name.  It is invalid to have
c           a home name appear twice.  It is also assumed that the 
c           style will be identical. 
            if(home(1:n) /= name(1:n)) then
              TEMP_LINE = HOME(1:N)//NAME
              NAME = TEMP_LINE
            endif
          else
            !There is a leading slash but the home name is blank.
            !This does not make sense.  Therefore strip the leading slash
            ! and return a name that will be opened in the local diretory.
            name = name(2:)
          ENDIF
        ENDIF
      ENDIF
      RETURN
      END
C
C
C
      SUBROUTINE MAYBE_ADD_GHOME_OUT(
     M                             NAME)

C     Add output home name to front of file names that start with 
C     a / or \ but only if GHOME_OUT is not blank.

      IMPLICIT NONE

      CHARACTER*(*) NAME

      INCLUDE 'home.cmn'

C     Called program units
     
C     Local
      INTEGER N
      CHARACTER*256 TEMP_LINE
C***********************************************************************
      IF(NAME.NE.' ') THEN
        name = adjustl(name)

        IF(NAME(1:1).EQ.'/'.OR.NAME(1:1).EQ.'\') THEN
          IF(GHOME_OUT  /= ' ') THEN
            N = LEN_TRIM(GHOME_OUT)
c           Check to see if a home name already exists at
c           the start of the file name.  It is invalid to have
c           a home name appear twice.  It is also assumed that the 
c           style will be identical. 
            if(ghome_out(1:n) /= name(1:n)) then
              TEMP_LINE = GHOME_OUT(1:N)//NAME
              NAME = TEMP_LINE
            endif
          else
            !GHOME is blank but yet we have a leading slash.  Does
            !not make sense.  Strip the leading slash.                                                        
            name = name(2:)
          ENDIF
        ENDIF
      ENDIF
      RETURN
      END

C
C
C
      SUBROUTINE CLEAR_HOME()

C     Clear the Local HOME part of file names. 

      IMPLICIT NONE

      INCLUDE 'home.cmn'
C***********************************************************************
      HOME = ' '
      RETURN
      END
C
C
C
      SUBROUTINE CLEAR_GHOME_OUT()

C     Clear the global output home name

      IMPLICIT NONE

      INCLUDE 'home.cmn'
C***********************************************************************
      GHOME_OUT = ' '
      RETURN
      END
C
C
C
      SUBROUTINE CLEAR_ext()

C     Clear the standard output extension 

      IMPLICIT NONE

      INCLUDE 'home.cmn'
C***********************************************************************
      stdext = ' '
      RETURN
      END
C
C
C
      SUBROUTINE SET_HOME(LHOME)

C     Set the Local HOME part of file names. 

      IMPLICIT NONE
      CHARACTER*(*) LHOME

      INCLUDE 'home.cmn'
C***********************************************************************
      HOME = LHOME
      RETURN
      END



