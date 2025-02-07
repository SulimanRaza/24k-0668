#include <iostream>
using namespace std;

class Glass{
    public:
    int Liquidlevel=200;

    void Drink(int millimeters){
        Liquidlevel-=millimeters;
        cout<<"Water remaining: "<<Liquidlevel<<endl;
    }

    void Refill(){
        Liquidlevel=200;
    }
};

int main(){
    Glass glass;
    int choice;
    int m;
    while (1)
    {
        cout<<"Press 1 to drink or 0 to exit: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter millimeters to drink: ";
            cin>>m;
            if (m>glass.Liquidlevel)
            {
                glass.Refill();
                glass.Drink(m);
            }
            else
            {
                glass.Drink(m);
            }
            break;
        
        case 0:
            cout<<"You are no longer thirsty!!!";
            return 0;
        default:
            cout<<"Incorrect Input, try again!!";
            break;
        }
    }
    return 0;
}