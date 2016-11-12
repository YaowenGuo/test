#!/usr/bin/env python
# -*- coding:UTF-8 -*-
#Author:GuoYaoWen

# 6、授权和函数编程。
# (a) 请为课程中的CapOpen 类编写一个writelines()方法。
#这个新函数将可以一次读入多行文本，然后将文本数据转换成大写的形式，
# 它与write()方法的区别和通常意思上的writelines()与write()方法
#之间的区别相似。
# 注意：编写完这个方法后，writelines()将不再由文件对象"代理"。
# (b) 在writelines()方法中添加一个参数，用这个参数来指明是否需
#要为每行文本加上一个换行符。此参数的默认值是False,表示不加换行符。

class CapOpen(object):
    """docstring for CapOpen"""
    def __init__(self, fn, mode='r', buf=-1):
        self.file = open(fn, mode, buf)

    def __str__(self):
        return str(self.file)

    def __repr__(self):
        return 'self.file'
    
    def write(self, line):
        self.file.write(line.upper())

    def __getattr__(self,attr):
        return getattr(self.file,attr)

    def writelines(self,lines,line_feed=False):
        for line in lines:
            self.file.write(line.upper())
            if  line_feed:
                self.file.write("\n")


if __name__ == '__main__':
    source_file = open("1.py","r")
    lines = source_file.readlines()
    target_file = CapOpen("1copy.py","w+")
    target_file.writelines(lines)
    target_file.writelines(lines,True)
    target_file.close()


