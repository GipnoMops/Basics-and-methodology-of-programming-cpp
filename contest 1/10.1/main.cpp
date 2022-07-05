#include <iostream>
#include <string>

using namespace std;

int main() {
    string num;
    cin >> num;
    for (size_t i = 0; i < size(num); ++i) {
        if (num[size(num) - i - 1] == '9') {
            num[size(num) - i - 1] = '0';
        } else {
            num[size(num) - i - 1] += 1;
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
