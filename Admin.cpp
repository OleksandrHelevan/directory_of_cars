
#include "Admin.h"
#include <fstream>
#include "Client_not_found.h"


Admin::Admin(std::string &new_name, std::string &new_surname, std::string &new_password)
        : Person(new_name, new_surname, new_password) {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)");
    fout <<"authorization of ADMIN"<<endl;
    fout.close();
}

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

void Admin::add_bus() {
    Person::add_bus();
}

void Admin::add_truck() {
    Person::add_truck();
}

void Admin::add_car() {
    Person::add_car();
}

string Admin::get_name() {
    return Person::get_name();
}

string Admin::get_surname() {
    return Person::get_surname();
}

string Admin::get_password() {
    return Person::get_password();
}

bool Admin::search() {
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Admins.txt)");
    Admin A;
    while(fin >> A){
        try {
            if (A.get_name() == Person::get_name() && A.get_surname() == Person::get_surname()
                && A.get_password() == Person::get_password()) {
                fin.close();
                return true;
            } else {
                throw Client_not_found();
            }
        }catch (Client_not_found& e){
            fin.close();
            cerr<<"Admin "<<e.what()<<endl;
        }
    }
    fin.close();
    return false;
}

void Admin::write_to_file() {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Admins.txt)", ios_base::app);
    fout << get_name() << "\t" << get_surname() << "\t" << get_password() << endl;
    fout.close();
}

list<Truck> Admin::trucks_from_file() {
    return Person::trucks_from_file();
}

list<Bus> Admin::buses_from_file() {
    return Person::buses_from_file();
}

list<Car> Admin::cars_from_file() {
    unique_ptr<Car> car{new Car()};
    list <Car> cars;
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)");
    while(fin>>*car){
        cars.push_back(*car);
    }
    fin.close();
    return cars;
}


Admin::~Admin() noexcept {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)", ios_base::app);
    fout << "Admin destructor"<<endl;
    fout.close();
}

void Admin::set_surname(string &newsurname) {
    Person::set_surname(newsurname);
}

void Admin::set_name(string &newname) {
    Person::set_name(newname);
}

void Admin::set_password(string &newpassword) {
    Person::set_password(newpassword);
}