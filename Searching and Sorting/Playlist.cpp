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
    map<int, int> m;
    int l = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(ar[i]) != m.end()) {
            int val = m[ar[i]];
            for (int j = l; j < val; j++) {
                m.erase(ar[j]);
            }
            l = m[ar[i]] + 1;
            m[ar[i]] = i;
            mx = max(mx, i - l + 1);
        } else {
            m[ar[i]] = i;
            mx = max(mx, i - l + 1);
        }
    }
    cout << mx << "\n";
    return 0;
}
