#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t n, m, bombs;
    cin >> n >> m >> bombs;

    vector<vector<int>> field(m + 2, vector<int>(n + 2));

    for (size_t i = 0; i < n + 2; ++i){
        for (size_t j = 0; j < m + 2; ++j) {
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
