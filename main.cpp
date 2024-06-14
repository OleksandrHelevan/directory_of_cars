#include <iostream>
//#include "Client.h"
#include "Engine.h"
//#include "Trailer.h"
//#include "Trailer_Bus.h"
//#include "Trailer_Car.h"
//#include "Trailer_Truck.h"
//#include "Truck.h"
//#include "Vehicle.h"
//#include "Car.h"
//#include "Bus.h"
#include "memory"
//#include "WrongTypeEx.h"

void addEngine(){
    unique_ptr <Engine> newEngine {new Engine()};
    cin >> *newEngine;
    newEngine->write();
    cout << *newEngine;
}

using namespace std;
int main() {
    addEngine();
    return 0;
}
