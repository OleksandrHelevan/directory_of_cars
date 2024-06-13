
#ifndef DIRECTORY_OF_CARS_CAR_H
#define DIRECTORY_OF_CARS_CAR_H

#include <iostream>
#include "Vehicle.h"
using namespace std;

class Car: public Vehicle {
string wheel_drive;
string transmission;
public:
    Car();
    ~Car();
};


#endif //DIRECTORY_OF_CARS_CAR_H
