#!/bin/bash 

read -p "plase input:" num1 num2
echo num1=$num1
echo $num1
echo $(expr $num1 + $num2)
echo $(expr $num1 - $num2)
echo $(expr $num1 \* $num2)
echo $(expr $num1 / $num2)
