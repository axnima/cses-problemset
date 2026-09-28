#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
const int mod = 1e9 + 7;

int vis[7][7];
vector<pair<int, int>> m = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int cnt = 0;
int s[48];

bool is_valid(int x, int y) {
    if (x >= 0 && x < 7 && y >= 0 && y < 7 && !vis[x][y])
        return true;
    return false;
}

bool opt(int x, int xc, int y, int yc) {
    int a = abs(yc);
    int b = abs(xc);
    if (!is_valid(x + xc + xc, y + yc + yc) && is_valid(x + xc + a, y + yc + b) &&
        is_valid(x + xc - a, y + yc - b) && is_valid(x + xc, y + yc)) {
        return false;
    }
    if (!is_valid(x + xc + a, y + yc + b) && is_valid(x + a, y + b))
        return false;
    if (!is_valid(x + xc - a, y + yc - b) && is_valid(x - a, y - b))
        return false;
    return true;
}

void dfs(int ind, int x, int y) {
    if (ind == 48 && x == 6 && y == 0) {
        cnt++;
    } else {
        vis[x][y] = true;
        if (s[ind] == 4) {
            for (auto i : m) {
                if (is_valid(x + i.ff, y + i.ss)) {
                    if (opt(x, i.ff, y, i.ss))
                        dfs(ind + 1, x + i.ff, y + i.ss);
                }
            }
        } else {
            int xc, yc;
            switch (s[ind]) {
            case 0:
                xc = 1;
                yc = 0;
                break;
            case 1:
                xc = -1;
                yc = 0;
                break;
            case 2:
                xc = 0;
                yc = -1;
                break;
            case 3:
                xc = 0;
                yc = 1;
            }
            if (is_valid(x + xc, y + yc)) {
                if (!(x + xc == 6 && y + yc == 0 && ind < 47)) {
                    if (opt(x, xc, y, yc))
                        dfs(ind + 1, x + xc, y + yc);
                }
            }
        }
        vis[x][y] = false;
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string st;
    cin >> st;
    for (int i = 0; i < 48; i++) {
        switch (st[i]) {
        case 'D':
            s[i] = 0;
            break;
        case 'U':
            s[i] = 1;
            break;
        case 'L':
            s[i] = 2;
            break;
        case 'R':
            s[i] = 3;
            break;
        case '?':
            s[i] = 4;
        }
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            vis[i][j] = 0;
        }
    }
    dfs(0, 0, 0);
    cout << cnt << "\n";
    return 0;
}
