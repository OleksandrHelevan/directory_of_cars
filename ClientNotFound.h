
#ifndef DIRECTORY_OF_CARS_CLIENTNOTFOUND_H
#define DIRECTORY_OF_CARS_CLIENTNOTFOUND_H
#include <iostream>
class ClientNotFound: public std::exception{
public:
    ClientNotFound() = default;
    ~ClientNotFound() override = default;

    [[nodiscard]] const char *what() const noexcept override{
        return "Client not found!!!";
    };
};
#endif //DIRECTORY_OF_CARS_CLIENTNOTFOUND_H
