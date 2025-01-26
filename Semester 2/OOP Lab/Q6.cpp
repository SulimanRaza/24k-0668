#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string name;
    float score[5], sum = 0, avg = 0;
    cout << "Enter name od student: ";
    cin >> name;
    cout << "Enter 5 Test scores: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> score[i];
        sum += score[i];
    }
    avg = sum / 5;
    cout << "Student name: " << name << endl;
    cout << "Test Scores:";
    for (int i = 0; i < 5; i++)
    {
        cout << " " << score[i];
    }
    cout << endl;
    cout << "Average Test score: " << fixed << setprecision(2) << avg << endl;
}