def is_leap(year):
	if year%4==0 and year%100 != 0 :
		return True
	elif  year%400 ==0 :
		return True
	else:
		return False


def check_years(a_year_list):
	return filter(is_leap,a_year_list)



year_list=[1993,1994,1995,1996,1997,1998,1999,2000,2001,2002,2003,2004,2005]

print "check_years:",year_list

print "use filter check:", check_years(year_list)
print "use list product to check:", [year for year in year_list if \
(year%4==0 and year%100!=0 or year%400==0)]
