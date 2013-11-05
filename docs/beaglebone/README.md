# Beaglebone Black with Angstrom Distribution

## System

```sh
opkg update
opkg upgrade
```

## Generating SSH Keys

Setup 'ssh-agent':

```sh
echo 'EDITOR=/usr/bin/nano export EDITOR' > ~/.profile
echo 'eval `ssh-agent -s`' > ~/.profile
```

Install 'ssh-keygen':

```sh
opkg install openssh-keygen
```

```sh
ssh-keygen -t rsa -C "<your email here>"
ssh-add ~/.ssh/id_rsa
```

Edit '~/.ssh/config':

```sh
Host *
   IdentityFile ~/.ssh/id_rsa
```

## Fix SSL certificates

For git, edit ~/.gitconfig:

```sh
git config --global http.sslVerify true
git config --global http.sslCAinfo /etc/ssl/certs/ca-certificates.crt
```

For curl, do:

```sh
echo "export CURL_CA_BUNDLE=/etc/ssl/certs/ca-certificates.crt" >> ~/.profile
```

For rubygem and other, do:

```sh
echo "export SSL_CERT_FILE=/etc/ssl/certs/ca-certificates.crt" >> ~/.profile
```


## Time

Automatically update the time using NTP:

http://derekmolloy.ie/automatically-setting-the-beaglebone-black-time-using-ntp/

Install ntp:

```sh
opkg install ntp
```

Edit '/etc/ntp.conf' file:

```sh
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

```sh
rm localtime
ln -s /usr/share/zoneinfo/Europe/London /etc/localtime
```

Enable the NTP services:

```sh
systemctl enable ntpdate.service
systemctl enable ntpd.service
```

Edit '/lib/systemd/system/ntpdate.service':

```sh
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

## Install Ruby

You may need to install ruby. In a beaglebone with angstrom installed do:

```sh
opkg update
opkg install ruby
```

Fixing /usr/lib/ruby/mkmf.rb:

```sh
INCFLAGS = -I. #$INCFLAGS -I/usr/include/
ldflags  = #{$LDFLAGS} -L/lib/
```

## Wifi using rtl8192cu/rtl8188cus chipset

How to install a rtl8192cu/rtl8188cus on the Beaglebone Black (BBB) running Angstrom:  

http://www.codealpha.net/864/how-to-set-up-a-rtl8192cu-on-the-beaglebone-black-bbb/

```sh
opkg install kernel-dev
opkg install kernel-headers
```

After reboot:

```sh
cd /usr/src/kernel
make scripts
ln -s /usr/src/kernel /lib/modules/$(uname -r)/build
cd ~
git clone https://github.com/cmicali/rtl8192cu_beaglebone.git
cd rtl8192cu_beaglebone
make CROSS_COMPILE=""
```

Install the driver:

```sh
mv 8192cu.ko /lib/modules/$(uname -r)
depmod -a
cd /etc/modules-load.d
echo "8192cu" > rtl8192cu-vendor.conf
```

Blacklist old rtlxxxx drivers:

```sh
cd /etc/modprobe.d
echo "install rtl8192cu /bin/false" >wifi_blacklist.conf
echo "install rtl8192c_common /bin/false" >>wifi_blacklist.conf
echo "install rtlwifi /bin/false" >>wifi_blacklist.conf
```

Edit '/var/lib/connman/settings':

```sh
[global]
Timeservers=0.angstrom.pool.ntp.org;1.angstrom.pool.ntp.org;2.angstrom.pool.ntp.org;3.angstrom.pool.ntp.org
OfflineMode=false

[Wired]
Enable=true
Tethering=false

[WiFi]
Enable=true
Tethering=false
```

Edit '/var/lib/connman/wifi.config':

```sh
[service_home]
Type=wifi
Name="<SSID>"
```

After reboot, connecting manually:

```sh
pgrep wpa
wpa_supplicant -Dwext -iwlan0 -c/etc/wpa_supplicant.conf -B
wpa_cli
/sbin/udhcpc -iwlan0
```

Or add init script:

```
cp wifi_init.sh /etc/init.d/wifi_init
chmod 755 /etc/init.d/wifi_init
update-rc.d wifi_init defaults
```