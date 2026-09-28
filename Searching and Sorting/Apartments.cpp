#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int la = n - 1;
    int lb = m - 1;
    int cnt = 0;
    while (lb >= 0 && la >= 0) {
        if (abs(a[la] - b[lb]) <= k) {
            la--;
            lb--;
            cnt++;
        } else if (a[la] + k < b[lb]) {
            lb--;
        } else if (a[la] - k > b[lb]) {
            la--;
        }
    }
    cout << cnt << "\n";
    return 0;
}
