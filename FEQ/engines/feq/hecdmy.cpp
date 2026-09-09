/* hecdmy.f -- translated by f2c (version 20240504).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "common.hpp"
#ifdef __cplusplus
extern "C" {
#endif
#include "f2c.h"

/*     This file contains the subprograms that are specific to */
/*     access to the HECDSS. */
/*     *********** */
/*     *         * */
/*     * HECDSS_INIT */
/*     *         * */
/*     *********** */
/* SOURCE hecdmy.for:9 */
/*<       subroutinehecdss_init(stdout) >*/
/* Subroutine */ int feq_gen_hecdss_init_d_(integer *stdout)
{
/*     Set various values for managing HECDSS */
/* SOURCE hecdmy.for:13 */
/*<       implicitnone >*/
/* SOURCE hecdmy.for:14 */
/*<       integerstdout >*/
/*     INCLUDE 'arsize.prm' */
/*     INCLUDE 'hecdss.cmn' */
/*     INCLUDE 'dssout.cmn' */
/* ********************************************************************** */
/*     STOP 'HECDSS OPTION NOT SUPPORTED IN THIS VERSION OF FEQ' */
/* SOURCE hecdmy.for:22 */
/*<       return >*/
    return 0;
/* SOURCE hecdmy.for:23 */
/*<       end >*/
} /* hecdss_init__ */

/*     *********** */
/*     *         * */
/*     * HECDSS_QUIT */
/*     *         * */
/*     *********** */
/* SOURCE hecdmy.for:30 */
/*<       subroutinehecdss_quit(stdout) >*/
/* Subroutine */ int feq_gen_hecdss_quit_d_(integer *stdout)
{
/*     Shut down any HECDSS files. */
/* SOURCE hecdmy.for:34 */
/*<       implicitnone >*/
/* SOURCE hecdmy.for:35 */
/*<       integerstdout >*/
/* *********************************************************************** */
/* C    STOP 'HECDSS NOT IMPLEMENTED' */
/* SOURCE hecdmy.for:39 */
/*<       return >*/
    return 0;
/* SOURCE hecdmy.for:40 */
/*<       end >*/
} /* hecdss_quit__ */

/*     *********** */
/*     *         * */
/*     * PROCESS_HECDSS_NAME */
/*     *         * */
/*     *********** */
/* SOURCE hecdmy.for:47 */
/*<       subroutineprocess_hecdss_name(stdout,name,index,option,eflag) >*/
/* Subroutine */ int feq_gen_process_hecdss_name_d_(integer *stdout, char *feq_gen_name_d_, 
	integer *index, char *option, integer *eflag, ftnlen name_len, ftnlen 
	option_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

/*     Process a reference to a HECDSS file name. */
/* SOURCE hecdmy.for:52 */
/*<       implicitnone >*/
/* SOURCE hecdmy.for:53 */
/*<       charactername*64,option*6 >*/
/* SOURCE hecdmy.for:55 */
/*<       integereflag,index,stdout >*/
/* SOURCE hecdmy.for:57 */
/*<       stop'HECDSS NOT IMPLEMENTED-1' >*/
    s_stop(const_cast<char*>("HECDSS NOT IMPLEMENTED-1"), (ftnlen)24);
/* SOURCE hecdmy.for:58 */
/*<       end >*/
    return 0;
} /* process_hecdss_name__ */

/*     *********** */
/*     *         * */
/*     * PROCESS_HECDSS_PATH_NAME */
/*     *         * */
/*     *********** */
/* SOURCE hecdmy.for:65 */
/*<       subroutineprocess_hecdss_path_name(stdout,name,time_step,eflag) >*/
/* Subroutine */ int feq_gen_process_hecdss_path_name_d_(integer *stdout, char *feq_gen_name_d_,
	 integer *feq_gen_time_step_d_, integer *eflag, ftnlen name_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

/*     Process a path name. */
/* SOURCE hecdmy.for:70 */
/*<       implicitnone >*/
/* SOURCE hecdmy.for:71 */
/*<       character*80name >*/
/* SOURCE hecdmy.for:73 */
/*<       integereflag,stdout,time_step >*/
/* *********************************************************************** */
/* SOURCE hecdmy.for:76 */
/*<       stop'HECDSS NOT IMPLEMENTED-2' >*/
    s_stop(const_cast<char*>("HECDSS NOT IMPLEMENTED-2"), (ftnlen)24);
/* SOURCE hecdmy.for:77 */
/*<       end >*/
    return 0;
} /* process_hecdss_path_name__ */

/*     *********** */
/*     *         * */
/*     * CHECK_EXIST */
/*     *         * */
/*     *********** */
/* SOURCE hecdmy.for:84 */
/*<       subroutinecheck_exist(dss_index,name,ierr) >*/
/* Subroutine */ int feq_gen_check_exist_d_(integer *feq_gen_dss_index_d_, char *feq_gen_name_d_, 
	integer *ierr, ftnlen name_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

/*     Try checking for the existence of a time-series record */
/*     without a D part defined. */
/* SOURCE hecdmy.for:89 */
/*<       implicitnone >*/
/* SOURCE hecdmy.for:90 */
/*<       integerdss_index,ierr >*/
/* SOURCE hecdmy.for:92 */
/*<       charactername*80 >*/
/* *********************************************************************** */
/* SOURCE hecdmy.for:95 */
/*<       stop'HECDSS NOT IMPLEMENTED-3' >*/
    s_stop(const_cast<char*>("HECDSS NOT IMPLEMENTED-3"), (ftnlen)24);
/* SOURCE hecdmy.for:96 */
/*<       end >*/
    return 0;
} /* check_exist__ */

/*     *********** */
/*     *         * */
/*     * UPDATE_DSSOUT_JTIME */
/*     *         * */
/*     *********** */
/* SOURCE hecdmy.for:103 */
/*<       subroutineupdate_dssout_jtime(jtime,full) >*/
/* Subroutine */ int feq_gen_update_dssout_jtime_d_(doublereal *jtime, integer *full)
{
/*     Add the next FEQ Julian time to the buffer for output going */
/*     to HECDSS data sets.  Set the FULL flag when the last row */
/*     in the buffer is used. */
/* SOURCE hecdmy.for:109 */
/*<       implicitnone >*/
/* SOURCE hecdmy.for:110 */
/*<       integerfull >*/
/* SOURCE hecdmy.for:112 */
/*<       real*8jtime >*/
/* *********************************************************************** */
/*      STOP 'HECDSS NOT IMPLEMENTED-4' */
/* SOURCE hecdmy.for:116 */
/*<       full=0 >*/
    *full = 0;
/* SOURCE hecdmy.for:117 */
/*<       end >*/
    return 0;
} /* update_dssout_jtime__ */

/*     *********** */
/*     *         * */
/*     * UPDATE_DSSOUT_BUFFER */
/*     *         * */
/*     *********** */
/* SOURCE hecdmy.for:124 */
/*<       subroutineupdate_dssout_buffer(column,val) >*/
/* Subroutine */ int feq_gen_update_dssout_buffer_d_(integer *column, real *val)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

/*     Add an output value to the DSS output buffer.  The row index */
/*     is already set in UPDATE_DSSOUT_JTIME. */
/* SOURCE hecdmy.for:129 */
/*<       implicitnone >*/
/* SOURCE hecdmy.for:130 */
/*<       integercolumn >*/
/* SOURCE hecdmy.for:132 */
/*<       realval >*/
/* *********************************************************************** */
/* SOURCE hecdmy.for:136 */
/*<       stop'HECDSS NOT IMPLEMENTED-5' >*/
    s_stop(const_cast<char*>("HECDSS NOT IMPLEMENTED-5"), (ftnlen)24);
/* SOURCE hecdmy.for:137 */
/*<       end >*/
    return 0;
} /* update_dssout_buffer__ */

/*     *********** */
/*     *         * */
/*     * INITIALIZE_DSSOUT_JTIME */
/*     *         * */
/*     *********** */
/* SOURCE hecdmy.for:144 */
/*<       subroutineinitialize_dssout_jtime(jtime) >*/
/* Subroutine */ int feq_gen_initialize_dssout_jtime_d_(doublereal *jtime)
{
/*     Add starting JTIME to zero row in the buffer */
/* SOURCE hecdmy.for:148 */
/*<       implicitnone >*/
/* SOURCE hecdmy.for:149 */
/*<       real*8jtime >*/
/* *********************************************************************** */
/*      STOP 'HECDSS NOT IMPLEMENTED-6' */
/* SOURCE hecdmy.for:153 */
/*<       return >*/
    return 0;
/* SOURCE hecdmy.for:154 */
/*<       end >*/
} /* initialize_dssout_jtime__ */

/*     *********** */
/*     *         * */
/*     * INITIALIZE_DSSOUT_BUFFER */
/*     *         * */
/*     *********** */
/* SOURCE hecdmy.for:161 */
/*<       subroutineinitialize_dssout_buffer(column,val) >*/
/* Subroutine */ int feq_gen_initialize_dssout_buffer_d_(integer *column, real *val)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

/*     Put the run-start values in the zero row of the buffer. */
/* SOURCE hecdmy.for:165 */
/*<       implicitnone >*/
/* SOURCE hecdmy.for:166 */
/*<       integercolumn >*/
/* SOURCE hecdmy.for:168 */
/*<       realval >*/
/* *********************************************************************** */
/* SOURCE hecdmy.for:172 */
/*<       stop'HECDSS NOT IMPLEMENTED-7' >*/
    s_stop(const_cast<char*>("HECDSS NOT IMPLEMENTED-7"), (ftnlen)24);
/* SOURCE hecdmy.for:173 */
/*<       end >*/
    return 0;
} /* initialize_dssout_buffer__ */

/*     *********** */
/*     *         * */
/*     * OUTPUT_DSSOUT_BUFFER */
/*     *         * */
/*     *********** */
/* SOURCE hecdmy.for:180 */
/*<       subroutineoutput_dssout_buffer >*/
/* Subroutine */ int feq_gen_output_dssout_buffer_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

/*     Output the DSS output buffer when it is full and at the end */
/*     of the run. */
/* SOURCE hecdmy.for:185 */
/*<       stop'HECDSS NOT IMPLEMENTED-8' >*/
    s_stop(const_cast<char*>("HECDSS NOT IMPLEMENTED-8"), (ftnlen)24);
/* SOURCE hecdmy.for:186 */
/*<       end >*/
    return 0;
} /* output_dssout_buffer__ */

/*     *********** */
/*     *         * */
/*     * GET_HECDSS_BLOCK  * */
/*     *         * */
/*     *********** */
/* SOURCE hecdmy.for:193 */
/*<        >*/
/* Subroutine */ int feq_gen_get_hecdss_block_d_(integer *stdout, char *namein, 
	integer *feq_gen_dss_file_index_d_, integer *feq_gen_time_step_d_, char *feq_gen_report_mode_d_, 
	doublereal *jtime, integer *nmax, integer *nvalues, doublereal *
	feq_storage_jtimes, real *feq_storage_values, integer *mrjtimes, ftnlen namein_len, ftnlen 
	report_mode_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

/*     Get a consecutive sequence of values from a HECDSS pathname */
/*     attached to an input unit.  The sequence begins on or after */
/*     a FEQ julian time and will return no more than a given */
/*     number of values. */
/* SOURCE hecdmy.for:202 */
/*<       implicitnone >*/
/* SOURCE hecdmy.for:203 */
/*<       characternamein*(*),report_mode*8 >*/
/* SOURCE hecdmy.for:205 */
/*<       integerdss_file_index,time_step,stdout,nmax,nvalues,mrjtimes >*/
/* SOURCE hecdmy.for:208 */
/*<       realvalues(mrjtimes) >*/
/* SOURCE hecdmy.for:210 */
/*<       real*8jtime,jtimes(mrjtimes) >*/
/* *********************************************************************** */
/* SOURCE hecdmy.for:213 */
/*<       stop'HECDSS NOT IMPLEMENTED-9' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> values(feq_storage_values, 1);

    feq::IndexedPointer<doublereal> jtimes(feq_storage_jtimes, 1);

    /* Function Body */
    s_stop(const_cast<char*>("HECDSS NOT IMPLEMENTED-9"), (ftnlen)24);
/* SOURCE hecdmy.for:214 */
/*<       end >*/
    return 0;
} /* get_hecdss_block__ */

/*     *********** */
/*     *         * */
/*     * CHK_HECDSS_RECORD  * */
/*     *         * */
/*     *********** */
/* SOURCE hecdmy.for:221 */
/*<        >*/
/* Subroutine */ int feq_gen_chk_hecdss_record_d_(integer *stdout, char *namein, 
	integer *feq_gen_dss_file_index_d_, integer *feq_gen_time_step_d_, char *feq_gen_report_mode_d_, 
	doublereal *jtime, doublereal *feq_gen_start_time_d_, integer *eflag, ftnlen 
	namein_len, ftnlen report_mode_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

/*     Check to make sure that the DSS time series is of the */
/*     proper reporting mode; and find the start time needed */
/*     so the GET_HECDSS_BLOCK will obtain data from the time series */
/*     at or before the start time of the run. */
/* SOURCE hecdmy.for:230 */
/*<       implicitnone >*/
/* SOURCE hecdmy.for:231 */
/*<       characternamein*(*),report_mode*8 >*/
/* SOURCE hecdmy.for:233 */
/*<       integerdss_file_index,time_step,stdout,eflag >*/
/* SOURCE hecdmy.for:235 */
/*<       real*8jtime,start_time >*/
/* *********************************************************************** */
/* SOURCE hecdmy.for:238 */
/*<       stop'HECDSS NOT IMPLEMENTED-10' >*/
    s_stop(const_cast<char*>("HECDSS NOT IMPLEMENTED-10"), (ftnlen)25);
/* SOURCE hecdmy.for:239 */
/*<       end >*/
    return 0;
} /* chk_hecdss_record__ */

#ifdef __cplusplus
	}
#endif
