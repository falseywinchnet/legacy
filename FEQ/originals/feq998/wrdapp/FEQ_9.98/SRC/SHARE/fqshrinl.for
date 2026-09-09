C
C
C
      SUBROUTINE   INL80B
     I                  (IN, OUT,
     O                   LINE)
 
C     + + + PURPOSE + + +
C     Function to read lines from the input, detect comments, 
C     and return only valid input lines to the point of call.
C     This routine returns a blank line as a valid input line.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IN, OUT
      CHARACTER LINE*80
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     OUT    - unit number for output
C     LINE   - buffer for an input line
 
C     Local 

      INTEGER N

C     + + + SAVED VALUES + + +
      CHARACTER INONLY*1, INOUT*1, PLUS*1

      SAVE INONLY, INOUT, PLUS
 
C     + + + DATA INITIALIZATIONS + + +
      DATA INOUT/'*'/, PLUS/'+'/, INONLY/';'/

C     Program units called.

      EXTERNAL  FILTER_CR
C***********************************************************************
 100  CONTINUE
        READ(IN,'(A80)',END=200) LINE
        CALL FILTER_CR(
     M                LINE)
        IF(LINE(1:1).EQ.INOUT.OR.LINE(1:1).EQ.PLUS) THEN
C         OUTPUT THE LINE AND GO BACK AND GET NEXT LINE
          N = LEN_TRIM(LINE)
          WRITE(OUT,'(1X,A)') LINE(1:N)
          GOTO 100
        ELSEIF(LINE(1:1).NE.INONLY) THEN
C         LINE IS NOT A COMMENT.  RETURN THE LINE TO
C         THE POINT OF CALL.
 
          RETURN
        ENDIF
      GOTO 100
 200  CONTINUE
        LINE = 'ENDFILE'
        RETURN
 
      END
C
C
C
      SUBROUTINE   INL112
     I                   (IN, OUT,
     O                    LINE)
 
C     + + + PURPOSE + + +
C     Function to read lines from the input, detect comments, 
C     and return only valid input lines to the point of call.
C     This routine treats blank lines like echoing comments.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IN, OUT
      CHARACTER LINE*112
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     OUT    - unit number for output
C     LINE   - buffer for an input line
 
C     Local 

      INTEGER N

C     + + + SAVED VALUES + + +
      CHARACTER INONLY*1, INOUT*1, PLUS*1, BLINE*112
      SAVE INONLY, INOUT, PLUS, BLINE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA INOUT/'*'/, PLUS/'+'/, INONLY/';'/, BLINE/' '/

C     Program units called.

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
C         Treat a blank line as an echoing comment.
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
C
C
C
      SUBROUTINE   INL120
     I                   (IN, OUT,
     O                    LINE)
 
C     + + + PURPOSE + + +
C     Function to read lines from the input, detect comments, 
C     and return only valid input lines to the point of call.
C     This routine treats blank lines like echoing comments.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IN, OUT
      CHARACTER LINE*120
 
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
C         Treat a blank line as an echoing comment.
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
C
C
C
      SUBROUTINE   INL120B
     I                    (IN, OUT,
     O                     LINE)
 
C     + + + PURPOSE + + +
C     Function to read lines from the input, detect comments, 
C     and return only valid input lines to the point of call.
C     This routine treats blank lines as valid input lines.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IN, OUT
      CHARACTER LINE*120
 
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

      EXTERNAL  FILTER_CR
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
C         Treat a blank line as an input line.
         
          RETURN
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
C
C
C
      SUBROUTINE   INL196
     I                   (IN, OUT,
     O                    LINE)
 
C     + + + PURPOSE + + +
C     Function to read lines from the input, detect comments, 
C     and return only valid input lines to the point of call.
C     This routine treats blank lines like echoing comments.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IN, OUT
      CHARACTER LINE*196
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     OUT    - unit number for output
C     LINE   - buffer for an input line
 
C     Local 

      INTEGER N

C     + + + SAVED VALUES + + +
      CHARACTER INONLY*1, INOUT*1, PLUS*1, BLINE*196
      SAVE INONLY, INOUT, PLUS, BLINE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA INOUT/'*'/, PLUS/'+'/, INONLY/';'/, BLINE/' '/

C     Program units called.

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
C         Treat a blank line as an echoing comment.
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
C
C
C
      SUBROUTINE   INL196_ALL
     I                   (IN,
     O                    LINE)
 
C     + + + PURPOSE + + +
C     Function to read lines from the input, returning all
C     lines.  Only strip carriage returns if found so that
C     un-recoded files from MS can be read in Linux!
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IN
      CHARACTER LINE*196
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     LINE   - buffer for an input line
 
C     Local 

      INTEGER N

C     Program units called.

      EXTERNAL FILTER_CR
C***********************************************************************
      READ(IN,'(A)',END=200) LINE
      CALL FILTER_CR(
     M               LINE)
      RETURN
 
 200  CONTINUE
        LINE = 'ENDFILE'
        RETURN
      END
C
C
C
      SUBROUTINE   INL80
     I                  (IN, OUT,
     O                   LINE)
 
C     + + + PURPOSE + + +
C     Function to read lines from the input, detect comments, 
C     and return only valid input lines to the point of call.
C     This routine treats blank lines like echoing comments.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IN, OUT
      CHARACTER LINE*80
 
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
        READ(IN,'(A80)',END=200) LINE
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
