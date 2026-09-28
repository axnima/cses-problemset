#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, n;
    cin >> x >> n;
    int ar[n];
    set<int> s;
    s.insert(0);
    s.insert(x);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    multiset<int> largest;
    largest.insert(x);
    for (int i = 0; i < n; i++) {
        int end = *s.upper_bound(ar[i]);
        auto begin = *(--s.upper_bound(ar[i]));
        int dis = end - begin;
        largest.erase(largest.find(dis));
        largest.insert(end - ar[i]);
        largest.insert(ar[i] - begin);
        auto big = largest.end();
        big--;
        cout << *big << " ";
        s.insert(ar[i]);
    }
    return 0;
}
