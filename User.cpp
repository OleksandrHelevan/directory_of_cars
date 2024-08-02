
#include "User.h"

User::User(std::string &new_name, std::string &new_surname, std::string &new_password)
: Person(new_name,new_surname,new_password){}

User::User(const User &other) : Person(other){}

User::User(User &&other) noexcept : Person(std::move(other)){}

User::User() :Person(){}

ostream& operator<<(ostream& os, const User& obj){
    os<<static_cast<Person>(obj);
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
