#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ll long long
#define int long long
#define mod 1000000007

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int target;
    cin >> target;
    vector<int> ways(target + 1, 0);
    ways[0] = 1;
    for(int i = 1; i <= target; i++) {
        for(int j = 1; j <= 6; j++) {
            if(i - j >= 0) ways[i] = (ways[i] + ways[i - j]) % mod;
        }
    }
    cout << ways[target] << "\n";
    return 0;
