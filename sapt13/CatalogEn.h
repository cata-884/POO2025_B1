//
// Created by cata-884 on 5/29/25.
//

#ifndef CATALOGEN_H
#define CATALOGEN_H
#include "Catalog.h"
#include "Materie.h"
#include "Student.h"


class CatalogEn : public Catalog{
    vector<Student*> students;
public:
    double getMedie(Student *st) override {
        return st->getMedie();
    }
    int getNota(Student *st, Materie* mat) override {
        vector<pair<Materie*, int>> mater = st->getMat();
        for(int i=0; i<st->getSize(); i++) {
            if(mater[i].first == mat) return mater[i].second;
        }
        return -1;
    }
    Catalog& operator+=(Student& st) override {
        students.push_back(&st);
        return *this;
    }
    void printStudents() override {
        for(auto i : students) {
            i->printData();
        }
    }
    void ranking() override {
        sort(students.begin(), students.end(), [](const Student *s1, const Student *s2) {
            return s1->getMedie() > s2->getMedie();
        });
        printStudents();
    }

    vector<Student*> filter(function<bool(Student*)> funct) override {
        vector<Student*> st;
        for(auto i : students) {
            if(funct(i)) {
                st.push_back(i);
            }
        }
        return st;
    }
};



#endif //CATALOGEN_H
