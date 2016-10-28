//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: safeOpenLoopCircle.cpp
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
#include "safeOpenLoopCircle.h"
#include "safeOpenLoopCircle_private.h"

// Named constants for Chart: '<Root>/Chart'
#define safeOpenLoopCircl_IN_Increasing ((uint8_T)1U)
#define safeOpenLoopCircle_IN_Stopping ((uint8_T)2U)
#define safeOpenLoop_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define safeOpenLoopCir_MessageQueueLen (1)

// Block signals (auto storage)
B_safeOpenLoopCircle_T safeOpenLoopCircle_B;

// Block states (auto storage)
DW_safeOpenLoopCircle_T safeOpenLoopCircle_DW;

// Real-time model
RT_MODEL_safeOpenLoopCircle_T safeOpenLoopCircle_M_;
RT_MODEL_safeOpenLoopCircle_T *const safeOpenLoopCircle_M =
  &safeOpenLoopCircle_M_;

// Model step function
void safeOpenLoopCircle_step(void)
{
  boolean_T varargout_1;
  SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist rtb_BusAssignment;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S6>/In1'
  //   MATLABSystem: '<S4>/SourceBlock'

  varargout_1 = Sub_safeOpenLoopCircle_3.getLatestMessage(&rtb_BusAssignment);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (varargout_1) {
    safeOpenLoopCircle_B.In1 = rtb_BusAssignment;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   MATLABSystem: '<S5>/SourceBlock'

  Sub_safeOpenLoopCircle_4.getLatestMessage(&safeOpenLoopCircle_B.varargout_2);

  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // Chart: '<Root>/Chart'
  // Gateway: Chart
  // During: Chart
  if (safeOpenLoopCircle_DW.is_active_c3_safeOpenLoopCircle == 0U) {
    // Entry: Chart
    safeOpenLoopCircle_DW.is_active_c3_safeOpenLoopCircle = 1U;

    // Entry Internal: Chart
    // Transition: '<S2>:4'
    safeOpenLoopCircle_DW.is_c3_safeOpenLoopCircle =
      safeOpenLoopCircl_IN_Increasing;

    // Entry 'Increasing': '<S2>:3'
    // '<S2>:3:1' vOut=0;
    safeOpenLoopCircle_B.vOut = 0.0;
  } else if (safeOpenLoopCircle_DW.is_c3_safeOpenLoopCircle ==
             safeOpenLoopCircl_IN_Increasing) {
    // During 'Increasing': '<S2>:3'
    // '<S2>:6:1' sf_internal_predicateOutput = ...
    // '<S2>:6:1' velocity >= 4.0;
    if (safeOpenLoopCircle_B.In1.Linear.X >= 4.0) {
      // Transition: '<S2>:6'
      safeOpenLoopCircle_DW.is_c3_safeOpenLoopCircle =
        safeOpenLoopCircle_IN_Stopping;

      // Entry 'Stopping': '<S2>:5'
    } else {
      // '<S2>:3:1' vOut = min(vOut + 0.1,4.1);
      if (safeOpenLoopCircle_B.vOut + 0.1 <= 4.1) {
        safeOpenLoopCircle_B.vOut += 0.1;
      } else {
        safeOpenLoopCircle_B.vOut = 4.1;
      }

      // '<S2>:3:2' steeringOut = 0.1;
      safeOpenLoopCircle_B.steeringOut = 0.1;
    }
  } else {
    // During 'Stopping': '<S2>:5'
    // '<S2>:8:1' sf_internal_predicateOutput = ...
    // '<S2>:8:1' velocity <= 0.1;
    if (safeOpenLoopCircle_B.In1.Linear.X <= 0.1) {
      // Transition: '<S2>:8'
      safeOpenLoopCircle_DW.is_c3_safeOpenLoopCircle =
        safeOpenLoopCircl_IN_Increasing;

      // Entry 'Increasing': '<S2>:3'
      // '<S2>:3:1' vOut=0;
      safeOpenLoopCircle_B.vOut = 0.0;
    } else {
      // '<S2>:5:1' vOut = max(vOut - 0.1,0);
      if (safeOpenLoopCircle_B.vOut - 0.1 >= 0.0) {
        safeOpenLoopCircle_B.vOut -= 0.1;
      } else {
        safeOpenLoopCircle_B.vOut = 0.0;
      }

      // '<S2>:5:1' steeringOut = 0.1;
      safeOpenLoopCircle_B.steeringOut = 0.1;
    }
  }

  // End of Chart: '<Root>/Chart'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'

  rtb_BusAssignment = safeOpenLoopCircle_P.Constant_Value_a;
  rtb_BusAssignment.Linear.X = safeOpenLoopCircle_B.vOut;
  rtb_BusAssignment.Angular.Z = safeOpenLoopCircle_B.steeringOut;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S3>/SinkBlock' incorporates:
  //   MATLABSystem: '<S3>/SinkBlock'

  Pub_safeOpenLoopCircle_9.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
}

// Model initialize function
void safeOpenLoopCircle_initialize(void)
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus(safeOpenLoopCircle_M, (NULL));

  // block I/O
  (void) memset(((void *) &safeOpenLoopCircle_B), 0,
                sizeof(B_safeOpenLoopCircle_T));

  // states (dwork)
  (void) memset((void *)&safeOpenLoopCircle_DW, 0,
                sizeof(DW_safeOpenLoopCircle_T));

  {
    static const char_T tmp[18] = { '/', 'a', 'z', 'c', 'a', 'r', '_', 's', 'i',
      'm', '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_0[19] = { '/', 'a', 'z', 'c', 'a', 'r', '_', 's',
      'i', 'm', '/', 's', 't', 'e', 'e', 'r', 'i', 'n', 'g' };

    static const char_T tmp_1[14] = { '/', 'a', 'z', 'c', 'a', 'r', '_', 's',
      'i', 'm', '/', 'v', 'e', 'l' };

    char_T tmp_2[19];
    char_T tmp_3[20];
    char_T tmp_4[15];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    safeOpenLoopCircle_DW.obj_d.isInitialized = 0;
    safeOpenLoopCircle_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      tmp_4[i] = tmp_1[i];
    }

    tmp_4[14] = '\x00';
    Sub_safeOpenLoopCircle_3.createSubscriber(tmp_4,
      safeOpenLoopCir_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    safeOpenLoopCircle_DW.obj_m.isInitialized = 0;
    safeOpenLoopCircle_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 19; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[19] = '\x00';
    Sub_safeOpenLoopCircle_4.createSubscriber(tmp_3,
      safeOpenLoopCir_MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe1'

    // Start for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    safeOpenLoopCircle_DW.obj.isInitialized = 0;
    safeOpenLoopCircle_DW.obj.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      tmp_2[i] = tmp[i];
    }

    tmp_2[18] = '\x00';
    Pub_safeOpenLoopCircle_9.createPublisher(tmp_2,
      safeOpenLoopCir_MessageQueueLen);

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S6>/Out1'
    safeOpenLoopCircle_B.In1 = safeOpenLoopCircle_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Chart: '<Root>/Chart'
    safeOpenLoopCircle_DW.is_active_c3_safeOpenLoopCircle = 0U;
    safeOpenLoopCircle_DW.is_c3_safeOpenLoopCircle =
      safeOpenLoop_IN_NO_ACTIVE_CHILD;
  }
}

// Model terminate function
void safeOpenLoopCircle_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S4>/SourceBlock'

  if (safeOpenLoopCircle_DW.obj_d.isInitialized == 1) {
    safeOpenLoopCircle_DW.obj_d.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S5>/SourceBlock'

  if (safeOpenLoopCircle_DW.obj_m.isInitialized == 1) {
    safeOpenLoopCircle_DW.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S3>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SinkBlock'

  if (safeOpenLoopCircle_DW.obj.isInitialized == 1) {
    safeOpenLoopCircle_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
