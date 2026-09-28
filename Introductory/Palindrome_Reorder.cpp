#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < s.size(); i++) {
        m[s[i]]++;
    }
    int odd = 0;
    map<char, int>::iterator itr;
    string fin = "";
    string o = "";
    for (itr = m.begin(); itr != m.end(); itr++) {
        char temp = itr->first;
        int t = (itr->second) / 2;
        for (int i = 0; i < t; i++) {
            fin += temp;
        }
        if (itr->second % 2 == 1) {
            odd++;
            o += temp;
        }
    }
    string ans = fin;
    ans += o;
    reverse(fin.begin(), fin.end());
    ans += fin;
    if (odd > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    } else {
        cout << ans;
    }
    return 0;
}
