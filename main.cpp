#include <iostream>
#include "Person.h"
#include "User.h"
#include "Admin.h"
#include "Truck.h"
#include <list>
//#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include <memory>
//#include "WrongTypeEx.h"
#include <vector>
#include <fstream>
#include <algorithm>


using namespace std;

void line(){
    cout<<"------------------------------------------------------------"
          "------------------------------------------------------------";
}


int main() {
    cout<<"WELCOME!"<<endl;
    line();
    cout<<"MAKE YOUR CHOICE:"<<endl;
    cout<<"1 - ADMIN"<<endl<<"2 - USER"<<endl<<"3 - VIEW THE INSTRUCTIONS"<<endl;
    line();
    unique_ptr<int> choice{new int};
    cin>>*choice;
    line();
    switch (*choice) {
        case 1:{
            unique_ptr<string> name{new string};
            unique_ptr<string> surname{new string};
            unique_ptr<string> password{new string};
            cout<<"Enter your name:"<<endl;
            cin>>*name;
            cout<<"Enter your surname:"<<endl;
            cin>>*surname;
            cout<<"Enter your password:"<<endl;
            cin>>*password;
            line();
            Admin admin(*name,*surname,*password);
                if (admin.search()) {
                    cout << "Hello" << " " << admin.getname() << endl;
                    while(true) {
                        cout << "Choose what do you want" << endl;
                        cout << "1 - to add CAR" << endl;
                        cout << "2 - to add TRUCK" << endl;
                        cout << "3 - to add BUS" << endl;
                        cout << "4 - to view all CARS" << endl;
                        cout << "5 - to view all TRUCKS" << endl;
                        cout << "6 - to view all BUSES" << endl;
                        cout << "0 - STOP " << endl;
                        unique_ptr<int> choice1{new int};
                        cin >> *choice1;
                        switch (*choice1) {
                            case 1: {
                                admin.addCar();
                                break;
                            }
                            case 2: {
                                admin.addTruck();
                                break;
                            }
                            case 3: {
                                admin.addBus();
                                break;
                            }
                            case 4: {
                                list<Car> cars = admin.cars_from_file();
                                for_each(cars.begin(), cars.end(), [](Car &car) {
                                    car.getVehicle();
                                    line();
                                });
                                break;
                            }
                            case 5: {
                                vector<Truck> trucks = admin.trucks_from_file();
                                for_each(trucks.begin(), trucks.end(), [](Truck &truck) { truck.getVehicle(); });
                                break;
                            }
                            case 6: {
                                vector<Bus> buses = admin.buses_from_file();
                                for_each(buses.begin(), buses.end(), [](Bus &bus) { bus.getVehicle(); });
                                break;
                            }
                            case 0:{
                                return 0;
                            }
                            default: {

                            }
                        }
                    }

                } else {
                    cout << "You are not admin!!!" << endl;
                }

            break;
        }
        case 2:{

        }
        case 3:{

        }
        default:{}

    }
}

