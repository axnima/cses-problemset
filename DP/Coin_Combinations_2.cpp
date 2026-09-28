#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> dp(1e6 + 1, 0);

    for (int i = 0; i < n; i++) {
        dp[v[i]]++;
        dp[v[i]] %= mod;
        for (int j = 1; j <= x; j++) {
            if (j - v[i] >= 1) {
                dp[j] += dp[j - v[i]];
                dp[j] %= mod;
            }
        }
    }

    cout << dp[x] << "\n";
    return 0;
}
