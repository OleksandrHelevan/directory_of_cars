#include "Engine.h"
#include "fstream"
#include "WrongTypeEx.h"
using namespace std;

Engine::Engine() : capacity(0.0), fuel(" "), power(0.0) {}

Engine::Engine(double cap, string& new_fuel, double pow) :capacity{cap},
        fuel{new_fuel},power{pow}{}

ostream &operator<<(ostream& os, const Engine& obj){
    os<<obj.capacity<<"\t"<<obj.fuel<<"\t"<<obj.power<<"\t";
    return os;
}

istream& operator>>(istream& is, Engine& obj){
is>>obj.capacity>>obj.fuel>>obj.power;
    return is;
}

bool Engine::sort_capacity_l(double cap) {
    return this->capacity <= cap;
}

bool Engine::sort_power_l(double pow) {
    return this->power <= pow;
}

bool Engine::sort_capacity_h(double cap) {
    return this->capacity >= cap;
}

bool Engine::sort_power_h(double pow) {
    return this->power >= pow;
}

bool Engine::sort_fuel(std::string &fuel1) {
    return this->fuel==fuel1;
}

Engine::Engine(const Engine &other) {
    fuel=other.fuel;
    capacity=other.capacity;
    power=other.power;
}

Engine::Engine(Engine &&other)  noexcept {
    fuel=other.fuel;
    capacity=other.capacity;
    power=other.power;
    other.power=0;
    other.fuel=" ";
    other.capacity=0;
}

void Engine::getEngine() const {
    cout<<"Capacity: "<<capacity<<" liters"<<"\nFuel: "<<fuel<<"\nPower (kW): "<<power<<endl;
}