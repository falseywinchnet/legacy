C     Routines used to create the IntelliCAD 2000 script file
C     that defines the schematic for the model. 

C
C
C 
      SUBROUTINE STRIP_ALL_BLANKS(
     M                            STRING,
     O                            N)

C     Strip all blanks from the given string and return

      IMPLICIT NONE
      CHARACTER*(*) STRING

C     Local

      INTEGER I, KNT, N
C***********************************************************************
      N = LEN_TRIM(STRING)
      KNT = 0
      DO 100 I=1,N
        IF(STRING(I:I).NE.' ') THEN
          KNT = KNT + 1
          STRING(KNT:KNT) = STRING(I:I)
        ENDIF
100   CONTINUE
      N = KNT
      RETURN
      END
C
C
C
      SUBROUTINE DO_DUMMY_BRANCHES(STDOUT, SCMUNIT, NBRA, NEX, BRPT, 
     I            EXNODT, EMC, HALF_L)
        
C     Do dummy branches in a schematic

      IMPLICIT NONE
      INCLUDE 'arsize.prm'
      INTEGER NBRA, NEX, STDOUT, BRPT(8,NBRA), EXNODT(9,NEX),
     A        EMC(MREMC), SCMUNIT

      REAL*8 HALF_L

C     BRPT   - branch pointer table.  Values for each branch are:
C              ROW       Meaning
C              1         upstream user node number
C              2         downstream user node number
C              3         pointer into branch vector for upstream node
C              4         pointer into branch vector for downstream node
C              5         upstream exterior node number
C              6         downstream exterior node number
C              7         pointer to address in EMC for the branch
C              8         number of unknowns at a node for the branch
C     EXNODT - exterior node table.  Contains the following items
C              for each exterior node.
C              Row   Content
C               1    sign of the node
C               2    pointer into vectors for nodes on a branch
C               3    descriptive code: if -1 then a reservoir;
C                    if  0 then not on a branch and not a reservoir;
C                    if > 0 then a branch number
C               4    pointer to a cross section table if on a branch, 
C                    to storage table if a reservoir, to other node if
C                    a dummy branch
C               5    gives the variable number(in the system matrix) for
C                    the flow at the exterior node. Also a junction
C                    pointer in initial processing of input
      
                    
      INCLUDE 'bnothr.cmn'
      INCLUDE 'matcom.cmn'
 

C     Called program units
      CHARACTER GETUSN*5
      EXTERNAL GETUSN, STRIP_ALL_BLANKS, FIND_PERPENDICULAR,
     A         FIND_LINE_COEF

C     Local
      INTEGER CODE, IENTRY, IPNT, UPN, DNN, NULL, UPNFLAG, DNNFLAG,
     A        NODE_KNT, MODE, SLEN, OUT

      REAL*8 UPNX, UPNY, DNNX, DNNY, X(2), Y(2), LENGTH,
     A       XS, YS, XE, YE, LABEL_LENGTH, SHIFT, DX, DY, M,
     B       TEMP_LENGTH, LS, LE, AA, BB, CC

      CHARACTER UPNLABEL*5, DNNLABEL*5, DUMBR_LABEL*11, LINE*80,
     A          UPNXLOC*15, UPNYLOC*15, DNNXLOC*15, DNNYLOC*15


      DATA NULL/-2147483647/, LABEL_LENGTH/220.D0/

C     **************************FORMATS*********************************
52    FORMAT(';',' Dummy branch with free nodes: ',A5,', ',A5)
54    FORMAT('Dummy branches not drawn in schematic',/,
     A' Dummy Branch Ups                     Dummy Branch Dns',/,
     B'  Node     X-location     Y-location ',
     C'  Node     X-location     Y-location') 
56    FORMAT(' ',A5,A15,A15,2X,A5,A15,A15)
C***********************************************************************
      LABEL_LENGTH = 2.D0*LABEL_LENGTH
C     General approach:
C     1. Scan EMC for dummy branches.
C     2. For each dummy branch extract the ups and dns node numbers
C     2.1 Check in EXNODT, in rows 6 and 7 to see if (x,y) is known for
C         this dummy branch from this source.   If not  goto 3
C         otherwise 
C     3. Scan EMC for code 2 (sum of flows = 0) and find
C        the one that containes the ups node (if any).
C       
C     4. If found, then search for the other nodes in the junction
C        for information of (x,y). As any are found, compute the sum 
C        of each coordinate value and count so that we can compute
C        an average location. 
C     5. Do this for each end of the dummy branch.
C     6.  If both ends have (x,y) info, then we can plot the DumBr.
C     7. Plot like a branch but shift to a layer than creates dashed
C        lines.
C     8. Get the user values for the free-node and place them at the
C        appropriate end of the dummy branch dashed line.  

C     Write heading for dummy branches not drawn
      WRITE(STDOUT,*) ' '
      WRITE(STDOUT,54)


C     Start loop seaching for Dummy Branches.  CODE=15
      IENTRY = 0
 
 100  CONTINUE
        IENTRY = IENTRY + 1
        IPNT = ADD(IENTRY)
        CODE = EMC(IPNT)
        IF(CODE.EQ.15) THEN
C         Get the ups and dns node numbers
          UPN = EMC(IPNT+1)
          DNN = EMC(IPNT+2)
          UPNLABEL = GETUSN(UPN)
          DNNLABEL = GETUSN(DNN)
          
C         Clear the location flags
          UPNFLAG = 0
          DNNFLAG = 0

C         Check to see if these nodes have a location given in EXNODT
          IF(EXNODT(6,UPN).GT.NULL) THEN
            UPNFLAG = 1
            UPNX = DBLE(EXNODT(6,UPN))/100.D0
            UPNY = DBLE(EXNODT(7,UPN))/100.D0
          ENDIF
          IF(EXNODT(6,DNN).GT.NULL) THEN
            DNNFLAG = 1
            DNNX = DBLE(EXNODT(6,DNN))/100.D0
            DNNY = DBLE(EXNODT(7,DNN))/100.D0
          ENDIF

C         Do searches for the location if needed

          IF(UPNFLAG.EQ.0) THEN
C           A search is needed. 

            CALL SEEK_FREE_NODE_LOCATION(STDOUT, NBRA, NEX, BRPT, 
     I            EMC, UPN,
     M            EXNODT, UPNFLAG,
     O            UPNX, UPNY)
          ENDIF
          IF(DNNFLAG.EQ.0) THEN
C           A search is needed. 

            CALL SEEK_FREE_NODE_LOCATION(STDOUT, NBRA, NEX, BRPT, 
     I            EMC, DNN,
     M            EXNODT, DNNFLAG,
     O            DNNX, DNNY)
          ENDIF

          IF(UPNFLAG.EQ.1.AND.DNNFLAG.EQ.1) THEN
C           We can draw the dummy branch.
     
C           MODE not now used-maybe later
            MODE = 1
            X(1) = UPNX
            Y(1) = UPNY
            X(2) = DNNX
            Y(2) = DNNY
            NODE_KNT = 2
            WRITE(SCMUNIT,52) UPNLABEL, DNNLABEL
            CALL DRAW_BRANCH_GRAPHIC(MODE, SCMUNIT, NODE_KNT, X, Y,
     I                               HALF_L)


C           Do dummy branch labels here. 
C           Select the layer for Dummy branch labels
            WRITE(SCMUNIT,'(A)') 'LAYER','MAKE','DUMBRLAB'
            write(scmunit,'( )')

C         
C           Find the length of the graphic
            LENGTH = SQRT( (X(2) - X(1))**2 + (Y(2) - Y(1))**2)


C           Tailor the length to the length of the dummy branch
            IF(LABEL_LENGTH.GT.0.8D0*LENGTH) THEN
              TEMP_LENGTH = 0.8D0*LENGTH
            ELSE
              TEMP_LENGTH = LABEL_LENGTH
            ENDIF
      
C           Compute the offsets from the ups node 
C           for the start and end of the text
            LS = 0.5*(LENGTH - TEMP_LENGTH)
            LE = 0.5*(LENGTH + TEMP_LENGTH)

            XS = X(1) + LS*(X(2) - X(1))/LENGTH
            YS = Y(1) + LS*(Y(2) - Y(1))/LENGTH
            XE = X(1) + LE*(X(2) - X(1))/LENGTH
            YE = Y(1) + LE*(Y(2) - Y(1))/LENGTH
      

C           Shift the label slightly away from the line.
            CALL FIND_LINE_COEF(X(1), Y(1), X(2), Y(2),
     O                      AA, BB, CC)
C           There are 11 chars in the label placed over a distance
C           of TEMP_LENGTH.  Make the shift about 1/2 of the average
C           character width.
            SHIFT = TEMP_LENGTH/22.D0
            M = -AA/BB
            DX = SHIFT/SQRT(1.D0/M**2 + 1.D0)
            DY = SHIFT/SQRT(M**2 + 1.D0)

C           Set signs so that the shift is always on the same side
C           of a line considered to be directed from the S to 
C           E end.
            IF(XE.GT.XS) THEN
              IF(M.GT.0.D0) THEN
                DX = -DX
              ENDIF
            ELSE
              IF(M.LT.0.D0) THEN
                DX = -DX
                DY = -DY
              ELSE
                DY = -DY
              ENDIF
            ENDIF


            XS = XS + DX
            YS = YS + DY
            XE = XE + DX
            YE = YE + DY


C           Now do the text insertion
            WRITE(SCMUNIT,'(A,/A)') 'TEXT', 'A'
            WRITE(LINE,'(F13.2,'','',F13.2)') XS, YS
            CALL STRIP_ALL_BLANKS(
     M                            LINE,
     O                            SLEN)
            WRITE(SCMUNIT,'(A)') LINE(1:SLEN)
            WRITE(LINE,'(F13.2,'','',F13.2)') XE, YE
            CALL STRIP_ALL_BLANKS(
     M                            LINE,
     O                            SLEN)
            WRITE(SCMUNIT,'(A)') LINE(1:SLEN)

            DUMBR_LABEL(1:5) = UPNLABEL
            DUMBR_LABEL(6:6) = ':'
            DUMBR_LABEL(7:11) = DNNLABEL
            WRITE(SCMUNIT,'(A11)') DUMBR_LABEL

C           Select the layer for Dummy branches
            WRITE(SCMUNIT,'(A)') 'LAYER','MAKE','DUMBR'
            write(scmunit,'( )')


          ELSE
C           Output note to user master output file for dummy branches not
C           drawn.
C           Clear the output flag.
            OUT = 0
            IF(UPNFLAG.EQ.1) THEN
C             We have data at the upstream end.  Convert to character
              WRITE(UPNXLOC,'(F15.2)') UPNX
              WRITE(UPNYLOC,'(F15.2)') UPNY
              OUT = 1
            ELSE
              UPNXLOC = ' '
              UPNYLOC = ' '
            ENDIF
            IF(DNNFLAG.EQ.1) THEN
C             We have data at the downstream end.  Convert to character
              WRITE(DNNXLOC,'(F15.2)') DNNX
              WRITE(DNNYLOC,'(F15.2)') DNNY
              OUT = 1
            ELSE
              DNNXLOC = ' '
              DNNYLOC = ' '
            ENDIF
            IF(OUT.EQ.1) THEN
              WRITE(STDOUT,56) UPNLABEL, UPNXLOC, UPNYLOC, 
     A                         DNNLABEL, DNNXLOC, DNNYLOC
            ENDIF
          ENDIF
        ENDIF
 
        IF(CODE.GT.0) THEN
C         Continue the search.
          GOTO 100
        ENDIF
      
        WRITE(STDOUT,*) ' '

      RETURN
      END
C
C
C
      SUBROUTINE SEEK_FREE_NODE_LOCATION(STDOUT, NBRA, NEX, BRPT, 
     I            EMC, NODE,
     M            EXNODT, NODEFLAG,
     O            NODEX, NODEY)

C     Scan EMC seeking to find NODE in a Code 2 relationship that also
C     has either branches or free nodes with a known location. 

      IMPLICIT NONE
      INCLUDE 'arsize.prm'
      INTEGER NBRA, NEX, STDOUT, BRPT(8,NBRA), EXNODT(9,NEX),
     A        EMC(MREMC), NODE, NODEFLAG

      REAL*8 NODEX, NODEY

C     EXNODT - exterior node table.  Contains the following items
C              for each exterior node.
C              Row   Content
C               1    sign of the node
C               2    pointer into vectors for nodes on a branch
C               3    descriptive code: if -1 then a reservoir;
C                    if  0 then not on a branch and not a reservoir;
C                    if > 0 then a branch number
C               4    pointer to a cross section table if on a branch, 
C                    to storage table if a reservoir, to other node if
C                    a dummy branch
C               5    gives the variable number(in the system matrix) for
C                    the flow at the exterior node. Also a junction
C                    pointer in initial processing of input

      INCLUDE 'bnothr.cmn'
      INCLUDE 'matcom.cmn'


C     Called program units
      REAL*8 GET_DP_FROM_FT
      EXTERNAL GET_DP_FROM_FT



C     Local
      INTEGER ADRS, CODE, IENTRY, IPNT, J, K, KNT, N, CNN, CLASS,
     A        NULL

      REAL*8 X, Y, SUMX, SUMY, DNULL

      DATA DNULL/-33.D6/, NULL/-2147483647/
C***********************************************************************
C     Scan over all CODE 2 entries and search for NODE

      IENTRY = 0


 100  CONTINUE
        IENTRY = IENTRY + 1
        IPNT = ADD(IENTRY)
        CODE = EMC(IPNT)
        IF(CODE.EQ.2) THEN
          N = EMC(IPNT+1)
          DO 200 J=1,N
            IF(NODE.EQ.EMC(IPNT+1+J)) THEN
C             We have found the junction containing the node.
C             Rescan the nodes in the junction seeking
C             location values. 
              KNT = 0
              SUMX = 0.D0
              SUMY = 0.D0
              DO 150 K=1,N
                CNN = EMC(IPNT+1+K)
                IF(CNN.NE.NODE) THEN
                  CLASS = EXNODT(3,CNN)
                  IF(CLASS.GT.0) THEN
C                   We have a branch.  Get the (x,y) from the 
C                   cross-section-function table
                    ADRS = EXNODT(4,CNN)
                    X = GET_DP_FROM_FT(ADRS+8)
                    Y = GET_DP_FROM_FT(ADRS+10)
                    IF(X.GT.DNULL) THEN
C                     Location is known. 
                      KNT = KNT + 1
                      SUMX = SUMX + X
                      SUMY = SUMY + Y
                    ENDIF
                  ELSEIF(CLASS.LE.0) THEN
C                   We have a free node.  Check to see if its location
C                   is known. 
                    IF(EXNODT(6,CNN).GT.NULL) THEN
C                     Location is known
                      X = DBLE(EXNODT(6,CNN))/100.D0
                      Y = DBLE(EXNODT(7,CNN))/100.D0
                      KNT = KNT + 1
                      SUMX = SUMX + X
                      SUMY = SUMY + Y
                    ENDIF
                  ENDIF
                ENDIF
150           CONTINUE 
              IF(KNT.GT.0) THEN

C               Compute the average value for the coordinate
                NODEX = SUMX/DBLE(KNT)
                NODEY = SUMY/DBLE(KNT)
                NODEFLAG = 1
C               Store the known value for the free node into
C               EXNODT
                EXNODT(6,NODE) = NINT(NODEX*100.D0)
                EXNODT(7,NODE) = NINT(NODEY*100.D0)
                GOTO 300
              ENDIF
            ENDIF
200       CONTINUE
        ENDIF
        IF(CODE.GT.0) THEN
C         Continue the search.
          GOTO 100
        ENDIF

300   CONTINUE
      RETURN
      END
C
C
C
      SUBROUTINE DRAW_BRANCH_GRAPHIC(MODE, SCMUNIT, NODE_KNT, X, Y,
     I           HALF_L)

C     Draw the graphic for a branch, either real or dummy. 

      IMPLICIT NONE
      INTEGER MODE, SCMUNIT, NODE_KNT
      REAL*8 X(NODE_KNT), Y(NODE_KNT), HALF_L
      
C     Called program units.
      EXTERNAL STRIP_ALL_BLANKS,FIND_LINE_COEF, FIND_PERPENDICULAR


C     Local 

      INTEGER J, SLEN

      REAL*8 A, B, C, AP, BP, CP, DX, DY, XTICK, YTICK, M

      CHARACTER LINE*80

C***********************************************************************

C     Output the polyline command
      WRITE(SCMUNIT,'(A)') 'PLINE'
C     Output the x,y pairs, one per line
      DO 110 J=1,NODE_KNT
        WRITE(LINE,'(F13.2,'','',F13.2)') X(J), Y(J)
        CALL STRIP_ALL_BLANKS(
     M                        LINE,
     O                        SLEN)
        WRITE(SCMUNIT,'(A)') LINE(1:SLEN)
110   CONTINUE

C     Write a blank line to terminate the polyline command
      WRITE(SCMUNIT,'( )') 

C     Compute the end points of the polyline that will represent
C     the ends of a branch.   We find the coefficents for the general
C     equation of a straight line that is perpendicular to the 
C     a line segment at one end and then at the other end of
C     the polyline for the branch.  We then define the end points
C     of a line segment on this perpendicular line to establish the
C     graphic object that we want,

C     Find the coef. of the line that passes through the 
C     endpoints of the line segement at the upstream end of
C     the branch.  

      CALL FIND_LINE_COEF(X(1), Y(1), X(2), Y(2),
     O                    A, B, C)

C     Find the coef. of the line that is perpendicular to the 
C     line just found and also passes through [X(1), Y(1)].

      CALL FIND_PERPENDICULAR(X(1), Y(1), A, B, C,
     O                        AP, BP, CP)

C     Compute the slope of the perpendicular line,  The general
C     equation for this line is: AP*X + BP*Y + CP = 0.  We solve
C     for M in the equation:  Y = M*X + Q, where M is the slope and
C     Q is the intercept.  This yields:  M = -AP/BP.  BP may be zero,
C     however both LF90 and LF95 include the IEEE floating point extensions
C     that include infinity in a logical manner.  Division by zero yields
C     infinity of the proper sign assuming the numerator of the ratio is
C     not also zero.  If it is zero we get Not a Number as the result. 
C     Division of any non-zero by infinity yields zero.

      M = -AP/BP

      WRITE(SCMUNIT,'(A)') 'PLINE'
      DX = HALF_L/SQRT(1.D0 + M**2)     
      DY = HALF_L/SQRT(1.D0 + 1.D0/M**2)

      IF(M.GT.0.D0) THEN
        XTICK = X(1)  +  DX
        YTICK = Y(1)  +  DY
      ELSE
        XTICK = X(1)  +  DX
        YTICK = Y(1)  -  DY
      ENDIF  

      WRITE(LINE,'(F13.2,'','',F13.2)') XTICK, YTICK
      CALL STRIP_ALL_BLANKS(
     M                      LINE,
     O                      SLEN)
      WRITE(SCMUNIT,'(A)') LINE(1:SLEN)
      
      IF(M.GT.0.D0) THEN
        XTICK = X(1)  - DX
        YTICK = Y(1)  - DY
      ELSE
        XTICK = X(1) - DX
        YTICK = Y(1) + DY
      ENDIF
      WRITE(LINE,'(F13.2,'','',F13.2)') XTICK, YTICK
      CALL STRIP_ALL_BLANKS(
     M                      LINE,
     O                      SLEN)
      WRITE(SCMUNIT,'(A)') LINE(1:SLEN)

      WRITE(SCMUNIT,'( )') 

C     Do the dns end of the branch
      CALL FIND_LINE_COEF(X(NODE_KNT-1), Y(NODE_KNT-1), X(NODE_KNT),
     I                    Y(NODE_KNT),
     O                    A, B, C)
      CALL FIND_PERPENDICULAR(X(NODE_KNT), Y(NODE_KNT), A, B, C,
     O                        AP, BP, CP)
      M = -AP/BP

      WRITE(SCMUNIT,'(A)') 'PLINE'
      DX = HALF_L/SQRT(1.D0 + M**2)     
      DY = HALF_L/SQRT(1.D0 + 1.D0/M**2)

      IF(M.GT.0.D0) THEN
        XTICK = X(NODE_KNT)  +  DX 
        YTICK = Y(NODE_KNT)  +  DY
      ELSE
        XTICK = X(NODE_KNT)  +  DX 
        YTICK = Y(NODE_KNT)  -  DY
      ENDIF
 
      WRITE(LINE,'(F13.2,'','',F13.2)') XTICK, YTICK
      CALL STRIP_ALL_BLANKS(
     M                      LINE,
     O                      SLEN)
      WRITE(SCMUNIT,'(A)') LINE(1:SLEN)
      IF(M.GT.0.D0) THEN
        XTICK = X(NODE_KNT)  -  DX 
        YTICK = Y(NODE_KNT)  -  DY
      ELSE
        XTICK = X(NODE_KNT)  -  DX 
        YTICK = Y(NODE_KNT)  +  DY
      ENDIF
      WRITE(LINE,'(F13.2,'','',F13.2)') XTICK, YTICK
      CALL STRIP_ALL_BLANKS(
     M                      LINE,
     O                      SLEN)
      WRITE(SCMUNIT,'(A)') LINE(1:SLEN)

      WRITE(SCMUNIT,'( )') 

      RETURN
      END
C
C
C

      SUBROUTINE FREE_NODE_LOCATION_DEFINE(STDOUT, NEX, BASE_NODE_VEC,
     M                               EXNODT,
     O                               EFLAG)

C     Define the free-node locations for a schematic. 

      IMPLICIT NONE

      INTEGER STDOUT, NEX, BASE_NODE_VEC(NEX), EXNODT(9,NEX), EFLAG

C     EXNODT - exterior node table.  Contains the following items
C              for each exterior node.
C              Row   Content
C               1    sign of the node
C               2    pointer into vectors for nodes on a branch
C               3    descriptive code: if -1 then a reservoir;
C                    if  0 then not on a branch and not a reservoir;
C                    if > 0 then a branch number
C               4    pointer to a cross section table if on a branch, 
C                    to storage table if a reservoir, to other node if
C                    a dummy branch
C               5    gives the variable number(in the system matrix) for
C                    the flow at the exterior node. Also a junction
C                    pointer in initial processing of input
C               6    X location of the node in a cartesian coordinate system
C               7    Y location of the node in a cartesian coordiante system. 
C                   The (X,Y) are scaled upward by 100.  That is 
C                   a coordinate value of 1234.51 becomes then integer
C                   123451.  If the coordinate value is -(2**31 -1) it
C                   indicates that no value for a coordinate exists. 
C                   The scaling permits a maximum value of 2**31/100 
C                   distance units.  When the length unit is feet the 
C                   maximum coordinate is 21,474,836.48 feet or
C                   about 4067 miles.  This appears to be adequate 
C                   for any reasonable purpose!

C     Common blocks and parameters
      INCLUDE 'arsize.prm'
      INCLUDE 'bnothr.cmn'

C     Called program units
      CHARACTER GETUSN*5
      REAL*8 GET_DP_FROM_FT
      EXTERNAL GET_DP_FROM_FT, GETUSN


C     Local
      INTEGER ADRS, BASE_NODE_NUMBER, CLASS, I, NULL
      REAL*8 DNULL, XBASE, YBASE, XLOC, YLOC
      CHARACTER BASE_NODE*5

      DATA NULL/-2147483647/, DNULL/-33.D6/

C     ******************************************************************
50    FORMAT(/,' *ERR:398* Base node= ',A5,' for free node= ',A5,
     A ' has at least one undefined coordinate value.')
52    FORMAT(/,' *ERR:399* Free node= ',A5,
     A      ' has at least one offset value that is unknown.')
C***********************************************************************
C     Check all values in BASE_NODE_VEC for a non-zero.  Branch-node 
C     locations are not given in EXNODT.  Thus they will have a zero value
C     for BASE_NODE_VEC and the null value for the offset values.  If 
C     absolute offsets were given for a free node, the BASE_NODE value 
C     will also be zero.  Thus the only adjustments made here are for
C     non-zero base-node values.   The base-node could be a free node
C     or a node on a branch.  The null value for nodes on a branch 
C     differs because those values are stored in the cross-section
C     function table at full double precision.  A reference to a 
C     base node that has null values for its location is a user
C     error. 

      DO 500 I=1,NEX
        BASE_NODE_NUMBER = BASE_NODE_VEC(I)
        IF(BASE_NODE_NUMBER.GT.0) THEN
C         We have a base node reference.   
C         Get the user label for this base node and its class:
C         on a branch or a free node.
          BASE_NODE = GETUSN(BASE_NODE_NUMBER)
          CLASS = EXNODT(3,BASE_NODE_NUMBER)
          IF(CLASS.GT.0) THEN
C           Base node is on the end of a branch.  Get the
C           function-table address.
            ADRS = EXNODT(2,BASE_NODE_NUMBER)
            XBASE = GET_DP_FROM_FT(ADRS+8)
            YBASE = GET_DP_FROM_FT(ADRS+10)
C           Check for validity
            IF(XBASE.LE.DNULL.OR.YBASE.LE.DNULL) THEN
              WRITE(STDOUT,50) BASE_NODE, GETUSN(I)
              EFLAG = 1
              STOP 'Abnormal stop.  Error(s) found.'
            ENDIF
          ELSE
C           Base node is a free node.  
            IF(EXNODT(6,BASE_NODE_NUMBER).EQ.NULL.OR.
     A         EXNODT(7,BASE_NODE_NUMBER).EQ.NULL) THEN
              WRITE(STDOUT,50) BASE_NODE, GETUSN(I)
              EFLAG = 1
              STOP 'Abnormal stop.  Error(s) found.'
            ENDIF
C           Convert to REAL
            XBASE = DBLE(EXNODT(6,BASE_NODE_NUMBER))/100.D0
            YBASE = DBLE(EXNODT(7,BASE_NODE_NUMBER))/100.D0
          ENDIF

C         We now have the base location.  Add the offsets to get
C         the final location.
          IF(EXNODT(6,I).EQ.NULL.OR.EXNODT(7,I).EQ.NULL) THEN
            WRITE(STDOUT,52) GETUSN(I)
            EFLAG = 1
            STOP 'Abnormal stop.  Error(s) found.'
          ENDIF
          
          XLOC = XBASE + DBLE(EXNODT(6,I))/100.D0
          YLOC = YBASE + DBLE(EXNODT(7,I))/100.D0
C         Rescale and convert to integer again.
          EXNODT(6,I) = NINT(XLOC*100.D0)
          EXNODT(7,I) = NINT(YLOC*100.D0)
        ENDIF
500   CONTINUE
      RETURN
      END          
C
C
C
      SUBROUTINE DRAW_LPR_GRAPHIC(SCMUNIT, NODE_KNT, X, Y, DNNLABEL)

C     Draw the graphic for a LPR

      IMPLICIT NONE
      INTEGER SCMUNIT, NODE_KNT
      REAL*8 X(NODE_KNT), Y(NODE_KNT)
      CHARACTER DNNLABEL*5
      
C     Called program units.
      EXTERNAL STRIP_ALL_BLANKS,FIND_LINE_COEF, FIND_PERPENDICULAR


C     Local 

      INTEGER SLEN

      REAL*8 A, B, C, AP, BP, CP, DX, DY, XTICK, YTICK, M, D, R,
     A       XC, YC, XL, YL, XR, YR

      CHARACTER LINE*80

C***********************************************************************
C     Compute the diameter of the circle.
      D = SQRT((X(2) - X(1))**2 + (Y(2) - Y(1))**2)
      R = 0.4*D

C     Issue the 2-point circle command
      WRITE(SCMUNIT,'(A,/,A)') 'CIRCLE','2P'
      WRITE(LINE,'(F13.2,'','',F13.2)') X(1), Y(1)
      CALL STRIP_ALL_BLANKS(
     M                      LINE,
     O                      SLEN)
      WRITE(SCMUNIT,'(A)') LINE(1:SLEN)
      WRITE(LINE,'(F13.2,'','',F13.2)') X(2), Y(2)
      CALL STRIP_ALL_BLANKS(
     M                      LINE,
     O                      SLEN)
      WRITE(SCMUNIT,'(A)') LINE(1:SLEN)


C     Find the coef. of the line that passes through the 
C     diameter line segment.

      CALL FIND_LINE_COEF(X(1), Y(1), X(2), Y(2),
     O                    A, B, C)

C     Find the coef. of the line that is perpendicular to the 
C     line just found and also passes through [X(2), Y(2)],
C     the downstream node of the LPR.

      CALL FIND_PERPENDICULAR(X(2), Y(2), A, B, C,
     O                        AP, BP, CP)

C     Compute the slope of the perpendicular line,  The general
C     equation for this line is: AP*X + BP*Y + CP = 0.  We solve
C     for M in the equation:  Y = M*X + Q, where M is the slope and
C     Q is the intercept.  This yields:  M = -AP/BP.  BP may be zero,
C     however both LF90 and LF95 include the IEEE floating point extensions
C     that include infinity in a logical manner.  Division by zero yields
C     infinity of the proper sign assuming the numerator of the ratio is
C     not also zero.  If it is zero we get Not a Number as the result. 
C     Division of any non-zero by infinity yields zero.

      M = -AP/BP

      WRITE(SCMUNIT,'(A)') 'PLINE'
      DX = R/SQRT(1.D0 + M**2)     
      DY = R/SQRT(1.D0 + 1.D0/M**2)

      IF(M.GT.0.D0) THEN
        XTICK = X(2)  +  DX
        YTICK = Y(2)  +  DY
      ELSE
        XTICK = X(2)  +  DX
        YTICK = Y(2)  -  DY
      ENDIF  

      WRITE(LINE,'(F13.2,'','',F13.2)') XTICK, YTICK
      CALL STRIP_ALL_BLANKS(
     M                      LINE,
     O                      SLEN)
      WRITE(SCMUNIT,'(A)') LINE(1:SLEN)
      
      IF(M.GT.0.D0) THEN
        XTICK = X(2)  - DX
        YTICK = Y(2)  - DY
      ELSE
        XTICK = X(2) - DX
        YTICK = Y(2) + DY
      ENDIF
      WRITE(LINE,'(F13.2,'','',F13.2)') XTICK, YTICK
      CALL STRIP_ALL_BLANKS(
     M                      LINE,
     O                      SLEN)
      WRITE(SCMUNIT,'(A)') LINE(1:SLEN)

      WRITE(SCMUNIT,'( )') 

C     Label the LPR with its downstream node label on a horizontal
C     line a bit below the center of the circle. 
      XC = 0.5*(X(1) + X(2))
      YC = 0.5*(Y(1) + Y(2))
C     Drop the line by a fraction of the diameter
      DY = 0.1*D
      DX = 0.35*D
      XL = XC - DX
      YL = YC - DY
      XR = XC + DX
      YR = YC - DY

C     Now do the text insertion
      WRITE(SCMUNIT,'(A,/,A)') 'TEXT', 'A'
      WRITE(LINE,'(F13.2,'','',F13.2)') XL, YL
      CALL STRIP_ALL_BLANKS(
     M                      LINE,
     O                      SLEN)
      WRITE(SCMUNIT,'(A)') LINE(1:SLEN)
      WRITE(LINE,'(F13.2,'','',F13.2)') XR, YR
      CALL STRIP_ALL_BLANKS(
     M                      LINE,
     O                      SLEN)
      WRITE(SCMUNIT,'(A)') LINE(1:SLEN)

      WRITE(SCMUNIT,'(A5)') DNNLABEL

      
      RETURN
      END
C
C
C
      SUBROUTINE DO_LPRS(STDOUT, SCMUNIT, NEX,
     I            EXNODT, EMC)
        
C     Do level-pool reservoirs in a schematic

      IMPLICIT NONE
      INCLUDE 'arsize.prm'
      INTEGER NEX, STDOUT, EXNODT(9,NEX),
     A        EMC(MREMC), SCMUNIT

C     EXNODT - exterior node table.  Contains the following items
C              for each exterior node.
C              Row   Content
C               1    sign of the node
C               2    pointer into vectors for nodes on a branch
C               3    descriptive code: if -1 then a reservoir;
C                    if  0 then not on a branch and not a reservoir;
C                    if > 0 then a branch number
C               4    pointer to a cross section table if on a branch, 
C                    to storage table if a reservoir, to other node if
C                    a dummy branch
C               5    gives the variable number(in the system matrix) for
C                    the flow at the exterior node. Also a junction
C                    pointer in initial processing of input
      
                    
      INCLUDE 'matcom.cmn'
 

C     Called program units
      CHARACTER GETUSN*5
      EXTERNAL GETUSN, STRIP_ALL_BLANKS, FIND_PERPENDICULAR,
     A         FIND_LINE_COEF

C     Local
      INTEGER CODE, IENTRY, IPNT, UPN, DNN, NULL, UPNFLAG, DNNFLAG,
     A        NODE_KNT

      REAL*8 UPNX, UPNY, DNNX, DNNY, X(2), Y(2)

      CHARACTER UPNLABEL*5, DNNLABEL*5


      DATA NULL/-2147483647/

C     **************************FORMATS*********************************
52    FORMAT(';',' LPR with free nodes: ',A5,', ',A5)
C***********************************************************************
C     General approach:
C     1. Scan EMC for LPR's
C     2. For each LPR extract the ups and dns node numbers
C     2.1 Check in EXNODT, in rows 6 and 7 to see if (x,y) is known for
C         this LPR.   If not don't draw it!


C     Start loop seaching for LPR's.  CODE=7
      IENTRY = 0
 
 100  CONTINUE
        IENTRY = IENTRY + 1
        IPNT = ADD(IENTRY)
        CODE = EMC(IPNT)
        IF(CODE.EQ.7) THEN
C         Get the ups and dns node numbers
          UPN = EMC(IPNT+5)
          DNN = EMC(IPNT+1)
          UPNLABEL = GETUSN(UPN)
          DNNLABEL = GETUSN(DNN)
          
C         Clear the location flags
          UPNFLAG = 0
          DNNFLAG = 0

C         Check to see if these nodes have a location given in EXNODT
          IF(EXNODT(6,UPN).GT.NULL) THEN
            UPNFLAG = 1
            UPNX = DBLE(EXNODT(6,UPN))/100.D0
            UPNY = DBLE(EXNODT(7,UPN))/100.D0
          ENDIF
          IF(EXNODT(6,DNN).GT.NULL) THEN
            DNNFLAG = 1
            DNNX = DBLE(EXNODT(6,DNN))/100.D0
            DNNY = DBLE(EXNODT(7,DNN))/100.D0
          ENDIF


          IF(UPNFLAG.EQ.1.AND.DNNFLAG.EQ.1) THEN
C           We can draw the LPR.
     
            X(1) = UPNX
            Y(1) = UPNY
            X(2) = DNNX
            Y(2) = DNNY
            NODE_KNT = 2
            WRITE(SCMUNIT,52) UPNLABEL, DNNLABEL
            CALL DRAW_LPR_GRAPHIC(SCMUNIT, NODE_KNT, X, Y, DNNLABEL)
          ENDIF
        ENDIF
 
        IF(CODE.GT.0) THEN
C         Continue the search.
          GOTO 100
        ENDIF

      RETURN
      END
C
C
C
      SUBROUTINE CONNECT_DISTANT_ITEMS(STDOUT, SCMUNIT, NEX, 
     A                                 EXNODT, EMC)


C     Connect items that are distant from one another so that 
C     the flow of water between them is evident.  Only applies
C     to nodes on reservoirs and branches.  Nodes on dummy 
C     branches are excluded.

      IMPLICIT NONE
      INCLUDE 'arsize.prm'
      INTEGER NEX, STDOUT, EXNODT(9,NEX),
     A        EMC(MREMC), SCMUNIT



      INCLUDE 'bnothr.cmn'
      INCLUDE 'matcom.cmn'


C     Called program units
      REAL*8 GET_DP_FROM_FT
      CHARACTER*5 GETUSN
      EXTERNAL GET_DP_FROM_FT, STRIP_ALL_BLANKS, GETUSN



C     Local
      INTEGER ADRS, CODE, IENTRY, IPNT, I, J, N, KNT,
     A        CLASSI, CLASSJ, NULL, NODEI, NODEJ, LOCI, LOCJ, SLEN,
     B        NODE

      REAL*8 DIST, XI, YI, XJ, YJ, DNULL

      CHARACTER LINE*80, UPNLABEL*5, DNNLABEL*5

      DATA DNULL/-33D6/, NULL/-2147483647/
C     ***************************FORMATS********************************
52    FORMAT(';',' Connection between nodes: ',A5,', ',A5,' D=',F10.1)
C***********************************************************************
C     Scan over all CODE 2 entries and check all unique pairs of nodes
C     in the junction

C     Select the layer
      WRITE(SCMUNIT,'(A)') 'LAYER','MAKE','DOT_CNCT'
      write(scmunit,'( )')

      IENTRY = 0

 100  CONTINUE
        IENTRY = IENTRY + 1
        IPNT = ADD(IENTRY)
        CODE = EMC(IPNT)
        IF(CODE.EQ.2) THEN
          N = EMC(IPNT+1)
C         If there is only one upstream node in a junction
C         and all other nodes are downstream, then we connect
C         that upstream node to any other node that is far enough
C         away.  If there is more than one upstream node, then
C         check to see if there is only a single downstream node in
C         the junction.  
          KNT = 0
          
          DO 150 I=1,N
C           Search for an upstream node in the junction. 
            NODE = EMC(IPNT+1+I)
            IF(EXNODT(1,NODE).LT.0) THEN
C             We have one. 
              KNT = KNT + 1
              NODEI = NODE
            ENDIF
150       CONTINUE

          IF(KNT.GT.1) THEN
C           See if there is a single downstream node
            KNT = 0
            DO 160 I=1,N
C             Search for a downstream node in the junction. 
              NODE = EMC(IPNT+1+I)
              IF(EXNODT(1,NODE).GT.0) THEN
C               We have one. 
                KNT = KNT + 1
                NODEI = NODE
              ENDIF
160         CONTINUE
          ENDIF  
          IF(KNT.EQ.1) THEN
C           Draw connections only if there is exactly one downstream or 
C           one upstream node.
C           Get the location for this node.
            CLASSI = EXNODT(3,NODEI)
            IF(CLASSI.GT.0) THEN
C             We have a branch.  Get the (x,y) from the 
C             cross-section-function table
              ADRS = EXNODT(4,NODEI)
              XI = GET_DP_FROM_FT(ADRS+8)
              YI = GET_DP_FROM_FT(ADRS+10)
              IF(XI.GT.DNULL) THEN
C               Location is known. 
                LOCI = 1
              ELSE
                LOCI = 0
              ENDIF
            ELSE
C             We have a free node.  Check to see if its location
C             is known. 
              IF(EXNODT(6,NODEI).GT.NULL) THEN
C               Location is known
                XI = DBLE(EXNODT(6,NODEI))/100.D0
                YI = DBLE(EXNODT(7,NODEI))/100.D0
                LOCI = 1
              ELSE
                LOCI = 0
              ENDIF
            ENDIF
            

            DO 190 J=1,N
              NODEJ = EMC(IPNT+1+J)
              IF(NODEJ.NE.NODEI) THEN
                CLASSJ = EXNODT(3,NODEJ)
                IF(CLASSJ.GT.0) THEN
C                 We have a branch.  Get the (x,y) from the 
C                 cross-section-function table
                  ADRS = EXNODT(4,NODEJ)
                  XJ = GET_DP_FROM_FT(ADRS+8)
                  YJ = GET_DP_FROM_FT(ADRS+10)
                  IF(XJ.GT.DNULL) THEN
C                   Location is known. 
                    LOCJ = 1
                  ELSE
                    LOCJ = 0
                  ENDIF
                ELSE
C                 We have a free node.  Check to see if its location
C                 is known. 
                  IF(EXNODT(6,NODEJ).GT.NULL) THEN
C                   Location is known
                    XJ = DBLE(EXNODT(6,NODEJ))/100.D0
                    YJ = DBLE(EXNODT(7,NODEJ))/100.D0
                    LOCJ = 1
                  ELSE
                    LOCJ = 0
                  ENDIF
                ENDIF
                IF(LOCI.EQ.1.AND.LOCJ.EQ.1) THEN
C                 We have locations for both nodes.  Compute 
C                 distance between them.  
                  DIST = SQRT( (XI - XJ)**2 + (YI - YJ)**2)
                  IF(DIST.GT.150.D0) THEN
C                   We have a case for drawing a dotted line to 
C                   indicate a connection. 
                    UPNLABEL = GETUSN(NODEI)
                    DNNLABEL = GETUSN(NODEJ)
                    WRITE(SCMUNIT,52) UPNLABEL, DNNLABEL, DIST
                
                    WRITE(SCMUNIT,'(A)') 'PLINE'
                    WRITE(LINE,'(F13.2,'','',F13.2)') XI, YI
                    CALL STRIP_ALL_BLANKS(
     M                                    LINE,
     O                                    SLEN)
                    WRITE(SCMUNIT,'(A)') LINE(1:SLEN)
                    
                    WRITE(LINE,'(F13.2,'','',F13.2)') XJ, YJ
                    CALL STRIP_ALL_BLANKS(
     M                                    LINE,
     O                                    SLEN)
                    WRITE(SCMUNIT,'(A)') LINE(1:SLEN)
                    
                    WRITE(SCMUNIT,'( )')
                  ENDIF
                ENDIF
              ENDIF
          
190         CONTINUE
          ENDIF
        ENDIF
        IF(CODE.GT.0) THEN
C         Continue the search.
          GOTO 100
        ENDIF

300   CONTINUE
      RETURN
      END


C
C
C
      SUBROUTINE OUTPUT_SCHEMATIC_SCRIPT(STDOUT, NBRA, NEX, BRPT, 
     I            EXNODT, EMC)

C     Create an IntelliCAD 2000 script to create a draft schematic
C     of the model. 

      IMPLICIT NONE
      INCLUDE 'arsize.prm'
      INTEGER NBRA, NEX, STDOUT, BRPT(8,NBRA), EXNODT(9,NEX),
     A        EMC(MREMC)

C     BRPT   - branch pointer table.  Values for each branch are:
C              ROW       Meaning
C              1         upstream user node number
C              2         downstream user node number
C              3         pointer into branch vector for upstream node
C              4         pointer into branch vector for downstream node
C              5         upstream exterior node number
C              6         downstream exterior node number
C              7         pointer to address in EMC for the branch
C              8         number of unknowns at a node for the branch


C     Called program units
      INTEGER GET_UNIT, GETUSB
      REAL*8 GET_DP_FROM_FT
      EXTERNAL GET_UNIT, FREE_UNIT, GETUSB, FIND_LINE_COEF,
     A        STRIP_ALL_BLANKS, DRAW_BRANCH_GRAPHIC, os_file_style

      INCLUDE 'bnothr.cmn'
      INCLUDE 'home.cmn'
    
C     Local

      INTEGER  ADRS, I, J, UPSNODE, DNSNODE, NODE_KNT, SCMUNIT,
     A         SLEN, USB, MODE

      REAL*8 X(MNBN), Y(MNBN), A, B, C, AP, BP, CP, HALF_L, M,
     A       DX, DY, XMID, YMID, XS, YS, XE, YE, FACTOR,
     B       MINOR_AXIS, BL, HLTMP, DDX, DDY, LF, HF, SHIFT
      CHARACTER LINE*80, BRAN*4

      DATA HALF_L/25.D0/,LF/2.D0/, HF/5.D0/
C     ****************************FORMATS*******************************      
50    FORMAT('; Branch number is:',I6)
C***********************************************************************
C     Make sure the local home-directory name is cleared.  Otherwise
C     we might end up putting schematic.scr in the home directory for
C     the function-table files!
      CALL CLEAR_HOME()

C     Try scaling to get better results for less detailed schematics
      FACTOR = 1.5D0
      HALF_L = FACTOR*HALF_L
      LF = FACTOR*LF
      HF = FACTOR*HF

      SCMUNIT = GET_UNIT(0)
      IF(GHOME_out.NE.' ') THEN
C       A global home directory name exists.  Put the script file there.
        LINE = '/schematic.scr'
        CALL MAYBE_ADD_GHOME_out(
     M                      LINE)
      ELSE
C       No global home directory exists.  Put script in the current directory.
        LINE = 'schematic.scr'
      ENDIF  

      call os_file_style(
     m                     line)
      OPEN(UNIT=SCMUNIT, FILE=LINE, STATUS='UNKNOWN')

C     Set the line-type-scale
      WRITE(SCMUNIT,'(A)') 'ltscale', '500.0'

C     Select the layer for branches
      WRITE(SCMUNIT,'(A)') 'LAYER','MAKE','BRANCHES'
      write(scmunit,'( )')

C     Scan all branches and output the trace of each 

      DO 500 I=1,NBRA
        USB = GETUSB(I)
        WRITE(BRAN,'(I4)') USB
        UPSNODE = BRPT(3,I)
        DNSNODE = BRPT(4,I)
        NODE_KNT = 0
        DO 100 J=UPSNODE, DNSNODE
          NODE_KNT = NODE_KNT + 1
          ADRS = NSEC(J)
          X(NODE_KNT) = GET_DP_FROM_FT(ADRS+8)
          Y(NODE_KNT) = GET_DP_FROM_FT(ADRS+10)
100     CONTINUE

C       Output a comment giving the external branch number
        WRITE(SCMUNIT,50) USB

C       MODE not now used-maybe later
        MODE = 2
        CALL DRAW_BRANCH_GRAPHIC(MODE, SCMUNIT, NODE_KNT, X, Y,
     I           HALF_L)

C       Now label the branch.  Use these rules as a start:
C       1. Place branch number in a circle of radius 1.2 * 
C          the tick length if the tick length is >= the 
C          straightline distance from start to end of branch.
C       2. Place label on line perpendicular to the strightline
C          from one end to the other.  Put center of circle at
C          twice its diameter from the line.  

C       Find coef. for line connecting end points of branch


        CALL FIND_LINE_COEF(X(1), Y(1), X(NODE_KNT), Y(NODE_KNT),
     O                      A, B, C)

C       Compute midpoint of this line segment
        XMID = 0.5D0*(X(1) + X(NODE_KNT))
        YMID = 0.5D0*(Y(1) + Y(NODE_KNT))

C       Find coef. for the line perpendicular to the branch line segment
        CALL FIND_PERPENDICULAR(XMID, YMID, A, B, C,
     O                          AP, BP, CP)

        M = -AP/BP

C       Reduce scale if branch is too short.
        BL = SQRT( (X(1) - X(NODE_KNT))**2 + 
     A             (Y(1) - Y(NODE_KNT))**2)
        IF(BL.LT.2.0*HALF_L) THEN
          HLTMP = 0.5*BL
        ELSE
          HLTMP = HALF_L
        ENDIF
    
        DX = HLTMP/SQRT(1.D0 + M**2)     
        DY = HLTMP/SQRT(1.D0 + 1.D0/M**2)

        IF(M.GT.0.D0) THEN
          XS = XMID  + LF*DX 
          YS = YMID  + LF*DY
          XE = XMID  + HF*DX 
          YE = YMID  + HF*DY
        ELSE
          XS = XMID  +  LF*DX 
          YS = YMID  -  LF*DY
          XE = XMID  +  HF*DX 
          YE = YMID  -  HF*DY
        ENDIF

C       Now do the text insertion
        WRITE(SCMUNIT,'(A,/A)') 'TEXT', 'A'
        WRITE(LINE,'(F13.2,'','',F13.2)') XS, YS
        CALL STRIP_ALL_BLANKS(
     M                        LINE,
     O                        SLEN)
        WRITE(SCMUNIT,'(A)') LINE(1:SLEN)
        WRITE(LINE,'(F13.2,'','',F13.2)') XE, YE
        CALL STRIP_ALL_BLANKS(
     M                        LINE,
     O                        SLEN)
        WRITE(SCMUNIT,'(A)') LINE(1:SLEN)

        WRITE(SCMUNIT,'(A4)') BRAN

C       Do an ellipse around the text.
C       Shift the midpoint to center around branch label
        SHIFT = 0.18*(HF - LF)*HLTMP
        DDX = SHIFT/SQRT(1.D0/M**2 + 1.D0)
        DDY = SHIFT/SQRT(M**2 + 1.D0)

        IF(M.GT.0.D0) THEN
          DDX = -DDX
        ENDIF
          
        XMID = XMID + DDX
        YMID = YMID + DDY

        IF(M.GT.0.D0) THEN
          XS = XMID  +  (LF - 1.)*DX 
          YS = YMID  +  (LF - 1.)*DY
          XE = XMID  +  (HF + 1.)*DX 
          YE = YMID  +  (HF + 1.)*DY
        ELSE
          XS = XMID  +  (LF - 1.)*DX 
          YS = YMID  -  (LF - 1.)*DY
          XE = XMID  +  (HF + 1.)*DX 
          YE = YMID  -  (HF + 1.)*DY
        ENDIF
        
        MINOR_AXIS = FACTOR*HLTMP

        WRITE(SCMUNIT,'(A)') 'ELLIPSE'
        WRITE(LINE,'(F13.2,'','',F13.2)') XS, YS
        CALL STRIP_ALL_BLANKS(
     M                        LINE,
     O                        SLEN)
        WRITE(SCMUNIT,'(A)') LINE(1:SLEN)
        WRITE(LINE,'(F13.2,'','',F13.2)') XE, YE
        CALL STRIP_ALL_BLANKS(
     M                        LINE,
     O                        SLEN)
        WRITE(SCMUNIT,'(A)') LINE(1:SLEN)
        WRITE(LINE,'(F10.2)') MINOR_AXIS
        CALL STRIP_ALL_BLANKS(
     M                        LINE,
     O                        SLEN)
        WRITE(SCMUNIT,'(A)') LINE(1:SLEN)

500   CONTINUE


C     Select the layer for Dummy branches
      WRITE(SCMUNIT,'(A)') 'LAYER','MAKE','DUMBR',' '

C     Now do the dummy branches 
      CALL DO_DUMMY_BRANCHES(STDOUT, SCMUNIT, NBRA, NEX, BRPT, 
     I            EXNODT, EMC, HALF_L)


C     Select the layer for LPR's
      WRITE(SCMUNIT,'(A)') 'LAYER','MAKE','LPRS'
      write(scmunit,'( )')

      CALL DO_LPRS(STDOUT, SCMUNIT, NEX, EXNODT, EMC)


C     Draw dotted lines to connect items that are more than
C     about 100 feet apart. 
      
      CALL CONNECT_DISTANT_ITEMS(STDOUT, SCMUNIT, NEX, EXNODT, EMC)
 
      CALL FREE_UNIT(STDOUT, SCMUNIT)
      RETURN
      END      
