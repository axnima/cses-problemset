#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> e(n), l(n);
    for (int i = 0; i < n; i++) {
        cin >> e[i] >> l[i];
    }
    sort(e.begin(), e.end());
    sort(l.begin(), l.end());
    int indl = 0;
    int inde = 0;
    int cnt = 0;
    int max = 0;
    while (indl < n) {
        while (l[indl] > e[inde] && inde < n) {
            inde++;
            cnt++;
        }
        if (cnt > max) {
            max = cnt;
        }
        cnt--;
        indl++;
    }
    cout << max << "\n";
    return 0;
}
