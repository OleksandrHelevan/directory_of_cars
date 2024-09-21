

#ifndef DIRECTORY_OF_CARS_USER_H
#define DIRECTORY_OF_CARS_USER_H

#include <limits>
#include "Person.h"
using namespace std;
class User :public Person{
public:
    User();
    User(std::string& new_name, std::string& new_surname, std::string& new_password);
    ~User() override = default;
    User(User&& other) noexcept;
    User& operator=(User&& other) noexcept;
    User& operator=(const User& other);
    User(const User& other);
    friend ostream& operator<<(ostream& os, const User& obj);
    friend istream& operator>>(istream& is, User& obj);

    string get_name() override;
    string get_surname() override;
    string get_password() override;

    void set_name(string& newname) override;
    void set_surname(string& newsurname) override;
    void set_password(string& newpassword) override;

    list <Car> cars_from_file() override;
    list <Truck> trucks_from_file() override;
    list <Bus> buses_from_file() override;
    void add_car() override{};
    void add_truck() override{};
    void add_bus() override{};
    void write_to_file() override;
    bool search() override;
    void car_menu();
    void truck_menu();
    void bus_menu();

    static void line(){
        cout<<"------------------------------------------------------------"
              "------------------------------------------------------------";
    }

    template <typename T>
    static T getInput(const string& prompt) {
        T value;
        while (true) {
            cout << prompt << endl;
            cin >> value;
            if (cin.fail()) {
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
                cerr << "Invalid input. Please enter a value of the correct type." << endl;
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any extra input
                return value;
            }
        }
    }

    static unique_ptr<string> getStringInput(const string& prompt) {
        unique_ptr<string> value = make_unique<string>();
        cout << prompt << endl;
        cin >> *value;
        return value;
    }
};

#endif //DIRECTORY_OF_CARS_USER_H
