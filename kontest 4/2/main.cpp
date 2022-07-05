#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    priority_queue<int> priority_queue, clear = {};
    string comand;
    while (cin >> comand) {
        if (comand == "ADD") {
            int num;
            cin >> num;
            priority_queue.push(num);
        } else if (comand == "CLEAR") {
            priority_queue = clear;
        } else if (comand == "EXTRACT") {
            if (priority_queue.empty()) {
                cout << "CANNOT\n";
            } else {
                cout << priority_queue.top() << "\n";
                priority_queue.pop();
            }
        }
    }
    return 0;
}
