/* Author: Rahul Kumar Bhadani
 * This code implements first order follower algorithm for follower vehicle
 * V_follower = (Distance*1/30 + 2/3)*V_leader
*/

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"

#include <cstdio>
#include <cstdlib>


// this global var holds the distance
geometry_msgs::Twist leader_vel;
geometry_msgs::Twist follower_vel;
nav_msgs::Odometry leader_odom;
nav_msgs::Odometry follower_odom;

ros::Time lastUpdate;
bool newMessage;


void leaderVelCallback(const geometry_msgs::Twist::ConstPtr& leaderVelPtr )
{
    leader_vel.linear.x = leaderVelPtr->linear.x;
    leader_vel.linear.y = leaderVelPtr->linear.y;
    leader_vel.linear.z = leaderVelPtr->linear.z;
    leader_vel.angular.x = leaderVelPtr->angular.x;
    leader_vel.angular.y = leaderVelPtr->angular.y;
    leader_vel.angular.z = leaderVelPtr->angular.z;


    
//    ROS_INFO("leader vel %f",leader_vel.linear.x);
    newMessage = true;
    /*leader_vel = *leaderVelPtr;*/
}

void leaderOdomCallback(const nav_msgs::Odometry::ConstPtr& leaderOdomPtr )
{
    newMessage = true;
    leader_odom.pose.pose.position.x = leaderOdomPtr->pose.pose.position.x;
    leader_odom.pose.pose.position.y = leaderOdomPtr->pose.pose.position.y;
    leader_odom.pose.pose.position.z = leaderOdomPtr->pose.pose.position.z;
//    ROS_INFO("leader odom %f", leader_odom.pose.pose.position.x);


}

void followerOdomCallback(const nav_msgs::Odometry::ConstPtr& followerOdomPtr )
{
    newMessage = true;
    /*follower_odom = followerOdomPtr;*/
    follower_odom.pose.pose.position.x = followerOdomPtr->pose.pose.position.x;
    follower_odom.pose.pose.position.y = followerOdomPtr->pose.pose.position.y;
    follower_odom.pose.pose.position.z = followerOdomPtr->pose.pose.position.z;
  //  ROS_INFO("follower odom %f", follower_odom.pose.pose.position.x);
}

int main( int argc, char **argv )
{
	ros::init(argc, argv, "firstOrderController");

	ros::NodeHandle n;
	//ros::NodeHandle n("~");
    std::string leader_vel_topic="/azcar_sim/vel";
    std::string leader_odom_topic="/azcar_sim/odom";
    std::string follower_odom_topic="/follower_sim/odom";
    std::string follower_InputVel_topic="/follower_sim/cmd_vel";
    double lX, lY, fX, fY, dX, dY;

   // ROS_INFO("firstOrder Controller");


  	ros::Subscriber sub_leader_vel = n.subscribe(leader_vel_topic, 10, &leaderVelCallback);
  	ros::Subscriber sub_leader_odom = n.subscribe(leader_odom_topic, 10, &leaderOdomCallback);
  	ros::Subscriber sub_follower_odom = n.subscribe(follower_odom_topic, 10, &followerOdomCallback);

    //ros::spin();
    ros::Publisher follower_vel_pub = n.advertise<geometry_msgs::Twist>(follower_InputVel_topic, 1);

    ros::Rate loop_rate(1000);
    newMessage = false;


	while( ros::ok() )
	{

        if( newMessage )
        {
            lX = leader_odom.pose.pose.position.x;
     //       ROS_INFO("want to publish follower vel ");
            lY = leader_odom.pose.pose.position.y;
            fX = follower_odom.pose.pose.position.x;
            fY = follower_odom.pose.pose.position.y;

            dX = lX - fX;
            dY = lY - fY;
    		follower_vel.linear.x = (sqrt(dX*dX + dY*dY)*(1.0/30.0) + (2.0/3.0))*leader_vel.linear.x;
            
       //     ROS_INFO("follower commanded vel %f", follower_vel.linear.x);
            follower_vel_pub.publish(follower_vel);
            newMessage = false;
        }
		ros::spinOnce( );
		loop_rate.sleep( );

	}

	return EXIT_SUCCESS;
}

