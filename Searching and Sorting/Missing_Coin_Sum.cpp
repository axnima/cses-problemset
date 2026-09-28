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
    int sm = ar[0];
    if (sm != 1) {
        cout << 1 << "\n";
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (ar[i] > sm + 1) {
            cout << sm + 1 << "\n";
            return 0;
        }
        sm += ar[i];
    }
    cout << sm + 1 << "\n";
    return 0;
}
