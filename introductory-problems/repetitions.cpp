#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    size_t cur_length = 1;
    size_t max_length = 1;

    for (size_t i = 1; i < str.size(); i++) {
        if (str[i] == str[i - 1]) cur_length += 1;
        else {
            max_length = max(max_length, cur_length);
            cur_length = 1;
        }
    }

    max_length = max(max_length, cur_length);
    cout << max_length << "\n";

    return 0;
}