#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n], b[n], p[n];
    map<int, int> compress;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        compress[a[i]];
        compress[b[i]];
    }
    int value = 1;
    for (auto &i : compress) {
        i.second = value;
        value++;
    }

    vector<vector<pair<int, int>>> projects(value + 1);
    for (int i = 0; i < n; i++) {
        projects[compress[b[i]]].push_back({compress[a[i]], p[i]});
    }
    vector<int> dp(value + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= value; i++) {
        if (projects[i].size() == 0) {
            dp[i] = dp[i - 1];
        } else {
            for (auto &j : projects[i]) {
                dp[i] = max(dp[i], dp[j.first - 1] + j.second);
            }
            dp[i] = max(dp[i], dp[i - 1]);
        }
    }
    cout << dp[value] << "\n";
    return 0;
}
