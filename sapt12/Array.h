//
// Created by cata-884 on 5/14/25.
//

#ifndef ARRAY_H
#define ARRAY_H
#include <exception>
#include<iostream>

class exceptie1 : std::exception {
    virtual const char* what() const noexcept
    {
        return "eroare lil bro";
    }
};
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2);
};
template<class T>
class ArrayIterator
{
private:
    int current; // mai adaugati si alte date si functii necesare pentru iterator
public:
    T** element;
    ArrayIterator();
    ArrayIterator& operator ++ ();
    ArrayIterator& operator -- ();
    ArrayIterator<T>& operator= (ArrayIterator<T> &);
    bool operator!=(ArrayIterator<T> &);
    T* GetElement();
};

template<class T>
class Array
{
private:
    T** list; // lista cu pointeri la obiecte de tipul T*
    int capacity; // dimensiunea listei de pointeri
    int size; // cate elemente sunt in lista
public:
    Array(); // Lista nu e alocata, Capacity si Size = 0
    ~Array(); // destructor
    Array(int capacity); // Lista e alocata cu 'capacity' elemente
    Array(const Array<T> &otherArray); // constructor de copiere

    T& operator[] (int index); // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T &newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T &newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T> &otherArray);
    void Sort(); // sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
    void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator

    int GetSize();
    int GetCapacity();

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
};



#endif //ARRAY_H
