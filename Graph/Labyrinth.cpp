#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int n, m;

vector<vector<pair<int, int>>> path;
vector<vector<bool>> vis;

int sx, sy, ex, ey;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int x, int y) {
    if ((y >= 0 && y < n && x >= 0 && x < m) && (vis[y][x] == false)) {
        return true;
    }
    return false;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    vis[sy][sx] = true;
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        if (row == ey && col == ex) {
            break;
        }
        q.pop();
        for (auto i : moves) {
            if (isValid(col + i.first, row + i.second)) {
                q.push(make_pair(row + i.second, col + i.first));
                vis[row + i.second][col + i.first] = true;
                path[row + i.second][col + i.first] = {row, col};
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vis.resize(n);
    path.resize(n);
    for (int i = 0; i < n; i++) {
        vis[i].resize(m);
        path[i].resize(m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                vis[i][j] = true;
            } else if (c == '.') {
                vis[i][j] = false;
            } else if (c == 'A') {
                vis[i][j] = false;
                sx = j;
                sy = i;
            } else {
                vis[i][j] = false;
                ex = j;
                ey = i;
            }
        }
    }
    bfs();
    if (vis[ey][ex] == false) {
        cout << "NO\n";
        return 0;
    }
    vector<char> traced;
    int row = ey;
    int col = ex;
    while (!(row == sy && col == sx)) {
        if (path[row][col].first == row + 1) {
            traced.push_back('U');
        } else if (path[row][col].first == row - 1) {
            traced.push_back('D');
        } else if (path[row][col].second == col + 1) {
            traced.push_back('L');
        } else {
            traced.push_back('R');
        }
        int r = path[row][col].first;
        int c = path[row][col].second;
        row = r;
        col = c;
    }
    reverse(traced.begin(), traced.end());
    cout << "YES\n" << traced.size() << "\n";
    for (auto i : traced) {
        cout << i;
    }
    cout << "\n";
    return 0;
}
