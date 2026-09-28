#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int l = 0;
    int r = 0;
    int cur = ar[0];
    int cnt = 0;
    while (l != n) {
        if (cur == x)
            cnt++;
        if (cur < x) {
            r++;
            cur += ar[r];
        } else {
            cur -= ar[l];
            l++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
