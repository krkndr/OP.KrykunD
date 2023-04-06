#pragma once
#ifndef NUMERIC_ARRAY_HPP
#define NUMERIC_ARRAY_HPP
#include <iostream>
using namespace std;

class NumericArray {
    int size;
    int* arr;
    int MaxElement;
    
public:
    NumericArray() : size(0), arr(nullptr), MaxElement(0) {}
    ~NumericArray();
    void setSize(size_t s);
    void setArray();
    void getArray();
    void updateMaxElement();
    int getMaxElement();
    
};

 void createArrays();
 int inputNumArrays();
 int inputSizeArray();
#endif
