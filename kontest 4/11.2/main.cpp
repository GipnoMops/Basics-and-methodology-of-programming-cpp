#include <iostream>
#include <vector>

template <typename InIter, typename OutIter>
OutIter ReverseCopy(InIter first, InIter last, OutIter out) {
    --last;
    while (last != first) {
        *(out++) = *last;
        --last;
    }
    *(out++) = *last;
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
    std::vector<int> v2, v1 = {1, 2, 3, 4, 5, 6};
    v2.resize(6);
    reverse_copy(v1.begin(), v1.end(), v2.begin());
    //ReverseCopy(v1.begin(), v1.end(), v2.begin());
    std::cout << v1.size() << " " << v2.size() << " ";
    /*for (auto& i : v2) {
        std::cout << i << " ";
    }*/
    auto k = v1.end();
    std::cout << *--k << " " << *--k << " " << *--k << " " << *v1.begin();
    return 0;
}
