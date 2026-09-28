#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int cnt = 0;
    map<int, int> cur;
    int l = 0;
    int r = 0;
    cur[v[0]]++;
    while (l < n) {
        if (cur.size() <= k) {
            if (r + 1 < n) {
                r++;
                cur[v[r]]++;
            } else {
                break;
            }
        }
        if (cur.size() > k) {
            cnt += n - r;
            if (cur[v[l]] == 1) {
                cur.erase(v[l]);
            } else {
                cur[v[l]]--;
            }
            l++;
        }
    }
    cout << (n * (n + 1) / 2) - cnt << "\n";
    return 0;
}
