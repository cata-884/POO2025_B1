//
// Created by cata-884 on 4/2/25.
//

#ifndef CIRCUIT_H
#define CIRCUIT_H

#include"Car.h"
class Circuit {
protected:
    Car *cars[64];
    int car_num;
    double length;
    Weather weather;
    double time_for_each[64];
public:
    Circuit();
    void AddCar(Car* obj);
    void SetLength(double n);
    void SetWeather(Weather weather);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};



#endif //CIRCUIT_H
