#include "User.h"
#include "fstream"
using namespace std;

User::User() : name{"none"}, surname{"none"}, password{"none"}{}

User::User(string& new_name, string& new_surname, string& new_password)
    :name{new_name}, surname{new_surname}, password{new_password}{}

ostream &operator<<(ostream& os, const User &obj){
    os<<obj.name<<"\t"<<obj.surname<<"\t"<<obj.password<<endl;
    return os;
}

istream &operator>>(istream& is, User &obj){
    is>>obj.name;
    is>>obj.surname;
    is>>obj.password;
    return is;
}

void User::write_to_file(){
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Users.txt)",
                  ios_base::app);
    fout<<name<<"\t"<<surname<<"\t"<<password<<endl;
    fout.close();
}