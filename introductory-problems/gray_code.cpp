#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> res = {"0", "1"};

    for (int i = 2; i <= n; i++) {
        for (int j = (int) res.size() - 1; j >= 0; j--) {
            res.push_back(res[j] + '1');
            res[j].push_back('0');
        }
    }

    for (string str : res) cout << str << "\n";

    return 0;
}