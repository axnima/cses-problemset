#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e17;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int adj[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            adj[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(c, adj[a][b]);
        adj[b][a] = min(c, adj[b][a]);
    }
    for (int i = 1; i <= n; i++) {
        adj[i][i] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[j][k]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << (adj[a][b] == INF ? -1 : adj[a][b]) << "\n";
    }
    return 0;
}
