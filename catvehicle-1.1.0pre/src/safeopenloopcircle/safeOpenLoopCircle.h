//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: safeOpenLoopCircle.h
//
// Code generated for Simulink model 'safeOpenLoopCircle'.
//
// Model version                  : 1.12
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Thu Apr 21 12:32:15 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_safeOpenLoopCircle_h_
#define RTW_HEADER_safeOpenLoopCircle_h_
#include <stddef.h>
#include <string.h>
#ifndef safeOpenLoopCircle_COMMON_INCLUDES_
# define safeOpenLoopCircle_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // safeOpenLoopCircle_COMMON_INCLUDES_

#include "safeOpenLoopCircle_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist In1;// '<S6>/In1'
  SL_Bus_safeOpenLoopCircle_geometry_msgs_Wrench varargout_2;
  real_T vOut;                         // '<Root>/Chart'
  real_T steeringOut;                  // '<Root>/Chart'
} B_safeOpenLoopCircle_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S5>/SourceBlock'
  void *SourceBlock_PWORK_m;           // '<S4>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S3>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S3>/SinkBlock'
  robotics_slros_internal_blo_c_T obj_m;// '<S5>/SourceBlock'
  robotics_slros_internal_blo_c_T obj_d;// '<S4>/SourceBlock'
  uint8_T is_active_c3_safeOpenLoopCircle;// '<Root>/Chart'
  uint8_T is_c3_safeOpenLoopCircle;    // '<Root>/Chart'
} DW_safeOpenLoopCircle_T;

// Parameters (auto storage)
struct P_safeOpenLoopCircle_T_ {
  SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                        //  Referenced by: '<S6>/Out1'

  SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                               //  Referenced by: '<S4>/Constant'

  SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                                 //  Referenced by: '<S1>/Constant'

  SL_Bus_safeOpenLoopCircle_geometry_msgs_Wrench Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                           //  Referenced by: '<S7>/Out1'

  SL_Bus_safeOpenLoopCircle_geometry_msgs_Wrench Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                  //  Referenced by: '<S5>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_safeOpenLoopCircle_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_safeOpenLoopCircle_T safeOpenLoopCircle_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_safeOpenLoopCircle_T safeOpenLoopCircle_B;

// Block states (auto storage)
extern DW_safeOpenLoopCircle_T safeOpenLoopCircle_DW;

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
  extern void safeOpenLoopCircle_initialize(void);
  extern void safeOpenLoopCircle_step(void);
  extern void safeOpenLoopCircle_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_safeOpenLoopCircle_T *const safeOpenLoopCircle_M;

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
//  '<Root>' : 'safeOpenLoopCircle'
//  '<S1>'   : 'safeOpenLoopCircle/Blank Message'
//  '<S2>'   : 'safeOpenLoopCircle/Chart'
//  '<S3>'   : 'safeOpenLoopCircle/Publish'
//  '<S4>'   : 'safeOpenLoopCircle/Subscribe'
//  '<S5>'   : 'safeOpenLoopCircle/Subscribe1'
//  '<S6>'   : 'safeOpenLoopCircle/Subscribe/Enabled Subsystem'
//  '<S7>'   : 'safeOpenLoopCircle/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_safeOpenLoopCircle_h_

//
// File trailer for generated code.
//
// [EOF]
//
