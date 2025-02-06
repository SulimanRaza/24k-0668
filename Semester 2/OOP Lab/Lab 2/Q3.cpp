#include <iostream>
using namespace std;

void resizing(int *&arr, int &cap)
{

    int *resizedarr = new int[cap * 2];
    for (int i = 0; i < cap; i++)
    {
        resizedarr[i] = arr[i];
    }
    delete[] arr;
    arr = resizedarr;
    cap *= 2;
    cout << "Array resized to: " << cap << endl;
}

int main()
{
    int cap = 5;
    int n = 0;
    int *arr = new int[cap];

    while (1)
    {
        int choice;
        cout << "Enter elements for array or press 0 to exit: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Elements are: ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << "Array size is: " << n;
            delete[] arr;
            return 0;

        default:
            if (n == cap)
            {
                resizing(arr, cap);
            }

            arr[n] = choice;
            n++;
            break;
        }
    }
}