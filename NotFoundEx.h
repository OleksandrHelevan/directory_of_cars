
#ifndef DIRECTORY_OF_CARS_NOTFOUNDEX_H
#define DIRECTORY_OF_CARS_NOTFOUNDEX_H
#include <iostream>
class NotFoundEx: public std::exception{
public:
    NotFoundEx() = default;
    ~NotFoundEx() override = default;

    [[nodiscard]] const char *what() const noexcept override{
        return "not found!!!";
    };
};
#endif //DIRECTORY_OF_CARS_NOTFOUNDEX_H
