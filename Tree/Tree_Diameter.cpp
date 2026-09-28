#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int n;
int ans = 0;
vector<vector<int>> g;
vector<int> cnt;

void dfs1(int n, int par) {
    for (auto i : g[n]) {
        if (i == par)
            continue;
        dfs1(i, n);
        cnt[n] = max(cnt[n], cnt[i] + 1);
    }
}

void call(int n, int par) {
    int big = -1;
    int small = -1;
    for (auto i : g[n]) {
        if (i == par)
            continue;
        if (cnt[i] > big) {
            small = big;
            big = cnt[i];
        } else if (cnt[i] > small && cnt[i] <= big) {
            small = cnt[i];
        }
        call(i, n);
    }
    ans = max(ans, small + big + 2);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    g.resize(n + 1);
    cnt.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1, -1);
    call(1, -1);
    cout << ans << "\n";
    return 0;
}
