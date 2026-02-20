#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    vector<vector<bool>> nums_in_row(n, vector<bool>(128));
    vector<vector<bool>> nums_in_col(n, vector<bool>(128));

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            size_t num = 0;
            for (size_t k = 0; k < 128; k++) {
                if (!nums_in_row[i][k] and !nums_in_col[j][k]) {
                    num = k;
                    break;
                }
            }
            cout << num << " ";
            nums_in_row[i][num] = true;
            nums_in_col[j][num] = true;
        }
        cout << "\n";
    }

    return 0;
}