//
// Created by cata-884 on 5/29/25.
//

#ifndef MATEMATICA_H
#define MATEMATICA_H
#include"Materie.h"


class Matematica : public Materie{
public:
    int credite() override {
        return 5;
    }
    string nume() override {
        return "Matematica";
    }
    int obligatoriu() override {
        return 0;
    }
};



#endif //MATEMATICA_H
