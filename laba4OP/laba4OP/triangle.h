#pragma once

#include <iostream>
using namespace std;

class Point {
    int x, y, z;
public:
    Point() : x(0), y(0), z(0) {}
    Point(int x1, int y1, int z1);
    double distance(Point p);
};

class Side {
    Point A, B;
    double length;
public:
    Side();
    Side(Point A1, Point B1);
    double getLength();
    void setLength(double l);
};

class Triangle {
    Side AB;
    Side AC;
    Side BC;

public:
    Triangle();
    Triangle(Side ab, Side ac, Side bc);
    void setAB(Side ab);
    void setAC(Side ac);
    void setBC(Side bc);
    void getTriangle();
    double area();
    Triangle operator++();
    Triangle operator--();
    Triangle operator+=(int n);
    Triangle operator-=(int n);
    //~Triangle();
   
    
};

void printTriangle(Triangle t1, Triangle t2, Triangle t3);
void findMaxAreaTriangle(Triangle t1, Triangle t2, Triangle t3);
