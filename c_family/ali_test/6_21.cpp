#include <iosteam>
#include <cassert>
using namespace std;

class Point{
public:
    Point():x(0),y(0){
    }
    Point(int x,int y):x(x),y(y){
    }
    ~Point(){
    }
    int getX() const{ return x; }
    int getY() const{ return y; }
    void move(int newX, int newY){
        x = newX;
        y = newY;
    }

private:
    int x,y;
};

class ArrayOfPoints{
public:
    ArrayOfPoints(int size):size(size){
        points = new Point[size];
    }
    ~ArrayOfPoints(){
        delete[] points;
    }
    Point &element(int index){
        assert(index >= 0 && index < size);
        return points[index];
    }
private:
    Point * points;
    int size;
}
int main(){
    int count;
    cout<<"Please input the count of points: ";
    cin>>count;
    ArrayOfPoints pointsArr1(count);
    pointsArr1.element(0).move(5,10);
    pointsArr1.element(1).move(15,20);
    cout<<"Point1:("<<pointsArr1.element(1).getX()<<endl;
    return 0;


}
