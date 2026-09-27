#include <bits/stdc++.h>

#define int long long
using namespace std;
const int inf=1e18;

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> dp(n , 0);
    vector<int> v(n) , pre(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
        pre[i]=v[i]+((i-1)>=0?pre[i-1]:0);
    }
    for (int i=1;i<=n;i++) {
        vector<int> cur(n , -inf);
        for (int j=0;j+i-1<n;j++) {
            if (i==1) {
                cur[j]=v[j];
                continue;
            }
            int seg=pre[j+i-1]-((j-1)>=0?pre[j-1]:0);
            cur[j]=max(seg-dp[j+1] , cur[j]);
            cur[j]=max(seg-dp[j] , cur[j]);
        }
        dp=cur;
    }
    cout<<dp[0]<<"\n";
    return 0;
}
