#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {

    string text;
    cin >> text;
    vector<int> gepa = {1, 2, 3};
    int it = text.find("pisya", 0);
    while (it != string::npos) {
        text.replace(it, size("pisya"), "*** *");
        it = text.find("pisya", it);
    }

    cout << text;

    return 0;
}