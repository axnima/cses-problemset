#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int mx = (500 * 501 )/ 2;
    int dp[mx + 1000];
    int n;
    cin >> n;
    int md = (n * (n + 1)) / 2;
    if (md % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = mx + 1; j >= 1; j--) {
            dp[j + i] = (dp[j + i] + dp[j]) % mod;
        }
        dp[i]++;
    }

    cout << dp[md / 2] << "\n";
    return 0;
}
