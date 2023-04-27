#define _CRT_SECURE_NO_WARNINGS
#define _XOPEN_SOURCE

#include <string>
#include <cmath>
#include <iostream>
#include "TintNumber.h"
using namespace std;

int main() {
    
    int m;
    cout << "Enter the number of binary numbers: ";
    cin >> m;
    TintNumber2* arr2 = new TintNumber2[m];
    for (int i = 0; i < m; i++) {
        string s;
        cout << "Enter the number: ";
        cin >> s;
        arr2[i].setNum(s, 2);
    }

    int n;
    cout << "Enter the number of hexadecimal numbers: ";
    cin >> n;
    TintNumber16* arr16 = new TintNumber16[n];
    for (int i = 0; i < n; i++) {
        string s;
        cout << "Enter the number: ";
        cin >> s;
        arr16[i].setNum(s, 16);

    }
    cout << endl;

    for (int i = 0; i < m; i++) {
        arr2[i].increment();
        cout << arr2[i].getNum() << " -> Decimal representation: " << arr2[i].toDecimal() << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        arr16[i].decrement();
        cout << arr16[i].getNum() << " -> Decimal representation: " << arr16[i].toDecimal() << endl;
    }
    cout << endl;

    int max2 = findmax2(arr2, m);
    int max16 = findmax16(arr16, n);
    if (max2 > max16){cout << "Max value: " << max2 << endl; }
    else { cout << "Max value: " << max16 << endl; }

    delete[] arr2;
    delete[] arr16;
    
    return 0;
}