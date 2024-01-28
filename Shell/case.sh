#!/bin/bash 

read -p "input yes /no：" val

case $val in
	yes | y | Y | YES)
		echo "Y"
		;;
	n)
		echo "N"
esac


