#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    long long total = 1ull * n * (n + 1) / 2;

    if ((total & 1) != 0) {
        cout << "NO\n";
        return 0;
    }

    total /= 2;

    vector<int> arr_1;
    vector<int> arr_2;

    long long sum_1 = 0;
    long long sum_2 = 0;

    for (int i = n; i > 0; i--) {
        if (sum_1 + i <= total) {
            sum_1 += i;
            arr_1.push_back(i);
        } else {
            sum_2 += i;
            arr_2.push_back(i);
        }
    }

    cout << "YES\n";
    cout << arr_1.size() << "\n";
    for (int i : arr_1) cout << i << " ";
    cout << "\n" << arr_2.size() << "\n";
    for (int i : arr_2) cout << i << " ";

    return 0;
}