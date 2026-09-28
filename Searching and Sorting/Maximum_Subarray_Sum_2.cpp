#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i == 0)
            pre[0] = v[0];
        else {
            pre[i] = pre[i - 1] + v[i];
        }
    }
    multiset<int> sums;
    int ans = pre[a - 1];
    for (int i = 0; i <= n - a; i++) {
        if (i == 0) {
            for (int j = a - 1; j < b; j++) {
                sums.insert(pre[j]);
            }
            ans = max(ans, *sums.rbegin());
        } else {
            sums.erase(sums.find(pre[i + a - 2]));
            if (i + b - 1 < n)
                sums.insert(pre[i + b - 1]);
            ans = max(ans, (*sums.rbegin()) - pre[i - 1]);
        }
    }
    cout << ans << "\n";
    return 0;
}
