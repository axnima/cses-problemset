#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int solve() {
    int n;
    cin >> n;
    int ans = (n * (n + 1)) / 2;
    if (ans % 2 == 0) {
        cout << "YES\n";
        if (n % 2 == 0) {
            cout << n / 2 << "\n";
            for (int i = 1; i <= n / 2; i++) {
                if (i % 2 == 0) {
                    cout << i << " " << n - i + 1 << " ";
                }
            }
            cout << "\n" << n / 2 << "\n";
            for (int i = 1; i <= n / 2; i++) {
                if (i % 2 == 1) {
                    cout << i << " " << n - i + 1 << " ";
                }
            }
        } else {
            cout << (n / 2) << "\n";
            for (int i = 1; i <= n / 2; i++) {
                if (i % 2 == 0) {
                    cout << i << " " << n - i << " ";
                }
            }
            cout << n << "\n" << (n / 2) + 1 << "\n";
            for (int i = 1; i <= n / 2; i++) {
                if (i % 2 == 1) {
                    cout << i << " " << n - i << " ";
                }
            }
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();

    return 0;
}
