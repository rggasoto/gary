import numpy as np
import numpy.linalg
import scipy.misc
from astar import *
from PIL import Image, ImageDraw
from math import *
#define car transform

def scale(xy):
	return xy*20 #each pixel is 1/4 of a meter
imgpath = "path2.png"
carSize = scale(np.array([2,5])) # Car is 2x5 meters in average
road = scipy.misc.imread(imgpath,flatten=True)
road = (road != 0).astype(int)#treshold path

start = state(2.5,3.75,pi/2,0)
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

def createLine(x1, y1, x2, y2):
	if x1 != x2:
		m = (y2 - y1)/ (x2 - x1)
		b = y2 - (m*x2)
		return (m, b)


def collisionCheck(state):
	carShape = getCarShape(state)
	for i in range(carShape.shape[1]):
		print(i)
		if int(carShape[1,i]) >= road.shape[1] or int(carShape[0,i]) >= road.shape[0]:
			return True

		if road[int(carShape[1,i]),int(carShape[0,i])] != 0:
			return True
		# Get the initial XY values of the car side
		x1 = carShape[:,i-1][0]
		y1 = carShape[:,i-1][1]
		# Get the final XY values of the car side
		x2 = carShape[:,i][0]
		y2 = carShape[:,i][1]
		#If the vehicle is not perfectly vertical then create a line equation between the car corner to represent the car side
		if int(x1) != int(x2):
			# Get the slope m and the y intercept b of the line
			m, b = createLine(x1,y1,x2,y2)
			# Interate X from the initial X0 to XF to create x axis values
			for x in np.linspace(float(x1), float(x2),1):
				# For every x between x1 and X2 return a y value
				y = (m*x) + b
				# Check to see if an obstacle is present on the road where our xy axis value.
				if road[int(x),int(y)] != 0:
					return True
		# Check for when the x1 = x2
		# This method is needed because the slope will be infinite (y2 - y1)/ (x2 - x1) => (y2 - y1)/0
		else:
			# Since X1 = X2 keep X1 constant. Then get the starting Y1 and ending Y2 values and interate over them to create a vertical line
			for y in np.linspace(float(y1), float(y2),1):
				if road[int(x1), int(y)] != 0:
					return True

	return False

#Get road that was generated
im = Image.open(imgpath).convert('RGB')
draw = ImageDraw.Draw(im,'RGBA')
TP = tuple(scale(np.array(([goal.x,goal.y]))))
# draw.point(TP,fill =(255,0,0))
#print collisionCheck(goal)
#print collisionCheck(start)

# stepsize,heuristics,v, collisionCheck,maxBranch,steeringSpeed,steeringLimit,L)
finder = Astar(.5,"euclidean",5,collisionCheck,5,radians(70),radians(35),4.5)
path = finder.search(start,goal);

for i in finder.c_visited:
	draw.polygon(matrix2Tuples(getCarShape(i)),fill=(0,255,255,30),outline = (255,0,0,150))
draw.polygon(matrix2Tuples(getCarShape(start)),fill=(255,0,0))

if path:
	rgb = np.zeros((4,len(path)),dtype = np.int)
	rgb[0,:] = np.linspace(255,0,num=len(path))
	rgb[1,:] = np.linspace(0,255,num=len(path))
	rgb[3,:] = np.ones((1,len(path)))*255
	# print rgb
	#print path[0]
	for i in range(1,len(path)):
		#print path[i]
		draw.line(scale(np.array([path[i-1].x,path[i-1].y,path[i].x,path[i].y])).tolist(),fill=(0,0,255))
		draw.polygon(matrix2Tuples(getCarShape(path[i-1])),fill=(rgb[0,i-1],rgb[1,i-1],rgb[2,i-1],rgb[3,i-1]))
	draw.polygon(matrix2Tuples(getCarShape(path[i])),fill=(rgb[0,i],rgb[1,i],rgb[2,i],255))

del draw

im.save("draw3.png","PNG")
