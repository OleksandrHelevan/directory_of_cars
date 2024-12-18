#include "Vehicle.h"
#include "fstream"
#include <algorithm>

using namespace std;


Vehicle::Vehicle() : engine{Engine()}, weight{0}, fuel_consumption{0},
                     mileage{0}, color{"none"}, brand{"none"}, model{"none"},
                     year{0}, location{"none"}, price{make_unique<int>(0)} {}


Vehicle::Vehicle(Engine &new_engine, int weigh, double consumption, int new_mileage, string &col,
                 string &bran, string &mod, int new_year, string &loc, int new_price)
        : engine{new_engine}, weight{weigh}, fuel_consumption{consumption}, mileage{new_mileage},
          color{col}, brand{bran}, model{mod}, year{new_year}, location{loc},
          price{make_unique<int>(new_price)} {}

Vehicle::Vehicle(const Vehicle &other) : engine{other.engine}, weight{other.weight},
                                         fuel_consumption{other.fuel_consumption}, mileage{other.mileage},
                                         color{other.color},
                                         brand{other.brand}, model{other.model}, year{other.year},
                                         location{other.location},
                                         price{make_unique<int>(*other.price)} {}

Vehicle::Vehicle(Vehicle &&other) noexcept: engine{std::move(other.engine)}, weight{other.weight},
                                            fuel_consumption{other.fuel_consumption}, mileage{other.mileage},
                                            color{std::move(other.color)},
                                            brand{std::move(other.brand)}, model{std::move(other.model)},
                                            year{other.year}, location{std::move(other.location)},
                                            price{std::move(other.price)} {}

Vehicle &Vehicle::operator=(const Vehicle &other) {
    if (this == &other) return *this;

    engine = other.engine;
    weight = other.weight;
    fuel_consumption = other.fuel_consumption;
    mileage = other.mileage;
    color = other.color;
    brand = other.brand;
    model = other.model;
    year = other.year;
    location = other.location;

    price = make_unique<int>(*other.price);

    return *this;
}

Vehicle::Vehicle(int year, std::string &brand, std::string &model, std::string &color) {
    this->brand = brand;
    this->year = year;
    this->model = model;
    this->color = color;
}

Vehicle &Vehicle::operator=(Vehicle &&other) noexcept {
    if (this == &other) return *this;

    engine = std::move(other.engine);
    weight = other.weight;
    fuel_consumption = other.fuel_consumption;
    mileage = other.mileage;
    color = std::move(other.color);
    brand = std::move(other.brand);
    model = std::move(other.model);
    year = other.year;
    location = std::move(other.location);
    price = std::move(other.price);

    return *this;
}

ostream &operator<<(ostream &os, const Vehicle &obj) {
    os << obj.brand << "\t" << obj.model << "\t" << obj.color << "\t" << obj.year << "\t" << *obj.price << "\t"
       << obj.mileage <<
       "\t" << obj.fuel_consumption << "\t" << obj.weight << "\t" << obj.location << "\t" << obj.engine;
    return os;
}

istream &operator>>(istream &is, Vehicle &obj) {
    is >> obj.brand >> obj.model >> obj.color >> obj.year >> *obj.price >> obj.mileage >>
       obj.fuel_consumption >> obj.weight >> obj.location >> obj.engine;
    return is;
}

bool Vehicle::sort_fuel(std::string &fuel1) {
    return engine.sort_fuel(fuel1);
}

bool Vehicle::sort_capacity_h(double cap) {
    return engine.sort_capacity_h(cap);
}

bool Vehicle::sort_capacity_l(double cap) {
    return engine.sort_capacity_l(cap);
}

bool Vehicle::sort_power_h(double pow) {
    return engine.sort_power_h(pow);
}

bool Vehicle::sort_power_l(double pow) {
    return engine.sort_power_l(pow);
}

bool Vehicle::sort_weight_h(int weigh) const {
    return this->weight >= weigh;
}

bool Vehicle::sort_weight_l(int weigh) const {
    return this->weight <= weigh;
}

bool Vehicle::sort_consumption_l(double cons) const {
    return this->fuel_consumption <= cons;
}

bool Vehicle::sort_consumption_h(double cons) const {
    return this->fuel_consumption >= cons;
}

bool Vehicle::sort_mileage_l(int mil) const {
    return this->mileage <= mil;
}

bool Vehicle::sort_mileage_h(int mil) const {
    return this->mileage >= mil;
}
bool Vehicle::sort_model(std::string &mod) {
    transform(mod.begin(), mod.end(), mod.begin(), [](char c) {
        return std::tolower(c);
    });

    std::string model_copy = this->model;
    transform(model_copy.begin(), model_copy.end(), model_copy.begin(), [](char c) {
        return std::tolower(c);
    });

    return model_copy == mod;
}

bool Vehicle::sort_color(std::string &col) {
    transform(col.begin(), col.end(), col.begin(), [](char c) {
        return std::tolower(c);
    });

    std::string color_copy = this->color;
    transform(color_copy.begin(), color_copy.end(), color_copy.begin(), [](char c) {
        return std::tolower(c);
    });

    return color_copy == col;
}

bool Vehicle::sort_brand(std::string &bra) {
    transform(bra.begin(), bra.end(), bra.begin(), [](char c) {
        return std::tolower(c);
    });

    std::string brand_copy = this->brand;
    transform(brand_copy.begin(), brand_copy.end(), brand_copy.begin(), [](char c) {
        return std::tolower(c);
    });

    return brand_copy == bra;
}

bool Vehicle::sort_year_l(int yea) const {
    return this->year <= yea;
}

bool Vehicle::sort_year_h(int yea) const {
    return this->year >= yea;
}

bool Vehicle::sort_location(std::string &loc) {
    transform(loc.begin(), loc.end(), loc.begin(), [](char c) {
        return std::tolower(c);
    });

    std::string location_copy = this->location;
    transform(location_copy.begin(), location_copy.end(), location_copy.begin(), [](char c) {
        return std::tolower(c);
    });

    return location_copy == loc;
}


bool Vehicle::sort_price_h(int pric) const {
    return *this->price >= pric;
}

bool Vehicle::sort_price_l(int pric) const {
    return *this->price <= pric;
}

void Vehicle::get_vehicle() const {
    cout << brand << " " << model << " " << color << " " << year << endl <<
         "Price: " << *price << " $\nMileage: " << mileage << " thousands of km" << "\nFuel consumption: "
         << fuel_consumption << " liters/100km" << "\nWeight: " << weight << " kg" << "\nLocation: " << location
         << endl;
    engine.get_engine();
}

Vehicle::~Vehicle() {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)", ios_base::app);
    fout << model << " " << brand << " " << year << " destructor" << endl;
    fout.close();
}

void Vehicle::set_engine(const Engine &newEngine) {
    this->engine = newEngine;
}

void Vehicle::set_weight(int newWeight) {
    this->weight = newWeight;
}

void Vehicle::set_fuel_consumption(double newFuelConsumption) {
    this->fuel_consumption = newFuelConsumption;
}

void Vehicle::set_mileage(int newMileage) {
    this->mileage = newMileage;
}

void Vehicle::set_color(const string &newColor) {
    this->color = newColor;
}

void Vehicle::set_brand(const string &newBrand) {
    this->brand = newBrand;
}

void Vehicle::set_model(const string &newModel) {
    this->model = newModel;
}

void Vehicle::set_year(int newYear) {
    this->year = newYear;
}

void Vehicle::set_location(const string &newLocation) {
    this->location = newLocation;
}

void Vehicle::set_price(int newPrice) {
    *this->price = newPrice;
}


Engine Vehicle::get_engine() const {
    return engine;
}

int Vehicle::get_weight() const {
    return weight;
}

double Vehicle::get_fuel_consumption() const {
    return fuel_consumption;
}

int Vehicle::get_mileage() const {
    return mileage;
}

string Vehicle::get_color() const {
    return color;
}

string Vehicle::get_brand() const {
    return brand;
}

string Vehicle::get_model() const {
    return model;
}

int Vehicle::get_year() const {
    return year;
}

string Vehicle::get_location() const {
    return location;
}

int Vehicle::get_price() const {
    return *price;
}

