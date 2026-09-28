#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 2e5; // limit for array size
int n;             // array size
int t[2 * N];

void build() { // build the tree
    for (int i = n - 1; i > 0; --i)
        t[i] = min(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, int value) { // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = min(t[p], t[p ^ 1]);
}

int query(int l, int r) { // sum on interval [l, r)
    int res = mod;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = min(res, t[l++]);
        if (r & 1)
            res = min(res, t[--r]);
    }
    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        t[n + i] = v[i];
    }
    build();
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            k--;
            modify(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            a--;
            cout << query(a, b) << "\n";
        }
    }
    return 0;
}
