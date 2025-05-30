//
// Created by cata-884 on 5/29/25.
//

#ifndef MATERIE_H
#define MATERIE_H
#include<string>
using namespace std;

class Materie {
public:
    virtual ~Materie() = default;
    virtual int obligatoriu() = 0;
    virtual string nume() = 0;
    virtual int credite() = 0;
};



#endif //MATERIE_H
