#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l = 0;
    map<int, int> last;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (last.find(v[i]) != last.end()) {
            l = max(l, last[v[i]] + 1);
        }
        last[v[i]] = i;
        cnt += i - l + 1;
    }
    cout << cnt << "\n";
    return 0;
}
