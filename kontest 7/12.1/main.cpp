#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

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

class Writer {
public:
    virtual void Write(const char* data, size_t len) {
        // Какой-то вывод в файл, на экран или в память
    }
};

class BufferedWriter: Writer {
private:
    size_t size_;
    size_t fullness_ = 0;
    std::stringstream bufer_;

public:
    BufferedWriter(size_t n): size_(n) {}

    void Write(const char* data, size_t len) override {
        size_t num_read = size_ - fullness_;
        bufer_.write(data, std::min(size_ - fullness_, len));
        fullness_ += size_ - fullness_;
        if (fullness_ < size_) {
            return;
        } else {
            Writer::Write(bufer_.str().c_str(), size_);
            bufer_.clear();
            fullness_ = 0;
            std::advance(data, num_read);
            Write(data, len - num_read);
        }
    }

    ~BufferedWriter() {
        if (fullness_ != 0) {
            Writer::Write(bufer_.str().c_str(), sizeof(bufer_));
        }
    }
};

int main() {
    // заклинание для ускорения потокового ввода-вывода
    std::ios::sync_with_stdio(false);

    Model m1;

    // как-то заполняем m1.data случайными числами

    std::stringstream ss;// записываем данные не в файл, а просто в память (в строку)
    m1.save(ss);

    std::cout << sizeof(ss) << "\n";

    auto F = ss.str().c_str();
    std::cout << sizeof(F) << "\n";
    std::advance(F, 1);
    std::cout << sizeof(F) << "\n";

    std::cout << "****" << sizeof(int) << "\n\n";

    struct Type {
        int* data;
    };

    Type a;
    Type b;
    a.data = new int[10000];
    std::cout << sizeof(a) << " " << sizeof(b) << "\n";

    /*Model m2;
    m2.load(ss);

    if (m1.data != m2.data)
        std::cout << "Models differ\n";*/
}
