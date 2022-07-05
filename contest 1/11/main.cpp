#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile("input.txt");
    string word;
    vector<string> lines;

    while (getline(inFile, word)) {
        lines.push_back(word);
    }

    sort(lines.begin(), lines.end(), greater<string>());
    for (string i : lines) {
        cout << i << '\n';
    }
    return 0;
}
