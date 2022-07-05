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
    std::unique_ptr<int> address = nullptr;
    for (auto elem : data)
        out.write(reinterpret_cast<const char*>(&elem), sizeof(elem));
}

void Model::load(std::istream& in) {
    data.clear();
    data.resize(static_cast<size_t>(sizeof(in) / 4));
    int elem;
    for (size_t i = 0; i < static_cast<size_t>(sizeof(in) / 4); ++i) {
        in.read(reinterpret_cast<char*>(&elem), sizeof(elem));
        data[i] = elem;
    }
}


int main() {
    // заклинание для ускорения потокового ввода-вывода
    std::ios::sync_with_stdio(false);

    Model m1;

    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    m1.data = v;

    // как-то заполняем m1.data случайными числами

    std::stringstream ss;  // записываем данные не в файл, а просто в память (в строку)
    m1.save(ss);

    Model m2;
    m2.load(ss);

    if (m1.data != m2.data)
        std::cout << "Models differ\n";
}
