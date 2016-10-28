
# Release 1.1.0 (prerelease) (31 May 2016)

* Modifications to ensure license files throughout. 
* Improvements to launch files in order to ensure that they had default values. 
* Additional launch files to show the robot model when 
  visualizing in rosbag playback mode.

# Release 1.0.2 (23 May 2016)

## Updated nodes

### cmdvel2gazebo.py
Modified to utilize Ackermann's steering model, which dramatically reduces 
wheel slipping.

## New launch files

### azcar_slomo.launch
A modified version of azcar.launch which loads a gazebo world file called 
azcar_skidpan_slomo.world --- this file can be modified to run slower than real time.

The reason for this modified launch file is to preserve the nature of the existing
demos with the existing launch files.

### hectorslam.launch
Starts up the hectorslam node with default values associated with the simulator.

### hectorslam-sicktest.launch
Starts up the hectorslam node with default SICK /scan topic, to enable testing
with only the hardware (and no simulator).

### joystick.launch
Starts up nodes to control the simulator with the joystick.

# Release 1.0.1 (15 April 2016)

Initial software release, including new nodes, and a few new launch files.

## New nodes

### safeopenloopcircle_node
This is based off of the simulink model safeOpenLoopCircle.slx, and it is the 
code generated from that model.

### cmdvel2gazebo_node
Replaces the python script in azcar_sim/scripts with a code-generated version.
This version includes logic to attempt to prevent wheel slippage, by adding
a dynamical delay to the vehicle wheel speed commands. See the model for more
information.

## New launch files

## azcar_skidpan.launch
This launchfile uses the cmdvel2gazebo_node with correct launch parameters for the /azcar_sim node. It launches into an empty skidpan.

# License
See README.md
