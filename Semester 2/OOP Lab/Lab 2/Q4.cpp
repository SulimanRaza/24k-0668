#include <iostream>
using namespace std;

struct Employee
{
    int employeeID;
    string name;
    float salary;
};

struct Organization
{
    string organisation_name;
    string organisation_number;
    Employee emp;
};

int main()
{
    Organization org;

    org.emp.employeeID = 127;
    org.emp.name = "Linus Sebastian";
    org.emp.salary = 400000;
    org.organisation_name = "NU-Fast";
    org.organisation_number = "NUFAST123ABC";

    cout << "The size of structure organization: " << sizeof(org) << endl;
    cout << "Organization name: " << org.organisation_name << endl;
    cout << "Organization number: " << org.organisation_number << endl;
    cout << "Employee ID: " << org.emp.employeeID << endl;
    cout << "Employee name: " << org.emp.name << endl;
    cout << "Employee salary: " << org.emp.salary << endl;

    return 0;
}