#ifndef DIRECTORY_OF_CARS_WRONGCHOICEEX_H
#define DIRECTORY_OF_CARS_WRONGCHOICEEX_H

#include <iostream>
class WrongChoiceEx: public std::exception{
public:

    WrongChoiceEx() = default;
    ~WrongChoiceEx() override = default;

    [[nodiscard]] const char *what() const noexcept override{
        return "Wrong choice!!!";
    };
};
#endif //DIRECTORY_OF_CARS_WRONGCHOICEEX_H
