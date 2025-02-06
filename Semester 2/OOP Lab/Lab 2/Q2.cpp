#include <iostream>
using namespace std;

void *add(void *arr, int n)
{

    int *added = (int *)arr;

    for (int i = 0; i < n; i++)
    {
        added[i] += i + 1;
    }
    return arr;
}

int main(int argc, char *argv[])
{
    int n = argc - 1;
    int *arr = new int[n];

    for (int i = 1; i <= n; i++)
    {
        arr[i - 1] = atoi(argv[i]);
    }

    add(arr, n);

    cout << "Elements after addition are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
