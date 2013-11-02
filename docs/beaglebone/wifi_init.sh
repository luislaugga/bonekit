#! /bin/sh
# /etc/init.d/wifi
#

DESC="Wifi script"

case "$1" in
  start)
	echo -n "Starting $DESC: "
  sleep 5
  kill -9 `pgrep wpa`
  wpa_supplicant -Dwext -iwlan0 -c/etc/wpa_supplicant.conf -B
  sleep 5
  /sbin/udhcpc -iwlan0 > /var/log/wifi_init.log &
	;;
  stop)
	echo -n "Stopping $DESC: "
	;;
  restart)
	echo -n "Restarting $DESC: "
  kill -9 `pgrep wpa`
  wpa_supplicant -Dwext -iwlan0 -c/etc/wpa_supplicant.conf -B
  sleep 5
  /sbin/udhcpc -iwlan0 > /var/log/wifi_init.log &
	;;
  *)
	N=/etc/init.d/$NAME
	echo "Usage: $N {start|stop|restart}" >&2
	exit 1
	;;
esac

exit 0
