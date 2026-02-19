#include <iostream>
#include <vector>
#include <climits>
using namespace std;

static void backtrack(long long& min_dif, long long& sum_1, long long& sum_2, vector<int>& weights, size_t idx) {
    if (idx == weights.size()) {
        min_dif = min(min_dif, abs(sum_1 - sum_2));
        return;
    }

    int weight = weights[idx];

    sum_1 += weight;
    backtrack(min_dif, sum_1, sum_2, weights, idx + 1);
    sum_1 -= weight;

    sum_2 += weight;
    backtrack(min_dif, sum_1, sum_2, weights, idx + 1);
    sum_2 -= weight;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> weights;

    int cur_weight;

    for (int i = 0; i < n; i++) {
        cin >> cur_weight;
        weights.push_back(cur_weight);
    }

    long long sum_1 = 0;
    long long sum_2 = 0;

    long long min_dif = LLONG_MAX;

    backtrack(min_dif, sum_1, sum_2, weights, 0);

    cout << min_dif << "\n";

    return 0;
}