#include <iostream>

int main() {
    int a, b, c, d;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    if (a == c || b == d || (a - c) == (b - d)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
