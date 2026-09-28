#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int solve() {
    int a, b;
    cin >> a >> b;
    int d = (-3);
    int dx = b - (2 * a);
    int dy = a - (2 * b);

    if (abs(dx) % 3 != 0 || abs(dy) % 3 != 0 || dx > 0 || dy > 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
