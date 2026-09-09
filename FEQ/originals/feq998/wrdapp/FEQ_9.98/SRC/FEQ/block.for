C
C
C
      BLOCKDATA   SPOUT_INIT
 
C     + + + PURPOSE + + +
C     Initialize the list of names for special output item
C     names.
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'arsize.prm'
      INCLUDE 'spout.cmn'
 
C     + + + DATA INITIALIZATIONS + + +
      DATA SPOUT_ITEM_NAME/'V','MCV','FPV','A','MCA','FPA',
     A                     'MCQ', 'FPQ'/
      DATA SPOUT_ITEM_LABEL/'Velocity','MnChnVlcty','FdPlnVlcty',
     A                      'Area','MnChnArea','FdPlnArea',
     B                      'MnChnFlow','FdPlnFlow'/
      DATA SPOUT_ITEM_VALUE/MEAN_VELOCITY, MAIN_CHANNEL_VELOCITY,
     A                      FLOOD_PLAIN_VELOCITY, TOTAL_AREA,
     B                      MAIN_CHANNEL_AREA, FLOOD_PLAIN_AREA,
     C                      MAIN_CHANNEL_FLOW, FLOOD_PLAIN_FLOW/
      DATA EXTRA_BUFFER/FILL_FACTOR*'        '/
C***********************************************************************
      END
C
C
C
      BLOCKDATA   XOFFIN
 
C     + + + PURPOSE + + +
C     Initialize the offset list for cross sections
 
C     + + + COMMON BLOCKS + + +
      INCLUDE 'offcom.cmn'
 
C     + + + DATA INITIALIZATIONS + + +
      DATA OFFVEC/6,10*0,8,7*0,5, 6, 8, 7, 8, 10/
C***********************************************************************
      END
