#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ll long long
#define int long long
#define mod 1000000007

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &i : a) cin >> i;
    for(auto &j : b) cin >> j;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    map<pair<int , int> , vector<int>> store;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

            }
            else dp[i][j] = max(dp[i - 1][j - 1] , max(dp[i - 1][j] , dp[i][j - 1]));
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << dp[n][m] << "\n";
    vector<int> ans;
    int l = n;
    int r = m;
    while(r > 0 && l > 0) {
        if(a[l - 1] == b[r - 1]) {
            ans.push_back(a[l - 1]);
            l--;
            r--;
        }
        else {
            if(dp[l][r - 1] > dp[l - 1][r]) {
                r--;
            }
            else {
                l--;
            }
        }
    }
    reverse(ans.begin() , ans.end());
    for(auto i : ans) cout << i << " ";
    cout << "\n";
    return 0;
}
