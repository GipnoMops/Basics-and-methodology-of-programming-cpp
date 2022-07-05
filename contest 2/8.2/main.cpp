#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Transpose(const vector<vector<int>>& matrix) {
    vector<vector<int>> transposed(size(matrix[0]), vector<int>(size(matrix)));

    for (size_t i = 0; i < size(matrix); ++i) {
        for (size_t j = 0; j < size(matrix[0]); ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

int main() {

    vector<vector<int>> mat = {
            {1, 2, 3},
            {4, 7, 8}
    };


    vector<vector<int>> a = Transpose(mat);

    for (size_t i = 0; i < size(a); ++i) {
        for (size_t j = 0; j < size(a[0]); ++j) {
            cout << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}
