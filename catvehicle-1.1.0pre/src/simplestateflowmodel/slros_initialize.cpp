#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "simpleStateFlowModel";

// For Block simpleStateFlowModel/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_simpleStateFlowModel_geometry_msgs_Twist> Sub_simpleStateFlowModel_3;

// For Block simpleStateFlowModel/Subscribe1
SimulinkSubscriber<geometry_msgs::Wrench, SL_Bus_simpleStateFlowModel_geometry_msgs_Wrench> Sub_simpleStateFlowModel_4;

// For Block simpleStateFlowModel/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_simpleStateFlowModel_geometry_msgs_Twist> Pub_simpleStateFlowModel_9;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

