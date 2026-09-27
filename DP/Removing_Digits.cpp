#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> val;
int solve(int n) {
    if (val[n]!=-1) {
        return val[n];
    }
    else {
        string s=to_string(n);
        int l=s.size();
        int ans=1000000;
        for (int i=0;i<l;i++) {
            string num="";
            num+=s[i];
            if (num=="0") {
                continue;
            }
            ans=min(solve(n-stoi(num))+1,ans);
        }
        val[n]=ans;
        return ans;
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    val.resize(t+1);
    for (int i=0;i<t+1;i++) {
        if (i<10) {
            val[i]=1;
        }
        else {
            val[i]=-1;
        }
    }
    val[0]=0;
    int o=solve(t);
    cout<<o<<"\n";
    return 0;
}
