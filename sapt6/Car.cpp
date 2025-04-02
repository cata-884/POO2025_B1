//
// Created by cata-884 on 4/1/25.
//

#include "Car.h"

#define endl "\n"
#define max 64
Car::Car() {
    nume = new char[max];
    fuel_capacity=0;
    fuel_consumption=0;
}

void Car::setCap(double n) {
    fuel_capacity = n;
}

void Car::setCons(double n) {
    fuel_consumption = n;
}

char* Car::getName() {
    return nume;
}

void Car::setDefaultSpeed(double n) {
    default_speed = n;
}

double Car::getMaxDistance() {
    return 10000*fuel_capacity/ fuel_consumption;
}

double Car::raceTimeInHours(double length, Weather weather) {
    double current_speed = default_speed * ((double)(int)weather / 100.0 + 1.0);
    return length/current_speed;
}



