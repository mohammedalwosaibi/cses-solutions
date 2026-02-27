#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    long long cur_sum;
    cin >> cur_sum;
    long long max_sum = cur_sum;

    for (size_t i = 1; i < n; i++) {
        long long num;
        cin >> num;

        cur_sum = max(cur_sum + num, num);
        max_sum = max(max_sum, cur_sum);
    }

    cout << max_sum << "\n";

    return 0;
}