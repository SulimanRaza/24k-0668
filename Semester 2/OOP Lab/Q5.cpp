#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string name;
    int aticketsold, cticketsold;
    float adultprice, childprice, tsold, grossamount, adp, adonated, net;
    cout << "Enter movie name: ";
    getline(cin, name);
    cout << "Adult ticket price: ";
    cin >> adultprice;
    cout << "Child ticket price: ";
    cin >> childprice;
    cout << "Adult ticket sold: ";
    cin >> aticketsold;
    cout << "Child ticket sold: ";
    cin >> cticketsold;
    cout << "Percentage of the gross amount to be donated to the charity: ";
    cin >> adp;

    grossamount = (adultprice * aticketsold) + (childprice * cticketsold);
    adonated = grossamount * (adp / 100);
    net = grossamount - adonated;
    tsold = aticketsold + cticketsold;

    cout << "Movie Name: ............................. " << name << endl;
    cout << "Number of Tickets Sold: ................. " << tsold << endl;
    cout << "Gross Amount: ........................... $" << fixed << setprecision(2) << grossamount << endl;
    cout << "Percentage of Gross Amount Donated: ..... " << fixed << setprecision(2) << adp << "%" << endl;
    cout << "Amount Donated: ......................... $" << fixed << setprecision(2) << adonated << endl;
    cout << "Net Sale: ............................... $" << fixed << setprecision(2) << net << endl;

    return 0;
}