#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iterator>

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

    class Const_Iterator {
    private:
        const Matrix<T>& M;
        size_t row_, col_;

    public:
        Const_Iterator(const Matrix<T>& m, size_t row, size_t col): M(m), row_(row), col_(col) {}

        const T& operator* () const {
            return M[row_][col_];
        }

        const Const_Iterator& operator++ () {
            if (col_ < M.size().second - 1) {
                ++col_;
                return *this;
            } else {
                col_ = 0;
                ++row_;
                return *this;
            }
        }

        const Const_Iterator operator++ (int) {
            auto ansver = *this;
            if (col_ < M.size().second - 1) {
                ++col_;
            } else {
                col_ = 0;
                ++row_;
            }
            return ansver;
        }

        bool operator== (Const_Iterator other) const {
            return (row_ == other.row_) && (col_ == other.col_);
        }

        bool operator!= (Const_Iterator other) const {
            return !((*this) == other);
        }
    };

    class Iterator {
    private:
        Matrix<T>& M;
        size_t row_, col_;

    public:
        Iterator(Matrix<T>& m, size_t row, size_t col): M(m), row_(row), col_(col) {}

        T& operator* () const {
            return M[row_][col_];
        }

        Iterator& operator++ () {
            if (col_ < M.size().second - 1) {
                ++col_;
                return *this;
            } else {
                col_ = 0;
                ++row_;
                return *this;
            }
        }

        Iterator operator++ (int) {
            auto ansver = *this;
            if (col_ < M.size().second - 1) {
                ++col_;
            } else {
                col_ = 0;
                ++row_;
            }
            return ansver;
        }

        bool operator== (Iterator other) const {
            return (row_ == other.row_) && (col_ == other.col_);
        }

        bool operator!= (Iterator other) const {
            return !((*this) == other);
        }
    };

    Iterator begin() {
        return Iterator(*this, 0, 0);
    }

    Iterator end() {
        return Iterator(*this, elem_.size(), 0);
    }

    Const_Iterator begin() const {
        return Const_Iterator(*this, 0, 0);
    }

    Const_Iterator end() const {
        return Const_Iterator(*this, elem_.size(), 0);
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

    Matrix& transpose() {
        size_t max_size = std::max(lines_, columns_);
        elem_.resize(max_size);
        for (auto& i : elem_) {
            i.resize(max_size, 0);
        }
        for (size_t i = 0; i < max_size; ++i) {
            for (size_t j = i; j < max_size; ++j) {
                std::swap(elem_[i][j], elem_[j][i]);
            }
        }
        elem_.resize(columns_);
        for (auto& i : elem_) {
            i.resize(lines_);
        }
        std::swap(lines_, columns_);
        return *this;
    }

    Matrix transposed() const {
        Matrix<T> result(*this);
        result.transpose();
        return result;
    }

    Matrix operator * (const Matrix& other) const {
        assert(lines_ == other.columns_);
        assert(columns_ == other.lines_);

        std::vector<std::vector<T>> result;
        result.resize(lines_);
        for (auto& i : result) {
            i.resize(other.columns_);
        }

        for (size_t i = 0; i < lines_; ++i) {
            for (size_t j = 0; j < lines_; ++j) {
                for (size_t k = 0; k < columns_; ++k) {
                    result[i][j] += elem_[i][k] * other.elem_[k][j];
                }
            }
        }
        return Matrix<T>(result);
    }

    Matrix& operator *= (const Matrix& other) {
        (*this) = (*this) * other;
        return *this;
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
            {1, 2},
            {3, 4},
            {5, 6}
    };
    std::vector<std::vector<int>> vec2 = {
            {1, 2, 3},
            {4, 5, 6},
    };
    Matrix<int> m1(vec1), m2(vec2);

    auto e1 = m1.begin();
    std::cout << *e1 << " " << ++(*e1) << "\n";

    auto e = m1.begin();
    while (e != m1.end()) {
        std::cout << *(e++) << " ";
    }
    return 0;
}
