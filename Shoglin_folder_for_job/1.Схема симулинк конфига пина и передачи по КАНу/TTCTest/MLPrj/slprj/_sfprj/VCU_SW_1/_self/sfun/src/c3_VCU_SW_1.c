/* Include files */

#include "VCU_SW_1_sfun.h"
#include "c3_VCU_SW_1.h"
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

/* Forward Declarations */

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
static void initialize_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance);
static void initialize_params_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct
  *chartInstance);
static void mdl_start_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance);
static void mdl_terminate_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *
  chartInstance);
static void mdl_cleanup_runtime_resources_c3_VCU_SW_1
  (SFc3_VCU_SW_1InstanceStruct *chartInstance);
static void enable_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance);
static void disable_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance);
static void sf_gateway_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance);
static void ext_mode_exec_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance);
static void c3_update_jit_animation_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct
  *chartInstance);
static void c3_do_animation_call_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct
  *chartInstance);
static void set_sim_state_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance,
  const mxArray *c3_st);
static void initSimStructsc3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance);
static void initSubchartIOPointersc3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct
  *chartInstance);
static StateModeTypes c3_emlrt_marshallIn(SFc3_VCU_SW_1InstanceStruct
  *chartInstance, const mxArray *c3_nullptr, const char_T *c3_identifier);
static StateModeTypes c3_b_emlrt_marshallIn(SFc3_VCU_SW_1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static uint8_T c3_c_emlrt_marshallIn(SFc3_VCU_SW_1InstanceStruct *chartInstance,
  const mxArray *c3_nullptr, const char_T *c3_identifier);
static uint8_T c3_d_emlrt_marshallIn(SFc3_VCU_SW_1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_slStringInitializeDynamicBuffers(SFc3_VCU_SW_1InstanceStruct
  *chartInstance);
static void c3_chart_data_browse_helper(SFc3_VCU_SW_1InstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig);
static void init_dsm_address_info(SFc3_VCU_SW_1InstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_VCU_SW_1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance)
{
  sf_is_first_init_cond(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c3_doneDoubleBufferReInit = false;
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *
  chartInstance)
{
  static const uint32_T c3_decisionTxtEndIdx = 0U;
  static const uint32_T c3_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, chartInstance->c3_JITStateAnimation,
                        chartInstance->c3_JITTransitionAnimation);
  setDataBrowseFcn(chartInstance->S, (void *)&c3_chart_data_browse_helper);
  chartInstance->c3_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c3_RuntimeVar,
    &chartInstance->c3_IsDebuggerActive,
    &chartInstance->c3_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c3_mlFcnLineNumber, &chartInstance->c3_IsHeatMapPresent, 0);
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
                    278, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 93, 101, 156,
                    219, false);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 66, 84,
    0, 0U);
}

static void mdl_cleanup_runtime_resources_c3_VCU_SW_1
  (SFc3_VCU_SW_1InstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c3_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c3_covrtInstance);
}

static void enable_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance)
{
  uint16_T c3_b_error;
  boolean_T c3_b_value;
  StateModeTypes c3_b_enum;
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 1U, (real_T)
                    *chartInstance->c3_error);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 0U, (real_T)
                    *chartInstance->c3_value);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_JITTransitionAnimation[0] = 0U;
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
  c3_do_animation_call_c3_VCU_SW_1(chartInstance);
}

static void ext_mode_exec_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_update_jit_animation_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_do_animation_call_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct
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
  sf_mex_check_enum("StateModeTypes", 5, &c3_sv[0], &c3_iv[0]);
  c3_u = (int32_T)*chartInstance->c3_enum;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_m, c3_c_y, false);
  sf_mex_assign(&c3_b_y, sf_mex_create_enum("StateModeTypes", c3_m), false);
  sf_mex_destroy(&c3_m);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y",
    &chartInstance->c3_is_active_c3_VCU_SW_1, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_enum = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "enum");
  chartInstance->c3_is_active_c3_VCU_SW_1 = c3_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 1)), "is_active_c3_VCU_SW_1");
  sf_mex_destroy(&c3_u);
  sf_mex_destroy(&c3_st);
}

static void initSimStructsc3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSubchartIOPointersc3_VCU_SW_1(SFc3_VCU_SW_1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c3_VCU_SW_1_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  const char_T *c3_data[4] = {
    "789cc553c14ac340147c912a5e5a7bf22c7817040fc5a32b8516530289787085c6f495c46693905d4b73f7ee6ff847e267f80792269b260b4b4ac1f65d26c364"
    "dfcc0e091823d300801e1473715260b7e4fd128fa039aa6e6850ce31741ae7a4fe59a217470257a22091cbb03a398b5910b99170b20421451e874b9cad957910",
    "a21330b4eb64923336ac4915c9a5fc99f8e82dec7706a9cf3709c33aa9fa986aeedb69e9431db50ff53de997ece827f7f714aefa49dd16ae40339e615e2b3fdc"
    "7dbf76f493fb498b9fd49f272fe4963e724c390de357d7f37149ef912f449c50c7210e7241cd072b7da35ee8728e9c362bba628ddc534daeb32d73ebfe932e9c",
    "aef1fbe3c7d8a71fb0dfcbbdfa957328bf9566dfb6dfddb9c6afafe856fa34b4c88d188caf4936c8e6114f46e3bb4d0eabc5a72d0768f87fefff03627c58c3",
    "" };

  c3_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&c3_data[0], 1592U, &c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static StateModeTypes c3_emlrt_marshallIn(SFc3_VCU_SW_1InstanceStruct
  *chartInstance, const mxArray *c3_nullptr, const char_T *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  StateModeTypes c3_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nullptr), &c3_thisId);
  sf_mex_destroy(&c3_nullptr);
  return c3_y;
}

static StateModeTypes c3_b_emlrt_marshallIn(SFc3_VCU_SW_1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  StateModeTypes c3_y;
  (void)chartInstance;
  sf_mex_check_enum("StateModeTypes", 5, &c3_sv[0], &c3_iv[0]);
  sf_mex_check_builtin(c3_parentId, c3_u, "StateModeTypes", 0, 0U, NULL);
  c3_y = (StateModeTypes)sf_mex_get_enum_element(c3_u, 0);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static uint8_T c3_c_emlrt_marshallIn(SFc3_VCU_SW_1InstanceStruct *chartInstance,
  const mxArray *c3_nullptr, const char_T *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nullptr), &c3_thisId);
  sf_mex_destroy(&c3_nullptr);
  return c3_y;
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_VCU_SW_1InstanceStruct *chartInstance,
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

static void c3_slStringInitializeDynamicBuffers(SFc3_VCU_SW_1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_chart_data_browse_helper(SFc3_VCU_SW_1InstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig)
{
  const mxArray *c3_m = NULL;
  int32_T c3_i;
  uint16_T c3_u;
  boolean_T c3_b;
  StateModeTypes c3_r;
  *c3_mxData = NULL;
  *c3_mxData = NULL;
  *c3_isValueTooBig = 0U;
  switch (c3_ssIdNumber) {
   case 4U:
    c3_b = *chartInstance->c3_value;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_b, 11, 0U, 0U, 0U, 0),
                  false);
    break;

   case 5U:
    c3_r = *chartInstance->c3_enum;
    c3_i = (int32_T)c3_r;
    sf_mex_assign(&c3_m, sf_mex_create("unnamed temp", &c3_i, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_assign(c3_mxData, sf_mex_create_enum("StateModeTypes", c3_m), false);
    break;

   case 6U:
    c3_u = *chartInstance->c3_error;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_u, 5, 0U, 0U, 0U, 0),
                  false);
    break;
  }

  sf_mex_destroy(&c3_m);
}

static void init_dsm_address_info(SFc3_VCU_SW_1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_VCU_SW_1InstanceStruct *chartInstance)
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
void sf_c3_VCU_SW_1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(791495608U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(831922597U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4088606336U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2199587464U);
}

mxArray *sf_c3_VCU_SW_1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_VCU_SW_1_jit_fallback_info(void)
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

mxArray *sf_c3_VCU_SW_1_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_VCU_SW_1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wMjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lmw6GdB0i8A5KXmlebyQfmU2a/gQJ"
    "l+iP0eBNwviuJ+CD+zOD4xuSSzLDU+2Tg+zDk0Pjg83hBqHggAAGEdGHY="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_VCU_SW_1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "syYoJClqqhwmQsdvg21FiNE";
}

static void sf_opaque_initialize_c3_VCU_SW_1(void *chartInstanceVar)
{
  initialize_params_c3_VCU_SW_1((SFc3_VCU_SW_1InstanceStruct*) chartInstanceVar);
  initialize_c3_VCU_SW_1((SFc3_VCU_SW_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_VCU_SW_1(void *chartInstanceVar)
{
  enable_c3_VCU_SW_1((SFc3_VCU_SW_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_VCU_SW_1(void *chartInstanceVar)
{
  disable_c3_VCU_SW_1((SFc3_VCU_SW_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_VCU_SW_1(void *chartInstanceVar)
{
  sf_gateway_c3_VCU_SW_1((SFc3_VCU_SW_1InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_VCU_SW_1(SimStruct* S)
{
  return get_sim_state_c3_VCU_SW_1((SFc3_VCU_SW_1InstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_VCU_SW_1(SimStruct* S, const mxArray *st)
{
  set_sim_state_c3_VCU_SW_1((SFc3_VCU_SW_1InstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c3_VCU_SW_1(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_VCU_SW_1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_VCU_SW_1_optimization_info();
    }

    mdl_cleanup_runtime_resources_c3_VCU_SW_1((SFc3_VCU_SW_1InstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c3_VCU_SW_1(void *chartInstanceVar)
{
  mdl_start_c3_VCU_SW_1((SFc3_VCU_SW_1InstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc3_VCU_SW_1InstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c3_VCU_SW_1(void *chartInstanceVar)
{
  mdl_terminate_c3_VCU_SW_1((SFc3_VCU_SW_1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_VCU_SW_1(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_VCU_SW_1((SFc3_VCU_SW_1InstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc3_VCU_SW_1((SFc3_VCU_SW_1InstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c3_VCU_SW_1_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [25] = {
    "eNrdWUtv60QUtkOpuNAWkLiwAIkrsWEDor0gVQhx2zoJpOoj4LQVEFRN7ZN46HjszozzQGLHnr9",
    "w92yQEL+ADf8A+AmsKDuWnHGc1HV7G0/Co1xfpbfHzjdnznee41p2Y9fCawU/D1+2rEX8/yn8VK",
    "zR9WQm27nP6P6C9V4m//S0ZXmRD13gbtLp0IFldvEkbBJBQmmZX5yE8DHIiCWKRrzBO1F5LOUdE",
    "MA9XCCOhDLSK2mYMMpP6wn3tGZ5FFAvcIMoYf4WLkj8fc6Gj9IbJ6qJGqtUgKfqAL4KRJR0gzoj",
    "3ZtZEKrvBOCdyiQ05kqCcpNYmyp3E6ZozKA2AK/BpSLIgpxir6uIAkcNzEjW9kp3jI7CmFHCy3M",
    "dEOlCjNGh4CD28ed+opC9knpR3wnlREWCElYLmRMQURbbZLjPXQxrZsyzClUVTpJul/KuZlckIX",
    "C0H+OkBFcdJ+qBIF3Y52Z6PW1dbZA6eBKXJbGKhnBIxKaHcSDBN8tBDGDpEnQttHAZIyxwcsKgI",
    "VuC9tBHpnWjoVNpprqRhKNIkjNhU721HnpVzqi37nGHMCbNsK0o3oEesFR/lSgyA3ak3wAsJfVb",
    "EUaHzlzD7E84PUsgwzoR92n5qOwVUGmT2MOCXwJOQ50G4CPNk61PFpqWR4lUUehg6ld3dkrqu4p",
    "tcAWiQzwoXa8FoRJww2lcGer1qdSJhGhkSaVWll5hlIMzQS3ZSXi1H4lT5Ni0MVxwpTPBDA1+F6",
    "qgIC1yNYzuQ8KSknsOJVZlHR4HEqusmV7E6vyZCewRLwBf90DKYBfrLC5Q1sVSt89NtLZH1bAK0",
    "hM0LptJCRZ0bH6apdYwhgN+yqM+r4sodLMp5oa4AsCqQQTHVraFrVQM67j5crsWcNZKq7vpwKB5",
    "JoqREx0bHwDHbqht1d2beJhVNY7jJm5oHqxLv8RxhEsqFY6Aw1qaA346B29YF3PwwjVz8DO5Ofi",
    "5TPbuHx86B8fu0fGqNZ6n38qts1Rinh7jvnvCbA5fzuRv9D4iLDsDdTEcX3gyCtF/XOkQQNfgyN",
    "zL+nyHjhq3mxf2tBTWc48mgn6kf08Lm4uFTQS5gGB54QoPRT7HV57PMW6aH1YKOC2nY6ae2rSZc",
    "j79gyn6nQJOy5/tfe682z6QIGSbRSc643ttzNdTFcXtVstpgVTt3Z2m+KLtMYKjlmxf3vKb4UT/",
    "ek7/s1PiYDm7//PXv9rz4K3wj9fmwuf4mxf/4RT+Xyzwr+WmOKo3nbfV+vaqM1wfdriMG9tbo/V",
    "ez61nX7NePg5m+f6suHx83qlc/n6lwFMF/9n21fxYLuhZKOAWM45+fP6r35rfPvh98IOzvNY5/3",
    "6afvuKfnuSew8rZnVqnK+vjM8qk8mod2V4KOP/lwr+17IcfhJtO+zsLOiHH0m/111brdO9Wrreu",
    "X3zfiuF/Y7v39PnI1019frCa/i50kqS0Xm4GO+LU/i4cynezx/Mh39hY1qds3MxMeJrAee+JFx5",
    "RL6a6b+3MR++nL/vFvx9Nz0vHxM9FcHx5Q68UjK/bopvU9z/Rd/jvs+/074yc1tlRpw955z4b+H",
    "mte+f7ru37fuzzpu3zQ7rhjq6dI1ddmHd22rXL5bZ3PJqJr8/eRfmBJT515zGs8d4YO5c9/Qxie",
    "8/Dfkbz2k1zV/2B4hP729ywoZ4/B693shuN4V+9z15JIDI699x/Bf9pOy5dKmQ31ruU+5HffnG6",
    "to7q/P0p78ASRhZJw==",
    ""
  };

  static char newstr [1745] = "";
  newstr[0] = '\0';
  for (i = 0; i < 25; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c3_VCU_SW_1(SimStruct *S)
{
  const char* newstr = sf_c3_VCU_SW_1_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(3917287875U));
  ssSetChecksum1(S,(4013927248U));
  ssSetChecksum2(S,(222541176U));
  ssSetChecksum3(S,(3018876466U));
}

static void mdlRTW_c3_VCU_SW_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c3_VCU_SW_1(SimStruct *S)
{
  SFc3_VCU_SW_1InstanceStruct *chartInstance;
  chartInstance = (SFc3_VCU_SW_1InstanceStruct *)utMalloc(sizeof
    (SFc3_VCU_SW_1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_VCU_SW_1InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_VCU_SW_1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_VCU_SW_1;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c3_VCU_SW_1;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c3_VCU_SW_1;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c3_VCU_SW_1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_VCU_SW_1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_VCU_SW_1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_VCU_SW_1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_VCU_SW_1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_VCU_SW_1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_VCU_SW_1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_VCU_SW_1;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c3_VCU_SW_1(chartInstance);
}

void c3_VCU_SW_1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c3_VCU_SW_1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_VCU_SW_1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_VCU_SW_1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_VCU_SW_1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
