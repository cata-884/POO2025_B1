//
// Created by cata-884 on 5/29/25.
//

#ifndef CATALOG_H
#define CATALOG_H
#include<functional>
#include"Student.h"

class Catalog {
public:
    virtual ~Catalog() = default;

private:
    virtual int getNota(Student *st, Materie* mat) = 0;
    virtual Catalog& operator+=(Student& st) = 0;
    virtual double getMedie(Student* st) = 0;
    virtual void printStudents() = 0;
    virtual void ranking() = 0;
    virtual vector<Student*> filter(function<bool(Student*)> funct) = 0;
};



#endif //CATALOG_H
