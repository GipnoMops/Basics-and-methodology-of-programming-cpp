#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile("input.txt");
    string line;
    int letters = 0, words = 0, lines = 0;

    bool flag = false;
    while (getline(inFile, line)) {
        if (flag) {
            words += 1;
            flag = false;
        }
        lines += 1;
        for (char i : line) {
            if (isalpha(i)) {
                letters += 1;
                flag = true;
            } else if (flag) {
                words += 1;
                flag = false;
            }
        }
    }

    if (flag) {
        words += 1;
    }

    cout << "Input file contains:\n";
    cout << letters << " letters\n";
    cout << words << " words\n";
    cout << lines << " lines\n";

    return 0;
}
