#include <iostream>
#include <algorithm>
using namespace std;

struct person
{
    int id;
    string name;
};

int main()
{
    int N;
    cout << "Enter the number of persons: ";
    cin >> N;

    person *persons = new person[N];

    for (int i = 0; i < N; i++)
    {
        cout << "Enter id and name for person " << i + 1 << ": ";
        cin >> persons[i].id >> persons[i].name;
    }

    person *byid = new person[N];
    person *byname = new person[N];

    for (int i = 0; i < N; i++)
    {
        byid[i] = persons[i];
        byname[i] = persons[i];
    }

    sort(byid, byid + N, [](const person &a, const person &b)
         { return a.id < b.id; });

    sort(byname, byname + N, [](const person &a, const person &b)
         {
        if (a.name[0]!=b.name[0])
        {
            return a.name[0]<b.name[0];
        }
        else if (a.name[0]==b.name[0])
        {
             return a.name[1]<b.name[1];
        } });

    cout << "Records sorted by id" << endl;
    ;
    for (int i = 0; i < N; i++)
    {
        cout << "id: " << byid[i].id << ", name: " << byid[i].name << "\n";
    }

    cout << "\nRecords sorted by the first character of name:\n";
    for (int i = 0; i < N; i++)
    {
        cout << "id: " << byname[i].id << ", name: " << byname[i].name << "\n";
    }

    delete[] persons;
    delete[] byid;
    delete[] byname;

    return 0;
}