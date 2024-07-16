#include "User.h"
#include <fstream>
#include <iostream>
using namespace std;

User::User() : name{"none"}, surname{"none"}, password{new string {"none"}} {}

User::User(string& new_name, string& new_surname, [[maybe_unused]] string& new_password)
        : name{new_name}, surname{new_surname}, password{new string{new_password}} {}

ostream &operator<<(ostream& os, const User &obj){
    os << obj.name << "\t" << obj.surname << "\t" << *obj.password << endl;
    return os;
}

istream &operator>>(istream& is, User &obj){
    is >> obj.name;
    is >> obj.surname;
    is >> *obj.password;
    return is;
}

void User::write_to_file(){
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Users.txt)", ios_base::app);
    fout << name << "\t" << surname << "\t" << *password << endl;
    fout.close();
}

bool User::search() {
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Users.txt)");
    User A;
    while(fin >> A){
        if(A.name == name && A.surname == surname && *A.password == *password)
            return true;
    }
    return false;
}

User &User::operator=(const User &other) {
    if (this == &other)
        return *this;
    name = other.name;
    surname = other.surname;
    password = make_unique<string>(*other.password);
    return *this;
}

User::User(const User& other)
        : name{other.name}, surname{other.surname}, password{make_unique<string>(*other.password)} {}

User::User(User&& other) noexcept
        : name{std::move(other.name)}, surname{std::move(other.surname)}, password{std::move(other.password)} {}

User &User::operator=(User &&other) noexcept {
    if (this == &other)
        return *this;
    name = std::move(other.name);
    surname = std::move(other.surname);
    password = make_unique<string>(*other.password);
    return *this;
}

User::~User() {
    cout << name << " destructor"<<endl;
}

vector<Car> User::cars_from_file() {
        shared_ptr<Car> car{new Car()};
        vector <Car> cars;
        ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)");
        while(fin>>*car){
            cars.push_back(*car);
        }
        fin.close();
        return cars;
    }

vector<Bus> User::buses_from_file() {
    shared_ptr<Bus> bus;
    vector<Bus> buses;
    ifstream fin (R"(C:\Users\Admin\Desktop\directory_of_cars\database)");
    while (fin>>*bus){
        buses.push_back(*bus);
    }
    fin.close();
    return buses;
}

vector<Truck> User::trucks_from_file() {
    shared_ptr<Truck> truck;
    vector <Truck> trucks;
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)");
    while(fin>>*truck){
        trucks.push_back(*truck);
    }
    fin.close();
    return trucks;
}

void User::addCar() {
        unique_ptr <Car> newCar {new Car()};
        cin>>*newCar;
        ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)",ios_base::app);
        fout<<*newCar;
        fout.close();
    }

void User::addTruck() {
    unique_ptr <Truck> newTruck{ new Truck()};
    cin>>*newTruck;
    ofstream fout (R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)");
    fout<<*newTruck;
    fout.close();
}

void User::addBus() {
        unique_ptr <Bus> newBus { new Bus()};
        cin>>*newBus;
        ofstream fout (R"(C:\Users\Admin\Desktop\directory_of_cars\database)");
        fout<<*newBus;
        fout.close();
    }