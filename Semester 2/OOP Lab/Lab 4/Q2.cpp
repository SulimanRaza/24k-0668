#include <iostream>
using namespace std;

class Account
{
    float balance;

public:
    Account() : balance(0.0) {}
    void credit(float amount)
    {
        balance += amount;
    }
    void debit(float amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Invalid balance.." << endl;
        }
    }
    float get_balance()
    {
        return balance;
    }
};

int main()
{
    float a;
    int choice;
    Account accounts;
    while (1)
    {
        cout << "1. Deposit money" << endl
             << "2. withdraw money: " << endl
             << "3. Show balance" << endl
             << "4. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter ammount to deposit: " << endl;
            cin >> a;
            accounts.credit(a);
            break;

        case 2:
            cout << "Enter ammount to withdraw: " << endl;
            cin >> a;
            accounts.debit(a);
            break;

        case 3:
            cout << "Current balance is: " << accounts.get_balance() << "$" << endl;
            break;

        case 4:
            cout << "Exiting program....";
            return 0;

        default:
            cout << "Invalid input, try again";
            break;
        }
    }
    return 0;
}