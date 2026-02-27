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

    vector<int> starts(n);
    vector<int> ends(n);

    for (size_t i = 0; i < n; i++) {
        cin >> starts[i];
        cin >> ends[i];
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int max_customers = 0;
    int cur_customers = 0;

    size_t s = 0, e = 0;

    while (s < n) {
        if (starts[s] < ends[e]) {
            cur_customers++;
            max_customers = max(max_customers, cur_customers);
            s++;
        } else {
            cur_customers--;
            e++;
        }
    }

    cout << max_customers << "\n";

    return 0;
}