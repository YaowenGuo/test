#!/usr/bin/env python
#使用列表实现堆栈
#create date:2016/3/26

stack = []
def pushit():
	'''从屏幕输入一个数据，将其去掉两端的空格，添加的列表的尾部'''
	stack.append(raw_input('Enter New String:').strip())

def popit():
	'''出栈操作，如果列表的长度为０，表示栈为空，输出栈为空的信息。否则从列表的末端弹出一个值。'''
	if len(stack) == 0:
		print 'Cannot pop from an enpty stack1'
	else:
		print "Removed [", `stack.pop()`, ']'

def viewstack():
	'''输出栈中的内容'''
	print stack
#使用字典讲字符与函数对应
CNDs = { 'u':pushit, 'o':popit, 'v':viewstack}

def showmenu():
	'''输出菜单信息'''
	pr = '''
p(U)sh
p(O)p
(V)iew
(Q)uit

Enter choice:'''
while  True:
	while True:
		try:
			choice = raw_input(pr).strip()[0].lower()
		except (EOFError,KeyboardInterrupt,IndexError):
			choice = 'q'
		print '\nYou picked:[%s]' % choice
		if choice not in 'uovq':
			print 'Invalid option, Try again'
		else:
			break
		if choice =='q':
			break
		CNDs[choice]()
#主函数
if __name__ == '__main__':
	showmenu()
