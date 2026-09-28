#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int factorialC(int n) {
    int ans = 1;
    if (n == 1 || n == 0) {
        ans = 0;
    } else {
        int temp = n * n;
        ans = temp * (temp - 1);
        ans /= 2;
    }
    return ans;
}
int b(int n) {
    int ans = 0;
    if (n >= 3) {
        ans = (n - 1) * (n - 2);
        ans *= 2;
    }
    return ans;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int tot = factorialC(i);
        int box = b(i) * 2;
        cout << tot - box << "\n";
    }

    return 0;
}
