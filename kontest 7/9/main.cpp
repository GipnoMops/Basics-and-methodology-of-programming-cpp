#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>


class Animal {
public:
    virtual std::string voice() const {
        return "Not implemented yet";
    }
    virtual ~Animal() {
    }
};


class Tiger: public Animal {
    std::string voice() const override {
        return "Rrrr";
    }
};


class Wolf: public Animal {
    std::string voice() const override {
        return "Wooo";
    }
};


class Fox: public Animal {
    std::string voice() const override {
        return "Tyaf";
    }
};

#include <memory>

using Zoo = std::vector<std::unique_ptr<Animal>>;

Zoo CreateZoo() {
    Zoo zoo;
    std::string word;
    while (std::cin >> word && word != "0") {
        if (word == "Tiger") {
            zoo.emplace_back(new Tiger);
        } else if (word == "Wolf") {
            zoo.emplace_back(new Wolf);
        } else if (word == "Fox") {
            zoo.emplace_back(new Fox);
        } else {
            throw std::runtime_error("Unknown animal!");
        }
    }
    return zoo;
}

void Process(const Zoo& zoo) {
    for (const auto& animal : zoo) {
        std::cout << animal->voice() << "\n";
    }
}

int main() {
    auto zoo = CreateZoo();
    Process(zoo);
    return 0;
}