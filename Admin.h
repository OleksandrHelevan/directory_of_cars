#ifndef DIRECTORY_OF_CARS_ADMIN_H
#define DIRECTORY_OF_CARS_ADMIN_H

#include "Person.h"
#include "Car.h"
#include "Truck.h"
#include "Bus.h"
#include <list>
#include <memory>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

class Admin : public Person {
    unique_ptr<string> name;
    unique_ptr<string> surname;
    unique_ptr<string> password;

public:
    Admin();
    Admin(string& new_name, string& new_surname, string& new_password);
    ~Admin() override;
    Admin(Admin &&other) noexcept ;
    Admin(const Admin &other);
    Admin& operator=(Admin &&other) noexcept;
    Admin& operator=(const Admin &other);

    friend ostream& operator<<(ostream& os, const Admin& obj);
    friend istream& operator>>(istream& is, Admin& obj);

    [[nodiscard]] string get_name() const;
    [[maybe_unused]] [[nodiscard]] string get_surname() const;
    [[maybe_unused]] [[nodiscard]] string get_password() const;

    void set_name(const string& new_name);
    void set_surname(const string& new_surname);
    void set_password(const string& new_password);

    void write_to_file() override;
    bool search() override;

    void add_car() override;
    void add_truck() override;
    void add_bus() override;

    void set_car() override;
    void set_truck() override;
    void set_bus() override;

    static list <Car> cars_from_file();
    static list <Truck> trucks_from_file();
    static list <Bus> buses_from_file();

    void delete_vehicle() override;

    template <typename T>
    static T get_input(const string& prompt) {
        T value;
        while (true) {
            cout << prompt << endl;
            cin >> value;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Invalid input. Please enter a value of the correct type." << endl;
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }

    static unique_ptr<string> get_string_input(const string& prompt) {
        unique_ptr<string> value = make_unique<string>();
        cout << prompt << endl;
        cin >> *value;
        return value;
    }

    static void line(){
        cout<<"------------------------------------------------------------"
              "------------------------------------------------------------";
    }
};

#endif //DIRECTORY_OF_CARS_ADMIN_H
