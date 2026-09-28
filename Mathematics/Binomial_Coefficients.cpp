#include <bits/stdc++.h>

#define mod 1000000007
#define int long long
#define ll long long
using namespace std;

const int N = 1e6 + 1;

int fact[N] = {0};
int invfact[N] = {0};

ll inv(ll a) {
    ll b = mod - 2;
    ll p = mod;
    a %= p;
    if (a == 0)
        return 1;
    ll product = 1;
    while (b > 0) {
        if (b & 1) { // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2; // you can also use b >> 1
    }
    return product;
}

ll nCk(ll n, ll k) {
    if (k == 0)
        return 1;
    return (((fact[n] * invfact[k]) % mod) * invfact[n - k]) % mod;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[1] = 1;
    fact[0] = 1;
    invfact[1] = inv(fact[1]);
    invfact[0] = inv(fact[0]);
    for (int i = 2; i <= N + 1; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = inv(fact[i]);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << nCk(a, b) << "\n";
    }
    return 0;
}
