#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> dis(n + 1, vector<int>(2));
    //dfs for distance
    auto dfs = [&](int node, int par, int index, auto &&dfs) -> void {
        if (par != -1)
            dis[node][index] = dis[par][index] + 1;
        else {
            dis[node][index] = 0;
        }
        for (auto child : g[node]) {
            if (child == par)
                continue;
            dfs(child, node, index, dfs);
        }
    };
    //bfs for finding
    auto bfs = [&](int node) -> int {
        queue<pair<int, int>> q;
        q.push({node, 0});
        int last = node;
        while (!q.empty()) {
            auto [curNode, par] = q.front();
            q.pop();
            for (auto child : g[curNode]) {
                if (child == par)
                    continue;
                q.push({child, curNode});
            }
            if (q.empty())
                last = curNode;
        }
        return last;
    };
    int end = bfs(1);
    int anotherEnd = bfs(end);
    dfs(end, -1, 0, dfs);
    dfs(anotherEnd, -1, 1, dfs);
    for (int i = 1; i <= n; i++) {
        cout << max(dis[i][0], dis[i][1]) << ' ';
    }
    return 0;
}
