#!/usr/bin/env python
import numpy as np
import numpy.linalg
import scipy.misc
import os
from astar import *
from PIL import Image, ImageDraw
from math import *
import rospy
import math
from tf.transformations import euler_from_quaternion

from nav_msgs.msg import OccupancyGrid
from nav_msgs.msg import MapMetaData
from nav_msgs.msg import GridCells
from geometry_msgs.msg import Twist
from geometry_msgs.msg import Point
from std_msgs.msg import Float64
from geometry_msgs.msg import PoseWithCovarianceStamped
from geometry_msgs.msg import PoseStamped
#define car transform

def scale(xy):
    global mapResolution
    #meters to pixels
    return xy/mapResolution

def getCarShape(carPos):
    global carSize
    pixelxy = scale(np.array([carPos.x,carPos.y]));
    carRect1 =  - carSize/2
    carRect3 =  + carSize/2
    carRect2 = np.array([carRect3[0],carRect1[1]])
    carRect4 = np.array([carRect1[0],carRect3[1]])
    cr = np.matrix([carRect1,carRect2,carRect3,carRect4])
    carRect = rotate(cr.T,carPos.theta)
    for i in range(carRect.shape[1]):
        carRect[0,i] += pixelxy[0]
        carRect[1,i] += pixelxy[1]
    return carRect

def rotate(points,theta):
    s = sin(theta)
    c = cos(theta)
    R = np.matrix([[c, -s],[s, c]]);
    rPoints = R*points
    # for i in range(points.shape[1]):
    #     rPoints[0,i] = (c * (points[0,i]) - s * (points[1,i]))
    #     rPoints[1,i] = (s * (points[0,i]) + c * (points[1,i]))
    #     print [points[0,i],rPoints[0,i]]
    #     print [points[1,i],rPoints[1,i]]
    #     print '\n'
    return rPoints

def mapToImage(points):
    global mapResolution
    # Note: this only works with rectangular images!
    #rotate 180 about x axis
    # then shift by offset from road shape information
    roadShape = road.shape
    #extract
    delY = roadShape[1]*mapResolution
    print delY
    R = np.matrix([[1,0,0,0],[0, -1, 0,delY],[0, 0, -1,0],[0,0,0,1]]);
    rPoints = R*points
    return rPoints



def matrix2Tuples(matrix):
    tuples = []
    for i in range(matrix.shape[1]):
        tuples.append(tuple(matrix[:,i]))
    return tuples

def collisionCheck(state):
    global road
    carShape = getCarShape(state)
    for i in range(carShape.shape[1]):
        print carShape[1,i],carShape[0,i]
        if int(carShape[1,i]) >= road.shape[1] or int(carShape[0,i]) >= road.shape[0]:
            return True

        if road[int(carShape[1,i]),int(carShape[0,i])] == 0:
            return True
    return False

def readGoal(goalPos):
    #PoseStamped
    global goal
    x = goalPos.pose.position.x
    y = goalPos.pose.position.y
    quat = goalPos.pose.orientation
    q = [quat.x, quat.y, quat.z, quat.w]
    roll, pitch, yaw = euler_from_quaternion(q)
    points = np.matrix([x,y,0,1])
    goalCoord = mapToImage(points.transpose())
    goal = state(goalCoord.item(0),goalCoord.item(1),-yaw+pi/2,0)
    print goal.x
    print goal.y
    print goal.theta
    print goal.phi

def readStart(startPos):
    #PoseWithCovarianceStamped
    global start
    x = startPos.pose.pose.position.x
    y = startPos.pose.pose.position.y
    quat = startPos.pose.pose.orientation
    q = [quat.x, quat.y, quat.z, quat.w]
    roll, pitch, yaw = euler_from_quaternion(q)
    points = np.matrix([x,y,0,1])
    startCoord = mapToImage(points.transpose())
    start = state(startCoord.item(0),startCoord.item(1),-yaw+pi/2,0)
    #start = state(startCoord)
    print start.x
    print start.y
    print start.theta
    print start.phi

def mapCallBack(map):
    pass

def mapMetaCallback(metaData):
    global mapResolution, road, imgpath
    mapResolution = metaData.resolution
    print "map resolution is ", mapResolution, "m/pix"
    # retrieve current working directory
    currDir = os.path.dirname(os.path.realpath(__file__))
    parDir = os.path.abspath(os.path.join(currDir, os.pardir))
    imgpath = parDir + "/maps/shapes.pgm"
    road = scipy.misc.imread(imgpath, flatten=True)
    print "road size is : ", road.size, " and shape is", road.shape
    road = (road == 0).astype(int)  # threshold path
    rospy.sleep(5)

def planPath():
    global carSize, road,impath
    carSize = scale(np.array([2, 5]))  # Car is 2x5 meters in average
    #Get road that was generated
    im = Image.open(imgpath).convert('RGB')
    draw = ImageDraw.Draw(im,'RGBA')
    TP = tuple(scale(np.array(([goal.x,goal.y]))))
    # draw.point(TP,fill =(255,0,0))

    print collisionCheck(goal)
    print collisionCheck(start)

    # stepsize,heuristics,v, collisionCheck,maxBranch,steeringSpeed,steeringLimit,L)
    finder = Astar(.5,"euclidean",5,collisionCheck,5,radians(70),radians(35),4.5)
    path = finder.search(start,goal);

    for i in finder.c_visited:
        draw.polygon(matrix2Tuples(getCarShape(i)),fill=(0,255,255,30),outline = (255,0,0,150))
    draw.polygon(matrix2Tuples(getCarShape(start)),fill=(255,0,0))

    if path:
        print "path data type is: ", type(path)
        rgb = np.zeros((4,len(path)),dtype = np.int)
        rgb[0,:] = np.linspace(255,0,num=len(path))
        rgb[1,:] = np.linspace(0,255,num=len(path))
        rgb[3,:] = np.ones((1,len(path)))*255
        # print rgb
        print path[0]
        for i in range(1,len(path)):
            print path[i]
            draw.line(scale(np.array([path[i-1].x,path[i-1].y,path[i].x,path[i].y])).tolist(),fill=(0,0,255))
            draw.polygon(matrix2Tuples(getCarShape(path[i-1])),fill=(rgb[0,i-1],rgb[1,i-1],rgb[2,i-1],rgb[3,i-1]))
        draw.polygon(matrix2Tuples(getCarShape(path[i])),fill=(rgb[0,i],rgb[1,i],rgb[2,i],255))

    del draw
    im.save("draw3.png","PNG")

#Main handler of the project
def run():
    global pub
    global carSize, road
    global start, goal,mapResolution,impath
    start = None
    goal = None

    rospy.init_node('carPathPlanning')

    sub = rospy.Subscriber("/map_metadata", MapMetaData, mapMetaCallback)
    sub = rospy.Subscriber("/map", OccupancyGrid, mapCallBack)
    pub = rospy.Publisher("/map_check", GridCells, queue_size=1)
    pubpath = rospy.Publisher("/path", GridCells, queue_size=1) # you can use other types if desired
    pubway = rospy.Publisher("/waypoints", GridCells, queue_size=1)
    goal_sub = rospy.Subscriber('move_base_simple/goal', PoseStamped, readGoal, queue_size=1) #change topic for best results
    goal_sub = rospy.Subscriber('initialpose', PoseWithCovarianceStamped, readStart, queue_size=1) #change topic for best results

    # wait a second for publisher, subscribers, and TF
    rospy.sleep(1)

    while (1 and not rospy.is_shutdown()):
        #publishCells(mapData) #publishing map data every 2 seconds
        print("waiting")
        rospy.sleep(1)
        if start != None and goal != None:
            pass
            planPath()
            print("Complete")
            return



if __name__ == '__main__':
    try:
        run()
    except rospy.ROSInterruptException:
        pass
