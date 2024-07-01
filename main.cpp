#include <iostream>
#include "User.h"
#include "Truck.h"
//#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include <memory>
//#include "WrongTypeEx.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;

void line(){
    cout<<"------------------------------------------------------------"
          "------------------------------------------------------------"<<endl;
}
void clear(){
    system("cls");
}

vector<Car> cars_from_file(){
   shared_ptr<Car> car{new Car()};
   vector <Car> cars;
   ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)");
   while(fin>>*car){
       cars.push_back(*car);
   }
   fin.close();

    return cars;
}

vector<Truck> trucks_from_file(){
    shared_ptr<Truck> truck;
    vector <Truck> trucks;
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)");
    while(fin>>*truck){
        trucks.push_back(*truck);
    }
    fin.close();
    return trucks;
}

vector<Bus> buses_from_file(){
    shared_ptr<Bus> bus;
    vector<Bus> buses;
    ifstream fin (R"(C:\Users\Admin\Desktop\directory_of_cars\database)");
    while (fin>>*bus){
        buses.push_back(*bus);
    }
    return buses;
}

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
    vector <Car> cars;
    cars = cars_from_file();
    line();
    for_each(cars.begin(),cars.end(),[](Car &car){if(car.sort_year_h(2012))car.getCar();
    line();});
    return 0;
}

