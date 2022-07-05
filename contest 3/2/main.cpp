#include <iostream>
#include <set>

using namespace std;

int main() {
    int i;
    set<int> numbers;
    while (cin >> i) {
        if (numbers.count(i) == 0) {
            cout << "NO" << "\n";
            numbers.insert(i);
        } else {
            cout << "YES" << "\n";
        }
    }
    return 0;
}
