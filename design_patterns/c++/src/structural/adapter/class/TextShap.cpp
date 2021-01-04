//
// Created by Albert on 1/3/21.
//

#include "TextShap.h"

// BoundingBox操作对TextView的接口进行转换使之匹配 Shape的接 。这里是获取View边界的。
void TextShape::setBouningBox(Point& bottomLeft, Point& topRight) const {
  Coord bottom, left, width, height;
  getOrigin(bottom, left);
  getExtent(width, height);
  bottomLeft = Point(bottom, left);
  topRight = Point(bottom + height, left + width);
}

bool TextShape::isEmpty() const {
  return TextView:: isEmpty();
}

// 最后，我们定义 CreateManipulator(TextView 不支持该操作)，假定我们已经实现支持TextShape操作的类 TextManipulator。

Manipulator* TextShape::getCreateManipulator () const {
  return new TextManipulator(this);
}