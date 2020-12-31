package structural.dapter;

import java.awt.Point;

/**
 * Target。 客户端的类体系，Adapter 将 Adaptee 转化为 Target
 */
public abstract class Shape {
    protected Point bottomLeft, topRight;
    protected abstract void boundingBox(Point bottomLeft, Point topRight) throws Exception;
    public abstract Manipulator createManipulator();
}
