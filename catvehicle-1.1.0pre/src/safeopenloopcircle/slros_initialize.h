#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block safeOpenLoopCircle/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist> Sub_safeOpenLoopCircle_3;

// For Block safeOpenLoopCircle/Subscribe1
extern SimulinkSubscriber<geometry_msgs::Wrench, SL_Bus_safeOpenLoopCircle_geometry_msgs_Wrench> Sub_safeOpenLoopCircle_4;

// For Block safeOpenLoopCircle/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist> Pub_safeOpenLoopCircle_9;

void slros_node_init(int argc, char** argv);

#endif
