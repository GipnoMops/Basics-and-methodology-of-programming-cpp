#include <iostream>

int main() {
    int a;
    std::cin >> a;
    if (a == 1) {
        std::cout << "mon" << std::endl;
    } else if (a == 2) {
        std::cout << "tue" << std::endl;
    } else if (a == 3) {
        std::cout << "wed" << std::endl;
    } else if (a == 4) {
        std::cout << "thu" << std::endl;
    } else if (a == 5) {
        std::cout << "fri" << std::endl;
    } else if (a == 6) {
        std::cout << "sat" << std::endl;
    } else if (a == 7) {
        std::cout << "sun" << std::endl;
    }
    return 0;
}
