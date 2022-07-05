#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, pair<unsigned long long int, unsigned int>> students;
    size_t n;
    cin >> n;
    string name;
    int grade;
    for (size_t i = 0; i < n; ++i) {
        cin >> name >> grade;
        students[name].first += grade;
        ++students[name].second;
        cout << students[name].first / students[name].second << "\n";
    }
    return 0;
}
