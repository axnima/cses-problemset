#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cout << t << " ";
    while (t != 1) {
        if (t & 1) {
            t = 3 * t + 1;
        } else {
            t /= 2;
        }
        cout << t << " ";
    }
    return 0;
}
