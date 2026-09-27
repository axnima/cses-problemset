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
    vector<pair<int , int>> nums;
    for(int i = 0; i < n; i++) {
        cin >>v[i];
        nums.push_back({v[i] , i});
    }
    sort(nums.begin() , nums.end());
    reverse(nums.begin() , nums.end());
    stack<pair<int , int>> st;
    vector<int> next(n);
    vector<int> prev(n);
    for(int i = n - 1; i >= 0; i--) {
        while(st.size() > 0 && st.top().first <= v[i]) st.pop();
        if(st.size() == 0) {
            next[i] = -1;
        }
        else{
            next[i] = st.top().second;
        }
        st.push({v[i] , i});
    }
    while(!st.empty()) st.pop();
    for(int i = 0; i < n; i++) {
        while(st.size() > 0 && st.top().first <= v[i]) st.pop();
        if(st.size() == 0) {
            prev[i] = -1;
        }
        else{
            prev[i] = st.top().second;
        }
        st.push({v[i] , i});
        // cout << prev[i] << " ";
    }
    // cout << "\n";
    // for(int i = 0; i < n; i++) {
    //     cout << next[i] << " ";
    // }
    vector<int> dp(n , 0);
    int mx = 0;
    for(auto i : nums) {
        if(next[i.second] == -1 && prev[i.second] == -1) {
            dp[i.second] = 1;
        }
        else {
            dp[i.second] = 1 + max((next[i.second] != -1 ? dp[next[i.second]] : 0) , (prev[i.second] != -1 ? dp[prev[i.second]] : 0));
        }
        mx = max(mx , dp[i.second]);
    }
    cout << mx << "\n";
    return 0;
}
