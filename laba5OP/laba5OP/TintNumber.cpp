#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "TintNumber.h"


void TintNumber::increment() {
    // збільшення числа на одиницю відповідно до системи числення
    int carry = 1;
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit = (num[i] >= '0' && num[i] <= '9') ? num[i] - '0' : num[i] - 'A' + 10;
        digit += carry;
        carry = digit / base;
        digit %= base;
        if (digit < 10) {
            num[i] = digit + '0';
        }
        else {
            num[i] = digit - 10 + 'A';
        }
        if (carry == 0) {
            break;
        }
    }
    if (carry > 0) {
        num = "1" + num;
    }
}

void TintNumber::decrement() {
    // зменшення числа на одиницю відповідно до системи числення
    int borrow = 1;
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit = (num[i] >= '0' && num[i] <= '9') ? num[i] - '0' : num[i] - 'A' + 10;
        digit -= borrow;
        if (digit < 0) {
            digit += base;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        if (digit < 10) {
            num[i] = digit + '0';
        }
        else {
            num[i] = digit - 10 + 'A';
        }
    }
    while (num.length() > 1 && num[0] == '0') {
        num.erase(0, 1);
    }
}

int TintNumber::toDecimal() {
    // переведення числа у десяткову систему числення
    int decimal = 0;
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit = (num[i] >= '0' && num[i] <= '9') ? num[i] - '0' : num[i] - 'A' + 10;
        decimal += digit * pow(base, num.length() - 1 - i);
    }
    return decimal;
}
string TintNumber::getNum() {
    return num;
}

void TintNumber2::increment() {
    // збільшення числа на одиницю в двійковій системі числення
    //cout << "iiiii" << endl;
    int carry = 1;
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit = num[i] - '0';
        digit += carry;
        carry = digit / base;
        digit %= base;
        num[i] = digit + '0';
        if (carry == 0) {
            break;
        }
    }
    if (carry > 0) {
        num = "1" + num;
    }
}

void TintNumber::setNum(string _num, int _base) {
    num = _num;
    base = _base;
}

void TintNumber16::decrement() {
    // зменшення числа на одиницю в шістнадцятковій системі числення
    //cout << "ddddd" << endl;
    int carry = -1;
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit = hexToDecimal(num[i]);
        digit += carry;
        if (digit < 0) {
            digit += base;
            carry = -1;
        }
        else {
            carry = 0;
        }
        num[i] = decimalToHex(digit);
        if (carry == 0) {
            break;
        }
    }
    // видалення лідуючих нулів
    while (num.length() > 1 && num[0] == '0') {
        num.erase(0, 1);
    }
}

int TintNumber16::hexToDecimal(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    }
    else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    }
    else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    }
    return 0;
}

char TintNumber16::decimalToHex(int decimal) {
    if (decimal >= 0 && decimal <= 9) {
        return decimal + '0';
    }
    else if (decimal >= 10 && decimal <= 15) {
        return decimal - 10 + 'A';
    }
    return '0';
}

int findmax2(TintNumber2* arr, int size) {
    int max = arr[0].toDecimal();
    for (int i = 1; i < size; i++) {
        int dec = arr[i].toDecimal();
        if (dec > max) {
            max = dec;
        }
    }
    return max;
}

int findmax16(TintNumber16* arr, int size) {
    int max = arr[0].toDecimal();
    for (int i = 1; i < size; i++) {
        int dec = arr[i].toDecimal();
        if (dec > max) {
            max = dec;
        }
    }
    return max;
}