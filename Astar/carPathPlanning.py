import numpy as np
import scipy.misc
from astar import *
from PIL import Image, ImageDraw
from math import *
#define car transform

def scale(xy):
    return xy*20 #each pixel is 1/4 of a meter

carSize = scale(np.array([2,5])) # Car is 2x5 meters in average
road = scipy.misc.imread("path2.png",flatten=True)
road = (road > 0).astype(int)#treshold path

start = state(2.5,2.75,pi/2-pi/12,0)
goal = state(92.5,93.5,pi,0)


def getCarShape(carPos):
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
def matrix2Tuples(matrix):
    tuples = []
    for i in range(matrix.shape[1]):
        tuples.append(tuple(matrix[:,i]))
    return tuples


def collisionCheck(state):
    carShape = getCarShape(state)
    for i in range(carShape.shape[1]):
        # print carShape[1,i],carShape[0,i],
        if int(carShape[1,i]) >= road.shape[1] or int(carShape[0,i]) >= road.shape[0]:
            return True

        if road[int(carShape[1,i]),int(carShape[0,i])] == 0:
            return True
    return False

#Get road that was generated
im = Image.open("path.png").convert('RGB')
draw = ImageDraw.Draw(im,'RGBA')
TP = tuple(scale(np.array(([goal.x,goal.y]))))
# draw.point(TP,fill =(255,0,0))
draw.polygon(matrix2Tuples(getCarShape(start)),fill=(255,0,0))
print collisionCheck(goal)
print collisionCheck(start)

# stepsize,heuristics,v, collisionCheck,maxBranch,steeringSpeed,steeringLimit,L)
finder = Astar(0.4,"euclidean",3,collisionCheck,5,radians(70),radians(35),4.5)
path = finder.search(start,goal);

for i in finder.c_visited:
    draw.polygon(matrix2Tuples(getCarShape(i)),fill=(0,0,0,0),outline = (0,0,255,150))

if path:
    rgb = np.zeros((4,len(path)),dtype = np.int)
    rgb[0,:] = np.linspace(255,0,num=len(path))
    rgb[1,:] = np.linspace(0,255,num=len(path))
    rgb[3,:] = np.ones((1,len(path)))*70
    # print rgb
    print path[0]
    for i in range(1,len(path)):
        print path[i]
        draw.line(scale(np.array([path[i-1].x,path[i-1].y,path[i].x,path[i].y])).tolist(),fill=(0,0,255))
        draw.polygon(matrix2Tuples(getCarShape(path[i-1])),fill=(rgb[0,i-1],rgb[1,i-1],rgb[2,i-1],rgb[3,i-1]))
    draw.polygon(matrix2Tuples(getCarShape(path[i])),fill=(rgb[0,i],rgb[1,i],rgb[2,i],255))

del draw

im.save("draw.png","PNG")
