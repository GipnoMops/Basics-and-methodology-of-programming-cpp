#include <iostream>
#include <utility>

template<class T>
class Vector {
private:
    T* data;
    size_t sz;
    size_t cp;

    static T* Allocate(size_t n) {
        return static_cast<T*>(operator new(n * sizeof(T)));
    }

    static void Deallocate(T* buf) {
        operator delete(buf);
    }

    static void Construct(void * buf) {
        new (buf) T();
    }

    static void Construct(void * buf, const T& elem) {
        new (buf) T(elem);
    }

    static void Construct(void * buf, T&& elem) {
        new (buf) T(std::move(elem));
    }

    static void Destroy(T* buf) {
        buf->~T();
    }

public:
    explicit Vector(size_t n = 0) {
        data = Allocate(n);
        for (size_t i = 0; i != n; ++i) {
            Construct(data + i);
        }
        sz = cp = n;
    }

    Vector(const Vector& other) {
        data = Allocate(other.sz);
        for (size_t i = 0; i != other.sz; ++i) {
            Construct(data + i, other[i]);
        }
        sz = cp = other.sz;
    }

    ~Vector() {
        for (size_t i = 0; i != sz; ++i) {
            Destroy(data + i);
        }
        Deallocate(data);
    }

    void Reserve(size_t n) {
        if (n > cp) {
            auto data2 = Allocate(n);
            for(size_t i = 0; i != sz; ++i) {
                Construct(data2 + i, std::move(data[i]));
                Destroy(data + i);
            }
            Deallocate(data);
            data = data2;
            cp = n;
        }
    }
    /*MyVector() = default;
    MyVector(const MyVector& other) {
        size_ = other.size_;
        capacity_ = other.size_;
        ptr_ = new T[size_];
        for (size_t i = 0; i < size_; ++i) {
            ptr_[i] = other.ptr_[i];
        }
    }
    size_t size() const {
        return size_;
    }
    size_t capacity() const {
        return capacity_;
    }
    T& front() {
        return ptr_[0];
    }
    const T& front() const {
        return ptr_[0];
    }
    T& back() {
        return ptr_[size_ - 1];
    }
    const T& back() const {
        return ptr_[size_ - 1];
    }
    void push_back(const T& new_elem) {
        if (size_ + 1 <= capacity_) {
            ptr_[size_++] = new_elem;
        } else {
            capacity_ *= 2;
            T* new_ptr_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                new_ptr_[i] = ptr_[i];
            }
            delete[] ptr_;
            ptr_ = new_ptr_;
            ptr[size_++] = new_elem;
        }
    }*/
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
