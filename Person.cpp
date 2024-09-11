#include "Person.h"
#include <fstream>
#include <iostream>
#include <limits>

using namespace std;


template <typename T>
T getInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt << endl;
        cin >> value;
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
            cerr << "Invalid input. Please enter a value of the correct type." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any extra input
            return value;
        }
    }
}

unique_ptr<string> getStringInput(const string& prompt) {
    unique_ptr<string> value = make_unique<string>();
    cout << prompt << endl;
    cin >> *value;
    return value;
}

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

void Person::addCar() {
    unique_ptr<string> brand =
            getStringInput("Enter BRAND of car:");
    unique_ptr<string> model =
            getStringInput("Enter MODEL of car:");
    unique_ptr<int> year =
            make_unique<int>(getInput<int>("Enter YEAR of car:"));
    unique_ptr<string> color =
            getStringInput("Enter COLOR of car:");
    unique_ptr<double> capacity =
            make_unique<double>(getInput<double>("Enter CAPACITY of car's engine:"));
    unique_ptr<string> fuel =
            getStringInput("Enter FUEL of car's engine:");
    unique_ptr<double> power =
            make_unique<double>(getInput<double>("Enter POWER of car's engine:"));

    Engine engine(*capacity, *fuel, *power);

    unique_ptr<int> weight =
            make_unique<int>(getInput<int>("Enter WEIGHT of car:"));
    unique_ptr<double> fuelConsumption =
            make_unique<double>(getInput<double>("Enter FUEL CONSUMPTION of car/100km:"));
    unique_ptr<int> mileage =
            make_unique<int>(getInput<int>("Enter MILEAGE of car in thousands of km:"));
    unique_ptr<string> location =
            getStringInput("Enter LOCATION of car:");
    unique_ptr<string> wheelDrive =
            getStringInput("Enter WHEEL DRIVE of car (full/back/front):");
    unique_ptr<string> transmission =
            getStringInput("Enter TRANSMISSION of car (automatic/mechanics):");
    unique_ptr<int> price =
            make_unique<int>(getInput<int>("Enter PRICE of car:"));

    Car car(engine, *weight, *fuelConsumption, *mileage,
            *color, *brand, *model, *year, *location,
            *price, *wheelDrive, *transmission);

    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)", ios_base::app);
    fout << car;
    fout.close();
}

void Person::addTruck() {
    unique_ptr<string> brand =
            getStringInput("Enter BRAND of truck:");
    unique_ptr<string> model =
            getStringInput("Enter MODEL of truck:");
    unique_ptr<int> year =
            make_unique<int>(getInput<int>("Enter YEAR of truck:"));
    unique_ptr<string> color =
            getStringInput("Enter COLOR of truck:");
    unique_ptr<double> capacity =
            make_unique<double>(getInput<double>("Enter CAPACITY of truck's engine:"));
    unique_ptr<string> fuel =
            getStringInput("Enter FUEL of truck's engine:");
    unique_ptr<double> power =
            make_unique<double>(getInput<double>("Enter POWER of truck's engine:"));

    Engine engine(*capacity, *fuel, *power);

    unique_ptr<int> weight =
            make_unique<int>(getInput<int>("Enter WEIGHT of truck:"));
    unique_ptr<double> fuelConsumption =
            make_unique<double>(getInput<double>("Enter FUEL CONSUMPTION of truck/100km:"));
    unique_ptr<int> mileage =
            make_unique<int>(getInput<int>("Enter MILEAGE of truck in thousands of km:"));
    unique_ptr<string> location =
            getStringInput("Enter LOCATION of truck:");
    unique_ptr<int> cargoCapacity =
            make_unique<int>(getInput<int>("Enter CARGO CAPACITY of truck:"));
    unique_ptr<int> price =
            make_unique<int>(getInput<int>("Enter PRICE of truck:"));

    Truck truck(engine, *weight, *fuelConsumption, *mileage,
                *color, *brand, *model, *year, *location,
                *price, *cargoCapacity);

    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)", ios_base::app);
    fout << truck;
    fout.close();
}

void Person::addBus() {
    unique_ptr<string> brand =
            getStringInput("Enter BRAND of bus:");
    unique_ptr<string> model =
            getStringInput("Enter MODEL of bus:");
    unique_ptr<int> year =
            make_unique<int>(getInput<int>("Enter YEAR of bus:"));
    unique_ptr<string> color=
            getStringInput("Enter COLOR of bus:");
    unique_ptr<double> capacity =
            make_unique<double>(getInput<double>("Enter CAPACITY of bus's engine:"));
    unique_ptr<string> fuel =
            getStringInput("Enter FUEL of bus's engine:");
    unique_ptr<double> power =
            make_unique<double>(getInput<double>("Enter POWER of bus's engine:"));

    Engine engine(*capacity, *fuel, *power);

    unique_ptr<int> weight =
            make_unique<int>(getInput<int>("Enter WEIGHT of bus:"));
    unique_ptr<double> fuelConsumption =
            make_unique<double>(getInput<double>("Enter FUEL CONSUMPTION of bus/100km:"));
    unique_ptr<int> mileage =
            make_unique<int>(getInput<int>("Enter MILEAGE of bus in thousands of km:"));
    unique_ptr<string> location =
            getStringInput("Enter LOCATION of bus:");
    unique_ptr<int> passengerCapacity =
            make_unique<int>(getInput<int>("Enter PASSENGER CAPACITY of bus:"));
    unique_ptr<int> price =
            make_unique<int>(getInput<int>("Enter PRICE of bus:"));

    Bus bus(engine, *weight, *fuelConsumption, *mileage,
            *color, *brand, *model, *year, *location,
            *price, *passengerCapacity);

    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Buses.txt)", ios_base::app);
    fout << bus;
    fout.close();
    }

string Person::getname() {
    return name;
}

string Person::getsurname() {
    return surname;
}

string Person::getpassword() {
    return *password;
}

void Person::setname(std::string& newname) {
    this->name = newname;
}

void Person::setpassword(std::string &newpassword) {
    *this->password = newpassword;
}

void Person::setsurname(std::string &newsurname) {
    this->surname = newsurname;
}
