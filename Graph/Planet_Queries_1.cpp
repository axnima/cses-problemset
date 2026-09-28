#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int maxN = 2e5 + 1;

int n, q;
int t[maxN][60];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> t[i][0];
    }
    for (int i = 1; i < 30; i++) {
        for (int j = 1; j <= n; j++) {
            t[j][i] = t[t[j][i - 1]][i - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i < 30; i++) {
            if (k & (1 << i)) {
                x = t[x][i];
            }
        }
        cout << x << "\n";
    }
    return 0;
}
