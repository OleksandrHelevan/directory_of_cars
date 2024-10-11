
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

    static void add_car();
    static void add_truck();
    static void add_bus();

    void write_to_file() override;
    bool search() override;

    static void set_car();
    static void set_truck();
    static void set_bus();

    static void delete_vehicle();
};


#endif //DIRECTORY_OF_CARS_ADMIN_H
