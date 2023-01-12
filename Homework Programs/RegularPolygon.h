#include<iostream>
#include <math.h>
#define PI 3.14159265

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

    void setNumOfSides(int o) const
    {
        n = o;
    }

    void setSideLength(double o) const
    {
        side = o;
    }

    void setxCoord(double o) const
    {
        x = o;
    }

    void setyCoord(double o) const
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
        for(i=0; i<n; i++)
        {
            perimeter = perimeter + side;
        }
        return perimeter;
    }

    double getArea() const
    {
        double area = 0;
        area = (n*(side*side)/(4*(tan(PI/n))));
    }

};

int main()
{
    RegularPolygon poly1();
    cout<<poly1.getArea()<<endl;
    cout<<poly1.getPerimeter()<<endl;

    RegularPolygon poly2(6, 4);
    cout<<poly1.getArea()<<endl;
    cout<<poly1.getPerimeter()<<endl;

    RegularPolygon poly3(10, 4, 5.6, 7.8);
    cout<<poly1.getArea()<<endl;
    cout<<poly1.getPerimeter()<<endl;


    return 0;
}
