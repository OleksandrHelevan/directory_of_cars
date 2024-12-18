#include <iostream>
#include "User.h"
#include "Admin.h"
#include "Truck.h"
#include <list>
#include "Car.h"
#include "Bus.h"
#include <memory>
#include "WrongType.h"
#include "WrongChoice.h"
#include "ClientNotFound.h"
#include <algorithm>
#include <limits>
#include "FileReader.h"
#include "WrongTypeVehicle.h"

using namespace std;

void line() {
    cout << "------------------------------------------------------------"
            "------------------------------------------------------------"<<endl;
}

int main() {
    line();
    cout << "WELCOME!"<<endl;
    line();
    unique_ptr<int> choice{new int};
    while (true) {
        try {
            cout << "MAKE YOUR CHOICE:" << endl;
            cout << "1 - ADMIN" << endl << "2 - CLIENT" << endl << "3 - VIEW THE INSTRUCTIONS" << endl;
            line();
            cin >> *choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw WrongType();
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
                    bool is_main_admin = false;
                    if(admin.get_name() == "main" && admin.get_surname() == "admin" && admin.get_password() == "143")
                        is_main_admin = true;
                    if (admin.search() || is_main_admin) {
                        cout << "Hello" << " " << admin.get_name() << "!" << endl;
                        while (true) {
                            try {
                                cout << "Choose one of options" << endl;
                                cout << "1 - add CAR" << endl;
                                cout << "2 - add TRUCK" << endl;
                                cout << "3 - add BUS" << endl;
                                cout << "4 - get information about all CARS" << endl;
                                cout << "5 - get information about all TRUCKS" << endl;
                                cout << "6 - get information about all BUSES" << endl;
                                cout << "7 - change some criteria of CAR" << endl;
                                cout << "8 - change some criteria of TRUCK" << endl;
                                cout << "9 - change some criteria of BUS" << endl;
                                cout << "10 - delete a specific VEHICLE" << endl;
                                cout << "11 - add new admin" << endl;
                                cout << "0 - EXIT" << endl;
                                unique_ptr<int> choice1{new int};
                                cin >> *choice1;
                                line();
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    throw WrongType();
                                }
                                switch (*choice1) {
                                    case 1: {
                                        admin.add_car();
                                        break;
                                    }
                                    case 2: {
                                        admin.add_truck();
                                        break;
                                    }
                                    case 3: {
                                        admin.add_bus();
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
                                        admin.set_car();
                                        break;
                                    }
                                    case 8: {
                                        admin.set_truck();
                                        break;
                                    }
                                    case 9: {
                                        admin.set_bus();
                                        break;
                                    }
                                    case 10: {
                                        admin.delete_vehicle();
                                        break;
                                    }
                                    case 11: {
                                        unique_ptr<string> new_name{new string};
                                        unique_ptr<string> new_surname{new string};
                                        unique_ptr<string> new_password{new string};
                                        cout << "Enter name of new admin:" << endl;
                                        cin >> *new_name;
                                        cout << "Enter surname of new admin:" << endl;
                                        cin >> *new_surname;
                                        cout << "Enter password for new admin:" << endl;
                                        cin >> *new_password;
                                        line();
                                        Admin new_admin(*new_name, *new_surname, *new_password);
                                        new_admin.write_to_file();
                                        cout << "Admin was added successfully" << endl;
                                        line();
                                        break;
                                    }
                                    case 0: {
                                        return 0;
                                    }
                                    default: {
                                        throw WrongChoice();
                                    }
                                }
                            } catch (const WrongChoice &e) {
                                cerr << e.what() << endl;
                            } catch (const WrongType &e) {
                                cerr << e.what() << endl;
                            } catch (const WrongTypeVehicle &e){
                                cerr << e.what() << endl;
                            }
                        }
                    } else {
                        throw ClientNotFound();
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
                    if (user.search()) {
                        cout << "Hello " << user.get_name() << "!" << endl;
                    } else {
                        user.write_to_file();
                        cout << "Hello new client: " << user.get_name() << "!" << endl;
                    }

                    while (true) {
                        try {
                            cout << "Choose one of options" << endl;
                            cout << "1 - get information about all CARS" << endl;
                            cout << "2 - get information about all TRUCKS" << endl;
                            cout << "3 - get information about all BUSES" << endl;
                            cout << "4 - use some filter for CARS" << endl;
                            cout << "5 - use some filter for TRUCKS" << endl;
                            cout << "6 - use some filter for BUSES" << endl;
                            cout << "0 - EXIT " << endl;
                            unique_ptr<int> choice1{new int};
                            cin >> *choice1;
                            line();
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                throw WrongType();
                            }
                            switch (*choice1) {
                                case 1: {
                                    list<Car> cars = User::cars_from_file();
                                    for_each(cars.begin(), cars.end(), [](Car &car) {
                                        car.get_vehicle();
                                        line();
                                    });
                                    break;
                                }
                                case 2: {
                                    list<Truck> trucks = User::trucks_from_file();
                                    for_each(trucks.begin(), trucks.end(),
                                             [](Truck &truck) {
                                                 truck.get_vehicle();
                                                 line();
                                             });
                                    break;
                                }
                                case 3: {
                                    list<Bus> buses = User::buses_from_file();
                                    for_each(buses.begin(), buses.end(),
                                             [](Bus &bus) {
                                                 bus.get_vehicle();
                                                 line();
                                             });
                                    break;
                                }
                                case 4: {
                                    user.car_menu();
                                    break;
                                }
                                case 5: {
                                    user.truck_menu();
                                    break;
                                }
                                case 6: {
                                    user.bus_menu();
                                    break;
                                }
                                case 0: {
                                    return 0;
                                }
                                default: {
                                    throw WrongChoice();
                                }
                            }
                        } catch (const WrongChoice &e) {
                            cerr << e.what() << endl;
                        } catch (const WrongType &e) {
                            cerr << e.what() << endl;
                        }
                    }

                }
                case 3: {
                    line();
                    unique_ptr<string> instruction_file
                            {new string{"database\\instruction.txt"}};
                    FileReader::read_file(*instruction_file);
                    cout << endl;
                    line();
                    break;
                }
                default: {
                    throw WrongChoice();
                }

            }
        } catch (const WrongChoice &e) {
            cerr << e.what() << endl;
        } catch (const WrongType &e) {
            cerr << e.what() << endl;
        } catch (const ClientNotFound &e) {
            cerr << e.what() << endl;
        }

    }
}

