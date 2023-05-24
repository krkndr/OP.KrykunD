#include <string>
#include <cmath>
#include <iostream>
#include "struct.h"
using namespace std;


template<typename T>
MyArray<T>::Iterator::Iterator(value_type* c, value_type* e) {
    current = c;
    end = e;
}

template<typename T>
typename MyArray<T>::Iterator::value_type& MyArray<T>::Iterator::operator*() {
    return *current;
}

template<typename T>
typename MyArray<T>::Iterator& MyArray<T>::Iterator::operator++() {
    ++current;
    return *this;
}

template<typename T>
typename MyArray<T>::Iterator MyArray<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
bool MyArray<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

template<typename T>
void MyArray<T>::Iterator::advance(int n) {
    current += n;
    if (current > end) {
        current = end;
    }
}

template<typename T>
MyArray<T>::MyArray(int s) {
    size = s;
    data = new T[size]();
}

template<typename T>
MyArray<T>::~MyArray() {
    delete[] data;
}

template<typename T>
int MyArray<T>::getSize() {
    return size;
}

template<typename T>
bool MyArray<T>::checkEmpty() {
    return size == 0;
}

template<typename T>
int MyArray<T>::findValue(const T& value) {
    Iterator it = begin();
    Iterator endIt = end();
    int index = 0;
    while (it != endIt) {
        if (*it == value) {
            return index;
        }
        ++it;
        ++index;
    }
    return -1;
}

template<typename T>
void MyArray<T>::insert(const Iterator& pos, const T& val) {
    int index = pos.current - data;
    if (index < 0 || index > size) {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    T* newData = new T[size + 1];
    Iterator it = begin();
    for (int i = 0; i < index; i++) {
        newData[i] = *it;
        it++;
    }
    newData[index] = val;
    for (int i = index; i < size; i++) {
        newData[i + 1] = *it;
        it++;
    }
    delete[] data;
    data = newData;
    size++;
}

template<typename T>
typename MyArray<T>::Iterator MyArray<T>::begin() {
    return Iterator(data, data + size);
}

template<typename T>
typename MyArray<T>::Iterator MyArray<T>::end() {
    return Iterator(data + size, data + size);
}

template<typename T>
void MyArray<T>::getArray() {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
T& MyArray<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        std::cout << "Invalid index" << std::endl;
    }
    return data[index];
}


template <typename TYPE>
void testMyArray() {
    
    int n;
    cout << "The number of elements in the array:";
    cin >> n;
    MyArray<TYPE> arr(n);
    
    cout << "Enter items with a space:";
    typename MyArray<TYPE>::Iterator it = arr.begin();
    typename MyArray<TYPE>::Iterator end = arr.end();

    while (it != end) {
        TYPE e;
        cin >> e;
        *it = e;
        ++it;
    }
    arr.getArray();

    int s = arr.getSize();
    
    cout << endl << "1)Array size:" << s << endl << endl;;

    TYPE value;
    cout << "2)Enter the value whose index you want to search for:";
    cin >> value;
    int index = arr.findValue(value);
    if (index != -1) { cout << "Value found at index " << index << endl << endl; }
    else { cout << "Value not found" << endl << endl; }

    if (arr.checkEmpty()) { cout << "3)The array is empty" << endl << endl; }
    else { cout << "3)The array is not empty" << endl << endl; }

    cout << "4)Inserting an element at an arbitrary position" << endl;
    TYPE elem;
    cout << "Enter an item:";
    cin >> elem;
    int pos;
    cout << "Enter position:";
    cin >> pos;
    typename MyArray<TYPE>::Iterator it_ = arr.begin();
    if (pos < 0 || pos > arr.getSize()) {
        cout << "Invalid position" << endl;
    }
    else {
        it_.advance(pos);
        arr.insert(it_, elem);
    }
    arr.getArray();
}

void ArrInsert() {

    string type;
    cout << "----Creating an array of arbitrary size and type----" << endl << endl;
    cout << "Type of elements:";
    cin >> type;
    if (type == "int") {
        testMyArray<int>();
    }
    else if (type == "double") {
        testMyArray<double>();
    }
    else if (type == "char") {
        testMyArray<char>();
    }


}