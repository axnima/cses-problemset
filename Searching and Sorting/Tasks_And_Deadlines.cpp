#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    int cnt = 0, time = 0;
    for (int i = 0; i < n; i++) {
        time += v[i].first;
        cnt += v[i].second - time;
    }
    cout << cnt << "\n";
    return 0;
}
