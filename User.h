#ifndef DIRECTORY_OF_CARS_USER_H
#define DIRECTORY_OF_CARS_USER_H

#include <limits>
#include "Person.h"
#include "Car.h"
#include "Truck.h"
#include "Bus.h"

using namespace std;

class User : public Person {
private:
    unique_ptr<string> name;
    unique_ptr<string> surname;
    unique_ptr<string> password;

public:
    User();
    User(string& new_name, string& new_surname, string& new_password);
    ~User() override = default;
    User(User&& other) noexcept;
    User& operator=(User&& other) noexcept;
    User& operator=(const User& other);
    User(const User& other);
    friend ostream& operator<<(ostream& os, const User& obj);
    friend istream& operator>>(istream& is, User& obj);

    [[nodiscard]] string get_name() const;
    [[nodiscard]] string get_surname() const;
    [[nodiscard]] string get_password() const;

    [[maybe_unused]] void set_name(const string& new_name);
    [[maybe_unused]] void set_surname(const string& new_surname);
    [[maybe_unused]] void set_password(const string& new_password);

    void write_to_file() override;
    bool search() override;

    void add_car() override;
    void add_truck() override;
    void add_bus() override;

    void set_car() override;
    void set_truck() override;
    void set_bus() override;

    void delete_vehicle() override;

    static list<Car> cars_from_file();
    static list<Truck> trucks_from_file();
    static list<Bus> buses_from_file();

    void car_menu() override;
    void truck_menu() override;
    void bus_menu() override;

    friend ostream& operator<<(ostream& os, const User& obj);
    friend istream& operator>>(istream& is, User& obj);

    template <typename T>
    static T get_input(const string& prompt) {
        T value;
        while (true) {
            cout << prompt << endl;
            cin >> value;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Invalid input. Please enter a value of the correct type." << endl;
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }

    static unique_ptr<string> get_string_input(const string& prompt) {
        unique_ptr<string> value = make_unique<string>();
        cout << prompt << endl;
        cin >> *value;
        return value;
    }

    static void line() {
        cout << "------------------------------------------------------------"
                "------------------------------------------------------------";
    }
};

#endif //DIRECTORY_OF_CARS_USER_H
