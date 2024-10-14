#include "Admin.h"
#include <fstream>
#include "ClientNotFound.h"
#include "WrongChoice.h"
#include "FileReader.h"
#include <list>
#include <algorithm>
#include <memory>

using namespace std;

Admin::Admin(string &new_name, string &new_surname, string &new_password) {
    name = make_unique<string>(new_name);
    surname = make_unique<string>(new_surname);
    password = make_unique<string>(new_password);

    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)");
    fout << "authorization of ADMIN" << endl;
    fout.close();
}

[[maybe_unused]] Admin::Admin(const Admin &other) {
    name = make_unique<string>(*other.name);
    surname = make_unique<string>(*other.surname);
    password = make_unique<string>(*other.password);
}

[[maybe_unused]] Admin::Admin(Admin &&other) noexcept
        : name(std::move(other.name)), surname(std::move(other.surname)), password(std::move(other.password)) {}

Admin::Admin() : name(make_unique<string>("")), surname(make_unique<string>("")), password(make_unique<string>("")) {}

ostream &operator<<(ostream &os, const Admin &obj) {
    os << "Name: " << *obj.name << ", Surname: " << *obj.surname << ", Password: " << *obj.password;
    return os;
}

istream &operator>>(istream &is, Admin &obj) {
    string name, surname, password;
    is >> name >> surname >> password;
    obj.set_name(name);
    obj.set_surname(surname);
    obj.set_password(password);
    return is;
}

Admin &Admin::operator=(Admin &&other) noexcept {
    if (this == &other) return *this;
    name = std::move(other.name);
    surname = std::move(other.surname);
    password = std::move(other.password);
    return *this;
}

Admin &Admin::operator=(const Admin &other) {
    if (this == &other) return *this;
    name = make_unique<string>(*other.name);
    surname = make_unique<string>(*other.surname);
    password = make_unique<string>(*other.password);
    return *this;
}

void Admin::write_to_file() {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Admins.txt)", ios_base::app);
    fout << *name << "\t" << *surname << "\t" << *password << endl;
    fout.close();
}

Admin::~Admin() noexcept {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)", ios_base::app);
    fout << "Admin destructor" << endl;
    fout.close();
}

string Admin::get_name() const {
    return *name;
}

[[maybe_unused]] string Admin::get_surname() const {
    return *surname;
}

[[maybe_unused]] string Admin::get_password() const {
    return *password;
}

void Admin::set_name(const string &new_name) {
    name = make_unique<string>(new_name);
}

void Admin::set_surname(const string &new_surname) {
    surname = make_unique<string>(new_surname);
}

void Admin::set_password(const string &new_password) {
    password = make_unique<string>(new_password);
}


bool Admin::search() {
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Admins.txt)");
    Admin A;
    while (fin >> A) {
        if (*A.name == *name && *A.surname == *surname && *A.password == *password) {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

void Admin::car_menu() {
    cout<<"You are not Client"<<endl;
}
void Admin::truck_menu() {
    cout<<"You are not Client"<<endl;
}
void Admin::bus_menu() {
    cout<<"You are not Client"<<endl;
}

void Admin::add_car() {
    unique_ptr<string> brand =
            get_string_input("Enter BRAND of car:");
    unique_ptr<string> model =
            get_string_input("Enter MODEL of car:");
    unique_ptr<int> year =
            make_unique<int>(get_input<int>("Enter YEAR of car:"));
    unique_ptr<string> color =
            get_string_input("Enter COLOR of car:");
    unique_ptr<double> capacity =
            make_unique<double>(get_input<double>("Enter CAPACITY of car's engine (cubic decimeters):"));
    unique_ptr<string> fuel =
            get_string_input("Enter FUEL of car's engine:");
    unique_ptr<double> power =
            make_unique<double>(get_input<double>("Enter POWER of car's engine (kW):"));

    Engine engine(*capacity, *fuel, *power);

    unique_ptr<int> weight =
            make_unique<int>(get_input<int>("Enter WEIGHT of car (kg):"));
    unique_ptr<double> fuelConsumption =
            make_unique<double>(get_input<double>("Enter FUEL CONSUMPTION of car (liters/100km):"));
    unique_ptr<int> mileage =
            make_unique<int>(get_input<int>("Enter MILEAGE of car (thousands of km):"));
    unique_ptr<string> location =
            get_string_input("Enter LOCATION of car:");
    unique_ptr<string> wheelDrive =
            get_string_input("Enter WHEEL DRIVE of car (full/back/front or other):");
    unique_ptr<string> transmission =
            get_string_input("Enter TRANSMISSION of car (automatic/mechanics or other):");
    unique_ptr<int> price =
            make_unique<int>(get_input<int>("Enter PRICE of car ($):"));

    Car car(engine, *weight, *fuelConsumption, *mileage,
            *color, *brand, *model, *year, *location,
            *price, *wheelDrive, *transmission);

    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)", ios_base::app);
    fout << car;
    fout.close();
}


void Admin::add_truck() {
    unique_ptr<string> brand =
            get_string_input("Enter BRAND of truck:");
    unique_ptr<string> model =
            get_string_input("Enter MODEL of truck:");
    unique_ptr<int> year =
            make_unique<int>(get_input<int>("Enter YEAR of truck:"));
    unique_ptr<string> color =
            get_string_input("Enter COLOR of truck:");
    unique_ptr<double> capacity =
            make_unique<double>(get_input<double>("Enter CAPACITY of truck's engine (cubic decimeters):"));
    unique_ptr<string> fuel =
            get_string_input("Enter FUEL of truck's engine:");
    unique_ptr<double> power =
            make_unique<double>(get_input<double>("Enter POWER of truck's engine (kW):"));

    Engine engine(*capacity, *fuel, *power);

    unique_ptr<int> weight =
            make_unique<int>(get_input<int>("Enter WEIGHT of truck (kg):"));
    unique_ptr<double> fuelConsumption =
            make_unique<double>(get_input<double>("Enter FUEL CONSUMPTION of truck (liters/100km):"));
    unique_ptr<int> mileage =
            make_unique<int>(get_input<int>("Enter MILEAGE of truck (thousands of km):"));
    unique_ptr<string> location =
            get_string_input("Enter LOCATION of truck:");
    unique_ptr<int> cargoCapacity =
            make_unique<int>(get_input<int>("Enter CARGO CAPACITY of truck (kg):"));
    unique_ptr<int> price =
            make_unique<int>(get_input<int>("Enter PRICE of truck ($):"));

    Truck truck(engine, *weight, *fuelConsumption, *mileage,
                *color, *brand, *model, *year, *location,
                *price, *cargoCapacity);

    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)", ios_base::app);
    fout << truck;
    fout.close();
}


void Admin::add_bus() {
    unique_ptr<string> brand =
            get_string_input("Enter BRAND of bus:");
    unique_ptr<string> model =
            get_string_input("Enter MODEL of bus:");
    unique_ptr<int> year =
            make_unique<int>(get_input<int>("Enter YEAR of bus:"));
    unique_ptr<string> color =
            get_string_input("Enter COLOR of bus:");
    unique_ptr<double> capacity =
            make_unique<double>(get_input<double>("Enter CAPACITY of bus's engine (cubic decimeters):"));
    unique_ptr<string> fuel =
            get_string_input("Enter FUEL of bus's engine:");
    unique_ptr<double> power =
            make_unique<double>(get_input<double>("Enter POWER of bus's engine (kW):"));

    Engine engine(*capacity, *fuel, *power);

    unique_ptr<int> weight =
            make_unique<int>(get_input<int>("Enter WEIGHT of bus (kg):"));
    unique_ptr<double> fuelConsumption =
            make_unique<double>(get_input<double>("Enter FUEL CONSUMPTION of bus (liters/100km):"));
    unique_ptr<int> mileage =
            make_unique<int>(get_input<int>("Enter MILEAGE of bus (thousands of km):"));
    unique_ptr<string> location =
            get_string_input("Enter LOCATION of bus:");
    unique_ptr<int> passengerCapacity =
            make_unique<int>(get_input<int>("Enter PASSENGER CAPACITY of bus (persons):"));
    unique_ptr<int> price =
            make_unique<int>(get_input<int>("Enter PRICE of bus ($):"));

    Bus bus(engine, *weight, *fuelConsumption, *mileage,
            *color, *brand, *model, *year, *location,
            *price, *passengerCapacity);

    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Buses.txt)", ios_base::app);
    fout << bus;
    fout.close();
}

list<Car> Admin::cars_from_file() {
    shared_ptr<Car> car{new Car()};
    list<Car> cars;
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)");
    while (fin >> *car) {
        cars.push_back(*car);
    }
    fin.close();
    return cars;
}

list<Bus> Admin::buses_from_file() {
    shared_ptr<Bus> bus{new Bus};
    list<Bus> buses;
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Buses.txt)");
    while (fin >> *bus) {
        buses.push_back(*bus);
    }
    fin.close();
    return buses;
}

list<Truck> Admin::trucks_from_file() {
    shared_ptr<Truck> truck{new Truck};
    list<Truck> trucks;
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)");
    while (fin >> *truck) {
        trucks.push_back(*truck);
    }
    fin.close();
    return trucks;
}

void Admin::set_car() {

    list<Car> cars = Admin::cars_from_file();
    std::for_each(cars.begin(), cars.end(), [](Car &car) {
        car.get_vehicle();
        Admin::line();
    });

    cout << "Enter the brand, model, year and color of CAR which you would like to change" << endl;
    unique_ptr<string> brand =
            get_string_input("Enter BRAND of car:");
    unique_ptr<string> model =
            get_string_input("Enter MODEL of car:");
    unique_ptr<int> year =
            make_unique<int>(get_input<int>("Enter YEAR of car:"));
    unique_ptr<string> color =
            get_string_input("Enter COLOR of car:");
    try {
        Car car1(*year, *brand, *model, *color);
        if (!car1.if_exists(cars))
            throw runtime_error("Car was not found!");

        unique_ptr<string> file{new string{R"(C:\Users\Admin\Desktop\directory_of_cars\database\Car_criteria.txt)"}};
        FileReader::read_file(*file);
        Admin::line();

        unique_ptr<int> choice{new int{0}};
        while (unique_ptr<int> choice1 =
                make_unique<int>(get_input<int>("Enter the choice for changing"))
                ) {
            try {
                if (*choice1 > 14 || *choice1 < 0)
                    throw WrongChoice();
                else {
                    *choice = *choice1;
                    break;
                }
            } catch (WrongChoice &e) {
                cerr << e.what() << endl;
            }
        }

        ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)");
        for (Car &car: cars) {
            if (car.get_brand() == *brand && car.get_model() == *model && car.get_year() == *year &&
                car.get_color() == *color) {
                switch (*choice) {
                    case 1: {
                        unique_ptr<int> year1 = make_unique<int>
                                (get_input<int>("Enter YEAR of car would you like to change:"));
                        car.set_year(*year1);
                        break;
                    }
                    case 2: {
                        unique_ptr<int> weight =
                                make_unique<int>(get_input<int>("Enter WEIGHT of car would you like to change:"));
                        car.set_weight(*weight);
                        break;
                    }
                    case 3: {
                        unique_ptr<double> power =
                                make_unique<double>(
                                        get_input<double>("Enter POWER of car's engine would you like to change:"));
                        Engine engine = car.get_engine();
                        engine.set_power(*power);
                        car.set_engine(engine);
                        break;
                    }
                    case 4: {
                        unique_ptr<double> capacity =
                                make_unique<double>(
                                        get_input<double>("Enter CAPACITY of car's engine would you like to change:"));
                        Engine engine = car.get_engine();
                        engine.set_capacity(*capacity);
                        car.set_engine(engine);
                        break;
                    }
                    case 5: {
                        unique_ptr<string> fuel =
                                get_string_input("Enter FUEL of car's engine would you like to change:");
                        Engine engine = car.get_engine();
                        engine.set_fuel(*fuel);
                        car.set_engine(engine);
                        break;
                    }
                    case 6: {
                        unique_ptr<double> fuelConsumption =
                                make_unique<double>(get_input<double>
                                                            ("Enter FUEL CONSUMPTION of car liters/100km would you like to change:"));
                        car.set_fuel_consumption(*fuelConsumption);
                        break;
                    }
                    case 7: {
                        unique_ptr<int> mileage =
                                make_unique<int>(get_input<int>(
                                        "Enter MILEAGE of car in thousands of km would you like to change:"));
                        car.set_mileage(*mileage);
                        break;
                    }
                    case 8: {
                        unique_ptr<string> brand1 = get_string_input("Enter BRAND of car would you like to change:");
                        car.set_brand(*brand1);

                        break;
                    }
                    case 9: {
                        unique_ptr<string> model1 =
                                get_string_input("Enter MODEL of car would you like to change:");
                        car.set_model(*model1);
                        break;
                    }
                    case 10: {
                        unique_ptr<string> color1 =
                                get_string_input("Enter COLOR of car would you like to change:");
                        car.set_color(*color1);
                        break;
                    }
                    case 11: {
                        unique_ptr<string> location =
                                get_string_input("Enter LOCATION of car would you like to change:");
                        car.set_location(*location);
                        break;
                    }
                    case 12: {
                        unique_ptr<int> price =
                                make_unique<int>(get_input<int>("Enter PRICE of car would you like to change:"));
                        car.set_price(*price);
                        break;
                    }
                    case 13: {
                        unique_ptr<string> transmission =
                                get_string_input(
                                        "Enter TRANSMISSION of car (automatic/mechanics) would you like to change:");
                        car.set_transmission(*transmission);
                        break;
                    }
                    case 14: {
                        unique_ptr<string> wheelDrive =
                                get_string_input(
                                        "Enter WHEEL DRIVE of car (full/back/front) would you like to change:");
                        car.set_wheel_drive(*wheelDrive);
                        break;
                    }
                    default: {
                        throw WrongChoice();
                    }
                }
            }
            fout << car;
        }
        fout.close();

    } catch (WrongChoice &e) {
        cerr << e.what() << endl;
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
}

void Admin::set_truck() {
    list<Truck> trucks = Admin::trucks_from_file();
    std::for_each(trucks.begin(), trucks.end(), [](Truck &truck) {
        truck.get_vehicle();
        Admin::line();
    });

    cout << "Enter the brand, model, year and color of TRUCK which you would like to change" << endl;
    unique_ptr<string> brand =
            get_string_input("Enter BRAND of truck:");
    unique_ptr<string> model =
            get_string_input("Enter MODEL of truck:");
    unique_ptr<int> year =
            make_unique<int>(get_input<int>("Enter YEAR of truck:"));
    unique_ptr<string> color =
            get_string_input("Enter COLOR of truck:");
    try {
        Truck truck1(*year, *brand, *model, *color);
        if (!truck1.if_exists(trucks))
            throw runtime_error("Truck was not found!");

        unique_ptr<string> file{new string{R"(C:\Users\Admin\Desktop\directory_of_cars\database\Truck_criteria.txt)"}};
        FileReader::read_file(*file);

        unique_ptr<int> choice{new int{0}};
        while (unique_ptr<int> choice1 =
                make_unique<int>(get_input<int>("Enter the choice for changing"))
                ) {
            try {
                if (*choice1 > 14 || *choice1 < 0)
                    throw WrongChoice();
                else {
                    *choice = *choice1;
                    break;
                }
            } catch (WrongChoice &e) {
                cerr << e.what() << endl;
            }
        }

        ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)");
        for (Truck &truck: trucks) {
            if (truck.get_brand() == *brand && truck.get_model() == *model && truck.get_year() == *year &&
                truck.get_color() == *color) {
                switch (*choice) {
                    case 1: {
                        unique_ptr<int> year1 = make_unique<int>
                                (get_input<int>("Enter YEAR of truck would you like to change:"));
                        truck.set_year(*year1);
                        break;
                    }
                    case 2: {
                        unique_ptr<int> weight =
                                make_unique<int>(get_input<int>("Enter WEIGHT of truck would you like to change:"));
                        truck.set_weight(*weight);
                        break;
                    }
                    case 3: {
                        unique_ptr<double> power =
                                make_unique<double>(
                                        get_input<double>("Enter POWER of truck's engine would you like to change:"));
                        Engine engine = truck.get_engine();
                        engine.set_power(*power);
                        truck.set_engine(engine);
                        break;
                    }
                    case 4: {
                        unique_ptr<double> capacity =
                                make_unique<double>(
                                        get_input<double>(
                                                "Enter CAPACITY of truck's engine would you like to change:"));
                        Engine engine = truck.get_engine();
                        engine.set_capacity(*capacity);
                        truck.set_engine(engine);
                        break;
                    }
                    case 5: {
                        unique_ptr<string> fuel =
                                get_string_input("Enter FUEL of truck's engine would you like to change:");
                        Engine engine = truck.get_engine();
                        engine.set_fuel(*fuel);
                        truck.set_engine(engine);
                        break;
                    }
                    case 6: {
                        unique_ptr<double> fuelConsumption =
                                make_unique<double>(get_input<double>
                                                            ("Enter FUEL CONSUMPTION of truck liters/100km would you like to change:"));
                        truck.set_fuel_consumption(*fuelConsumption);
                        break;
                    }
                    case 7: {
                        unique_ptr<int> mileage =
                                make_unique<int>(get_input<int>(
                                        "Enter MILEAGE of truck in thousands of km would you like to change:"));
                        truck.set_mileage(*mileage);
                        break;
                    }
                    case 8: {
                        unique_ptr<string> brand1 = get_string_input("Enter BRAND of truck would you like to change:");
                        truck.set_brand(*brand1);

                        break;
                    }
                    case 9: {
                        unique_ptr<string> model1 =
                                get_string_input("Enter MODEL of truck would you like to change:");
                        truck.set_model(*model1);
                        break;
                    }
                    case 10: {
                        unique_ptr<string> color1 =
                                get_string_input("Enter COLOR of truck would you like to change:");
                        truck.set_color(*color1);
                        break;
                    }
                    case 11: {
                        unique_ptr<string> location =
                                get_string_input("Enter LOCATION of truck would you like to change:");
                        truck.set_location(*location);
                        break;
                    }
                    case 12: {
                        unique_ptr<int> price =
                                make_unique<int>(get_input<int>("Enter PRICE of truck would you like to change:"));
                        truck.set_price(*price);
                        break;
                    }
                    case 13: {
                        unique_ptr<int> cargo =
                                make_unique<int>(
                                        get_input<int>("Enter CARGO CAPACITY of truck would you like to change:"));
                        truck.set_cargo_capacity(*cargo);
                        break;
                    }
                    default: {
                        throw WrongChoice();
                    }
                }
            }
            fout << truck;
        }
        fout.close();
    } catch (WrongChoice &e) {
        cerr << e.what() << endl;
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
}

void Admin::set_bus() {
    list<Bus> buses = Admin::buses_from_file();
    std::for_each(buses.begin(), buses.end(), [](Bus &bus) {
        bus.get_vehicle();
        Admin::line();
    });

    cout << "Enter the brand, model, year and color of BUS which you would like to change" << endl;
    unique_ptr<string> brand =
            get_string_input("Enter BRAND of bus:");
    unique_ptr<string> model =
            get_string_input("Enter MODEL of bus:");
    unique_ptr<int> year =
            make_unique<int>(get_input<int>("Enter YEAR of bus:"));
    unique_ptr<string> color =
            get_string_input("Enter COLOR of bus:");
    try {
        Bus bus1(*year, *brand, *model, *color);
        if (!bus1.if_exists(buses))
            throw runtime_error("Truck was not found!");

        unique_ptr<string> file{new string{R"(C:\Users\Admin\Desktop\directory_of_cars\database\Bus_criteria.txt)"}};
        FileReader::read_file(*file);

        unique_ptr<int> choice{new int{0}};
        while (unique_ptr<int> choice1 =
                make_unique<int>(get_input<int>("Enter the choice for changing"))
                ) {
            try {
                if (*choice1 > 14 || *choice1 < 0)
                    throw WrongChoice();
                else {
                    *choice = *choice1;
                    break;
                }
            } catch (WrongChoice &e) {
                cerr << e.what() << endl;
            }
        }


        ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Buses.txt)");

        for (Bus &bus: buses) {
            if (bus.get_brand() == *brand && bus.get_model() == *model && bus.get_year() == *year &&
                bus.get_color() == *color) {
                switch (*choice) {
                    case 1: {
                        unique_ptr<int> year1 = make_unique<int>
                                (get_input<int>("Enter YEAR of bus would you like to change:"));
                        bus.set_year(*year1);
                        break;
                    }
                    case 2: {
                        unique_ptr<int> weight =
                                make_unique<int>(get_input<int>("Enter WEIGHT of bus would you like to change:"));
                        bus.set_weight(*weight);
                        break;
                    }
                    case 3: {
                        unique_ptr<double> power =
                                make_unique<double>(
                                        get_input<double>("Enter engine`s POWER of bus would you like to change:"));
                        Engine engine = bus.get_engine();
                        engine.set_power(*power);
                        bus.set_engine(engine);
                        break;
                    }
                    case 4: {
                        unique_ptr<double> capacity =
                                make_unique<double>(
                                        get_input<double>("Enter engine`s CAPACITY of bus would you like to change:"));
                        Engine engine = bus.get_engine();
                        engine.set_capacity(*capacity);
                        bus.set_engine(engine);
                        break;
                    }
                    case 5: {
                        unique_ptr<string> fuel =
                                get_string_input("Enter engine`s FUEL of bus would you like to change:");
                        Engine engine = bus.get_engine();
                        engine.set_fuel(*fuel);
                        bus.set_engine(engine);
                        break;
                    }
                    case 6: {
                        unique_ptr<double> fuelConsumption =
                                make_unique<double>(get_input<double>
                                                            ("Enter FUEL CONSUMPTION of bus liters/100km would you like to change:"));
                        bus.set_fuel_consumption(*fuelConsumption);
                        break;
                    }
                    case 7: {
                        unique_ptr<int> mileage =
                                make_unique<int>(get_input<int>(
                                        "Enter MILEAGE of bus in thousands of km would you like to change:"));
                        bus.set_mileage(*mileage);
                        break;
                    }
                    case 8: {
                        unique_ptr<string> brand1 = get_string_input("Enter BRAND of bus would you like to change:");
                        bus.set_brand(*brand1);

                        break;
                    }
                    case 9: {
                        unique_ptr<string> model1 =
                                get_string_input("Enter MODEL of bus would you like to change:");
                        bus.set_model(*model1);
                        break;
                    }
                    case 10: {
                        unique_ptr<string> color1 =
                                get_string_input("Enter COLOR of bus would you like to change:");
                        bus.set_color(*color1);
                        break;
                    }
                    case 11: {
                        unique_ptr<string> location =
                                get_string_input("Enter LOCATION of bus would you like to change:");
                        bus.set_location(*location);
                        break;
                    }
                    case 12: {
                        unique_ptr<int> price =
                                make_unique<int>(get_input<int>("Enter PRICE of bus would you like to change:"));
                        bus.set_price(*price);
                        break;
                    }
                    case 13: {
                        unique_ptr<int> passenger =
                                make_unique<int>(
                                        get_input<int>("Enter PASSENGER CAPACITY of bus would you like to change:"));
                        bus.set_passenger_capacity(*passenger);
                        break;
                    }
                    default: {
                        throw WrongChoice();
                    }
                }
            }
            fout << bus;
        }
        fout.close();
    } catch (WrongChoice &e) {
        cerr << e.what() << endl;
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
}

void Admin::delete_vehicle() {
    cout << "Make choice what do you want to delete:" << endl;
    cout << "1 - CAR" << endl;
    cout << "2 - TRUCK " << endl;
    cout << "3 - BUS" << endl;

    unique_ptr<int> choice{new int};
    cin >> *choice;
    try {
        switch (*choice) {
            case 1: {
                list<Car> cars = Admin::cars_from_file();
                std::for_each(cars.begin(), cars.end(), [](Car &car) {
                    car.get_vehicle();
                    Admin::line();
                });


                cout << "Enter the brand, model, year and color of CAR which you would like to delete" << endl;
                unique_ptr<string> brand =
                        get_string_input("Enter BRAND of car:");
                unique_ptr<string> model =
                        get_string_input("Enter MODEL of car:");
                unique_ptr<int> year =
                        make_unique<int>(get_input<int>("Enter YEAR of car:"));
                unique_ptr<string> color =
                        get_string_input("Enter COLOR of car:");


                Car car1(*year, *brand, *model, *color);
                if (!car1.if_exists(cars))
                    throw runtime_error("Truck was not found!");
                ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)");
                for (Car &car: cars) {
                    if (car.get_brand() == *brand && car.get_model()
                                                     == *model && car.get_year() == *year &&
                        car.get_color() == *color) {
                    } else {
                        fout << car;
                    }
                }
                fout.close();
                cout << "Car have been deleted!" << endl;
                line();
                break;
            }
            case 2: {
                list<Truck> trucks = Admin::trucks_from_file();
                std::for_each(trucks.begin(), trucks.end(), [](Truck &truck) {
                    truck.get_vehicle();
                    Admin::line();
                });


                cout << "Enter the brand, model, year and color of TRUCK which you would like to delete" << endl;
                unique_ptr<string> brand =
                        get_string_input("Enter BRAND of truck:");
                unique_ptr<string> model =
                        get_string_input("Enter MODEL of truck:");
                unique_ptr<int> year =
                        make_unique<int>(get_input<int>("Enter YEAR of truck:"));
                unique_ptr<string> color =
                        get_string_input("Enter COLOR of truck:");


                Truck truck1(*year, *brand, *model, *color);
                if (!truck1.if_exists(trucks))
                    throw runtime_error("Truck was not found!");
                ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)");
                for (Truck &truck: trucks) {
                    if (truck.get_brand() == *brand && truck.get_model()
                                                       == *model && truck.get_year() == *year &&
                        truck.get_color() == *color) {
                    } else {
                        fout << truck;
                    }
                }
                fout.close();
                cout << "Truck have been deleted!" << endl;
                line();
                break;
            }

            case 3: {
                list<Bus> buses = Admin::buses_from_file();
                std::for_each(buses.begin(), buses.end(), [](Bus &bus) {
                    bus.get_vehicle();
                    Admin::line();
                });


                cout << "Enter the brand, model, year and color of BUS which you would like to delete" << endl;
                unique_ptr<string> brand =
                        get_string_input("Enter BRAND of bus:");
                unique_ptr<string> model =
                        get_string_input("Enter MODEL of bus:");
                unique_ptr<int> year =
                        make_unique<int>(get_input<int>("Enter YEAR of bus:"));
                unique_ptr<string> color =
                        get_string_input("Enter COLOR of bus:");


                Bus bus1(*year, *brand, *model, *color);
                if (!bus1.if_exists(buses))
                    throw runtime_error("Truck was not found!");
                ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)");
                for (Bus &bus: buses) {
                    if (bus.get_brand() == *brand && bus.get_model()
                                                     == *model && bus.get_year() == *year &&
                        bus.get_color() == *color) {
                    } else {
                        fout << bus;
                    }
                }
                fout.close();
                cout << "Bus have been deleted!" << endl;
                line();
                break;
            }
            default: {
                throw WrongChoice();
            }
        }
    } catch (WrongChoice &e) {
        cerr << e.what() << endl;
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
}





