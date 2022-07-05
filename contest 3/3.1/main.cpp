#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    char comand = ' ';
    string word;
    unordered_set<string> words;
    while (true) {
        cin >> comand;
        if (comand == '#') {
            break;
        }
        cin >> word;
        if (comand == '+') {
            words.insert(word);
        } else if (comand == '-') {
            words.erase(word);
        } else if (comand == '?') {
            if (words.count(word) == 0) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
    return 0;
}
