#include <iostream>
using namespace std;

class Student
{
    const int rollnumber;
    string name;

public:
    Student(int r, string n) : rollnumber(r), name(n) {}

    void display() const
    {
        cout << endl;
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollnumber << endl;
    }
};

int main()
{
    int rollnumber;
    string name;

    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> rollnumber;

    Student s1(rollnumber, name);
    s1.display();

    return 0;
}