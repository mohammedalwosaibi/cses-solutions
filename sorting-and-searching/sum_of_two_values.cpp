#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    int x;
    cin >> n >> x;

    vector<pair<int, int>> nums(n);

    auto val = [&](int idx) -> int {
        return nums[static_cast<size_t>(idx)].first;
    };

    auto pos = [&](int idx) -> int {
        return nums[static_cast<size_t>(idx)].second;
    };

    for (size_t i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = static_cast<int>(i) + 1;
    }

    sort(nums.begin(), nums.end());

    int l = 0, r = static_cast<int>(n) - 1;

    while (l < r) {
        if (val(l) + val(r) == x) {
            cout << pos(l) << " " << pos(r) << "\n";
            return 0;
        } else if (val(l) + val(r) < x) {
            l++;
        } else {
            r--;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}