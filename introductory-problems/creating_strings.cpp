#include <iostream>
#include <cstddef>
#include <string>
#include <array>
using namespace std;

static int fact(int n) {
    if (n == 0 || n == 1) return 1;

    return n * fact(n - 1);
}

static void build(int n, string& builder, array<int, 26>& freq) {
    if ((int) builder.size() == n) { cout << builder << "\n"; return; }

    for (size_t i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            builder.push_back(static_cast<char>(i) + 'a');
            freq[i]--;
            build(n, builder, freq);
            freq[i]++;
            builder.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 26> freq{};

    string str;
    cin >> str;

    int n = (int) str.size();

    for (char c : str) freq[static_cast<size_t>(c - 'a')]++;

    int num_of_strings = fact(n);

    for (int count : freq) num_of_strings /= fact(count);

    cout << num_of_strings << "\n";

    string builder = "";

    build(n, builder, freq);

    return 0;
}