#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> v;
    int num = pow(2, n);
    v.resize(num);
    int val = num / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < num; j++) {
            int temp = (j) / val;
            if (temp % 2 == 1) {
                v[j] += '1';
            } else {
                v[j] += '0';
            }
        }
        val = val / 2;
    }
    for (int i = 0; i < num; i++) {
        string p = "";
        p += v[i][0];
        for (int j = 0; j < n - 1; j++) {
            string a = "", b = "";
            a += v[i][j];
            b += v[i][j + 1];
            p += to_string(stoi(a) ^ stoi(b));
        }
        cout << p << "\n";
    }
    return 0;
}
