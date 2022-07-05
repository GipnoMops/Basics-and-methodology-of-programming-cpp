#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    map<size_t, set<string>> words;
    string word;
    size_t page;
    for (size_t i = 0; i < n; ++i) {
        cin >> word >> page;
        words[page].insert(word);
    }

    for (const auto& [key, value] : words) {
        cout << key;
        for (const auto& i : words[key]) {
            cout << " " << i;
        }
        cout << "\n";
    }
    return 0;
}
