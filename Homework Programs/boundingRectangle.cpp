// This exercise uses the Rectangle2D class in Exercise 11.9.
#ifndef RECTANGLE2D_H
#define RECTANGLE2D_H
#include <iostream>

using namespace std; 

class Rectangle2D
{
public:
  Rectangle2D();
  Rectangle2D(double x, double y, double width, double height);

  double getX() const;
  double getY() const;
  double getWidth() const;
  double getHeight() const;
  // The rest in Exercise 11.9 are not used in this exercise. They can be omitted

private:
  double x, y; // Center of the rectangle
  double width, height;
};

#endif

Rectangle2D::Rectangle2D()
{
  x = y = 0;
  width = height = 1;
}

Rectangle2D::Rectangle2D(double x, double y, double width, double height)
{
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

double Rectangle2D::getX() const 
{
  return x;
}

double Rectangle2D::getY() const 
{
  return y;
}

double Rectangle2D::getWidth() const 
{
  return width;
}

double Rectangle2D::getHeight() const 
{
  return height;
}

// MyRectangle2D getRectangle(const double points[][SIZE], int numberOfPoints);
const int SIZE = 2;

double minX(const double points[][SIZE], int numberOfPoints) 
{
  double minX;
  for(int i=0; i<numberOfPoints; i++)
  {
      if(points[i][0] < points[0][0])
        minX = points[i][0];
      else
        minX = points[0][0];
  }
  return minX;
}
  
double maxX(const double points[][SIZE], int numberOfPoints)
{
  double maxX;
  for(int i=0; i<numberOfPoints; i++)
  {
      if(points[i][0] > points[0][0])
        maxX = points[i][0];
      else
        maxX = points[0][0];
  }
  return maxX;
}
  
double minY(const double points[][SIZE], int numberOfPoints)
{
  double minY;
  for(int i=0; i<numberOfPoints; i++)
  {
      if(points[i][1] < points[0][1])
        minY = points[i][1];
      else
        minY = points[0][1];
  }
  return minY;
}
  
double maxY(const double points[][SIZE], int numberOfPoints) 
{
  double maxY;
  for(int i=0; i<numberOfPoints; i++)
  {
      if(points[i][1] > points[0][1])
        maxY = points[i][1];
      else
        maxY = points[0][1];
  }
  return maxY;
}

Rectangle2D* getRectanglePointer(const double points[][SIZE], int numberOfPoints)
{ 
  double width = (maxX(points, numberOfPoints) - minX(points, numberOfPoints));
  double height = (maxY(points, numberOfPoints) - minY(points, numberOfPoints));
  double xCenter = ((maxX(points, numberOfPoints) + minX(points, numberOfPoints))/2);
  double yCenter = ((maxY(points, numberOfPoints) + minY(points, numberOfPoints))/2);
  Rectangle2D* rectangleptr;
  rectangleptr = new Rectangle2D(xCenter, yCenter, width, height);
  return rectangleptr;
}

Rectangle2D getRectangle(const double points[][SIZE], int numberOfPoints) 
{
  double width = (maxX(points, numberOfPoints) - minX(points, numberOfPoints));
  double height = (maxY(points, numberOfPoints) - minY(points, numberOfPoints));
  double xCenter = ((maxX(points, numberOfPoints) + minX(points, numberOfPoints))/2);
  double yCenter = ((maxY(points, numberOfPoints) + minY(points, numberOfPoints))/2);
  Rectangle2D rectangle(xCenter, yCenter, width, height);
  return rectangle;
}

#include <iostream>
using namespace std;

int main()
{
  double points[5][2];
  double a1, a2, b1, b2, c1, c2, d1, d2, e1, e2;
  cout << "Enter five points: ";
  cin>>a1>>a2>>b1>>b2>>c1>>c2>>d1>>d2>>e1>>e2;
  // Write your code to read five points 
  points[0][0] = a1;
  points[0][1] = a2;
  points[1][0] = b1;
  points[1][1] = b2;
  points[2][0] = c1;
  points[2][1] = c2;
  points[3][0] = d1;
  points[3][1] = d2;
  points[4][0] = e1;
  points[4][1] = e2;

  Rectangle2D boundingRectangle = getRectangle(points, 5);   
  cout << "The bounding rectangle's center (" << boundingRectangle.getX() << ", " << 
    boundingRectangle.getY() << "), width " << boundingRectangle.getWidth() << 
	  ", height " << boundingRectangle.getHeight() << endl;

  Rectangle2D* boundingRectangleP = getRectanglePointer(points, 5);
  cout << "The bounding rectangle's center (" << boundingRectangleP->getX() << ", " <<
	  boundingRectangleP->getY() << "), width " << boundingRectangleP->getWidth() <<
	  ", height " << boundingRectangleP->getHeight() << endl;

  return 0;
}