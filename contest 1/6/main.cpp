#include <iostream>

using namespace std;

int main() {
    for (size_t i = 33; i <= 126; ++i) {
        cout << static_cast<char>(i) << " " << i << "\n";
    }
    return 0;
}
