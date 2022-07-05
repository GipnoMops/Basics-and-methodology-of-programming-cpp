#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <list>

using namespace std;

int scalar_product(const vector<int>& v1, const vector<int>& v2, const size_t& v_size) {
    int value = 0;
    for (size_t i = 0; i < v_size; ++i) {
        value += v1[i] * v2[i];
    }
    return value;
}

int main() {
    size_t num_of_words, size_vector;
    cin >> num_of_words >> size_vector;
    list<string> closest_words;
    vector<int> coordinates(size_vector), base(size_vector);

    string word;
    cin >> word;
    for (size_t i = 0; i < size_vector; ++i) {
        cin >> base[i];
    }

    int value_of_closest_words = 0, value;

    for (size_t i = 0; i < num_of_words - 1; ++i) {
        cin >> word;
        for (size_t j = 0; j < size_vector; ++j) {
            cin >> coordinates[j];
        }
        value = scalar_product(base, coordinates, size_vector);

        if (value == value_of_closest_words) {
            closest_words.push_back(word);
        } else if (value > value_of_closest_words) {
            value_of_closest_words = value;
            closest_words.clear();
            closest_words.push_back(word);
        }
    }
    for (const string& i : closest_words) {
        cout << i << "\n";
    }
    return 0;
}
