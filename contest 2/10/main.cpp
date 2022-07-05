#include <iostream>
#include <vector>

std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> ansver;
    std::string word;

    if (str == "") {
        return ansver;
    } else {
        for (size_t i = 0; i < std::size(str); ++i) {
            word = "";
            if (str[i] != delimiter) {
                size_t j = i;
                while (j < std::size(str) && str[j] != delimiter) {
                    ++j;
                }
                word = str.substr(i, j - i);
                ansver.push_back(word);


                i = j;
            } else {
                ansver.push_back("");
            }
        }

        if (str[std::size(str) - 1] == delimiter) {
            ansver.push_back("");
        }

        return ansver;
    }
}

int main() {
    std::string dada = "__";
    char da = '_';
    std::vector<std::string> a = Split(dada, da);
    for (std::size_t i = 0; i < std::size(a); ++i) {
        std::cout << a[i] << "\n";
    }

    std::cout << std::size(a);

    return 0;
}
