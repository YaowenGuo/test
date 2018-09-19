#!/bin/sh

adb shell monkey  -p com.pandarow.chinese  -v -s 3500 100000 | tee  ~/test/monkey_log.txt
