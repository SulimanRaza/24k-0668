#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float w;
    cout << "Enter weight in KG: ";
    cin >> w;
    w *= 2.2;
    cout << "Weight in pounds is: " << fixed << setprecision(2) << w;
    return 0;
}