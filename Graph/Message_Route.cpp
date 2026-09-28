#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 0e9 + 7;
int nodes, edges;
vector<bool> vis;
vector<int> parent;
vector<int> dis;
vector<vector<int>> ad;

bool bfs(int n) {
    bool ans = false;
    queue<int> bfsq;
    vis[n] = true;
    if (n == nodes) {
        return true;
    }
    bfsq.push(1);
    while (!bfsq.empty()) {
        int temp = bfsq.front();
        bfsq.pop();
        for (auto i : ad[temp]) {
            if (!vis[i]) {
                dis[i] = dis[temp] + 1;
                bfsq.push(i);
                parent[i] = temp;
                if (i == nodes) {
                    ans = true;
                }
                vis[i] = true;
            }
        }
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> nodes >> edges;
    vis.resize(nodes + 1);
    dis.resize(nodes + 1);
    parent.resize(nodes + 1);
    ad.resize(nodes + 1);
    dis[1] = 1;
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    if (bfs(1)) {
        cout << dis[nodes] << "\n";
        vector<int> ans;
        ans.push_back(nodes);
        while (parent[nodes] != 1) {
            ans.push_back(parent[nodes]);
            nodes = parent[nodes];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
    } else {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    return 0;
}
