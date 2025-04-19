#include <iostream>
#include <string>

using namespace std;

class Wallet
{
private:
    double balance;
    double dailyDepositLimit;
    double dailyWithdrawalLimit;
    double todayDeposited;
    double todayWithdrawn;

public:
    Wallet(double depositLimit = 10000.0, double withdrawalLimit = 5000.0)
        : balance(0.0), dailyDepositLimit(depositLimit), dailyWithdrawalLimit(withdrawalLimit),
          todayDeposited(0.0), todayWithdrawn(0.0) {}

    bool deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Deposit amount must be positive.\n";
            return false;
        }
        if (todayDeposited + amount > dailyDepositLimit)
        {
            cout << "Deposit limit exceeded.\n";
            return false;
        }
        balance += amount;
        todayDeposited += amount;
        return true;
    }

    bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Withdrawal amount must be positive.\n";
            return false;
        }
        if (amount > balance)
        {
            cout << "Insufficient balance.\n";
            return false;
        }
        if (todayWithdrawn + amount > dailyWithdrawalLimit)
        {
            cout << "Withdrawal limit exceeded.\n";
            return false;
        }
        balance -= amount;
        todayWithdrawn += amount;
        return true;
    }

    double getBalance() const
    {
        return balance;
    }

    void resetDailyLimits()
    {
        todayDeposited = 0;
        todayWithdrawn = 0;
    }
};

class User
{
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string username) : userID(id), name(username) {}

    bool deposit(double amount)
    {
        return wallet.deposit(amount);
    }

    bool withdraw(double amount)
    {
        return wallet.withdraw(amount);
    }

    void checkBalance() const
    {
        cout << "User: " << name << " | Balance: $" << wallet.getBalance() << "\n";
    }

    void resetLimits()
    {
        wallet.resetDailyLimits();
    }
};

int main()
{
    User user1("U001", "Alice");
    User user2("U002", "Bob");

    cout << "--- Transactions for Alice ---\n";
    user1.deposit(3000);  // OK
    user1.deposit(8000);  // Exceeds limit
    user1.withdraw(1000); // OK
    user1.withdraw(6000); // Exceeds withdrawal limit
    user1.checkBalance();

    cout << "\n--- Transactions for Bob ---\n";
    user2.deposit(9000);  // OK
    user2.withdraw(4000); // OK
    user2.withdraw(2000); // Exceeds limit
    user2.checkBalance();

    cout << "\n--- Resetting daily limits ---\n";
    user1.resetLimits();
    user1.deposit(7000); // Now works after reset
    user1.checkBalance();

    return 0;
}
