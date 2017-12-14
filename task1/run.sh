#!/bin/bash
sudo dmesg -c
make
sudo insmod `ls | grep -E .+\.ko`
dmesg | grep ve482
read -s -n1 -p "Press any key to continue ... "
sudo rmmod -f `ls | grep -E .+\.ko`
echo "Module removed"
dmesg | grep ve482
make clean