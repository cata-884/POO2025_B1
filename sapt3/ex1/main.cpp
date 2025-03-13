#include <iostream>
#include "Math.h"
int main() {
    double a=6.2, b=3.1, c=2.8;
    int d = 6, e = 3, f = 2, x= 32, y = 21, z = 421;
    const char buff1[] = "2314", buff2[] = "4123";
    std::cout<<Math::Add(d, e, f)<<"\n";
    std::cout<<Math::Add(a, b)<<"\n";
    std::cout<<Math::Add(a, b, c)<<"\n";
    std::cout<<Math::Mul(d, e)<<"\n";
    std::cout<<Math::Mul(e, f, x)<<"\n";
    std::cout<<Math::Mul(a, b)<<"\n";
    std::cout<<Math::Mul(a, b, c)<<"\n";
    std::cout<<Math::Add(6, d, e, f, x, y, z)<<"\n";
    std::cout<<Math::Add(buff1, buff2)<<"\n";
    return 0;
}