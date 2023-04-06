#include "numeric_array.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

NumericArray::~NumericArray() {
    delete[] arr;
}

void NumericArray::setSize(size_t s) {
    size = s;
    arr = new int[size];
    for (size_t i = 0; i < s; i++) {
        arr[i] = 0;
    }
}

void NumericArray::setArray() {
    cout << "Enter " << size << " numbers:" << endl;
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void NumericArray::getArray() {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void NumericArray::updateMaxElement() {
    MaxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > MaxElement) {
            MaxElement = arr[i];
        }
    }
}

int NumericArray::getMaxElement() {
    return MaxElement;
}

int inputNumArrays()
{
    int numArrays;
    cout << "Enter number arrays: ";
    cin >> numArrays;
    return numArrays;
}

int inputSizeArray()
{
    int SizeArray;
    cout << "Enter size for array: ";
    cin >> SizeArray;
    return SizeArray;
}

void createArrays()
{
    int n = inputNumArrays();
    int s = inputSizeArray();
    cout << endl;
    NumericArray* Array = new NumericArray[n];
    for (int i = 0; i < n; i++) {
        Array[i].setSize(s);
        Array[i].setArray();
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        Array[i].getArray();
    }
    cout << endl;
    NumericArray* smallestMax = &Array[0];
    smallestMax->updateMaxElement();
    int smallestMaxValue = smallestMax->getMaxElement();
    for (int i = 1; i < n; i++) {
        Array[i].updateMaxElement();
        int max = Array[i].getMaxElement();
        if (max < smallestMaxValue) {
            smallestMaxValue = max;
            smallestMax = &Array[i];
        }
    }
    cout << "The object with the smallest maximal element: ";
    smallestMax->getArray();
    int maxEl = smallestMax->getMaxElement();
    cout << "Maximal Element: " << maxEl << endl;
    delete[] Array;
}





/*
NumericArray::NumericArray(const NumericArray& other) : size(other.size), arr(new int[other.size]), MaxElement(other.MaxElement) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}*/
