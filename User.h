

#ifndef DIRECTORY_OF_CARS_USER_H
#define DIRECTORY_OF_CARS_USER_H

#include <limits>
#include "Person.h"
using namespace std;
class User :public Person{
public:
    User();
    User(std::string& new_name, std::string& new_surname, std::string& new_password);
    ~User() override = default;
    User(User&& other) noexcept;
    User& operator=(User&& other) noexcept;
    User& operator=(const User& other);
    User(const User& other);
    friend ostream& operator<<(ostream& os, const User& obj);
    friend istream& operator>>(istream& is, User& obj);

    void write_to_file() override;
    bool search() override;

    static void car_menu();
    static void truck_menu();
    static void bus_menu();

};

#endif //DIRECTORY_OF_CARS_USER_H
