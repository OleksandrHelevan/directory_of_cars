
#ifndef DIRECTORY_OF_CARS_TRAILER_CAR_H
#define DIRECTORY_OF_CARS_TRAILER_CAR_H

#include <iostream>
#include "Car.h"
#include "Trailer.h"
using namespace std;


class Trailer_Car: public Car{
Trailer trailer;

public:
    Trailer_Car();
    ~Trailer_Car();
};


#endif //DIRECTORY_OF_CARS_TRAILER_CAR_H
