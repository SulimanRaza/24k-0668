#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
private:
    vector<int> digits; // stores digits in reverse order (least significant first)
    bool negative;

    // Helper function to remove leading zeros
    void trim() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            negative = false; 
        }
    }

public:
    BigInteger() : negative(false) {
        digits.push_back(0); 
    }

    // Constructor from string
    BigInteger(const string& num) {
        negative = (num[0] == '-');
        int start = (negative || num[0] == '+') ? 1 : 0;
        for (int i = num.length() - 1; i >= start; --i) {
            digits.push_back(num[i] - '0');
        }
        trim();
    }

    // Constructor from integer
    BigInteger(int num) {
        negative = (num < 0);
        num = abs(num);
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        if (digits.empty()) digits.push_back(0);
        trim();
    }

    // Addition operator
    BigInteger operator+(const BigInteger& other) const {
        if (negative == other.negative) {
            BigInteger result;
            result.negative = negative;
            int carry = 0;
            int maxSize = max(digits.size(), other.digits.size());
            result.digits.clear();
            for (int i = 0; i < maxSize || carry; ++i) {
                int sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }
            return result;
        } else {
            BigInteger temp = other;
            temp.negative = !temp.negative;
            return *this - temp;
        }
    }

    // Subtraction operator
    BigInteger operator-(const BigInteger& other) const {
        if (negative != other.negative) {
            BigInteger temp = other;
            temp.negative = !temp.negative;
            return *this + temp;
        }

        bool resultNegative = false;
        const BigInteger* larger = this;
        const BigInteger* smaller = &other;

        if (*this < other) {
            resultNegative = !negative;
            swap(larger, smaller);
        }

        BigInteger result;
        result.negative = resultNegative;
        int borrow = 0;
        int maxSize = larger->digits.size();
        result.digits.clear();

        for (int i = 0; i < maxSize; ++i) {
            int diff = larger->digits[i] - borrow;
            if (i < smaller->digits.size()) {
                diff -= smaller->digits[i];
            }

            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }

        result.trim();
        return result;
    }

    // Multiplication operator
    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.digits = vector<int>(digits.size() + other.digits.size(), 0);
        result.negative = (negative != other.negative);

        for (size_t i = 0; i < digits.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry; ++j) {
                long long product = result.digits[i + j] +
                                    digits[i] * 1LL * (j < other.digits.size() ? other.digits[j] : 0) +
                                    carry;
                result.digits[i + j] = product % 10;
                carry = product / 10;
            }
        }

        result.trim();
        return result;
    }

    // Comparison operators
    bool operator==(const BigInteger& other) const {
        return digits == other.digits && negative == other.negative;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (negative != other.negative) {
            return negative;
        }

        if (digits.size() != other.digits.size()) {
            return negative ? digits.size() > other.digits.size()
                            : digits.size() < other.digits.size();
        }

        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return negative ? digits[i] > other.digits[i]
                                : digits[i] < other.digits[i];
            }
        }

        return false;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    // I/O operators
    friend ostream& operator<<(ostream& os, const BigInteger& bi) {
        if (bi.negative && !(bi.digits.size() == 1 && bi.digits[0] == 0)) {
            os << "-";
        }
        for (int i = bi.digits.size() - 1; i >= 0; --i) {
            os << bi.digits[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& bi) {
        string num;
        is >> num;
        bi = BigInteger(num);
        return is;
    }
};

int main() {
    BigInteger a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;

    cout << boolalpha;
    cout << "a == b: " << (a == b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a > b: " << (a > b) << endl;

    return 0;
}
