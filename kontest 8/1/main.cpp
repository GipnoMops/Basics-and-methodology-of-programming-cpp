#include <iostream>

template<typename T>
class UniquePtr {
private:
    T* ptr_;

public:
    UniquePtr(): ptr_(nullptr) {}

    UniquePtr(T* p): ptr_(p) {}

    UniquePtr(UniquePtr&& other) {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }

    UniquePtr(const UniquePtr& other) noexcept = delete;

    UniquePtr& operator=(const UniquePtr& other) noexcept = delete;

    UniquePtr& operator=(UniquePtr&& p) {
        if (this != &p) {
            delete ptr_;
            ptr_ = p.ptr_;
            p.ptr_ = nullptr;
        }
        return *this;
    }

    UniquePtr& operator=(std::nullptr_t a) {
        delete ptr_;
        ptr_ = a;
        return *this;
    }

    void Print() {
        if (ptr_ == nullptr) {
            std::cout << "nullptr\n";
        } else {
            std::cout << *ptr_ << "\n";
        }
    }

    ~UniquePtr() {
        delete ptr_;
    }

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const noexcept {
        return ptr_;
    }

    T* release() {
        T* ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void reset(T* ptr) {
        delete ptr_;
        ptr_ = ptr;
    }

    void swap(UniquePtr& other) {
        std::swap(ptr_, other.ptr_);
    }

    T* get() const {
        return ptr_;
    }

    explicit operator bool() const {
        if (ptr_ == nullptr) {
            return false;
        } else {
            return true;
        }
    }
};

int main() {
    /*int* ptr = new int;
    std::cout << *ptr << "\n";
    *ptr = 8;

    std::cout << *ptr << "\n";

    UniquePtr<int> a(ptr);

    if (a) {
        std::cout << "O\n";
    }

    a = nullptr;

    a.Print();*/

    int* ptr = new int;
    *ptr = 8;

    int* ptr2 = new int;
    *ptr2 = 10;


    UniquePtr<int> a2(ptr);
    UniquePtr<int> a1(ptr2);
    a2 = std::move(a1);

    return 0;
}
