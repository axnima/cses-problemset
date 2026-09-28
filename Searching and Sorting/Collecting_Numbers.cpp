#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m[a] = i;
    }

    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (m[i] > m[i + 1]) {
            cnt++;
        }
    }
    cout << cnt + 1 << "\n";
    return 0;
}
