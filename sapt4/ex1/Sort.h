//
// Created by cata-884 on 3/19/25.
//

#ifndef SORT_H
#define SORT_H
#include<vector>
#include<ctime>
#include<cstdlib>
#include<stdarg.h>
#include<initializer_list>
#include<iostream>
class Sort {
private:
    std::vector<int> v;
public:
    Sort(int count, int maximum, int minimum);
    Sort(std::initializer_list<int> list); // Initializer list
    Sort(const std::vector<int>& vec, int numElements); // From vector
    Sort(const char* str); // From string
    Sort(int count, ...); // Variadic constructor

    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false, int low = 0, int high = 0);
    void BubbleSort(bool ascendent=false);

    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);

};



#endif //SORT_H
