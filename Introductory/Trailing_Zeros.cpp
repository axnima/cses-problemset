#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n) {
        ans += (n / 5);
        n /= 5;
    }
    cout << ans;
    return 0;
}
