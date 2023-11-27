adb push ./QtDemo /usr/bin/
adb shell chmod 777 /usr/bin/QtDemo
adb shell sync
::adb shell source /etc/qtenv.sh
::adb shell /usr/bin/QTDemo