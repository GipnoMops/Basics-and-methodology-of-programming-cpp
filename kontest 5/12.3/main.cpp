#include <iostream>
#include <vector>

using std::vector;

class Minesweeper {
private:
    size_t M, N;
    vector<vector<int>> Table;

public:
    Minesweeper(size_t m, size_t n): M(m), N(n) {
        vector<int> row(N, 0);
        Table.resize(M, row);
    }

    size_t Rows() const {
        return M;
    }

    size_t Columns() const {
        return N;
    }

    void SetMine(size_t i, size_t j) {
        Table[i][j] = -1;
    }

    int& operator () (size_t i, size_t j) {
        return Table[i][j];
    }

    int operator () (size_t i, size_t j) const {
        return Table[i][j];
    }

    void CheckForMinesAround() {
        for (size_t i = 0; i != M; ++i) {
            for (size_t j = 0; j != N; ++j) {
                CheckForMinesAround(i, j);
            }
        }
    }

private:
    void CheckForMinesAround(size_t i, size_t j) {
        if (Table[i][j] != -1) {
            int counter = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (0 <= i + dx && i + dx < M &&
                        0 <= j + dy && j + dy < N &&
                        Table[i + dx][j + dy] == -1) {
                        ++counter;
                    }
                }
            }
            Table[i][j] = counter;
        }
    }
};

std::ostream& operator << (std::ostream& out, const Minesweeper& ms) {
    for (size_t i = 0; i != ms.Rows(); ++i) {
        for (size_t j = 0; j != ms.Columns(); ++j) {
            if (ms(i, j) == -1)
                out << '*';
            else
                out << ms(i, j);
        }
        out << "\n";
    }
    return out;
}


int main() {
    Minesweeper table(10, 10);
    table.SetMine(0, 0);
    table.SetMine(2, 1);
    table.SetMine(4, 3);
    table.SetMine(7, 2);
    table.SetMine(1, 9);
    table.SetMine(9, 1);
    table.SetMine(7, 6);
    table.SetMine(2, 8);
    table.SetMine(9, 4);
    table.SetMine(9, 0);
    table.CheckForMinesAround();
    std::cout << table;
    return 0;
}
