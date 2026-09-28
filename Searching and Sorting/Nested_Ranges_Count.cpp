#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (int i = 0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if (r < n)
                bit[r] += bit[i];
        }
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

bool cmp_l(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first)
        return true;
    else if (a.first == b.first) {
        if (a.second > b.second)
            return true;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> s;
    vector<pair<int, int>> ar;
    map<pair<int, int>, int> m;
    map<int, int> compressed;
    //Take the input
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        s.push_back(l);
        s.push_back(r);
        ar.push_back({l, r});
    }
    //Perform point compression
    int val = 1;
    sort(s.begin(), s.end());
    for (int i = 0; i < n * 2; i++) {
        if (compressed.find(s[i]) == compressed.end()) {
            compressed[s[i]] = val;
            val++;
        }
    }
    for (int i = 0; i < n; i++) {
        ar[i].first = compressed[ar[i].first];
        ar[i].second = compressed[ar[i].second];
        m[{ar[i].first, ar[i].second}] = i;
    }
    //All values now are in between 1 and 2*n
    //We have stored every interval and its index in a map
    FenwickTree contains(val), is_contained(val);
    vector<int> int_contains(n, 0), int_is_contained(n, 0);
    sort(ar.begin(), ar.end(), cmp_l);
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            int_contains[m[ar[i]]] = contains.sum(ar[i].first, ar[i].second);
        }
        contains.add(ar[i].second, 1);
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            int_is_contained[m[ar[i]]] = is_contained.sum(ar[i].second, val - 1);
        }
        is_contained.add(ar[i].second, 1);
    }
    for (auto i : int_contains) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto i : int_is_contained) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
