#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <cctype>

using namespace std;

int string_in_int(string& str) {
    int len = str.size(), num = 0;
    --len;
    for (char& i : str) {
        if (i == '1') {
            num += 1 * static_cast<int>(pow(10, len--));
        } else if (i == '2') {
            num += 2 * static_cast<int>(pow(10, len--));
        } else if (i == '3') {
            num += 3 * static_cast<int>(pow(10, len--));
        } else if (i == '4') {
            num += 4 * static_cast<int>(pow(10, len--));
        } else if (i == '5') {
            num += 5 * static_cast<int>(pow(10, len--));
        } else if (i == '6') {
            num += 6 * static_cast<int>(pow(10, len--));
        } else if (i == '7') {
            num += 7 * static_cast<int>(pow(10, len--));
        } else if (i == '8') {
            num += 8 * static_cast<int>(pow(10, len--));
        } else if (i == '9') {
            num += 9 * static_cast<int>(pow(10, len--));
        }
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
        int counter = 2;
        for (int  i = 0; i < (num_of_tasks - v.size() + 2); ++i) {
            if (counter < (v.size() - 1) && char(i + 65) == v[counter][0]) {
                ++counter;
            } else {
                cout << char(i + 65) << " ";
            }
        }
        cout << "\n";
    } else {
        int counter = 2;
        for (int  i = 1; i <= (num_of_tasks - v.size() + 2); ++i) {
            if (counter < (v.size() - 1) && i == string_in_int(v[counter])) {
                ++counter;
            } else {
                cout << i << " ";
            }
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

    while (inFile.good())
    {
        string elem;
        inFile >> elem;
        a[i].push_back(elem);
        if (inFile.peek()=='\n') {
            ++i;
            a.push_back(empty);
        }
    }

    for (auto& j : a) {
        for (auto& k : j) {
            cout << k << " ";
        }
        cout << "\n";
    }


    unresolved(a[0]);

    return 0;
}
