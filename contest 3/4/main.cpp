#include <iostream>
#include <set>
#include <string>
#include <fstream>

using namespace std;

set<char> set_from_str(const string& str) {
    set<char> set_from_str;
    for (const char& i : str) {
        set_from_str.insert(i);
    }
    return set_from_str;
}

set<char> intersection(const set<char>& set1, const set<char>& set2) {
    set<char> intersection;
    for (const char& i : set1) {
        if (set2.count(i) != 0) {
            intersection.insert(i);
        }
    }
    return intersection;
}

int main() {
    ifstream inFile("input.txt");
    string str;
    getline(inFile, str);
    set<char> general = set_from_str(str);
    while (getline(inFile, str) && !(general.empty())) {
        general = intersection(general, set_from_str(str));
    }

    for (const char& i : general) {
        cout << i;
    }
}
