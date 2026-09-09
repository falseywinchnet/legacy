C     Code for checking conditions at side weirs
C
C
C
      SUBROUTINE   SIDE_WEIR_CHK
     I                   (STDOUT, GRAV, NEX, EXNODT, EPT,
     M                    EMC)
 
C     + + + PURPOSE + + +
C     Checks validity of side-weir configuration.  We assume that
C     side weirs are rarely active at the start of the run.  Thus
C     the initial version of this code will check to see if the
C     side weir is active and if its datum for head makes sense
C     for the given conditions in the source and desintation nodes. 
 
      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EPT, STDOUT, NEX
      INTEGER EMC(EPT), EXNODT(9,NEX)
      REAL GRAV
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     GRAV - gravitational acceleration
C     NEX    - number of exterior nodes in the model
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
C     EMC    - vector containing coded form of the Matrix Control Input
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'ftable.cmn'
      INCLUDE 'enelem.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER ADRS, CODE, DNN, IDUM, ITYPE, J, 
     A         MDN, UPN, TADRS
      REAL  HBASE, HDATUM, RDUM, ZUP, ZMID, ZBUP, ZBMID,
     A      MAX_DIFF, MAX_DIFF_IN_FEET
     
      CHARACTER INVERT_HIGH *4, Q_NON_ZERO*4, DISABLED*4

C     + + + EQUIVALENCES + + +
      EQUIVALENCE (IDUM,RDUM)
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS, FLOAT, SIGN
 
C     + + + EXTERNAL FUNCTIONS + + +
      INTEGER GETTBN
      REAL GETHDD, GET_SLOT_DEPTH
      CHARACTER GETUSN*5,  GET_TABID*16
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL GETHDD, GETTBN, GETUSN, GET_SLOT_DEPTH,
     A         GET_TABID
 
C     + + + OUTPUT FORMATS + + +
50    FORMAT(/,' Starting check of Side-Weir Instructions')
51    FORMAT(/,' End  check of Side-Weir Instructions')
53    FORMAT(
     A'   Ups    Invert  Wat-Surf   Dns   Mid    Invert  Wat-Surf  ',
     B'Hd-Datum  Invert    Flow  Dis-  ',/,
     C'  Node Elevation Elevation  Node  Node Elevation Elevation ',
     D'Elevation    High NonZero   abled',/,
     E' ----- --------- --------- ----- ----- --------- ---------',
     F' --------- ------- ------- -------')

54    FORMAT(1X,A5,F10.3,F10.3,1X,A5,1X,A5,F10.3,F10.3,F10.3,4X,A4,
     A       4X,A4,4X,A4)
C***********************************************************************
      MAX_DIFF_IN_FEET = 0.1
C     Set the maximum difference allowed in water-surface elevation.
      IF(GRAV.LT.16.0) THEN
        MAX_DIFF = MAX_DIFF_IN_FEET*0.3048
      ELSE
        MAX_DIFF = MAX_DIFF_IN_FEET
      ENDIF
C     START THE LOOP OVER THE instructions
      WRITE(STDOUT,50) 
      WRITE(STDOUT, *) ' '
      WRITE(STDOUT,53)
      J = EMC(1)
 1000 CONTINUE
         CODE = EMC(J)
         IF(CODE.EQ.-1) GOTO 2000
         GOTO(1,2,3,4,5,6,7,8,9,10, 10, 10, 10, 14, 10),CODE
           WRITE(STDOUT,*)' *BUG:20* INVALID EMC CODE IN FINCHK. CODE=',
     A                  CODE
            STOP 'Abnormal stop: errors found.'
 1       CONTINUE
            GOTO 1500
 2       CONTINUE
            J = J+EMC(J+1)
            GOTO 1500
 3       CONTINUE
            GOTO 1500
 4       CONTINUE
 
         GOTO 1500
 5       CONTINUE
           ITYPE = EMC(J+1)
           UPN = EMC(J+2)
           DNN = EMC(J+3)
           GOTO(501, 502, 503, 504, 505, 506, 507, 508, 509), ITYPE
             WRITE(STDOUT,*) ' *BUG:21* INVALID CODE=5 TYPE IN FINCHK.',
     A                 ' TYPE=', ITYPE
             STOP 'Abnormal stop: errors found.'
 501       CONTINUE
             J = J + CD5TY1
             GOTO 599
 502       CONTINUE
             J = J + CD5TY2
             GOTO 599
 
 503       CONTINUE
 
             J = J + CD5TY3
             GOTO 599
 
 504       CONTINUE
             J = J + CD5TY4
             GOTO 599
 
 505       CONTINUE
             J = J + CD5TY5
             GOTO 599
 506       CONTINUE
             J = J + 1 + ABS(EMC(J+6))*CD5TY6
             GOTO 599
 507       CONTINUE
             J = J + CD5TY7
             GOTO 599
 508       CONTINUE
             J = J + CD5TY8
             GOTO 599
 509       CONTINUE
             J = J + CD5TY9
             GOTO 599
 
 599       CONTINUE
         GOTO 1500
 
 6       CONTINUE
           GOTO 1500
 
 7       CONTINUE
           GOTO 1500
 8       CONTINUE
            GOTO 1500
 9       CONTINUE
            GOTO 1500
 
 10      CONTINUE
           GOTO 1500
 14      CONTINUE
C          Check the status of the side weir to make sure it
C          is consistent with the computed initial condition. 

           UPN = EMC(J+1)
           DNN = EMC(J+2)
           MDN = EMC(J+3)
           ADRS = EMC(J+4)
C          Get the head datum from the 2-D table.  
           HDATUM = GETHDD(ADRS)

C          Get the invert elevations.  We assume that the
C          and free nodes have had their invert elevation set 
C          to match the invert elevation of the node to which
C          they are tied.  This is done automatically for dummy 
C          branches tied to branches via an EqZ instruction.
           ZBUP = ZE(UPN) 
           ZBMID = ZE(MDN)

C          Get the water-surface elevations.
           ZUP = ZBUP + YE1(UPN)
           ZMID = ZBMID + YE1(MDN)

C          Adjust invert to true invert in case the cross section
C          has a bottom slot.
           TADRS = EXNODT(4,UPN)
C          Slot depth is relative to the true invert.  Thus it is
C          < 0 if a slot is present.  Note that the side-weir instruction
C          requires that the ups and dsn nodes have cross sections. 
C          The depth already includes the slot so we  must adjust
C          the invert after we compute the water-surface elevation!
           ZBUP = ZBUP - GET_SLOT_DEPTH(TADRS)

C          Set the values to the default
           INVERT_HIGH = 'NO'
           Q_NON_ZERO = 'NO'

           IF(ZBUP.GT.HDATUM.OR.ZBMID.GT.HDATUM) THEN
C            Major problem.  One or both of the invert elevations
C            is greater than the elevation datum for head
             INVERT_HIGH = 'YES'
           ENDIF
           IF(ZUP.GT.HDATUM.OR.ZMID.GT.HDATUM) THEN
             IF(ZUP.NE.ZMID) THEN
               Q_NON_ZERO = 'YES'
             ENDIF
           ENDIF
           IF(INVERT_HIGH.NE.'NO'.OR.Q_NON_ZERO.NE.'NO') THEN
             IF(ABS(ZUP - ZMID).GT.MAX_DIFF) THEN
C              Set datum very high.
               DISABLED = 'YES'
               RDUM = 99999.0
               EMC(J+9) = IDUM
             ELSE
               DISABLED = 'NO'
             ENDIF
             WRITE(STDOUT,54) GETUSN(UPN), ZBUP, ZUP, GETUSN(DNN),
     A                        GETUSN(MDN), ZBMID, ZMID, HDATUM,
     B                        INVERT_HIGH, Q_NON_ZERO, DISABLED
           ENDIF

           GOTO 1500
 1500 CONTINUE
        J = J + EMC(CODE+1)
      GOTO 1000
 2000 CONTINUE
      WRITE(STDOUT,51)
      RETURN
      END
