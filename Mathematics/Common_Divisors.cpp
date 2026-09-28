#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        int val = v[i];
        freq[val]++;
        int sq = sqrt(val);
        for (int j = 2; j <= sq; j++) {
            if (val % j == 0) {
                freq[j]++;
                if (val / j != j)
                    freq[val / j]++;
            }
        }
    }
    int big = 1;
    for (auto i : freq) {
        if (i.second >= 2)
            big = max(big, i.first);
    }
    cout << big << "\n";
    return 0;
}
