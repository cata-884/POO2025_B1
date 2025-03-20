//
// Created by cata-884 on 3/20/25.
//

#include "Sort.h"

Sort::Sort(int count, int maximum, int minimum) {
    srand(time(nullptr));
    for(int i=0; i<count; i++) {
        v.push_back(rand()%(maximum - minimum + 1) + minimum);
    }
}

Sort::Sort(const std::vector<int> &vec, int numElements) {
    for(int i=0; i<numElements; i++) {
        v.push_back(vec[i]);
    }
}
int isdigit(char c) {
    return (c>='0' && c<='9');
}
Sort::Sort(const char *str) {
    int i = 0;
    int num = 0;
    bool negative = false;

    while (str[i] != '\0') {
        if (str[i] == '-') {
            negative = true;
        } else if (str[i] == ',') {
            v.push_back(negative ? -num : num);
            num = 0;
            negative = false;
        } else if (isdigit(str[i])) {
            num = num * 10 + (str[i] - '0');
        }
        i++;
    }
    if (i > 0) {
        v.push_back(negative ? -num : num);
    }
}

Sort::Sort(int count, ...) {
    va_list args;
    va_start(args, count);
    for(int i=0; i<count; i++) {
        v.push_back(va_arg(args, int));
    }
}

Sort::Sort(Sort &&obj) { //move
    v = obj.v;
    obj.v.erase(v.begin(), v.end());
}
Sort::Sort(Sort &obj) { //copy
    v = obj.v;
}

Sort::Sort() {

}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < v.size(); ++i) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void Sort::QuickSort(bool ascendent, int low , int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        QuickSort(true, low, pi - 1);
        QuickSort(true, pi + 1, high);
    }
}

void Sort::BubbleSort(bool ascendent) {
    int n = v.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(&v[j], &v[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void Sort::Print() {
    for(int i=0; i<v.size(); i++) {
        std::cout<<v[i]<<" ";
    }
    std::cout<<"\n";
}

int Sort::GetElementsCount() {
    return v.size();
}

int Sort::GetElementFromIndex(int index) {
    if(index>=0 && index<v.size()) return v[index];
}

Sort Sort::operator+(Sort const &obj) { //optional
    Sort res(v, v.size());
    int n = obj.v.size();
    for(int i=0; i<n; i++) {
        res.v.push_back(obj.v[i]);
    }
    return res;
}

Sort Sort::operator!() {
    Sort res(v, v.size());
    for(int i=0; i<res.v.size(); i++) {
        res.v[i] = (res.v[i] == 0) ? 1 : 0;
    }
    return res;
}

Sort Sort::operator=(Sort const &obj) {
    if(this != &obj) {
        v.clear();
        for(int i=0; i<obj.v.size(); i++) {
            v.push_back(obj.v[i]);
        }
    }
    return *this;
}



