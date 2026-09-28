#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 0e9 + 7;
int nodes, edges;
vector<bool> vis;
vector<int> color;
vector<vector<int>> ad;

bool dfs(int n, int c, int par) {
    vis[n] = true;
    color[n] = c;
    for (auto i : ad[n]) {
        if (i == par) {
            continue;
        }
        if (!vis[i]) {
            if (!dfs(i, 3 - c, n)) {
                return 0;
            }
        } else {
            if (color[i] == color[n]) {
                return 0;
            }
        }
    }
    return 1;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> nodes >> edges;
    vis.resize(nodes + 1);
    color.resize(nodes + 1);
    ad.resize(nodes + 1);
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    color[1] = 1;
    for (int i = 0; i < nodes; i++) {
        if (!vis[i]) {
            if (!dfs(i, 1, -1)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    int len = color.size();
    for (int i = 1; i < len; i++) {
        cout << color[i] << " ";
    }
    return 0;
}
