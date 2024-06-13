
#ifndef DIRECTORY_OF_CARS_BUS_H
#define DIRECTORY_OF_CARS_BUS_H

#include <iostream>
#include "Vehicle.h"
using namespace std;

class Bus :public Vehicle {
    int passenger_capacity;
public:
    Bus();
    ~Bus();
};


#endif //DIRECTORY_OF_CARS_BUS_H
