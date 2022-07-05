#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>

using namespace std;

const vector<string> NUM = {
        "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "11", "12", "13", "14", "15", "16", "17", "18", "19", "20"
};

const vector<string> LETTERS = {
        "A", "B", "C", "D", "E",
        "F", "G", "H", "I", "J",
        "K", "L", "M", "N", "O",
        "P", "Q", "R", "S", "T",
};

int string_in_int(string& str) {
    int len = str.size(), num = 0;
    --len;
    for (char& i : str) {
        num += (i - '1' + 1) * static_cast<int>(pow(10, len--));
    }
    return num;
}

void unresolved(vector<string> v) {
    cout << v[0] << " ";
    int num_of_tasks = string_in_int(v[1]);
    if (v.size() == 2) {
        for (int i = 1; i <= num_of_tasks; ++i) {
            cout << i << " ";
        }
        cout << "\n";
    } else if (v[2].size() == 1 && isupper(v[2][0])) {
        vector<string> ansver;
        set_difference(LETTERS.begin(), LETTERS.begin() + num_of_tasks,
                       v.begin() + 2, v.end(), ansver.begin());
        for (const auto& i : ansver) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cout << "!";
        vector<string> ansver;
        set_difference(NUM.begin(), NUM.begin() + num_of_tasks,
                       v.begin() + 2, v.end(), ansver.begin());
        for (const auto& i : ansver) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main() {
    ifstream inFile("input.txt");
    vector<vector<string>> a;
    vector<string> empty;
    a.push_back(empty);
    int i = 0;

    while (inFile.good()) {
        string elem;
        inFile >> elem;
        a[i].push_back(elem);
        if (inFile.peek() =='\n') {
            ++i;
            a.push_back(empty);
        }
    }

    if (a[a.size() - 1].empty()) {
        a.pop_back();
    }

    for (auto& vec : a) {
        unresolved(vec);
    }

    return 0;
}
