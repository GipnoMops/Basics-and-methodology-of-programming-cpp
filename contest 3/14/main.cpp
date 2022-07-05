#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;


int main() {
    size_t n;
    cin >> n;
    list<int> order;
    map<int, list<int>::iterator> mapping;

    for (size_t i = 0; i < n; ++i) {
        int value, afterValue;
        cin >> value >> afterValue;
        auto it = mapping.find(afterValue);
        if (it != mapping.end()) {
            auto position = it->second;
            ++position;
            mapping[value] = order.insert(position, value);
        } else {
            mapping[value] = order.insert(order.begin(), value);
        }
    }
    for (auto value : order) {
        cout << value << "\n";
    }
}
