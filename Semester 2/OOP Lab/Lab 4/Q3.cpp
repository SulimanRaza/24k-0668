#include <iostream>
#include <string>
using namespace std;

class invoice
{
    string number;
    string desc;
    int quantity;
    double price;

public:
    invoice(string n, string d, int q, double p)
    {
        number = n;
        desc = d;
        if (q < 0)
        {
            quantity = 0.0;
        }
        else
        {
            quantity = q;
        }
        if (p < 0)
        {
            price = 0.0;
        }
        else
        {
            price = p;
        }
    }
    double get_invoice(){
        return price*quantity;
    }
};

int main(int argc,char *argv[]){
    invoice i(argv[1],argv[2],atoi(argv[3]),atof(argv[4]));
    cout<<"Price : "<<i.get_invoice();
    return 0;
}