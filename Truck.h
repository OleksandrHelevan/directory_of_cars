#ifndef DIRECTORY_OF_CARS_TRUCK_H
#define DIRECTORY_OF_CARS_TRUCK_H

#include <iostream>
#include "Vehicle.h"
using namespace std;

class Truck :public Vehicle{
int cargo_capacity;

public:
    Truck();
    ~Truck();
};


#endif //DIRECTORY_OF_CARS_TRUCK_H
