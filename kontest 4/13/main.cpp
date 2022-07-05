#include <iostream>
#include <vector>

template <typename It, typename OutputIt>
OutputIt SidewaysMerge(It first1, It last1, It first2, It last2, OutputIt out) {
    if (last2 != first2) {
        --last2;
    }
    while (first1 != last1 && last2 != first2) {
        if (*first1 < *last2) {
            *out++ = *first1;
            ++first1;
        } else {
            *out++ = *last2;
            --last2;
        }
    }
    if (++last2 != first2) {
        --last2;
    }
    if (last2 == first2) {
        while (first1 != last1) {
            *out++ = *first1;
        }
    } else if (first1 == last1) {
        while (first2 != last2) {
            *out++ = *--last2;
        }
    }
    return out;
}

int main() {
    std::vector<int> v1 = {1, 3, 4, 8, 10}, v2 = {9, 7, 6, 5, 2}, v3(10);
    /*SidewaysMerge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for (auto& i : v3) {
        std::cout << i << " ";
    }*/
    auto k = v1.end();
    std::cout << *--k;
    if (++k != v1.begin()) {
        --k;
    }
    return 0;
}
