#!/bin/bash

RET=`grep "^l" /etc/passwd | wc -l`
echo `grep "^l" /etc/passwd | wc -l`
echo `grep "^linux" /etc/passwd`

if [ $RET -eq 0 ]
then
	echo "no"
else
	echo "yes"
fi

