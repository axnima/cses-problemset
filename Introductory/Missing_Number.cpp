#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int a = 0;
    for (int i = 1; i <= t; i++) {
        a = a ^ i;
    }
    for (int i = 0; i < t - 1; i++) {
        int x;
        cin >> x;
        a = a ^ x;
    }
    cout << a;
    return 0;
}
