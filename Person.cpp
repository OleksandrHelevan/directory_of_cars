#include "Person.h"
#include <fstream>
#include <iostream>
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
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Users.txt)");
    Person A;
    while(fin >> A){
        if(A.name == name && A.surname == surname && *A.password == *password)
            return true;
    }
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
    cout << name << " destructor"<<endl;
}

vector<Car> Person::cars_from_file() {
        shared_ptr<Car> car{new Car()};
        vector <Car> cars;
        ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)");
        while(fin>>*car){
            cars.push_back(*car);
        }
        fin.close();
        return cars;
    }

vector<Bus> Person::buses_from_file() {
    shared_ptr<Bus> bus;
    vector<Bus> buses;
    ifstream fin (R"(C:\Users\Admin\Desktop\directory_of_cars\database)");
    while (fin>>*bus){
        buses.push_back(*bus);
    }
    fin.close();
    return buses;
}

vector<Truck> Person::trucks_from_file() {
    shared_ptr<Truck> truck;
    vector <Truck> trucks;
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)");
    while(fin>>*truck){
        trucks.push_back(*truck);
    }
    fin.close();
    return trucks;
}

void Person::addCar() {
        unique_ptr <Car> newCar {new Car()};
        cin>>*newCar;
        ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)",ios_base::app);
        fout<<*newCar;
        fout.close();
    }

void Person::addTruck() {
    unique_ptr <Truck> newTruck{ new Truck()};
    cin>>*newTruck;
    ofstream fout (R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)");
    fout<<*newTruck;
    fout.close();
}

void Person::addBus() {
        unique_ptr <Bus> newBus { new Bus()};
        cin>>*newBus;
        ofstream fout (R"(C:\Users\Admin\Desktop\directory_of_cars\database)");
        fout<<*newBus;
        fout.close();
    }