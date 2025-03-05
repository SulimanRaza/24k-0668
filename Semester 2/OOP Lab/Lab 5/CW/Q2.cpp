#include <iostream>
#include <vector>
using namespace std;

class Car {
public:
    string name;
    int id;

    Car(string n, int i) : name(n), id(i) {}

    void display() const {
        cout << "Car ID: " << id << ", Name: " << name << endl;
    }
};

class Garage {
    vector<Car*> cars; 

public:
    void parkCar(Car* car) {
        if (car) {
            cars.push_back(car);
            cout << car->name << " is parked in the garage." << endl;
        }
    }

    void listCars() const {
        if (cars.empty()) {
            cout << "Garage is empty." << endl;
            return;
        }

        cout << "Cars in the garage:" << endl;
        for (const auto& car : cars) {
            car->display();
        }
    }
};

int main() {
    Car c1("Vigo", 2021);
    Car c2("Civic", 2023);
    Car c3("BMW", 2020);
    Garage garage;
    garage.parkCar(&c1);
    garage.parkCar(&c2);  
    garage.parkCar(&c3);
    garage.listCars(); 
    return 0;
}