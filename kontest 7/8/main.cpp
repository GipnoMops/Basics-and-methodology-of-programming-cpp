#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <functional>

template <class T>
class IntegrationMethod {
public:
    virtual double Integrate(std::function<T>, double, double, int) {
        return 0.0;
    }

    virtual ~IntegrationMethod() = default;
};

template <class T>
class RectangleRule: public IntegrationMethod<T> {
    double Integrate(std::function<T> func, double a, double b, int n) override {
        double value = 0;
        double x1, x2;
        for (int i = 0; i < n; ++i) {
            x1 = a + ((b - a) * i) / n;
            x2 = a + ((b - a) * (i + 1)) / n;
            value += func((x1 + x2) / 2) * (x2 - x1);
        }
        return value;
    }
};

template <class T>
class TrapezoidalRule: public IntegrationMethod<T> {
    double Integrate(std::function<T> func, double a, double b, int n) override {
        double value = 0;
        double x1, x2;
        for (int i = 0; i < n; ++i) {
            x1 = a + ((b - a) * i) / n;
            x2 = a + ((b - a) * (i + 1)) / n;
            value += ((func(x1) + func(x2)) / 2) * (x2 - x1);
        }
        return value;
    }
};

int main() {
    using F = decltype(cos);

    std::string input;
    std::cin >> input;
    std::unique_ptr<IntegrationMethod<F>> method;
    if (input == "rectangle")
        method.reset(new RectangleRule<F>);
    else
        method.reset(new TrapezoidalRule<F>);

    double x, y;
    std::cin >> x >> y;

    int n;
    std::cin >> n;

    std::cout << method->Integrate(cos, x, y, n) << "\n";
    std::cout << method->Integrate(sin, x, y, n) << "\n";
}