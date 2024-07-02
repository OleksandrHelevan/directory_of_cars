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
          "------------------------------------------------------------";
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
    cout<<"Welcome! "<<endl;
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
    if(newUser.search()) {
        cout<<"Welcome "<<*name<<" "<<*surname<<endl;
        return true;
    }
    else{

        return false;
    }
}


int main() {
    cout<<"Welcome to the DIRECTORY OF CARS"<<endl;
    line();
    cout<<"If you want to SIGN UP - enter 1"<<endl<<"If you want to SIGN IN - enter 2"<<endl;
    unique_ptr<int> choice{new int{0}};
    cin>>*choice;
    if(*choice==1){
        registration();

    } else if(*choice==2){
        if(authorization()){
            unique_ptr<int> choice1{new int{0}};
            while(*choice1!=777){
                cout<<"Make your choice: "<<endl;
                cout<<"1 - to add CAR"<<endl<<"2 - to add TRUCK"<<endl<<"3 - to add BUS"<<endl;
                cout<<"4 - to view CARS"<<endl<<"5 - to view TRUCKS"<<endl<<"4 - to view BUSES"<<endl;
                cin>>*choice1;
                switch (*choice1) {
                    case 1:{
                        addCar();
                        break;
                    }

                    case 2:{
                        addTruck();
                        break;
                    }

                    case 3:{
                        addBus();
                        break;
                    }

                    case 4:{
                        vector<Car> cars;
                        cars = cars_from_file();
                        for_each(cars.begin(),cars.end(),[](Car &obj){
                            obj.getCar();
                            line();
                        });
                        break;
                    }
                    case 5:{
                        vector<Truck> trucks;
                        trucks = trucks_from_file();
                        for_each(trucks.begin(),trucks.end(),[](Truck &obj){obj.getVehicle();
                        line();
                        });
                        break;
                    }
                    case 6: {
                        vector<Bus> buses;
                        buses = buses_from_file();
                        for_each(buses.begin(),buses.end(),[](Bus &obj){obj.getVehicle();
                        line();
                        });
                        break;
                    }

                }
            }
        } else{

        }

    } else{

    }
    return 0;
}

