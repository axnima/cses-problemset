#include <bits/stdc++.h>

#define int long long
#define pb push_back
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> suc(n + 1);
    for (int i = 1; i <= n; i++) {
        int par;
        cin >> par;
        suc[i] = par;
    }
    // Do a dfs and mark the nodes in a cycle with the length of their cycle
    vector<int> dfsOrder;
    vector<bool> vis(n + 1, false);
    vector<int> cycLen(n + 1, -1);
    auto dfs = [&](int node, auto &&dfs) -> void {
        if (vis[node]) {
            if (cycLen[node] != -1)
                return;
            int dLen = dfsOrder.size();
            int cycLength = -1;
            for (int i = 0; i < dLen; i++) {
                if (dfsOrder[i] == node) {
                    cycLength = dLen - i;
                    break;
                }
            }
            int toadd = 0;
            while (dfsOrder.size()) {
                cycLen[dfsOrder.back()] = cycLength;
                if (dfsOrder.back() == node) {
                    toadd = 1;
                }
                dfsOrder.pop_back();
                cycLength += toadd;
            }
            return;
        }
        dfsOrder.pb(node);
        vis[node] = true;
        dfs(suc[node], dfs);
        if (cycLen[node] == -1) {
            cycLen[node] = cycLen[suc[node]] + 1;
        }
        if (dfsOrder.size() && dfsOrder.back() == node)
            dfsOrder.pop_back();
    };
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, dfs);
    }
    for (int i = 1; i <= n; i++) {
        cout << cycLen[i] << " ";
    }
    return 0;
}
