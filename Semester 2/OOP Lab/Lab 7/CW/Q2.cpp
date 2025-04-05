#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial {
private:
    vector<int> coefficients;

    void trim() {
        if (coefficients.empty()) return;
        size_t lastNonZero = 0;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            if (coefficients[i] != 0) lastNonZero = i;
        }
        if (coefficients[lastNonZero] == 0) {
            coefficients = {0};
            return;
        }
        coefficients.resize(lastNonZero + 1);
    }

public:
    Polynomial() = default;

    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {
        trim();
    }

    friend Polynomial operator+(const Polynomial& a, const Polynomial& b);
    friend Polynomial operator-(const Polynomial& a, const Polynomial& b);
    friend Polynomial operator*(const Polynomial& a, const Polynomial& b);
    friend ostream& operator<<(ostream& os, const Polynomial& p);

    friend class PolynomialUtils;
};

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        int power = 1;
        for (size_t i = 0; i < p.coefficients.size(); ++i) {
            result += p.coefficients[i] * power;
            power *= x;
        }
        return result;
    }

    static Polynomial derivative(const Polynomial& p) {
        vector<int> derivCoeff;
        for (size_t i = 1; i < p.coefficients.size(); ++i) {
            derivCoeff.push_back(p.coefficients[i] * i);
        }
        return Polynomial(derivCoeff);
    }
};

Polynomial operator+(const Polynomial& a, const Polynomial& b) {
    vector<int> result(max(a.coefficients.size(), b.coefficients.size()), 0);
    for (size_t i = 0; i < a.coefficients.size(); ++i) result[i] += a.coefficients[i];
    for (size_t i = 0; i < b.coefficients.size(); ++i) result[i] += b.coefficients[i];
    return Polynomial(result);
}

Polynomial operator-(const Polynomial& a, const Polynomial& b) {
    vector<int> result(max(a.coefficients.size(), b.coefficients.size()), 0);
    for (size_t i = 0; i < a.coefficients.size(); ++i) result[i] += a.coefficients[i];
    for (size_t i = 0; i < b.coefficients.size(); ++i) result[i] -= b.coefficients[i];
    return Polynomial(result);
}

Polynomial operator*(const Polynomial& a, const Polynomial& b) {
    vector<int> result(a.coefficients.size() + b.coefficients.size() - 1, 0);
    for (size_t i = 0; i < a.coefficients.size(); ++i) {
        for (size_t j = 0; j < b.coefficients.size(); ++j) {
            result[i + j] += a.coefficients[i] * b.coefficients[j];
        }
    }
    return Polynomial(result);
}

ostream& operator<<(ostream& os, const Polynomial& p) {
    if (p.coefficients.empty()) {
        os << "0";
        return os;
    }

    bool firstTerm = true;
    for (int i = p.coefficients.size() - 1; i >= 0; --i) {
        int coeff = p.coefficients[i];
        if (coeff == 0) continue;

        if (firstTerm) {
            firstTerm = false;
            if (coeff < 0) {
                os << "-";
                coeff = -coeff;
            }
        } else {
            if (coeff > 0) {
                os << " + ";
            } else {
                os << " - ";
            }
            coeff = abs(coeff);
        }

        if (i == 0) {
            os << coeff;
        } else {
            if (coeff != 1) {
                os << coeff;
            }
            os << "x";
            if (i > 1) {
                os << "^" << i;
            }
        }
    }

    if (firstTerm) os << "0";
    return os;
}

int main() {
    // Create polynomials using the constructor
    Polynomial p1({2, 0, -1, 3});  // Represents 3x^3 - x^2 + 2
    Polynomial p2({-1, 2, 4});     // Represents 4x^2 + 2x - 1

    // Display the polynomials
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    // Perform polynomial addition
    Polynomial sum = p1 + p2;
    cout << "p1 + p2: " << sum << endl;

    // Perform polynomial subtraction
    Polynomial diff = p1 - p2;
    cout << "p1 - p2: " << diff << endl;

    // Perform polynomial multiplication
    Polynomial prod = p1 * p2;
    cout << "p1 * p2: " << prod << endl;

    // Evaluate a polynomial at a given point (e.g., x = 2)
    int evalResult = PolynomialUtils::evaluate(p1, 2);
    cout << "p1 evaluated at x = 2: " << evalResult << endl;

    // Get the derivative of the polynomial
    Polynomial derivative = PolynomialUtils::derivative(p1);
    cout << "Derivative of p1: " << derivative << endl;

    return 0;
}