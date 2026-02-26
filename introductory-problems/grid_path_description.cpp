#include <iostream>
#include <string>
#include <array>
using namespace std;

array<array<bool, 9>, 9> visited;
array<int, 48> moves;
array<int, 4> dr = {-1, 0, 0, 1};
array<int, 4> dc = {0, 1, -1, 0};
int paths = 0;

void solve(int r, int c, int move) {
    if (r == 7 && c == 1) {
        if (move == 48) paths++;
        return;
    }

    if (visited[r + 1][c] && visited[r - 1][c] && !visited[r][c - 1] && !visited[r][c + 1]) {
        return;
    }

    if (!visited[r + 1][c] && !visited[r - 1][c] && visited[r][c - 1] && visited[r][c + 1]) {
        return;
    }

    visited[r][c] = true;
    int dir = moves[move];

    if (dir != -1) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (!visited[nr][nc]) solve(nr, nc, move + 1);
    } else {
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (!visited[nr][nc]) solve(nr, nc, move + 1);
        }
    }

    visited[r][c] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    for (int i = 0; i < 9; i++) {
        visited[i][0] = true;
        visited[i][8] = true;
        visited[0][i] = true;
        visited[8][i] = true;
    }

    for (int i = 0; i < 48; i++) {
        char c = str[i];
        if (c == '?') moves[i] = -1;
        else if (c == 'U') moves[i] = 0;
        else if (c == 'R') moves[i] = 1;
        else if (c == 'L') moves[i] = 2;
        else if (c == 'D') moves[i] = 3;
    }

    solve(1, 1, 0);

    cout << paths << "\n";

    return 0;
}