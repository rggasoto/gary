README

Need to create a .launch file for this!
Commands To run (each in a tab):

* roslaunch azcar_sim azcar_skidpan.launch

* rosrun rviz rviz
# THEN Manually load (file "open" in RViz)
<yourGitRepo>/catVehicle/catvehicle-1.1.0pre/src/rbe502code/rbe502.rviz

* rosrun map_server map_server <yourGitRepo>/catVehicle/catvehicle-1.1.0pre/src/rbe502code/maps/shapes.yaml

# need to create a node for this
* rosrun tf static_transform_publisher 0 0 0 0 0 0 1 azcar_sim/odom map 10

* python <yourGitRepo>/catVehicle/catvehicle-1.1.0pre/src/rbe502code/scripts/carPathPlanning.py

Currently, you can use the "2D Pose Estimate" and the "2D Nav Goal" buttons in rviz to send commands to the pathPlanner.py
When A* completes, the path is printed onto the map... in pixel coordinates. Need to fix in next push.
