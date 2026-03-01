#include <iostream>
#include <cstddef>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    vector<int> coins(n);

    for (size_t i = 0; i < n; i++) cin >> coins[i];

    sort(coins.begin(), coins.end());

    long long target = 1;

    for (int coin : coins) {
        if (coin > target) break;
        target += coin;
    }

    cout << target << "\n";

    return 0;
}