#!/usr/bin/env python
#coding:utf-8

class Solution:
    def strStr(self, source, target):
        if source is None or target is None:
            return -1
        return source.find(target)



if __name__ == "__main__":
    str = "Hello World! I'm nisdfs!"
    solution = Solution();
    print(solution.strStr(str, "I'm"))
