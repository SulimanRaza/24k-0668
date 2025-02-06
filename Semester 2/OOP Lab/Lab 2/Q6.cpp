#include <iostream>
#include <vector>
using namespace std;
struct Subject
{
    string name;
};

struct Student
{
    int id;
    vector<Subject> subjects;
};
main()
{
    int sub, stu;
    cout << "Enter the number of Student : ";
    cin >> stu;
    Student *students = new Student[stu];
    for (int i = 0; i < stu; i++)
    {
        cout << "Enter Student " << i + 1 << " ID : ";
        cin >> students[i].id;
        cout << "Enter the number of Subjects for Student " << i + 1 << " : ";
        cin >> sub;
        students[i].subjects.resize(sub);
        for (int j = 0; j < sub; j++)
        {
            cout << "Enter Student " << i + 1 << " Subject " << j + 1 << " Name : ";
            cin>>students[i].subjects[j].name;
        }
    };
    for (int i = 0; i < stu; i++)
    {
        cout<<endl;
        cout << "Student ID : " << students[i].id;
        cout<<endl;
        cout << "Subjects : ";
        for (int j = 0; j < students[i].subjects.size(); j++)
        {
            cout << students[i].subjects[j].name << " | ";
        }
    }
    delete[] students;
}