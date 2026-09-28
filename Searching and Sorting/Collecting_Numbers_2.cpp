#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int ar[n];
    int location[n + 1];
    location[0] = -1;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        location[ar[i]] = i;
    }
    int cnt = 1;
    for (int i = 1; i <= n - 1; i++) {
        if (location[i + 1] < location[i])
            cnt++;
    }
    auto check = [&](int a) -> bool {
        if (a >= 1 && a <= n)
            return true;
        return false;
    };
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        set<int> old;
        if (check(ar[a] - 1) && location[ar[a] - 1] > location[ar[a]])
            old.insert(ar[a] - 1);
        if (check(ar[a] + 1) && location[ar[a]] > location[ar[a] + 1])
            old.insert(ar[a]);
        if (check(ar[b] - 1) && location[ar[b] - 1] > location[ar[b]])
            old.insert(ar[b] - 1);
        if (check(ar[b] + 1) && location[ar[b]] > location[ar[b] + 1])
            old.insert(ar[b]);
        set<int> now;
        location[ar[a]] = b;
        location[ar[b]] = a;
        swap(ar[a], ar[b]);
        if (check(ar[a] - 1) && location[ar[a] - 1] > location[ar[a]])
            now.insert(ar[a] - 1);
        if (check(ar[a] + 1) && location[ar[a]] > location[ar[a] + 1])
            now.insert(ar[a]);
        if (check(ar[b] - 1) && location[ar[b] - 1] > location[ar[b]])
            now.insert(ar[b] - 1);
        if (check(ar[b] + 1) && location[ar[b]] > location[ar[b] + 1])
            now.insert(ar[b]);
        cnt += now.size() - old.size();
        cout << cnt << "\n";
    }
    return 0;
}
