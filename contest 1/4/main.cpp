#include <iostream>

using namespace std;

int main() {
    int n;
    long summ = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        summ += i * i;
    }
    cout << summ;
    return 0;
}
