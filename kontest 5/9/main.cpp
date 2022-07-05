#include <iostream>

int gcd(int a, int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}

class Rational {
    int numerator_;
    int denominator_;

public:
    Rational(int numerator = 0, int denominator = 1) {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    Rational operator+ () const {
        return *this;
    }

    Rational operator+ (const Rational& other) const {
        return Rational(numerator_ * other.denominator_ + other.numerator_ * denominator_,
                        denominator_ * other.denominator_);
    }

    Rational operator+ (int other) const {
        return *this + Rational(other);
    }

    Rational operator- () const {
        return Rational(-numerator_, denominator_);
    }

    Rational operator- (const Rational& other) const {
        return Rational(numerator_ * other.denominator_ - other.numerator_ * denominator_,
                        denominator_ * other.denominator_);
    }

    Rational operator- (int other) const {
        return *this - Rational(other);
    }

    Rational operator* (const Rational& other) const {
        return Rational(numerator_ * other.numerator_,
                        denominator_ * other.denominator_);
    }

    Rational operator* (int other) const {
        return *this * Rational(other);
    }

    Rational operator/ (const Rational& other) const {
        return Rational(numerator_ * other.denominator_,
                        denominator_ * other.numerator_);
    }

    Rational operator/ (int other) const {
        return *this / Rational(other);
    }

    int Numerator() const {
        if (denominator_ > 0) {
            return (numerator_ / gcd(numerator_, denominator_));
        } else {
            return -(numerator_ / gcd(numerator_, denominator_));
        }
    }

    int Denominator() const {
        if (denominator_ > 0) {
            return (denominator_ / gcd(numerator_, denominator_));
        } else {
            return -(denominator_ / gcd(numerator_, denominator_));
        }
    }

    Rational& operator += (const Rational& other) {
        *this = *this + other;
        return *this;
    }

    Rational& operator -= (const Rational& other) {
        *this = *this - other;
        return *this;
    }

    Rational& operator *= (const Rational& other) {
        *this = *this * other;
        return *this;
    }

    Rational& operator /= (const Rational& other) {
        *this = *this / other;
        return *this;
    }

    Rational& operator++() {
        *this += 1;
        return *this;
    }

    Rational& operator--() {
        *this -= 1;
        return *this;
    }

    Rational operator++(int) {
        Rational temp(numerator_, denominator_);
        ++(*this);
        return temp;
    }

    Rational operator--(int) {
        Rational tepm(numerator_, denominator_);
        --(*this);
        return tepm;
    }

    bool operator == (const Rational& other) const {
        return (other.Numerator() == (*this).Numerator()) &&
        (other.Denominator() == (*this).Denominator());
    }

    bool operator != (const Rational& other) const {
        return !(*this == other);
    }
};

Rational operator+ (int a, const Rational& b) {
    return b + a;
}

Rational operator- (int a, const Rational& b) {
    return b - a;
}

Rational operator* (int a, const Rational& b) {
    return b * a;
}

Rational operator/ (int a, const Rational& b) {
    return b / a;
}


int main() {
    Rational a(-3, 2), b(6, -4);
    std::cout << a.Numerator() << " " << a.Denominator() << "\n";
    //std::cout << (3 + a).Numerator() << " " << (a * b).Denominator() << " " << "\n";
    std::cout << a.Numerator() << " " << a.Denominator() << "\n";
    std::cout << (a - b).Numerator() << " " << (a - b).Denominator() << "\n";
    return 0;
}
