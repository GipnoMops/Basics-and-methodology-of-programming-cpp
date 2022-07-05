#include <iostream>
#include <string>
#include <utility>
#include <fstream>


class Vim {
private:
    std::string input_;
    std::string output_;
    std::string text_;
    size_t cursor_position_ = 0;
    size_t reading_position_ = 0;
    bool mode_ = false;

public:
    Vim(std::string input) : input_(std::move(input)) {}

    bool mode() {
        return mode_;
    }

    void change_mode0() {
        mode_ = false;
    }

    void change_mode1() {
        mode_ = true;
    }

    void left() {
        if (cursor_position_ > 0) {
            --cursor_position_;
        }
    }

    void right() {
        if (cursor_position_ < reading_position_) {
            ++cursor_position_;
        }
    }

    void insert(char letter) {
        output_.insert(cursor_position_, 1, letter);
        ++cursor_position_;
        ++reading_position_;
    }

    std::string print() const {
        return output_;
    }
};

int main() {
    std::string text;
    std::ifstream inFile("input.txt");
    std::getline(inFile, text);

    Vim out(text);

    for (size_t i = 0; i < text.size(); ++i) {
        char letter = text[i];
        if (letter == 'i' && !out.mode()) {
            out.change_mode1();
        } else if (letter == 'h' && !out.mode()) {
            out.left();
        } else if (letter == 'l' && !out.mode()) {
            out.right();
        } else if (letter == '<' && out.mode()) {
            i += 4;
            out.change_mode0();
        } else if (out.mode()) {
            out.insert(letter);
        }
    }

    std::cout << out.print();
    return 0;
}
