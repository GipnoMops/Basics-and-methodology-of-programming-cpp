#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string password;
    cin >> password;
    bool cond1 = true, cond2, cond3 = false;

    for (char i : password) {
        if (i < 33 || i > 126) {
            cond1 = false;
            break;
        }
    }

    if (size(password) >= 8 && size(password) <= 14) {
        cond2 = true;
    } else {
        cond2 = false;
    }

    int big = 0, small = 0, num = 0, other = 0;
    for (char i : password) {
        if (isupper(i)) {
            big = 1;
        } else if (islower(i)) {
            small = 1;
        } else if (isalnum(i)) {
            num = 1;
        } else {
            other = 1;
        }
    }
    if (big + small + num + other >= 3) {
        cond3 = true;
    }

    if (cond1 && cond2 && cond3) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
