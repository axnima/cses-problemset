#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> v;
    do {
        v.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    int l = v.size();
    cout << l << "\n";
    for (int i = 0; i < l; i++) {
        cout << v[i] << "\n";
    }
    return 0;
}
