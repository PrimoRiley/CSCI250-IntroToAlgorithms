#include<iostream>
#include<cmath>

using namespace std;

class MyPoint
{
private:
  double x;
  double y;

public:
  MyPoint()
  {
    x = y = 0;
  }

  MyPoint(double x, double y)
  {
    this->x = x;
    this->y = y;
  }

  double distance(const MyPoint& p2) const
  {
    return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
  }

  double getX() const
  {
    return x;
  }

  double getY() const
  {
    return y;
  }
};

class ThreeDPoint: public MyPoint
{
private:
  double z;

public:
  ThreeDPoint();
  ThreeDPoint(double x, double y, double z);
  double getZ() const;
  double distance(const ThreeDPoint& p2);
};

ThreeDPoint::ThreeDPoint() : MyPoint()
{
    z = 0;
}

ThreeDPoint::ThreeDPoint(double x, double y, double z) : MyPoint(x, y)
{
    this->z = z;
}

double ThreeDPoint::getZ() const
{
    return z;
}

double ThreeDPoint:: distance(const ThreeDPoint& p2)
{
    return sqrt((this->getX() - p2.getX()) * (this->getX() - p2.getX()) + (this->getY() - p2.getY()) * (this->getY() - p2.getY()) + (getZ() - p2.getZ())*(getZ() - p2.getZ()));
}


int main()
{
    ThreeDPoint point;
    ThreeDPoint p2(10, 30, 25.5);
    cout<<point.getX()<<endl;
    cout<<point.distance(p2)<<endl;
    

    return 0;
}