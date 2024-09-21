#ifndef DIRECTORY_OF_CARS_WRONG_TYPE_H
#define DIRECTORY_OF_CARS_WRONG_TYPE_H

#include <iostream>
class Wrong_type: public std::exception{
public:

Wrong_type() = default;
~Wrong_type() override = default;

[[nodiscard]] const char *what() const noexcept override{
    return "Wrong type of data!!!";
    };
};

#endif //DIRECTORY_OF_CARS_WRONG_TYPE_H
