#define _CRT_SECURE_NO_WARNINGS
#define _XOPEN_SOURCE
#include "triangle.h"
#include <string>
#include <iostream>




using namespace std;



int main()
{
	cout << "Enter the vertices of the first triangle:" << endl;
	int x, y, z;
    cout << "Enter coordinates of vertex A (in the format x y z):";
	cin >> x >> y >> z;
	Point A1(x, y, z);
	cout << "Enter coordinates of vertex B (in the format x y z):";
	cin >> x >> y >> z;
	Point B1(x, y, z);
	cout << "Enter coordinates of vertex C (in the format x y z):";
	cin >> x >> y >> z;
	Point C1(x, y, z);
	Side AB1(A1, B1);
	Side AC1(A1, C1);
	Side BC1(B1, C1);
	Triangle T1(AB1, AC1, BC1);
	cout << endl;

	cout << "Enter the vertices of the second triangle:" << endl;
	cout << "Enter coordinates of vertex A (in the format x y z):";
	cin >> x >> y >> z;
	Point A2(x, y, z);
	cout << "Enter coordinates of vertex B (in the format x y z):";
	cin >> x >> y >> z;
	Point B2(x, y, z);
	cout << "Enter coordinates of vertex C (in the format x y z):";
	cin >> x >> y >> z;
	Point C2(x, y, z);
	Side AB2(A2, B2);
	Side AC2(A2, C2);
	Side BC2(B2, C2);
	Triangle T2(AB2, AC2, BC2);
	cout << endl;

	cout << "Enter the vertices of the third triangle:" << endl;
	cout << "Enter coordinates of vertex A (in the format x y z):";
	cin >> x >> y >> z;
	Point A3(x, y, z);
	cout << "Enter coordinates of vertex B (in the format x y z):";
	cin >> x >> y >> z;
	Point B3(x, y, z);
	cout << "Enter coordinates of vertex C (in the format x y z):";
	cin >> x >> y >> z;
	Point C3(x, y, z);
    Side AB3(A3, B3);
	Side AC3(A3, C3);
	Side BC3(B3, C3);
	Triangle T3;
	T3.setAB(AB3);
	T3.setAC(AC3);
	T3.setBC(BC3);
	cout << endl;

	printTriangle(T1, T2, T3);
	cout << endl;
	++T1;
	--T2;
	int n;
	cout << "Enter a number: ";
	cin >> n;
	cout << endl;
	T3 += n;
	printTriangle(T1, T2, T3);
	findMaxAreaTriangle(T1, T2, T3);
    return 0;
}