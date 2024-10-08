#include <iostream>
#include "User.h"
#include "Admin.h"
#include "Truck.h"
#include <list>
#include "Car.h"
#include "Bus.h"
#include <memory>
#include "Wrong_type.h"
#include "Wrong_choice.h"
#include "Client_not_found.h"
#include <algorithm>
#include <limits>
#include "FileReader.h"


using namespace std;

void line(){
    cout<<"------------------------------------------------------------"
          "------------------------------------------------------------";
}


int main() {
    cout<<"WELCOME!"<<endl;
    line();
    unique_ptr<int> choice{new int};
    while (true) {
        try {
            cout<<"MAKE YOUR CHOICE:"<<endl;
            cout<<"1 - ADMIN"<<endl<<"2 - CLIENT"<<endl<<"3 - VIEW THE INSTRUCTIONS"<<endl;
            line();
            cin>>*choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw Wrong_type();
            }
            switch (*choice) {
                case 1: {
                    line();
                    unique_ptr<string> name{new string};
                    unique_ptr<string> surname{new string};
                    unique_ptr<string> password{new string};
                    cout << "Enter your name:" << endl;
                    cin >> *name;
                    cout << "Enter your surname:" << endl;
                    cin >> *surname;
                    cout << "Enter your password:" << endl;
                    cin >> *password;
                    line();
                    Admin admin(*name, *surname, *password);
                    if (admin.search()) {
                        cout << "Hello" << " " << admin.get_name() << endl;
                        while (true) {
                            try {
                                cout << "Choose what do you want" << endl;
                                cout << "1 - to add CAR" << endl;
                                cout << "2 - to add TRUCK" << endl;
                                cout << "3 - to add BUS" << endl;
                                cout << "4 - to view all CARS" << endl;
                                cout << "5 - to view all TRUCKS" << endl;
                                cout << "6 - to view all BUSES" << endl;
                                cout << "7 - to change some criteria of CAR" << endl;
                                cout << "8 - to change some criteria of TRUCK" << endl;
                                cout << "9 - to change some criteria of BUS" << endl;
                                cout << "10 - to delete some VEHICLE" << endl;
                                cout << "0 - STOP " << endl;
                                unique_ptr<int> choice1{new int};
                                cin >> *choice1;
                                line();
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    throw Wrong_type();
                                }
                                switch (*choice1) {
                                    case 1: {
                                        Admin::add_car();
                                        break;
                                    }
                                    case 2: {
                                        Admin::add_truck();
                                        break;
                                    }
                                    case 3: {
                                        Admin::add_bus();
                                        break;
                                    }
                                    case 4: {
                                        list<Car> cars = Admin::cars_from_file();
                                        for_each(cars.begin(), cars.end(), [](Car &car) {
                                            car.get_vehicle();
                                            line();
                                        });
                                        break;
                                    }
                                    case 5: {
                                        list<Truck> trucks = Admin::trucks_from_file();
                                        for_each(trucks.begin(), trucks.end(),
                                                 [](Truck &truck) {
                                                     truck.get_vehicle();
                                        line();
                                        });
                                        break;
                                    }
                                    case 6: {
                                        list<Bus> buses = Admin::buses_from_file();
                                        for_each(buses.begin(), buses.end(),
                                                 [](Bus &bus) {
                                                     bus.get_vehicle();
                                        line();
                                        });
                                        break;
                                    }
                                    case 7: {
                                        Admin::set_car();
                                        break;
                                    }
                                    case 8:{
                                        Admin::set_truck();
                                        break;
                                    }
                                    case 9:{
                                        Admin::set_bus();
                                        break;
                                    }
                                    case 10:
                                    {
                                        Admin::delete_vehicle();
                                        break;
                                    }
                                    case 0: {
                                        return 0;
                                    }
                                    default: {
                                        throw Wrong_choice();
                                    }
                                }
                            }catch (const Wrong_choice& e) {
                                cerr << e.what() << endl;
                            }catch (const Wrong_type& e){
                                cerr << e.what() << endl;
                            }
                        }
                    }
                    else{
                        throw Client_not_found();
                    }
                }
                case 2: {
                    line();
                    unique_ptr<string> name{new string};
                    unique_ptr<string> surname{new string};
                    unique_ptr<string> password{new string};
                    cout << "Enter your name:" << endl;
                    cin >> *name;
                    cout << "Enter your surname:" << endl;
                    cin >> *surname;
                    cout << "Enter your password:" << endl;
                    cin >> *password;
                    line();

                    User user(*name, *surname, *password);
                    if(user.search()){
                        cout << "Hello " << user.get_name() <<"!" << endl;
                    }
                    else {
                        user.write_to_file();
                        cout << "Hello new client: " << user.get_name() <<"!" << endl;
                    }

                        while (true) {
                            try {
                                cout << "Choose what do you want" << endl;
                                cout << "1 - to view all CARS" << endl;
                                cout << "2 - to view all TRUCKS" << endl;
                                cout << "3 - to view all BUSES" << endl;
                                cout << "4 - to use some filter for CARS" << endl;
                                cout << "5 - to use some filter for TRUCKS" << endl;
                                cout << "6 - to use some filter for BUSES" << endl;
                                cout << "0 - STOP " << endl;
                                unique_ptr<int> choice1{new int};
                                cin >> *choice1;
                                line();
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    throw Wrong_type();
                                }
                                switch (*choice1) {
                                    case 1:{
                                        list<Car> cars = User::cars_from_file();
                                        for_each(cars.begin(), cars.end(), [](Car &car) {
                                            car.get_vehicle();
                                            line();
                                        });
                                        break;
                                    }
                                    case 2:{
                                        list<Truck> trucks = User::trucks_from_file();
                                        for_each(trucks.begin(), trucks.end(),
                                                 [](Truck &truck) {
                                                     truck.get_vehicle();
                                                     line();
                                                 });
                                        break;
                                    }
                                    case 3:{
                                        list<Bus> buses = User::buses_from_file();
                                        for_each(buses.begin(), buses.end(),
                                                 [](Bus &bus) {
                                                     bus.get_vehicle();
                                                     line();
                                                 });
                                        break;
                                    }
                                    case 4:{
                                        User::car_menu();
                                        break;
                                    }
                                    case 5:{
                                        User::truck_menu();
                                        break;
                                    }
                                    case 6:{
                                        User::bus_menu();
                                        break;
                                    }
                                    case 0:{
                                        return 0;
                                    }
                                    default: {
                                        throw Wrong_choice();
                                    }
                                }
                            } catch (const Wrong_choice &e) {
                                cerr << e.what() << endl;
                            } catch (const Wrong_type &e) {
                                cerr << e.what() << endl;
                            }
                        }

                }
                case 3: {
                    line();
                    string instruction_file = R"(C:\Users\Admin\Desktop\directory_of_cars\database\instruction.txt)";
                    FileReader::read_file(instruction_file);
                    cout<<endl;
                    line();
                    break;
                }
                default: {
                    throw Wrong_choice();
                }

            }
        }catch (const Wrong_choice& e) {
            cerr << e.what() << endl;
        }catch (const Wrong_type& e){
            cerr << e.what() << endl;
        }catch(const Client_not_found &e){
            cerr<< e.what()<<endl;
        }

    }
}

