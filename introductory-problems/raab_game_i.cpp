#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

void test_case() {
    int n, a, b;
    cin >> n >> a >> b;

    if (a + b > n or (a > 0 and b == 0) or (b > 0 and a == 0)) {
        cout << "NO\n";
        return;
    }

    int ties = n - (a + b);

    vector<int> p1_path;
    vector<int> p2_path;

    for (int i = 1; i <= ties; i++) {
        p1_path.push_back(i);
        p2_path.push_back(i);
    }

    for (int i = 1; i <= a + b; i++) {
        p1_path.push_back(i + ties);
    }

    for (int i = 1; i <= b; i++) {
        p2_path.push_back(i + ties + a);
    }

    for (int i = 1; i <= a; i++) {
        p2_path.push_back(i + ties);
    }

    cout << "YES\n";

    for (int i = 0; i < n; i++) cout << p1_path[static_cast<size_t>(i)] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << p2_path[static_cast<size_t>(i)] << " ";
    cout << "\n";
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