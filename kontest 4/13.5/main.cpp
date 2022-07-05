#include <iostream>
#include <vector>

template <typename It, typename OutputIt>
OutputIt SidewaysMerge(It first1, It last1, It first2, It last2, OutputIt out) {
    if (last2 != first2) {
        --last2;
    } else {
        while (first1 != last1) {
            *out++ = *first1;
            ++first1;
        }
        return out;
    }

    while (first1 != last1) {
        if (*first1 < *last2) {
            *out++ = *first1;
            ++first1;
        } else {
            *out++ = *last2;
            if (last2 == first2) {
                break;
            } else {
                --last2;
            }
        }
    }

    if (first1 == last1) {
        while (first2 != last2) {
            *out++ = *last2;
            --last2;
        }
        *out++ = *last2;
    } else if (last2 == first2) {
        while (first1 != last1) {
            *out++ = *first1;
            ++first1;
        }
    }
    return out;
}

int main() {
    std::vector<int> v1 = {1, 2, 3, 8, 11}, v2 = {}, v3(10);
    SidewaysMerge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for (auto& i : v3) {
        std::cout << i << " ";
    }
    return 0;
}
