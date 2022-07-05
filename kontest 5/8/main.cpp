#include <iostream>
#include <cmath>

class Complex {
    double re_, im_;

public:
    Complex(double r, double i = 0) {
        re_ = r;
        im_ = i;
    }

    Complex operator + (const Complex& other) const {
        return Complex(re_ + other.re_, im_ + other.im_);
    }

    Complex operator + (const double& other) const {
        return *this + Complex(other);
    }

    Complex operator - (const Complex& other) const {
        return Complex(re_ - other.re_, im_ - other.im_);
    }

    Complex operator - (const double& other) const {
        return *this - Complex(other);
    }

    Complex operator * (const Complex& other) const {
        return Complex(re_ * other.re_ - im_ * other.im_,
                       re_ * other.im_ + im_ * other.re_);
    }

    Complex operator * (const double& other) const {
        return *this * Complex(other);
    }

    Complex operator / (const Complex& other) const {
        double abs2 = other.re_ * other.re_ + other.im_ * other.im_;
        return Complex((re_ * other.re_ + im_ * other.im_) / abs2,
                       (other.re_ * im_ - re_ * other.im_) / abs2);
    }

    Complex operator / (const double& other) const {
        return Complex(re_ / other, im_ / other);
    }

    Complex operator - () const {
        return Complex(-re_, -im_);
    }

    Complex operator + () const {
        return Complex(re_, im_);
    }

    double Re() const {
        return re_;
    }

    double Im() const {
        return im_;
    }

    ~Complex() = default;;
};

Complex operator + (const double& a, const Complex& b) {
    return b + a;
}

Complex operator - (const double& a, const Complex& b) {
    return b - a;
}

Complex operator * (const double& a, const Complex& b) {
    return b * a;
}

Complex operator / (const double& a, const Complex& b) {
    return Complex(a) / b;
}

double Abs(const Complex& c) {
    return sqrt(c.Re() * c.Re() + c.Im() * c.Im());
}

bool operator == (const Complex& c1, const Complex& c2) {
    return (c1.Re() == c2.Re()) && (c1.Im() == c2.Im());
}

bool operator != (const Complex& c1, const Complex& c2) {
    return !(c1 == c2);
}


int main() {
    double c0 = 2;
    Complex c1(1,1);
    Complex c2(2, 2);
    Complex c4(3, 4);
    Complex c(3, 4);
    Complex c3(3);
    /*std::cout << (c1 + c2).Re() << " " << (c1 + c2).Im() << "\n";
    std::cout << (c1 + c3).Re() << " " << (c1 + c3).Im() << "\n";
    std::cout << (c1 != c2) << "\n";
    std::cout << (c1 == c2) << "\n";
    std::cout << (c1 * c2).Re() << " " << (c1 * c2).Im() << "\n";
    std::cout << (c2 * c).Re() << " " << (c2 * c).Im() << "\n";
    std::cout << (c1 * c0).Re() << " " << (c1 * c0).Im() << "\n";
    std::cout << (c0 * c1).Re() << " " << (c0 * c1).Im() << "\n";
    std::cout << (c2 / c1).Re() << " " << (c2 / c1).Im() << "\n";
    std::cout << (c1 / c2).Re() << " " << (c1 / c2).Im() << "\n";
    std::cout << (c2 / c).Re() << " " << (c2 / c).Im() << "\n";
    std::cout << -c2.Re() << " " << -c2.Im() << " " << c2.Re() << "\n";
    std::cout << Abs(c1) << " " << (Abs(c1) == 1.0) << "\n";
    std::cout << -c0 << " " << c0 << "\n";
    std::cout << sqrt(c.Re() * c.Re() + c.Im() * c.Im()) << "\n";*/
    std::cout << (c4 == c) << "\n";
    return 0;
}
