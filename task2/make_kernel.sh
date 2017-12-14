#!/bin/bash
make menuconfig
read -s -n1 -p "Press modify CONFIG_LOCALVERSION_AUTO"
make
sudo make modules_install
sudo make install 
