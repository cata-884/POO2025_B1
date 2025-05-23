//
// Created by cata-884 on 3/13/25.
//

#ifndef MATH_H
#define MATH_H



class Math {
public:
    static int Add(int a,int b);
    static int Add(int a,int b,int c);
    static int Add(double a, double b);
    static int Add(double a, double b, double c);
    static int Mul(int a,int b);
    static int Mul(int a, int b, int c);
    static int Mul(double a, double b);
    static int Mul(double a, double b, double c);
    static int Add(int count,...); // sums up a list of integers
    static char* Add(const char * str1, const char * str2);
};



#endif //MATH_H
