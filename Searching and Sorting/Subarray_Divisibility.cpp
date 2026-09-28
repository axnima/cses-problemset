#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    int cnt = 0, pre = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pre += v[i];
        cnt += m[pre % n];
        if (pre % n > 0)
            cnt += m[-(n - abs(pre % n))];
        else {
            cnt += m[(n - abs(pre % n))];
        }
        m[pre % n]++;
    }
    cout << cnt + m[0] << "\n";
    return 0;
}
