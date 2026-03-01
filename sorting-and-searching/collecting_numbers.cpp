#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> pos(static_cast<size_t>(n + 1));

    auto at = [&](int idx) -> int& {
        return pos[static_cast<size_t>(idx)];
    };

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        at(num) = i;
    }

    int rounds = 1;

    for (int num = 1; num < n; num++) {
        if (at(num + 1) < at(num)) rounds++;
    }

    cout << rounds << "\n";

    return 0;
}