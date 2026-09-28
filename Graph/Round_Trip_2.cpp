#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int n, m;
vector<vector<int>> g;
vector<int> vis;
stack<int> s;
vector<bool> marked;
bool done = false;
vector<int> ans;

bool dfs(int n) {
    vis[n] = true;
    s.push(n);
    marked[n] = true;
    for (auto i : g[n]) {
        if (!vis[i]) {
            bool d = dfs(i);
            if (d == false)
                return false;
        } else if (vis[i] && marked[i]) {
            ans.push_back(i);
            while (s.top() != i) {
                ans.push_back(s.top());
                s.pop();
            }
            ans.push_back(s.top());
            done = true;
            return false;
        }
    }
    s.pop();
    marked[n] = false;
    return true;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    marked.resize(n + 1, false);
    vis.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bool d = dfs(i);
            if (d == false)
                break;
        }
        if (done) {
            break;
        }
    }
    if (ans.size() == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}
