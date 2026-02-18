#include <iostream>
using namespace std;

void test_case() {
    int a, b;
    cin >> a >> b;

    if (a > 2 * b || b > 2 * a || (a + b) % 3 != 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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