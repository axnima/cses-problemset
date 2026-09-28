#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> m;
    int ans = n;
    m[1] = 1;
    m[2] = 2;
    m[3] = 3;
    //1 start
    //2 middle
    //3 final
    vector<pair<int, int>> p;
    if (ans % 2 == 0) {
        p.push_back(make_pair(m[1], m[2]));
        n--;
        while (n) {
            p.push_back(make_pair(1, (n % 2) + 2));
            int sz = p.size();
            if (n % 2 == 0) {
                m[2] = 1;
                m[1] = 3;
                m[3] = 2;
            } else {
                m[3] = 1;
                m[1] = 2;
                m[2] = 3;
            }
            for (int i = 0; i < sz - 1; i++) {
                p.push_back(make_pair(m[p[i].first], m[p[i].second]));
            }
            n--;
        }
    } else {
        p.push_back(make_pair(m[1], m[3]));
        n--;
        while (n) {
            p.push_back(make_pair(1, (n % 2) + 2));
            int sz = p.size();
            if (n % 2 == 0) {
                m[2] = 1;
                m[1] = 3;
                m[3] = 2;
            } else {
                m[3] = 1;
                m[1] = 2;
                m[2] = 3;
            }
            for (int i = 0; i < sz - 1; i++) {
                p.push_back(make_pair(m[p[i].first], m[p[i].second]));
            }
            n--;
        }
    }
    cout << int(p.size()) << "\n";
    for (auto i : p) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
