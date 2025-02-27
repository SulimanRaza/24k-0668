#include <iostream>
using namespace std;

class Car
{
    int horsePower;
    int seatingcapacity;
    int numberofspeaker;

public:
    Car(int hp, int sc, int ns) : horsePower(hp), seatingcapacity(sc), numberofspeaker(ns) {}
    Car update(int hp, int sc, int ns) const
    {
        return Car(hp, sc, ns);
    }
    void Display()
    {
        cout << "Horse Power: " << horsePower << endl;
        cout << "Seating Capacity: " << seatingcapacity << endl;
        cout << "No of Speaker: " << numberofspeaker << endl;
        cout<<endl;
    }
};
int main()
{
    Car c1(1000, 7, 5);
    c1.Display();
    Car c2=c1.update(650, 5, 3);
    c2.Display();
}