def safe_max(*alist):
    if len(alist) ==0:
        return None
    elif len(alist)==1:
        return alist[0]
    else:
        max_one  = alist[0]
        try:
            for item in alist:
                if max_one < item:
                    max_one = item
            return max_one
        except Exception,e:
            print e


print safe_max(1,2,3,4,5)
print safe_max('a','c','b')
print safe_max(['a'],['c'],['b'],['d','e'])
print safe_max('abcdef')
print safe_max("abcdef","string")        