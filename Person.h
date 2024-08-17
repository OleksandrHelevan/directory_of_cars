#ifndef DIRECTORY_OF_CARS_PERSON_H
#define DIRECTORY_OF_CARS_PERSON_H

#include <iostream>
#include <memory>
#include "Car.h"
#include "Truck.h"
#include "Bus.h"
#include <vector>
#include "list"

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


    virtual string getname()=0;
    virtual string getsurname()=0;
    virtual string getpassword()=0;
    virtual list <Car> cars_from_file()=0;
    virtual vector <Truck> trucks_from_file()=0;
    virtual vector <Bus> buses_from_file()=0;
    virtual void addCar()=0;
    virtual void addTruck()=0;
    virtual void addBus()=0;
    virtual void write_to_file()=0;
    virtual bool search()=0;

};


#endif //DIRECTORY_OF_CARS_PERSON_H
