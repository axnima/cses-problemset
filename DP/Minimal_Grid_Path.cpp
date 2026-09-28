#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    dp[0][0] = true;
    string ans;
    ans.push_back(v[0][0]);
    for (int i = 1; i < (2 * n) - 1; i++) {
        int ival = min(i, n - 1);
        char best = 'Z';
        for (int j = i - ival; j <= min(n - 1, i); j++) {
            if (j - 1 >= 0 && dp[ival][j - 1])
                best = 'A' + min(best - 'A', v[ival][j] - 'A');
            if (ival - 1 >= 0 && dp[ival - 1][j])
                best = 'A' + min(best - 'A', v[ival][j] - 'A');
            ival--;
        }

        ans.push_back(best);
        ival = min(i, n - 1);
        for (int j = i - ival; j <= min(n - 1, i); j++) {
            if (j - 1 >= 0 && dp[ival][j - 1] && v[ival][j] == best)
                dp[ival][j] = true;
            if (ival - 1 >= 0 && dp[ival - 1][j] && v[ival][j] == best)
                dp[ival][j] = true;
            ival--;
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
