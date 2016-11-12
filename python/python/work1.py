#1
a = 12
b = 5

print "a = 12,b = 5"
print "a + b = %d" % (a + b)
print "a - b = %d" % (a - b)
print "a * b = %d" % (a * b)
print "a / b = %d" % (a / b)
print "a // b = %d" % (a // b)
print "a %% b = %d" % (a % b)
print "a ** b = %d" % (a ** b)

#2
s = raw_input("Please input something to sava:")
try:
    file_out = open("recode.txt","w")
    	
    file_out.write(s)
except IOError,e:
    print "write to file error ",e


#3

str = raw_input("Please input all text name you want to combine:")

sourceFileArray = str.split()
targetFile = raw_input("Please input target file:")

import os.path
if os.path.exists(targetFile):
#	answer = raw_input('OK, the "%s" exists ,Woult you like to override it?Y/N:' % filename)
#	while (answer != 'Y' || answer != "N")
#		answer = raw_input('Input errot!You can input Y/N:')
	
	print "Filed to combine %s have exists!" % targetFile
else :
	for filename in sourceFileArray :
		try:
			file_handle = open( filename )
			file_out = open(targetFile,"w+")
			for f in file_handle :
				file_out.write(f)
			file_handle.close()
		except IOError, e:
			print e
		finally :
			file_out.close()
		
#4,5,6 I think it mybe was visualization program.
visual programming have not study. It was hard for me.


#7

(4)is error	

	1.sqrt() is not support as  normall function by Python parser
	must import os.math package,and use math.sqrt().
	2.Function parameters must be positive or 0

	import os.math
	math.sqrt(7.5-5.0)+7*3

#8
radiusStr = raw_input("Please enter the radius of the circle:")
radius = int(radiusStr)
pi = 3.14
valume = 4.0/3*pi*radius**3
print "Valume = %f" % valume


#9

scoreStr = raw_input("Please enter the student achievement:")
score = float(scoreStr)

if 90 <= score <= 100 :
	print "A"
elif 80 <= score < 90 :
	print "B"
elif 70 <= score < 80 :
	print "C"
elif 60 <= score < 70 :
	print "D"
elif 0 <= score < 60 :
	print "E"
else :
	print "Input Error"
