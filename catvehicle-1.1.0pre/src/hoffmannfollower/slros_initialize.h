#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block hoffmannFollower/Subscribe3
extern SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_hoffmannFollower_nav_msgs_Odometry> Sub_hoffmannFollower_13;

// For Block hoffmannFollower/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_hoffmannFollower_geometry_msgs_Twist> Pub_hoffmannFollower_9;

// For Block hoffmannFollower/Publish1
extern SimulinkPublisher<visualization_msgs::InteractiveMarkerPose, SL_Bus_hoffmannFollower_InteractiveMarkerPose_bqmzo4> Pub_hoffmannFollower_68;

void slros_node_init(int argc, char** argv);

#endif
