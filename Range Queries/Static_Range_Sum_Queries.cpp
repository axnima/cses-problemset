#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int p[n];
    p[0] = ar[0];
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] + ar[i];
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            cout << p[b - 1] << "\n";
        } else {
            cout << p[b - 1] - p[a - 2] << "\n";
        }
    }
    return 0;
}
