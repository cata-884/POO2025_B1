//
// Created by cata-884 on 5/29/25.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <memory>
#include <vector>
#include"Materie.h"
using namespace std;



class Student {
    string nume;
    int nr_matricol;
    vector<pair<Materie*, int>> materii;
public:
    Student(const string &n, const int &nr) {
        nume = n;
        nr_matricol = nr;
    }
    Student(const string &n, const int &nr, Materie* mat, int nota) {
        nume = n;
        nr_matricol = nr;
        materii.emplace_back(mat, nota);
    }
    Student& operator+=(pair<Materie*, int> materie) {
        materii.emplace_back(materie.first, materie.second);
        return *this;
    }
    Student& operator=(pair<Materie*, int> materie) {
        materii.clear();
        materii.emplace_back(materie.first, materie.second);
        return *this;
    }
    string getNume() {
        return nume;
    }
    [[nodiscard]] int getNr() const {
        return nr_matricol;
    }
    vector<pair<Materie*, int>> getMat() {
        return materii;
    }
    [[nodiscard]] int getSize() const {
        return static_cast<int>(materii.size());
    }
    void printData() const {
        cout<<"nume: "<<nume<<"; nr matricol: " << nr_matricol<<" \n";
        for(auto i : materii) {
            cout<<i.first->nume()<<" "<<i.second<<endl;
        }
        cout<<endl<<endl;
    }
    [[nodiscard]] double getMedie() const {
        double med = 0;
        for(auto [fst, snd] : materii) {
            med+=snd;
        }
        return static_cast<double>(med/static_cast<int>(materii.size()));
    }
};



#endif //STUDENT_H
