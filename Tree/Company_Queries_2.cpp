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
    for (int i = 2; i <= n; i++) {
        cin >> lift[i][0];
        tree[lift[i][0]].push_back(i);
        tree[i].push_back(lift[i][0]);
    }
    for (int j = 1; j <= 18; j++) {
        for (int i = 1; i <= n; i++) {
            if (lift[i][j - 1] == -1)
                continue;
            lift[i][j] = lift[lift[i][j - 1]][j - 1];
        }
    }
    vector<int> depth(n + 1, 0);
    auto dfs = [&](int node, int par, auto &&dfs) -> void {
        depth[node] = depth[par] + 1;
        for (auto child : tree[node]) {
            if (child != par) {
                dfs(child, node, dfs);
            }
        }
    };
    dfs(1, 0, dfs);
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (depth[a] > depth[b])
            swap(a, b);
        if (depth[a] != depth[b])
            for (int i = 0; i <= 18; i++)
                if (1 << i & (depth[b] - depth[a]))
                    b = lift[b][i];
        if (a == b) {
            cout << a << "\n";
            continue;
        }
        for (int i = 18; i >= 0; i--) {
            if (lift[a][i] != lift[b][i]) {
                a = lift[a][i];
                b = lift[b][i];
            }
        }
        cout << lift[a][0] << "\n";
    }
    return 0;
}
