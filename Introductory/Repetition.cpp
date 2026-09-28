#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int max = 1;
    int temp = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i]) {
            temp++;
        } else {
            temp = 1;
        }
        if (temp > max) {
            max = temp;
        }
    }
    cout << max;
    return 0;
}
