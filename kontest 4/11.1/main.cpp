#include <iostream>
#include <vector>

template <typename InIter, typename OutIter>
OutIter ReverseCopy(InIter first, InIter last, OutIter out) {
    --last;
    while (last != first) {
        *out++ = *last;
        --last;
    }
    *out++ = *last;
    return out;
}

int main() {
    std::vector<int> v2, v1 = {1, 2 , 3, 4, 5, 6};
    std::cout << *ReverseCopy(v1.begin(), v1.end(), v2.begin()) << " ";
    std::cout << v1.size() << " " << v2.size() << " ";
    for (auto& i : v2) {
        std::cout << i << " ";
    }
    return 0;
}
