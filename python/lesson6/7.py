#!/usr/bin/env python
# -*- coding:UTF-8 -*-
#Author:GuoYaoWen


# 7、改进如下程序，
# class Time60(object):
#     def __init__(self, hr, min):
#         self.hr = hr
#         self.min = min
#     def __str__(self):
#         return "%d:%d" % (self.hr, self.min)
#     __repr__ = __str__
#     def __add__(self, other):
#         return self.__class__(self.hr + other.hr, self.min + other.min)
#     def __iadd__(self, other):
#         self.hr += other.hr
#         self.min += other.min
#         return self

# 使得
# (a) 允许“空”实例化: 如果小时和分钟的值没有给出，默认为零小时、零分钟。
# (b) 用零占位组成两位数的表示形式,因为当前的时间格式不符合要求。如下面的示例，wed
# 应该输出为“12:05.”
# (c)除了用hours (hr) 和minutes (min)进行初始化外，还支持以下时间输入格式：
#  一个由小时和分钟组成的元组(10, 30)
# 一个由小时和分钟组成的字典({'hr': 10, 'min': 30})
# 一个代表小时和分钟的字符串("10:30")
# 附加题: 允许不恰当的时间字符串表示形式，如 “12:5”.
# (d) 我们是否需要实现__radd__()方法? 为什么? 如果不必实现此方法，那我们什么时候可
# 以或应该覆盖它?
# (e) __repr__()函数的实现是有缺陷而且被误导的。我们只是重载了此函数，这样我们可以省
# 去使用print 语句的麻烦，使它在解释器中很好的显示出来。但是，这个违背了一个原则:对于可估
# 值的Python 表达式，repr()总是应该给出一个(有效的)字符串表示形式。12:05 本身不是一个合法
# 的Python 表达式，但Time60('12:05')是合法的。请实现它。
# (f) 添加六十进制(基数是60)的运算功能。下面示例中的输出应该是19:15，而不是18:75:
# >>> thu = Time60(10, 30)
# >>> fri = Time60(8, 45)
# >>> thu + fri
# 18:75


# 程序输入：
# thu = Time60(10,30)
# fri = Time60(8,35)
# print thu + fri
# thu = Time60((10,30))
# fri = Time60({"hr":8,"min":35})
# mon = Time60("10:30")
# print thu + fri
# print fri + mon
# thu += fri
# print thu

# 程序输出：
# >>>
# 19:05
# 19:05
# 19:05
# 19:05