execute_process(COMMAND "/home/nolan/Documents/catVehicle/catvehicle-1.1.0pre/build/azcar_sim/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/nolan/Documents/catVehicle/catvehicle-1.1.0pre/build/azcar_sim/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
