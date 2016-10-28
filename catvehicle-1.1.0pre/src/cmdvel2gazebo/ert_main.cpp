//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
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
#include <stdio.h>
#include <stdlib.h>
#include "cmdvel2gazebo.h"
#include "cmdvel2gazebo_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "linuxinitialize.h"

// Function prototype declaration
void exitTask(int sig);
void terminateTask(void *arg);
void baseRateTask(void *arg);
void subrateTask(void *arg);
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
void baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(cmdvel2gazebo_M) == (NULL)) &&
    !rtmGetStopRequested(cmdvel2gazebo_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);
    cmdvel2gazebo_step();

    // Get model outputs here
    runModel = (rtmGetErrorStatus(cmdvel2gazebo_M) == (NULL)) &&
      !rtmGetStopRequested(cmdvel2gazebo_M);
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
}

void exitTask(int sig)
{
  rtmSetErrorStatus(cmdvel2gazebo_M, "stopping the model");
}

void terminateTask(void *arg)
{
  terminatingmodel = 1;
  printf("**terminating the model**\n");
  fflush(stdout);

  {
    int ret;
    runModel = 0;
  }

  // Disable rt_OneStep() here

  // Terminate model
  cmdvel2gazebo_terminate();
  sem_post(&stopSem);
}

int main(int argc, char **argv)
{
  void slros_node_init(int argc, char** argv);
  slros_node_init(argc, argv);
  printf("**starting the model**\n");
  fflush(stdout);
  rtmSetErrorStatus(cmdvel2gazebo_M, 0);

  // Initialize model
  cmdvel2gazebo_initialize();

//  myRTOSInit(0.02, 0);
  myRTOSInit(0.2, 0);

  // Wait for stop semaphore
  sem_wait(&stopSem);
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
