#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<int> ar1, ar2;
    int num;

    for (size_t i = 0; i < n; ++i) {
        cin >> num;
        ar1.push_back(num);
    }

    for (size_t i = 0; i < m; ++i) {
        cin >> num;
        ar2.push_back(num);
    }

    for (const int& i : ar2) {
        auto it = lower_bound(ar1.begin(), ar1.end(), i);
        if (it == ar1.begin()) {
            cout << *it << "\n";
        } else if (it == ar1.end()) {
            cout << *--ar1.end() << "\n";
        } else if ((*it - i) < (i - *--it)) {
            cout << *++it << "\n";
        } else {
            cout << *it << "\n";
        }
    }
    return 0;
}
