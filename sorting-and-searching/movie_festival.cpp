#include <iostream>
#include <utility>
#include <vector>
#include <cstddef>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    vector<pair<int, int>> movies(n);

    for (size_t i = 0; i < n; i++) {
        cin >> movies[i].second;
        cin >> movies[i].first;
    }

    sort(movies.begin(), movies.end());

    int last_end = 0;
    int total_movies = 0;

    for (size_t i = 0; i < n; i++) {
        if (movies[i].second >= last_end) {
            total_movies++;
            last_end = movies[i].first;
        }
    }

    cout << total_movies << "\n";

    return 0;
}