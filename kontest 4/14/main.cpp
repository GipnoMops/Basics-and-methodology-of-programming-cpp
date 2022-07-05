#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

struct Star {
    std::string name;
    uint64_t age;
};


std::string FindStar(const std::vector<Star>& stars) {
    std::map<std::string, uint64_t> max_size_of_stars_map;
    for (const auto& i : stars) {
        if (max_size_of_stars_map[i.name] < i.age) {
            max_size_of_stars_map[i.name] = i.age;
        }
    }

    std::vector<Star> max_size_of_stars_v;
    Star star;
    for (auto& [key, value] : max_size_of_stars_map) {
        star.name = key;
        star.age = value;
        max_size_of_stars_v.push_back(star);
    }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
