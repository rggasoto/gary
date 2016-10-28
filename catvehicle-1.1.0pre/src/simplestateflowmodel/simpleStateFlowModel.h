//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: simpleStateFlowModel.h
//
// Code generated for Simulink model 'simpleStateFlowModel'.
//
// Model version                  : 1.2
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Wed Apr 13 06:33:42 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_simpleStateFlowModel_h_
#define RTW_HEADER_simpleStateFlowModel_h_
#include <stddef.h>
#include <string.h>
#ifndef simpleStateFlowModel_COMMON_INCLUDES_
# define simpleStateFlowModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // simpleStateFlowModel_COMMON_INCLUDES_

#include "simpleStateFlowModel_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  SL_Bus_simpleStateFlowModel_geometry_msgs_Twist In1;// '<S6>/In1'
  SL_Bus_simpleStateFlowModel_geometry_msgs_Wrench In1_c;// '<S7>/In1'
  SL_Bus_simpleStateFlowModel_geometry_msgs_Wrench varargout_2;
  char_T cv0[23];
  real_T vOut;                         // '<Root>/Chart'
} B_simpleStateFlowModel_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S5>/SourceBlock'
  void *SourceBlock_PWORK_m;           // '<S4>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S3>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S3>/SinkBlock'
  robotics_slros_internal_blo_o_T obj_m;// '<S5>/SourceBlock'
  robotics_slros_internal_blo_o_T obj_d;// '<S4>/SourceBlock'
  uint8_T is_active_c3_simpleStateFlowMod;// '<Root>/Chart'
  uint8_T is_c3_simpleStateFlowModel;  // '<Root>/Chart'
} DW_simpleStateFlowModel_T;

// Parameters (auto storage)
struct P_simpleStateFlowModel_T_ {
  SL_Bus_simpleStateFlowModel_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                          //  Referenced by: '<S6>/Out1'

  SL_Bus_simpleStateFlowModel_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                                 //  Referenced by: '<S4>/Constant'

  SL_Bus_simpleStateFlowModel_geometry_msgs_Twist Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                                   //  Referenced by: '<S1>/Constant'

  SL_Bus_simpleStateFlowModel_geometry_msgs_Wrench Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                             //  Referenced by: '<S7>/Out1'

  SL_Bus_simpleStateFlowModel_geometry_msgs_Wrench Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                    //  Referenced by: '<S5>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_simpleStateFlowModel_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_simpleStateFlowModel_T simpleStateFlowModel_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_simpleStateFlowModel_T simpleStateFlowModel_B;

// Block states (auto storage)
extern DW_simpleStateFlowModel_T simpleStateFlowModel_DW;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void simpleStateFlowModel_initialize(void);
  extern void simpleStateFlowModel_step(void);
  extern void simpleStateFlowModel_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_simpleStateFlowModel_T *const simpleStateFlowModel_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'simpleStateFlowModel'
//  '<S1>'   : 'simpleStateFlowModel/Blank Message'
//  '<S2>'   : 'simpleStateFlowModel/Chart'
//  '<S3>'   : 'simpleStateFlowModel/Publish'
//  '<S4>'   : 'simpleStateFlowModel/Subscribe'
//  '<S5>'   : 'simpleStateFlowModel/Subscribe1'
//  '<S6>'   : 'simpleStateFlowModel/Subscribe/Enabled Subsystem'
//  '<S7>'   : 'simpleStateFlowModel/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_simpleStateFlowModel_h_

//
// File trailer for generated code.
//
// [EOF]
//
