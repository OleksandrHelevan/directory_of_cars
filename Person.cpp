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
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)");
    fout << name << " destructor"<<endl;
    fout.close();
}

list <Car> Person::cars_from_file() {
        shared_ptr<Car> car{new Car()};
       list <Car> cars;
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
    cout<<"Enter BRAND of car:"<<endl;
    unique_ptr <string> brand {new string };
    cin>>*brand;

    cout<<"Enter MODEL of car:"<<endl;
    unique_ptr <string> model {new string };
    cin>>*model;

    cout<<"Enter YEAR of car:"<<endl;
    unique_ptr <int> year {new int };
    cin>>*year;

    cout<<"Enter COLOR of car:"<<endl;
    unique_ptr <string> color {new string };
    cin>>*color;

    cout<<"Enter CAPACITY of car`s engine:"<<endl;
    unique_ptr <double> capacity{new double };
    cin>>*capacity;

    cout<<"Enter FUEL of car`s engine:"<<endl;
    unique_ptr <string> fuel{new string };
    cin>>*fuel;

    cout<<"Enter POWER of car`s engine:"<<endl;
    unique_ptr <double> power{new double };
    cin>>*power;

    Engine engine(*capacity,*fuel,*capacity);

    cout<<"Enter WEIGHT of car:"<<endl;
    unique_ptr <int> weight {new int };
    cin>>*weight;

    cout<<"Enter FUEL CONSUMPTION of car/100km:"<<endl;
    unique_ptr <double> fuel_con {new double };
    cin>>*fuel_con;

    cout<<"Enter MILEAGE of car in thousands of km:"<<endl;
    unique_ptr <int> mileage {new int };
    cin>>*mileage;

    cout<<"Enter LOCATION of car:"<<endl;
    unique_ptr <string> location {new string };
    cin>>*location;

    cout<<"Enter wheel drive of car(full/back/front):"<<endl;
    unique_ptr <string> wheel_drive {new string };
    cin>>*wheel_drive;

    cout<<"Enter TRANSMISSION of car(automatics/mechanics):"<<endl;
    unique_ptr <string> transmission {new string };
    cin>>*transmission;

    cout<<"Enter PRICE of car:"<<endl;
    unique_ptr <int> price {new int };
    cin>>*price;

    Car car(engine,*weight,*fuel_con,*mileage,
            *color,*brand,*model,*year,*location,
            *price,*wheel_drive,*transmission);

    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)",ios_base::app);
    fout<<car;
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

string Person::getname() {return name;}
string Person::getsurname() {return surname;}
string Person::getpassword() {return *password;}