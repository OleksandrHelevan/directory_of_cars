#ifndef DIRECTORY_OF_CARS_PERSON_H
#define DIRECTORY_OF_CARS_PERSON_H

#include <iostream>
#include <memory>
#include "Car.h"
#include "Truck.h"
#include "Bus.h"
#include <vector>

using namespace std;

class Person {
string name;
string surname;
unique_ptr <string> password;

public:
    Person();
    Person(string& new_name, string& new_surname, string& new_password);
    virtual ~Person();
    Person(Person&& other) noexcept;
    Person &operator=(Person &&other) noexcept;
    Person &operator=(const Person &rhs);
    Person(const Person& other);
    friend ostream &operator<<(ostream& os, const Person &obj);
    friend istream &operator>>(istream& is, Person &obj);

    vector <Car> cars_from_file();
    vector <Truck> trucks_from_file();
    vector <Bus> buses_from_file();
    void addCar();
    void addTruck();
    void addBus();
    void write_to_file();
    bool search();

};


#endif //DIRECTORY_OF_CARS_PERSON_H
