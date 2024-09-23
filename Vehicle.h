#ifndef DIRECTORY_OF_CARS_VEHICLE_H
#define DIRECTORY_OF_CARS_VEHICLE_H

#include <iostream>
#include <memory>
#include "Engine.h"
using namespace std;

class Vehicle {
    Engine engine;
    int weight;
    double fuel_consumption;
    int mileage;
    string color;
    string brand;
    string model;
    int year;
    string location;
    unique_ptr<int> price;

public:
    Vehicle();
    Vehicle(Engine& new_engine, int weigh, double consumption, int new_mileage, string& col,
            string& bran, string& mod, int new_year, string& loc, int new_price);
    Vehicle(const Vehicle& other);
    Vehicle(int year, string &brand, string &model, string &color);
    Vehicle(Vehicle&& other) noexcept;
    Vehicle& operator=(const Vehicle& other);
    Vehicle& operator=(Vehicle&& other) noexcept;
    friend ostream &operator<<(ostream &os, const Vehicle &obj);
    friend istream &operator>>(istream &is, Vehicle &obj);
    virtual ~Vehicle();

    bool sort_capacity_l(double cap);
    bool sort_power_l(double pow);
    bool sort_capacity_h(double cap);
    bool sort_power_h(double pow);
    bool sort_fuel(string &fuel1);
    [[nodiscard]] bool sort_weight_l(int weigh) const;
    [[nodiscard]] bool sort_weight_h(int weigh) const;
    [[nodiscard]] bool sort_consumption_l(double cons) const;
    [[nodiscard]] bool sort_consumption_h(double cons) const;
    [[nodiscard]] bool sort_mileage_l(int mil) const;
    [[nodiscard]] bool sort_mileage_h(int mil) const;
    bool sort_color(string &col);
    bool sort_brand(string &bra);
    bool sort_model(string &mod);
    [[nodiscard]] bool sort_year_l(int yea) const;
    [[nodiscard]] bool sort_year_h(int yea) const;
    bool sort_location(string &loc);
    [[nodiscard]] bool sort_price_l(int pric) const;
    [[nodiscard]] bool sort_price_h(int pric) const;

    [[maybe_unused]] void set_engine(const Engine& newEngine);
    [[maybe_unused]] void set_weight(int newWeight);
    [[maybe_unused]] void set_fuel_consumption(double newFuelConsumption);
    [[maybe_unused]] void set_mileage(int newMileage);
    [[maybe_unused]] void set_color(const string& newColor);
    [[maybe_unused]] void set_brand(const string& newBrand);
    [[maybe_unused]] void set_model(const string& newModel);
    [[maybe_unused]] void set_year(int newYear);
    [[maybe_unused]] void set_location(const string& newLocation);
    [[maybe_unused]] void set_price(int newPrice);

    [[maybe_unused]][[nodiscard]] Engine get_engine() const;
    [[nodiscard]] int get_weight() const;
    [[nodiscard]] double get_fuel_consumption() const;
    [[nodiscard]] int get_mileage() const;
    [[maybe_unused]][[nodiscard]] string get_color() const;
    [[maybe_unused]][[nodiscard]] string get_brand() const;
    [[maybe_unused]][[nodiscard]] string get_model() const;
    [[nodiscard]] int get_year() const;
    [[maybe_unused]][[nodiscard]] string get_location() const;
    [[nodiscard]] int get_price() const;

    virtual void get_vehicle() const =0;
};

#endif //DIRECTORY_OF_CARS_VEHICLE_H
