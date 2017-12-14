#!/bin/bash
sudo dmesg -c
make
sudo insmod `ls | grep -E .+\.ko`
dmesg | grep Hello
read -s -n1 -p "Press any key to continue ... "
sudo rmmod -f `ls | grep -E .+\.ko`
echo "Module removed"
dmesg | grep Hello
make clean