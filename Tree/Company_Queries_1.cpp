#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> lift(n + 1, vector<int>(31, -1));
    for (int i = 2; i <= n; i++) {
        cin >> lift[i][0];
    }
    for (int j = 1; j <= 30; j++) {
        for (int i = 1; i <= n; i++) {
            if (lift[i][j - 1] == -1)
                continue;
            lift[i][j] = lift[lift[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int j = 0; j <= 30; j++) {
            if (k & 1 << j) {
                x = lift[x][j];
            }
            if (x == -1) {
                x = -1;
                break;
            }
        }
        cout << x << "\n";
    }
    return 0;
}
