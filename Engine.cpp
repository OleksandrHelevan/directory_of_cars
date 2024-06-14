#include "Engine.h"
#include "fstream"
#include "WrongTypeEx.h"
using namespace std;

Engine::Engine() : capacity(0.0), fuel(" "), power(0.0) {}

Engine::Engine(double cap, string& new_fuel, double pow) :capacity{cap},
        fuel{new_fuel},power{pow}{}

ostream &operator<<(ostream& os, const Engine& obj){
    os<<obj.capacity<<"\t"<<obj.fuel<<"\t"<<obj.power<<endl;
    return os;
}

istream& operator>>(istream& is, Engine& obj){
        if (!(is >> obj.capacity)||!(is >> obj.fuel)||!(is >> obj.power))
            throw WrongTypeEx();

    return is;
}

void Engine::write_to_file() {
    ofstream fout (R"(C:\Users\Admin\Desktop\directory_of_cars\database\Engines.txt)",
                   ios_base::app);
    fout<<capacity<<"\t"<<fuel<<"\t"<<power<<endl;
    fout.close();
}
