def average(alist):
	return reduce((lambda x,y:x+y),alist)/len(alist)

allNum = range(5)
print allNum
print "average:", average(allNum)