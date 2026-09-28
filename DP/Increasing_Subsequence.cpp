#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> ans;
    ans.push_back(1e9 + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        auto itr = upper_bound(ans.begin(), ans.end(), v[i]);
        auto itrl = lower_bound(ans.begin(), ans.end(), v[i]);
        if (*itrl == v[i])
            continue;
        else {
            if (itr == ans.end())
                ans.push_back(v[i]);
            else {
                ans[itr - ans.begin()] = v[i];
            }
        }
    }
    cout << ans.size() << "\n";
    return 0;
}
