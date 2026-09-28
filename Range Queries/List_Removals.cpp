#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
#define int long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    indexed_set pb;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        pb.insert({i, temp});
    }
    for (int i = 0; i < n; i++) {
        int index;
        cin >> index;
        auto p = pb.find_by_order(index - 1);
        cout << (p->second) << " ";
        pb.erase(pb.find_by_order(index - 1));
    }
    return 0;
}
