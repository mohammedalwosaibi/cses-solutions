#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n;
    cin >> n;

    unsigned long long total = 0;

    for (unsigned int i = 0; i < n - 1; i++) {
        unsigned int cur;
        cin >> cur;
        total += cur;
    }

    unsigned long long sum_to_n = 1ull * n * (n + 1) / 2;

    cout << sum_to_n - total << "\n";

    return 0;
}