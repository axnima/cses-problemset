#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

struct triplet {
    int first;
    int second;
    int third;
};

int n, m;
map<int, int> parent;
vector<triplet> edgelist;
vector<int> dis;

void bellman() {
    int x = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a = edgelist[j].first;
            int b = edgelist[j].second;
            int c = edgelist[j].third;
            if (dis[a] + c < dis[b] && i == n - 1) {
                x = a;
                dis[b] = dis[a] + c;
            }
            if (dis[a] + c < dis[b]) {
                dis[b] = dis[a] + c;
                parent[b] = a;
            }
        }
    }
    if (x == -1) {
        cout << "NO\n";
        return;
    }
    while (n--) {
        x = parent[x];
    }
    int start = x;
    vector<int> ans;
    ans.push_back(x);
    x = parent[x];
    while (x != start) {
        ans.push_back(x);
        x = parent[x];
    }
    ans.push_back(x);
    cout << "YES\n";
    reverse(ans.begin(), ans.end());
    for (auto i : ans) {
        cout << i << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    edgelist.resize(m);
    dis.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edgelist[i].first = a;
        edgelist[i].second = b;
        edgelist[i].third = c;
    }
    for (int i = 0; i <= n; i++) {
        dis[i] = INF;
    }
    bellman();
    return 0;
}
