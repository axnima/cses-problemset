#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int ar[t];
    for (int i = 0; i < t; i++) {
        cin >> ar[i];
    }
    sort(ar, ar + t);
    int val = ar[t / 2];
    int cnt = 0;
    for (int i = 0; i < t; i++) {
        cnt += abs(val - ar[i]);
    }
    cout << cnt << "\n";
    return 0;
}
