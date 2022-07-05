#include <iostream>
#include <string>

using namespace std;

int main() {
    string word, line;
    while (cin >> word) {
        line += word;
    }

    string flag = "yes";
    for (size_t i = 0; i <= size(line) / 2; ++i) {
        if (line[i] != line[size(line) - i - 1]) {
            flag = "no";
            break;
        }
    }

    cout << flag << "\n";

    return 0;
}
