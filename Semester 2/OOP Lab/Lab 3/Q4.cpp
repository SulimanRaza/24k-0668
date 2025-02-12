#include <iostream>
#include <string>
using namespace std;

class Employee{
    string fname;
    string lname;
    double msalary;

    public:
   void Set_details(string f,string l,double s){
    fname=f;
    lname=l;
    if (s<0.0)
    {
        msalary=0.0;
    }
    else
    {
        msalary=s*12.0;
    } 
   }
   void get_details(){
        cout<<"Employee Yearly salary is: "<<msalary<<endl;
        msalary+=msalary*0.1;

        cout<<"Employee yearly salary after 10% raise: "<<msalary<<endl;
    }
};

int main(int argc, char *argv[]){
    Employee employees[2];

    employees[0].Set_details(argv[1],argv[2],stod(argv[3]));
    employees[1].Set_details(argv[4],argv[5],stod(argv[6]));

    cout<<"First Employee Salary"<<endl;
    employees[0].get_details();
    cout<<"Second Employee Salary"<<endl;
    employees[1].get_details();

    return 0;
}