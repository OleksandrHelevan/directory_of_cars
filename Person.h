#ifndef DIRECTORY_OF_CARS_PERSON_H
#define DIRECTORY_OF_CARS_PERSON_H

#include <iostream>
#include <memory>
#include "Car.h"
#include "Truck.h"
#include "Bus.h"
#include <vector>
#include <limits>
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


    virtual string get_name()=0;
    virtual string get_surname()=0;
    virtual string get_password()=0;

    virtual void set_name(string& newname);
    virtual void set_surname(string& newsurname);
    virtual void set_password(string& newpassword);

    static list <Car> cars_from_file();
    static list <Truck> trucks_from_file();
    static list <Bus> buses_from_file();
    virtual void write_to_file()=0;
    virtual bool search()=0;


    static void line(){
        cout<<"------------------------------------------------------------"
              "------------------------------------------------------------";
    }
    template <typename T>
    static T getInput(const string& prompt) {
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

    static unique_ptr<string> getStringInput(const string &prompt) {
        unique_ptr<string> value = make_unique<string>();
        cout << prompt << endl;
        cin >> *value;
        return value;
    }
};


#endif //DIRECTORY_OF_CARS_PERSON_H
