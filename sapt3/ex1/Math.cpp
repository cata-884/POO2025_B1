//
// Created by cata-884 on 3/13/25.
//

#include "Math.h"
#include<stdlib.h>
#include<stdarg.h>
int Math::Add(int a, int b) {
    return a+b;
}

int Math::Add(int a, int b, int c) {
    return a+b+c;
}

int Math::Add(double a, double b) {
    return a+b;
}

int Math::Add(double a, double b, double c) {
    return a+b+c;
}

int Math::Mul(int a, int b) {
    return a*b;
}

int Math::Mul(int a, int b, int c) {
    return a*b*c;
}

int Math::Mul(double a, double b) {
    return a*b;
}

int Math::Mul(double a, double b, double c) {
    return a*b*c;
}

int Math::Add(int count, ...) {
    va_list args;
    va_start(args, count);
    int s = 0;
    for(int i=0; i<count; i++) {
        s+=va_arg(args, int);
    }
    va_end(args);
    return s;
}
int maxim(int a, int b) {
    if(a>b) return a;
    if(a==b) return a+1; //sa avem unde pune carry-ul daca ambele au aceeasi marime
    return b;
}
int getSize(const char * str) {
    int i=0;
    while(str[i]!='\0') i++;
    return i;
}
char * Math::Add(const char *str1, const char *str2) {
    if(!(str1 && str2)) return nullptr;
    int a = getSize(str1), b = getSize(str2);
    int mx = maxim(a, b);
    int carry = 0;
    char* res = new char[mx+1];
    res[mx] = '\0';
    int i = a-1, j = b-1, k = mx-1;
    while(i>=0 || j>=0 || carry) {
        int digit1 = (i>=0) ? (str1[i]-'0') : 0;
        int digit2 = (j>=0) ? (str2[j]-'0') : 0;
        int sum = digit1 + digit2 + carry;
        res[k] = sum%10+'0';
        carry = sum/10;
        k--; i--; j--;
    }
    if(carry) {
        res[0] = carry;
        return res;
    }
    else {
        return res+1;
    }
}
//1234512

