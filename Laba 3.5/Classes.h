#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
const int MAX_DIGITS = 100;

class Array {
protected:
    int data[MAX_DIGITS];
    int size;
public:
    const int *getData() const;
    int getSize() const;
    void setSize(int size);

    Array(int newSize = 0, int initValue = 0);
    virtual ~Array() {}
    int& operator[](int index);
    void rangeCheck(int index) const;

};

class Money : public Array {
public:
    Money(int newSize = 0, int initValue = 0);
    Money();
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Money& money);
    friend std::istream& operator>>(std::istream& is, Money& money);
};