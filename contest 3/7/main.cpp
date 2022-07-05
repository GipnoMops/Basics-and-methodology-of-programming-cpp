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

bool is_word_in_snake(const set<char>& alphabet, const set<char>& word) {
    set<char> intersection;
    for (const char& i : word) {
        if (alphabet.count(i) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    set<char> alphabet;

    string alph;
    cin >> alph;

    for (const char& i : alph) {
        alphabet.insert(i);
    }

    size_t n;
    cin >> n;
    string word;
    list<string> snake_words;
    for (size_t i = 0; i < n; ++i) {
        cin >> word;
        if (is_word_in_snake(alphabet, set_from_str(word))) {
            snake_words.push_back(word);
        }
    }

    for (const string& i : snake_words) {
        cout << i << "\n";
    }

    return 0;
}
