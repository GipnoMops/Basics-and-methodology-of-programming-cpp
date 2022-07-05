#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<int> numbers;
    string comand;
    while (cin >> comand) {
        if (comand == "push") {
            int num;
            cin >> num;
            numbers.push(num);
            cout << "ok\n";
        } else if (comand == "pop") {
            if (numbers.empty()) {
                cout << "error\n";
            } else {
                cout << numbers.front() << "\n";
                numbers.pop();
            }
        } else if (comand == "front") {
            if (numbers.empty()) {
                cout << "error\n";
            } else {
                cout << numbers.front() << "\n";
            }
        } else if (comand == "size") {
            cout << numbers.size() << "\n";
        } else if (comand == "clear") {
            int k = numbers.size();
            for (size_t i = 0; i < k; ++i) {
                numbers.pop();
            }
            cout << "ok\n";
        } else if (comand == "exit") {
            cout << "bye\n";
            break;
        }
    }
    return 0;
}
