#!/bin/bash 

i=0
while ((i<5))
do
	echo "$i"
	i=`expr $i + 1`
done

for ((i=0;i<5;i=i+1))
do
	echo "$i"
done

