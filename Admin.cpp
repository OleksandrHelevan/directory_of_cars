
#include "Admin.h"
#include <fstream>
#include "Client_not_found.h"
#include "FileReader.h"
#include "Wrong_choice.h"
#include <list>
#include <algorithm>


Admin::Admin(std::string &new_name, std::string &new_surname, std::string &new_password)
        : Person(new_name, new_surname, new_password) {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)");
    fout <<"authorization of ADMIN"<<endl;
    fout.close();
}

Admin::Admin(const Admin &other) : Person(other) {}

Admin::Admin(Admin &&other) noexcept : Person(std::move(other)) {}

Admin::Admin() : Person() {}




string Admin::get_name() {
    return Person::get_name();
}

string Admin::get_surname() {
    return Person::get_surname();
}

string Admin::get_password() {
    return Person::get_password();
}

ostream& operator<<(ostream& os, const Admin& obj) {
    os << static_cast<Person&>((Person &) obj);
    return os;
}

istream& operator>>(istream& is, Admin& obj) {
    is >> static_cast<Person&>(obj);
    return is;
}

Admin &Admin::operator=(Admin &&other) noexcept {
    if (this == &other) return *this;
    Person::operator=(std::move(other));
    return *this;
}

Admin &Admin::operator=(const Admin &other) {
    if (this == &other) return *this;
    Person::operator=(other);
    return *this;
}


void Admin::write_to_file() {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Admins.txt)", ios_base::app);
    fout << get_name() << "\t" << get_surname() << "\t" << get_password() << endl;
    fout.close();
}


Admin::~Admin() noexcept {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)", ios_base::app);
    fout << "Admin destructor"<<endl;
    fout.close();
}

void Admin::set_surname(string &newsurname) {
    Person::set_surname(newsurname);
}

void Admin::set_name(string &newname) {
    Person::set_name(newname);
}

void Admin::set_password(string &newpassword) {
    Person::set_password(newpassword);
}

bool Admin::search() {
    ifstream fin(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Admins.txt)");
    Admin A;
    while(fin >> A){
        try {
            if (A.get_name() == Person::get_name() && A.get_surname() == Person::get_surname()
                && A.get_password() == Person::get_password()) {
                fin.close();
                return true;
            } else {
                throw Client_not_found();
            }
        }catch (Client_not_found& e){
            fin.close();
            cerr<<"Admin "<<e.what()<<endl;
        }
    }
    fin.close();
    return false;
}



void Admin::add_car() {
    unique_ptr<string> brand =
            getStringInput("Enter BRAND of car:");
    unique_ptr<string> model =
            getStringInput("Enter MODEL of car:");
    unique_ptr<int> year =
            make_unique<int>(getInput<int>("Enter YEAR of car:"));
    unique_ptr<string> color =
            getStringInput("Enter COLOR of car:");
    unique_ptr<double> capacity =
            make_unique<double>(getInput<double>("Enter CAPACITY of car's engine:"));
    unique_ptr<string> fuel =
            getStringInput("Enter FUEL of car's engine:");
    unique_ptr<double> power =
            make_unique<double>(getInput<double>("Enter POWER of car's engine:"));

    Engine engine(*capacity, *fuel, *power);

    unique_ptr<int> weight =
            make_unique<int>(getInput<int>("Enter WEIGHT of car:"));
    unique_ptr<double> fuelConsumption =
            make_unique<double>(getInput<double>("Enter FUEL CONSUMPTION of car/100km:"));
    unique_ptr<int> mileage =
            make_unique<int>(getInput<int>("Enter MILEAGE of car in thousands of km:"));
    unique_ptr<string> location =
            getStringInput("Enter LOCATION of car:");
    unique_ptr<string> wheelDrive =
            getStringInput("Enter WHEEL DRIVE of car (full/back/front):");
    unique_ptr<string> transmission =
            getStringInput("Enter TRANSMISSION of car (automatic/mechanics):");
    unique_ptr<int> price =
            make_unique<int>(getInput<int>("Enter PRICE of car:"));

    Car car(engine, *weight, *fuelConsumption, *mileage,
            *color, *brand, *model, *year, *location,
            *price, *wheelDrive, *transmission);

    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Cars.txt)", ios_base::app);
    fout << car;
    fout.close();
}


void Admin::add_truck() {
    unique_ptr<string> brand =
            getStringInput("Enter BRAND of truck:");
    unique_ptr<string> model =
            getStringInput("Enter MODEL of truck:");
    unique_ptr<int> year =
            make_unique<int>(getInput<int>("Enter YEAR of truck:"));
    unique_ptr<string> color =
            getStringInput("Enter COLOR of truck:");
    unique_ptr<double> capacity =
            make_unique<double>(getInput<double>("Enter CAPACITY of truck's engine:"));
    unique_ptr<string> fuel =
            getStringInput("Enter FUEL of truck's engine:");
    unique_ptr<double> power =
            make_unique<double>(getInput<double>("Enter POWER of truck's engine:"));

    Engine engine(*capacity, *fuel, *power);

    unique_ptr<int> weight =
            make_unique<int>(getInput<int>("Enter WEIGHT of truck:"));
    unique_ptr<double> fuelConsumption =
            make_unique<double>(getInput<double>("Enter FUEL CONSUMPTION of truck/100km:"));
    unique_ptr<int> mileage =
            make_unique<int>(getInput<int>("Enter MILEAGE of truck in thousands of km:"));
    unique_ptr<string> location =
            getStringInput("Enter LOCATION of truck:");
    unique_ptr<int> cargoCapacity =
            make_unique<int>(getInput<int>("Enter CARGO CAPACITY of truck:"));
    unique_ptr<int> price =
            make_unique<int>(getInput<int>("Enter PRICE of truck:"));

    Truck truck(engine, *weight, *fuelConsumption, *mileage,
                *color, *brand, *model, *year, *location,
                *price, *cargoCapacity);

    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Trucks.txt)", ios_base::app);
    fout << truck;
    fout.close();
}


void Admin::add_bus() {
    unique_ptr<string> brand =
            getStringInput("Enter BRAND of bus:");
    unique_ptr<string> model =
            getStringInput("Enter MODEL of bus:");
    unique_ptr<int> year =
            make_unique<int>(getInput<int>("Enter YEAR of bus:"));
    unique_ptr<string> color=
            getStringInput("Enter COLOR of bus:");
    unique_ptr<double> capacity =
            make_unique<double>(getInput<double>("Enter CAPACITY of bus's engine:"));
    unique_ptr<string> fuel =
            getStringInput("Enter FUEL of bus's engine:");
    unique_ptr<double> power =
            make_unique<double>(getInput<double>("Enter POWER of bus's engine:"));

    Engine engine(*capacity, *fuel, *power);

    unique_ptr<int> weight =
            make_unique<int>(getInput<int>("Enter WEIGHT of bus:"));
    unique_ptr<double> fuelConsumption =
            make_unique<double>(getInput<double>("Enter FUEL CONSUMPTION of bus/100km:"));
    unique_ptr<int> mileage =
            make_unique<int>(getInput<int>("Enter MILEAGE of bus in thousands of km:"));
    unique_ptr<string> location =
            getStringInput("Enter LOCATION of bus:");
    unique_ptr<int> passengerCapacity =
            make_unique<int>(getInput<int>("Enter PASSENGER CAPACITY of bus:"));
    unique_ptr<int> price =
            make_unique<int>(getInput<int>("Enter PRICE of bus:"));

    Bus bus(engine, *weight, *fuelConsumption, *mileage,
            *color, *brand, *model, *year, *location,
            *price, *passengerCapacity);

    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\Buses.txt)", ios_base::app);
    fout << bus;
    fout.close();
}

void Admin::set_car() {
    string file = R"(C:\Users\Admin\Desktop\directory_of_cars\database\Car_criteria.txt)";
    FileReader::read_file(file);
    cout<<endl;
    list<Car> cars = Admin::cars_from_file();
    std::for_each(cars.begin(), cars.end(),[](Car& car){
        car.get_vehicle();
        Admin::line();
    });

    cout<<"Enter the brand, model, year and color of Car which you would like to change"<<endl;
    unique_ptr<string> brand =
            getStringInput("Enter BRAND of car:");
    unique_ptr<string> model =
            getStringInput("Enter MODEL of car:");
    unique_ptr<int> year =
            make_unique<int>(getInput<int>("Enter YEAR of car:"));
    unique_ptr<string> color =
            getStringInput("Enter COLOR of car:");
    try{
        Car car1(*year,*brand,*model,*color);
        if(!car1.if_exists(cars))
            throw runtime_error("Car was not found!");

    unique_ptr<int> choice{new int};
    cin>>*choice;

    for(Car &car: cars) {
        if(car.get_brand() == *brand && car.get_model() == *model && car.get_year() == *year && car.get_color() == *color) {
            switch (*choice) {
                case 1: {
                    unique_ptr<int> year1 =  make_unique<int>
                            (getInput<int>("Enter YEAR of car would you like to change:"));
                    car.set_year(*year1);
                    break;
                }
                case 2: {
                    unique_ptr<int> weight =
                            make_unique<int>(getInput<int>("Enter WEIGHT of car would you like to change:"));
                    car.set_weight(*weight);
                    break;
                }
                case 3: {
                    unique_ptr<double> power =
                            make_unique<double>(getInput<double>("Enter POWER of car's engine would you like to change:"));
                    Engine engine = car.get_engine();
                    engine.set_power(*power);
                    car.set_engine(engine);
                    break;
                }
                case 4: {
                    unique_ptr<double> capacity =
                            make_unique<double>(getInput<double>("Enter CAPACITY of car's engine would you like to change:"));
                    Engine engine = car.get_engine();
                    engine.set_capacity(*capacity);
                    car.set_engine(engine);
                    break;
                }
                case 5: {
                    unique_ptr<string> fuel =
                            getStringInput("Enter FUEL of car's engine would you like to change:");
                    Engine engine = car.get_engine();
                    engine.set_fuel(*fuel);
                    car.set_engine(engine);
                    break;
                }
                case 6: {
                    unique_ptr<double> fuelConsumption =
                            make_unique<double>(getInput<double>
                                    ("Enter FUEL CONSUMPTION of car/100km would you like to change:"));
                    car.set_fuel_consumption(*fuelConsumption);
                    break;
                }
                case 7: {
                    unique_ptr<int> mileage =
                            make_unique<int>(getInput<int>("Enter MILEAGE of car in thousands of km would you like to change:"));
                    car.set_mileage(*mileage);
                    break;
                }
                case 8: {
                    unique_ptr<string> brand1 = getStringInput("Enter BRAND of car would you like to change:");
                    car.set_brand(*brand1);

                    break;
                }
                case 9: {
                    unique_ptr<string> model1 =
                            getStringInput("Enter MODEL of car would you like to change:");
                   car.set_model(*model1);
                    break;
                }
                case 10: {
                    unique_ptr<string> color1 =
                            getStringInput("Enter COLOR of car would you like to change:");
                    car.set_color(*color1);
                    break;
                }
                case 11: {
                    unique_ptr<string> location =
                            getStringInput("Enter LOCATION of car would you like to change:");
                   car.set_location(*location);
                    break;
                }
                case 12: {
                    unique_ptr<int> price =
                            make_unique<int>(getInput<int>("Enter PRICE of car would you like to change:"));
                    car.set_price(*price);
                    break;
                }
                case 13: {
                    unique_ptr<string> transmission =
                            getStringInput("Enter TRANSMISSION of car (automatic/mechanics) would you like to change:");
                    car.set_transmission(*transmission);
                    break;
                }
                case 14: {
                    unique_ptr<string> wheelDrive =
                            getStringInput("Enter WHEEL DRIVE of car (full/back/front) would you like to change:");
                    car.set_wheel_drive(*wheelDrive);
                    break;
                }
                default: {
                    throw Wrong_choice();
                }
            }
        }
    }

    }catch (Wrong_choice &e){
        cerr<<e.what()<<endl;
    }catch (exception &e){
        cerr<<e.what()<<endl;
    }
}


