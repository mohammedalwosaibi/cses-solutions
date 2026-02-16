#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n;
    cin >> n;

    while (n != 1) {
        cout << n << " ";

        if ((n & 1) == 0) n >>= 1;
        else n = 3 * n + 1;
    }

    cout << "1\n";
    return 0;
}