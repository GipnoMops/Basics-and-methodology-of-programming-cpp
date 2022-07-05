#include <iostream>

// Это исключение нужно генерировать в функции value
// при обращении к пустому объекту Optional
struct BadOptionalAccess {
};

template <typename T>
class Optional {
private:
    // alignas нужен для правильного выравнивания блока памяти
    alignas(T) unsigned char data[sizeof(T)];
    bool defined = false;

public:
    Optional() = default;

    Optional(const T& elem) {
        T* value = new (data) T(elem);
    }

    /*Optional(T&& elem);
    Optional(const Optional& other);

    Optional& operator=(const Optional& other);
    Optional& operator=(const T& elem);
    Optional& operator=(T&& elem);

    bool has_value() const;

    T& operator*();
    const T& operator*() const;

    T* operator->();
    const T* operator->() const;*/

    T& value() {
        return *reinterpret_cast<T*>(data);
    }
    /*const T& value() const;

    void reset();

    ~Optional();*/
};

int main() {
    Optional<int> a(42);
    std::cout << a.value();
    return 0;
}