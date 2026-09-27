#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    int ar[n];
    int c[x+1]={-1};
    c[0]=0;
    for (int i=0;i<n;i++) {
        cin>>ar[i];
    }
    sort(ar,ar+n);
    for (int i=0;i<=x;i++) {
        c[i]=-1;
    }
    c[0]=0;
    for (int i=1;i<=x;i++) {
        bool f=true;
        for (int j=0;j<n;j++) {
            if (i-ar[j]>=0) {
                if (c[i-ar[j]]!=-1) {
                    if (f) {
                        c[i]=i+1;
                        f=false;
                    }
                    c[i]=min(c[i-ar[j]]+1,c[i]);
                }
                else {
                    continue;
                }
            }
        }
    }

    if (c[x]==0) {
        cout<<-1<<"\n";
        return 0;
    }
    cout<<c[x]<<"\n";
    return 0;
}
