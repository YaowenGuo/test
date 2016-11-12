#!usr/bin/env python

import string
#use string model is not invided

alphas = string.letters + "_"
num = string.digits

print 'Welcome to the Identifier Checker v1.0'
print 'Testees must be at least 2 chars long.'
myInput = raw_input('Identifier to test? ')

length = len(myInput)
if length > 1:
	if myInput[0] not in alphas:
		print '''invalid: first symble must be alphabetic'''
	else:
		alphnums = alphas + num
		for otherChar in myInput[1:]:

			if otherChar not in alphnums:
				print '''invalid: remaining symblos must be in alphanumeric'''
				break
		else:
			print 'okay as an identifier'