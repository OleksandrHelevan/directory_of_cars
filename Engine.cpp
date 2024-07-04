#include "Engine.h"
#include "WrongTypeEx.h"
using namespace std;

Engine::Engine() : capacity{new double {0}}, fuel(" "), power(0.0) {}

Engine::Engine([[maybe_unused]] double cap, string& new_fuel, double pow)
    :capacity{make_unique<double>(cap)}, fuel{new_fuel},power{pow}{}

ostream &operator<<(ostream& os, const Engine& obj){
    os<<*obj.capacity<<"\t"<<obj.fuel<<"\t"<<obj.power<<"\t";
    return os;
}

istream& operator>>(istream& is, Engine& obj){
is>>*obj.capacity>>obj.fuel>>obj.power;
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

bool Engine::sort_fuel(std::string &fuel1) {
    return this->fuel==fuel1;
}

Engine::Engine(const Engine &other) {
    fuel=other.fuel;
    capacity = make_unique<double>(*other.capacity);
    power=other.power;
}

Engine::Engine(Engine &&other)  noexcept {
    fuel=std::move(other.fuel);
    capacity = std::move(other.capacity);
    power=other.power;
    other.power=0;
    other.fuel=" ";
    other.capacity = nullptr;
}

void Engine::getEngine() const {
    cout<<"Capacity: "<<*capacity<<" liters"<<"\nFuel: "<<fuel<<"\nPower (kW): "<<power<<endl;
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
    cout<<*capacity<<" "<<fuel<<" destructor"<<endl;
    capacity = nullptr;
}