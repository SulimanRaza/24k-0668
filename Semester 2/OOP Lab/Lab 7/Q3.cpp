#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string empID;
public:
    virtual void getData() {
        cout << "Enter Employee ID: ";
        cin >> empID;
    }
    
    virtual void displayData() {
        cout << "Employee ID: " << empID << endl;
    }
};

class Admin : public Person {
private:
    string name;
    double monthlyIncome;
public:
    void getData() override {
        Person::getData();
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter monthly income: ";
        cin >> monthlyIncome;
    }
    
    void displayData() override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl << endl;
    }
    
    double bonus() {
        return monthlyIncome * 12 * 0.05; 
    }
};

class Accounts : public Person {
private:
    string name;
    double monthlyIncome;
public:
    void getData() override {
        Person::getData();
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter monthly income: ";
        cin >> monthlyIncome;
    }
    
    void displayData() override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl << endl;
    }
    
    double bonus() {
        return monthlyIncome * 12 * 0.05; 
    }
};

int main() {
    Admin adminEmp;
    Accounts accountsEmp;

    cout << "Enter Admin Employee Details:" << endl;
    adminEmp.getData();
    
    cout << "\nEnter Accounts Employee Details:" << endl;
    accountsEmp.getData();
    
    cout << "\n--- Employee Information ---" << endl;
    cout << "Admin Department:" << endl;
    adminEmp.displayData();
    
    cout << "Accounts Department:" << endl;
    accountsEmp.displayData();

    return 0;
}