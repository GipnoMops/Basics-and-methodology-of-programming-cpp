#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main() {
    ifstream inFile("input.txt");
    set<string> ansver;
    string str, substring;

    while (getline(inFile, str)) {
        for (const char& i : str) {
            substring += i;
            if (i == '/') {
                ansver.insert(substring);
            }
        }
        substring = "";
    }

    for (const string& i : ansver) {
        cout << i << "\n";
    }
    return 0;
}
