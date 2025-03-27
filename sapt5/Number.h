#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <cstring>

class Number {
private:
    char* value;
    int base;

public:
    static int chtoi(char c);
    static char itoch(int val);
    int toDecimal() const;
    void fromDecimal(int val, int targetBase);
    Number(const char* value, int base);

    Number(int val);
    Number(const Number& other);
    Number(Number&& other);
    ~Number();

    Number& operator=(const Number& other);
    Number& operator=(Number&& other);
    Number& operator=(int val);
    Number& operator=(const char* val);

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

    char operator[](int index) const;

    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);

    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;

    Number& operator+=(const Number& other);

    Number& operator--();
    Number operator--(int);
};

#endif
