//
// Created by cata-884 on 4/2/25.
//

#include "Circuit.h"
#define max 64
#define endl "\n"
Circuit::Circuit() {
    for(int i=0; i<max; i++) {
        cars[i] = new Car();
    }
    car_num = 0;
    length = 0;
    weather = Weather::Rain;
}

void Circuit::AddCar(Car *obj) {
    cars[car_num] = obj;
    car_num++;
}

void Circuit::SetLength(double n) {
    length = n;
}

void Circuit::SetWeather(Weather w) {
    weather = w;
}
void swap(Car *a, Car *b) {
    Car temp = *a;
    *a = *b;
    *b = temp;
}
void swap1(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}
void Circuit::Race() {
    for (int i = 0; i < car_num; i++) {
        double maxDist = cars[i]->getMaxDistance();
        if (maxDist >= length) {
            time_for_each[i] = cars[i]->raceTimeInHours(length, weather);
        } else {
            time_for_each[i] = -1;
        }
    }
    for (int i = 0; i < car_num - 1; i++) {
        for (int j = 0; j < car_num - 1; j++) {
            if (time_for_each[j] == -1) continue; // Don't move non-finishers
            if (time_for_each[j + 1] == -1) continue;
            if (time_for_each[j] > time_for_each[j + 1]) {
                swap(cars[j], cars[j + 1]);
                swap1(&time_for_each[j], &time_for_each[j + 1]);
            }
        }
    }
}
void Circuit::ShowFinalRanks() {
    for (int i = 0; i < car_num; i++) {
        if (time_for_each[i] == -1) continue;
        std::cout << cars[i]->getName() << ": " << time_for_each[i] << " ore" << endl;
    }
}

void Circuit::ShowWhoDidNotFinish() {
    for(int i=0; i<car_num; i++) {
        if(cars[i]->getMaxDistance()<length) {
            std::cout<<"\nnu a terminat "<<cars[i]->getName()<<endl;
        }
    }
}
