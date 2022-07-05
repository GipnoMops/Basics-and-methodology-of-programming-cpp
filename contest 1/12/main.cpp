#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int num;
    vector<int> sequence_1;
    vector<int> sequence_2(n);

    while (cin >> num && num != -1) {
        sequence_1.push_back(num);
    }

    for (size_t i = 0; i < n; ++i) {
        sequence_2[sequence_1[i] - 1] = i + 1;
    }

    for (int i : sequence_2) {
        cout << i << " ";
    }

    return 0;
}
