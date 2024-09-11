
#include "User.h"
#include <fstream>

User::User(std::string &new_name, std::string &new_surname, std::string &new_password)
: Person(new_name,new_surname,new_password){}

User::User(const User &other) : Person(other){}

User::User(User &&other) noexcept : Person(std::move(other)){}

User::User() :Person(){}

ostream& operator<<(ostream& os, const User& obj){
    os<<static_cast<Person&>((Person &) obj);
    return os;
}

istream& operator>>(istream& is, User& obj){
    is>>static_cast<Person&>(obj);
    return is;
}

User &User::operator=(User &&other) noexcept {
    if (this == &other) return *this;
    Person::operator=(std::move(other));
    return *this;
}

User &User::operator=(const User &other) {
    if (this == &other) return *this;
    Person::operator=(other);
    return *this;
}

bool User::search() {
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Users.txt)");
    User A;
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

void User::write_to_file() {
    Person::write_to_file();
}


list<Truck> User::trucks_from_file() {
    return Person::trucks_from_file();
}

list<Bus> User::buses_from_file() {
    return Person::buses_from_file();
}

list <Car> User::cars_from_file() {
    return Person::cars_from_file();
}

string User::getname() {
    return Person::getname();
}

string User::getsurname() {
    return Person::getsurname();
}

string User::getpassword() {
    return Person::getpassword();
}

void User::setname(std::string &newname) {
    Person::setname(newname);
}

void User::setsurname(std::string &newsurname) {
    Person::setsurname(newsurname);
}

void User::setpassword(std::string &newpassword) {
    Person::setpassword(newpassword);
}

