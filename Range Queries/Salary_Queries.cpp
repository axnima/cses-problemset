#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    Tree<pair<int, int>> pbds;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pbds.insert({v[i], i});
    }
    while (q--) {
        char type;
        cin >> type;
        if (type == '?') {
            int a, b;
            cin >> a >> b;
            int up = pbds.order_of_key({b + 1, 0});
            int low = pbds.order_of_key({a, 0});
            cout << up - low << "\n";
        } else {
            int k, x;
            cin >> k >> x;
            pbds.erase({v[k - 1], k - 1});
            pbds.insert({x, k - 1});
            v[k - 1] = x;
        }
    }
    return 0;
}
