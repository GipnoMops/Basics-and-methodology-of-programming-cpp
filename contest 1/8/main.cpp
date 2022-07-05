#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string word;
    cin >> word;
    vector<int> soundex;
    for (size_t i = 1; i < size(word); ++i) {
        if (word[i] == 'b' || word[i] == 'f' ||
            word[i] == 'p' || word[i] == 'v') {
            soundex.push_back(1);
        } else if (word[i] == 'c' || word[i] == 'g' ||
            word[i] == 'j' || word[i] == 'k' ||
            word[i] == 'q' || word[i] == 's' ||
            word[i] == 'x' || word[i] == 'z')  {
            soundex.push_back(2);
        } else if (word[i] == 'd' || word[i] == 't') {
            soundex.push_back(3);
        } else if (word[i] == 'l') {
            soundex.push_back(4);
        } else if (word[i] == 'm' || word[i] == 'n') {
            soundex.push_back(5);
        } else if (word[i] == 'r') {
            soundex.push_back(6);
        }
    }

    cout << word[0];
    int k = 1;
    if (size(soundex) > 1) {
        cout << soundex[0];
        ++k;
        for (size_t i = 1; i < size(soundex); ++i) {
            if (soundex[i] != soundex[i - 1]) {
                cout << soundex[i];
                ++k;
                if (k == 4) {
                    break;
                }
            }
        }
    } else if (size(soundex) == 1) {
        cout << soundex[0];
        ++k;
    }

    if (k < 4) {
        for (size_t i = 0; i < static_cast<size_t>(4 - k); ++i) {
            cout << '0';
        }
    }
    return 0;
}
