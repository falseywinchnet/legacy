C     *****************
C     *               *
C     * DMPMC         *
C     *               *
C     *****************

      SUBROUTINE DMPMC(STDOUT, NBRA, NEX, BRPT, EXNODT)

C     OUTPUT THE CONTROL INFORMATION FOR CHECKING

      INTEGER STDOUT, NBRA, NEX

      INTEGER BRPT(8,NEX), EXNODT(9,NEX)

      INCLUDE 'arsize.prm'
      INCLUDE 'matcom.cmn'

C     LOCAL

      INTEGER I
C     *********************FORMATS**************************************
50    FORMAT('   EQU NUM   ROW PNT   COL PNT')
52    FORMAT(3I10)
54    FORMAT(' BLOCK NUM    BEGROW    ENDCON    MBTYPE')
56    FORMAT(4I10)
60    FORMAT(' BRANCH POINTER')
62    FORMAT(I7,I8)

C***********************************************************************

      WRITE(STDOUT,*) '  '
      WRITE(STDOUT,*) ' NUMEQ=',NUMEQ

      WRITE(STDOUT,*) ' POINTERS FOR PROFILE STORAGE OF MATRIX.'
      WRITE(STDOUT,50) 

      DO 100 I=1,NUMEQ
        WRITE(STDOUT,52) I, R(I), C(I)
100   CONTINUE

      WRITE(STDOUT,*) ' '
      WRITE(STDOUT,*) ' MATRIX BLOCK CONTROL'
      WRITE(STDOUT,*) ' MATBLK=',MATBLK
      WRITE(STDOUT,54)
        
      DO 200 I=1,MATBLK
        WRITE(STDOUT,56) I, BEGROW(I), ENDCON(I), MBTYPE(I)
200   CONTINUE


      WRITE(STDOUT,*) ' '
      WRITE(STDOUT,*) ' POINTERS TO VARIABLES FOR BRANCHES'
      WRITE(STDOUT,60)
      DO 300 I=1,NBRA
        WRITE(STDOUT,62) I, BRPT(7,I)
300   CONTINUE

      WRITE(STDOUT,*) ' '
      WRITE(STDOUT,*) ' POINTERS TO VARIABLE FOR EXTERIOR NODES'
      WRITE(STDOUT,60)
      DO 400 I=1,NEX
        WRITE(STDOUT,62) I, EXNODT(5,I)
400   CONTINUE
      
      WRITE(STDOUT,*) ' '
      RETURN
      END
