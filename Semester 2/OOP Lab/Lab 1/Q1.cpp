#include <iostream>
using namespace std;

int main()
{
    float arr[] = {1.2, 4.5, 2.5, 6.2, 5.2, 6.5, 7.4, 8, 120.56, 346.23, 21.5, 123.4, 324.65, 11.12, 234.43, 346.23, 54.23, 12.3, 67.54, 12.12};
    float max = *(arr);
    float secondmax = 0;
    for (int i = 1; i < 19; i++)
    {
        if (max < *(arr+i))
        {
            max = *(arr+i);
        }
    }
    for (int i = 0; i < 20; i++)
    {
        if (secondmax < *(arr+i) && *(arr+i) != max)
        {
            secondmax = *(arr+i);
        }
    }
    cout << "The second highest number is " << secondmax;
}
