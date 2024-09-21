
#ifndef DIRECTORY_OF_CARS_CLIENT_NOT_FOUND_H
#define DIRECTORY_OF_CARS_CLIENT_NOT_FOUND_H
#include <iostream>
class Client_not_found: public std::exception{
public:
    Client_not_found() = default;
    ~Client_not_found() override = default;

    [[nodiscard]] const char *what() const noexcept override{
        return "Client not found!!!";
    };
};
#endif //DIRECTORY_OF_CARS_CLIENT_NOT_FOUND_H
