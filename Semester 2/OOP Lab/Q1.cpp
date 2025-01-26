#include <iostream>
using namespace std;

int main()
{
    float arr[] = {1.2, 4.5, 2.5, 6.2, 5.2, 6.5, 7.4, 8, 120.56, 11.5, 21.5, 123.4, 324.65, 54.67, 234.43, 346.23, 54.23, 12.3, 67.54, 12.12};
    for (int i = 0; i < 20 - 1; i++)
    {
        for (int j = 0; j < 20 - i - 1; j++)
        {
            if (*(arr + j) < *(arr + j + 1))
            {
                float temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
    cout << "The second highest number is " << *(arr + 1);
}