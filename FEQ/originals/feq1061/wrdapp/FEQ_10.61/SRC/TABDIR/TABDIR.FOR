C     ***********
C     *         *
C     * INL112
C     *         *
C     ***********

      SUBROUTINE   INL112
     I                   (IN,
     O                    LINE)
 
C     + + + PURPOSE + + +
C     Read lines and return only non-comments.  No echo of the 
C     line.
C     + + + DUMMY ARGUMENTS + + +
      INTEGER IN
      CHARACTER LINE*112
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     IN     - unit number for the user input file
C     LINE   - buffer for an input line
 
C     + + + SAVED VALUES + + +
      CHARACTER INONLY*1, INOUT*1, PLUS*1, BLINE*112
      SAVE INONLY, INOUT, PLUS, BLINE
 
C     + + + DATA INITIALIZATIONS + + +
      DATA INOUT/'*'/, PLUS/'+'/, INONLY/';'/, BLINE/' '/
C     + + + END SPECIFICATIONS + + +
 100  CONTINUE
        READ(IN,'(A)',END=200) LINE
        IF(LINE(1:1).EQ.INOUT.OR.LINE(1:1).EQ.PLUS) THEN
C         OUTPUT THE LINE AND GO BACK AND GET NEXT LINE
          GOTO 100
        ELSEIF(LINE.EQ.BLINE) THEN
C         Treat a blank line as an echoing comment.
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
C     **************
C     *            *
C     *  QSRTIA    *
C     *            *
C     **************
  
      SUBROUTINE QSRTIA(A, AI, AII, N)
  
C     THIS IS ACENDING ORDER
C 
C       THIS IS A VERY FAST SUBROUTINE FOR SORTING AN INTEGER  ARRAY IN
C       ASCENDING ORDER. THIS PROGRAM IS A TRANSLATION INTO
C       FORTRAN IV OF ALGORITHM 271, QUICKERSORT, BY R.S. SCOWEN IN
C       COLLECTED ALGORITHMS OF THE ACM. CONSULT THIS FOR FURTHER
C       REFERENCES.
C 
C       PARAMETERS:
C            A           INTEGER ARRAY         ON INPUT THIS IS THE
C                                              ARRAY TO BE SORTED.
C                                              ON OUTPUT THIS IS THE
C                                              SORTED ARRAY.

C            AI          INTEGER ARRAY         On input this array
C                                              gives user defined
C                                              indices.  These are
C                                              kept in order with
C                                              the elements of A
C                                              as it is sorted.

C            AII         INTEGER ARRAY         On input this array
C                                              gives user defined
C                                              indices.  These are
C                                              kept in order with
C                                              the elements of A
C                                              as it is sorted.

C            N           INTEGER*4             THE  DIMENSION OF THE
C                                              ARRAY A.
C 
C       THE METHOD IS USED IS THAT OF CONTINUALLY SPLITTING THE ARRAY
C       INTO PARTS SUCH THAT ALL ELEMENTS OF ONE PART ARE LESS THAN
C       ALL ELEMENTS OF THE OTHER, WITH A THIRD PART IN THE MIDDLE
C       CONSISTING OF ONE ELEMENT.
C           AN ELEMENT WITH VALUE T IS CHOSEN ARBITRARILY (HERE WE
C       CHOOSE THE  MIDDLE ELEMENT). I AND J GIVE THE LOWER AND
C       UPPER LIMITS OF THE SEGMENT BEING SPLIT. AFTER THE SPLIT A
C       VALUE Q WILL HAVE BEEN FOUND SUCH THAT A(Q)=T AND
C       A(L)<=T<=A(M) FOR ALL I<=L<Q<M<=J. THE PROGRAM THEN PERFORMS
C       OPERATIONS ON THE TWO SEGMENTS (I,Q-1) AND (Q+1,J) AS FOLLOWS.
C       THE SMALLER SEGMENT IS SPLIT AND THE POSITION OF THE LARGER
C       SEGMENT IS STORED IN THE LT AND UT ARRAYS. IF THE SEGMENT TO
C       BE SPLIT CONTAINS TWO OR FEWER ELEMENTS, IT IS SORTED AND
C       ANOTHER SEGMENT IS OBTAINED FROM THE LT AND UT ARRAYS. WHEN
C       NO MORE SEGMENTS REMAIN, THE ARRAY IS COMPLETELY SORTED.
C 
C 
      INTEGER N, AI(N), AII(N)
      INTEGER LT(32), UT(32), I, J, K, M, P, Q, TI, TII, XI
      CHARACTER*16 A(N), T, X
C       THE DIMENSIONS FOR LT AND UT HAVE TO BE AT LEAST LOG  N.
C                                                           2
C       32 WAS CHOSEN TO HANDLE N <4,294,967,297.  This should
C       do for most applications!
C 
      J=N
      M=1
      I=1
C 
C       IF THIS SEGMENT HAS MORE THAN TWO ELEMENTS  WE SPLIT IT
 10   IF (J-I-1) 100,90,15
C 
C       P IS THE POSITION OF AN ARBITRARY ELEMENT IN THE SEGMENT
C       WE CHOOSE THE MIDDLE ELEMENT. UNDER CERTAIN CIRCUMSTANCES
C       IT MAY BE ADVANTAGEOUS TO CHOOSE P AT RANDOM.
 15   P=(J+I)/2
      T=A(P)
      A(P)=A(I)
      TI = AI(P)
      AI(P) = AI(I)
      TII = AII(P)
      AII(P) = AII(I)
  
C 
C       STARTING AT THE BEGINNING OF THE SEGMENT, SEARCH FOR K
C       SUCH THAT A(K)>T
      Q=J
      K=I
 20   K=K+1
      IF (K.GT.Q) GO TO 60
       IF (A(K).LE.T) GO TO 20
C 
C        SUCH AN ELEMENT HAS NOW BEEN FOUND
C        NOW SEARCH FOR A Q SUCH THAT A(Q)<T STARTING AT THE END OF THE
C        SEGMENT.
 30    IF (A(Q).LT.T) GO TO 40
       Q=Q-1
       IF (Q.GT.K) GO TO 30
       GO TO 50
C 
C        A(Q) HAS NOW BEEN FOUND. WE INTERCHANGE A(Q) AND A(K)
 40    CONTINUE
       X=A(K)
       A(K)=A(Q)
       A(Q)=X
       XI=AI(K)
       AI(K)=AI(Q)
       AI(Q)=XI
       XI=AII(K)
       AII(K)=AII(Q)
       AII(Q)=XI
  
C 
C        UPDATE Q AND SEARCH FOR ANOTHER PAIR TO INTERCHANGE
       Q=Q-1
       GO TO 20
 50    Q=K-1
 60   CONTINUE

C        THE UPWARDS SEARCH HAS NOW MET THE DOWNWARDS SEARCH
      A(I)=A(Q)
      A(Q)=T
      AI(I) = AI(Q)
      AI(Q) = TI
      AII(I) = AII(Q)
      AII(Q) = TII

C       THE SEGMENT IS NOW DIVIDED IN THREE PARTS: (I,Q-1),(Q),(Q+1,J)
C       STORE THE POSITION OF THE LARGEST SEGMENT IN LT AND UT
      IF (2*Q.LE.I+J) GO TO 70
        LT(M)=I
        UT(M)=Q-1
        I=Q+1
      GO TO 80
 70     LT(M)=Q+1
        UT(M)=J
        J=Q-1

C       UPDATE M AND SPLIT THE NEW SMALLER SEGMENT
 80   M=M+1
      GO TO 10

C       WE ARRIVE HERE IF THE SEGMENT HAS  TWO ELEMENTS
C       WE TEST TO SEE IF THE SEGMENT IS PROPERLY ORDERED
C       IF NOT, WE PERFORM AN INTERCHANGE
 90   IF (A(I).LE.A(J)) GO TO 100
      X=A(I)
      A(I)=A(J)
      A(J)=X
      XI=AI(I)
      AI(I)=AI(J)
      AI(J)=XI
      XI=AII(I)
      AII(I)=AII(J)
      AII(J)=XI

C       IF LT AND UT CONTAIN MORE SEGMENTS TO BE SORTED REPEAT PROCESS
 100  M=M-1
      IF (M.LE.0) RETURN
      I=LT(M)
      J=UT(M)
      GO TO 10
      END
C     ***********
C     *         *
C     * TABDIR  *
C     *         *
C     ***********
  
  
      PROGRAM TABDIR
  
C     Contruct a directory list for FEQ function tables.
  
      LOGICAL THERE
  
      INTEGER  MAXTAB, MAXFILE, MORG
      PARAMETER (MAXTAB=10000, MAXFILE=500, MORG=1)
  
      INTEGER NUMBER_OF_TABLES, NUMBER_OF_FILES, NARG, IARGC,
     A        IN, LOUT, NXT, IOFLAG, I, IDSN, TYPE, LP, FP,
     B        TAB_FLAG
  
      INTEGER  FILE_NAME_POINTER(MAXTAB),
     A        TABLE_TYPE(MAXTAB), LABEL_POINTER(MAXTAB)
  
      CHARACTER*16 TABLE_ID(MAXTAB), TABID
      CHARACTER*80 TABLE_LABEL(MAXTAB)
  
      CHARACTER*112 LINE

      CHARACTER*128 FILE_NAME(MAXFILE), INPUT_NAME, DIRECTORY_NAME


      INTEGER LENSTR     
      EXTERNAL LENSTR, STRIP_L_BLANKS     
  
C     **************************FORMATS********************************
50    FORMAT(' TABLE ID          TYPE  File name/table label')
52    FORMAT(1X,A16,1X,I6,2X,A,/,27X,A)
C**********************************************************************
C
C     strings for Unix what command
      line =
     &'@(#)TABDIR - Convert FEQ input file to new network matrix format'
      line =
     &      '@(#)TABDIR - Franz, D.D., and Melching, C.S., WRIR 96-4240'
      line = '@(#)TABDIR - Contact: h2osoft@usgs.gov'
      line = '@(#)TABDIR - Version: 0.9 Beta 1998/06/04'
C     set string for use with RCS ident command
      line =
     &'$Id: tabdir.f,v 1.0 1998/06/04 19:16:54 rsregan Exp rsregan $'
C
      IN = 5
      LOUT = 6
      IDSN = 7
  
      IF(MORG.LT.0.OR.MORG.GT.1) THEN
        WRITE(*,*) ' MORG INVALID.  Must be 0 or 1.'
        STOP
      ENDIF
  
C     PROCESS COMMAND LINE ARGUMENTS
  
      NARG = 0
      NARG = IARGC()
C      WRITE(*,*) ' NARG=',NARG
      IF(NARG-MORG.LT.2) THEN
        WRITE(*,*) 'TOO FEW ARGUMENTS'
        WRITE(*,*) ' GIVE THE INPUT FILE NAME AND THE OUTPUT FILE NAME'
        WRITE(*,*) ' AFTER THE COMMAND NAME WITH SPACES USED AS'
        WRITE(*,*) ' SEPERATORS LIKE THIS: TABDIR INPUT OUTPUT'
        STOP
      ENDIF
  
C     GET THE FIRST FILE ARGUMENT
  
      CALL GETARG
     I           (1+MORG,
     O            INPUT_NAME)
  
      INQUIRE(FILE=INPUT_NAME, EXIST=THERE)
      IF(THERE) THEN
        OPEN(IN, FILE = INPUT_NAME, STATUS = 'OLD')
      ELSE
        WRITE(*,*) ' FILE NAMED:',INPUT_NAME,' NOT FOUND.'
        WRITE(*,*) ' PLEASE CHECK SPELLING OF FILE NAME USED.'
        STOP
      ENDIF
  
C     GET THE SECOND FILE ARGUMENT
  
      CALL GETARG
     I           (2+MORG,
     O            DIRECTORY_NAME)
      IF(INPUT_NAME.EQ.DIRECTORY_NAME) THEN
        WRITE(*,*) ' INPUT AND OUTPUT FILE CANNOT BE THE SAME'
        STOP
      ENDIF
      OPEN(LOUT, FILE = DIRECTORY_NAME, STATUS = 'UNKNOWN',
     A               IOSTAT=IOFLAG)
  
      IF(IOFLAG.NE.0) THEN
        WRITE(*,*) ' PROBLEM IN OPENING FILE: ',DIRECTORY_NAME
        WRITE(*,*) ' CHECK PATH FOR OUTPUT FILE.'
        STOP
      ENDIF
  
  
      NUMBER_OF_FILES = 0
  
100   CONTINUE
        READ(IN,'(A)',END=110) FILE_NAME(NUMBER_OF_FILES + 1)
        IF(FILE_NAME(NUMBER_OF_FILES + 1).NE.' ') THEN
          NUMBER_OF_FILES = NUMBER_OF_FILES + 1
          IF(NUMBER_OF_FILES.GT.MAXFILE) THEN
            WRITE(LOUT,*) ' Too many files.'
            STOP
          ENDIF
          GOTO 100
        ENDIF
110   CONTINUE

      WRITE(LOUT,*) ' NUMBER_OF_FILES=',NUMBER_OF_FILES  
C     Open each file in turn and find the table numbers in the
C     file.
      NUMBER_OF_TABLES = 0
  
      DO 500 I=1,NUMBER_OF_FILES
  
        INQUIRE(FILE=FILE_NAME(I), EXIST=THERE)
        IF(THERE) THEN
          OPEN(IDSN, FILE = FILE_NAME(I), STATUS = 'OLD')
        ELSE
          WRITE(*,*) ' FILE NAMED:',FILE_NAME(I),' NOT FOUND.'
          WRITE(*,*) ' PLEASE CHECK SPELLING OF FILE NAME USED.'
          STOP
        ENDIF

        WRITE(LOUT,*) ' DOING FILE:',FILE_NAME(I)
  
200     CONTINUE
          CALL INL112(IDSN, LINE)
          IF(LINE.EQ.'ENDFILE') GOTO 210
          TAB_FLAG = 0
          IF(LINE(1:6).EQ.'TABLE#') THEN
            READ(LINE(8:),'(A)',ERR=999) TABID
            TAB_FLAG = 1
          ELSEIF(LINE(1:5).EQ.'TABID') THEN
            READ(LINE(7:),'(A)',ERR=999) TABID
            TAB_FLAG = 1
          ENDIF
          IF(TAB_FLAG.EQ.1) THEN
            CALL STRIP_L_BLANKS(
     M                          TABID)

            IF(TABID(1:1).EQ.'-') GOTO 200

            NUMBER_OF_TABLES = NUMBER_OF_TABLES + 1
            IF(NUMBER_OF_TABLES.GT.MAXTAB) THEN
              WRITE(LOUT,*) ' Too many tables.'
              STOP 'Abnormal stop.  Errors found.'
            ENDIF
C           Get the table type next.   
            CALL INL112(IDSN, LINE)
            IF(LINE.EQ.'ENDFILE') GOTO 210
            READ(LINE(6:10),'(I5)',ERR=202) TYPE
            GOTO 203
202         CONTINUE
C             Probably processing a FEQUTL input file.
              TYPE = 1
203         CONTINUE
            TYPE = ABS(TYPE)
            LABEL_POINTER(NUMBER_OF_TABLES) = NUMBER_OF_TABLES
            TABLE_TYPE(NUMBER_OF_TABLES) = TYPE
            TABLE_ID(NUMBER_OF_TABLES) = TABID
            FILE_NAME_POINTER(NUMBER_OF_TABLES) = I
C           Try to get a label for the table.
            IF(TYPE.GE.2.AND.TYPE.LE.4.OR.
     A        TYPE.GE.7.AND.TYPE.LE.9.OR.
     B        TYPE.EQ.11) THEN
              CALL INL112(IDSN, LINE)
              CALL INL112(IDSN, LINE)
              TABLE_LABEL(NUMBER_OF_TABLES) = LINE(1:80)
            ELSEIF(TYPE.EQ.10.OR.TYPE.EQ.13.OR.TYPE.EQ.14) THEN
              CALL INL112(IDSN, LINE)
              TABLE_LABEL(NUMBER_OF_TABLES)  = LINE(7:80)
            ELSEIF(TYPE.EQ.15) THEN
              CALL INL112(IDSN, LINE)
              TABLE_LABEL(NUMBER_OF_TABLES)  = LINE(23:80)
            ELSEIF(TYPE.EQ.6) THEN
              CALL INL112(IDSN, LINE)
              TABLE_LABEL(NUMBER_OF_TABLES)  = LINE(21:80)
            ELSE
C             Assume cross section table.
              CALL INL112(IDSN, LINE)
              TABLE_LABEL(NUMBER_OF_TABLES)  = LINE(1:80)
            ENDIF



          ENDIF
          GOTO 200
210     CONTINUE
        CLOSE(IDSN)
500   CONTINUE
  
  
C     Sort on the table number moving the file-name pointer and the
C     label pointer at the same time.
  
      CALL QSRTIA(TABLE_ID, FILE_NAME_POINTER, LABEL_POINTER,
     A            NUMBER_OF_TABLES)
  
      WRITE(LOUT,50)
  
      DO 600 I=1,NUMBER_OF_TABLES
        LP = LABEL_POINTER(I)
        LLP = LENSTR(TABLE_LABEL(LP))
        FP = FILE_NAME_POINTER(I)
        LFP = LENSTR(FILE_NAME(FP))
        WRITE(LOUT,52) TABLE_ID(I), TABLE_TYPE(LP),
     A          FILE_NAME(FP)(1:LFP), TABLE_LABEL(LP)(1:LLP)
  
600   CONTINUE
      CLOSE(IN)
      CLOSE(LOUT)
      STOP
999   CONTINUE
      WRITE(LOUT,'(A)') LINE
      WRITE(LOUT,*) ' Conversion error in above line.'
      STOP
      END
