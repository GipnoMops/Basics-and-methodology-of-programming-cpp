#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inFile("input.txt");

    map<char, int> frequency;
    string str;
     while (getline(inFile, str)) {
         for (const char& i : str) {
             if (i != ' ') {
                 ++frequency[i];
             }
         }
     }

     int max_height = 0;

    for (auto [i, j] : frequency) {
        if (j > max_height) {
            max_height = j;
        }
    }

    for (int i = 0; i < max_height; ++i) {
        for (auto [ch, num] : frequency) {
            if (max_height - i > num) {
                cout << " ";
            } else {
                cout << "#";
            }
        }
        cout << "\n";
    }

    for (auto [ch, num] : frequency) {
        cout << ch;
    }

    return 0;
}
