#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block simpleStateFlowModel/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_simpleStateFlowModel_geometry_msgs_Twist> Sub_simpleStateFlowModel_3;

// For Block simpleStateFlowModel/Subscribe1
extern SimulinkSubscriber<geometry_msgs::Wrench, SL_Bus_simpleStateFlowModel_geometry_msgs_Wrench> Sub_simpleStateFlowModel_4;

// For Block simpleStateFlowModel/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_simpleStateFlowModel_geometry_msgs_Twist> Pub_simpleStateFlowModel_9;

void slros_node_init(int argc, char** argv);

#endif
