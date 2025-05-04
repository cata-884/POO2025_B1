#include "Map.h"
#include <stdexcept>

template<typename T1, typename T2>
Map<T1, T2>::Map() {
    elements = new Pair<T1, T2>[size];
    cnt = 0;
}

template<typename T1, typename T2>
Map<T1, T2>::~Map() {
    delete[] elements;
}

template<typename T1, typename T2>
T2& Map<T1, T2>::operator[](T1 key) {
    for(int i = 0; i < cnt; i++) {
        if(elements[i].key == key) {
            return elements[i].value;
        }
    }
    if(cnt < size) {
        elements[cnt].key = key;
        elements[cnt].value = T2();
        return elements[cnt++].value;
    }
}
template class Map<int, const char*>;
template class Map<int, int>;