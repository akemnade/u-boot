#!/bin/sh
if [ "$1" = "" -o "--help" = "$1" ]
then
	echo "Usage $0 /dev/sdX (your target sdcard)"
	exit 1
fi
dd if=MLO bs=512 seek=256 of=$1
dd if=u-boot.img bs=512 seek=512 of=$1
