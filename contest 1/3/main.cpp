#include <iostream>

using namespace std;

int main() {
    int a, summ = 0;
    cin >> a;
    while (a > 0) {
        summ += a % 10;
        a /= 10;
    }
    cout << summ;
    return 0;
}
