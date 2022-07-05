#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t m, n;
    cin >> m >> n;

    vector<vector<int>> plates(m + 2, vector<int>(n + 2));

    for (size_t i = 1; i < m + 1; ++i) {
        for (size_t j = 1; j < n + 1; ++j) {
            cin >> plates[i][j];
        }
    }

    size_t k;
    cin >> k;

    bool flag = true;
    size_t counter = 0;
    for (size_t i = 1; i < m + 1; ++i) {
        for (size_t j = 1; j < n + 1; ++j) {
            if (plates[i][j] == 0) {
                ++counter;
                if (counter >= k) {
                    flag = false;
                    break;
                }
            } else {
                counter = 0;
            }
        }
        if (counter >= k) {
            counter = false;
            cout << i;
            break;
        } else {
            counter = 0;
        }
    }

    if (flag) {
        cout << "0";
    }

    return 0;
}