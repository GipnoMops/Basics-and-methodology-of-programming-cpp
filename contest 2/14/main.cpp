#include <iostream>
#include <string_view>

bool CheckPalindrome (std::string_view line) {
    for (size_t i = 0; i < line.size() / 2; ++i) {
        if (line[i] != line[line.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

size_t CountPalindromes(std::string_view line) {
    size_t counter = 0;
    for (size_t i = 0; i < line.size(); ++i) {
        if (line[i] != ' ') {
            size_t j = i;
            while (j < line.size() && line[j] != ' ') {
                ++j;
            }
            if (CheckPalindrome(line.substr(i, j - i))) {
                ++counter;
            }
            i = j;
        }
    }
    return counter;
}



int main() {

    return 0;
}



