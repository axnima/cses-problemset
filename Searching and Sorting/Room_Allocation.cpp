#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // time type index
    vector<pair<int, pair<int, int>>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.pb({a, {0, i}});
        v.pb({b, {1, i}});
    }
    sort(v.begin(), v.end());
    set<int> free, used;
    vector<int> ans(n);
    int capacity = 0;
    for (int i = 0; i < n * 2; i++) {
        int type = v[i].second.first;
        int index = v[i].second.second;
        if (free.size() == 0 && type == 0) {
            capacity++;
            free.insert(capacity);
        }
        if (type == 0) {
            auto back = free.end();
            back--;
            ans[index] = *back;
            used.insert(*back);
            free.erase(back);
        } else {
            int val = ans[index];
            used.erase(val);
            free.insert(val);
        }
    }
    cout << capacity << "\n";
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}
