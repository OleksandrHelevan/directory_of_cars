#include <iostream>
#include "User.h"
#include "Truck.h"
//#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include <memory>
//#include "WrongTypeEx.h"
#include <vector>
#include <algorithm>


using namespace std;

void line(){
    cout<<"------------------------------------------------------------"
          "------------------------------------------------------------";
}

void registration(){
    unique_ptr <User> newUser {new User()};
    cin >> *newUser;
    newUser->write_to_file();
    cout<<"Welcome! "<<endl;
}
User authorization() {
    unique_ptr<string> name{new string{"unknown"}};
    unique_ptr<string> surname{new string{"unknown"}};
    unique_ptr<string> password{new string{"unknown"}};
    cout << "Enter your name" << endl;
    cin >> *name;
    cout << "Enter your surname" << endl;
    cin >> *surname;
    cout << "Enter your password" << endl;
    cin >> *password;
    User newUser(*name, *surname, *password);
    if (newUser.search()) {
        cout << "Welcome " << *name << " " << *surname << endl;
        return newUser;
    } else{
        cerr<<"ex";
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
        User user = authorization();
            unique_ptr<int> choice1{new int};
            while(*choice1!=777){
                cout<<"Make your choice: "<<endl;
                cout<<"1 - to add CAR"<<endl<<"2 - to add TRUCK"<<endl<<"3 - to add BUS"<<endl;
                cout<<"4 - to view CARS"<<endl<<"5 - to view TRUCKS"<<endl<<"4 - to view BUSES"<<endl;
                cin>>*choice1;
                switch (*choice1) {
                    case 1:{
                        user.addCar();
                        break;
                    }

                    case 2:{
                        user.addTruck();
                        break;
                    }

                    case 3:{
                        user.addBus();
                        break;
                    }

                    case 4:{
                        vector<Car> cars;
                        cars = user.cars_from_file();
                        line();

                        string choice2;
                        cout<<"You can view cars: "<<endl;
                        cout<<"1h - By higher year"<<endl;
                        cout<<"1l - By lower year"<<endl;
                        cout<<"2h - By higher price"<<endl;
                        cout<<"2l - By lower price"<<endl;
                        cout<<"3h - By higher mileage"<<endl;
                        cout<<"3l - By lower mileage"<<endl;
                        cout<<"4h - By higher fuel consumption"<<endl;
                        cout<<"4l - By lower fuel consumption"<<endl;

                        break;
                    }
                    case 5:{
                        vector<Truck> trucks;
                        trucks = user.trucks_from_file();
                        for_each(trucks.begin(),trucks.end(),[](Truck &obj){obj.getVehicle();
                        line();
                        });
                        break;
                    }
                    case 6: {
                        vector<Bus> buses;
                        buses = user.buses_from_file();
                        for_each(buses.begin(),buses.end(),[](Bus &obj){obj.getVehicle();
                        line();
                        });
                        break;
                    }
                    default:{

                    }

                }
            }


    } else{

    }
    return 0;
}

