#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> lift(n + 1, vector<int>(19, -1));
    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> depth(n + 1, 0);
    auto dfs = [&](int node, int par, auto &&dfs) -> void {
        if (par != -1) {
            depth[node] = depth[par] + 1;
            lift[node][0] = par;
        }
        for (auto child : tree[node]) {
            if (child != par) {
                dfs(child, node, dfs);
            }
        }
    };
    dfs(1, -1, dfs);
    for (int j = 1; j <= 18; j++) {
        for (int i = 1; i <= n; i++) {
            if (lift[i][j - 1] == -1)
                continue;
            lift[i][j] = lift[lift[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        int oa = a;
        int ob = b;
        if (depth[a] > depth[b])
            swap(a, b);
        if (depth[a] != depth[b])
            for (int i = 0; i <= 18; i++)
                if (1 << i & (depth[b] - depth[a]))
                    b = lift[b][i];
        if (a == b) {
            cout << depth[oa] + depth[ob] - (2 * depth[a]) << "\n";
            continue;
        }
        for (int i = 18; i >= 0; i--) {
            if (lift[a][i] != lift[b][i]) {
                a = lift[a][i];
                b = lift[b][i];
            }
        }
        int lca = lift[a][0];
        cout << depth[oa] + depth[ob] - (2 * depth[lca]) << '\n';
    }
    return 0;
}
