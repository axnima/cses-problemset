#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    bool even = false;
    if (k & 1 == 0) {
        even = true;
    }
    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    set<int> s;
    for (int i = 0; i < k; i++) {
        s.insert(ar[i]);
        if (even) {

        } else {
        }
    }
    for (int i = k; i < n - k + 1; i++) {
        s.erase(ar[i - k]);
        s.insert(ar[i]);
        if (even) {

        } else {
        }
    }
    return 0;
}
