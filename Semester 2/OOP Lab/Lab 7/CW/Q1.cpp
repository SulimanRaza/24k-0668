#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

    int gcd(int a, int b)
    {
        if (b == 0)
        {
            if (a < 0)
                return -a;
            else
                return a;
        }
        return gcd(b, a % b);
    }

    void reduce()
    {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
        if (denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den)
    {
        if (denominator == 0)
        {
            cout << "Denominator cannot be zero. Using 1 instead.\n";
            denominator = 1;
            return;
        }

        if (denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
        reduce();
    }

    Fraction operator+(const Fraction &other)
    {
        return Fraction(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction &other)
    {
        return Fraction(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }
    Fraction operator*(const Fraction &other)
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction &other)
    {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Fraction &other) const
    {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction &other) const
    {
        return !(*this == other);
    }

    bool operator<(const Fraction &other)const
    {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction &other) const { return other < *this; }

    bool operator<=(const Fraction &other) const { return !(*this > other); }

    bool operator>=(const Fraction &other) const { return !(*this < other); }

    friend ostream &operator<<(ostream &os, const Fraction &f);
    friend istream &operator>>(istream &is, Fraction &f);
};

ostream &operator<<(ostream &out, const Fraction &f)
{
    if (f.denominator == 1)
        out << f.numerator << endl;
    else
        out << f.numerator << "/" << f.denominator << endl;
    return out;
}

istream &operator>>(istream &in, Fraction &f)
{
    string input;
        in >> input;
        size_t slashIndex = input.find('/');
        int n = stoi(input.substr(0, slashIndex));
        int d = stoi(input.substr(slashIndex + 1));
        f = Fraction(n, d);
        return in;
}

int main() {
    
        Fraction f1(4, 8);
        Fraction f2(3, 6);
        Fraction sum = f1 + f2;
        Fraction diff = f1 - f2;
        Fraction prod = f1 * f2;
        Fraction quot = f1 / f2;

        cout << "f1 = " << f1 << "\n";
        cout << "f2 = " << f2 << "\n";
        cout << "f1 + f2 = " << sum << "\n";
        cout << "f1 - f2 = " << diff << "\n";
        cout << "f1 * f2 = " << prod << "\n";
        cout << "f1 / f2 = " << quot << "\n";

        // Comparison example
        cout << "\nComparison Operators:\n";
        cout << "f1 == f2? " << (f1 == f2 ? "True" : "False") << endl;
        cout << "f1 != f2? " << (f1 != f2 ? "True" : "False") << endl;
        cout << "f1 < f2? " << (f1 < f2 ? "True" : "False") << endl;
        cout << "f1 > f2? " << (f1 > f2 ? "True" : "False") << endl;
        cout << "f1 <= f2? " << (f1 <= f2 ? "True" : "False") << endl;
        cout << "f1 >= f2? " << (f1 >= f2 ? "True" : "False") << endl;

        // I/O example
        Fraction f3;
        cout << "Enter a fraction (format: numerator/denominator or just an integer): ";
        cin >> f3;
        cout << "You entered: " << f3 << "\n";
    
    return 0;
}