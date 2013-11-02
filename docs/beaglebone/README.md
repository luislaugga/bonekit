# Beaglebone Black with Angstrom Distribution

## System

```
opkg update
opkg upgrade
```

## Time

Automatically update the time using NTP:

http://derekmolloy.ie/automatically-setting-the-beaglebone-black-time-using-ntp/

Install ntp:

```shell
opkg install ntp
```

Edit '/etc/ntp.conf' file:

```shell
# This is the most basic ntp configuration file
# The driftfile must remain in a place specific to this
# machine - it records the machine specific clock error

driftfile /etc/ntp.drift
logfile /var/log/ntpd.log

# NTP Servers for Ireland from www.pool.ntp.org
server 0.pool.ntp.org
server 1.pool.ntp.org
server 2.pool.ntp.org
server 3.pool.ntp.org

# Using local hardware clock as fallback
# Disable this when using ntpd -q -g -x as ntpdate or it will sync to itself
# server 127.127.1.0 
# fudge 127.127.1.0 stratum 14

# Defining a default security setting
restrict 192.168.1.0 mask 255.255.255.0 nomodify notrap
```

Set localtime according to time zone:

```
rm localtime
ln -s /usr/share/zoneinfo/Europe/London /etc/localtime
```

Enable the NTP services:

```
systemctl enable ntpdate.service
systemctl enable ntpd.service
```

Edit '/lib/systemd/system/ntpdate.service':

```
[Unit]
Description=Network Time Service (one-shot ntpdate mode)
Before=ntpd.service

[Service]
Type=oneshot
ExecStart=/usr/bin/ntpd -q -g -x
ExecStart=/sbin/hwclock --systohc
RemainAfterExit=yes

[Install]
WantedBy=multi-user.target
```

## Ruby

You may need to install ruby. In a beaglebone with angstrom installed do:

```
opkg update
opkg install ruby
```

Fixing /usr/lib/ruby/mkmf.rb:

```
INCFLAGS = -I. #$INCFLAGS -I/usr/include/
ldflags  = #{$LDFLAGS} -L/lib/
```

## Wifi using rtl8192cu chipset

...


