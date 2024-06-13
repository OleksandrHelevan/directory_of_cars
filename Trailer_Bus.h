
#ifndef DIRECTORY_OF_CARS_TRAILER_BUS_H
#define DIRECTORY_OF_CARS_TRAILER_BUS_H

#include <iostream>
#include "Bus.h"
#include "Trailer.h"
using namespace std;


class Trailer_Bus: public Bus{
Trailer trailer;

public:
   Trailer_Bus();
   ~Trailer_Bus();
};


#endif //DIRECTORY_OF_CARS_TRAILER_BUS_H
