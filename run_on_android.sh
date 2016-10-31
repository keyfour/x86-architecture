#!/bin/bash
#
# Run executables on Android Device
#

##Change your adb path
[[ "$ADB" ]] || ADB=/usr/bin/adb

[[ "$1" ]] || { echo "Usage: ./run_on_android.sh [executable file]" && exit 1; }

EFILE=$1

#Install program
$ADB push $EFILE /data/local/tmp/$EFILE

#Run in shell
$ADB shell /data/local/tmp/$EFILE
