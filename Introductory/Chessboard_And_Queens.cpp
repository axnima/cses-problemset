#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

vector<pair<int, int>> steps = {{-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

bool is_valid(int i, int j) {
    if (i < 8 && i >= 0 && j < 8 && j >= 0) {
        return true;
    }
    return false;
}

int board[8][8];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                board[i][j] = 0;
            } else {
                board[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    int perm[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    do {
        bool wrong = false;
        for (int j = 0; j < 8; j++) {
            if (board[j][perm[j]] == 1) {
                wrong = true;
                break;
            }
            board[j][perm[j]] = 2;
        }
        if (wrong == true) {
            for (int j = 0; j < 8; j++) {
                if (board[j][perm[j]] == 2) {
                    board[j][perm[j]] = 0;
                }
            }
            continue;
        }
        for (int i = 0; i < 8; i++) {
            for (auto j : steps) {
                int x = i + j.first;
                int y = perm[i] + j.second;
                while (is_valid(x, y)) {
                    if (board[x][y] == 2) {
                        wrong = true;
                        break;
                    }
                    x += j.first;
                    y += j.second;
                }
                if (wrong) {
                    break;
                }
            }
            if (wrong) {
                break;
            }
        }
        if (!wrong) {
            cnt++;
        }
        for (int j = 0; j < 8; j++) {
            if (board[j][perm[j]] == 2) {
                board[j][perm[j]] = 0;
            }
        }
    } while (next_permutation(perm, perm + 8));
    cout << cnt << "\n";
    return 0;
}
