#ifndef FEQ_PROBE_CALLBACKS_HPP
#define FEQ_PROBE_CALLBACKS_HPP
#include "common.hpp"
typedef doublereal (*FeqCallback1)(doublereal*);
typedef doublereal (*FeqCallback2)(doublereal*, doublereal*);
typedef doublereal (*FeqCallback3)(real*);
typedef int (*FeqCallback4)(integer*, doublereal*, doublereal*, doublereal*, doublereal*, doublereal*, doublereal*, doublereal*, integer*);
#endif
