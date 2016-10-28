#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/nolan/Documents/catVehicle/catvehicle-1.1.0pre/src/azcar_sim"

# snsure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/nolan/Documents/catVehicle/catvehicle-1.1.0pre/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/nolan/Documents/catVehicle/catvehicle-1.1.0pre/install/lib/python2.7/dist-packages:/home/nolan/Documents/catVehicle/catvehicle-1.1.0pre/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/nolan/Documents/catVehicle/catvehicle-1.1.0pre/build" \
    "/usr/bin/python" \
    "/home/nolan/Documents/catVehicle/catvehicle-1.1.0pre/src/azcar_sim/setup.py" \
    build --build-base "/home/nolan/Documents/catVehicle/catvehicle-1.1.0pre/build/azcar_sim" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/nolan/Documents/catVehicle/catvehicle-1.1.0pre/install" --install-scripts="/home/nolan/Documents/catVehicle/catvehicle-1.1.0pre/install/bin"
