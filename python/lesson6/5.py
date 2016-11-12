#!/usr/bin/env python
# -*- coding:UTF-8 -*-
#Author:GuoYaoWen


# 5、编写一个Unix操作界面的python脚本。该脚本可以跨平台使用。
# 输入ls 可以显示一个目录中的文件列表（如果在win下面，调用dir，
# 在linux下，调用ls），并返回相应的输出
# 输入more （win下调用moer）分页显示一个文件
# 输入cat （win下调用type）
# 输入cp  （win下调用copy）
# 输入mv  （win下调用ren）
# 输入rm  （win下调用del）
# 等等，能够实现越多命令越好。

import os
def ls():
    dirName = os.getcwd()
    for i in os.listdir(dirName):
        print dirName + "/" + i
def more(cmd):
    fileName = cmd.split(" ")[1]
    with open(fileName) as fobj:
        for line in fobj:
            print line,
def cat(cmd):
    fileName = cmd.split(" ")[1]
    with open(fileName) as fobj:
        for line in fobj:
            print line,
def copy(cmd):
    oldFile = cmd.split(" ")[1]
    newFile = cmd.split(" ")[2]
    with open(oldFile,"r") as foldObj:
        with open(newFile,"w") as fnewObj:
            for line in foldObj:
                fnewObj.write(line)
def move(cmd):
    with open(cmd.split(" ")[2]+"/"+cmd.split(" ")[1],"w") as wfile:
        text = open(cmd.split(" ")[1]).read()
        wfile.write(text)

    delFile = cmd.split(" ")[1]
    os.remove(delFile)
def remove(cmd):
    delFile = cmd.split(" ")[1]
    os.remove(delFile)
def DOS():
     
    while True:
        cmd = raw_input("in python  space >")
        if cmd.find("ls") != -1:
            ls()
        elif cmd.find("more") != -1:
            more(cmd)
        elif cmd.find("cat") != -1:
            cat(cmd)
        elif cmd.find("cp") != -1:
            copy(cmd)
        elif cmd.find("mv") != -1:
            move(cmd)
        elif cmd.find("rm") != -1:
            remove(cmd)
        else:
            print "sorry, command is wrong.please enter:ls,more,cat,cp,mv or rm"
if __name__ == "__main__":
    DOS()