#include "Vehicle.h"
#include "fstream"
using namespace std;


Vehicle::Vehicle() : engine{Engine()}, weight{0}, fuel_consumption{0},
                     mileage{0}, color{"none"}, brand{"none"}, model{"none"},
                     year{0}, location{"none"}, price{make_unique<int>(0)} {}

Vehicle::Vehicle(Engine& new_engine, int weigh, double consumption, int new_mileage, string& col,
    string& bran, string& mod, int new_year, string& loc, int new_price) : engine{new_engine},
    weight{weigh}, fuel_consumption{consumption}, mileage{new_mileage}, color{col},
    brand{bran}, model{mod}, year{new_year}, location{loc}, price{make_unique<int>(new_price)} {}

Vehicle::Vehicle(const Vehicle& other) : engine{other.engine}, weight{other.weight},
    fuel_consumption{other.fuel_consumption}, mileage{other.mileage}, color{other.color},
    brand{other.brand}, model{other.model}, year{other.year}, location{other.location},
    price{make_unique<int>(*other.price)} {}

Vehicle::Vehicle(Vehicle&& other) noexcept : engine{std::move(other.engine)}, weight{other.weight},
    fuel_consumption{other.fuel_consumption}, mileage{other.mileage}, color{std::move(other.color)},
    brand{std::move(other.brand)}, model{std::move(other.model)}, year{other.year}, location{std::move(other.location)},
    price{std::move(other.price)} {}

Vehicle& Vehicle::operator=(const Vehicle& other) {
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

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept {
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
    os << obj.brand << "\t" << obj.model << "\t" << obj.color << "\t" << obj.year << "\t" << *obj.price << "\t" << obj.mileage <<
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
    return this->model == mod;
}

bool Vehicle::sort_color(std::string &col) {
    return this->color == col;
}

bool Vehicle::sort_brand(std::string &bra) {
    return this->brand == bra;
}

bool Vehicle::sort_year_l(int yea) const {
    return this->year <= yea;
}

bool Vehicle::sort_year_h(int yea) const {
    return this->year >= yea;
}

bool Vehicle::sort_location(std::string &loc) {
    return this->location == loc;
}

bool Vehicle::sort_price_h(int pric) const {
    return *this->price >= pric;
}

bool Vehicle::sort_price_l(int pric) const {
    return *this->price <= pric;
}

void Vehicle::getVehicle() const {
    cout << brand << " " << model << " " << color << " " << year << endl <<
         "Price: " << *price << " $\nMileage: " << mileage << " thousands of km" << "\nFuel consumption: "
         << fuel_consumption << " liters/100km" << "\nWeight: " << weight << " kg" << "\nLocation: " << location << endl;
    engine.getEngine();
}

Vehicle::~Vehicle() {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)",ios_base::app);
    fout << model <<" "<<brand<<" "<<year<< " destructor"<<endl;
    fout.close();
}

void Vehicle::setEngine(const Engine& newEngine) {
    this->engine = newEngine;
}

void Vehicle::setWeight(int newWeight) {
    this->weight = newWeight;
}

void Vehicle::setFuelConsumption(double newFuelConsumption) {
    this->fuel_consumption = newFuelConsumption;
}

void Vehicle::setMileage(int newMileage) {
    this->mileage = newMileage;
}

void Vehicle::setColor(const string& newColor) {
    this->color = newColor;
}

void Vehicle::setBrand(const string& newBrand) {
    this->brand = newBrand;
}

void Vehicle::setModel(const string& newModel) {
    this->model = newModel;
}

void Vehicle::setYear(int newYear) {
    this->year = newYear;
}

void Vehicle::setLocation(const string& newLocation) {
    this->location = newLocation;
}

void Vehicle::setPrice(int newPrice) {
    *this->price = newPrice;
}


Engine Vehicle::getEngine() const{
    return engine;
}

int Vehicle::getWeight() const {
    return weight;
}

double Vehicle::getFuelConsumption() const {
    return fuel_consumption;
}

int Vehicle::getMileage() const {
    return mileage;
}

string Vehicle::getColor() const {
    return color;
}

string Vehicle::getBrand() const {
    return brand;
}

string Vehicle::getModel() const {
    return model;
}

int Vehicle::getYear() const {
    return year;
}

string Vehicle::getLocation() const {
    return location;
}

int Vehicle::getPrice() const {
    return *price;
}

