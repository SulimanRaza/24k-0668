#include<iostream>
#include<string>
using namespace std;

class Circle{
    float radius,area,peri;
    public:
    Circle(float radius){
        area=(22.0/7.0)*radius*radius;
        peri=(22.0/7.0)*2*radius;
    }
    float get_area(){
        return area;
    }
    float get_peri(){
        return peri;
    }
};

int main(int argc,char *argv[]){
    float r = atof(argv[1]);

    Circle Circle(r);
    cout<<"Area: "<<Circle.get_area()<<endl;
    cout<<"Perimeter: "<<Circle.get_peri()<<endl;
    return 0;
}