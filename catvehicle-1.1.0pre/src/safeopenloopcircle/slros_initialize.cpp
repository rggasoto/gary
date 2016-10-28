#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "safeOpenLoopCircle";

// For Block safeOpenLoopCircle/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist> Sub_safeOpenLoopCircle_3;

// For Block safeOpenLoopCircle/Subscribe1
SimulinkSubscriber<geometry_msgs::Wrench, SL_Bus_safeOpenLoopCircle_geometry_msgs_Wrench> Sub_safeOpenLoopCircle_4;

// For Block safeOpenLoopCircle/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_safeOpenLoopCircle_geometry_msgs_Twist> Pub_safeOpenLoopCircle_9;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

