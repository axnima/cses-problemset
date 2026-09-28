#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar, ar + n);
    reverse(ar, ar + n);
    int val = 0;
    for (int i = 1; i < n; i++) {
        val += ar[i];
    }
    cout << max(0ll, ar[0] - val) + val + ar[0] << "\n";
    return 0;
}
