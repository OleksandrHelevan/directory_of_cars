

#ifndef DIRECTORY_OF_CARS_USER_H
#define DIRECTORY_OF_CARS_USER_H
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

    string getname() override;
    string getsurname() override;
    string getpassword() override;

    void setname(string& newname) override;
    void setsurname(string& newsurname) override;
    void setpassword(string& newpassword) override;

    list <Car> cars_from_file() override;
    vector <Truck> trucks_from_file() override;
    vector <Bus> buses_from_file() override;
    void addCar() override{};
    void addTruck() override{};
    void addBus() override{};
    void write_to_file() override;
    bool search() override;
};


#endif //DIRECTORY_OF_CARS_USER_H
