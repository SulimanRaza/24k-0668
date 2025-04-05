#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int v = 0) : value(v) {}

    Number& operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        value /= 4;
        return *this;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(16);
    
    cout << "Original value: ";
    num.display();

    // Prefix decrement
    --num;
    cout << "After prefix -- (multiply by 4): ";
    num.display();

    // Postfix decrement
    num--;
    cout << "After postfix -- (divide by 4): ";
    num.display();

    return 0;
}