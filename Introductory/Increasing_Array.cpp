#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int ar[t];
    for (int i = 0; i < t; i++) {
        cin >> ar[i];
    }
    int l = ar[0];
    int mov = 0;
    for (int i = 1; i < t; i++) {
        if (l > ar[i]) {
            mov += l - ar[i];
        } else {
            l = ar[i];
        }
    }
    cout << mov;
    return 0;
}
