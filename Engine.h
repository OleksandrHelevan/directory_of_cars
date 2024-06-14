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
    void write_to_file();
    ~Engine() {cout<<capacity<<" "<<fuel<<" engine is deleted";};

};


#endif //DIRECTORY_OF_CARS_ENGINE_H
