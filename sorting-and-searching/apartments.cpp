#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, m;
    int k;
    cin >> n >> m >> k;

    vector<int> applicants(n);
    vector<int> apartments(m);

    for (size_t i = 0; i < n; i++) cin >> applicants[i];

    for (size_t i = 0; i < m; i++) cin >> apartments[i];

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    size_t i = 0, j = 0;
    int total = 0;

    while (i < n && j < m) {
        if (abs(applicants[i] - apartments[j]) <= k) {
            i++;
            j++;
            total++;
        } else if (applicants[i] < apartments[j]) i++;
        else j++;
    }

    cout << total << "\n";

    return 0;
}