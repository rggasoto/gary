# Overview
This workspace houses simulation software. Any software that can be run ONLY on the platform is 
housed elsewhere. 

If you are installing this software, you should be able to simulate a car-like robot using the
same commands as the turtlebot simulator. There are significant differences in the kinematic 
models of a unicycle (like the turtlebot) and a car-like robot (like the CAT Vehicle), namely
the ability to change orientation without moving (for a unicycle) is not possible for a car-like
robot. 

## Goals
The usefulness of this simulator is to experiment with controllers and ideas that must be explored
with realistic limitations in computing power, and latency of communication, all while controlling
a system that obeys physical laws of motion. To this end, our simulator is not intended to 
perfectly mirror our physical system, but rather to provide an easy to use (and safe to fail in)
environment that uses the same communication models, functional inputs, and sensor types.

## Limitations
Because our simulation uses Gazebo as its major engine to advance time for the physical system's
state, we are limited by the limitations in Gazebo:
 * Simulation results may not be repeatable
 * Simulations may not run in real time on all hardware platforms
 * The physical system's model will not perfectly mirror the physical vehicle

Among the reasons for an approximate simulation model are that (i) simulation times will increase
the more accurate the Gazebo model becomes; (ii) the costs associated with obtaining accurate
masses and inertias for the physical system are not negligible, but the simulation results are not
repeatable so the goal to perfom this system identification is suspect; and (iii) settings of the
simulation step size and real-time factor are selected in order to provide a representative 
behavior of the vehicle, rather than mirror "real life," in order to speed up simulation. If you 
reduce the step size by an order of magnitude, it is not clear whether the results are more or 
less accurate without significant investment in system identification.

Nonetheless, advice and recommendations to improve the Gazebo model and/or the simulation setup 
are welcome, as long as they are accompanied by data that back up the suggestion (or experiments
that would couple physical platform data with simulator data).

# Installation

Step-by-step installation instructions may be found in the internal packages and their README 
files. Tutorials for how to download, build, and install the software and run the simulations are 
found on the main webpage or are linked from http://csl.arizona.edu

# About
The CAT Vehicle project is housed at the University of Arizona in the Compositional Systems
Laboratory. The project is directed by Dr. Jonathan Sprinkle, and is based on long-term 
fundamental research in cyber-physical systems conducted through funding by the National
Science Foundation under award numbers 1262960, 1253334, 1446435, and 1544395. Additional 
support from the Air Force Office of Scientific Research is provided under award 1262960. 

Any opinions, findings, and conclusions or recommendations expressed in this material are 
those of the author(s) and do not necessarily reflect the views of the National Science 
Foundation or the Air Force Office of Scientific Research.

# License

The BSD License

Copyright (c) 2015-2016 Arizona Board of Regents
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted 
provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions 
  and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of 
  conditions and the following disclaimer in the documentation and/or other materials provided 
  with the distribution.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED 
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE 
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR 
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# Authors

Jonathan Sprinkle <sprinkjm@email.arizona.edu>

Individual licenses for re-distributed products do not conflict with the above license. In those 
redistributed packages, additional acknowledgments are included.


