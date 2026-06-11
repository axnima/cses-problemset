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
    map<int , set<int>> col, row;
    vector<vector<int>> mex(n, vector<int>(n));
    for(int i = 0; i < n; i ++) {
      mex[0][i] = i;
      row[0].insert(i);
      col[i].insert(i);
    }
    for(int i = 0; i < n; i ++) {
      mex[i][0] = i;
      row[i].insert(i);
      col[0].insert(i);
    }
    for(int i = 1; i < n; i ++) {
      for(int j = 1; j < n ; j ++) {
        auto citr = col[j].begin();
        auto ritr = row[i].begin();
        for(int k = 0; k <= n * 2; k ++) {
          if(*citr == k && citr != col[j].end()) {
            citr++;
          }
          else if(*ritr == k && ritr != row[i].end()) {
            ritr++;
          }
          else {
            mex[i][j] = k;
            col[j].insert(k);
            row[i].insert(k);
            break;
          }
        }
      }
    }
    for(int i = 0; i < n; i ++) {
      for(int j = 0; j < n ; j ++) {
        cout << mex[i][j] << " ";
      }
      cout << "\n";
    }
    return 0;
}
  