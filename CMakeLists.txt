cmake_minimum_required(VERSION 3.27)
project(directory_of_cars)

set(CMAKE_CXX_STANDARD 17)

add_executable(directory_of_cars main.cpp
        Client.cpp
        Client.h
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
        Trailer.cpp
        Trailer.h
        Trailer_Car.cpp
        Trailer_Car.h
        Trailer_Bus.cpp
        Trailer_Bus.h
        Trailer_Truck.cpp
        Trailer_Truck.h
        WrongTypeEx.h)
