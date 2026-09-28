#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ar;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ar.push_back(a);
        sum += a;
    }
    int ans = sum;
    int num = pow(2, n);
    int tsum = 0;
    for (int i = 0; i < num; i++) {
        tsum = 0;
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                tsum += ar[j];
            }
        }
        ans = min(ans, abs(sum - (2 * tsum)));
    }
    cout << ans << "\n";
    return 0;
}
