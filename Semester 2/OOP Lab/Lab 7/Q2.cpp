#include <iostream>
using namespace std;

class Shape
{
private:
    double area;

public:
    Shape(double a) : area(a) {}

    double GetArea() 
    {
        return area;
    }

    double operator+(const Shape &other)
    {
        return this->area + other.area;
    }
};

int main()
{
    Shape s1(25.0); 
    Shape s2(30.5); 

    Shape  s3= s1 + s2;

    // Output the total area
    cout << "The total area of the two shapes is: " << s3.GetArea() << endl;

    return 0;
}
