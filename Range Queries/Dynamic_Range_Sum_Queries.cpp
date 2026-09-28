#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

struct FenwickTree {
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (int i = 0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if (r < n)
                bit[r] += bit[i];
        }
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    FenwickTree tree(v);
    for (int i = 0; i < q; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            tree.add(a - 1, -v[a - 1] + b);
            v[a - 1] = b;
        } else {
            cout << tree.sum(a - 1, b - 1) << "\n";
        }
    }
    return 0;
}
