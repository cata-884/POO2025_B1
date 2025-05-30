//
// Created by cata-884 on 5/29/25.
//

#ifndef ROMANA_H
#define ROMANA_H
#include"Materie.h"


class Romana : public Materie{
    int credite() override {
        return 3;
    }
    string nume() override {
        return "Romana";
    }
    int obligatoriu() override {
        return 1;
    }
};



#endif //ROMANA_H
