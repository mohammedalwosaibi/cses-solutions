#include <iostream>
#include <string>
#include <array>
#include <cstddef>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    array<int, 26> freq{};
    int max_freq = 0;

    for (char c : str) {
        size_t idx = static_cast<size_t>(c - 'A');
        max_freq = max(max_freq, ++freq[idx]);
    }

    int n = static_cast<int>(str.size());

    if (max_freq > (n + 1) / 2) {
        cout << -1 << "\n";
        return 0;
    }

    string res = "";
    res.reserve(str.size());
    int remaining_chars = n;

    for (int i = 0; i < n; i++) {
        size_t char_idx = 26;

        for (size_t j = 0; j < 26; j++) {
            if (freq[j] > remaining_chars / 2) {
                char_idx = j;
                break;
            }
        }

        if (char_idx == 26) {
            for (size_t j = 0; j < 26; j++) {
                if (freq[j] > 0) {
                    if (!res.empty() and res.back() == static_cast<char>('A' + j)) continue;
                    char_idx = j;
                    break;
                }
            }
        }

        res.push_back(static_cast<char>('A' + char_idx));
        freq[char_idx]--;
        remaining_chars--;
    }

    cout << res << "\n";

    return 0;
}