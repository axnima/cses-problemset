#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}

int solve() {
    int a, b;
    cin >> a >> b;
    cout << power(a, b) << "\n";
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
