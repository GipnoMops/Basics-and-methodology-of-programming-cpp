#include <iostream>
#include <vector>

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) {
        return first;
    }
    Iter result = first;
    while (++first != last) {
        while (first != last && *result == *first) {
            ++first;
        }
        if (first != last) {
            *++result = *first;
        } else {
            --first;
            //*++result = *--first;
        }
    }
    return ++result;
}

template<class ForwardIt>
ForwardIt unique(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return last;

    ForwardIt result = first;
    while (++first != last) {
        if (*result != *first && ++result != first) {
            *result = std::move(*first);
        }
    }
    return ++result;
}

int main() {
    std::vector<int> a = {};
    auto last = Unique(a.begin(), a.end());
    auto first = a.begin();
    for (; first != last; ++first) {
        std::cout << *first << " ";
    }
    return 0;
}
