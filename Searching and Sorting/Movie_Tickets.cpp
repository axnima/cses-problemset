#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

bool cmp1(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second < b.second);
}

bool cmp2(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first < b.first);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    stable_sort(v.begin(), v.end(), cmp2);
    stable_sort(v.begin(), v.end(), cmp1);
    int cnt = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].second > cur and v[i].first >= cur) {
            cnt++;
            cur = v[i].second;
        } else {
            continue;
        }
    }
    cout << cnt << "\n";
    return 0;
}
