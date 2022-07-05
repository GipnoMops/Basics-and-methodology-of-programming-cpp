#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    size_t n, k;
    cin >> n >> k;
    vector<int> values;
    int value;
    for (size_t i = 0; i < n; ++i) {
        cin >> value;
        values.push_back(value);
    }
    multiset<int> window;
    for (size_t i = 0; i < n; ++i) {
        window.insert(values[i]);
        if (window.size() > k) {
            window.erase(window.find(values[i - k]));
        }
        if (window.size() == k) {
            cout << *window.begin() << "\n";
        }
    }
    return 0;
}
