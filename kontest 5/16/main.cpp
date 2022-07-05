#include <iostream>
#include <string>
#include <chrono>

class TimerGuard {
private:
    std::string message_;
    std::chrono::_V2::system_clock::time_point start_;
    std::ostream& out_;

public:
    TimerGuard(std::string_view message = "", std::ostream& out = std::cout): out_(out) {
        message_ = message;
        start_ = std::chrono::high_resolution_clock::now();
    }

    ~TimerGuard() {
        std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start_;
        out_ << message_ << diff1.count() << "\n";
    }
};

int FirstLongFunction(int n) {
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    std::cout << fact << "\n";
    return fact;
}

void SomeFunc(int n) {
    {
        TimerGuard timer("FirstLongFunction elapsed: ", std::cerr);
        FirstLongFunction(n);
    }
}

int main() {
    int n;
    std::cin >> n;
    SomeFunc(n);
    return 0;
}