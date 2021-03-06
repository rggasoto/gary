#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Wrench.h>
#include "safeOpenLoopCircle_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist const* busPtr);
void convertToBus(SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr);

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_safeOpenLoopCircle_geometry_msgs_Vector3 const* busPtr);
void convertToBus(SL_Bus_safeOpenLoopCircle_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convertFromBus(geometry_msgs::Wrench* msgPtr, SL_Bus_safeOpenLoopCircle_geometry_msgs_Wrench const* busPtr);
void convertToBus(SL_Bus_safeOpenLoopCircle_geometry_msgs_Wrench* busPtr, geometry_msgs::Wrench const* msgPtr);


#endif
