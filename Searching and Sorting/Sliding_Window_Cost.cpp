#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int n, k;
multiset<int> low, up;
vector<int> v;
int lowSum, upSum;

void ins(int val) {
    int med = *low.rbegin();
    if (val > med) {
        up.insert(val);
        upSum += val;
        if (up.size() > k / 2) {
            auto first = up.begin();
            upSum -= *first;
            low.insert(*first);
            lowSum += *first;
            up.erase(first);
        }
    } else {
        low.insert(val);
        lowSum += val;
        if ((k % 2 == 0 && low.size() > (k / 2)) || (k % 2 == 1 && low.size() > (k + 1) / 2)) {
            auto last = low.rbegin();
            lowSum -= *last;
            up.insert(*last);
            upSum += *last;
            low.erase(low.find(*last));
        }
    }
}

void del(int val) {
    int med = *low.rbegin();
    if (val > med) {
        upSum -= val;
        up.erase(up.find(val));
        if (up.size() < k / 2) {
            auto last = low.rbegin();
            lowSum -= *last;
            up.insert(*last);
            upSum += *last;
            low.erase(low.find(*last));
        }
    } else {
        lowSum -= val;
        low.erase(low.find(val));
        if ((k % 2 == 0 && low.size() < (k / 2)) || (k % 2 == 1 && low.size() < (k + 1) / 2)) {
            auto first = up.begin();
            upSum -= *first;
            low.insert(*first);
            lowSum += *first;
            up.erase(first);
        }
    }
}

int med() {
    int med = *low.rbegin();
    return upSum - lowSum + (k % 2 == 1 ? med : 0);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i <= n - k; i++) {
        if (i == 0) {
            low.insert(v[0]);
            lowSum += v[0];
            for (int j = 1; j < k; j++) {
                ins(v[j]);
            }
        } else {
            ins(v[i + k - 1]);
            del(v[i - 1]);
        }
        cout << med() << " \n"[i == n - k];
    }
    return 0;
}
