#include <iostream>
using namespace std;

// Abstract base class
class Shape
{
public:
    virtual double getArea() const = 0;

    virtual ~Shape() {}
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getArea() const override
    {
        return length * width;
    }
};

class Triangle : public Shape
{
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double getArea() const override
    {
        return 0.5 * base * height;
    }
};

int main()
{
    // Create instances of derived classes
    Rectangle rect(5.0, 3.0);
    Triangle tri(4.0, 6.0);

    // Calculate and display areas
    cout << "Area of Rectangle: " << rect.getArea() << endl;
    cout << "Area of Triangle: " << tri.getArea() << endl;

    // Demonstrate polymorphism
    Shape *shapes[] = {&rect, &tri};
    cout << "\nUsing polymorphism:\n";
    cout << "Rectangle area: " << shapes[0]->getArea() << endl;
    cout << "Triangle area: " << shapes[1]->getArea() << endl;

    return 0;
}