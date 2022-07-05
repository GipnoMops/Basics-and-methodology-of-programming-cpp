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

    auto& operator[] (size_t i) {
        return elem_[i];
    }

    auto& operator[] (size_t i) const {
        return elem_[i];
    }

    Matrix& operator+= (const Matrix<T>& other) {
        for (size_t i = 0; i < lines_; ++i) {
            for (size_t j = 0; j < columns_; ++j) {
                elem_[i][j] += other.elem_[i][j];
            }
        }
        return (*this);
    }

    Matrix operator+ (const Matrix<T>& b) const {
        Matrix<T> result(*this);
        result += b;
        return result;
    }

    template<typename Num>
    Matrix& operator*= (const Num& num) {
        for (size_t i = 0; i < lines_; ++i) {
            for (size_t j = 0; j < columns_; ++j) {
                elem_[i][j] *= num;
            }
        }
        return (*this);
    }

    template<typename Num>
    Matrix operator* (const Num& num) const {
        Matrix<T> result(*this);
        result *= num;
        return result;
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

int main() {
    std::vector<std::vector<int>> vec1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {10, 11, 12}
    };
    std::vector<std::vector<int>> vec2 = {
            {0, 0, -1},
            {1, 0, -1},
            {0, 0, 1},
            {0, -1, -2}
    };
    Matrix<int> m1(vec1), m2(vec2);
    //std::cout << (m1 + m2);
    /*m1 *= 5;
    m2 *= 0;*/
    m2 = m1;
    std::cout << m2;
    //std::cout << (m1 * 5) << "\n\n" << m1 << "\n\n" << (m2 * 0) << "\n\n" << m2;
    return 0;
}
