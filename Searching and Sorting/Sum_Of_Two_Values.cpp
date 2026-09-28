#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> ar;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ar.push_back(make_pair(a, i + 1));
    }
    sort(ar.begin(), ar.end());
    for (int i = 0; i < n - 1; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (ar[m].first + ar[i].first == x) {
                cout << ar[m].second << " " << ar[i].second << "\n";
                return 0;
            } else if (ar[m].first + ar[i].first < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
