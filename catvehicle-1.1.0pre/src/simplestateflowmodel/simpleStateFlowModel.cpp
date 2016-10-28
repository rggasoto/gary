//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: simpleStateFlowModel.cpp
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
#include "simpleStateFlowModel.h"
#include "simpleStateFlowModel_private.h"

// Named constants for Chart: '<Root>/Chart'
#define simpleStateF_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define simpleStateFlowMo_IN_Increasing ((uint8_T)1U)
#define simpleStateFlowMode_IN_Stopping ((uint8_T)2U)
#define simpleStateFlow_MessageQueueLen (1)

// Block signals (auto storage)
B_simpleStateFlowModel_T simpleStateFlowModel_B;

// Block states (auto storage)
DW_simpleStateFlowModel_T simpleStateFlowModel_DW;

// Real-time model
RT_MODEL_simpleStateFlowModel_T simpleStateFlowModel_M_;
RT_MODEL_simpleStateFlowModel_T *const simpleStateFlowModel_M =
  &simpleStateFlowModel_M_;

// Model step function
void simpleStateFlowModel_step(void)
{
  boolean_T varargout_1;
  SL_Bus_simpleStateFlowModel_geometry_msgs_Twist rtb_BusAssignment;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S6>/In1'
  //   MATLABSystem: '<S4>/SourceBlock'

  varargout_1 = Sub_simpleStateFlowModel_3.getLatestMessage(&rtb_BusAssignment);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (varargout_1) {
    simpleStateFlowModel_B.In1 = rtb_BusAssignment;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Chart: '<Root>/Chart'
  // Gateway: Chart
  // During: Chart
  if (simpleStateFlowModel_DW.is_active_c3_simpleStateFlowMod == 0U) {
    // Entry: Chart
    simpleStateFlowModel_DW.is_active_c3_simpleStateFlowMod = 1U;

    // Entry Internal: Chart
    // Transition: '<S2>:4'
    simpleStateFlowModel_DW.is_c3_simpleStateFlowModel =
      simpleStateFlowMo_IN_Increasing;

    // Entry 'Increasing': '<S2>:3'
    // '<S2>:3:1' vOut=0
    simpleStateFlowModel_B.vOut = 0.0;
  } else if (simpleStateFlowModel_DW.is_c3_simpleStateFlowModel ==
             simpleStateFlowMo_IN_Increasing) {
    // During 'Increasing': '<S2>:3'
    // '<S2>:6:1' sf_internal_predicateOutput = ...
    // '<S2>:6:1' velocity >= 5;
    if (simpleStateFlowModel_B.In1.Linear.X >= 5.0) {
      // Transition: '<S2>:6'
      simpleStateFlowModel_DW.is_c3_simpleStateFlowModel =
        simpleStateFlowMode_IN_Stopping;

      // Entry 'Stopping': '<S2>:5'
    } else {
      // '<S2>:3:1' vOut = vOut + 0.1;
      simpleStateFlowModel_B.vOut += 0.1;
    }
  } else {
    // During 'Stopping': '<S2>:5'
    // '<S2>:5:1' vOut = 0;
    simpleStateFlowModel_B.vOut = 0.0;
  }

  // End of Chart: '<Root>/Chart'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S7>/In1'
  //   MATLABSystem: '<S5>/SourceBlock'

  varargout_1 = Sub_simpleStateFlowModel_4.getLatestMessage
    (&simpleStateFlowModel_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  if (varargout_1) {
    simpleStateFlowModel_B.In1_c = simpleStateFlowModel_B.varargout_2;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'

  rtb_BusAssignment = simpleStateFlowModel_P.Constant_Value_a;
  rtb_BusAssignment.Linear.X = simpleStateFlowModel_B.vOut;
  rtb_BusAssignment.Angular.Z = simpleStateFlowModel_B.In1_c.Torque.Z;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S3>/SinkBlock' incorporates:
  //   MATLABSystem: '<S3>/SinkBlock'

  Pub_simpleStateFlowModel_9.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
}

// Model initialize function
void simpleStateFlowModel_initialize(void)
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus(simpleStateFlowModel_M, (NULL));

  // block I/O
  (void) memset(((void *) &simpleStateFlowModel_B), 0,
                sizeof(B_simpleStateFlowModel_T));

  // states (dwork)
  (void) memset((void *)&simpleStateFlowModel_DW, 0,
                sizeof(DW_simpleStateFlowModel_T));

  {
    static const char_T tmp[21] = { '/', 'f', 'o', 'l', 'l', 'o', 'w', 'e', 'r',
      '_', 's', 'i', 'm', '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_0[22] = { '/', 'f', 'o', 'l', 'l', 'o', 'w', 'e',
      'r', '_', 's', 'i', 'm', '/', 's', 't', 'e', 'e', 'r', 'i', 'n', 'g' };

    static const char_T tmp_1[17] = { '/', 'f', 'o', 'l', 'l', 'o', 'w', 'e',
      'r', '_', 's', 'i', 'm', '/', 'v', 'e', 'l' };

    char_T tmp_2[22];
    char_T tmp_3[18];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    simpleStateFlowModel_DW.obj_d.isInitialized = 0;
    simpleStateFlowModel_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      tmp_3[i] = tmp_1[i];
    }

    tmp_3[17] = '\x00';
    Sub_simpleStateFlowModel_3.createSubscriber(tmp_3,
      simpleStateFlow_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    simpleStateFlowModel_DW.obj_m.isInitialized = 0;
    simpleStateFlowModel_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 22; i++) {
      simpleStateFlowModel_B.cv0[i] = tmp_0[i];
    }

    simpleStateFlowModel_B.cv0[22] = '\x00';
    Sub_simpleStateFlowModel_4.createSubscriber(simpleStateFlowModel_B.cv0,
      simpleStateFlow_MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe1'

    // Start for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    simpleStateFlowModel_DW.obj.isInitialized = 0;
    simpleStateFlowModel_DW.obj.isInitialized = 1;
    for (i = 0; i < 21; i++) {
      tmp_2[i] = tmp[i];
    }

    tmp_2[21] = '\x00';
    Pub_simpleStateFlowModel_9.createPublisher(tmp_2,
      simpleStateFlow_MessageQueueLen);

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S6>/Out1'
    simpleStateFlowModel_B.In1 = simpleStateFlowModel_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Chart: '<Root>/Chart'
    simpleStateFlowModel_DW.is_active_c3_simpleStateFlowMod = 0U;
    simpleStateFlowModel_DW.is_c3_simpleStateFlowModel =
      simpleStateF_IN_NO_ACTIVE_CHILD;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S7>/Out1'
    simpleStateFlowModel_B.In1_c = simpleStateFlowModel_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'
  }
}

// Model terminate function
void simpleStateFlowModel_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S4>/SourceBlock'

  if (simpleStateFlowModel_DW.obj_d.isInitialized == 1) {
    simpleStateFlowModel_DW.obj_d.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S5>/SourceBlock'

  if (simpleStateFlowModel_DW.obj_m.isInitialized == 1) {
    simpleStateFlowModel_DW.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S3>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SinkBlock'

  if (simpleStateFlowModel_DW.obj.isInitialized == 1) {
    simpleStateFlowModel_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
