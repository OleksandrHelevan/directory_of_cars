#ifndef DIRECTORY_OF_CARS_WRONGCHOICE_H
#define DIRECTORY_OF_CARS_WRONGCHOICE_H

#include <iostream>

class WrongChoice : public std::exception {
public:

    WrongChoice() = default;

    ~WrongChoice() override = default;

    [[nodiscard]] const char *what() const noexcept override {
        return "Wrong choice!!!";
    };
};

#endif //DIRECTORY_OF_CARS_WRONGCHOICE_H
