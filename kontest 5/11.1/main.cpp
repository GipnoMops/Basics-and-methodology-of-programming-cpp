#include <iostream>
#include <vector>

template <typename T>
class MathVector {
private:
    std::vector<T> data;

public:
    // Zero vector of size n
    MathVector(size_t n) {
        data.resize(n);
    }

    template <typename Iter>
    MathVector(Iter first, Iter last) {
        while (first != last)
            data.push_back(*(first++));
    }

    size_t Dimension() const {
        return data.size();
    }

    T& operator[] (size_t i) {
        return data[i];
    }

    T operator[] (size_t i) const {
        return data[i];
    }
};


// Output format: (1, 2, 3, 4, 5)
template <typename T>
std::ostream& operator << (std::ostream& out, const MathVector<T>& v) {
    out << '(';
    for (size_t i = 0; i != v.Dimension(); ++i) {
        if (i > 0)
            out << ", ";
        out << v[i];
    }
    out << ')';
    return out;
}

template <typename T>
MathVector<T>& operator *= (MathVector<T>& v, const T& scalar) {
    for (size_t i = 0; i != v.Dimension(); ++i)
        v[i] *= scalar;
    return v;
}

template <typename T>
MathVector<T> operator * (const MathVector<T>& v, const T& scalar) {
    auto tmp(v);
    tmp *= scalar;
    return tmp;
}

template <typename T>
MathVector<T> operator * (const T& scalar, const MathVector<T>& v) {
    return v * scalar;
}

template <typename T>
MathVector<T>& operator += (MathVector<T>& v1, const MathVector<T>& v2) {
    for (size_t i = 0; i != v1.Dimension(); ++i)
        v1[i] += v2[i];
    return v1;
}

template <typename T>
MathVector<T> operator + (const MathVector<T>& v1, const MathVector<T>& v2) {
    auto tmp(v1);
    tmp += v2;
    return tmp;
}


int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5}, v2 = {5, 4, 3, 2, 1};
    MathVector<int> vm(v1.begin(), v1.end()), vm2(v2.begin(), v2.end());
    vm += vm2;
    std::cout << (vm + vm2) << " " << vm2 << "\n";
    return 0;
}
