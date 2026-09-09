C Routines used in function table lookup                                  
C                                                                               
C                                                                               
C
C
C
      SUBROUTINE   GETYQC
     I                   (ADRS, TYPE,
     O                    NDEP, Y, QC)
 
C     + + + PURPOSE + + +
C     Extract depth and critical flow values from tables of type 22
C     or 25
      IMPLICIT NONE
 
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER ADRS, NDEP, TYPE
      REAL*8 QC(MNDEP), Y(MNDEP)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     TYPE   - type of the cross section function table
C     NDEP   - number of depth values
C     Y      - depth values
C     QC     - critical flow
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'ftable.cmn'
      INCLUDE 'offcom.cmn'
 
C     + + + LOCAL VARIABLES + + +
      INTEGER HA, I, J, LA, XOFF
C***********************************************************************
C     Get the addresses in the table. HA=high address, for the last
C     argument in the table; LA=low address, for the first argument
C     in the table.
 
      HA = ITAB(ADRS)
      LA = ADRS + XTIOFF
      XOFF = OFFVEC(TYPE)
 
C     Critical flow is always at offset 7 and depth is at offset 0.
 
      J = 0
      DO 100 I=LA,HA,XOFF
        J = J + 1
        Y(J) = FTAB(I)
        QC(J) = FTAB(I+7)
 100  CONTINUE
 
C     Set number of depth values.
      NDEP = J
 
      RETURN
      END
C
C
C
      SUBROUTINE   TDLK14
     I                   (STDOUT, IP, PTYPE, EDA, HBASE,
     M                    QARG,
     O                    HU, DHUED, DHUQ, FREE)
 
C     + + + PURPOSE + + +
C     Do 2-d lookup for flow for tables of type 14.  The arguments
C     are flow at the flow node and the downstream elevation.

      IMPLICIT NONE 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER FREE, IP, STDOUT, PTYPE
      REAL DHUED, DHUQ, EDA, HBASE, HU, QARG
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     IP     - address of the table
C     PTYPE  - expected table type
C     EDA    - water surface elevation at downstream node
C     HBASE  - datum for heads
C     QARG   - flow argument for table lookup
C     HU     - head at upstream node
C     DHUED  - derivative of upstream head wrt downstream
C               water surface elevation
C     DHUQ   - derivative of upstream head wrt flow
C     FREE   - flag for free flow
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'
 
C     Called subprograms
      CHARACTER*16 GET_TABID
      EXTERNAL GET_TABID      

C     + + + LOCAL PARAMETERS + + +
      INTEGER INC
      PARAMETER(INC=4)
 
C     + + + LOCAL VARIABLES + + +
      INTEGER LHD, LHU, LPFQ, LQF, OFFL, OFFR, TAB, TYPE
      REAL DHD, DHHDP, DHLP, DHP, DHRP, DQFHD, ED, HD, HDL, HDMAX, HDR,
     A     HL, HLD, HLU, HR, HRD, HRU, HUL, HUR, P, PD, PU, QFL, QFR,
     B     QFREE, QL, QMAX, QR
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT(/,' *BUG:XXX* NEGATIVE QARG IN TDLK14=',F10.2,' TABID=',A)
 52   FORMAT(/,' *WRN:43* FLOW > MAXFLOW IN TWO-D TABID=',A,' FLOW=',
     A       F10.2,' MAXFLOW=',F10.2)
 54   FORMAT(/,' *ERR:73* Unexpected type in two-D TABID=',A,
     A       ' Type=',I5,' Expected Type=',I5)
 56   FORMAT(/,' *WRN:44* HDN > MAXHDN IN TWO-D TABID=',A,' HDN=',
     A       F10.2,' MAXHDN=',F10.2)
C***********************************************************************
C     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT
C     POINTERS ARE SET TO THE PROPER VALUES AT START
 
      TAB = ITAB(IP+1)
      TYPE = ITAB(IP+2)
 
 
      ED = EDA
 
C      WRITE(STDOUT,*) 'TDLK14: TAB#=',TAB, ' QARG=',QARG,' ED=',ED
 
      IF(TYPE.NE.PTYPE) THEN
        WRITE(STDOUT,54) GET_TABID(TAB), TYPE, PTYPE
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
 
      HD = ED - HBASE
 
C      WRITE(STDOUT,*) 'TDLK14: HBASE=',HBASE, ' HD=',HD
 
C     FIND THE DOWNSTREAM HEAD INTERVAL CONTAINING HD.
C     FIRST MAKE SURE THAT HD IS WITHIN VALID RANGE.
 
      HDMAX = FTAB(IP+5)
 
      IF(HD.GT.HDMAX) THEN
        WRITE(STDOUT,56)  GET_TABID(TAB), HD, HDMAX
        HD = HDMAX
      ENDIF
 
      IF(HD.LT.0.0) HD = 0.0
 
C     NOW THAT HD IS IN THE VALID RANGE SEARCH FOR THE INTERVAL
 
      LHD = ITAB(IP+3)
C      WRITE(STDOUT,*) ' LHD=',LHD,' HDMAX=',HDMAX
 
      IF(HD.GE.FTAB(LHD)) THEN
 200    CONTINUE
          IF(HD.LE.FTAB(LHD+INC)) GOTO 220
          LHD = LHD + INC
          GOTO 200
      ELSE
 210    CONTINUE
          LHD = LHD - INC
          IF(HD.GE.FTAB(LHD)) GOTO 220
          GOTO 210
      ENDIF
 220  CONTINUE
      ITAB(IP+3) = LHD
 
C     NOW INTERPOLATE FOR THE VALUE OF FREE FLOW WHICH CORRESPONDS
C     TO INCIPIENT SUBMERGENCE AT HD.
 
      QFL = FTAB(LHD-1)
      QFR = FTAB(LHD+INC-1)
      HDL = FTAB(LHD)
      HDR = FTAB(LHD+INC)
 
      DQFHD = (QFR - QFL)/(HDR - HDL)
      QFREE = QFL + DQFHD*(HD - HDL)
 
C     DQFHD GIVES THE RATE OF CHANGE OF THE FREE FLOW AT INCIPIENT
C     SUBMERGENCE WITH RESPECT TO THE DOWNSTEAM HEAD.
 
      IF(QARG.GE.QFREE) THEN
C       FLOW IS FREE.  NOW FIND THE VALUE OF UPSTREAM HEAD WHICH
C       CORRESPONDS TO FREE FLOW IF QARG > 0.  MUST SEARCH FREE FLOW
C       LIST USING  QARG.
 
        QMAX = FTAB(IP+9)
 
        IF(QARG.GT.QMAX) THEN
          WRITE(STDOUT,52) GET_TABID(TAB), QARG, QMAX
          QARG = QMAX
        ENDIF
 
        IF(QARG.LT.0.0) THEN
          WRITE(STDOUT,50) QARG, GET_TABID(TAB)
          STOP 'Abnormal stop: errors found.'
        ENDIF
 
        IF(QARG.GT.0.0) THEN
C         QARG IS NOW WITHIN THE RANGE OF THE FLOWS IN THE LIST.
C         FIND THE FLOW INTERVAL IN THE TABLE CONTAINING QARG
 
          LQF = ITAB(IP+4)
          IF(QARG.GE.FTAB(LQF)) THEN
 100        CONTINUE
              IF(QARG.LE.FTAB(LQF+INC)) GOTO 120
              LQF = LQF + INC
              GOTO 100
          ELSE
 110        CONTINUE
              LQF = LQF - INC
              IF(QARG.GE.FTAB(LQF)) GOTO 120
              GOTO 110
          ENDIF
 120      CONTINUE
          ITAB(IP+4) = LQF
 
C         FIND UPSTREAM LEVEL FOR QARG.
 
          QL = FTAB(LQF)
          HUL = FTAB(LQF+2)
          HUR = FTAB(LQF+INC+2)
          DHUQ = (HUR - HUL)/(FTAB(LQF+INC) - QL)
          HU = HUL + DHUQ*(QARG - QL)
          DHUED = 0.0
          FREE = 1
C          WRITE(STDOUT,*) 'TDLK14: FREE FLOW QARG=',QARG,' QFREE=',QFREE
C          WRITE(STDOUT,*) ' QL=',QL,' QR=',FTAB(LQF+INC),
C     A                          ' HUL=',HUL,' HUR=',HUR
C          WRITE(STDOUT,*) 'HU =',HU,' DHUQ=',DHUQ
 
C         DHUQ GIVES THE DERIVATIVE OF UPSTREAM HEAD WITH RESPECT TO
C         FREE FLOW.
        ELSE
C         FLOW IS ZERO HERE AND THE DOWNSTREAM HEAD IS LESS THAN
C         THE UPSTREAM HEAD.  ASSUME FREE FLOW TO GET THE FLOW
C         STARTED.  MUST FIND THE FREE FLOW FOR THE GIVEN UPSTREAM
C         HEAD.  WHEN QARG = 0.0 THEN UPSTREAM HEAD IS IN HU.
C         THE RESULTING VALUE OF FLOW IS RETURNED IN QARG.
 
          ITMP = ITAB(IP+4)
C         THE UPSTREAM HEAD FOR EACH FREE FLOW IS STORED 2 AFTER THE
C         FREE FLOW.
          LHU = ITMP + 2
          IF(HU.GE.FTAB(LHU)) THEN
 102        CONTINUE
              IF(HU.LE.FTAB(LHU+INC)) GOTO 122
              LHU = LHU + INC
              GOTO 102
          ELSE
 112        CONTINUE
              LHU = LHU - INC
              IF(HU.GE.FTAB(LHU)) GOTO 122
              GOTO 112
          ENDIF
 122      CONTINUE
 
C         FIND THE FREE FLOW FOR HU
 
          HUL = FTAB(LHU)
          QL = FTAB(LHU-2)
          HUR = FTAB(LHU+INC)
          QR = FTAB(LHU+INC-2)
C         VARIABLE DHUQ IS USED TO RETURN A VALUE WHICH IN THIS CASE
C         IS DQHU!
          DHUQ = (QR - QL)/(HUR - HUL)
          QARG = QL + DHUQ*(HU - HUL)
          DHUED = 0.0
          FREE = 1
C          WRITE(STDOUT,*) 'TDLK14: FREE FLOW SPECIAL CASE. HU=',HU
C          WRITE(STDOUT,*) ' QL=',QL,' QR=',QR,
C     A                          ' HUL=',HUL,' HUR=',HUR
C          WRITE(STDOUT,*) 'QARG =',QARG,' DHUQ=',DHUQ
 
C         DHUQ GIVES THE DERIVATIVE OF FREE FLOW WITH RESPECT TO
C         UPSTREAM HEAD IN THIS CASE.
        ENDIF
      ELSE
C       SUBMERGED FLOW HERE.
 
 
C       GET OFFSETS FROM THE START OF THE
C       PARTIAL FREE FLOW LIST TO THE START OF THE LIST OF UPSTREAM
C       HEADS FOR EACH OF THE DOWNSTREAM HEADS WHICH BRACKET HD.
 
        OFFL = ITAB(LHD+2)
C        WRITE(STDOUT,*) ' LHD=',LHD,' OFFL=',OFFL
        OFFR = ITAB(LHD+INC+2)
C        WRITE(STDOUT,*) ' LHD=',LHD,' OFFR=',OFFR
 
C       GET THE LOCATION OF LAST ACCESS IN THE LIST OF PARTIAL FREE
C       FLOWS
 
        LPFQ = ITAB(IP+6)
 
C       FIND THE FRACTION OF FREE FLOW REPRESENTED BY THE CURRENT FLOW
 
        P = QARG/QFREE
 
C        WRITE(STDOUT,*) 'TDLK14; SUBMERGED FLOW'
C        WRITE(STDOUT,*) ' QARG=',QARG,' QFREE=',QFREE,' P=',P
 
C       WE HAVE TWO LINES OF CONSTANT DWNSTRM LEVEL.  ONE IS ON THE LEFT
C       AND WILL BE DESIGNATED BY THE SUFFIX L.  THE OTHER IS ON THE RIGHT
C       AND WILL BE DESIGNATED BY THE SUFFIX R.  ON EACH LINE THERE WILL BE
C       A POINT ABOVE AND BELOW P.  THE ONE ABOVE IS DENOTED AS U AND THE
C       ONE BELOW AS D.  WE INTERPOLATE IN EACH LINE WITH P AND THEN
C       INTERPOLATE ON THE DOWNSTREAM LEVEL. IN TYPE 14 WE HAVE
C       ONLY ONE SEQUENCE OF PARTIAL FREE FLOWS.  THUS WE SEARCH ONLY
C       ONCE.
 
 
C       SEARCH IN THE PARTIAL FREE FLOW LIST
 
C        WRITE(STDOUT,*) 'PFQ SEARCH START LPFQ=',LPFQ
        IF(P.GE.FTAB(LPFQ)) THEN
 130      CONTINUE
            IF(P.LE.FTAB(LPFQ+1)) GOTO 150
              LPFQ = LPFQ + 1
              GOTO 130
        ELSE
 140      CONTINUE
            LPFQ = LPFQ - 1
            IF(P.GE.FTAB(LPFQ)) GOTO 150
            GOTO 140
        ENDIF
 150    CONTINUE
        ITAB(IP+6) = LPFQ
 
C        WRITE(STDOUT,*) ' PFQ SEARCH END LPFQ=',LPFQ
 
        PD = FTAB(LPFQ)
        HLD = FTAB(OFFL+LPFQ)
        HLU = FTAB(OFFL+LPFQ+1)
        PU = FTAB(LPFQ+1)
        DHLP = (HLU - HLD)/(PU - PD)
        HL = HLD + DHLP*(P - PD)
 
C       DHLP GIVES THE PARTIAL DERIVATIVE OF THE UPSTREAM HEAD
C       WITH RESPECT TO THE PARTIAL FREE FLOW ALONG THE LEFT
C       LINE OF CONSTANT DOWNSTREAM HEAD.
 
C        WRITE(STDOUT,*) ' PD=',PD,' HLD=',HLD,' LPFQ=',LPFQ
C        WRITE(STDOUT,*) ' PU=',PU,' HLU=',HLU,' HL=',HL
 
        HRD = FTAB(OFFR+LPFQ)
        HRU = FTAB(OFFR+LPFQ+1)
        DHRP = (HRU - HRD)/(PU - PD)
        HR = HRD + DHRP*(P - PD)
 
C       DHRP GIVES THE PARTIAL DERIVATIVE OF UPSTREAM HEAD
C       WITH RESPECT TO THE PARTIAL FREE FLOW ALONG THE
C       RIGHT LINE OF CONSTANT DOWNSTREAM HEAD.
 
C        WRITE(STDOUT,*) ' PD=',PD,' HRD=',HRD,' LPFQ=',LPFQ
C        WRITE(STDOUT,*) ' PU=',PU,' HRU=',HRU,' HR=',HR
 
C        WRITE(STDOUT,*) 'TDLK14: HL=',HL,' HR=',HR
 
C       COMPUTE THE UPSTREAM HEAD AND ITS DERIVATIVES
 
        DHD = HDR - HDL
        DHHDP = (HR - HL)/DHD
        HU = HL + DHHDP*(HD - HDL)
 
C       DHHDP GIVES THE PARTIAL DERIVATIVE OF THE UPSTREAM HEAD
C       WITH RESPECT TO DOWNSTREAM HEAD WHEN THE PARTIAL FREE FLOW
C       IS HELD CONSTANT.
 
        DHP = DHLP + (HD - HDL)*(DHRP - DHLP)/DHD
 
        DHUQ = DHP/QFREE
 
        DHUED = -QARG*DHP*DQFHD/QFREE**2 + DHHDP
 
        FREE = 0
 
      ENDIF
C      WRITE(STDOUT,*) 'TDLK14: Q=',QARG,' DHUED=',DHUED,' DHUQ=',DHUQ,
C     A               ' HU=',HU
      RETURN
 
      END
C
C
C
      SUBROUTINE   TDLK14_CHK
     I                   (STDOUT, IP, PTYPE, EDA, HBASE,
     M                    QARG,
     O                    HU, QFREE, FREE)
 
C     + + + PURPOSE + + +
C     Do 2-d lookup for flow for tables of type 14.  The arguments
C     are flow at the flow node and the downstream elevation.
C     This version used for checking tables. 
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER FREE, IP, STDOUT, PTYPE
      REAL  EDA, HBASE, HU, QARG, QFREE
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     IP     - address of the table
C     PTYPE  - expected table type
C     EDA    - water surface elevation at downstream node
C     HBASE  - datum for heads
C     QARG   - flow argument for table lookup
C     HU     - head at upstream node
C     QFREE  - free flow at the downstream head
C     FREE   - flag for free flow
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'

C     Called subprograms
      CHARACTER*16 GET_TABID
      EXTERNAL GET_TABID      
 
C     + + + LOCAL PARAMETERS + + +
      INTEGER INC
      PARAMETER(INC=4)
 
C     + + + LOCAL VARIABLES + + +
      INTEGER LHD, LHU, LPFQ, LQF, OFFL, OFFR, TAB, TYPE
      REAL DHD, DHHDP, DHLP, DHP, DHRP, DHUQ, DQFHD, ED, HD, HDL, 
     A     HDMAX, HDR, HL, HLD, HLU, HR, HRD, HRU, HUL, HUR, P, 
     B     PD, PU, QFL, QFR, QL, QMAX, QR
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT
     A (/,' *BUG:XXX* NEGATIVE QARG IN TDLK14_CHK=',F10.3,' TABID=',A)
 52   FORMAT(/,' *WRN:43* Flow > Maxflow in Two-D tabid=',A,' Flow=',
     A       F10.2,' Maxflow=',F10.2)
 54   FORMAT(/,' *ERR:73* Unexpected type in two-D TABID=',A,
     A       ' Type=',I5,' Expected Type=',I5)
 56   FORMAT(/,' *WRN:44* HDN > MAXHDN IN TWO-D TABID=',A,' HDN=',
     A       F10.2,' MAXHDN=',F10.2)
C***********************************************************************
C     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT
C     POINTERS ARE SET TO THE PROPER VALUES AT START
 
      TAB = ITAB(IP+1)
      TYPE = ITAB(IP+2)
 
 
      ED = EDA
 
C      WRITE(STDOUT,*) 'TDLK14: TAB#=',TAB, ' QARG=',QARG,' ED=',ED
 
      IF(TYPE.NE.PTYPE) THEN
        WRITE(STDOUT,54) GET_TABID(TAB), TYPE, PTYPE
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
 
      HD = ED - HBASE
 
C      WRITE(STDOUT,*) 'TDLK14: HBASE=',HBASE, ' HD=',HD
 
C     FIND THE DOWNSTREAM HEAD INTERVAL CONTAINING HD.
C     FIRST MAKE SURE THAT HD IS WITHIN VALID RANGE.
 
      HDMAX = FTAB(IP+5)
 
      IF(HD.GT.HDMAX) THEN
        WRITE(STDOUT,56)  GET_TABID(TAB), HD, HDMAX
        HD = HDMAX
      ENDIF
 
      IF(HD.LT.0.0) HD = 0.0
 
C     NOW THAT HD IS IN THE VALID RANGE SEARCH FOR THE INTERVAL
 
      LHD = ITAB(IP+3)
C      WRITE(STDOUT,*) ' LHD=',LHD,' HDMAX=',HDMAX
 
      IF(HD.GE.FTAB(LHD)) THEN
 200    CONTINUE
          IF(HD.LE.FTAB(LHD+INC)) GOTO 220
          LHD = LHD + INC
          GOTO 200
      ELSE
 210    CONTINUE
          LHD = LHD - INC
          IF(HD.GE.FTAB(LHD)) GOTO 220
          GOTO 210
      ENDIF
 220  CONTINUE
      ITAB(IP+3) = LHD
 
C     NOW INTERPOLATE FOR THE VALUE OF FREE FLOW WHICH CORRESPONDS
C     TO INCIPIENT SUBMERGENCE AT HD.
 
      QFL = FTAB(LHD-1)
      QFR = FTAB(LHD+INC-1)
      HDL = FTAB(LHD)
      HDR = FTAB(LHD+INC)
 
      DQFHD = (QFR - QFL)/(HDR - HDL)
      QFREE = QFL + DQFHD*(HD - HDL)
 
C     DQFHD GIVES THE RATE OF CHANGE OF THE FREE FLOW AT INCIPIENT
C     SUBMERGENCE WITH RESPECT TO THE DOWNSTEAM HEAD.
 
      IF(QARG.GE.QFREE) THEN
C       FLOW IS FREE.  NOW FIND THE VALUE OF UPSTREAM HEAD WHICH
C       CORRESPONDS TO FREE FLOW IF QARG > 0.  MUST SEARCH FREE FLOW
C       LIST USING  QARG.
 
        QMAX = FTAB(IP+9)
 
        IF(QARG.GT.QMAX) THEN
          WRITE(STDOUT,52) GET_TABID(TAB), QARG, QMAX
          QARG = QMAX
        ENDIF
 
        IF(QARG.LT.0.0) THEN
          WRITE(STDOUT,50) QARG, GET_TABID(TAB)
          STOP 'Abnormal stop: errors found.'
        ENDIF
 
        IF(QARG.GT.0.0) THEN
C         QARG IS NOW WITHIN THE RANGE OF THE FLOWS IN THE LIST.
C         FIND THE FLOW INTERVAL IN THE TABLE CONTAINING QARG
 
          LQF = ITAB(IP+4)
          IF(QARG.GE.FTAB(LQF)) THEN
 100        CONTINUE
              IF(QARG.LE.FTAB(LQF+INC)) GOTO 120
              LQF = LQF + INC
              GOTO 100
          ELSE
 110        CONTINUE
              LQF = LQF - INC
              IF(QARG.GE.FTAB(LQF)) GOTO 120
              GOTO 110
          ENDIF
 120      CONTINUE
          ITAB(IP+4) = LQF
 
C         FIND UPSTREAM LEVEL FOR QARG.
 
          QL = FTAB(LQF)
          HUL = FTAB(LQF+2)
          HUR = FTAB(LQF+INC+2)
          DHUQ = (HUR - HUL)/(FTAB(LQF+INC) - QL)
          HU = HUL + DHUQ*(QARG - QL)
          FREE = 1
C          WRITE(STDOUT,*) 'TDLK14: FREE FLOW QARG=',QARG,' QFREE=',QFREE
C          WRITE(STDOUT,*) ' QL=',QL,' QR=',FTAB(LQF+INC),
C     A                          ' HUL=',HUL,' HUR=',HUR
C          WRITE(STDOUT,*) 'HU =',HU,' DHUQ=',DHUQ
 
C         DHUQ GIVES THE DERIVATIVE OF UPSTREAM HEAD WITH RESPECT TO
C         FREE FLOW.
        ELSE
C         FLOW IS ZERO HERE AND THE DOWNSTREAM HEAD IS LESS THAN
C         THE UPSTREAM HEAD.  ASSUME FREE FLOW TO GET THE FLOW
C         STARTED.  MUST FIND THE FREE FLOW FOR THE GIVEN UPSTREAM
C         HEAD.  WHEN QARG = 0.0 THEN UPSTREAM HEAD IS IN HU.
C         THE RESULTING VALUE OF FLOW IS RETURNED IN QARG.
 
          ITMP = ITAB(IP+4)
C         THE UPSTREAM HEAD FOR EACH FREE FLOW IS STORED 2 AFTER THE
C         FREE FLOW.
          LHU = ITMP + 2
          IF(HU.GE.FTAB(LHU)) THEN
 102        CONTINUE
              IF(HU.LE.FTAB(LHU+INC)) GOTO 122
              LHU = LHU + INC
              GOTO 102
          ELSE
 112        CONTINUE
              LHU = LHU - INC
              IF(HU.GE.FTAB(LHU)) GOTO 122
              GOTO 112
          ENDIF
 122      CONTINUE
 
C         FIND THE FREE FLOW FOR HU
 
          HUL = FTAB(LHU)
          QL = FTAB(LHU-2)
          HUR = FTAB(LHU+INC)
          QR = FTAB(LHU+INC-2)
C         VARIABLE DHUQ IS USED TO RETURN A VALUE WHICH IN THIS CASE
C         IS DQHU!
          DHUQ = (QR - QL)/(HUR - HUL)
          QARG = QL + DHUQ*(HU - HUL)
          FREE = 1
C          WRITE(STDOUT,*) 'TDLK14: FREE FLOW SPECIAL CASE. HU=',HU
C          WRITE(STDOUT,*) ' QL=',QL,' QR=',QR,
C     A                          ' HUL=',HUL,' HUR=',HUR
C          WRITE(STDOUT,*) 'QARG =',QARG,' DHUQ=',DHUQ
 
C         DHUQ GIVES THE DERIVATIVE OF FREE FLOW WITH RESPECT TO
C         UPSTREAM HEAD IN THIS CASE.
        ENDIF
      ELSE
C       SUBMERGED FLOW HERE.
 
 
C       GET OFFSETS FROM THE START OF THE
C       PARTIAL FREE FLOW LIST TO THE START OF THE LIST OF UPSTREAM
C       HEADS FOR EACH OF THE DOWNSTREAM HEADS WHICH BRACKET HD.
 
        OFFL = ITAB(LHD+2)
C        WRITE(STDOUT,*) ' LHD=',LHD,' OFFL=',OFFL
        OFFR = ITAB(LHD+INC+2)
C        WRITE(STDOUT,*) ' LHD=',LHD,' OFFR=',OFFR
 
C       GET THE LOCATION OF LAST ACCESS IN THE LIST OF PARTIAL FREE
C       FLOWS
 
        LPFQ = ITAB(IP+6)
 
C       FIND THE FRACTION OF FREE FLOW REPRESENTED BY THE CURRENT FLOW
 
        P = QARG/QFREE
 
C        WRITE(STDOUT,*) 'TDLK14; SUBMERGED FLOW'
C        WRITE(STDOUT,*) ' QARG=',QARG,' QFREE=',QFREE,' P=',P
 
C       WE HAVE TWO LINES OF CONSTANT DWNSTRM LEVEL.  ONE IS ON THE LEFT
C       AND WILL BE DESIGNATED BY THE SUFFIX L.  THE OTHER IS ON THE RIGHT
C       AND WILL BE DESIGNATED BY THE SUFFIX R.  ON EACH LINE THERE WILL BE
C       A POINT ABOVE AND BELOW P.  THE ONE ABOVE IS DENOTED AS U AND THE
C       ONE BELOW AS D.  WE INTERPOLATE IN EACH LINE WITH P AND THEN
C       INTERPOLATE ON THE DOWNSTREAM LEVEL. IN TYPE 14 WE HAVE
C       ONLY ONE SEQUENCE OF PARTIAL FREE FLOWS.  THUS WE SEARCH ONLY
C       ONCE.
 
 
C       SEARCH IN THE PARTIAL FREE FLOW LIST
 
C        WRITE(STDOUT,*) 'PFQ SEARCH START LPFQ=',LPFQ
        IF(P.GE.FTAB(LPFQ)) THEN
 130      CONTINUE
            IF(P.LE.FTAB(LPFQ+1)) GOTO 150
              LPFQ = LPFQ + 1
              GOTO 130
        ELSE
 140      CONTINUE
            LPFQ = LPFQ - 1
            IF(P.GE.FTAB(LPFQ)) GOTO 150
            GOTO 140
        ENDIF
 150    CONTINUE
        ITAB(IP+6) = LPFQ
 
C        WRITE(STDOUT,*) ' PFQ SEARCH END LPFQ=',LPFQ
 
        PD = FTAB(LPFQ)
        HLD = FTAB(OFFL+LPFQ)
        HLU = FTAB(OFFL+LPFQ+1)
        PU = FTAB(LPFQ+1)
        DHLP = (HLU - HLD)/(PU - PD)
        HL = HLD + DHLP*(P - PD)
 
C       DHLP GIVES THE PARTIAL DERIVATIVE OF THE UPSTREAM HEAD
C       WITH RESPECT TO THE PARTIAL FREE FLOW ALONG THE LEFT
C       LINE OF CONSTANT DOWNSTREAM HEAD.
 
C        WRITE(STDOUT,*) ' PD=',PD,' HLD=',HLD,' LPFQ=',LPFQ
C        WRITE(STDOUT,*) ' PU=',PU,' HLU=',HLU,' HL=',HL
 
        HRD = FTAB(OFFR+LPFQ)
        HRU = FTAB(OFFR+LPFQ+1)
        DHRP = (HRU - HRD)/(PU - PD)
        HR = HRD + DHRP*(P - PD)
 
C       DHRP GIVES THE PARTIAL DERIVATIVE OF UPSTREAM HEAD
C       WITH RESPECT TO THE PARTIAL FREE FLOW ALONG THE
C       RIGHT LINE OF CONSTANT DOWNSTREAM HEAD.
 
C        WRITE(STDOUT,*) ' PD=',PD,' HRD=',HRD,' LPFQ=',LPFQ
C        WRITE(STDOUT,*) ' PU=',PU,' HRU=',HRU,' HR=',HR
 
C        WRITE(STDOUT,*) 'TDLK14: HL=',HL,' HR=',HR
 
C       COMPUTE THE UPSTREAM HEAD AND ITS DERIVATIVES
 
        DHD = HDR - HDL
        DHHDP = (HR - HL)/DHD
        HU = HL + DHHDP*(HD - HDL)
 
C       DHHDP GIVES THE PARTIAL DERIVATIVE OF THE UPSTREAM HEAD
C       WITH RESPECT TO DOWNSTREAM HEAD WHEN THE PARTIAL FREE FLOW
C       IS HELD CONSTANT.
 
        DHP = DHLP + (HD - HDL)*(DHRP - DHLP)/DHD
 
        DHUQ = DHP/QFREE
 
 
        FREE = 0
 
      ENDIF
C      WRITE(STDOUT,*) 'TDLK14: Q=',QARG,' DHUED=',DHUED,' DHUQ=',DHUQ,
C     A               ' HU=',HU
      RETURN
 
      END
C
C
C
      SUBROUTINE   TDLK6
     I                  (STDOUT, IP, PTYPE, MFTAB, TIME, EDA, EUA, 
     I                   HBASE,
     O                   Q, DQED, DQEU, FREE)
 
C     + + + PURPOSE + + +
C     Do 2-d lookup for flow in tables of type 6.
 
      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER FREE, IP, STDOUT, MFTAB, PTYPE
      REAL DQED, DQEU, EDA, EUA, HBASE, Q, TIME
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT   - Fortran unit number for user output and messages
C     IP     - address of the table
C     PTYPE  - expected table type
C     MFTAB  - table number and later table address of the function
C               table that supplies an adjustment factor for flows
C     TIME   - elapsed time in seconds from start of run
C     EDA    - water surface elevation at downstream node
C     EUA    - elevation of water surface at upstream node
C     HBASE  - datum for heads
C     Q      - flow rate
C     DQED   - derivative of flow wrt downstream elevation
C     DQEU   - derivative flow wrt upstream elevation
C     FREE   - flag for free flow
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'ftable.cmn'

C     Called subprograms
      CHARACTER*16 GET_TABID
      EXTERNAL GET_TABID
 
C     + + + LOCAL PARAMETERS + + +
      INTEGER INC
      PARAMETER(INC=5)
 
C     + + + LOCAL VARIABLES + + +
      INTEGER LHU, LP, NTAB, TAB, TYPE
      REAL DDROPU, DPEU, DQHU, DQLED, DQLEU, DQLP, DQRED, DQREU, DQRP,
     A     DROP, ED, EU, FAC, HDROP, HDROPL, HDROPR, HMAX, HU, HUL, HUR,
     B     P, PDV, PLD, PLU, PRD, PRU, QL, QLD, QLU, QR, QRD, QRU,
     C     THDROP
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL LKTAB
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT('*ERR:72* EU < ED in two-D TABID=',A,' EU=',
     A       F10.2,' ED=',F10.2)
 52   FORMAT('*WRN:04* HU > HMAX in two-D TABID=',A,' HU=',
     A       F10.2,' HMAX=',F10.2)
 54   FORMAT('*ERR:73* Unexpected type in two-D TABID=',A,
     A       ' Type=',I5,' expected Type=',I5)
C***********************************************************************
C     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT
C     POINTERS ARE SET TO THE PROPER VALUES AT START
 
      TAB = ITAB(IP+1)
      TYPE = ITAB(IP+2)
      LHU = ITAB(IP+4)
      HMAX = FTAB(IP+9)
 
C      WRITE(STDOUT,*) 'TDLK6: LHU=',LHU,' HMAX=',HMAX
 
C     IMPORTANT: THE DESIGNATIONS UPSTREAM AND DOWNSTREAM REFER TO
C     THE TRUE RELATIONSHIP.  THUS EU >= ED ALWAYS.
 
      EU = EUA
      ED = EDA
 
C      WRITE(STDOUT,*) 'TDLK6: EU=',EU,' ED=',ED
 
      IF(TYPE.NE.PTYPE) THEN
        WRITE(STDOUT,54) GET_TABID(TAB), TYPE, PTYPE
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
      IF(EU.LT.ED) THEN
        WRITE(STDOUT,50) GET_TABID(TAB), EU, ED
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
 
      HU = EU - HBASE
C      WRITE(STDOUT,*) 'TDLK6: HBASE=',HBASE, ' HU=',HU
 
      IF(HU.GT.HMAX) THEN
        WRITE(STDOUT,52) GET_TABID(TAB), HU, HMAX
        DROP = EU - ED
        HU = HMAX
        EU = HBASE + HMAX
        ED = EU - DROP
      ENDIF
 
C     DETERMINE IF THERE IS FLOW AND IF IT IS KNOWN TO BE FREE
 
      IF(EU.LT.HBASE) THEN
C       FLOW IS ZERO AND SO ARE DERIVATIVES
        Q = 0.0
        DQED = 0.0
        DQEU = 0.0
        FREE = 0
        RETURN
      ENDIF
 
C     UPSTREAM LEVEL IS ABOVE BASE.  FIND THE UPSTREAM LEVEL INTERVAL
C     CONTAINING EU
 
      IF(HU.GE.FTAB(LHU)) THEN
 100    CONTINUE
          IF(HU.LE.FTAB(LHU+INC)) GOTO 120
          LHU = LHU + INC
          GOTO 100
      ELSE
 110    CONTINUE
          LHU = LHU - INC
          IF(HU.GE.FTAB(LHU)) GOTO 120
          GOTO 110
      ENDIF
 120  CONTINUE
      ITAB(IP+4) = LHU
 
C     ELIMINATE SPECIAL CASE OF FREE FLOW TO ALLOW THE HEAD DROP TO
C     BE LARGER THAN THE UPSTREAM HEAD.  THIS MEANS THAT THE DOWNSTREAM
C     HEAD COULD BE BELOW THE ZERO FLOW LEVEL.
 
C      IF(ED.LT.HBASE) THEN
C       FREE FLOW BECAUSE DOWNSTREAM LEVEL IS BELOW BASE
 
C        HUL = FTAB(LHU)
C        HUR = FTAB(LHU+INC)
C        QL = FTAB(LHU+4)
C        QR = FTAB(LHU+INC+4)
 
C        DQEU = (QR - QL)/(HUR - HUL)
C        Q = QL + DQEU*(HU - HUL)
C        DQED = 0.0
C        FREE = 1
CC        WRITE(STDOUT,*) 'TDLK6: SIMPLE FREE FLOW'
CC        WRITE(STDOUT,*) ' HUL=',HUL,' HUR=',HUR,' QL=',QL,' QR=',QR
CC        WRITE(STDOUT,*) 'Q =',Q,' DQEU=',DQEU
 
C        GOTO 9000
C        RETURN
C      ENDIF
 
C     GENERAL CASE. FREE FLOW MAY RESULT IF THE DOWNSTREAM HEAD IS
C     SMALL ENOUGH
 
C     FIND THE HEAD DROP CORRESPONDING TO HU
 
      HUL = FTAB(LHU)
      HUR = FTAB(LHU+INC)
      HDROPL = FTAB(LHU+1)
      HDROPR = FTAB(LHU+INC+1)
      DDROPU = (HDROPR - HDROPL)/(HUR - HUL)
      THDROP = HDROPL + DDROPU*(HU - HUL)
C     THDROP IS THE TABLE VALUE OF THE HEAD DROP TO FREE FLOW
C     FOR THE CURRENT UPSTREAM LEVEL
C     HDROP IS THE CURRENT HEAD DROP
 
      HDROP = EU - ED
 
 
      IF(HDROP.GE.THDROP) THEN
C       FREE FLOW
 
        QL = FTAB(LHU+4)
        QR = FTAB(LHU+INC+4)
        DQEU = (QR - QL)/(HUR - HUL)
        Q = QL + DQEU*(HU - HUL)
        DQED = 0.0
        FREE = 1
C        WRITE(STDOUT,*) 'TDLK6: COMPLEX FREE FLOW'
C        WRITE(STDOUT,*) ' HUL=',HUL,' HUR=',HUR,' QL=',QL,' QR=',QR
C        WRITE(STDOUT,*) 'Q =',Q,' DQEU=',DQEU
 
        GOTO 9000
C        RETURN
      ENDIF
 
C     SUBMERGED FLOW HERE
 
C     FIND THE FRACTION OF FREE FLOW DROP REPRESENTED BY THE CURRENT DROP
 
      P = HDROP/THDROP
 
C      WRITE(STDOUT,*) 'TDLK6; SUBMERGED FLOW'
C      WRITE(STDOUT,*) ' HDROP=',HDROP,' THDROP=',THDROP,' P=',P
 
 
C     WE HAVE TWO LINES OF CONSTANT UPSTREAM LEVEL.  ONE IS ON THE LEFT
C     AND WILL BE DESIGNATED BY THE SUFFIX L.  THE OTHER IS ON THE RIGHT
C     AND WILL BE DESIGNATED BY THE SUFFIX R.  ON EACH LINE THERE WILL BE
C     A POINT ABOVE AND BELOW P.  THE ONE ABOVE IS DENOTED AS U AND THE
C     ONE BELOW AS D.  WE INTERPOLATE IN EACH LINE WITH P AND THEN
C     INTERPOLATE ON THE UPSTREAM LEVEL.
 
 
C     DO SEARCH ALONG THE LEFT LINE OF P VERSUS Q
 
      LP = ITAB(LHU+3)
 
C      WRITE(STDOUT,*) 'LEFT LINE START LP=',LP
      IF(P.GE.FTAB(LP)) THEN
 130    CONTINUE
          IF(P.LE.FTAB(LP+2)) GOTO 150
            LP = LP + 2
            GOTO 130
      ELSE
 140    CONTINUE
          LP = LP -2
          IF(P.GE.FTAB(LP)) GOTO 150
          GOTO 140
      ENDIF
 150  CONTINUE
      ITAB(LHU+3) = LP
 
      PLD = FTAB(LP)
      QLD = FTAB(LP+1)
      PLU = FTAB(LP+2)
      QLU = FTAB(LP+3)
      DQLP = (QLU - QLD)/(PLU - PLD)
      QL = QLD + DQLP*(P - PLD)
 
C      WRITE(STDOUT,*) ' PLD=',PLD,' QLD=',QLD,' LP=',LP
C      WRITE(STDOUT,*) ' PLU=',PLU,' QLU=',QLU,' QL=',QL
C     DO SEARCH ALONG THE RIGHT LINE
 
      LP = ITAB(LHU+INC+3)
C      WRITE(STDOUT,*) 'RIGHT LINE START LP=',LP
      IF(P.GE.FTAB(LP)) THEN
 160    CONTINUE
          IF(P.LE.FTAB(LP+2)) GOTO 180
            LP = LP + 2
            GOTO 160
      ELSE
 170    CONTINUE
          LP = LP -2
          IF(P.GE.FTAB(LP)) GOTO 180
          GOTO 170
      ENDIF
 180  CONTINUE
 
      ITAB(LHU+INC+3) = LP
 
      PRD = FTAB(LP)
      QRD = FTAB(LP+1)
      PRU = FTAB(LP+2)
      QRU = FTAB(LP+3)
      DQRP = (QRU - QRD)/(PRU - PRD)
      QR = QRD + DQRP*(P - PRD)
 
C      WRITE(STDOUT,*) ' PRD=',PRD,' QRD=',QRD,' LP=',LP
C      WRITE(STDOUT,*) ' PRU=',PRU,' QRU=',QRU,' QR=',QR
 
C      WRITE(STDOUT,*) 'TDLK6: QL=',QL,' QR=',QR
C     COMPUTE THE FLOW AND ITS DERIVATIVES
 
      DQHU = (QR - QL)/(HUR - HUL)
      Q = QL + DQHU*(HU - HUL)
 
      FAC = (HU - HUL)/(HUR - HUL)
      DPEU = (1.0 - P*DDROPU)/THDROP
      DQLEU = DQLP*DPEU
      DQREU = DQRP*DPEU
      DQEU = DQLEU + DQHU + FAC*(DQREU - DQLEU)
 
      DQLED = -DQLP/THDROP
      DQRED = -DQRP/THDROP
      DQED = DQLED + FAC*(DQRED - DQLED)
 
      FREE = 0
 
 9000 CONTINUE
C     CHECK FOR FINAL ADJUSMENT
      IF(MFTAB.GT.0) THEN
C       FIND ADJUSTMENT FACTOR AND APPLY TO THE FLOW AND DERIVATIVES
 
        CALL LKTAB
     I            (MFTAB, TIME, 1,
     O             FAC, NTAB, PDV)
 
        Q = Q*FAC
        DQED = DQED*FAC
        DQEU = DQEU*FAC
      ENDIF
C      WRITE(STDOUT,*) 'TDLK6: Q=',Q,' DQEU=',DQEU,' DQED=',DQED
      RETURN
 
      END
