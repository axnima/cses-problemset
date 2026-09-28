#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 0e9 + 7;

int n;
vector<vector<int>> g;
vector<int> cnt;

void dfs(int n) {
    for (auto i : g[n]) {
        cnt[n]++;
        dfs(i);
        cnt[n] += cnt[i];
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    g.resize(n + 1);
    cnt.resize(n + 1);
    cnt[1] = 0;
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        g[a].push_back(i);
        cnt[n] = 0;
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << ' ';
    }
    return 0;
}
