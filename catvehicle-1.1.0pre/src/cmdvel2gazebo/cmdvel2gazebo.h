//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: cmdvel2gazebo.h
//
// Code generated for Simulink model 'cmdvel2gazebo'.
//
// Model version                  : 1.29
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Tue May 10 14:11:14 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Custom Processor->Custom
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_cmdvel2gazebo_h_
#define RTW_HEADER_cmdvel2gazebo_h_
#include <string.h>
#include <stddef.h>
#ifndef cmdvel2gazebo_COMMON_INCLUDES_
# define cmdvel2gazebo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // cmdvel2gazebo_COMMON_INCLUDES_

#include "cmdvel2gazebo_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

// Block signals (auto storage)
typedef struct {
  char_T cv0[60];
  char_T cv1[59];
  SL_Bus_cmdvel2gazebo_geometry_msgs_Twist In1;// '<S13>/In1'
  SL_Bus_cmdvel2gazebo_geometry_msgs_Twist varargout_2;
  char_T cv2[46];
  real_T safeValue;                    // '<S5>/timeout set to 0 output'
} B_cmdvel2gazebo_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T TimeStampA;                   // '<S11>/Derivative'
  real_T LastUAtTimeA;                 // '<S11>/Derivative'
  real_T TimeStampB;                   // '<S11>/Derivative'
  real_T LastUAtTimeB;                 // '<S11>/Derivative'
  real_T sinceLastMsg;                 // '<S5>/timeout set to 0 output'
  void *SourceBlock_PWORK;             // '<S10>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S9>/SinkBlock'
  void *SinkBlock_PWORK_f;             // '<S8>/SinkBlock'
  void *SinkBlock_PWORK_h;             // '<S7>/SinkBlock'
  void *SinkBlock_PWORK_l;             // '<S6>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S9>/SinkBlock'
  robotics_slros_internal_block_T obj_m;// '<S8>/SinkBlock'
  robotics_slros_internal_block_T obj_l;// '<S7>/SinkBlock'
  robotics_slros_internal_block_T obj_n;// '<S6>/SinkBlock'
  robotics_slros_internal_blo_a_T obj_d;// '<S10>/SourceBlock'
  boolean_T sinceLastMsg_not_empty;    // '<S5>/timeout set to 0 output'
} DW_cmdvel2gazebo_T;

// Continuous states (auto storage)
typedef struct {
  real_T TransferFcn1_CSTATE;          // '<S11>/Transfer Fcn1'
  real_T TransferFcn2_CSTATE;          // '<S11>/Transfer Fcn2'
} X_cmdvel2gazebo_T;

// State derivatives (auto storage)
typedef struct {
  real_T TransferFcn1_CSTATE;          // '<S11>/Transfer Fcn1'
  real_T TransferFcn2_CSTATE;          // '<S11>/Transfer Fcn2'
} XDot_cmdvel2gazebo_T;

// State disabled
typedef struct {
  boolean_T TransferFcn1_CSTATE;       // '<S11>/Transfer Fcn1'
  boolean_T TransferFcn2_CSTATE;       // '<S11>/Transfer Fcn2'
} XDis_cmdvel2gazebo_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Parameters (auto storage)
struct P_cmdvel2gazebo_T_ {
  real_T DeadMansSwitch_stepSize;      // Mask Parameter: DeadMansSwitch_stepSize
                                       //  Referenced by: '<S5>/Simulate step size'

  real_T DeadMansSwitch_timeout;       // Mask Parameter: DeadMansSwitch_timeout
                                       //  Referenced by: '<S5>/Timeout in seconds'

  SL_Bus_cmdvel2gazebo_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                   //  Referenced by: '<S13>/Out1'

  SL_Bus_cmdvel2gazebo_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                          //  Referenced by: '<S10>/Constant'

  real_T TransferFcn1_A;               // Computed Parameter: TransferFcn1_A
                                       //  Referenced by: '<S11>/Transfer Fcn1'

  real_T TransferFcn1_C;               // Computed Parameter: TransferFcn1_C
                                       //  Referenced by: '<S11>/Transfer Fcn1'

  real_T TransferFcn2_A;               // Computed Parameter: TransferFcn2_A
                                       //  Referenced by: '<S11>/Transfer Fcn2'

  real_T TransferFcn2_C;               // Computed Parameter: TransferFcn2_C
                                       //  Referenced by: '<S11>/Transfer Fcn2'

  real_T Switch_Threshold;             // Expression: 0
                                       //  Referenced by: '<S11>/Switch'

  real_T GazeboMultiplier_Gain;        // Expression: 2.8101
                                       //  Referenced by: '<Root>/Gazebo Multiplier'

  SL_Bus_cmdvel2gazebo_std_msgs_Float64 Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                         //  Referenced by: '<S1>/Constant'

  SL_Bus_cmdvel2gazebo_std_msgs_Float64 Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                         //  Referenced by: '<S2>/Constant'

  SL_Bus_cmdvel2gazebo_std_msgs_Float64 Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                         //  Referenced by: '<S3>/Constant'

  SL_Bus_cmdvel2gazebo_std_msgs_Float64 Constant_Value_h5;// Computed Parameter: Constant_Value_h5
                                                          //  Referenced by: '<S4>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_cmdvel2gazebo_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  ModelData:
  //  The following substructure contains information regarding
  //  the data used in the model.

  struct {
    X_cmdvel2gazebo_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[2];
    real_T odeF[3][2];
    ODE3_IntgData intgData;
  } ModelData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_cmdvel2gazebo_T cmdvel2gazebo_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_cmdvel2gazebo_T cmdvel2gazebo_B;

// Continuous states (auto storage)
extern X_cmdvel2gazebo_T cmdvel2gazebo_X;

// Block states (auto storage)
extern DW_cmdvel2gazebo_T cmdvel2gazebo_DW;

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
  extern void cmdvel2gazebo_initialize(void);
  extern void cmdvel2gazebo_step(void);
  extern void cmdvel2gazebo_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_cmdvel2gazebo_T *const cmdvel2gazebo_M;

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
//  '<Root>' : 'cmdvel2gazebo'
//  '<S1>'   : 'cmdvel2gazebo/Blank Message'
//  '<S2>'   : 'cmdvel2gazebo/Blank Message1'
//  '<S3>'   : 'cmdvel2gazebo/Blank Message2'
//  '<S4>'   : 'cmdvel2gazebo/Blank Message3'
//  '<S5>'   : 'cmdvel2gazebo/Dead Man's Switch'
//  '<S6>'   : 'cmdvel2gazebo/Publish'
//  '<S7>'   : 'cmdvel2gazebo/Publish1'
//  '<S8>'   : 'cmdvel2gazebo/Publish2'
//  '<S9>'   : 'cmdvel2gazebo/Publish3'
//  '<S10>'  : 'cmdvel2gazebo/Subscribe'
//  '<S11>'  : 'cmdvel2gazebo/Velocity Dynamics'
//  '<S12>'  : 'cmdvel2gazebo/Dead Man's Switch/timeout set to 0 output'
//  '<S13>'  : 'cmdvel2gazebo/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_cmdvel2gazebo_h_

//
// File trailer for generated code.
//
// [EOF]
//
