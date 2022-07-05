#include <stdexcept>
#include <optional>
#include <memory>
#include <map>
#include <iostream>

template <typename Key1, typename Key2, typename Value>
class BiMap {
private:
    std::map<Key1, std::shared_ptr<Value>> map1_;
    std::map<Key2, std::shared_ptr<Value>> map2_;

public:
    // Вставить значение, указав один или оба ключа.
    // Генерирует исключение std::invalid_argument("some text") в случае,
    // если оба ключа пусты, либо один из ключей уже имеется в хранилище.
    void Insert(const std::optional<Key1>& key1,
                const std::optional<Key2>& key2,
                const Value& value) {
        if (key1 && key2) {
            if (map1_.find(key1.value()) == map1_.end() &&
            map2_.find(key2.value()) == map2_.end()) {
                auto ptr1 = std::make_shared<Value>(value);
                map1_[key1.value()] = ptr1;
                map2_[key2.value()] = ptr1;
                return;
            } else {
                throw std::invalid_argument("some text");
            }
        }

        if (key1 && !key2) {
            if (map1_.find(key1.value()) == map1_.end()) {
                auto ptr1 = std::make_shared<Value>(value);
                map1_[key1.value()] = ptr1;
            } else {
                throw std::invalid_argument("some text");
            }
        }

        if (key2 && !key1) {
            if (map2_.find(key2.value()) == map2_.end()) {
                auto ptr2 = std::make_shared<Value>(value);
                map2_[key2.value()] = ptr2;
            } else {
                throw std::invalid_argument("some text");
            }
        }

        if (!key1 && !key2) {
            throw std::invalid_argument("some text");
        }
    }

    // Получить значение по ключу первого типа.
    // Генерирует исключение std::out_of_range("some text")
    // в случае отсутствия ключа (как и функция at в std::map).
    Value& GetByPrimaryKey(const Key1& key) {
        if (map1_.find(key) != map1_.end()) {
            return *map1_.at(key);
        } else {
            throw std::out_of_range("some text");
        }
    }

    const Value& GetByPrimaryKey(const Key1& key) const {
        if (map1_.find(key) != map1_.end()) {
            return *map1_.at(key);
        } else {
            throw std::out_of_range("some text");
        }
    }

    // Аналогичная функция для ключа второго типа.
    Value& GetBySecondaryKey(const Key2& key) {
        if (map2_.find(key) != map2_.end()) {
            return *map2_.at(key);
        } else {
            throw std::out_of_range("some text");
        }
    }

    const Value& GetBySecondaryKey(const Key2& key) const {
        if (map2_.find(key) != map2_.end()) {
            return *map2_.at(key);
        } else {
            throw std::out_of_range("some text");
        }
    }
};


struct Student {
    std::string Surname, Name;
};

std::ostream& operator << (std::ostream& out, const Student& s) {
    return out << s.Surname << " " << s.Name;
}

int main() {
    BiMap<int, std::string, Student> bimap;  // студента можно определить либо по номеру, либо по логину
    bimap.Insert(42, {}, {"Ivanov", "Ivan"});
    bimap.Insert({}, "cshse-ami-512", {"Petrov", "Petr"});
    bimap.Insert(13, "cshse-ami-999", {"Fedorov", "Fedor"});

    std::cout << bimap.GetByPrimaryKey(42) << "\n";  // Ivanov Ivan

    std::cout << bimap.GetBySecondaryKey("cshse-ami-512") << "\n";  // Petrov Petr

    std::cout << bimap.GetByPrimaryKey(13) << "\n";  // Fedorov Fedor
    std::cout << bimap.GetBySecondaryKey("cshse-ami-999") << "\n";  // Fedorov Fedor

    bimap.GetByPrimaryKey(13).Name = "Oleg";  // меняем значение по первичному ключу - по вторичному оно тоже должно измениться
    std::cout << bimap.GetByPrimaryKey(13) << "\n";  // Fedorov Oleg
    std::cout << bimap.GetBySecondaryKey("cshse-ami-999") << "\n";  // Fedorov Oleg
    return 0;
}
