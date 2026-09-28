#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, val;
    cin >> n >> val;
    vector<int> ar(n);
    map<int, pair<int, int>> m;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            int left = val - ar[i] - ar[j];
            if (m.find(left) != m.end()) {
                cout << i + 1 << " " << j + 1 << " " << m[left].first << " " << m[left].second
                     << "\n";
                return 0;
            }
        }
        for (int j = i + 1; j < n; j++) {
            m[ar[i] + ar[j]] = {i + 1, j + 1};
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
