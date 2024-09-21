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

    [[maybe_unused]] void set_capacity(double newCapacity);
    [[maybe_unused]] void set_fuel(string& newFuel);
    [[maybe_unused]] void set_power(double newPower);

    [[maybe_unused]] [[nodiscard]] double get_capacity() const;
    [[maybe_unused]] [[nodiscard]] string get_fuel() const;
    [[maybe_unused]] [[nodiscard]] double get_power() const;

    void get_engine() const;
    bool sort_capacity_l(double cap);
    [[nodiscard]] bool sort_power_l(double pow) const;
    bool sort_capacity_h(double cap);
    [[nodiscard]] bool sort_power_h(double pow) const;
    bool sort_fuel(string &fuel1);
};


#endif //DIRECTORY_OF_CARS_ENGINE_H
