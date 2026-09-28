#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
vector<vector<int>> dp(1e6 + 1, vector<int>(2, 0));

int solve() {
    int n;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % mod << "\n";
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    dp[0][0] = 0;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 1e6; i++) {
        dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % mod;
    }
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
