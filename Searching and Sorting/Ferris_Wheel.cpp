#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int low = 0;
    int hi = n - 1;
    int cnt = 0;
    while (low < hi) {
        if (v[low] + v[hi] <= x) {
            cnt++;
            low++;
            hi--;
        } else {
            hi--;
        }
    }
    cout << n - cnt << "\n";
    return 0;
}
