#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 0e9 + 7;
int nodes, edges;
int start, ed;
vector<bool> vis;
vector<vector<int>> ad;
vector<int> parent;
bool yes = false;

bool dfs(int n, int par) {
    vis[n] = true;
    parent[n] = par;
    for (auto i : ad[n]) {
        if (i == par) {
            continue;
        } else if (!vis[i]) {
            if (dfs(i, n)) {
                return true;
            }
        } else {
            start = i;
            ed = n;
            return true;
        }
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> nodes >> edges;
    vis.resize(nodes + 1);
    ad.resize(nodes + 1);
    parent.resize(nodes + 1);
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    for (int i = 1; i <= nodes; i++) {
        if (!vis[i]) {
            if (dfs(i, -1)) {
                yes = true;
                break;
            }
        }
    }
    if (yes) {
        vector<int> ans;
        ans.push_back(ed);
        int temp = ed;
        while (temp != start) {
            ans.push_back(parent[temp]);
            temp = parent[temp];
        }
        ans.push_back(ed);
        cout << ans.size() << "\n";
        for (auto i : ans) {
            cout << i << " ";
        }
    } else {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
}
