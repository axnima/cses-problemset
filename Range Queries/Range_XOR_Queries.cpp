#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int pre[n];
    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    pre[0] = ar[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] ^ ar[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == 0) {
            cout << pre[r] << "\n";
        } else {
            cout << (pre[r] ^ pre[l - 1]) << "\n";
        }
    }
    return 0;
}
