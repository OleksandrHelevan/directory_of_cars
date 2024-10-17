#ifndef DIRECTORY_OF_CARS_WRONGTYPEVEHICLE_H
#define DIRECTORY_OF_CARS_WRONGTYPEVEHICLE_H

#include <exception>

class WrongTypeVehicle : public std::exception {
public:

    WrongTypeVehicle() = default;

    ~WrongTypeVehicle() override = default;

    [[nodiscard]] const char *what() const noexcept override {
        return "It may be other type of vehicle!";
    };
};

#endif //DIRECTORY_OF_CARS_WRONGTYPEVEHICLE_H
