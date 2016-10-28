//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: hoffmannFollower.h
//
// Code generated for Simulink model 'hoffmannFollower'.
//
// Model version                  : 1.61
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Tue May 24 16:45:59 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_hoffmannFollower_h_
#define RTW_HEADER_hoffmannFollower_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef hoffmannFollower_COMMON_INCLUDES_
# define hoffmannFollower_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // hoffmannFollower_COMMON_INCLUDES_

#include "hoffmannFollower_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  real_T MultiportSwitch[903];         // '<S6>/Multiport Switch'
  creal_T r[301];
  real_T ys[301];                      // '<S6>/straight line'
  real_T xs[301];                      // '<S6>/straight line'
  SL_Bus_hoffmannFollower_nav_msgs_Odometry In1;// '<S14>/In1'
  SL_Bus_hoffmannFollower_nav_msgs_Odometry varargout_2;
  SL_Bus_hoffmannFollower_InteractiveMarkerPose_bqmzo4 BusAssignment1;// '<Root>/Bus Assignment1' 
  SL_Bus_hoffmannFollower_geometry_msgs_Twist BusAssignment;// '<Root>/Bus Assignment' 
  real_T delta1;
} B_hoffmannFollower_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S7>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S5>/SinkBlock'
  void *SinkBlock_PWORK_l;             // '<S4>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S5>/SinkBlock'
  robotics_slros_internal_block_T obj_n;// '<S4>/SinkBlock'
  robotics_slros_internal_blo_e_T obj_l;// '<S7>/SourceBlock'
} DW_hoffmannFollower_T;

// Parameters (auto storage)
struct P_hoffmannFollower_T_ {
  SL_Bus_hoffmannFollower_nav_msgs_Odometry Out1_Y0;// Computed Parameter: Out1_Y0
                                                    //  Referenced by: '<S14>/Out1'

  SL_Bus_hoffmannFollower_nav_msgs_Odometry Constant_Value;// Computed Parameter: Constant_Value
                                                           //  Referenced by: '<S7>/Constant'

  SL_Bus_hoffmannFollower_InteractiveMarkerPose_bqmzo4 Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                                      //  Referenced by: '<S2>/Constant'

  SL_Bus_hoffmannFollower_geometry_msgs_Twist Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                               //  Referenced by: '<S1>/Constant'

  real_T k1_Value;                     // Expression: 0
                                       //  Referenced by: '<S3>/k1'

  real_T pathChoice_Value;             // Expression: 1
                                       //  Referenced by: '<S6>/pathChoice '

  real_T radius_Value;                 // Expression: 36.6
                                       //  Referenced by: '<S6>/radius'

  real_T startpoint_Value[2];          // Expression: [0 0]
                                       //  Referenced by: '<S6>/start point'

  real_T len_Value;                    // Expression: 36.6
                                       //  Referenced by: '<S6>/len'

  real_T heading_Value;                // Expression: 0
                                       //  Referenced by: '<S6>/heading'

  real_T refVelocity_Value;            // Expression: 3
                                       //  Referenced by: '<Root>/refVelocity'

  real_T Switch_Threshold;             // Expression: 4
                                       //  Referenced by: '<S3>/Switch'

  real_T k_Value;                      // Expression: .7
                                       //  Referenced by: '<S3>/k'

  real_T Gain_Gain;                    // Expression: -1
                                       //  Referenced by: '<S3>/Gain'

  real_T Constant_Value_l;             // Expression: 0
                                       //  Referenced by: '<S9>/Constant'

  real_T u2_Gain;                      // Expression: 0.5
                                       //  Referenced by: '<S19>/1//2'

};

// Real-time Model Data Structure
struct tag_RTM_hoffmannFollower_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_hoffmannFollower_T hoffmannFollower_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_hoffmannFollower_T hoffmannFollower_B;

// Block states (auto storage)
extern DW_hoffmannFollower_T hoffmannFollower_DW;

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
  extern void hoffmannFollower_initialize(void);
  extern void hoffmannFollower_step(void);
  extern void hoffmannFollower_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_hoffmannFollower_T *const hoffmannFollower_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/Scope' : Unused code path elimination


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
//  '<Root>' : 'hoffmannFollower'
//  '<S1>'   : 'hoffmannFollower/Blank Message'
//  '<S2>'   : 'hoffmannFollower/Blank Message1'
//  '<S3>'   : 'hoffmannFollower/Hoffmann Controller'
//  '<S4>'   : 'hoffmannFollower/Publish'
//  '<S5>'   : 'hoffmannFollower/Publish1'
//  '<S6>'   : 'hoffmannFollower/Select desired path'
//  '<S7>'   : 'hoffmannFollower/Subscribe3'
//  '<S8>'   : 'hoffmannFollower/quaternion2heading'
//  '<S9>'   : 'hoffmannFollower/yaw2quat'
//  '<S10>'  : 'hoffmannFollower/Hoffmann Controller/calculate delta'
//  '<S11>'  : 'hoffmannFollower/Hoffmann Controller/calculate e'
//  '<S12>'  : 'hoffmannFollower/Select desired path/circle centered'
//  '<S13>'  : 'hoffmannFollower/Select desired path/straight line'
//  '<S14>'  : 'hoffmannFollower/Subscribe3/Enabled Subsystem'
//  '<S15>'  : 'hoffmannFollower/quaternion2heading/Quaternions to Rotation Angles'
//  '<S16>'  : 'hoffmannFollower/quaternion2heading/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S17>'  : 'hoffmannFollower/quaternion2heading/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S18>'  : 'hoffmannFollower/quaternion2heading/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S19>'  : 'hoffmannFollower/yaw2quat/Rotation Angles to Quaternions'

#endif                                 // RTW_HEADER_hoffmannFollower_h_

//
// File trailer for generated code.
//
// [EOF]
//
