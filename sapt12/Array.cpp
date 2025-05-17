//
// Created by cata-884 on 5/14/25.
//

#include "Array.h"
template<class T>
int compare(const T &T1, const T &T2) {
        return T1>T2;
}
template<class T>
Array<T>::Array() {
    list = nullptr;
    size = 0;
    capacity = 0;
}

template<class T>
Array<T>::~Array() {
    if(list == nullptr) return;
    for(int i=0; i<capacity; i++) {
        delete[] list[i];
    }
    delete[] list;
    capacity = 0;
    size = 0;
}

template<class T>
Array<T>::Array(int capacity) {
    list = new T*[capacity];
    size = 0;
}

template<class T>
Array<T>::Array(const Array<T> &otherArray) {
    list = otherArray.list;
    capacity = otherArray.capacity;
    size = otherArray.size;
}

template<class T>
T & Array<T>::operator[](int index) {
    try {
        if(index>=size || index<0) {
            exceptie1 out_of_bounds;
            throw out_of_bounds;
        }
        return list[index];
    }
    catch(const std::exception& e){
        printf("exceptie lil bro: %s", e.what());
        throw;
    }
}

template<class T>
const Array<T> & Array<T>::operator+=(const T &newElem) {
    try {
        if(size == capacity) {
            exceptie1 overflow;
            throw overflow;
        }
        list[size] = newElem;
        size++;
    }
    catch (const std::exception &e) {
        printf("eroare lil bro %s \n", e.what());
    }
}

template<class T>
const Array<T> & Array<T>::Insert(int index, const T &newElem) {
    try {
        if(index>=capacity || index<0) {
            exceptie1 out_of_range;
            throw out_of_range;
        }
        list[index] = newElem;
    }
    catch (const std::exception &e) {
        printf("eroare lil bro %s \n", e.what());
    }
}

template<class T>
const Array<T> & Array<T>::Insert(int index, const Array<T> otherArray) {
    try {
        if(index>=capacity || index<0) {
            exceptie1 out_of_range;
            throw out_of_range;
        }
        list[index] = otherArray;
    }
    catch (const std::exception &e) {
        printf("eroare lil bro %s \n", e.what());
    }
}

template<class T>
const Array<T> & Array<T>::Delete(int index) {
    try {
        if(index>=capacity || index<0) {
            exceptie1 out_of_range;
            throw out_of_range;
        }
        delete[] list[index];
        while(index<size-1) {
            list[index] = list[index+1];
            index++;
        }
        size--;
    }
    catch (const std::exception &e) {
        printf("eroare lil bro %s \n", e.what());
    }
}

template<class T>
bool Array<T>::operator=(const Array<T> &otherArray) {
    if(otherArray.size != size) return 0;
    for(int i=0; i<size; i++) {
        if(list != otherArray.list) return 0;
    }
    return 1;
}

template<class T>
void Array<T>::Sort() {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1; j++) {
            if(list[j]<list[j+1]) std::swap(list[j], list[j+1]);
        }
    }
}

template<class T>
void Array<T>::Sort(int(*compare)(const T &, const T &)) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1; j++) {
            if(compare(list[j], list[j+1]) == 0) std::swap(list[j], list[j+1]);
        }
    }
}

template<class T>
void Array<T>::Sort(Compare *comparator) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1; j++) {
            if(comparator->CompareElements(list[j], list[j+1]) == 0) std::swap(list[j], list[j+1]);
        }
    }
}

template<class T>
int Array<T>::BinarySearch(const T &elem) {
    this->Sort();
    int l = 0, r = size-1   ;
    while(l<=r) {
        int h = (l+r)/2;
        if(list[h] == elem) return h;
        else if(list[h]>elem) l = h+1;
        else r = h-1;
    }
    return -1;
}

template<class T>
int Array<T>::BinarySearch(const T &elem, int(*compare)(const T &, const T &)) {
    this->Sort(compare);
    int l = 0, r = size-1;
    while(l<=r) {
        int h = (l+r)/2;
        if(list[h] == elem) return h;
        else if(list[h]>elem) l = h+1;
        else r = h-1;
    }
    return -1;
}

template<class T>
int Array<T>::BinarySearch(const T &elem, Compare *comparator) {
    this->Sort(comparator);
    int l = 0, r = size-1;
    while(l<=r) {
        int h = (l+r)/2;
        int comp_res = comparator->CompareElements(list[h], elem);
        if(comp_res == 1) return h;
        else if(comp_res == -1) l = h+1;
        else r = h-1;
    }
    return -1;
}

template<class T>
int Array<T>::GetSize() {
    return size;
}

template<class T>
int Array<T>::GetCapacity() {
    return capacity;
}

template<class T>
ArrayIterator<T> Array<T>::GetBeginIterator() {
    ArrayIterator<T> it;
    it.element = &list[0];
    return it;
}

template<class T>
ArrayIterator<T> Array<T>::GetEndIterator() {
    ArrayIterator<T> it;
    it.element = &list[size];
    return it;
}


template<class T>
ArrayIterator<T>::ArrayIterator() {
    element = nullptr;
}

template<class T>
ArrayIterator<T> & ArrayIterator<T>::operator++() {
    ++element;
}

template<class T>
ArrayIterator<T> & ArrayIterator<T>::operator--() {
    --element;
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator=(ArrayIterator<T> &other) {
    element = other.element;
    return *this;
}

template<class T>
bool ArrayIterator<T>::operator!=(ArrayIterator<T> &other) {
    return element !=other.element;
}

template<class T>
T * ArrayIterator<T>::GetElement() {
    return *element;
}

int Compare::CompareElements(void *e1, void *e2) {
    int* p1 = static_cast<int*>(e1);
    int* p2 = static_cast<int*>(e2);
    if(p1<p2) return 0;
    else if(p1>p2) return -1;
    else return 1;
}
