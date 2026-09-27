#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int ar[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            char c;
            cin>>c;
            if (c=='.') {
                ar[i][j]=0;
            }
            else {
                ar[i][j]=-1;
            }
        }
    }
    if (ar[0][0]!=-1) {
        ar[0][0]=1;
    }
    else {
        cout<<0<<"\n";
        return 0;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i==0 && j==0) {
                ar[i][j]=1;
                continue;
            }
            if (ar[i][j]==-1) {
                continue;
            }
            else if (i==0 && j>0) {
                ar[i][j]+=ar[i][j-1];
            }
            else if (j==0 && i>0) {
                ar[i][j]+=ar[i-1][j];
            }
            else {
                if (ar[i-1][j]!=-1) {
                    ar[i][j]+=ar[i-1][j];
                }
                if (ar[i][j-1]!=-1) {
                    ar[i][j]+=ar[i][j-1];
                }
            }
            ar[i][j]=ar[i][j]%mod;
        }
    }

    if (ar[n-1][n-1]==-1) {
        cout<<0<<"\n";
        return 0;
    }
    cout<<ar[n-1][n-1];
    return 0;
}
