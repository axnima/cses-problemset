#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    ;
    vector<int> v(n);
    int largest = 0;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        largest = max(largest, v[i]);
        total += v[i];
    }
    int l = largest;
    int r = total;
    while (l < r) {
        int m = l + (r - l) / 2;
        int parts = k;
        int temp = 0;
        int big = total;
        for (int i = 0; i < n; i++) {
            temp += v[i];
            if (temp > m) {
                parts--;
                big = max(big, temp - v[i]);
                temp = v[i];
            } else if (temp == m) {
                big = max(temp, big);
                temp = 0;
                parts--;
            }
        }
        if (temp > 0) {
            big = max(big, temp);
            parts--;
        }
        if (parts < 0 || big < m) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << l << "\n";
    return 0;
}
