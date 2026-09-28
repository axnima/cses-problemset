#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            cout << 0 << " ";
        } else {
            while (!s.empty() && s.top().first >= v[i])
                s.pop();
            if (!s.empty())
                cout << s.top().second << " ";
            else {
                cout << 0 << " ";
            }
        }
        s.push({v[i], i + 1});
    }

    return 0;
}
