
#include "Admin.h"
#include <fstream>


Admin::Admin(std::string &new_name, std::string &new_surname, std::string &new_password)
        : Person(new_name, new_surname, new_password) {}

Admin::Admin(const Admin &other) : Person(other) {}

Admin::Admin(Admin &&other) noexcept : Person(std::move(other)) {}

Admin::Admin() : Person() {}

ostream& operator<<(ostream& os, const Admin& obj) {
    os << static_cast<Person&>((Person &) obj);
    return os;
}

istream& operator>>(istream& is, Admin& obj) {
    is >> static_cast<Person&>(obj);
    return is;
}

Admin &Admin::operator=(Admin &&other) noexcept {
    if (this == &other) return *this;
    Person::operator=(std::move(other));
    return *this;
}

Admin &Admin::operator=(const Admin &other) {
    if (this == &other) return *this;
    Person::operator=(other);
    return *this;
}

void Admin::addBus() {
    Person::addBus();
}

void Admin::addTruck() {
    Person::addTruck();
}

void Admin::addCar() {
    Person::addCar();
}

string Admin::getname() {
    return Person::getname();
}

string Admin::getsurname() {
    return Person::getsurname();
}

string Admin::getpassword() {
    return Person::getpassword();
}

bool Admin::search() {
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Admins.txt)");
    Admin A;
    while(fin >> A){
        if(A.getname() == Person::getname() && A.getsurname() == Person::getsurname()
        && A.getpassword() == Person::getpassword()){
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

void Admin::write_to_file() {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Admins.txt)", ios_base::app);
    fout << getname() << "\t" << getsurname() << "\t" << getpassword() << endl;
    fout.close();
}

vector<Truck> Admin::trucks_from_file() {
    return Person::trucks_from_file();
}

vector<Bus> Admin::buses_from_file() {
    return Person::buses_from_file();
}

list<Car> Admin::cars_from_file() {
    Car car;
    list <Car> cars;
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)");
    while(fin>>car){
        cars.push_back(car);
    }
    fin.close();
    return cars;
}
