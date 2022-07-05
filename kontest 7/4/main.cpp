//#include "classifiers.h"
#include <exception>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

using std::cout;
using std::string;
using std::vector;

class TooHardObjectException : public std::exception {
};

class MainClassifier {
public:
    explicit MainClassifier(const string& s)
            : data_(s) {
        cout << "Created MainClassifier()\n";
    }

    double classify(const string& s) {
        cout << "Called MainClassifier::classify(\"" << s << "\")\n";

        std::istringstream iss(s);
        vector<string> tokens{std::istream_iterator<string>{iss},
                              std::istream_iterator<string>{}};
        return std::stod(tokens[2]);
    }

private:
    string data_;
};

class FastClassifier {
public:
    explicit FastClassifier(const string& s)
            : data_(s) {
        cout << "Created FastClassifier()\n";
    }

    double classify(const string& s) {
        cout << "Called FastClassifier::classify(\"" << s << "\")\n";
        std::istringstream iss(s);
        vector<string> tokens{std::istream_iterator<string>{iss},
                              std::istream_iterator<string>{}};
        if (tokens[1] == "hard") {
            throw TooHardObjectException();
        } else {
            return std::stod(tokens[0]);
        }
    }

private:
    string data_;
};

class  CombinedClassifier {
private:
    string data1_;
    string data2_;
    std::unique_ptr<MainClassifier> ptr_mainclass_;
    std::unique_ptr<FastClassifier> ptr_fastclass_;

public:
    CombinedClassifier(const string&  s1, const string& s2):
    data1_(s1),
    data2_(s2),
    ptr_mainclass_(nullptr),
    ptr_fastclass_(std::make_unique<FastClassifier>(s1)) {}

    double classify(const string& s) {
        try {
            return (*ptr_fastclass_).classify(s);
        } catch (TooHardObjectException) {
            if (ptr_mainclass_ == nullptr) {
                ptr_mainclass_ = std::make_unique<MainClassifier>(s);
                return (*ptr_mainclass_).classify(s);
            } else {
                return (*ptr_mainclass_).classify(s);
            }
        }
    }
};

class sq {
private:
    std::unique_ptr<int> ptr_;

public:
    sq(const int& a): ptr_(std::make_unique<int>(a * a)) {}

    void pomen (const int& b) {

    }
};

int main() {
    /*CombinedClassifier c("a", "f");
    c.classify("Z");*/

    /*auto uni = std::make_unique<int>(42);
    cout << *uni << "\n";*/

    int n;
    try {
        std::cin >> n;
        if (n % 2 == 0) {
            throw TooHardObjectException();
        }
        std::cout << "no even\n";
    } catch (TooHardObjectException& e) {
        std::cout << "even\n";
    }

    return 0;
}