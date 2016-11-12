
def my_zip(alist,blist):
	return map(None,alist,blist)

alist = [1,2,3,4,5,6]
blist = ['abc','def','ghi','jkl','mno','pqr']

print "my_zip output:", my_zip(alist,blist)
print 'zip output:', zip(alist,blist)