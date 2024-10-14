#include "Engine.h"
#include "WrongType.h"
#include "fstream"
#include <algorithm>

using namespace std;

Engine::Engine() : capacity{new double{0}}, fuel(" "), power(0.0) {}

Engine::Engine([[maybe_unused]] double cap, string &new_fuel, double pow)
        : capacity{make_unique<double>(cap)}, fuel{new_fuel}, power{pow} {}

ostream &operator<<(ostream &os, const Engine &obj) {
    os << *obj.capacity << "\t" << obj.fuel << "\t" << obj.power << "\t";
    return os;
}

istream &operator>>(istream &is, Engine &obj) {
    is >> *obj.capacity >> obj.fuel >> obj.power;
    return is;
}

bool Engine::sort_capacity_l(double cap) {
    return *this->capacity <= cap;
}

bool Engine::sort_power_l(double pow) const {
    return this->power <= pow;
}

bool Engine::sort_capacity_h(double cap) {
    return *this->capacity >= cap;
}

bool Engine::sort_power_h(double pow) const {
    return this->power >= pow;
}

bool Engine::sort_fuel(std::string &new_fuel) {
    transform(new_fuel.begin(), new_fuel.end(), new_fuel.begin(), [](char c) {
        return std::tolower(c);
    });
    cout << new_fuel;
    return this->fuel == new_fuel;

}

Engine::Engine(const Engine &other) {
    fuel = other.fuel;
    capacity = make_unique<double>(*other.capacity);
    power = other.power;
}

Engine::Engine(Engine &&other) noexcept {
    fuel = std::move(other.fuel);
    capacity = std::move(other.capacity);
    power = other.power;
    other.power = 0;
    other.fuel = " ";
    other.capacity = nullptr;
}

void Engine::get_engine() const {
    cout << "Capacity: " << *capacity << " liters" << "\nFuel: " << fuel << "\nPower (kW): " << power << endl;
}

Engine &Engine::operator=(const Engine &other) {
    if (this == &other)
        return *this;
    capacity = make_unique<double>(*other.capacity);
    fuel = other.fuel;
    power = other.power;
    return *this;
}

Engine &Engine::operator=(Engine &&other) noexcept {
    if (this == &other)
        return *this;
    capacity = std::move(other.capacity);
    fuel = std::move(other.fuel);
    power = other.power;
    return *this;
}

Engine::~Engine() {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)", ios_base::app);
    fout << *capacity << " " << fuel << " destructor" << endl;
    fout.close();
}

void Engine::set_capacity(double new_capacity) {
    *this->capacity = new_capacity;
}

void Engine::set_fuel(string &new_fuel) {
    this->fuel = new_fuel;
}

void Engine::set_power(double new_power) {
    this->power = new_power;
}

[[maybe_unused]] double Engine::get_capacity() {
    return *capacity;
}

[[maybe_unused]] string Engine::get_fuel() {
    return fuel;
}

[[maybe_unused]] double Engine::get_power() const {
    return power;
}