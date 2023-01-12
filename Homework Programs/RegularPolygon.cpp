#include<iostream>
#include <math.h>
#define PI 3.14159265

using namespace std;

class RegularPolygon
{
private:
    int n;
    double side;
    double x;
    double y;

public:

    RegularPolygon()
    {
        n = 3;
        side = 1;
        x = 0;
        y = 0;
    }

    RegularPolygon(int num, double s)
    {
        n = num;
        side = s;
        x = 0;
        y = 0;
    }

    RegularPolygon(int num, double s, double xcord, double ycord)
    {
        n = num;
        side = s;
        x = xcord;
        y = ycord;
    }

    void setNumOfSides(int o)
    {
        n = o;
    }

    void setSideLength(double o)
    {
        side = o;
    }

    void setxCoord(double o)
    {
        x = o;
    }

    void setyCoord(double o)
    {
        y = o;
    }

    int getNumOfSides() const
    {
        return n;
    }

    double getSideLength() const
    {
        return side;
    }

    double getxCoord() const
    {
        return x;
    }

    double getyCoord() const
    {
        return x;
    }

    double getPerimeter() const
    {
        double perimeter = 0;
        for(int i=0; i<n; i++)
        {
            perimeter = perimeter + side;
        }
        return perimeter;
    }

    double getArea() const
    {
        double area = 0;
        area = (n*(side*side)/(4*(tan(PI/n))));
        return area;
    }

};

int main()
{
    RegularPolygon poly1;
    RegularPolygon poly2(6, 4);
    RegularPolygon poly3(10, 4, 5.6, 7.8);

    cout<<"Regular Polygon 1: "<<endl;
    cout<<"Area: "<<poly1.getArea()<<endl;
    cout<<"Perimeter: "<<poly1.getPerimeter()<<endl<<endl;

    cout<<"Regular Polygon 2: "<<endl;
    cout<<"Area: "<<poly2.getArea()<<endl;
    cout<<"Perimeter: "<<poly2.getPerimeter()<<endl<<endl;

    cout<<"Regular Polygon 3: "<<endl;
    cout<<"Area: "<<poly3.getArea()<<endl;
    cout<<"Perimeter: "<<poly3.getPerimeter()<<endl<<endl;


    return 0;
}
