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
