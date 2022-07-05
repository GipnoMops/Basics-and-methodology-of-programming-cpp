#include <iostream>
#include <vector>

template <typename T>
class Matrix {
private:
    size_t lines_;
    size_t columns_;
    std::vector<std::vector<T>> elem_;

public:
    Matrix(const std::vector<std::vector<T>>& vec) {
        elem_ = vec;
        lines_ = vec.size();
        columns_ = vec[0].size();
    }

    std::pair<size_t, size_t> size() const {
        return std::pair<size_t, size_t> (lines_, columns_);
    }

    T operator[] (size_t i) {
    return elem_[i];
    }

    const T operator[] (size_t i) const {
    return elem_[i];
    }
};

template <typename T>
std::ostream& operator<< (std::ostream& out, const Matrix<T>& m) {
    size_t M = m.size().first;
    size_t N = m.size().second;
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            out << m[i][j];
            if (j != N - 1) {
                out << "\t";
            }
        }
        if (i != M - 1) {
            out << "\n";
        }
    }
    return out;
}
