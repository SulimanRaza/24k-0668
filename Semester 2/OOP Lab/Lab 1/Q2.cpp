#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr + i);
        sum += *(arr + i);
    }
    cout << "The sum of " << n << " numbers is: " << sum;
    return 0;
}