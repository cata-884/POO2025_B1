//
// Created by cata-884 on 4/1/25.
//

#ifndef CAR_H
#define CAR_H

#define max 64
#include<iostream>
#include<string.h>
enum class Weather {Rain=75, Sunny=100, Snow=50}; //speed multiplier

class Car {
protected:
  char* nume;
  double fuel_capacity;
  double fuel_consumption;
  double default_speed;
  double max_distance;
  public:
  Car();
  void setCap(double n);
  void setCons(double n);
  char* getName();
  void setDefaultSpeed(double n);
  double getMaxDistance();
  virtual double raceTimeInHours(double length, Weather weather);
};







#endif //CAR_H
