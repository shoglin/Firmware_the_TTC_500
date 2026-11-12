#ifndef __c3_VCU_SW_h__
#define __c3_VCU_SW_h__

/* Type Definitions */
#ifdef __has_include
#if __has_include("swcAppEnumTypes.h")
#include "swcAppEnumTypes.h"
#else
#error Cannot find header file swcAppEnumTypes.h for imported type StateModeTypes.\
 Supply the missing header file or turn on Simulation Target -> Generate typedefs\
 for imported bus and enumeration types.
#endif

#else
#include "swcAppEnumTypes.h"
#endif

#ifndef typedef_SFc3_VCU_SWInstanceStruct
#define typedef_SFc3_VCU_SWInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c3_sfEvent;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_VCU_SW;
  uint8_T c3_JITStateAnimation[1];
  uint8_T c3_JITTransitionAnimation[1];
  int32_T c3_IsDebuggerActive;
  int32_T c3_IsSequenceViewerPresent;
  int32_T c3_SequenceViewerOptimization;
  int32_T c3_IsHeatMapPresent;
  void *c3_RuntimeVar;
  uint32_T c3_mlFcnLineNumber;
  void *c3_fcnDataPtrs[3];
  char_T *c3_dataNames[3];
  uint32_T c3_numFcnVars;
  uint32_T c3_ssIds[3];
  uint32_T c3_statuses[3];
  void *c3_outMexFcns[3];
  void *c3_inMexFcns[3];
  CovrtStateflowInstance *c3_covrtInstance;
  void *c3_fEmlrtCtx;
  boolean_T *c3_value;
  StateModeTypes *c3_enum;
  uint16_T *c3_error;
} SFc3_VCU_SWInstanceStruct;

#endif                                 /*typedef_SFc3_VCU_SWInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_VCU_SW_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_VCU_SW_get_check_sum(mxArray *plhs[]);
extern void c3_VCU_SW_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
