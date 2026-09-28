#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    pbds children;
    for (int i = 1; i <= n; i++) {
        children.insert(i);
    }
    int index = 0;
    while (!children.empty()) {
        index = (index + k) % children.size();
        auto itr = children.find_by_order(index);
        cout << *itr << " ";
        children.erase(*itr);
    }
    return 0;
}
