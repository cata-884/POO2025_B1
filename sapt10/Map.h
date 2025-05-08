//
// Created by cata-884 on 5/4/25.
//

#ifndef MAP_H
#define MAP_H

const unsigned int size = 100;
#include <tuple>

template<typename T1, typename T2>
struct Pair {
    T2 value; //char
    T1 key; //int
};
template<typename T1, typename T2>
class Map {
    Pair<T1, T2>* elements;
    int cnt;
public:
    Map();
    ~Map();
    T2& operator[](T1 key);
    void Set(T1 key, T2 value);
    bool Get(const T1& key, T2& value);
    int Count();
    void Clear();
    bool Delete(const T1& key);
    bool Includes(const Map<T1,T2>& map);
    struct Iterator {
        Pair<T1, T2>* ptr;
        int index;
        auto operator*() const {
            return std::make_tuple(ptr->key, ptr->value, index);
        }
        Iterator& operator++() {
            ptr++;
            index++;
            return *this;
        }
        bool operator!=(const Iterator &obj) const {
            return ptr!=obj.ptr;
        }
    };
    Iterator begin() {
        return {elements, 0};
    }
    Iterator end() {
        return {elements+cnt, cnt};
    }

};

#endif //MAP_H
