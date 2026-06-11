#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ll long long
#define int long long
#define mod 1000000007

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--) {
      int n, a, b;
      cin >> n >> a >> b;
      if(a + b > n || a > n - 1 || b > n - 1) {
        cout << "NO\n";
        continue;
      }
      if((a == 0 && b != 0) || (a != 0 && b == 0)) {
        cout << "NO\n";
        continue;
      }
      int aans[n], bans[n];
      for(int i = 1; i <= n; i ++){
        aans[i - 1] = i;
        bans[i - 1] = i;
      }
      // rotate(first, middle, last)
      if(a - 1 > 0) {
        if(b == 1) rotate(aans, aans + 1, aans + a + 1);
        else rotate(aans, aans + 1, aans + a);
      }
      if(b - 1 > 0 || (a == 1 && b == 1)) {
        if(a == 1) rotate(bans + (n - b - 1), bans + (n - b), bans + n);
        else rotate(bans + (n - b), bans + (n - b + 1), bans + n);
      }
      cout << "YES\n";
      for(auto i : aans) {
        cout << i << " ";
      }
      cout << "\n";
      for(auto i : bans) {
        cout << i << " ";
      }
      cout << "\n";
    }
    return 0;
}