#include <fstream>
#include <iostream>
#include <vector>
#include <memory>

#include <iostream>
#include <sstream>

class Model {
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
}


int main() {
    // заклинание для ускорения потокового ввода-вывода
    std::ios::sync_with_stdio(false);

    Model m1;

    std::vector<int> v{1, 2/*, 3, 4, 5, 6, 7, 8, 9, 10, 11*/};

    m1.data = v;

    // как-то заполняем m1.data случайными числами

    std::stringstream ss;  // записываем данные не в файл, а просто в память (в строку)
    std::cout << "*" << sizeof (ss);
    m1.save(ss);
    std::cout << " " << sizeof (ss) << "\n";

    Model m2;
    m2.load(ss);
    std::cout << " " << sizeof (ss) << "\n";

    if (m1.data != m2.data)
        std::cout << "Models differ\n";

    for (auto& elem : m1.data) {
        std::cout << elem << " ";
    }

    std::cout << "\n";

    for (auto& elem : m2.data) {
        std::cout << elem << " ";
    }
}
