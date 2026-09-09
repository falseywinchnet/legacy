!   Kindly supplied for use in the FEQ/FEQUTL modeling system by:
!   Juan Ramon Perez Garreleta.  Many thanks to him!
!   In an e-mail, dated 2007-12-10 he wrote:
! 
!   "I am happy so that the code is to him useful.
!    It can use it where it wants and as it wants.
!
!  (I am aircraft engineer and Fortran Hobbyist from year 1970 !!!uf¡¡¡)

!   I agree in which it includes my name and my e-mail.
!   My complete name is: Juan Ramon Perez Garraleta 
!   My personal e-mail is: garraleta@telefonica.net"

    SUBROUTINE MD5(MENSAJE,CODIGO)
    IMPLICIT NONE
    INTEGER(4) :: I
    INTEGER(4) :: J
    INTEGER(4) :: L
    INTEGER(4) :: IB
    INTEGER(8) :: K(0:63)
    INTEGER(4) :: H0
    INTEGER(4) :: H1
    INTEGER(4) :: H2
    INTEGER(4) :: H3
    INTEGER(4) :: LEN_ORIG
    INTEGER(4) :: LEN_MAX
    INTEGER(8) :: LEN_ORIG_BITS
    INTEGER(4) :: LEN
    INTEGER(4) :: ANADIR

    REAL(8) :: DUM
    INTEGER(4) :: A
    INTEGER(4) :: B
    INTEGER(4) :: C
    INTEGER(4) :: D
    INTEGER(4) :: F
    INTEGER(4) :: G
    INTEGER(4) :: TEMP
    INTEGER(4) :: LOCO
    CHARACTER(LEN=*), INTENT(IN) :: MENSAJE
    INTEGER(4) :: R(0:63)
    INTEGER(1),ALLOCATABLE :: XXXX(:)
    CHARACTER(LEN=8) :: LINEA(4)
    CHARACTER(LEN=32) :: CODIGO
    INTEGER(4) :: W(0:15)
    INTEGER(4) :: BLO
    INTEGER(4) :: N_BLOQUES

    INTEGER(1) :: LEN_ORIG_1(8)
    EQUIVALENCE(LEN_ORIG_1(1),LEN_ORIG_BITS)


    DATA (R(I),I=0,15) /7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22/
    DATA (R(I),I=16,31) /5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20/
    DATA (R(I),I=32,47) /4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23/
    DATA (R(I),I=48,63) /6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21/

    DO I=0,63
      DUM=I+1
      DUM=ABS(SIN(DUM))
      DUM=DUM*4294967296
      K(I)=DUM
    ENDDO

    H0=Z'67452301'
    H1=Z'EFCDAB89'
    H2=Z'98BADCFE'
    H3=Z'10325476'


!   Preproceso
!   Se calcula la longitud del mensaje

    LEN_ORIG=LEN_TRIM(MENSAJE)
    LEN_ORIG_BITS=LEN_ORIG*8
    LEN_MAX=LEN_ORIG+512

    LEN=LEN_ORIG

    ALLOCATE(XXXX(LEN_MAX))
    DO I=1,LEN_MAX
      XXXX(I)=0
    ENDDO

!   Transformamos el mensaje en enteros


    DO I=1,LEN
      XXXX(I)=ICHAR(MENSAJE(I:I))
    ENDDO

!   Se añade un 1

    LEN=LEN+1       
    XXXX(LEN)=Z'80'

!   Los 8 ultimos bytes tienen que ser el tamaño original el litte-endian
!   y en total el tamaño de XXXX debe ser multiplo de 64

    LEN=LEN+8
    IB=LEN/64
    IF(IB*64 .EQ. LEN)THEN
      ANADIR=0
    ELSE
      IB=IB+1
      ANADIR=IB*64-LEN
    ENDIF
    LEN=LEN+ANADIR

    IB=0
    DO I=LEN-7,LEN
      IB=IB+1
      XXXX(I)=LEN_ORIG_1(IB)
    ENDDO

!   Descompone al array XXXX de 64 bytes en 16 arrays de 4 bytes W

    N_BLOQUES=LEN/64
    DO BLO=1,N_BLOQUES
      J=(BLO-1)*64+1
      DO I=0,15
        CALL EXTRAE(XXXX(J),W(I))
        J=J+4
      ENDDO

      A=H0
      B=H1
      C=H2
      D=H3
      DO I=0,63
        IF(I .GE. 0 .AND. I .LE. 15)THEN
          F=IOR(IAND(B,C),IAND(NOT(B),D))     
          G=I
        ELSE IF(I .GE. 16 .AND. I .LE. 31)THEN
          F=IOR(IAND(D,B),IAND(NOT(D),C))
          G=MOD(5*I+1,16)
        ELSE IF(I .GE. 31 .AND. I .LE. 47)THEN
          F=IEOR(B,IEOR(C,D))
          G=MOD((3*I+5),16)
        ELSE IF(I .GE. 48 .AND. I.LE. 63)THEN
          F=IEOR(C,IOR(B,NOT(D)))
          G=MOD((7*I),16)
        ENDIF
        TEMP=D
        D=C
        C=B
        LOCO=A+F+K(I)+W(G)
        B=B+ISHFTC((A+F+K(I)+W(G)),R(I),32)
        A=TEMP
      ENDDO
      H0 = H0 + A
      H1 = H1 + B
      H2 = H2 + C
      H3 = H3 + D
    ENDDO
    WRITE(LINEA(1),FMT='(Z8.8)')H0
    WRITE(LINEA(2),FMT='(Z8.8)')H1
    WRITE(LINEA(3),FMT='(Z8.8)')H2
    WRITE(LINEA(4),FMT='(Z8.8)')H3
    
    L=0
    DO I=1,4
      DO J=7,1,-2
        L=L+1
        CODIGO(L:L)=LINEA(I)(J:J)
        L=L+1
        CODIGO(L:L)=LINEA(I)(J+1:J+1)
      ENDDO
    ENDDO
    END

    SUBROUTINE EXTRAE(UNO,CUATRO)
    IMPLICIT NONE
    INTEGER(1) :: UNO(4)
    INTEGER(4) :: CUATRO
    INTEGER(1) :: UNO_B(4)
    INTEGER(4) :: CUATRO_B


    EQUIVALENCE(UNO_B,CUATRO_B)
    UNO_B=UNO
    CUATRO=CUATRO_B
    END

