#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[v].push_back(u);
        tree[u].push_back(v);
    }
    vector<int> subTreeSize(n + 1, 0), subTreeSum(n + 1, 0), ans(n + 1, 0);
    auto dfs = [&](int node, int par, auto &&dfs) -> int {
        int size = 1;
        for (auto child : tree[node]) {
            if (child == par)
                continue;
            size += dfs(child, node, dfs);
            subTreeSum[node] += subTreeSum[child] + subTreeSize[child];
        }
        subTreeSize[node] = size;
        return size;
    };
    auto dfs1 = [&](int node, int par, auto &&dfs1) -> void {
        if (node != 1)
            ans[node] = ans[par] - (2 * subTreeSize[node]) + n;
        for (auto child : tree[node]) {
            if (child == par)
                continue;
            dfs1(child, node, dfs1);
        }
    };
    dfs(1, 0, dfs);
    ans[1] = subTreeSum[1];
    dfs1(1, -1, dfs1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
