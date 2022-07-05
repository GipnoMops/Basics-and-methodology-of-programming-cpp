#include <iostream>

template <typename InIter, typename OutIter, typename Predicate>
OutIter RemoveCopyIf(InIter first, InIter last, OutIter out, Predicate f) {
    for (; first != last; ++first) {
        if (!f(*first)) {
            ++out;
            *out = *first;
        }
    }
    return out;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
