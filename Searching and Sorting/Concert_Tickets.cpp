#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int, greater<int>> v;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.insert(temp);
    }
    for (int i = 0; i < m; i++) {
        int l = 0;
        int r = v.size() - 1;
        int a;
        cin >> a;
        auto ans = v.lower_bound(a);
        if (ans != v.end()) {
            cout << *ans << "\n";
            v.erase(ans);

        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
