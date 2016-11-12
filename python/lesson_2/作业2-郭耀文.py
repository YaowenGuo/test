#current a less 1 pan to lettle pan

input_pan = raw_input("Please input a num less 1 as Pan:")

#Make pan to integer
try:
    pan = int (input_pan * 100)
    
    if 0 < pan < 100:
        littlePan25 = pan / 25
        pan %= 25
        littlePan10 = pan / 10
        pan %= 10
        littlePan5 = pan / 5
        pan %= 5
        littlePan1 = pan
    
    print "%f pan = ", inputPan ,
    if littlePan25 != 0:
        print "%d littlePan 25", littlePan25,
    if littlePan10 != 0:
        print "+ %d littlePan 10", littlePan10,
    if littlePan5 != 0:
        print "+ %d littlePan5", littlePan5,
    if littlePan1 != 0:
        print "+ %d littlePan1", littlePan1
except :
    print "Input errot"
    print input_pan
    
    
#2
17 + 32 = 49
017 + 32 = 47
017 + 032 = 41
在数字前面加0表示八进制
结果现实的是十进制

#3
import random
N = random.randint(2,100)
alist = []
i = 0
while i < N:
    alist.append( random.uniform(0,pow(2,31)) )
    i += 1
    
alist = random.sample(alist,random.randint(2,N) )

print sorted(alist)


#4
def my_strip(str):
    start = 0
    end = 0
    i = 0
    while i < len( str ):
        if not str[i].isspace():
            start = i
            end = i
            break
        i += 1;
        
    while i < len( str ):
        if not str[i].isspace():
            end = i
        i += 1
        
    return str[start:end+1]

print my_strip("     welcome to Python's world!     \n "),
print "zxcv",
print "zxcv"




#5
#coding=utf-8
import random
#0代表石头，1代表剪刀，2代表布
computer = random.randint(0,2)
your = raw_input("Please input you choice(石头，剪刀，布):")

if computer == 0:
    print "电脑：石头 VS 你的：%s",your
    if your == "石头":
        print "平手！"
    elif your == "剪刀":
        print "很遗憾，你输了！"
    elif your == "布":
        print "恭喜，你赢了！"
    else:
        print "输入有误！"

elif computer == 1:
    print "电脑：剪刀 VS 你的：",your
    if your == "石头":
        print "恭喜，你赢了！"
    elif your == "剪刀":
        print "平手！"
    elif your == "布":
        print "很遗憾，你输了！"
    else:
        print "输入有误！"
else :
    print "电脑：布 VS 你的：",your
    if your == "石头":
        print "很遗憾，你输了！"
    elif your == "剪刀":
        print "恭喜，你赢了！"
    elif your == "布":
        print "平手！"
    else:
        print "输入有误！"
        
        
        

#!/usr/bin/python
import time
import sys

def dateinput():
    date = raw_input('please input the first date: ')
        return date

def datetrans(tdate):
    spdate = tdate.replace("/","-")
    try:
        atesec = time.strptime(spdate,'%Y-%m-%d')
    except ValueError:
        print "%s is not a rightful date!!" % tdate
        sys.exit(1)
    return time.mktime(datesec)

def daysdiff(d1,d2):
    daysec = 24 * 60 * 60
    return int(( d1 - d2 )/daysec)

    date1 = dateinput()
    date2 = dateinput()

    date1sec = datetrans(date1)
    date2sec = datetrans(date2)

    print "The number of days between two dates is: ",daysdiff(date1sec,date2sec)
#7
def add(A,B):
    res = [ [0] * len(B[0]) for i in range(len(A) )]
    for i in range(len(A) ):
        for j in range( len(A[0])):
            res[i][j] = A[i][j] + B[i][j]
    return res

def matrixMul(A, B):
    res = [[0] * len(B[0]) for i in range(len(A))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                res[i][j] += A[i][k] * B[k][j]
    return res

M = [ [1,2,3],[4,5,6],[7,8,9]]
N = [ [3,5,3],[2,2,1],[1,1,1]]
result = [ [0,0,0],[0,0,0],[0,0,0] ]

print "M"
print M
print "N"
print N
print "M+N:"
print add(M,N)
print "M*N"
print matrixMul(M,N)



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