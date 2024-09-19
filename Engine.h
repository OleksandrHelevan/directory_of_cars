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

    [[maybe_unused]] void setCapacity(double newCapacity);
    [[maybe_unused]] void setFuel(string& newFuel);
    [[maybe_unused]] void setPower(double newPower);

    [[maybe_unused]] [[nodiscard]] double getCapacity() const;
    [[maybe_unused]] [[nodiscard]] string getFuel() const;
    [[maybe_unused]] [[nodiscard]] double getPower() const;

    void getEngine() const;
    bool sort_capacity_l(double cap);
    [[nodiscard]] bool sort_power_l(double pow) const;
    bool sort_capacity_h(double cap);
    [[nodiscard]] bool sort_power_h(double pow) const;
    bool sort_fuel(string &fuel1);
};


#endif //DIRECTORY_OF_CARS_ENGINE_H
