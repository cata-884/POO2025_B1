//
// Created by cata-884 on 5/29/25.
//

#ifndef INFOMATICA_H
#define INFOMATICA_H
#include"Materie.h"


class Infomatica : public Materie{
    string nume() override {
        return "Informatica";
    }
    int obligatoriu() override {
        return 2;
    }
    int credite() override {
        return 10;
    }
};



#endif //INFOMATICA_H
