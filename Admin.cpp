
#include "Admin.h"

Admin::Admin(std::string &new_name, std::string &new_surname, std::string &new_password)
        : Person(new_name, new_surname, new_password) {}

Admin::Admin(const Admin &other) : Person(other) {}

Admin::Admin(Admin &&other) noexcept : Person(std::move(other)) {}

Admin::Admin() : Person() {}

ostream& operator<<(ostream& os, const Admin& obj) {
    os << static_cast<Person>(obj);
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