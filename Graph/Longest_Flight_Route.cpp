#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<vector<int>> g;
vector<vector<int>> ginv;
vector<int> dis;
vector<int> parent;
vector<int> deg;
vector<int> ans;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int a, b;
    g.resize(n + 1);
    dis.resize(n + 1, -1);
    deg.resize(n + 1);
    parent.resize(n + 1, -1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        deg[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            pq.push(i);
            ans.push_back(i);
        }
    }
    while (!pq.empty()) {
        int v = pq.top();
        pq.pop();
        for (auto i : g[v]) {
            deg[i]--;
            if (deg[i] == 0) {
                pq.push(i);
                ans.push_back(i);
            }
        }
    }
    if (deg[n] != 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int len = ans.size();
    dis[1] = 0;
    for (int i = 0; i < len; i++) {
        for (auto u : g[ans[i]]) {
            if (dis[ans[i]] < 0)
                continue;
            if (dis[u] < 0)
                dis[u] = 0;
            if (dis[ans[i]] + 1 > dis[u]) {
                dis[u] = dis[ans[i]] + 1;
                parent[u] = ans[i];
            }
        }
    }
    if (dis[n] < 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int x = n;
    ans.clear();
    ans.push_back(x);
    while (x != 1) {
        x = parent[x];
        ans.push_back(x);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << ' ';
    }
    return 0;
}
