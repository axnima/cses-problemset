#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> full;
vector<int> disc;

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    disc[1] = 0;
    full[1] = 0;
    pq.push({0, {1, 1}});
    while (!pq.empty()) {
        int c = pq.top().first;
        int d = pq.top().second.first;
        int f = pq.top().second.second;
        pq.pop();
        if (f == 0 && disc[d] < c)
            continue;
        if (f == 1 && full[d] < c)
            continue;
        for (auto e : g[d]) {
            int v = e.first;
            int cost = e.second;
            if (f == 0) {
                if (disc[v] > cost + c) {
                    disc[v] = cost + c;
                    pq.push({cost + c, {v, 0}});
                }
            }
            if (f == 1) {
                if (full[v] > cost + c) {
                    full[v] = cost + c;
                    pq.push({cost + c, {v, 1}});
                }
                if (disc[v] > (cost / 2) + c) {
                    disc[v] = (cost / 2) + c;
                    pq.push({(cost / 2) + c, {v, 0}});
                }
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    disc.resize(n + 1);
    full.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        disc[i] = INF;
        full[i] = INF;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    dijkstra();
    cout << disc[n] << "\n";
    return 0;
}
