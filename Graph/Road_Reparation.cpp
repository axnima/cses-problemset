#include <bits/stdc++.h>

#define int long long
using namespace std;

struct DSU {
    vector<int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    int components = n;
    vector<pair<int, pair<int, int>>> roads;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        roads.push_back({c, {a, b}});
    }
    sort(roads.begin(), roads.end());
    int cost = 0;
    for (int i = 0; i < m; i++) {
        if (dsu.merge(roads[i].second.first, roads[i].second.second)) {
            components--;
            cost += roads[i].first;
        }
    }
    if (components == 1) {
        cout << cost << "\n";
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}
