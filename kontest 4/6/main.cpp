#include <iostream>
#include <vector>
#include <algorithm>

void delete_zeroes(std::vector<int>& numbers) {
    std::vector<int> without_zeros;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(without_zeros));
    numbers = without_zeros;
}

int main() {
    std::vector<int> a = {1, 0, 2, 3, 0, 0, 0, 4, 5, 5, 0, 4, 0};
    delete_zeroes(a);
    for (const auto& i : a) {
        std::cout << i << " ";
    }
    return 0;
}
