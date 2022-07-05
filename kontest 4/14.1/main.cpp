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
    std::sort(max_size_of_stars_v.begin(), max_size_of_stars_v.end(),
              [](const Star& star1, const Star& star2) {
                  if (star1.age != star2.age) {
                      return star1.age < star2.age;
                  } else {
                      return star1.name < star2.name;
                  } });

    size_t k = max_size_of_stars_v.size() / 2;
    std::string answer = max_size_of_stars_v[k].name;
    while (k > 0 && max_size_of_stars_v[k].age == max_size_of_stars_v[k - 1].age) {
        k--;
        answer = max_size_of_stars_v[k].name;
    }
    return answer;
}

int main() {
    Star star1 = {"one", 1}, star2 = {"two", 2}, star3 = {"three", 3};
    Star star4 = {"fore", 2}, star5 = {"five", 100};
    std::vector<Star> stars = {
            star3,
            star2,
            star1,
            star4,
            star5
    };
    std::cout << FindStar(stars);
    return 0;
}
