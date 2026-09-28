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
    int s = 0;
    int max = ar[0];
    for (int i = 0; i < t; i++) {
        s += ar[i];
        if (s > max) {
            max = s;
        }
        if (s < 0) {
            s = 0;
        }
    }
    cout << max << "\n";
    return 0;
}
