def mult(x,y):
	return x*y
def factorial(n):
	if n < 0 :
		print "Input Error"
	elif n == 0:
		return 1;
	else:
		return  reduce(mult,range(n)[1:])


def factorial_copy(n):
	if n < 0 :
		print "Input Error"
	elif n == 0:
		return 1;
	else:
		return  reduce((lambda x,y:x*y),range(n)[1:])


import time
def timeit(func,*args):
	start = time.clock()
	for i in range(10000000):
		func(*args)
	end = time.clock()
	return end - start

print timeit(factorial_copy,7)