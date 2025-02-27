#include <iostream>
#include<windows.h>
using namespace std;

class Blend
{
public:
    void blendjuice()
    {
        int j;
        cout << "Choose fruit to blend \n1.Pineapple\n2.Mango\n3.Apple\n4.Blueberry\n5.Watermelon" << endl;
        cin >> j;
        cout << "Blending in progress!!!" << endl;
        for (int i = 0; i < 5; i++)
        {
            Sleep(1000);
            cout << "Blending juice for " << i + 1 << " second(s)" << endl;
        }
        cout << "Blending complete!!!" << endl;
    }
};

class Grind
{
public:
    void grindjuice()
    {
        cout << "Grinding in progress" << endl;
        Sleep(5000);
        cout << "Grinding complete!!!" << endl;
    }
};

class JuiceMaker
{
    Blend b;
    Grind g;

public:
    void makeJuice()
    {
        b.blendjuice();
        g.grindjuice();
    }
};
int main()
{
    JuiceMaker j;
    j.makeJuice();
    return 0;
}