#include <iostream>
#include <utility>

class Vector {
private:
    size_t size_ = 0;
    int* ptr_ = nullptr;
    size_t capacity_ = 0;

public:
    Vector() = default;

    Vector(const Vector& other) {
        size_ = other.size_;
        capacity_ = other.size_;
        ptr_ = new int[size_];
        for (size_t i = 0; i < size_; ++i) {
            ptr_[i] = other.ptr_[i];
        }
    }

    ~Vector() {
        delete[] ptr_;
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }
        delete[] ptr_;
        size_ = other.size_;
        capacity_ = other.size_;
        ptr_ = new int[size_];
        for (size_t i = 0; i < size_; ++i) {
            ptr_[i] = other.ptr_[i];
        }
        return *this;
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }

    void push_back(const int& new_elem) {
        if (size_ + 1 <= capacity_) {
            ptr_[size_++] = new_elem;
        } else {
            capacity_ *= 2;
            int* new_ptr = new int[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                new_ptr[i] = ptr_[i];
            }
            delete[] ptr_;
            ptr_ = new_ptr;
            ptr_[size_++] = new_elem;
        }
    }

    void pop_back() {
        --size_;
    }

    int& operator[](const size_t& n) {
        return ptr_[n];
    }

    const int& operator[](const size_t& n) const {
        return ptr_[n];
    }
};


int main() {
    Vector a;
    a.push_back(10);
    std::cout << a[0];
    return 0;
}
