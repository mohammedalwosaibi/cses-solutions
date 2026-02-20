#include <iostream>
#include <array>
#include <string>
#include <cstddef>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<string, 8> grid;

    for (string& s : grid) {
        cin >> s;
    }

    int total_ways = 0;
    array<bool, 8> cols{};
    array<bool, 15> main_diag{};
    array<bool, 15> anti_diag{};

    auto backtrack = [&](const auto& self, size_t row) {
        if (row == 8) { total_ways++; return; }

        for (size_t col = 0; col < 8; col++) {
            if (grid[row][col] == '.' && !cols[col] && !main_diag[row + 7 - col] && !anti_diag[row + col]) {
                cols[col] = true;
                main_diag[row + 7 - col] = true;
                anti_diag[row + col] = true;
                self(self, row + 1);
                cols[col] = false;
                main_diag[row + 7 - col] = false;
                anti_diag[row + col] = false;
            }
        }
    };

    backtrack(backtrack, 0);

    cout << total_ways << "\n";

    return 0;
}