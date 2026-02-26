#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;

    for (int i = 0; i < n; i++) {
        int ticket;
        cin >> ticket;
        tickets.insert(ticket);
    }

    for (int i = 0; i < m; i++) {
        int bid;
        cin >> bid;

        auto it = tickets.upper_bound(bid);

        if (it == tickets.begin()) {
            cout << -1 << "\n";
        } else {
            it--;

            cout << *it << "\n";

            tickets.erase(it);
        }
    }

    return 0;
}