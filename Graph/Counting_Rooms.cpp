#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 0e9 + 7;
int r, c;
vector<vector<bool>> vis;
int rooms = 0;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool is_valid(int y, int x) //used to check if a cell is valid
{
    if (x < 0 || x >= c || y < 0 || y >= r) {
        return 0;
    }
    if (vis[y][x]) {
        return 0;
    }
    return 1;
}

void dfs(int n, int m) {
    vis[n][m] = true;
    for (auto p : moves) {
        if (is_valid(n + p.first, m + p.second)) {
            dfs(n + p.first, m + p.second);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    vis.resize(r);
    for (int i = 0; i < r; i++) {
        vis[i].resize(c);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char a;
            cin >> a;
            if (a == '.') {
                vis[i][j] = 0;
            } else {
                vis[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!vis[i][j]) {
                dfs(i, j);
                rooms++;
            }
        }
    }
    cout << rooms << "\n";
    return 0;
}
