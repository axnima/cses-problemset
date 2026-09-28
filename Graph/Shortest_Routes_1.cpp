#include <bits/stdc++.h>
using namespace std;
#define int long long
int nodes, edges;
vector<vector<pair<int, int>>> g;
vector<int> dis;
int inf = 1e17;

void dijkstras() {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int distance = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (distance != dis[u])
            continue;
        for (auto i : g[u]) {
            int to = i.first;
            int len = i.second;
            if (dis[to] > dis[u] + len) {
                dis[to] = dis[u] + len;
                pq.push({dis[to], to});
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> nodes >> edges;
    for (int i = 0; i <= nodes; i++) {
        dis.push_back(inf);
    }
    g.resize(nodes + 1);
    for (int i = 0; i < edges; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    dijkstras();
    for (int i = 1; i <= nodes; i++) {
        cout << dis[i] << ' ';
    }
    return 0;
}
