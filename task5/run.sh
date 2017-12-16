#!/bin/bash
make
echo 'ACTION=="add", SUBSYSTEM=="usb", RUN+="/sbin/insmod '`pwd`'/helloworld.ko"'\n > hobby-usb.rules
echo 'ACTION=="remove", SUBSYSTEM=="usb", RUN+="/sbin/rmmod '`pwd`'/helloworld.ko"' >> hobby-usb.rules
sudo cp hobby-usb.rules /etc/udev/rules.d/
read -s -n1 -p "Press any key to continue ... "
sudo rm -f /etc/udev/rules.d/hobby-usb.rules
make clean