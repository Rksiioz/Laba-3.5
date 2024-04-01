#include "Classes.h"

Array::Array(int newSize, int initValue) {
    if (newSize < 0 || newSize > MAX_DIGITS) {
        throw std::invalid_argument("Invalid size for array");
    }
    size = newSize;
    for (int i = 0; i < size; ++i) {
        data[i] = initValue;
    }
}

int& Array::operator[](int index) {
    rangeCheck(index);
    return data[index];
}

void Array::rangeCheck(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
}

const int *Array::getData() const {
    return data;
}

int Array::getSize() const {
    return size;
}

void Array::setSize(int size) {
    Array::size = size;
}

Money::Money(int newSize, int initValue) : Array(newSize, initValue) {
    if (newSize > MAX_DIGITS) {
        throw std::invalid_argument("Invalid size for Money");
    }
}

Money::Money() : Array(3, 0) {
}

std::string Money::toString() const {
    std::string result = "$";
    bool decimalAdded = false;
    for (int i = 0; i < size; ++i) {
        if (!decimalAdded && i == size - 2) {
            result += ".";
            decimalAdded = true;
        }
        result += std::to_string(data[i]);
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Money& money) {
    os << money.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Money& money) {
    std::string input;
    is >> input;
    if (input[0] != '$') {
        throw std::invalid_argument("Invalid money format");
    }
    int index = 1;
    for (int i = 0; i < money.size; ++i) {
        if (input[index] == '.') {
            ++index;
        }
        if (!isdigit(input[index])) {
            throw std::invalid_argument("Invalid money format");
        }
        money[i] = input[index] - '0';
        ++index;
    }
    return is;
}