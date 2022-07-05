#include <iostream>
#include <algorithm>
#include <vector>

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out) {
    while (first1 != last1) {
        if (first2 == last2) {
            return std::copy(first1, last1, out);
        }
        if (*first1 < *first2) {
            *out++ = *first1++;
        } else if (*first2 == *first1) {
            ++first1;
            ++first2;
        } else {
            ++first2;
        }
    }
    return out;
}


int main() {
    std::vector<int> v1 = {2, 4, 5}, v2 = {1, 2, 3}, v3, v4;
    /*auto k = SetDifference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for (auto i = v3.begin(); i != k; ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
    for (auto& i : v3) {
        std::cout << i << " ";
    }
    std::cout << "\n";*/

    auto k = std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    for (auto i = v3.begin(); i != k; ++i) {
        std::cout << *i << " ";
    }
    return 0;
}
