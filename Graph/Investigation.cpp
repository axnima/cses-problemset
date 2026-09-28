#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int INF = 1e17;

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dis;
vector<int> mini;
vector<int> maxi;
vector<int> routes;

void dij() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (cost > dis[u])
            continue;
        for (auto v : g[u]) {
            int node = v.first;
            int val = v.second;
            if (cost + val > dis[node])
                continue;
            if (cost + val == dis[node]) {
                routes[node] += routes[u];
                routes[node] %= mod;
                mini[node] = min(mini[node], mini[u] + 1);
                maxi[node] = max(maxi[node], maxi[u] + 1);
            } else if (cost + val < dis[node]) {
                dis[node] = cost + val;
                routes[node] = routes[u];
                mini[node] = mini[u] + 1;
                maxi[node] = maxi[u] + 1;
                pq.push({dis[node], node});
            }
        }
    }
    cout << dis[n] << " " << routes[n] << " " << mini[n] << " " << maxi[n] << " ";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    mini.resize(n + 1);
    maxi.resize(n + 1);
    routes.resize(n + 1, 0);
    dis.resize(n + 1, INF);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    for (int i = 2; i <= n; ++i) {
        dis[i] = INF;
    }
    dis[1] = 0;
    routes[1] = 1;
    dij();
    return 0;
}
