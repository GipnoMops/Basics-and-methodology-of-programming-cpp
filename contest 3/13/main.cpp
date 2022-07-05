#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    string name, comand;
    deque<string> stack;
    for (size_t i = 0; i < n; ++i) {
        cin >> name >> comand;
        if (comand == "top") {
            stack.push_front(name);
        } else {
            stack.push_back(name);
        }
    }

    size_t m, number;
    cin >> m;

    for (size_t i = 0; i < m; ++i) {
        cin >> number;
        cout << stack[number - 1] << "\n";
    }
    return 0;
}
