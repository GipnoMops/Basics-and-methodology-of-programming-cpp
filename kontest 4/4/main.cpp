#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> player1, player2;
    int card;

    for (size_t i = 0; i < 5; ++i) {
        cin >> card;
        player1.push_back(card);
    }

    for (size_t i = 0; i < 5; ++i) {
        cin >> card;
        player2.push_back(card);
    }

    size_t moves = 0;

    while (!player1.empty() && !player2.empty() && moves < 1000000) {
        if ((player1[0] == 0 && player2[0] == 9)
        || (player1[0] > player2[0] && !(player1[0] == 9 && player2[0] == 0))) {
            player1.push_back(player1[0]);
            player1.push_back(player2[0]);
            player2.pop_front();
            player1.pop_front();
        } else {
            player2.push_back(player1[0]);
            player2.push_back(player2[0]);
            player1.pop_front();
            player2.pop_front();
        }
        ++moves;
    }

    if (player1.empty()) {
        cout << "second " << moves << "\n";
    } else if (player2.empty()) {
        cout << "first " << moves << "\n";
    } else if (moves > 1000000) {
        cout << "botva\n";
    }

    return 0;
}
