#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t m, n, bombs;
    cin >> m >> n >> bombs;

    vector<vector<int>> field(m + 2, vector<int>(n + 2));

    int x, y;
    for (size_t i = 0; i < bombs; ++i) {
        cin >> x >> y;
        field[x][y] -= 9;
        ++field[x - 1][y];
        ++field[x][y - 1];
        ++field[x + 1][y];
        ++field[x][y + 1];
        ++field[x - 1][y - 1];
        ++field[x - 1][y + 1];
        ++field[x + 1][y - 1];
        ++field[x + 1][y + 1];
    }

    for (size_t i = 1; i < m + 1; ++i) {
        for (size_t j = 1; j < n + 1; ++j) {
            if (field[i][j] < 0) {
                cout << "*" << " ";
            } else {
                cout << field[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}