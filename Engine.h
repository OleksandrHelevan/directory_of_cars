#ifndef DIRECTORY_OF_CARS_ENGINE_H
#define DIRECTORY_OF_CARS_ENGINE_H

#include <iostream>
#include <memory>
using namespace std;

class Engine {
unique_ptr <double> capacity;
string fuel;
double power;

public:
    Engine();
    Engine([[maybe_unused]] double cap, string& new_fuel, double pow);
    ~Engine();
    Engine (Engine &&other) noexcept ;
    Engine(const Engine &other);
    Engine& operator=(const Engine& other);
    Engine& operator=(Engine&& other) noexcept;

    friend ostream &operator<<(ostream& os, const Engine& obj);
    friend istream &operator>>(istream& is, Engine& engine);

    void set_capacity(double new_capacity);
    void set_fuel(string& new_fuel);
    void set_power(double new_power);

    [[maybe_unused]]double get_capacity();
    [[maybe_unused]]string get_fuel();
    [[maybe_unused]] [[nodiscard]] double get_power() const;

    void get_engine() const;
    bool sort_capacity_l(double cap);
    [[nodiscard]] bool sort_power_l(double pow) const;
    bool sort_capacity_h(double cap);
    [[nodiscard]] bool sort_power_h(double pow) const;
    bool sort_fuel(string &new_fuel );
};


#endif //DIRECTORY_OF_CARS_ENGINE_H
