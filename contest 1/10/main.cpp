#include <iostream>
#include <string>

using namespace std;

int main() {
    string num;
    cin >> num;
    for (size_t i = size(num) - 1; i >= 0; --i) {
        if (num[i] == '9') {
            num[i] = '0';
        } else {
            num[i] += 1;
            break;
        }
    }

    if (num[0] == '0') {
        cout << '1' << num << '\n';
    } else {
        cout << num << '\n';
    }

    return 0;
}
