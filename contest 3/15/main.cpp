#include <iostream>
#include <deque>
#include <tuple>

using namespace std;

pair<int, int> min_and_quantity(deque<int>& d) {
    int min_elem = d[0], quantity = 0;
    pair<int, int> min_and_quant(d[0], 0);
    for (const int& i : d) {
        if (i < min_and_quant.first) {
            min_and_quant.first = i;
            min_and_quant.second = 1;
        } else if (i == min_and_quant.first) {
            ++min_and_quant.second;
        }
    }
    return min_and_quant;
}

int main() {
    size_t n_num, k_wind;
    cin >> n_num >> k_wind;
    pair<int, int> min_in_wind_and_kol_min;
    deque<int> window;
    int num;
    for (size_t i = 0; i < k_wind; ++i) {
        cin >> num;
        window.push_back(num);
    }
    min_in_wind_and_kol_min = min_and_quantity(window);
    cout << min_in_wind_and_kol_min.first << "\n";

    cout << "\n";
    for (auto& h : window) {
        cout << h << " ";
    }
    cout << "\n";

    for (size_t i = 0; i < n_num - k_wind; ++i) {
        if (window[0] == min_in_wind_and_kol_min.first && min_in_wind_and_kol_min.second == 1) {
            window.pop_front();
            cin >> window[k_wind];
            min_in_wind_and_kol_min = min_and_quantity(window);
        } else if (window[0] == min_in_wind_and_kol_min.first && min_in_wind_and_kol_min.second > 1) {
            --min_in_wind_and_kol_min.second;
            window.pop_front();
            cin >> window[k_wind];
        }
        cout << min_in_wind_and_kol_min.first << "\n";

        cout << "\n";
        for (auto& h : window) {
            cout << h << " ";
        }
        cout << "\n";

    }
    return 0;
}
