#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 0e9 + 7;
int nodes, edges;
vector<bool> vis;
vector<vector<int>> ad;
void dfs(int n) {
    vis[n] = true;
    for (auto i : ad[n]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> nodes >> edges;
    vis.resize(nodes + 1, false);
    ad.resize(nodes + 1);
    int count = 0;

    for (int i = 0; i < edges; i++) {
        int x, y;
        cin >> x >> y;
        ad[x].push_back(y);
        ad[y].push_back(x);
    }
    vector<int> ans;
    for (int i = 1; i <= nodes; i++) {
        if (!vis[i]) {
            dfs(i);
            ans.push_back(i);
            count++;
        }
    }
    cout << count - 1 << "\n";
    int len = ans.size();
    for (int i = 0; i < len - 1; i++) {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }
    return 0;
}
