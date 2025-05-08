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
    cnt = 0;
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

template<typename T1, typename T2>
void Map<T1, T2>::Set(T1 key, T2 value) {
    for(int i=0; i<cnt; i++) {
        if(elements[i].value = value) {
            elements[i].key= key;
        }
    }
    elements[cnt].key = key;
    elements[cnt].value = value;
    cnt++;
}

template<typename T1, typename T2>
bool Map<T1, T2>::Get(const T1 &key, T2 &value) {
    for(int i=0; i<cnt; i++) {
        if(elements[i].key == key) {
            value = elements[i].value;
            return 1;
        }
    }
    return 0;
}

template<typename T1, typename T2>
int Map<T1, T2>::Count() {
    return cnt;
}

template<typename T1, typename T2>
void Map<T1, T2>::Clear() {
    delete[] elements;
    cnt = 0;
}

template<typename T1, typename T2>
bool Map<T1, T2>::Delete(const T1 &key) {
    int poz;
    for(int i=0; i<cnt; i++) {
        if(elements[i].key = key) {
            poz = i;
            break;
        }
    }
    while(poz<cnt-1) {
        elements[poz] = elements[poz+1];
        poz++;
    }
    cnt--;
}

template<typename T1, typename T2>
bool Map<T1, T2>::Includes(const Map<T1, T2> &map) {
    int sz = map.cnt;
    int ceva = sz;
    for(int i=0; i<sz && !ceva; i++) {
        for(int j=0; j<cnt && !ceva; j++) {
            if(map.elements[i].key == elements[j].key && map.elements[i].key == elements[j].key) {
                ceva--;
            }
        }
    }
    if(ceva) return 0;
    return 1;
}

template class Map<int, const char*>;
template class Map<int, int>;
