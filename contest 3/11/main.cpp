#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    map<string, vector<int>> table;
    for (size_t i = 0; i < n; ++i) {
        size_t k;
        cin >> k;
        string login;
        int score;
        for (size_t j = 0; j < k; ++j) {
            cin >> login >> score;
            table.try_emplace(login, n).first->second[i] = score;
        }
    }

    for (const auto& [key, value] : table) {
        cout << key << "\t";
        for (size_t i = 0; i < n; ++i) {
            cout << value[i] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
