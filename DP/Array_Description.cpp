#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int ar[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    int dp[n + 2][m + 2] = {0};
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            dp[i][j] = 0;
        }
    }
    int low = 1;
    int high = m;
    if (ar[1] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[1][i] = 1;
        }
    } else {
        dp[1][ar[1]] = 1;
        low = ar[1];
        high = ar[1];
    }

    for (int i = 1; i <= n; i++) {
        int l, h;
        int val = ar[i];
        if (val != 0) {
            low = val;
            high = val;
            l = val;
            h = val;
        } else {
            high = min(high + 1, m);
            low = max(low - 1, 1ll);
        }
        l = low;
        h = high;

        for (int j = low; j <= high; j++) {
            dp[i][j] += (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
        }
        low = l;
        high = h;
    }

    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        cnt += dp[n][i];
        cnt %= mod;
    }
    cout << cnt;
    return 0;
}
