#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

int n, m, k;
vector<vector<pair<int, int>>> g;
vector<vector<int>> dist;

void dij() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            dist[i][j] = INF;
        }
    }
    dist[1][0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int c = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dist[u][k - 1] < c)
            continue;
        for (auto v : g[u]) {
            int d = v.first;
            int cost = v.second;
            if (dist[d][k - 1] <= cost + c)
                continue;
            dist[d][k - 1] = cost + c;
            pq.push({c + cost, d});
            sort(dist[d].begin(), dist[d].end());
        }
    }
    for (auto i : dist[n]) {
        cout << i << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    g.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        dist[i].resize(k);
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    dij();
    return 0;
}
