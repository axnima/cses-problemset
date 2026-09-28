#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> forest, sum;
    forest.resize(n + 1);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        forest[i].resize(n);
        for (int j = 0; j < n; j++) {
            if (s[j] == '*')
                forest[i][j] = 1;
            else {
                forest[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i - 1 >= 0)
                forest[i][j] += forest[i - 1][j];
            if (j - 1 >= 0)
                forest[i][j] += forest[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0)
                forest[i][j] -= forest[i - 1][j - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        int upy = max(y1 - 1, y2 - 1);
        int upx = max(x1 - 1, x2 - 1);
        int lowy = min(y1 - 1, y2 - 1);
        int lowx = min(x1 - 1, x2 - 1);
        lowx--;
        lowy--;
        int ans = forest[upy][upx];
        if (lowx >= 0)
            ans -= forest[upy][lowx];
        if (lowy >= 0)
            ans -= forest[lowy][upx];
        if (lowx >= 0 && lowy >= 0)
            ans += forest[lowy][lowx];
        cout << ans << '\n';
    }
    return 0;
}
