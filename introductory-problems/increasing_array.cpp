#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n;
    cin >> n;

    unsigned long long moves = 0;

    unsigned int prev;
    cin >> prev;

    for (unsigned int i = 1; i < n; i++) {
        unsigned int cur;
        cin >> cur;

        if (cur < prev) moves += prev - cur;
        else prev = cur;
    }

    cout << moves << "\n";

    return 0;
}