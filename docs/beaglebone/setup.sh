#!/bin/bash

# system
opkg update
opkg upgrade

# ntp
opkg install ntp
cp ntp.conf /etc/ntp.conf
rm localtime
ln -s /usr/share/zoneinfo/Europe/London /etc/localtime
systemctl enable ntpdate.service
systemctl enable ntpd.service
cp ntpdate.service /lib/systemd/system/ntpdate.service

# ruby

# wifi
opkg install kernel-dev
opkg install kernel-headers

