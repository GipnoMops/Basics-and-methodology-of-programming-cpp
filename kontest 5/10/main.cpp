#include <iostream>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
private:
    Container conteiner_;

public:
    T front() const {
        return conteiner_.back();
    }

    T& front() {
        return conteiner_.back();
    }

    void push(const T& elem) {
        conteiner_.push_front(elem);
    }

    void pop() {
        conteiner_.pop_back();
    }

    size_t size() const {
        return conteiner_.size();
    }

    bool empty() const {
        return conteiner_.size() == 0;
    }

    bool operator == (const Queue& other) const {
        return conteiner_ == other.conteiner_;
    }

    bool operator != (const Queue& other) const {
        return conteiner_ != other.conteiner_;
    }
};

int main() {
    Queue<int, std::deque<int>> q, p;
    q.push(3);
    q.push(4);
    p.push(4);
    std::cout << q.front();
    q.pop();
    std::cout << q.front();
    return 0;
}
