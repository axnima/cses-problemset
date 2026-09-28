#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e17;
const int NINF = -1 * 1e17;

struct triplet {
    int first;
    int second;
    int third;
};

int nodes, edges;
vector<triplet> edgelist;
vector<int> dis;

void bf() {
    dis[1] = 0;
    for (int i = 1; i <= nodes; i++) {
        for (auto i : edgelist) {
            int a = i.first;
            int b = i.second;
            int c = i.third;
            if (dis[a] == INF)
                continue;
            dis[b] = min(dis[a] + c, dis[b]);
            dis[b] = max(dis[b], NINF);
        }
    }
    for (int i = 1; i <= nodes; i++) {
        for (auto i : edgelist) {
            int a = i.first;
            int b = i.second;
            int c = i.third;
            if (dis[a] == INF)
                continue;
            if (dis[a] + c < dis[b]) {
                dis[b] = NINF;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> nodes >> edges;
    dis.resize(nodes + 1);
    for (int i = 2; i <= nodes; i++) {
        dis[i] = INF;
    }
    edgelist.resize(edges);
    for (int i = 0; i < edges; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        triplet temp;
        temp.first = a;
        temp.second = b;
        temp.third = c * (-1);
        edgelist[i] = temp;
    }
    bf();
    if (dis[nodes] == NINF || (nodes == 1 && edgelist[0].third * (-1) > 0)) {
        cout << -1 << endl;
    } else {
        cout << dis[nodes] * (-1) << endl;
    }
    return 0;
}
