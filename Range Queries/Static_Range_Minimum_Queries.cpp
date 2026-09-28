#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int lift[n][32];
    for (int i = 0; i < n; i++) {
        lift[i][0] = ar[i];
    }
    for (int j = 1; j < 31; j++) {
        for (int i = 0; i < n; i++) {
            if (i + (1 << (j)) - 1 >= n) {
                lift[i][j] = mod;
                continue;
            }
            lift[i][j] = min(lift[i][j - 1], lift[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int num = b - a + 1;
        a--;
        int mn = mod;
        for (int j = 0; j < 30; j++) {
            if (num & 1 << j) {
                mn = min(mn, lift[a][j]);
                a += pow(2, j);
            }
        }
        cout << mn << "\n";
    }
    return 0;
}
