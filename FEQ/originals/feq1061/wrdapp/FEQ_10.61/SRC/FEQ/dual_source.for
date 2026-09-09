c     File containing the code for handling the dual-source input
c     block. 
      subroutine dual_source 
     i                (in, stdout,
     m                 eflag)

c     Process dual-source time-series block.  User defines two or more 
c     time series to be concatenated or merged to create a single time 
c     series for use in a forced boundary condition.  

      implicit none
      integer in, stdout, eflag

      include 'arsize.prm'
      include 'home.cmn'
      include 'ftable.cmn'

c     Called units
      integer get_unit, mjd
      external get_unit, mjd
      CHARACTER JTTOCT*14


c     Local
      INTEGER  CHRVAL, INTVAL,REAVAL, DPRVAL
      PARAMETER(INTVAL=1, REAVAL=2, DPRVAL=3,CHRVAL=4)

      integer MAX_KNT
      PARAMETER (MAX_KNT=20)

      INTEGER PERIOD, ASTERISK, PLUS_OR_MINUS, COMMA, SLASH, SPACE,
     A        COLON, EQUAL, UNDERLINE, BACKSLASH, QUOTE, DIGIT, A_TO_C,
     B        D, E, F_TO_Z, VERTICAL_BAR, DQUOTE, MISC, SEMICOLON

      PARAMETER (PERIOD=1, ASTERISK=2, PLUS_OR_MINUS=3, COMMA=4,
     A           SLASH=5, SPACE=6, COLON=7, EQUAL=8, UNDERLINE=9,
     B           BACKSLASH=10, QUOTE=11, DIGIT=12, A_TO_C=13, D=14,
     C           E=15, F_TO_Z=16, VERTICAL_BAR=17, DQUOTE=18,
     D           MISC=19, SEMICOLON=20)

      
      integer (kind=2) :: file_structure_version
      integer i, it, tran_tab_adrs, stdfinal, record_length,
     a        ioflag, irec,item_knt, tran_start_yr, tran_start_mn, 
     b        tran_start_dy, tran_end_yr, tran_end_mn, tran_end_dy,
     b        is
      integer item_length(max_knt), item_type(max_knt),
     a        term_class(max_knt), source_adrs(2),
     b        start_adrs(2), end_adrs(2)

      real dummy, value

      real*8 tran_start_hr, tran_end_hr, start_jtime(2), end_jtime(2), 
     a   tran_start_jtime, tran_end_jtime, jtime, jtime_break

      character :: what*1, unused*1
      character line*196,tran_tabid*16, final_file*256,
     a       blk_name*128,  ITEMS(MAX_KNT)*128,  source(2)*128,
     b       source_type(2)*5, char16*16, tfile*256

c     *************************Formats*********************************
50    format(/,' *WRN:443* Equal sign missing in line displayed.',
     a   '  Terminating character found is used.')
52    FORMAT(/,' *ERR:132* Cannot open file named:',/,5X,A,/,5X,
     A ' Check path for file name.')

54    FORMAT(' Writing header to dual_source file:',A)
56    format(/,' *ERR:133* Value for hour:',f12.2,' is out of range.')
58    format(/,' *ERR:203* Expected to find FILE, TABLE, HOME, or ',
     a   'TRAN_TAB but found:',/,
     a  a, /,5x,' instead.')
60    format(/,' *ERR:204* DEFINE block end-name: ',a,/,
     a  11x,'does not match start name: ',a)
62    format(/,' *ERR:434 Apparent end of dual-source block but DUAL',
     a     ' SOURCE not found following END.')
64    format(/,' *ERR:435* Expected: ',a,' but found: ',a,' instead.')
66    format(/,' *ERR:436* TRAN_START is already known as: ',
     a          i5,'/',i2,'/',i3,':',f14.4)
68    format(/,' *ERR:437* TRAN_END  is already known as: ',
     a          i5,'/',i2,'/',i3,':',f14.4)
70    format(/,' *ERR:438* Number of sources > 2.')
72    format(/,' *ERR:439* Transistion table not found.')
74    format(/,' *ERR:440*  Transition-start jtime=',f18.7,
     a             ' > first source end jtime=',f18.7)
c***********************************************************************
c     Set some standard values
      file_structure_version = 1
      what = 'Q'
      unused = ' '
      record_length = 12
c     Clear the start and end year. If > 0 means user has supplied 
c     a value.  
      tran_start_yr = 0 
      tran_end_yr = 0

c     Clear the local home name
      CALL CLEAR_HOME()
      tran_tabid = ' '

c     Read the next line from the input.  If it does not contain what
c     we expect, backspace the input file and return. 

      CALL inline
     I          (IN, STDOUT,
     O           LINE)
      if(line(1:4).ne.'DUAL') then
        backspace(in)
        return
      endif

      write(stdout,'(/,a)') line


100   continue
        CALL inline
     I            (IN, STDOUT,
     O             LINE)
        it = len_trim(line)
        write(stdout,'(a)') line(1:it)


        call get_items(stdout, line, max_knt,
     o                   item_knt, items, item_length, 
     o                   item_type, term_class, eflag)
c        write(stdout,5599)
c        do i=1,item_knt
c          write(stdout, 5600) items(i), item_length(i), item_type(i), 
c     a                        term_class(i)
c        end do
c5599  format('Item',35x,'Length  ','Type    ','Term Cls')
c5600  format(a40,i8,i8,i8)
        if(items(1)(1:4) == 'HOME'.or. items(1)(1:4) == 'home') then
c         Set the local home name 
          if(term_class(1) /= EQUAL) then
            write(stdout,50)
          endif
          home = items(2)
        elseif(items(1)(1:6) == 'DEFINE') then
c         Start of a define block. 
c         Get the file name

          final_file= items(2)
          blk_name = final_file
          call MAYBE_ADD_HOME(
     M                        final_file)
          call os_file_style(
     m                       final_file)
c         Open the file for writing           
          stdfinal = GET_UNIT (STDOUT)

          OPEN(stdfinal, FILE=final_file, FORM='UNFORMATTED', 
     a         STATUS='UNKNOWN', access='direct', recl=record_length,
     b         IOSTAT=IOFLAG)
          IF(IOFLAG.NE.0) THEN
            WRITE(STDOUT,52) final_file
            STOP 'Abnormal stop: errors found.'
          ENDIF

          irec = 1
          write(stdfinal,rec=irec) record_length, 
     a       file_structure_version, what, unused,
     b       DPTSF_REC_AT_FRST_TS_PNT 
c          write(stdout,*) 'stdfinal=',stdfinal, 
c     a      'record len=',record_length, 
c     b      ' first data record#=',
c     c      DPTSF_REC_AT_FRST_TS_PNT

c         Point to the next open record for writing time-series data.
          irec = irec + 1
c         Fill unused records with blanks
          do i= irec, DPTSF_REC_AT_FRST_TS_PNT - 1
            write(stdfinal, rec=i) '            '
          end do

c         Update pointer to the record for the first time-series value
          irec = DPTSF_REC_AT_FRST_TS_PNT

c         Tell the user about the successful open. 
          WRITE(STDOUT,54) final_file


c         Clear the source pointer
          is = 0
200       continue

c           Now get the next line in the current define block.
            CALL inline
     I                (IN, STDOUT,
     O                 LINE)
            it = len_trim(line)
            write(stdout,'(a)') line(1:it)


            call get_items(stdout, line, max_knt,
     o                      item_knt, items, item_length, 
     o                      item_type, term_class, eflag)
c            write(stdout,5599)
c            do i=1,item_knt
c              write(stdout, 5600) items(i), item_length(i),item_type(i),
c     a                        term_class(i)
c            end do
            
            if(items(1) == 'FILE') then
              is = is + 1
              if(is > 2) then
                write(stdout,70) 
              endif
c             Get the file name. 
              if(term_class(1) /= EQUAL) then
                write(stdout,50)
              endif
              source(is) = items(2)
              source_type(is) = 'FILE'
              source_adrs(is) = get_unit(stdout)
              tfile = source(is)
              call MAYBE_ADD_HOME(
     M                            tfile)
              call os_file_style(
     m                            tfile)

c             Process the file name here so that home can be changed for each file
c             if required. 
              OPEN(source_adrs(is), FILE=tfile, FORM='UNFORMATTED', 
     a             STATUS='UNKNOWN', access='direct', 
     b             recl=record_length, IOSTAT=IOFLAG)
              IF(IOFLAG.NE.0) THEN
                WRITE(STDOUT,52) tfile
                STOP 'Abnormal stop: errors found.'
              ENDIF
c             Get the starting and ending values for this file
              start_adrs(is) =  DPTSF_REC_AT_FRST_TS_PNT
              read(source_adrs(is), 
     a              rec=DPTSF_REC_AT_FRST_TS_PNT) start_jtime(is), dummy
              read(source_adrs(is), rec=DPTSF_REC_AT_FRST_TS_PNT-1) 
     a                         end_jtime(is), end_adrs(is)

              if(item_knt > 2) then                                     
c               More info follows the source name                         
                if(items(3) == 'TRAN_START') then 
                  if(tran_start_yr > 0) then
                    write(stdout,66) tran_start_yr, tran_start_mn,
     a                               tran_start_dy, tran_start_hr  
                    STOP 'Abnormal stop: errors found.' 
                  endif              
                  if(term_class(3) /= EQUAL) then                       
                    write(stdout,50)                                    
                  endif                                                 
                  if(eflag == 0) then                                   
                    read(items(4),'(i4)') tran_start_yr                 
                    read(items(5),'(i2)') tran_start_mn                 
                    read(items(6),'(i2)') tran_start_dy                 
                    read(items(7),'(f15.0)') tran_start_hr              
                    eflag = 0                                           
                    call  chkdat                                        
     i                         (stdout, tran_start_yr,                  
     m                          tran_start_mn, tran_start_dy,           
     o                          eflag)                                  
                    if(tran_start_hr < 0.d0 .or. 
     a                 tran_start_hr > 24.d0) then                
                      write(stdout,56) tran_start_hr                    
                      eflag = 1                                         
                    endif                                               
                    if(eflag /= 0) then                                 
                      STOP 'Abnormal stop: errors found.'               
                    endif                                               
                    tran_start_jtime = DBLE(MJD(tran_start_yr,
     a                      tran_start_mn, tran_start_dy)) + 
     b                                        tran_start_hr/24.D0         
                                                                        
                  else                                                  
                    STOP 'Abnormal stop: errors found.'                 
                  endif                                                 
                elseif(items(3) == 'TRAN_END') then 
                  if(tran_end_yr > 0) then
                    write(stdout,68) tran_end_yr, tran_end_mn,
     a                               tran_end_dy, tran_end_hr  
                    STOP 'Abnormal stop: errors found.' 
                  endif              
                  if(term_class(3) /= EQUAL) then                       
                    write(stdout,50)                                    
                  endif                                                 
                  if(eflag == 0) then                                   
                    read(items(4),'(i4)') tran_end_yr                   
                    read(items(5),'(i2)') tran_end_mn                   
                    read(items(6),'(i2)') tran_end_dy                   
                    read(items(7),'(f15.0)') tran_end_hr                
                    eflag = 0                                           
                    call  chkdat                                        
     i                         (stdout, tran_end_yr,                    
     m                          tran_end_mn, tran_end_dy,               
     o                          eflag)                                  
                    if(tran_end_hr < 0.d0 .or. 
     a                 tran_end_hr > 24.d0) then                
                      write(stdout,56) tran_end_hr                      
                      eflag = 1                                         
                    endif                                               
                    if(eflag /= 0) then                                 
                      STOP 'Abnormal stop: errors found.'               
                    endif                                               
                    tran_end_jtime = DBLE(MJD(tran_end_yr,
     a                      tran_end_mn, tran_end_dy)) + 
     b                                        tran_end_hr/24.D0         
                                                                        
                  else                                                  
                    STOP 'Abnormal stop: errors found.'                 
                  endif                                                 
                else                                                    
                                                   
                  write(stdout, 64) 'TRAN_START or TRAN_END',                         
     a               items(3)(1:len_trim(items(3)))                     
                     STOP 'Abnormal stop: errors found.'                 
                endif                                                   
                                                                        
              endif                                                     


            elseif(items(1) == 'TABLE') then
c             Get the table name  
              is = is + 1   
              if(is > 2) then
                write(stdout,70) 
              endif
              if(term_class(1) /= EQUAL) then
                write(stdout,50)
              endif
              source(is) = items(2)
              source_type(is) = 'TABLE'
c             find the address for the time-series table 
              char16 = source(is) 
              call FIND_INTERNAL_TAB_NUMBER
     I                                  (char16,
     O                                   source_adrs(is))

              if(source_adrs(is).gt.0) then
                call CHKTAB
     I                     (7, stdout, ftpnt, MFTNUM,
     M                     source_adrs(is),
     O                     eflag)
              else
                write(stdout,*) ' Time-series table not found.'
                stop 'Abnormal stop.  Missing time-series table.'
              endif
              if(item_knt > 2) then                                     
c               More info follows the source name                         
                if(items(3) == 'TRAN_START') then 
                  if(tran_start_yr > 0) then
                    write(stdout,66) tran_start_yr, tran_start_mn,
     a                               tran_start_dy, tran_start_hr  
                    STOP 'Abnormal stop: errors found.' 
                  endif              
                  if(term_class(3) /= EQUAL) then                       
                    write(stdout,50)                                    
                  endif                                                 
                  if(eflag == 0) then                                   
                    read(items(4),'(i4)') tran_start_yr                 
                    read(items(5),'(i2)') tran_start_mn                 
                    read(items(6),'(i2)') tran_start_dy                 
                    read(items(7),'(f15.0)') tran_start_hr              
                    eflag = 0                                           
                    call  chkdat                                        
     i                         (stdout, tran_start_yr,                  
     m                          tran_start_mn, tran_start_dy,           
     o                          eflag)                                  
                    if(tran_start_hr < 0.d0 .or. 
     a                 tran_start_hr > 24.d0) then                
                      write(stdout,56) tran_start_hr                    
                      eflag = 1                                         
                    endif                                               
                    if(eflag /= 0) then                                 
                      STOP 'Abnormal stop: errors found.'               
                    endif                                               
                    tran_start_jtime = DBLE(MJD(tran_start_yr,
     a                      tran_start_mn, tran_start_dy)) + 
     b                                        tran_start_hr/24.D0         
                                                                        
                  else                                                  
                    STOP 'Abnormal stop: errors found.'                 
                  endif    
c                 Get starting and ending                                              
                elseif(items(3) == 'TRAN_END') then 
                  if(tran_end_yr > 0) then
                    write(stdout,68) tran_end_yr, tran_end_mn,
     a                               tran_end_dy, tran_end_hr  
                    STOP 'Abnormal stop: errors found.' 
                  endif              
                  if(term_class(3) /= EQUAL) then                       
                    write(stdout,50)                                    
                  endif                                                 
                  if(eflag == 0) then                                   
                    read(items(4),'(i4)') tran_end_yr                   
                    read(items(5),'(i2)') tran_end_mn                   
                    read(items(6),'(i2)') tran_end_dy                   
                    read(items(7),'(f15.0)') tran_end_hr                
                    eflag = 0                                           
                    call  chkdat                                        
     i                         (stdout, tran_end_yr,                    
     m                          tran_end_mn, tran_end_dy,             
     o                          eflag)                                  
                    if(tran_end_hr < 0.d0 .or. 
     a                 tran_end_hr > 24.d0) then                
                      write(stdout,56) tran_end_hr                      
                      eflag = 1                                         
                    endif                                               
                    if(eflag /= 0) then                                 
                      STOP 'Abnormal stop: errors found.'               
                    endif                                               
                    tran_end_jtime = DBLE(MJD(tran_end_yr,
     a                      tran_end_mn, tran_end_dy)) + 
     b                                        tran_end_hr/24.D0         
                                                                        
                  else                                                  
                    STOP 'Abnormal stop: errors found.'                 
                  endif                                                 
                else                                                    
                                                   
                  write(stdout, 64) 'TRAN_START or TRAN_END',          
     a               items(3)(1:len_trim(items(3)))                     
                endif                                                   
                                                                        
              endif     

c             Get starging and ending info for this table.  
              start_adrs(is) = (source_adrs(is) + OFF234)/2
              start_jtime(is) = dtab(start_adrs(is)) 

              end_adrs(is) = itab(source_adrs(is))
              end_jtime(is) = dtab(end_adrs(is))

            elseif(items(1)(1:10) == 'TRAN_TAB') then
c             process the transition table 
              if(term_class(1) /= EQUAL) then
                write(stdout,50)
               endif
               tran_tabid = items(2)

c              find the address for the transition table          
                call FIND_INTERNAL_TAB_NUMBER
     I                                  (tran_tabid,
     O                                   tran_tab_adrs)

                if(tran_tab_adrs.gt.0) then
                call CHKTAB
     I                     (7, STDOUT, FTPNT, MFTnum,
     M                     tran_tab_adrs,
     O                     EFLAG)
              else
                write(stdout,72) 
                stop 'Abnormal stop: errors found.'
              endif

            elseif(items(1)(1:4) == 'HOME'.or. 
     a             items(1)(1:4) == 'home') then
c              Set the local home name 
               if(term_class(1) /= EQUAL) then
                 write(stdout,50)
               endif
               home = items(2)
            elseif(items(1) == 'END') then
              if( items(2) == blk_name) then
c               We have all basic items in hand.  Create the dual source
c               file

c                write(stdout,5699) final_file, stdfinal
c5699            format(' Final file name=',a,/,
c     b          14x,'Stdfinal=',i5)
c                do i=1,2 
c                  write(stdout,5700) i, 
c     a              source(i), source_type(i), source_adrs(i)
c5700            format( i2,' Source Name='a,/,
c     b              14x,'Type=',a5,/,
c     c               14x,'Address=',i10)
c                  write(stdout,5702) start_adrs(i), end_adrs(i)
c                  write(stdout,5704) start_jtime(i), end_jtime(i)
c5702              format(14x,' start_adrs=',i10,' end_adrs=',i10)
c5704              format(14x,' start_jtime=',f14.4,' end_jtime=',f14.4)
c                enddo
                if(tran_start_yr > 0) then
                  write(stdout,5701)  'Tran_start=',tran_start_yr, 
     a              tran_start_mn, tran_start_dy, tran_start_hr
5701              format(2x,a,i5,'/',i2,'/',i3,':',f14.4)
                endif
                if(tran_end_yr > 0) then
                  write(stdout,5701)  'Tran_end=',tran_end_yr, 
     a              tran_end_mn, tran_end_dy, tran_end_hr
                endif

                if(tran_start_yr == 0) then
c                  tran_end time if given is ignored because the 
c                  start time is not present. 
                   jtime_break = end_jtime(1)  ! We transfer the entire first source.
                else
                  if(tran_end_yr == 0) then
c                   tran_start time was given but no tran_end time
                    if(tran_start_jtime > end_jtime(1)) then
                      write(stdout,74) tran_start_jtime, end_jtime(1)
                      stop 'Abnormal stop: errors found.'
                    endif

                    jtime_break = tran_start_jtime  ! We transfer the first source up to and includeing tran_end_time
                  else
                    write(stdout,*) 
     a                   'Transition region not yet implemented'
                    stop 'Unimplemented option requested'
                  endif
                endif  

                if(source_type(1) == 'FILE') then
                  do i=start_adrs(1), end_adrs(1)
                    read(source_adrs(1), rec=i) jtime, value
                    if(jtime <= jtime_break) then
                      write(stdfinal, rec=irec) jtime,value
c                write(stdout,'(i10,1x,a,1x,f17.8,f10.2)') 
c     a                       irec,jttoct(jtime), jtime,value
                      irec = irec + 1
                    else
c                      write(stdout,'(a)') ' First source ends here'
                      exit
                    endif
                  enddo
                  call free_unit(stdout, source_adrs(1))
                  if(source_type(2) == 'TABLE') then
                    do i=start_adrs(2), end_adrs(2), 2
                      jtime = dtab(i)
                      value = sngl(dtab(i+1))
                      if(jtime > jtime_break) then
                        write(stdfinal, rec=irec) jtime,value
c                write(stdout,'(i10,1x,a,1x,f17.8,f10.2)') 
c     a                       irec,jttoct(jtime), jtime,value
                        irec = irec + 1
                      endif
                    enddo
                  else
c                   Source type is FILE here
                    do i=start_adrs(2), end_adrs(2), 2
                      read(source_adrs(2), rec=i) jtime, value
                      if(jtime > jtime_break) then
                        write(stdfinal, rec=irec) jtime, value
c                write(stdout,'(i10,1x,a,1x,f17.8,f10.2)') 
c     a                       irec,jttoct(jtime), jtime,value
                        irec = irec + 1
                      endif
                    enddo
                    call free_unit(stdout, source_adrs(2))
                  endif
                else
c                 First source is a ts table.  
                  do i=start_adrs(1), end_adrs(1),2
                    jtime = dtab(i)
                    value = sngl(dtab(i+1))
                    if(jtime <= jtime_break) then
                      write(stdfinal, rec=irec) jtime,value
c                write(stdout,'(i10,1x,a,1x,f17.8,f10.2)') 
c     a                       irec,jttoct(jtime), jtime,value
                      irec = irec + 1
                    else
c                      write(stdout,'(a)') ' First source ends here'
                      exit
                    endif
                  enddo

                  if(source_type(2) == 'TABLE') then
                    do i=start_adrs(2), end_adrs(2), 2
                      jtime = dtab(i)
                      value = sngl(dtab(i+1))
                      if(jtime > jtime_break) then
                        write(stdfinal, rec=irec) jtime,value
c                write(stdout,'(i10,1x,a,1x,f17.8,f10.2)') 
c     a                       irec,jttoct(jtime), jtime,value
                        irec = irec + 1
                      endif
                    enddo
                  else
c                   Source type is FILE here
                    do i=start_adrs(2), end_adrs(2), 2
                      read(source_adrs(2), rec=i) jtime, value
                      if(jtime > jtime_break) then
                        write(stdfinal, rec=irec) jtime,value
c                write(stdout,'(i10,1x,a,1x,f17.8,f10.2)') 
c     a                       irec,jttoct(jtime), jtime,value
                        irec = irec + 1
                      endif
                    enddo
                    call free_unit(stdout, source_adrs(2))
                  endif
                endif
c               write the final record and store the last record
c               inforomation.
                jtime = 0.d0
                value = 0.0
                write(stdfinal, rec=irec) jtime,value
c                write(stdout,'(i10,f17.8,f10.2)') irec, jtime,value
                write(stdfinal, rec=DPTSF_REC_AT_FRST_TS_PNT - 1)
     a               end_jtime(2), end_adrs(2)
                close(stdfinal)
                call free_unit(stdout, stdfinal)
  
              else
                write(stdout,60)  items(2), blk_name
                STOP 'Abnormal stop: errors found.'

              endif

c             Go look for the next define block

              goto 100 
            else
              write(stdout,58) items(1)
              STOP 'Abnormal stop: errors found.'

            endif


c           Go check for the next line of info in the current define block 
            goto 200


        elseif(items(1)(1:3) == 'END') then
          if(items(2) == 'DUAL' .and. items(3) == 'SOURCE') then

            write(stdout,*) ' '
            write(stdout,*) ' Returning from dual_source'
            return

          else
            write(stdout,62)
            STOP 'Abnormal stop: errors found.'
          endif
        endif

        goto 100

      end
