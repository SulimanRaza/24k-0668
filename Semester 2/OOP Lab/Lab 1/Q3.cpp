#include <iostream>
using namespace std;

int main()
{
    int cID;
    string cName;
    float unit, cunit, charge = 0, Tcharge = 0, surcharge = 0;
    cout << "Enter customer ID: ";
    cin >> cID;
    cout << "Enter customer Name: ";
    cin >> cName;
    cout << "Enter units consumed: ";
    cin >> unit;

    if (unit < 200)
    {
        cunit = 16.20;
    }
    else if (unit >= 200 && unit < 300)
    {
        cunit = 20.10;
    }
    else if (unit >= 300 && unit < 500)
    {
        cunit = 27.10;
    }
    else if (unit >= 500)
    {
        cunit = 35.90;
    }
    charge = unit * cunit;
    if (charge > 18000)
    {
        surcharge = charge * 0.15;
        Tcharge = charge + surcharge;
    }
    cout << "Customer ID: " << cID << endl;
    cout << "Customer Name: " << cName << endl;
    cout << "Units Consumed : " << unit << endl;
    cout << "Amount Charges @Rs." << cunit << " per unit: " << charge << endl;
    cout << "Surcharge Amount: " << surcharge << endl;
    cout << "Net Amount Paid by the Customer: " << Tcharge << endl;
}