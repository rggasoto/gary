#!/usr/bin/env python
import rospy
import tf
from nav_msgs.msg import MapMetaData
def mapMetaCallback(msg):
    br = tf.TransformBroadcaster()
    xO = msg.origin.position.x
    yO = msg.origin.position.y
    xq = msg.origin.orientation.x
    yq = msg.origin.orientation.y
    zq = msg.origin.orientation.z
    wq = msg.origin.orientation.w
    br.sendTransform((xO, yO, 0),
                     (xq,yq,zq,wq),
                     rospy.Time.now(),
                     "map",
                     "azcar_sim/odom")

if __name__ == '__main__':
    rospy.init_node('base2MapBroadcaster')
    rate = rospy.Rate(10.0)
    while not rospy.is_shutdown():
        mapSub = rospy.Subscriber("/map_metadata", MapMetaData, mapMetaCallback)
        rate.sleep()