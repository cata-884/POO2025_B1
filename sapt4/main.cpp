#include <iostream>
#include "Sort.h"
int main() {
    Sort s1(10, 100, 1);
    std::cout << "generare random:" << std::endl;
    s1.Print();

    std::vector<int> vec = {5, 15, 25, 35, 45};
    Sort s3(vec, vec.size());
    std::cout << "\ngenerare dintr-un vector:" << std::endl;
    s3.Print();

    Sort s4("10,20,30,40,50");
    std::cout << "\ngenerare dintr-un  sir de caractere:" << std::endl;
    s4.Print();

    Sort s5(4, 4, 3, 2, 1);
    std::cout << "\ngenerare dintr-un sir variadic:" << std::endl;
    s5.Print();

    std::cout << "\nbubblesort:" << std::endl;
    s5.BubbleSort(true);
    s5.Print();

    std::cout << "\ninsertion sort:" << std::endl;
    s5.InsertSort(false);
    s5.Print();

    std::cout << "\nquick sort:" << std::endl;
    s5.QuickSort(true, 0, s5.GetElementsCount() - 1);
    s5.Print();

    Sort s6 = Sort("4,0,6,2,10,12");
    Sort s7 = Sort(s6);
    std::cout<<"\nmove constructor list :\n";
    s7.Print();

    Sort s8 = s7;
    std::cout<<"\ncopy constructor list(intital era copy constructor, iar acum '=' operator test):\n";
    s8.Print();

    Sort s9 = s6 + s5;
    std::cout<<"\noperator overloading test:\n";
    s9.Print();

    std::cout<<"\noperator overloading test:\n";
    s9 = !s9;
    s9.Print();
    return 0;
}
