#include <iostream>
#include <vector>

template <typename InIter, typename OutIter>
OutIter ReverseCopy(InIter first, InIter last, OutIter out) {
    if (last == first) {
        return out;
    }
    --last;
    while (last != first) {
        *out++ = *last;
        --last;
    }
    *out++ = *last;
    return out;
}

template<class BidirIt, class OutputIt>
OutputIt reverse_copy(BidirIt first, BidirIt last, OutputIt d_first)
{
    while (first != last) {
        *(d_first++) = *(--last);
    }
    return d_first;
}

int main() {
    std::vector<int> v2, v1 = {1, 2, 3, 4, 5, 6}, v3;
    v2.resize(6);
    v3.resize(6);
    auto k = v1.end();
    --k;
    --k;
    --k;
    --k;
    --k;
    --k;
    std::cout << (reverse_copy(v1.begin(), ++k, v3.begin()) == ReverseCopy(v1.begin(), ++k, v2.begin())) << "\n";
    for (auto& i : v2) {
        std::cout << i << " ";
    }
    return 0;
}
