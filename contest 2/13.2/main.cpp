#include <vector>
#include <string>
#include <string_view>
#include <iostream>

bool NextToken(std::string_view& sv, const char& delimiter, std::string_view& token) {

    if (sv.empty()) {
        return false;
    }

    size_t i = 0;

    while (i < sv.size() && sv[i] != delimiter) {
        ++i;
    }

    if (i == 0) {
        token = "";
        sv.remove_prefix(1);
    } else {
        token = sv.substr(0, i);
        if (sv.size() > i + 1) {
            sv.remove_prefix(i + 1);
        } else {
            sv.remove_prefix(i);
        }

    }

    return true;
}

int main() {
    std::string_view sv = "  ";
    const char delimiter = ' ';
    std::string_view token = "a";
    while (NextToken(sv, delimiter, token)) {
        if (token.empty()) {
            std::cout << "empty" << "\n";
        } else {
            std::cout << token << "\n";
        }
    }
}
