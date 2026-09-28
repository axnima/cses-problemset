#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 200200; // limit for array size
int n;                // array size
int t[2 * N];

void build() { // build the tree
    for (int i = n - 1; i > 0; --i)
        t[i] = max(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, int value) { // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = max(t[p], t[p ^ 1]);
}

int query(int l, int r) { // sum on interval [l, r)
    int res = -1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = max(t[l++], res);
        if (r & 1)
            res = max(t[--r], res);
    }
    return res;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        t[n + i] = v[i];
    }
    build();
    while (m--) {
        int group;
        cin >> group;
        if (query(0, n) < group) {
            cout << 0 << " ";
        } else {
            int l = 0;
            int r = n - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (query(l, mid + 1) >= group) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            v[l] -= group;
            cout << l + 1 << " ";
            modify(l, v[l]);
        }
    }
    return 0;
}
