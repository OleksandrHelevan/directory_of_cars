#include <algorithm>
#include "User.h"
#include <fstream>
#include "WrongChoiceEx.h"

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
        if(A.getname() == Person::getname() && A.getsurname() == Person::getsurname()
           && A.getpassword() == Person::getpassword()){
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


list<Truck> User::trucks_from_file() {
    return Person::trucks_from_file();
}

list<Bus> User::buses_from_file() {
    return Person::buses_from_file();
}

list <Car> User::cars_from_file() {
    return Person::cars_from_file();
}

string User::getname() {
    return Person::getname();
}

string User::getsurname() {
    return Person::getsurname();
}

string User::getpassword() {
    return Person::getpassword();
}

void User::setname(std::string &newname) {
    Person::setname(newname);
}

void User::setsurname(std::string &newsurname) {
    Person::setsurname(newsurname);
}

void User::setpassword(std::string &newpassword) {
    Person::setpassword(newpassword);
}


void User::carMenu() {
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Car_criteria.txt)");
    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }
    fin.close();

    unique_ptr<int> choice{new int};
    cin>>*choice;
    list<Car> cars = cars_from_file();
    try {
        switch (*choice) {
            case 1: {
                unique_ptr<int> value =
                make_unique<int>(User::getInput<int>("Enter the year you want to start from"));
                try {
                    User::line();
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::getInput<int>
                                    ("1 - lower year \n2 - higher year"));
                    User::line();

                    cars.sort([](const Car &a, const Car &b) {
                        return a.getYear() > b.getYear();
                    });

                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_year_l(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_year_h(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoiceEx();
                    }
                }catch(WrongChoiceEx& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 2: {
                unique_ptr<int> value =
                        make_unique<int>( User::getInput<int>
                                ("Enter the weight of car you want to start from"));
                try {
                    User::line();
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::getInput<int>
                                    ("1 - lower weight \n2 - higher weight"));
                    User::line();

                    cars.sort([](const Car &a, const Car &b) {
                        return a.getWeight() < b.getWeight();
                    });
                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_weight_l(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_weight_h(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoiceEx();
                    }
                }catch(WrongChoiceEx& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 3: {
                unique_ptr<double> value =
                make_unique<double>(User::getInput<double>("Enter the power of car`s engine you want to start from"));
                try {
                    User::line();
                    unique_ptr<double> choice1 =
                            make_unique<double> (User::getInput<double>("1 - lower power \n2 - higher power"));
                    User::line();

//                    cars.sort([](const Car &a, const Car &b) {
//                        return a.getWeight() < b.getWeight();
//                    });
                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_power_l(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_power_h(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoiceEx();
                    }
                }catch(WrongChoiceEx& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 4: {
                unique_ptr<double> value =
                make_unique<double>(User::getInput<double>("Enter the capacity of car`s engine you want to start from"));
                try {
                    User::line();
                    unique_ptr<double> choice1 =
                            make_unique<double> (User::getInput<double>("1 - lower capacity \n2 - higher capacity"));
                    User::line();

//                    cars.sort([](const Car &a, const Car &b) {
//                        return a.getWeight() < b.getWeight();
//                    });
                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_capacity_l(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_capacity_h(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoiceEx();
                    }
                }catch(WrongChoiceEx& e){
                    cerr<<e.what()<<endl;
                }
            }
            case 5: {
                    //FUEL
                break;
            }
            case 6: {
                unique_ptr<double> value =
                    make_unique<double>(User::getInput<double>
                        ("Enter the consumption of car you want to start from"));
                try {
                    User::line();
                    unique_ptr<double> choice1 =
                            make_unique<double> (User::getInput<double>
                                ("1 - lower consumption \n2 - higher consumption"));
                    User::line();

                    cars.sort([](const Car &a, const Car &b) {
                        return a.getFuelConsumption() < b.getFuelConsumption();
                    });
                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_consumption_l(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_consumption_h(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoiceEx();
                    }
                }catch(WrongChoiceEx& e){
                    cerr<<e.what()<<endl;
                }
                break;
            }
            case 7: {
                unique_ptr<int> value =
                        make_unique<int>(User::getInput<int>("Enter the mileage you want to start from"));
                try {
                    User::line();
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::getInput<int>("1 - lower mileage \n2 - higher mileage"));
                    User::line();

                    cars.sort([](const Car &a, const Car &b) {
                        return a.getMileage() > b.getMileage();
                    });

                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_mileage_h(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_mileage_l(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoiceEx();
                    }
                }catch(WrongChoiceEx& e){
                    cerr<<e.what()<<endl;
                }
                break;
            }
            case 8: {

                break;
            }
            case 9: {

                break;
            }
            case 10: {

                break;
            }
            case 11: {

                break;
            }
            case 12: {
                unique_ptr<int> value =
                        make_unique<int>(User::getInput<int>("Enter the price you want to start from"));
                try {
                    User::line();
                    unique_ptr<int> choice1 =
                            make_unique<int> (User::getInput<int>("1 - lower price \n2 - higher price"));
                    User::line();

                    cars.sort([](const Car &a, const Car &b) {
                        return a.getPrice() > b.getPrice();
                    });

                    if (*choice1 == 1) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_price_l(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    }
                    if (*choice1 == 2) {
                        for_each(cars.begin(), cars.end(), [&value](Car &car) {
                            if (car.sort_price_h(*value)) {
                                car.getVehicle();
                                User::line();
                            }
                        });
                        break;
                    } else {
                        throw WrongChoiceEx();
                    }
                }catch(WrongChoiceEx& e){
                    cerr<<e.what()<<endl;
                }

                break;
            }
            case 13: {

                break;
            }
            case 14: {

                break;
            }
            default: {
                throw WrongChoiceEx();
            }

        }
    }catch (WrongChoiceEx& e){
        cerr<<e.what()<<endl;
    }
}
