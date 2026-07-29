/* Include files */

#include "VCU_SW_sfun.h"
#include "c3_VCU_SW.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char_T *c3_sv[5] = { "STT_DISABLE", "STT_ENABLE", "STT_RESERVED",
  "STT_DEFAULT", "STT_ERROR" };

static const int32_T c3_iv[5] = { 0, 1, 2, 3, 4 };

/* Function Declarations */
static void initialize_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance);
static void initialize_params_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance);
static void enable_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance);
static void disable_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance);
static void c3_update_jit_animation_state_c3_VCU_SW(SFc3_VCU_SWInstanceStruct
  *chartInstance);
static void c3_do_animation_call_c3_VCU_SW(SFc3_VCU_SWInstanceStruct
  *chartInstance);
static void ext_mode_exec_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_VCU_SW(SFc3_VCU_SWInstanceStruct
  *chartInstance);
static void set_sim_state_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance,
  const mxArray *c3_st);
static void sf_gateway_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance);
static void mdl_start_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance);
static void mdl_terminate_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c3_VCU_SW(SFc3_VCU_SWInstanceStruct
  *chartInstance);
static void mdl_cleanup_runtime_resources_c3_VCU_SW(SFc3_VCU_SWInstanceStruct
  *chartInstance);
static void initSimStructsc3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance);
static StateModeTypes c3_emlrt_marshallIn(SFc3_VCU_SWInstanceStruct
  *chartInstance, const mxArray *c3_b_enum, const char_T *c3_identifier);
static StateModeTypes c3_b_emlrt_marshallIn(SFc3_VCU_SWInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static uint8_T c3_c_emlrt_marshallIn(SFc3_VCU_SWInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_VCU_SW, const char_T *c3_identifier);
static uint8_T c3_d_emlrt_marshallIn(SFc3_VCU_SWInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *c3_chart_data_browse_helper(SFc3_VCU_SWInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber);
static void init_dsm_address_info(SFc3_VCU_SWInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_VCU_SWInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_VCU_SW = 0U;
}

static void initialize_params_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_jit_animation_state_c3_VCU_SW(SFc3_VCU_SWInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_do_animation_call_c3_VCU_SW(SFc3_VCU_SWInstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_VCU_SW(SFc3_VCU_SWInstanceStruct
  *chartInstance)
{
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_m = NULL;
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_u;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(2, 1), false);
  c3_b_y = NULL;
  sf_mex_check_enum("StateModeTypes", 5, c3_sv, c3_iv);
  c3_u = (int32_T)*chartInstance->c3_enum;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_m, c3_c_y, false);
  sf_mex_assign(&c3_b_y, sf_mex_create_enum("StateModeTypes", c3_m), false);
  sf_mex_destroy(&c3_m);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y",
    &chartInstance->c3_is_active_c3_VCU_SW, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_enum = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "enum");
  chartInstance->c3_is_active_c3_VCU_SW = c3_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 1)), "is_active_c3_VCU_SW");
  sf_mex_destroy(&c3_u);
  sf_mex_destroy(&c3_st);
}

static void sf_gateway_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance)
{
  uint16_T c3_b_error;
  boolean_T c3_b_value;
  StateModeTypes c3_b_enum;
  chartInstance->c3_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 1U, (real_T)
                    *chartInstance->c3_error);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 0U, (real_T)
                    *chartInstance->c3_value);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_b_value = *chartInstance->c3_value;
  c3_b_error = *chartInstance->c3_error;
  covrtEmlFcnEval(chartInstance->c3_covrtInstance, 4U, 0, 0);
  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance,
        4U, 0U, 0U, (real_T)c3_b_error, 0.0, 0, 0U, c3_b_error == 0))) {
    if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 1, c3_b_value)) {
      c3_b_enum = STT_ENABLE;
    } else {
      c3_b_enum = STT_DISABLE;
    }
  } else {
    c3_b_enum = STT_ERROR;
  }

  *chartInstance->c3_enum = c3_b_enum;
  c3_do_animation_call_c3_VCU_SW(chartInstance);
}

static void mdl_start_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c3_VCU_SW(SFc3_VCU_SWInstanceStruct
  *chartInstance)
{
  static const uint32_T c3_decisionTxtEndIdx = 0U;
  static const uint32_T c3_decisionTxtStartIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c3_chart_data_browse_helper);
  chartInstance->c3_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c3_RuntimeVar,
    &chartInstance->c3_IsDebuggerActive,
    &chartInstance->c3_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c3_mlFcnLineNumber, &chartInstance->c3_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c3_covrtInstance, 1U, 0U, 1U,
    348U);
  covrtChartInitFcn(chartInstance->c3_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c3_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c3_decisionTxtStartIdx, &c3_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c3_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c3_covrtInstance, "", 4U, 0U, 1U, 0U, 2U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 282);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 63, 84, 224,
                    278);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 93, 101, 156,
                    219);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 66, 84,
    0, 0U);
}

static void mdl_cleanup_runtime_resources_c3_VCU_SW(SFc3_VCU_SWInstanceStruct
  *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c3_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c3_covrtInstance);
}

static void initSimStructsc3_VCU_SW(SFc3_VCU_SWInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c3_VCU_SW_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  const char_T *c3_data[4] = {
    "789c6360f4f465646060e0638000093608cd0bc4d24c0c0c025071260654802ecf8885fe598f50cfcac002e6f322c983f4f743f9c9f97925a91525104e5e626e"
    "2a5c674a7e6e665e625e494865412a43516a717e4e596a0a58262d332735243337351899e307e2e5ba2149c139202910db392335393bb83497a128a318e1c21c",
    "640e383c40ee4b40f22fc8fd30ffb260090f647974c088c617400b1f987d0564da07339f0f8d8f6e1f4c3eb824b124d5373f251514acc503e7df0564da0733df"
    "8a807d30f968bf58172bfdf0fca26cfd82a2fcacd4e49262fd9010e790d4e2127d5f9f80a22cfde49cc4e2e2d4627dd490d1cb45756f020ef7f013e95e741aa1",
    "9e03acfe7acb4d467adac790fb5199aef641c140d95781c33c62d39b180efb60e90d261f5014ee16e06c5262e165e85c69519996575ce0e9e584704700017b08"
    "b98301079fd6e60300b0118623", "" };

  c3_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&c3_data[0], 1584U, &c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static StateModeTypes c3_emlrt_marshallIn(SFc3_VCU_SWInstanceStruct
  *chartInstance, const mxArray *c3_b_enum, const char_T *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  StateModeTypes c3_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_enum), &c3_thisId);
  sf_mex_destroy(&c3_b_enum);
  return c3_y;
}

static StateModeTypes c3_b_emlrt_marshallIn(SFc3_VCU_SWInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  StateModeTypes c3_y;
  (void)chartInstance;
  sf_mex_check_enum("StateModeTypes", 5, c3_sv, c3_iv);
  sf_mex_check_builtin(c3_parentId, c3_u, "StateModeTypes", 0, 0U, NULL);
  c3_y = (StateModeTypes)sf_mex_get_enum_element(c3_u, 0);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static uint8_T c3_c_emlrt_marshallIn(SFc3_VCU_SWInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_VCU_SW, const char_T *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_VCU_SW), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_VCU_SW);
  return c3_y;
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_VCU_SWInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_b_u;
  uint8_T c3_y;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b_u, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_b_u;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *c3_chart_data_browse_helper(SFc3_VCU_SWInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber)
{
  const mxArray *c3_m = NULL;
  const mxArray *c3_mxData = NULL;
  int32_T c3_i;
  uint16_T c3_u;
  boolean_T c3_b;
  StateModeTypes c3_r;
  c3_mxData = NULL;
  switch (c3_ssIdNumber) {
   case 4U:
    c3_b = *chartInstance->c3_value;
    sf_mex_assign(&c3_mxData, sf_mex_create("mxData", &c3_b, 11, 0U, 0U, 0U, 0),
                  false);
    break;

   case 5U:
    c3_r = *chartInstance->c3_enum;
    c3_i = (int32_T)c3_r;
    sf_mex_assign(&c3_m, sf_mex_create("unnamed temp", &c3_i, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_assign(&c3_mxData, sf_mex_create_enum("StateModeTypes", c3_m), false);
    break;

   case 6U:
    c3_u = *chartInstance->c3_error;
    sf_mex_assign(&c3_mxData, sf_mex_create("mxData", &c3_u, 5, 0U, 0U, 0U, 0),
                  false);
    break;
  }

  sf_mex_destroy(&c3_m);
  return c3_mxData;
}

static void init_dsm_address_info(SFc3_VCU_SWInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_VCU_SWInstanceStruct *chartInstance)
{
  chartInstance->c3_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_value = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_enum = (StateModeTypes *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_error = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c3_VCU_SW_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4149907275U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2685075159U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1798036352U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(869640696U);
}

mxArray *sf_c3_VCU_SW_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_VCU_SW_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("imported_enum");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("StateModeTypes");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_VCU_SW_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_VCU_SW(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wMjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lmw6GdB0i8A5KXmlebyQfmU2a/gQJ"
    "l+iP0eBNwvjOJ+CD+zOD4xuSSzLDU+2Tg+zDk0Pjgcbh4IAABZThfi"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_VCU_SW_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "scZ2AYJRDMFN454yvIGziAG";
}

static void sf_opaque_initialize_c3_VCU_SW(void *chartInstanceVar)
{
  initialize_params_c3_VCU_SW((SFc3_VCU_SWInstanceStruct*) chartInstanceVar);
  initialize_c3_VCU_SW((SFc3_VCU_SWInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_VCU_SW(void *chartInstanceVar)
{
  enable_c3_VCU_SW((SFc3_VCU_SWInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_VCU_SW(void *chartInstanceVar)
{
  disable_c3_VCU_SW((SFc3_VCU_SWInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_VCU_SW(void *chartInstanceVar)
{
  sf_gateway_c3_VCU_SW((SFc3_VCU_SWInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_VCU_SW(SimStruct* S)
{
  return get_sim_state_c3_VCU_SW((SFc3_VCU_SWInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_VCU_SW(SimStruct* S, const mxArray *st)
{
  set_sim_state_c3_VCU_SW((SFc3_VCU_SWInstanceStruct*)sf_get_chart_instance_ptr
    (S), st);
}

static void sf_opaque_cleanup_runtime_resources_c3_VCU_SW(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_VCU_SWInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_VCU_SW_optimization_info();
    }

    mdl_cleanup_runtime_resources_c3_VCU_SW((SFc3_VCU_SWInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c3_VCU_SW(void *chartInstanceVar)
{
  mdl_start_c3_VCU_SW((SFc3_VCU_SWInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c3_VCU_SW(void *chartInstanceVar)
{
  mdl_terminate_c3_VCU_SW((SFc3_VCU_SWInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_VCU_SW((SFc3_VCU_SWInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_VCU_SW(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_VCU_SW((SFc3_VCU_SWInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc3_VCU_SW((SFc3_VCU_SWInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c3_VCU_SW_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [19] = {
    "eNrtV09v3EQUt1dLRaVSRRSJCxK9tUcEBXGCJN7ddlG2iepNKrhEk/Hb9WjHM2b+ONl+Aj4GXHp",
    "GqBz4AFw5cOLGV+gXQPDG62w2XtubzapVQThynLF/7zfvvd+bNxPP7w88vG7j/d27nncDn2/j3f",
    "Jm11vF2F+4Z+/b3r1i/AKNhE0OiCKJ9hovQRJ4Alpya5gUfTGSlTAmRqBAUMSmUpk6Ns0Sy5mY9",
    "Kygjk8/jRmNw1haHu2iLYn2BZ8iW2rNAfJ0mAJqegCRiZW047jHyXjusTKnQQx0om3SFIIGE9rU",
    "uaUHlhuWcuieAe0LbQh6rC98Cw0xEJiz2jBdpDo8B8ok5YyIymhjokNIMcEGDtMIf+9bg0GVYTQ",
    "myuxCTDLQe2ySc0oBZU6m8cMJE8RIxQjvJjxwhsu+HXD0ZyAj4A0JQd92FZBJKpkw9fqHPYy0K8",
    "gJhw6c2HE9WwjfWif+EYNTULV5GwUyA0XGsC9qJ80T0j3L1ZpXyTLMsASOiNqhqJ+GqLZ6sXJ0S",
    "FAnGKJFHQzyIPt6qFiG6a1ls0nfVeaqJWOTmdh6FSxn62bQpMKcrUdFQDjXtbChTPcgA56zdogh",
    "zbAZazVOaxYNJSbYlXf9arCCofAFLJAiYpVyZSVA3nceY2O5jKRWG5kEWLydvb3lz8uwvjCgRoR",
    "CVRdQhGnAnOXprWeLmHbaIxC9Mrl7VeBZhaxCeXpkRedUqgnmpKGJXITgFK0FJnqMWuJKONS4aJ",
    "pgTstVOEpoDJFrMIzDAJcNYityol1r28F1lzEz7YCmiqUVqlpcddiGuq6gpikciomQp6KnZBIWP",
    "X6mAnYG7OEJajDM15igSMW0wXbBLqaPALAoiRJMjHexzalpD52sVMztex95F/verSvse+d25ef9",
    "BR6/gsdbeJbnvdm6jG+V5m3hj+/P7LYX7N4pzdMu2TncFt4//vb7z9EPfz//9bODR3/98udPq+b",
    "3l+b387+d3fet9c4Jt4vxB+cNeb7AsqW6dthHC361K/jfX+DfKsaafvPxztdfPekMeo8ffPpgmv",
    "UfPmM7D3O+l36zv62Sv+fv77qdAasxr2NF+1FxgHFjYmfbuuP/fMHfGyvycbN4P7tefrmZ/XvbZ",
    "R2r8tW+lK82dh+bLNbt9ee/u72Z/dX0vlPS+06+/x8T11XgmH5yfBQcHodPl9bjdet7XTvvNdv9",
    "W/z8Py+vPr6r7Feta9r5G+6Pr8tu0/jW3bffNHxT//dK+K03OI5Nz1OvGv+Ht96558Ni/MX8X6A",
    "gZjyqOA0Xn/HMOqr6+h+p03Xw/wClvr5G",
    ""
  };

  static char newstr [1309] = "";
  newstr[0] = '\0';
  for (i = 0; i < 19; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c3_VCU_SW(SimStruct *S)
{
  const char* newstr = sf_c3_VCU_SW_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(3050491568U));
  ssSetChecksum1(S,(2801770852U));
  ssSetChecksum2(S,(1213216453U));
  ssSetChecksum3(S,(3001006589U));
}

static void mdlRTW_c3_VCU_SW(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c3_VCU_SW(SimStruct *S)
{
  SFc3_VCU_SWInstanceStruct *chartInstance;
  chartInstance = (SFc3_VCU_SWInstanceStruct *)utMalloc(sizeof
    (SFc3_VCU_SWInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_VCU_SWInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_VCU_SW;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_VCU_SW;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c3_VCU_SW;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c3_VCU_SW;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c3_VCU_SW;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_VCU_SW;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_VCU_SW;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_VCU_SW;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_VCU_SW;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_VCU_SW;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_VCU_SW;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_VCU_SW;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c3_JITStateAnimation,
    chartInstance->c3_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c3_VCU_SW(chartInstance);
}

void c3_VCU_SW_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c3_VCU_SW(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_VCU_SW(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_VCU_SW(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_VCU_SW_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
