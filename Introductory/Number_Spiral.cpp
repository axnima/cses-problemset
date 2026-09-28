#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int solve() {
    int y, x;
    int ans;
    cin >> y >> x;
    if (y >= x) {
        if (y % 2 == 0) {
            ans = (y) * (y);
            ans -= x;
            ans++;
        } else {
            ans = (y - 1) * (y - 1);
            ans++;
            ans += x - 1;
        }
    } else {
        if (x % 2 == 1) {
            ans = (x) * (x);
            ans -= y;
            ans++;
        } else {
            ans = (x - 1) * (x - 1);
            ans++;
            ans += y - 1;
        }
    }
    cout << ans << "\n";
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
