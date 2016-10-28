//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: cmdvel2gazebo_types.h
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
#ifndef RTW_HEADER_cmdvel2gazebo_types_h_
#define RTW_HEADER_cmdvel2gazebo_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_cmdvel2gazebo_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_cmdvel2gazebo_std_msgs_Float64_

// MsgType=std_msgs/Float64
typedef struct {
  real_T Data;
} SL_Bus_cmdvel2gazebo_std_msgs_Float64;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_cmdvel2gazebo_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_cmdvel2gazebo_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_cmdvel2gazebo_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_cmdvel2gazebo_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_cmdvel2gazebo_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_cmdvel2gazebo_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_cmdvel2gazebo_geometry_msgs_Vector3 Angular;
} SL_Bus_cmdvel2gazebo_geometry_msgs_Twist;

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

#ifndef typedef_robotics_slros_internal_blo_a_T
#define typedef_robotics_slros_internal_blo_a_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_blo_a_T;

#endif                                 //typedef_robotics_slros_internal_blo_a_T

#ifndef typedef_struct_T_cmdvel2gazebo_T
#define typedef_struct_T_cmdvel2gazebo_T

typedef struct {
  char_T f0[4];
} struct_T_cmdvel2gazebo_T;

#endif                                 //typedef_struct_T_cmdvel2gazebo_T

#ifndef typedef_struct_T_cmdvel2gazebo_a_T
#define typedef_struct_T_cmdvel2gazebo_a_T

typedef struct {
  char_T f0[8];
} struct_T_cmdvel2gazebo_a_T;

#endif                                 //typedef_struct_T_cmdvel2gazebo_a_T

#ifndef typedef_struct_T_cmdvel2gazebo_aq_T
#define typedef_struct_T_cmdvel2gazebo_aq_T

typedef struct {
  char_T f0[7];
} struct_T_cmdvel2gazebo_aq_T;

#endif                                 //typedef_struct_T_cmdvel2gazebo_aq_T

#ifndef typedef_struct_T_cmdvel2gazebo_aqh_T
#define typedef_struct_T_cmdvel2gazebo_aqh_T

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_cmdvel2gazebo_aqh_T;

#endif                                 //typedef_struct_T_cmdvel2gazebo_aqh_T

// Parameters (auto storage)
typedef struct P_cmdvel2gazebo_T_ P_cmdvel2gazebo_T;

// Forward declaration for rtModel
typedef struct tag_RTM_cmdvel2gazebo_T RT_MODEL_cmdvel2gazebo_T;

#endif                                 // RTW_HEADER_cmdvel2gazebo_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
