
#ifndef DIRECTORY_OF_CARS_ADMIN_H
#define DIRECTORY_OF_CARS_ADMIN_H
#include "Person.h"


class Admin :public Person{

public:
    Admin();
    Admin(std::string& new_name, std::string& new_surname, std::string& new_password);
    ~Admin() override;
    Admin(Admin&& other) noexcept;
    Admin& operator=(Admin&& other) noexcept;
    Admin& operator=(const Admin& other);
    Admin(const Admin& other);
    friend ostream& operator<<(ostream& os, const Admin& obj);
    friend istream& operator>>(istream& is, Admin& obj);

    string getname() override;
    string getsurname() override;
    string getpassword() override;

    void setname(string& newname) override;
    void setsurname(string& newsurname) override;
    void setpassword(string& newpassword) override;

    list <Car> cars_from_file() override;
    vector <Truck> trucks_from_file() override;
    vector <Bus> buses_from_file() override;
    void addCar() override;
    void addTruck() override;
    void addBus() override;
    void write_to_file() override;
    bool search() override;
};


#endif //DIRECTORY_OF_CARS_ADMIN_H
