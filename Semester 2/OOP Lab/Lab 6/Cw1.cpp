#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
public:
    string accountNumber;
    double balance;
    bool isFrozen = false;

    BankAccount(string accNum, double balance) : accountNumber(accNum), balance(balance) {}

    void freeze()
    {
        isFrozen = true;
    }

    void deposit(double value)
    {
        if (isFrozen)
        {
            cout << "Account is frozen. Deposit denied!" << endl;
            return;
        }
        balance += value;
    }

    void withdraw(double value)
    {
        if (isFrozen)
        {
            cout << "Account is frozen. Withdrawal denied!" << endl;
            return;
        }
        if (balance >= value)
        {
            balance -= value;
        }
        else
        {
            cout << "Insufficient balance. Withdrawal denied!" << endl;
        }
    }

    double getBalance() const
    {
        return balance;
    }
};

class SavingsAccount : public BankAccount
{
public:
    double monthlyInterest;

    SavingsAccount(string accNum, double balance, double monthlyInterest)
        : BankAccount(accNum, balance), monthlyInterest(monthlyInterest) {}

    void applyMonthlyInterest()
    {
        double interest = balance * monthlyInterest;
        balance += interest;
        cout << "Monthly interest applied. New balance: " << balance << endl;
    }
};

class CheckingAccount : public BankAccount
{
public:
    double overdraftLimit;

    CheckingAccount(string accNum, double balance, double overdraftLimit)
        : BankAccount(accNum, balance), overdraftLimit(overdraftLimit) {}

    void withdraw(double value)
    {
        if (balance - value < -overdraftLimit)
        {
            cout << "Alert: Overdraft limit exceeded. Withdrawal denied!" << endl;
        }
        else
        {
            balance -= value;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
    }

    void setOverdraftLimit(double limit)
    {
        overdraftLimit = limit;
    }

    double getOverdraftLimit() const
    {
        return overdraftLimit;
    }
};

class BusinessAccount : public BankAccount
{
public:
    double corporateTax;

    BusinessAccount(string accNum, double balance, double corporateTax)
        : BankAccount(accNum, balance), corporateTax(corporateTax) {}

    void deposit(double value)
    {
        double tax = value * corporateTax;
        if (value - tax <= 0)
        {
            cout << "Deposit amount is too low after tax deduction. Deposit denied!" << endl;
        }
        else
        {
            balance += (value - tax);
            cout << "Deposit after tax deduction. New balance: " << balance << endl;
        }
    }
};

class Customer
{
public:
    void deposit(BankAccount &account, double value)
    {
        account.deposit(value);
        cout << "Customer deposited: " << value << ". New balance: " << account.getBalance() << endl;
    }

    void withdraw(BankAccount &account, double value)
    {
        account.withdraw(value);
        cout << "Customer withdrew: " << value << ". New balance: " << account.getBalance() << endl;
    }
};

class Employee
{
public:
    void freezeAccount(BankAccount &account)
    {
        account.freeze();
        cout << "Account " << account.accountNumber << " has been frozen." << endl;
    }
};

class Teller : public Employee
{
public:
    void deposit(BankAccount &account, double value)
    {
        account.deposit(value);
        cout << "Teller deposited: " << value << ". New balance: " << account.getBalance() << endl;
    }

    void withdraw(BankAccount &account, double value)
    {
        account.withdraw(value);
        cout << "Teller withdrew: " << value << ". New balance: " << account.getBalance() << endl;
    }
};

class Manager : public Employee
{
public:
    void deposit(BankAccount &account, double value)
    {
        account.deposit(value);
        cout << "Manager deposited: " << value << ". New balance: " << account.getBalance() << endl;
    }

    void withdraw(BankAccount &account, double value)
    {
        account.withdraw(value);
        cout << "Manager withdrew: " << value << ". New balance: " << account.getBalance() << endl;
    }

    void adjustOverdraftLimit(CheckingAccount &account, double newLimit)
    {
        account.setOverdraftLimit(newLimit);
        cout << "Manager adjusted overdraft limit to: " << newLimit << endl;
    }
};

int main()
{
    SavingsAccount savings("SA123", 5000.0, 0.02);
    CheckingAccount checking("CA456", 2000.0, 500.0);
    BusinessAccount business("BA789", 10000.0, 0.05);

    Customer customer;
    cout << "\n--- Customer Transactions ---\n";
    customer.deposit(savings, 1000.0);
    customer.withdraw(checking, 2500.0); 

    savings.applyMonthlyInterest();

    Teller teller;
    cout << "\n--- Teller Transactions ---\n";
    teller.deposit(business, 5000.0);
    teller.withdraw(savings, 2000.0);

    Manager manager;
    cout << "\n--- Manager Actions ---\n";
    manager.adjustOverdraftLimit(checking, 1000.0);
    manager.withdraw(checking, 2500.0); 

    cout << "\n--- Freezing Account ---\n";
    manager.freezeAccount(savings);
    customer.withdraw(savings, 500.0); 

    return 0;
}