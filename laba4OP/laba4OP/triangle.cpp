#include "triangle.h"
#include <iostream>
#include <string>
using namespace std;


Triangle::Triangle() {
    AB = Side();
    BC = Side();
    AC = Side();
}
Triangle::Triangle(Side ab, Side ac, Side bc) {
    AC = ac;
    AB = ab;
    BC = bc;
}
double Triangle::area() {
    double P = AB.getLength() + BC.getLength() + AC.getLength();
    double p = P / 2;
    return sqrt(p * (p - AB.getLength()) * (p - BC.getLength()) * (p - AC.getLength()));
}
void Triangle::setAB(Side ab) {
    AB = ab;
}
void Triangle::setAC(Side ac) {
    AC = ac;
}
void Triangle::setBC(Side bc) {
    BC = bc;
}
void Triangle::getTriangle() {
    cout << "AB = " << AB.getLength() << endl;
    cout << "AC = " << AC.getLength() << endl;
    cout << "BC = " << BC.getLength() << endl;
}

Triangle Triangle::operator++() {
    AB.setLength(AB.getLength() + 1);
    AC.setLength(AC.getLength() + 1);
    BC.setLength(BC.getLength() + 1);
    return *this;
}
Triangle Triangle::operator--() {
    AB.setLength(AB.getLength() - 1);
    AC.setLength(AC.getLength() - 1);
    BC.setLength(BC.getLength() - 1);
    return *this;
}

Triangle Triangle::operator+=(int n) {
    AB.setLength(AB.getLength() + n);
    AC.setLength(AC.getLength() + n);
    BC.setLength(BC.getLength() + n);
    return *this;
}

Triangle Triangle::operator-=(int n) {
    AB.setLength(AB.getLength() - n);
    AC.setLength(AC.getLength() - n);
    BC.setLength(BC.getLength() - n);
    return *this;
}

Point::Point(int x1, int y1, int z1) {
    x = x1;
    y = y1;
    z = z1;
}
double Point::distance(Point p) {
    double dx = p.x - x;
    double dy = p.y - y;
    double dz = p.z - z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

Side::Side() {
    A = Point(0, 0, 0);
    B = Point(0, 0, 0);
}

Side::Side(Point A1, Point B1) {
    A = A1;
    B = B1;
    length = A.distance(B);
}

void Side::setLength(double l) {
    length = l;
}

double Side::getLength() {
    return length;
}

void printTriangle(Triangle t1, Triangle t2, Triangle t3){
    cout << "T1:" << endl;
    t1.getTriangle();
    double s1 = t1.area();
    cout << "Area T1 = " << s1 << endl;
    cout << "T2:" << endl;
    t2.getTriangle();
    double s2 = t2.area();
    cout << "Area T2 = " << s2 << endl;
    cout << "T3:" << endl;
    t3.getTriangle();
    double s3 = t3.area();
    cout << "Area T3 = " << s3 << endl;
}

void findMaxAreaTriangle(Triangle t1, Triangle t2, Triangle t3) {
    double maxArea = 0.0;
    string name = "";
    Triangle maxAreaTriangle;
    double area1 = t1.area();
    if (area1 > maxArea) {
        maxArea = area1;
        maxAreaTriangle = t1;
        name = "T1";
    }
    double area2 = t2.area();
    if (area2 > maxArea) {
        maxArea = area2;
        maxAreaTriangle = t2;
        name = "T2";
    }
    double area3 = t3.area();
    if (area3 > maxArea) {
        maxArea = area3;
        maxAreaTriangle = t3;
        name = "T3";
    }
    cout << "Triangle with maximum area: " << name << endl;
    double s = maxAreaTriangle.area();
    cout << "Area = " << s << endl;
}
