#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int n = argc - 1;
    int *arr = new int[n];

    for (int i = 1; i <= n; i++)
    {
        arr[i - 1] = atoi(argv[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }

    cout << "The sum is: " << sum;

    delete[] arr;
    return 0;
}
