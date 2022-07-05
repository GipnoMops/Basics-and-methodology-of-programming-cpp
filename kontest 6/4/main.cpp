#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

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
    m1 *= m2;
    std::cout << m1;
    //std::cout << m1 * m2 << "\n\n" << m1 << "\n\n" << m2;
    return 0;
}


/*
 * if (month > 12 || month < 1 || day < 1 || day > DAY_IN_MONTH[month - 1]) {
            throw  std::invalid_argument("invalid argument");
        }
 */