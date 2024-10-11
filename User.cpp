#include <algorithm>
#include "User.h"
#include <fstream>
#include "WrongChoice.h"
#include "CriteriaReader.h"

User::User(std::string &new_name, std::string &new_surname, std::string &new_password)
: Person(new_name,new_surname,new_password){}

User::User(const User &other) : Person(other){}

User::User(User &&other) noexcept : Person(std::move(other)){}

User::User() :Person(){}

ostream& operator<<(ostream& os, const User& obj){
    os<<static_cast<Person&>((Person &) obj);
    return os;
}

istream& operator>>(istream& is, User& obj){
    is>>static_cast<Person&>(obj);
    return is;
}

User &User::operator=(User &&other) noexcept {
    if (this == &other) return *this;
    Person::operator=(std::move(other));
    return *this;
}

User &User::operator=(const User &other) {
    if (this == &other) return *this;
    Person::operator=(other);
    return *this;
}

bool User::search() {
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Users.txt)");
    User A;
    while(fin >> A){
        if(A.get_name() == Person::get_name() && A.get_surname() == Person::get_surname()
           && A.get_password() == Person::get_password()){
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

void User::write_to_file() {
    Person::write_to_file();
}

string User::get_name() {
    return Person::get_name();
}

string User::get_surname() {
    return Person::get_surname();
}

string User::get_password() {
    return Person::get_password();
}

void User::set_name(string &newname) {
    Person::set_name(newname);
}

void User::set_surname(string &newsurname) {
    Person::set_surname(newsurname);
}

void User::set_password(string &newpassword) {
    Person::set_password(newpassword);
}


void User::car_menu() {
    cout<<"CARS filter by:"<<endl;
    string file = R"(C:\Users\Admin\Desktop\directory_of_cars\database\Car_criteria.txt)";
    CriteriaReader reader(file);
    reader.read_file();
    cout<<endl;

    unique_ptr<int> choice{new int};
    cin>>*choice;
    list<Car> cars = cars_from_file();
    try {
        switch (*choice) {
            case 1: {
                unique_ptr<int> value =
                make_unique<int>(User::get_input<int>("Enter the year you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 2: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>
                                                 ("Enter the weight of car you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 3: {
                unique_ptr<double> value =
                make_unique<double>(User::get_input<double>("Enter the power of car`s engine you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>("1 - lower power \n2 - higher power"));
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 4: {
                unique_ptr<double> value =
                make_unique<double>(User::get_input<double>("Enter the capacity of car`s engine you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>("1 - lower capacity \n2 - higher capacity"));
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
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
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
                break;
            }
            case 7: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the mileage you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>("1 - lower mileage \n2 - higher mileage"));
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
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
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>("1 - lower price \n2 - higher price"));
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
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
    }catch (WrongChoice& e){
        cerr<<e.what()<<endl;
    }
}

void User::truck_menu() {
    cout<<"TRUCKS filter by:"<<endl;
    string file = R"(C:\Users\Admin\Desktop\directory_of_cars\database\Truck_criteria.txt)";
    CriteriaReader reader(file);
    reader.read_file();
    cout<<endl;

    cout<<endl;

    unique_ptr<int> choice{new int};
    cin>>*choice;
    list<Truck> trucks = trucks_from_file();
    try {
        switch (*choice) {
            case 1: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the year you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 2: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>
                                                 ("Enter the weight of truck you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 3: {
                unique_ptr<double> value =
                        make_unique<double>(
                                User::get_input<double>("Enter the power of truck`s engine you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>("1 - lower power \n2 - higher power"));
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 4: {
                unique_ptr<double> value =
                        make_unique<double>(
                                User::get_input<double>("Enter the capacity of truck`s engine you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>("1 - lower capacity \n2 - higher capacity"));
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
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
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
                break;
            }
            case 7: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the mileage you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>("1 - lower mileage \n2 - higher mileage"));
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
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
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>("1 - lower price \n2 - higher price"));
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }

                break;
            }
            case 13: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>
                                                 ("Enter the cargo capacity you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
                break;
            }

            default: {
                throw WrongChoice();
            }

        }
    }catch (WrongChoice& e){
        cerr<<e.what()<<endl;
    }
}

void User::bus_menu() {
    cout<<"BUSES filter by:"<<endl;
    string file = R"(C:\Users\Admin\Desktop\directory_of_cars\database\Bus_criteria.txt)";
    CriteriaReader reader(file);
    reader.read_file();
    cout<<endl;

    cout<<endl;

    unique_ptr<int> choice{new int};
    cin>>*choice;
    list<Bus> buses = buses_from_file();
    try {
        switch (*choice) {
            case 1: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the year you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 2: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>
                                                 ("Enter the weight of truck you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 3: {
                unique_ptr<double> value =
                        make_unique<double>(
                                User::get_input<double>("Enter the power of truck`s engine you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>("1 - lower power \n2 - higher power"));
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 4: {
                unique_ptr<double> value =
                        make_unique<double>(
                                User::get_input<double>("Enter the capacity of truck`s engine you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>("1 - lower capacity \n2 - higher capacity"));
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
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
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
                break;
            }
            case 7: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>("Enter the mileage you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>("1 - lower mileage \n2 - higher mileage"));
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
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
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>("1 - lower price \n2 - higher price"));
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }

                break;
            }
            case 13: {
                unique_ptr<int> value =
                        make_unique<int>(User::get_input<int>
                                                 ("Enter the cargo capacity you want to start from"));
                try {
                    User::line();
                    cout<<"Enter what do you want to get"<<endl;
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::get_input<int>
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
                }catch(WrongChoice& e){
                    cerr<<e.what()<<endl;
                }
                break;
            }

            default: {
                throw WrongChoice();
            }

        }
    }catch (WrongChoice& e){
        cerr<<e.what()<<endl;
    }
}
