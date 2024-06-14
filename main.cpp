#include <iostream>
#include "User.h"
#include "Engine.h"
//#include "Truck.h"
//#include "Vehicle.h"
//#include "Car.h"
//#include "Bus.h"
#include "memory"
//#include "WrongTypeEx.h"


using namespace std;


void addEngine(){
    unique_ptr <Engine> newEngine {new Engine()};
    cin >> *newEngine;
    newEngine->write_to_file();
    cout << *newEngine;
}

void registration(){
    unique_ptr <User> newUser {new User()};
    cin >> *newUser;
    newUser->write_to_file();
    cout<< *newUser;
}

int main() {
    registration();

    addEngine();
    return 0;
}
