#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define ll long long
#define int long long
#define mod 1000000007
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    char g[n][m];
    bool vis[n][m] = {false};
    queue<tuple<int , int , int>> q;
    tuple<int , int , int> aloc;
    map<pair<int , int> , pair<int , int>> child;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
            if(g[i][j] == 'M') {
                q.push({i , j , 'M'})
            }
            else if(g[i][j] == 'A'){
                aloc = {i , j , 'A'};
            }
        }
    }
    q.push(aloc);
 
    auto is_valid = [&](int x, int y, bool visval, char gval) {
        return x >= 0 && y >= 0 && x < n && y < m && !visval && gval != '#';
    };
 
    const vector<pair<int , int>> moves={{-1,0},{1,0},{0,1},{0,-1}};
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        char type = cur[2];
        for(auto move : moves){
            int nx = move.first + cur[0];
            int ny = move.second + cur[1];
            if(is_valid(nx , ny, vis[nx][ny], g[nx][ny])){
                q.push({nx, ny, type});
                vis[nx][ny] = true;
            }
        }
    }
    cout << rooms << "\n";
    return 0;
}
