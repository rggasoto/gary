Author: Jonathan Sprinkle

In order to quickly set your ROS_MASTER_URI and ROS_HOSTNAME, use the script
 source setupMaster.sh

If you don't run this script, you might have errors like the following:
* Can see topics from other machines, but other machines cannot see my topics
* Can see my published topics, but nodes might not be able to subscribe
* Launchfiles may launch my own roscore, instead of using that of another master

Example: I am running in the lab, and want merlin.local to be the ROS_MASTER

On Merlin:

   $ source setupMaster.sh merlin

  Now my env variables should include
   ROS_MASTER_URI="http://merlin.local:11311"
   ROS_HOSTNAME="merlin.local"

  You can check this by
   $ export | grep ROS

On Jane:

   $ source setupmaster.sh merlin

  Now my env variables should include
   ROS_MASTER_URI="http://merlin.local:11311"
   ROS_HOSTNAME="jane.local"

  You can check this by
   $ export | grep ROS
