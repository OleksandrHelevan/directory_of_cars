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

    void setEngine(const Engine& newEngine);
    void setWeight(int newWeight);
    void setFuelConsumption(double newFuelConsumption);
    void setMileage(int newMileage);
    void setColor(const string& newColor);
    void setBrand(const string& newBrand);
    void setModel(const string& newModel);
    void setYear(int newYear);
    void setLocation(const string& newLocation);
    void setPrice(int newPrice);

    [[nodiscard]] Engine getEngine() const;
    [[nodiscard]] int getWeight() const;
    [[nodiscard]] double getFuelConsumption() const;
    [[nodiscard]] int getMileage() const;
    [[nodiscard]] string getColor() const;
    [[nodiscard]] string getBrand() const;
    [[nodiscard]] string getModel() const;
    [[nodiscard]] int getYear() const;
    [[nodiscard]] string getLocation() const;
    [[nodiscard]] int getPrice() const;

    virtual void getVehicle() const =0;
};

#endif //DIRECTORY_OF_CARS_VEHICLE_H
