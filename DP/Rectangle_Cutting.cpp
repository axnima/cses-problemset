#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a , b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1 , vector<int>(b+1 , 1e9));
    for (int i=0;i<=a;i++) {
        dp[i][0]=0;
    }
    for (int i=0;i<=b;i++) {
        dp[0][i]=0;
    }
    dp[1][1]=0;
    for (int i=1;i<=a;i++) {
        for (int j=1;j<=b;j++) {
            if (i==j) {
                dp[i][j]=0;
                continue;
            }
            for (int vert=1;vert<=(j+1)/2;vert++) {
                dp[i][j]=min(dp[i][j] , 1+dp[i][vert]+dp[i][j-vert]);
            }
            for (int hori=1;hori<=(i+1)/2;hori++) {
                dp[i][j]=min(dp[i][j] , 1+dp[hori][j]+dp[i-hori][j]);
            }
        }
    }
    cout<<dp[a][b]<<"\n";
    return 0;
}
