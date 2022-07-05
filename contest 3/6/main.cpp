#include <iostream>
#include <list>
#include <set>
#include <string>

using namespace std;

set<char> set_from_str(const string& str) {
    set<char> set_from_str;
    for (const char& i : str) {
        set_from_str.insert(i);
    }
    return set_from_str;
}

size_t num_of_consistent(const set<set<char>>& witness, const set<char>& suspect) {
    size_t consistent_num = 0;

    for (const set<char>& witnes : witness) {
        bool flag = true;
        for (const char& i : witnes) {
            if (suspect.count(i) == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ++consistent_num;
        }
    }
    return consistent_num;
}

int main() {
    set<set<char>> witness;
    size_t m;
    cin >> m;
    string witnes;
    for (size_t i = 0; i < m; ++i) {
        cin >> witnes;
        witness.insert(set_from_str(witnes));
    }

    cin >> m;
    list<string> suspects;
    string suspect;
    size_t max_consistent_num = 0, consistent_num;
    for (size_t i = 0; i  < m; ++i) {
        cin >> suspect;
        consistent_num = num_of_consistent(witness, set_from_str(suspect));
        if (consistent_num == max_consistent_num) {
            suspects.push_back(suspect);
        } else if (consistent_num > max_consistent_num) {
            max_consistent_num = consistent_num;
            suspects.clear();
            suspects.push_back(suspect);
        }
    }

    for (const auto& i : suspects) {
        cout << i << "\n";
    }

    return 0;
}
