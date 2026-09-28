#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ar[n];
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (v.size() == 0) {
            v.push_back(ar[i]);
        } else if (v.back() <= ar[i]) {
            v.push_back(ar[i]);
        } else {
            auto a = upper_bound(v.begin(), v.end(), ar[i]);
            v[a - v.begin()] = ar[i];
        }
    }
    cout << v.size();
    return 0;
}
