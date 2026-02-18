#include <iostream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    array<int, 26> freq;
    freq.fill(0);

    for (char c : str) {
        freq[c - 'A']++;
    }

    int odd_count = 0;
    char odd_char = '\0';

    for (int i = 0; i < 26; i++) {
        if ((freq[i] & 1) == 1) {
            odd_count++;
            odd_char = 'A' + i;
        }
    }

    if (odd_count > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string left_half = "";

    for (int i = 0; i < 26; i++) {
        left_half += string(freq[i] / 2, i + 'A');
    }

    string right_half = left_half;
    reverse(right_half.begin(), right_half.end());

    cout << left_half;
    if (odd_count) cout << odd_char;
    cout << right_half << "\n";
}