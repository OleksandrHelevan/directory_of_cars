#ifndef DIRECTORY_OF_CARS_WRONGTYPEEX_H
#define DIRECTORY_OF_CARS_WRONGTYPEEX_H

#include <iostream>
class WrongTypeEx: public std::exception{
public:

WrongTypeEx() = default;
~WrongTypeEx() override = default;

[[nodiscard]] const char *what() const noexcept override{
    return "Wrong type of data!!!";
    };
};

#endif //DIRECTORY_OF_CARS_WRONGTYPEEX_H
