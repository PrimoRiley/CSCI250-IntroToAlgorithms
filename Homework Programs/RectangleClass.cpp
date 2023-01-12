#include <iostream> // Exercise09_01
using namespace std;

class Rectangle
{
public:

  double width;
  double height;

  Rectangle();
  Rectangle(double, double);
  double getArea();
  double getPerimeter();
};

Rectangle::Rectangle()
{
    width = 1;
    height = 1;
}

Rectangle::Rectangle(double w, double h)
{
    width = w;
    height = h;
}

double Rectangle::getArea()
{
    return width * height;
}

double Rectangle::getPerimeter()
{
    return (width*2)+(height*2);
}

int main() {
  Rectangle rec1(4, 40);
  Rectangle rec2(3.5, 35.9);

  cout<<"Rectangle 1: "<<endl;

  cout<<"Width: "<<rec1.width<<endl;
  cout<<"Height: "<<rec1.height<<endl;
  cout<<"Area: "<<rec1.getArea()<<endl;
  cout<<"Perimeter: "<<rec1.getPerimeter()<<endl<<endl;


  cout<<"Rectangle 2: "<<endl;
  cout<<"Width: "<<rec2.width<<endl;
  cout<<"Height: "<<rec2.height<<endl;
  cout<<"Area: "<<rec2.getArea()<<endl;
  cout<<"Perimeter: "<<rec2.getPerimeter()<<endl;

  return 0;
}
