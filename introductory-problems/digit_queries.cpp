#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

void test_case() {
    long long idx;
    cin >> idx;

    int num_of_digits = 1;
    long long count = 9;

    while (true) {
        if (idx > num_of_digits * count) {
            idx -= num_of_digits * count;
            num_of_digits++;
            count *= 10;
        } else {
            long long base = count / 9;
            long long skip = (idx - 1) / num_of_digits;
            long long num = base + skip;
            int position = (idx - 1) % num_of_digits;
            cout << to_string(num)[static_cast<size_t>(position)] << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        test_case();
    }

    return 0;
}