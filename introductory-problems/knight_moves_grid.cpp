#include <iostream>
#include <vector>
#include <cstddef>
#include <queue>
#include <array>
#include <utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const array<int, 8> dr = {-2, -2, -1, 1, 2, 2, 1, -1};
    const array<int, 8> dc = {-1, 1, 2, 2, 1, -1, -2, -2};

    vector<vector<int>> grid(static_cast<size_t>(n), vector<int>(static_cast<size_t>(n), -1));

     auto at = [&](int row, int col) -> int& {
        return grid[static_cast<size_t>(row)][static_cast<size_t>(col)];
    };

    queue<pair<int, int>> q;

    at(0, 0) = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (size_t i = 0; i < 8; i++) {
            int next_row = row + dr[i];
            int next_col = col + dc[i];

            if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n && at(next_row, next_col) == -1) {
                at(next_row, next_col) = at(row, col) + 1;
                q.push({next_row, next_col});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << at(i, j) << " ";
        }
        cout << "\n";
    }

    return 0;
}