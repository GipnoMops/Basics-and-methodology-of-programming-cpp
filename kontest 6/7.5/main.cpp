#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
class Polynomial {
private:
    std::vector<T> odds_;

public:
    Polynomial(const std::vector<T>& vec): odds_(vec) {
        (*this).DelNuls();
    }

    Polynomial(const T& a_0 = T(0)) {
        odds_.push_back(a_0);
        (*this).DelNuls();
    }

    template <typename Iter>
    Polynomial(Iter begin, Iter end) {
        while (begin != end) {
            odds_.push_back(*begin);
            ++begin;
        }
        (*this).DelNuls();
    }

    Polynomial<T>& operator+= (const Polynomial<T>& other) {
        if (odds_.size() > other.odds_.size()) {
            for (size_t i = 0; i < other.odds_.size(); ++i) {
                odds_[i] += other.odds_[i];
            }
        } else {
            size_t max_size = std::max(odds_.size(), other.odds_.size());
            odds_.resize(max_size);
            for (size_t i = 0; i < other.odds_.size(); ++i) {
                odds_[i] += other.odds_[i];
            }
        }
        (*this).DelNuls();
        return *this;
    }

    Polynomial<T> operator+ (const Polynomial<T>& other) const {
        Polynomial<T> ansver(odds_);
        ansver += other;
        return ansver;
    }

    Polynomial<T>& operator-= (const Polynomial<T>& other) {
        if (odds_.size() > other.odds_.size()) {
            for (size_t i = 0; i < other.odds_.size(); ++i) {
                odds_[i] -= other.odds_[i];
            }
        } else {
            size_t max_size = std::max(odds_.size(), other.odds_.size());
            odds_.resize(max_size);
            for (size_t i = 0; i < other.odds_.size(); ++i) {
                odds_[i] -= other.odds_[i];
            }
        }
        (*this).DelNuls();
        return *this;
    }

    Polynomial<T> operator- (const Polynomial<T>& other) const {
        Polynomial<T> ansver(odds_);
        ansver -= other;
        return ansver;
    }

    Polynomial<T> operator* (const Polynomial<T>& other) const {
        Polynomial<T> ansver;
        ansver.odds_.resize(odds_.size() + other.odds_.size());
        for (size_t i = 0; i < odds_.size(); ++i) {
            for (size_t j = 0; j < other.odds_.size(); ++j) {
                ansver.odds_[i + j] += odds_[i] * other.odds_[j];
            }
        }
        ansver.DelNuls();
        return ansver;
    }

    Polynomial<T>& operator*= (const Polynomial<T>& other) {
        (*this) = (*this) * other;
        return (*this);
    }

    /*Polynomial<T> operator/ (const Polynomial<T>& other) const {
        Polynomial<T> temp = *this;
        int rdeg = temp.Degree() - other.Degree() + 1;
        Polynomial<T> res;
        res.odds_.resize(rdeg);
        for (int i = 0; i < rdeg; i++) {
            res.odds_[rdeg - i - 1] = temp[temp.Degree() - i] / other[other.Degree()];
            for (int j = 0; j < other.Degree(); j++) {
                temp.odds_[temp.Degree() - j - i - 1] -= other[other.Degree() - j - 1] *
                        res[rdeg - i - 1];
            }
        }
        res.DelNuls();
        return res;
    }*/

    Polynomial<T> operator/ (const Polynomial<T>& other) const {
        Polynomial<T> temp = *this;
        Polynomial<T> ansver;
        ansver.odds_.resize((temp).Degree() - other.Degree() + 1);
        for (size_t i = 0; i <= ansver.Degree(); ++i) {
            ansver.odds_[ansver.Degree() - i] = temp[temp.Degree() - i] / other[other.Degree()];
            for (size_t j = 0; j <= other.Degree(); ++j) {
                temp.odds_[temp.Degree() - j - i] -= ansver[ansver.Degree() - i] * other[other.Degree() - j];
            }
        }
        return ansver;
    }

    Polynomial<T> operator% (const Polynomial<T> other) const {
        Polynomial<T> temp = *this;
        return temp - other * ((*this) / other);
        /*Polynomial<T> ansver;
        ansver.odds_.resize((temp).Degree() - other.Degree() + 1);
        for (size_t i = 0; i <= ansver.Degree(); ++i) {
            ansver[ansver.Degree() - i] = temp[temp.Degree() - i] / other[other.Degree()];
            for (size_t j = 0; j <= other.Degree(); ++j) {
                temp[temp.Degree() - j - i] -= ansver[ansver.Degree() - i] * other[other.Degree() - j];
            }
        }
        temp.DelNuls();
        return temp;*/
    }

    /*Polynomial<T> operator% (const Polynomial<T> other) const {
        Polynomial<T> temp = *this;
        int rdeg = temp.Degree() - other.Degree() + 1;
        Polynomial<T> res;
        res.odds_.resize(rdeg);
        for (int i = 0; i < rdeg; i++) {
            res.odds_[rdeg - i - 1] = temp[temp.Degree() - i] / other[other.Degree()];
            for (int j = 0; j < other.Degree() + 1; j++) {
                temp.odds_[temp.Degree() - j - i] -= other[other.Degree() - j] *
                        res[rdeg - i - 1];
            }
        }
        temp.DelNuls();
        return temp;
    }*/

    bool operator== (const Polynomial<T>& other) const {
        return (odds_ == other.odds_);
    }

    bool operator!= (const Polynomial<T>& other) const {
        return (odds_ != other.odds_);
    }

    const T operator[] (size_t i) const {
        if (i < odds_.size()) {
            return odds_[i];
        } else {
            T nul = static_cast<T>(0);
            return nul;
        }
    }

    T operator[] (size_t i) {
        if (i < odds_.size()) {
            return odds_[i];
        } else {
            T nul = static_cast<T>(0);
            return nul;
        }
    }

    T operator() (const T& x) const {
        T ansver = static_cast<T>(0);
        T i_pow_x = 1;
        for (size_t i = 0; i < odds_.size(); ++i) {
            ansver += i_pow_x * odds_[i];
            i_pow_x *= x;
        }
        return ansver;
    }

    Polynomial<T> operator,(const Polynomial<T>& P) {
        auto a = *this;
        auto b = P;
        while (b.Degree() != -1) {
            a = a % b;
            std::swap(a, b);
            b.DelNuls();
        }
        if (a.Degree() == 0) {
            return T(1);
        }
        return a;
    }

    Polynomial<T> operator& (const Polynomial<T>& other) const {
        Polynomial<T> ansver;
        ansver.odds_.resize((*this).Degree() * other.Degree());
        Polynomial<T> i_pow_other = other;

        if ((*this).Degree() >= 0) {
            ansver += odds_[0];
        }

        for (size_t i = 1; i < odds_.size(); ++i) {
            ansver += i_pow_other * odds_[i];
            i_pow_other = i_pow_other * other;
        }
        ansver.DelNuls();
        return ansver;
    }

    int Degree() const {
        if (odds_.size() == 0) {
            return -1;
        } else {
            return odds_.size() - 1;
        }
    }

    class Iterator {
    private:
        const Polynomial<T>& P_;
        size_t i_;

    public:
        Iterator(const Polynomial<T>& P, size_t i = 0): P_(P), i_(i) {}

        const T& operator* () const {
            return P_.odds_[i_];
        }

        Iterator& operator++ () {
            ++i_;
            return *this;
        }

        bool operator== (Iterator other) const {
            return i_ == other.i_;
        }

        bool operator!= (Iterator other) const {
            return i_ != other.i_;
        }
    };

    Iterator begin() const {
        return Iterator(*this, 0);
    }

    Iterator end() const {
        return Iterator(*this, odds_.size());
    }

    Polynomial<T>& DelNuls() {
        size_t counter = 0;
        for (int i = odds_.size() - 1; i > -1; --i) {
            if (odds_[i] == static_cast<T>(0)) {
                ++counter;
            } else {
                break;
            }
        }
        odds_.erase(odds_.end() - counter, odds_.end());
        return *this;
    }

    const std::vector<T>& GetVec() const {
        return odds_;
    }
};

template <typename T>
Polynomial<T> operator+ (const T& a, const Polynomial<T>& b) {
    return Polynomial<T>(a) + b;
}

template <typename T>
Polynomial<T> operator+ (const Polynomial<T>& a, const T& b) {
    return a + Polynomial<T>(b);
}

template <typename T>
Polynomial<T> operator- (const T& a, const Polynomial<T>& b) {
    return Polynomial<T>(a) - b;
}

template <typename T>
Polynomial<T> operator- (const Polynomial<T>& a, const T& b) {
    return a - Polynomial<T>(b);
}

template <typename T>
Polynomial<T> operator* (const T& a, const Polynomial<T>& b) {
    return Polynomial<T>(a) * b;
}

template <typename T>
Polynomial<T> operator* (const Polynomial<T>& a, const T& b) {
    return a * Polynomial<T>(b);
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const Polynomial<T>& P) {
    if (P.Degree() == 1) {
        if (P[1] == T(-1)) {
            out << "-x";
        } else if (P[1] == T(1)) {
            out << "x";
        } else if (P[1] != T(0)) {
            out << P[1] << "*x";
        }

        if (P[0] > T(0)) {
            out << "+";
            out << P[0];
        } else if (P[0] < T(0)) {
            out << P[0];
        }

    } else if (P.Degree() == 0) {
        out << P[0];

    } else if (P.Degree() == -1) {
        out << T(0);

    } else {
        if (P[P.Degree()] == T(-1)) {
            out << "-x^" << P.Degree();
        } else if (P[P.Degree()] == T(1)) {
            out << "x^" << P.Degree();
        } else {
            out << P[P.Degree()] << "*x^" << P.Degree();
        }

        for (int i = 1; i < P.Degree() - 1; ++i) {
            if (P[P.Degree() - i] == T(-1)) {
                out << "-x^" << P.Degree() - i;
            } else if (P[P.Degree() - i] == T(1)) {
                out << "+x^" << P.Degree() - i;
            } else if (P[P.Degree() - i] != T(0)) {
                if (P[P.Degree() - i] > T(0)) {
                    out << "+";
                }
                out << P[P.Degree() - i] << "*x^" << P.Degree() - i;
            }
        }

        if (P[1] == T(-1)) {
            out << "-x";
        } else if (P[1] == T(1)) {
            out << "+x";
        } else if (P[1] != T(0)) {
            if (P[1] > T(0)) {
                out << "+";
            }
            out << P[1] << "*x";
        }

        if (P[0] > T(0)) {
            out << "+";
            out << P[0];
        } else if (P[0] < T(0)) {
            out << P[0];
        }
    }
    return out;
}


int main() {
    std::vector<int> vec = {2, 2};
    std::vector<int> vec1 = {10, 43, 58, 24};
    std::vector<int> vec2 = {1, 3};
    Polynomial<int> p1(vec);
    Polynomial<int> p2(vec1);
    Polynomial<int> p3(vec2);

    std::cout << p2 / p3;

    //std::cout << p2 << "\n" << p3 << "\n";

    //std::cout << (p2, p3);
    return 0;
}
