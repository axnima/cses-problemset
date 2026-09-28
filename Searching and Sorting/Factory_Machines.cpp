#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int l = 1;
    int r = 1e18;
    while (l < r) {
        int m = l + ((r - l) / 2);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += m / ar[i];
            if (cnt >= t) {
                break;
            }
        }
        if (cnt < t) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << l << "\n";
    return 0;
}
