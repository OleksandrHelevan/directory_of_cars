
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

    string get_name() override;
    string get_surname() override;
    string get_password() override;

    void set_name(string& newname) override;
    void set_surname(string& newsurname) override;
    void set_password(string& newpassword) override;

    list <Car> cars_from_file() override;
    list <Truck> trucks_from_file() override;
    list <Bus> buses_from_file() override;
    void add_car() override;
    void add_truck() override;
    void add_bus() override;
    void write_to_file() override;
    bool search() override;
};


#endif //DIRECTORY_OF_CARS_ADMIN_H
