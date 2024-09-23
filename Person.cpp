#include "Person.h"
#include <fstream>
#include <iostream>
#include <limits>

using namespace std;


Person::Person() : name{"none"}, surname{"none"}, password{new string {"none"}} {}

Person::Person(string& new_name, string& new_surname, [[maybe_unused]] string& new_password)
        : name{new_name}, surname{new_surname}, password{new string{new_password}} {}

ostream &operator<<(ostream& os, const Person &obj){
    os << obj.name << "\t" << obj.surname << "\t" << *obj.password << endl;
    return os;
}

istream &operator>>(istream& is, Person &obj){
    is >> obj.name;
    is >> obj.surname;
    is >> *obj.password;
    return is;
}

void Person::write_to_file(){
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Users.txt)", ios_base::app);
    fout << name << "\t" << surname << "\t" << *password << endl;
    fout.close();
}

bool Person::search() {
    return false;
}

Person &Person::operator=(const Person &other) {
    if (this == &other)
        return *this;
    name = other.name;
    surname = other.surname;
    password = make_unique<string>(*other.password);
    return *this;
}

Person::Person(const Person& other)
        : name{other.name}, surname{other.surname}, password{make_unique<string>(*other.password)} {}

Person::Person(Person&& other) noexcept
        : name{std::move(other.name)}, surname{std::move(other.surname)}, password{std::move(other.password)} {}

Person &Person::operator=(Person &&other) noexcept {
    if (this == &other)
        return *this;
    name = std::move(other.name);
    surname = std::move(other.surname);
    password = make_unique<string>(*other.password);
    return *this;
}

Person::~Person() {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)", ios_base::app);
    fout << name << " destructor"<<endl;
    fout.close();
}

list <Car> Person::cars_from_file() {
        shared_ptr<Car> car{new Car()};
        list<Car> cars;
        ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)");
        while(fin>>*car){
            cars.push_back(*car);
        }
        fin.close();
        return cars;
    }

list<Bus> Person::buses_from_file() {
    shared_ptr<Bus> bus{new Bus};
    list<Bus> buses;
    ifstream fin (R"(C:\Users\Admin\Desktop\directory_of_cars\database\Buses.txt)");
    while (fin>>*bus){
        buses.push_back(*bus);
    }
    fin.close();
    return buses;
}

list<Truck> Person::trucks_from_file() {
    shared_ptr<Truck> truck {new Truck};
    list <Truck> trucks;
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)");
    while(fin>>*truck){
        trucks.push_back(*truck);
    }
    fin.close();
    return trucks;
}

string Person::get_name() {
    return name;
}

string Person::get_surname() {
    return surname;
}

string Person::get_password() {
    return *password;
}

void Person::set_name(string &newname) {
    this->name = newname;
}

void Person::set_password(string &newpassword) {
    *this->password = newpassword;
}

void Person::set_surname(string &newsurname) {
    this->surname = newsurname;
}
