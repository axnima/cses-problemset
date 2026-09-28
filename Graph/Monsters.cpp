#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int n, m;
vector<pair<int, int>> monsters;
vector<vector<int>> g;
vector<vector<int>> vis;
map<pair<int, int>, pair<int, int>> parent;
int si, sj;
int ei, ej;
vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
vector<char> name = {'R', 'D', 'U', 'L'};
string ans;

bool is_valid(int row, int col, int time) {
    if (row >= n || row < 0 || col < 0 || col >= m) {
        return false;
    } else if (g[row][col] <= time && g[row][col] != 0) {
        return false;
    } else if (g[row][col] == -2) {
        return false;
    }
    return true;
}

bool boundary(int row, int col) {
    if (row == n - 1 || row == 0 || col == 0 || col == m - 1) {
        return true;
    }
    return false;
}

void multibfs() {
    queue<pair<int, int>> bfsq;
    queue<int> time;
    for (auto i : monsters) {
        bfsq.push({i.first, i.second});
        time.push(0);
    }
    while (!bfsq.empty()) {
        int row = bfsq.front().first;
        int col = bfsq.front().second;
        int now = time.front();
        time.pop();
        bfsq.pop();
        for (auto i : moves) {
            if (is_valid(row + i.first, col + i.second, now + 1)) {
                bfsq.push({row + i.first, col + i.second});
                time.push(now + 1);
                g[row + i.first][col + i.second] = now + 1;
            }
        }
    }
}

bool sourcebfs() {
    queue<pair<int, int>> q;
    queue<int> time;
    q.push({si, sj});
    time.push(0);
    bool ret = false;
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        int now = time.front();
        time.pop();
        q.pop();
        vis[row][col] = 1;
        for (auto i : moves) {
            if (is_valid(row + i.first, col + i.second, now + 1) &&
                !vis[row + i.first][col + i.second]) {
                parent[{row + i.first, col + i.second}] = {row, col};
                q.push({row + i.first, col + i.second});
                time.push(now + 1);
                vis[row + i.first][col + i.second] = 1;
                if (boundary(row + i.first, col + i.second)) {
                    ret = true;
                    ei = row + i.first;
                    ej = col + i.second;
                    break;
                }
            }
        }
    }
    if (ret) {
        int row = ei;
        int col = ej;
        while (!(row == si && col == sj)) {
            int pari = parent[{row, col}].first;
            int parj = parent[{row, col}].second;
            for (int i = 0; i < 4; i++) {
                if (pari + moves[i].first == row && parj + moves[i].second == col) {
                    ans.push_back(name[i]);
                    break;
                }
            }
            row = pari;
            col = parj;
        }
    }
    return ret;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; i++) {
        g[i].resize(m);
        vis[i].resize(m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            vis[i][j] = 0;
            if (c == '#') {
                g[i][j] = -2;
            } else if (c == '.') {
                g[i][j] = 0;
            } else if (c == 'M') {
                monsters.push_back({i, j});
                g[i][j] = -1;
            } else {
                si = i;
                sj = j;
            }
        }
    }
    multibfs();
    if (sourcebfs() || boundary(si, sj)) {
        cout << "YES\n";
        cout << ans.size() << "\n";
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
