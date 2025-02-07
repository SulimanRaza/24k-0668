#include <iostream>
using namespace std;

class user
{
public:
    string name;
    int age;
};

int main(int argc, char *argv[])
{
    user users;

    users.name = argv[1];
    users.age = atoi(argv[2]);

    cout << "My name is " << users.name << " and Im " << users.age << " years old.";

    return 0;
}
