cmake_minimum_required(VERSION 3.27)
project(directory_of_cars)

set(CMAKE_CXX_STANDARD 17)

add_executable(directory_of_cars main.cpp
        Person.cpp
        Person.h
        Engine.cpp
        Engine.h
        Vehicle.cpp
        Vehicle.h
        Car.cpp
        Car.h
        Bus.cpp
        Bus.h
        Truck.cpp
        Truck.h
        Wrong_type.h
        User.cpp
        User.h
        Admin.cpp
        Admin.h
        Wrong_choice.h
        Client_not_found.h
)
