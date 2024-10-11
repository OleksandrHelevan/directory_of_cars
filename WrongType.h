#ifndef DIRECTORY_OF_CARS_WRONGTYPE_H
#define DIRECTORY_OF_CARS_WRONGTYPE_H

#include <iostream>
class WrongType: public std::exception{
public:

WrongType() = default;
~WrongType() override = default;

[[nodiscard]] const char *what() const noexcept override{
    return "Wrong type of data!!!";
    };
};

#endif //DIRECTORY_OF_CARS_WRONGTYPE_H
