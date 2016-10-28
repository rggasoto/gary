//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: simpleStateFlowModel_types.h
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
#ifndef RTW_HEADER_simpleStateFlowModel_types_h_
#define RTW_HEADER_simpleStateFlowModel_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_simpleStateFlowModel_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_simpleStateFlowModel_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_simpleStateFlowModel_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_simpleStateFlowModel_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_simpleStateFlowModel_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_simpleStateFlowModel_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_simpleStateFlowModel_geometry_msgs_Vector3 Angular;
} SL_Bus_simpleStateFlowModel_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_simpleStateFlowModel_geometry_msgs_Wrench_
#define DEFINED_TYPEDEF_FOR_SL_Bus_simpleStateFlowModel_geometry_msgs_Wrench_

// MsgType=geometry_msgs/Wrench
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_simpleStateFlowModel_geometry_msgs_Vector3 Force;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_simpleStateFlowModel_geometry_msgs_Vector3 Torque;
} SL_Bus_simpleStateFlowModel_geometry_msgs_Wrench;

#endif

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_block_T
#define typedef_robotics_slros_internal_block_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_block_T;

#endif                                 //typedef_robotics_slros_internal_block_T

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_blo_o_T
#define typedef_robotics_slros_internal_blo_o_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_blo_o_T;

#endif                                 //typedef_robotics_slros_internal_blo_o_T

#ifndef typedef_struct_T_simpleStateFlowModel_T
#define typedef_struct_T_simpleStateFlowModel_T

typedef struct {
  char_T f0[4];
} struct_T_simpleStateFlowModel_T;

#endif                                 //typedef_struct_T_simpleStateFlowModel_T

#ifndef typedef_struct_T_simpleStateFlowMod_o_T
#define typedef_struct_T_simpleStateFlowMod_o_T

typedef struct {
  char_T f0[8];
} struct_T_simpleStateFlowMod_o_T;

#endif                                 //typedef_struct_T_simpleStateFlowMod_o_T

#ifndef typedef_struct_T_simpleStateFlowMo_oi_T
#define typedef_struct_T_simpleStateFlowMo_oi_T

typedef struct {
  char_T f0[7];
} struct_T_simpleStateFlowMo_oi_T;

#endif                                 //typedef_struct_T_simpleStateFlowMo_oi_T

#ifndef typedef_struct_T_simpleStateFlowM_oiq_T
#define typedef_struct_T_simpleStateFlowM_oiq_T

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_simpleStateFlowM_oiq_T;

#endif                                 //typedef_struct_T_simpleStateFlowM_oiq_T

// Parameters (auto storage)
typedef struct P_simpleStateFlowModel_T_ P_simpleStateFlowModel_T;

// Forward declaration for rtModel
typedef struct tag_RTM_simpleStateFlowModel_T RT_MODEL_simpleStateFlowModel_T;

#endif                                 // RTW_HEADER_simpleStateFlowModel_types_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
