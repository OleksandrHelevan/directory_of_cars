#ifndef DIRECTORY_OF_CARS_ENGINE_H
#define DIRECTORY_OF_CARS_ENGINE_H

#include <iostream>
using namespace std;

class Engine {
double capacity;
string fuel;
double power;

public:
    Engine();
    Engine(double cap, string& new_fuel, double pow);
    friend ostream &operator<<(ostream& os, const Engine& obj);
    friend istream &operator>>(istream& is, Engine& engine);
    ~Engine() {}//cout<<capacity<<" "<<fuel<<" engine is deleted";};
    bool sort_capacity_l(double cap);
    bool sort_power_l(double pow);
    bool sort_capacity_h(double cap);
    bool sort_power_h(double pow);
    bool sort_fuel(string &fuel1);
};


#endif //DIRECTORY_OF_CARS_ENGINE_H
