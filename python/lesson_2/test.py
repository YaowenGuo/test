#8

def stack_push(alist,item):
    alist.append(item)

def stack_pop(alist):
    if len(alist) == 0:
        return None
    else:
        return alist.pop()

def queue_add(alist,item):
    alist.append(item)
    
def queue_get(alist):
    if len( alist ) == 0:
        return None
    else:
        a = alist[0]
        del alist[0]
        return a


stack = []
stack_push(stack,3)
stack_push(stack,4)
print stack_pop(stack)
print stack_pop(stack)

queue_add(stack,2)
queue_add(stack,4)
print queue_get( stack )
print queue_get( stack )