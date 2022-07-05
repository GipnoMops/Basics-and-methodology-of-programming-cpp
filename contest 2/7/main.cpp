#include <iostream>
#include <vector>

using namespace std;

bool is_associative(const vector<vector<int>>& matrix) {
    size_t n;
    n = std::size(matrix);

    if (n == 0 || n == 1) {
        return true;
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i; j < n; ++j) {
            for (size_t k = j; k < n; ++k) {
                if (matrix[matrix[i][j]][k] != matrix[k][matrix[i][j]]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    size_t n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }


    if (is_associative(matrix)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
