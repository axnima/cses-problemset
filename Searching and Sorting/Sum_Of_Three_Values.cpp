#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, val;
    cin >> n >> val;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back({a, i + 1});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int l = j + 1;
            int r = n - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                int num = v[i].first + v[j].first + v[m].first;
                if (num == val) {
                    cout << v[i].second << " " << v[j].second << " " << v[m].second << "\n";
                    return 0;
                } else if (num > val) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
