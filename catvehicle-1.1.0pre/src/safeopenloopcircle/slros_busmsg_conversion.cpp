#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist and geometry_msgs::Twist

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertFromBus(&msgPtr->angular, &busPtr->Angular);
  convertFromBus(&msgPtr->linear, &busPtr->Linear);
}

void convertToBus(SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertToBus(&busPtr->Angular, &msgPtr->angular);
  convertToBus(&busPtr->Linear, &msgPtr->linear);
}


// Conversions between SL_Bus_safeOpenLoopCircle_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_safeOpenLoopCircle_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_safeOpenLoopCircle_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_safeOpenLoopCircle_geometry_msgs_Wrench and geometry_msgs::Wrench

void convertFromBus(geometry_msgs::Wrench* msgPtr, SL_Bus_safeOpenLoopCircle_geometry_msgs_Wrench const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Wrench");

  convertFromBus(&msgPtr->force, &busPtr->Force);
  convertFromBus(&msgPtr->torque, &busPtr->Torque);
}

void convertToBus(SL_Bus_safeOpenLoopCircle_geometry_msgs_Wrench* busPtr, geometry_msgs::Wrench const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Wrench");

  convertToBus(&busPtr->Force, &msgPtr->force);
  convertToBus(&busPtr->Torque, &msgPtr->torque);
}

