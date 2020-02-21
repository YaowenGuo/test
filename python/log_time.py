import os
import time
import sys

file = ""
outFile = ""
print(sys.argv[1])
print(sys.argv[2])
try:
    file = open(sys.argv[1], 'r')
    outFile = open(sys.argv[2], 'w')

    outFile.writelines("Launch, LaunchMilli, Start, StartMilli, UseTime")
    while True:
        lineStart = file.readline()
        outline = ''
        lunchTimestamp = 0
        openTimestamp = 0

        if not lineStart:
            break
        elif (lineStart.find("act=android.intent.action.MAIN")):
            launchTime = "2019-" + lineStart[:18]
            timeMilli = time.strptime(launchTime, "%Y-%m-%d %H:%M:%S.%f")
            lunchTimestamp = int(time.mktime(timeMilli)) * 1000 + int(lineStart[15: 18])

            outline += launchTime + ', ' + str(lunchTimestamp) + ', '
        else:
            outline += "error, ,"

        lineMainOpen = file.readline()

        if not lineMainOpen:
            break
        elif (lineMainOpen.find("START")):
            openTime = "2019-" + lineMainOpen[:18]
            timeMilli = time.strptime(openTime, "%Y-%m-%d %H:%M:%S.%f")
            openTimestamp = int(time.mktime(timeMilli)) * 1000 + int(lineMainOpen[15:18])
            timeMilli = str()
            outline += openTime + ', ' + str(openTimestamp) + ', '
        else:
            outline += "error, ,"

        useTime = openTimestamp - lunchTimestamp

        print(outline + str(useTime))
        outFile.writelines(outline + str(useTime) + '\n')

finally:
    file.close()
    outFile.close()
