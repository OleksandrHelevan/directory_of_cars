#ifndef DIRECTORY_OF_CARS_WRONG_CHOICE_H
#define DIRECTORY_OF_CARS_WRONG_CHOICE_H

#include <iostream>
class Wrong_choice: public std::exception{
public:

    Wrong_choice() = default;
    ~Wrong_choice() override = default;

    [[nodiscard]] const char *what() const noexcept override{
        return "Wrong choice!!!";
    };
};
#endif //DIRECTORY_OF_CARS_WRONG_CHOICE_H
