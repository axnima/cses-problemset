#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int num[x + 1ll] = {0ll};
    int coin[n];
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    num[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coin[j] >= 0ll) {
                num[i] = (num[i] + num[i - coin[j]]) % mod;
            }
        }
    }

    cout << num[x] << "\n";
    return 0;
}
