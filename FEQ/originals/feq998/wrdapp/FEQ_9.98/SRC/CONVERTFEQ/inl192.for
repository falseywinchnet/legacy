C
C
C
      SUBROUTINE   INL192
     I                   (IN, OUT,
     O                    LINE)
 
C     + + + PURPOSE + + +
C     Function to read lines from the input, detect comments, 
C     and return only valid input lines to the point of call.
C     This routine treats blank lines like echoing comments.
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IN, OUT
      CHARACTER LINE*192
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     OUT    - unit number for output
C     LINE   - buffer for an input line
 
C     Local 

      INTEGER N

C     + + + SAVED VALUES + + +
      CHARACTER INONLY*1, INOUT*1, PLUS*1, BLINE*120
      SAVE INONLY, INOUT, PLUS, BLINE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA INOUT/'*'/, PLUS/'+'/, INONLY/';'/, BLINE/' '/

C     Program units called.

      INTEGER LENSTR
      EXTERNAL LENSTR
C***********************************************************************
 100  CONTINUE
        READ(IN,'(A)',END=200) LINE
        IF(LINE(1:1).EQ.INOUT.OR.LINE(1:1).EQ.PLUS
     A        .OR.LINE(1:1).EQ.INONLY) THEN
C         OUTPUT THE LINE AND GO BACK AND GET NEXT LINE
          N = LENSTR(LINE)
          WRITE(OUT,'(A)') LINE(1:N)
          GOTO 100
        ELSEIF(LINE.EQ.BLINE) THEN
C         Treat a blank line as an echoing comment.
          WRITE(OUT,'(A1)') ' '
          GOTO 100
        ELSE
C         LINE IS NOT BLANK AND NOT A COMMENT.  RETURN THE LINE TO
C         THE POINT OF CALL.
 
          RETURN
        ENDIF
 
      GOTO 100
 
 200  CONTINUE
        LINE = 'ENDFILE'
        RETURN
      END
