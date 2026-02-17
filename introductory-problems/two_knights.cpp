#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        int board_size = k * k;

        long long total_combs = 1ull * board_size * (board_size - 1) / 2;
        long long invalid_combs = 4ull * (k - 1) * (k - 2);

        cout << total_combs - invalid_combs << "\n";
    }

    return 0;
}