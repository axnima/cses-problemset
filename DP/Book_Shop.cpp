#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int> prev(x+1) , price(n) , pages(n);
    for (int i=0;i<n;i++) {
        cin>>price[i];
    }
    for (int i=0;i<n;i++) {
        cin>>pages[i];
    }
    for (int i=0;i<n;i++) {
        vector<int> cur(x+1 , 0);
        for (int j=0;j<=x;j++) {
            int take=((j-price[i])>=0?prev[j-price[i]]+pages[i]:0);
            int skip=prev[j];
            cur[j]=max(take , skip);
        }
        prev=cur;
    }
    cout<<prev[x]<<"\n";
    return 0;
}
