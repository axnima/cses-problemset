#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(b, a);
    }
    sort(v.begin(), v.end());
    multiset<int> ends;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        auto itr = ends.upper_bound(v[i].second);
        if (itr != ends.begin()) {
            itr--;
            ends.erase(itr);
            ends.insert(v[i].first);
            cnt++;
        } else {
            if (ends.size() < k) {
                ends.insert(v[i].first);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
