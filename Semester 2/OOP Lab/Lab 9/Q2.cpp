#include <iostream>
#include <string>

using namespace std;

class Car
{
protected:
    string model;
    double price;

public:
    Car(string m) : model(m), price(0.0) {}

    string getModel()
    {
        return model;
    }

    double getPrice()
    {
        return price;
    }

    void setModel(string m)
    {
        model = m;
    }

    virtual void setPrice(double p) = 0;

    virtual ~Car() {}
};

class Color : public Car
{
private:
    string color;

public:
    Color(string m, string c) : Car(m), color(c){}

    void setPrice(double p) override
    {
        price = p + 1000.0;
    }

    void display()
    {
        cout << "Model: " << model << ", Color: " << color << ", Price: $" << price << endl;
    }
};

class Company : public Car
{
private:
    string companyName;

public:
    Company(string m, string c) : Car(m),companyName(c){}

    void setPrice(double p) override
    {
        price = p + 2000.0;
    }

    void display()
    {
        cout << "Model: " << model << ", Company: " << companyName << ", Price: $" << price << endl;
    }
};

int main() {
    // Create a Color‑based car
    Color sportCar("Roadster X", "Red");
    sportCar.setPrice(50000.0);   // base 50k + 1k color surcharge
    sportCar.display();

    // Create a Company‑based car
    Company familyCar("Family Sedan", "AutoMoto");
    familyCar.setPrice(30000.0);  // base 30k + 2k company surcharge
    familyCar.display();

    // Polymorphic demonstration (optional)
    Car* fleet[2];
    fleet[0] = new Color("Coupe Z", "Blue");
    fleet[1] = new Company("Luxury L", "PremiumMotors");

    fleet[0]->setPrice(45000.0);
    fleet[1]->setPrice(80000.0);

    cout << "\n--- Fleet Overview ---\n";
    // Note: need downcast to call display(), or you could add a virtual display() in Car
    static_cast<Color*>(fleet[0])->display();
    static_cast<Company*>(fleet[1])->display();

    // Clean up
    delete fleet[0];
    delete fleet[1];

    return 0;
}