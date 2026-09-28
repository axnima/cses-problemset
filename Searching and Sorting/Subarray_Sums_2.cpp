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
    int pre = 0;
    map<int, int> m;
    m[0]++;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        pre += ar[i];
        ans += m[pre - x];
        m[pre]++;
    }
    cout << ans << "\n";

    return 0;
}
