#include <algorithm>
#include <cstddef>
#include <memory>

struct RawMemory {
    int* buf;
    size_t Capacity_;

    static int* Allocate(size_t n) {
        return static_cast<int*>(operator new(n * sizeof(int)));
    }

    static void Deallocate(int* ptr) {
        operator delete(ptr);
    }

    void Swap(RawMemory& other) noexcept {
        std::swap(buf, other.buf);
        std::swap(Capacity_, other.Capacity_);
    }

    RawMemory() = default;

    RawMemory(size_t n) {
        buf = Allocate(n);
        Capacity_ = n;
    }

    RawMemory(const RawMemory&) = delete;
    RawMemory(RawMemory&& other) noexcept {
        Swap(other);
    }

    ~RawMemory() {
        Deallocate(buf);
    }

    int* operator+ (size_t i) {
        return buf + i;
    }

    const int* operator+ (size_t i) const {
        return buf + i;
    }

    int& operator[] (size_t i) const {
        return buf[i];
    }
};


class Vector {
private:
    RawMemory Data_;
    size_t Size_;

    static void Construct(void* buf) {
        new (buf) int();
    }

    static void Construct(void* buf, const int& elem) {
        new (buf) int(elem);
    }

    static void Construct(void* buf, int && elem) {
        new (buf) int(std::move(elem));
    }
    static void Destroy(int* buf) {
        delete buf;
    }

public:
    Vector(size_t size = 0): Data_(size) {
        std::uninitialized_value_construct_n(Data_.buf, size);
        Size_ = size;
    }

    Vector(const Vector& other): Data_(other.Size_) {
        std::uninitialized_copy_n(other.Data_.buf, other.Size_, Data_.buf);
        Size_ = other.Size_;
    }

    Vector& operator=(const Vector& other) {
        if (other.Size_ > capacity()) {
            Vector tmp(other);
            swap(tmp);
        } else {
            for (size_t i = 0; i < Size_ && i < other.Size_; ++i) {
                Data_[i] = other.Data_[i];
            }
            if (Size_ < other.Size_) {
                std::uninitialized_copy_n(other.Data_.buf + Size_,
                                          other.Size_ - Size_, Data_.buf);
            } else if (Size_ > other.Size_) {
                std::destroy_n(Data_.buf + other.Size_, Size_ - other.Size_);
            }
            Size_ = other.Size_;
        }
        return *this;
    }

    size_t capacity() const {
        return Data_.Capacity_;
    }

    size_t size() const {
        return Size_;
    }

    void reserve(size_t size) {
        if (capacity() < size) {
            RawMemory new_data(size);
            std::uninitialized_move_n(Data_.buf, Size_, new_data.buf);
            std::destroy_n(Data_.buf, Size_);
            Data_.Swap(new_data);
        }
    }

    ~Vector() {
        std::destroy_n(Data_.buf, Size_);
    }

    void resize(size_t size) {
        reserve(size);
        if (Size_ < size) {
            std::uninitialized_value_construct_n(Data_ + Size_, size - Size_);
        } else if (Size_ > size) {
            std::destroy_n(Data_ + size, Size_ - size);
        }
        Size_ = size;
    }

    void push_back(const int& elem) {
        if (Size_ == Data_.Capacity_) {
            reserve(Size_ == 0 ? 1 : Size_ * 2);
        }
        new (Data_ + Size_) int(elem);
        ++Size_;
    }

    void push_back(int&& elem) {
        if (Size_ == Data_.Capacity_) {
            reserve(Size_ == 0 ? 1 : Size_ * 2);
        }
        new (Data_ + Size_) int(std::move(elem));
        ++Size_;
    }

    void pop_back() {
        std::destroy_at(Data_ + Size_ - 1);
        --Size_;
    }

    void clear() {
        std::destroy_n(Data_ + 0, Size_);
        Size_ = 0;
    }

    void swap(Vector& other) noexcept {
        Data_.Swap(other.Data_);
        std::swap(Size_, other.Size_);
    }

    int* begin() {
        return Data_ + 0;
    }

    const int* begin() const {
        return Data_ + 0;
    }

    int* end() {
        return Data_ + Size_;
    }

    const int* end() const {
        return Data_ + Size_;
    }

    int& operator[](size_t i) {
        return Data_[i];
    }

    const int& operator[](size_t i) const {
        return Data_[i];
    }
};


int main() {
    return 0;
}