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
int getSize(int n) {
    int s = 0;
    while(n) {
        s++;
        n/=10;
    }
    return s;
}
char * Math::Add(const char *str1, const char *str2) {
    if(str1==nullptr || str2==nullptr) return nullptr;
    int n1=0, n2=0;
    int i1=0, i2=0;
    while(str1[i1]!='\0') {
        n1 = n1*10 + (str1[i1]-'0');
        i1++;
    }
    while(str2[i2]!='\0') {
        n2 = n2*10 + (str2[i2]-'0');
        i2++;
    }
    int n = n1+n2;
    char* res = (char*)malloc(getSize(n)+1);
    if(!res) return nullptr;
    res[getSize(n)] = '\0';
    for(int i=getSize(n)-1; i>=0; i--) {
        int digit =  n%10;
        res[i] = (digit+'0');
        n/=10;
    }
    return res;
}
//1234512

