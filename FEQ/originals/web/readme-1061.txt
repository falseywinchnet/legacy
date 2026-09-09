README                                                         Mar 31, 2009

                                   FEQ
                    Full Equations Flow Routing Model

                              FEQ - Version: 10.61
                           FEQUTL - Version: 5.80


Instructions for installation, execution, and testing are provided
below.  After installation, see the file doc\feq.txt in the FEQ
installation directory for summary information on FEQ, including
documentation references.  For assistance, enhancement requests, or to
report bugs, contact the USGS Illinois Water Science Center by sending 
e-mail to alishii@usgs.gov.

For all versions of Microsoft Operating Systems, this DOS version of 
FEQ must be run using an MS-DOS Command Prompt window.


                            TABLE OF CONTENTS

                         A. SYSTEM REQUIREMENTS
                         B. DISTRIBUTION FILES
                         C. INSTALLING
                             o Installing FEQ
                             o FEQ directory structure
                             o Making FEQ easily accessible
                         D. COMPILING
                         E. RUNNING THE SOFTWARE
                             o Running FEQ
                             o Running FEQUTL
                             o Running TABDIR
                         F. TESTING


A. SYSTEM REQUIREMENTS

For installation of FEQ, approximately 30 megabytes of free disk space 
are needed.

To run the FEQ executables, the following are necessary:

  - 586 or greater processor


B. DISTRIBUTION FILES

FEQ and FEQUTL are distributed in a compressed (zip format)  
distribution file, named feq1061.zip.  The distribution file contains 
the software, test data sets, and information files.  The 
executables were compiled using Lahey/Fujitsu Fortran 95 Version 5.70f.


C. INSTALLING

Installing FEQ
--------------

These instructions assume that you are installing the software in the
directory c:\wrdapp, which we strongly recommend.  You may use other
directories or disk drives, but you must change each occurrence of "c:"
and "\wrdapp" in all of the following instructions to the alternate
location that you choose.

To install FEQ from the zip file, extract the files with the 
"Use folder names" box checked.  The directory structure shown below 
will be located to the c:\wrdapp directory unless you use a different 
location.

FEQ directory structure
-----------------------

The following directory structure will be created within the directory
c:\wrdapp (the contents of each directory are shown to the right):

      feq_10.61              ; copy of this readme file
       `----bin              ; compiled executables
             `----convert_tsf; compiled executables
                   `---lf90  ; TSF utilities compiled using Lahey Fortran LF90
                   `---lf95  ; TSF utilities compiled using Lahey Fortran LF95
       `----doc              ; documentation files (see file "contents")
       `----src              ; makefiles and source code
             `----feq        ; FEQ source code
                   `---single; FEQ single precision code
                   `---double; FEQ double precision code
                   `---make  ; FEQ make file (Lahey Fortran LF95)
             `----fequtl     ; FEQUTL source code 
                   `---make  ; FEQUTL make file (Lahey Fortran LF95)
             `----share      ; shared source code for all programs
             `----tabdir     ; source code for TABDIR utility
             `----tsfutl     ; source code for TSFUTL utility
                   `---make  ; TSFUTL make file
             `----updateptsf ; source code for UPDATEPTSF utility
                   `---make  ; UPDATEPTSF make file
             `----svn_include; shared source code for software version control
             `----svn_report ; shared source code for software version control         
       `----test             ; batch files to run verification tests
       `----data             ; data sets used in verification tests

Notes:

It is recommended that no user files be kept in the feq_10.61
directory structure.  If you do plan to put files in the feq_10.61
directory structure, do so only by creating subdirectories of 
feq_10.61.


Making FEQ easily accessible
----------------------------

To make the executables accessible from any directory, without needing to
type the full pathname of the software's location, the feq_10.61\bin
directory must be included in the PATH environment variable.

On Windows 2000 and XP systems, from the Start menu, select Settings and 
then Control Panel.  Double-click System, select the Advanced tab, and click 
Environment Variables. Click Path in the System variables, click Edit, 
append ";c:\wrdapp\feq_10.61\bin" in the Variable Value field.  Click OK 
and then click OK on the Environment Variables form.  Initiate and use 
a new MS-DOS Command Prompt window after making this change.


D. COMPILING

The source code is provided in the feq1061.zip distribution file so 
that users can generate the executables themselves.  No support can 
be provided for users generating their own versions of the software.  
In general, the requirements are a Fortran compiler and a minimal 
level of knowledge of the compiler and the DOS operating system.  
As provided, the makefile and source code for FEQ and FEQUTL are 
optimized for use on a personal computer using the Lahey/Fujitsu Fortran 
95 compiler.

Note that use of the Hydrologic Engineering Center's Data Storage System
(HEC-DSS) files is not implemented in the pre-compiled versions of the
software.  See the instructions in feq_10.61\src\feq\make to compile
the software to make use of the HEC-DSS library.

To generate a new FEQ executable, do the following:

   1. Change directory to the source directory:
         cd \wrdapp\feq_10.61\src\feq\make\double

   2. Run compile.bat to initiate compilation of the source code:
     
         compile.bat 

      The compiled program will be placed in the make directory.

To generate a new FEQUTL executable, do the following:

   1. Change directory to the source directory:
         cd \wrdapp\feq_10.61\src\fequtl\make

   2. Run compile.bat to initiate compilation of the source code:
     
         compile.bat 

      The compiled program will be placed in the make directory.
  

E. RUNNING THE SOFTWARE

The executables have been compiled using the Lahey/Fujitsu Fortran 95 compiler 
version 5.7f.  After the software is properly installed in a directory that is 
included in your PATH, the programs are initiated as described below.

Running FEQ
-----------

FEQ is initiated using the command:

  feq infile_name outfile_name

In addition to the output file, a file named in the input file will be
produced.  It is recommended that a consistent suffix such as wsq or spc
be used for identification of this file.  This file contains the final
elevation and flow results for each time step at nodes selected in the
special output block in the input.


Running FEQUTL
--------------

FEQUTL is initiated using the command:

  fequtl infile_name outfile_name tabfile_name


Running TABDIR
--------------

TABDIR is a utility program that creates a directory of function tables
for an existing FEQ model.  More details on the input file specification
can be found in doc\tabdir.txt.

TABDIR is initiated using the command:

  tabdir infile_name outfile_name


Running UPDATEPTSF
------------------

UPDATEPTSF is a utility program that converts a Point Time Series File
(PTSF) from the comiler-dependent sequential unformatted style to the
direct unformatted style, which is compatible with this version of FEQ
(LF95, post-version 10.17).  Use the executable version that is compatible 
with the compiled FEQ executable that created the PTSF (LF90 or LF95),  
sequential unformatted style.  Create the input/output specification 
file by listing the names f the file to be converted and the output file
in single quotes (one pair per lin, no extra lines) as:
'input_filename' 'output_filename'
'input_filename2' 'output_filename2'

UPDATEPTSF is initiated using the command:

  updateptsf

Respond to the prompt with the input/output specification file name.  
Further detail is available in the file doc\updateptsf.txt.


Running TSFUTL
--------------

TSFUTL is a utility program that converts a Diffuse Time Series File 
(DTSF) from the compiler-dependent sequential unformatted style to the
direct unformatted style, which is compatible with this version of FEQ 
(LF95, post-version 10.17).  Use the executable version that is compatible 
with the compiled FEQ executable that created the DTSF (LF90 or LF95),  
sequential unformatted style.

TSFUTL is initiated using the command:

  tsfutl infile_name outfile_name

The input file is constructed by modifying the UPDATE command at the end 
of the example input file in doc\tsfutl.txt to include the names of the 
DTSF input and new DTSF output and saving it under the the user-selected 
input file name.  


F. TESTING

Test data sets are provided to verify that the program is correctly
installed and running on the system.  The tests may also be looked at as
examples of how to use the program.  Tests are run in the feq_10.61\test
directory.  The directory feq_10.61\data contains the FEQ and FEQUTL input
data and expected results for each test.  

To test the installation, change to the feq_10.61\test directory and type
the command:

     test [m [n]]  

where:
     m = the number of the first test to perform, default=1
     n = the number of the last test to perform, default=6

For example:

command                         what happens
------------------      ------------------------------------
test                    runs all of the tests
test n                  runs test 'n' through the last test
test n m                runs test 'n' through 'm'

After the tests are completed, the results are compared to the expected
results.  If all goes well, the only differences will be due to different
processing times.  To clean up after the tests, type the command:

     clean

The tests are described in the table below.  Test is the test number, program
is the program used to run the test, and the usage column indicates how a file
is used, with i for input and o for output.

test  program  description of test and files      file name & usage
----  -------  ---------------------------------  -----------------
  1   feq      Unsteady flow, single branch system

               input data                         feqex1       i
               feq printed output                 feqex1.out   o
               flow and elevations results        feqex1.wsq   o

  2   feq      Unsteady flow, three branch system

               input data                         feqex2       i
               feq printed output                 feqex2.out   o
               flow and elevations results        feqex2.wsq   o

  3   feq      Unsteady flow, three branch system
               with level-pool reservoir

               input data                         feqex3       i
               feq printed output                 feqex3.out   o
               flow and elevations results        feqex3.wsq   o

  4   feq      Unsteady flow, three branch system
               with off-line reservoir

               input data                         feqex4       i
               feq printed output                 feqex4.out   o
               flow and elevations results        feqex4.wsq   o

  5   fequtl   Example illustrating many FEQUTL features

               input data                         utlexm.in    i
               function table                     type5.tab    i
               HEC2 formatted input               model01.inp  i
               output table                       utlexm.tab   o
               fequtl printed output              utlexm.out   o
               FEQX format cross sections         utlexm.chx   o

  6   fequtl   Unsteady flow, three branch system
               with off-line reservoir

               input data                         culvert.in   i
               function table data                type5.tab    i
               function table data                weirtabs     i
               fequtl printed output              culvert.out  o
               output table                       culvert.tab  o

