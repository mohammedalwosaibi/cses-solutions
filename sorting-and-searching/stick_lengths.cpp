#include <iostream>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    vector<int> lengths(n);

    for (size_t i = 0; i < n; i++) cin >> lengths[i];

    size_t mid = n  / 2;

    nth_element(lengths.begin(), lengths.begin() + static_cast<ptrdiff_t>(mid), lengths.end());

    int common_length = lengths[mid];

    long long cost = 0;

    for (size_t i = 0; i < n; i++) {
        cost += abs(common_length - lengths[i]);
    }

    cout << cost << "\n";

    return 0;
}