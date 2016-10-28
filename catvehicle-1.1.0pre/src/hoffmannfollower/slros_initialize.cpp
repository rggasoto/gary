#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "hoffmannFollower";

// For Block hoffmannFollower/Subscribe3
SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_hoffmannFollower_nav_msgs_Odometry> Sub_hoffmannFollower_13;

// For Block hoffmannFollower/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_hoffmannFollower_geometry_msgs_Twist> Pub_hoffmannFollower_9;

// For Block hoffmannFollower/Publish1
SimulinkPublisher<visualization_msgs::InteractiveMarkerPose, SL_Bus_hoffmannFollower_InteractiveMarkerPose_bqmzo4> Pub_hoffmannFollower_68;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

