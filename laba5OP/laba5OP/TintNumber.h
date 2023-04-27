#pragma once
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class TintNumber {
protected:
    string num; 
    int base; 
public:
    TintNumber() {
        num = "";  
        base = 0;  
    };
    TintNumber(string num, int base) : num(num), base(base) {}
    void increment();
    void decrement();
    int toDecimal();
    void setNum(string _num, int _base);
    string getNum();
    
};

class TintNumber2 : public TintNumber {
public:
    TintNumber2() {}
    TintNumber2(string num): TintNumber(num, 2){}
    void increment();
};

class TintNumber16 : public TintNumber {
public:
    TintNumber16(): TintNumber() {}
    TintNumber16(string num):TintNumber(num, 16) {  }
    void decrement();
private:
    // функції для конвертації між шістнадцятковою та десятковою системами числення
    int hexToDecimal(char hex);
    char decimalToHex(int decimal);
};

int findmax2(TintNumber2* arr, int size);
int findmax16(TintNumber16* arr, int size);