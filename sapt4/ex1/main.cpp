#include <iostream>
#include "Sort.h"
int main() {
    Sort s1(10, 100, 1);
    std::cout << "generare random:" << std::endl;
    s1.Print();

    Sort s2({10, 20, 30, 40, 50});
    std::cout << "\ngenerare dintr-o lista:" << std::endl;
    s2.Print();

    std::vector<int> vec = {5, 15, 25, 35, 45};
    Sort s3(vec, vec.size());
    std::cout << "\ngenerare dintr-un vector:" << std::endl;
    s3.Print();

    Sort s4("10,20,30,40,50");
    std::cout << "\ngenerare dintr-un  sir de caractere:" << std::endl;
    s4.Print();

    Sort s5(4, 1, 2, 3, 4);
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
    return 0;
}
