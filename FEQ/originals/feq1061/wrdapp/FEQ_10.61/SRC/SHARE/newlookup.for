c     1-6 March 2003:  Start some new lookup and storage options to see if
c     we can improve robustness of the solution in FEQ by providing, as a start,
c     at storage and lookup for type 13 tables that will provide at least 
c     continuous first derivatives and in some cases continuous second derivatives. 

C
C
C
      subroutine   tdlk43
     I                (STDOUT, IP, PTYPE, MFTAB, JTIME, EDA, EUA,
     I                 HBASE,
     O                 Q, DQED, DQEU, FREE)
 
C     + + + PURPOSE + + +
C     Do 2-d lookup for flow for tables of type 43.
c     These tables use piecewise-cubic Hermite interpolation in 
c     both the upstream head, and partial free drop.  If the smoother
c     function gives us enough benefit, then we will revise the order
c     of storage and lookup to gain a bit of speed. 


      IMPLICIT NONE
C     + + + DUMMY ARGUMENTS + + +
      INTEGER FREE, IP, STDOUT, MFTAB, PTYPE
      REAL DQED, DQEU, EDA, EUA, HBASE, Q
      REAL*8 jtime
 
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
 
C     + + + LOCAL PARAMETERS + + +
      INTEGER INC
      PARAMETER(INC=4)
 
C     + + + LOCAL VARIABLES + + +
      INTEGER LHU, LP,  NTAB,  TAB, TYPE
      integer  it, itl, itr, qoffset, ppfd
      REAL 
     A     DROP, ED, EU, FAC, HDROP, HDROPL, HDROPR, HMAX, HU,
     B     HUL, HUR, P, PDV,    THDROP, dthdropdhu,
     d  dhdropl, dhdropr, t, h, flp, frp, fl, fr, dlp, drp, dm,
     e  dqldhu, dqrdhu, pfdD, pfdU,
     f  QLD, PQPpfdLD, PQPhuLD, PPQPpfdPhuLD,
     g  QLU, PQPpfdLU, PQPhuLU, PPQPpfdPhuLU,
     h  QRD, PQPpfdRD, PQPhuRD, PPQPpfdPhuRD,
     i  QRU, PQPpfdRU, PQPhuRU, PPQPpfdPhuRU, 
     j  QL, QR, PQPpfdL, PQPpfdR, PQPhuL, PQPhuR, 
     k  PPQPpfdPhuL, PPQPpfdPhuR,
     l  PQPpfd, PQPHU,
     m  t_hu, h_hu, flp_hu, frp_hu, fl_hu, fr_hu, dlp_hu, drp_hu, dm_hu 


        
 
C     + + + EXTERNAL NAMES + + +
      CHARACTER*16 GET_TABID
      EXTERNAL GET_TABID, LKTSTAB
 
C     + + + OUTPUT FORMATS + + +
 50   FORMAT('*ERR:72* EU < ED in two-D TABID=',A,' EU=',
     A       F10.2,' ED=',F10.2)
 52   FORMAT('*WRN:04* HU > HMAX in two-D TABID=',A,' HU=',
     A       F10.2,' HMAX=',F10.2)
 54   FORMAT('*ERR:73* Unexpected type in two-D TABID',A,
     A       ' Type=',I5,' expected Type=',I5)
C***********************************************************************
C     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT
C     POINTERS ARE SET TO THE PROPER VALUES AT START
 
      TAB = ITAB(IP+1)
      TYPE = ITAB(IP+2)
      LHU = ITAB(IP+4)
      HMAX = FTAB(IP+9)
      
c     Get the offset from zero flow to free flow in the table.  This is 
c     a constant for each upstream head and is 4*(number of partial free drops
c     including zero free drop - 1).  Must be set on input of the table!
      qoffset = itab(ip+10)

c     Get the pointer to the start of the partial free-drop sequence. 
c     needed to compute some offsets. 
      ppfd = itab(ip+5)

c      WRITE(STDOUT,*) ' TDLK43: TAB=',TAB,' TYPE=',TYPE,' LHU=',LHU
      
 
C     IMPORTANT: THE DESIGNATIONS UPSTREAM AND DOWNSTREAM REFER TO
C     THE TRUE RELATIONSHIP.  THUS EU >= ED ALWAYS.
 
      EU = EUA
      ED = EDA
c      write(stdout,*) ' tdlk43 EU=',EU,' ED=',ED,' HBASE=',HBASE,
c     a                ' HMAX=',HMAX
      IF(TYPE.NE.PTYPE) THEN
        WRITE(STDOUT,54) GET_TABID(TAB), TYPE, PTYPE
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
      IF(EU.LT.ED) THEN
        WRITE(STDOUT,50) GET_TABID(TAB), EU, ED
        STOP 'Abnormal stop: errors found.'
      ENDIF
 
 
      HU = EU - HBASE
 
      IF(HU.GT.HMAX) THEN
        WRITE(STDOUT,52) GET_TABID(TAB), HU, HMAX
        DROP = EU - ED
        HU = HMAX
        EU = HBASE + HMAX
        ED = EU - DROP
      ENDIF
 

C     DETERMINE IF THERE IS FLOW AND IF IT IS KNOWN TO BE FREE
 
      IF(EU.LE.HBASE) THEN
C       FLOW IS ZERO AND SO ARE DERIVATIVES
        Q = 0.0
        DQED = 0.0
        DQEU = 0.0
        FREE = 0
        goto 9000
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

C      WRITE(STDOUT,*) ' LHU AFTER SEARCH=',LHU
 
C     FREE FLOW MAY RESULT IF THE DOWNSTREAM HEAD IS
C     SMALL ENOUGH
 
C     FIND THE HEAD DROP CORRESPONDING TO HU
 
c     Get the ups heads on left (smaller) and right( larger) of the argument value
c     of ups head.  Also get the the drop to free flow and the derivative of the drop
c     to free flow wrt to ups head.
      HUL = FTAB(LHU)
      HUR = FTAB(LHU+INC)
      HDROPL = FTAB(LHU+1)
      HDROPR = FTAB(LHU+INC+1)
      dhdropl = ftab(lhu+2)
      dhdropr = ftab(lhu+inc+2)

c     Now do cubic interpolation for the value of free drop at the argument ups head.  Compute
C     the factors that depend only on the relative location in the interval.  We can reuse these
c     if the flow is in fact free. 
      h_hu = hur - hul
      t_hu = (hu - hul)/h_hu
c     compute factors on left and right derivative. 
      flp_hu = (1.0 - t_hu)*t_hu*h_hu
      frp_hu = -flp_hu*t_hu
      flp_hu = flp_hu*(1.0 - t_hu)
c     compute factors on left and right function value
      fl_hu = 2.*t_hu + 1.0
      fr_hu = (4.0 - fl_hu)*t_hu*t_hu
      fl_hu = fl_hu*(1.0 - t_hu)**2

c     compute the factors based on relative interval for computing derivatives. 
      dlp_hu = 1. - 3.*t_hu
      drp_hu = -(1. + dlp_hu)*t_hu
      dlp_hu = dlp_hu*(1.0 - t_hu)
      dm_hu = 6.*(1.0 - t_hu)*t_hu/h_hu

      thdrop = 
     A     flp_hu*dhdropl + frp_hu*dhdropr + fl_hu*hdropl + fr_hu*hdropr


C      WRITE(STDOUT,*) ' THDROP=',THDROP 
C     THDROP IS THE TABLE VALUE OF THE HEAD DROP TO FREE FLOW
C     FOR THE CURRENT UPSTREAM LEVEL
C     HDROP IS THE CURRENT HEAD DROP
 
      HDROP = EU - ED
      IF(HDROP.GE.THDROP) THEN
C       Free flow.  Get the values we need: flow on left and right 
C       and the derivative of flow wrt ups head on left and right. 
c       These are stored with the submerged values because they form the 
c       upper condition for submerged flow. 
 
        it = itab(lhu+3)
        QL = FTAB(it)
        dqldhu = ftab(it+2)
        it = itab(lhu+inc+3)
        QR = FTAB(it)
        dqrdhu = ftab(it+2)


        Q = flp_hu*dqldhu + frp_hu*dqrdhu + fl_hu*ql + fr_hu*qr

        DQEU = dlp_hu*dqldhu + drp_hu*dqrdhu + dm_hu*(qr - ql)


        DQED = 0.0
        FREE = 1
 
        GOTO 9000
      ENDIF
 
C     SUBMERGED FLOW HERE
 
 
C     FIND THE FRACTION OF FREE-FLOW DROP REPRESENTED BY THE CURRENT DROP

      P = HDROP/THDROP
 
c      WRITE(STDOUT,*) ' P=',P

c     Outline of approach and variables: 
c     1. we interpolate wrt to pfd (partial free drop) first.  
c     2  Then interpolate wrt to ups head. 

c     For each upstream head we have in sequence all of the values for that head.
c     The upstream head that is just less than the argument value will be denoted
c     by L for left.  The upstream head that is just greater than the argument value
c     will be denoted by R for right.  Note that equality is accepted at either end as well. 

c     In the sequence of partial free drops we will have one that is just below the
c     argument value.  We denote that by D.  We also have one that just above the 
c     argument value of pfd.  We denote that by U.  Now we need not distinguish left and 
c     right for the pfd because they are the same.   The pattern looks like this:

c                          Value of argument upstream head
c                          |
c          huL             hu       huR
c        --------------    --     ---------------
c           .              |         .
c           .              |         .            Zero or more sets of 4
c           .              |         .
c   pfdD    QLD            |        QRD
c           PQPpfdLD       |        PQPpfdRD      partial Q wrt to pfd
c           PQPhuLD        |        PQPhuRD       partial Q wrt to hu
c           PPQPpfdPhuLD   |        PPQPpfdPhuRD  partial partial Q wrt to pfd (2nd) and hu (1st)
c    P -------------------------------------------  value of argument pfd
c   pfdU    QLU            |        QRU          
c           PQPpfdLU       |        PQPpfdRU     
c           PQPhuLU        |        PQPhuRU      
c           PPQPpfdPhuLU   |        PPQPpfdPhuRU 
c           .              |         .
c           .              |         .            Zero or more sets of 4
c           .              |         .

c     Beware:  Fortran does not distinguish upper and lower case in names!!!!!
c              I may use upper and lower case to more clearly recognize the role of the name. 
c              However, this is a two-edged sword-the role may appear proper but may not be!!
c              There is no easy way to make sure programs work!

 
C     SEARCH IN THE PARTIAL FREE DROP LIST.  Get the value where we last found
C     the interval. 
 
      LP = ITAB(IP+6)
      IF(P.GE.FTAB(LP)) THEN
 130    CONTINUE
          IF(P.LE.FTAB(LP+1)) GOTO 150
            LP = LP + 1
            GOTO 130
      ELSE
 140    CONTINUE
          LP = LP - 1
          IF(P.GE.FTAB(LP)) GOTO 150
          GOTO 140
      ENDIF
 150  CONTINUE
      ITAB(IP+6) = LP
C      WRITE(STDOUT,*) ' LP=',LP

c     get the pointers to the free flows for the bounding upstream heads.
      itl = ITAB(LHU+3)
      itr = ITAB(LHU+INC+3)

c     Find the pointer for each flow at the partial free drop 
c     below P (smaller than P).  4*(lp - ppfd) gives the distance from
c     the flow at zero pfd to the flow at the pfd just smaller than P.
c     qoffset is the distance from free flow to zero flow (flow at zero 
c     partial free drop). INC is 4 and is a parameter already in the code.

      it = INC*(lp - ppfd) - qoffset
      itl = itl + it
      itr = itr + it

c     At this point itl points to QLD and itr points to QRD in the pattern 
c     given above. 

c     Set the values of pfdD and pfdU

      pfdD = ftab(lp)
      pfdU = ftab(lp+1)
 
c     Get the values in the pattern above.  All will be needed plus a whole
c     lot more!

      QLD          =  ftab(itl)
      PQPpfdLD     =  ftab(itl+1)
      PQPhuLD      =  ftab(itl+2)
      PPQPpfdPhuLD =  ftab(itl+3)

      QLU          =  ftab(itl+4)
      PQPpfdLU     =  ftab(itl+5)
      PQPhuLU      =  ftab(itl+6)
      PPQPpfdPhuLU =  ftab(itl+7)
      
      QRD          =  ftab(itr)
      PQPpfdRD     =  ftab(itr+1)
      PQPhuRD      =  ftab(itr+2)
      PPQPpfdPhuRD =  ftab(itr+3)

      QRU          =  ftab(itr+4)
      PQPpfdRU     =  ftab(itr+5)
      PQPhuRU      =  ftab(itr+6)
      PPQPpfdPhuRU =  ftab(itr+7)


c     now compute the coefficients that depend only on the local interval and the interpolation
c     point.   These apply to both the left and right sequences since the partial free-drop interval
c     is the same and so is P

      h = pfdU - pfdD
      t = (P - pfdD)/h
c     compute factors on left and right derivative. 
      flp = (1.0 - t)*t*h
      frp = -flp*t
      flp = flp*(1.0 - t)
c     compute factors on left and right function value
      fl = 2.*t + 1.0
      fr = (4.0 - fl)*t*t
      fl = fl*(1.0 - t)**2
c     compute the factors based on relative interval for computing derivatives. 
      dlp = 1. - 3.*t
      drp = -(1. + dlp)*t
      dlp = dlp*(1.0 - t)
      dm = 6.*(1.0 - t)*t/h

c     We need four values at P on huL and four values at P on huR to be able
c     to compute both the function and its two derivatives at P and hu:
c      1. Q ---------------------------------->  QL           QR
c      2. partial Q wrt to pfd --------------->  PQPpfdL      PQPpfdR
c      3. partial Q wrt to hu ---------------->  PQPhuL       PQPhuR
c      4. partial partial Q wrt to pfd and hu->  PPQPpfdPhuL  PPQPpfdPhuR

      QL      = fl*QLD + fr*QLU + flp*PQPpfdLD + frp*PQPpfdLU     
      PQPpfdL = dlp*PQPpfdLD + drp*PQPpfdLU + dm*(QLU - QLD)

      PQPhuL      = 
     a   fl*PQPhuLD + fr*PQPhuLU + flp*PPQPpfdPhuLD + frp*PPQPpfdPhuLU       
      PPQPpfdPhuL = 
     a  dlp*PPQPpfdPhuLD + drp*PPQPpfdPhuLU 
     b                            + dm*(PQPhuLU - PQPhuLD)

      QR      = fl*QRD + fr*QRU + flp*PQPpfdRD + frp*PQPpfdRU     
      PQPpfdR = dlp*PQPpfdRD + drp*PQPpfdRU + dm*(QRU - QRD)

      PQPhuR      = 
     a   fl*PQPhuRD + fr*PQPhuRU + flp*PPQPpfdPhuRD + frp*PPQPpfdPhuRU       
      PPQPpfdPhuR = 
     a  dlp*PPQPpfdPhuRD + drp*PPQPpfdPhuRU 
     b                            + dm*(PQPhuRU - PQPhuRD)

c     We now interpolate on upstream head for the values at p and hu.

      Q = fl_hu*QL + fr_hu*QR + flp_hu*PQPhuL  + frp_hu*PQPhuR

c     Note that PQPhu is with pfd held fixed.  To get the 
c     derivative of flow with respect to hu,  with the hd held
c     fixed, we must also include the variation of pfd with hu. 
c     A somewhat subtle point that I missed on the first pass!


      PQPhu = dlp_hu*PQPhuL + drp_hu*PQPhuR + dm_hu*(QR - QL)

c     compute the derivative of free drop wrt to ups head.
      dthdropdhu = 
     a    dlp_hu*dhdropl + drp_hu*dhdropr + dm_hu*(hdropr - hdropl)


      PQPpfd = fl_hu*PQPpfdL + fr_hu*PQPpfdR 
     a                  + flp_hu*PPQPpfdPhuL + frp_hu*PPQPpfdPhuR
      DQED =  -PQPpfd/thdrop

c     Now we can compute DQEU, that is, the partial of Q wrt hu when 
c     hd is held constant.  

      DQEU = PQPhu + PQPpfd*(1. - P*dthdropdhu)/thdrop
      FREE = 0
 
 9000 CONTINUE
 

      RETURN
 
      END

c
c
c
      subroutine store43(stdout, table, source, maxrow, nhu, npfd, 
     i            huall, freedrop,  pfdropphu, pfd, qmat, pqppfd, 
     i            pqphu, ppQppfdphu, ftp, hdatum,
     o            ftpup)

c     Store table of type = 43- bicubic pp Hermite at a minimum yielding
c     values of flow and its first derivative wrt to both ups and dns head
c     that are continuous.  In most cases the the second derivatives will 
c     also be continuous because the tables are created by fitting, in so 
c     far as possible, cubic splines.  However, we apply variation limitation
c     to these splines to avoid the wild nonesense that sometimes occurs 
c     in non-linear interpolation.  However, in testing and checking 
c     so far, the points with changes to derivative to enforce monotone
c     variation between tabulated points, often represent fewer than 
c     1 per cent of the total. 

      implicit none
      integer nhu, npfd, maxrow, stdout, ftp, ftpup, table
      real hdatum 
      real*8 huall(nhu),freedrop(nhu), pfdropphu(nhu),
     a  pqppfd(maxrow,npfd), pqphu(maxrow,npfd), 
     b  ppQppfdphu(maxrow,npfd), qmat(maxrow,npfd),
     c  pfd(npfd)
      character*8 source
      

      include 'arsize.prm'
      include 'ftable.cmn'

c     Local

      integer i, j, ip, phu, ppfd, qoffset, it, pfq, eflag

c***********************************************************************
      ip = ftp
c     Check for room for storage.
      eflag = 0
      if(ip + TDTIOFF + 4*nhu*(1 + npfd) + npfd.gt.mrftab) then 
        CALL KIL
     I          (10,
     M           FTP, EFLAG)
        stop 'Abnormal stop. Out of function-table space!'
      endif
 
c      write(stdout,*) ' store43: ftp=',ftp,' on entry.'
c     Set head datum
      ftab(ip) = hdatum

c     Set table number as a dummy for now
      itab(ip+1) = table
      itab(ip+2) = 43
      
c     pointer to first upstream head
      phu = ip + TDTIOFF
      itab(ip+3) = phu
      itab(ip+4) = phu

c     We store 4 items for each upstream head.  
      
      ppfd = phu + 4*nhu
      itab(ip+5) = ppfd
      itab(ip+6) = ppfd

c     compute the offset between the flow at pfd=0 and pfd=1 for each 
c     ups head. 
      qoffset = 4*(npfd - 1)
      itab(ip+10) = qoffset

c     set the maximum upstream head
      ftab(ip+9) = sngl(huall(nhu))

c     store the information for upstream heads
      it = phu
      ppfd = phu + 4*nhu
      pfq = ppfd + npfd + qoffset
      do i=1,nhu
        ftab(it) = sngl(huall(i))
        ftab(it+1) = sngl(freedrop(i))
        ftab(it+2) = sngl(pfdropphu(i))
        itab(it+3) =  pfq
        it = it + 4
c       update to zero flow for the next head
        pfq = pfq + 4
c       point to free flow for the next head
        pfq = pfq + qoffset
      end do       


c     store the partial free drops
      it = ppfd
      do i=1,npfd
        ftab(it) = pfd(i)
        it = it + 1
      end do


c     store the flow and derivatives
      do i=1,nhu
        do j=1,npfd
          ftab(it) = qmat(i,j)
          ftab(it+1) = pqppfd(i,j)
          ftab(it+2) = pqphu(i,j)
          ftab(it+3) = ppQppfdphu(i,j)
          it = it + 4
        end do
      end do

c     Set the pointer to the next open location in the ftable system
      ftpup = it - 4


      return
      end
c
c
c
      subroutine convert_to_43(stdout, mlft, table, ip, hdatum,
     i                         verbose,
     m                         ftp, eflag)

c     Convert a type 13 table to type 43.  tabadr points to the type 13
c     table.  The table has just been added to ftab/itab.  We will extract
c     values from the table into local arrays, and then compute the type 43
c     data.  This will then be stored in ftab/itab at the same address.
c     We must return the updated ftp.  

      implicit none

      integer stdout, mlft, table, ip, ftp, eflag, verbose
      real hdatum

      include 'arsize.prm'
      include 'ftable.cmn'

c     Local

      integer ihu, ipfd, it, nhu, npfd, maxrow, phu, ppfd, ftpup 
      real*8 
     b       huall(pmxnhu+1),
     e       freedrop(pmxnhu+1),
     f       qmat(pmxnhu+1,pmxfrc), pfd(pmxfrc)

      character*8 source
c***********************************************************************
c     Compute the maxrow value for array passing
      maxrow = pmxnhu+1

c     Extract various values to compute the number of ups heads
c     and the number of partial free drops.  The type 13 storage pattern
c     includes the zero head and zero partial free drop even though
c     the input table format does not!

c     Get pointer to the first upstream head
      phu = itab(ip+3)

c     Get the pointer to the start of the partial free drop list.
c     This list follows after the info for the upstream heads is given
      ppfd = itab(ip+5)

c     The relationship is: ppfd = phu + 4*nhu.  Therefore we can compute
c     nhu from these two values
      nhu = (ppfd - phu)/4

c     the pattern for upstream heads is:
c       phu+0    hu 
c          +1    freedrop
c          +2    free flow
c          +3    offset from ppfd to the start of the list of flows for this
c                ups head for each partial free drop from 0 to 1.0.

c       Thus the difference between two consecutive  entries for the offset
c       should be the number of partial free drops!

      npfd = itab(phu+7) - itab(phu+3)

c      write(stdout,*) 'convert_to_43: nhu=',nhu,' npfd=',npfd

c     now extract the upstream heads and the free drop.
      it = phu
      do ihu=1,nhu      
        huall(ihu) = ftab(it)
        freedrop(ihu) = ftab(it+1)
        it = it + 4
      end do

c     extract the sequence of partial free drops next
      it = ppfd
      do ipfd=1,npfd
        pfd(ipfd) = ftab(it)
        it = it + 1
      end do

c     extract the flows.  Get pointer to the first flow for the first
c     upstream head and the first partial free drop. 
      it = ppfd + npfd
      do ihu=1,nhu
        do ipfd=1,npfd
          qmat(ihu,ipfd) = ftab(it)
          it = it + 1
        end do
      end do

c      write(stdout,*) ' '
c      write(stdout,*) ' Dump of qmat. Each row for an ups head!'
c
c      do ihu=1,nhu
c        write(stdout,50) huall(ihu),(qmat(ihu,ipfd), ipfd=1,npfd)
c50    format(f10.4,25(1pe12.5))
c      end do

c     Call the fitting routine, which also stores the table and does 
c     some test lookups.  ip should be the address of the type 13 table
c     being replaced.  ftpup is the new value of ftp that should be 
c     returned to the point of call.  source for now is passed but not used.
c     hdatum is used. 

      call twodtabfit
     I               (STDOUT, table, nhu, npfd, maxrow, hdatum,
     i                huall, freedrop, pfd, qmat,
     I                SOURCE, verbose,
     m                ip,
     O                EFLAG, ftpup)


      ftp = ftpup
      return
      end
C
C
C
      subroutine   twodtabfit
     I                   (STDOUT, table, nhu, npfd, maxrow, hdatum,
     i                    huall, freedrop, pfd, qmat,
     I                    SOURCE, verbose,
     m                    ftp,
     O                    EFLAG, ftpup)
 
C     + + + PURPOSE + + +
C     Fit a table of type 13 to create information for a table of type 43.
c     The basic data for a type 13 table is already stored in the proper
c     arrays for processing.  Note that here  qmat includes all flows
c     at zero upshead and zero drop.  The partial free drop sequence and
c     the upstream head sequences are complete, having their zero entries
c     present.  nhu gives the count of all  upstream heads including zero,
c     and npfd gives all partial free drops including zero. 
 
      IMPLICIT NONE

C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER EFLAG, FTP, ftpup,  nhu, npfd, maxrow, 
     a        stdout, table, verbose
      real hdatum

      real*8 huall(nhu), freedrop(nhu), pfd(npfd),
     a       qmat(maxrow,npfd)

      CHARACTER  SOURCE*8
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I, ihu, ipfd, free, nadj, splineok, nadj_phu, 
     a        nadj_ppfd, nadj_mixed, cflag
      real ed, eu, qt, dqted, dqteu, eut, qtl, qtr,
     a qt_diff(10), dqted_diff(10), dqteu_diff(10),
     b qtdiff, dqteddiff, dqteudiff, dqeu, pdfm,
     c dqtedl, dqtedr, dqteul, dqteur, eps, dh, qpp
 
      integer lcode, rcode
      real*8 lval, rval, fac
      real*8 f(PMXNHU), m(PMXNHU),
     a       pqppfd(maxrow,npfd),
     b       pqphu(maxrow,npfd), 
     c       ppQppfdphu(maxrow,npfd),
     d       ppQphuppfd(maxrow,npfd),
     e       pfdropphu(nhu)
     f       
      character pqppfdadj(maxrow,npfd)*1, pqphuadj(maxrow,npfd)*1,
     a          adjloc(pmxfrc)*1,  make_monotone*4

c     note: ppQppfdphu is the mixed partial derivative of flow first with 
c     respect to hu and then wrt pfd.  ppQphuppfd is the mixed partial 
c     of flow first wrt pfd and then wrt hu.  We want to test if these 
c     are equal if no variation limitation is imposed. 

c     ***************************formats******************************** 
50    format(/,'Dump of results-----------------------------pfd values',
     a'-----------------------------------------------------------',/,
     a'hu/   Q-->',31f10.6)
52    format(f10.3,31(1pe10.4e1))
54    format('pQ/ppfd   ',30(1pe9.3e1,a1))
56    format('pQ/phu    ',30(1pe9.3e1,a1))
60    format('ppQ/ppfdph',30(1pe10.4e1))
62    format('ppQ/phppfd',30(1pe10.4e1))
72    format(5x,' There were',i5,' derivatives adjusted',
     a' representing ',f7.1,' per cent of the total.')
73    format(5x,' There were',i5,' derivatives adjusted for',
     a' pQ/ppfd and ',i5,' for pQ/phu.')
74    format(/,'Type 43 Error Summary',/,
     a'    Item   MaxRerr        hu        hd        Q ',
     b'pQ/phu|pfd   pQ/ppfd      Free        Qt   pQt/peu   pQt/ped')
75    format('       Q',f10.6,f10.3,f10.3,1pe10.3e1,1pe10.3e1,1pe10.3e1,
     a         0pf10.1,1pe10.3e1,1pe10.3e1,1pe10.3e1)
76    format('  dQ/deu',f10.6,f10.3,f10.3,1pe10.3e1,1pe10.3e1,1pe10.3e1,
     a         0pf10.1,1pe10.3e1,1pe10.3e1,1pe10.3e1)
77    format('  dQ/ded',f10.6,f10.3,f10.3,1pe10.3e1,1pe10.3e1,1pe10.3e1,
     a         0pf10.1,1pe10.3e1,1pe10.3e1,1pe10.3e1)
78    format(' Two-D table of type 43 is a bi-cubic spline')
79    format(' Two-D table of type 43 is a bi-cubic Hermite',
     a       ' piecewise polynomial')
C***********************************************************************
      make_monotone = 'YES'
      adjloc = ' '

c     Set not-a-knot conditions for cubic spline
      lcode = 3
      lval = 0.5d0
      rcode = 3
      rval = 0.5d0
      
c     fit free drop versus ups head
      call spline
     i        (stdout, huall, freedrop, nhu ,lcode, lval, rcode, rval,
     o           pfdropphu)


c     compute the 1-d spline fits of flow vs pfd for each upstream head.  This gives
c     the partials of flow wrt to pfd

c     Impose what seems like reasonable end conditions:
c     On the left, that is for pfd=0, that is, complete submergence
c     to zero flow, we know that the derivative is infinite.  However, 
c     we will not attempt to match that.  Instead we will just use 
c     the extension, maybe same as not-a-knot, end condition.
c     At the right end, that is, pfd=1.0, theory implies that the 
c     derivative should be zero.  It appears that to be consistent
c     as we approach free flow, that this condition must be forced 
c     as well.  7 march 2003. It seems that forcing zero derivative 
c     at the free-flow limit, as makes sense, does not make sense 
c     for some 2-D tables, especially those from CULVERT.  The actual
c     table contents do not support zero derivatives.  Thus we will 
c     shift that condition to the not-a-knot one as well.  Those tables
c     that DO statisfy the theory there should have small derivatives at the
c     free flow limit.  4 April 2003. 

      nadj = 0

      lcode = 3
      lval = 0.5d0
c     Theory would like this set. 
      rcode = 1
      rval = 0.0d0
c     but practice seems to want this one.  4 April 2003.  This
c     also produces equality between the two mixed derivatives at each
c     lattice point.  We can get this by forcing more complex conditions 
c     at the limits.  However, the not-a-knot condition for the mixed
c     deriatives is attractive. 
c      rcode = 3
c      rval = 0.5d0

      splineok = 0
      nadj_ppfd = 0
      do ihu=1,nhu
        do ipfd=1,npfd
          f(ipfd) =  qmat(ihu,ipfd)
        end do
        call spline
     i          (stdout, pfd, f, npfd ,lcode, lval, rcode, rval,
     o              m)
        if(make_monotone.eq.'YES') then
          call vrlim
     i              (npfd, pfd, f,
     m               m,
     o               nadj, adjloc)
        else
          nadj = 0
        endif
        splineok = splineok + nadj
        nadj_ppfd = nadj_ppfd + nadj

c       store results in matrix for later output and analysis 
        do ipfd=1,npfd
          pqppfd(ihu,ipfd) = m(ipfd)
          pqppfdadj(ihu,ipfd) = adjloc(ipfd)
        end do
      end do

c     Now do a fit for pfd constant, that is, flow versus upstream head
c     for each line of constant partial free drop.   

c     In some cases the partial wrt to hu with pfd held fixed should be 
c     zero at the left end.  EMBANKQ, CHANRAT, CULVERT, and even ORIFICE
c     all start out at small heads as weir-like flow.  Thus if pfd=1.0,
c     free flow, it is clear that the partial wrt to hu should be zero.

      lcode = 1
      lval = 0.0d0

c     Try not-a-knot
c      lcode = 3
c      lval = 0.5d0
      rcode = 3
      rval = 0.5d0

      nadj_phu = 0
      do ipfd=1,npfd
        do ihu=1,nhu
          f(ihu) = qmat(ihu,ipfd)
        end do

        call spline
     i          (stdout, huall, f, nhu, lcode, lval, rcode, rval,
     o              m)
        if(make_monotone.eq.'YES') then
          call vrlim
     i              (nhu, huall, f,
     m               m,
     o               nadj, adjloc)
        else
          nadj = 0
        endif
        splineok = splineok + nadj
        nadj_phu = nadj_phu + nadj

        do ihu=1,nhu
          pqphu(ihu,ipfd) = m(ihu)
          pqphuadj(ihu,ipfd) = adjloc(ihu)
        end do
      end do

c     For the mixed partials, we have no good theory to guide us 
c     in what conditions to use.  We select boundary conditions that
c     cause the two estimates of mixed partials to be equal whenever
c     a cubic-spline fit satisfies monotonicity requirements.  

      lcode = 3
      lval = 0.5d0
      rcode = 1
      rval = 0.0d0

c     Now compute the mixed partial derivatives.  
c     Do those wrt to pfd. 
    
      nadj = 0
      do ihu=1,nhu
        do ipfd=1,npfd
          f(ipfd) = pqphu(ihu,ipfd)
        end do
        call spline
     i          (stdout, pfd, f, npfd, lcode, lval, rcode, rval,
     o              m)
c       Only force monotonicity on the mixed partials if adjustments were 
c       made in the original fits. 
        if(nadj_phu.ne.0) then
          call vrlim
     i              (npfd, pfd, f,
     m               m,
     o               nadj_mixed, adjloc)
        endif
        do ipfd=1,npfd
          ppQppfdphu(ihu,ipfd) = m(ipfd)
        end do
      end do

c     Do those wrt to hu
      lcode = 1
      lval = 0.0d0
      rcode = 3
      rval = 0.5d0
      
      nadj = 0
      do ipfd=1,npfd
        do ihu=1,nhu
          f(ihu) = pqppfd(ihu,ipfd)
        end do

        call spline
     i          (stdout, huall, f, nhu, lcode, lval, rcode, rval,
     o              m)
        if(nadj_ppfd.ne.0) then
          call vrlim
     i              (nhu, huall, f,
     m               m,
     o               nadj_mixed, adjloc)
        endif
        do ihu=1,nhu
          ppQphuppfd(ihu,ipfd) = m(ihu)
        end do
      end do
      
      if(splineok.eq.0) then
        write(stdout,78) 
      else
        write(stdout,79)
        fac = float(splineok)/float(2*nhu*npfd)
        write(stdout,72) splineok, fac*100. 
        write(stdout,73) nadj_ppfd, nadj_phu
      endif

      if(verbose.eq.1) then 
        do ihu=1,nhu
          write(stdout,50) (pfd(i), i=1,npfd)

          write(stdout,52) huall(ihu), (qmat(ihu,ipfd), ipfd=1,npfd),
     a                     freedrop(ihu)
        
          write(stdout,54) 
     a    (pqppfd(ihu,ipfd), pqppfdadj(ihu,ipfd), ipfd=1,npfd),
     b     pfdropphu(ihu)

          write(stdout,56) 
     a    (pqphu(ihu,ipfd), pqphuadj(ihu,ipfd), ipfd=1,npfd)

          write(stdout,60) (ppQppfdphu(ihu,ipfd), ipfd=1,npfd)

          write(stdout,62) (ppQphuppfd(ihu,ipfd), ipfd=1,npfd)
        end do
      endif

c     store the table in the function-table structure but do not update 
c     the pointer.  We will do some tests of this table 
c     without retaining information in function-table structure. 
c     The pointer may be updated by the routine that calls this one
c     however. 

c      call store43(stdout, table, source, maxrow, nhu, npfd, 
c     i         huall, freedrop, pfdropphu, pfd, qmat, pqppfd, 
c     i         pqphu, ppQphuppfd, ftp,   hdatum ,
c     o         ftpup )
      call store43(stdout, table, source, maxrow, nhu, npfd, 
     i         huall, freedrop, pfdropphu, pfd, qmat, pqppfd, 
     i         pqphu, ppQppfdphu, ftp,   hdatum ,
     o         ftpup )


c     Check against the table at lattice points

c      write(stdout,71)
c71    format('        hu        hd        qt    qtdiff',
c     a'     dqted dqteddiff     dqteu dqteudiff free')
      qt_diff(1) = -1.e10
      dqteu_diff(1) = -1.e10
      dqted_diff(1)  = -1.e10

c     eliminate zero free drop for checking
      if(freedrop(1).eq.0.0) then
        freedrop(1) = freedrop(2)
      endif
      do ihu=1,nhu
        do ipfd=1,npfd
          eu = huall(ihu) 
          ed = huall(ihu) - pfd(ipfd)*freedrop(ihu) 

c         set datum to zero so that heads are used!
          call tdlk43
     I               (STDOUT, ftp, 43, 0, 0.0d0, ED, EU,
     I                0.0,
     O                qt, dqted, dqteu, free)

          if(qmat(ihu,ipfd).gt.0.0) then
            qtdiff = (qt - qmat(ihu,ipfd))/max(0.005d0,qmat(ihu,ipfd))
          else
c           use absolute error.
            qtdiff = qt
          endif
          if(abs(qtdiff).gt.qt_diff(1)) then
            qt_diff(1) = abs(qtdiff)
            qt_diff(2) = eu
            qt_diff(3) = ed
            qt_diff(4) = qmat(ihu,ipfd)
            qt_diff(5) = pqphu(ihu,ipfd)
            qt_diff(6) = pqppfd(ihu,ipfd)
            qt_diff(7) = free
            qt_diff(8) = qt
            qt_diff(9) = dqteu
            qt_diff(10) = dqted

          endif
          if(abs(pqppfd(ihu,ipfd)).gt. 0.0) then
            dqteddiff = 
     a     (dqted + pqppfd(ihu,ipfd)/max(0.001d0,freedrop(ihu)))/
     a      max(0.005d0,abs(pqppfd(ihu,ipfd)/freedrop(ihu)))
          else
c           use absolute error.
            dqteddiff =  abs(pqppfd(ihu,ipfd)/freedrop(ihu))
          endif  
          if(abs(dqteddiff).gt.dqted_diff(1)) then
            dqted_diff(1) = abs(dqteddiff)
            dqted_diff(2) = eu
            dqted_diff(3) = ed
            dqted_diff(4) = qmat(ihu,ipfd)
            dqted_diff(5) = pqphu(ihu,ipfd)
            dqted_diff(6) = pqppfd(ihu,ipfd)
            dqted_diff(7) = free
            dqted_diff(8) = qt
            dqted_diff(9) = dqteu
            dqted_diff(10) = dqted
          endif

c         compute dqeu from the basic data
          dqeu = pqphu(ihu,ipfd) + pqppfd(ihu,ipfd)*
     a         (1.0 - pfd(ipfd)*pfdropphu(ihu))/freedrop(ihu)
          if(abs(dqeu).gt.0.0) then
            dqteudiff = 
     a       (dqteu - dqeu)/max(0.005,abs(dqeu))
          else
c           use absolute error
            dqteudiff = abs(dqteu)
          endif  
          if(abs(dqteudiff).gt.dqteu_diff(1)) then
            dqteu_diff(1) = abs(dqteudiff)
            dqteu_diff(2) = eu
            dqteu_diff(3) = ed
            dqteu_diff(4) = qmat(ihu,ipfd)
            dqteu_diff(5) = pqphu(ihu,ipfd)
            dqteu_diff(6) = pqppfd(ihu,ipfd)
            dqteu_diff(7) = free
            dqteu_diff(8) = qt
            dqteu_diff(9) = dqteu
            dqteu_diff(10) = dqted
          endif
c          write(stdout,73) 
c     a      eu, ed, qt, qtdiff, dqted, dqteddiff, dqteu, dqteudiff, free
c
c73    format(f10.3,f10.3,6(1pe10.3),i5)

        end do
      end do

      write(stdout,74)

      write(stdout,75) qt_diff
 
      write(stdout,76) dqteu_diff
 
      write(stdout,77) dqted_diff
 
c     check for continuity of function and derivative between lattice points.

      eps = 5.e-4
      cflag = 0
      do ipfd=2,npfd
        pdfm = 0.5*(pfd(ipfd-1) + pfd(ipfd))
        do ihu=2,nhu-1
          cflag = 0
          eu = huall(ihu) 
          eut = eu - eu*epsilon(eu)

          ed = eut - pdfm*freedrop(ihu) 

c         Compute a small deviation from the ups elevation/head
c         to force lookup on both sides of the tabulated values. 

c         set datum to zero so that heads are used!
          call tdlk43
     I               (STDOUT, ftp, 43, 0, 0.0d0, ED, eut,
     I                0.0,
     O                qtl, dqtedl, dqteul, free)

          call tdlk43
     I               (STDOUT, ftp, 43, 0, 0.0d0, ED, eu,
     I                0.0,
     O                qt, dqted, dqteu, free)

          eut = eu + eu*epsilon(eu)
          call tdlk43
     I               (STDOUT, ftp, 43, 0, 0.0d0, ED, eut,
     I                0.0,
     O                qtr, dqtedr, dqteur, free)


          if(min(abs(dqtedl),abs(dqtedr)).gt.eps) then
            if( abs(0.5*(dqtedl  - dqtedr)/
     a                  min(abs(dqtedl),abs(dqtedr))).gt.eps) then

              cflag =  1
            endif
          else
            if(abs(dqtedl - dqtedr).gt.eps) then
              cflag =  1
            endif
          endif
          if(min(abs(dqteul),abs(dqteur)).gt.eps) then
            if( abs(0.5*(dqteul  - dqteur)/
     a                  min(abs(dqteul),abs(dqteur))).gt.eps) then
              cflag =  1
            endif
          else
            if(abs(dqteul - dqteur).gt.eps) then
              cflag =  1
            endif
          endif
                                                                                      
      if(cflag.gt.0) then
c        write(stdout,80) cflag
c80    format(/,'Warning: Count of derivative discontinuities=',i5)

        write(stdout,82) eu, eut, ed, dqtedl, dqtedr, dqteul, dqteur,
     a    pdfm
82    format(/,'Warning: deriv discon:',/,
     a 'eu=',f14.8,' eut=',f14.8,' ed=',f12.7,' dqtedl=',1pe12.5,
     b ' dqtedr=',1pe12.5,' dqteul=',1pe12.5,' dqteur=',1pe12.5,
     c  ' pdfm=',1pe12.5)
      endif

        end do
      end do


      RETURN
      END
C
C
C
      SUBROUTINE   VRLIM
     I                  (N, X, Y,
     M                   M,
     O                   nadj, ADJLOC)
 
C     + + + PURPOSE + + +
C     Force limited variation on the cubic piecewise polynomial
C     representation of the function Y.

      IMPLICIT NONE

C     + + + DUMMY ARGUMENTS + + +
      INTEGER N, nadj
      DOUBLE PRECISION M(N), X(N), Y(N)

      character adjloc(n)*1

 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     N      - number of points
C     X      - breakpoints for the spline
C     Y      - function values for spline
C     M      - Vector of first derivatives
C     ADJLOC - values at which slope was adjusted to limit variation
 
C     + + + LOCAL VARIABLES + + +
      INTEGER I
      DOUBLE PRECISION R, S, SL, SR, st, xl, xr
 
C     + + + INTRINSICS + + +
      INTRINSIC ABS, MIN, SIGN
C***********************************************************************
C     To have limited variation, the ratio, R,  of the derivative at the
C     breakpoints in X(*) to the slopes in M(*)
C     must satisfy 0 <= R <= 3 at each breakpoint.  This is somewhat more
c     restrictive than it need be.  For example if the relative slope on the
c     left is 1.0 then the relative slope on the right may be as large as 
c     4 and still maintain a zero or positive slope.  However, making the 
c     changes depend on a particular slope outcome is more involved. 

c     Thus we restrict the relative slope to be between 0 and 3 even though
c     that forces a change at a point where the variation is already monotone.
c     We capture most of the region involved this way and keep the adjustment
c     of computed slopes relatively simple.  If we made the adjustment 
c     dependent on the local computed slopes, to gain more of the region of 
c     monotone behavior, then we have to have special action if the computed
c     relative slope is negative and the problem of propagation of changes
c     must be solved.  We are only trying to create a smoother function 
c     to constrain wild behavior.  This smoother function 
c     may be more accurate but we have not checked nor are we motivated 
c     by concern for accuracy here-we are motivated by concern for smoothness
c     and certainty about the nature of interpolated results. 
c     13 march 2003.

 
      nadj = 0
C     Check the left end.  Chord is on the right.
 
      xr = (X(2) - X(1))
      SR = (Y(2) - Y(1))/xr
 
      ADJLOC(1) = ' '
      IF(SR.EQ.0.D0) THEN
        IF(M(1).NE.0.D0) THEN
C         Derivative must be zero if the secant slope is zero
          M(1) = 0.D0
          ADJLOC(1) = '^'
          nadj = nadj + 1
        ENDIF
      ELSE
        R = M(1)/SR
        IF(R.GT.3.D0) THEN
c         Limit slope to three times the secant slope. 
          M(1) = 3.D0*SR
          ADJLOC(1) = '^'
          nadj = nadj + 1
        ELSEIF(R.LT.0.0) THEN 
c         The slope  outcome for the spline is inconsistent with the 
c         slope of the secant.  Force the slope to match
c         the slope of the secant at this point
          M(1) = SR
          ADJLOC(1) = '^'
          nadj = nadj + 1
        ENDIF
      ENDIF
 
C     Now check the interior breakpoints.  Each point has two chords.
 
      SL = SR
      xl = xr
      DO 100 I=2,N-1
        ADJLOC(I) = ' '
        xr = X(I+1) - X(I)
        SR = (Y(I+1) - Y(I))/xr
 
C       Derivative must be zero at a local extreme
 
        IF(SL*SR.LE.0.0) THEN
          IF(M(I).NE.0.D0) THEN
            ADJLOC(I) = '^'
            nadj = nadj + 1
            M(I) = 0.D0
          ENDIF
        ELSE
C         Find the chord slope closest to 0.  SL and SR are of the
C         same sign here and both differ from 0.
 
          S = SIGN(MIN(ABS(SL), ABS(SR)), SL)
          R = M(I)/S
          IF(R.GT.3.D0) THEN
            M(I) = 3.D0*S
            ADJLOC(I) = '^'
            nadj = nadj + 1
         ELSEIF(R.LT.0.D0) THEN
c          Computed derivative is inconsistent.   Match the 
c          slope estimated from the secants to the left and right of 
c          point.  We do not use a three-point slope estimate because if
c          a cubic spline fit has a "wild" derivative here, then so will 
c          a parabola.  Use a weighted-slope estimate so that we get 
c          improved accuracy if the argument increment is locally uniform. 
           st = (sl*xr + sr*xl)/(xl + xr)
           r = st/s
           if(r.gt.3.d0) then
c            Limit slope to 3 times the smaller secant slope at this point. 
             st = 3.d0*s
           endif
           M(I) = st
           ADJLOC(I) = '^'
           nadj = nadj + 1
          ENDIF
        ENDIF
        SL = SR
        xl = xr
 100  CONTINUE
 
C     Check right end.  Chord is on left and its slope was computed
C     in the loop just completed.
 
      ADJLOC(N) = ' '
      IF(SL.EQ.0.D0) THEN
        IF(M(N).NE.0.D0) THEN
C         Force derivative to 0.
          M(N) = 0.D0
          ADJLOC(N) = '^'
          nadj = nadj + 1
        ENDIF
      ELSE
        R = M(N)/SL
        IF(R.GT.3.D0) THEN
          M(N) = 3.D0*SL
          ADJLOC(N) = '^'
          nadj = nadj + 1
        ELSEIF(R.LT.0.D0) THEN
c         outcome for the spline is inconsistent with the 
c         slope of the secant.  Force the slope to match
c         the slope of the secant at this point
          M(N) = SL
          ADJLOC(N) = '^'
          nadj = nadj + 1
        ENDIF
      ENDIF
      RETURN
      END

C
C
C
      SUBROUTINE   SPLINE
     I                   (STDOUT, X, Y, N, LCODE, LVAL, RCODE, RVAL,
     O                    M)
 
C     + + + PURPOSE + + +
C     Estimate the first derivative of Y wrt X at each of the
C     N pairs of points stored in X(*),Y(*) and store in M(*).
C     Use a cubic spline with specified end conditions.
 
      IMPLICIT NONE

C     + + + DUMMY ARGUMENTS + + +
      INTEGER LCODE, N, RCODE, STDOUT
      REAL*8 LVAL, M(N), RVAL, X(N), Y(N)
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT - Fortran unit number for user output and messages
C     X      - Abscissas for cubic spline
C     Y      - Ordinate values for cubic spline
C     N      - Number of points defining the cubic spline
C     LCODE  - Code for left hand end condition
C     LVAL   - Value of the left hand end condition
C     RCODE  - Code for the right-hand end condition
C     RVAL   - Value of the right-hand end condition
C     M      - Vector of first derivatives
 
C     + + + LOCAL PARAMETERS + + +
      INTEGER MAXN
      PARAMETER(MAXN=1000)
 
C     + + + LOCAL VARIABLES + + +
      INTEGER IFLAG, J
      DOUBLE PRECISION D(MAXN), H, HJ, HJP1, L(MAXN), U(MAXN)
 
C     + + + EXTERNAL NAMES + + +
      EXTERNAL TRID
C***********************************************************************
      IF(N.GT.MAXN) THEN
        WRITE(STDOUT,*) 'TOO MANY POINTS FOR SUBROUTINE SPLINE'
        WRITE(STDOUT,*) 'SPACE FOR ',MAXN,' POINTS BUT ',N,' POINTS',
     1              ' REQUESTED'
        STOP 'Abnormal stop. Errors found.'
      ENDIF
      IF(N.LT.2) THEN
        WRITE(STDOUT,*) 'LESS THAN TWO POINTS IN SUB. SPLINE. AT LEAST',
     1             ' TWO ARE REQUIRED.'
        STOP 'Abnormal stop. Errors found.'
      ENDIF
 
C     COMPUTE THE VALUES IN L, D, U, AND M.  M SERVES AS THE RIGHT
C     HAND SIDE VECTOR FOR NOW
 
 
      HJ = X(2) - X(1)
      DO 100 J=2,N-1
        HJP1 = X(J+1) - X(J)
        L(J) = HJP1/(HJ + HJP1)
        U(J) = 1.D0 - L(J)
        D(J) = 2.D0
        M(J) = 3.D0*(L(J)*(Y(J) - Y(J-1))/HJ +
     1               U(J)*(Y(J+1) - Y(J))/HJP1)
 
        HJ = HJP1
 100  CONTINUE
 
C     DO THE LEFT END CONDITION
 
      D(1) = 2.D0
      H = X(2) - X(1)
      IF(LCODE.EQ.1) THEN
C       FIRST DERIVATIVE GIVEN
 
        U(1) = 0.D0
        M(1) = 2.D0*LVAL
 
      ELSE IF(LCODE.EQ.2) THEN
C       SECOND DERIVATIVE GIVEN
 
        U(1) = 1.D0
        M(1) = 3.D0*(Y(2) - Y(1))/H - 0.5D0*H*LVAL
 
      ELSE
C       SPECIAL END CASE
 
          U(1) = 4.D0*(1.D0 - LVAL)/(4.D0 - LVAL)
          M(1) = 6.D0*(2.D0 - LVAL)*(Y(2) - Y(1))/
     1                ((4.D0 - LVAL)*H)
      ENDIF
 
 
C     DO RIGHT END CONDITION
 
      D(N) = 2.D0
      H = X(N) - X(N-1)
      IF(RCODE.EQ.1) THEN
        L(N) = 0.D0
        M(N) = 2.D0*RVAL
      ELSE IF(RCODE.EQ.2) THEN
        L(N) = 1.D0
        M(N) = 3.D0*(Y(N) - Y(N-1))/H + 0.5D0*H*RVAL
      ELSE
        L(N) = 4.D0*(1.D0 - RVAL)/(4.D0 - RVAL)
        M(N) = 6.D0*(2.D0 - RVAL)*(Y(N) - Y(N-1))/
     1              ((4.D0 - RVAL)*H)
      ENDIF
 
C     FIND THE SOLUTION
 
      CALL TRID
     I         (L, U, N,
     M          D, M,
     O          IFLAG)
 
      IF(IFLAG.EQ.1) THEN
        WRITE(STDOUT,*) 'SINGULAR MATRIX IN SUBROUTINE SPLINE'
        STOP 'Abnormal stop. Errors found.'
      ENDIF
 
      RETURN
 
      END

C
C
C
      subroutine   trid
     I                 (sb, sp, n,
     M                  md, rhs,
     O                  iflag)
 
c     + + + purpose + + +
c     Solve the tridiagonal system with coefficient matrix
c     given by sb, md, sp.  sb(1) and sp(n) are not used.
c     The right hand side is contained in rhs. n gives the number of
c     equations.  md and rhs are changed in the solution
c     process.  rhs is used to return the solution.
c     Based on Conte and DeBoor, 1st Ed. p. 122.
 
c     iflag=1 signals a singular matrix
 
      implicit none

c     + + + dummy arguments + + +
      integer iflag, n
      double precision rhs(n), md(n), sb(n), sp(n)
 
c     + + +DUMMY ARGUMENT DEFINITIONS + + +
c     sb    - Sub-diagonal elements
c     sp    - Super diagonal elements
c     n      - Number of equations
c     md   - main diagonal elements for a tri-diagonal matrix
c     rhs      - Right hand side vector
c     iflag  - error flag
 
c     + + + LOCAL VARIABLES + + +
      integer k
      double precision rat
c***********************************************************************
      iflag = 0
 
       if(n.eq.1) then
        if(md(1).eq.0.d0) then
           iflag = 1
           return
        endif
 
        rhs(1) = rhs(1)/md(1)
        return
      else
 
        do 11 k=2,n
          if(md(k-1).eq.0.d0) then
            iflag=1
            return
          endif
          rat = -sb(k)/md(k-1)
          md(k) = md(k) + rat*sp(k-1)
          rhs(k) = rhs(k) + rat*rhs(k-1)
 11     continue
 
        if(md(n).eq.0.d0) then
          iflag = 1
          return
        endif
        rhs(n) = rhs(n)/md(n)
        do 12 k=n-1,1,-1
          rhs(k) = (rhs(k) - sp(k)*rhs(k+1))/md(k)
 12     continue
      endif
 
      return
 
      end

c
c
c
      subroutine store_xsec_tab(stdout, ndep, type, tabid, tab,
     i              stat, zmin, slot_depth, gisid, easting, northing,
     i              xst, max_arg, zone, hgrid, vdatum, unitsys, basis,
     m              ftp) 

c     Store a cross section table in the FTAB/ITAB system

      implicit none
c     + + + parameters + + +
      include 'arsize.prm'

      integer stdout, ndep, type, tab, ftp
      real stat, xst(pmxpnt,pmxelm), zmin, slot_depth, max_arg
      real*8 easting, northing
      character tabid*16, gisid*16, zone*8, hgrid*8, vdatum*8,
     a          unitsys*8, basis*8


      INCLUDE 'ftable.cmn'
      INCLUDE 'offcom.cmn'

c     Local
      integer i, j, nstore
C     ***********************formats************************************
50    format(/,'*BUG* type=',i5, 'in store_xsec_tab invalid.')

c***********************************************************************
      FTPNT(TAB) = FTP
      ITAB(FTP+1) = TAB
      ITAB(FTP+2) = TYPE
      ITAB(FTP+3) = FTP + XTIOFF
      FTAB(FTP+4) = STAT
c     Apply vertical datum shift.  Must default to 0.0!
      FTAB(FTP+5) = ZMIN
C     Store the maximum unextrapolated argument in the
C     cross-section function table.
      FTAB(FTP+6) = max_arg
C     Put the slot depth into the table--Note: SLOT_DEPTH <=0.0
      FTAB(FTP+7) = SLOT_DEPTH
C     Put the easting coordinate value in the table.
      CALL PUT_DP_IN_FT(FTP+8, EASTING)
C     Put the northing coordinate value in the table
      CALL PUT_DP_IN_FT(FTP+10, NORTHING)

C     Store the GIS identifier string.  May be blank. 
      CALL PUT_STRING_IN_FT(FTP+12, GISID)
C     Store the table name in the table. 
      CALL PUT_STRING_IN_FT(FTP+16, TABID)

c     Store the zone, grid, datum, and unitsys information
      call put_chr8_in_ft(ftp+22, zone)
      call put_chr8_in_ft(ftp+24, hgrid)
      call put_chr8_in_ft(ftp+26, vdatum)
      call put_chr8_in_ft(ftp+28, unitsys)
      call put_chr8_in_ft(ftp+30, basis)


C     Set the offset to the extra derivatives 
c      write(stdout,*) 'store_xsec_tab: storing type=',type
      if(type.le.25) then
        itab(ftp+21) = 0
      else
        itab(ftp+21) = offvec(type-10)
c        write(stdout,*) ' doff=',itab(ftp+21)
      endif
      nstore = offvec(type)
      I = FTP + XTIOFF
      DO 200 J=1, NDEP
        FTAB(I+0) = XST(J,1)
        FTAB(I+1) = XST(J,2)
        FTAB(I+2) = XST(J,3)
        FTAB(I+3) = XST(J,5)
        FTAB(I+4) = XST(J,6)
 
C       REMAINDER OF THE TABLE DEPENDS ON THE TYPE. 
        select case (type)

        case default
          WRITE(STDOUT,50) type
          STOP 'Abnormal stop. Bug found.'
 
        case(20)
C         TABLE TYPE 20.  EVERYTHING ALREADY STORED
 
        case(21)
C         TABLE TYPE 1 AND 21.  ADD STORAGE OF THE FIRST MOMENT OF
C         AREA ABOUT THE WATER SURFACE.
          FTAB(I+5) = XST(J,4)
 
        case(22)
C         TABLE TYPE 12 AND 22.  ADD FIRST MOMENT, ALPHA, AND
C         CRITICAL FLOW
          FTAB(I+5) = XST(J,4)
          FTAB(I+6) = XST(J,7)
          FTAB(I+7) = XST(J,13)
 
        case(23)
C         TABLE TYPE 23.  ADD THE CURVILINEAR ELEMENTS: MA AND MQ
          FTAB(I+5) = XST(J,14)
          FTAB(I+6) = XST(J,15)
 
        case(24)
C         TABLE TYPE 24.  ADD FIRST MOMENT, MA, AND MQ
          FTAB(I+5) = XST(J,4)
          FTAB(I+6) = XST(J,14)
          FTAB(I+7) = XST(J,15)
 
        case(25)
C         TABLE TYPE 25. ADD FIRST MOMENT, ALPHA, CRITICAL FLOW, MA,
C         AND MQ.
          FTAB(I+5) = XST(J,4)
          FTAB(I+6) = XST(J,7)
          FTAB(I+7) = XST(J,13)
          FTAB(I+8) = XST(J,14)
          FTAB(I+9) = XST(J,15)


        case(30)
C         TABLE TYPE 30. store dkh/dy and dbeta/dy from cubic-spline fit.
          ftab(i+5) = xst(j,18)
          ftab(i+6) = xst(j,20) 
 
        case(31)
C         TABLE 31.  add first moment, dkh/dy and dbeta/dy from cubic-spline fit 
          FTAB(I+5) = XST(J,4)
          FTAB(I+6) = XST(J,18)
          ftab(i+7) = xst(j,20) 
 
        case(32)
C         TABLE type 32. add first moment, alpha, critical flow. dkh/dy, dbeta/dy, dalpha/dy from cubic-spline fit 
          FTAB(I+5) = XST(J,4)
          FTAB(I+6) = XST(J,7)
          FTAB(I+7) = XST(J,13)
          FTAB(I+8) = XST(J,18)
          FTAB(I+9) = XST(J,20)
          FTAB(I+10) = XST(J,19)
 
        case(33)
C         TABLE TYPE 33. add ma, mq.  dkh/dy, dbeta/dy, dma/dy, and dmq/dy from cubic-spline fit
          FTAB(I+5) = XST(J,14)
          FTAB(I+6) = XST(J,15)
          FTAB(I+7) = XST(J,18)
          FTAB(I+8) = XST(J,20)
          FTAB(I+9) = XST(J,21)
          FTAB(I+10) = XST(J,22)
 
        case(34)
C         TABLE TYPE 34. add first moment, ma, mq, dkh/dy, dbeta/dy, dma/dy, and dmq/dy from cubic-spline fit
          FTAB(I+5) = XST(J,4)
          FTAB(I+6) = XST(J,14)
          FTAB(I+7) = XST(J,15)
          FTAB(I+8) = XST(J,18)
          FTAB(I+9) = XST(J,20)
          FTAB(I+10) = XST(J,21)
          FTAB(I+11) = XST(J,22)
 
C     Offset    Value
C     1         Maximum depth-y
C     2         Top width
C     3         Area
C     4         First moment of area about water surface
C     5         Square root of conveyance- kh
C     6         Beta
C     7         Alpha
C     8         dBeta/dy
C     9         dAlpha/dy
C     10        Critical flow from momentum
C     11        Critical flow from energy
C     12        Critcal flow assuming Alpha=beta=1
C     13        Critical flow that is selected by user: 10, 11, or 12
C     14        MA- correction of volumes for sinuousity
C     15        MQ- correction of momentum for sinuosity
C     16        Total wetted perimeter- added May 22, 1998
C     17        Average Manning's n value for the cross section 
c     18        dkh/dy computed by cubic-spline fit
c     19        dalpha/dy computed by cubic-spline fit
c     20        dbeta/dy computed by cubic-spline fit
c     21        dma/dy computed by cubic-spline fit
c     22        dmq/dy computed by cubic-spline fit
        case(35)
C         TABLE TYPE 35. add first moment, alpha, critical flow, ma, mq, dkh/dy, dbeta/dy, dma/dy, dma/dy, and dalpha/dy from cubic-spline fit 
          FTAB(I+5) = XST(J,4)
          FTAB(I+6) = XST(J,7)
          FTAB(I+7) = XST(J,13)
          FTAB(I+8) = XST(J,14)
          FTAB(I+9) = XST(J,15)
          FTAB(I+10) = XST(J,18)
          FTAB(I+11) = XST(J,20)
          FTAB(I+12) = XST(J,21)                       
          FTAB(I+13) = XST(J,22)
          FTAB(I+14) = XST(J,19)
        end select
 
        I = I + NSTORE
 200  CONTINUE
      ITAB(FTP) = I - NSTORE
      FTP = I

      return
      end

C
C
c
      subroutine do_upgrade_xsec_tab(stdout, ip, 
     i                         verbose,
     m                         ftp, eflag)

c     Convert tables of 20-25 to 30-35.  The table has just been added
c     to the ftab/itab system.  We will extract the data to  local arrays,
c     compute the additional values, and then store the table into the 
c     current location of the table.  
c     

      implicit none

      integer stdout, ip, ftp, eflag, verbose

      include 'arsize.prm'
      include 'ftable.cmn'
      include 'offcom.cmn'

      real*8 GET_DP_FROM_FT
      CHARACTER*16 GET_STRING_FROM_FT
      character*8 get_chr8_from_ft
      EXTERNAL GET_STRING_FROM_FT, GET_DP_FROM_FT,
     a         get_chr8_from_ft
c     Local

      integer i, la, ha, type, xoff, ndep, tab
      real xst(pmxpnt,pmxelm), stat, zmin, slot_depth
      real yl, ym, yr, khl, khm, khr, dkhl, dkhm, dkhr,
     a       betal, betam, betar, dbetal, dbetam, dbetar,
     b alphal, alpham, alphar, dalphal, dalpham,  dalphar,
     d mal, mam, mar, dmal, dmam, dmar, 
     e mql, mqm, mqr, dmql, dmqm, dmqr,
     f kh_err, beta_err, alpha_err, ma_err, mq_err,
     g tl, tm, tr, al, am, ar, jl, jm, jr,
     h dtl, dtm, dtr, kl, km, kr, dkl, dkm, dkr,
     i qcl, qcm, qcr, 
     j max_kh_err,  max_beta_err, max_alpha_err, 
     k max_ma_err, max_mq_err, max_arg

      real*8 easting, northing

      CHARACTER 
     a  khflag(pmxpnt)*1, alphaflag(pmxpnt)*1, betaflag(pmxpnt)*1,
     b     maflag(pmxpnt)*1, mqflag(pmxpnt)*1,
     c  tabid*16, gisid*16, zone*8, hgrid*8, vdatum*8, unitsys*8,
     d  basis*8
c     ***************************formats********************************
50    format(/,' Possible problem on upgrade. Errors are:',/,
     a '        kh      beta     alpha        ma        mq')
52    format(5(1pe10.2))
54    format(' Upgrade is OK.')
60    format(/,' Possible problem on upgrade. Errors are:',/,
     a '        kh      beta')
62    format(2(1pe10.2))
70    format(/,' Possible problem on upgrade. Errors are:',/,
     a '        kh      beta        ma        mq')
72    format(4(1pe10.2))
c***********************************************************************

C     Added May 22, 1998: definition of XST(i,*) contents
c     Extended 13 March 2003

C     Offset    Value
C     1         Maximum depth-y
C     2         Top width
C     3         Area
C     4         First moment of area about water surface
C     5         Square root of conveyance- kh
C     6         Beta
C     7         Alpha
C     8         dBeta/dy
C     9         dAlpha/dy
C     10        Critical flow from momentum
C     11        Critical flow from energy
C     12        Critcal flow assuming Alpha=beta=1
C     13        Critical flow that is selected by user: 10, 11, or 12
C     14        MA- correction of volumes for sinuousity
C     15        MQ- correction of momentum for sinuosity
C     16        Total wetted perimeter- added May 22, 1998
C     17        Average Manning's n value for the cross section
c     18        dkh/dy computed by cubic-spline fit
c     19        dalpha/dy computed by cubic-spline fit
c     20        dbeta/dy computed by cubic-spline fit
c     21        dma/dy computed by cubic-spline fit
c     22        dmq/dy computed by cubic-spline fit


c     Extract the data from the itab/ftab structure for each type and place 
c     in xst.  Then call the fitting routine, and then store the new values
c     over the old.  ip gives the table address.   We will fill in the 
c     data in fields not in the tables so that the fitting process can compute 
c     values even though they are not needed.


C     ha = high address
C     la = low address
 
      ha = itab(ip)
      la = ip + XTIOFF
      type = itab(ip+2)
      xoff = offvec(type)

      ndep = 0
      do i=la,ha,xoff
        ndep = ndep + 1

c       extract the universal element group.
c       max depth in the section
        xst(ndep,1) = ftab(i)
c       top width
        xst(ndep,2) = ftab(i+1)
c       area
        xst(ndep,3) = ftab(i+2)
c       sqrt of conveyance
        xst(ndep,5) = ftab(i+3)
c       beta
        xst(ndep,6) = ftab(i+4)

        select case (type)

        case(20)
c         first moment
          xst(ndep,4) = 0.0
c         alpha 
          xst(ndep,7) = 1.0
c         critical flow
          xst(ndep,13) = 0.0
c         ma
          xst(ndep,14) = 1.0
c         mq
          xst(ndep,15) = 1.0

        case(21)
          xst(ndep,4) = ftab(i+5)
          xst(ndep,7) = 1.0
          xst(ndep,13) = 0.0
          xst(ndep,14) = 1.0
          xst(ndep,15) = 1.0

        case(22)
          xst(ndep,4) = ftab(i+5)
          xst(ndep,7) = ftab(i+6)
          xst(ndep,13) = ftab(i+7)
          xst(ndep,14) = 1.0
          xst(ndep,15) = 1.0

        case(23)
          xst(ndep,4) = 0.0
          xst(ndep,7) = 1.0
          xst(ndep,13) = 0.0
          xst(ndep,14) = ftab(i+5)
          xst(ndep,15) = ftab(i+6)

        case(24)
          xst(ndep,4) = ftab(i+5)
          xst(ndep,7) = 1.0
          xst(ndep,13) = 0.0
          xst(ndep,14) = ftab(i+6)
          xst(ndep,15) = ftab(i+7)
        
        case(25)  
          xst(ndep,4) = ftab(i+5)
          xst(ndep,7) = ftab(i+6)
          xst(ndep,13) = ftab(i+7)
          xst(ndep,14) = ftab(i+8)
          xst(ndep,15) = ftab(i+9)
        end select
      end do



      call xsecfit(STDOUT, verbose,
     M             NDEP, XST, 
     o             khflag, alphaflag, betaflag, maflag, mqflag)



c     extract stuff to be restored
      TAB = ITAB(ip+1) 
      STAT = FTAB(ip+4)
      ZMIN = FTAB(ip+5)
      max_arg = ftab(ip+6)
      SLOT_DEPTH = FTAB(ip+7) 
C     Put the easting coordinate value in the table.
      easting = GET_DP_FROM_FT(ip+8)
      northing = GET_DP_FROM_FT(ip+10)
      gisid = GET_string_FROM_FT(ip+12)
      tabid = GET_string_FROM_FT(ip+16)
c     get the zone, grid, datum, and unitsys information
      zone = GET_chr8_FROM_FT(ip+22)
      hgrid = GET_chr8_FROM_FT(ip+24)
      vdatum = GET_chr8_FROM_FT(ip+26)
      unitsys = GET_chr8_FROM_FT(ip+28)
      basis = GET_chr8_FROM_FT(ip+30)


c     upgrade the type- always by 10.
      type = type + 10      

      
      call store_xsec_tab(stdout, ndep, type, tabid, tab,
     i              stat, zmin, slot_depth, gisid,
     i              easting, northing,
     i              xst, max_arg, zone, hgrid, vdatum, unitsys, basis,
     m              ftp) 


c     Compute checks on the upgraded tables and report summaries.

      select case (type)

      case(30)

      case(31)

        yl = xst(1,1)
        call  xlkt21
     i              (ip,
     m               yl,
     O               al, tl, dtl, jl, kl, dkl, betal, dbetal) 
        khl = 0.0
        dkhl = 0.0
        max_kh_err = -1.0
        max_beta_err = -1.0
        do i=2,ndep
          yr = xst(i,1)
          ym = 0.5*(yl + yr)
          call  xlkt21
     i                (ip,
     m                 ym,
     O                 am, tm, dtm, jm, km, dkm, betam, dbetam) 
          khm = sqrt(km)
          dkhm = 0.5*dkm/khm
          call  xlkt21
     i                (ip,
     m                 yr,
     O                 ar, tr, dtr, jr, kr, dkr, betar, dbetar) 
          khr = sqrt(kr)
          dkhr = 0.5*dkr/khr
        
          kh_err = khr - khl -(yr - yl)*(dkhl + 4.*dkhm + dkhr)/6.0
          kh_err = abs(kh_err)/max(abs(khr-khl),1.0)
          max_kh_err = max(max_kh_err, kh_err)
          
          beta_err = betar - betal -(yr - yl)*
     a                 (dbetal + 4.*dbetam + dbetar)/6.0
          beta_err = abs(beta_err)/max(abs(betar-betal),1.0)
          max_beta_err = max(max_beta_err, beta_err)
        
        
        
          yl = yr
          khl = khr
          dkhl = dkhr
          betal = betar
          dbetal = dbetar
        end do
        if(max(max_kh_err,  max_beta_err).gt.1.e-3) then

          write(stdout,60)
          write(stdout,62) max_kh_err,  max_beta_err
        else
          write(stdout,54) 
        endif

      case(32)

      case(33)
        yl = xst(1,1)
        call  xlkt23
     i              (ip,
     m               yl,
     O               al, tl, dtl, kl, dkl, betal, dbetal, 
     o                mal, dmal, mql, dmql)
        khl = 0.0
        dkhl = 0.0
        max_kh_err = -1.0
        max_beta_err = -1.0
        max_ma_err = -1.0
        max_mq_err = -1.0
c        write(stdout,50)
        do i=2,ndep
          yr = xst(i,1)
          ym = 0.5*(yl + yr)
          call  xlkt23
     i                (ip,
     m                 ym,
     O                 am, tm, dtm, km, dkm, betam, dbetam, 
     o                  mam, dmam, mqm, dmqm)
          khm = sqrt(km)
          dkhm = 0.5*dkm/khm
          call  xlkt23
     i                (ip,
     m                 yr,
     O                 ar, tr, dtr, kr, dkr, betar, dbetar, 
     o                  mar, dmar, mqr, dmqr)
          khr = sqrt(kr)
          dkhr = 0.5*dkr/khr
        
          kh_err = khr - khl -(yr - yl)*(dkhl + 4.*dkhm + dkhr)/6.0
          kh_err = abs(kh_err)/max(abs(khr-khl),1.0)
          max_kh_err = max(max_kh_err, kh_err)
          
          beta_err = betar - betal -(yr - yl)*
     a                 (dbetal + 4.*dbetam + dbetar)/6.0
          beta_err = abs(beta_err)/max(abs(betar-betal),1.0)
          max_beta_err = max(max_beta_err, beta_err)
        
        
          ma_err = mar - mal -(yr - yl)*(dmal + 4.*dmam + dmar)/6.0
          ma_err = abs(ma_err)/max(abs(mar-mal),1.0)
          max_ma_err = max(max_ma_err, ma_err)
        
          mq_err = mqr - mql -(yr - yl)*(dmql + 4.*dmqm + dmqr)/6.0
          mq_err = abs(mq_err)/max(abs(mqr-mql),1.0)
          max_mq_err = max(max_mq_err, mq_err)
        
        
          yl = yr
          khl = khr
          dkhl = dkhr
          betal = betar
          dbetal = dbetar
          mal = mar
          dmal = dmar
          mql = mqr
          dmql = dmqr
        end do
        if(max(max_kh_err,  max_beta_err,
     a                   max_ma_err, max_mq_err).gt.1.e-3) then

          write(stdout,70)
          write(stdout,72) max_kh_err,  max_beta_err,
     a                   max_ma_err, max_mq_err 
        else
          write(stdout,54) 
        endif

      case(34)

      
      case(35)  

        yl = xst(1,1)
        call  xlkt25
     i              (ip,
     m               yl,
     O               al, tl, dtl, jl, kl, dkl, betal, dbetal, 
     o               alphal, dalphal, qcl, mal, dmal, mql, dmql)
        khl = 0.0
        dkhl = 0.0
        max_kh_err = -1.0
        max_beta_err = -1.0
        max_alpha_err = -1.0
        max_ma_err = -1.0
        max_mq_err = -1.0
c        write(stdout,50)
        do i=2,ndep
          yr = xst(i,1)
          ym = 0.5*(yl + yr)
          call  xlkt25
     i                (ip,
     m                 ym,
     O                 am, tm, dtm, jm, km, dkm, betam, dbetam, 
     o                 alpham, dalpham, qcm, mam, dmam, mqm, dmqm)
          khm = sqrt(km)
          dkhm = 0.5*dkm/khm
          call  xlkt25
     i                (ip,
     m                 yr,
     O                 ar, tr, dtr, jr, kr, dkr, betar, dbetar, 
     o                 alphar, dalphar, qcr, mar, dmar, mqr, dmqr)
          khr = sqrt(kr)
          dkhr = 0.5*dkr/khr
        
          kh_err = khr - khl -(yr - yl)*(dkhl + 4.*dkhm + dkhr)/6.0
          kh_err = abs(kh_err)/max(abs(khr-khl),1.0)
          max_kh_err = max(max_kh_err, kh_err)
          
          beta_err = betar - betal -(yr - yl)*
     a                 (dbetal + 4.*dbetam + dbetar)/6.0
          beta_err = abs(beta_err)/max(abs(betar-betal),1.0)
          max_beta_err = max(max_beta_err, beta_err)
        
          alpha_err = alphar - alphal -(yr - yl)*
     a                             (dalphal + 4.*dalpham + dalphar)/6.0
          alpha_err = abs(alpha_err)/max(abs(alphar-alphal),1.0)
          max_alpha_err = max(max_alpha_err, alpha_err)
        
          ma_err = mar - mal -(yr - yl)*(dmal + 4.*dmam + dmar)/6.0
          ma_err = abs(ma_err)/max(abs(mar-mal),1.0)
          max_ma_err = max(max_ma_err, ma_err)
        
          mq_err = mqr - mql -(yr - yl)*(dmql + 4.*dmqm + dmqr)/6.0
          mq_err = abs(mq_err)/max(abs(mqr-mql),1.0)
          max_mq_err = max(max_mq_err, mq_err)
        
        
          yl = yr
          khl = khr
          dkhl = dkhr
          betal = betar
          dbetal = dbetar
          alphal = alphar
          dalphal = dalphar
          mal = mar
          dmal = dmar
          mql = mqr
          dmql = dmqr
        end do
        if(max(max_kh_err,  max_beta_err, max_alpha_err, 
     a                   max_ma_err, max_mq_err).gt.1.e-3) then

          write(stdout,50)
          write(stdout,52) max_kh_err,  max_beta_err, max_alpha_err, 
     a                   max_ma_err, max_mq_err 
        else
          write(stdout,54) 
        endif

      end select


c     Reset the last lookup position to the first level.  Needed
c     for later possible adjustment of conveyance
      itab(ip+3) = ip + XTIOFF

      return
      end

C
C
C
      subroutine   xsecfit(STDOUT, verbose,
     M              NDEP, XST,
     o              khflag, alphaflag, betaflag, maflag, mqflag)
 
C     + + + PURPOSE + + +
c     Compute some fits to the values in a cross-section function table.

      IMPLICIT NONE
C     + + + PARAMETERS + + +
      INCLUDE 'arsize.prm'
 
C     + + + DUMMY ARGUMENTS + + +
      INTEGER  NDEP, STDOUT, verbose
      REAL  XST(PMXPNT,PMXELM)
      CHARACTER 
     a  khflag(pmxpnt)*1, alphaflag(pmxpnt)*1, betaflag(pmxpnt)*1,
     b     maflag(pmxpnt)*1, mqflag(pmxpnt)*1
 
C     + + +DUMMY ARGUMENT DEFINITIONS + + +
C     STDOUT - Fortran unit number for user output and messages
C     NDEP   - Number of depth values
C     XST    - Storage matrix for various elements of cross section
 
C     + + + COMMON BLOCKS + + +
c      INCLUDE 'ftable.cmn'
c      INCLUDE 'grvcom.cmn'
c      INCLUDE 'xtadd.cmn'
 
 
C     + + + LOCAL VARIABLES + + +
      INTEGER  I,  N

      integer lcode, rcode,  nadj

      real*8  lval, rval, khl, khr, yl, yr, p

      real*8   kh(pmxpnt),
     a     dkhdy(pmxpnt),alpha(pmxpnt), dalphady(pmxpnt), 
     b     beta(pmxpnt), dbetady(pmxpnt),  ma(pmxpnt), dmady(pmxpnt), 
     c     mq(pmxpnt), dmqdy(pmxpnt)

      real*8 y(pmxpnt)

      CHARACTER  make_monotone*4
 
 
C     + + + EXTERNAL FUNCTIONS + + +
C     + + + EXTERNAL NAMES + + +
      external spline, vrlim
c     *********************formats**************************************
70    format(/,' Results for upgrade:')
72    format('         y        kh     dkh/dy     alpha  dalpha/dy',
     a '      beta   dbeta/dy        ma     dma/dy',
     b '        mq     dmq/dy')
74    format(f10.3,
     *  1pe10.4e1, 1pe10.4e1,a1, 
     a  0pf10.6,f10.5,a1,
     b  f10.6,f10.5,a1,
     c  f10.6,f10.5,a1,
     d  f10.6,f10.5,a1)
75    format(' Power for sqrt of conveyance near zero=',f10.4)
C***********************************************************************

      make_monotone = 'YES'
      alphaflag = ' '
      betaflag = ' '
      maflag = ' '
      mqflag = ' '
 
C     FILL IN THE VELOCITY DISTRIBUTION COEFFICIENTS AT DEPTH 0.0
C     AND CRITICAL FLOW AT ZERO DEPTH.
      XST(1,6) = XST(1+1,6)
      XST(1,7) = XST(1+1,7)
      XST(1,13) = 0.0

C     do for ma and mq also
      xst(1,14) = xst(2,14)
      xst(1,15) = xst(2,15)
 
C     Added May 22, 1998: definition of XSV(*) contents
c     Extended 13 March 2003

C     Offset    Value
C     1         Maximum depth-y
C     2         Top width
C     3         Area
C     4         First moment of area about water surface
C     5         Square root of conveyance- kh
C     6         Beta
C     7         Alpha
C     8         dBeta/dy
C     9         dAlpha/dy
C     10        Critical flow from momentum
C     11        Critical flow from energy
C     12        Critcal flow assuming Alpha=beta=1
C     13        Critical flow that is selected by user: 10, 11, or 12
C     14        MA- correction of volumes for sinuousity
C     15        MQ- correction of momentum for sinuosity
C     16        Total wetted perimeter- added May 22, 1998
C     17        Average Manning's n value for the cross section
c     18        dkh/dy computed by cubic-spline fit
c     19        dalpha/dy computed by cubic-spline fit
c     20        dbeta/dy computed by cubic-spline fit
c     21        dma/dy computed by cubic-spline fit
c     22        dmq/dy computed by cubic-spline fit


c     Transfer the data to the working variables. 

      n = ndep
      do i=1,n
        y(i) = dble(xst(i,1))
c        t(i) = dble(xst(i,2))
        kh(i) = dble(xst(i,5))
        alpha(i) = dble(xst(i,7))
        beta(i) = dble(xst(i,6))
        ma(i) = dble(xst(i,14))
        mq(i) = dble(xst(i,15))
      end do

c     compute power of the square root of conveyance near zero. 
      yl = y(2)
      yr = y(3)
      khl = kh(2)
      khr = kh(3)
      p = log(khr/khl)/log(yr/yl)
c      write(stdout,75) p

 

c     The code values for vlchpp which calls spline are:
c        code       Meaning of val
c       -------     --------------------------
c          1         first derivative at the given end
c          2         second derivative at the given end
c          3          0 < val  < 1
c   In terms of the "beam" theory behind the idea of a spline:
c   code 1 provides a cantilever support at the end.  That is,
c   the beam has a fixed slope there.  Code 2 is for a simple
c   support, the beam can rotate there as required.  The third
c   case for the left end places a simple support at location

c      xa  = (x(1) - val*x(2))/(1 - val)

c     and requiring that the entire curve from xa to x(2) be a 
c     cubic.  A typical value of val is 0.5.

c     try sqrt of conveyance.  If power near zero is 1.0 or greater, 
c     impose zero slope at zero depth.  Otherwise use the third option.
c     If the power is less than 1.0, then the derivative at zero depth is
c     infinite but we cannot impose that!  

      if(p.ge.1.d0) then
        lcode = 1
        lval = 0.0d0
      else
        lcode = 3
        lval = 0.5d0
      endif

      rcode = 3
      rval = 0.5d0

c      call  vlchpp
c     i            (stdout, n, y, kh, lcode, lval, rcode, rval,
c     o                dkhdy, khflag)

      call  spline
     i            (stdout, y, kh, n, lcode, lval, rcode, rval,
     o               dkhdy )
      call vrlim
     i          (n, y, kh,
     m           dkhdy,
     o           nadj, khflag)


c     try the rest 

      lcode = 3
      lval = 0.5d0

      rcode = 3
      rval = 0.5d0

      call  spline
     i            (stdout, y, alpha, n, lcode, lval, rcode, rval,
     o                dalphady)
      if(make_monotone.eq.'YES') then
        call vrlim
     i            (n, y, alpha,
     m             dalphady,
     o             nadj, alphaflag)
      endif

      call  spline
     i            (stdout, y, beta, n, lcode, lval, rcode, rval,
     o                dbetady)
      if(make_monotone.eq.'YES') then
      call vrlim
     i          (n, y, beta,
     m           dbetady,
     o           nadj, betaflag)
      endif
      call  spline
     i            (stdout, y, ma, n, lcode, lval, rcode, rval,
     o                dmady)
      if(make_monotone.eq.'YES') then
      call vrlim
     i          (n, y, ma,
     m           dmady,
     o           nadj, maflag)
      endif
      call  spline
     i            (stdout, y, mq, n, lcode, lval, rcode, rval,
     o                dmqdy)
      if(make_monotone.eq.'YES') then
      call vrlim
     i          (n, y, mq,
     m           dmqdy,
     o           nadj, mqflag)
      endif


      if(verbose.eq.1) then
        write(stdout,70)
        write(stdout,72) 
        do i=1,n
          write(stdout,74) y(i), kh(i), dkhdy(i), khflag(i), 
     *      alpha(i), dalphady(i), alphaflag(i), 
     a      beta(i), dbetady(i), betaflag(i), ma(i), dmady(i), 
     b      maflag(i), mq(i), dmqdy(i), mqflag(i)
        end do

      endif
c     Put the values in the standard structure
      do i=1,n
        xst(i,18) = dkhdy(i)
        xst(i,19) = dalphady(i)
        xst(i,20) = dbetady(i)
        xst(i,21) = dmady(i)
        xst(i,22) = dmqdy(i)
      end do

      return
      end
