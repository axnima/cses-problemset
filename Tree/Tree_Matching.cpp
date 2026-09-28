#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 0e9 + 7;

int n;
vector<vector<int>> g;
vector<vector<int>> cnt;

void dfs(int n, int par) {
    int notmake = 0;
    int make = 0;
    for (auto i : g[n]) {
        if (i == par)
            continue;
        dfs(i, n);
        notmake += max(cnt[i][0], cnt[i][1]);
    }
    for (auto i : g[n]) {
        if (i == par)
            continue;
        make = max(make, notmake - max(cnt[i][0], cnt[i][1]) + cnt[i][0] + 1);
    }
    cnt[n][0] = notmake;
    cnt[n][1] = make;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    g.resize(n + 1);
    cnt.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        cnt[i].resize(2);
    }
    // 0 not connected
    // 1 connected already
    cnt[1][0] = 0;
    cnt[1][1] = 0;
    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        cnt[n][0] = 0;
        cnt[n][1] = 0;
    }
    dfs(1, -1);
    cout << max(cnt[1][0], cnt[1][1]) << "\n";
    return 0;
}
