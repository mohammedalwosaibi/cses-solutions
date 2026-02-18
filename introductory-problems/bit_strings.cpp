#include <iostream>
using namespace std;

constexpr int MOD = 1'000'000'007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int exp;
    cin >> exp;
    
    long long answer = 1;
    long long base = 2;

    while (exp) {
        if ((exp & 1) == 1) answer = (answer * base) % MOD;

        base = (base * base) % MOD;
        exp /= 2;
    }

    cout << answer << "\n";

    return 0;
}