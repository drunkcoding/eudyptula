#!/bin/bash
make
sudo insmod helloworld.ko
sudo chmod 777 /dev/hobby
read -s -n1 -p "Press any key to continue ... "
sudo rmmod -f helloworld.ko
make clean