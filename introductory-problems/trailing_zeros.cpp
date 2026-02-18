#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int trailing_zeros = 0;

    while (n) {
        n /= 5;
        trailing_zeros += n;
    }

    cout << trailing_zeros << "\n";

    return 0;
}