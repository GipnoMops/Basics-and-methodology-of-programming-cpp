#include <iostream>
#include <cstddef>  // for size_t
#include <iterator>
#include <iterator>

/*#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>*/

/*class Model {
public:
    std::vector<int> data;

    void save(std::ostream& out) const;
    void load(std::istream& in);
};

void Model::save(std::ostream& out) const {
    size_t size_of_data = data.size();
    out.write(reinterpret_cast<const char*>(&size_of_data), sizeof(size_of_data));
    for (auto elem : data) {
        out.write(reinterpret_cast<const char*>(&elem), sizeof(elem));
    }
}

void Model::load(std::istream& in) {
    size_t size_of_new_data = 0;
    in.read(reinterpret_cast<char*>(&size_of_new_data), sizeof(size_of_new_data));
    data.clear();
    data.resize(size_of_new_data);
    int elem;
    for (size_t i = 0; i < size_of_new_data; ++i) {
        in.read(reinterpret_cast<char*>(&elem), sizeof(elem));
        data[i] = elem;
    }
}*/



class RangeError {
};

size_t CountValues(char* data, size_t size) {
    size_t value = 0;
    size_t byte_number = 0;
    size_t* elem = nullptr;
    while (byte_number < size) {
        try {
            elem = reinterpret_cast<size_t*>(data);
            ++value;
            std::advance(data, *elem);
            byte_number += *elem + sizeof(size_t);
            if (byte_number > size) {
                throw;
            }
        } catch (...) {
            throw RangeError();
        }
    }
    return value;
}


int main() {

    std::cout << sizeof(size_t);

    size_t a = 1;
    char* b = reinterpret_cast<char*>(a);
    std::cout << CountValues(b, sizeof(b));

    // заклинание для ускорения потокового ввода-вывода
    /*std::ios::sync_with_stdio(false);

    Model m1;

    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    m1.data = v;

    // как-то заполняем m1.data случайными числами

    std::stringstream ss;  // записываем данные не в файл, а просто в память (в строку)
    m1.save(ss);

    int a = 1;
    const char* s = reinterpret_cast<const char*>(a);

    std::cout << CountValues(s, sizeof(a) + 1) << "\n";*/

    return 0;
}
