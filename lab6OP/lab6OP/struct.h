#pragma once
#include <iostream>


template <typename T>
class MyArray {
private:
    T* data;
    int size;
public:
    class Iterator {
    public:
        T* current;
        T* end;
        using value_type = T;
        Iterator(value_type* c, value_type* e);
        value_type& operator*();
        Iterator& operator++();
        Iterator operator++(int);
        bool operator!=(const Iterator& other) const;
        void advance(int n);
    };
    MyArray(int s);
    ~MyArray();
    int getSize();
    bool checkEmpty();
    int findValue(const T& value);
    void insert(const Iterator& pos, const T& val);
    Iterator begin();
    Iterator end();
    void getArray();
    T& operator[](int index);
};

template <typename TYPE>
void testMyArray();

void ArrInsert();


