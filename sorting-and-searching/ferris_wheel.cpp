#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    int x;

    cin >> n >> x;

    vector<int> weights(n);

    for (size_t i = 0; i < n; i++) cin >> weights[i];

    sort(weights.begin(), weights.end());

    size_t l = 0, r = n - 1;
    int total = 0;

    while (l < r) {
        if (weights[l] + weights[r] <= x) {
            l++;
            r--;
        } else {
            r--;
        }

        total++;
    }

    if (l == r) total ++;

    cout << total << "\n";

    return 0;
}