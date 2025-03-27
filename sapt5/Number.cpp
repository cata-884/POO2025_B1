#include "Number.h"
#include <cmath>
#include <stdexcept>

int Number::chtoi(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
}

char Number::itoch(int n) {
    if (n < 10) return '0' + n;
    return 'A' + (n - 10);
}
int str_size(const char *str) {
    int i=0;
    while(str[i]!='\0') i++;
    return i;
}
void strcpy1(char *str1, const char *str2) {
    while(*str2) {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}
int Number::toDecimal() const {
    int result = 0;
    for (int i = 0; value[i]; ++i) {
        result = result * base + chtoi(value[i]);
    }
    return result;
}

void Number::fromDecimal(int n, int newBase) {
    char buffer[65];
    int i = 64;
    buffer[i] = 0;
    do {
        buffer[--i] = itoch(n % newBase);
        n /= newBase;
    } while (n > 0);
    delete[] value;
    value = new char[65 - i];
    strcpy1(value, buffer + i);
    base = newBase;
}

Number::Number(const char* str, int newBase){
    value = new char[str_size(str) + 1];
    strcpy1(value, str);
    base = newBase;
}

Number::Number(int n){
    fromDecimal(n, 10);
    base = 10;
}

Number::Number(const Number& other){
    value = new char[str_size(other.value) + 1];
    strcpy1(value, other.value);
    base = other.base;
}

Number::Number(Number&& other){
    value = other.value;
    base = other.base;
    delete[] other.value;
    other.value = nullptr;
}

Number::~Number() {
    delete[] value;
    value = nullptr;
}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] value;
        base = other.base;
        value = new char[strlen(other.value) + 1];
        strcpy1(value, other.value);
    }
    return *this;
}

Number& Number::operator=(Number&& other){
    if (this != &other) {
        delete[] value;
        value = other.value;
        base = other.base;
        other.value = nullptr;
    }
    return *this;
}

Number& Number::operator=(int val) {
    fromDecimal(val, base);
    return *this;
}

Number& Number::operator=(const char* val) {
    delete[] value;
    value = new char[strlen(val) + 1];
    strcpy1(value, val);
    return *this;
}

void Number::SwitchBase(int newBase) {
    int decimal = toDecimal();
    fromDecimal(decimal, newBase);
}

void Number::Print() const {
    std::cout<<value<<" "<<base<<std::endl;
}

int Number::GetDigitsCount() const {
    return str_size(value);
}

int Number::GetBase() const {
    return base;
}

char Number::operator[](int index) const {
    return value[index];
}

Number operator+(const Number& a, const Number& b) {
    int resultBase = std::max(a.base, b.base);
    int sum = a.toDecimal() + b.toDecimal();
    Number res("0", resultBase);
    res.fromDecimal(sum, resultBase);
    return res;
}

Number operator-(const Number& a, const Number& b) {
    int resultBase = std::max(a.base, b.base);
    int diff = a.toDecimal() - b.toDecimal();
    Number res("0", resultBase);
    res.fromDecimal(diff, resultBase);
    return res;
}

bool Number::operator>(const Number& other) const {
    return toDecimal() > other.toDecimal();
}

bool Number::operator<(const Number& other) const {
    return toDecimal() < other.toDecimal();
}

bool Number::operator>=(const Number& other) const {
    return toDecimal() >= other.toDecimal();
}

bool Number::operator<=(const Number& other) const {
    return toDecimal() <= other.toDecimal();
}

bool Number::operator==(const Number& other) const {
    return toDecimal() == other.toDecimal();
}

bool Number::operator!=(const Number& other) const {
    return toDecimal() != other.toDecimal();
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

Number& Number::operator--() {
    int len = strlen(value);
    if (len > 1) {
        memmove(value, value + 1, len);
    } else {
        value[0] = '0';
        value[1] = 0;
    }
    return *this;
}

Number Number::operator--(int) {
    Number temp = *this;
    int len = strlen(value);
    if (len > 1) {
        value[len - 1] = 0;
    } else {
        value[0] = '0';
        value[1] = 0;
    }
    return temp;
}
