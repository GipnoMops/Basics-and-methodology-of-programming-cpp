#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    unordered_map<string, size_t> university;
    size_t n;
    cin >> n;
    string university_name;
    size_t places;
    for (size_t i = 0; i < n; ++i) {
        cin >> university_name >> places;
        university[university_name] = places;
    }

    cin >> n;
    string name, surname;
    size_t day, month, year, points, k;
    set<tuple<size_t, size_t, size_t, size_t, string, string, vector<string>>> studens;
    vector<string> uni;
    for (size_t i = 0; i < n; ++i) {
        cin >> name >> surname >> day >> month >> year >> points >> k;
        studens.insert(make_tuple(points, -1 * year, -1 * month, -1 * day, name, surname, uni));
    }
    return 0;
}
