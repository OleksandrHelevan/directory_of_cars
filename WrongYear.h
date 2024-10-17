#ifndef DIRECTORY_OF_CARS_WRONGYEAR_H
#define DIRECTORY_OF_CARS_WRONGYEAR_H

#include <exception>

class WrongYear : public std::exception {
public:

    WrongYear() = default;

    ~WrongYear() override = default;

    [[nodiscard]] const char *what() const noexcept override {
        return "Year is wrong!";
    };
};

#endif //DIRECTORY_OF_CARS_WRONGYEAR_H
