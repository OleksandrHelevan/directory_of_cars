cmake_minimum_required(VERSION 3.27)
project(directory_of_cars)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(directory_of_cars main.cpp
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
        WrongType.h
        User.cpp
        User.h
        Admin.cpp
        Admin.h
        WrongChoice.h
        ClientNotFound.h
        FileReader.h
        WrongTypeVehicle.h
        WrongYear.h
)
