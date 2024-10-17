#include <algorithm>
#include "User.h"
#include <fstream>
#include "WrongChoice.h"
#include "FileReader.h"

User::User(string &new_name, string &new_surname, string &new_password)
        : name(make_unique<string>(new_name)), surname(make_unique<string>(new_surname)),
          password(make_unique<string>(new_password)) {}

User::User(const User &other) {
    name = make_unique<string>(*other.name);
    surname = make_unique<string>(*other.surname);
    password = make_unique<string>(*other.password);
}

User::User(User &&other) noexcept {
    name = std::move(other.name);
    surname = std::move(other.surname);
    password = std::move(other.password);
}

User::User() : name(make_unique<string>()), surname(make_unique<string>()), password(make_unique<string>()) {}

ostream &operator<<(ostream &os, const User &obj) {
    os << *obj.name << "\t" << *obj.surname << "\t" << *obj.password;
    return os;
}

istream &operator>>(istream &is, User &obj) {
    is >> *obj.name >> *obj.surname >> *obj.password;
    return is;
}

User &User::operator=(User &&other) noexcept {
    if (this == &other) return *this;
    name = std::move(other.name);
    surname = std::move(other.surname);
    password = std::move(other.password);
    return *this;
}

User &User::operator=(const User &other) {
    if (this == &other) return *this;
    name = make_unique<string>(*other.name);
    surname = make_unique<string>(*other.surname);
    password = make_unique<string>(*other.password);
    return *this;
}

bool User::search() {
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Users.txt)");
    User A;
    while (fin >> A) {
        if (A.get_name() == this->get_name() &&
            A.get_surname() == this->get_surname() &&
            A.get_password() == this->get_password()) {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

void User::write_to_file() {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Users.txt)", ios_base::app);
    fout << get_name() << "\t" << get_surname() << "\t" << get_password() << endl;
    fout.close();
}

string User::get_name() const {
    return *name;
}

string User::get_surname() const {
    return *surname;
}

string User::get_password() const {
    return *password;
}

void User::set_name(string &new_name) {
    *name = new_name;
}

void User::set_surname(string &new_surname) {
    *surname = new_surname;
}

void User::set_password(string &new_password) {
    *password = new_password;
}

list<Car> User::cars_from_file() {
    shared_ptr<Car> car{new Car()};
    list<Car> cars;
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)");
    while (fin >> *car) {
        cars.push_back(*car);
    }
    fin.close();
    return cars;
}

list<Bus> User::buses_from_file() {
    shared_ptr<Bus> bus{new Bus()};
    list<Bus> buses;
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Buses.txt)");
    while (fin >> *bus) {
        buses.push_back(*bus);
    }
    fin.close();
    return buses;
}

list<Truck> User::trucks_from_file() {
    shared_ptr<Truck> truck{new Truck()};
    list<Truck> trucks;
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)");
    while (fin >> *truck) {
        trucks.push_back(*truck);
    }
    fin.close();
    return trucks;
}

void User::add_car() {
    cout << "You are not admin!!!" << endl;
}

void User::add_truck() {
    cout << "You are not admin!!!" << endl;
}

void User::add_bus() {
    cout << "You are not admin!!!" << endl;
}

void User::set_car() {
    cout << "You are not admin!!!" << endl;
}

void User::set_truck() {
    cout << "You are not admin!!!" << endl;
}

void User::set_bus() {
    cout << "You are not admin!!!" << endl;
}

void User::delete_vehicle() {
    cout << "You are not admin!!!" << endl;
}

void User::car_menu() {
    cout << "CARS filter by:" << endl;
    unique_ptr<string> file{new string{R"(C:\Users\Admin\Desktop\directory_of_cars\database\Car_criteria.txt)"}};
    FileReader::read_file(*file);

    cout << endl;

    unique_ptr<int> choice{new int};
    cin >> *choice;
    list<Car> cars = cars_from_file();
    try {
        switch (*choice) {
            case 1: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the year you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>
                                                     ("1 - lower year \n2 - higher year"));
                    User::line();

                    cars.sort([](const Car &a, const Car &b) {
                        return a.get_year() > b.get_year();
                    });

                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_year_l(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_year_h(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
            }
            case 2: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>
                                                 ("Enter the weight of car you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>
                                                     ("1 - lower weight \n2 - higher weight"));
                    User::line();

                    cars.sort([](const Car &a, const Car &b) {
                        return a.get_weight() < b.get_weight();
                    });
                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_weight_l(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_weight_h(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
            }
            case 3: {
                unique_ptr<double> value =
                        make_unique<double>(
                                User::get_input<double>("Enter the power of car`s engine you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>("1 - lower power \n2 - higher power"));
                    User::line();

                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_power_l(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_power_h(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
            }
            case 4: {
                unique_ptr<double> value =
                        make_unique<double>(
                                User::get_input<double>("Enter the capacity of car`s engine you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>("1 - lower capacity \n2 - higher capacity"));
                    User::line();

                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_capacity_l(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_capacity_h(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
            }
            case 5: {
                unique_ptr<string> value =
                        get_string_input("Enter the fuel of car you want to have");
                User::line();
                cars.sort([](const Car &a, const Car &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(cars.begin(), cars.end(), [&value](Car &car) {
                    if (car.sort_fuel(*value)) {
                        car.get_vehicle();
                        User::line();
                    }
                });
                break;
            }
            case 6: {
                unique_ptr<double> value =
                        make_unique<double>(User::get_input<double>
                                                    ("Enter the consumption of car you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>
                                                     ("1 - lower consumption \n2 - higher consumption"));
                    User::line();

                    cars.sort([](const Car &a, const Car &b) {
                        return a.get_fuel_consumption() < b.get_fuel_consumption();
                    });
                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_consumption_l(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_consumption_h(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 7: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the mileage you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>("1 - lower mileage \n2 - higher mileage"));
                    User::line();

                    cars.sort([](const Car &a, const Car &b) {
                        return a.get_mileage() > b.get_mileage();
                    });

                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_mileage_h(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_mileage_l(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 8: {
                unique_ptr<string> value =
                        get_string_input("Enter the brand of car you want to have");
                User::line();
                cars.sort([](const Car &a, const Car &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(cars.begin(), cars.end(), [&value](Car &car) {
                    if (car.sort_brand(*value)) {
                        car.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 9: {
                unique_ptr<string> value =
                        get_string_input("Enter the model of car you want to have");
                User::line();
                cars.sort([](const Car &a, const Car &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(cars.begin(), cars.end(), [&value](Car &car) {
                    if (car.sort_model(*value)) {
                        car.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 10: {
                unique_ptr<string> value =
                        get_string_input("Enter the color of car you want to have");
                User::line();
                cars.sort([](const Car &a, const Car &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(cars.begin(), cars.end(), [&value](Car &car) {
                    if (car.sort_color(*value)) {
                        car.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 11: {
                unique_ptr<string> value =
                        get_string_input("Enter the location of car you want to have");
                User::line();
                cars.sort([](const Car &a, const Car &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(cars.begin(), cars.end(), [&value](Car &car) {
                    if (car.sort_location(*value)) {
                        car.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 12: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the price you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>("1 - lower price \n2 - higher price"));
                    User::line();

                    cars.sort([](const Car &a, const Car &b) {
                        return a.get_price() > b.get_price();
                    });

                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_price_l(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_price_h(*value)) {
                                car.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }

                break;
            }
            case 13: {
                unique_ptr<string> value =
                        get_string_input("Enter the transmission of car you want to have");
                User::line();
                cars.sort([](const Car &a, const Car &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(cars.begin(), cars.end(), [&value](Car &car) {
                    if (car.sort_transmission(*value)) {
                        car.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 14: {
                unique_ptr<string> value =
                        get_string_input("Enter the wheel drive of car you want to have");
                User::line();
                cars.sort([](const Car &a, const Car &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(cars.begin(), cars.end(), [&value](Car &car) {
                    if (car.sort_wheel_drive(*value)) {
                        car.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            default: {
                throw WrongChoice();
            }

        }
    } catch (WrongChoice &e) {
        cerr << e.what() << endl;
    }
}

void User::truck_menu() {
    cout << "TRUCKS filter by:" << endl;
    unique_ptr<string> file{new string{R"(C:\Users\Admin\Desktop\directory_of_cars\database\Car_criteria.txt)"}};
    FileReader::read_file(*file);
    cout << endl;

    cout << endl;

    unique_ptr<int> choice{new int};
    cin >> *choice;
    list<Truck> trucks = trucks_from_file();
    try {
        switch (*choice) {
            case 1: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the year you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>
                                                     ("1 - lower year \n2 - higher year"));
                    User::line();

                    trucks.sort([](const Truck &a, const Truck &b) {
                        return a.get_year() > b.get_year();
                    });

                    if (*choice1 == 1) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_year_l(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_year_h(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
            }
            case 2: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>
                                                 ("Enter the weight of truck you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>
                                                     ("1 - lower weight \n2 - higher weight"));
                    User::line();

                    trucks.sort([](const Truck &a, const Truck &b) {
                        return a.get_weight() < b.get_weight();
                    });
                    if (*choice1 == 1) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_weight_l(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_weight_h(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
            }
            case 3: {
                unique_ptr<double> value =
                        make_unique<double>(
                                User::get_input<double>("Enter the power of truck`s engine you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>("1 - lower power \n2 - higher power"));
                    User::line();

                    if (*choice1 == 1) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_power_l(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_power_h(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
            }
            case 4: {
                unique_ptr<double> value =
                        make_unique<double>(
                                User::get_input<double>("Enter the capacity of truck`s engine you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>("1 - lower capacity \n2 - higher capacity"));
                    User::line();

                    if (*choice1 == 1) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_capacity_l(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_capacity_h(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
            }
            case 5: {
                unique_ptr<string> value =
                        get_string_input("Enter the fuel of truck you want to have");
                User::line();
                trucks.sort([](const Truck &a, const Truck &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                    if (truck.sort_fuel(*value)) {
                        truck.get_vehicle();
                        User::line();
                    }
                });
                break;
            }
            case 6: {
                unique_ptr<double> value =
                        make_unique<double>(User::get_input<double>
                                                    ("Enter the consumption of truck you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>
                                                     ("1 - lower consumption \n2 - higher consumption"));
                    User::line();

                    trucks.sort([](const Truck &a, const Truck &b) {
                        return a.get_fuel_consumption() < b.get_fuel_consumption();
                    });
                    if (*choice1 == 1) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_consumption_l(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_consumption_h(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 7: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the mileage you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>("1 - lower mileage \n2 - higher mileage"));
                    User::line();

                    trucks.sort([](const Truck &a, const Truck &b) {
                        return a.get_mileage() > b.get_mileage();
                    });

                    if (*choice1 == 1) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_mileage_h(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_mileage_l(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 8: {
                unique_ptr<string> value =
                        get_string_input("Enter the brand of truck you want to have");
                User::line();
                trucks.sort([](const Truck &a, const Truck &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                    if (truck.sort_brand(*value)) {
                        truck.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 9: {
                unique_ptr<string> value =
                        get_string_input("Enter the model of truck you want to have");
                User::line();
                trucks.sort([](const Truck &a, const Truck &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                    if (truck.sort_model(*value)) {
                        truck.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 10: {
                unique_ptr<string> value =
                        get_string_input("Enter the color of truck you want to have");
                User::line();
                trucks.sort([](const Truck &a, const Truck &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                    if (truck.sort_color(*value)) {
                        truck.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 11: {
                unique_ptr<string> value =
                        get_string_input("Enter the location of truck you want to have");
                User::line();
                trucks.sort([](const Truck &a, const Truck &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                    if (truck.sort_location(*value)) {
                        truck.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 12: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the price you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>("1 - lower price \n2 - higher price"));
                    User::line();

                    trucks.sort([](const Truck &a, const Truck &b) {
                        return a.get_price() > b.get_price();
                    });

                    if (*choice1 == 1) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_price_l(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_price_h(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }

                break;
            }
            case 13: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>
                                                 ("Enter the cargo capacity you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>
                                                     ("1 - lower year \n2 - higher year"));
                    User::line();

                    trucks.sort([](const Truck &a, const Truck &b) {
                        return a.get_cargo_capacity() > b.get_cargo_capacity();
                    });

                    if (*choice1 == 1) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_cargo_capacity_l(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(trucks.begin(), trucks.end(), [&value](Truck &truck) {
                            if (truck.sort_cargo_capacity_h(*value)) {
                                truck.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
                break;
            }

            default: {
                throw WrongChoice();
            }

        }
    } catch (WrongChoice &e) {
        cerr << e.what() << endl;
    }
}

void User::bus_menu() {
    cout << "BUSES filter by:" << endl;
    unique_ptr<string> file{new string{R"(C:\Users\Admin\Desktop\directory_of_cars\database\Car_criteria.txt)"}};
    FileReader::read_file(*file);
    cout << endl;

    cout << endl;
    unique_ptr<int> choice{new int};
    cin >> *choice;
    list<Bus> buses = buses_from_file();
    try {
        switch (*choice) {
            case 1: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the year you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>
                                                     ("1 - lower year \n2 - higher year"));
                    User::line();

                    buses.sort([](const Bus &a, const Bus &b) {
                        return a.get_year() > b.get_year();
                    });

                    if (*choice1 == 1) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_year_l(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_year_h(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
            }
            case 2: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>
                                                 ("Enter the weight of truck you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>
                                                     ("1 - lower weight \n2 - higher weight"));
                    User::line();

                    buses.sort([](const Bus &a, const Bus &b) {
                        return a.get_weight() < b.get_weight();
                    });
                    if (*choice1 == 1) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_weight_l(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_weight_h(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
            }
            case 3: {
                unique_ptr<double> value =
                        make_unique<double>(
                                User::get_input<double>("Enter the power of truck`s engine you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>("1 - lower power \n2 - higher power"));
                    User::line();

                    if (*choice1 == 1) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_power_l(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_power_h(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
            }
            case 4: {
                unique_ptr<double> value =
                        make_unique<double>(
                                User::get_input<double>("Enter the capacity of truck`s engine you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>("1 - lower capacity \n2 - higher capacity"));
                    User::line();

                    if (*choice1 == 1) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_capacity_l(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_capacity_h(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
            }
            case 5: {
                unique_ptr<string> value =
                        get_string_input("Enter the fuel of truck you want to have");
                User::line();
                buses.sort([](const Bus &a, const Bus &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                    if (bus.sort_fuel(*value)) {
                        bus.get_vehicle();
                        User::line();
                    }
                });
                break;
            }
            case 6: {
                unique_ptr<double> value =
                        make_unique<double>(User::get_input<double>
                                                    ("Enter the consumption of truck you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>
                                                     ("1 - lower consumption \n2 - higher consumption"));
                    User::line();

                    buses.sort([](const Bus &a, const Bus &b) {
                        return a.get_fuel_consumption() < b.get_fuel_consumption();
                    });
                    if (*choice1 == 1) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_consumption_l(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_consumption_h(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 7: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the mileage you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>("1 - lower mileage \n2 - higher mileage"));
                    User::line();

                    buses.sort([](const Bus &a, const Bus &b) {
                        return a.get_mileage() > b.get_mileage();
                    });

                    if (*choice1 == 1) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_mileage_h(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_mileage_l(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 8: {
                unique_ptr<string> value =
                        get_string_input("Enter the brand of truck you want to have");
                User::line();
                buses.sort([](const Bus &a, const Bus &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                    if (bus.sort_brand(*value)) {
                        bus.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 9: {
                unique_ptr<string> value =
                        get_string_input("Enter the model of truck you want to have");
                User::line();
                buses.sort([](const Bus &a, const Bus &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                    if (bus.sort_model(*value)) {
                        bus.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 10: {
                unique_ptr<string> value =
                        get_string_input("Enter the color of truck you want to have");
                User::line();
                buses.sort([](const Bus &a, const Bus &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                    if (bus.sort_color(*value)) {
                        bus.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 11: {
                unique_ptr<string> value =
                        get_string_input("Enter the location of truck you want to have");
                User::line();
                buses.sort([](const Bus &a, const Bus &b) {
                    return a.get_year() < b.get_year();
                });
                for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                    if (bus.sort_location(*value)) {
                        bus.get_vehicle();
                        User::line();
                    }
                });

                break;
            }
            case 12: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the price you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>("1 - lower price \n2 - higher price"));
                    User::line();

                    buses.sort([](const Bus &a, const Bus &b) {
                        return a.get_price() > b.get_price();
                    });

                    if (*choice1 == 1) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_price_l(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_price_h(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }

                break;
            }
            case 13: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>
                                                 ("Enter the cargo capacity you want to start from"));
                try {
                    User::line();
                    cout << "Enter what do you want to get" << endl;
                    unique_ptr<int> choice1 =
                            make_unique<int>(User::get_input<int>
                                                     ("1 - lower year \n2 - higher year"));
                    User::line();

                    buses.sort([](const Bus &a, const Bus &b) {
                        return a.get_passenger_capacity() > b.get_passenger_capacity();
                    });

                    if (*choice1 == 1) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_passenger_capacity_l(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(buses.begin(), buses.end(), [&value](Bus &bus) {
                            if (bus.sort_passenger_capacity_h(*value)) {
                                bus.get_vehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoice();
                    }
                } catch (WrongChoice &e) {
                    cerr << e.what() << endl;
                }
                break;
            }

            default: {
                throw WrongChoice();
            }

        }
    } catch (WrongChoice &e) {
        cerr << e.what() << endl;
    }
}
