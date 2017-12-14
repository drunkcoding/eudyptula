#!/bin/bash
make menuconfig
read -s -n1 -p "Press modify Makefile extension"
make
sudo make modules_install
sudo make install 
