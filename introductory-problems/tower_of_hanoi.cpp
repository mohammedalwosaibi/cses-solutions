#include <iostream>
using namespace std;

void move(int n, int src, int aux, int dest) {
    if (n == 1) { cout << src << " " << dest << "\n"; return; }

    move(n - 1, src, dest, aux);
    cout << src << " " << dest << '\n';
    move(n - 1, aux, src, dest);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";

    move(n, 1, 2, 3);

    return 0;
}