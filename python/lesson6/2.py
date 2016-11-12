#!/usr/bin/env python
#-*- coding:UTF-8 -*-

import math
class Point(object):
    """Point is in the two-dimensional plane defined by
    the coordinates,with x and y coordinates."""
    def __init__(self, x, y):
        super(Point, self).__init__()
        self.x = x
        self.y = y
    def __repr__(self):
        return "(%f,%f)" % (self.x, self.y)
    __str__ = __repr__
    def getX(self):
        return  self.x
    def getY(self):
        return self.y

class  Line(object):
    """docstring for  Line"""
    def __init__(self, p1, p2):
        self.point1 = p1
        self.point2 = p2
    def length(self):
        return math.sqrt((self.point1.x - self.point2.x)**2 + (self.point1.y - self.point2.y)**2)
    def slope(self):
        if (self.point1.x == self.point2.x):
            return None
        else:
            return (self.point2.y - self.point1.y)/(self.point2.x - self.point1.x)
    def getPoint1(self):
        return self.point1
    def getPoint2(self):
        return self.point2
    def __str__(self):
        return "%s-->%s" % (self.point1, self.point2)
    def __repr__(self):
        return ( self.point1 ,self.point2)  

pointA = Point(2,4)
pointB = Point(4,-1)

line  = Line(pointA, pointB)

print "point A is %s" % pointA
print "point B is %s" % pointB
print "line is %s" % line
print "line's length id %d" % line.length()
print "line's slope is % d" % line.slope()