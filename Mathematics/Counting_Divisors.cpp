#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int ar[1000005] = {0};

int solve() {
    int n;
    cin >> n;
    cout << ar[n] << "\n";
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            ar[j]++;
        }
    }
    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
