#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
class Polynomial {
private:
    std::vector<T> odds_;
    //friend std::ostream& operator<< (std::ostream& out, const Polynomial<T>& polin);
public:
    Polynomial(const std::vector<T>& vec): odds_(vec) {
        (*this).DelNuls();
    }

    //это првельно?
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
    /*Polynomial(typename std::vector<T>::iterator begin,
               typename std::vector<T>::iterator end) {}*/

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

    bool operator== (const Polynomial<T>& other) const {
        return (odds_ == other.odds_);
    }

    bool operator!= (const Polynomial<T>& other) const {
        return (odds_ != other.odds_);
    }

    const T& operator[] (size_t i) const {
        if (i < odds_.size()) {
            return odds_[i];
        } else {
            return 0;
        }
    }

    int Degree () const {
        if (odds_.size() == 0) {
            return -1;
        } else {
            return odds_.size() - 1;
        }
    }

    //degin что такое ведущие нули
    //end

    class Iterator {
    private:
        Polynomial<T>& P_;
        size_t i_;

    public:
        Iterator(Polynomial<T>& P, size_t i = 0): P_(P) {
            i_ = i;
            while (i_ < P_.odds_.size() && P_.odds_[i] == static_cast<T>(0)) {
                ++i_;
            }
        }

        const T& operator* () const {
            return P_[i_];
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

    Iterator begin() {
        return Iterator(*this, 0);
    }

    Iterator end() {
        return Iterator(*this, odds_.size());
    }

    const std::vector<T>& GetVec() const {
        return odds_;
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
        //дифолтный ноль ое Т нужно писать, а не 0
    }
};

/*template <typename T>
std::ostream& operator<< (std::ostream& out, const Polynomial<T>& polin) {
}*/

int main() {
    std::vector<int> vec = {0, 0, 2, 3, 4, 5, 6, 0, 0, 0, 0, 0};
    std::vector<int> vec1 = {2, 3, 4, 5, 6, 0, 0};
    std::vector<double> vec2 = {4.0, 0.0};
    Polynomial<int> p1(vec);
    Polynomial<int> p2(vec1);
    Polynomial<double> p3(vec2);

    for (auto& i : p1.GetVec()) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    for (auto& i : p2.GetVec()) {
        std::cout << i << " ";
    }
    std::cout << "\n";


    for (auto& i : p3.GetVec()) {
        std::cout << i << " ";
    }
    std::cout << "\n\n";

    //p1 += p2;
    /*for (auto& i : (p1 - p2).GetVec()) {
        std::cout << i << " ";
    }
    std::cout << "\n";*/

    /*for (auto& i : p1.GetVec()) {
        std::cout << i << " ";
    }
    std::cout << "\n";*/

    //std::cout << p1.Degree() << " " << p2.Degree() << " " << p3.Degree() << "\n";
    //std::cout << (p1 == p2) << " " << (p1 == p3);


    auto e = p1.begin();
    std::cout << *e << " " << *(++e) << " " << *(++e) << " " << *(++e) << "  " << *(++e);
    return 0;
}
