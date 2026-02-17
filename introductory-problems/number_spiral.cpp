#include <iostream>
using namespace std;

void test_case() {
    int row, col;
    cin >> row >> col;

    int layer = max(row, col);

    if ((layer & 1) == 0) {
        if (row < col) {
            cout << 1ull * (layer - 1) * (layer - 1) + row << "\n";
        } else {
            cout << 1ull * layer * layer - col + 1 << "\n";
        }
    } else {
        if (row < col) {
            cout << 1ull * layer * layer - row + 1 << "\n";
        } else {
            cout << 1ull * (layer - 1) * (layer - 1) + col << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        test_case();
    }

    return 0;
}