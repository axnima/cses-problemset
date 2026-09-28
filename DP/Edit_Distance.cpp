#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    if (a.size() > b.size()) {
        swap(a, b);
    }
    vector<vector<int>> dp(b.size(), vector<int>(a.size(), 10000));
    int n = a.size();
    int m = b.size();
    for (int i = 0; i < m; i++) {
        if (b[i] == a[0]) {
            dp[i][0] = i;
        } else {
            dp[i][0] = i + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[0] == a[i]) {
            dp[0][i] = i;
        } else {
            dp[0][i] = i + 1;
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = +min(min((a[j] == b[i] ? 0 : 1) + dp[i - 1][j - 1], dp[i - 1][j] + 1),
                            dp[i][j - 1] + 1);
        }
    }

    cout << dp[m - 1][n - 1] << "\n";
    return 0;
}
