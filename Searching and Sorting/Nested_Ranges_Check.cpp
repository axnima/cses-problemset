#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

bool cmp_l(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first)
        return true;
    else if (a.first == b.first) {
        if (a.second > b.second)
            return true;
        return false;
    }
    return false;
}

bool cmp_r(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second)
        return true;
    else if (a.second == b.second) {
        if (a.first > b.first)
            return true;
        return false;
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> range;
    map<pair<int, int>, int> index;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        range.push_back({a, b});
        index[{a, b}] = i;
    }
    vector<int> contains(n, 0), is_contained(n, 0);
    sort(range.begin(), range.end(), cmp_l);
    int r_max = range[0].second;
    for (int i = 1; i < n; i++) {
        if (range[i].second <= r_max) {
            is_contained[index[range[i]]] = 1;
        }
        r_max = max(r_max, range[i].second);
    }
    sort(range.begin(), range.end(), cmp_r);
    int l_max = range[0].first;
    for (int i = 1; i < n; i++) {
        if (range[i].first <= l_max) {
            contains[index[range[i]]] = 1;
        }
        l_max = max(l_max, range[i].first);
    }
    for (auto i : contains) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto i : is_contained) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
