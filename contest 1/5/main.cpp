#include <iostream>

using namespace std;

int main() {
    int n, b;
    double summ = 0.0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        b = i * (i % 2) - i * ((i + 1) % 2);
        summ += 1.0 / b;
    }
    cout << summ;
    return 0;
}
