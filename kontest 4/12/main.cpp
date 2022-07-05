#include <iostream>

template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter TransformIf(InIter first, InIter last, OutIter out, Predicate condition, Action f) {
    for( ; first != last; ++first) {
        if (condition(*first)) {
            *out++ = f(*first);
        }
    }
    return out;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
