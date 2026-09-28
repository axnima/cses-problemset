#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

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

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> compressed, anti_compressed;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        nums.push_back(v[i]);
    }
    sort(nums.begin(), nums.end());
    int val = 1;
    for (auto i : nums) {
        if (compressed.find(i) == compressed.end()) {
            compressed[i] = val;
            anti_compressed[val] = i;
            val++;
        }
    }
    FenwickTree tree(val);
    for (int i = 0; i <= n - k; i++) {
        if (i == 0) {
            for (int j = 0; j < k; j++) {
                tree.add(compressed[v[j]], 1);
            }
        } else {
            tree.add(compressed[v[i - 1]], -1);
            tree.add(compressed[v[i + k - 1]], 1);
        }
        int l = 1;
        int r = val - 1;
        int pos = (k + 1) / 2;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (tree.sum(m) >= pos) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        cout << anti_compressed[l] << " ";
    }
    return 0;
}
