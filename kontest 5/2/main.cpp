#include <iostream>

class C {
private:
    static int counter;
    const int id;

public:
    C(): id(++counter) {
        std::cout << "constructor C() " << id << "\n";
    }

    C(const C& other): id(++counter) {
        std::cout << "constructor C(const C&) " << id << " " << other.id << "\n";
    }

    C(C&& other): id(++counter) {
        std::cout << "constructor C(const C&&) " << id << " " << other.id << "\n";
    }

    C& operator = (const C& other) {
        std::cout << "operator = (const C&) " << id << " " << other.id << "\n";
        return *this;
    }

    C& operator = (C&& other) {
        std::cout << "operator = (const C&&) " << id << " " << other.id << "\n";
        return *this;
    }

    ~C() {
        std::cout << "destructor C() " << id << "\n";
    }
};

int C::counter = 0;

int main() {
    {
        C c1;
        C c2(c1);
    }

    {
        C c1;
        auto c2 = c1;
    }
    return 0;
}
