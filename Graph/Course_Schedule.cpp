#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<vector<int>> g;
vector<int> ans;
vector<int> deg;

void top() {
    //degree , vertex
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0)
            pq.push(i);
    }
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        for (auto i : g[u]) {
            deg[i]--;
            if (deg[i] == 0) {
                pq.push(i);
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    deg.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        deg[b]++;
    }
    top();
    if (ans.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (auto i : ans) {
            cout << i << " ";
        }
    }
    return 0;
}
