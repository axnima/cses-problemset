#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ll long long
#define int long long
#define mod 1000000007

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    map<int , int> cnt;
    for(auto &i : v) {
        cin >> i;
        cnt[i]++;
    }
    int ans = 1;
    for(auto &i : cnt) {
        ans *= i.second + 1;
        ans %= mod;
    }
    cout << ans - 1 << "\n";
    return 0;
}
