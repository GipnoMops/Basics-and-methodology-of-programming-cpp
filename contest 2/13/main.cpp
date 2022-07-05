#include <vector>
#include <string_view>

bool NextToken(string_view& sv; const char& delimiter, std::string_view token) {
    return true;
}

std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> ansver;
    std::string word;

    if (str == "") {
        return ansver;
    } else {
        for (size_t i = 0; i < str.size(); ++i) {
            word = "";
            if (str[i] != delimiter) {
                size_t j = i;
                while (j < str.size() && str[j] != delimiter) {
                    ++j;
                }
                word = str.substr(i, j - i);
                ansver.push_back(word);


                i = j;
            } else {
                ansver.push_back("");
            }
        }

        if (str[str.size() - 1] == delimiter) {
            ansver.push_back("");
        }

        return ansver;
    }
}

int main() {
    std::string_view sd = "Hello";
    return 0;
}