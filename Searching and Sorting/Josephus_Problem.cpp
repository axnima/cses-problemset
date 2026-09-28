#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i + 1);
    }
    bool skip = true;
    while (!q.empty()) {
        if (skip) {
            int val = q.front();
            q.pop();
            q.push(val);
            skip = false;
        } else {
            cout << q.front() << " ";
            q.pop();
            skip = true;
        }
    }
    return 0;
}
