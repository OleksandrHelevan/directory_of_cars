#include <iostream>
#include "User.h"
#include "Truck.h"
//#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include <memory>
//#include "WrongTypeEx.h"
#include <fstream>




using namespace std;



void addCar(){
    unique_ptr <Car> newCar {new Car()};
    cin>>*newCar;
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)",ios_base::app);
    fout<<*newCar;
    fout.close();
}

void addTruck(){
    unique_ptr <Truck> newTruck{ new Truck()};
    cin>>*newTruck;
    ofstream fout (R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)");
    fout<<*newTruck;
    fout.close();
}

void addBus(){
    unique_ptr <Bus> newBus { new Bus()};
    cin>>*newBus;
    ofstream fout (R"(C:\Users\Admin\Desktop\directory_of_cars\database)");
    fout<<*newBus;
    fout.close();
}

void registration(){
    unique_ptr <User> newUser {new User()};
    cin >> *newUser;
    newUser->write_to_file();
    cout<< *newUser;
}
bool authorization(){
    unique_ptr<string> name{new string{"unknown"}};
    unique_ptr<string> surname{new string{"unknown"}};
    unique_ptr<string> password{new string{"unknown"}};
    cout<<"Enter your name"<<endl;
    cin>>*name;
    cout<<"Enter your surname"<<endl;
    cin>>*surname;
    cout<<"Enter your password"<<endl;
    cin>>*password;
    User newUser(*name, *surname, *password);
    return newUser.search();
}


int main() {
    if (authorization())
        cout << "Супер!";
    else cout << "Погано!";

    return 0;
}

