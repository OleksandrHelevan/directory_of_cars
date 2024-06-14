#ifndef DIRECTORY_OF_CARS_USER_H
#define DIRECTORY_OF_CARS_USER_H

#include <iostream>
using namespace std;

class User {
string name;
string surname;
string password;

public:
    User();
    User(string& new_name, string& new_surname, string& new_password);
    friend ostream &operator<<(ostream& os, const User &obj);
    friend istream &operator>>(istream& is, User &obj);
    void write_to_file();
    ~User(){cout << name << "obj was deleted"<<endl;};

};


#endif //DIRECTORY_OF_CARS_USER_H
