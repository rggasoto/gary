#!/bin/bash
# Author: Jonathan Sprinkle
# Sets a ROS_MASTER_URI to make another machine the ROS_MASTER
# Prevents us from having to run roscore
# NOTE: This must be sourced in every window that needs to run
# ROS, or you will get bizarre errors.
# 
# TODO: 
# * Add 'fail' or 'fix' logic if we cannot ping this machine
# * Add 'fail' or 'fix' logic if our ROS_HOSTNAME will not work
# License:
# The BSD License
#
# Copyright (c) 2015-2016 Arizona Board of Regents
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without modification, 
# are permitted provided that the following conditions are met:
# 
# * Redistributions of source code must retain the above copyright notice, this 
#   list of conditions and the following disclaimer.
# * Redistributions in binary form must reproduce the above copyright notice, this 
#   list of conditions and the following disclaimer in the documentation and/or 
#   other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR 
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL 
# THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

function usage 
{
   echo "Usage: source $0 hostmachine"
   echo ""
   echo "  Sets a ROS_MASTER_URI to make another machine the ROS_MASTER"
   echo "   This prevents us from having to run roscore on this machine."
   echo "   NOTE: This must be sourced in every window that needs to run"
   echo "   ROS, or you will get bizarre errors."
   echo "  The script appropriately names the http prefix and port number"
   echo ""
}

if [ $# -ne 1 ]; then
   usage
else
   # from http://stackoverflow.com/questions/2683279/how-to-detect-if-a-script-is-being-sourced
   #[[ "${BASH_SOURCE[0]}" != "${0}" ]] && echo "script ${BASH_SOURCE[0]} is being sourced ..."
   if [[ "${BASH_SOURCE[0]}" = "${0}" ]]; then
       echo "script ${BASH_SOURCE[0]} must be sourced; run as "
       echo "  source $0 $1"
   else 
       declare -x ROS_MASTER_URI=http://$1:11311
       declare -x ROS_HOSTNAME=$(hostname).local
   #    echo "ROS_HOSTNAME=${ROS_HOSTNAME}"
   #    echo "ROS_MASTER_URI=${ROS_MASTER_URI}"
   fi 
fi
