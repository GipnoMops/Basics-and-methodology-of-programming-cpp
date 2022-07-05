#include <iostream>

template<typename T>
class SharedPtr {
private:
    T* ptr = nullptr;
    size_t* ref_counter = nullptr;

public:
    SharedPtr() = default;

    SharedPtr(T* ptr): ptr(ptr) {
        if (ptr == nullptr) {
            return;
        }
        ref_counter = new size_t(1);
    }

    SharedPtr(const SharedPtr& other): ptr(other.ptr), ref_counter(other.ref_counter) {
        if (ptr == nullptr) {
            return;
        }
        ++*ref_counter;
    }

    SharedPtr(SharedPtr&& other): ptr(other.ptr), ref_counter(other.ref_counter) {
        other.ptr = nullptr;
        other.ref_counter = nullptr;
    }

    SharedPtr& operator=(T* new_ptr) {
        release();
        ptr = new_ptr;
        if (ptr == nullptr) {
            ref_counter = nullptr;
            return *this;
        }
        ref_counter = new size_t(1);
        return *this;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (&other == this) {
            return *this;
        }

        release();
        ptr = other.ptr;
        ref_counter = other.ref_counter;
        if (ptr != nullptr) {
            ++*ref_counter;
        }
        return *this;
    }

    SharedPtr& operator=(SharedPtr<T>&& other) {
        if (&other == this) {
            return *this;
        }

        release();
        ptr = other.ptr;
        ref_counter = other.ref_counter;
        other.ref_counter = nullptr;
        other.ptr = nullptr;
        return *this;
    }

    void release() {
        if (ptr != nullptr) {
            --*ref_counter;
            if (*ref_counter == 0) {
                delete ptr;
                delete ref_counter;
            }
        }
        ptr = nullptr;
        ref_counter = nullptr;
    }

    ~SharedPtr() {
        release();
    }

    T& operator*() const {
        return *ptr;
    }

    T& operator*() {
        return *ptr;
    }

    T* operator->() const noexcept {
        return ptr;
    }

    void reset(T* ref) {
        release();
        ptr = ref;
        if (ptr == nullptr) {
            ref_counter = nullptr;
            return;
        }
        ref_counter = new size_t(1);
    }

    void swap(SharedPtr& other) {
        std::swap(ptr, other.ptr);
        std::swap(ref_counter, other.ref_counter);
    }

    T* get() const {
        return ptr;
    }

    explicit operator bool() const {
        if (ptr == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    void Print() const {
        if (ptr == nullptr) {
            std::cout << "ptr == nullptr; ";
        }
        if (ref_counter == nullptr) {
            std::cout << "counter == nullptr;\n";
        }
        if (ptr != nullptr) {
            std::cout << "ptr == " << *ptr << "; ";
        }
        if (ref_counter != nullptr) {
            std::cout << "counter == " << *ref_counter << ";\n";
        }
    }
};


int main() {
    SharedPtr<int> a(new int(42));
    SharedPtr<int> b;
    a.Print();
    b.Print();
    b = a;
    a.Print();
    b.Print();
    return 0;
}
