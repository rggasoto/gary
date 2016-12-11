#!/usr/bin/env python
import rospy
import tf
from nav_msgs.msg import MapMetaData
def imageCallback(msg):
    mapResolution = msg.resolution
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
                     "image",
                     "map")

if __name__ == '__main__':
    rospy.init_node('map2ImageBroadcaster')
    rate = rospy.Rate(10.0)
    listener.waitForTransform("/map", "/azcar_sim/odom", rospy.Time(), rospy.Duration(0.1))
    while not rospy.is_shutdown():
        try:
            imageSub = rospy.Subscriber("/map_metadata", MapMetaData, imageCallback)
        except (tf.Exception, tf.LookupException, tf.ConnectivityException):
            continue

        rate.sleep()