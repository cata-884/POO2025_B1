//
// Created by cata-884 on 3/20/25.
//

#ifndef SORT_H
#define SORT_H
#include<vector>
#include<ctime>
#include<cstdlib>
#include<cstdarg>
#include<iostream>

class Sort {
    std::vector<int> v;
public:
    Sort(int count, int maximum, int minimum);
    Sort(const std::vector<int>& vec, int numElements);
    Sort(const char* str);
    Sort(int count, ...);
    Sort(Sort&& obj); //move
    Sort(Sort& obj); //copy
    Sort(); //empty

    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false, int low = 0, int high = 0);
    void BubbleSort(bool ascendent=false);

    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);

    Sort operator+(Sort const& obj);
    Sort operator!();
    Sort operator=(Sort const& obj);

};



#endif //SORT_H
