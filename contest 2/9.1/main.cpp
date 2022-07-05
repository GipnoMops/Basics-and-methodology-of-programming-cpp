#include <iostream>
#include <string>

std::string CommonSuffix(const std::string& a, const std::string& b) {
    int i = 0;
    int pref_a = static_cast<int>(std::size(a)) - 1;
    int pref_b = static_cast<int>(std::size(b)) - 1;
    while (pref_a >= 0 && pref_b >= 0 && a[pref_a] == b[pref_b]) {
        ++i;
        --pref_b;
        --pref_a;
    }
    return a.substr(pref_a + 1, i);
}

int main() {
    std::string A = "llllllapple", B = "apple";
    std::cout << CommonSuffix(A, B);
    return 0;
}
