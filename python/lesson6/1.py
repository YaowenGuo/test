#!/usr/bin/env python
#-*- coding: UTF-8 -*-
#
        
class MoneyFmt(object):
    def __init__(self, value = 0.0):
        self.value = "{:,}".format(value)
    def __repr__(self):
        return repr(self.value)
    def __str__(self):
        val = "$"
        if self.value[0] == "-":
            val = "-$" + self.value[1:]
        else:
            val += self.value
        return val
    def __nonzero__(self):
        return bool(self.value)

money = MoneyFmt(1234567.8901)
print money

money = MoneyFmt(-1234567.8901)
print money