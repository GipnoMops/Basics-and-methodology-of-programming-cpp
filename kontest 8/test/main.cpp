#include <iostream>
#include <vector>
#include <memory>

bool foo() {
    int * ptr = new int(42);
    std::unique_ptr<int> up1(ptr);
    std::unique_ptr<int> up2(ptr);
    return *up1 == *up2;
}

int main() {
    std::cout << (foo() ? "equal" : "not equal") << "\n";
    return 0;
}
