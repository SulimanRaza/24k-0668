#include <iostream>
using namespace std;

class Date
{
public:
    int month;
    int day;
    int year;

    void Display()
    {
        cout << month << "/" << day << "/" << year;
    }
};

int main(int argc, char *argv[])
{
    Date dates;
    dates.month = atoi(argv[1]);
    dates.day = atoi(argv[2]);
    dates.year = atoi(argv[3]);

    dates.Display();

    return 0;
}