#include <iostream>
#include <vector>
#include <cstddef>
#include <array>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(static_cast<size_t>(n));

    auto at = [&](int r, int c) -> char& {
        return grid[static_cast<size_t>(r)][static_cast<size_t>(c)];
    };

    for (int i = 0; i < n; i++) {
            cin >> grid[static_cast<size_t>(i)];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char original_char = at(i, j);
            char up_char = i > 0 ? at(i - 1, j) : '\0';
            char left_char = j > 0 ? at(i, j - 1) : '\0';

            for (char k = 'A'; k <= 'D'; k++) {
                if (k != original_char and k != up_char and k != left_char) {
                    at(i, j) = k;
                    break;
                }
            }
        }
    }

    for (const string& row : grid) {
        cout << row << "\n";
    }

    return 0;
}