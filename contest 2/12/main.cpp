#include <iostream>
#include <tuple>
#include <string>


std::tuple<std::size_t, size_t > FindVowels(const std::string& text, size_t& pos) {
    size_t start = pos, lengs = 0;
    while (start < text.size() && !(text[start + lengs] == 'a' || text[start + lengs] == 'e' ||
    text[start + lengs] == 'i' || text[start + lengs] == 'o' ||
    text[start + lengs] == 'u' || text[start + lengs] == 'y'||
    text[start + lengs] == 'A' || text[start + lengs] == 'E' ||
    text[start + lengs] == 'I' || text[start + lengs] == 'O' ||
    text[start + lengs] == 'U' || text[start + lengs] == 'Y')) {
        ++start;
    }

    if (start == text.size()) {
        start = std::string::npos;
        return std::make_tuple(start, 0);
    }


    while (start + lengs < text.size() - 1 && (text[start + lengs] == 'a' ||
    text[start + lengs] == 'e' ||
    text[start + lengs] == 'i' || text[start + lengs] == 'o' ||
    text[start + lengs] == 'u' || text[start + lengs] == 'y'||
    text[start + lengs] == 'A' || text[start + lengs] == 'E' ||
    text[start + lengs] == 'I' || text[start + lengs] == 'O' ||
    text[start + lengs] == 'U' || text[start + lengs] == 'Y')) {
        ++lengs;
    }

    if (start + lengs == text.size()) {
        start = std::string::npos;
        return std::make_tuple(start, 0);
    }

    if (start + lengs == text.size() - 1 && (text[start + lengs] == 'a' ||
    text[start + lengs] == 'e' ||
    text[start + lengs] == 'i' || text[start + lengs] == 'o' ||
    text[start + lengs] == 'u' || text[start + lengs] == 'y'||
    text[start + lengs] == 'A' || text[start + lengs] == 'E' ||
    text[start + lengs] == 'I' || text[start + lengs] == 'O' ||
    text[start + lengs] == 'U' || text[start + lengs] == 'Y')) {
        ++lengs;
    }

    return std::make_tuple(start, lengs);
}

int main() {
    std::string text;
    getline(std::cin, text);
    size_t pos = 0;
    while (true) {
        auto [start, length] = FindVowels(text, pos);
        if (start == std::string::npos)
            break;
        std::cout << start << " " << length << " " << text.substr(start, length) << "\n";
        pos = start + length;
    }
}