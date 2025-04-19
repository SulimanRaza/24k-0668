#include <iostream>
#include <string>

using namespace std;

// Base class
class Person
{
protected:
    string name;
    int id;
    double salary;

public:
    virtual void getdata()
    {
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter ID: ";
        {
            string tmp;
            getline(cin, tmp);
            id = stoi(tmp);
        }

        cout << "Enter salary: ";
        {
            string tmp;
            getline(cin, tmp);
            salary = stod(tmp);
        }
    }

    virtual void displaydata()
    {
        cout << "Name: " << name
             << "\nID: " << id
             << "\nSalary: $" << salary << "\n";
    }

    virtual double bonus() = 0;
    virtual ~Person() {}
};

class Admin : virtual public Person
{
public:
    void getdata() override
    {
        cout << "\n--- Admin Data Entry ---\n";
        Person::getdata();
    }

    void displaydata() override
    {
        cout << "\n--- Admin Details ---\n";
        Person::displaydata();
    }

    double bonus() override
    {
        return salary * 0.20;
    }
};

class Account : virtual public Person
{
public:
    void getdata() override
    {
        cout << "\n--- Account Data Entry ---\n";
        Person::getdata();
    }

    void displaydata() override
    {
        cout << "\n--- Account Details ---\n";
        Person::displaydata();
    }

    double bonus() override
    {
        return salary * 0.15;
    }
};

class Master : public Admin, public Account
{
public:
    void getdata() override
    {
        cout << "\n--- Master Data Entry ---\n";
        Person::getdata();
    }

    void displaydata() override
    {
        cout << "\n--- Master Details ---\n";
        Person::displaydata();
    }

    double bonus() override
    {
        return salary * 0.35; // combined 20% + 15%
    }
};

int main() {
    Admin adminEmp;
    Account accountEmp;
    Master masterEmp;

    Person* p;

    // Admin
    p = &adminEmp;
    p->getdata();
    p->displaydata();
    cout << "Admin Bonus: $" << p->bonus() << "\n\n";

    // Account
    p = &accountEmp;
    p->getdata();
    p->displaydata();
    cout << "Account Bonus: $" << p->bonus() << "\n\n";

    // Master
    p = &masterEmp;
    p->getdata();
    p->displaydata();
    cout << "Master Bonus: $" << p->bonus() << "\n";

    return 0;
}
