#ifndef DIRECTORY_OF_CARS_PERSON_H
#define DIRECTORY_OF_CARS_PERSON_H

#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <list>
#include "Car.h"
#include "Bus.h"
#include "Truck.h"

using namespace std;

class Person {
public:
    virtual ~Person() = default;
    virtual void write_to_file() = 0;
    virtual bool search() = 0;

    virtual void add_car() = 0;
    virtual void add_truck() = 0;
    virtual void add_bus() = 0;

    virtual void set_car() = 0;
    virtual void set_truck() = 0;
    virtual void set_bus() = 0;

    virtual void delete_vehicle() = 0;

    virtual void car_menu() = 0;
    virtual void truck_menu() = 0;
    virtual void bus_menu() = 0;

};

#endif //DIRECTORY_OF_CARS_PERSON_H
