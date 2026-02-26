#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    vector<int> nums_arr(n);

    for (size_t i = 0; i < n; i++) {
        int num;
        cin >> num;

        nums_arr[i] = num;
    }

    int unique = 1;

    sort(nums_arr.begin(), nums_arr.end());

    for (size_t i = 1; i < n; i++) {
        if (nums_arr[i] != nums_arr[i - 1]) unique++;
    }

    cout << unique << "\n";

    return 0;
}