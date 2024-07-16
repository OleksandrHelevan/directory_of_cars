#ifndef DIRECTORY_OF_CARS_USER_H
#define DIRECTORY_OF_CARS_USER_H

#include <iostream>
#include <memory>
#include "Car.h"
#include "Truck.h"
#include "Bus.h"
#include <vector>

using namespace std;

class User {
string name;
string surname;
unique_ptr <string> password;

public:
    User();
    User(string& new_name, string& new_surname, string& new_password);
    ~User();
    User(User&& other) noexcept;
    User &operator=(User &&other) noexcept;
    User &operator=(const User &rhs);
    User(const User& other);
    friend ostream &operator<<(ostream& os, const User &obj);
    friend istream &operator>>(istream& is, User &obj);

    vector <Car> cars_from_file();
    vector <Truck> trucks_from_file();
    vector <Bus> buses_from_file();
    void addCar();
    void addTruck();
    void addBus();
    void write_to_file();
    bool search();

};


#endif //DIRECTORY_OF_CARS_USER_H
