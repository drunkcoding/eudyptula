#!/bin/bash
make
sudo insmod `ls | grep -E .+\.ko`
read -s -n1 -p "Press any key to continue ... "
sudo rmmod -f `ls | grep -E .+\.ko`
make clean